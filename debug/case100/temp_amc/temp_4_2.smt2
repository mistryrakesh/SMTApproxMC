; [approxMC_boolector_bvurem2.py] Autogenerated from source file: case100.smt2
(set-logic QF_BV)
(declare-fun clok_0 () (_ BitVec 1))
(declare-fun clok_1 () (_ BitVec 1))
(declare-fun flashclk1__U1__count1_0 () (_ BitVec 16))
(declare-fun flashclk1__U1__sflashclock1_0 () (_ BitVec 1))
(declare-fun flashclk1__U1__sflashclock1_1 () (_ BitVec 1))
(declare-fun rset_0 () (_ BitVec 1))
(declare-fun rset_1 () (_ BitVec 1))
(define-fun $e1 () (_ BitVec 16) (_ bv0 16))
(define-fun $e2 () (_ BitVec 1) (ite (= clok_0 clok_1) #b1 #b0))
(define-fun $e3 () (_ BitVec 1) (ite (= rset_0 rset_1) #b1 #b0))
(define-fun $e4 () (_ BitVec 1) (bvand $e2 $e3))
(define-fun $e5 () (_ BitVec 1) (bvand clok_1 (bvnot $e2)))
(define-fun $e6 () (_ BitVec 1) (ite (= flashclk1__U1__count1_0 (bvnot $e1)) #b1 #b0))
(define-fun $e7 () (_ BitVec 1) (ite (= (bvnot flashclk1__U1__sflashclock1_0) flashclk1__U1__sflashclock1_1) #b1 #b0))
(define-fun $e8 () (_ BitVec 1) (ite (= flashclk1__U1__sflashclock1_0 flashclk1__U1__sflashclock1_1) #b1 #b0))
(define-fun $e9 () (_ BitVec 1) (bvand $e6 (bvnot $e7)))
(define-fun $e10 () (_ BitVec 1) (bvand (bvnot $e6) (bvnot $e8)))
(define-fun $e11 () (_ BitVec 1) (bvand (bvnot $e9) (bvnot $e10)))
(define-fun $e12 () (_ BitVec 1) (bvand $e5 (bvnot $e11)))
(define-fun $e13 () (_ BitVec 1) (bvand (bvnot $e5) (bvnot $e8)))
(define-fun $e14 () (_ BitVec 1) (bvand (bvnot $e12) (bvnot $e13)))
(define-fun $e15 () (_ BitVec 1) (bvand (bvnot flashclk1__U1__sflashclock1_1) rset_1))
(define-fun $e16 () (_ BitVec 1) (bvand (bvnot rset_1) (bvnot $e14)))
(define-fun $e17 () (_ BitVec 1) (bvand (bvnot $e15) (bvnot $e16)))
(define-fun $e18 () (_ BitVec 1) (bvand $e4 (bvnot $e8)))
(define-fun $e19 () (_ BitVec 1) (bvand (bvnot $e4) (bvnot $e17)))
(assert(and (= (bvurem (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd (bvmul (_ bv105 13) ((_ zero_extend 5) ((_ extract 15 8) flashclk1__U1__count1_0))) (bvmul (_ bv137 13) ((_ zero_extend 5) ((_ extract 7 0) flashclk1__U1__count1_0)))) (bvmul (_ bv48 13) ((_ zero_extend 5) ((_ extract 7 0) ((_ zero_extend 15) flashclk1__U1__sflashclock1_1))))) (bvmul (_ bv196 13) ((_ zero_extend 5) ((_ extract 7 0) ((_ zero_extend 15) clok_0))))) (bvmul (_ bv157 13) ((_ zero_extend 5) ((_ extract 7 0) ((_ zero_extend 15) clok_1))))) (bvmul (_ bv69 13) ((_ zero_extend 5) ((_ extract 7 0) ((_ zero_extend 15) rset_1))))) (bvmul (_ bv235 13) ((_ zero_extend 5) ((_ extract 7 0) ((_ zero_extend 15) rset_0))))) (bvmul (_ bv105 13) ((_ zero_extend 5) ((_ extract 7 0) ((_ zero_extend 15) flashclk1__U1__sflashclock1_0))))) (_ bv257 13)) (_ bv192 13)) (= (bvurem (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd (bvmul (_ bv14 11) ((_ zero_extend 7) ((_ extract 15 12) flashclk1__U1__count1_0))) (bvmul (_ bv6 11) ((_ zero_extend 7) ((_ extract 11 8) flashclk1__U1__count1_0)))) (bvmul (_ bv12 11) ((_ zero_extend 7) ((_ extract 7 4) flashclk1__U1__count1_0)))) (bvmul (_ bv4 11) ((_ zero_extend 7) ((_ extract 3 0) flashclk1__U1__count1_0)))) (bvmul (_ bv0 11) ((_ zero_extend 7) ((_ extract 3 0) ((_ zero_extend 15) flashclk1__U1__sflashclock1_1))))) (bvmul (_ bv3 11) ((_ zero_extend 7) ((_ extract 3 0) ((_ zero_extend 15) clok_0))))) (bvmul (_ bv7 11) ((_ zero_extend 7) ((_ extract 3 0) ((_ zero_extend 15) clok_1))))) (bvmul (_ bv5 11) ((_ zero_extend 7) ((_ extract 3 0) ((_ zero_extend 15) rset_1))))) (bvmul (_ bv2 11) ((_ zero_extend 7) ((_ extract 3 0) ((_ zero_extend 15) rset_0))))) (bvmul (_ bv14 11) ((_ zero_extend 7) ((_ extract 3 0) ((_ zero_extend 15) flashclk1__U1__sflashclock1_0))))) (_ bv17 11)) (_ bv12 11))))
(assert (not (= (bvnot $e18) #b0)))
(assert (not (= (bvnot $e19) #b0)))
(assert true)
(check-sat)
(exit)
