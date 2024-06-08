/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

In the "generic" implementation, vector types are always 
defined as homogeneous aggregates. Specifically, structs with 
1, 2, 4, 8, 16, 32, 64, or 128 members, each representing a
lane. For targets with a little endian integer representation,
the vector elements will correspond in memory to the array 
index.

    Vdhu        x = {0};
    uint16_t    y[4] = {0};
    offsetof(Vdhu, K0) == (y+0)-y;
    offsetof(Vdhu, K1) == (y+1)-y;
    offsetof(Vdhu, K2) == (y+2)-y;
    offsetof(Vdhu, K3) == (y+3)-y;

For targets with big endian integers, the lowest vector lane
number will equal the highest valid array index, which allows
safely reinterpret casting two differently sized views of the
same vector, just like is possibly for little endian. E.g.

    union {
        Vdhu H;
        Vdwu W;
    } x = {.H=newldhu(12345, 54321)};
    x.W.K0 == x
    x.H.K0 == 12345 (because x[0:16] is 12345)
    x.H.K2 == x.
    
Remember, just because at present the vector types are so
well defined doesn't mean newl/newr shouldn't be used to 
construct them. At least in user code.

CHANGES:

24-04-17
*   created anyop.h
*   implemented absu, addl, cvhs, cvhz, newl, asbu, and asbi

24-05-02
*   partially implemented get1

24-05-03
*   reimplemented asbu and asbi
*   implemented astv, asyu, asbc, ashu, ashi, ashf, aswu, 
    aswi, aswf, asdu, asdi, asdf, shll, shrs
*   added VEC1TIZE_V for operations like shll and shrs

24-05-04
*   added include of "allop.h"

*/

#define     SPC_NO_CEQSZ
#define     SPC_NO_TSTSZ
#define     SPC_NO_DUPW
#define     SPC_NO_DUPD
#define     SPC_NO_DUPQ

#define     SPC_NO_GET1

#define     SPC_NO_LUNN
#define     SPC_NO_LUNW
#define     SPC_NO_LUND
#define     SPC_NO_LUNQ

#include "allop.h"

#define MY_VEC1IZE1(T, F, V)   \
(                   \
    (T)             \
    {               \
        .K0=F(V.K0),\
    }               \
)

#define MY_VEC1IZE2(T, F, V)   \
(                   \
    (T)             \
    {               \
        .K0=F(V.K0),\
        .K1=F(V.K1),\
    }               \
)

#define MY_VEC1IZE4(T, F, V) \
(                   \
    (T)             \
    {               \
        .K0=F(V.K0),\
        .K1=F(V.K1),\
        .K2=F(V.K2),\
        .K3=F(V.K3),\
    }               \
)

#define MY_VEC1IZE8(T, F, V) \
(                   \
    (T)             \
    {               \
        .K0=F(V.K0),\
        .K1=F(V.K1),\
        .K2=F(V.K2),\
        .K3=F(V.K3),\
        .K4=F(V.K4),\
        .K5=F(V.K5),\
        .K6=F(V.K6),\
        .K7=F(V.K7),\
    }               \
)

#define MY_VEC1IZE16(T, F, V) \
(                       \
    (T)                 \
    {                   \
        .K0 =F(V.K0),   \
        .K1 =F(V.K1),   \
        .K2 =F(V.K2),   \
        .K3 =F(V.K3),   \
        .K4 =F(V.K4),   \
        .K5 =F(V.K5),   \
        .K6 =F(V.K6),   \
        .K7 =F(V.K7),   \
        .K8 =F(V.K8),   \
        .K9 =F(V.K9),   \
        .K10=F(V.K10),  \
        .K11=F(V.K11),  \
        .K12=F(V.K12),  \
        .K13=F(V.K13),  \
        .K14=F(V.K14),  \
        .K15=F(V.K15),  \
    }                   \
)


#define MY_VEC1IZE1V(T, F, V, ...)   \
(                                   \
    (T)                             \
    {                               \
        .K0=F(V.K0, __VA_ARGS__),   \
    }                               \
)

#define MY_VEC1IZE2V(T, F, V, ...)   \
(                                   \
    (T)                             \
    {                               \
        .K0=F(V.K0, __VA_ARGS__),   \
        .K1=F(V.K1, __VA_ARGS__),   \
    }                               \
)

#define MY_VEC1IZE4V(T, F, V, ...)   \
(                                   \
    (T)                             \
    {                               \
        .K0=F(V.K0, __VA_ARGS__),   \
        .K1=F(V.K1, __VA_ARGS__),   \
        .K2=F(V.K2, __VA_ARGS__),   \
        .K3=F(V.K3, __VA_ARGS__),   \
    }                               \
)

#define MY_VEC1IZE8V(T, F, V, ...)   \
(                                   \
    (T)                             \
    {                               \
        .K0=F(V.K0, __VA_ARGS__),   \
        .K1=F(V.K1, __VA_ARGS__),   \
        .K2=F(V.K2, __VA_ARGS__),   \
        .K3=F(V.K3, __VA_ARGS__),   \
        .K4=F(V.K4, __VA_ARGS__),   \
        .K5=F(V.K5, __VA_ARGS__),   \
        .K6=F(V.K6, __VA_ARGS__),   \
        .K7=F(V.K7, __VA_ARGS__),   \
    }                               \
)

#define MY_VEC1IZE16V(T, F, V, ...)  \
(                                   \
    (T)                             \
    {                               \
        .K0= F(V.K0, __VA_ARGS__),  \
        .K1= F(V.K1, __VA_ARGS__),  \
        .K2= F(V.K2, __VA_ARGS__),  \
        .K3= F(V.K3, __VA_ARGS__),  \
        .K4= F(V.K4, __VA_ARGS__),  \
        .K5= F(V.K5, __VA_ARGS__),  \
        .K6= F(V.K6, __VA_ARGS__),  \
        .K7= F(V.K7, __VA_ARGS__),  \
        .K9= F(V.K9, __VA_ARGS__),  \
        .K10=F(V.K10,__VA_ARGS__),  \
        .K11=F(V.K11,__VA_ARGS__),  \
        .K12=F(V.K12,__VA_ARGS__),  \
        .K13=F(V.K13,__VA_ARGS__),  \
        .K14=F(V.K14,__VA_ARGS__),  \
        .K15=F(V.K15,__VA_ARGS__),  \
    }                               \
)

#define MY_VEC2IZE1(T, F, A, B) \
(                               \
    (T)                         \
    {                           \
        .K0 = F(A.K0, B.K0),    \
    }                           \
)

#define MY_VEC2IZE2(T, F, A, B) \
(                               \
    (T)                         \
    {                           \
        .K0 =F(A.K0, B.K0),     \
        .K1 =F(A.K1, B.K1),     \
    }                           \
)

#define MY_VEC2IZE4(T, F, A, B) \
(                           \
    (T)                     \
    {                       \
        .K0 =F(A.K0,B.K0),  \
        .K1 =F(A.K1,B.K1),  \
        .K2 =F(A.K2,B.K2),  \
        .K3 =F(A.K3,B.K3),  \
    }                       \
)

#define MY_VEC2IZE8(T, F, A, B) \
(                           \
    (T)                     \
    {                       \
        .K0 =F(A.K0,B.K0),  \
        .K1 =F(A.K1,B.K1),  \
        .K2 =F(A.K2,B.K2),  \
        .K3 =F(A.K3,B.K3),  \
        .K4 =F(A.K4,B.K4),  \
        .K5 =F(A.K5,B.K5),  \
        .K6 =F(A.K6,B.K6),  \
        .K7 =F(A.K7,B.K7),  \
    }                       \
)

#define MY_VEC2IZE16(T, F, A, B)    \
(                               \
    (T)                         \
    {                           \
        .K0 =F(A.K0, B.K0),     \
        .K1 =F(A.K1, B.K1),     \
        .K2 =F(A.K2, B.K2),     \
        .K3 =F(A.K3, B.K3),     \
        .K4 =F(A.K4, B.K4),     \
        .K5 =F(A.K5, B.K5),     \
        .K6 =F(A.K6, B.K6),     \
        .K7 =F(A.K7, B.K7),     \
        .K8 =F(A.K8, B.K8),     \
        .K9 =F(A.K9, B.K9),     \
        .K10=F(A.K10,B.K10),    \
        .K11=F(A.K11,B.K11),    \
        .K12=F(A.K12,B.K12),    \
        .K13=F(A.K13,B.K13),    \
        .K14=F(A.K14,B.K14),    \
        .K15=F(A.K15,B.K15),    \
    }                           \
)


#if 0 // _ENTER_ANY_ASTV
{
#endif

INLINE(Vwwu,  UINT_ASTV)   (uint x) {return  ((WORD_TYPE){.U=x}).M1.U;}
INLINE(Vwwi,   INT_ASTV)    (int x) {return  ((WORD_TYPE){.I=x}).M1.I;}
INLINE(Vwwf,   FLT_ASTV)  (float x) {return  ((WORD_TYPE){.F=x}).M1.F;}
INLINE(Vddf,   DBL_ASTV) (double x) {return  ((DWRD_TYPE){.F=x}).M1.F;}

#if DWRD_NLONG == 1

INLINE(Vddu, ULONG_ASTV)  (ulong x) {return  ((DWRD_TYPE){.U=x}).M1.U;}
INLINE(Vddi,  LONG_ASTV)   (long x) {return  ((DWRD_TYPE){.I=x}).M1.I;}

#else

INLINE(Vwwu, ULONG_ASTV)  (ulong x) {return  ((WORD_TYPE){.U=x}).M1.U;}
INLINE(Vwwi,  LONG_ASTV)   (long x) {return  ((WORD_TYPE){.I=x}).M1.I;}

#endif

#if QUAD_NLLONG == 1

INLINE(Vqqu,ULLONG_ASTV) (ullong x) {return  ((QUAD_TYPE){.U=x}).M1.U;}
INLINE(Vqqi, LLONG_ASTV)  (llong x) {return  ((QUAD_TYPE){.I=x}).M1.I;}

#else

INLINE(Vddu,ULLONG_ASTV) (ullong x) {return  ((DWRD_TYPE){.U=x}).M1.U;}
INLINE(Vddi, LLONG_ASTV)  (llong x) {return  ((DWRD_TYPE){.I=x}).M1.I;}

#endif

INLINE(uint32_t,VWWU_ASTV) (Vwwu v) {return v.K0;}
INLINE( int32_t,VWWI_ASTV) (Vwwi v) {return v.K0;}
INLINE(   float,VWWF_ASTV) (Vwwf v) {return v.K0;}

INLINE(uint64_t,VDDU_ASTV) (Vddu v) {return v.K0;}
INLINE( int64_t,VDDI_ASTV) (Vddi v) {return v.K0;}
INLINE(  double,VDDF_ASTV) (Vddf v) {return v.K0;}

#if 0 // _LEAVE_ANY_ASTV
}
#endif

#if 0 // _ENTER_ANY_ASYU
{
#endif

//          VWYU_ASYU
INLINE(Vwyu,VWBU_ASYU) (Vwbu v) {return  ((WORD_TYPE){.M4. U=v}).M32.U;}
INLINE(Vwyu,VWBI_ASYU) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M32.U;}
INLINE(Vwyu,VWBC_ASYU) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M32.U;}
INLINE(Vwyu,VWHU_ASYU) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M32.U;}
INLINE(Vwyu,VWHI_ASYU) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M32.U;}
INLINE(Vwyu,VWHF_ASYU) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M32.U;}
INLINE(Vwyu,VWWU_ASYU) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M32.U;}
INLINE(Vwyu,VWWI_ASYU) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M32.U;}
INLINE(Vwyu,VWWF_ASYU) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M32.U;}

//          VDYU_ASYU
INLINE(Vdyu,VDBU_ASYU) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M64.U;}
INLINE(Vdyu,VDBI_ASYU) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M64.U;}
INLINE(Vdyu,VDBC_ASYU) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M64.U;}
INLINE(Vdyu,VDHU_ASYU) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M64.U;}
INLINE(Vdyu,VDHI_ASYU) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M64.U;}
INLINE(Vdyu,VDHF_ASYU) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M64.U;}
INLINE(Vdyu,VDWU_ASYU) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M64.U;}
INLINE(Vdyu,VDWI_ASYU) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M64.U;}
INLINE(Vdyu,VDWF_ASYU) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M64.U;}
INLINE(Vdyu,VDDU_ASYU) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M64.U;}
INLINE(Vdyu,VDDI_ASYU) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M64.U;}
INLINE(Vdyu,VDDF_ASYU) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M64.U;}

//          VQYU_ASYU
INLINE(Vqyu,VQBU_ASYU) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M128.U;}
INLINE(Vqyu,VQBI_ASYU) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M128.U;}
INLINE(Vqyu,VQBC_ASYU) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M128.U;}
INLINE(Vqyu,VQHU_ASYU) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M128.U;}
INLINE(Vqyu,VQHI_ASYU) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M128.U;}
INLINE(Vqyu,VQHF_ASYU) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M128.U;}
INLINE(Vqyu,VQWU_ASYU) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M128.U;}
INLINE(Vqyu,VQWI_ASYU) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M128.U;}
INLINE(Vqyu,VQWF_ASYU) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M128.U;}
INLINE(Vqyu,VQDU_ASYU) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M128.U;}
INLINE(Vqyu,VQDI_ASYU) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M128.U;}
INLINE(Vqyu,VQDF_ASYU) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M128.U;}

#if 0 // _LEAVE_ANY_ASYU
}
#endif

#if 0 // _ENTER_ANY_ASBU
{
#endif

INLINE(Vwbu,VWYU_ASBU) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M4.U;}
//          VWBU_ASBU
INLINE(Vwbu,VWBI_ASBU) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M4.U;}
INLINE(Vwbu,VWBC_ASBU) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M4.U;}
INLINE(Vwbu,VWHU_ASBU) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M4.U;}
INLINE(Vwbu,VWHI_ASBU) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M4.U;}
INLINE(Vwbu,VWHF_ASBU) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M4.U;}
INLINE(Vwbu,VWWU_ASBU) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M4.U;}
INLINE(Vwbu,VWWI_ASBU) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M4.U;}
INLINE(Vwbu,VWWF_ASBU) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M4.U;}

INLINE(Vdbu,VDYU_ASBU) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M8.U;}
//          VDBU_ASBU
INLINE(Vdbu,VDBI_ASBU) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M8.U;}
INLINE(Vdbu,VDBC_ASBU) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M8.U;}
INLINE(Vdbu,VDHU_ASBU) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M8.U;}
INLINE(Vdbu,VDHI_ASBU) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M8.U;}
INLINE(Vdbu,VDHF_ASBU) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M8.U;}
INLINE(Vdbu,VDWU_ASBU) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M8.U;}
INLINE(Vdbu,VDWI_ASBU) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M8.U;}
INLINE(Vdbu,VDWF_ASBU) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M8.U;}
INLINE(Vdbu,VDDU_ASBU) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M8.U;}
INLINE(Vdbu,VDDI_ASBU) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M8.U;}
INLINE(Vdbu,VDDF_ASBU) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M8.U;}

INLINE(Vqbu,VQYU_ASBU) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M16.U;}
//          VQBU_ASBU
INLINE(Vqbu,VQBI_ASBU) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M16.U;}
INLINE(Vqbu,VQBC_ASBU) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M16.U;}
INLINE(Vqbu,VQHU_ASBU) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M16.U;}
INLINE(Vqbu,VQHI_ASBU) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M16.U;}
INLINE(Vqbu,VQHF_ASBU) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M16.U;}
INLINE(Vqbu,VQWU_ASBU) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M16.U;}
INLINE(Vqbu,VQWI_ASBU) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M16.U;}
INLINE(Vqbu,VQWF_ASBU) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M16.U;}
INLINE(Vqbu,VQDU_ASBU) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M16.U;}
INLINE(Vqbu,VQDI_ASBU) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M16.U;}
INLINE(Vqbu,VQDF_ASBU) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M16.U;}

#if 0 // _LEAVE_ANY_ASBU
}
#endif

#if 0 // _ENTER_ANY_ASBI
{
#endif

INLINE(Vwbi,VWYU_ASBI) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M4.I;}
INLINE(Vwbi,VWBU_ASBI) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M4.I;}
//          VWBI_ASBI
INLINE(Vwbi,VWBC_ASBI) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M4.I;}
INLINE(Vwbi,VWHU_ASBI) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M4.I;}
INLINE(Vwbi,VWHI_ASBI) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M4.I;}
INLINE(Vwbi,VWHF_ASBI) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M4.I;}
INLINE(Vwbi,VWWU_ASBI) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M4.I;}
INLINE(Vwbi,VWWI_ASBI) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M4.I;}
INLINE(Vwbi,VWWF_ASBI) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M4.I;}

INLINE(Vdbi,VDYU_ASBI) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M8.I;}
INLINE(Vdbi,VDBU_ASBI) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M8.I;}
//          VDBI_ASBI
INLINE(Vdbi,VDBC_ASBI) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M8.I;}
INLINE(Vdbi,VDHU_ASBI) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M8.I;}
INLINE(Vdbi,VDHI_ASBI) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M8.I;}
INLINE(Vdbi,VDHF_ASBI) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M8.I;}
INLINE(Vdbi,VDWU_ASBI) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M8.I;}
INLINE(Vdbi,VDWI_ASBI) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M8.I;}
INLINE(Vdbi,VDWF_ASBI) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M8.I;}
INLINE(Vdbi,VDDU_ASBI) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M8.I;}
INLINE(Vdbi,VDDI_ASBI) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M8.I;}
INLINE(Vdbi,VDDF_ASBI) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M8.I;}

INLINE(Vqbi,VQYU_ASBI) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M16.I;}
INLINE(Vqbi,VQBU_ASBI) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M16.I;}
//          VQBU_ASBI
INLINE(Vqbi,VQBC_ASBI) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M16.I;}
INLINE(Vqbi,VQHU_ASBI) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M16.I;}
INLINE(Vqbi,VQHI_ASBI) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M16.I;}
INLINE(Vqbi,VQHF_ASBI) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M16.I;}
INLINE(Vqbi,VQWU_ASBI) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M16.I;}
INLINE(Vqbi,VQWI_ASBI) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M16.I;}
INLINE(Vqbi,VQWF_ASBI) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M16.I;}
INLINE(Vqbi,VQDU_ASBI) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M16.I;}
INLINE(Vqbi,VQDI_ASBI) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M16.I;}
INLINE(Vqbi,VQDF_ASBI) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M16.I;}

#if 0 // _LEAVE_ANY_ASBI
}
#endif

#if 0 // _ENTER_ANY_ASBC
{
#endif

INLINE(Vwbc,VWYU_ASBC) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M4.C;}
INLINE(Vwbc,VWBU_ASBC) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M4.C;}
INLINE(Vwbc,VWBI_ASBC) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M4.C;}
//          VWBC_ASBC
INLINE(Vwbc,VWHU_ASBC) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M4.C;}
INLINE(Vwbc,VWHI_ASBC) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M4.C;}
INLINE(Vwbc,VWHF_ASBC) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M4.C;}
INLINE(Vwbc,VWWU_ASBC) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M4.C;}
INLINE(Vwbc,VWWI_ASBC) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M4.C;}
INLINE(Vwbc,VWWF_ASBC) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M4.C;}

INLINE(Vdbc,VDYU_ASBC) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M8.C;}
INLINE(Vdbc,VDBU_ASBC) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M8.C;}
INLINE(Vdbc,VDBI_ASBC) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M8.C;}
//          VDBC_ASBC
INLINE(Vdbc,VDHU_ASBC) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M8.C;}
INLINE(Vdbc,VDHI_ASBC) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M8.C;}
INLINE(Vdbc,VDHF_ASBC) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M8.C;}
INLINE(Vdbc,VDWU_ASBC) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M8.C;}
INLINE(Vdbc,VDWI_ASBC) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M8.C;}
INLINE(Vdbc,VDWF_ASBC) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M8.C;}
INLINE(Vdbc,VDDU_ASBC) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M8.C;}
INLINE(Vdbc,VDDI_ASBC) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M8.C;}
INLINE(Vdbc,VDDF_ASBC) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M8.C;}

INLINE(Vqbc,VQYU_ASBC) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M16.C;}
INLINE(Vqbc,VQBU_ASBC) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M16.C;}
INLINE(Vqbc,VQBI_ASBC) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M16.C;}
//          VQBC_ASBC
INLINE(Vqbc,VQHU_ASBC) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M16.C;}
INLINE(Vqbc,VQHI_ASBC) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M16.C;}
INLINE(Vqbc,VQHF_ASBC) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M16.C;}
INLINE(Vqbc,VQWU_ASBC) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M16.C;}
INLINE(Vqbc,VQWI_ASBC) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M16.C;}
INLINE(Vqbc,VQWF_ASBC) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M16.C;}
INLINE(Vqbc,VQDU_ASBC) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M16.C;}
INLINE(Vqbc,VQDI_ASBC) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M16.C;}
INLINE(Vqbc,VQDF_ASBC) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M16.C;}

#if 0 // _LEAVE_ANY_ASBC
}
#endif

#if 0 // _ENTER_ANY_ASHU
{
#endif

INLINE(Vwhu,VWYU_ASHU) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M2.U;}
INLINE(Vwhu,VWBU_ASHU) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M2.U;}
INLINE(Vwhu,VWBI_ASHU) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M2.U;}
INLINE(Vwhu,VWBC_ASHU) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M2.U;}
//          VWHU_ASHU
INLINE(Vwhu,VWHI_ASHU) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M2.U;}
INLINE(Vwhu,VWHF_ASHU) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M2.U;}
INLINE(Vwhu,VWWU_ASHU) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M2.U;}
INLINE(Vwhu,VWWI_ASHU) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M2.U;}
INLINE(Vwhu,VWWF_ASHU) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M2.U;}

INLINE(Vdhu,VDYU_ASHU) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M4.U;}
INLINE(Vdhu,VDBU_ASHU) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M4.U;}
INLINE(Vdhu,VDBI_ASHU) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M4.U;}
INLINE(Vdhu,VDBC_ASHU) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M4.U;}
//          VDHU_ASHU
INLINE(Vdhu,VDHI_ASHU) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M4.U;}
INLINE(Vdhu,VDHF_ASHU) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M4.U;}
INLINE(Vdhu,VDWU_ASHU) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M4.U;}
INLINE(Vdhu,VDWI_ASHU) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M4.U;}
INLINE(Vdhu,VDWF_ASHU) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M4.U;}
INLINE(Vdhu,VDDU_ASHU) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M4.U;}
INLINE(Vdhu,VDDI_ASHU) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M4.U;}
INLINE(Vdhu,VDDF_ASHU) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M4.U;}

INLINE(Vqhu,VQYU_ASHU) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M8.U;}
INLINE(Vqhu,VQBU_ASHU) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M8.U;}
INLINE(Vqhu,VQBI_ASHU) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M8.U;}
INLINE(Vqhu,VQBC_ASHU) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M8.U;}
//          VQHU_ASHU
INLINE(Vqhu,VQHI_ASHU) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M8.U;}
INLINE(Vqhu,VQHF_ASHU) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M8.U;}
INLINE(Vqhu,VQWU_ASHU) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M8.U;}
INLINE(Vqhu,VQWI_ASHU) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M8.U;}
INLINE(Vqhu,VQWF_ASHU) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M8.U;}
INLINE(Vqhu,VQDU_ASHU) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M8.U;}
INLINE(Vqhu,VQDI_ASHU) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M8.U;}
INLINE(Vqhu,VQDF_ASHU) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M8.U;}

#if 0 // _LEAVE_ANY_ASHU
}
#endif

#if 0 // _ENTER_ANY_ASHI
{
#endif

INLINE(Vwhi,VWYU_ASHI) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M2.I;}
INLINE(Vwhi,VWBU_ASHI) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M2.I;}
INLINE(Vwhi,VWBI_ASHI) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M2.I;}
INLINE(Vwhi,VWBC_ASHI) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M2.I;}
INLINE(Vwhi,VWHU_ASHI) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M2.I;}
//          VWHI_ASHI
INLINE(Vwhi,VWHF_ASHI) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M2.I;}
INLINE(Vwhi,VWWU_ASHI) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M2.I;}
INLINE(Vwhi,VWWI_ASHI) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M2.I;}
INLINE(Vwhi,VWWF_ASHI) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M2.I;}

INLINE(Vdhi,VDYU_ASHI) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M4.I;}
INLINE(Vdhi,VDBU_ASHI) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M4.I;}
INLINE(Vdhi,VDBI_ASHI) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M4.I;}
INLINE(Vdhi,VDBC_ASHI) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M4.I;}
INLINE(Vdhi,VDHU_ASHI) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M4.I;}
//          VDHI_ASHI
INLINE(Vdhi,VDHF_ASHI) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M4.I;}
INLINE(Vdhi,VDWU_ASHI) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M4.I;}
INLINE(Vdhi,VDWI_ASHI) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M4.I;}
INLINE(Vdhi,VDWF_ASHI) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M4.I;}
INLINE(Vdhi,VDDU_ASHI) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M4.I;}
INLINE(Vdhi,VDDI_ASHI) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M4.I;}
INLINE(Vdhi,VDDF_ASHI) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M4.I;}

INLINE(Vqhi,VQYU_ASHI) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M8.I;}
INLINE(Vqhi,VQBU_ASHI) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M8.I;}
INLINE(Vqhi,VQBI_ASHI) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M8.I;}
INLINE(Vqhi,VQBC_ASHI) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M8.I;}
INLINE(Vqhi,VQHU_ASHI) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M8.I;}
//          VQHI_ASHI
INLINE(Vqhi,VQHF_ASHI) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M8.I;}
INLINE(Vqhi,VQWU_ASHI) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M8.I;}
INLINE(Vqhi,VQWI_ASHI) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M8.I;}
INLINE(Vqhi,VQWF_ASHI) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M8.I;}
INLINE(Vqhi,VQDU_ASHI) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M8.I;}
INLINE(Vqhi,VQDI_ASHI) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M8.I;}
INLINE(Vqhi,VQDF_ASHI) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M8.I;}

#if 0 // _LEAVE_ANY_ASHI
}
#endif

#if 0 // _ENTER_ANY_ASHF
{
#endif

INLINE(Vwhf,VWYU_ASHF) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M2.F;}
INLINE(Vwhf,VWBU_ASHF) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M2.F;}
INLINE(Vwhf,VWBI_ASHF) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M2.F;}
INLINE(Vwhf,VWBC_ASHF) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M2.F;}
INLINE(Vwhf,VWHU_ASHF) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M2.F;}
INLINE(Vwhf,VWHI_ASHF) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M2.F;}
//          VWHF_ASHF
INLINE(Vwhf,VWWU_ASHF) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M2.F;}
INLINE(Vwhf,VWWI_ASHF) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M2.F;}
INLINE(Vwhf,VWWF_ASHF) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M2.F;}

INLINE(Vdhf,VDYU_ASHF) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M4.F;}
INLINE(Vdhf,VDBU_ASHF) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M4.F;}
INLINE(Vdhf,VDBI_ASHF) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M4.F;}
INLINE(Vdhf,VDBC_ASHF) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M4.F;}
INLINE(Vdhf,VDHU_ASHF) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M4.F;}
INLINE(Vdhf,VDHI_ASHF) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M4.F;}
//          VDHF_ASHF
INLINE(Vdhf,VDWU_ASHF) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M4.F;}
INLINE(Vdhf,VDWI_ASHF) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M4.F;}
INLINE(Vdhf,VDWF_ASHF) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M4.F;}
INLINE(Vdhf,VDDU_ASHF) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M4.F;}
INLINE(Vdhf,VDDI_ASHF) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M4.F;}
INLINE(Vdhf,VDDF_ASHF) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M4.F;}

INLINE(Vqhf,VQYU_ASHF) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M8.F;}
INLINE(Vqhf,VQBU_ASHF) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M8.F;}
INLINE(Vqhf,VQBI_ASHF) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M8.F;}
INLINE(Vqhf,VQBC_ASHF) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M8.F;}
INLINE(Vqhf,VQHU_ASHF) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M8.F;}
INLINE(Vqhf,VQHI_ASHF) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M8.F;}
//          VQHF_ASHF
INLINE(Vqhf,VQWU_ASHF) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M8.F;}
INLINE(Vqhf,VQWI_ASHF) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M8.F;}
INLINE(Vqhf,VQWF_ASHF) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M8.F;}
INLINE(Vqhf,VQDU_ASHF) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M8.F;}
INLINE(Vqhf,VQDI_ASHF) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M8.F;}
INLINE(Vqhf,VQDF_ASHF) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M8.F;}

#if 0 // _LEAVE_ANY_ASHF
}
#endif

#if 0 // _ENTER_ANY_ASWU
{
#endif

INLINE(Vwwu,VWYU_ASWU) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M1.U;}
INLINE(Vwwu,VWBU_ASWU) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M1.U;}
INLINE(Vwwu,VWBI_ASWU) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M1.U;}
INLINE(Vwwu,VWBC_ASWU) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M1.U;}
INLINE(Vwwu,VWHU_ASWU) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M1.U;}
INLINE(Vwwu,VWHI_ASWU) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M1.U;}
INLINE(Vwwu,VWHF_ASWU) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M1.U;}
//          VWWU_ASWU
INLINE(Vwwu,VWWI_ASWU) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M1.U;}
INLINE(Vwwu,VWWF_ASWU) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M1.U;}

INLINE(Vdwu,VDYU_ASWU) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M2.U;}
INLINE(Vdwu,VDBU_ASWU) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M2.U;}
INLINE(Vdwu,VDBI_ASWU) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M2.U;}
INLINE(Vdwu,VDBC_ASWU) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M2.U;}
INLINE(Vdwu,VDHU_ASWU) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M2.U;}
INLINE(Vdwu,VDHI_ASWU) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M2.U;}
INLINE(Vdwu,VDHF_ASWU) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M2.U;}
//          VDWU_ASWU
INLINE(Vdwu,VDWI_ASWU) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M2.U;}
INLINE(Vdwu,VDWF_ASWU) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M2.U;}
INLINE(Vdwu,VDDU_ASWU) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M2.U;}
INLINE(Vdwu,VDDI_ASWU) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M2.U;}
INLINE(Vdwu,VDDF_ASWU) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M2.U;}

INLINE(Vqwu,VQYU_ASWU) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M4.U;}
INLINE(Vqwu,VQBU_ASWU) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M4.U;}
INLINE(Vqwu,VQBI_ASWU) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M4.U;}
INLINE(Vqwu,VQBC_ASWU) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M4.U;}
INLINE(Vqwu,VQHU_ASWU) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M4.U;}
INLINE(Vqwu,VQHI_ASWU) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M4.U;}
INLINE(Vqwu,VQHF_ASWU) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M4.U;}
//          VQWU_ASWU
INLINE(Vqwu,VQWI_ASWU) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M4.U;}
INLINE(Vqwu,VQWF_ASWU) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M4.U;}
INLINE(Vqwu,VQDU_ASWU) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M4.U;}
INLINE(Vqwu,VQDI_ASWU) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M4.U;}
INLINE(Vqwu,VQDF_ASWU) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M4.U;}

#if 0 // _LEAVE_ANY_ASWU
}
#endif

#if 0 // _ENTER_ANY_ASWI
{
#endif

INLINE(Vwwi,VWYU_ASWI) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M1.I;}
INLINE(Vwwi,VWBU_ASWI) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M1.I;}
INLINE(Vwwi,VWBI_ASWI) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M1.I;}
INLINE(Vwwi,VWBC_ASWI) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M1.I;}
INLINE(Vwwi,VWHU_ASWI) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M1.I;}
INLINE(Vwwi,VWHI_ASWI) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M1.I;}
INLINE(Vwwi,VWHF_ASWI) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M1.I;}
INLINE(Vwwi,VWWU_ASWI) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M1.I;}
//          VWWU_ASWI
INLINE(Vwwi,VWWF_ASWI) (Vwwf v) {return  ((WORD_TYPE){.M1 .F=v}).M1.I;}

INLINE(Vdwi,VDYU_ASWI) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M2.I;}
INLINE(Vdwi,VDBU_ASWI) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M2.I;}
INLINE(Vdwi,VDBI_ASWI) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M2.I;}
INLINE(Vdwi,VDBC_ASWI) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M2.I;}
INLINE(Vdwi,VDHU_ASWI) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M2.I;}
INLINE(Vdwi,VDHI_ASWI) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M2.I;}
INLINE(Vdwi,VDHF_ASWI) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M2.I;}
INLINE(Vdwi,VDWU_ASWI) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M2.I;}
//          VDWI_ASWI
INLINE(Vdwi,VDWF_ASWI) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M2.I;}
INLINE(Vdwi,VDDU_ASWI) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M2.I;}
INLINE(Vdwi,VDDI_ASWI) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M2.I;}
INLINE(Vdwi,VDDF_ASWI) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M2.I;}

INLINE(Vqwi,VQYU_ASWI) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M4.I;}
INLINE(Vqwi,VQBU_ASWI) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M4.I;}
INLINE(Vqwi,VQBI_ASWI) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M4.I;}
INLINE(Vqwi,VQBC_ASWI) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M4.I;}
INLINE(Vqwi,VQHU_ASWI) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M4.I;}
INLINE(Vqwi,VQHI_ASWI) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M4.I;}
INLINE(Vqwi,VQHF_ASWI) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M4.I;}
INLINE(Vqwi,VQWU_ASWI) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M4.I;}
//          VQWI_ASWI
INLINE(Vqwi,VQWF_ASWI) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M4.I;}
INLINE(Vqwi,VQDU_ASWI) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M4.I;}
INLINE(Vqwi,VQDI_ASWI) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M4.I;}
INLINE(Vqwi,VQDF_ASWI) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M4.I;}

#if 0 // _LEAVE_ANY_ASWI
}
#endif

#if 0 // _ENTER_ANY_ASWF
{
#endif

INLINE(Vwwf,VWYU_ASWF) (Vwyu v) {return  ((WORD_TYPE){.M32.U=v}).M1.F;}
INLINE(Vwwf,VWBU_ASWF) (Vwbu v) {return  ((WORD_TYPE){.M4 .U=v}).M1.F;}
INLINE(Vwwf,VWBI_ASWF) (Vwbi v) {return  ((WORD_TYPE){.M4 .I=v}).M1.F;}
INLINE(Vwwf,VWBC_ASWF) (Vwbc v) {return  ((WORD_TYPE){.M4 .C=v}).M1.F;}
INLINE(Vwwf,VWHU_ASWF) (Vwhu v) {return  ((WORD_TYPE){.M2 .U=v}).M1.F;}
INLINE(Vwwf,VWHI_ASWF) (Vwhi v) {return  ((WORD_TYPE){.M2 .I=v}).M1.F;}
INLINE(Vwwf,VWHF_ASWF) (Vwhf v) {return  ((WORD_TYPE){.M2 .F=v}).M1.F;}
INLINE(Vwwf,VWWU_ASWF) (Vwwu v) {return  ((WORD_TYPE){.M1 .U=v}).M1.F;}
INLINE(Vwwf,VWWI_ASWF) (Vwwi v) {return  ((WORD_TYPE){.M1 .I=v}).M1.F;}
//          VWWF_ASWF

INLINE(Vdwf,VDYU_ASWF) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M2.F;}
INLINE(Vdwf,VDBU_ASWF) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M2.F;}
INLINE(Vdwf,VDBI_ASWF) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M2.F;}
INLINE(Vdwf,VDBC_ASWF) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M2.F;}
INLINE(Vdwf,VDHU_ASWF) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M2.F;}
INLINE(Vdwf,VDHI_ASWF) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M2.F;}
INLINE(Vdwf,VDHF_ASWF) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M2.F;}
INLINE(Vdwf,VDWU_ASWF) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M2.F;}
INLINE(Vdwf,VDWI_ASWF) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M2.F;}
//          VDWF_ASWF
INLINE(Vdwf,VDDU_ASWF) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M2.F;}
INLINE(Vdwf,VDDI_ASWF) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M2.F;}
INLINE(Vdwf,VDDF_ASWF) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M2.F;}

INLINE(Vqwf,VQYU_ASWF) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M4.F;}
INLINE(Vqwf,VQBU_ASWF) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M4.F;}
INLINE(Vqwf,VQBI_ASWF) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M4.F;}
INLINE(Vqwf,VQBC_ASWF) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M4.F;}
INLINE(Vqwf,VQHU_ASWF) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M4.F;}
INLINE(Vqwf,VQHI_ASWF) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M4.F;}
INLINE(Vqwf,VQHF_ASWF) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M4.F;}
INLINE(Vqwf,VQWU_ASWF) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M4.F;}
INLINE(Vqwf,VQWI_ASWF) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M4.F;}
//          VQWF_ASWF
INLINE(Vqwf,VQDU_ASWF) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M4.F;}
INLINE(Vqwf,VQDI_ASWF) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M4.F;}
INLINE(Vqwf,VQDF_ASWF) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M4.F;}

#if 0 // _LEAVE_ANY_ASWF
}
#endif

#if 0 // _ENTER_ANY_ASDU
{
#endif

INLINE(Vddu,VDYU_ASDU) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M1.U;}
INLINE(Vddu,VDBU_ASDU) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M1.U;}
INLINE(Vddu,VDBI_ASDU) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M1.U;}
INLINE(Vddu,VDBC_ASDU) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M1.U;}
INLINE(Vddu,VDHU_ASDU) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M1.U;}
INLINE(Vddu,VDHI_ASDU) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M1.U;}
INLINE(Vddu,VDHF_ASDU) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M1.U;}
INLINE(Vddu,VDWU_ASDU) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M1.U;}
INLINE(Vddu,VDWI_ASDU) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M1.U;}
INLINE(Vddu,VDWF_ASDU) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M1.U;}
//          VDDU_ASDU
INLINE(Vddu,VDDI_ASDU) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M1.U;}
INLINE(Vddu,VDDF_ASDU) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M1.U;}

INLINE(Vqdu,VQYU_ASDU) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M2.U;}
INLINE(Vqdu,VQBU_ASDU) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M2.U;}
INLINE(Vqdu,VQBI_ASDU) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M2.U;}
INLINE(Vqdu,VQBC_ASDU) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M2.U;}
INLINE(Vqdu,VQHU_ASDU) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M2.U;}
INLINE(Vqdu,VQHI_ASDU) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M2.U;}
INLINE(Vqdu,VQHF_ASDU) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M2.U;}
INLINE(Vqdu,VQWU_ASDU) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M2.U;}
INLINE(Vqdu,VQWI_ASDU) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M2.U;}
INLINE(Vqdu,VQWF_ASDU) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M2.U;}
//          VQDU_ASDU
INLINE(Vqdu,VQDI_ASDU) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M2.U;}
INLINE(Vqdu,VQDF_ASDU) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M2.U;}

#if 0 // _LEAVE_ANY_ASDU
}
#endif

#if 0 // _ENTER_ANY_ASDI
{
#endif

INLINE(Vddi,VDYU_ASDI) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M1.I;}
INLINE(Vddi,VDBU_ASDI) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M1.I;}
INLINE(Vddi,VDBI_ASDI) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M1.I;}
INLINE(Vddi,VDBC_ASDI) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M1.I;}
INLINE(Vddi,VDHU_ASDI) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M1.I;}
INLINE(Vddi,VDHI_ASDI) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M1.I;}
INLINE(Vddi,VDHF_ASDI) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M1.I;}
INLINE(Vddi,VDWU_ASDI) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M1.I;}
INLINE(Vddi,VDWI_ASDI) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M1.I;}
INLINE(Vddi,VDWF_ASDI) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M1.I;}
INLINE(Vddi,VDDU_ASDI) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M1.I;}
//          VDDI_ASDI
INLINE(Vddi,VDDF_ASDI) (Vddf v) {return  ((DWRD_TYPE){.M1 .F=v}).M1.I;}

INLINE(Vqdi,VQYU_ASDI) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M2.I;}
INLINE(Vqdi,VQBU_ASDI) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M2.I;}
INLINE(Vqdi,VQBI_ASDI) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M2.I;}
INLINE(Vqdi,VQBC_ASDI) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M2.I;}
INLINE(Vqdi,VQHU_ASDI) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M2.I;}
INLINE(Vqdi,VQHI_ASDI) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M2.I;}
INLINE(Vqdi,VQHF_ASDI) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M2.I;}
INLINE(Vqdi,VQWU_ASDI) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M2.I;}
INLINE(Vqdi,VQWI_ASDI) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M2.I;}
INLINE(Vqdi,VQWF_ASDI) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M2.I;}
INLINE(Vqdi,VQDU_ASDI) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M2.I;}
//          VQDI_ASDI
INLINE(Vqdi,VQDF_ASDI) (Vqdf v) {return  ((QUAD_TYPE){.M2  .F=v}).M2.I;}

#if 0 // _LEAVE_ANY_ASDI
}
#endif

#if 0 // _ENTER_ANY_ASDF
{
#endif

INLINE(Vddf,VDYU_ASDF) (Vdyu v) {return  ((DWRD_TYPE){.M64.U=v}).M1.F;}
INLINE(Vddf,VDBU_ASDF) (Vdbu v) {return  ((DWRD_TYPE){.M8 .U=v}).M1.F;}
INLINE(Vddf,VDBI_ASDF) (Vdbi v) {return  ((DWRD_TYPE){.M8 .I=v}).M1.F;}
INLINE(Vddf,VDBC_ASDF) (Vdbc v) {return  ((DWRD_TYPE){.M8 .C=v}).M1.F;}
INLINE(Vddf,VDHU_ASDF) (Vdhu v) {return  ((DWRD_TYPE){.M4 .U=v}).M1.F;}
INLINE(Vddf,VDHI_ASDF) (Vdhi v) {return  ((DWRD_TYPE){.M4 .I=v}).M1.F;}
INLINE(Vddf,VDHF_ASDF) (Vdhf v) {return  ((DWRD_TYPE){.M4 .F=v}).M1.F;}
INLINE(Vddf,VDWU_ASDF) (Vdwu v) {return  ((DWRD_TYPE){.M2 .U=v}).M1.F;}
INLINE(Vddf,VDWI_ASDF) (Vdwi v) {return  ((DWRD_TYPE){.M2 .I=v}).M1.F;}
INLINE(Vddf,VDWF_ASDF) (Vdwf v) {return  ((DWRD_TYPE){.M2 .F=v}).M1.F;}
INLINE(Vddf,VDDU_ASDF) (Vddu v) {return  ((DWRD_TYPE){.M1 .U=v}).M1.F;}
INLINE(Vddf,VDDI_ASDF) (Vddi v) {return  ((DWRD_TYPE){.M1 .I=v}).M1.F;}
//          VDDF_ASDF

INLINE(Vqdf,VQYU_ASDF) (Vqyu v) {return  ((QUAD_TYPE){.M128.U=v}).M2.F;}
INLINE(Vqdf,VQBU_ASDF) (Vqbu v) {return  ((QUAD_TYPE){.M16 .U=v}).M2.F;}
INLINE(Vqdf,VQBI_ASDF) (Vqbi v) {return  ((QUAD_TYPE){.M16 .I=v}).M2.F;}
INLINE(Vqdf,VQBC_ASDF) (Vqbc v) {return  ((QUAD_TYPE){.M16 .C=v}).M2.F;}
INLINE(Vqdf,VQHU_ASDF) (Vqhu v) {return  ((QUAD_TYPE){.M8  .U=v}).M2.F;}
INLINE(Vqdf,VQHI_ASDF) (Vqhi v) {return  ((QUAD_TYPE){.M8  .I=v}).M2.F;}
INLINE(Vqdf,VQHF_ASDF) (Vqhf v) {return  ((QUAD_TYPE){.M8  .F=v}).M2.F;}
INLINE(Vqdf,VQWU_ASDF) (Vqwu v) {return  ((QUAD_TYPE){.M4  .U=v}).M2.F;}
INLINE(Vqdf,VQWI_ASDF) (Vqwi v) {return  ((QUAD_TYPE){.M4  .I=v}).M2.F;}
INLINE(Vqdf,VQWF_ASDF) (Vqwf v) {return  ((QUAD_TYPE){.M4  .F=v}).M2.F;}
INLINE(Vqdf,VQDU_ASDF) (Vqdu v) {return  ((QUAD_TYPE){.M2  .U=v}).M2.F;}
INLINE(Vqdf,VQDI_ASDF) (Vqdi v) {return  ((QUAD_TYPE){.M2  .I=v}).M2.F;}
//          VQDF_ASDF

#if 0 // _LEAVE_ANY_ASDF
}
#endif

#if 0 // _ENTER_ANY_SHLL
{
#endif

#if 0
INLINE(Vwyu,VWYU_SHLL) (Vwyu a, Rc(0, 1) b);
{
    uint32_t x = VWWU_ASTV(VWYU_ASWU(a));
    uint32_t y = ~(0u-b);
    return  VWWU_ASYU(WWU_ASTV((x&y)));
}
#endif

INLINE(Vwbu,VWBU_SHLL) (Vwbu a, Rc(0,  8) b) {return MY_VEC1IZE4V(Vwbu, shllbz, a, b);}
INLINE(Vwbi,VWBI_SHLL) (Vwbi a, Rc(0,  8) b) {return MY_VEC1IZE4V(Vwbi, shllbz, a, b);}
INLINE(Vwbc,VWBC_SHLL) (Vwbc a, Rc(0,  8) b) {return MY_VEC1IZE4V(Vwbc, shllbz, a, b);}
INLINE(Vwhu,VWHU_SHLL) (Vwhu a, Rc(0, 16) b) {return MY_VEC1IZE2V(Vwhu, shllhz, a, b);}
INLINE(Vwhi,VWHI_SHLL) (Vwhi a, Rc(0, 16) b) {return MY_VEC1IZE2V(Vwhi, shllhz, a, b);}
INLINE(Vwwu,VWWU_SHLL) (Vwwu a, Rc(0, 32) b) {return MY_VEC1IZE1V(Vwwu, shllwz, a, b);}
INLINE(Vwwi,VWWI_SHLL) (Vwwi a, Rc(0, 32) b) {return MY_VEC1IZE1V(Vwwi, shllwz, a, b);}

INLINE(Vdbu,VDBU_SHLL) (Vdbu a, Rc(0,  8) b) {return MY_VEC1IZE8V(Vdbu, shllbz, a, b);}
INLINE(Vdbi,VDBI_SHLL) (Vdbi a, Rc(0,  8) b) {return MY_VEC1IZE8V(Vdbi, shllbz, a, b);}
INLINE(Vdbc,VDBC_SHLL) (Vdbc a, Rc(0,  8) b) {return MY_VEC1IZE8V(Vdbc, shllbz, a, b);}
INLINE(Vdhu,VDHU_SHLL) (Vdhu a, Rc(0, 16) b) {return MY_VEC1IZE4V(Vdhu, shllhz, a, b);}
INLINE(Vdhi,VDHI_SHLL) (Vdhi a, Rc(0, 16) b) {return MY_VEC1IZE4V(Vdhi, shllhz, a, b);}
INLINE(Vdwu,VDWU_SHLL) (Vdwu a, Rc(0, 32) b) {return MY_VEC1IZE2V(Vdwu, shllwz, a, b);}
INLINE(Vdwi,VDWI_SHLL) (Vdwi a, Rc(0, 32) b) {return MY_VEC1IZE2V(Vdwi, shllwz, a, b);}
INLINE(Vddu,VDDU_SHLL) (Vddu a, Rc(0, 64) b) {return MY_VEC1IZE1V(Vddu, shlldz, a, b);}
INLINE(Vddi,VDDI_SHLL) (Vddi a, Rc(0, 64) b) {return MY_VEC1IZE1V(Vddi, shlldz, a, b);}

INLINE(Vqbu,VQBU_SHLL) (Vqbu a, Rc(0,  8) b) {return MY_VEC1IZE16V(Vqbu, shllbz, a, b);}
INLINE(Vqbi,VQBI_SHLL) (Vqbi a, Rc(0,  8) b) {return MY_VEC1IZE16V(Vqbi, shllbz, a, b);}
INLINE(Vqbc,VQBC_SHLL) (Vqbc a, Rc(0,  8) b) {return MY_VEC1IZE16V(Vqbc, shllbz, a, b);}
INLINE(Vqhu,VQHU_SHLL) (Vqhu a, Rc(0, 16) b) {return MY_VEC1IZE8V( Vqhu, shllhz, a, b);}
INLINE(Vqhi,VQHI_SHLL) (Vqhi a, Rc(0, 16) b) {return MY_VEC1IZE8V( Vqhi, shllhz, a, b);}
INLINE(Vqwu,VQWU_SHLL) (Vqwu a, Rc(0, 32) b) {return MY_VEC1IZE4V( Vqwu, shllwz, a, b);}
INLINE(Vqwi,VQWI_SHLL) (Vqwi a, Rc(0, 32) b) {return MY_VEC1IZE4V( Vqwi, shllwz, a, b);}
INLINE(Vqdu,VQDU_SHLL) (Vqdu a, Rc(0, 64) b) {return MY_VEC1IZE2V( Vqdu, shlldz, a, b);}
INLINE(Vqdi,VQDI_SHLL) (Vqdi a, Rc(0, 64) b) {return MY_VEC1IZE2V( Vqdi, shlldz, a, b);}

#if 0 // _LEAVE_ANY_SHLL
}
#endif

#if 0 // _ENTER_ANY_SHL2
{
#endif

INLINE(QUAD_UTYPE,shl2du)   (uint64_t a, Rc(0, 64) b)
{
    QUAD_TYPE c = {.Lo.U=a<<b, .Hi.U=a>>(64-b)};
    return  c.U;
}

INLINE(QUAD_ITYPE,shl2di)    (int64_t a, Rc(0, 64) b)
{
    QUAD_TYPE c;
    c.Lo.U =   (uint64_t) a<<b;
    c.Hi.U = -((uint64_t) a>>63);
    c.Hi.U <<= b;
    c.Hi.U |= ((uint64_t) a)>>(64-b);
    return  c.I;
}

INLINE(uint16_t,UCHAR_SHL2)  (uchar a, Rc(0, UCHAR_WIDTH) b) 
{
#define     UCHAR_SHL2(A, B) ((uint16_t)((0x00ffULL&A)<<B))
    return  (unsigned) a<<b;
}

INLINE( int16_t, SCHAR_SHL2)  (schar a, Rc(0, SCHAR_WIDTH) b) 
{
#define     SCHAR_SHL2(A, B) (( int16_t)((0xffffULL&A)<<B))
    return  SCHAR_SHL2(a, b);
}

#if CHAR_MIN

INLINE( int16_t,  CHAR_SHL2)   (char a, Rc(0,  CHAR_WIDTH) b) 
{
#   define  CHAR_SHL2(A, B) ((int16_t)((0xffffULL&A)<<B))
    return  CHAR_SHL2(a, b);
}

#else

INLINE(uint16_t,  CHAR_SHL2)   (char a, Rc(0,  CHAR_WIDTH) b) 
{
#   define  CHAR_SHL2(A, B) ((uint16_t)((0x00ffULL&A)<<B))
    return  CHAR_SHL2(a, b);
}

#endif


INLINE(uint32_t, USHRT_SHL2) (ushort a, Rc(0,  USHRT_WIDTH) b)
{
#define     USHRT_SHL2(A, B) ((uint32_t) ((0x0000ffffULL&A)<<B))
    return  (uint32_t) a<<b;
}

INLINE( int32_t,  SHRT_SHL2)  (short a, Rc(0,   SHRT_WIDTH) b)
{
#define     SHRT_SHL2(A, B)  (( int32_t) ((0xffffffffULL&A)<<B))
    return  (uint32_t) a<<b;
}


INLINE(uint64_t,  UINT_SHL2)   (uint a, Rc(0,   UINT_WIDTH) b)
{
#define     UINT_SHL2(A, B) ((uint64_t) ((0x00000000ffffffffULL&A)<<B))
    return  (uint64_t) a<<b;
}

INLINE( int64_t,   INT_SHL2)    (int a, Rc(0,    INT_WIDTH) b)
{
#define     INT_SHL2(A, B)  (( int64_t) ((0xffffffffffffffffULL&A)<<B))
    return  (uint64_t) a<<b;
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_SHL2)   (ulong a, Rc(0, ULONG_WIDTH) b)
{
#   define  ULONG_SHL2(A, B) ((uint64_t) ((0x00000000ffffffffULL&A)<<B))
    return  (uint64_t) a<<b;
}

INLINE( int64_t,  LONG_SHL2)    (long a, Rc(0,  LONG_WIDTH) b)
{
#define     LONG_SHL2(A, B)  (( int64_t) ((0xffffffffffffffffULL&A)<<B))
    return  (uint64_t) a<<b;
}

#else

INLINE(QUAD_UTYPE, ULONG_SHL2)  (ulong a, Rc(0, ULONG_WIDTH) b)
{
    return  shl2du(a, b);
}

INLINE(QUAD_ITYPE,  LONG_SHL2)   (long a, Rc(0,  LONG_WIDTH) b)
{
    return  shl2di(a, b);
}

#endif

INLINE(Vdhu,VWBU_SHL2) (Vwbu a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE4V(Vdhu, UCHAR_SHL2, a, b);
}

INLINE(Vdhi,VWBI_SHL2) (Vwbi a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE4V(Vdhi, SCHAR_SHL2, a, b);
}

#if CHAR_MIN
INLINE(Vdhi,VWBC_SHL2) (Vwbc a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE4V(Vdhi, CHAR_SHL2, a, b);
}

#else

INLINE(Vdhu,VWBC_SHL2) (Vwbc a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE4V(Vdhu, CHAR_SHL2, a, b);
}

#endif

INLINE(Vdwu,VWHU_SHL2) (Vwhu a, Rc(0, 16) b) 
{
    return  MY_VEC1IZE2V(Vdwu, USHRT_SHL2, a, b);
}

INLINE(Vdwi,VWHI_SHL2) (Vwhi a, Rc(0, 16) b) 
{
    return  MY_VEC1IZE2V(Vdwi,  SHRT_SHL2, a, b);
}


INLINE(Vddu,VWWU_SHL2) (Vwwu a, Rc(0, 32) b) 
{
    return  MY_VEC1IZE1V(Vddu,  UINT_SHL2, a, b);
}

INLINE(Vddi,VWWI_SHL2) (Vwwi a, Rc(0, 32) b) 
{
    return  MY_VEC1IZE1V(Vddi,   INT_SHL2, a, b);
}


INLINE(Vqhu,VDBU_SHL2) (Vdbu a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE8V(Vqhu, UCHAR_SHL2, a, b);
}

INLINE(Vqhi,VDBI_SHL2) (Vdbi a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE8V(Vqhi, SCHAR_SHL2, a, b);
}


#if CHAR_MIN

INLINE(Vqhi,VDBC_SHL2) (Vdbc a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE4V(Vqhi, CHAR_SHL2, a, b);
}

#else

INLINE(Vqhu,VWBC_SHL2) (Vdbc a, Rc(0,  8) b) 
{
    return  MY_VEC1IZE4V(Vqhu, CHAR_SHL2, a, b);
}

#endif

INLINE(Vqwu,VDHU_SHL2) (Vdhu a, Rc(0, 16) b) 
{
    return  MY_VEC1IZE4V(Vqwu, USHRT_SHL2, a, b);
}

INLINE(Vqwi,VDHI_SHL2) (Vdhi a, Rc(0, 16) b) 
{
    return  MY_VEC1IZE4V(Vqwi, SHRT_SHL2, a, b);
}


INLINE(Vqdu,VDWU_SHL2) (Vdwu a, Rc(0, 32) b) 
{
    return  MY_VEC1IZE2V(Vqdu, UINT_SHL2, a, b);
}

INLINE(Vqdi,VDWI_SHL2) (Vdwi a, Rc(0, 32) b) 
{
    return  MY_VEC1IZE2V(Vqdi, INT_SHL2, a, b);
}

#if 0 // _LEAVE_ANY_SHL2
}
#endif

#if 0 // _ENTER_ANY_SHRS
{
#endif
/*
x86 and arm and probably any other architecture designed to
run in the last 30 years will have a saturating signed 
right shift instruction. Because C says right shifting 
negative values is implementation defined, we're forced to
emulate the behavior and hope the compiler is smart enough
to figure out our mumbo jumbo and replace it with the 
single instruction.

TODO: find a better way to emulate signed shifts
*/
#define     shrsbz(A, B) (UINT8_MAX &(((unsigned) A)>>B))
#define     shrshz(A, B) (UINT16_MAX&(((unsigned) A)>>B))
#define     shrswz(A, B) (UINT32_MAX&(((uint32_t) A)>>B))
#define     shrsdz(A, B) (UINT64_MAX&(((uint64_t) A)>>B))
#if QUAD_NLLONG == 1
#   define  shrsqz(A, B) ((ullong) A>>B)
#else

INLINE(QUAD_UTYPE,shrsqz) (QUAD_UTYPE a, Rc(0, 128) b)
{
    QUAD_TYPE const c = {.U=a};
    return (
        (QUAD_TYPE const)
        {
            .Lo.U= (c.Lo.U>>b),
            .Hi.U=((c.Lo.U>>(64-b))|(c.Hi.U>>b)),
        }
    ).U;
}

#endif

INLINE( _Bool,  BOOL_SHRS)  (_Bool a, Rc(0,  1) b)
{
#define     BOOL_SHRS(A, B)  ((_Bool)(A&&!B))
    return  a && !b;
}


INLINE( uchar, UCHAR_SHRS)  (uchar a, Rc(0, UCHAR_WIDTH) b) 
{
#define     UCHAR_SHRS(A, B) ((uchar) ((unsigned) A>>B))
    return  a>>b;
}

INLINE( schar, SCHAR_SHRS)  (schar a, Rc(0, SCHAR_WIDTH) b) 
{
    unsigned n = SCHAR_WIDTH-b;
    unsigned u = UCHAR_MAX&a;
    unsigned s = u>>(SCHAR_WIDTH-1);
    unsigned m = UCHAR_MAX&((0-s)<<(SCHAR_WIDTH-b));
    u = u>>b;
    return (u|m);
}

INLINE(  char,  CHAR_SHRS)   (char a, Rc(0,  CHAR_WIDTH) b) 
{
#if CHAR_MIN
    return  SCHAR_SHRS(a, b);
#else
    return  UCHAR_SHRS(a, b);
#endif
}


INLINE(ushort, USHRT_SHRS) (ushort a, Rc(0, USHRT_WIDTH) b)
{
#define     USHRT_SHRS(A, B) ((ushort) ((unsigned) A>>B))
    return  a>>b;
}

INLINE( short,  SHRT_SHRS)  (short a, Rc(0,  SHRT_WIDTH) b)
{
    unsigned n =  SHRT_WIDTH-b;
    unsigned u = USHRT_MAX&a;
    unsigned s = u>>(SHRT_WIDTH-1);
    unsigned m = USHRT_MAX&((0-s)<<(SHRT_WIDTH-b));
    u = u>>b;
    return (u|m);
}


INLINE(  uint,  UINT_SHRS)   (uint a, Rc(0,  UINT_WIDTH) b)
{
#define     UINT_SHRS(A, B) ((unsigned) A>>B)
    return  a>>b;
}

INLINE(   int,   INT_SHRS)    (int a, Rc(0,   INT_WIDTH) b)
{
    unsigned n =  INT_WIDTH-b;
    unsigned u = UINT_MAX&a;
    unsigned s = u>>(INT_WIDTH-1);
    unsigned m = UINT_MAX&((0-s)<<(INT_WIDTH-b));
    u = u>>b;
    return (u|m);
}


INLINE( ulong, ULONG_SHRS)  (ulong a, Rc(0, ULONG_WIDTH) b) 
{
#define     ULONG_SHRS(A, B) ((ulong) A>>B)
    return  a>>b;
}

INLINE(  long,  LONG_SHRS)   (long a, Rc(0,  LONG_WIDTH) b) 
{
    ulong n =  LONG_WIDTH-b;
    ulong u = ULONG_MAX&a;
    ulong s = u>>(LONG_WIDTH-1);
    ulong m = ULONG_MAX&((0-s)<<(LONG_WIDTH-b));
    u = u>>b;
    return (u|m);
}


INLINE(ullong,ULLONG_SHRS) (ullong a, Rc(0,ULLONG_WIDTH) b) 
{
#define     ULLONG_SHRS(A, B) ((ullong) A>>B)
    return  a>>b;
}

INLINE( llong, LLONG_SHRS)  (llong a, Rc(0, LLONG_WIDTH) b) 
{
    ullong n =  LLONG_WIDTH-b;
    ullong u = ULLONG_MAX&a;
    ullong s = u>>(LLONG_WIDTH-1);
    ullong m = ULLONG_MAX&((0-s)<<(LLONG_WIDTH-b));
    u = u>>b;
    return (u|m);
}

#if 0
INLINE(Vwyu,VWYU_SHRS) (Vwyu a, Rc(0, 1) b);
{
    uint32_t x = VWWU_ASTV(VWYU_ASWU(a));
    uint32_t y = ~(0u-b);
    return  VWWU_ASYU(WWU_ASTV((x&y)));
}
#endif

INLINE(Vwbu,VWBU_SHRS) (Vwbu a, Rc(0,  8) b) {return MY_VEC1IZE4V(Vwbu, shrsbz, a, b);}
INLINE(Vwbi,VWBI_SHRS) (Vwbi a, Rc(0,  8) b) {return MY_VEC1IZE4V(Vwbi, shrsbz, a, b);}
INLINE(Vwbc,VWBC_SHRS) (Vwbc a, Rc(0,  8) b) {return MY_VEC1IZE4V(Vwbc, shrsbz, a, b);}
INLINE(Vwhu,VWHU_SHRS) (Vwhu a, Rc(0, 16) b) {return MY_VEC1IZE2V(Vwhu, shrshz, a, b);}
INLINE(Vwhi,VWHI_SHRS) (Vwhi a, Rc(0, 16) b) {return MY_VEC1IZE2V(Vwhi, shrshz, a, b);}
INLINE(Vwwu,VWWU_SHRS) (Vwwu a, Rc(0, 32) b) {return MY_VEC1IZE1V(Vwwu, shrswz, a, b);}
INLINE(Vwwi,VWWI_SHRS) (Vwwi a, Rc(0, 32) b) {return MY_VEC1IZE1V(Vwwi, shrswz, a, b);}

INLINE(Vdbu,VDBU_SHRS) (Vdbu a, Rc(0,  8) b) {return MY_VEC1IZE8V(Vdbu, shrsbz, a, b);}
INLINE(Vdbi,VDBI_SHRS) (Vdbi a, Rc(0,  8) b) {return MY_VEC1IZE8V(Vdbi, shrsbz, a, b);}
INLINE(Vdbc,VDBC_SHRS) (Vdbc a, Rc(0,  8) b) {return MY_VEC1IZE8V(Vdbc, shrsbz, a, b);}
INLINE(Vdhu,VDHU_SHRS) (Vdhu a, Rc(0, 16) b) {return MY_VEC1IZE4V(Vdhu, shrshz, a, b);}
INLINE(Vdhi,VDHI_SHRS) (Vdhi a, Rc(0, 16) b) {return MY_VEC1IZE4V(Vdhi, shrshz, a, b);}
INLINE(Vdwu,VDWU_SHRS) (Vdwu a, Rc(0, 32) b) {return MY_VEC1IZE2V(Vdwu, shrswz, a, b);}
INLINE(Vdwi,VDWI_SHRS) (Vdwi a, Rc(0, 32) b) {return MY_VEC1IZE2V(Vdwi, shrswz, a, b);}
INLINE(Vddu,VDDU_SHRS) (Vddu a, Rc(0, 64) b) {return MY_VEC1IZE1V(Vddu, shrsdz, a, b);}
INLINE(Vddi,VDDI_SHRS) (Vddi a, Rc(0, 64) b) {return MY_VEC1IZE1V(Vddi, shrsdz, a, b);}

INLINE(Vqbu,VQBU_SHRS) (Vqbu a, Rc(0,  8) b) {return MY_VEC1IZE16V(Vqbu, shrsbz, a, b);}
INLINE(Vqbi,VQBI_SHRS) (Vqbi a, Rc(0,  8) b) {return MY_VEC1IZE16V(Vqbi, shrsbz, a, b);}
INLINE(Vqbc,VQBC_SHRS) (Vqbc a, Rc(0,  8) b) {return MY_VEC1IZE16V(Vqbc, shrsbz, a, b);}
INLINE(Vqhu,VQHU_SHRS) (Vqhu a, Rc(0, 16) b) {return MY_VEC1IZE8V( Vqhu, shrshz, a, b);}
INLINE(Vqhi,VQHI_SHRS) (Vqhi a, Rc(0, 16) b) {return MY_VEC1IZE8V( Vqhi, shrshz, a, b);}
INLINE(Vqwu,VQWU_SHRS) (Vqwu a, Rc(0, 32) b) {return MY_VEC1IZE4V( Vqwu, shrswz, a, b);}
INLINE(Vqwi,VQWI_SHRS) (Vqwi a, Rc(0, 32) b) {return MY_VEC1IZE4V( Vqwi, shrswz, a, b);}
INLINE(Vqdu,VQDU_SHRS) (Vqdu a, Rc(0, 64) b) {return MY_VEC1IZE2V( Vqdu, shrsdz, a, b);}
INLINE(Vqdi,VQDI_SHRS) (Vqdi a, Rc(0, 64) b) {return MY_VEC1IZE2V( Vqdi, shrsdz, a, b);}

#if 0 // _LEAVE_ANY_SHRS
}
#endif

#if 0 // _ENTER_ANY_NEWL
{
#endif

#define MY_NEWL2(T) ((T){.K0=k0,.K1=k1})
#define MY_NEWL4(T) ((T){.K0=k0,.K1=k1,.K2=k2,.K3=k3})
#define MY_NEWL8(T) \
((T){.K0=k0,.K1=k1,.K2=k2,.K3=k3,.K4=k4,.K5=k5,.K6=k6,.K7=k7})

#define MY_NEWL16(T)                            \
(                                               \
    (T)                                         \
    {                                           \
        .K0=k0,  .K1 =k1,  .K2=k2,   .K3=k3,    \
        .K4=k4,  .K5 =k5,  .K6=k6,   .K7=k7,    \
        .K8=k8,  .K9 =k9,  .K10=k10, .K11=k11,  \
        .K12=k12,.K13=k13, .K14=k14, .K15=k15,  \
    }                                           \
)
    

INLINE(Vwbu,VWBU_NEWL) (uint8_t  k0, uint8_t  k1, uint8_t k2, uint8_t k3)
{
    return  MY_NEWL4(Vwbu);
}

INLINE(Vwbi,VWBI_NEWL) ( int8_t  k0,  int8_t  k1,  int8_t k2,  int8_t k3)
{
    return  MY_NEWL4(Vwbi);
}

INLINE(Vwbc,VWBC_NEWL) (   char  k0,    char  k1,    char k2,    char k3)
{
    return  MY_NEWL4(Vwbc);
}


INLINE(Vwhu,VWHU_NEWL) (uint16_t k0, uint16_t k1)
{
    return  MY_NEWL2(Vwhu);
}

INLINE(Vwhi,VWHI_NEWL) ( int16_t k0,  int16_t k1)
{
    return  MY_NEWL2(Vwhi);
}

INLINE(Vwhf,VWHF_NEWL) ( flt16_t k0,  flt16_t k1)
{
    return  MY_NEWL2(Vwhf);
}


INLINE(Vwwu,VWWU_NEWL) (uint32_t k0)
{
    return  (Vwwu){k0};
}

INLINE(Vwwi,VWWI_NEWL) ( int32_t k0)
{
    return  (Vwwi){k0};
}

INLINE(Vwwf,VWWF_NEWL) (   float k0)
{
    return  (Vwwf){k0};
}


INLINE(Vdbu,VDBU_NEWL)
(
    uint8_t k0, uint8_t k1, uint8_t k2, uint8_t k3,
    uint8_t k4, uint8_t k5, uint8_t k6, uint8_t k7
)
{
    return MY_NEWL8(Vdbu);
}

INLINE(Vdbi,VDBI_NEWL)
(
    int8_t k0, int8_t k1, int8_t k2, int8_t k3,
    int8_t k4, int8_t k5, int8_t k6, int8_t k7
)
{
    return  MY_NEWL8(Vdbi);
}

INLINE(Vdbc,VDBC_NEWL)
(
    char k0, char k1, char k2, char k3,
    char k4, char k5, char k6, char k7
)
{
    return  MY_NEWL8(Vdbc);
}


INLINE(Vdhu,VDHU_NEWL)
(
    uint16_t k0, uint16_t k1, uint16_t k2, uint16_t k3
)
{
    return  MY_NEWL4(Vdhu);
}

INLINE(Vdhi,VDHI_NEWL)
(
    int16_t k0, int16_t k1, int16_t k2, int16_t k3
)
{
    return  MY_NEWL4(Vdhi);
}

INLINE(Vdhf,VDHF_NEWL)
(
    flt16_t k0, flt16_t k1, flt16_t k2, flt16_t k3
)
{
    return  MY_NEWL4(Vdhf);
}


INLINE(Vdwu,VDWU_NEWL)
(
    uint32_t k0, uint32_t k1
)
{
    return  MY_NEWL2(Vdwu);
}

INLINE(Vdwi,VDWI_NEWL)
(
    int32_t k0, int32_t k1
)
{
    return  MY_NEWL2(Vdwi);
}

INLINE(Vdwf,VDWF_NEWL)
(
    float k0, float k1
)
{
    return  MY_NEWL2(Vdwf);
}


INLINE(Vddu,VDDU_NEWL) (uint64_t k0)
{
    return (Vddu){k0};
}

INLINE(Vddi,VDDI_NEWL) (int64_t k0)
{
    return (Vddi){k0};
}

INLINE(Vddf,VDDF_NEWL) (double k0)
{
    return (Vddf){k0};
}


INLINE(Vqbu,VQBU_NEWL)
(
    uint8_t  k0, uint8_t  k1, uint8_t  k2, uint8_t  k3,
    uint8_t  k4, uint8_t  k5, uint8_t  k6, uint8_t  k7,
    uint8_t  k8, uint8_t  k9, uint8_t k10, uint8_t k11,
    uint8_t k12, uint8_t k13, uint8_t k14, uint8_t k15
)
{
    return MY_NEWL16(Vqbu);
}

INLINE(Vqbi,VQBI_NEWL)
(
    int8_t  k0, int8_t  k1, int8_t  k2, int8_t  k3,
    int8_t  k4, int8_t  k5, int8_t  k6, int8_t  k7,
    int8_t  k8, int8_t  k9, int8_t k10, int8_t k11,
    int8_t k12, int8_t k13, int8_t k14, int8_t k15
)
{
    return  MY_NEWL16(Vqbi);
}

INLINE(Vqbc,VQBC_NEWL)
(
    char  k0, char  k1, char  k2, char  k3,
    char  k4, char  k5, char  k6, char  k7,
    char  k8, char  k9, char k10, char k11,
    char k12, char k13, char k14, char k15
)
{
    return  MY_NEWL16(Vqbc);
}


INLINE(Vqhu,VQHU_NEWL)
(
    uint16_t k0, uint16_t k1, uint16_t k2, uint16_t k3,
    uint16_t k4, uint16_t k5, uint16_t k6, uint16_t k7
)
{
    return  MY_NEWL8(Vqhu);
}

INLINE(Vqhi,VQHI_NEWL)
(
    int16_t k0, int16_t k1, int16_t k2, int16_t k3,
    int16_t k4, int16_t k5, int16_t k6, int16_t k7
)
{
    return  MY_NEWL8(Vqhi);
}

INLINE(Vqhf,VQHF_NEWL)
(
    flt16_t k0, flt16_t k1, flt16_t k2, flt16_t k3,
    flt16_t k4, flt16_t k5, flt16_t k6, flt16_t k7
)
{
    return  MY_NEWL8(Vqhf);
}


INLINE(Vqwu,VQWU_NEWL)
(
    uint32_t k0, uint32_t k1, uint32_t k2, uint32_t k3
)
{
    return  MY_NEWL4(Vqwu);
}

INLINE(Vqwi,VQWI_NEWL)
(
    int32_t k0, int32_t k1, int32_t k2, int32_t k3
)
{
    return  MY_NEWL4(Vqwi);
}

INLINE(Vqwf,VQWF_NEWL)
(
    float k0, float k1, float k2, float k3
)
{
    return  MY_NEWL4(Vqwf);
}


INLINE(Vqdu,VQDU_NEWL) (uint64_t k0, uint64_t k1)
{
    return  MY_NEWL2(Vqdu);
}

INLINE(Vqdi,VQDI_NEWL) (int64_t k0, int64_t k1)
{
    return  MY_NEWL2(Vqdi);
}

INLINE(Vqdf,VQDF_NEWL) (double k0, double k1)
{
    return  MY_NEWL2(Vqdf);
}

#if 0 // _LEAVE_ANY_NEWL
}
#endif


#if 0 // _ENTER_ANY_ABSU
{
#endif

INLINE(uchar,SCHAR_ABSU)  (schar a)
{
    int b = a>>(SCHAR_WIDTH-1);
    return b^a+b;
}

INLINE(uchar, CHAR_ABSU)   (char a)
{
#if CHAR_MIN
    return  SCHAR_ABSU(a);
#else
    return  a;
#endif
}


INLINE(ushort,SHRT_ABSU)  (short a)
{
    int b = a>>(SHRT_WIDTH-1);
    return b^(a+b);
}


INLINE(  uint, INT_ABSU)    (int a)
{
    int b = a>>(INT_WIDTH-1);
    return b^(a+b);
}


INLINE( ulong, LONG_ABSU)  (long a)
{
    long b = a>>(LONG_WIDTH-1);
    return b^(a+b);
}

INLINE(ullong,LLONG_ABSU) (llong a)
{
    llong b = a>>(LLONG_WIDTH-1);
    return b^(a+b);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE, absuqi) (QUAD_ITYPE a)
{
    QUAD_ITYPE b = a>>127;
    return b^(a+b);
}

#endif

INLINE(uint16_t,FLT16_ABSU) (flt16_t a)
{
// not dealing with 16 bit floats for now
    return  0;
}

INLINE(uint32_t,FLT_ABSU) (float a)
{
    return  a <= -0.0f ? -a : a;
}

INLINE(uint64_t,DBL_ABSU) (double a)
{
    return  a <= -0.0 ? -a : a;
}


INLINE(Vwbu,VWBI_ABSU) (Vwbi a)
{
    return  MY_VEC1IZE4(Vwbu, INT8_ABSU, a);
}

INLINE(Vwbu,VWBC_ABSU) (Vwbc a)
{
    return  MY_VEC1IZE4(Vwbu, CHAR_ABSU, a);
}


INLINE(Vwhu,VWHI_ABSU) (Vwhi a)
{
    return  MY_VEC1IZE2(Vwhu, INT16_ABSU, a);
}

INLINE(Vwhu,VWHF_ABSU) (Vwhf a)
{
    return  MY_VEC1IZE2(Vwhu, FLT16_ABSU, a);
}


INLINE(Vwwu,VWWI_ABSU) (Vwwi a)
{
    return  ((Vwwu){INT32_ABSU(a.K0)});
}

INLINE(Vwwu,VWWF_ABSU) (Vwwf a)
{
    return  ((Vwwu){FLT_ABSU(a.K0)});
}


INLINE(Vdbu,VDBI_ABSU) (Vdbi a)
{
    return  MY_VEC1IZE8(Vdbu, INT8_ABSU, a);
}

INLINE(Vdbu,VDBC_ABSU) (Vdbc a)
{
    return  MY_VEC1IZE8(Vdbu, CHAR_ABSU, a);
}


INLINE(Vdhu,VDHI_ABSU) (Vdhi a)
{
    return  MY_VEC1IZE4(Vdhu, INT16_ABSU, a);
}

INLINE(Vdhu,VDHF_ABSU) (Vdhf a)
{
    return  MY_VEC1IZE4(Vdhu, FLT16_ABSU, a);
}


INLINE(Vdwu,VDWI_ABSU) (Vdwi a)
{
    return MY_VEC1IZE2(Vdwu, INT32_ABSU, a);
}

INLINE(Vdwu,VDWF_ABSU) (Vdwf a)
{
    return MY_VEC1IZE2(Vdwu, INT32_ABSU, a);
}


INLINE(Vddu,VDDI_ABSU) (Vddi a)
{
    return ((Vddu){INT64_ABSU(a.K0)});
}

INLINE(Vddu,VDDF_ABSU) (Vddf a)
{
    return ((Vddu){DBL_ABSU(a.K0)});
}


INLINE(Vqbu,VQBI_ABSU) (Vqbi a)
{
    return  MY_VEC1IZE16(Vqbu, INT8_ABSU, a);
}

INLINE(Vqbu,VQBC_ABSU) (Vqbc a)
{
    return  MY_VEC1IZE16(Vqbu, CHAR_ABSU, a);
}


INLINE(Vqhu,VQHI_ABSU) (Vqhi a)
{
    return  MY_VEC1IZE8(Vqhu, INT16_ABSU, a);
}

INLINE(Vqhu,VQHF_ABSU) (Vqhf a)
{
    return  MY_VEC1IZE8(Vqhu, FLT16_ABSU, a);
}


INLINE(Vqwu,VQWI_ABSU) (Vqwi a)
{
    return  MY_VEC1IZE4(Vqwu, INT32_ABSU, a);
}

INLINE(Vqwu,VQWF_ABSU) (Vqwf a)
{
    return  MY_VEC1IZE4(Vqwu, FLT_ABSU, a);
}


INLINE(Vqdu,VQDI_ABSU) (Vqdi a)
{
    return  MY_VEC1IZE2(Vqdu, INT64_ABSU, a);
}

INLINE(Vqdu,VQDF_ABSU) (Vqdf a)
{
    return  MY_VEC1IZE2(Vqdu, DBL_ABSU, a);
}

#if 0 // _LEAVE_ANY_ABSU
}
#endif


#if 0 // _ENTER_ANY_ADDL
{
#endif
/*

*/
INLINE( _Bool,  BOOL_ADDL)  (_Bool a,  _Bool b) {return a^b;}
INLINE( uchar, UCHAR_ADDL)  (uchar a,  uchar b) {return a+b;}
INLINE( schar, SCHAR_ADDL)  (schar a,  schar b) {return UCHAR_ADDL(a,b);}
INLINE(  char,  CHAR_ADDL)   (char a,   char b) {return UCHAR_ADDL(a,b);}
INLINE(ushort, USHRT_ADDL) (ushort a, ushort b) {return a+b;}
INLINE( short,  SHRT_ADDL)  (short a,  short b) {return USHRT_ADDL(a,b);}
INLINE(  uint,  UINT_ADDL)   (uint a,   uint b) {return a+b;}
INLINE(   int,   INT_ADDL)    (int a,    int b) {return UINT_ADDL(a,b);}
INLINE( ulong, ULONG_ADDL)  (ulong a,  ulong b) {return a+b;}
INLINE(  long,  LONG_ADDL)   (long a,   long b) {return ULONG_ADDL(a,b);}
INLINE(ullong,ULLONG_ADDL) (ullong a, ullong b) {return a+b;}
INLINE( llong, LLONG_ADDL)  (llong a,  llong b) {return ULLONG_ADDL(a,b);}

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,addlqu) (QUAD_UTYPE a, QUAD_UTYPE b) {return a+b;}
INLINE(QUAD_ITYPE,addlqi) (QUAD_ITYPE a, QUAD_ITYPE b) {return a+b;}
#endif

INLINE(Vwyu,VWYU_ADDL) (Vwyu a, Vwyu b)
{
    Vw p = {.Y=a};
    Vw q = {.Y=b};
    p.W.U.K0 ^= q.W.U.K0;
    return p.Y;
}

INLINE(Vwbu,VWBU_ADDL) (Vwbu a, Vwbu b) 
{
    return  MY_VEC2IZE4(Vwbu, UINT8_ADDL, a, b);
}

INLINE(Vwbi,VWBI_ADDL) (Vwbi a, Vwbi b) 
{
    return  MY_VEC2IZE4(Vwbi, INT8_ADDL, a, b);
}

INLINE(Vwbc,VWBC_ADDL) (Vwbc a, Vwbc b) 
{
    return  MY_VEC2IZE4(Vwbc, CHAR_ADDL, a, b);
}


INLINE(Vwhu,VWHU_ADDL) (Vwhu a, Vwhu b) 
{
    return  MY_VEC2IZE2(Vwhu, UINT16_ADDL, a, b);
}

INLINE(Vwhi,VWHI_ADDL) (Vwhi a, Vwhi b) 
{
    return  MY_VEC2IZE2(Vwhi, INT16_ADDL, a, b);
}


INLINE(Vwwu,VWWU_ADDL) (Vwwu a, Vwwu b) 
{
    return  ((Vwwu){UINT32_ADDL(a.K0, b.K0)});
}

INLINE(Vwwi,VWWI_ADDL) (Vwwi a, Vwwi b) 
{
    return  ((Vwwi){UINT32_ADDL(a.K0, b.K0)});
}


INLINE(Vdyu,VDYU_ADDL) (Vdyu a, Vdyu b)
{
    Vd p = {.Y=a};
    Vd q = {.Y=b};
    p.D.U.K0 ^= q.D.U.K0;
    return p.Y;
}


INLINE(Vdbu,VDBU_ADDL) (Vdbu a, Vdbu b) 
{
    return  MY_VEC2IZE8(Vdbu, UINT8_ADDL, a, b);
}

INLINE(Vdbi,VDBI_ADDL) (Vdbi a, Vdbi b) 
{
    return  MY_VEC2IZE8(Vdbi, INT8_ADDL, a, b);
}

INLINE(Vdbc,VDBC_ADDL) (Vdbc a, Vdbc b) 
{
    return  MY_VEC2IZE8(Vdbc, CHAR_ADDL, a, b);
}


INLINE(Vdhu,VDHU_ADDL) (Vdhu a, Vdhu b) 
{
    return  MY_VEC2IZE4(Vdhu, UINT16_ADDL, a, b);
}

INLINE(Vdhi,VDHI_ADDL) (Vdhi a, Vdhi b) 
{
    return  MY_VEC2IZE4(Vdhi, INT16_ADDL, a, b);
}


INLINE(Vdwu,VDWU_ADDL) (Vdwu a, Vdwu b) 
{
    return  MY_VEC2IZE2(Vdwu, UINT32_ADDL, a, b);
}

INLINE(Vdwi,VDWI_ADDL) (Vdwi a, Vdwi b) 
{
    return  MY_VEC2IZE2(Vdwi, INT32_ADDL, a, b);
}


INLINE(Vddu,VDDU_ADDL) (Vddu a, Vddu b) 
{
    return  MY_VEC2IZE1(Vddu, UINT64_ADDL, a, b);
}

INLINE(Vddi,VDDI_ADDL) (Vddi a, Vddi b) 
{
    return  MY_VEC2IZE1(Vddi, INT64_ADDL, a, b);
}



INLINE(Vqyu,VQYU_ADDL) (Vqyu a, Vqyu b)
{
    Vq p = {.Y=a};
    Vq q = {.Y=b};
    p.D.U.K0 ^= q.D.U.K0;
    p.D.U.K1 ^= q.D.U.K1;
    return  p.Y;
}


INLINE(Vqbu,VQBU_ADDL) (Vqbu a, Vqbu b) 
{
    return  MY_VEC2IZE16(Vqbu, UINT8_ADDL, a, b);
}

INLINE(Vqbi,VQBI_ADDL) (Vqbi a, Vqbi b) 
{
    return  MY_VEC2IZE16(Vqbi, INT8_ADDL, a, b);
}

INLINE(Vqbc,VQBC_ADDL) (Vqbc a, Vqbc b) 
{
    return  MY_VEC2IZE16(Vqbc, CHAR_ADDL, a, b);
}


INLINE(Vqhu,VQHU_ADDL) (Vqhu a, Vqhu b) 
{
    return  MY_VEC2IZE8(Vqhu, UINT16_ADDL, a, b);
}

INLINE(Vqhi,VQHI_ADDL) (Vqhi a, Vqhi b) 
{
    return  MY_VEC2IZE8(Vqhi, INT16_ADDL, a, b);
}


INLINE(Vqwu,VQWU_ADDL) (Vqwu a, Vqwu b) 
{
    return  MY_VEC2IZE4(Vqwu, UINT32_ADDL, a, b);
}

INLINE(Vqwi,VQWI_ADDL) (Vqwi a, Vqwi b) 
{
    return  MY_VEC2IZE4(Vqwi, INT32_ADDL, a, b);
}


INLINE(Vqdu,VQDU_ADDL) (Vqdu a, Vqdu b) 
{
    return  MY_VEC2IZE2(Vqdu, UINT64_ADDL, a, b);
}

INLINE(Vqdi,VQDI_ADDL) (Vqdi a, Vqdi b) 
{
    return  MY_VEC2IZE2(Vqdi, INT64_ADDL, a, b);
}

#if 0 // _LEAVE_ANY_ADDL
}
#endif


#if 0 // _ENTER_ANY_CVHS
{
#endif
/*  
TODO: implement cvhshf
TODO: implement cvhsqr
*/
#define     MY_CVHSU(X)         \
(                               \
    (X > INT16_MAX) ? INT16_MAX:\
    (X)                         \
)

#define     MY_CVHSI(X)         \
(                               \
    (X > INT16_MAX) ? INT16_MAX:\
    (X < INT16_MIN) ? INT16_MIN:\
    (X)                         \
)

INLINE(int16_t,  BOOL_CVHS)  (_Bool x) 
{
    return  x;
}


INLINE(int16_t, UCHAR_CVHS)  (uchar x) 
{
    return  x;
}

INLINE(int16_t, SCHAR_CVHS)  (schar x) 
{
    return  x;
}

INLINE(int16_t,  CHAR_CVHS)   (char x) 
{
    return  x;
}


INLINE(int16_t, USHRT_CVHS) (ushort x) 
{
    return  MY_CVHSU(x);
}

INLINE(int16_t,  SHRT_CVHS)  (short x) 
{
    return  MY_CVHSI(x);
}


INLINE(int16_t,  UINT_CVHS)   (uint x) 
{
    return  MY_CVHSU(x);
}

INLINE(int16_t,   INT_CVHS)    (int x) 
{
    return  MY_CVHSI(x);
}


INLINE(int16_t, ULONG_CVHS)  (ulong x) 
{
    return  MY_CVHSU(x);
}

INLINE(int16_t,  LONG_CVHS)   (long x) 
{
    return  MY_CVHSI(x);
}


INLINE(int16_t,ULLONG_CVHS) (ullong x) 
{
    return  MY_CVHSU(x);
}

INLINE(int16_t, LLONG_CVHS)  (llong x) 
{
    return  MY_CVHSI(x);
}


INLINE(int16_t, FLT16_CVHS)(flt16_t x) 
{
    return  0;
}

INLINE(int16_t,   FLT_CVHS)  (float x) 
{
    return  MY_CVHSI(x);
}

INLINE(int16_t,   DBL_CVHS) (double x) 
{
    return  MY_CVHSI(x);
}


INLINE(int16_t,cvhsqu) (QUAD_UTYPE x) 
{
    return 0;
}

INLINE(int16_t,cvhsqi) (QUAD_ITYPE x) 
{
    return 0;
}

INLINE(int16_t,cvhsqf) (QUAD_FTYPE x) 
{
    return 0;
}


INLINE(Vwhi,VWHU_CVHS) (Vwhu x) 
{
    return  MY_VEC1IZE2(Vwhi, UINT16_CVHS, x);
}

INLINE(Vwhi,VWHI_CVHS) (Vwhi x) 
{
    return  x;
}

INLINE(Vwhi,VWHF_CVHS) (Vwhf x) 
{
    return  (Vwhi){0};
}


INLINE(Vqhi,VDBU_CVHS) (Vdbu x) 
{
    return  MY_VEC1IZE8(Vqhi, UINT8_CVHS, x);
}

INLINE(Vqhi,VDBI_CVHS) (Vdbi x) 
{
    return  MY_VEC1IZE8(Vqhi, INT8_CVHS, x);
}

INLINE(Vqhi,VDBC_CVHS) (Vdbc x) 
{
    return  MY_VEC1IZE8(Vqhi, CHAR_CVHS, x);
}


INLINE(Vdhi,VDHU_CVHS) (Vdhu x) 
{
    return  MY_VEC1IZE4(Vdhi, UINT16_CVHS, x);
}

INLINE(Vdhi,VDHI_CVHS) (Vdhi x) 
{
    return  x;
}

INLINE(Vdhi,VDHF_CVHS) (Vdhf x) 
{
    return  (Vdhi){0};
}


INLINE(Vwhi,VDWU_CVHS) (Vdwu x) 
{
    return  MY_VEC1IZE2(Vwhi, UINT32_CVHS, x);
}

INLINE(Vwhi,VDWI_CVHS) (Vdwi x) 
{
    return  MY_VEC1IZE2(Vwhi, UINT32_CVHS, x);
}

INLINE(Vwhi,VDWF_CVHS) (Vdwf x) 
{
    return  MY_VEC1IZE2(Vwhi, FLT_CVHS, x);
}


INLINE(Vqhi,VQHU_CVHS) (Vqhu x) 
{
    return  MY_VEC1IZE8(Vqhi, UINT16_CVHS, x);
}

INLINE(Vqhi,VQHI_CVHS) (Vqhi x) 
{
    return  MY_VEC1IZE8(Vqhi, INT16_CVHS, x);
}

INLINE(Vqhi,VQHF_CVHS) (Vqhf x) 
{
    return  (Vqhi){0};
}


INLINE(Vdhi,VQWU_CVHS) (Vqwu x) 
{
    return  MY_VEC1IZE4(Vdhi, UINT32_CVHS, x);
}

INLINE(Vdhi,VQWI_CVHS) (Vqwi x) 
{
    return  MY_VEC1IZE4(Vdhi, INT32_CVHS, x);
}

INLINE(Vdhi,VQWF_CVHS) (Vqwf x) 
{
    return  MY_VEC1IZE4(Vdhi, FLT_CVHS, x);
}


INLINE(Vwhi,VQDU_CVHS) (Vqdu x) 
{
    return  MY_VEC1IZE2(Vwhi, UINT64_CVHS, x);
}

INLINE(Vwhi,VQDI_CVHS) (Vqdi x) 
{
    return  MY_VEC1IZE2(Vwhi, INT64_CVHS, x);
}

INLINE(Vwhi,VQDF_CVHS) (Vqdf x) 
{
    return  MY_VEC1IZE2(Vwhi, DBL_CVHS, x);
}


#if 0 // _LEAVE_ANY_CVHS
}
#endif


#if 0 // _ENTER_ANY_CVHZ
{
#endif
/*  
TODO: implement cvhzhf
TODO: implement cvhzqr
*/
#define     MY_CVHZU(X)             \
(                                   \
    (X > UINT16_MAX) ? UINT16_MAX:  \
    (X)                             \
)

#define     MY_CVHZI(X)             \
(                                   \
    (X > UINT16_MAX) ? UINT16_MAX:  \
    (X <          0) ? 0:           \
    (X)                             \
)

INLINE(uint16_t, BOOL_CVHZ)  (_Bool x) 
{
    return  x;
}


INLINE(uint16_t, UCHAR_CVHZ)  (uchar x) 
{
    return  x;
}

INLINE(uint16_t, SCHAR_CVHZ)  (schar x) 
{
    return  x < 0 ? 0 : x; 
}

INLINE(uint16_t,  CHAR_CVHZ)   (char x) 
{
#if CHAR_MIN
    return  SCHAR_CVHZ(x);
#else
    return  UCHAR_CVHZ(x);
#endif
}


INLINE(uint16_t, USHRT_CVHZ) (ushort x) 
{
    return  MY_CVHZU(x);
}

INLINE(uint16_t,  SHRT_CVHZ)  (short x) 
{
    return  x < 0 ? 0 : x;
}


INLINE(uint16_t,  UINT_CVHZ)   (uint x) 
{
    return  MY_CVHZU(x);
}

INLINE(uint16_t,   INT_CVHZ)    (int x) 
{
    return  MY_CVHZI(x);
}


INLINE(uint16_t, ULONG_CVHZ)  (ulong x) 
{
    return  MY_CVHZU(x);
}

INLINE(uint16_t,  LONG_CVHZ)   (long x) 
{
    return  MY_CVHZI(x);
}


INLINE(uint16_t,ULLONG_CVHZ) (ullong x) 
{
    return  MY_CVHZU(x);
}

INLINE(uint16_t, LLONG_CVHZ)  (llong x) 
{
    return  MY_CVHZI(x);
}


INLINE(uint16_t, FLT16_CVHZ)(flt16_t x) 
{
    return  0;
}

INLINE(uint16_t,   FLT_CVHZ)  (float x) 
{
    return  MY_CVHZI(x);
}

INLINE(uint16_t,   DBL_CVHZ) (double x) 
{
    return  MY_CVHZI(x);
}


INLINE(uint16_t,cvhzqu) (QUAD_UTYPE x) 
{
    return 0;
}

INLINE(uint16_t,cvhzqi) (QUAD_ITYPE x) 
{
    return 0;
}

INLINE(uint16_t,cvhzqf) (QUAD_FTYPE x) 
{
    return 0;
}


INLINE(Vwhu,VWHU_CVHZ) (Vwhu x) 
{
    return  x;
}

INLINE(Vwhu,VWHI_CVHZ) (Vwhi x) 
{
    return  MY_VEC1IZE2(Vwhu, INT16_CVHZ, x);
}

INLINE(Vwhu,VWHF_CVHZ) (Vwhf x) 
{
    return  (Vwhu){0};
}


INLINE(Vqhu,VDBU_CVHZ) (Vdbu x) 
{
    return  MY_VEC1IZE8(Vqhu, UINT8_CVHZ, x);
}

INLINE(Vqhu,VDBI_CVHZ) (Vdbi x) 
{
    return  MY_VEC1IZE8(Vqhu, INT8_CVHZ, x);
}

INLINE(Vqhu,VDBC_CVHZ) (Vdbc x) 
{
    return  MY_VEC1IZE8(Vqhu, CHAR_CVHZ, x);
}


INLINE(Vdhu,VDHU_CVHZ) (Vdhu x) 
{
    return  x;
}

INLINE(Vdhu,VDHI_CVHZ) (Vdhi x) 
{
    return  MY_VEC1IZE4(Vdhu, INT16_CVHZ, x);
}

INLINE(Vdhu,VDHF_CVHZ) (Vdhf x) 
{
    return  (Vdhu){0};
}


INLINE(Vwhu,VDWU_CVHZ) (Vdwu x) 
{
    return  MY_VEC1IZE2(Vwhu, UINT32_CVHZ, x);
}

INLINE(Vwhu,VDWI_CVHZ) (Vdwi x) 
{
    return  MY_VEC1IZE2(Vwhu, INT32_CVHZ, x);
}

INLINE(Vwhu,VDWF_CVHZ) (Vdwf x) 
{
    return  MY_VEC1IZE2(Vwhu, FLT_CVHZ, x);
}


INLINE(Vqhu,VQHU_CVHZ) (Vqhu x) 
{
    return  MY_VEC1IZE8(Vqhu, UINT16_CVHZ, x);
}

INLINE(Vqhu,VQHI_CVHZ) (Vqhi x) 
{
    return  MY_VEC1IZE8(Vqhu, INT16_CVHZ, x);
}

INLINE(Vqhu,VQHF_CVHZ) (Vqhf x) 
{
    return  (Vqhu){0};
}


INLINE(Vdhu,VQWU_CVHZ) (Vqwu x) 
{
    return  MY_VEC1IZE4(Vdhu, UINT32_CVHZ, x);
}

INLINE(Vdhu,VQWI_CVHZ) (Vqwi x) 
{
    return  MY_VEC1IZE4(Vdhu, INT32_CVHZ, x);
}

INLINE(Vdhu,VQWF_CVHZ) (Vqwf x) 
{
    return  MY_VEC1IZE4(Vdhu, FLT_CVHZ, x);
}


INLINE(Vwhu,VQDU_CVHZ) (Vqdu x) 
{
    return  MY_VEC1IZE2(Vwhu, UINT64_CVHZ, x);
}

INLINE(Vwhu,VQDI_CVHZ) (Vqdi x) 
{
    return  MY_VEC1IZE2(Vwhu, INT64_CVHZ, x);
}

INLINE(Vwhu,VQDF_CVHZ) (Vqdf x) 
{
    return  MY_VEC1IZE2(Vwhu, DBL_CVHZ, x);
}


#if 0 // _LEAVE_ANY_CVHZ
}
#endif


#if 0 // _ENTER_ANY_CEQS
{
#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,ceqsqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE l = {.U=a};
    QUAD_TYPE r = {.U=b};
    QUAD_TYPE c;
    c.Lo.U = l.Lo.U == r.Lo.U ? -1 : 0;
    c.Hi.U = l.Hi.U == r.Hi.U ? -1 : 0;
    l.Lo.U = c.Lo.U&c.Hi.U;
    c.Lo.U = l.Lo.U;
    c.Hi.U = l.Lo.U;
    return  c.U;
}

INLINE(QUAD_ITYPE,ceqsqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE l = {.I=a};
    QUAD_TYPE r = {.I=b};
    QUAD_TYPE c;
    c.Lo.U = l.Lo.U == r.Lo.U ? -1 : 0;
    c.Hi.U = l.Hi.U == r.Hi.U ? -1 : 0;
    l.Lo.U = c.Lo.U&c.Hi.U;
    c.Lo.U = l.Lo.U;
    c.Hi.U = l.Lo.U;
    return  c.I;
}

#endif

INLINE(Vwyu,VWYU_CEQS) (Vwyu a, Vwyu b)
{
    uint32_t p = VWWU_ASTV(VWYU_ASWU(a));
    uint32_t q = VWWU_ASTV(VWYU_ASWU(b));
    return  VWWU_ASYU(UINT32_ASTV(((~(p^q)))));
}

INLINE(Vwbu,VWBU_CEQS) (Vwbu a, Vwbu b) 
{
    return  MY_VEC2IZE4(Vwbu, UINT8_CEQS, a, b);
}

INLINE(Vwbi,VWBI_CEQS) (Vwbi a, Vwbi b) 
{
    return  MY_VEC2IZE4(Vwbi, INT8_CEQS, a, b);
}

INLINE(Vwbc,VWBC_CEQS) (Vwbc a, Vwbc b) 
{
    return  MY_VEC2IZE4(Vwbc, CHAR_CEQS, a, b);
}


INLINE(Vwhu,VWHU_CEQS) (Vwhu a, Vwhu b) 
{
    return  MY_VEC2IZE2(Vwhu, UINT16_CEQS, a, b);
}

INLINE(Vwhi,VWHI_CEQS) (Vwhi a, Vwhi b) 
{
    return  MY_VEC2IZE2(Vwhi, INT16_CEQS, a, b);
}


INLINE(Vwwu,VWWU_CEQS) (Vwwu a, Vwwu b) 
{
    return  ((Vwwu){UINT32_CEQS(a.K0, b.K0)});
}

INLINE(Vwwi,VWWI_CEQS) (Vwwi a, Vwwi b) 
{
    return  ((Vwwi){UINT32_CEQS(a.K0, b.K0)});
}


INLINE(Vdyu,VDYU_CEQS) (Vdyu a, Vdyu b)
{
    DWRD_TYPE p = {.M64.U=a};
    DWRD_TYPE q = {.M64.U=b};
    p.U = ~(p.U^q.U);
    return  p.M64.U;
}


INLINE(Vdbu,VDBU_CEQS) (Vdbu a, Vdbu b) 
{
    return  MY_VEC2IZE8(Vdbu, UINT8_CEQS, a, b);
}

INLINE(Vdbi,VDBI_CEQS) (Vdbi a, Vdbi b) 
{
    return  MY_VEC2IZE8(Vdbi, INT8_CEQS, a, b);
}

INLINE(Vdbc,VDBC_CEQS) (Vdbc a, Vdbc b) 
{
    return  MY_VEC2IZE8(Vdbc, CHAR_CEQS, a, b);
}


INLINE(Vdhu,VDHU_CEQS) (Vdhu a, Vdhu b) 
{
    return  MY_VEC2IZE4(Vdhu, UINT16_CEQS, a, b);
}

INLINE(Vdhi,VDHI_CEQS) (Vdhi a, Vdhi b) 
{
    return  MY_VEC2IZE4(Vdhi, INT16_CEQS, a, b);
}


INLINE(Vdwu,VDWU_CEQS) (Vdwu a, Vdwu b) 
{
    return  MY_VEC2IZE2(Vdwu, UINT32_CEQS, a, b);
}

INLINE(Vdwi,VDWI_CEQS) (Vdwi a, Vdwi b) 
{
    return  MY_VEC2IZE2(Vdwi, INT32_CEQS, a, b);
}


INLINE(Vddu,VDDU_CEQS) (Vddu a, Vddu b) 
{
    return  MY_VEC2IZE1(Vddu, UINT64_CEQS, a, b);
}

INLINE(Vddi,VDDI_CEQS) (Vddi a, Vddi b) 
{
    return  MY_VEC2IZE1(Vddi, INT64_CEQS, a, b);
}



INLINE(Vqyu,VQYU_CEQS) (Vqyu a, Vqyu b)
{
    QUAD_TYPE p = {.M128.U=a};
    QUAD_TYPE q = {.M128.U=b};
    p.Lo.U = ~(p.Lo.U^q.Lo.U);
    p.Hi.U = ~(p.Hi.U^q.Hi.U);
    return  p.M128.U;
}


INLINE(Vqbu,VQBU_CEQS) (Vqbu a, Vqbu b) 
{
    return  MY_VEC2IZE16(Vqbu, UINT8_CEQS, a, b);
}

INLINE(Vqbi,VQBI_CEQS) (Vqbi a, Vqbi b) 
{
    return  MY_VEC2IZE16(Vqbi, INT8_CEQS, a, b);
}

INLINE(Vqbc,VQBC_CEQS) (Vqbc a, Vqbc b) 
{
    return  MY_VEC2IZE16(Vqbc, CHAR_CEQS, a, b);
}


INLINE(Vqhu,VQHU_CEQS) (Vqhu a, Vqhu b) 
{
    return  MY_VEC2IZE8(Vqhu, UINT16_CEQS, a, b);
}

INLINE(Vqhi,VQHI_CEQS) (Vqhi a, Vqhi b) 
{
    return  MY_VEC2IZE8(Vqhi, INT16_CEQS, a, b);
}


INLINE(Vqwu,VQWU_CEQS) (Vqwu a, Vqwu b) 
{
    return  MY_VEC2IZE4(Vqwu, UINT32_CEQS, a, b);
}

INLINE(Vqwi,VQWI_CEQS) (Vqwi a, Vqwi b) 
{
    return  MY_VEC2IZE4(Vqwi, INT32_CEQS, a, b);
}


INLINE(Vqdu,VQDU_CEQS) (Vqdu a, Vqdu b) 
{
    return  MY_VEC2IZE2(Vqdu, UINT64_CEQS, a, b);
}

INLINE(Vqdi,VQDI_CEQS) (Vqdi a, Vqdi b) 
{
    return  MY_VEC2IZE2(Vqdi, INT64_CEQS, a, b);
}

#if 0 // _LEAVE_ANY_CEQS
}
#endif

#if 0 // _ENTER_ANY_CEQY
{
#endif

INLINE(Vwyu,VWYU_CEQY) (Vwyu a, Vwyu b)
{
    uint32_t p = VWWU_ASTV(VWYU_ASWU(a));
    uint32_t q = VWWU_ASTV(VWYU_ASWU(b));
    return  VWWU_ASYU(UINT32_ASTV(((~(p^q)))));
}

INLINE(Vwbu,VWBU_CEQY) (Vwbu a, Vwbu b) 
{
    return  MY_VEC2IZE4(Vwbu, UINT8_CEQY, a, b);
}

INLINE(Vwbi,VWBI_CEQY) (Vwbi a, Vwbi b) 
{
    return  MY_VEC2IZE4(Vwbi, INT8_CEQY, a, b);
}

INLINE(Vwbc,VWBC_CEQY) (Vwbc a, Vwbc b) 
{
    return  MY_VEC2IZE4(Vwbc, CHAR_CEQY, a, b);
}


INLINE(Vwhu,VWHU_CEQY) (Vwhu a, Vwhu b) 
{
    return  MY_VEC2IZE2(Vwhu, UINT16_CEQY, a, b);
}

INLINE(Vwhi,VWHI_CEQY) (Vwhi a, Vwhi b) 
{
    return  MY_VEC2IZE2(Vwhi, INT16_CEQY, a, b);
}


INLINE(Vwwu,VWWU_CEQY) (Vwwu a, Vwwu b) 
{
    return  ((Vwwu){UINT32_CEQY(a.K0, b.K0)});
}

INLINE(Vwwi,VWWI_CEQY) (Vwwi a, Vwwi b) 
{
    return  ((Vwwi){INT32_CEQY(a.K0, b.K0)});
}


INLINE(Vdyu,VDYU_CEQY) (Vdyu a, Vdyu b)
{
    DWRD_TYPE p = {.M64.U=a};
    DWRD_TYPE q = {.M64.U=b};
    p.U = ~(p.U^q.U);
    return  p.M64.U;
}


INLINE(Vdbu,VDBU_CEQY) (Vdbu a, Vdbu b) 
{
    return  MY_VEC2IZE8(Vdbu, UINT8_CEQY, a, b);
}

INLINE(Vdbi,VDBI_CEQY) (Vdbi a, Vdbi b) 
{
    return  MY_VEC2IZE8(Vdbi, INT8_CEQY, a, b);
}

INLINE(Vdbc,VDBC_CEQY) (Vdbc a, Vdbc b) 
{
    return  MY_VEC2IZE8(Vdbc, CHAR_CEQY, a, b);
}


INLINE(Vdhu,VDHU_CEQY) (Vdhu a, Vdhu b) 
{
    return  MY_VEC2IZE4(Vdhu, UINT16_CEQY, a, b);
}

INLINE(Vdhi,VDHI_CEQY) (Vdhi a, Vdhi b) 
{
    return  MY_VEC2IZE4(Vdhi, INT16_CEQY, a, b);
}


INLINE(Vdwu,VDWU_CEQY) (Vdwu a, Vdwu b) 
{
    return  MY_VEC2IZE2(Vdwu, UINT32_CEQY, a, b);
}

INLINE(Vdwi,VDWI_CEQY) (Vdwi a, Vdwi b) 
{
    return  MY_VEC2IZE2(Vdwi, INT32_CEQY, a, b);
}


INLINE(Vddu,VDDU_CEQY) (Vddu a, Vddu b) 
{
    return  MY_VEC2IZE1(Vddu, UINT64_CEQY, a, b);
}

INLINE(Vddi,VDDI_CEQY) (Vddi a, Vddi b) 
{
    return  MY_VEC2IZE1(Vddi, INT64_CEQY, a, b);
}



INLINE(Vqyu,VQYU_CEQY) (Vqyu a, Vqyu b)
{
    QUAD_TYPE p = {.M128.U=a};
    QUAD_TYPE q = {.M128.U=b};
    p.Lo.U = ~(p.Lo.U^q.Lo.U);
    p.Hi.U = ~(p.Hi.U^q.Hi.U);
    return  p.M128.U;
}


INLINE(Vqbu,VQBU_CEQY) (Vqbu a, Vqbu b) 
{
    return  MY_VEC2IZE16(Vqbu, UINT8_CEQY, a, b);
}

INLINE(Vqbi,VQBI_CEQY) (Vqbi a, Vqbi b) 
{
    return  MY_VEC2IZE16(Vqbi, INT8_CEQY, a, b);
}

INLINE(Vqbc,VQBC_CEQY) (Vqbc a, Vqbc b) 
{
    return  MY_VEC2IZE16(Vqbc, CHAR_CEQY, a, b);
}


INLINE(Vqhu,VQHU_CEQY) (Vqhu a, Vqhu b) 
{
    return  MY_VEC2IZE8(Vqhu, UINT16_CEQY, a, b);
}

INLINE(Vqhi,VQHI_CEQY) (Vqhi a, Vqhi b) 
{
    return  MY_VEC2IZE8(Vqhi, INT16_CEQY, a, b);
}


INLINE(Vqwu,VQWU_CEQY) (Vqwu a, Vqwu b) 
{
    return  MY_VEC2IZE4(Vqwu, UINT32_CEQY, a, b);
}

INLINE(Vqwi,VQWI_CEQY) (Vqwi a, Vqwi b) 
{
    return  MY_VEC2IZE4(Vqwi, INT32_CEQY, a, b);
}


INLINE(Vqdu,VQDU_CEQY) (Vqdu a, Vqdu b) 
{
    return  MY_VEC2IZE2(Vqdu, UINT64_CEQY, a, b);
}

INLINE(Vqdi,VQDI_CEQY) (Vqdi a, Vqdi b) 
{
    return  MY_VEC2IZE2(Vqdi, INT64_CEQY, a, b);
}

#if 0 // _LEAVE_ANY_CEQY
}
#endif

#if 0 // _ENTER_ANY_REVY
{
#endif
/*  
clang is currently the only compiler capable optimizing 
these to a single bit reversal instruction, on platforms 
with such a thing.
*/

INLINE(uint8_t,revybz)  (uint8_t x)
{
    BYTE_TYPE v = {.U=x};
    v.U = ((v.U>>1)&0x55ULL)|((v.U&0x55ULL)<<1);
    v.U = ((v.U>>2)&0x33ULL)|((v.U&0x33ULL)<<2);
    v.U = ((v.U>>4)&0x0fULL)|((v.U&0x0fULL)<<4);
    return  v.U;
}

INLINE(uint16_t,revyhz) (uint16_t x) 
{
    HALF_TYPE v = {.U=x};
    v.U = ((v.U>>001)&0x5555ULL)|((v.U&0x5555ULL)<<001);
    v.U = ((v.U>>002)&0x3333ULL)|((v.U&0x3333ULL)<<002);
    v.U = ((v.U>>004)&0x0f0fULL)|((v.U&0x0f0fULL)<<004);
    v.U = ((v.U>>010)&0x00ffULL)|((v.U&0x00ffULL)<<010);
    return  v.U;
}

INLINE(uint32_t,revywz) (uint32_t x) 
{
    WORD_TYPE v = {.U=x};
    v.U = ((v.U>>001)&0x55555555ULL)|((v.U&0x55555555ULL)<<001);
    v.U = ((v.U>>002)&0x33333333ULL)|((v.U&0x33333333ULL)<<002);
    v.U = ((v.U>>004)&0x0f0f0f0fULL)|((v.U&0x0f0f0f0fULL)<<004);
    v.U = ((v.U>>010)&0x00ff00ffULL)|((v.U&0x00ff00ffULL)<<010);
    v.U = ((v.U>>020)|(v.U<<020));
    return  v.U;
}

INLINE(uint64_t,revydz) (uint64_t x) 
{
    DWRD_TYPE v = {.U=x};
    v.U = ((v.U>>001)&0x5555555555555555ULL)|((v.U&0x5555555555555555ULL)<<001);
    v.U = ((v.U>>002)&0x3333333333333333ULL)|((v.U&0x3333333333333333ULL)<<002);
    v.U = ((v.U>>004)&0x0f0f0f0f0f0f0f0fULL)|((v.U&0x0f0f0f0f0f0f0f0fULL)<<004);
    v.U = ((v.U>>010)&0x00ff00ff00ff00ffULL)|((v.U&0x00ff00ff00ff00ffULL)<<010);
    v.U = ((v.U>>020)&0x0000ffff0000ffffULL)|((v.U&0x0000ffff0000ffffULL)<<020);
    v.U = ((v.U>>040)|(v.U<<040));
    return  v.U;
}

INLINE(QUAD_UTYPE,revyqz) (QUAD_UTYPE x) 
{
#if QUAD_NLLONG == 2
    QUAD_TYPE const v = {.U=x};
    return (
        (QUAD_TYPE const)
        {
            .Lo=revydz(v.Hi.U),
            .Hi=revydz(v.Lo.U),
        }
    ).U;
#else
    QUAD_TYPE v = {.U=x};
    v.U = (
        ((v.U>>001)&0x55555555555555555555555555555555ULL)
    |   ((v.U&0x55555555555555555555555555555555ULL)<<001)
    );
    v.U = (
        ((v.U>>002)&0x33333333333333333333333333333333ULL)
    |   ((v.U&0x33333333333333333333333333333333ULL)<<002)
    );
    v.U = (
        ((v.U>>004)&0x0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0fULL)
    |   ((v.U&0x0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0fULL)<<004)
    );
    v.U = (
        ((v.U>>010)&0x00ff00ff00ff00ff00ff00ff00ff00ffULL)
    |   ((v.U&0x00ff00ff00ff00ff00ff00ff00ff00ffULL)<<010)
    );
    v.U = (
        ((v.U>>020)&0x0000ffff0000ffff0000ffff0000ffffULL)
    |   ((v.U&0x0000ffff0000ffff0000ffff0000ffffULL)<<020)
    );
    v.U = (
        ((v.U>>040)&0x00000000ffffffff00000000ffffffffULL)
    |   ((v.U&0x00000000ffffffff00000000ffffffffULL)<<040)
    );
    v.U = ((v.U>>64)|(v.U<<64));
    return  v.U;
#endif
}

INLINE( uchar, UCHAR_REVY)  (uchar x) {return (revybz)(x);}
INLINE( schar, SCHAR_REVY)  (schar x) {return (revybz)(x);}
INLINE(  char,  CHAR_REVY)   (char x) {return (revybz)(x);}
INLINE(ushort, USHRT_REVY) (ushort x) {return (revyhz)(x);}
INLINE( short,  SHRT_REVY)  (short x) {return (revyhz)(x);}
INLINE(  uint,  UINT_REVY)   (uint x) {return (revywz)(x);}
INLINE(   int,   INT_REVY)    (int x) {return (revywz)(x);}
INLINE( ulong, ULONG_REVY)  (ulong x) 
{
#if DWRD_NLONG == 2
    return  (revywz)(x);
#else
    return  (revydz)(x);
#endif
}

INLINE(  long,  LONG_REVY)   (long x) {return ULONG_REVY(x);}

INLINE(ullong,ULLONG_REVY) (ullong x) 
{
#if QUAD_NLONG == 2
    return  (revydz)(x);
#else
    return  (revyqz)(x);
#endif
}

INLINE( llong, LLONG_REVY)  (llong x) {return ULLONG_REVY(x);}

INLINE(Vwbu,VWBU_REVY) (Vwbu v) {return MY_VEC1IZE4(Vwbu, revybz, v);}
INLINE(Vwbi,VWBI_REVY) (Vwbi v) {return MY_VEC1IZE4(Vwbi, revybz, v);}
INLINE(Vwbc,VWBC_REVY) (Vwbc v) {return MY_VEC1IZE4(Vwbc, revybz, v);}
INLINE(Vwhu,VWHU_REVY) (Vwhu v) {return MY_VEC1IZE2(Vwhu, revyhz, v);}
INLINE(Vwhi,VWHI_REVY) (Vwhi v) {return MY_VEC1IZE2(Vwhi, revyhz, v);}
INLINE(Vwwu,VWWU_REVY) (Vwwu v) {return MY_VEC1IZE1(Vwwu, revywz, v);}
INLINE(Vwwi,VWWI_REVY) (Vwwi v) {return MY_VEC1IZE1(Vwwi, revywz, v);}

INLINE(Vdbu,VDBU_REVY) (Vdbu v) {return MY_VEC1IZE8(Vdbu, revybz, v);}
INLINE(Vdbi,VDBI_REVY) (Vdbi v) {return MY_VEC1IZE8(Vdbi, revybz, v);}
INLINE(Vdbc,VDBC_REVY) (Vdbc v) {return MY_VEC1IZE8(Vdbc, revybz, v);}
INLINE(Vdhu,VDHU_REVY) (Vdhu v) {return MY_VEC1IZE4(Vdhu, revyhz, v);}
INLINE(Vdhi,VDHI_REVY) (Vdhi v) {return MY_VEC1IZE4(Vdhi, revyhz, v);}
INLINE(Vdwu,VDWU_REVY) (Vdwu v) {return MY_VEC1IZE2(Vdwu, revywz, v);}
INLINE(Vdwi,VDWI_REVY) (Vdwi v) {return MY_VEC1IZE2(Vdwi, revywz, v);}
INLINE(Vddu,VDDU_REVY) (Vddu v) {return MY_VEC1IZE1(Vddu, revydz, v);}
INLINE(Vddi,VDDI_REVY) (Vddi v) {return MY_VEC1IZE1(Vddi, revydz, v);}

INLINE(Vqbu,VQBU_REVY) (Vqbu v) {return MY_VEC1IZE16(Vqbu, revybz, v);}
INLINE(Vqbi,VQBI_REVY) (Vqbi v) {return MY_VEC1IZE16(Vqbi, revybz, v);}
INLINE(Vqbc,VQBC_REVY) (Vqbc v) {return MY_VEC1IZE16(Vqbc, revybz, v);}
INLINE(Vqhu,VQHU_REVY) (Vqhu v) {return MY_VEC1IZE8(Vqhu, revyhz, v);}
INLINE(Vqhi,VQHI_REVY) (Vqhi v) {return MY_VEC1IZE8(Vqhi, revyhz, v);}
INLINE(Vqwu,VQWU_REVY) (Vqwu v) {return MY_VEC1IZE4(Vqwu, revywz, v);}
INLINE(Vqwi,VQWI_REVY) (Vqwi v) {return MY_VEC1IZE4(Vqwi, revywz, v);}
INLINE(Vqdu,VQDU_REVY) (Vqdu v) {return MY_VEC1IZE2(Vqdu, revydz, v);}
INLINE(Vqdi,VQDI_REVY) (Vqdi v) {return MY_VEC1IZE2(Vqdi, revydz, v);}

#if 0 // _LEAVE_ANY_REVY
}
#endif
#if 0 // _ENTER_ANY_CNT1
{
#endif

unsigned cnt1wz(unsigned v)
{
    unsigned c;
    c = v-(0x55555555&(v>>001));
    c =   (0x33333333& (c>>002))+(0x33333333&c);
    c =   (0x0F0F0F0F&((c>>004)+c));
    c =   (0x00FF00FF&((c>>010)+c));
    c =   (0x0000FFFF&((c>>020)+c));
    return c;
}
#endif

uint64_t cnt1dz(uint64_t v)
{
    uint64_t c;
    c = v-(UINT64_C(0x5555555555555555)& (v>>001));
    c =   (UINT64_C(0x3333333333333333)& (c>>002))+(0x3333333333333333ull&c);
    c =   (UINT64_C(0x0F0F0F0F0F0F0F0F)&((c>>004)+c));
    c =   (UINT64_C(0x00FF00FF00FF00FF)&((c>>010)+c));
    c =   (UINT64_C(0x0000FFFF0000FFFF)&((c>>020)+c));
    c =   (UINT64_C(0x00000000FFFFFFFF)&((c>>040)+c));
    return c;
}

#if DWRD_NLONG == 2
#   define  MY_CNT1L    cnt1wz
#else
#   define  MY_CNT1L    cnt1dz
#endif

#if QUAD_NLLONG == 2
#   define  MY_CNT1LL   cnt1dz
#else
#   define  MY_CNT1LL   MY_CNT1Q
#endif

INLINE( UCHAR_STG(UTYPE), UCHAR_CNT1)  (uchar x) {return cnt1wz(x);}
INLINE( SCHAR_STG(ITYPE), SCHAR_CNT1)  (schar x) {return cnt1wz(x);}
INLINE(             char,  CHAR_CNT1)   (char x) {return cnt1wz(x);}
INLINE( USHRT_STG(UTYPE), USHRT_CNT1) (ushort x) {return cnt1wz(x);}
INLINE(  SHRT_STG(ITYPE),  SHRT_CNT1)  (short x) {return cnt1wz(x);}
INLINE(  UINT_STG(UTYPE),  UINT_CNT1)   (uint x) {return cnt1wz(x);}
INLINE(   INT_STG(ITYPE),   INT_CNT1)    (int x) {return cnt1wz(x);}
INLINE( ULONG_STG(UTYPE), ULONG_CNT1)  (ulong x) {return MY_CNT1L(x);}
INLINE(  LONG_STG(UTYPE),  LONG_CNT1)   (long x) {return MY_CNT1L(x);}
INLINE(ULLONG_STG(UTYPE),ULLONG_CNT1) (ullong x) {return MY_CNT1LL(x);}
INLINE( LLONG_STG(UTYPE), LLONG_CNT1)  (llong x) {return MY_CNT1LL(x);}

INLINE(Vwbu,VWBU_CNT1) (Vwbu x) {return MY_VEC1IZE4(Vwbu, cnt1wz, x);}
INLINE(Vwbi,VWBI_CNT1) (Vwbi x) {return MY_VEC1IZE4(Vwbi, cnt1wz, x);}
INLINE(Vwbc,VWBC_CNT1) (Vwbc x) {return MY_VEC1IZE4(Vwbc, cnt1wz, x);}
INLINE(Vwhu,VWHU_CNT1) (Vwhu x) {return MY_VEC1IZE2(Vwhu, cnt1wz, x);}
INLINE(Vwhi,VWHI_CNT1) (Vwhi x) {return MY_VEC1IZE2(Vwhi, cnt1wz, x);}
INLINE(Vwwu,VWWU_CNT1) (Vwwu x) {return MY_VEC1IZE1(Vwwu, cnt1wz, x);}
INLINE(Vwwi,VWWI_CNT1) (Vwwi x) {return MY_VEC1IZE1(Vwwi, cnt1wz, x);}

INLINE(Vdbu,VDBU_CNT1) (Vdbu x) {return MY_VEC1IZE8(Vdbu, cnt1wz, x);}
INLINE(Vdbi,VDBI_CNT1) (Vdbi x) {return MY_VEC1IZE8(Vdbi, cnt1wz, x);}
INLINE(Vdbc,VDBC_CNT1) (Vdbc x) {return MY_VEC1IZE8(Vdbc, cnt1wz, x);}
INLINE(Vdhu,VDHU_CNT1) (Vdhu x) {return MY_VEC1IZE4(Vdhu, cnt1wz, x);}
INLINE(Vdhi,VDHI_CNT1) (Vdhi x) {return MY_VEC1IZE4(Vdhi, cnt1wz, x);}
INLINE(Vdwu,VDWU_CNT1) (Vdwu x) {return MY_VEC1IZE2(Vdwu, cnt1wz, x);}
INLINE(Vdwi,VDWI_CNT1) (Vdwi x) {return MY_VEC1IZE2(Vdwi, cnt1wz, x);}
INLINE(Vddu,VDDU_CNT1) (Vddu x) {return MY_VEC1IZE1(Vddu, cnt1dz, x);}
INLINE(Vddi,VDDI_CNT1) (Vddi x) {return MY_VEC1IZE1(Vddi, cnt1dz, x);}

INLINE(Vqbu,VQBU_CNT1) (Vqbu x) {return MY_VEC1IZE16(Vqbu, cnt1wz, x);}
INLINE(Vqbi,VQBI_CNT1) (Vqbi x) {return MY_VEC1IZE16(Vqbi, cnt1wz, x);}
INLINE(Vqbc,VQBC_CNT1) (Vqbc x) {return MY_VEC1IZE16(Vqbc, cnt1wz, x);}
INLINE(Vqhu,VQHU_CNT1) (Vqhu x) {return MY_VEC1IZE8(Vqhu,  cnt1wz, x);}
INLINE(Vqhi,VQHI_CNT1) (Vqhi x) {return MY_VEC1IZE8(Vqhi,  cnt1wz, x);}
INLINE(Vqwu,VQWU_CNT1) (Vqwu x) {return MY_VEC1IZE4(Vqwu,  cnt1wz, x);}
INLINE(Vqwi,VQWI_CNT1) (Vqwi x) {return MY_VEC1IZE4(Vqwi,  cnt1wz, x);}
INLINE(Vqdu,VQDU_CNT1) (Vqdu x) {return MY_VEC1IZE2(Vqdu,  cnt1dz, x);}
INLINE(Vqdi,VQDI_CNT1) (Vqdi x) {return MY_VEC1IZE2(Vqdi,  cnt1dz, x);}

#if 0 // _LEAVE_ANY_CNT1
}
#endif
