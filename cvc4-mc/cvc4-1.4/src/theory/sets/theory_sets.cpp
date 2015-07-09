/*********************                                                        */
/*! \file theory_sets.cpp
 ** \verbatim
 ** Original author: Kshitij Bansal
 ** Major contributors: none
 ** Minor contributors (to current version): none
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2014  New York University and The University of Iowa
 ** See the file COPYING in the top-level source directory for licensing
 ** information.\endverbatim
 **
 ** \brief Sets theory.
 **
 ** Sets theory.
 **/

#include "theory/sets/theory_sets.h"
#include "theory/sets/theory_sets_private.h"

namespace CVC4 {
namespace theory {
namespace sets {

TheorySets::TheorySets(context::Context* c,
                       context::UserContext* u,
                       OutputChannel& out,
                       Valuation valuation,
                       const LogicInfo& logicInfo) :
  Theory(THEORY_SETS, c, u, out, valuation, logicInfo),
  d_internal(new TheorySetsPrivate(*this, c, u)) {
}

TheorySets::~TheorySets() {
  delete d_internal;
}

void TheorySets::addSharedTerm(TNode n) {
  d_internal->addSharedTerm(n);
}

void TheorySets::check(Effort e) {
  d_internal->check(e);
}

void TheorySets::collectModelInfo(TheoryModel* m, bool fullModel) {
  d_internal->collectModelInfo(m, fullModel);
}

void TheorySets::computeCareGraph() {
  d_internal->computeCareGraph();
}

Node TheorySets::explain(TNode node) {
  return d_internal->explain(node);
}

void TheorySets::preRegisterTerm(TNode node) {
  d_internal->preRegisterTerm(node);
}

void TheorySets::propagate(Effort e) {
  d_internal->propagate(e);
}

void TheorySets::setMasterEqualityEngine(eq::EqualityEngine* eq) {
  d_internal->setMasterEqualityEngine(eq);
}

}/* CVC4::theory::sets namespace */
}/* CVC4::theory namespace */
}/* CVC4 namespace */
