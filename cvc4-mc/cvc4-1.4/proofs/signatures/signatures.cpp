namespace CVC4 {
namespace proof {

extern const char *const plf_signatures;
const char *const plf_signatures = "\
(declare bool type)\n\
(declare tt bool)\n\
(declare ff bool)\n\
\n\
(declare var type)\n\
\n\
(declare lit type)\n\
(declare pos (! x var lit))\n\
(declare neg (! x var lit))\n\
\n\
(declare clause type)\n\
(declare cln clause)\n\
(declare clc (! x lit (! c clause clause)))\n\
\n\
; constructs for general clauses for R, Q, satlem\n\
\n\
(declare concat (! c1 clause (! c2 clause clause)))\n\
(declare clr (! l lit (! c clause clause)))\n\
\n\
; code to check resolutions\n\
\n\
(program append ((c1 clause) (c2 clause)) clause\n\
  (match c1 (cln c2) ((clc l c1') (clc l (append c1' c2)))))\n\
\n\
; we use marks as follows:\n\
; -- mark 1 to record if we are supposed to remove a positive occurrence of the variable.\n\
; -- mark 2 to record if we are supposed to remove a negative occurrence of the variable.\n\
; -- mark 3 if we did indeed remove the variable positively\n\
; -- mark 4 if we did indeed remove the variable negatively\n\
(program simplify_clause ((c clause)) clause\n\
  (match c\n\
    (cln cln)\n\
    ((clc l c1)\n\
      (match l\n\
        ; Set mark 1 on v if it is not set, to indicate we should remove it.\n\
        ; After processing the rest of the clause, set mark 3 if we were already\n\
        ; supposed to remove v (so if mark 1 was set when we began).  Clear mark3\n\
        ; if we were not supposed to be removing v when we began this call.\n\
        ((pos v)\n\
          (let m (ifmarked v tt (do (markvar v) ff))\n\
          (let c' (simplify_clause c1)\n\
            (match m\n\
              (tt (do (ifmarked3 v v (markvar3 v)) c'))\n\
              (ff (do (ifmarked3 v (markvar3 v) v) (markvar v) (clc l c')))))))\n\
        ; the same as the code for tt, but using different marks.\n\
        ((neg v)\n\
          (let m (ifmarked2 v tt (do (markvar2 v) ff))\n\
          (let c' (simplify_clause c1)\n\
            (match m\n\
              (tt (do (ifmarked4 v v (markvar4 v)) c'))\n\
              (ff (do (ifmarked4 v (markvar4 v) v) (markvar2 v) (clc l c')))))))))\n\
    ((concat c1 c2) (append (simplify_clause c1) (simplify_clause c2)))\n\
    ((clr l c1)\n\
      (match l\n\
        ; set mark 1 to indicate we should remove v, and fail if\n\
        ; mark 3 is not set after processing the rest of the clause\n\
        ; (we will set mark 3 if we remove a positive occurrence of v).\n\
        ((pos v)\n\
            (let m (ifmarked v tt (do (markvar v) ff))\n\
            (let m3 (ifmarked3 v (do (markvar3 v) tt) ff)\n\
            (let c' (simplify_clause c1)\n\
              (ifmarked3 v (do (match m3 (tt v) (ff (markvar3 v)))\n\
                                (match m (tt v) (ff (markvar v))) c')\n\
                          (fail clause))))))\n\
        ; same as the tt case, but with different marks.\n\
        ((neg v)\n\
            (let m2 (ifmarked2 v tt (do (markvar2 v) ff))\n\
            (let m4 (ifmarked4 v (do (markvar4 v) tt) ff)\n\
            (let c' (simplify_clause c1)\n\
              (ifmarked4 v (do (match m4 (tt v) (ff (markvar4 v)))\n\
                                (match m2 (tt v) (ff (markvar2 v))) c')\n\
                          (fail clause))))))\n\
   ))))\n\
\n\
\n\
; resolution proofs\n\
\n\
(declare holds (! c clause type))\n\
\n\
(declare R (! c1 clause (! c2 clause\n\
           (! u1 (holds c1)\n\
           (! u2 (holds c2)\n\
           (! n var\n\
            (holds (concat (clr (pos n) c1)\n\
                     (clr (neg n) c2)))))))))\n\
\n\
(declare Q (! c1 clause (! c2 clause\n\
           (! u1 (holds c1)\n\
           (! u2 (holds c2)\n\
           (! n var\n\
            (holds (concat (clr (neg n) c1)\n\
                     (clr (pos n) c2)))))))))\n\
\n\
(declare satlem_simplify\n\
                (! c1 clause\n\
                (! c2 clause\n\
                (! c3 clause\n\
                (! u1 (holds c1)\n\
                (! r (^ (simplify_clause c1) c2)\n\
                (! u2 (! x (holds c2) (holds c3))\n\
                   (holds c3))))))))\n\
\n\
(declare satlem\n\
  (! c clause\n\
  (! c2 clause\n\
  (! u (holds c)\n\
  (! u2 (! v (holds c) (holds c2))\n\
    (holds c2))))))\n\
\n\
; A little example to demonstrate simplify_clause.\n\
; It can handle nested clr's of both polarities,\n\
; and correctly cleans up marks when it leaves a\n\
; clr or clc scope.  Uncomment and run with\n\
; --show-runs to see it in action.\n\
;\n\
; (check\n\
;   (% v1 var\n\
;   (% u1 (holds (concat (clr (neg v1) (clr (pos v1) (clc (pos v1) (clr (pos v1) (clc (pos v1) (clc (neg v1) cln))))))\n\
;                    (clc (pos v1) (clc (pos v1) cln))))\n\
;    (satlem _ _ _ u1 (\\ x x))))))\n\
\n\
\n\
;(check\n\
;   (% v1 var\n\
;   (% u1 (holds (clr (neg v1) (concat (clc (neg v1) cln)\n\
;                                      (clr (neg v1) (clc (neg v1) cln)))))\n\
;    (satlem _ _ _ u1 (\\ x x))))))\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;\n\
; SMT syntax and semantics (not theory-specific)\n\
;\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
; depends on sat.plf\n\
\n\
(declare formula type)\n\
(declare th_holds (! f formula type))\n\
\n\
; standard logic definitions\n\
(declare true formula)\n\
(declare false formula)\n\
(declare not (! f formula formula))\n\
(declare and (! f1 formula (! f2 formula formula)))\n\
(declare or (! f1 formula (! f2 formula formula)))\n\
(declare impl (! f1 formula (! f2 formula formula)))\n\
(declare iff (! f1 formula (! f2 formula formula)))\n\
(declare xor (! f1 formula (! f2 formula formula)))\n\
(declare ifte (! b formula (! f1 formula (! f2 formula formula))))\n\
\n\
; terms\n\
(declare sort type)\n\
(declare term (! t sort type))	; declared terms in formula\n\
\n\
; standard definitions for =, ite, let and flet\n\
(declare = (! s sort\n\
           (! x (term s)\n\
           (! y (term s)\n\
             formula))))\n\
(declare ite (! s sort\n\
             (! f formula\n\
             (! t1 (term s)\n\
             (! t2 (term s)\n\
               (term s))))))\n\
(declare let (! s sort\n\
             (! t (term s)\n\
             (! f (! v (term s) formula)\n\
               formula))))\n\
(declare flet (! f1 formula\n\
              (! f2 (! v formula formula)\n\
                formula)))\n\
\n\
; We view applications of predicates as terms of sort \"Bool\".\n\
; Such terms can be injected as atomic formulas using \"p_app\".\n\
(declare Bool sort)				; the special sort for predicates\n\
(declare p_app (! x (term Bool) formula))	; propositional application of term\n\
\n\
\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;\n\
; CNF Clausification\n\
;\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
\n\
; binding between an LF var and an (atomic) formula\n\
(declare atom (! v var (! p formula type)))\n\
\n\
(declare decl_atom\n\
  (! f formula\n\
  (! u (! v var\n\
       (! a (atom v f)\n\
         (holds cln)))\n\
    (holds cln))))\n\
\n\
; clausify a formula directly\n\
(declare clausify_form\n\
  (! f formula\n\
  (! v var\n\
  (! a (atom v f)\n\
  (! u (th_holds f)\n\
    (holds (clc (pos v) cln)))))))\n\
    \n\
(declare clausify_form_not\n\
  (! f formula\n\
  (! v var\n\
  (! a (atom v f)\n\
  (! u (th_holds (not f))\n\
    (holds (clc (neg v) cln)))))))\n\
    \n\
(declare clausify_false\n\
  (! u (th_holds false)\n\
    (holds cln)))\n\
\n\
(declare th_let_pf\n\
  (! f formula\n\
  (! u (th_holds f)\n\
  (! u2 (! v (th_holds f) (holds cln))\n\
    (holds cln)))))\n\
\n\
\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;\n\
; Natural deduction rules : used for CNF\n\
;\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
\n\
\n\
;; contradiction\n\
\n\
(declare contra\n\
  (! f formula\n\
  (! r1 (th_holds f)\n\
  (! r2 (th_holds (not f))\n\
    (th_holds false)))))\n\
\n\
;; not not\n\
\n\
(declare not_not_intro\n\
  (! f formula\n\
  (! u (th_holds f)\n\
    (th_holds (not (not f))))))\n\
\n\
(declare not_not_elim\n\
  (! f formula\n\
  (! u (th_holds (not (not f)))\n\
    (th_holds f))))\n\
\n\
;; or elimination\n\
\n\
(declare or_elim_1\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds (not f1))\n\
  (! u2 (th_holds (or f1 f2))\n\
    (th_holds f2))))))\n\
\n\
(declare or_elim_2\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds (not f2))\n\
  (! u2 (th_holds (or f1 f2))\n\
    (th_holds f1))))))\n\
\n\
;; and elimination\n\
\n\
(declare and_elim_1\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u (th_holds (and f1 f2))\n\
    (th_holds f1)))))\n\
\n\
(declare and_elim_2\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u (th_holds (and f1 f2))\n\
    (th_holds f2)))))\n\
\n\
;; not impl elimination\n\
\n\
(declare not_impl_elim_1\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u (th_holds (not (impl f1 f2)))\n\
    (th_holds f1)))))\n\
\n\
(declare not_impl_elim_2\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u (th_holds (not (impl f1 f2)))\n\
    (th_holds (not f2))))))\n\
\n\
;; impl elimination\n\
\n\
(declare impl_intro (! f1 formula\n\
                    (! f2 formula\n\
                    (! i1 (! u (th_holds f1)\n\
                              (th_holds f2))\n\
                      (th_holds (impl f1 f2))))))\n\
\n\
(declare impl_elim\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds f1)\n\
  (! u2 (th_holds (impl f1 f2))\n\
    (th_holds f2))))))\n\
\n\
;; iff elimination\n\
\n\
(declare iff_elim_1\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds (iff f1 f2))\n\
    (th_holds (impl f1 f2))))))\n\
\n\
(declare iff_elim_2\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds (iff f1 f2))\n\
    (th_holds (impl f2 f1))))))\n\
\n\
(declare not_iff_elim_1\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds (not f1))\n\
  (! u2 (th_holds (not (iff f1 f2)))\n\
    (th_holds f2))))))\n\
\n\
(declare not_iff_elim_2\n\
  (! f1 formula\n\
  (! f2 formula\n\
  (! u1 (th_holds f1)\n\
  (! u2 (th_holds (not (iff f1 f2)))\n\
    (th_holds (not f2)))))))\n\
\n\
;; ite elimination\n\
\n\
(declare ite_elim_1\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds a)\n\
  (! u2 (th_holds (ifte a b c))\n\
    (th_holds b)))))))\n\
\n\
(declare ite_elim_2\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds (not a))\n\
  (! u2 (th_holds (ifte a b c))\n\
    (th_holds c)))))))\n\
\n\
(declare ite_elim_3\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds (not b))\n\
  (! u2 (th_holds (ifte a b c))\n\
    (th_holds c)))))))\n\
\n\
(declare ite_elim_2n\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds a)\n\
  (! u2 (th_holds (ifte (not a) b c))\n\
    (th_holds c)))))))\n\
\n\
(declare not_ite_elim_1\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds a)\n\
  (! u2 (th_holds (not (ifte a b c)))\n\
    (th_holds (not b))))))))\n\
\n\
(declare not_ite_elim_2\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds (not a))\n\
  (! u2 (th_holds (not (ifte a b c)))\n\
    (th_holds (not c))))))))\n\
\n\
(declare not_ite_elim_3\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds b)\n\
  (! u2 (th_holds (not (ifte a b c)))\n\
    (th_holds (not c))))))))\n\
\n\
(declare not_ite_elim_2n\n\
  (! a formula\n\
  (! b formula\n\
  (! c formula\n\
  (! u1 (th_holds a)\n\
  (! u2 (th_holds (not (ifte (not a) b c)))\n\
    (th_holds (not c))))))))\n\
\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;\n\
; For theory lemmas\n\
; - make a series of assumptions and then derive a contradiction (or false)\n\
; - then the assumptions yield a formula like \"v1 -> v2 -> ... -> vn -> false\"\n\
; - In CNF, it becomes a clause: \"~v1, ~v2, ..., ~vn\"\n\
;\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
\n\
(declare ast\n\
  (! v var\n\
  (! f formula\n\
  (! C clause\n\
  (! r (atom v f)       ;this is specified\n\
  (! u (! o (th_holds f)\n\
         (holds C))\n\
    (holds (clc (neg v) C))))))))\n\
\n\
(declare asf\n\
  (! v var\n\
  (! f formula\n\
  (! C clause\n\
  (! r (atom v f)\n\
  (! u (! o (th_holds (not f))\n\
         (holds C))\n\
    (holds (clc (pos v) C))))))))\n\
    \n\
\n\
\n\
\n\
;; Example:\n\
;;\n\
;; Given theory literals (F1....Fn), and an input formula A of the form (th_holds (or F1 (or F2 .... (or F{n-1} Fn))))).\n\
;;\n\
;; We introduce atoms (a1,...,an) to map boolean literals (v1,...,vn) top literals (F1,...,Fn).\n\
;; Do this at the beginning of the proof:\n\
;;\n\
;; (decl_atom F1 (\\ v1 (\\ a1\n\
;; (decl_atom F2 (\\ v2 (\\ a2\n\
;; ....\n\
;; (decl_atom Fn (\\ vn (\\ an\n\
;;\n\
;;  A is then clausified by the following proof:\n\
;;\n\
;;(satlem _ _\n\
;;(asf _ _ _ a1 (\\ l1\n\
;;(asf _ _ _ a2 (\\ l2\n\
;;...\n\
;;(asf _ _ _ an (\\ ln\n\
;;(clausify_false\n\
;;\n\
;;   (contra _\n\
;;      (or_elim_1 _ _ l{n-1}\n\
;;	...\n\
;;      (or_elim_1 _ _ l2\n\
;; 	(or_elim_1 _ _ l1 A))))) ln)\n\
;;	\n\
;;))))))) (\\ C\n\
;;\n\
;; We now have the free variable C, which should be the clause (v1 V ... V vn).\n\
;;\n\
;; Polarity of literals should be considered, say we have A of the form (th_holds (or (not F1) (or F2 (not F3)))).\n\
;; Where necessary, we use \"ast\" instead of \"asf\", introduce negations by \"not_not_intro\" for pattern matching, and flip\n\
;; the arguments of contra:\n\
;;\n\
;;(satlem _ _\n\
;;(ast _ _ _ a1 (\\ l1\n\
;;(asf _ _ _ a2 (\\ l2\n\
;;(ast _ _ _ a3 (\\ l3\n\
;;(clausify_false\n\
;;\n\
;;   (contra _ l3\n\
;;      (or_elim_1 _ _ l2\n\
;; 	(or_elim_1 _ _ (not_not_intro l1) A))))\n\
;;	\n\
;;))))))) (\\ C\n\
;;\n\
;; C should be the clause (~v1 V v2 V ~v3 )\n\
\n\
\n\
\n\
\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;\n\
; Theory of Equality and Congruence Closure\n\
;\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
; depends on : smt.plf\n\
\n\
; sorts :\n\
\n\
(declare arrow (! s1 sort (! s2 sort sort)))	; function constructor\n\
\n\
; functions :\n\
\n\
(declare apply (! s1 sort\n\
               (! s2 sort\n\
               (! t1 (term (arrow s1 s2))\n\
               (! t2 (term s1)\n\
                (term s2))))))\n\
                \n\
                \n\
; inference rules :\n\
\n\
(declare trust (th_holds false))	; temporary\n\
\n\
(declare refl\n\
  (! s sort\n\
  (! t (term s)\n\
    (th_holds (= s t t)))))\n\
\n\
(declare symm (! s sort\n\
              (! x (term s)\n\
              (! y (term s)\n\
              (! u (th_holds (= _ x y))\n\
                (th_holds (= _ y x)))))))\n\
\n\
(declare trans (! s sort\n\
               (! x (term s)\n\
               (! y (term s)\n\
               (! z (term s)\n\
               (! u (th_holds (= _ x y))\n\
               (! u (th_holds (= _ y z))\n\
                 (th_holds (= _ x z)))))))))\n\
\n\
(declare cong (! s1 sort\n\
              (! s2 sort\n\
              (! a1 (term (arrow s1 s2))\n\
              (! b1 (term (arrow s1 s2))\n\
              (! a2 (term s1)\n\
              (! b2 (term s1)\n\
              (! u1 (th_holds (= _ a1 b1))\n\
              (! u2 (th_holds (= _ a2 b2))\n\
                (th_holds (= _ (apply _ _ a1 a2) (apply _ _ b1 b2))))))))))))\n\
\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
; Examples\n\
\n\
; an example of \"(p1 or p2(0)) and t1=t2(1)\"\n\
;(! p1 (term Bool)\n\
;(! p2 (term (arrow Int Bool))\n\
;(! t1 (term Int)\n\
;(! t2 (term (arrow Int Int))\n\
;(! F (th_holds (and (or (p_app p1) (p_app (apply _ _ p2 0)))\n\
;                    (= _ t1 (apply _ _ t2 1))))\n\
;  ...\n\
\n\
; another example of \"p3(a,b)\"\n\
;(! a (term Int)\n\
;(! b (term Int)\n\
;(! p3 (term (arrow Int (arrow Int Bool)))	; arrow is right assoc.\n\
;(! F (th_holds (p_app (apply _ _ (apply _ _ p3 a) b))) ; apply is left assoc.\n\
;  ...\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;\n\
; Theory of Arrays\n\
;\n\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
; depdends on : th_base.plf\n\
\n\
; sorts\n\
\n\
(declare array (! s1 sort (! s2 sort sort)))	; s1 is index, s2 is element\n\
\n\
; functions\n\
(declare write (! s1 sort\n\
               (! s2 sort\n\
                 (term (arrow (array s1 s2)\n\
                       (arrow s1\n\
                       (arrow s2 (array s1 s2))))))))\n\
\n\
(declare read (! s1 sort\n\
              (! s2 sort\n\
              	(term (arrow (array s1 s2)\n\
               	      (arrow s1 s2))))))\n\
\n\
; inference rules\n\
(declare row1 (! s1 sort\n\
              (! s2 sort\n\
              (! t1 (term (array s1 s2))\n\
              (! t2 (term s1)\n\
              (! t3 (term s2)\n\
              	(th_holds (= _ (apply _ _ (apply _ _ (read s1 s2) (apply _ _ (apply _ _ (apply _ _ (write s1 s2) t1) t2) t3)) t2)\n\
              		       t3))))))))\n\
              	\n\
\n\
(declare row (! s1 sort\n\
             (! s2 sort\n\
             (! t2 (term s1)\n\
             (! t3 (term s1)\n\
             (! t1 (term (array s1 s2))\n\
             (! t4 (term s2)\n\
             (! u (th_holds (not (= _ t2 t3)))\n\
               (th_holds (= _ (apply _ _ (apply _ _ (read s1 s2) (apply _ _ (apply _ _ (apply _ _ (write s1 s2) t1) t2) t4)) t3)\n\
               		      (apply _ _ (apply _ _ (read s1 s2) t1) t3)))))))))))\n\
\n\
(declare ext (! s1 sort\n\
             (! s2 sort\n\
             (! t1 (term (array s1 s2))\n\
             (! t2 (term (array s1 s2))\n\
             (! u1 (! k (term s1)\n\
                   (! u2 (th_holds (or (= _ t1 t2) (not (= _ (apply _ _ (apply _ _ (read s1 s2) t1) k) (apply _ _ (apply _ _ (read s1 s2) t2) k)))))\n\
                     (holds cln)))\n\
               (holds cln)))))))\n\
";

} /* CVC4::proof namespace */
} /* CVC4 namespace */
