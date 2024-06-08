/*

HISTORY:

2024-05-23
* implemented zipl
* implemented uzpl, uzpr
* implemented dupw, dupd, dupq
* implemented mvql, mvdl, mvwl


Operations with an x86 implementation. 

Actually... we require SSSE3 and all extensions its presence
implies for an Intel or AMD processor. Anything manufactured
after 2010 should suffice.

x86 has some rather severe flaws, mostly related to a lack 
of 8 bit SIMD. E.g. even in 2024, there's no equivalent for
the 8 bit svl and svr series. svrsdbi(a, b) must be
implemented as a cvbi(svrs(cvhi(a), cvhi(b))) and there is
no hardware support without SPC_X86_AVX512. Well, svrsqwz 
maps to a single instruction with SPC_X86_AVX2. If the C
intrinsics are considered, the fact there is only 1 integer
vector type and the way certain intrinsics take pointers to
__m128 might also be problematic.

On the other hand, the limited number of intrinsic vector 
types dramatically reduces the number of intrinsics and
correspondingly reduces the compile time cost. It's nice 
that NEON has vaddq_u8 and vaddq_s8 for adding unsigned or
signed 8 bit integers but semantically, those intrinsics 
compile to the same thing. 

Since _mm_shuffle_epi8 is going to be one of if not the most
commonly occuring symbol, here's an illustration that can
be used to compute its second operand

    .B .B .B .B .B .B .B .B   .B .B .B .B .B .B .B .B
    0f 0e 0d 0c 0b 0a 09 08   07 06 05 04 03 02 01 00
    |           |     |       |     |     |     |
    |..H7 |..H6 |..H5 |..H4   |..H3 |..H2 |..H1 |..H0
    |0f0e  0d0c |0b0a  0908   |0706  0504 |0302 |0100
    | \7/   \6/ | \5/   \4/   | \3/   \2/ | \1/   \0/
    |           |             |           |
    |   .....W3 |   .....W2   |   .....W1 | .......W0
    |  0f0e0d0c    0b0a0908   |  07060504    03020100
    |   \  3  /     \  2  /   |   \  1  /     \  0  /
    |       .............D1   |       .............D0
    |       \      1      /   |       \      0      /
    |      0f0e0d0c0b0a0908   |      0706050403020100
              
*/
#if 0 // _ENTER_X86
{
#endif

#ifdef SPC_X86_SSE2

#if 0 // _ENTER_X86_VOID
{
#endif

#define     WBU_VOID    (0.0f)
#define     WBI_VOID    (0.0f)
#define     WHU_VOID    (0.0f)
#define     WHI_VOID    (0.0f)
#define     WHF_VOID    (0.0f)
#define     WWU_VOID    (0.0f)
#define     WWI_VOID    (0.0f)
#define     WWF_VOID    (0.0f)

#define     DBU_VOID    (0.0)
#define     DBI_VOID    (0.0)
#define     DHU_VOID    (0.0)
#define     DHI_VOID    (0.0)
#define     DHF_VOID    (0.0)
#define     DWU_VOID    (0.0)
#define     DWI_VOID    (0.0)
#define     DWF_VOID    (0.0)
#define     DDU_VOID    (0.0)
#define     DDI_VOID    (0.0)
#define     DDF_VOID    (0.0)

#define     QYU_VOID    (_mm_undefined_si128())
#define     QBU_VOID    (_mm_undefined_si128())
#define     QBI_VOID    (_mm_undefined_si128())
#define     QHU_VOID    (_mm_undefined_si128())
#define     QHI_VOID    (_mm_undefined_si128())
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_VOID    (_mm_undefined_ph())
#else
#   define  QHF_VOID    (_mm_undefined_si128())
#endif
#define     QWU_VOID    (_mm_undefined_si128())
#define     QWI_VOID    (_mm_undefined_si128())
#define     QWF_VOID    (_mm_undefined_ps())
#define     QDU_VOID    (_mm_undefined_si128())
#define     QDI_VOID    (_mm_undefined_si128())
#define     QDF_VOID    (_mm_undefined_pd())

#define     VWYU_VOID   ((VWYU_TYPE){WYU_VOID})
#define     VWBU_VOID   ((VWBU_TYPE){WBU_VOID})
#define     VWBI_VOID   ((VWBI_TYPE){WBI_VOID})
#define     VWHU_VOID   ((VWHU_TYPE){WHU_VOID})
#define     VWHI_VOID   ((VWHI_TYPE){WHI_VOID})
#define     VWHF_VOID   ((VWHF_TYPE){WHF_VOID})
#define     VWWU_VOID   ((VWWU_TYPE){WWU_VOID})
#define     VWWI_VOID   ((VWWI_TYPE){WWI_VOID})
#define     VWWF_VOID   ((VWWF_TYPE){WWF_VOID})

#define     VDYU_VOID   ((VDYU_TYPE){DYU_VOID})
#define     VDBU_VOID   ((VDBU_TYPE){DBU_VOID})
#define     VDBI_VOID   ((VDBI_TYPE){DBI_VOID})
#define     VDHU_VOID   ((VDHU_TYPE){DHU_VOID})
#define     VDHI_VOID   ((VDHI_TYPE){DHI_VOID})
#define     VDHF_VOID   ((VDHF_TYPE){DHF_VOID})
#define     VDWU_VOID   ((VDWU_TYPE){DWU_VOID})
#define     VDWI_VOID   ((VDWI_TYPE){DWI_VOID})
#define     VDWF_VOID   ((VDWF_TYPE){DWF_VOID})
#define     VDDU_VOID   ((VDDU_TYPE){DDU_VOID})
#define     VDDI_VOID   ((VDDI_TYPE){DDI_VOID})
#define     VDDF_VOID   ((VDDF_TYPE){DDF_VOID})


#define     VQYU_VOID   QYU_VOID
#define     VQBU_VOID   ((VQBU_TYPE){QBU_VOID})
#define     VQBI_VOID   ((VQBI_TYPE){QBI_VOID})

#define     VQHU_VOID   ((VQHU_TYPE){QHU_VOID})
#define     VQHI_VOID   ((VQHI_TYPE){QHI_VOID})
#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_VOID   QHF_VOID
#else
#   define  VQHF_VOID   ((VQHF_TYPE){QHF_VOID})
#endif

#define     VQWU_VOID   ((VQWU_TYPE){QWU_VOID})
#define     VQWI_VOID   ((VQWI_TYPE){QWI_VOID})
#define     VQWF_VOID   QWF_VOID
#define     VQDU_VOID   ((VQDU_TYPE){QDU_VOID})
#define     VQDI_VOID   ((VQDI_TYPE){QDI_VOID})
#define     VQDF_VOID   QDF_VOID


#if 0 // _LEAVE_X86_VOID
}
#endif

#if 0 // _ENTER_X86_ASTM
{
#endif

// astm
#define     MY_HVA1_ASTM(T,V)   _Generic((V),T:(V).V0)

#define     VWBU_ASTM(V)        MY_HVA1_ASTM(VWBU_TYPE,V)
#define     VWBI_ASTM(V)        MY_HVA1_ASTM(VWBI_TYPE,V)
#define     VWBC_ASTM(V)        MY_HVA1_ASTM(VWBC_TYPE,V)
#define     VWHU_ASTM(V)        MY_HVA1_ASTM(VWHU_TYPE,V)
#define     VWHI_ASTM(V)        MY_HVA1_ASTM(VWHI_TYPE,V)
#define     VWHF_ASTM(V)        MY_HVA1_ASTM(VWHF_TYPE,V)
#define     VWWU_ASTM(V)        MY_HVA1_ASTM(VWWU_TYPE,V)
#define     VWWI_ASTM(V)        MY_HVA1_ASTM(VWWI_TYPE,V)
#define     VWWF_ASTM(V)        MY_HVA1_ASTM(VWWF_TYPE,V)

#define     VDBU_ASTM(V)        MY_HVA1_ASTM(VDBU_TYPE,V)
#define     VDBI_ASTM(V)        MY_HVA1_ASTM(VDBI_TYPE,V)
#define     VDBC_ASTM(V)        MY_HVA1_ASTM(VDBC_TYPE,V)
#define     VDHU_ASTM(V)        MY_HVA1_ASTM(VDHU_TYPE,V)
#define     VDHI_ASTM(V)        MY_HVA1_ASTM(VDHI_TYPE,V)
#define     VDHF_ASTM(V)        MY_HVA1_ASTM(VDHF_TYPE,V)
#define     VDWU_ASTM(V)        MY_HVA1_ASTM(VDWU_TYPE,V)
#define     VDWI_ASTM(V)        MY_HVA1_ASTM(VDWI_TYPE,V)
#define     VDWF_ASTM(V)        MY_HVA1_ASTM(VDWF_TYPE,V)
#define     VDDU_ASTM(V)        MY_HVA1_ASTM(VDDU_TYPE,V)
#define     VDDI_ASTM(V)        MY_HVA1_ASTM(VDDI_TYPE,V)
#define     VDDF_ASTM(V)        MY_HVA1_ASTM(VDDF_TYPE,V)

#define     VQBU_ASTM(V)        MY_HVA1_ASTM(VQBU_TYPE,V)
#define     VQBI_ASTM(V)        MY_HVA1_ASTM(VQBI_TYPE,V)
#define     VQBC_ASTM(V)        MY_HVA1_ASTM(VQBC_TYPE,V)

#define     VQHU_ASTM(V)        MY_HVA1_ASTM(VQHU_TYPE,V)
#define     VQHI_ASTM(V)        MY_HVA1_ASTM(VQHI_TYPE,V)
#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_ASTM           VQHF_REQS
#else
#define     VQHF_ASTM(V)        MY_HVA1_ASTM(VQHF_TYPE,V)
#endif

#define     VQWU_ASTM(V)        MY_HVA1_ASTM(VQWU_TYPE,V)
#define     VQWI_ASTM(V)        MY_HVA1_ASTM(VQWI_TYPE,V)
#define     VQWF_ASTM           VQWF_REQS
#define     VQDU_ASTM(V)        MY_HVA1_ASTM(VQDU_TYPE,V)
#define     VQDI_ASTM(V)        MY_HVA1_ASTM(VQDI_TYPE,V)
#define     VQDF_ASTM(V)        MY_HVA1_ASTM(VQDF_TYPE,V)
#define     VQDF_ASTM           VQDF_REQS

#if 0 // _LEAVE_X86_ASTM
}
#endif

#if 0 // _ENTER_X86_ASTV
{
#endif

#define     MY_HVA1_NEWL(T,M)   ((T){.V0=(M)})

#define     WYU_ASTV(M)         MY_HVA1_NEWL(VWYU_TYPE,M)
#define     WBU_ASTV(M)         MY_HVA1_NEWL(VWBU_TYPE,M)
#define     WBI_ASTV(M)         MY_HVA1_NEWL(VWBI_TYPE,M)
#define     WBC_ASTV(M)         MY_HVA1_NEWL(VWBC_TYPE,M)
#define     WHU_ASTV(M)         MY_HVA1_NEWL(VWHU_TYPE,M)
#define     WHI_ASTV(M)         MY_HVA1_NEWL(VWHI_TYPE,M)
#define     WHF_ASTV(M)         MY_HVA1_NEWL(VWHF_TYPE,M)
#define     WWU_ASTV(M)         MY_HVA1_NEWL(VWWU_TYPE,M)
#define     WWI_ASTV(M)         MY_HVA1_NEWL(VWWI_TYPE,M)
#define     WWF_ASTV(M)         MY_HVA1_NEWL(VWWF_TYPE,M)

INLINE(uint32_t,VWWU_ASTV) (Vwwu v)
{
#   define  VWWU_ASTV(V)    (((WORD_TYPE){.F=VWWU_ASTM(V)}).U)
    return  (WORD_TYPE){.F=v.V0}.U;
}

INLINE( int32_t,VWWI_ASTV) (Vwwi v)
{
#   define  VWWI_ASTV(V)    (((WORD_TYPE){.F=VWWI_ASTM(V)}).I)
    return  (WORD_TYPE){.F=v.V0}.I;
}

INLINE(   float,VWWF_ASTV) (Vwwf v)
{
#   define  VWWF_ASTV   VWWF_ASTM
    return  v.V0;
}

#define     VWWI_ASTV(V)        ((WORD_TYPE){.F=(VWWI_REQS(V).V0)}).I

#define     DYU_ASTV(M)         MY_HVA1_NEWL(VDYU_TYPE,M)
#define     DBU_ASTV(M)         MY_HVA1_NEWL(VDBU_TYPE,M)
#define     DBI_ASTV(M)         MY_HVA1_NEWL(VDBI_TYPE,M)
#define     DBC_ASTV(M)         MY_HVA1_NEWL(VDBC_TYPE,M)
#define     DHU_ASTV(M)         MY_HVA1_NEWL(VDHU_TYPE,M)
#define     DHI_ASTV(M)         MY_HVA1_NEWL(VDHI_TYPE,M)
#define     DHF_ASTV(M)         MY_HVA1_NEWL(VDHF_TYPE,M)
#define     DWU_ASTV(M)         MY_HVA1_NEWL(VDWU_TYPE,M)
#define     DWI_ASTV(M)         MY_HVA1_NEWL(VDWI_TYPE,M)
#define     DWF_ASTV(M)         MY_HVA1_NEWL(VDWF_TYPE,M)
#define     DDU_ASTV(M)         MY_HVA1_NEWL(VDDU_TYPE,M)
#define     DDI_ASTV(M)         MY_HVA1_NEWL(VDDI_TYPE,M)
#define     DDF_ASTV(M)         MY_HVA1_NEWL(VDDF_TYPE,M)

#define     VDYU_ASTV(V)        ((DWRD_TYPE){.F=(VDDU_REQS(V).V0)}).U
#define     VDDU_ASTV(V)        ((DWRD_TYPE){.F=(VDDU_REQS(V).V0)}).U
#define     VDDI_ASTV(V)        ((DWRD_TYPE){.F=(VDDI_REQS(V).V0)}).I
#define     VDDF_ASTV(V)                        (VDDU_REQS(V).V0)

#define     QYU_ASTV(M)         _Generic((M),__m128i:(M))
#define     QBU_ASTV(M)         MY_HVA1_NEWL(VDBU_TYPE,M)
#define     QBI_ASTV(M)         MY_HVA1_NEWL(VQBI_TYPE,M)
#define     QBC_ASTV(M)         MY_HVA1_NEWL(VQBC_TYPE,M)
#define     QHU_ASTV(M)         MY_HVA1_NEWL(VQHU_TYPE,M)
#define     QHI_ASTV(M)         MY_HVA1_NEWL(VQHI_TYPE,M)
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_ASTV(M)         _Generic((M),__m128h:(M))
#else
#   define  QHF_ASTV(M)         MY_HVA1_NEWL(VQHF_TYPE,M)
#endif
#define     QWU_ASTV(M)         MY_HVA1_NEWL(VQWU_TYPE,M)
#define     QWI_ASTV(M)         MY_HVA1_NEWL(VQWI_TYPE,M)
#define     QWF_ASTV(M)         _Generic((M),__m128: (M))
#define     QDU_ASTV(M)         MY_HVA1_NEWL(VQDU_TYPE,M)
#define     QDI_ASTV(M)         MY_HVA1_NEWL(VQDI_TYPE,M)
#define     QDF_ASTV(M)         _Generic((M),__m128d:(M))

#if 0 // _LEAVE_X86_ASTV
}
#endif

#if 0 // _ENTER_X86_ASYU
{
#endif

INLINE(Vwyu,VWBU_ASYU) (Vwbu v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWBI_ASYU) (Vwbi v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWBC_ASYU) (Vwbc v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWHU_ASYU) (Vwhu v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWHI_ASYU) (Vwhi v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWHF_ASYU) (Vwhf v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWWU_ASYU) (Vwwu v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWWI_ASYU) (Vwwi v) {return (VWYU_TYPE){v.V0};}
INLINE(Vwyu,VWWF_ASYU) (Vwwf v) {return (VWYU_TYPE){v.V0};}

INLINE(Vdyu,VDBU_ASYU) (Vdbu v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDBI_ASYU) (Vdbi v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDBC_ASYU) (Vdbc v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDHU_ASYU) (Vdhu v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDHI_ASYU) (Vdhi v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDHF_ASYU) (Vdhf v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDWU_ASYU) (Vdwu v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDWI_ASYU) (Vdwi v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDWF_ASYU) (Vdwf v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDDU_ASYU) (Vddu v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDDI_ASYU) (Vddi v) {return (VDYU_TYPE){v.V0};}
INLINE(Vdyu,VDDF_ASYU) (Vddf v) {return (VDYU_TYPE){v.V0};}

INLINE(Vqyu,VQBU_ASYU) (Vqbu v) {return v.V0;}
INLINE(Vqyu,VQBI_ASYU) (Vqbi v) {return v.V0;}
INLINE(Vqyu,VQBC_ASYU) (Vqbc v) {return v.V0;}
INLINE(Vqyu,VQHU_ASYU) (Vqhu v) {return v.V0;}
INLINE(Vqyu,VQHI_ASYU) (Vqhi v) {return v.V0;}
INLINE(Vqyu,VQHF_ASYU) (Vqhf v) 
{
#if defined(SPC_X64_FP16)
    return  _mm_castph_si128(v);
#else
    return  v.V0;
#endif
}

INLINE(Vqyu,VQWU_ASYU) (Vqwu v) {return v.V0;}
INLINE(Vqyu,VQWI_ASYU) (Vqwi v) {return v.V0;}
INLINE(Vqyu,VQWF_ASYU) (Vqwf v) {return _mm_castps_si128(v);}
INLINE(Vqyu,VQDU_ASYU) (Vqdu v) {return v.V0;}
INLINE(Vqyu,VQDI_ASYU) (Vqdi v) {return v.V0;}
INLINE(Vqyu,VQDF_ASYU) (Vqdf v) {return _mm_castpd_si128(v);}

#if 0 // _LEAVE_X86_ASYU
}
#endif

#if 0 // _ENTER_X86_ASBU
{
#endif

INLINE(Vwbu,VWYU_ASBU) (Vwyu v) {return (VWBU_TYPE){v.V0};}

INLINE(Vwbu,VWBI_ASBU) (Vwbi v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWBC_ASBU) (Vwbc v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWHU_ASBU) (Vwhu v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWHI_ASBU) (Vwhi v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWHF_ASBU) (Vwhf v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWWU_ASBU) (Vwwu v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWWI_ASBU) (Vwwi v) {return (VWBU_TYPE){v.V0};}
INLINE(Vwbu,VWWF_ASBU) (Vwwf v) {return (VWBU_TYPE){v.V0};}

INLINE(Vdbu,VDYU_ASBU) (Vdyu v) {return (VDBU_TYPE){v.V0};}

INLINE(Vdbu,VDBI_ASBU) (Vdbi v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDBC_ASBU) (Vdbc v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDHU_ASBU) (Vdhu v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDHI_ASBU) (Vdhi v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDHF_ASBU) (Vdhf v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDWU_ASBU) (Vdwu v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDWI_ASBU) (Vdwi v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDWF_ASBU) (Vdwf v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDDU_ASBU) (Vddu v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDDI_ASBU) (Vddi v) {return (VDBU_TYPE){v.V0};}
INLINE(Vdbu,VDDF_ASBU) (Vddf v) {return (VDBU_TYPE){v.V0};}

INLINE(Vqbu,VQYU_ASBU) (Vqyu v) {return (VQBU_TYPE){v};}

INLINE(Vqbu,VQBI_ASBU) (Vqbi v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQBC_ASBU) (Vqbc v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQHU_ASBU) (Vqhu v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQHI_ASBU) (Vqhi v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQHF_ASBU) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQBU_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQBU_TYPE){v.V0});
#endif
}
INLINE(Vqbu,VQWU_ASBU) (Vqwu v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQWI_ASBU) (Vqwi v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQWF_ASBU) (Vqwf v) {return (VQBU_TYPE){_mm_castps_si128(v)};}
INLINE(Vqbu,VQDU_ASBU) (Vqdu v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQDI_ASBU) (Vqdi v) {return (VQBU_TYPE){v.V0};}
INLINE(Vqbu,VQDF_ASBU) (Vqdf v) {return (VQBU_TYPE){_mm_castpd_si128(v)};}


#if 0 // _LEAVE_X86_ASBU
}
#endif

#if 0 // _ENTER_X86_ASBI
{
#endif

INLINE(Vwbi,VWYU_ASBI) (Vwyu v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWBU_ASBI) (Vwbu v) {return (VWBI_TYPE){v.V0};}

INLINE(Vwbi,VWBC_ASBI) (Vwbc v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWHU_ASBI) (Vwhu v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWHI_ASBI) (Vwhi v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWHF_ASBI) (Vwhf v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWWU_ASBI) (Vwwu v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWWI_ASBI) (Vwwi v) {return (VWBI_TYPE){v.V0};}
INLINE(Vwbi,VWWF_ASBI) (Vwwf v) {return (VWBI_TYPE){v.V0};}

INLINE(Vdbi,VDYU_ASBI) (Vdyu v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDBU_ASBI) (Vdbu v) {return (VDBI_TYPE){v.V0};}

INLINE(Vdbi,VDBC_ASBI) (Vdbc v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDHU_ASBI) (Vdhu v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDHI_ASBI) (Vdhi v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDHF_ASBI) (Vdhf v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDWU_ASBI) (Vdwu v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDWI_ASBI) (Vdwi v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDWF_ASBI) (Vdwf v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDDU_ASBI) (Vddu v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDDI_ASBI) (Vddi v) {return (VDBI_TYPE){v.V0};}
INLINE(Vdbi,VDDF_ASBI) (Vddf v) {return (VDBI_TYPE){v.V0};}

INLINE(Vqbi,VQYU_ASBI) (Vqyu v) {return (VQBI_TYPE){v};}
INLINE(Vqbi,VQBU_ASBI) (Vqbu v) {return (VQBI_TYPE){v.V0};}

INLINE(Vqbi,VQBC_ASBI) (Vqbc v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQHU_ASBI) (Vqhu v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQHI_ASBI) (Vqhi v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQHF_ASBI) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQBI_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQBI_TYPE){v.V0});
#endif
}
INLINE(Vqbi,VQWU_ASBI) (Vqwu v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQWI_ASBI) (Vqwi v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQWF_ASBI) (Vqwf v) {return (VQBI_TYPE){_mm_castps_si128(v)};}
INLINE(Vqbi,VQDU_ASBI) (Vqdu v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQDI_ASBI) (Vqdi v) {return (VQBI_TYPE){v.V0};}
INLINE(Vqbi,VQDF_ASBI) (Vqdf v) {return (VQBI_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASBI
}
#endif

#if 0 // _ENTER_X86_ASBC
{
#endif

INLINE(Vwbc,VWYU_ASBC) (Vwyu v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWBU_ASBC) (Vwbu v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWBI_ASBC) (Vwbi v) {return (VWBC_TYPE){v.V0};}

INLINE(Vwbc,VWHU_ASBC) (Vwhu v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWHI_ASBC) (Vwhi v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWHF_ASBC) (Vwhf v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWWU_ASBC) (Vwwu v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWWI_ASBC) (Vwwi v) {return (VWBC_TYPE){v.V0};}
INLINE(Vwbc,VWWF_ASBC) (Vwwf v) {return (VWBC_TYPE){v.V0};}

INLINE(Vdbc,VDYU_ASBC) (Vdyu v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDBU_ASBC) (Vdbu v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDBI_ASBC) (Vdbi v) {return (VDBC_TYPE){v.V0};}

INLINE(Vdbc,VDHU_ASBC) (Vdhu v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDHI_ASBC) (Vdhi v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDHF_ASBC) (Vdhf v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDWU_ASBC) (Vdwu v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDWI_ASBC) (Vdwi v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDWF_ASBC) (Vdwf v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDDU_ASBC) (Vddu v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDDI_ASBC) (Vddi v) {return (VDBC_TYPE){v.V0};}
INLINE(Vdbc,VDDF_ASBC) (Vddf v) {return (VDBC_TYPE){v.V0};}

INLINE(Vqbc,VQYU_ASBC) (Vqyu v) {return (VQBC_TYPE){v};}
INLINE(Vqbc,VQBU_ASBC) (Vqbu v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQBI_ASBC) (Vqbi v) {return (VQBC_TYPE){v.V0};}

INLINE(Vqbc,VQHU_ASBC) (Vqhu v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQHI_ASBC) (Vqhi v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQHF_ASBC) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQBC_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQBC_TYPE){v.V0});
#endif
}
INLINE(Vqbc,VQWU_ASBC) (Vqwu v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQWI_ASBC) (Vqwi v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQWF_ASBC) (Vqwf v) {return (VQBC_TYPE){_mm_castps_si128(v)};}
INLINE(Vqbc,VQDU_ASBC) (Vqdu v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQDI_ASBC) (Vqdi v) {return (VQBC_TYPE){v.V0};}
INLINE(Vqbc,VQDF_ASBC) (Vqdf v) {return (VQBC_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASBC
}
#endif

#if 0 // _ENTER_X86_ASHU
{
#endif

INLINE(Vwhu,VWYU_ASHU) (Vwyu v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWBU_ASHU) (Vwbu v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWBI_ASHU) (Vwbi v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWBC_ASHU) (Vwbc v) {return (VWHU_TYPE){v.V0};}

INLINE(Vwhu,VWHI_ASHU) (Vwhi v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWHF_ASHU) (Vwhf v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWWU_ASHU) (Vwwu v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWWI_ASHU) (Vwwi v) {return (VWHU_TYPE){v.V0};}
INLINE(Vwhu,VWWF_ASHU) (Vwwf v) {return (VWHU_TYPE){v.V0};}

INLINE(Vdhu,VDYU_ASHU) (Vdyu v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDBU_ASHU) (Vdbu v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDBI_ASHU) (Vdbi v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDBC_ASHU) (Vdbc v) {return (VDHU_TYPE){v.V0};}

INLINE(Vdhu,VDHI_ASHU) (Vdhi v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDHF_ASHU) (Vdhf v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDWU_ASHU) (Vdwu v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDWI_ASHU) (Vdwi v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDWF_ASHU) (Vdwf v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDDU_ASHU) (Vddu v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDDI_ASHU) (Vddi v) {return (VDHU_TYPE){v.V0};}
INLINE(Vdhu,VDDF_ASHU) (Vddf v) {return (VDHU_TYPE){v.V0};}

INLINE(Vqhu,VQYU_ASHU) (Vqyu v) {return (VQHU_TYPE){v};}
INLINE(Vqhu,VQBU_ASHU) (Vqbu v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQBI_ASHU) (Vqbi v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQBC_ASHU) (Vqbc v) {return (VQHU_TYPE){v.V0};}

INLINE(Vqhu,VQHI_ASHU) (Vqhi v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQHF_ASHU) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQHU_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQHU_TYPE){v.V0});
#endif
}
INLINE(Vqhu,VQWU_ASHU) (Vqwu v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQWI_ASHU) (Vqwi v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQWF_ASHU) (Vqwf v) {return (VQHU_TYPE){_mm_castps_si128(v)};}
INLINE(Vqhu,VQDU_ASHU) (Vqdu v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQDI_ASHU) (Vqdi v) {return (VQHU_TYPE){v.V0};}
INLINE(Vqhu,VQDF_ASHU) (Vqdf v) {return (VQHU_TYPE){_mm_castpd_si128(v)};}


#if 0 // _LEAVE_X86_ASHU
}
#endif

#if 0 // _ENTER_X86_ASHI
{
#endif

INLINE(Vwhi,VWYU_ASHI) (Vwyu v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWBU_ASHI) (Vwbu v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWBI_ASHI) (Vwbi v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWBC_ASHI) (Vwbc v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWHU_ASHI) (Vwhu v) {return (VWHI_TYPE){v.V0};}

INLINE(Vwhi,VWHF_ASHI) (Vwhf v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWWU_ASHI) (Vwwu v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWWI_ASHI) (Vwwi v) {return (VWHI_TYPE){v.V0};}
INLINE(Vwhi,VWWF_ASHI) (Vwwf v) {return (VWHI_TYPE){v.V0};}

INLINE(Vdhi,VDYU_ASHI) (Vdyu v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDBU_ASHI) (Vdbu v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDBI_ASHI) (Vdbi v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDBC_ASHI) (Vdbc v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDHU_ASHI) (Vdhu v) {return (VDHI_TYPE){v.V0};}

INLINE(Vdhi,VDHF_ASHI) (Vdhf v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDWU_ASHI) (Vdwu v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDWI_ASHI) (Vdwi v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDWF_ASHI) (Vdwf v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDDU_ASHI) (Vddu v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDDI_ASHI) (Vddi v) {return (VDHI_TYPE){v.V0};}
INLINE(Vdhi,VDDF_ASHI) (Vddf v) {return (VDHI_TYPE){v.V0};}

INLINE(Vqhi,VQYU_ASHI) (Vqyu v) {return (VQHI_TYPE){v};}
INLINE(Vqhi,VQBU_ASHI) (Vqbu v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQBI_ASHI) (Vqbi v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQBC_ASHI) (Vqbc v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQHU_ASHI) (Vqhu v) {return (VQHI_TYPE){v.V0};}

INLINE(Vqhi,VQHF_ASHI) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQHI_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQHI_TYPE){v.V0});
#endif
}
INLINE(Vqhi,VQWU_ASHI) (Vqwu v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQWI_ASHI) (Vqwi v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQWF_ASHI) (Vqwf v) {return (VQHI_TYPE){_mm_castps_si128(v)};}
INLINE(Vqhi,VQDU_ASHI) (Vqdu v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQDI_ASHI) (Vqdi v) {return (VQHI_TYPE){v.V0};}
INLINE(Vqhi,VQDF_ASHI) (Vqdf v) {return (VQHI_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASHI
}
#endif

#if 0 // _ENTER_X86_ASHF
{
#endif

INLINE(Vwhf,VWYU_ASHF) (Vwyu v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWBU_ASHF) (Vwbu v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWBI_ASHF) (Vwbi v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWBC_ASHF) (Vwbc v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWHU_ASHF) (Vwhu v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWHI_ASHF) (Vwhi v) {return (VWHF_TYPE){v.V0};}

INLINE(Vwhf,VWWU_ASHF) (Vwwu v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWWI_ASHF) (Vwwi v) {return (VWHF_TYPE){v.V0};}
INLINE(Vwhf,VWWF_ASHF) (Vwwf v) {return (VWHF_TYPE){v.V0};}

INLINE(Vdhf,VDYU_ASHF) (Vdyu v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDBU_ASHF) (Vdbu v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDBI_ASHF) (Vdbi v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDBC_ASHF) (Vdbc v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDHU_ASHF) (Vdhu v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDHI_ASHF) (Vdhi v) {return (VDHF_TYPE){v.V0};}

INLINE(Vdhf,VDWU_ASHF) (Vdwu v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDWI_ASHF) (Vdwi v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDWF_ASHF) (Vdwf v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDDU_ASHF) (Vddu v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDDI_ASHF) (Vddi v) {return (VDHF_TYPE){v.V0};}
INLINE(Vdhf,VDDF_ASHF) (Vddf v) {return (VDHF_TYPE){v.V0};}

#if defined(SPC_X86_FP16)

INLINE(Vqhf,VQYU_ASHF) (Vqyu v) {return _mm_castsi128_ph(v);}
INLINE(Vqhf,VQBU_ASHF) (Vqbu v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQBI_ASHF) (Vqbi v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQBC_ASHF) (Vqbc v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQHU_ASHF) (Vqhu v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQHI_ASHF) (Vqhi v) {return _mm_castsi128_ph(v.V0);}

INLINE(Vqhf,VQWU_ASHF) (Vqwu v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQWI_ASHF) (Vqwi v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQWF_ASHF) (Vqwf v) {return _mm_castps_ph(v);}
INLINE(Vqhf,VQDU_ASHF) (Vqdu v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQDI_ASHF) (Vqdi v) {return _mm_castsi128_ph(v.V0);}
INLINE(Vqhf,VQDF_ASHF) (Vqdf v) {return _mm_castpd_ph(v);}

#else

INLINE(Vqhf,VQYU_ASHF) (Vqyu v) {return (VQHF_TYPE){v};}
INLINE(Vqhf,VQBU_ASHF) (Vqbu v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQBI_ASHF) (Vqbi v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQBC_ASHF) (Vqbc v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQHU_ASHF) (Vqhu v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQHI_ASHF) (Vqhi v) {return (VQHF_TYPE){v.V0};}

INLINE(Vqhf,VQWU_ASHF) (Vqwu v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQWI_ASHF) (Vqwi v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQWF_ASHF) (Vqwf v) {return (VQHF_TYPE){_mm_castps_si128(v)};}
INLINE(Vqhf,VQDU_ASHF) (Vqdu v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQDI_ASHF) (Vqdi v) {return (VQHF_TYPE){v.V0};}
INLINE(Vqhf,VQDF_ASHF) (Vqdf v) {return (VQHF_TYPE){_mm_castpd_si128(v)};}

#endif

#if 0 // _LEAVE_X86_ASHF
}
#endif

#if 0 // _ENTER_X86_ASWU
{
#endif

INLINE(Vwwu,VWYU_ASWU) (Vwyu v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWBU_ASWU) (Vwbu v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWBI_ASWU) (Vwbi v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWBC_ASWU) (Vwbc v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWHU_ASWU) (Vwhu v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWHI_ASWU) (Vwhi v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWHF_ASWU) (Vwhf v) {return (VWWU_TYPE){v.V0};}

INLINE(Vwwu,VWWI_ASWU) (Vwwi v) {return (VWWU_TYPE){v.V0};}
INLINE(Vwwu,VWWF_ASWU) (Vwwf v) {return (VWWU_TYPE){v.V0};}

INLINE(Vdwu,VDYU_ASWU) (Vdyu v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDBU_ASWU) (Vdbu v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDBI_ASWU) (Vdbi v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDBC_ASWU) (Vdbc v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDHU_ASWU) (Vdhu v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDHI_ASWU) (Vdhi v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDHF_ASWU) (Vdhf v) {return (VDWU_TYPE){v.V0};}

INLINE(Vdwu,VDWI_ASWU) (Vdwi v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDWF_ASWU) (Vdwf v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDDU_ASWU) (Vddu v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDDI_ASWU) (Vddi v) {return (VDWU_TYPE){v.V0};}
INLINE(Vdwu,VDDF_ASWU) (Vddf v) {return (VDWU_TYPE){v.V0};}

INLINE(Vqwu,VQYU_ASWU) (Vqyu v) {return (VQWU_TYPE){v};}
INLINE(Vqwu,VQBU_ASWU) (Vqbu v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQBI_ASWU) (Vqbi v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQBC_ASWU) (Vqbc v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQHU_ASWU) (Vqhu v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQHI_ASWU) (Vqhi v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQHF_ASWU) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQWU_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQWU_TYPE){v.V0});
#endif
}

INLINE(Vqwu,VQWI_ASWU) (Vqwi v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQWF_ASWU) (Vqwf v) {return (VQWU_TYPE){_mm_castps_si128(v)};}
INLINE(Vqwu,VQDU_ASWU) (Vqdu v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQDI_ASWU) (Vqdi v) {return (VQWU_TYPE){v.V0};}
INLINE(Vqwu,VQDF_ASWU) (Vqdf v) {return (VQWU_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASWU
}
#endif

#if 0 // _ENTER_X86_ASWI
{
#endif

INLINE(Vwwi,VWYU_ASWI) (Vwyu v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWBU_ASWI) (Vwbu v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWBI_ASWI) (Vwbi v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWBC_ASWI) (Vwbc v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWHU_ASWI) (Vwhu v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWHI_ASWI) (Vwhi v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWHF_ASWI) (Vwhf v) {return (VWWI_TYPE){v.V0};}
INLINE(Vwwi,VWWU_ASWI) (Vwwu v) {return (VWWI_TYPE){v.V0};}

INLINE(Vwwi,VWWF_ASWI) (Vwwf v) {return (VWWI_TYPE){v.V0};}

INLINE(Vdwi,VDYU_ASWI) (Vdyu v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDBU_ASWI) (Vdbu v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDBI_ASWI) (Vdbi v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDBC_ASWI) (Vdbc v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDHU_ASWI) (Vdhu v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDHI_ASWI) (Vdhi v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDHF_ASWI) (Vdhf v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDWU_ASWI) (Vdwu v) {return (VDWI_TYPE){v.V0};}

INLINE(Vdwi,VDWF_ASWI) (Vdwf v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDDU_ASWI) (Vddu v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDDI_ASWI) (Vddi v) {return (VDWI_TYPE){v.V0};}
INLINE(Vdwi,VDDF_ASWI) (Vddf v) {return (VDWI_TYPE){v.V0};}

INLINE(Vqwi,VQYU_ASWI) (Vqyu v) {return (VQWI_TYPE){v};}
INLINE(Vqwi,VQBU_ASWI) (Vqbu v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQBI_ASWI) (Vqbi v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQBC_ASWI) (Vqbc v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQHU_ASWI) (Vqhu v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQHI_ASWI) (Vqhi v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQHF_ASWI) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQWI_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQWI_TYPE){v.V0});
#endif
}
INLINE(Vqwi,VQWU_ASWI) (Vqwu v) {return (VQWI_TYPE){v.V0};}

INLINE(Vqwi,VQWF_ASWI) (Vqwf v) {return (VQWI_TYPE){_mm_castps_si128(v)};}
INLINE(Vqwi,VQDU_ASWI) (Vqdu v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQDI_ASWI) (Vqdi v) {return (VQWI_TYPE){v.V0};}
INLINE(Vqwi,VQDF_ASWI) (Vqdf v) {return (VQWI_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASWI
}
#endif

#if 0 // _ENTER_X86_ASWF
{
#endif

INLINE(Vwwf,VWYU_ASWF) (Vwyu v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWBU_ASWF) (Vwbu v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWBI_ASWF) (Vwbi v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWBC_ASWF) (Vwbc v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWHU_ASWF) (Vwhu v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWHI_ASWF) (Vwhi v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWHF_ASWF) (Vwhf v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWWU_ASWF) (Vwwu v) {return (VWWF_TYPE){v.V0};}
INLINE(Vwwf,VWWI_ASWF) (Vwwi v) {return (VWWF_TYPE){v.V0};}


INLINE(Vdwf,VDYU_ASWF) (Vdyu v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDBU_ASWF) (Vdbu v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDBI_ASWF) (Vdbi v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDBC_ASWF) (Vdbc v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDHU_ASWF) (Vdhu v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDHI_ASWF) (Vdhi v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDHF_ASWF) (Vdhf v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDWU_ASWF) (Vdwu v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDWI_ASWF) (Vdwi v) {return (VDWF_TYPE){v.V0};}

INLINE(Vdwf,VDDU_ASWF) (Vddu v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDDI_ASWF) (Vddi v) {return (VDWF_TYPE){v.V0};}
INLINE(Vdwf,VDDF_ASWF) (Vddf v) {return (VDWF_TYPE){v.V0};}

INLINE(Vqwf,VQYU_ASWF) (Vqyu v) {return _mm_castsi128_ps(v);}
INLINE(Vqwf,VQBU_ASWF) (Vqbu v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQBI_ASWF) (Vqbi v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQBC_ASWF) (Vqbc v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQHU_ASWF) (Vqhu v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQHI_ASWF) (Vqhi v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQHF_ASWF) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  _mm_castph_ps(v);
#else
    return  _mm_castsi128_ps(v.V0);
#endif
}

INLINE(Vqwf,VQWU_ASWF) (Vqwu v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQWI_ASWF) (Vqwi v) {return _mm_castsi128_ps(v.V0);}

INLINE(Vqwf,VQDU_ASWF) (Vqdu v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQDI_ASWF) (Vqdi v) {return _mm_castsi128_ps(v.V0);}
INLINE(Vqwf,VQDF_ASWF) (Vqdf v) {return _mm_castpd_ps(v);}

#if 0 // _LEAVE_X86_ASWF
}
#endif

#if 0 // _ENTER_X86_ASDU
{
#endif

INLINE(Vddu,VDYU_ASDU) (Vdyu v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDBU_ASDU) (Vdbu v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDBI_ASDU) (Vdbi v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDBC_ASDU) (Vdbc v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDHU_ASDU) (Vdhu v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDHI_ASDU) (Vdhi v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDHF_ASDU) (Vdhf v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDWU_ASDU) (Vdwu v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDWI_ASDU) (Vdwi v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDWF_ASDU) (Vdwf v) {return (VDDU_TYPE){v.V0};}

INLINE(Vddu,VDDI_ASDU) (Vddi v) {return (VDDU_TYPE){v.V0};}
INLINE(Vddu,VDDF_ASDU) (Vddf v) {return (VDDU_TYPE){v.V0};}

INLINE(Vqdu,VQYU_ASDU) (Vqyu v) {return (VQDU_TYPE){v};}
INLINE(Vqdu,VQBU_ASDU) (Vqbu v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQBI_ASDU) (Vqbi v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQBC_ASDU) (Vqbc v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQHU_ASDU) (Vqhu v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQHI_ASDU) (Vqhi v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQHF_ASDU) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQDU_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQDU_TYPE){v.V0});
#endif
}
INLINE(Vqdu,VQWU_ASDU) (Vqwu v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQWI_ASDU) (Vqwi v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQWF_ASDU) (Vqwf v) {return (VQDU_TYPE){_mm_castps_si128(v)};}

INLINE(Vqdu,VQDI_ASDU) (Vqdi v) {return (VQDU_TYPE){v.V0};}
INLINE(Vqdu,VQDF_ASDU) (Vqdf v) {return (VQDU_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASDU
}
#endif

#if 0 // _ENTER_X86_ASDI
{
#endif

INLINE(Vddi,VDYU_ASDI) (Vdyu v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDBU_ASDI) (Vdbu v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDBI_ASDI) (Vdbi v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDBC_ASDI) (Vdbc v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDHU_ASDI) (Vdhu v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDHI_ASDI) (Vdhi v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDHF_ASDI) (Vdhf v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDWU_ASDI) (Vdwu v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDWI_ASDI) (Vdwi v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDWF_ASDI) (Vdwf v) {return (VDDI_TYPE){v.V0};}
INLINE(Vddi,VDDU_ASDI) (Vddu v) {return (VDDI_TYPE){v.V0};}

INLINE(Vddi,VDDF_ASDI) (Vddf v) {return (VDDI_TYPE){v.V0};}

INLINE(Vqdi,VQYU_ASDI) (Vqyu v) {return (VQDI_TYPE){v};}
INLINE(Vqdi,VQBU_ASDI) (Vqbu v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQBI_ASDI) (Vqbi v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQBC_ASDI) (Vqbc v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQHU_ASDI) (Vqhu v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQHI_ASDI) (Vqhi v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQHF_ASDI) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  ((VQDI_TYPE){_mm_castph_si128(v)});
#else
    return  ((VQDI_TYPE){v.V0});
#endif
}
INLINE(Vqdi,VQWU_ASDI) (Vqwu v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQWI_ASDI) (Vqwi v) {return (VQDI_TYPE){v.V0};}
INLINE(Vqdi,VQWF_ASDI) (Vqwf v) {return (VQDI_TYPE){_mm_castps_si128(v)};}
INLINE(Vqdi,VQDU_ASDI) (Vqdu v) {return (VQDI_TYPE){v.V0};}

INLINE(Vqdi,VQDF_ASDI) (Vqdf v) {return (VQDI_TYPE){_mm_castpd_si128(v)};}

#if 0 // _LEAVE_X86_ASDI
}
#endif

#if 0 // _ENTER_X86_ASDF
{
#endif

INLINE(Vddf,VDYU_ASDF) (Vdyu v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDBU_ASDF) (Vdbu v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDBI_ASDF) (Vdbi v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDBC_ASDF) (Vdbc v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDHU_ASDF) (Vdhu v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDHI_ASDF) (Vdhi v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDHF_ASDF) (Vdhf v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDWU_ASDF) (Vdwu v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDWI_ASDF) (Vdwi v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDWF_ASDF) (Vdwf v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDDU_ASDF) (Vddu v) {return (VDDF_TYPE){v.V0};}
INLINE(Vddf,VDDI_ASDF) (Vddi v) {return (VDDF_TYPE){v.V0};}

INLINE(Vqdf,VQYU_ASDF) (Vqyu v) {return _mm_castsi128_pd(v);}
INLINE(Vqdf,VQBU_ASDF) (Vqbu v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQBI_ASDF) (Vqbi v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQBC_ASDF) (Vqbc v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQHU_ASDF) (Vqhu v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQHI_ASDF) (Vqhi v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQHF_ASDF) (Vqhf v) 
{
#if defined(SPC_X86_FP16)
    return  _mm_castph_pd(v);
#else
    return  _mm_castsi128_pd(v.V0);
#endif
}

INLINE(Vqdf,VQWU_ASDF) (Vqwu v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQWI_ASDF) (Vqwi v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQWF_ASDF) (Vqwf v) {return _mm_castps_pd(v);}
INLINE(Vqdf,VQDU_ASDF) (Vqdu v) {return _mm_castsi128_pd(v.V0);}
INLINE(Vqdf,VQDI_ASDF) (Vqdi v) {return _mm_castsi128_pd(v.V0);}

#if 0 // _LEAVE_X86_ASDF
}
#endif

#if 0 // _ENTER_X86_MVWL
{
#endif

INLINE(Vwyu,  BOOL_MVWL)     (_Bool x) 
{
#define     BOOL_MVWL(X)   ((Vwyu){ ((WORD_TYPE){.Y0=X}).F })
    return  BOOL_MVWL(x);
}


INLINE(Vwbu, UCHAR_MVWL)  (unsigned x) 
{
#define     UCHAR_MVWL(X)   ((Vwbu){((WORD_TYPE){.B0.U=X}).F})
    return  UCHAR_MVWL(x);
}

INLINE(Vwbi, SCHAR_MVWL)    (signed x) 
{
#define     SCHAR_MVWL(X)   ((Vwbi){((WORD_TYPE){.B0.I=X}).F})
    return  SCHAR_MVWL(x);
}

INLINE(Vwbc,  CHAR_MVWL)       (int x) 
{
#define     CHAR_MVWL(X)    ((Vwbc){((WORD_TYPE){.C0=X}).F})
    return  CHAR_MVWL(x);
}


INLINE(Vwhu, USHRT_MVWL)  (unsigned x) 
{
#define     USHRT_MVWL(X)   ((Vwhu){((WORD_TYPE){.H0.U=X}).F})
    return  USHRT_MVWL(x);
}

INLINE(Vwhi,  SHRT_MVWL)    (signed x) 
{
#define     SHRT_MVWL(X)    ((Vwhi){((WORD_TYPE){.H0.I=X}).F})
    return  SHRT_MVWL(x);
}


INLINE(Vwwu,  UINT_MVWL)      (uint x) 
{
#define     UINT_MVWL(X)    ((Vwwu){((WORD_TYPE){.U=X}).F})
    return  UINT_MVWL(x);
}

INLINE(Vwwi,   INT_MVWL)       (int x) 
{
#define     INT_MVWL(X)     ((Vwwi){ ((WORD_TYPE){.I=X}).F})
    return  INT_MVWL(x);
}

#if DWRD_NLONG == 2

INLINE(Vwwu, ULONG_MVWL)     (ulong x) 
{
#define     ULONG_MVWL(X)   ((Vwwu){((WORD_TYPE){.U=X}).F})
    return  ULONG_MVWL(x);
}

INLINE(Vwwi,  LONG_MVWL)      (long x) 
{
#define     LONG_MVWL(X)    ((Vwwi){((WORD_TYPE){.I=X}).F})
    return  LONG_MVWL(x);
}

#endif

INLINE(Vwhf,FLT16_MVWL)    (flt16_t x) 
{
#define     FLT16_MVWL(X)   ((Vwhf){((WORD_TYPE){.H0.F=X}).F})
    return  FLT16_MVWL(x);
}

INLINE(Vwwf,  FLT_MVWL)      (float x) 
{
#define     FLT_MVWL(X)     ((Vwwf){X})
    return  FLT_MVWL(x);
}

INLINE(   _Bool,VWYU_MVWL) (Vwyu x) 
{
#define     VWYU_MVWL(X) (((WORD_TYPE){.F=X.V0}).Y0)
    return  VWYU_MVWL(x);
}


INLINE( uint8_t,VWBU_MVWL) (Vwbu x) 
{
#define     VWBU_MVWL(X) (((WORD_TYPE){.F=X.V0}).B0.U)
    return  VWBU_MVWL(x);
}

INLINE(  int8_t,VWBI_MVWL) (Vwbi x) 
{
#define     VWBI_MVWL(X) (((WORD_TYPE){.F=X.V0}).B0.I)
    return  VWBI_MVWL(x);
}

INLINE(    char,VWBC_MVWL) (Vwbc x) 
{
#define     VWBC_MVWL(X) (((WORD_TYPE){.F=X.V0}).C0)
    return  VWBC_MVWL(x);
}


INLINE(uint16_t,VWHU_MVWL) (Vwhu x) 
{
#define     VWHU_MVWL(X) (((WORD_TYPE){.F=X.V0}).H0.U)
    return  VWHU_MVWL(x);
}

INLINE( int16_t,VWHI_MVWL) (Vwhi x) 
{
#define     VWHI_MVWL(X) (((WORD_TYPE){.F=X.V0}).H0.I)
    return  VWHI_MVWL(x);
}

INLINE( flt16_t,VWHF_MVWL) (Vwhf x) 
{
#define     VWHF_MVWL(X) (((WORD_TYPE){.F=X.V0}).H0.F)
    return  VWHF_MVWL(x);
}


INLINE(uint32_t,VWWU_MVWL) (Vwwu x) 
{
#define     VWWU_MVWL(X) (((WORD_TYPE){.F=X.V0}).U)
    return  VWWU_MVWL(x);
}

INLINE( int32_t,VWWI_MVWL) (Vwwi x)
{
#define     VWWI_MVWL(X) (((WORD_TYPE){.F=X.V0}).I)
    return  VWWI_MVWL(x);
}

INLINE(   float,VWWF_MVWL) (Vwwf x) 
{
#define     VWWF_MVWL(X) (X.V0)
    return  VWWF_MVWL(x);
}


#if 0 // _LEAVE_X86_MVWL
}
#endif

#if 0 // _ENTER_X86_MVDL
{
#endif

INLINE(Vdyu,  BOOL_MVDL)  (_Bool x) 
{
#define     BOOL_MVDL(X) ((VDYU_TYPE){ ((DWRD_TYPE){.I=X?-1:0}).F })
    return  BOOL_MVDL(x);
}


INLINE(Vdbu, UCHAR_MVDL)  (unsigned x) 
{
#define     UCHAR_MVDL(X)   ((Vdbu){ ((DWRD_TYPE){.B0.U=X}).F })
    return  UCHAR_MVDL(x);
}

INLINE(Vdbi, SCHAR_MVDL)  (signed x) 
{
#define     SCHAR_MVDL(X)   ((Vdbi){ ((DWRD_TYPE){.B0.I=X}).F })
    return  SCHAR_MVDL(x);
}

INLINE(Vdbc,  CHAR_MVDL)   (int x) 
{
#define     CHAR_MVDL(X)    ((Vdbc){ ((DWRD_TYPE){.C0=X}).F })
    return  CHAR_MVDL(x);
}


INLINE(Vdhu, USHRT_MVDL) (unsigned x) 
{
#define     USHRT_MVDL(X)   ((Vdhu){ ((DWRD_TYPE){.H0.U=X}).F })
    return  USHRT_MVDL(x);
}

INLINE(Vdhi,  SHRT_MVDL)  (signed x) 
{
#define     SHRT_MVDL(X)    ((Vdhi){ ((DWRD_TYPE){.H0.I=X}).F })
    return  SHRT_MVDL(x);
}


INLINE(Vdwu,  UINT_MVDL)   (uint x) 
{
#define     UINT_MVDL(X)    ((Vdwu){ ((DWRD_TYPE){.W0.U=X}).F })
    return  UINT_MVDL(x);
}

INLINE(Vdwi,   INT_MVDL)    (int x) 
{
#define     INT_MVDL(X)     ((Vdwi){ ((DWRD_TYPE){.W0.I=X}).F })
    return  INT_MVDL(x);
}


#if DWRD_NLONG == 2
INLINE(Vdwu, ULONG_MVDL)  (ulong x) 
{
#define     ULONG_MVDL(X)   ((Vdwu){ ((DWRD_TYPE){.W0.U=X}).F })
    return  ULONG_MVDL(x);
}

INLINE(Vdwi,  LONG_MVDL)   (long x) 
{
#define     LONG_MVDL(X)    ((Vdwi){ ((DWRD_TYPE){.W0.I=X}).F })
    return  LONG_MVDL(x);
}

#else

INLINE(Vddu, ULONG_MVDL)  (ulong x) 
{
#define     ULONG_MVDL(X)   ((Vddu){ ((DWRD_TYPE){   .U=X}).F })
    return  ULONG_MVDL(x);
}

INLINE(Vddi,  LONG_MVDL)   (long x) 
{
#define     LONG_MVDL(X)    ((Vddi){ ((DWRD_TYPE){   .I=X}).F })
    return  LONG_MVDL(x);
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vddu, ULLONG_MVDL)  (ullong x) 
{
#define     ULLONG_MVDL(X)   ((Vddu){ ((DWRD_TYPE){   .U=X}).F })
    return  ULLONG_MVDL(x);
}

INLINE(Vdwi,  LLONG_MVDL)   (long x) 
{
#define     LLONG_MVDL(X)    ((Vddi){ ((DWRD_TYPE){   .I=X}).F })
    return  LLONG_MVDL(x);
}

#endif


INLINE(Vdhf, FLT16_MVDL)    (flt16_t x) 
{
#define     FLT_MVDL(X)     ((Vdhf){ ((DWRD_TYPE){.H0.F=X}).F })
    return  FLT_MVDL(x);
}

INLINE(Vdwf,   FLT_MVDL)    (float x) 
{
#define     FLT_MVDL(X)     ((Vdwf){ ((DWRD_TYPE){.W0.F=X}).F })
    return  FLT_MVDL(x);
}

INLINE(Vddf,   DBL_MVDL)    (double x) 
{
#define     DBL_MVDL(X)     ((Vddf){X})
    return  DBL_MVDL(x);
}


INLINE(   _Bool,VDYU_MVDL) (Vdyu x) 
{
#define     VDYU_MVDL(X) (((DWRD_TYPE){.F=X.V0}).Y0)
    return  VDYU_MVDL(x);
}


INLINE( uint8_t,VDBU_MVDL) (Vdbu x) 
{
#define     VDBU_MVDL(X) (((DWRD_TYPE){.F=X.V0}).B0.U)
    return  VDBU_MVDL(x);
}

INLINE(  int8_t,VDBI_MVDL) (Vdbi x) 
{
#define     VDBI_MVDL(X) (((DWRD_TYPE){.F=X.V0}).B0.I)
    return  VDBI_MVDL(x);
}

INLINE(    char,VDBC_MVDL) (Vdbc x) 
{
#define     VDBC_MVDL(X) (((DWRD_TYPE){.F=X.V0}).C0)
    return  VDBC_MVDL(x);
}


INLINE(uint16_t,VDHU_MVDL) (Vdhu x) 
{
#define     VDHU_MVDL(X) (((DWRD_TYPE){.F=X.V0}).H0.U)
    return  VDHU_MVDL(x);
}

INLINE( int16_t,VDHI_MVDL) (Vdhi x) 
{
#define     VDHI_MVDL(X) (((DWRD_TYPE){.F=X.V0}).H0.I)
    return  VDHI_MVDL(x);
}

INLINE( flt16_t,VDHF_MVDL) (Vdhf x) 
{
#define     VDHF_MVDL(X) (((DWRD_TYPE){.F=X.V0}).H0.F)
    return  VDHF_MVDL(x);
}


INLINE(uint32_t,VDWU_MVDL) (Vdwu x) 
{
#define     VDWU_MVDL(X) (((DWRD_TYPE){.F=X.V0}).W0.U)
    return  VDWU_MVDL(x);
}

INLINE( int32_t,VDWI_MVDL) (Vdwi x)
{
#define     VDWI_MVDL(X) (((DWRD_TYPE){.F=X.V0}).W0.I)
    return  VDWI_MVDL(x);
}

INLINE(   float,VDWF_MVDL) (Vdwf x) 
{
#define     VDWF_MVDL(X) (((DWRD_TYPE){.F=X.V0}).W0.F)
    return  VDWF_MVDL(x);
}


INLINE(uint64_t,VDDU_MVDL) (Vddu x) 
{
#define     VDDU_MVDL(X) (((DWRD_TYPE){.F=X.V0}).U)
    return  VDDU_MVDL(x);
}


INLINE( int64_t,VDDI_MVDL) (Vddi x) 
{
#define     VDDI_MVDL(X) (((DWRD_TYPE){.F=X.V0}).I)
    return  VDDI_MVDL(x);
}

INLINE(  double,VDDF_MVDL) (Vddf x) 
{
#define     VDDF_MVDL(X) (X.V0)
    return  VDDF_MVDL(x);
}

#if 0 // _LEAVE_X86_MVDL
}
#endif

#if 0 // _ENTER_X86_MVQL
{
#endif

#define     mvqlbz(X) _mm_cvtsi32_si128((UINT8_MAX&X))
#define     mvqlhz(X) _mm_cvtsi32_si128((UINT16_MAX&X))
#define     mvqlwz(X) _mm_cvtsi32_si128((UINT32_MAX&X))
#define     mvqldz(X) _mm_cvtsi64_si128((UINT64_MAX&X))

INLINE(Vqyu,  BOOL_MVQL)  (_Bool x) 
{
#define BOOL_MVQL(X) _mm_cvtsi32_si128((X?1:0))
    return  _mm_cvtsi32_si128(x);
}


INLINE(Vqbu, UCHAR_MVQL)  (unsigned x) 
{
#define     UCHAR_MVQL(X)   ((VQBU_TYPE){mvqlbz(X)})
    return  UCHAR_MVQL(x);
}

INLINE(Vqbi, SCHAR_MVQL)  (signed x) 
{
#define     SCHAR_MVQL(X)   ((VQBI_TYPE){mvqlbz(X)})
    return  SCHAR_MVQL(x);
}

INLINE(Vqbc,  CHAR_MVQL)   (int x) 
{
#define     CHAR_MVQL(X)    ((VQBC_TYPE){mvqlbz(X)})
    return  CHAR_MVQL(x);
}


INLINE(Vqhu, USHRT_MVQL) (unsigned x) 
{
#define     USHRT_MVQL(X)   ((VQHU_TYPE){mvqlhz(X)})
    return  USHRT_MVQL(x);
}

INLINE(Vqhi,  SHRT_MVQL)  (signed x) 
{
#define     SHRT_MVQL(X)    ((VQHI_TYPE){mvqlhz(X)})
    return  SHRT_MVQL(x);
}


INLINE(Vqwu,  UINT_MVQL)   (uint x) 
{
#define     UINT_MVQL(X)    ((VQWU_TYPE){mvqlwz(X)})
    return  UINT_MVQL(x);
}

INLINE(Vqwi,   INT_MVQL)    (int x) 
{
#define     INT_MVQL(X)    ((VQWI_TYPE){mvqlwz(X)})
    return  INT_MVQL(x);
}

#if DWRD_NLONG == 2

INLINE(Vqwu, ULONG_MVQL)  (ulong x) 
{
#define     ULONG_MVQL(X)    ((VQWU_TYPE){mvqlwz(X)})
    return  ULONG_MVQL(x);
}

INLINE(Vqwi,  LONG_MVQL)   (long x) 
{
#define     LONG_MVQL(X)    ((VQWI_TYPE){mvqlwz(X)})
    return  LONG_MVQL(x);
}

#else

INLINE(Vqdu, ULONG_MVQL)  (ulong x) 
{
#define     ULONG_MVQL(X)    ((VQDU_TYPE){mvqldz(X)})
    return  ULONG_MVQL(x);
}

INLINE(Vqdi,  LONG_MVQL)   (long x) 
{
#define     LONG_MVQL(X)    ((VQDI_TYPE){mvqldz(X)})
    return  LONG_MVQL(x);
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vqdu, ULLONG_MVQL)  (ullong x) 
{
#define     ULLONG_MVQL(X)  ((VQDU_TYPE){mvqldz(X)})
    return  ULLONG_MVQL(x);
}

INLINE(Vqdi,  LLONG_MVQL)   (llong x) 
{
#define     LLONG_MVQL(X)   ((VQDI_TYPE){mvqldz(X)})
    return  LLONG_MVQL(x);
}

#else
// TODO: this

INLINE(Vqqu, ULLONG_MVQL) (ullong x) 
{
    return  ((VQQU_TYPE){_mm_set_epi64x((x>>64), x)});
}

INLINE(Vqqi, LLONG_MVQL) (llong x) 
{
    ullong z = x;
    return  ((VQQI_TYPE){_mm_set_epi64x((z>>64), z)});
}

#endif

INLINE(Vqhf,FLT16_MVQL)  (flt16_t x) 
{
#if defined(SPC_X86_FP16)
#   define  FLT16_MVQL _mm_set_sh
    return  _mm_set_sh(x);
#else
    WORD_TYPE   v = {.H0.F=x};
    __m128i     z = _mm_cvtsi32_si128(v.U);
    return  ((VQHF_TYPE){z});
#endif
}

INLINE(Vqwf,  FLT_MVQL)  (float x) 
{
#define     FLT_MVQL    _mm_set_ss
    return  FLT_MVQL(x);
}

INLINE(Vqdf,  DBL_MVQL)  (double x) 
{
#define     DBL_MVQL    _mm_set_sd
    return  DBL_MVQL(x);
}


INLINE(   _Bool,VQYU_MVQL) (Vqyu x) 
{
#define     VQYU_MVQL(X) ((_Bool) (1&_mm_cvtsi128_si32(X)))
    return  VQYU_MVQL(x);
}

INLINE( uint8_t,VQBU_MVQL) (Vqbu x) 
{
#define     VQBU_MVQL(X) ((uint8_t) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}

INLINE(  int8_t,VQBI_MVQL) (Vqbi x) 
{
#define     VQBI_MVQL(X) ((int8_t) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}

INLINE(    char,VQBC_MVQL) (Vqbc x) 
{
#define     VQBC_MVQL(X) ((char) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}


INLINE(uint16_t,VQHU_MVQL) (Vqhu x) 
{
#define     VQHU_MVQL(X) ((uint16_t) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}

INLINE( int16_t,VQHI_MVQL) (Vqhi x) 
{
#define     VQHI_MVQL(X) ((int16_t) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}

INLINE( flt16_t,VQHF_MVQL) (Vqhf x) 
{
#if defined(SPC_X86_FP16)
#   define  VQHF_MVQL _mm_cvtsh_h
    return  _mm_cvtsh_h(x);
#else
    WORD_TYPE   v;
    v.U = _mm_cvtsi128_si32(x.V0);
    return  ((VQHF_TYPE){_mm_cvtsi32_si128(v.H0.U)});
#endif

}


INLINE(uint32_t,VQWU_MVQL) (Vqwu x) 
{
#define     VQWU_MVQL(X) ((uint32_t) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}

INLINE( int32_t,VQWI_MVQL) (Vqwi x)
{
#define     VQWI_MVQL(X) ((int32_t) _mm_cvtsi128_si32(X.V0))
    return  _mm_cvtsi128_si32(x.V0);
}

INLINE(   float,VQWF_MVQL) (Vqwf x) 
{
#define     VQWF_MVQL   _mm_cvtss_f32
    return  VQWF_MVQL(x);
}

INLINE(uint64_t,VQDU_MVQL) (Vqdu x) 
{
#define     VQDU_MVQL(X) ((uint64_t) _mm_cvtsi128_si64(X.V0))
    return  _mm_cvtsi128_si64(x.V0);
}

INLINE( int64_t,VQDI_MVQL) (Vqdi x) 
{
#define     VQDI_MVQL(X) ((int64_t) _mm_cvtsi128_si64(X.V0))
    return  _mm_cvtsi128_si64(x.V0);
}

INLINE(  double,VQDF_MVQL) (Vqdf x) 
{
#define     VQDF_MVQL   _mm_cvtsd_f64
    return  _mm_cvtsd_f64(x);
}

#if 0 // _LEAVE_X86_MVQL
}
#endif


#if 0 // _ENTER_ARM_REVS
{
#endif

#if defined(_MSC_VER)
#   define  MY_REVSHZ _byteswap_ushort
#   define  MY_REVSWZ _byteswap_uint
#   define  MY_REVSDZ _byteswap_uint64
#else
#   define  MY_REVSHZ __builtin_bswap16
#   define  MY_REVSWZ __builtin_bswap32
#   define  MY_REVSDZ __builtin_bswap64
#endif

#if defined(SPC_X86_FP16)

INLINE(_Float16,HBR_REVS) (_Float16 x)
{
    __m128h f = _mm_set_sh(x);
    __m128i z = _mm_castph_si128(f);
    __m128i t = _mm_cvtsi32_si128(0x0001);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ph(z);
    return  _mm_cvtsh_h(f);
}

#endif

INLINE(float,WBR_REVS) (float x)
{
    __m128  f = _mm_set_ss(x);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_cvtsi32_si128(0x00010203);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,WHR_REVS) (float x)
{
    __m128  f = _mm_set_ss(x);
    __m128i z = _mm_castps_si128(f);
    z = _mm_shufflelo_epi16(z, 0b00010001);
    f = _mm_castsi128_ps(z);
    return _mm_cvtss_f32(f);
}


INLINE(double,DBR_REVS) (double x)
{
    __m128d f = _mm_set_sd(x);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_cvtsi64_si128(0x0001020304050607LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

INLINE(double,DHR_REVS) (double x)
{
    __m128d f = _mm_set_sd(x);
    __m128i z = _mm_castpd_si128(f);
    z = _mm_shufflelo_epi16(z, 0b00011011);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

INLINE(double,DWR_REVS) (double x)
{
    __m128d f = _mm_set_sd(x);
    __m128i z = _mm_castpd_si128(f);
    z = _mm_shufflelo_epi16(z, 0b01001110);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}


INLINE(__m128i,QBZ_REVS) (__m128i x)
{
#define     QBZ_REVS(X) \
_mm_shuffle_epi8(       \
    X,                  \
    _mm_set_epi8(       \
        0x0,0x1,0x2,0x3,\
        0x4,0x5,0x6,0x7,\
        0x8,0x9,0xa,0xb,\
        0xc,0xd,0xe,0xf \
    )                   \
)

    return  QBZ_REVS(x);
}

INLINE(__m128i,QHZ_REVS) (__m128i x)
{
#define     QHZ_REVS(X) \
_mm_shuffle_epi8(X,_mm_set_epi8(1,0,3,2,5,4,7,6, 9,8,11,10,13,12,15,14))

    return  QHZ_REVS(x);

}

#if defined(SPC_X86_FP16)

INLINE(__m128h,QHF_REVS) (__m128h x)
{
#define     QHF_REVS(X)             \
_mm_castsi128_ph(                   \
    _mm_shuffle_epi8(               \
        _mm_castph_si128(X),        \
        _mm_set_epi8(               \
            1,0,3,2,5,4,7,6,        \
            9,8,11,10,13,12,15,14   \
        )                           \
    )                               \
)

    return  QHZ_REVS(x);

}

#else

INLINE(__m128i,QHF_REVS) (__m128i x)
{
#define     QHF_REVS(X) \
_mm_shuffle_epi8(X,_mm_set_epi8(1,0,3,2,5,4,7,6, 9,8,11,10,13,12,15,14))

    return  QHF_REVS(x);

}

#endif

INLINE(__m128i,QWZ_REVS) (__m128i x)
{
#define     QWZ_REVS(X) _mm_shuffle_epi32(X,0b00011011)
    return  QWZ_REVS(x);
}

INLINE(__m128i,QDZ_REVS) (__m128i x)
{
#define     QDZ_REVS(X) _mm_shuffle_epi32(X,0b01001110)
    return  QDZ_REVS(x);
}


INLINE(Vwbu,VWBU_REVS) (Vwbu x) {return ((Vwbu){WBR_REVS(x.V0)});}
INLINE(Vwbi,VWBI_REVS) (Vwbi x) {return ((Vwbi){WBR_REVS(x.V0)});}
INLINE(Vwbc,VWBC_REVS) (Vwbc x) {return ((Vwbc){WBR_REVS(x.V0)});}
INLINE(Vwhu,VWHU_REVS) (Vwhu x) {return ((Vwhu){WHR_REVS(x.V0)});}
INLINE(Vwhi,VWHI_REVS) (Vwhi x) {return ((Vwhi){WHR_REVS(x.V0)});}
INLINE(Vwhf,VWHF_REVS) (Vwhf x) {return ((Vwhf){WHR_REVS(x.V0)});}

INLINE(Vdbu,VDBU_REVS) (Vdbu x) {return ((Vdbu){DBR_REVS(x.V0)});}
INLINE(Vdbi,VDBI_REVS) (Vdbi x) {return ((Vdbi){DBR_REVS(x.V0)});}
INLINE(Vdbc,VDBC_REVS) (Vdbc x) {return ((Vdbc){DBR_REVS(x.V0)});}
INLINE(Vdhu,VDHU_REVS) (Vdhu x) {return ((Vdhu){DHR_REVS(x.V0)});}
INLINE(Vdhi,VDHI_REVS) (Vdhi x) {return ((Vdhi){DHR_REVS(x.V0)});}
INLINE(Vdhf,VDHF_REVS) (Vdhf x) {return ((Vdhf){DHR_REVS(x.V0)});}
INLINE(Vdwu,VDWU_REVS) (Vdwu x) {return ((Vdwu){DWR_REVS(x.V0)});}
INLINE(Vdwi,VDWI_REVS) (Vdwi x) {return ((Vdwi){DWR_REVS(x.V0)});}
INLINE(Vdwf,VDWF_REVS) (Vdwf x) {return ((Vdwf){DWR_REVS(x.V0)});}

INLINE(Vqbu,VQBU_REVS) (Vqbu x)
{
#define     VQBU_REVS(X) ((Vqbu){QBZ_REVS(X.V0)})
    return  VQBU_REVS(x);
}

INLINE(Vqbi,VQBI_REVS) (Vqbi x)
{
#define     VQBI_REVS(X) ((Vqbi){QBZ_REVS(X.V0)})
    return  VQBI_REVS(x);
}

INLINE(Vqbc,VQBC_REVS) (Vqbc x)
{
#define     VQBC_REVS(X) ((Vqbc){QBZ_REVS(X.V0)})
    return  VQBC_REVS(x);
}


INLINE(Vqhu,VQHU_REVS) (Vqhu x)
{
#define     VQHU_REVS(X) ((Vqhu){QHZ_REVS(X.V0)})
    return  VQHU_REVS(x);
}

INLINE(Vqhi,VQHI_REVS) (Vqhi x)
{
#define     VQHI_REVS(X) ((Vqhi){QHZ_REVS(X.V0)})
    return  VQHI_REVS(x);
}

INLINE(Vqhf,VQHF_REVS) (Vqhf x)
{
#if defined(SPC_X86_FP16)
#   define  VQHF_REVS(X) _mm_castsi128_ph(QHZ_REVS(_mm_castph_si128(X)))
#else
#   define  VQHF_REVS(X) ((Vqhf){QHZ_REVS(X.V0)})
#endif

    return  VQHF_REVS(x);
}

INLINE(Vqwu,VQWU_REVS) (Vqwu x)
{
#define     VQWU_REVS(X) ((Vqwu){QWZ_REVS(X.V0)})
    return  VQWU_REVS(x);
}

INLINE(Vqwi,VQWI_REVS) (Vqwi x)
{
#define     VQWI_REVS(X) ((Vqwi){QWZ_REVS(X.V0)})
    return  VQWI_REVS(x);
}

INLINE(Vqwf,VQWF_REVS) (Vqwf x)
{
#define     VQWF_REVS(X) _mm_shuffle_ps(X,X,0b00011011)
    return  VQWF_REVS(x);
}

INLINE(Vqdu,VQDU_REVS) (Vqdu x)
{
#define     VQDU_REVS(X) ((Vqdu){QDZ_REVS(X.V0)})
    return  VQDU_REVS(x);
}

INLINE(Vqdi,VQDI_REVS) (Vqdi x)
{
#define     VQDI_REVS(X) ((Vqdi){QDZ_REVS(X.V0)})
    return  VQDI_REVS(x);
}

INLINE(Vqdf,VQDF_REVS) (Vqdf x)
{
#define     VQDF_REVS(X) _mm_shuffle_pd(X,X, 0b01);
    return  VQDF_REVS(x);
}

#if 0 // _LEAVE_ARM_REVS
}
#endif

#if 0 // _ENTER_ARM_REVB
{
#endif

INLINE( ushort, USHRT_REVB)  (ushort x) {return MY_REVSHZ(x);}
INLINE(  short,  SHRT_REVB)   (short x) {return MY_REVSHZ(x);}

INLINE(   uint,  UINT_REVB)    (uint x) {return MY_REVSWZ(x);}
INLINE(    int,   INT_REVB)     (int x) {return MY_REVSWZ(x);}
INLINE(  ulong, ULONG_REVB)   (ulong x) 
{
#if DWRD_NLONG == 2
    return  MY_REVSWZ(x);
#else
    return  MY_REVSDZ(x);
#endif
}

INLINE(   long,  LONG_REVB)    (long x) {return ULONG_REVB(x);}
INLINE( ullong,ULLONG_REVB)  (ullong x) 
{
#if QUAD_NLLONG == 2
    return  MY_REVSDZ(x);
#else
#   error "128 bit x86?"
#endif
}

INLINE(  llong, LLONG_REVB)   (llong x) {return ULLONG_REVB(x);}
INLINE(flt16_t, FLT16_REVB) (flt16_t x)
{
#if defined(SPC_X86_FP16)
    return  HBR_REVS(x);
#else
    return ((HALF_TYPE){.U=UINT16_REVB(((HALF_TYPE){.F=x}).U)}).F;
#endif
}

INLINE(  float,   FLT_REVB)   (float x) {return WBR_REVS(x);}
INLINE( double,   DBL_REVB)  (double x) {return DBR_REVS(x);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,revbqu) (QUAD_UTYPE x)
{
    QUAD_TYPE l = {.U=x};
    QUAD_TYPE r = {
        .Lo.U = UINT64_REVB(l.Hi.U),
        .Hi.U = UINT64_REVB(l.Lo.U),
    };
    return  r.U;
}

INLINE(QUAD_ITYPE,revbqi) (QUAD_ITYPE x)
{
    QUAD_TYPE l = {.I=x};
    QUAD_TYPE r = {
        .Lo.U = UINT64_REVB(l.Hi.U),
        .Hi.U = UINT64_REVB(l.Lo.U),
    };
    return  r.I;
}

#endif

INLINE(float,WHR_REVB) (float v)
{
    __m128  f = _mm_set_ss(v);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x0607040502030001LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(Vwhu,VWHU_REVB) (Vwhu x) {return ((Vwhu){WHR_REVB(x.V0)});}
INLINE(Vwhi,VWHI_REVB) (Vwhi x) {return ((Vwhi){WHR_REVB(x.V0)});}
INLINE(Vwhf,VWHF_REVB) (Vwhf x) {return ((Vwhf){WHR_REVB(x.V0)});}
INLINE(Vwwu,VWWU_REVB) (Vwwu x) {return ((Vwwu){WBR_REVS(x.V0)});}
INLINE(Vwwi,VWWI_REVB) (Vwwi x) {return ((Vwwi){WBR_REVS(x.V0)});}
INLINE(Vwwf,VWWF_REVB) (Vwwf x) {return ((Vwwf){WBR_REVS(x.V0)});}


INLINE(double,DHR_REVB) (double v)
{
    __m128d f = _mm_set_sd(v);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x0607040502030001LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

INLINE(double,DWR_REVB) (double v)
{
    __m128d f = _mm_set_sd(v);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x0405060700010203LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

INLINE(Vdhu,VDHU_REVB) (Vdhu x) {return ((Vdhu){DHR_REVB(x.V0)});}
INLINE(Vdhi,VDHI_REVB) (Vdhi x) {return ((Vdhi){DHR_REVB(x.V0)});}
INLINE(Vdhf,VDHF_REVB) (Vdhf x) {return ((Vdhf){DHR_REVB(x.V0)});}
INLINE(Vdwu,VDWU_REVB) (Vdwu x) {return ((Vdwu){DWR_REVB(x.V0)});}
INLINE(Vdwi,VDWI_REVB) (Vdwi x) {return ((Vdwi){DWR_REVB(x.V0)});}
INLINE(Vdwf,VDWF_REVB) (Vdwf x) {return ((Vdwf){DWR_REVB(x.V0)});}
INLINE(Vddu,VDDU_REVB) (Vddu x) {return ((Vddu){DBR_REVS(x.V0)});}
INLINE(Vddi,VDDI_REVB) (Vddi x) {return ((Vddi){DBR_REVS(x.V0)});}
INLINE(Vddf,VDDF_REVB) (Vddf x) {return ((Vddf){DBR_REVS(x.V0)});}

#define     QHZ_REVB(X) \
_mm_shuffle_epi8(       \
    X,                  \
    _mm_set_epi16(      \
        0x0e0f,0x0c0d,  \
        0x0a0b,0x0809,  \
        0x0607,0x0405,  \
        0x0203,0x0001   \
    )                   \
)

#define     QWZ_REVB(X)         \
_mm_shuffle_epi8(               \
    X,                          \
    _mm_set_epi32(              \
        0x0c0d0e0f,0x08090a0b,  \
        0x04050607,0x00010203   \
    )                           \
)


#define     QDZ_REVB(X)         \
_mm_shuffle_epi8(               \
    X,                          \
    _mm_set_epi64x(             \
        0x08090a0b0c0d0e0fLL,   \
        0x0001020304050607LL    \
    )                           \
)

#define     QDF_REVB(X) _mm_castsi128_pd(QDZ_REVB(_mm_castpd_si128(X)))


INLINE(Vqhu,VQHU_REVB) (Vqhu x)
{
#define     VQHU_REVB(X) ((Vqhu){QHZ_REVB(X.V0)})
    return  VQHU_REVB(x);
}

INLINE(Vqhi,VQHI_REVB) (Vqhi x)
{
#define     VQHI_REVB(X) ((Vqhi){QHZ_REVB(X.V0)})
    return  VQHI_REVB(x);
}

INLINE(Vqhf,VQHF_REVB) (Vqhf x)
{
#if defined(SPC_X86_FP16)
#   define  VQHF_REVB(X) _mm_castsi128_ph(QHZ_REVB(_mm_castph_si128(X)))
#else
#   define  VQHF_REVB(X) ((Vqhf){QHZ_REVB(X.V0)})
#endif

    return  VQHF_REVB(x);
}


INLINE(Vqwu,VQWU_REVB) (Vqwu x)
{
#define     VQWU_REVB(X) ((Vqwu){QWZ_REVB(X.V0)})
    return  VQWU_REVB(x);
}

INLINE(Vqwi,VQWI_REVB) (Vqwi x)
{
#define     VQWI_REVB(X) ((Vqwi){QWZ_REVB(X.V0)})
    return  VQWI_REVB(x);
}

INLINE(Vqwf,VQWF_REVB) (Vqwf x)
{
#define     VQWF_REVB(X) _mm_castsi128_ps(QWZ_REVB(_mm_castps_si128(X)))
    return  VQWF_REVB(x);
}


INLINE(Vqdu,VQDU_REVB) (Vqdu x)
{
#define     VQDU_REVB(X) ((Vqdu){QDZ_REVB(X.V0)})
    return  VQDU_REVB(x);
}

INLINE(Vqdi,VQDI_REVB) (Vqdi x)
{
#define     VQDI_REVB(X) ((Vqdi){QDZ_REVB(X.V0)})
    return  VQDI_REVB(x);
}

INLINE(Vqdf,VQDF_REVB) (Vqdf x)
{
#define     VQDF_REVB(X) _mm_castsi128_ps(QDZ_REVB(_mm_castps_si128(X)))
    return  VQDF_REVB(x);
}

#if 0 // _LEAVE_ARM_REVB
}
#endif

#if 0 // _ENTER_X86_ZIPL
{
#endif

INLINE(float,WBR_ZIPL) (float a, float b)
{
    __m128  f = _mm_set_ps(0,0,b,a);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x05010400LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,WHR_ZIPL) (float a, float b)
{
    __m128  f = _mm_set_ps(0,0,b,a);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x05040100LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(double,DBZ_ZIPL) (double a, double b)
{
    __m128d f = _mm_set_pd(b, a);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x0b030a0209010800LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

INLINE(double,DHZ_ZIPL) (double a, double b)
{
    __m128d f = _mm_set_pd(b, a);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x0b0a030209080100LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

INLINE(double,DWZ_ZIPL) (double a, double b)
{
    __m128d f = _mm_set_pd(b, a);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi64x(0, 0x0b0a090803020100LL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_pd(z);
    return  _mm_cvtsd_f64(f);
}

#define     QBZ_ZIPL _mm_unpacklo_epi8
#define     QHZ_ZIPL _mm_unpacklo_epi16
#if defined(SPC_X86_FP16)
#   define  QHF_ZIPL(A, B) \
_mm_castsi128_ph(_mm_unpacklo_epi16(_mm_castph_si128(A),_mm_castph_si128(B)))
#else
#   define  QHF_ZIPL _mm_unpacklo_epi16
#endif

#define     QWZ_ZIPL _mm_unpacklo_epi32
#define     QWF_ZIPL _mm_unpacklo_ps
#define     QDZ_ZIPL _mm_unpacklo_epi64
#define     QDF_ZIPL _mm_unpacklo_pd


INLINE(uint16_t, UCHAR_ZIPP) (uchar a, uchar b)
{
    unsigned x = a;
    x = 0x0f0f&(x|(x<<4));
    x = 0x3333&(x|(x<<2));
    x = 0x5555&(x|(x<<1));
    unsigned y = b;
    y = 0x0f0f&(y|(y<<4));
    y = 0x3333&(y|(y<<2));
    y = 0x5555&(y|(y<<1));
    return x|(y<<1);
}

INLINE(uint16_t, CHAR_ZIPP) (char a, char b)
{
    return  UCHAR_ZIPP(a, b);
}

INLINE(uint32_t, USHRT_ZIPP) (ushort a, ushort b)
{
    uint32_t x = a;
    x = UINT32_C(0x00ff00ff)&(x|(x<<8));
    x = UINT32_C(0x0f0f0f0f)&(x|(x<<4));
    x = UINT32_C(0x33333333)&(x|(x<<2));
    x = UINT32_C(0x55555555)&(x|(x<<1));
    uint32_t y = b;
    y = UINT32_C(0x00ff00ff)&(y|(y<<8));
    y = UINT32_C(0x0f0f0f0f)&(y|(y<<4));
    y = UINT32_C(0x33333333)&(y|(y<<2));
    y = UINT32_C(0x55555555)&(y|(y<<1));
    return x|(y<<1);
}

INLINE(uint64_t, UINT_ZIPP) (uint a, uint b)
{
    uint64_t x = a;
    x = UINT64_C(0x0000ffff0000ffff)&(x|(x<<16));
    x = UINT64_C(0x00ff00ff00ff00ff)&(x|(x<<8));
    x = UINT64_C(0x0f0f0f0f0f0f0f0f)&(x|(x<<4));
    x = UINT64_C(0x3333333333333333)&(x|(x<<2));
    x = UINT64_C(0x5555555555555555)&(x|(x<<1));
    uint64_t y = b;
    y = UINT64_C(0x0000ffff0000ffff)&(y|(y<<16));
    y = UINT64_C(0x00ff00ff00ff00ff)&(y|(y<<8));
    y = UINT64_C(0x0f0f0f0f0f0f0f0f)&(y|(y<<4));
    y = UINT64_C(0x3333333333333333)&(y|(y<<2));
    y = UINT64_C(0x5555555555555555)&(y|(y<<1));
    return x|(y<<1);
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_ZIPP) (ulong a, ulong b)
{
    return  UINT_ZIPP(a, b);
}

#endif

INLINE(uint64_t, UINT64_ZIPL) (uint64_t a, uint64_t b)
{
    return  UINT_ZIPP(a, b);
}

INLINE(uint64_t, UINT64_ZIPR) (uint64_t a, uint64_t b)
{
    return UINT_ZIPP((a>>32), (b>>32));
}


INLINE(Vwyu,VWYU_ZIPL) (Vwyu a, Vwyu b)
{
    WORD_TYPE x = {.F=a.V0};
    WORD_TYPE y = {.F=b.V0};
    x.U = USHRT_ZIPP(x, y);
    return  (VWYU_TYPE){x.F};
}


INLINE(Vwbu,VWBU_ZIPL) (Vwbu a, Vwbu b)
{
    return  ((VWBU_TYPE){WBZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vwbi,VWBI_ZIPL) (Vwbi a, Vwbi b)
{
    return  ((VWBI_TYPE){WBZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vwbc,VWBC_ZIPL) (Vwbc a, Vwbc b)
{
    return  ((VWBC_TYPE){WBZ_ZIPL(a.V0, b.V0)});
}


INLINE(Vwhu,VWHU_ZIPL) (Vwhu a, Vwhu b)
{
    return  ((VWHU_TYPE){WHZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vwhi,VWHI_ZIPL) (Vwhi a, Vwhi b)
{
    return  ((VWHI_TYPE){WHZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vwhf,VWHF_ZIPL) (Vwhf a, Vwhf b)
{
    return  ((VWHF_TYPE){WHZ_ZIPL(a.V0, b.V0)});
}


INLINE(Vdyu,VDYU_ZIPL) (Vdyu a, Vdyu b)
{
    DWRD_TYPE x = {.F=a.V0};
    DWRD_TYPE y = {.F=b.V0};
    x.U = UINT_ZIPP(x, y);
    return  (VDYU_TYPE){x.F};
}

INLINE(Vdbu,VDBU_ZIPL) (Vdbu a, Vdbu b) 
{
    return  ((VDBU_TYPE){DBZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vdbi,VDBI_ZIPL) (Vdbi a, Vdbi b) 
{
    return  ((VDBI_TYPE){DBZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vdbc,VDBC_ZIPL) (Vdbc a, Vdbc b)
{
    return  ((VDBC_TYPE){DBZ_ZIPL(a.V0, b.V0)});
}


INLINE(Vdhu,VDHU_ZIPL) (Vdhu a, Vdhu b) 
{
    return  ((VDHU_TYPE){DHZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vdhi,VDHI_ZIPL) (Vdhi a, Vdhi b) 
{
    return  ((VDHI_TYPE){DHZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vdhf,VDHF_ZIPL) (Vdhf a, Vdhf b)
{
    return  ((VDHF_TYPE){DHZ_ZIPL(a.V0, b.V0)});
}


INLINE(Vdwu,VDWU_ZIPL) (Vdwu a, Vdwu b) 
{
    return  ((VDWU_TYPE){DWZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vdwi,VDWI_ZIPL) (Vdwi a, Vdwi b) 
{
    return  ((VDWI_TYPE){DWZ_ZIPL(a.V0, b.V0)});
}

INLINE(Vdwf,VDWF_ZIPL) (Vdwf a, Vdwf b) 
{
    return  ((VDWF_TYPE){DWZ_ZIPL(a.V0, b.V0)});
}


INLINE(Vqyu,VQYU_ZIPL) (Vqyu a, Vqyu b)
{
    uint64_t p = _mm_cvtsi128_si64(a);
    uint64_t q = _mm_cvtsi128_si64(b);
    uint64_t l = UINT_ZIPP(p, q);
    uint64_t r = UINT_ZIPP(p>>32, q>>32);
    return  _mm_set_epi64x(r, l);
}


INLINE(Vqbu,VQBU_ZIPL) (Vqbu a, Vqbu b) 
{
    return  ((VQBU_TYPE){QBZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqbi,VQBI_ZIPL) (Vqbi a, Vqbi b) 
{
    return  ((VQBI_TYPE){QBZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqbc,VQBC_ZIPL) (Vqbc a, Vqbc b)
{
    return  ((VQBC_TYPE){QBZ_ZIPL(a.V0,b.V0)});
}


INLINE(Vqhu,VQHU_ZIPL) (Vqhu a, Vqhu b) 
{
    return  ((VQHU_TYPE){QHZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqhi,VQHI_ZIPL) (Vqhi a, Vqhi b) 
{
    return  ((VQHI_TYPE){QHZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqhf,VQHF_ZIPL) (Vqhf a, Vqhf b)
{
    __m128i p, q;
#if defined(SPC_X86_FP16)
    p = _mm_castph_si128(a);
    q = _mm_castph_si128(b);
#else
    p = a.V0;
    q = b.V0;
#endif

    p = QHZ_ZIPL(p,q);
#if defined(SPC_X86_FP16)
    return  _mm_castsi128_ph(p);
#else 
    return  p;
#endif

}


INLINE(Vqwu,VQWU_ZIPL) (Vqwu a, Vqwu b) 
{
    return  ((VQWU_TYPE){QWZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqwi,VQWI_ZIPL) (Vqwi a, Vqwi b)
{
    return  ((VQWI_TYPE){QWZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqwf,VQWF_ZIPL) (Vqwf a, Vqwf b) 
{
    return  QWF_ZIPL(a, b);
}


INLINE(Vqdu,VQDU_ZIPL) (Vqdu a, Vqdu b) 
{
    return  ((VQDU_TYPE){QDZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqdi,VQDI_ZIPL) (Vqdi a, Vqdi b) 
{
    return  ((VQDI_TYPE){QDZ_ZIPL(a.V0,b.V0)});
}

INLINE(Vqdf,VQDF_ZIPL) (Vqdf a, Vqdf b) 
{
    return  QDF_ZIPL(a, b);
}

#if 0 // _LEAVE_X86_ZIPL
}
#endif

#if 0 // _ENTER_X86_UZPL
{
#endif

INLINE(float,WBR_UZPL) (float a, float b)
{
    __m128  f = _mm_setr_ps(a, b, 0.0f, 0.0f);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set1_epi64x(0x0000000006040200ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,WHR_UZPL) (float a, float b)
{
    __m128  f = _mm_setr_ps(a, b, 0.0f, 0.0f);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set1_epi64x(0x0000000005040100ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}


INLINE(Vwbu,VWBU_UZPL) (Vwbu a, Vwbu b)
{
    return  ((VWBU_TYPE){WBR_UZPL(a.V0, b.V0)});
}

INLINE(Vwbi,VWBI_UZPL) (Vwbi a, Vwbi b)
{
    return  ((VWBI_TYPE){WBR_UZPL(a.V0, b.V0)});
}

INLINE(Vwbc,VWBC_UZPL) (Vwbc a, Vwbc b)
{
    return  ((VWBC_TYPE){WBR_UZPL(a.V0, b.V0)});
}


INLINE(Vwhu,VWHU_UZPL) (Vwhu a, Vwhu b)
{
    return  ((VWHU_TYPE){WBR_UZPL(a.V0, b.V0)});
}

INLINE(Vwhi,VWHI_UZPL) (Vwhi a, Vwhi b)
{
    return  ((VWHI_TYPE){WBR_UZPL(a.V0, b.V0)});
}

INLINE(Vwhf,VWHF_UZPL) (Vwhf a, Vwhf b)
{
    return  ((VWHF_TYPE){WBR_UZPL(a.V0, b.V0)});
}


INLINE(Vdyu,VDYU_UZPL) (Vdyu a, Vdyu b)
{
    // TODO
    return  a;
}

INLINE(double,DBR_UZPL) (double a, double b)
{
    __m128d f = _mm_setr_pd(a, b);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set1_epi64x(0x0e0c0a0806040200ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return _mm_cvtsd_f64(f);
}

INLINE(double,DHR_UZPL) (double a, double b)
{
    __m128d f = _mm_setr_pd(a, b);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set1_epi64x(0x0d0c090805040100ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return _mm_cvtsd_f64(f);
}

INLINE(double,DWR_UZPL) (double a, double b)
{
    __m128d f = _mm_setr_pd(a, b);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set1_epi64x(0x0b0a090803020100ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return _mm_cvtsd_f64(f);
}


INLINE(Vdbu,VDBU_UZPL) (Vdbu a, Vdbi b) 
{
    return  ((VDBU_TYPE){DBR_UZPL(a.V0, b.V0)});
}

INLINE(Vdbi,VDBI_UZPL) (Vdbi a, Vdbi b) 
{
    return  ((VDBI_TYPE){DBR_UZPL(a.V0, b.V0)});
}

INLINE(Vdbc,VDBC_UZPL) (Vdbc a, Vdbc b)
{
    return  ((VDBC_TYPE){DBR_UZPL(a.V0, b.V0)});
}


INLINE(Vdhu,VDHU_UZPL) (Vdhu a, Vdhu b) 
{
    return  ((VDHU_TYPE){DHR_UZPL(a.V0, b.V0)});
}

INLINE(Vdhi,VDHI_UZPL) (Vdhi a, Vdhi b) 
{
    return  ((VDHI_TYPE){DHR_UZPL(a.V0, b.V0)});
}

INLINE(Vdhf,VDHF_UZPL) (Vdhf a, Vdhf b)
{
    return  ((VDHF_TYPE){DHR_UZPL(a.V0, b.V0)});
}


INLINE(Vdwu,VDWU_UZPL) (Vdwu a, Vdwu b) 
{
    return  ((VDWU_TYPE){DWR_UZPL(a.V0, b.V0)});
}
    
INLINE(Vdwi,VDWI_UZPL) (Vdwi a, Vdwi b)
{
    return  ((VDWI_TYPE){DWR_UZPL(a.V0, b.V0)});
}

INLINE(Vdwf,VDWF_UZPL) (Vdwf a, Vdwf b)
{
    return  ((VDWF_TYPE){DWR_UZPL(a.V0, b.V0)});
}


INLINE(__m128i,QBZ_UZPL) (__m128i a, __m128i b)
{
    __m128i t = _mm_set1_epi64x(0x0e0c0a0806040200ULL);
    a = _mm_shuffle_epi8(a, t);
    b = _mm_shuffle_epi8(b, t);
    return  _mm_unpacklo_epi64(a, b);
}

INLINE(__m128i,QHZ_UZPL) (__m128i a, __m128i b)
{
    __m128i t = _mm_set1_epi64x(0x0d0c090805040100ULL);
    a = _mm_shuffle_epi8(a, t);
    b = _mm_shuffle_epi8(b, t);
    return  _mm_unpacklo_epi64(a, b);
}

INLINE(__m128i,QWZ_UZPL) (__m128i a, __m128i b)
{
    __m128i t = _mm_set1_epi64x(0x0b0a090803020100ULL);
    a = _mm_shuffle_epi8(a, t);
    b = _mm_shuffle_epi8(b, t);
    return  _mm_unpacklo_epi64(a, b);
}

INLINE(__m128i,QDZ_UZPL) (__m128i a, __m128i b)
{
    return  _mm_unpacklo_epi64(a, b);
}


INLINE(Vqbu,VQBU_UZPL) (Vqbu a, Vqbu b) 
{
    return  ((VQBU_TYPE){QBZ_UZPL(a.V0, b.V0)});
}

INLINE(Vqbi,VQBI_UZPL) (Vqbi a, Vqbi b) 
{
    return  ((VQBI_TYPE){QBZ_UZPL(a.V0, b.V0)});
}


INLINE(Vqbc,VQBC_UZPL) (Vqbc a, Vqbc b)
{
    return  ((VQBC_TYPE){QBZ_UZPL(a.V0, b.V0)});
}

INLINE(Vqhu,VQHU_UZPL) (Vqhu a, Vqhu b) 
{
    return  ((VQHU_TYPE){QHZ_UZPL(a.V0, b.V0)});
}

INLINE(Vqhi,VQHI_UZPL) (Vqhi a, Vqhi b) 
{
    return  ((VQHI_TYPE){QHZ_UZPL(a.V0, b.V0)});
}

INLINE(Vqhf,VQHF_UZPL) (Vqhf a, Vqhf b)
{
#if defined(SPC_X86_FP16)
    __m128i l = _mm_castph_si128(a);
    __m128i r = _mm_castph_si128(b);
    l = QHZ_UZPL(l, r);
    return  _mm_castsi128_ph(l);
#else
    return  ((VQHF_TYPE){QHZ_UZPL(a.V0, b.V0)});
#endif
}


INLINE(Vqwu,VQWU_UZPL) (Vqwu a, Vqwu b) 
{
    return  ((VQWU_TYPE){QWZ_UZPL(a.V0, b.V0)});
}

INLINE(Vqwi,VQWI_UZPL) (Vqwi a, Vqwi b) 
{
    return  ((VQWI_TYPE){QWZ_UZPL(a.V0, b.V0)});
}

INLINE(Vqwf,VQWF_UZPL) (Vqwf a, Vqwf b) 
{
    __m128i z = QWZ_UZPL(_mm_castps_si128(a, _mm_castps_si128(b)));
    return  _mm_castsi128_ps(z);
}


INLINE(Vqdu,VQDU_UZPL) (Vqdu a, Vqdu b) 
{
    return  ((VQDU_TYPE){_mm_unpacklo_epi64(a.V0, b.V0)});
}

INLINE(Vqdi,VQDI_UZPL) (Vqdi a, Vqdi b) 
{
    return  ((VQDI_TYPE){_mm_unpacklo_epi64(a.V0, b.V0)});
}

INLINE(Vqdf,VQDF_UZPL) (Vqdf a, Vqdf b) 
{
    return  _mm_unpacklo_pd(a, b);
}


#if 0 // _LEAVE_X86_UZPL
}
#endif

#if 0 // _ENTER_X86_UZPR
{
#endif

INLINE(float,WBR_UZPR) (float a, float b)
{
    __m128  f = _mm_setr_ps(a, b, 0.0f, 0.0f);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set1_epi64x(0x0000000007050301ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,WHR_UZPR) (float a, float b)
{
    __m128  f = _mm_setr_ps(a, b, 0.0f, 0.0f);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set1_epi64x(0x0000000007060302ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}


INLINE(Vwbu,VWBU_UZPR) (Vwbu a, Vwbu b)
{
    return  ((VWBU_TYPE){WBR_UZPR(a.V0, b.V0)});
}

INLINE(Vwbi,VWBI_UZPR) (Vwbi a, Vwbi b)
{
    return  ((VWBI_TYPE){WBR_UZPR(a.V0, b.V0)});
}

INLINE(Vwbc,VWBC_UZPR) (Vwbc a, Vwbc b)
{
    return  ((VWBC_TYPE){WBR_UZPR(a.V0, b.V0)});
}


INLINE(Vwhu,VWHU_UZPR) (Vwhu a, Vwhu b)
{
    return  ((VWHU_TYPE){WBR_UZPR(a.V0, b.V0)});
}

INLINE(Vwhi,VWHI_UZPR) (Vwhi a, Vwhi b)
{
    return  ((VWHI_TYPE){WBR_UZPR(a.V0, b.V0)});
}

INLINE(Vwhf,VWHF_UZPR) (Vwhf a, Vwhf b)
{
    return  ((VWHF_TYPE){WBR_UZPR(a.V0, b.V0)});
}


INLINE(Vdyu,VDYU_UZPR) (Vdyu a, Vdyu b)
{
    // TODO
    return  a;
}

INLINE(double,DBR_UZPR) (double a, double b)
{
    __m128d f = _mm_setr_pd(a, b);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set1_epi64x(0x0f0d0b0907050301ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return _mm_cvtsd_f64(f);
}

INLINE(double,DHR_UZPR) (double a, double b)
{
    __m128d f = _mm_setr_pd(a, b);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set1_epi64x(0x0f0e0b0a07060302ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return _mm_cvtsd_f64(f);
}

INLINE(double,DWR_UZPR) (double a, double b)
{
    __m128d f = _mm_setr_pd(a, b);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set1_epi64x(0x0f0e0d0c07060504ULL);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castsi128_ps(z);
    return _mm_cvtsd_f64(f);
}


INLINE(Vdbu,VDBU_UZPR) (Vdbu a, Vdbi b) 
{
    return  ((VDBU_TYPE){DBR_UZPR(a.V0, b.V0)});
}

INLINE(Vdbi,VDBI_UZPR) (Vdbi a, Vdbi b) 
{
    return  ((VDBI_TYPE){DBR_UZPR(a.V0, b.V0)});
}

INLINE(Vdbc,VDBC_UZPR) (Vdbc a, Vdbc b)
{
    return  ((VDBC_TYPE){DBR_UZPR(a.V0, b.V0)});
}


INLINE(Vdhu,VDHU_UZPR) (Vdhu a, Vdhu b) 
{
    return  ((VDHU_TYPE){DHR_UZPR(a.V0, b.V0)});
}

INLINE(Vdhi,VDHI_UZPR) (Vdhi a, Vdhi b) 
{
    return  ((VDHI_TYPE){DHR_UZPR(a.V0, b.V0)});
}

INLINE(Vdhf,VDHF_UZPR) (Vdhf a, Vdhf b)
{
    return  ((VDHF_TYPE){DHR_UZPR(a.V0, b.V0)});
}


INLINE(Vdwu,VDWU_UZPR) (Vdwu a, Vdwu b) 
{
    return  ((VDWU_TYPE){DWR_UZPR(a.V0, b.V0)});
}
    
INLINE(Vdwi,VDWI_UZPR) (Vdwi a, Vdwi b)
{
    return  ((VDWI_TYPE){DWR_UZPR(a.V0, b.V0)});
}

INLINE(Vdwf,VDWF_UZPR) (Vdwf a, Vdwf b)
{
    return  ((VDWF_TYPE){DWR_UZPR(a.V0, b.V0)});
}


INLINE(__m128i,QBZ_UZPR) (__m128i a, __m128i b)
{
    __m128i t = _mm_set1_epi64x(0x0f0d0b0907050301ULL);
    a = _mm_shuffle_epi8(a, t);
    b = _mm_shuffle_epi8(b, t);
    return  _mm_unpacklo_epi64(a, b);
}

INLINE(__m128i,QHZ_UZPR) (__m128i a, __m128i b)
{
    __m128i t = _mm_set1_epi64x(0x0f0e0b0a07060302ULL);
    a = _mm_shuffle_epi8(a, t);
    b = _mm_shuffle_epi8(b, t);
    return  _mm_unpacklo_epi64(a, b);
}

INLINE(__m128i,QWZ_UZPR) (__m128i a, __m128i b)
{
    __m128i t = _mm_set1_epi64x(0x0f0e0d0c07060504ULL);
    a = _mm_shuffle_epi8(a, t);
    b = _mm_shuffle_epi8(b, t);
    return  _mm_unpacklo_epi64(a, b);
}


INLINE(Vqbu,VQBU_UZPR) (Vqbu a, Vqbu b) 
{
    return  ((VQBU_TYPE){QBZ_UZPR(a.V0, b.V0)});
}

INLINE(Vqbi,VQBI_UZPR) (Vqbi a, Vqbi b) 
{
    return  ((VQBI_TYPE){QBZ_UZPR(a.V0, b.V0)});
}

INLINE(Vqbc,VQBC_UZPR) (Vqbc a, Vqbc b)
{
    return  ((VQBC_TYPE){QBZ_UZPR(a.V0, b.V0)});
}


INLINE(Vqhu,VQHU_UZPR) (Vqhu a, Vqhu b) 
{
    return  ((VQHU_TYPE){QHZ_UZPR(a.V0, b.V0)});
}

INLINE(Vqhi,VQHI_UZPR) (Vqhi a, Vqhi b) 
{
    return  ((VQHI_TYPE){QHZ_UZPR(a.V0, b.V0)});
}

INLINE(Vqhf,VQHF_UZPR) (Vqhf a, Vqhf b)
{
#if defined(SPC_X86_FP16)
    __m128i l = _mm_castph_si128(a);
    __m128i r = _mm_castph_si128(b);
    l = QHZ_UZPR(l, r);
    return  _mm_castsi128_ph(l);
#else
    return  ((VQHF_TYPE){QHZ_UZPR(a.V0, b.V0)});
#endif
}


INLINE(Vqwu,VQWU_UZPR) (Vqwu a, Vqwu b) 
{
    return  ((VQWU_TYPE){QWZ_UZPR(a.V0, b.V0)});
}

INLINE(Vqwi,VQWI_UZPR) (Vqwi a, Vqwi b) 
{
    return  ((VQWI_TYPE){QWZ_UZPR(a.V0, b.V0)});
}

INLINE(Vqwf,VQWF_UZPR) (Vqwf a, Vqwf b) 
{
    __m128i l = _mm_castps_si128(a);
    __m128i r = _mm_castps_si128(b);
    l = QWZ_UZPR(l, r);
    return  _mm_castsi128_ps(l);
}


INLINE(Vqdu,VQDU_UZPR) (Vqdu a, Vqdu b) 
{
    return  ((VQDU_TYPE){_mm_unpackhi_epi64(a.V0, b.V0)});
}

INLINE(Vqdi,VQDI_UZPR) (Vqdi a, Vqdi b) 
{
    return  ((VQDI_TYPE){_mm_unpackhi_epi64(a.V0, b.V0)});
}

INLINE(Vqdf,VQDF_UZPR) (Vqdf a, Vqdf b) 
{
    return  _mm_unpackhi_pd(a, b);
}


#if 0 // _LEAVE_X86_UZPR
}
#endif


#if 0 // _ENTER_X86_DUPW
{
#endif

INLINE(Vwyu,BOOL_DUPW) (_Bool x)
{
    return  ((VWYU_TYPE){((WORD_TYPE){.U=0u-x}).F});
}

INLINE(Vwyu,BOOL_DUPWAC) (void const *a)
{
#define     BOOL_DUPWAC(A)   BOOL_DUPW((*(_Bool const *) A))
    return  BOOL_DUPWAC(a);
}

INLINE(Vwyu,VWYU_DUPW) (Vwyu v, Rc(0, 31) k)
{
    WORD_TYPE w = {.F=v.V0};
    w.U = -(1ULL&(w.U>>k));
    return  ((VWYU_TYPE){w.F});
}

INLINE(Vwyu,VDYU_DUPW) (Vdyu v, Rc(0, 63) k)
{
    DWRD_TYPE w = {.F=v.V0};
    w.U = -(1ULL&(w.U>>k));
    return  ((VWYU_TYPE){w.W0.F});
}

INLINE(Vwyu,VQYU_DUPW) (Vqyu v, Rc(0,127) k)
{
    DWRD_TYPE d;
    if (k < 64)
    {
        v = _mm_srl_epi64(v, _mm_cvtsi64_si128(k));
    }
    else
    {
        v = _mm_srl_epi64(v, _mm_cvtsi64_si128(k-64));
        v = _mm_unpackhi_epi64(v, v);
    }
    d.U = _mm_cvtsi128_si64(v);
    d.U = -(1ULL&d.U);
    return  ((VWYU_TYPE){d.W0.F});
}


INLINE(float,WBR_DUPW) (float v, int k)
{
    __m128i t = _mm_set1_epi8(k);
    __m128  w = _mm_set_ss(v);
    __m128i z = _mm_castps_si128(w);
    z = _mm_shuffle_epi8(z, t);
    w = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(w);
}

INLINE(float,DBR_DUPW) (double v, int k)
{
    __m128i t = _mm_set1_epi8(k);
    __m128d d = _mm_set_sd(v);
    __m128i z = _mm_castpd_si128(d);
    z = _mm_shuffle_epi8(z, t);
    __m128  f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,QBZ_DUPW) (__m128i v, int k)
{
    v = _mm_shuffle_epi8(v, _mm_set1_epi8(k));
    __m128  f = _mm_castsi128_ps(v);
    return  _mm_cvtss_f32(f);
}


INLINE(Vwbu,UCHAR_DUPW) (uchar x)
{
#define     UCHAR_DUPW(X) \
((VWBU_TYPE){_mm_cvtss_f32(_mm_castsi128_ps(_mm_set1_epi8(X)))})

    return  UCHAR_DUPW(x);
}


INLINE(Vwbu,UCHAR_DUPWAC) (void const *a)
{
    return  UCHAR_DUPW((*(uchar const *) a));
}

INLINE(Vwbu,VWBU_DUPW) (Vwbu v, Rc(0, 3) k)
{
    return  ((VWBU_TYPE){WBR_DUPW(v.V0, k)});
}

INLINE(Vwbu,VDBU_DUPW) (Vdbu v, Rc(0, 7) k)
{
    return  ((VWBU_TYPE){DBR_DUPW(v.V0, k)});
}

INLINE(Vwbu,VQBU_DUPW) (Vqbu v, Rc(0, 15) k)
{
    return  ((VWBU_TYPE){QBZ_DUPW(v.V0, k)});
}


INLINE(Vwbi,SCHAR_DUPW) (schar x)
{
#define     SCHAR_DUPW(X) \
((VWBI_TYPE){_mm_cvtss_f32(_mm_castsi128_ps(_mm_set1_epi8(X)))})

    return  SCHAR_DUPW(x);
}


INLINE(Vwbi,SCHAR_DUPWAC) (void const *a)
{
    return  SCHAR_DUPW((*(schar const *) a));
}

INLINE(Vwbi,VWBI_DUPW) (Vwbi v, Rc(0, 3) k)
{
    return  ((VWBI_TYPE){WBR_DUPW(v.V0, k)});
}

INLINE(Vwbi,VDBI_DUPW) (Vdbi v, Rc(0, 7) k)
{
    return  ((VWBI_TYPE){DBR_DUPW(v.V0, k)});
}

INLINE(Vwbi,VQBI_DUPW) (Vqbi v, Rc(0, 15) k)
{
    return  ((VWBU_TYPE){QBZ_DUPW(v.V0, k)});
}


INLINE(Vwbc,CHAR_DUPW) (char x)
{
#define     CHAR_DUPW(X) \
((VWBC_TYPE){_mm_cvtss_f32(_mm_castsi128_ps(_mm_set1_epi8(X)))})

    return  CHAR_DUPW(x);
}

INLINE(Vwbc,CHAR_DUPWAC) (void const *a)
{
    return  CHAR_DUPW((*(char const *) a));
}

INLINE(Vwbc,VWBC_DUPW) (Vwbc v, Rc(0, 3) k)
{
    return  ((VWBC_TYPE){WBR_DUPW(v.V0, k)});
}

INLINE(Vwbc,VDBC_DUPW) (Vdbc v, Rc(0, 7) k)
{
    return  ((VWBC_TYPE){DBR_DUPW(v.V0, k)});
}

INLINE(Vwbc,VQBC_DUPW) (Vqbc v, Rc(0, 15) k)
{
    return  ((VWBC_TYPE){QBZ_DUPW(v.V0, k)});
}



INLINE(float,WHR_DUPW) (float v, int k)
{
    __m128i t = _mm_set1_epi8((2*k));
    __m128  m = _mm_set_ss(v);
    __m128i z = _mm_castps_si128(m);
    t = _mm_add_epi8(t, _mm_set1_epi16(0x0100));
    z = _mm_shuffle_epi8(z, t);
    m = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(m);
}

INLINE(float,DHR_DUPW) (double v, int k)
{
    __m128i t = _mm_set1_epi8((2*k));
    __m128d m = _mm_set_sd(v);
    __m128i z = _mm_castps_si128(m);
    t = _mm_add_epi8(t, _mm_set1_epi16(0x0100));
    z = _mm_shuffle_epi8(z, t);
    __m128  f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,QHZ_DUPW) (__m128i v, int k)
{
    __m128i t = _mm_set1_epi8((2*k));
    t = _mm_add_epi8(t, _mm_set1_epi16(0x0100));
    v = _mm_shuffle_epi8(v, t);
    __m128  f = _mm_castsi128_ps(v);
    return  _mm_cvtss_f32(f);
}


INLINE(Vwhu,USHRT_DUPW) (ushort x)
{
#define     USHRT_DUPW(X) \
((VWHU_TYPE){_mm_cvtss_f32(_mm_castsi128_ps(_mm_set1_epi16(X)))})

    return  USHRT_DUPW(x);
}

INLINE(Vwhu,USHRT_DUPWAC) (void const *a)
{
    return  USHRT_DUPW( (*(ushort const *) a) );
}

INLINE(Vwhu,VWHU_DUPW) (Vwhu v, Rc(0, 1) b)
{
    return  ((VWHU_TYPE){WHR_DUPW(v.V0, k)});
}

INLINE(Vwhu,VDHU_DUPW) (Vdhu v, Rc(0, 3) k)
{
    return  ((VWHU_TYPE){DHR_DUPW(v.V0, k)});
}

INLINE(Vwhu,VQHU_DUPW) (Vqhu v, Rc(0, 7) k)
{
    return  ((VWHU_TYPE){QHZ_DUPW(v.V0, k)});
}


INLINE(Vwhi,SHRT_DUPW) (short x)
{
#define     SHRT_DUPW(X) \
((VWHI_TYPE){_mm_cvtss_f32(_mm_castsi128_ps(_mm_set1_epi16(X)))})

    return  SHRT_DUPW(x);
}

INLINE(Vwhi,SHRT_DUPWAC) (void const *a)
{
    return  SHRT_DUPW( (*(short const *) a) );
}

INLINE(Vwhi,VWHI_DUPW) (Vwhi v, Rc(0, 1) k)
{
    return  ((VWHI_TYPE){WHR_DUPW(v.V0, k)});
}

INLINE(Vwhi,VDHI_DUPW) (Vdhi v, Rc(0, 3) k)
{
    return  ((VWHU_TYPE){DHR_DUPW(v.V0, k)});
}

INLINE(Vwhi,VQHI_DUPW) (Vqhi v, Rc(0, 7) k)
{
    return  ((VWHU_TYPE){QHH_DUPW(v.V0, k)});
}


INLINE(Vwhf,FLT16_DUPW) (flt16_t x)
{
#if defined(SPC_X86_FP16)
#   define  FLT16_DUPW(X) \
((VWHF_TYPE){_mm_cvtss_f32(_mm_castph_ps(_mm_set1_ph(X)))})

#else
#   define  FLT16_DUPW(X) \
((VWHF_TYPE){0.0f})

#endif

    return  FLT16_DUPW(x);
}

INLINE(Vwhf,FLT16_DUPWAC) (void const *a)
{
    return  FLT16_DUPW( (*(flt16_t const *) a) );
}

INLINE(Vwhf,VWHF_DUPW) (Vwhf v, Rc(0, 1) k)
{
    return  ((VWHF_TYPE){WHR_DUPW(v.V0, k)});
}

INLINE(Vwhf,VDHF_DUPW) (Vdhf v, Rc(0, 3) k)
{
    return  ((VWHF_TYPE){DHR_DUPW(v.V0, k)});
}

INLINE(Vwhf,VQHF_DUPW) (Vqhf v, Rc(0, 7) k)
{
    __m128i z;
#if defined(SPC_X86_FP16)
    z = _mm_castph_si128(v);
#else
    z = v.V0;
#endif

    return  QHZ_DUPW(z, k);;
}


INLINE(float,DWR_DUPW) (double v, int k)
{
    __m128i t = _mm_set1_epi8((4*k));
    __m128d m = _mm_set_sd(v);
    __m128i z = _mm_castps_si128(m);
    t = _mm_add_epi8(t, _mm_set1_epi16(0x03020100));
    z = _mm_shuffle_epi8(z, t);
    __m128  f = _mm_castsi128_ps(z);
    return  _mm_cvtss_f32(f);
}

INLINE(float,QWZ_DUPW) (__m128i v, int k)
{
    __m128i t = _mm_set1_epi8((4*k));
    t = _mm_add_epi8(t, _mm_set1_epi16(0x03020100));
    v = _mm_shuffle_epi8(v, t);
    __m128  f = _mm_castsi128_ps(v);
    return  _mm_cvtss_f32(f);
}


INLINE(Vwwu,UINT_DUPW) (uint x)
{
    __m128i z = _mm_cvtsi32_si128(x);
    __m128  f = _mm_castsi128_ps(z);
    float   m = _mm_cvtss_f32(f);
    return  ((VWWU_TYPE){m});
}

INLINE(Vwwu,UINT_DUPWAC) (void const *a)
{
    __m128  f = _mm_load_ss(a);
    float   m = _mm_cvtss_f32(f);
    return  ((VWWU_TYPE){m});
}

INLINE(Vwwu,VWWU_DUPW) (Vwwu v, Rc(0, 0) k) {return v;}

INLINE(Vwwu,VDWU_DUPW) (Vdwu v, Rc(0, 1) k)
{
    return  ((VWWU_TYPE){DWR_DUPW(v.V0, k)});
}

INLINE(Vwwu,VQWU_DUPW) (Vqwu v, Rc(0, 3) k)
{
    return  ((VWWU_TYPE){QWZ_DUPW(v.V0, k)});
}



INLINE(Vwwi, INT_DUPW) (int x)
{
    return  ((VWWI_TYPE){((WORD_TYPE){.I=x}).F});
}

INLINE(Vwwi, INT_DUPWAC) (void const *a)
{
    __m128  f = _mm_load_ss(a);
    float   m = _mm_cvtss_f32(f);
    return  ((VWWI_TYPE){m});
}

INLINE(Vwwi,VWWI_DUPW) (Vwwi v, Rc(0, 0) k) {return v;}

INLINE(Vwwi,VDWI_DUPW) (Vdwi v, Rc(0, 1) k)
{
    return  ((VWWI_TYPE){DWR_DUPW(v.V0, k)});
}

INLINE(Vwwi,VQWI_DUPW) (Vqwi v, Rc(0, 3) k)
{
    return  ((VWWU_TYPE){QWZ_DUPW(v.V0, k)});
}

INLINE(Vwwf, FLT_DUPW) (float x)
{
    return  ((VWWF_TYPE){x});
}

INLINE(Vwwf, FLT_DUPWAC) (void const *a)
{
    return  ((VWWF_TYPE){((WORD_TYPE const *) a)->M.F});
}

INLINE(Vwwf,VWWF_DUPW) (Vwwf v, int const k) {return v;}

INLINE(Vwwf,VDWF_DUPW) (Vdwf v, Rc(0, 1) k)
{
    return  ((VWWF_TYPE){DWR_DUPW(v.V0, k)});
}

INLINE(Vwwf,VQWF_DUPW) (Vqwf v, Rc(0, 3) k)
{
    __m128i z = _mm_castpd_si128(v);
    return  ((VWWF_TYPE){QWZ_DUPW(z, k)});
}

#if 0 // _LEAVE_X86_DUPW
}
#endif

#if 0 // _ENTER_X86_DUPD
{
#endif

#define dupdbz(X) _mm_cvtsd_f64(_mm_castsi128_pd(_mm_set1_epi8(X)))
#define dupdhz(X) _mm_cvtsd_f64(_mm_castsi128_pd(_mm_set1_epi16(X)))
#define dupdwz(X) _mm_cvtsd_f64(_mm_castsi128_pd(_mm_set1_epi32(X)))

#define WBR_DUPD(V, K)          \
_mm_cvtsd_f64(                  \
    _mm_castsi128_pd(           \
        _mm_shuffle_epi8(       \
            _mm_castps_si128(   \
                _mm_set_ss(V)   \
            ),                  \
            _mm_set1_epi8(K)    \
        )                       \
    )                           \
)

#define DBR_DUPD(V, K)          \
_mm_cvtsd_f64(                  \
    _mm_castsi128_pd(           \
        _mm_shuffle_epi8(       \
            _mm_castpd_si128(   \
                _mm_set_sd(V)   \
            ),                  \
            _mm_set1_epi8(K)    \
        )                       \
    )                           \
)

#define QBZ_DUPD(V, K)          \
_mm_cvtsd_f64(                  \
    _mm_castsi128_pd(           \
        _mm_shuffle_epi8(       \
            V,                  \
            _mm_set1_epi8(K)    \
        )                       \
    )                           \
)


#define WHR_DUPD(V, K)                  \
_mm_cvtsd_f64(                          \
    _mm_castsi128_pd(                   \
        _mm_shuffle_epi8(               \
            _mm_castps_si128(           \
                _mm_set_ss(V)           \
            ),                          \
            _mm_add_epi8(               \
                _mm_set1_epi8((2*K)),   \
                _mm_set1_epi16(0x0100)  \
            )                           \
        )                               \
    )                                   \
)

#define DHR_DUPD(V, K)                  \
_mm_cvtsd_f64(                          \
    _mm_castsi128_pd(                   \
        _mm_shuffle_epi8(               \
            _mm_castpd_si128(           \
                _mm_set_sd(V)           \
            ),                          \
            _mm_add_epi8(               \
                _mm_set1_epi8((2*K)),   \
                _mm_set1_epi16(0x0100)  \
            )                           \
        )                               \
    )                                   \
)

#define QHZ_DUPD(V, K)                  \
_mm_cvtsd_f64(                          \
    _mm_castsi128_pd(                   \
        _mm_shuffle_epi8(               \
            V,                          \
            _mm_add_epi8(               \
                _mm_set1_epi8((2*K)),   \
                _mm_set1_epi16(0x0100)  \
            )                           \
        )                               \
    )                                   \
)


INLINE(double,dupdacwr_DUPDAC) (void const *a)
{
/*
TODO: see if _mm_load1_ps can be used instead 
*/
    __m128  w = _mm_load_ss(a);
    float   f = _mm_cvtss_f32(w);
    w = _mm_set1_ps(f);
    __m128d d = _mm_castps_pd(w);
    return  _mm_cvtsd_f64(d);
}

#define     dupddz(X) _mm_cvtsd_f64(_mm_castsi128_pd(_mm_set_epi64x(0,X)))

INLINE(double,dupdacdr) (void const *a)
{
    return  _mm_cvtsd_f64(_mm_load_sd(a));
}


#define DWR_DUPD(V, K)                      \
_mm_cvtsd_f64(                              \
    _mm_castsi128_pd(                       \
        _mm_shuffle_epi8(                   \
            _mm_castpd_si128(               \
                _mm_set_sd(V)               \
            ),                              \
            _mm_add_epi8(                   \
                _mm_set1_epi8((4*K)),       \
                _mm_set1_epi32(0x03020100)  \
            )                               \
        )                                   \
    )                                       \
)

#define QWZ_DUPD(V, K)                      \
_mm_cvtsd_f64(                              \
    _mm_castsi128_pd(                       \
        _mm_shuffle_epi8(                   \
            V,                              \
            _mm_add_epi8(                   \
                _mm_set1_epi8((4*K)),       \
                _mm_set1_epi32(0x03020100)  \
            )                               \
        )                                   \
    )                                       \
)

INLINE(double,WWR_DUPD) (float v)
{
    __m128  w = _mm_set1_ps(v);
    __m128d d = _mm_castps_pd(w);
    return  _mm_cvtsd_f64(d);
}

INLINE(double,dupdacdr) (void const *a) 
{
    return  _mm_cvtsd_f64(_mm_load_sd(a));
}

#define     QDZ_DUPD(V, K) \
_mm_cvtsd_f64(_mm_castsi128_pd(_mm_bsrli_si128(V,(8*K))))

#define     QDF_DUPD(V, K) QDZ_DUPD(_mm_castpd_si128(V),K)

#define     QDZ_DUPD2(V, K)                 \
_mm_cvtsd_f64(                              \
    _mm_castsi128_pd(                       \
        _mm_shuffle_epi8(                   \
            V,                              \
            _mm_add_epi8(                   \
                _mm_set1_epi8((1&K)),       \
                _mm_set_epi64x(             \
                    0,                      \
                    0x0706050403020100ULL   \
                )                           \
            )                               \
        )                                   \
    )                                       \
)

#define     QDF_DUPD2(V, K)  QDZ_DUPD2(_mm_castpd_si128(V),K)


INLINE(Vdyu,BOOL_DUPD) (_Bool x)
{
    return  ((VDYU_TYPE){((DWRD_TYPE){.U=0ULL-x}).F});
}

INLINE(Vdyu,BOOL_DUPDAC) (void const *a)
{
#define     BOOL_DUPDAC(A)   BOOL_DUPD((*(_Bool const *) A))
    return  BOOL_DUPDAC(a);
}

INLINE(Vdyu,VWYU_DUPD) (Vwyu v, Rc(0, 31) k)
{
    DWRD_TYPE z = {.W0.F=v.V0};
    z.U = -(1ULL&(z.U>>k));
    return  ((VDYU_TYPE){z.F});
}

INLINE(Vdyu,VDYU_DUPD) (Vdyu v, Rc(0, 63) k)
{
    DWRD_TYPE z = {.F=v.V0};
    if (1&(z.U>>k)) z.I =-1;
    else            z.I = 0;
    return  ((VDYU_TYPE){z.F});
}

INLINE(Vdyu,VQYU_DUPD) (Vqyu v, Rc(0,127) k)
{
    if (k > 64)
    {
        v = _mm_bsrli_si128(v, 8);
        k = k-64;
    }
    v = _mm_srl_epi64(v, _mm_cvtsi64_si128(k));
    v = _mm_and_si128(v, _mm_set_epi64x(0, 1));
    v = _mm_sub_epi64(_mm_setzero_si128(), v);
    __m128d f = _mm_castsi128_pd(v);
    double  m = _mm_cvtsd_f64(f);
    return  ((VDYU_TYPE){m});
}



INLINE(Vdbu,UCHAR_DUPD) (uchar x)
{
#define     UCHAR_DUPD(X) ((VDBU_TYPE){dupdbz(X)})
    return  UCHAR_DUPD(x);
}

INLINE(Vdbu,UCHAR_DUPDAC) (void const *a)
{
    return  UCHAR_DUPD((*(uchar const *) a));
}

INLINE(Vdbu,VWBU_DUPD) (Vwbu v, Rc(0, 3) k)
{
    return  ((VDBU_TYPE){WBR_DUPD(v.V0, k)});
}

INLINE(Vdbu,VDBU_DUPD) (Vdbu v, Rc(0, 7) k)
{
    return  ((VDBU_TYPE){DBR_DUPD(v.V0, k)});
}

INLINE(Vdbu,VQBU_DUPD) (Vqbu v, Rc(0, 15) k)
{
    return  ((VDBU_TYPE){QBZ_DUPD(v.V0, k)});
}


INLINE(Vdbi,SCHAR_DUPD) (schar x)
{
#define     SCHAR_DUPD(X) ((VDBI_TYPE){dupdbz(X)})
    return  SCHAR_DUPD(x);
}


INLINE(Vdbi,SCHAR_DUPDAC) (void const *a)
{
    return  SCHAR_DUPD((*(schar const *) a));
}

INLINE(Vdbi,VWBI_DUPD) (Vwbi v, Rc(0, 3) k)
{
    return  ((VDBI_TYPE){WBR_DUPD(v.V0, k)});
}

INLINE(Vdbi,VDBI_DUPD) (Vdbi v, Rc(0, 7) k)
{
    return  ((VDBI_TYPE){DBR_DUPD(v.V0, k)});
}

INLINE(Vdbi,VQBI_DUPD) (Vqbi v, Rc(0, 15) k)
{
    return  ((VDBI_TYPE){QBZ_DUPD(v.V0, k)});
}


INLINE(Vdbc,CHAR_DUPD) (char x)
{
#define     CHAR_DUPD(X) ((VDBC_TYPE){dupdbz(X)})
    return  CHAR_DUPD(x);
}

INLINE(Vdbc,CHAR_DUPDAC) (void const *a)
{
    return  CHAR_DUPD((*(char const *) a));
}

INLINE(Vdbc,VWBC_DUPD) (Vwbc v, Rc(0, 3) k)
{
    return  ((VDBC_TYPE){WBR_DUPD(v.V0, k)});
}

INLINE(Vdbc,VDBC_DUPD) (Vdbc v, Rc(0, 7) k)
{
    return  ((VDBC_TYPE){DBR_DUPD(v.V0, k)});
}

INLINE(Vdbc,VQBC_DUPD) (Vqbc v, Rc(0, 15) k)
{
    return  ((VDBC_TYPE){QBZ_DUPD(v.V0, k)});
}


INLINE(Vdhu,USHRT_DUPD) (ushort x)
{
#define     USHRT_DUPD(X) ((VDHU_TYPE){dupdhz(X)})
    return  USHRT_DUPD(x);
}

INLINE(Vdhu,USHRT_DUPDAC) (void const *a)
{
    return  USHRT_DUPD( (*(ushort const *) a) );
}

INLINE(Vdhu,VWHU_DUPD) (Vwhu v, Rc(0, 1) b)
{
    return  ((VDHU_TYPE){WHR_DUPD(v.V0, k)});
}

INLINE(Vdhu,VDHU_DUPD) (Vdhu v, Rc(0, 3) k)
{
    return  ((VDHU_TYPE){DHR_DUPD(v.V0, k)});
}

INLINE(Vdhu,VQHU_DUPD) (Vqhu v, Rc(0, 7) k)
{
    return  ((VDHU_TYPE){QHZ_DUPD(v.V0, k)});
}


INLINE(Vdhi,SHRT_DUPD) (short x)
{
#define     SHRT_DUPD(X) ((VDHI_TYPE){dupdhz(X)})
    return  SHRT_DUPD(x);
}

INLINE(Vdhi,SHRT_DUPDAC) (void const *a)
{
    return  SHRT_DUPD( (*(short const *) a) );
}

INLINE(Vdhi,VWHI_DUPD) (Vwhi v, Rc(0, 1) k)
{
    return  ((VDHI_TYPE){WHR_DUPD(v.V0, k)});
}

INLINE(Vdhi,VDHI_DUPD) (Vdhi v, Rc(0, 3) k)
{
    return  ((VDHI_TYPE){DHR_DUPD(v.V0, k)});
}

INLINE(Vdhi,VQHI_DUPD) (Vqhi v, Rc(0, 7) k)
{
    return  ((VDHI_TYPE){QHH_DUPD(v.V0, k)});
}



INLINE(Vdwu,UINT_DUPD) (uint x)
{
#define     UINT_DUPD(X) ((VDWU_TYPE){dupdwz(X)})
    return  UINT_DUPD(x);
}

INLINE(Vdwu,UINT_DUPDAC) (void const *a)
{
    return  ((VDWU_TYPE){dupdacwr(a)});
}


INLINE(Vdwu,VWWU_DUPD) (Vwwu v, Rc(0, 0) k) 
{
    return  ((VDWU_TYPE){WWR_DUPD(v.V0)});
}

INLINE(Vdwu,VDWU_DUPD) (Vdwu v, Rc(0, 1) k)
{
    return  ((VDWU_TYPE){DWR_DUPD(v.V0, k)});
}

INLINE(Vdwu,VQWU_DUPD) (Vqwu v, Rc(0, 3) k)
{
    return  ((VDWU_TYPE){QWZ_DUPD(v.V0, k)});
}


INLINE(Vdwi,INT_DUPD) (int x)
{
#define     INT_DUPD(X) ((VDWI_TYPE){dupdwz(X)})
    return  INT_DUPD(x);
}

INLINE(Vdwi,INT_DUPDAC) (void const *a)
{
    return  ((VDWI_TYPE){dupdacwr(a)});
}

INLINE(Vdwi,VWWI_DUPD) (Vwwi v, Rc(0, 0) k) 
{
    return  ((VDWI_TYPE){WWR_DUPD(v.V0)});
}

INLINE(Vdwi,VDWI_DUPD) (Vdwi v, Rc(0, 1) k)
{
    return  ((VDWI_TYPE){DWR_DUPD(v.V0, k)});
}

INLINE(Vdwi,VQWI_DUPD) (Vqwi v, Rc(0, 3) k)
{
    return  ((VDWI_TYPE){QWZ_DUPD(v.V0, k)});
}


#if DWRD_NLONG == 2

INLINE(Vdwu,ULONG_DUPD) (ulong x)
{
#define     ULONG_DUPD(X) ((VDWU_TYPE){dupdwz(X)})
    return  ULONG_DUPD(x);
}

INLINE(Vdwu,ULONG_DUPDAC) (void const *a)
{
    return  ((VDWU_TYPE){dupdacwr(a)});
}

INLINE(Vdwi,LONG_DUPD) (long x)
{
#define     LONG_DUPD(X) ((VDWI_TYPE){dupdwz(X)})
    return  LONG_DUPD(x);
}

INLINE(Vdwi,LONG_DUPDAC) (void const *a)
{
    return  ((VDWI_TYPE){dupdacwr(a)});
}

#else

INLINE(Vddu,ULONG_DUPD) (ulong x) 
{
    return ((VDDU_TYPE){dupddz(x)});
}

INLINE(Vddu,ULONG_DUPDAC) (void const *a) 
{
    return ((VDDU_TYPE){dupdacdr(a)});
}

INLINE(Vddi, LONG_DUPD)  (long x) 
{
    return ((VDDI_TYPE){dupddz(x)});
}

INLINE(Vddi, LONG_DUPDAC) (void const *a) 
{
    return ((VDDI_TYPE){dupdacdr(a)});
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vddu,ULLONG_DUPD) (ullong x) 
{
    return ((VDDU_TYPE){dupddz(x)});
}

INLINE(Vddu,ULLONG_DUPDAC) (void const *a) 
{
    return ((VDDU_TYPE){dupdacdr(a)});
}


INLINE(Vddi, LLONG_DUPD)  (llong x) 
{
    return ((VDDI_TYPE){dupddz(x)});
}

INLINE(Vddi, LLONG_DUPDAC) (void const *a) 
{
    return ((VDDI_TYPE){dupdacdr(a)});
}

#endif


INLINE(Vddu,VDDU_DUPD) (Vddu v, Rc(0, 0) k) {return v;}

INLINE(Vddu,VQDU_DUPD) (Vqdu v, Rc(0, 1) k)
{
#define     VQDU_DUPD(V, K) ((VDDU_TYPE){QDZ_DUPD(V.V0,(1&K))})
    return  ((VQDU_TYPE){QDZ_DUPD2(v.V0, k)});
}

INLINE(Vddi,VDDI_DUPD) (Vddi v, Rc(0, 0) k) {return v;}

INLINE(Vddi,VQDI_DUPD) (Vqdi v, Rc(0, 1) k)
{
#define     VQDI_DUPD(V, K) ((VDDI_TYPE){QDZ_DUPD(V.V0,(1&K))})
    return  ((VQDI_TYPE){QDZ_DUPD2(v.V0, k)});
}


INLINE(Vdhf,FLT16_DUPD) (flt16_t x)
{
#if defined(SPC_X86_FP16)
#   define  FLT16_DUPD(X) \
((VDHF_TYPE){_mm_cvtsd_f64(_mm_castph_pd(_mm_set1_ph(X)))})

#else
#   define  FLT16_DUPD(X) ((VDHF_TYPE){0.0f})
#endif

    return  FLT16_DUPD(x);
}

INLINE(Vdhf,FLT16_DUPDAC) (void const *a)
{
    return  FLT16_DUPD( (*(flt16_t const *) a) );
}

INLINE(Vdhf,VWHF_DUPD) (Vwhf v, Rc(0, 1) k)
{
    return  ((VDHF_TYPE){WHR_DUPD(v.V0, k)});
}

INLINE(Vdhf,VDHF_DUPD) (Vdhf v, Rc(0, 3) k)
{
    return  ((VDHF_TYPE){DHR_DUPD(v.V0, k)});
}

INLINE(Vdhf,VQHF_DUPD) (Vqhf v, Rc(0, 7) k)
{
    __m128i z;
#if defined(SPC_X86_FP16)
    z = _mm_castph_si128(v);
#else
    z = v.V0;
#endif

    return  QHZ_DUPD(z, k);
}


INLINE(Vdwf, FLT_DUPD) (float x)
{
#define     FLT_DUPD(X) \
((VDWF_TYPE){_mm_cvtsd_f64(_mm_castps_pd(_mm_set1_ps(X)))})

    return  FLT_DUPD(x);
}

INLINE(Vdwf, FLT_DUPDAC) (void const *a)
{
    return  ((VDWF_TYPE){dupdacwr(a)});
}


INLINE(Vdwf,VWWF_DUPD) (Vwwf v, Rc(0, 0) k)
{
    return  ((VDWF_TYPE){WWR_DUPD(v.V0)});
}


INLINE(Vdwf,VDWF_DUPD) (Vdwf v, Rc(0, 1) k)
{
    return  ((VDWF_TYPE){DWR_DUPD(v.V0, k)});
}

INLINE(Vdwf,VQWF_DUPD) (Vqwf v, Rc(0, 3) k)
{
    __m128i z = _mm_castpd_si128(v);
    return  ((VDWF_TYPE){QWZ_DUPD(z, k)});
}


INLINE(Vddf, DBL_DUPD)  (double x) 
{
    return ((VDDF_TYPE){x});
}

INLINE(Vddf, DBL_DUPDAC) (void const *a) 
{
    return ((VDDF_TYPE){dupdacdr(a)});
}

INLINE(Vddf,VDDF_DUPD) (Vddf v, Rc(0, 0) k) {return v;}

INLINE(Vddf,VQDF_DUPD) (Vqdf v, Rc(0, 1) k)
{
#define     VQDF_DUPD(V, K) ((VDDF_TYPE){QDF_DUPD(V,(1&K))})
    return  ((VQDU_TYPE){QDZ_DUPD2(v, k)});
}


#if 0 // _LEAVE_X86_DUPD
}
#endif

#if 0 // _ENTER_X86_DUPQ
{
#endif

#define     dupqbz  _mm_set1_epi8
#define     dupqacbz(A) _mm_set1_epi8( *((char const *) A) )

#define     dupqhz  _mm_set1_epi16
#define     dupqachz(A)                 \
_mm_shuffle_epi8(                       \
    _mm_loadu_si16(((void const *) A)), \
    _mm_set1_epi16(0x0100)              \
)

#define     dupqwz  _mm_set1_epi32
#define     dupqacwz(A)                 \
_mm_shuffle_epi8(                       \
    _mm_loadu_si32(((void const *) A)), \
    _mm_set1_epi32(0x03020100)          \
)

#define     dupqdz  _mm_set1_epi64x
#define     dupqacdz(X)                     \
_mm_shuffle_epi8(                           \
    _mm_loadu_si64(((void const *) A)),     \
    _mm_set1_epi64x(0x0706050403020100LL)   \
)

#define WBR_DUPQ(V, K)  \
_mm_shuffle_epi8(_mm_castps_si128(_mm_set_ss(V)),_mm_set1_epi8(K))

#define WHZ_DUPQ(V, K)          \
_mm_shuffle_epi8(               \
    _mm_castps_si128(           \
        _mm_set_ss(V)           \
    ),                          \
    _mm_add_epi8(               \
        _mm_set1_epi8((2*K)),   \
        _mm_set1_epi16(0x0100)  \
    )                           \
)

#define WWZ_DUPQ(V, ...)    _mm_castps_si128(_mm_set1_ps(V))
#define WWF_DUPQ(V, ...)    _mm_set1_ps(V)

#define     DBR_DUPQ(V, K)      \
_mm_shuffle_epi8(_mm_castpd_si128(_mm_set_sd(V)),_mm_set1_epi8(K))

#define     DHR_DUPQ(V, K)      \
_mm_shuffle_epi8(               \
    _mm_castpd_si128(           \
        _mm_set_sd(V)           \
    ),                          \
    _mm_add_epi8(               \
        _mm_set1_epi8((2*K)),   \
        _mm_set1_epi16(0x0100)  \
    )                           \
)

#define     DWZ_DUPQ(V, K)          \
_mm_shuffle_epi8(                   \
    _mm_castpd_si128(               \
        _mm_set_sd(V)               \
    ),                              \
    _mm_add_epi8(                   \
        _mm_set1_epi8((2*K)),       \
        _mm_set1_epi32(0x03020100)  \
    )                               \
)

#define     DDZ_DUPQ(V, ...)    _mm_castpd_si128(_mm_set1_pd(V))
#define     DDF_DUPQ(V, ...)    _mm_set1_pd(V)

#define     QBZ_DUPQ(V, K) _mm_shuffle_epi8(V,_mm_set1_epi8(K))

#define     QHZ_DUPQ(V, K)      \
_mm_shuffle_epi8(               \
    V,                          \
    _mm_add_epi8(               \
        _mm_set1_epi8((2*K)),   \
        _mm_set1_epi16(0x0100)  \
    )                           \
)

#define     QWZ_DUPQ(V, K) \
_mm_shuffle_epi32(V,(((3&B)<<6)|((3&B)<<4)|((3&B)<<2)|(3&B)))

#define     QWZ_DUPQ2(V, K)         \
_mm_shuffle_epi8(                   \
    V,                              \
    _mm_add_epi8(                   \
        _mm_set1_epi8((4*K)),       \
        _mm_set1_epi32(0x03020100)  \
    )                               \
)

#define     QWF_DUPQ(V, K)              \
_mm_castsi128_ps(                       \
    _mm_shuffle_epi8(                   \
        _mm_castps_si128(V),            \
        _mm_add_epi8(                   \
            _mm_set1_epi8((4*K)),       \
            _mm_set1_epi32(0x03020100)  \
        )                               \
    )                                   \
)

#define QDZ_DUPQ(V, K) \
_mm_castpd_si128(_mm_movedup_pd(_mm_castsi128_pd(_mm_bsrli_si128(V,(8*K)))))

#define QDZ_DUPQ2(V, K)                         \
_mm_shuffle_epi8(                               \
    V,                                          \
    _mm_add_epi8(                               \
        _mm_set1_epi8((8*K)),                   \
        _mm_set1_epi64x(0x0706050403020100LL)   \
    )                                           \
)



INLINE(Vqyu,BOOL_DUPQ) (_Bool x)
{
    double m = BOOL_DUPD(x).V0;
    return  _mm_castpd_si128(_mm_set_pd(m, m));
}

INLINE(Vqyu,BOOL_DUPQAC) (void const *a)
{
#define     BOOL_DUPQAC(A)   BOOL_DUPQ((*(_Bool const *) A))
    return  BOOL_DUPQAC(a);
}

INLINE(Vqyu,VWYU_DUPQ) (Vwyu v, Rc(0, 31) k)
{
    DWRD_TYPE z = {.W0.F=v.V0};
    z.U = -(1ULL&(z.U>>k));
    return  _mm_castpd_si128(_mm_set_pd(z.F, z.F));
}

INLINE(Vqyu,VDYU_DUPQ) (Vdyu v, Rc(0, 63) k)
{
    DWRD_TYPE z = {.F=v.V0};
    if (1&(z.U>>k)) z.I =-1;
    else            z.I = 0;
    return  _mm_castpd_si128(_mm_set_pd(z.F, z.F));
}

INLINE(Vqyu,VQYU_DUPQ) (Vqyu v, Rc(0,127) k)
{
    if (k > 64)
    {
        v = _mm_bsrli_si128(v, 8);
        k = k-64;
    }
    v = _mm_srl_epi64(v, _mm_cvtsi64_si128(k));
    v = _mm_and_si128(v, _mm_set_epi64x(0, 1));
    v = _mm_sub_epi64(_mm_setzero_si128(), v);
    __m128d f = _mm_castsi128_pd(v);
    f = _mm_movedup_pd(f);
    return  _mm_castpd_si128(f);
}


INLINE(Vqbu,UCHAR_DUPQ) (uchar x)
{
#define     UCHAR_DUPQ(X) ((VQBU_TYPE){_mm_set1_epi8(X)})
    return  UCHAR_DUPQ(x);
}

INLINE(Vqbu,UCHAR_DUPQAC) (void const *a)
{
    return  ((VQBU_TYPE){dupqacbz(a)});
}

INLINE(Vqbu,VWBU_DUPQ) (Vwbu v, Rc(0, 3) k)
{
    return  ((VDBU_TYPE){WBR_DUPQ(v.V0, k)});
}

INLINE(Vqbu,VDBU_DUPQ) (Vdbu v, Rc(0, 7) k)
{
    return  ((VDBU_TYPE){DBR_DUPQ(v.V0, k)});
}

INLINE(Vqbu,VQBU_DUPQ) (Vqbu v, Rc(0, 15) k)
{
    return  ((VDBU_TYPE){QBZ_DUPQ(v.V0, k)});
}


INLINE(Vqbi,SCHAR_DUPQ) (schar x)
{
#define     SCHAR_DUPQ(X) ((VQBU_TYPE){_mm_set1_epi8(X)})
    return  SCHAR_DUPQ(x);
}


INLINE(Vqbi,SCHAR_DUPQAC) (void const *a)
{
    return  ((VQBI_TYPE){dupqacbz(a)});
}

INLINE(Vqbi,VWBI_DUPQ) (Vwbi v, Rc(0, 3) k)
{
    return  ((VQBI_TYPE){WBR_DUPQ(v.V0, k)});
}

INLINE(Vqbi,VQBI_DUPQ) (Vdbi v, Rc(0, 7) k)
{
    return  ((VQBI_TYPE){DBR_DUPQ(v.V0, k)});
}

INLINE(Vqbi,VQBI_DUPQ) (Vqbi v, Rc(0, 15) k)
{
    return  ((VDBI_TYPE){QBZ_DUPQ(v.V0, k)});
}


INLINE(Vqbc,CHAR_DUPQ) (char x)
{
#define     CHAR_DUPQ(X) ((VQBC_TYPE){_mm_set1_epi8(X)})
    return  CHAR_DUPQ(x);
}

INLINE(Vqbc,CHAR_DUPQAC) (void const *a)
{
    return  ((VQBC_TYPE){dupqacbz(a)});
}

INLINE(Vqbc,VWBC_DUPQ) (Vwbc v, Rc(0, 3) k)
{
    return  ((VDBC_TYPE){WBR_DUPQ(v.V0, k)});
}

INLINE(Vqbc,VDBC_DUPQ) (Vdbc v, Rc(0, 7) k)
{
    return  ((VDBC_TYPE){DBR_DUPQ(v.V0, k)});
}

INLINE(Vqbc,VQBC_DUPQ) (Vqbc v, Rc(0, 15) k)
{
    return  ((VDBC_TYPE){QBZ_DUPQ(v.V0, k)});
}


INLINE(Vqhu,USHRT_DUPQ) (ushort x)
{
#define     USHRT_DUPQ(X) ((VQHU_TYPE){_mm_set1_epi16(X)})
    return  USHRT_DUPQ(x);
}

INLINE(Vqhu,USHRT_DUPQAC) (void const *a)
{
    return  ((VQHU_TYPE){dupqachz(a)});
}

INLINE(Vqhu,VWHU_DUPQ) (Vwhu v, Rc(0, 1) b)
{
    return  ((VQHU_TYPE){WHZ_DUPQ(v.V0, k)});
}

INLINE(Vqhu,VDHU_DUPQ) (Vdhu v, Rc(0, 3) k)
{
    return  ((VQHU_TYPE){DHR_DUPQ(v.V0, k)});
}

INLINE(Vqhu,VQHU_DUPQ) (Vqhu v, Rc(0, 7) k)
{
    return  ((VQHU_TYPE){QHZ_DUPQ(v.V0, k)});
}


INLINE(Vqhi,SHRT_DUPQ) (short x)
{
#define     SHRT_DUPQ(X) ((VQHI_TYPE){_mm_set1_epi16(X)})
    return  SHRT_DUPQ(x);
}

INLINE(Vqhi,SHRT_DUPQAC) (void const *a)
{
    return  ((VQHI_TYPE){dupqachz(a)});
}

INLINE(Vqhi,VWHI_DUPQ) (Vwhi v, Rc(0, 1) k)
{
    return  ((VQHI_TYPE){WHZ_DUPQ(v.V0, k)});
}

INLINE(Vqhi,VDHI_DUPQ) (Vdhi v, Rc(0, 3) k)
{
    return  ((VQHI_TYPE){DHR_DUPQ(v.V0, k)});
}

INLINE(Vqhi,VQHI_DUPQ) (Vqhi v, Rc(0, 7) k)
{
    return  ((VQHI_TYPE){QHZ_DUPQ(v.V0, k)});
}



INLINE(Vqwu,UINT_DUPQ) (uint x)
{
#define     UINT_DUPQ(X) ((VQWU_TYPE){dupqwz(X)})
    return  UINT_DUPQ(x);
}

INLINE(Vqwu,UINT_DUPQAC) (void const *a)
{
    return  ((VQWU_TYPE){dupqacwr(a)});
}


INLINE(Vqwu,VWWU_DUPQ) (Vwwu v, Rc(0, 0) k) 
{
    return  ((VQWU_TYPE){WWZ_DUPQ(v.V0, k)});
}

INLINE(Vqwu,VDWU_DUPQ) (Vdwu v, Rc(0, 1) k)
{
    return  ((VQWU_TYPE){DWZ_DUPQ(v.V0, k)});
}

INLINE(Vqwu,VQWU_DUPQ) (Vqwu v, Rc(0, 3) k)
{
#define     VQWU_DUPQ(V, K) ((VQWU_TYPE){QWZ_DUPQ(V.V0,K)})
    return  ((VQWU_TYPE){QWZ_DUPQ2(v.V0, k)});
}


INLINE(Vqwi,INT_DUPQ) (int x)
{
#define     INT_DUPQ(X) ((VQWI_TYPE){dupqwz(X)})
    return  INT_DUPQ(x);
}

INLINE(Vqwi,INT_DUPQAC) (void const *a)
{
    return  ((VQWI_TYPE){dupqacwr(a)});
}

INLINE(Vqwi,VWWI_DUPQ) (Vwwi v, Rc(0, 0) k) 
{
    return  ((VQWI_TYPE){WWZ_DUPQ(v.V0, k)});
}

INLINE(Vqwi,VDWI_DUPQ) (Vdwi v, Rc(0, 1) k)
{
    return  ((VQWI_TYPE){DWZ_DUPQ(v.V0, k)});
}

INLINE(Vqwi,VQWI_DUPQ) (Vqwi v, Rc(0, 3) k)
{
#define     VQWI_DUPQ(V, K) ((VQWI_TYPE){QWZ_DUPQ(V.V0,K)})
    return  ((VQWI_TYPE){QWZ_DUPQ2(v.V0, k)});
}


#if DWRD_NLONG == 2

INLINE(Vqwu,ULONG_DUPQ) (ulong x)
{
#define     ULONG_DUPQ(X) ((VQWU_TYPE){dupqwz(X)})
    return  ULONG_DUPQ(x);
}

INLINE(Vqwu,ULONG_DUPQAC) (void const *a)
{
    return  ((VQWU_TYPE){dupqacwr(a)});
}


INLINE(Vqwi,LONG_DUPQ) (long x)
{
#define     LONG_DUPQ(X) ((VQWI_TYPE){dupqwz(X)})
    return  LONG_DUPQ(x);
}

INLINE(Vqwi,LONG_DUPQAC) (void const *a)
{
    return  ((VQWI_TYPE){dupqacwr(a)});
}

#else

INLINE(Vqdu,ULONG_DUPQ) (ulong x) 
{
    return ((VQDU_TYPE){dupqdz(x)});
}

INLINE(Vqdu,ULONG_DUPQAC) (void const *a) 
{
    return ((VQDU_TYPE){dupqacdr(a)});
}

INLINE(Vqdi, LONG_DUPQ)  (long x) 
{
    return ((VQDI_TYPE){dupqdz(x)});
}

INLINE(Vqdi, LONG_DUPQAC) (void const *a) 
{
    return ((VQDI_TYPE){dupqacdr(a)});
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vqdu,ULLONG_DUPQ) (ullong x) 
{
    return ((VQDU_TYPE){dupqdz(x)});
}

INLINE(Vqdu,ULLONG_DUPQAC) (void const *a) 
{
    return ((VQDU_TYPE){dupqacdr(a)});
}


INLINE(Vqdi, LLONG_DUPQ)  (llong x) 
{
    return ((VQDI_TYPE){dupqdz(x)});
}

INLINE(Vqdi, LLONG_DUPQAC) (void const *a) 
{
    return ((VQDI_TYPE){dupqacdr(a)});
}

#endif


INLINE(Vqdu,VDDU_DUPQ) (Vddu v, Rc(0, 0) k)
{
    return ((VQDU_TYPE){DDZ_DUPQ(v.V0, k)});
}

INLINE(Vqdu,VQDU_DUPQ) (Vqdu v, Rc(0, 1) k)
{
#define     VQDU_DUPQ(V, K) ((VQDU_TYPE){QDZ_DUPQ(V.V0,(1&K))})
    return  ((VQDU_TYPE){QDZ_DUPQ2(v.V0, k)});
}


INLINE(Vqdi,VDDI_DUPQ) (Vddi v, Rc(0, 0) k) 
{
    return ((VQDI_TYPE){DDZ_DUPQ(v.V0, k)});
}

INLINE(Vqdi,VQDI_DUPQ) (Vqdi v, Rc(0, 1) k)
{
#define     VQDI_DUPQ(V, K) ((VQDI_TYPE){QDZ_DUPQ(V.V0,(1&K))})
    return  ((VQDI_TYPE){QDZ_DUPQ2(v.V0, k)});
}


INLINE(Vqhf,FLT16_DUPQ) (flt16_t x)
{
#if defined(SPC_X86_FP16)
#   define  FLT16_DUPQ  _mm_set1_ph
#else
#   define  FLT16_DUPQ(X) ((VQHF_TYPE){0})
#endif

    return  FLT16_DUPQ(x);
}

INLINE(Vqhf,FLT16_DUPQAC) (void const *a)
{
    return  FLT16_DUPQ( (*(flt16_t const *) a) );
}

INLINE(Vqhf,VWHF_DUPQ) (Vwhf v, Rc(0, 1) k)
{
    __m128i z = WHZ_DUPQ(v.V0, k);
#if defined(SPC_X86_FP16)
    return  _mm_castsi128_ph(z);
#else
    return  ((VQHF_TYPE){z});
#endif
}

INLINE(Vqhf,VDHF_DUPQ) (Vdhf v, Rc(0, 3) k)
{
    __m128i z = DHR_DUPQ(v.V0, k);
#if defined(SPC_X86_FP16)
    return  _mm_castsi128_ph(z);
#else
    return  ((VQHF_TYPE){z});
#endif
}

INLINE(Vqhf,VQHF_DUPQ) (Vqhf v, Rc(0, 7) k)
{
    __m128i z;
#if defined(SPC_X86_FP16)
    z = _mm_castph_si128(v);
#else
    z = v.V0;
#endif

    z = QHZ_DUPQ(z, k);
#if defined(SPC_X86_FP16)
    return  _mm_castsi128_ph(z);
#else
    return  ((VQHF_TYPE){z});
#endif

}


INLINE(Vqwf, FLT_DUPQ) (float x)
{
#define     FLT_DUPQ _mm_set1_ps
    return  FLT_DUPQ(x);
}

INLINE(Vqwf, FLT_DUPQAC) (void const *a)
{
    __m128  f = _mm_load_ss(a);
    __m128i z = _mm_castps_si128(f);
    z = _mm_shuffle_epi32(z, 0);
    return  _mm_castsi128_ps(z);
}


INLINE(Vqwf,VWWF_DUPQ) (Vwwf v, Rc(0, 0) k)
{
    return  _mm_set1_ps(v.V0);
}


INLINE(Vqwf,VDWF_DUPQ) (Vdwf v, Rc(0, 1) k)
{
    __m128i z = DWR_DUPQ(v.V0, k);
    return _mm_castsi128_ps(z);
}

INLINE(Vqwf,VQWF_DUPQ) (Vqwf v, Rc(0, 3) k)
{
    __m128i z = _mm_castpd_si128(v);
    z = QWZ_DUPQ(z, k);
    return _mm_castsi128_ps(z);
}


INLINE(Vqdf, DBL_DUPQ)  (double x) 
{
    return  _mm_set1_pd(x);
}

INLINE(Vqdf, DBL_DUPQAC) (void const *a) 
{
    return  _mm_movedup_pd(_mm_load_sd(a));
}

INLINE(Vqdf,VDDF_DUPQ) (Vddf v, Rc(0, 0) k)
{
    return  _mm_set1_pd(v.V0);
}

INLINE(Vqdf,VQDF_DUPQ) (Vqdf v, Rc(0, 1) k)
{
#define     VQDF_DUPQ(V, K) \
_mm_movedup_pd(_mm_castsi128_pd(_mm_bsrli_si128(_mm_castpd_si128(V),(8*K))))    
    __m128i z = _mm_castpd_si128(v);
    z = QDZ_DUPQ2(z, k);
    return  _mm_castsi128_pd(z);
}

#if 0 // _LEAVE_X86_DUPQ
}
#endif



#if 0 // _ENTER_X86_GET1
{
#endif

INLINE(  _Bool, VWYU_GET1) (Vwyu a, Rc(0, 31) b)
{
#define     VWYU_GET1(A, B)  \
((_Bool) (1&(((WORD_TYPE){.F=A.V0}).U>>B)))

    return  VWYU_GET1(a, b);
}

INLINE(char,get1wbz) (float a, Rc(0, 3) b)
{
#define     get1wbz(A, B) \
_mm_extract_epi8(_mm_castps_si128(_mm_set_ss(A)),(3&B))

    __m128      f = _mm_set_ss(a);
    __m128i     z = _mm_castps_si128(f);
    unsigned    v = _mm_cvtsi128_si32(z);
    return  (v>>(8*b));
}

INLINE(uint16_t,get1whz) (float a, Rc(0, 1) b)
{
#define     get1whz(A, B) \
_mm_extract_epi16(_mm_castps_si128(_mm_set_ss(A)),(1&B))

    __m128      f = _mm_set_ss(a);
    __m128i     z = _mm_castps_si128(f);
    unsigned    v = _mm_cvtsi128_si32(z);
    return  (v>>(16*b));
}

INLINE( uint8_t,VWBU_GET1) (Vwbu a, Rc(0, 3) b)
{
#define     VWBU_GET1(A, B) ((uint8_t) get1wbz(A.V0,B))
    return  (get1wbz)(a.V0, b);
}

INLINE(  int8_t,VWBI_GET1) (Vwbi a, Rc(0, 3) b)
{
#define     VWBI_GET1(A, B) ((int8_t) get1wbz(A.V0,B))
    return  (get1wbz)(a.V0, b);
}

INLINE(    char,VWBC_GET1) (Vwbc a, Rc(0, 3) b)
{
#define     VWBC_GET1(A, B) ((char) get1wbz(A.V0,B))
    return  (get1wbz)(a.V0, b);
}


INLINE(uint16_t,VWHU_GET1) (Vwhu a, Rc(0, 1) b)
{
#define     VWHU_GET1(A, B) ((uint16_t) get1whz(A.V0,B))
    return  (get1whz)(a.V0, b);
}

INLINE( int16_t,VWHI_GET1) (Vwhi a, Rc(0, 1) b)
{
#define     VWHI_GET1(A, B) ((int16_t) get1whz(A.V0,B))
    return  (get1whz)(a.V0, b);
}

INLINE( flt16_t,VWHF_GET1) (Vwhf a, Rc(0, 1) b)
{
#define     VWHF_GET1(A, B) (((HALF_TYPE){.U=get1whz(A.V0,B)}).F)
    return ((HALF_TYPE){.U=(get1whz)(a.V0, b)}).F;
}


INLINE(  _Bool, VDYU_GET1) (Vdyu a, Rc(0, 63) b)
{
#define     VDYU_GET1(A, B)  \
((_Bool) (1&(((DWRD_TYPE){.F=A.V0}).U>>B)))

    return  VDYU_GET1(a, b);
}

INLINE(char,get1dbz) (double a, Rc(0, 7) b)
{
#define     get1dbz(A, B) \
_mm_extract_epi8(_mm_castpd_si128(_mm_set_sd(A)),(7&B))

    __m128d     f = _mm_set_sd(a);
    __m128i     z = _mm_castpd_si128(f);
    uint64_t    v = _mm_cvtsi128_si64(z);
    return  (v>>(8*b));
}

INLINE(uint16_t,get1dhz) (float a, Rc(0, 3) b)
{
#define     get1dhz(A, B) \
_mm_extract_epi16(_mm_castpd_si128(_mm_set_sd(A)),(3&B))

    __m128d     f = _mm_set_sd(a);
    __m128i     z = _mm_castps_si128(f);
    uint64_t    v = _mm_cvtsi128_si64(z);
    return  (v>>(16*b));
}

INLINE(uint32_t,get1dwz) (float a, Rc(0, 1) b)
{
#define     get1dwz(A, B) \
_mm_extract_epi32(_mm_castpd_si128(_mm_set_sd(A)),(1&B))

    __m128d     f = _mm_set_sd(a);
    __m128i     z = _mm_castps_si128(f);
    uint64_t    v = _mm_cvtsi128_si64(z);
    return  (v>>(32*b));
}


INLINE( uint8_t,VDBU_GET1) (Vdbu a, Rc(0, 7) b)
{
#define     VDBU_GET1(A, B) ((uint8_t) get1dbz(A.V0,B))
    return  (get1dbz)(a.V0, b);
}

INLINE(  int8_t,VDBI_GET1) (Vdbi a, Rc(0, 7) b)
{
#define     VDBI_GET1(A, B) ((int8_t) get1dbz(A.V0,B))
    return  (get1dbz)(a.V0, b);
}

INLINE(    char,VDBC_GET1) (Vdbc a, Rc(0, 7) b)
{
#define     VDBC_GET1(A, B) ((char) get1dbz(A.V0,B))
    return  (get1dbz)(a.V0, b);
}


INLINE(uint16_t,VDHU_GET1) (Vdhu a, Rc(0, 3) b)
{
#define     VDHU_GET1(A, B) ((uint16_t) get1dhz(A.V0,B))
    return  (get1dhz)(a.V0, b);
}

INLINE( int16_t,VDHI_GET1) (Vdhi a, Rc(0, 3) b)
{
#define     VDHI_GET1(A, B) ((int16_t) get1dhz(A.V0,B))
    return  (get1dhz)(a.V0, b);
}

INLINE( flt16_t,VDHF_GET1) (Vdhf a, Rc(0, 3) b)
{
#define     VDHF_GET1(A, B) (((HALF_TYPE){.U=get1dhz(A.V0,B)}).F)
    return  ((HALF_TYPE){.U=(get1dhz)(a.V0, b)}).F;
}


INLINE(uint32_t,VDWU_GET1) (Vdwu a, Rc(0, 1) b)
{
#define     VDWU_GET1(A, B) ((uint32_t) get1dwz(A.V0,B))
    return  (get1dwz)(a.V0, b);
}

INLINE( int32_t,VDWI_GET1) (Vdwi a, Rc(0, 1) b)
{
#define     VDWI_GET1(A, B) ((int32_t) get1dwz(A.V0,B))
    return  (get1dwz)(a.V0, b);
}

INLINE(   float,VDWF_GET1) (Vdwf a, Rc(0, 1) b)
{
#define     VDWF_GET1(A, B) (((WORD_TYPE){.U=get1dwz(A.V0,B)}).F)

    return  ((WORD_TYPE){.U=(get1dwz)(a.V0, b)}).F;
}



INLINE(char,get1qbz) (__m128i a, Rc(0, 15) b)
{
#define     get1qbz _mm_extract_epi8
    __m128i     t = _mm_set1_epi8(b);
    a = _mm_shuffle_epi8(a, t);
    uint64_t    v = _mm_cvtsi128_si64(a);
    return      UINT8_MAX&v;
}

INLINE(uint16_t,get1qhz) (__m128i a, Rc(0, 7) b)
{
#define     get1qhz _mm_extract_epi16
    __m128i     t = _mm_set1_epi8(b*2);
    __m128i     r = _mm_cvtsi32_si128(0x0100);
    t = _mm_add_epi8(t, r);
    a = _mm_shuffle_epi8(a, t);
    uint64_t    v = _mm_cvtsi128_si64(a);
    return      UINT16_MAX&v;
}

INLINE(uint32_t,get1qwz) (__m128i a, Rc(0, 3) b)
{
#define     get1qwz _mm_extract_epi32
    __m128i     t = _mm_set1_epi8(b*4);
    __m128i     r = _mm_cvtsi32_si128(0x03020100);
    t = _mm_add_epi8(t, r);
    a = _mm_shuffle_epi8(a, t);
    uint64_t    v = _mm_cvtsi128_si64(a);
    return      UINT32_MAX&v;
}

INLINE(uint64_t,get1qdz) (__m128i a, Rc(0, 1) b)
{
#define     get1qdz _mm_extract_epi64
    __m128i     t = _mm_set1_epi8(b*8);
    __m128i     r = _mm_cvtsi64_si128(0x0706050403020100LL);
    t = _mm_add_epi8(t, r);
    a = _mm_shuffle_epi8(a, t);
    uint64_t    v = _mm_cvtsi128_si64(a);
    return      UINT32_MAX&v;
}


INLINE(   _Bool,VQYU_GET1) (Vqyu a, Rc(0, 127) b)
{
#define     VQYU_GET1(A, B) \
((_Bool) (1&(_mm_cvtsi128_si32(_mm_bsrli_si128(A,(4*(B>>5))))>>(31&B))))

    __m128i t = _mm_cvtsi32_si128(b);
    t = _mm_slli_epi64(t, 3);   // divide lane by 8
    a = _mm_shuffle_epi8(a, t);
    return  1&(_mm_cvtsi128_si32(a)>>(7&b));
    
}


INLINE( uint8_t,VQBU_GET1) (Vqbu a, Rc(0, 15) b)
{
#define     VQBU_GET1(A, B) ((uint8_t) get1qbz(A.V0,B))
    return  (get1qbz)(a.V0, b);
}

INLINE(  int8_t,VQBI_GET1) (Vqbi a, Rc(0, 15) b)
{
#define     VQBI_GET1(A, B) ((int8_t) get1qbz(A.V0,B))
    return  (get1qbz)(a.V0, b);
}

INLINE(    char,VQBC_GET1) (Vqbc a, Rc(0, 15) b)
{
#define     VQBC_GET1(A, B) ((char) get1qbz(A.V0,B))
    return  (get1qbz)(a.V0, b);
}


INLINE(uint16_t,VQHU_GET1) (Vqhu a, Rc(0, 7) b)
{
#define     VQHU_GET1(A, B) ((uint16_t) get1qhz(A.V0,B))
    return  (get1qhz)(a.V0, b);
}

INLINE( int16_t,VQHI_GET1) (Vqhi a, Rc(0, 7) b)
{
#define     VQHI_GET1(A, B) ((int16_t) get1qhz(A.V0,B))
    return  (get1qhz)(a.V0, b);
}

INLINE( flt16_t,VQHF_GET1) (Vqhf a, Rc(0, 7) b)
{
    HALF_TYPE v;
#if defined(SPC_X86_FP16)
#   define  VQHF_GET1(A, B) \
(((HALF_TYPE){.U=get1qhz(_mm_castph_si128(A),B)}).F)

    v.U = (get1qhz)(_mm_castph_si128(a), b);
#else
#   define  VQHF_GET1(A, B) (((HALF_TYPE){.U=get1qhz(A,B)}).F)
    v.U = (get1qhz)(a.V0, b);
#endif

    return  v.F;
}


INLINE(uint32_t,VQWU_GET1) (Vqwu a, Rc(0, 3) b)
{
#define     VQWU_GET1(A, B) ((uint32_t) get1qwz(A.V0,B))
    return  (get1qwz)(a.V0, b);
}

INLINE( int32_t,VQWI_GET1) (Vqwi a, Rc(0, 3) b)
{
#define     VQWI_GET1(A, B) ((int32_t) get1qwz(A.V0,B))
    return  (get1qwz)(a.V0, b);
}

INLINE(   float,VQWF_GET1) (Vqwf a, Rc(0, 3) b)
{
#define     VQWF_GET1(A, B) \
(((WORD_TYPE){.U=get1qwz(_mm_castps_si128(A),B)}).F)
    return  ((WORD_TYPE){.U=(get1qwz)(_mm_castps_si128(a), b)}).F;
}


INLINE(uint64_t,VQDU_GET1) (Vqdu a, Rc(0, 1) b)
{
#define     VQDU_GET1(A, B) ((uint64_t) get1qdz(A.V0,B))
    return  (get1qdz)(a.V0, b);
}

INLINE( int64_t,VQDI_GET1) (Vqdi a, Rc(0, 1) b)
{
#define     VQDI_GET1(A, B) ((int64_t) get1qdz(A.V0,B))
    return  (get1qdz)(a.V0, b);
}

INLINE(  double,VQDF_GET1) (Vqdf a, Rc(0, 1) b)
{
#define     VQDF_GET1(A, B) \
(((DWRD_TYPE){.U=get1qdz(_mm_castpd_si128(A),B)}).F)
    return  ((DWRD_TYPE){.U=(get1qwz)(_mm_castpd_si128(a), b)}).F;
}


#if 0 // _LEAVE_X86_GET1
}
#endif


#if 0 //_X86_CV__
{
#endif

#if 0 // _ENTER_X86_CVB_
{
#endif

#if 0 // _ENTER_X86_CVBU
{
#endif

#if QUAD_NLLONG == 2
INLINE(uint8_t,cvbuqu) (QUAD_UTYPE x) {return x;}
INLINE(uint8_t,cvbuqi) (QUAD_ITYPE x) {return x;}
INLINE(uint8_t,cvbuqf) (QUAD_FTYPE x) {return x;}
#endif

INLINE(uint8_t,FLT16_CVBU) (flt16_t x) 
{
    return 0;
}
INLINE(uint8_t,  FLT_CVBU)   (float x) {return x;}
INLINE(uint8_t,  DBL_CVBU)  (double x) {return x;}

INLINE(Vwbu,VWBU_CVBU) (Vwbu x) {return x;}
INLINE(Vwbu,VWBI_CVBU) (Vwbi x) {return VWBI_ASBU(x);}
INLINE(Vwbu,VWBC_CVBU) (Vwbc x) {return VWBC_ASBU(x);}

INLINE(Vdbu,VDBU_CVBU) (Vdbu x) {return x;}
INLINE(Vdbu,VDBI_CVBU) (Vdbi x) {return VDBI_ASBU(x);}
INLINE(Vdbu,VDBC_CVBU) (Vdbc x) {return VDBC_ASBU(x);}

INLINE(float,DHZ_CVBU) (double x)
{
    __m128i v = _mm_castpd_si128(_mm_set_sd(x));
    v = _mm_shuffle_epi8(v, _mm_cvtsi64_si128(0x06040200ULL));
    return  _mm_cvtss_f32(_mm_castps_si128(v));
}

INLINE(Vwbu,VDHU_CVBU) (Vdhu x) {return ((Vwbu){DHZ_CVBU(x.V0)});}
INLINE(Vwbu,VDHI_CVBU) (Vdhi x) {return ((Vwbu){DHZ_CVBU(x.V0)});}
INLINE(Vwbu,VDHF_CVBU) (Vdhf x) 
{
#if defined(SPC_X86_FP16)
    __m128h f = _mm_castpd_ph(_mm_set_sd(x.V0));
    __m128i z = _mm_cvtph_epi16(f);
    __m128d v = _mm_castsi128_pd(z);
    double  m = _mm_cvtsd_f64(v);
    return  DHZ_CVBU(m);
#else
    return  (Vwbu){0};
#endif
}


INLINE(Vqbu,VQBU_CVBU) (Vqbu x) {return x;}
INLINE(Vqbu,VQBI_CVBU) (Vqbi x) {return VQBI_ASBU(x);}
INLINE(Vqbu,VQBC_CVBU) (Vqbc x) {return VQBC_ASBU(x);}


INLINE(double,QHZ_CVBU) (__m128i x)
{
    v = _mm_shuffle_epi8(v, _mm_cvtsi64_si128(0x0e0c0a0806040200ULL));
    return  _mm_cvtsd_f64(_mm_castps_si128(v));
}

INLINE(Vdbu,VQHU_CVBU) (Vqhu x) {return ((VDBU_TYPE){QHZ_CVBU(x.V0)});}
INLINE(Vdbu,VQHI_CVBU) (Vqhi x) {return ((VDBU_TYPE){QHZ_CVBU(x.V0)});}
INLINE(Vdbu,VQHF_CVBU) (Vqhf x) 
{
#if defined(SPC_X86_FP16)
    __m128i z = __mm_cvtph_epi16(x);
    __m128d v = _mm_castsi128_pd(z);
    return ((VDBU_TYPE){_mm_cvtsd_f64(v)});
#else
    return  (Vdbu){0};
#endif
}

INLINE(float,QWZ_CVBU) (__m128i x)
{
    x = _mm_shuffle_epi8(v, _mm_cvtsi64_si128(0x0c080400ULL));
    return  _mm_cvtss_f32(_mm_castsi128_ps(x));
}

INLINE(Vwbu,VQWU_CVBU) (Vqwu x) 
{
    return ((VWBU_TYPE){QWZ_CVBU(x.V0)});
}

INLINE(Vwbu,VQWI_CVBU) (Vqwi x) 
{
    return ((VWBU_TYPE){QWZ_CVBU(x.V0)});
}

INLINE(Vwbu,VQWF_CVBU) (Vqwf x) 
{
    return ((VWBU_TYPE){QWZ_CVBU(_mm_cvtps_epi32(x))});
}

#if 0 // _LEAVE_X86_CVBU
}
#endif


#if 0 // _ENTER_X86_CVBI
{
#endif
#if 0 // _LEAVE_X86_CVBI
}
#endif

#if 0 // _ENTER_X86_CVBZ
{
#endif
#if 0 // _LEAVE_X86_CVBZ
}
#endif

#if 0 // _ENTER_X86_CVBS
{
#endif
#if 0 // _LEAVE_X86_CVBS
}
#endif

#if 0 // _LEAVE_X86_CVB_
}
#endif

#if 0 // _ENTER_X86_CVH_
{
#endif

#if 0 // _ENTER_X86_CVHU
{
#endif
#if 0 // _LEAVE_X86_CVHU
}
#endif

#if 0 // _ENTER_X86_CVHI
{
#endif
#if 0 // _LEAVE_X86_CVHI
}
#endif

#if 0 // _ENTER_X86_CVHZ
{
#endif
#if 0 // _LEAVE_X86_CVHZ
}
#endif

#if 0 // _ENTER_X86_CVHS
{
#endif
#if 0 // _LEAVE_X86_CVHS
}
#endif

#if 0 // _LEAVE_X86_CVH_
}
#endif

#if 0 // _ENTER_X86_CVW_
{
#endif

#if 0 // _ENTER_X86_CVWU
{
#endif
#if 0 // _LEAVE_X86_CVWU
}
#endif

#if 0 // _ENTER_X86_CVWI
{
#endif
#if 0 // _LEAVE_X86_CVWI
}
#endif

#if 0 // _ENTER_X86_CVWZ
{
#endif
#if 0 // _LEAVE_X86_CVWZ
}
#endif

#if 0 // _ENTER_X86_CVWS
{
#endif
#if 0 // _LEAVE_X86_CVWS
}
#endif

#if 0 // _LEAVE_X86_CVW_
}
#endif

#if 0 // _ENTER_X86_CVD_
{
#endif

#if 0 // _ENTER_X86_CVDU
{
#endif
#if 0 // _LEAVE_X86_CVDU
}
#endif

#if 0 // _ENTER_X86_CVDI
{
#endif
#if 0 // _LEAVE_X86_CVDI
}
#endif

#if 0 // _ENTER_X86_CVDZ
{
#endif
#if 0 // _LEAVE_X86_CVDZ
}
#endif

#if 0 // _ENTER_X86_CVDS
{
#endif
#if 0 // _LEAVE_X86_CVDS
}
#endif

#if 0 // _LEAVE_X86_CVD_
}
#endif

#if 0 // _LEAVE_X86_CV__
}
#endif

#if 0 // _ENTER_X86_LUNWAC
{
#endif

INLINE(VWBU_MTYPE,ABU_LUNWAC) (uint8_t const a[4])
{
    return *(VWBU_MTYPE volatile const *) a;
}

INLINE(VWBI_MTYPE,ABI_LUNWAC) (int8_t const a[4])
{
    return *(VWBI_MTYPE volatile const *) a;
}

#if CHAR_SIGNEDNESS
INLINE(VWBI_MTYPE,ABC_LUNWAC) (char const a[4])
{
    return ABI_LUNWAC((void *) a);
}
#else
INLINE(VWBU_MTYPE,ABC_LUNWAC) (char const a[4])
{
    return ABU_LUNWAC((void *) a);
}
#endif

INLINE(VWHU_MTYPE,AHU_LUNWAC) (uint16_t a[2])
{
    return *(VWHU_MTYPE volatile const *) a;
}

INLINE(VWHI_MTYPE,AHI_LUNWAC) (int16_t a[2])
{
    return *(VWHI_MTYPE volatile const *) a;
}

INLINE(VWHF_MTYPE,AHF_LUNWAC) (flt16_t a[2])
{
    return *(VWHF_MTYPE volatile const *) a;
}


INLINE(VWWU_MTYPE,AWU_LUNWAC) (uint32_t a[1])
{
    return *(VWWU_MTYPE volatile const *) a;
}

INLINE(VWWI_MTYPE,AWI_LUNWAC) (int32_t a[1])
{
    return *(VWWI_MTYPE volatile const *) a;
}

INLINE(VWWF_MTYPE,AWF_LUNWAC) (float a[1])
{
    return *(VWWF_MTYPE volatile const *) a;
}

#if 0 // _LEAVE_X86_LUNWAC
}
#endif

#if 0 // _ENTER_X86_LDRW
{
#endif

#define     ABU_LDRW(a)     ((VWBU_TYPE){ABU_LUNWAC(a)})
#define     ABI_LDRW(a)     ((VWBI_TYPE){ABI_LUNWAC(a)})
#if CHAR_SIGNEDNESS
#   define  ABC_LDRW(a)     ((VWBI_TYPE){ABC_LUNWAC(a)})
#else
#   define  ABC_LDRW(a)     ((VWBU_TYPE){ABC_LUNWAC(a)})
#endif
#define     AHU_LDRW(a)     ((VWHU_TYPE){AHU_LUNWAC(a)})
#define     AHI_LDRW(a)     ((VWHI_TYPE){AHI_LUNWAC(a)})
#define     AHF_LDRW(a)     ((VWHF_TYPE){AHF_LUNWAC(a)})
#define     AWU_LDRW(a)     ((VWWU_TYPE){AWU_LUNWAC(a)})
#define     AWI_LDRW(a)     ((VWWI_TYPE){AWI_LUNWAC(a)})
#define     AWF_LDRW(a)     ((VWWF_TYPE){AWF_LUNWAC(a)})

#if 0 // _LEAVE_X86_LDRW
}
#endif

#if 0 // _ENTER_X86_LUNDAC
{
#endif

INLINE(VDBU_MTYPE,ABU_LUNDAC) (uint8_t const a[8])
{
    return *(VDBU_MTYPE const *) a;
}

INLINE(VDBI_MTYPE,ABI_LUNDAC) (int8_t const a[8])
{
    return *(VDBI_MTYPE const *) a;
}

#if CHAR_SIGNEDNESS
INLINE(VDBI_MTYPE,ABC_LUNDAC) (char const a[8])
{
    return ABI_LUNDAC((void *) a);
}
#else
INLINE(VDBU_MTYPE,ABC_LUNDAC) (char const a[8])
{
    return ABU_LUNDAC((void *) a);
}
#endif

INLINE(VDHU_MTYPE,AHU_LUNDAC) (uint16_t a[4])
{
    return *(VDHU_MTYPE const *) a;
}

INLINE(VDHI_MTYPE,AHI_LUNDAC) (int16_t a[4])
{
    return *(VDHI_MTYPE const *) a;
}

INLINE(VDHF_MTYPE,AHF_LUNDAC) (flt16_t a[4])
{
    return *(VDHF_MTYPE const *) a;
}


INLINE(VDWU_MTYPE,AWU_LUNDAC) (uint32_t a[2])
{
    return *(VDWU_MTYPE const *) a;
}

INLINE(VDWI_MTYPE,AWI_LUNDAC) (int32_t a[2])
{
    return *(VDWI_MTYPE const *) a;
}

INLINE(VDWF_MTYPE,AWF_LUNDAC) (float a[2])
{
    return *(VDWF_MTYPE const *) a;
}


INLINE(VDDU_MTYPE,ADU_LUNDAC) (uint64_t a[1])
{
    return *(VDDU_MTYPE const *) a;
}

INLINE(VDDI_MTYPE,ADI_LUNDAC) (int64_t a[1])
{
    return *(VDDI_MTYPE const *) a;
}

INLINE(VDDF_MTYPE,ADF_LUNDAC) (double a[1])
{
    return *(VDDF_MTYPE const *) a;
}

#if 0 // _LEAVE_X86_LUNDAC
}
#endif

#if 0 // _ENTER_X86_LDRD
{
#endif

#define     ABU_LDRD(a)     ((VDBU_TYPE){ABU_LUNDAC(a)})
#define     ABI_LDRD(a)     ((VDBI_TYPE){ABI_LUNDAC(a)})
#if CHAR_SIGNEDNESS
#   define  ABC_LDRD(a)     ((VDBI_TYPE){ABC_LUNDAC(a)})
#else
#   define  ABC_LDRD(a)     ((VDBU_TYPE){ABC_LUNDAC(a)})
#endif
#define     AHU_LDRD(a)     ((VDHU_TYPE){AHU_LUNDAC(a)})
#define     AHI_LDRD(a)     ((VDHI_TYPE){AHI_LUNDAC(a)})
#define     AHF_LDRD(a)     ((VDHF_TYPE){AHF_LUNDAC(a)})

#define     AWU_LDRD(a)     ((VDWU_TYPE){AWU_LUNDAC(a)})
#define     AWI_LDRD(a)     ((VDWI_TYPE){AWI_LUNDAC(a)})
#define     AWF_LDRD(a)     ((VDWF_TYPE){AWF_LUNDAC(a)})

#define     ADU_LDRD(a)     ((VDDU_TYPE){ADU_LUNDAC(a)})
#define     ADI_LDRD(a)     ((VDDI_TYPE){ADI_LUNDAC(a)})
#define     ADF_LDRD(a)     ((VDDF_TYPE){ADF_LUNDAC(a)})

#if 0 // _LEAVE_X86_LDRD
}
#endif

#if 0 // _ENTER_X86_LUNQAC
{
#endif

INLINE(VQBU_MTYPE, ABU_LUNQAC) (uint8_t const a[16])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQBI_MTYPE, ABI_LUNQAC) (int8_t  const a[16])
{
    return  _mm_load_si128((void const *) a);
}

#if CHAR_SIGNEDNESS
INLINE(VQBI_MTYPE,ABC_LUNQAC) (char const a[16])
{
    return  ABI_LUNQAC((void *) a);
}
#else
INLINE(VQBU_MTYPE,ABC_LUNQAC) (char const a[16])
{
    return ABU_LUNDAC((void *) a);
}
#endif

INLINE(VQHU_MTYPE,AHU_LUNQAC) (uint16_t const a[8])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQHI_MTYPE,AHI_LUNQAC) (int16_t const a[8])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQHF_MTYPE,AHF_LUNQAC) (flt16_t const a[8])
{
#if defined(SPC_X86_AVX512FP16)
    return  _mm_load_ph(a);
#else
    return  _mm_load_si128((void const *) a);
#endif
}


INLINE(VQWU_MTYPE,AWU_LUNQAC) (uint32_t const a[4])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQWI_MTYPE,AWI_LUNQAC) (int32_t const a[4])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQWF_MTYPE,AWF_LUNQAC) (float const a[4])
{
    return  _mm_load_ps((void const *) a);
}


INLINE(VQDU_MTYPE,ADU_LUNQAC) (uint64_t const a[2])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQDI_MTYPE,ADI_LUNQAC) (int64_t const a[2])
{
    return  _mm_load_si128((void const *) a);
}

INLINE(VQDF_MTYPE,ADF_LUNQAC) (double const a[2])
{
    return  _mm_load_pd((void const *) a);
}

#if 0 // _LEAVE_X86_LUNQAC
}
#endif

#if 0 // _ENTER_X86_LDRQ
{
#endif

#define     ABU_LDRQ(a)     ((Vqbu){ABU_LUNQAC(a)})
#define     ABI_LDRQ(a)     ((Vqbi){ABI_LUNQAC(a)})
#if CHAR_SIGNEDNESS
#   define  ABC_LDRQ(a)     ((Vqbi){ABC_LUNQAC(a)})
#else
#   define  ABC_LDRQ(a)     ((Vqbu){ABC_LUNQAC(a)})
#endif

#define     AHU_LDRQ(a)     ((Vqhu){AHU_LUNQAC(a)})
#define     AHI_LDRQ(a)     ((Vqhi){AHI_LUNQAC(a)})
#if defined(SPC_X86_AVX512FP16)
#   define  AHF_LDRQ                AHF_LUNQAC
#else
#   define  AHF_LDRQ(a)     ((Vqhf){AHF_LUNQAC(a)})
#endif

#define     AWU_LDRQ(a)     ((Vqwu){AWU_LUNQAC(a)})
#define     AWI_LDRQ(a)     ((Vqwi){AWI_LUNQAC(a)})
#define     AWF_LDRQ                AWF_LUNQAC

#define     AQU_LDRQ(a)     ((Vqdu){AQU_LUNQAC(a)})
#define     AQI_LDRQ(a)     ((Vqdi){AQI_LUNQAC(a)})
#define     AQF_LDRQ                AQF_LUNQAC

#if 0 // _LEAVE_X86_LDRQ
}
#endif

#if 0 // _ENTER_X86_LDRO
{
#endif

#if 0 // _LEAVE_X86_LDRO
}
#endif

#if 0 // _ENTER_X86_LDRS
{
#endif

#if 0 // _LEAVE_X86_LDRS
}
#endif

#if 0 // _ENTER_X86_STRN
{
#endif

#if 0 // _LEAVE_X86_STRN
}
#endif

#if 0 // _ENTER_X86_STRN
{
#endif

#if 0 // _LEAVE_X86_STRN
}
#endif

#if 0 // _ENTER_X86_STRN
{
#endif
#if 0 // _LEAVE_X86_STRN
}
#endif

#if 0 // _ENTER_X86_STRO
{
#endif
#if 0 // _LEAVE_X86_STRO
}
#endif

#if 0 // _ENTER_X86_STRS
{
#endif

#if 0 // _LEAVE_X86_STRS
}
#endif

#if 0 // _ENTER_X86_NEWL
{
#endif

#define     WBZ_NEWL(T, k0, k1, k2, k3)         \
_mm_cvtss_f32(                                  \
    _mm_castsi128_ps(                           \
        _mm_setr_epi8(                          \
            (T)(k0), (T)(k1), (T)(k2), (T)(k3), \
            ('\x00'),('\x00'),('\x00'),('\x00'),\
            ('\x00'),('\x00'),('\x00'),('\x00'),\
            ('\x00'),('\x00'),('\x00'),('\x00') \
        )                                       \
    )                                           \
)

#define     WBU_NEWL(k0,k1,k2,k3) WBZ_NEWL(UINT8_TYPE, k0,k1,k2,k3)
#define     WBI_NEWL(k0,k1,k2,k3) WBZ_NEWL( INT8_TYPE, k0,k1,k2,k3)

#define     WHZ_NEWL(T, k0, k1)                 \
_mm_cvtss_f32(                                  \
    _mm_castsi128_ps(                           \
        _mm_setr_epi16(                         \
            (T)(k0), (T)(k1), (0x0000),(0x0000),\
            (0x0000),(0x0000),(0x0000),(0x0000) \
        )                                       \
    )                                           \
)

#define     WHU_NEWL(k0, k1) WHZ_NEWL(UINT16_TYPE, k0, k1)
#define     WHI_NEWL(k0, k1) WHZ_NEWL( INT16_TYPE, k0, k1)
#if defined(SPC_X86_AVX512FP16)
#   define  WHF_NEWL(k0, k1)                \
_mm_cvtss_f32(                              \
    _mm_castph_ps(                          \
        _mm_setr_ph(                        \
            (k0),   (k1),   0.0f16, 0.0f16, \
            0.0f16, 0.0f16, 0.0f16, 0.f16   \
        )                                   \
    )                                       \
)

#else
#   define  WHF_NEWL(k0, k1)                \
_mm_cvtss_f32(                              \
    _mm_castsi128_ps(                       \
        _mm_setr_epi16(                     \
            (k0).I, (k1).I, (0x00), (0x00), \
            (0x00), (0x00), (0x00), (0x00)  \
        )                                   \
    )                                       \
)

#endif

/*  Inb4 _mm_cvtsi32_si128 results in a less efficient
    instruction sequence compared to _mm_setr_epi32 with
    3 trailing zeros, similar to neon's vdup_n and vcreate
*/

#define     WWZ_NEWL(T, k0)                 \
_mm_cvtss_f32(_mm_castsi128_ps(_mm_cvtsi32_si128((T)(k0))))

#define     WWU_NEWL(k0)    WWZ_NEWL(UINT32_TYPE, k0)
#define     WWI_NEWL(k0)    WWZ_NEWL( INT32_TYPE, k0)
#define     WWF_NEWL(k0)    ((VWWF_MTYPE)(k0))

#define     DBZ_NEWL(T,k0,k1,k2,k3,k4,k5,k6,k7) \
_mm_cvtsd_f64(                                  \
    _mm_castsi128_pd(                           \
        _mm_setr_epi8(                          \
            (T)(k0), (T)(k1), (T)(k2), (T)(k3), \
            (T)(k4), (T)(k5), (T)(k6), (T)(k7), \
            ('\x00'),('\x00'),('\x00'),('\x00'),\
            ('\x00'),('\x00'),('\x00'),('\x00') \
        )                                       \
    )                                           \
)

#define     DBU_NEWL(...) DBZ_NEWL( UINT8_TYPE, __VA_ARGS__)
#define     DBI_NEWL(...) DBZ_NEWL(  INT8_TYPE, __VA_ARGS__)

#define     DHZ_NEWL(T,k0,k1,k2,k3)             \
_mm_cvtsd_f64(                                  \
    _mm_castsi128_pd(                           \
        _mm_setr_epi16(                         \
            (T)(k0), (T)(k1), (T)(k2), (T)(k3), \
            (0x0000),(0x0000),(0x0000),(0x0000) \
        )                                       \
    )                                           \
)

#define     DHU_NEWL(...) DHZ_NEWL(UINT16_TYPE, __VA_ARGS__)
#define     DHI_NEWL(...) DHZ_NEWL( INT16_TYPE, __VA_ARGS__)

#if defined(SPC_X86_AVX512FP16)
#   define  DHF_NEWL(k0, k1, k2, k3)        \
_mm_cvtsd_f64(                              \
    _mm_castph_pd(                         \
        _mm_setr_ph(                        \
            (k0),   (k1),   (k2),   (k3),   \
            0.0f16, 0.0f16, 0.0f16, 0.f16   \
        )                                   \
    )                                       \
)

#else
#   define  DHF_NEWL(k0, k1, k2, k3)        \
_mm_cvtsd_f64(                              \
    _mm_castsi128_pd(                       \
        _mm_setr_epi16(                     \
            (k0).I, (k1).I, (k2).I, (k3).I, \
            (0x00), (0x00), (0x00), (0x00)  \
        )                                   \
    )                                       \
)
#endif

#define     DWZ_NEWL(T, k0, k1)         \
_mm_cvtsd_f64(                          \
    _mm_castsi128_pd(                   \
        _mm_setr_epi32(                 \
            (T)(k0), (T)(k1),           \
            (0x00000000),(0x00000000)   \
        )                               \
    )                                   \
)

#define     DWU_NEWL(...)   DWZ_NEWL(UINT32_TYPE, __VA_ARGS__)
#define     DWI_NEWL(...)   DWZ_NEWL( INT32_TYPE, __VA_ARGS__)
#define     DWF_NEWL(k0, k1)        \
_mm_cvtsd_f64(                      \
    _mm_castps_pd(                  \
        _mm_setr_ps(                \
            (k0), (k1), 0.0f, 0.0f  \
        )                           \
    )                               \
)

#define     DDZ_NEWL(T, k0) \
_mm_cvtsd_f64(_mm_castsi128_pd(_mm_cvtsi64_si128((T)(k0))))

#define     DDU_NEWL(k0)    DDZ_NEWL(UINT64_TYPE, k0)
#define     DDI_NEWL(k0)    DDZ_NEWL( INT64_TYPE, k0)
#define     DDF_NEWL(k0)    ((VDDF_MTYPE)(k0))


#define     QBU_NEWL        _mm_setr_epi8
#define     QBI_NEWL        _mm_setr_epi8

#define     QHU_NEWL        _mm_setr_epi16
#define     QHI_NEWL        _mm_setr_epi16
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_NEWL        _mm_setr_ph
#else
#   define  QHF_NEWL(h0,h1,h2,h3,h4,h5,h6,h7)   \
_mm_setr_epi16(                                 \
    (h0).I, (h1).I, (h2).I, (h3).I,             \
    (h4).I, (h5).I, (h6).I, (h7).I              \
)
#endif

#define     QWU_NEWL        _mm_setr_epi32
#define     QWI_NEWL        _mm_setr_epi32
#define     QWF_NEWL        _mm_setr_ps

#define     QDU_NEWL(k0,k1) _mm_set_epi64x(k1, k0)
#define     QDI_NEWL(k0,k1) _mm_set_epi64x(k1, k0)
#define     QDF_NEWL        _mm_setr_pd

#define     VWBU_NEWL(...)  ((Vwbu){WBU_NEWL(__VA_ARGS__)})
#define     VWBI_NEWL(...)  ((Vwbi){WBI_NEWL(__VA_ARGS__)})

#define     VWHU_NEWL(...)  ((Vwhu){WHU_NEWL(__VA_ARGS__)})
#define     VWHI_NEWL(...)  ((Vwhi){WHI_NEWL(__VA_ARGS__)})
#define     VWHF_NEWL(...)  ((Vwhf){WHF_NEWL(__VA_ARGS__)})
#define     VWWU_NEWL(...)  ((Vwwu){WWU_NEWL(__VA_ARGS__)})
#define     VWWI_NEWL(...)  ((Vwwi){WWI_NEWL(__VA_ARGS__)})
#define     VWWF_NEWL(...)  ((Vwwf){WWF_NEWL(__VA_ARGS__)})

#define     VDBU_NEWL(...)  ((Vdbu){DBU_NEWL(__VA_ARGS__)})
#define     VDBI_NEWL(...)  ((Vdbi){DBI_NEWL(__VA_ARGS__)})
#define     VDHU_NEWL(...)  ((Vdhu){DHU_NEWL(__VA_ARGS__)})
#define     VDHI_NEWL(...)  ((Vdhi){DHI_NEWL(__VA_ARGS__)})
#define     VDHF_NEWL(...)  ((Vdhf){DHF_NEWL(__VA_ARGS__)})
#define     VDWU_NEWL(...)  ((Vdwu){DWU_NEWL(__VA_ARGS__)})
#define     VDWI_NEWL(...)  ((Vdwi){DWI_NEWL(__VA_ARGS__)})
#define     VDWF_NEWL(...)  ((Vdwf){DWF_NEWL(__VA_ARGS__)})
#define     VDDU_NEWL(...)  ((Vddu){DDU_NEWL(__VA_ARGS__)})
#define     VDDI_NEWL(...)  ((Vddi){DDI_NEWL(__VA_ARGS__)})
#define     VDDF_NEWL(...)  ((Vddf){DDF_NEWL(__VA_ARGS__)})

#define     VQBU_NEWL(...)  ((Vqbu){QBU_NEWL(__VA_ARGS__)})
#define     VQBI_NEWL(...)  ((Vqbi){QBI_NEWL(__VA_ARGS__)})
#define     VQHU_NEWL(...)  ((Vqhu){QHU_NEWL(__VA_ARGS__)})
#define     VQHI_NEWL(...)  ((Vqhi){QHI_NEWL(__VA_ARGS__)})
#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_NEWL               QHF_NEWL
#else
#   define  VQHF_NEWL(...)  ((Vqhf){QHF_NEWL(__VA_ARGS__)})
#endif
#define     VQWU_NEWL(...)  ((Vqwu){QWU_NEWL(__VA_ARGS__)})
#define     VQWI_NEWL(...)  ((Vqwi){QWI_NEWL(__VA_ARGS__)})
#define     VQWF_NEWL               QWF_NEWL
#define     VQDU_NEWL(...)  ((Vqdu){QDU_NEWL(__VA_ARGS__)})
#define     VQDI_NEWL(...)  ((Vqdi){QDI_NEWL(__VA_ARGS__)})
#define     VQDF_NEWL               QDF_NEWL


#if 0 // _LEAVE_X86_NEWL
}
#endif

#if 0 // _ENTER_X86_CATL
{
#endif

#define     VW_CAT(W, l, r)         \
_mm_cvtsd_f64(                      \
    _mm_castps_pd(                  \
        _mm_setr_ps(                \
            _Generic((l), W: (l)),  \
            _Generic((r), W: (r)),  \
            0, 0                    \
        )                           \
    )                               \
)

#define     WBU_CATL(l, r)  VW_CAT(VWBU_MTYPE, l, r)
#define     WBI_CATL(l, r)  VW_CAT(VWBI_MTYPE, l, r)
#define     WHU_CATL(l, r)  VW_CAT(VWHU_MTYPE, l, r)
#define     WHI_CATL(l, r)  VW_CAT(VWHI_MTYPE, l, r)
#define     WHF_CATL(l, r)  VW_CAT(VWHF_MTYPE, l, r)
#define     WWU_CATL(l, r)  VW_CAT(VWWU_MTYPE, l, r)
#define     WWI_CATL(l, r)  VW_CAT(VWWI_MTYPE, l, r)
#define     WWF_CATL(l, r)  VW_CAT(VWWF_MTYPE, l, r)

#define     VD_CAT(Q, D, l, r)  \
_mm_castpd_##Q(                 \
    _mm_setr_pd(                \
        _Generic((l), D: (l)),  \
        _Generic((r), D: (r))   \
    )                           \
)

#define     VDZ_CAT(D,l,r)  VD_CAT(si128, D, l, r)

#define     DBU_CATL(l, r)  VDZ_CAT(   VDBU_MTYPE, l, r)
#define     DBI_CATL(l, r)  VDZ_CAT(   VDBI_MTYPE, l, r)
#define     DHU_CATL(l, r)  VDZ_CAT(   VDHU_MTYPE, l, r)
#define     DHI_CATL(l, r)  VDZ_CAT(   VDHI_MTYPE, l, r)
#if defined(SPC_X86_AVX512FP16)
#   define  DHF_CATL(l, r)  VD_CAT(ph, VDHF_MTYPE, l, r)
#else
#   define  DHF_CATL(l, r)  VDZ_CAT(   VDHF_MTYPE, l, r)
#endif

#define     DWU_CATL(l, r)  VDZ_CAT(   VDWU_MTYPE, l, r)
#define     DWI_CATL(l, r)  VDZ_CAT(   VDWI_MTYPE, l, r)
#define     DWF_CATL(l, r)  VD_CAT(ps, VDWF_MTYPE, l, r)
#define     DDU_CATL(l, r)  VDZ_CAT(   VDDU_MTYPE, l, r)
#define     DDI_CATL(l, r)  VDZ_CAT(   VDDI_MTYPE, l, r)
#define     DDF_CATL(l, r)          \
_mm_setr_pd(                        \
    _Generic((l), VDDF_MTYPE: (l)), \
    _Generic((r), VDDF_MTYPE: (r))  \
)

// catl
#define     VWBU_CATL(l, r) ((Vdbu){WBU_CATL((l).V0, (r).V0)})
#define     VWBI_CATL(l, r) ((Vdbi){WBI_CATL((l).V0, (r).V0)})
#define     VWHU_CATL(l, r) ((Vdhu){WHU_CATL((l).V0, (r).V0)})
#define     VWHI_CATL(l, r) ((Vdhi){WHI_CATL((l).V0, (r).V0)})
#define     VWHF_CATL(l, r) ((Vdhf){WHF_CATL((l).V0, (r).V0)})
#define     VWWU_CATL(l, r) ((Vdwu){WWU_CATL((l).V0, (r).V0)})
#define     VWWI_CATL(l, r) ((Vdwi){WWI_CATL((l).V0, (r).V0)})
#define     VWWF_CATL(l, r) ((Vdwf){WWF_CATL((l).V0, (r).V0)})

#define     VDBU_CATL(l, r) ((Vqbu){DBU_CATL((l).V0, (r).V0)})
#define     VDBI_CATL(l, r) ((Vqbi){DBI_CATL((l).V0, (r).V0)})
#define     VDHU_CATL(l, r) ((Vqhu){DHU_CATL((l).V0, (r).V0)})
#define     VDHI_CATL(l, r) ((Vqhi){DHI_CATL((l).V0, (r).V0)})
#if defined(SPC_X86_AVX512FP16)
#   define  VDHF_CATL(l, r) DHF_CATL((l).V0, (r).V0)
#else
#   define  VDHF_CATL(l, r) ((Vqhf){DHI_CATL((l).V0, (r).V0)})
#endif

#define     VDWU_CATL(l, r) ((Vqwu){DWU_CATL((l).V0, (r).V0)})
#define     VDWI_CATL(l, r) ((Vqwi){DWI_CATL((l).V0, (r).V0)})
#define     VDWF_CATL(l, r)         DWF_CATL((l).V0, (r).V0)

#define     VDDU_CATL(l, r) ((Vqdu){DDU_CATL((l).V0, (r).V0)})
#define     VDDI_CATL(l, r) ((Vqdi){DDI_CATL((l).V0, (r).V0)})
#define     VDDF_CATL(l, r)         DDF_CATL((l).V0, (r).V0)

#if 0 // _LEAVE_X86_CATL
}
#endif

#if 0 // _ENTER_X86_REVS
{
#endif

#if 0 // _LEAVE_X86_REVS
}
#endif

#if 0 // _ENTER_X86_SHRS
{
#endif

INLINE(Vdbi,VDBI_SHRS) (Vdbi a, Rc(0, 8) b)
{
#define     VDBI_SHRS(A, B) \
(\
    (VDBI_TYPE)\
    {\
        _mm_cvtsd_f64(\
            _mm_castsi128_pd(\
                _mm_shuffle_epi8(\
                    _mm_srai_epi16(\
                        _mm_castpd_si128(\
                            _mm_set_sd(A.V0)\
                        ),\
                        B\
                    ),\
                    _mm_cvtsi64_si128(0x0e0c0a0806040200LL)\
                )\
            )\
        )\
    }       \
)

    __m128i z = _mm_castpd_si128(_mm_set_sd(a.V0));
    z = _mm_cvtepi8_epi16(z);
    z = _mm_sra_epi16(z, _mm_cvtsi64_si128(b));
    z = _mm_shuffle_epi8(z, _mm_cvtsi64_si128(0x0e0c0a0806040200LL));
    __m128d v = _mm_castsi128_pd(z);
    double  m = _mm_cvtsd_f64(v);
    return  ((VDBI_TYPE){m});
}

#if 0 // _LEAVE_X86_SHRS
}
#endif


#if 0 // _ENTER_X86_PERS
{
#endif
/*  no, using 0 for the unused upper bytes isn't an error or
accident. If -1 is used, clang outputs wildly and frankly
obviously inefficient code.
*/

#define WBR_PERS(A, K0,K1,K2,K3)    \
_mm_cvtss_f32(                      \
    _mm_castsi128_ps(               \
        _mm_shuffle_epi8(           \
            _mm_castps_si128(       \
                _mm_set_ss(A),      \
                _mm_set_epi8(       \
                    0,0,0,0,        \
                    0,0,0,0,        \
                    0,0,0,0,        \
                    K3,K2,K1,K0     \
                )                   \
            )                       \
        )                           \
    )                               \
)

#define WHR_PERS(A, K0,K1)                  \
_mm_cvtss_f32(                              \
    _mm_castsi128_ps(                       \
        _mm_shuffle_epi8(                   \
            _mm_castps_si128(               \
                _mm_set_ss(A),              \
                _mm_set_epi8(               \
                    0,0,0,0,                \
                    0,0,0,0,                \
                    0,0,0,0,                \
                    ((K1<0)?-1:(1+(2*K1))), \
                    ((K1<0)?-1:(0+(2*K1))), \
                    ((K0<0)?-1:(1+(2*K0))), \
                    ((K0<0)?-1:(0+(2*K0)))  \
                )                           \
            )                               \
        )                                   \
    )                                       \
)

#define DBR_PERS(A, K0,K1,K2,K3, K4,K5,K6,K7)    \
_mm_cvtss_f64(                      \
    _mm_castsi128_ps(               \
        _mm_shuffle_epi8(           \
            _mm_castpd_si128(       \
                _mm_set_sd(A),      \
                _mm_set_epi8(       \
                    0,0,0,0,    \
                    0,0,0,0,    \
                    K7,K6,K5,K4,    \
                    K3,K2,K1,K0     \
                )                   \
            )                       \
        )                           \
    )                               \
)

#define DHR_PERS(A, K0,K1,K2,K3)            \
_mm_cvtsd_f64(                              \
    _mm_castsi128_ps(                       \
        _mm_shuffle_epi8(                   \
            _mm_castps_si128(               \
                _mm_set_sd(A),              \
                _mm_set_epi8(               \
                    0,0,0,0,            \
                    0,0,0,0,            \
                    ((K3<0)?-1:(1+(2*K3))), \
                    ((K3<0)?-1:(0+(2*K3))), \
                    ((K2<0)?-1:(1+(2*K2))), \
                    ((K2<0)?-1:(0+(2*K2))), \
                    ((K1<0)?-1:(1+(2*K1))), \
                    ((K1<0)?-1:(0+(2*K1))), \
                    ((K0<0)?-1:(1+(2*K0))), \
                    ((K0<0)?-1:(0+(2*K0)))  \
                )                           \
            )                               \
        )                                   \
    )                                       \
)

#define DWR_PERS(A, K0,K1)                  \
_mm_cvtsd_f64(                              \
    _mm_castsi128_ps(                       \
        _mm_shuffle_epi8(                   \
            _mm_castps_si128(               \
                _mm_set_sd(A),              \
                _mm_set_epi8(               \
                    0,0,0,0,                \
                    0,0,0,0,                \
                    ((K1<0)?-1:(3+(4*K1))), \
                    ((K1<0)?-1:(2+(4*K1))), \
                    ((K1<0)?-1:(1+(4*K1))), \
                    ((K1<0)?-1:(0+(4*K1))), \
                    ((K0<0)?-1:(3+(4*K0))), \
                    ((K0<0)?-1:(2+(4*K0))), \
                    ((K0<0)?-1:(1+(4*K0))), \
                    ((K0<0)?-1:(0+(4*K0)))  \
                )                           \
            )                               \
        )                                   \
    )                                       \
)

#define QBZ_PERS(A, K0,K1,K2,K3, K4,K5,K6,K7, K8,K9,Ka,Kb, Kc,Kd,Ke,Kf)    \
_mm_shuffle_epi8(\
    A,\
    _mm_set_epi8(Kf,Ke,Kd,Kc,Kb,Ka,K9,K8,K7,K6,K5,K4,K3,K2,K1,K0)\
)


#define QHZ_PERS(A, K0,K1,K2,K3, K4,K5,K6,K7)    \
_mm_shuffle_epi8(                   \
    A,                              \
    _mm_set_epi8(                   \
        ((K7<0)?-1:(1+(2*K7))),     \
        ((K7<0)?-1:(0+(2*K7))),     \
        ((K6<0)?-1:(1+(2*K6))),     \
        ((K6<0)?-1:(0+(2*K6))),     \
        ((K5<0)?-1:(1+(2*K5))),     \
        ((K5<0)?-1:(0+(2*K5))),     \
        ((K4<0)?-1:(1+(2*K4))),     \
        ((K4<0)?-1:(0+(2*K4))),     \
        ((K3<0)?-1:(1+(2*K3))),     \
        ((K3<0)?-1:(0+(2*K3))),     \
        ((K2<0)?-1:(1+(2*K2))),     \
        ((K2<0)?-1:(0+(2*K2))),     \
        ((K1<0)?-1:(1+(2*K1))),     \
        ((K1<0)?-1:(0+(2*K1))),     \
        ((K0<0)?-1:(1+(2*K0))),     \
        ((K0<0)?-1:(0+(2*K0)))      \
    )                               \
)

#define QWZ_PERS(A, K0,K1,K2,K3)    \
_mm_shuffle_epi8(                   \
    A,                              \
    _mm_set_epi8(                   \
        ((K3<0)?-1:(3+(4*K3))),     \
        ((K3<0)?-1:(2+(4*K3))),     \
        ((K3<0)?-1:(1+(4*K3))),     \
        ((K3<0)?-1:(0+(4*K3))),     \
        ((K2<0)?-1:(3+(4*K2))),     \
        ((K2<0)?-1:(2+(4*K2))),     \
        ((K2<0)?-1:(1+(4*K2))),     \
        ((K2<0)?-1:(0+(4*K2))),     \
        ((K1<0)?-1:(3+(4*K1))),     \
        ((K1<0)?-1:(2+(4*K1))),     \
        ((K1<0)?-1:(1+(4*K1))),     \
        ((K1<0)?-1:(0+(4*K1))),     \
        ((K0<0)?-1:(3+(4*K0))),     \
        ((K0<0)?-1:(2+(4*K0))),     \
        ((K0<0)?-1:(1+(4*K0))),     \
        ((K0<0)?-1:(0+(4*K0)))      \
    )                               \
)

#define QDZ_PERS(A, K0,K1)          \
_mm_shuffle_epi8(                   \
    A,                              \
    _mm_set_epi8(                   \
        ((K1<0)?-1:(7+(8*K1))),     \
        ((K1<0)?-1:(6+(8*K1))),     \
        ((K1<0)?-1:(5+(8*K1))),     \
        ((K1<0)?-1:(4+(8*K1))),     \
        ((K1<0)?-1:(3+(8*K1))),     \
        ((K1<0)?-1:(2+(8*K1))),     \
        ((K1<0)?-1:(1+(8*K1))),     \
        ((K1<0)?-1:(0+(8*K1))),     \
        ((K0<0)?-1:(7+(8*K0))),     \
        ((K0<0)?-1:(6+(8*K0))),     \
        ((K0<0)?-1:(5+(8*K0))),     \
        ((K0<0)?-1:(4+(8*K0))),     \
        ((K0<0)?-1:(3+(8*K0))),     \
        ((K0<0)?-1:(2+(8*K0))),     \
        ((K0<0)?-1:(1+(8*K0))),     \
        ((K0<0)?-1:(0+(8*K0))),     \
    )                               \
)

INLINE(Vwbu,VWBU_PERS) 
(
    Vwbu a, 
    Rc(-1,3) k0, Rc(-1,3) k1, Rc(-1,3) k2, Rc(-1,3) k3
)
{
#define     VWBU_PERS(A, ...) ((Vwbu){WBR_PERS(A.V0,__VA_ARGS__)})
    __m128  f = _mm_set_ss(a.V0);
    __m128i z = _mm_castps_si128(f);
    __m128i t = _mm_set_epi8(
        -1,-1,-1,-1, 
        -1,-1,-1,-1,
        -1,-1,-1,-1,
        k3,k2,k1,k0
    );
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castps_si128(z);
    a.V0 = _mm_cvtss_f32(f);
    return a;
}


INLINE(Vwhu,VWHU_PERS) 
(
    Vwhu a, 
    Rc(-1,1) k0, Rc(-1,1) k1
)
{
#define     VWHU_PERS(A, ...) ((Vwhu){WHR_PERS(A.V0,__VA_ARGS__)})
    __m128  f = _mm_set_ss(a.V0);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi8(
        0,0,0,0, 0,0,0,0,
        0,0,0,0, k1,k1, k0,k0
    );
    __m128i m = _mm_cmpgt_epi8(t, _mm_set1_epi8(0));
    m = _mm_and_si128(m, _mm_set1_epi16(0x0100));
    t = _mm_add_epi8(t, m);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castps_si128(z);
    a.V0 = _mm_cvtss_f32(f);
    return a;
}

INLINE(Vdbu,VDBU_PERS) 
(
    Vdbu a, 
    Rc(-1,7) k0, Rc(-1,7) k1, Rc(-1,7) k2, Rc(-1,7) k3,
    Rc(-1,7) k4, Rc(-1,7) k5, Rc(-1,7) k6, Rc(-1,7) k7
)
{
#define     VDBU_PERS(A, ...) ((Vdbu){DBR_PERS(A.V0,__VA_ARGS__)})
    __m128d f = _mm_set_sd(a.V0);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi8(0,0,0,0,0,0, k7,k6,k5,k4,k3,k2,k1,k0);
    t = _mm_or_si128(t, _mm_slli_epi16(t, 8));
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castps_si128(z);
    a.V0 = _mm_cvtsd_f64(f);
    return a;
}


INLINE(Vdhu,VDHU_PERS) 
(
    Vdhu a, 
    Rc(-1,1) k0, Rc(-1,1) k1, Rc(-1,3) k2, Rc(-1,3) k3
)
{

#define     VDHU_PERS(A, ...) ((Vdhu){DHR_PERS(A.V0,__VA_ARGS__)})
    __m128d f = _mm_set_sd(a.V0);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi8(
        0,0,0,0, 0,0,0,0,
        k3,k3, k2,k2, k1,k1, k0,k0
    );
    __m128i m = _mm_cmpeq_epi8(t, _mm_set1_epi8(-1));
    m = _mm_and_si128(m, _mm_set1_epi16(0x0100));
    t = _mm_add_epi8(t, m);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castpd_si128(z);
    a.V0 = _mm_cvtsd_f64(f);
    return a;
}

INLINE(Vdwu,VDWU_PERS) 
(
    Vdwu a, 
    Rc(-1,1) k0, Rc(-1,1) k1
)
{

#define     VDWU_PERS(A, ...) ((Vdwu){DWR_PERS(A.V0,__VA_ARGS__)})
    __m128d f = _mm_set_sd(a.V0);
    __m128i z = _mm_castpd_si128(f);
    __m128i t = _mm_set_epi8(
        0,0,0,0, 0,0,0,0,
        k1,k1,k1,k1,  k0,k0,k0,k0
    );
    __m128i m = _mm_cmpeq_epi8(t, _mm_set1_epi8(-1));
    m = _mm_and_si128(m, _mm_set1_epi16(0x03020100));
    t = _mm_add_epi8(t, m);
    z = _mm_shuffle_epi8(z, t);
    f = _mm_castpd_si128(z);
    a.V0 = _mm_cvtsd_f64(f);
    return a;
}

INLINE(Vqbu,VQBU_PERS)
(
    Vqbu v,
    Rc(-1,+15)  k0, Rc(-1,+15)  k1, Rc(-1,+15)  k2, Rc(-1,+15)  k3,
    Rc(-1,+15)  k4, Rc(-1,+15)  k5, Rc(-1,+15)  k6, Rc(-1,+15)  k7,
    Rc(-1,+15)  k8, Rc(-1,+15)  k9, Rc(-1,+15) k10, Rc(-1,+15) k11,
    Rc(-1,+15) k12, Rc(-1,+15) k13, Rc(-1,+15) k14, Rc(-1,+15) k15
)
{
#define     VQBU_PERS(A, ...) ((Vqbu){QBZ_PERS(A.V0,__VA_ARGS__)})
    __m128i t = _mm_set_epi8(
        k15,k14,k13,k12,
        k11,k10, k9, k8,
        k7,  k6, k5, k4,
        k3,  k2, k1, k0
    );
    v.V0 = _mm_shuffle_epi8(v.V0, t);
    return v;
}

INLINE(Vqhu,VQHU_PERS)
(
    Vqhu v,
    Rc(-1,+7)  k0, Rc(-1,+7)  k1, Rc(-1,+7)  k2, Rc(-1,+7)  k3,
    Rc(-1,+7)  k4, Rc(-1,+7)  k5, Rc(-1,+7)  k6, Rc(-1,+7)  k7
)
{
#define     VQHU_PERS(A, ...) ((Vqhu){QHZ_PERS(A.V0,__VA_ARGS__)})
    __m128i t = _mm_set_epi8(
        k7,k7, k6,k6, k5,k5, k4,k4,
        k3,k3, k2,k2, k1,k1, k0,k0
    );
    __m128i m = _mm_cmpeq_epi8(t, _mm_set1_epi8(-1));
    m = _mm_and_si128(m, _mm_set1_epi16(0x0100));
    t = _mm_add_epi8(t, m);
    v.V0 = _mm_shuffle_epi8(v.V0, t);
    return v;
}

INLINE(Vqwu,VQWU_PERS)
(
    Vqwu v,
    Rc(-1,+3)  k0, Rc(-1,+3)  k1, Rc(-1,+3)  k2, Rc(-1,+3)  k3
)
{
#define     VQWU_PERS(A, ...) ((Vqwu){QWZ_PERS(A.V0,__VA_ARGS__)})
    __m128i t = _mm_set_epi8(
        k3,k3,k3,k3, k2,k2,k2,k2, k1,k1,k1,k1, k0,k0,k0,k0
    );
    __m128i m = _mm_cmpeq_epi8(t, _mm_set1_epi8(-1));
    m = _mm_and_si128(m, _mm_set1_epi32(0x03020100));
    t = _mm_add_epi8(t, m);
    v.V0 = _mm_shuffle_epi8(v.V0, t);
    return v;
}

INLINE(Vqdu,VQDU_PERS)
(
    Vqdu v,
    Rc(-1,+1)  k0, Rc(-1,+1)
)
{
#define     VQDU_PERS(A, ...) ((Vqdu){QDZ_PERS(A.V0,__VA_ARGS__)})
    __m128i t = _mm_set_epi8(
        k1,k1,k1,k1, k1,k1,k1,k1, 
        k0,k0,k0,k0, k0,k0,k0,k0
    );
    __m128i m = _mm_cmpeq_epi8(t, _mm_set1_epi8(-1));
    m = _mm_and_si128(m, _mm_set1_epi64x(0x0706050403020100LL));
    t = _mm_add_epi8(t, m);
    v.V0 = _mm_shuffle_epi8(v.V0, t);
    return v;
}

#if 0 // _LEAVE_X86_PERS
}
#endif

#if 0 // _ENTER_X86_GETL
{
#endif

#define     VD_GETL(V)      _mm_cvtss_f32(_mm_castpd_ps(_mm_set_sd(V)))

#define     DBU_GETL        VD_GETL
#define     DBI_GETL        VD_GETL
#define     DHU_GETL        VD_GETL
#define     DHI_GETL        VD_GETL
#define     DHF_GETL        VD_GETL
#define     DWU_GETL        VD_GETL
#define     DWI_GETL        VD_GETL
#define     DWF_GETL        VD_GETL

#define     VQ_GETL(T, V)   _mm_cvtsd_f64(_mm_cast##T(V))
#define     VQZ_GETL(V)     VQ_GETL(si128_pd, V)

#define     QBU_GETL        VQZ_GETL
#define     QBI_GETL        VQZ_GETL
#define     QHU_GETL        VQZ_GETL
#define     QHI_GETL        VQZ_GETL
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_GETL(V)     VQ_GETL(ph_pd, V)
#else
#   define  QHF_GETL        VQZ_GETL
#endif

#define     QWU_GETL        VQZ_GETL
#define     QWI_GETL        VQZ_GETL
#define     QWF_GETL(V)     VQ_GETL(ps_pd, V)
#define     QDU_GETL        VQZ_GETL
#define     QDI_GETL        VQZ_GETL
#define     QDF_GETL        _mm_cvtsd_f64

#define     VDBU_GETL(V)    ((Vwbu){DBU_GETL(VDBU_ASTM(V))})
#define     VDBI_GETL(V)    ((Vwbi){DBI_GETL(VDBI_ASTM(V))})
#define     VDHU_GETL(V)    ((Vwhu){DHU_GETL(VDHU_ASTM(V))})
#define     VDHI_GETL(V)    ((Vwhi){DHI_GETL(VDHI_ASTM(V))})
#define     VDHF_GETL(V)    ((Vwhf){DHF_GETL(VDHF_ASTM(V))})
#define     VDWU_GETL(V)    ((Vwwu){DWU_GETL(VDWU_ASTM(V))})
#define     VDWI_GETL(V)    ((Vwwi){DWI_GETL(VDWI_ASTM(V))})
#define     VDWF_GETL(V)    ((Vwwf){DWF_GETL(VDWF_ASTM(V))})

#define     VQBU_GETL(V)    ((Vdbu){QBU_GETL(VQBU_ASTM(V))})
#define     VQBI_GETL(V)    ((Vdbi){QBI_GETL(VQBI_ASTM(V))})
#define     VQHU_GETL(V)    ((Vdhu){QHU_GETL(VQHU_ASTM(V))})
#define     VQHI_GETL(V)    ((Vdhi){QHI_GETL(VQHI_ASTM(V))})
#define     VQHF_GETL(V)    ((Vdhf){QHF_GETL(VQHF_ASTM(V))})
#define     VQWU_GETL(V)    ((Vdwu){QWU_GETL(VQWU_ASTM(V))})
#define     VQWI_GETL(V)    ((Vdwi){QWI_GETL(VQWI_ASTM(V))})
#define     VQWF_GETL(V)    ((Vdwf){QWF_GETL(VQWF_ASTM(V))})
#define     VQDU_GETL(V)    ((Vddu){QDU_GETL(VQDU_ASTM(V))})
#define     VQDI_GETL(V)    ((Vddi){QDI_GETL(VQDI_ASTM(V))})
#define     VQDF_GETL(V)    ((Vddf){QDF_GETL(VQDF_ASTM(V))})

#if 0 // _LEAVE_X86_GETL
}
#endif

#if 0 // _ENTER_X86_GETR
{
#endif

#define     VD_GETR(V)                      \
_mm_cvtss_f32(                              \
    _mm_castsi128_ps(                       \
        _mm_shuffle_epi32(                  \
            _mm_castpd_si128(_mm_set_sd(V)),\
            0b01                            \
        )                                   \
    )                                       \
)

#define     DBU_GETR    VD_GETR
#define     DBI_GETR    VD_GETR
#define     DHU_GETR    VD_GETR
#define     DHI_GETR    VD_GETR
#define     DHF_GETR    VD_GETR
#define     DWU_GETR    VD_GETR
#define     DWI_GETR    VD_GETR
#define     DWF_GETR    VD_GETR

#define     VQ_GETR(T, V)   \
_mm_cvtsd_f64(              \
    _mm_unpackhi_pd(        \
        _mm_cast ##T(V),    \
        _mm_undefined_pd()  \
    )                       \
)

#define     VQZ_GETR(a)     VQ_GETR(si128_pd, a)
#define     QBU_GETR        VQZ_GETR
#define     QBI_GETR        VQZ_GETR
#define     QHU_GETR        VQZ_GETR
#define     QHI_GETR        VQZ_GETR
#if defined(SPC_X86_AVX512FP16)
#   define  QHF_GETR(a)     VQ_GETR(ph_pd, a)
#else
#   define  QHF_GETR        VQZ_GETR
#endif

#define     QWU_GETR        VQZ_GETR
#define     QWI_GETR        VQZ_GETR
#define     QWF_GETR(a)     VQ_GETR(ps_pd, a)
#define     QDU_GETR        VQZ_GETR
#define     QDI_GETR        VQZ_GETR
#define     QDF_GETR(c)     \
_mm_cvtsd_f64(_mm_unpackhi_pd(c, _mm_undefined_pd()))

#define     VDBU_GETR(V)    ((Vwbu){DBU_GETR(VDBU_ASTM(V))})
#define     VDBI_GETR(V)    ((Vwbi){DBI_GETR(VDBI_ASTM(V))})
#define     VDHU_GETR(V)    ((Vwhu){DHU_GETR(VDHU_ASTM(V))})
#define     VDHI_GETR(V)    ((Vwhi){DHI_GETR(VDHI_ASTM(V))})
#define     VDHF_GETR(V)    ((Vwhf){DHF_GETR(VDHF_ASTM(V))})
#define     VDWU_GETR(V)    ((Vwwu){DWU_GETR(VDWU_ASTM(V))})
#define     VDWI_GETR(V)    ((Vwwi){DWI_GETR(VDWI_ASTM(V))})
#define     VDWF_GETR(V)    ((Vwwf){DWF_GETR(VDWF_ASTM(V))})

#define     VQBU_GETR(V)    ((Vdbu){QBU_GETR(VQBU_ASTM(V))})
#define     VQBI_GETR(V)    ((Vdbi){QBI_GETR(VQBI_ASTM(V))})
#define     VQHU_GETR(V)    ((Vdhu){QHU_GETR(VQHU_ASTM(V))})
#define     VQHI_GETR(V)    ((Vdhi){QHI_GETR(VQHI_ASTM(V))})
#define     VQHF_GETR(V)    ((Vdhf){QHF_GETR(VQHF_ASTM(V))})
#define     VQWU_GETR(V)    ((Vdwu){QWU_GETR(VQWU_ASTM(V))})
#define     VQWI_GETR(V)    ((Vdwi){QWI_GETR(VQWI_ASTM(V))})
#define     VQWF_GETR(V)    ((Vdwf){QWF_GETR(VQWF_ASTM(V))})
#define     VQDU_GETR(V)    ((Vddu){QDU_GETR(VQDU_ASTM(V))})
#define     VQDI_GETR(V)    ((Vddi){QDI_GETR(VQDI_ASTM(V))})
#define     VQDF_GETR(V)    ((Vddf){QDF_GETR(VQDF_ASTM(V))})

#if 0 // _LEAVE_X86_GETR
}
#endif


double DBU_MULL(double a, double b)
{
    union {
        __m128i Z;
        __m128d F;
        struct {double Lo, Hi;};
    } xmm0, xmm1, xmm2;
    xmm0.Lo = a;
    xmm1.Lo = b;
    xmm0.Z  = _mm_unpacklo_epi8(xmm0.Z, _mm_setzero_si128());
    xmm1.Z  = _mm_unpacklo_epi8(xmm1.Z, _mm_setzero_si128());
    xmm2.Z  = _mm_maddubs_epi16(xmm0.Z, xmm1.Z);
    xmm0.Z  = _mm_shuffle_epi8(
        xmm2.Z,
        _mm_set1_epi64x(0x0e0c0a0806040200ull)
    );
    return xmm0.Lo;

}

#endif

#if 0 // _LEAVE_X86
}
#endif

INLINE(uint64_t,revydz) (uint64_t x) 
{
    x = ((x>>001)&0x5555555555555555ULL)|((x&0x5555555555555555ULL)<<001);
    x = ((x>>002)&0x3333333333333333ULL)|((x&0x3333333333333333ULL)<<002);
    x = ((x>>004)&0x0f0f0f0f0f0f0f0fULL)|((x&0x0f0f0f0f0f0f0f0fULL)<<004);
    x = ((x>>010)&0x00ff00ff00ff00ffULL)|((x&0x00ff00ff00ff00ffULL)<<010);
    x = ((x>>020)&0x0000ffff0000ffffULL)|((x&0x0000ffff0000ffffULL)<<020);
    x = ((x>>040)|(x<<040));
    return  x;
}

INLINE(__m128i,revyqqz) (__m128i x)
{
#undef MY_LHS
#undef MY_RHS
#define MY_LHS(N, M) _mm_and_si128(_mm_srli_epi64(x,N),_mm_set1_epi64x(M))
#define MY_RHS(N, M) _mm_slli_epi64(_mm_and_si128(x,_mm_set1_epi64x(M)),N)
    x = _mm_or_si128(MY_LHS(001,0x5555555555555555ULL));
    x = _mm_or_si128(MY_LHS(002,0x3333333333333333ULL));
    x = _mm_or_si128(MY_LHS(004,0x0f0f0f0f0f0f0f0fULL));
    x = _mm_or_si128(MY_LHS(010,0x00ff00ff00ff00ffULL));
    x = _mm_or_si128(MY_LHS(020,0x0000ffff0000ffffULL));
#undef MY_LHS
#undef MY_RHS
    return _mm_or_si128(_mm_srli_epi64(x,040),_mm_slli_epi64(x,040));

}

uint64_t revydux86(register uint64_t rdi)
{
    rdi = __builtin_bswap64(rdi);
    register uint64_t rax = rdi;
    rax >>= 4;
    register uint64_t rcx =  0xf0f0f0f0f0f0f0fULL;
    rax &= rcx;
    rdi &= rcx;
    rdi <<= 4;
    rdi |= rax;
    rax = 0x3333333333333333ULL;
    rcx = rdi;
    rcx &= rax;
    rdi >>= 2;
    rdi &= rax;
    rax = rdi+4*rcx;
    rcx = 0x5555555555555555ULL;
    register uint64_t rdx = rax;
    rdx &= rcx;
    rax >>= 1;
    rax &= rcx;
    rax = rax+2*rdx;
    return rax;
}
