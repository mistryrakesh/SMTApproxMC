/*********************                                                        */
/*! \file theory_strings_rewriter.cpp
 ** \verbatim
 ** Original author: Tianyi Liang
 ** Major contributors: none
 ** Minor contributors (to current version): none
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2014  New York University and The University of Iowa
 ** See the file COPYING in the top-level source directory for licensing
 ** information.\endverbatim
 **
 ** \brief Implementation of the theory of strings.
 **
 ** Implementation of the theory of strings.
 **/
#include "theory/strings/theory_strings_rewriter.h"
#include "theory/strings/options.h"
#include "smt/logic_exception.h"
#include <stdint.h>

using namespace std;
using namespace CVC4;
using namespace CVC4::kind;
using namespace CVC4::theory;
using namespace CVC4::theory::strings;

Node TheoryStringsRewriter::rewriteConcatString( TNode node ) {
  Trace("strings-prerewrite") << "Strings::rewriteConcatString start " << node << std::endl;
  Node retNode = node;
  std::vector<Node> node_vec;
  Node preNode = Node::null();
  for(unsigned int i=0; i<node.getNumChildren(); ++i) {
    Node tmpNode = node[i];
    if(node[i].getKind() == kind::STRING_CONCAT) {
      tmpNode = rewriteConcatString(node[i]);
      if(tmpNode.getKind() == kind::STRING_CONCAT) {
        unsigned j=0;
        if(!preNode.isNull()) {
          if(tmpNode[0].isConst()) {
            preNode = NodeManager::currentNM()->mkConst( preNode.getConst<String>().concat( tmpNode[0].getConst<String>() ) );
            node_vec.push_back( preNode );
            preNode = Node::null();
          } else {
            node_vec.push_back( preNode );
            preNode = Node::null();
            node_vec.push_back( tmpNode[0] );
          }
          ++j;
        }
        for(; j<tmpNode.getNumChildren() - 1; ++j) {
          node_vec.push_back( tmpNode[j] );
        }
        tmpNode = tmpNode[j];
      }
    }
    if(!tmpNode.isConst()) {
      if(!preNode.isNull()) {
        if(preNode.getKind() == kind::CONST_STRING && preNode.getConst<String>().isEmptyString() ) {
          preNode = Node::null();
        } else {
          node_vec.push_back( preNode );
          preNode = Node::null();
        }
      }
      node_vec.push_back( tmpNode );
    } else {
      if(preNode.isNull()) {
        preNode = tmpNode;
      } else {
        preNode = NodeManager::currentNM()->mkConst( preNode.getConst<String>().concat( tmpNode.getConst<String>() ) );
      }
    }
  }
  if(preNode != Node::null()) {
    node_vec.push_back( preNode );
  }
  if(node_vec.size() > 1) {
    retNode = NodeManager::currentNM()->mkNode(kind::STRING_CONCAT, node_vec);
  } else {
    retNode = node_vec[0];
  }
  Trace("strings-prerewrite") << "Strings::rewriteConcatString end " << retNode << std::endl;
  return retNode;
}

Node TheoryStringsRewriter::prerewriteConcatRegExp( TNode node ) {
  Assert( node.getKind() == kind::REGEXP_CONCAT );
  Trace("strings-prerewrite") << "Strings::prerewriteConcatRegExp start " << node << std::endl;
  Node retNode = node;
  std::vector<Node> node_vec;
  Node preNode = Node::null();
  bool emptyflag = false;
  for(unsigned int i=0; i<node.getNumChildren(); ++i) {
    Trace("strings-prerewrite") << "Strings::prerewriteConcatRegExp preNode: " << preNode << std::endl;
    Node tmpNode = node[i];
    if(tmpNode.getKind() == kind::REGEXP_CONCAT) {
      tmpNode = prerewriteConcatRegExp(node[i]);
      if(tmpNode.getKind() == kind::REGEXP_CONCAT) {
        unsigned j=0;
        if(!preNode.isNull()) {
          if(tmpNode[0].getKind() == kind::STRING_TO_REGEXP) {
            preNode = rewriteConcatString(
            NodeManager::currentNM()->mkNode( kind::STRING_CONCAT, preNode, tmpNode[0][0] ) );
            node_vec.push_back( NodeManager::currentNM()->mkNode( kind::STRING_TO_REGEXP, preNode ) );
            preNode = Node::null();
          } else {
            node_vec.push_back( NodeManager::currentNM()->mkNode( kind::STRING_TO_REGEXP, preNode ) );
            preNode = Node::null();
            node_vec.push_back( tmpNode[0] );
          }
          ++j;
        }
        for(; j<tmpNode.getNumChildren() - 1; ++j) {
          node_vec.push_back( tmpNode[j] );
        }
        tmpNode = tmpNode[j];
      }
    }
    if( tmpNode.getKind() == kind::STRING_TO_REGEXP ) {
      if(preNode.isNull()) {
        preNode = tmpNode[0];
      } else {
        preNode = rewriteConcatString(
        NodeManager::currentNM()->mkNode( kind::STRING_CONCAT, preNode, tmpNode[0] ) );
      }
    } else if( tmpNode.getKind() == kind::REGEXP_EMPTY ) {
      emptyflag = true;
      break;
    } else {
      if(!preNode.isNull()) {
        if(preNode.getKind() == kind::CONST_STRING && preNode.getConst<String>().isEmptyString() ) {
          preNode = Node::null();
        } else {
          node_vec.push_back( NodeManager::currentNM()->mkNode( kind::STRING_TO_REGEXP, preNode ) );
          preNode = Node::null();
        }
      }
      node_vec.push_back( tmpNode );
    }
  }
  if(emptyflag) {
    std::vector< Node > nvec;
    retNode = NodeManager::currentNM()->mkNode( kind::REGEXP_EMPTY, nvec );
  } else {
    if(!preNode.isNull()) {
      node_vec.push_back( NodeManager::currentNM()->mkNode( kind::STRING_TO_REGEXP, preNode ) );
    }
    if(node_vec.size() > 1) {
      retNode = NodeManager::currentNM()->mkNode(kind::REGEXP_CONCAT, node_vec);
    } else {
      retNode = node_vec[0];
    }
  }
  Trace("strings-prerewrite") << "Strings::prerewriteConcatRegExp end " << retNode << std::endl;
  return retNode;
}

Node TheoryStringsRewriter::prerewriteOrRegExp(TNode node) {
  Assert( node.getKind() == kind::REGEXP_UNION );
  Trace("strings-prerewrite") << "Strings::prerewriteOrRegExp start " << node << std::endl;
  Node retNode = node;
  std::vector<Node> node_vec;
  bool flag = false;
  for(unsigned i=0; i<node.getNumChildren(); ++i) {
    if(node[i].getKind() == kind::REGEXP_UNION) {
      Node tmpNode = prerewriteOrRegExp( node[i] );
      for(unsigned int j=0; j<tmpNode.getNumChildren(); ++j) {
        node_vec.push_back( tmpNode[j] );
      }
      flag = true;
    } else if(node[i].getKind() == kind::REGEXP_EMPTY) {
      flag = true;
    } else {
      node_vec.push_back( node[i] );
    }
  }
  if(flag) {
    std::vector< Node > nvec;
    retNode = node_vec.size() == 0 ? NodeManager::currentNM()->mkNode( kind::REGEXP_EMPTY, nvec ) :
          node_vec.size() == 1 ? node_vec[0] : NodeManager::currentNM()->mkNode(kind::REGEXP_UNION, node_vec);
  }
  Trace("strings-prerewrite") << "Strings::prerewriteOrRegExp end " << retNode << std::endl;
  return retNode;
}

bool TheoryStringsRewriter::checkConstRegExp( TNode t ) {
  if( t.getKind() != kind::STRING_TO_REGEXP ) {
    for( unsigned i = 0; i<t.getNumChildren(); ++i ) {
      if( !checkConstRegExp(t[i]) ) return false;
    }
    return true;
  } else {
    if( t[0].getKind() == kind::CONST_STRING ) {
      return true;
    } else {
      return false;
    }
  }
}

bool TheoryStringsRewriter::testConstStringInRegExp( CVC4::String &s, unsigned int index_start, TNode r ) {
  Assert( index_start <= s.size() );
  int k = r.getKind();
  switch( k ) {
    case kind::STRING_TO_REGEXP: {
      CVC4::String s2 = s.substr( index_start, s.size() - index_start );
      if(r[0].getKind() == kind::CONST_STRING) {
        return ( s2 == r[0].getConst<String>() );
      } else {
        Assert( false, "RegExp contains variables" );
      }
    }
    case kind::REGEXP_CONCAT: {
      if( s.size() != index_start ) {
        std::vector<int> vec_k( r.getNumChildren(), -1 );
        int start = 0;
        int left = (int) s.size();
        int i=0;
        while( i<(int) r.getNumChildren() ) {
          bool flag = true;
          if( i == (int) r.getNumChildren() - 1 ) {
            if( testConstStringInRegExp( s, index_start + start, r[i] ) ) {
              return true;
            }
          } else if( i == -1 ) {
            return false;
          } else {
            for(vec_k[i] = vec_k[i] + 1; vec_k[i] <= left; ++vec_k[i]) {
              CVC4::String t = s.substr(index_start + start, vec_k[i]);
              if( testConstStringInRegExp( t, 0, r[i] ) ) {
                start += vec_k[i]; left -= vec_k[i]; flag = false;
                ++i; vec_k[i] = -1;
                break;
              }
            }
          }

          if(flag) {
            --i;
            if(i >= 0) {
              start -= vec_k[i]; left += vec_k[i];
            }
          }
        }
        return false;
      } else {
        return true;
      }
    }
    case kind::REGEXP_UNION: {
      for(unsigned i=0; i<r.getNumChildren(); ++i) {
        if(testConstStringInRegExp( s, index_start, r[i] )) return true;
      }
      return false;
    }
    case kind::REGEXP_INTER: {
      for(unsigned i=0; i<r.getNumChildren(); ++i) {
        if(!testConstStringInRegExp( s, index_start, r[i] )) return false;
      }
      return true;
    }
    case kind::REGEXP_STAR: {
      if( s.size() != index_start ) {
        for(unsigned k=s.size() - index_start; k>0; --k) {
          CVC4::String t = s.substr(index_start, k);
          if( testConstStringInRegExp( t, 0, r[0] ) ) {
            if( index_start + k == s.size() || testConstStringInRegExp( s, index_start + k, r ) ) {
              return true;
            }
          }
        }
        return false;
      } else {
        return true;
      }
    }
    case kind::REGEXP_EMPTY: {
      return false;
    }
    case kind::REGEXP_SIGMA: {
      if(s.size() == 1) {
        return true;
      } else {
        return false;
      }
    }
    default: {
      Trace("strings-error") << "Unsupported term: " << r << " in testConstStringInRegExp." << std::endl;
      Assert( false, "Unsupported Term" );
      return false;
    }
  }
}

Node TheoryStringsRewriter::rewriteMembership(TNode node) {
  Node retNode = node;
  Node x = node[0];

  if(node[0].getKind() == kind::STRING_CONCAT) {
    x = rewriteConcatString(node[0]);
  }

  if(node[1].getKind() == kind::REGEXP_EMPTY) {
    retNode = NodeManager::currentNM()->mkConst( false );
  } else if( x.getKind() == kind::CONST_STRING && checkConstRegExp(node[1]) ) {
    //test whether x in node[1]
    CVC4::String s = x.getConst<String>();
    retNode = NodeManager::currentNM()->mkConst( testConstStringInRegExp( s, 0, node[1] ) );
  } else if(node[1].getKind() == kind::REGEXP_SIGMA) {
    Node one = NodeManager::currentNM()->mkConst( ::CVC4::Rational(1) );
    retNode = one.eqNode(NodeManager::currentNM()->mkNode(kind::STRING_LENGTH, x));
  } else if(node[1].getKind() == kind::REGEXP_STAR && node[1][0].getKind() == kind::REGEXP_SIGMA) {
    retNode = NodeManager::currentNM()->mkConst( true );
  } else if( x != node[0] ) {
    retNode = NodeManager::currentNM()->mkNode( kind::STRING_IN_REGEXP, x, node[1] );
  }
    return retNode;
}

RewriteResponse TheoryStringsRewriter::postRewrite(TNode node) {
  Trace("strings-postrewrite") << "Strings::postRewrite start " << node << std::endl;
  Node retNode = node;
  Node orig = retNode;

  if(node.getKind() == kind::STRING_CONCAT) {
    retNode = rewriteConcatString(node);
  } else if(node.getKind() == kind::EQUAL) {
    Node leftNode  = node[0];
    if(node[0].getKind() == kind::STRING_CONCAT) {
      leftNode = rewriteConcatString(node[0]);
    }
    Node rightNode = node[1];
    if(node[1].getKind() == kind::STRING_CONCAT) {
      rightNode = rewriteConcatString(node[1]);
    }

    if(leftNode == rightNode) {
      retNode = NodeManager::currentNM()->mkConst(true);
    } else if(leftNode.isConst() && rightNode.isConst()) {
      retNode = NodeManager::currentNM()->mkConst(false);
    } else if(leftNode > rightNode) {
      retNode = NodeManager::currentNM()->mkNode(kind::EQUAL, rightNode, leftNode);
    } else if( leftNode != node[0] || rightNode != node[1]) {
      retNode = NodeManager::currentNM()->mkNode(kind::EQUAL, leftNode, rightNode);
    }
  } else if(node.getKind() == kind::STRING_LENGTH) {
    if(node[0].isConst()) {
      retNode = NodeManager::currentNM()->mkConst( ::CVC4::Rational( node[0].getConst<String>().size() ) );
    } /*else if(node[0].getKind() == kind::STRING_SUBSTR_TOTAL) {
        retNode = node[0][2];
    }*/ else if(node[0].getKind() == kind::STRING_CONCAT) {
      Node tmpNode = rewriteConcatString(node[0]);
      if(tmpNode.isConst()) {
        retNode = NodeManager::currentNM()->mkConst( ::CVC4::Rational( tmpNode.getConst<String>().size() ) );
      } /*else if(tmpNode.getKind() == kind::STRING_SUBSTR_TOTAL) {
      retNode = tmpNode[2];
      }*/ else {
        // it has to be string concat
        std::vector<Node> node_vec;
        for(unsigned int i=0; i<tmpNode.getNumChildren(); ++i) {
          if(tmpNode[i].isConst()) {
            node_vec.push_back( NodeManager::currentNM()->mkConst( ::CVC4::Rational( tmpNode[i].getConst<String>().size() ) ) );
          } else if(tmpNode[i].getKind() == kind::STRING_SUBSTR_TOTAL) {
            node_vec.push_back( tmpNode[i][2] );
          } else {
            node_vec.push_back( NodeManager::currentNM()->mkNode(kind::STRING_LENGTH, tmpNode[i]) );
          }
        }
        retNode = NodeManager::currentNM()->mkNode(kind::PLUS, node_vec);
      }
    }
  } else if(node.getKind() == kind::STRING_SUBSTR_TOTAL) {
    Node zero = NodeManager::currentNM()->mkConst( ::CVC4::Rational(0) );
    if(node[2] == zero) {
      retNode = NodeManager::currentNM()->mkConst( ::CVC4::String("") );
    } else if( node[1].isConst() && node[2].isConst() ) {
      if(node[1].getConst<Rational>().sgn()>=0 && node[2].getConst<Rational>().sgn()>=0) {
        int i = node[1].getConst<Rational>().getNumerator().toUnsignedInt();
        int j = node[2].getConst<Rational>().getNumerator().toUnsignedInt();
        if( node[0].isConst() ) {
          if( node[0].getConst<String>().size() >= (unsigned) (i + j) ) {
            retNode = NodeManager::currentNM()->mkConst( node[0].getConst<String>().substr(i, j) );
          } else {
            retNode = NodeManager::currentNM()->mkConst( ::CVC4::String("") );
          }
        } else if(node[0].getKind() == kind::STRING_CONCAT && node[0][0].isConst()) {
          if( node[0][0].getConst<String>().size() >= (unsigned) (i + j) ) {
            retNode = NodeManager::currentNM()->mkConst( node[0][0].getConst<String>().substr(i, j) );
          }
        }
      } else {
        retNode = NodeManager::currentNM()->mkConst( ::CVC4::String("") );
      }
    }
  } else if(node.getKind() == kind::STRING_STRCTN) {
    if( node[0] == node[1] ) {
      retNode = NodeManager::currentNM()->mkConst( true );
    } else if( node[0].isConst() && node[1].isConst() ) {
      CVC4::String s = node[0].getConst<String>();
      CVC4::String t = node[1].getConst<String>();
      if( s.find(t) != std::string::npos ) {
        retNode = NodeManager::currentNM()->mkConst( true );
      } else {
        retNode = NodeManager::currentNM()->mkConst( false );
      }
    } else if( node[0].getKind() == kind::STRING_CONCAT ) {
      if( node[1].getKind() != kind::STRING_CONCAT ){
        bool flag = false;
        for(unsigned i=0; i<node[0].getNumChildren(); i++) {
          if(node[0][i] == node[1]) {
            flag = true;
            break;
          }
        }
        if(flag) {
          retNode = NodeManager::currentNM()->mkConst( true );
        }
      } else {
        bool flag = false;
        unsigned n1 = node[0].getNumChildren();
        unsigned n2 = node[1].getNumChildren();
        if(n1 - n2) {
          for(unsigned i=0; i<=n1 - n2; i++) {
            if(node[0][i] == node[1][0]) {
              flag = true;
              for(unsigned j=1; j<n2; j++) {
                if(node[0][i+j] != node[1][j]) {
                  flag = false;
                  break;
                }
              }
              if(flag) {
                break;
              }
            }
          }
          if(flag) {
            retNode = NodeManager::currentNM()->mkConst( true );
          }
        }
      }
    }
  } else if(node.getKind() == kind::STRING_STRIDOF) {
    if( node[0].isConst() && node[1].isConst() && node[2].isConst() ) {
      CVC4::String s = node[0].getConst<String>();
      CVC4::String t = node[1].getConst<String>();
      int i = node[2].getConst<Rational>().getNumerator().toUnsignedInt();
      std::size_t ret = s.find(t, i);
      if( ret != std::string::npos ) {
        retNode = NodeManager::currentNM()->mkConst( ::CVC4::Rational((int) ret) );
      } else {
        retNode = NodeManager::currentNM()->mkConst( ::CVC4::Rational(-1) );
      }
    }
  } else if(node.getKind() == kind::STRING_STRREPL) {
    if(node[1] != node[2]) {
      if(node[0].isConst() && node[1].isConst()) {
        CVC4::String s = node[0].getConst<String>();
        CVC4::String t = node[1].getConst<String>();
        std::size_t p = s.find(t);
        if( p != std::string::npos ) {
          if(node[2].isConst()) {
            CVC4::String r = node[2].getConst<String>();
            CVC4::String ret = s.replace(t, r);
            retNode = NodeManager::currentNM()->mkConst( ::CVC4::String(ret) );
          } else {
            CVC4::String s1 = s.substr(0, (int)p);
            CVC4::String s3 = s.substr((int)p + (int)t.size());
            Node ns1 = NodeManager::currentNM()->mkConst( ::CVC4::String(s1) );
            Node ns3 = NodeManager::currentNM()->mkConst( ::CVC4::String(s3) );
            retNode = NodeManager::currentNM()->mkNode( kind::STRING_CONCAT, ns1, node[2], ns3 );
          }
        } else {
          retNode = node[0];
        }
      }
    } else {
      retNode = node[0];
    }
  } else if(node.getKind() == kind::STRING_PREFIX) {
    if(node[0].isConst() && node[1].isConst()) {
      CVC4::String s = node[1].getConst<String>();
      CVC4::String t = node[0].getConst<String>();
      retNode = NodeManager::currentNM()->mkConst( false );
      if(s.size() >= t.size()) {
        if(t == s.substr(0, t.size())) {
          retNode = NodeManager::currentNM()->mkConst( true );
        }
      }
    } else {
      Node lens = NodeManager::currentNM()->mkNode(kind::STRING_LENGTH, node[0]);
      Node lent = NodeManager::currentNM()->mkNode(kind::STRING_LENGTH, node[1]);
      retNode = NodeManager::currentNM()->mkNode(kind::AND,
            NodeManager::currentNM()->mkNode(kind::GEQ, lent, lens),
            node[0].eqNode(NodeManager::currentNM()->mkNode(kind::STRING_SUBSTR_TOTAL, node[1],
                    NodeManager::currentNM()->mkConst( ::CVC4::Rational(0) ), lens)));
    }
  } else if(node.getKind() == kind::STRING_SUFFIX) {
    if(node[0].isConst() && node[1].isConst()) {
      CVC4::String s = node[1].getConst<String>();
      CVC4::String t = node[0].getConst<String>();
      retNode = NodeManager::currentNM()->mkConst( false );
      if(s.size() >= t.size()) {
        if(t == s.substr(s.size() - t.size(), t.size())) {
          retNode = NodeManager::currentNM()->mkConst( true );
        }
      }
    } else {
      Node lens = NodeManager::currentNM()->mkNode(kind::STRING_LENGTH, node[0]);
      Node lent = NodeManager::currentNM()->mkNode(kind::STRING_LENGTH, node[1]);
      retNode = NodeManager::currentNM()->mkNode(kind::AND,
            NodeManager::currentNM()->mkNode(kind::GEQ, lent, lens),
            node[0].eqNode(NodeManager::currentNM()->mkNode(kind::STRING_SUBSTR_TOTAL, node[1],
                    NodeManager::currentNM()->mkNode(kind::MINUS, lent, lens), lens)));
    }
  } else if(node.getKind() == kind::STRING_ITOS || node.getKind() == kind::STRING_U16TOS || node.getKind() == kind::STRING_U32TOS) {
    if(node[0].isConst()) {
      bool flag = false;
      std::string stmp = node[0].getConst<Rational>().getNumerator().toString();
      if(node.getKind() == kind::STRING_U16TOS) {
        CVC4::Rational r1(UINT16_MAX);
        CVC4::Rational r2 = node[0].getConst<Rational>();
        if(r2>r1) {
          flag = true;
        }
      } else if(node.getKind() == kind::STRING_U32TOS) {
        CVC4::Rational r1(UINT32_MAX);
        CVC4::Rational r2 = node[0].getConst<Rational>();
        if(r2>r1) {
          flag = true;
        }
      }
      //std::string stmp = static_cast<std::ostringstream*>( &(std::ostringstream() << node[0]) )->str();
      if(flag || stmp[0] == '-') {
        retNode = NodeManager::currentNM()->mkConst( ::CVC4::String("") );
      } else {
        retNode = NodeManager::currentNM()->mkConst( ::CVC4::String(stmp) );
      }
    }
  } else if(node.getKind() == kind::STRING_STOI || node.getKind() == kind::STRING_STOU16 || node.getKind() == kind::STRING_STOU32) {
    if(node[0].isConst()) {
      CVC4::String s = node[0].getConst<String>();
      if(s.isNumber()) {
        std::string stmp = s.toString();
        //if(stmp[0] == '0' && stmp.size() != 1) {
          //TODO: leading zeros
          //retNode = NodeManager::currentNM()->mkConst(::CVC4::Rational(-1));
        //} else {
          bool flag = false;
          CVC4::Rational r2(stmp.c_str());
          if(node.getKind() == kind::STRING_U16TOS) {
            CVC4::Rational r1(UINT16_MAX);
            if(r2>r1) {
              flag = true;
            }
          } else if(node.getKind() == kind::STRING_U32TOS) {
            CVC4::Rational r1(UINT32_MAX);
            if(r2>r1) {
              flag = true;
            }
          }
          if(flag) {
            retNode = NodeManager::currentNM()->mkConst(::CVC4::Rational(-1));
          } else {
            retNode = NodeManager::currentNM()->mkConst( r2 );
          }
        //}
      } else {
        retNode = NodeManager::currentNM()->mkConst(::CVC4::Rational(-1));
      }
    } else if(node[0].getKind() == kind::STRING_CONCAT) {
      for(unsigned i=0; i<node[0].getNumChildren(); ++i) {
        if(node[0][i].isConst()) {
          CVC4::String t = node[0][i].getConst<String>();
          if(!t.isNumber()) {
            retNode = NodeManager::currentNM()->mkConst(::CVC4::Rational(-1));
            break;
          }
        }
      }
    }
  } else if(node.getKind() == kind::STRING_IN_REGEXP) {
    retNode = rewriteMembership(node);
  }

  Trace("strings-postrewrite") << "Strings::postRewrite returning " << retNode << std::endl;
  return RewriteResponse(orig==retNode ? REWRITE_DONE : REWRITE_AGAIN_FULL, retNode);
}

RewriteResponse TheoryStringsRewriter::preRewrite(TNode node) {
  Node retNode = node;
  Node orig = retNode;
  Trace("strings-prerewrite") << "Strings::preRewrite start " << node << std::endl;

  if(node.getKind() == kind::STRING_CONCAT) {
    retNode = rewriteConcatString(node);
  } else if(node.getKind() == kind::REGEXP_CONCAT) {
    retNode = prerewriteConcatRegExp(node);
  } else if(node.getKind() == kind::REGEXP_UNION) {
    retNode = prerewriteOrRegExp(node);
  } else if(node.getKind() == kind::REGEXP_STAR) {
    if(node[0].getKind() == kind::REGEXP_STAR) {
      retNode = node[0];
    }
  } else if(node.getKind() == kind::REGEXP_PLUS) {
    retNode = NodeManager::currentNM()->mkNode( kind::REGEXP_CONCAT, node[0],
      NodeManager::currentNM()->mkNode( kind::REGEXP_STAR, node[0]));
  } else if(node.getKind() == kind::REGEXP_OPT) {
    retNode = NodeManager::currentNM()->mkNode( kind::REGEXP_UNION,
          NodeManager::currentNM()->mkNode( kind::STRING_TO_REGEXP, NodeManager::currentNM()->mkConst( ::CVC4::String("") ) ),
          node[0]);
  } else if(node.getKind() == kind::REGEXP_RANGE) {
    std::vector< Node > vec_nodes;
    char c = node[0].getConst<String>().getFirstChar();
    char end = node[1].getConst<String>().getFirstChar();
    for(; c<=end; ++c) {
      Node n = NodeManager::currentNM()->mkNode( kind::STRING_TO_REGEXP, NodeManager::currentNM()->mkConst( ::CVC4::String( c ) ) );
      vec_nodes.push_back( n );
    }
    if(vec_nodes.size() == 1) {
      retNode = vec_nodes[0];
    } else {
      retNode = NodeManager::currentNM()->mkNode( kind::REGEXP_UNION, vec_nodes );
    }
  } else if(node.getKind() == kind::REGEXP_LOOP) {
    Node r = node[0];
    if(r.getKind() == kind::REGEXP_STAR) {
      retNode = r;
    } else {
      unsigned l = node[1].getConst<Rational>().getNumerator().toUnsignedInt();
      std::vector< Node > vec_nodes;
      for(unsigned i=0; i<l; i++) {
        vec_nodes.push_back(r);
      }
      if(node.getNumChildren() == 3) {
        Node n = vec_nodes.size()==0 ? NodeManager::currentNM()->mkNode(kind::STRING_TO_REGEXP, NodeManager::currentNM()->mkConst(CVC4::String("")))
          : vec_nodes.size()==1 ? r : prerewriteConcatRegExp(NodeManager::currentNM()->mkNode(kind::REGEXP_CONCAT, vec_nodes));
        unsigned u = node[2].getConst<Rational>().getNumerator().toUnsignedInt();
        if(u <= l) {
          retNode = n;
        } else {
          std::vector< Node > vec2;
          vec2.push_back(n);
          for(unsigned j=l; j<u; j++) {
            vec_nodes.push_back(r);
            n = vec_nodes.size()==1? r : prerewriteConcatRegExp(NodeManager::currentNM()->mkNode(kind::REGEXP_CONCAT, vec_nodes));
            vec2.push_back(n);
          }
          retNode = prerewriteOrRegExp(NodeManager::currentNM()->mkNode(kind::REGEXP_UNION, vec2));
        }
      } else {
        Node rest = NodeManager::currentNM()->mkNode(kind::REGEXP_STAR, r);
        retNode = vec_nodes.size()==0? rest : prerewriteConcatRegExp( vec_nodes.size()==1?
                 NodeManager::currentNM()->mkNode(kind::REGEXP_CONCAT, r, rest)
                :NodeManager::currentNM()->mkNode(kind::REGEXP_CONCAT,
                  NodeManager::currentNM()->mkNode(kind::REGEXP_CONCAT, vec_nodes), rest) );
      }
    }
    Trace("strings-lp") << "Strings::lp " << node << " => " << retNode << std::endl;
  }

  Trace("strings-prerewrite") << "Strings::preRewrite returning " << retNode << std::endl;
  return RewriteResponse(orig==retNode ? REWRITE_DONE : REWRITE_AGAIN_FULL, retNode);
}
