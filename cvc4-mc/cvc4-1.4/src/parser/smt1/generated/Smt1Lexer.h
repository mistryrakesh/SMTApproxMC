/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/parser/smt1/Smt1.g
 *     -                            On : 2014-07-13 13:48:58
 *     -                 for the lexer : Smt1LexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
Smt1Lexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pSmt1Lexer, which is returned from a call to Smt1LexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in pSmt1Lexer are  as follows:
 *
 *  - 
 void
      pSmt1Lexer->T__100(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->T__101(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->T__102(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->T__103(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->T__104(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->T__105(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ASSUMPTION_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BENCHMARK_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->EXTRAFUNS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->EXTRAPREDS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->EXTRASORTS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->FALSE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->FLET_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->FORMULA_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ITE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->LET_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->LOGIC_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->LPAREN_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->NOTES_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->RPAREN_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->SAT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->STATUS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->THEORY_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->TRUE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->UNKNOWN_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->UNSAT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->AMPERSAND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->AND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->AT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->DISTINCT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->DIV_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->EQUAL_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->EXISTS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->FORALL_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->GREATER_THAN_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->IFF_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->IMPLIES_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->LESS_THAN_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->MINUS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->NOT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->OR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->PERCENT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->PIPE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->PLUS_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->POUND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->SELECT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->STAR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->STORE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->TILDE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->XOR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BITVECTOR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->CONCAT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->EXTRACT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVAND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVOR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVXOR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVNOT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVNAND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVNOR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVXNOR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVCOMP_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVMUL_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVADD_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSUB_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVNEG_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVUDIV_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVUREM_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSDIV_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSREM_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSMOD_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSHL_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVLSHR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVASHR_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVULT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVULE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVUGT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVUGE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSLT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSLE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSGT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BVSGE_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->REPEAT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ZERO_EXTEND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->SIGN_EXTEND_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ROTATE_LEFT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ROTATE_RIGHT_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BITVECTOR_BV_CONST(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->BITVECTOR1_BV_CONST(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->IDENTIFIER(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ATTR_IDENTIFIER(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->LET_IDENTIFIER(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->FLET_IDENTIFIER(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->PATTERN_ANNOTATION_BEGIN(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->USER_VALUE(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->WHITESPACE(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->NUMERAL_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->RATIONAL_TOK(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->STRING_LITERAL(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->COMMENT(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ALPHA(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->DIGIT(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->ESCAPE(pSmt1Lexer)
 *  - 
 void
      pSmt1Lexer->Tokens(pSmt1Lexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_Smt1Lexer_H
#define _Smt1Lexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

/** This suppresses warnings about the redefinition of token symbols between
  * different parsers. The redefinitions should be harmless as long as no
  * client: (a) #include's the lexer headers for two grammars AND (b) uses the
  * token symbol definitions.
  */
#pragma GCC system_header

#if defined(CVC4_COMPETITION_MODE) && !defined(CVC4_SMTCOMP_APPLICATION_TRACK)
/* This improves performance by ~10 percent on big inputs.
 * This option is only valid if we know the input is ASCII (or some 8-bit encoding).
 * If we know the input is UTF-16, we can use ANTLR3_INLINE_INPUT_UTF16.
 * Otherwise, we have to let the lexer detect the encoding at runtime.
 */
#  define ANTLR3_INLINE_INPUT_ASCII
#  define ANTLR3_INLINE_INPUT_8BIT
#endif /* CVC4_COMPETITION_MODE && !CVC4_SMTCOMP_APPLICATION_TRACK */

#include "parser/antlr_tracing.h"


#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct Smt1Lexer_Ctx_struct Smt1Lexer, * pSmt1Lexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
Smt1Lexer

 */
struct Smt1Lexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mT__100)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mT__101)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mT__102)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mT__103)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mT__104)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mT__105)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mASSUMPTION_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBENCHMARK_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mEXTRAFUNS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mEXTRAPREDS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mEXTRASORTS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mFALSE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mFLET_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mFORMULA_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mITE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mLET_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mLOGIC_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mLPAREN_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mNOTES_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mRPAREN_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSAT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSTATUS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mTHEORY_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mTRUE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mUNKNOWN_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mUNSAT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mAMPERSAND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mAND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mAT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mDISTINCT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mDIV_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mEQUAL_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mEXISTS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mFORALL_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mGREATER_THAN_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mIFF_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mIMPLIES_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mLESS_THAN_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mMINUS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mNOT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mPERCENT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mPIPE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mPLUS_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mPOUND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSELECT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSTAR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSTORE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mTILDE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mXOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBITVECTOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mCONCAT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mEXTRACT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVAND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVXOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVNOT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVNAND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVNOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVXNOR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVCOMP_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVMUL_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVADD_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSUB_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVNEG_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVUDIV_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVUREM_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSDIV_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSREM_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSMOD_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSHL_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVLSHR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVASHR_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVULT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVULE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVUGT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVUGE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSLT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSLE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSGT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBVSGE_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mREPEAT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mZERO_EXTEND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSIGN_EXTEND_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mROTATE_LEFT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mROTATE_RIGHT_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBITVECTOR_BV_CONST)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mBITVECTOR1_BV_CONST)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mIDENTIFIER)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mATTR_IDENTIFIER)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mLET_IDENTIFIER)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mFLET_IDENTIFIER)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mPATTERN_ANNOTATION_BEGIN)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mUSER_VALUE)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mWHITESPACE)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mNUMERAL_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mRATIONAL_TOK)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mSTRING_LITERAL)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mCOMMENT)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mALPHA)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mDIGIT)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mESCAPE)	(struct Smt1Lexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct Smt1Lexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct Smt1Lexer_Ctx_struct * ctx);
    void	    (*free)   (struct Smt1Lexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pSmt1Lexer Smt1LexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API pSmt1Lexer Smt1LexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__100      100
#define T__101      101
#define T__102      102
#define T__103      103
#define T__104      104
#define T__105      105
#define ALPHA      4
#define AMPERSAND_TOK      5
#define AND_TOK      6
#define ASSUMPTION_TOK      7
#define ATTR_IDENTIFIER      8
#define AT_TOK      9
#define BENCHMARK_TOK      10
#define BITVECTOR1_BV_CONST      11
#define BITVECTOR_BV_CONST      12
#define BITVECTOR_TOK      13
#define BVADD_TOK      14
#define BVAND_TOK      15
#define BVASHR_TOK      16
#define BVCOMP_TOK      17
#define BVLSHR_TOK      18
#define BVMUL_TOK      19
#define BVNAND_TOK      20
#define BVNEG_TOK      21
#define BVNOR_TOK      22
#define BVNOT_TOK      23
#define BVOR_TOK      24
#define BVSDIV_TOK      25
#define BVSGE_TOK      26
#define BVSGT_TOK      27
#define BVSHL_TOK      28
#define BVSLE_TOK      29
#define BVSLT_TOK      30
#define BVSMOD_TOK      31
#define BVSREM_TOK      32
#define BVSUB_TOK      33
#define BVUDIV_TOK      34
#define BVUGE_TOK      35
#define BVUGT_TOK      36
#define BVULE_TOK      37
#define BVULT_TOK      38
#define BVUREM_TOK      39
#define BVXNOR_TOK      40
#define BVXOR_TOK      41
#define COMMENT      42
#define CONCAT_TOK      43
#define DIGIT      44
#define DISTINCT_TOK      45
#define DIV_TOK      46
#define EQUAL_TOK      47
#define ESCAPE      48
#define EXISTS_TOK      49
#define EXTRACT_TOK      50
#define EXTRAFUNS_TOK      51
#define EXTRAPREDS_TOK      52
#define EXTRASORTS_TOK      53
#define FALSE_TOK      54
#define FLET_IDENTIFIER      55
#define FLET_TOK      56
#define FORALL_TOK      57
#define FORMULA_TOK      58
#define GREATER_THAN_TOK      59
#define IDENTIFIER      60
#define IFF_TOK      61
#define IMPLIES_TOK      62
#define ITE_TOK      63
#define LESS_THAN_TOK      64
#define LET_IDENTIFIER      65
#define LET_TOK      66
#define LOGIC_TOK      67
#define LPAREN_TOK      68
#define MINUS_TOK      69
#define NOTES_TOK      70
#define NOT_TOK      71
#define NUMERAL_TOK      72
#define OR_TOK      73
#define PATTERN_ANNOTATION_BEGIN      74
#define PERCENT_TOK      75
#define PIPE_TOK      76
#define PLUS_TOK      77
#define POUND_TOK      78
#define RATIONAL_TOK      79
#define REPEAT_TOK      80
#define ROTATE_LEFT_TOK      81
#define ROTATE_RIGHT_TOK      82
#define RPAREN_TOK      83
#define SAT_TOK      84
#define SELECT_TOK      85
#define SIGN_EXTEND_TOK      86
#define STAR_TOK      87
#define STATUS_TOK      88
#define STORE_TOK      89
#define STRING_LITERAL      90
#define THEORY_TOK      91
#define TILDE_TOK      92
#define TRUE_TOK      93
#define UNKNOWN_TOK      94
#define UNSAT_TOK      95
#define USER_VALUE      96
#define WHITESPACE      97
#define XOR_TOK      98
#define ZERO_EXTEND_TOK      99
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for Smt1Lexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
