(benchmark fuzzsmt
:logic QF_AUFBV
:status unsat
:extrafuns ((v0 BitVec[15]))
:extrafuns ((a1 Array[9:14]))
:formula
(let (?e2 bv37005[16])
(let (?e3 bv1274[11])
(let (?e4 (ite (bvugt v0 (zero_extend[4] ?e3)) bv1[1] bv0[1]))
(let (?e5 (ite (= ?e2 ?e2) bv1[1] bv0[1]))
(let (?e6 (store a1 (extract[8:0] v0) (zero_extend[13] ?e4)))
(let (?e7 (store ?e6 (extract[14:6] v0) (extract[14:1] ?e2)))
(let (?e8 (store ?e6 (extract[8:0] ?e3) (extract[15:2] ?e2)))
(let (?e9 (select a1 (extract[8:0] v0)))
(let (?e10 (store ?e7 (extract[9:1] ?e9) (zero_extend[13] ?e5)))
(let (?e11 (store ?e7 (extract[9:1] ?e9) (zero_extend[3] ?e3)))
(let (?e12 (bvxor ?e2 ?e2))
(let (?e13 (bvmul (zero_extend[15] ?e5) ?e2))
(let (?e14 (ite (bvuge ?e13 (sign_extend[1] v0)) bv1[1] bv0[1]))
(let (?e15 (ite (= (sign_extend[14] ?e4) v0) bv1[1] bv0[1]))
(let (?e16 (bvashr ?e3 (sign_extend[10] ?e14)))
(let (?e17 (bvnand ?e9 (sign_extend[3] ?e16)))
(flet ($e18 (bvsgt ?e2 (sign_extend[15] ?e5)))
(flet ($e19 (distinct (sign_extend[2] ?e17) ?e12))
(flet ($e20 (bvult ?e17 ?e17))
(flet ($e21 (bvsge ?e16 (zero_extend[10] ?e14)))
(flet ($e22 (bvsge v0 (zero_extend[4] ?e16)))
(flet ($e23 (bvuge (zero_extend[14] ?e4) v0))
(flet ($e24 (bvsle (sign_extend[2] ?e17) ?e12))
(flet ($e25 (= ?e13 (zero_extend[2] ?e17)))
(flet ($e26 (bvsgt v0 (sign_extend[14] ?e5)))
(flet ($e27 (distinct ?e13 ?e13))
(flet ($e28 (bvule ?e13 (zero_extend[5] ?e16)))
(flet ($e29 (bvule ?e17 ?e17))
(flet ($e30 (bvsle ?e13 (sign_extend[15] ?e4)))
(flet ($e31 (bvsge ?e2 (sign_extend[5] ?e3)))
(flet ($e32 (bvule ?e13 (sign_extend[5] ?e3)))
(flet ($e33 (bvule ?e13 (zero_extend[2] ?e17)))
(flet ($e34 (= (sign_extend[14] ?e14) v0))
(flet ($e35 (bvsgt ?e3 (zero_extend[10] ?e15)))
(flet ($e36 (bvuge ?e9 (sign_extend[13] ?e15)))
(flet ($e37 (not $e20))
(flet ($e38 (and $e30 $e22))
(flet ($e39 (not $e33))
(flet ($e40 (xor $e28 $e36))
(flet ($e41 (implies $e37 $e37))
(flet ($e42 (xor $e40 $e18))
(flet ($e43 (or $e25 $e38))
(flet ($e44 (iff $e43 $e23))
(flet ($e45 (if_then_else $e27 $e32 $e34))
(flet ($e46 (or $e24 $e19))
(flet ($e47 (iff $e46 $e21))
(flet ($e48 (or $e44 $e41))
(flet ($e49 (iff $e39 $e26))
(flet ($e50 (implies $e49 $e48))
(flet ($e51 (or $e42 $e42))
(flet ($e52 (xor $e35 $e31))
(flet ($e53 (iff $e47 $e52))
(flet ($e54 (implies $e53 $e29))
(flet ($e55 (if_then_else $e51 $e50 $e51))
(flet ($e56 (and $e55 $e54))
(flet ($e57 (xor $e56 $e56))
(flet ($e58 (not $e57))
(flet ($e59 (and $e58 $e45))
$e59
)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

