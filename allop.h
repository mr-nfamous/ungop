/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Included by ungop.h to define the operations that are the
same on all platforms.

HISTORY:

2024-05-04
*   created allop.h
*   implemented cvbu, cvbi, cvbc, cvhu, cvhi, cvwu, cvwi, 
    cvwf, cvdi, cvdu, cvdi, and cvdf
*   moved void, astg, and asyu from ungop.h

2024-05-11
*   put astu, asti, and astf in their own sections
*   delete many extraneous spaces
*   fixed ashf return types (was int16_t, woops...)
*   fixed asdu/asdi

*/


#define       ADDR_VOID ((void *) 0)
#define       BOOL_VOID ((_Bool) 0)
#define      UCHAR_VOID ((uchar) 0)
#define      SCHAR_VOID ((schar) 0)
#define       CHAR_VOID ((char) 0)
#define      USHRT_VOID ((ushort) 0)
#define       SHRT_VOID ((short) 0)
#define       UINT_VOID (0u)
#define        INT_VOID (0)
#define      ULONG_VOID (0ul)
#define     ULLONG_VOID (0ull)
#define      LLONG_VOID (0ll)
#define        FLT_VOID (0.0f)
#define        DBL_VOID (0.0)

#if 0 // _ENTER_ALL_ASTG
{
#endif

#define      UCHAR_ASTG(X)  ( (UCHAR_STG(TYPE)){.U=X})
#define      SCHAR_ASTG(X)  ( (SCHAR_STG(TYPE)){.I=X})
#define       CHAR_ASTG(X)  (  (CHAR_STG(TYPE)){.C=X})
#define      USHRT_ASTG(X)  ( (USHRT_STG(TYPE)){.U=X})
#define       SHRT_ASTG(X)  (  (SHRT_STG(TYPE)){.I=X})
#define       UINT_ASTG(X)  (  (UINT_STG(TYPE)){.U=X})
#define        INT_ASTG(X)  (   (INT_STG(TYPE)){.I=X})
#define      ULONG_ASTG(X)  ( (ULONG_STG(TYPE)){.U=X})
#define       LONG_ASTG(X)  (  (LONG_STG(TYPE)){.I=X})
#define     ULLONG_ASTG(X)  ((ULLONG_STG(TYPE)){.U=X})
#define      LLONG_ASTG(X)  ( (LLONG_STG(TYPE)){.I=X})
#define      FLT16_ASTG(X)  ( (FLT16_STG(TYPE)){.F=X})
#define        FLT_ASTG(X)  (   (FLT_STG(TYPE)){.F=X})
#define        DBL_ASTG(X)  (   (DBL_STG(TYPE)){.F=X})

#if 0 // _LEAVE_ALL_ASTG
}
#endif

#if 0 // _ENTER_ALL_ASTU
{
#endif

#define       BOOL_ASTU    BOOL_ASYU
#define      UCHAR_ASTU   UCHAR_ASBU
#define      SCHAR_ASTU   SCHAR_ASBU
#define       CHAR_ASTU    CHAR_ASBU
#define      USHRT_ASTU   USHRT_ASHU
#define       SHRT_ASTU    SHRT_ASHU
#define       UINT_ASTU    UINT_ASWU
#define        INT_ASTU     INT_ASWU

#if DWRD_NLONG == 2
#   define   ULONG_ASTU   ULONG_ASWU
#   define    LONG_ASTU    LONG_ASWU
#else
#   define   ULONG_ASTU   ULONG_ASDU
#   define    LONG_ASTU    LONG_ASDU
#endif

#if QUAD_NLLONG == 2
#   define  ULLONG_ASTU  ULLONG_ASDU
#   define   LLONG_ASTU   LLONG_ASDU
#else
#   define  ULLONG_ASTU  ULLONG_ASQU
#   define   LLONG_ASTU   LLONG_ASQU
#endif

#define      FLT16_ASTU   FLT16_ASHU
#define        FLT_ASTU     FLT_ASWU
#define        DBL_ASTU     DBL_ASDU

//efine     VWBU_ASTU
#define     VWBI_ASTU       VWBI_ASBU
#define     VWBC_ASTU       VWBC_ASBU
//efine     VWHU_ASTU
#define     VWHI_ASTU       VWHI_ASHU
#define     VWHF_ASTU       VWHF_ASHU
//efine     VWWU_ASTU
#define     VWWI_ASTU       VWWI_ASWU
#define     VWWF_ASTU       VWWF_ASWU

//efine     VDBU_ASTU
#define     VDBI_ASTU       VDBI_ASBU
#define     VDBC_ASTU       VDBC_ASBU
//efine     VDHU_ASTU
#define     VDHI_ASTU       VDHI_ASHU
#define     VDHF_ASTU       VDHF_ASHU
//efine     VDWU_ASTU
#define     VDWI_ASTU       VDWI_ASWU
#define     VDWF_ASTU       VDWF_ASWU
//efine     VDDU_ASTU
#define     VDDI_ASTU       VDDI_ASDU
#define     VDDF_ASTU       VDDF_ASDU

//efine     VQBU_ASTU
#define     VQBI_ASTU       VQBI_ASBU
#define     VQBC_ASTU       VQBC_ASBU
//efine     VQHU_ASTU
#define     VQHI_ASTU       VQHI_ASHU
#define     VQHF_ASTU       VQHF_ASHU
//efine     VQWU_ASTU
#define     VQWI_ASTU       VQWI_ASWU
#define     VQWF_ASTU       VQWF_ASWU
//efine     VQDU_ASTU
#define     VQDI_ASTU       VQDI_ASDU
#define     VQDF_ASTU       VQDF_ASDU

#if 0 // _LEAVE_ALL_ASTU
}
#endif

#if 0 // _ENTER_ALL_ASTI
{
#endif

#define      UCHAR_ASTI   UCHAR_ASBI
#define      SCHAR_ASTI   SCHAR_ASBI
#define       CHAR_ASTI    CHAR_ASBI
#define      USHRT_ASTI   USHRT_ASHI
#define       SHRT_ASTI    SHRT_ASHI
#define       UINT_ASTI    UINT_ASWI
#define        INT_ASTI     INT_ASWI

#if DWRD_NLONG == 2
#   define   ULONG_ASTI   ULONG_ASWI
#   define    LONG_ASTI    LONG_ASWI
#else
#   define   ULONG_ASTI   ULONG_ASDI
#   define    LONG_ASTI    LONG_ASDI
#endif

#if QUAD_NLLONG == 2
#   define  ULLONG_ASTI  ULLONG_ASDI
#   define   LLONG_ASTI   LLONG_ASDI
#else
#   define  ULLONG_ASTI  ULLONG_ASQI
#   define   LLONG_ASTI   LLONG_ASQI
#endif

#define      FLT16_ASTI   FLT16_ASHI
#define        FLT_ASTI     FLT_ASWI
#define        DBL_ASTI     DBL_ASDI
#define     VWBU_ASTI       VWBU_ASBI
//efine     VWBI_ASTI
#define     VWBC_ASTI       VWBC_ASBI
#define     VWHU_ASTI       VWHU_ASHI
//efine     VWHI_ASTI
#define     VWHF_ASTI       VWHF_ASHI
#define     VWWU_ASTI       VWWU_ASWI
//efine     VWWI_ASTI
#define     VWWF_ASTI       VWWF_ASWI

#define     VDBU_ASTI       VDBU_ASBI
//efine     VDBI_ASTI
#define     VDBC_ASTI       VDBC_ASBI
#define     VDHU_ASTI       VDHU_ASHI
//efine     VDHI_ASTI
#define     VDHF_ASTI       VDHF_ASHI
#define     VDWU_ASTI       VDWU_ASWI
//efine     VDWI_ASTI
#define     VDWF_ASTI       VDWF_ASWI
#define     VDDU_ASTI       VDDU_ASDI
//efine     VDDI_ASTI
#define     VDDF_ASTI       VDDF_ASDI

#define     VQBU_ASTI       VQBU_ASBI
//efine     VQBI_ASTI
#define     VQBC_ASTI       VQBC_ASBI
#define     VQHU_ASTI       VQHU_ASHI
//efine     VQHI_ASTI
#define     VQHF_ASTI       VQHF_ASHI
#define     VQWU_ASTI       VQWU_ASWI
//efine     VQWI_ASTI
#define     VQWF_ASTI       VQWF_ASWI
#define     VQDU_ASTI       VQDU_ASDI
//efine     VQDI_ASTI
#define     VQDF_ASTI       VQDF_ASDI

#if 0 // _LEAVE_ALL_ASTI
}
#endif

#if 0 // _ENTER_ALL_ASTF
{
#endif

#define      USHRT_ASTF   USHRT_ASHF
#define       SHRT_ASTF    SHRT_ASHF
#define       UINT_ASTF    UINT_ASWF
#define        INT_ASTF     INT_ASWF

#if DWRD_NLONG == 2
#   define   ULONG_ASTF   ULONG_ASWF
#   define    LONG_ASTF    LONG_ASWF
#else
#   define   ULONG_ASTF   ULONG_ASDF
#   define    LONG_ASTF    LONG_ASDF
#endif

#if QUAD_NLLONG == 2
#   define  ULLONG_ASTF  ULLONG_ASDF
#   define   LLONG_ASTF   LLONG_ASDF
#else
#   define  ULLONG_ASTF  ULLONG_ASQF
#   define   LLONG_ASTF   LLONG_ASQF
#endif

#define      FLT16_ASTF   FLT16_ASHF
#define        FLT_ASTF     FLT_ASWF
#define        DBL_ASTF     DBL_ASDF

#define     VWHU_ASTF       VWHU_ASHF
#define     VWHI_ASTF       VWHI_ASHF
//efine     VWHF_ASTF
#define     VWWU_ASTF       VWWU_ASWF
#define     VWWI_ASTF       VWWI_ASWF
//efine     VWWF_ASTF

#define     VDHU_ASTF       VDHU_ASHF
#define     VDHI_ASTF       VDHI_ASHF
//efine     VDHF_ASTF
#define     VDWU_ASTF       VDWU_ASWF
#define     VDWI_ASTF       VDWI_ASWF
//efine     VDWF_ASTF
#define     VDDU_ASTF       VDDU_ASDF
#define     VDDI_ASTF       VDDI_ASDF
//efine     VDDF_ASTF

#define     VQHU_ASTF       VQHU_ASHF
#define     VQHI_ASTF       VQHI_ASHF
//efine     VQHF_ASTF
#define     VQWU_ASTF       VQWU_ASWF
#define     VQWI_ASTF       VQWI_ASWF
//efine     VQWF_ASTF
#define     VQDU_ASTF       VQDU_ASDF
#define     VQDI_ASTF       VQDI_ASDF
//efine     VQDF_ASTF

#if 0 // _LEAVE_ALL_ASTF
}
#endif

#if 0 // _ENTER_ALL_ASYU
{
#endif

INLINE(   _Bool,  BOOL_ASYU)   (_Bool x)
{
#define     BOOL_ASYU(X)   ((_Bool) X)
    return  x;
}

#if 0 // _LEAVE_ALL_ASYU
}
#endif

#if 0 // _ENTER_ALL_ASBU
{
#endif

INLINE(uint8_t,UCHAR_ASBU) (uchar x) {return x;}
INLINE(uint8_t,SCHAR_ASBU) (schar x) {return x;}
INLINE(uint8_t, CHAR_ASBU)  (char x) {return x;}

#if 0 // _LEAVE_ALL_ASBU
}
#endif

#if 0 // _ENTER_ALL_ASBI
{
#endif

INLINE(int8_t,UCHAR_ASBI) (uchar x) {return x;}
INLINE(int8_t,SCHAR_ASBI) (schar x) {return x;}
INLINE(int8_t, CHAR_ASBI)  (char x) {return x;}

#if 0 // _LEAVE_ALL_ASBI
}
#endif

#if 0 // _ENTER_ALL_ASBC
{
#endif

INLINE(char,UCHAR_ASBC) (uchar x) {return x;}
INLINE(char,SCHAR_ASBC) (schar x) {return x;}
INLINE(char, CHAR_ASBC)  (char x) {return x;}

#if 0 // _LEAVE_ALL_ASBC
}
#endif

#if 0 // _ENTER_ALL_ASHU
{
#endif

INLINE(uint16_t,USHRT_ASHU)  (ushort x) {return x;}
INLINE(uint16_t, SHRT_ASHU)   (short x) {return x;}
INLINE(uint16_t,FLT16_ASHU) (flt16_t x) {return FLT16_ASTG(x).U;}

#if 0 // _LEAVE_ALL_ASHU
}
#endif

#if 0 // _ENTER_ALL_ASHI
{
#endif

INLINE(int16_t,USHRT_ASHI)  (ushort x) {return x;}
INLINE(int16_t, SHRT_ASHI)   (short x) {return x;}
INLINE(int16_t,FLT16_ASHI) (flt16_t x) {return FLT16_ASTG(x).I;}

#if 0 // _LEAVE_ALL_ASHI
}
#endif

#if 0 // _ENTER_ALL_ASHF
{
#endif

INLINE(flt16_t,USHRT_ASHF)  (ushort x) {return USHRT_ASTG(x).F;}
INLINE(flt16_t, SHRT_ASHF)   (short x) {return  SHRT_ASTG(x).F;}
INLINE(flt16_t,FLT16_ASHF) (flt16_t x) {return x;}

#if 0 // _LEAVE_ALL_ASHF
}
#endif

#if 0 // _ENTER_ALL_ASWU
{
#endif

INLINE(uint32_t, UINT_ASWU)  (uint x) {return x;}
INLINE(uint32_t,  INT_ASWU)   (int x) {return x;}

#if DWRD_NLONG == 2
INLINE(uint32_t,ULONG_ASWU) (ulong x) {return x;}
INLINE(uint32_t, LONG_ASWU)  (long x) {return x;}
#endif

INLINE(uint32_t,  FLT_ASWU) (float x) {return FLT_ASTG(x).U;}

#if 0 // _LEAVE_ALL_ASWU
}
#endif

#if 0 // _ENTER_ALL_ASWI
{
#endif

INLINE(int32_t, UINT_ASWI)  (uint x) {return x;}
INLINE(int32_t,  INT_ASWI)   (int x) {return x;}

#if DWRD_NLONG == 2
INLINE(int32_t,ULONG_ASWI) (ulong x) {return x;}
INLINE(int32_t, LONG_ASWI)  (long x) {return x;}
#endif

INLINE(int32_t,  FLT_ASWI) (float x) {return FLT_ASTG(x).I;}

#if 0 // _LEAVE_ALL_ASWI
}
#endif

#if 0 // _ENTER_ALL_ASWF
{
#endif

INLINE(float, UINT_ASWF)  (uint x) {return  UINT_ASTG(x).F;}
INLINE(float,  INT_ASWF)   (int x) {return   INT_ASTG(x).F;}

#if DWRD_NLONG == 2
INLINE(float,ULONG_ASWF) (ulong x) {return ULONG_ASTG(x).F;}
INLINE(float, LONG_ASWF)  (long x) {return  LONG_ASTG(x).F;}
#endif

INLINE(float,  FLT_ASWF) (float x) {return x;}

#if 0 // _LEAVE_ALL_ASWF
}
#endif

#if 0 // _ENTER_ALL_ASDU
{
#endif

#if DWRD_NLONG == 1
INLINE(uint64_t, ULONG_ASDU)  (ulong x) {return x;}
INLINE(uint64_t,  LONG_ASDU)   (long x) {return x;}
#endif

#if QUAD_NLLONG == 2
INLINE(uint64_t,ULLONG_ASDU) (ullong x) {return x;}
INLINE(uint64_t, LLONG_ASDU)  (llong x) {return x;}
#endif

INLINE(uint64_t,   DBL_ASDU) (double x) {return DBL_ASTG(x).U;}

#if 0 // _LEAVE_ALL_ASDU
}
#endif

#if 0 // _ENTER_ALL_ASDI
{
#endif

#if DWRD_NLONG == 1
INLINE(int64_t, ULONG_ASDI)  (ulong x) {return x;}
INLINE(int64_t,  LONG_ASDI)   (long x) {return x;}
#endif

#if QUAD_NLLONG == 2
INLINE(int64_t,ULLONG_ASDI) (ullong x) {return x;}
INLINE(int64_t, LLONG_ASDI)  (llong x) {return x;}
#endif

INLINE(int64_t, DBL_ASDI) (double x) {return DBL_ASTG(x).I;}

#if 0 // _LEAVE_ALL_ASDI
}
#endif

#if 0 // _ENTER_ALL_ASDF
{
#endif

#if DWRD_NLONG == 1
INLINE(double, ULONG_ASDF)  (ulong x) {return ULONG_ASTG(x).F;}
INLINE(double,  LONG_ASDF)   (long x) {return  LONG_ASTG(x).F;}
#endif

#if QUAD_NLLONG == 2
INLINE(double,ULLONG_ASDF) (ullong x) {return ULLONG_ASTG(x).F;}
INLINE(double, LLONG_ASDF)  (llong x) {return  LLONG_ASTG(x).F;}
#endif

INLINE(double,   DBL_ASDF) (double x) {return x;}

#if 0 // _LEAVE_ALL_ASDF
}
#endif

#if 0 // _ENTER_ALL_ASQU
{
#endif

#if QUAD_NLLONG == 1
INLINE(ullong,ULLONG_ASQU) (ullong x) {return x;}
INLINE(ullong, LLONG_ASQU)  (llong x) {return x;}
INLINE(ullong,  LDBL_ASQU)   (ldbl x) {return ((QUAD_TYPE){.F=x}).U;}
#else
INLINE(QUAD_UTYPE,asququ) (QUAD_UTYPE x) {return x;}
INLINE(QUAD_UTYPE,asquqi) (QUAD_ITYPE x) {return ((QUAD_TYPE){.I=x}).U;}
INLINE(QUAD_UTYPE,asquqf) (QUAD_FTYPE x) {return ((QUAD_TYPE){.F=x}).U;}
#endif

#if 0 // _LEAVE_ALL_ASQU
}
#endif

#if 0 // _ENTER_ALL_ASQI
{
#endif

#if QUAD_NLLONG == 1
INLINE(llong,ULLONG_ASQI) (ullong x) {return x;}
INLINE(llong, LLONG_ASQI)  (llong x) {return x;}
INLINE(llong,  LDBL_ASQI)   (ldbl x) {return ((QUAD_TYPE){.F=x}).I;}
#else
INLINE(QUAD_ITYPE,asqiqu) (QUAD_UTYPE x) {return ((QUAD_TYPE){.U=x}).I;}
INLINE(QUAD_ITYPE,asqiqi) (QUAD_ITYPE x) {return x;}
INLINE(QUAD_ITYPE,asqiqf) (QUAD_FTYPE x) {return ((QUAD_TYPE){.F=x}).I;}
#endif

#if 0 // _LEAVE_ALL_ASQI
}
#endif

#if 0 // _ENTER_ALL_ASQF
{
#endif

#if QUAD_NLLONG == 1
INLINE(llong,ULLONG_ASQF) (ullong x) {return ((QUAD_TYPE){.U=x}).F;}
INLINE(llong, LLONG_ASQF)  (llong x) {return ((QUAD_TYPE){.I=x}).F;}
INLINE(llong,  LDBL_ASQF)   (ldbl x) {return x;}
#else
INLINE(QUAD_ITYPE,asqfqu) (QUAD_UTYPE x) {return ((QUAD_TYPE){.U=x}).F;}
INLINE(QUAD_ITYPE,asqfqi) (QUAD_ITYPE x) {return ((QUAD_TYPE){.I=x}).F;}
INLINE(QUAD_ITYPE,asqfqf) (QUAD_FTYPE x) {return x;}
#endif

#if 0 // _LEAVE_ALL_ASQF
}
#endif

#if 0 // _ENTER_ALL_SETL
{
#endif

INLINE(ushort, USHRT_SETL) (unsigned x, unsigned lo)
{
    HALF_TYPE v = {.U=x};
    v.Lo.U = lo;
    return v.U;
}

INLINE( short,  SHRT_SETL)  (signed x,    signed lo)
{
    HALF_TYPE v = {.I=x};
    v.Lo.U = lo;
    return v.I;
}

INLINE(  uint,  UINT_SETL)    (uint x,  unsigned lo)
{
    WORD_TYPE v = {.U=x};
    v.Lo.U = lo;
    return v.U;
}

INLINE(   int,   INT_SETL)     (int x,  unsigned lo)
{
    WORD_TYPE v = {.I=x};
    v.Lo.U = lo;
    return v.I;
}

#if DWRD_NLONG == 2

INLINE( ulong, ULONG_SETL)    (ulong x, unsigned lo)
{
    WORD_TYPE v = {.U=x};
    v.Lo.U = lo;
    return  v.U;
}

INLINE(  long,  LONG_SETL)     (long x,   signed lo)
{
    WORD_TYPE v = {.I=x};
    v.Lo.U = lo;
    return  v.I;
}

#else

INLINE( ulong, ULONG_SETL)    (ulong x, uint32_t lo)
{
    DWRD_TYPE v = {.U=x};
    v.Lo.U = lo;
    return  v.U;
}

INLINE(  long,  LONG_SETL)     (long x,  int32_t lo)
{
    DWRD_TYPE v = {.I=x};
    v.Lo.U = lo;
    return  v.I;
}

#endif

#if QUAD_NLLONG == 2

INLINE(ullong,ULLONG_SETL)   (ullong x, uint32_t lo)
{
    DWRD_TYPE v = {.U=x};
    v.Lo.U = lo;
    return v.U;
}

INLINE( llong, LLONG_SETL)    (llong x,  int32_t lo)
{
    DWRD_TYPE v = {.I=x};
    v.Lo.U = lo;
    return v.I;
}

#else

INLINE(ullong,ULLONG_SETL)   (ullong x, uint64_t lo)
{
    QUAD_TYPE v = {.U=x};
    v.Lo.U = lo;
    return v.U;
}

INLINE( llong,LLONG_SETL)     (llong x,  int64_t lo)
{
    QUAD_TYPE v = {.I=x};
    v.Lo.U = lo;
    return v.I;
}

#endif

#if 0 // _LEAVE_ALL_SETL
}
#endif

#if 0 // _ENTER_ALL_CATL
{
#endif

INLINE(uint16_t, UCHAR_CATL) (unsigned l, unsigned r)
{
#define     UCHAR_CATL(L, R) ((HALF_TYPE){.Lo.U=L,.Hi.U=R}).U
    return  UCHAR_CATL(l, r);
}

INLINE( int16_t, SCHAR_CATL)   (signed l,   signed r)
{
#define     SCHAR_CATL(L, R) ((HALF_TYPE){.Lo.I=L,.Hi.I=R}).I
    return  SCHAR_CATL(l, r);
}

#if CHAR_MIN

INLINE( int16_t,  CHAR_CATL)      (int l,      int r)
{
#define     CHAR_CATL(L, R) ((HALF_TYPE){.Lo.C=L,.Hi.C=R}).I
    return  CHAR_CATL(l, r);
}
#else

INLINE(uint16_t,  CHAR_CATL)      (int l,      int r)
{
#define     CHAR_CATL(L, R) ((HALF_TYPE){.Lo.C=L,.Hi.C=R}).U
    return  CHAR_CATL(l, r);
}
#endif

INLINE(uint32_t, USHRT_CATL) (unsigned l, unsigned r)
{
#define     USHRT_CATL(L, R) ((WORD_TYPE){.Lo.U=L,.Hi.U=R}).U
    return  USHRT_CATL(l, r);
}

INLINE( int32_t, SHRT_CATL)    (signed l,   signed r)
{
#define     SHRT_CATL(L, R) ((WORD_TYPE){.Lo.I=L,.Hi.I=R}).I
    return  SHRT_CATL(l, r);
}

INLINE(uint64_t, UINT_CATL)      (uint l,     uint r)
{
#define     UINT_CATL(L, R) ((DWRD_TYPE){.Lo.U=L,.Hi.U=R}).U
    return  UINT_CATL(l, r);
}

INLINE( int64_t,  INT_CATL)       (int l,      int r)
{
#define     INT_CATL(L, R) ((DWRD_TYPE){.Lo.I=L,.Hi.I=R}).I
    return  INT_CATL(l, r);
}

#if DWRD_NLONG == 2

INLINE(uint64_t,ULONG_CATL)     (ulong l,    ulong r) 
{
#define     ULONG_CATL(L, R) ((DWRD_TYPE){.Lo.U=L,.Hi.U=R}).U
    return  ULONG_CATL(l, r);
}

INLINE( int64_t, LONG_CATL)      (long l,     long r)
{
#define     LONG_CATL(L, R) ((DWRD_TYPE){.Lo.I=L,.Hi.I=R}).I
    return  LONG_CATL(l, r);
}

#else

INLINE(QUAD_UTYPE, ULONG_CATL)  (ulong l,    ulong r)
{
#define     ULONG_CATL(L, R) ((QUAD_TYPE){.Lo.U=L,.Hi.U=R}).U
    return  ULONG_CATL(l, r);
}

INLINE(QUAD_ITYPE,  LONG_CATL)   (long l,     long r)
{
#define     LONG_CATL(L, R) ((QUAD_TYPE){.Lo.I=L,.Hi.I=R}).I
    return  LONG_CATL(l, r);
}

#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,ULLONG_CATL) (ullong l, ullong r)
{
#define     ULLONG_CATL(L, R) ((QUAD_TYPE){.Lo.U=L,.Hi.U=R}).U
    return  ULLONG_CATL(l, r);
}

INLINE(QUAD_ITYPE, LLONG_CATL)  (llong l,  llong r)
{
#define     LLONG_CATL(L, R) ((QUAD_TYPE){.Lo.I=L,.Hi.I=R}).I
    return  LLONG_CATL(l, r);
}

#endif

#if 0 // _LEAVE_ALL_CATL
}
#endif

#if 0 // _ENTER_ALL_CVBU
{
#endif

INLINE(uint8_t,   BOOL_CVBU)    (_Bool x) {return x;}
INLINE(uint8_t,  UCHAR_CVBU) (unsigned x) {return x;}
INLINE(uint8_t,  SCHAR_CVBU)   (signed x) {return x;}
INLINE(uint8_t,   CHAR_CVBU)      (int x) {return x;}
INLINE(uint8_t,  USHRT_CVBU) (unsigned x) {return x;}
INLINE(uint8_t,   SHRT_CVBU)   (signed x) {return x;}
INLINE(uint8_t,   UINT_CVBU)     (uint x) {return x;}
INLINE(uint8_t,    INT_CVBU)      (int x) {return x;}
INLINE(uint8_t,  ULONG_CVBU)    (ulong x) {return x;}
INLINE(uint8_t,   LONG_CVBU)     (long x) {return x;}
INLINE(uint8_t, ULLONG_CVBU)   (ullong x) {return x;}
INLINE(uint8_t,  LLONG_CVBU)    (llong x) {return x;}
INLINE(uint8_t,   ADDR_CVBU) (void volatile const *x)
{
    return  (uintptr_t) x;
}

#if 0 // _LEAVE_ALL_CVBU
}
#endif

#if 0 // _ENTER_ALL_CVBI
{
#endif

INLINE(int8_t,   BOOL_CVBI)    (_Bool x) {return x;}
INLINE(int8_t,  UCHAR_CVBI) (unsigned x) {return x;}
INLINE(int8_t,  SCHAR_CVBI)   (signed x) {return x;}
INLINE(int8_t,   CHAR_CVBI)      (int x) {return x;}
INLINE(int8_t,  USHRT_CVBI) (unsigned x) {return x;}
INLINE(int8_t,   SHRT_CVBI)   (signed x) {return x;}
INLINE(int8_t,   UINT_CVBI)     (uint x) {return x;}
INLINE(int8_t,    INT_CVBI)      (int x) {return x;}
INLINE(int8_t,  ULONG_CVBI)    (ulong x) {return x;}
INLINE(int8_t,   LONG_CVBI)     (long x) {return x;}
INLINE(int8_t, ULLONG_CVBI)   (ullong x) {return x;}
INLINE(int8_t,  LLONG_CVBI)    (llong x) {return x;}
INLINE(int8_t,   ADDR_CVBI) (void volatile const *x)
{
    return  (intptr_t) x;
}

#if 0 // _LEAVE_ALL_CVBI
}
#endif

#if 0 // _ENTER_ALL_CVBC
{
#endif

INLINE(char,   BOOL_CVBC)    (_Bool x) {return x;}
INLINE(char,  UCHAR_CVBC) (unsigned x) {return x;}
INLINE(char,  SCHAR_CVBC)   (signed x) {return x;}
INLINE(char,   CHAR_CVBC)      (int x) {return x;}
INLINE(char,  USHRT_CVBC) (unsigned x) {return x;}
INLINE(char,   SHRT_CVBC)   (signed x) {return x;}
INLINE(char,   UINT_CVBC)     (uint x) {return x;}
INLINE(char,    INT_CVBC)      (int x) {return x;}
INLINE(char,  ULONG_CVBC)    (ulong x) {return x;}
INLINE(char,   LONG_CVBC)     (long x) {return x;}
INLINE(char, ULLONG_CVBC)   (ullong x) {return x;}
INLINE(char,  LLONG_CVBC)    (llong x) {return x;}
INLINE(char,   ADDR_CVBC) (void volatile const *x)
{
    return  (intptr_t) x;
}

#if 0 // _LEAVE_ALL_CVBC
}
#endif

#if 0 // _ENTER_ALL_CVHU
{
#endif

INLINE(uint16_t,   BOOL_CVHU)    (_Bool x) {return x;}
INLINE(uint16_t,  UCHAR_CVHU) (unsigned x) {return x;}
INLINE(uint16_t,  SCHAR_CVHU)   (signed x) {return x;}
INLINE(uint16_t,   CHAR_CVHU)      (int x) {return x;}
INLINE(uint16_t,  USHRT_CVHU) (unsigned x) {return x;}
INLINE(uint16_t,   SHRT_CVHU)   (signed x) {return x;}
INLINE(uint16_t,   UINT_CVHU)     (uint x) {return x;}
INLINE(uint16_t,    INT_CVHU)      (int x) {return x;}
INLINE(uint16_t,  ULONG_CVHU)    (ulong x) {return x;}
INLINE(uint16_t,   LONG_CVHU)     (long x) {return x;}
INLINE(uint16_t, ULLONG_CVHU)   (ullong x) {return x;}
INLINE(uint16_t,  LLONG_CVHU)    (llong x) {return x;}
INLINE(uint16_t,   ADDR_CVHU) (void volatile const *x)
{
    return  (uintptr_t) x;
}

#if 0 // _LEAVE_ALL_CVHU
}
#endif

#if 0 // _ENTER_ALL_CVHI
{
#endif

INLINE(int16_t,   BOOL_CVHI)    (_Bool x) {return x;}
INLINE(int16_t,  UCHAR_CVHI) (unsigned x) {return x;}
INLINE(int16_t,  SCHAR_CVHI)   (signed x) {return x;}
INLINE(int16_t,   CHAR_CVHI)      (int x) {return x;}
INLINE(int16_t,  USHRT_CVHI) (unsigned x) {return x;}
INLINE(int16_t,   SHRT_CVHI)   (signed x) {return x;}
INLINE(int16_t,   UINT_CVHI)     (uint x) {return x;}
INLINE(int16_t,    INT_CVHI)      (int x) {return x;}
INLINE(int16_t,  ULONG_CVHI)    (ulong x) {return x;}
INLINE(int16_t,   LONG_CVHI)     (long x) {return x;}
INLINE(int16_t, ULLONG_CVHI)   (ullong x) {return x;}
INLINE(int16_t,  LLONG_CVHI)    (llong x) {return x;}
INLINE(int16_t,   ADDR_CVHI) (void volatile const *x)
{
    return  (intptr_t) x;
}

#if 0 // _LEAVE_ALL_CVHI
}
#endif

#if 0 // _ENTER_ALL_CVWU
{
#endif

INLINE(uint32_t,   BOOL_CVWU)    (_Bool x) {return x;}
INLINE(uint32_t,  UCHAR_CVWU) (unsigned x) {return x;}
INLINE(uint32_t,  SCHAR_CVWU)   (signed x) {return x;}
INLINE(uint32_t,   CHAR_CVWU)      (int x) {return x;}
INLINE(uint32_t,  USHRT_CVWU) (unsigned x) {return x;}
INLINE(uint32_t,   SHRT_CVWU)   (signed x) {return x;}
INLINE(uint32_t,   UINT_CVWU)     (uint x) {return x;}
INLINE(uint32_t,    INT_CVWU)      (int x) {return x;}
INLINE(uint32_t,  ULONG_CVWU)    (ulong x) {return x;}
INLINE(uint32_t,   LONG_CVWU)     (long x) {return x;}
INLINE(uint32_t, ULLONG_CVWU)   (ullong x) {return x;}
INLINE(uint32_t,  LLONG_CVWU)    (llong x) {return x;}
INLINE(uint32_t,   ADDR_CVWU) (void volatile const *x)
{
    return  (uintptr_t) x;
}

#if 0 // _LEAVE_ALL_CVWU
}
#endif

#if 0 // _ENTER_ALL_CVWI
{
#endif

INLINE(int32_t,   BOOL_CVWI)    (_Bool x) {return x;}
INLINE(int32_t,  UCHAR_CVWI) (unsigned x) {return x;}
INLINE(int32_t,  SCHAR_CVWI)   (signed x) {return x;}
INLINE(int32_t,   CHAR_CVWI)      (int x) {return x;}
INLINE(int32_t,  USHRT_CVWI) (unsigned x) {return x;}
INLINE(int32_t,   SHRT_CVWI)   (signed x) {return x;}
INLINE(int32_t,   UINT_CVWI)     (uint x) {return x;}
INLINE(int32_t,    INT_CVWI)      (int x) {return x;}
INLINE(int32_t,  ULONG_CVWI)    (ulong x) {return x;}
INLINE(int32_t,   LONG_CVWI)     (long x) {return x;}
INLINE(int32_t, ULLONG_CVWI)   (ullong x) {return x;}
INLINE(int32_t,  LLONG_CVWI)    (llong x) {return x;}
INLINE(int32_t,   ADDR_CVWI) (void volatile const *x)
{
    return  (intptr_t) x;
}

#if 0 // _LEAVE_ALL_CVWI
}
#endif

#if 0 // _ENTER_ALL_CVDU
{
#endif

INLINE(uint64_t,   BOOL_CVDU)    (_Bool x) {return x;}
INLINE(uint64_t,  UCHAR_CVDU) (unsigned x) {return x;}
INLINE(uint64_t,  SCHAR_CVDU)   (signed x) {return x;}
INLINE(uint64_t,   CHAR_CVDU)      (int x) {return x;}
INLINE(uint64_t,  USHRT_CVDU) (unsigned x) {return x;}
INLINE(uint64_t,   SHRT_CVDU)   (signed x) {return x;}
INLINE(uint64_t,   UINT_CVDU)     (uint x) {return x;}
INLINE(uint64_t,    INT_CVDU)      (int x) {return x;}
INLINE(uint64_t,  ULONG_CVDU)    (ulong x) {return x;}
INLINE(uint64_t,   LONG_CVDU)     (long x) {return x;}
INLINE(uint64_t, ULLONG_CVDU)   (ullong x) {return x;}
INLINE(uint64_t,  LLONG_CVDU)    (llong x) {return x;}
INLINE(uint64_t,   ADDR_CVDU) (void volatile const *x)
{
    return  (uintptr_t) x;
}

#if 0 // _LEAVE_ALL_CVDU
}
#endif

#if 0 // _ENTER_ALL_CVDI
{
#endif

INLINE(int64_t,   BOOL_CVDI)    (_Bool x) {return x;}
INLINE(int64_t,  UCHAR_CVDI) (unsigned x) {return x;}
INLINE(int64_t,  SCHAR_CVDI)   (signed x) {return x;}
INLINE(int64_t,   CHAR_CVDI)      (int x) {return x;}
INLINE(int64_t,  USHRT_CVDI) (unsigned x) {return x;}
INLINE(int64_t,   SHRT_CVDI)   (signed x) {return x;}
INLINE(int64_t,   UINT_CVDI)     (uint x) {return x;}
INLINE(int64_t,    INT_CVDI)      (int x) {return x;}
INLINE(int64_t,  ULONG_CVDI)    (ulong x) {return x;}
INLINE(int64_t,   LONG_CVDI)     (long x) {return x;}
INLINE(int64_t, ULLONG_CVDI)   (ullong x) {return x;}
INLINE(int64_t,  LLONG_CVDI)    (llong x) {return x;}
INLINE(int64_t,   ADDR_CVDI) (void volatile const *x)
{
    return  (intptr_t) x;
}

#if 0 // _LEAVE_ALL_CVDI
}
#endif

#if 0 // _ENTER_ARM_LUNN
{
#endif
/*
All presently supported compilers provide a way to define
"packed" structs, which can be loaded from any address.
*/

#ifdef SPC_NO_LUNN

INLINE(  _Bool,  BOOL_LUNNAC) (void const *a) {return *(_Bool const *) a;}

INLINE(  uchar, UCHAR_LUNNAC) (void const *a) {return *(uchar const *) a;}
INLINE(  schar, SCHAR_LUNNAC) (void const *a) {return *(schar const *) a;}
INLINE(   char,  CHAR_LUNNAC) (void const *a) {return  *(char const *) a;}

INLINE( ushort, USHRT_LUNNAC) (void const *a)
{
    return ((USHRT_STG(TYPE) const *) a)->M.U;
}

INLINE(   short, SHRT_LUNNAC) (void const *a)
{
    return ((SHRT_STG(TYPE) const *) a)->M.I;
}

INLINE(   uint,  UINT_LUNNAC) (void const *a)
{
    return ((UINT_STG(TYPE) const *) a)->M.U;
}

INLINE(    int,   INT_LUNNAC) (void const *a)
{
    return  ((INT_STG(TYPE) const *) a)->M.I;
}

INLINE(  ulong, ULONG_LUNNAC) (void const *a)
{
    return  ((ULONG_STG(TYPE) const *) a)->M.U;
}

INLINE(   long,  LONG_LUNNAC) (void const *a)
{
    return  ((LONG_STG(TYPE) const *) a)->M.I;
}

INLINE( ullong,ULLONG_LUNNAC) (void const *a)
{
    return  ((ULLONG_STG(TYPE) const *) a)->M.U;
}

INLINE(  llong, LLONG_LUNNAC) (void const *a)
{
    return  ((LLONG_STG(TYPE) const *) a)->M.I;
}

INLINE(flt16_t, FLT16_LUNNAC) (void const *a)
{
    return  ((FLT16_STG(TYPE) const *) a)->M.F;
}

INLINE(  float,   FLT_LUNNAC) (void const *a)
{
    return  ((FLT_STG(TYPE) const *) a)->M.F;
}

INLINE( double,   DBL_LUNNAC) (void const *a)
{
    return  ((DBL_STG(TYPE) const *) a)->M.F;
}

#endif // defined(SPC_NO_LUNN)

#if 0 // _LEAVE_ARM_LUNN
}
#endif

#if 0 // _ENTER_ALL_LUNW
{
#endif

#ifdef SPC_NO_LUNW

INLINE(Vwyu,BOOL_LUNWAC) (void const *a)
{
#define     BOOL_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M32.U)

    return  BOOL_LUNWAC(a);
}

INLINE(Vwbu,UCHAR_LUNWAC) (void const *a)
{
#define     UCHAR_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M4.U)

    return  UCHAR_LUNWAC(a);
}

INLINE(Vwbi,SCHAR_LUNWAC) (void const *a)
{
#define     SCHAR_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M4.I)

    return  SCHAR_LUNWAC(a);
}

INLINE(Vwbc,CHAR_LUNWAC) (void const *a)
{
#define     CHAR_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M4.C)

    return  CHAR_LUNWAC(a);
}

INLINE(Vwhu,USHRT_LUNWAC) (void const *a)
{
#define     USHRT_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M2.U)

    return  USHRT_LUNWAC(a);
}

INLINE(Vwhi,SHRT_LUNWAC) (void const *a)
{
#define     SHRT_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M2.I)

    return  SHRT_LUNWAC(a);
}

INLINE(Vwwu,UINT_LUNWAC) (void const *a)
{
#define     UINT_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M1.U)

    return  UINT_LUNWAC(a);
}

INLINE(Vwwi,INT_LUNWAC) (void const *a)
{
#define     INT_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M1.I)

    return  INT_LUNWAC(a);
}


#if DWRD_NLONG == 2

INLINE(Vwwu,ULONG_LUNWAC) (void const *a)
{
#define     ULONG_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M1.U)

    return  ULONG_LUNWAC(a);
}

INLINE(Vdwi,LONG_LUNDAC) (void const *a)
{
#define     LONG_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M1.I)

    return  LONG_LUNWAC(a);
}

#endif // DWRD_NLONG == 2

INLINE(Vwhf,FLT16_LUNWAC) (void const *a)
{
#define     FLT16_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M2.F)

    return  FLT16_LUNWAC(a);
}

INLINE(Vwwf,FLT_LUNWAC) (void const *a)
{
#define     FLT_LUNWAC(A)  \
(((WORD_TYPE){.U=((WORD_TYPE const *) A)->M.U}).M1.F)

    return  FLT_LUNWAC(a);
}

#endif // defined(SPC_NO_LUNW)

#if 0 // _LEAVE_ARM_LUNW
}
#endif

#if 0 // _ENTER_ALL_LUND
{
#endif

#ifdef SPC_NO_LUND

INLINE(Vdyu,BOOL_LUNDAC) (void const *a)
{
#define     BOOL_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M64.U)

    return  BOOL_LUNDAC(a);
}


INLINE(Vdbu,UCHAR_LUNDAC) (void const *a)
{
#define     UCHAR_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M8.U)

    return  UCHAR_LUNDAC(a);
}

INLINE(Vdbi,SCHAR_LUNDAC) (void const *a)
{
#define     SCHAR_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M8.I)

    return  SCHAR_LUNDAC(a);
}

INLINE(Vdbc,CHAR_LUNDAC) (void const *a)
{
#define     CHAR_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M8.C)

    return  CHAR_LUNDAC(a);
}


INLINE(Vdhu,USHRT_LUNDAC) (void const *a)
{
#define     USHRT_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M4.U)

    return  USHRT_LUNDAC(a);
}

INLINE(Vdhi,SHRT_LUNDAC) (void const *a)
{
#define     SHRT_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M4.I)

    return  SHRT_LUNDAC(a);
}


INLINE(Vdwu,UINT_LUNDAC) (void const *a)
{
#define     UINT_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M2.U)

    return  UINT_LUNDAC(a);
}

INLINE(Vdwi,INT_LUNDAC) (void const *a)
{
#define     INT_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M2.I)

    return  INT_LUNDAC(a);
}


#if DWRD_NLONG == 1

INLINE(Vddu,ULONG_LUNDAC) (void const *a)
{
#define     ULONG_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M1.U)

    return  ULONG_LUNDAC(a);
}

INLINE(Vddi,LONG_LUNDAC) (void const *a)
{
#define     LONG_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M1.I)

    return  LONG_LUNDAC(a);
}

#else

INLINE(Vdwu,ULONG_LUNDAC) (void const *a)
{
#define     ULONG_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M2.U)

    return  ULONG_LUNDAC(a);
}

INLINE(Vdwi,LONG_LUNDAC) (void const *a)
{
#define     LONG_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M2.I)

    return  LONG_LUNDAC(a);
}

#endif // DWRD_NLONG == 2

#if QUAD_NLLONG == 2

INLINE(Vddu,ULLONG_LUNDAC) (void const *a)
{
#define     ULLONG_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M1.U)

    return  ULLONG_LUNDAC(a);
}

INLINE(Vddi,LLONG_LUNDAC) (void const *a)
{
#define     LLONG_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M1.I)

    return  LLONG_LUNDAC(a);
}

#endif


INLINE(Vdhf,FLT16_LUNDAC) (void const *a)
{
#define     FLT16_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M4.F)

    return  FLT16_LUNDAC(a);
}

INLINE(Vdwf,FLT_LUNDAC) (void const *a)
{
#define     FLT_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M2.F)

    return  FLT_LUNDAC(a);
}

INLINE(Vddf,DBL_LUNDAC) (void const *a)
{
#define     DBL_LUNDAC(A)  \
(((DWRD_TYPE){.U=((DWRD_TYPE const *) A)->M.U}).M1.F)

    return  DBL_LUNDAC(a);
}

#endif // defined(SPC_NO_LUND)

#if 0 // _LEAVE_ARM_LUND
}
#endif

#if 0 // _ENTER_ALL_LUNQ
{
#endif

#ifdef SPC_NO_LUNQ

INLINE(Vqyu,BOOL_LUNQAC) (void const *a)
{
#define     BOOL_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M128.U)

    return  BOOL_LUNQAC(a);
}


INLINE(Vqbu,UCHAR_LUNQAC) (void const *a)
{
#define     UCHAR_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M16.U)

    return  UCHAR_LUNQAC(a);
}

INLINE(Vqbi,SCHAR_LUNQAC) (void const *a)
{
#define     SCHAR_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M16.I)

    return  SCHAR_LUNQAC(a);
}

INLINE(Vqbc,CHAR_LUNQAC) (void const *a)
{
#define     CHAR_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M16.C)

    return  CHAR_LUNQAC(a);
}


INLINE(Vqhu,USHRT_LUNQAC) (void const *a)
{
#define     USHRT_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M8.U)

    return  USHRT_LUNQAC(a);
}

INLINE(Vqhi,SHRT_LUNQAC) (void const *a)
{
#define     SHRT_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M8.I)

    return  SHRT_LUNQAC(a);
}


INLINE(Vqwu,UINT_LUNQAC) (void const *a)
{
#define     UINT_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M4.U)

    return  UINT_LUNQAC(a);
}

INLINE(Vqwi,INT_LUNQAC) (void const *a)
{
#define     INT_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M4.I)

    return  INT_LUNQAC(a);
}


#if DWRD_NLONG == 1

INLINE(Vqdu,ULONG_LUNQAC) (void const *a)
{
#define     ULONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M2.U)

    return  ULONG_LUNQAC(a);
}

INLINE(Vqdi,LONG_LUNQAC) (void const *a)
{
#define     LONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M2.I)

    return  LONG_LUNQAC(a);
}

#else

INLINE(Vqwu,ULONG_LUNQAC) (void const *a)
{
#define     ULONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M4.U)

    return  ULONG_LUNQAC(a);
}

INLINE(Vqwi,LONG_LUNQAC) (void const *a)
{
#define     LONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M4.I)

    return  LONG_LUNQAC(a);
}

#endif // QUAD_NLONG == 2

#if QUAD_NLLONG == 1

INLINE(Vqqu,ULLONG_LUNQAC) (void const *a)
{
#define     ULLONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M1.U)

    return  ULLONG_LUNQAC(a);
}

INLINE(Vqqi,LLONG_LUNQAC) (void const *a)
{
#define     LLONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M1.I)

    return  LLONG_LUNQAC(a);
}

#else

INLINE(Vqdu,ULLONG_LUNQAC) (void const *a)
{
#define     ULLONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M2.U)

    return  ULLONG_LUNQAC(a);
}

INLINE(Vqdi,LLONG_LUNQAC) (void const *a)
{
#define     LLONG_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M2.I)

    return  LLONG_LUNQAC(a);
}

#endif


INLINE(Vqhf,FLT16_LUNQAC) (void const *a)
{
#define     FLT16_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M8.F)

    return  FLT16_LUNQAC(a);
}

INLINE(Vqwf,FLT_LUNQAC) (void const *a)
{
#define     FLT_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M4.F)

    return  FLT_LUNQAC(a);
}

INLINE(Vqdf,DBL_LUNQAC) (void const *a)
{
#define     DBL_LUNQAC(A)  \
(((QUAD_TYPE){.U=((QUAD_TYPE const *) A)->M.U}).M2.F)

    return  DBL_LUNQAC(a);
}

#endif // defined(SPC_NO_LUNQ)

#if 0 // _LEAVE_ARM_LUNQ
}
#endif

#if 0 // _ENTER_ALL_GET1
{
#endif

INLINE(_Bool, UCHAR_GET1) (unsigned a, Rc(0, UCHAR_WIDTH-1) b)
{
#define     UCHAR_GET1(A, B) ((_Bool) (1&(((uchar) A)>>B)))
    return  1&((uchar) a>>b);
}

INLINE(_Bool, SCHAR_GET1)   (signed a, Rc(0, SCHAR_WIDTH-1) b)
{
#define     SCHAR_GET1(A, B) ((_Bool) (1&(((schar) A)>>B)))
    return  1&((schar) a>>b);
}

INLINE(_Bool, CHAR_GET1)       (int a, Rc(0, CHAR_WIDTH-1) b)
{
#define     CHAR_GET1(A, B) ((_Bool) (1&(((char) A)>>B)))
    return  1&((char) a>>b);
}


INLINE(_Bool, USHRT_GET1) (unsigned a, Rc(0, USHRT_WIDTH-1) b)
{
#define     USHRT_GET1(A, B) ((_Bool) (1&(((ushort) A)>>B)))
    return  1&((ushort) a>>b);
}

INLINE(_Bool,  SHRT_GET1)   (signed a, Rc(0,  SHRT_WIDTH-1) b)
{
#define     SHRT_GET1(A, B) ((_Bool) (1&(((short) A)>>B)))
    return  1&((short) a>>b);
}

INLINE(_Bool, UINT_GET1)      (uint a, Rc(0, UINT_WIDTH-1) b)
{
#define     UINT_GET1(A, B) ((_Bool) (1&(((uint) A)>>B)))
    return  1&((uint) a>>b);
}

INLINE(_Bool,  INT_GET1)       (int a, Rc(0,  INT_WIDTH-1) b)
{
#define     INT_GET1(A, B) ((_Bool) (1&(((int) A)>>B)))
    return  1&((int) a>>b);
}

INLINE(_Bool, ULONG_GET1)   (ulong a, Rc(0,  ULONG_WIDTH-1) b)
{
#define     ULONG_GET1(A, B) ((_Bool) (1&(((ulong) A)>>B)))
    return  1&((ulong) a>>b);
}

INLINE(_Bool, LONG_GET1)   (long a, Rc(0, LONG_WIDTH-1) b)
{
#define     LONG_GET1(A, B) ((_Bool) (1&(((long) A)>>B)))
    return  1&((long) a>>b);
}

INLINE(_Bool, ULLONG_GET1)   (ullong a, Rc(0, ULLONG_WIDTH-1) b)
{
#define     ULLONG_GET1(A, B) ((_Bool) (1&(((ullong) A)>>B)))
    return  1&((ullong) a>>b);
}

INLINE(_Bool, LLONG_GET1)   (llong a, Rc(0, LLONG_WIDTH-1) b)
{
#define     LLONG_GET1(A, B) ((_Bool) (1&(((llong) A)>>B)))
    return  1&((llong) a>>b);
}

#ifdef SPC_NO_GET1

INLINE(  _Bool, VWYU_GET1) (Vwyu a, Rc(0, 31) b)
{
    return  ((WORD_TYPE){.M32.U=a}).U>>b;
}


INLINE( uint8_t,VWBU_GET1) (Vwbu a, Rc(0, 3) b)
{
    return ((WORD_TYPE){.M4.U=a}).U>>(8*b);
}

INLINE(  int8_t,VWBI_GET1) (Vwbi a, Rc(0, 3) b)
{
    return ((WORD_TYPE){.M4.I=a}).U>>(8*b);
}

INLINE(    char,VWBC_GET1) (Vwbc a, Rc(0, 3) b)
{
    return ((WORD_TYPE){.M4.C=a}).U>>(8*b);
}


INLINE(uint16_t,VWHU_GET1) (Vwhu a, Rc(0, 1) b)
{
    return ((WORD_TYPE){.M2.U=a}).U>>(16*b);
}

INLINE( int16_t,VWHI_GET1) (Vwhi a, Rc(0, 1) b)
{
    return ((WORD_TYPE){.M2.I=a}).U>>(16*b);
}

INLINE( flt16_t,VWHF_GET1) (Vwhf a, Rc(0, 1) b)
{
    WORD_TYPE c = {.M2.F=a};
    c.U >>= 16*b;
    return  c.H0.F;
}


INLINE(   _Bool,VDYU_GET1) (Vdyu a, Rc(0, 63) b)
{
    return  ((DWRD_TYPE){.M64.U=a}).U>>b;
}


INLINE( uint8_t,VDBU_GET1) (Vdbu a, Rc(0, 7) b)
{
    return  ((DWRD_TYPE){.M8.U=a}).U>>(8*b);
}

INLINE(  int8_t,VDBI_GET1) (Vdbi a, Rc(0, 7) b)
{
    return  ((DWRD_TYPE){.M8.I=a}).U>>(8*b);
}

INLINE(    char,VDBC_GET1) (Vdbc a, Rc(0, 7) b)
{
    return  ((DWRD_TYPE){.M8.C=a}).U>>(8*b);
}


INLINE(uint16_t,VDHU_GET1) (Vdhu a, Rc(0, 3) b)
{
    return  ((DWRD_TYPE){.M4.U=a}).U>>(16*b);
}

INLINE( int16_t,VDHI_GET1) (Vdhi a, Rc(0, 3) b)
{
    return  ((DWRD_TYPE){.M4.I=a}).U>>(16*b);
}

INLINE( flt16_t,VDHF_GET1) (Vdhf a, Rc(0, 3) b)
{
    DWRD_TYPE c = {.M4.F=a};
    c.U >>= 16*b;
    return  c.H0.F;
}


INLINE(uint32_t,VDWU_GET1) (Vdwu a, Rc(0, 1) b)
{
    return  ((DWRD_TYPE){.M2.U=a}).U>>(32*b);
}

INLINE( int32_t,VDWI_GET1) (Vdwi a, Rc(0, 1) b)
{
    return  ((DWRD_TYPE){.M2.I=a}).U>>(32*b);
}

INLINE(   float,VDWF_GET1) (Vdwf a, Rc(0, 1) b)
{
    DWRD_TYPE c = {.M2.F=a};
    c.U >>= 32*b;
    return  c.W0.F;
}


INLINE(   _Bool,VQYU_GET1) (Vqyu a, Rc(0, 127) b)
{
    QUAD_TYPE const v = {.M128.U=a};
    if (b < 64) return 1&(v.Lo.U>>b);
    return  1&(v.Hi.U>>(b-64));
}

INLINE( uint8_t,VQBU_GET1) (Vqbu a, Rc(0, 15) b)
{
    QUAD_TYPE const v = {.M16.U=a};
    if (b < 8) return UINT8_MAX&(v.Lo.U>>(8*b));
    return  UINT8_MAX&(v.Hi.U>>(8*(b-8)));
}

INLINE(  int8_t,VQBI_GET1) (Vqbi a, Rc(0, 15) b)
{
    QUAD_TYPE const v = {.M16.I=a};
    if (b < 8) return UINT8_MAX&(v.Lo.U>>(8*b));
    return  UINT8_MAX&(v.Hi.U>>(8*(b-8)));
}

INLINE(    char,VQBC_GET1) (Vqbc a, Rc(0, 15) b)
{
    QUAD_TYPE const v = {.M16.C=a};
    if (b < 8) return UINT8_MAX&(v.Lo.U>>(8*b));
    return  UINT8_MAX&(v.Hi.U>>(8*(b-8)));
}


INLINE(uint16_t,VQHU_GET1) (Vqhu a, Rc(0, 7) b)
{
    QUAD_TYPE const v = {.M8.U=a};
    if (b < 4) return UINT16_MAX&(v.Lo.U>>(16*b));
    return  UINT16_MAX&(v.Hi.U>>(16*(b-4)));
}

INLINE( int16_t,VQHI_GET1) (Vqhi a, Rc(0, 7) b)
{
    QUAD_TYPE const v = {.M8.I=a};
    if (b < 4) return UINT16_MAX&(v.Lo.U>>(16*b));
    return  UINT16_MAX&(v.Hi.U>>(16*(b-4)));
}

INLINE( flt16_t,VQHF_GET1) (Vqhf a, Rc(0, 7) b)
{
    QUAD_TYPE   v = {.M8.F=a};
    if (b < 4)  v.Lo.U = v.Lo.U>>(16*b);
    else        v.Lo.U = v.Hi.U>>(16*(b-4));
    return      v.Lo.H0.F;
}


INLINE(uint32_t,VQWU_GET1) (Vqwu a, Rc(0, 3) b)
{
    QUAD_TYPE const v = {.M4.U=a};
    if (b < 2) return UINT32_MAX&(v.Lo.U>>(32*b));
    return  UINT32_MAX&(v.Hi.U>>(32*(b-2)));
}

INLINE( int32_t,VQWI_GET1) (Vqwi a, Rc(0, 3) b)
{
    QUAD_TYPE const v = {.M4.I=a};
    if (b < 2) return UINT32_MAX&(v.Lo.U>>(32*b));
    return  UINT32_MAX&(v.Hi.U>>(32*(b-2)));
}

INLINE(   float,VQWF_GET1) (Vqwf a, Rc(0, 3) b)
{
    QUAD_TYPE   v = {.M4.F=a};
    if (b < 4)  v.Lo.U = v.Lo.U>>(32*b);
    else        v.Lo.U = v.Hi.U>>(32*(b-2));
    return      v.Lo.W0.F;
}


INLINE(uint64_t,VQDU_GET1) (Vqdu a, Rc(0, 1) b)
{
    QUAD_TYPE const v = {.M2.U=a};
    return  !b ? v.Lo.U : v.Hi.U;
}

INLINE( int64_t,VQDI_GET1) (Vqdi a, Rc(0, 1) b)
{
    QUAD_TYPE const v = {.M2.I=a};
    return  !b ? v.Lo.I : v.Hi.I;
}

INLINE(  double,VQDF_GET1) (Vqdf a, Rc(0, 1) b)
{
    QUAD_TYPE const v = {.M2.F=a};
    return  !b ? v.Lo.F : v.Hi.F;
}

#endif // defined(SPC_NO_GET1)

#if 0 // _LEAVE_ALL_GET1
}
#endif

#if 0 // _ENTER_ALL_GETL
{
#endif

INLINE( uint8_t, USHRT_GETL) (unsigned x) 
{
#define     USHRT_GETL(X) (((HALF_TYPE){.U=X}).Lo.U)
    return  x;
}

INLINE(  int8_t,  SHRT_GETL)  (signed x)
{
#define     SHRT_GETL(X) (((HALF_TYPE){.I=X}).Lo.I)
    return  x;
}


INLINE(uint16_t,  UINT_GETL)   (uint x)
{
#define     UINT_GETL(X) (((WORD_TYPE){.U=X}).Lo.U)
    return  x;
}

INLINE( int16_t,   INT_GETL)    (int x)
{
#define     INT_GETL(X) (((WORD_TYPE){.I=X}).Lo.I)
    return  x;
}


#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_GETL)  (ulong x)
{
#define     ULONG_GETL(X) (((WORD_TYPE){.U=X}).Lo.U)
    return  x;
}

INLINE( int16_t,  LONG_GETL)   (long x)
{
#define     LONG_GETL(X) (((WORD_TYPE){.I=X}).Lo.I)
    return  x;
}

#else

INLINE(uint32_t, ULONG_GETL)  (ulong x)
{
#define     ULONG_GETL(X) (((DWRD_TYPE){.U=X}).Lo.I)
    return  x;
}

INLINE( int32_t,  LONG_GETL)   (long x)
{
#define     LONG_GETL(X) (((DWRD_TYPE){.I=X}).Lo.I)
    return  x;
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_GETL) (ullong x)
{
#define     ULLONG_GETL(X) (((DWRD_TYPE){.U=X}).Lo.U)
    return  x;
}

INLINE( int32_t, LLONG_GETL)  (llong x)
{
#define     LLONG_GETL(X) (((DWRD_TYPE){.I=X}).Lo.I)
    return  x;
}

#endif

#if 0 // _LEAVE_ALL_GETL
}
#endif

#if 0 // _ENTER_ALL_GETR
{
#endif

INLINE( uint8_t, USHRT_GETR) (unsigned x) 
{
#define     USHRT_GETR(X) (((HALF_TYPE){.U=X}).Hi.U)
    return  x>>(USHRT_WIDTH>>1);
}

INLINE(  int8_t,  SHRT_GETR)   (signed x)
{
#define     SHRT_GETR(X) (((HALF_TYPE){.I=X}).Hi.I)
    return  SHRT_GETR(x);
}


INLINE(uint16_t,  UINT_GETR)     (uint x)
{
#define     UINT_GETR(X) (((WORD_TYPE){.U=X}).Hi.U)
    return  x>>(UINT_WIDTH>>1);
}

INLINE( int16_t,   INT_GETR)      (int x)
{
#define     INT_GETR(X) (((WORD_TYPE){.I=X}).Hi.I)
    return  INT_GETR(x);
}

#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_GETR)    (ulong x)
{
#define     ULONG_GETR(X) (((WORD_TYPE){.U=X}).Hi.U)
    return  x>>(ULONG_WIDTH>>1);
}

INLINE( int16_t,  LONG_GETR)   (long x)
{
#define     LONG_GETR(X) (((WORD_TYPE){.I=X}).Hi.I)
    return  LONG_GETR(x);
}

#else

INLINE(uint32_t, ULONG_GETR)  (ulong x)
{
#define     ULONG_GETR(X) (((DWRD_TYPE){.U=X}).Hi.I)
    return  x>>(ULONG_WIDTH>>1);
}

INLINE( int32_t,  LONG_GETR)   (long x)
{
#define     LONG_GETR(X) (((DWRD_TYPE){.I=X}).Hi.I)
    return  LONG_GETR(x);
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_GETR) (ullong x)
{
#define     ULLONG_GETR(X) (((DWRD_TYPE){.U=X}).Hi.U)
    return  x>>(ULLONG_WIDTH>>1);
}

INLINE( int32_t, LLONG_GETR)  (llong x)
{
#define     LLONG_GETR(X) (((DWRD_TYPE){.I=X}).Hi.I)
    return  LLONG_GETR(x);
}

#else

INLINE(uint64_t,ULLONG_GETR) (ullong x)
{
#define     ULLONG_GETR(X) (((QUAD_TYPE){.U=X}).Hi.U)
    return  x>>(ULLONG_WIDTH>>1);
}

INLINE( int64_t, LLONG_GETR)  (llong x)
{
#define     LLONG_GETR(X) (((QUAD_TYPE){.I=X}).Hi.I)
    return  LLONG_GETR(x);
}

#endif

#if 0 // _LEAVE_ALL_GETR
}
#endif

#if 0 // _ENTER_ALL_DUPW
{
#endif

#ifdef SPC_NO_DUPW

INLINE(Vwyu,BOOL_DUPW) (_Bool x)
{
    WORD_TYPE r = {.I=-x};
    return  r.M32.U;
}


INLINE(Vwbu,UCHAR_DUPW) (unsigned x)
{
#define     UCHAR_DUPW(X) ((Vwbu){X,X,X,X})
    return  UCHAR_DUPW(x);
}

INLINE(Vwbi,SCHAR_DUPW) (signed x)
{
#define     SCHAR_DUPW(X) ((Vwbi){X,X,X,X})
    return  SCHAR_DUPW(x);
}

INLINE(Vwbc, CHAR_DUPW)  (int x)
{
#define     CHAR_DUPW(X) ((Vwbc){X,X,X,X})
    return  CHAR_DUPW(x);
}


INLINE(Vwhu,USHRT_DUPW) (unsigned x)
{
#define     USHRT_DUPW(X) ((Vwhu){X,X})
    return  USHRT_DUPW(x);
}

INLINE(Vwhi,SHRT_DUPW) (signed x)
{
#define     SHRT_DUPW(X) ((Vwhi){X,X})
    return  SHRT_DUPW(x);
}

INLINE(Vwwu,UINT_DUPW) (uint x)
{
#define     UINT_DUPW(X)    ((Vwwu){X})
    return  UINT_DUPW(x);
}

INLINE(Vwwi, INT_DUPW) (int x)
{
#define     INT_DUPW(X)     ((Vwwi){X})
    return  INT_DUPW(x);
}

#if DWRD_NLONG == 2

INLINE(Vwwu,ULONG_DUPW) (ulong x)
{
#define     ULONG_DUPW(X)   ((Vwwu){X})
    return  ULONG_DUPW(x);
}

INLINE(Vwwi, LONG_DUPW) (long x)
{
#define     LONG_DUPW(X)    ((Vwwi){X})
    return  LONG_DUPW(x);
}

#endif

INLINE(Vwhf,FLT16_DUPW) (flt16_t x)
{
#define     FLT16_DUPW(X) ((Vwhf){X,X})
    return  FLT16_DUPW(x);
}

INLINE(Vwwf, FLT_DUPW) (float x)
{
    return  (Vwwf){x};
}


INLINE(Vwyu,BOOL_DUPWAC) (void const *a)
{
    WORD_TYPE const v = {.U=0-*(_Bool const *) a};
    return  v.M32.U;
}

INLINE(Vwbu,UCHAR_DUPWAC) (void const *a)
{
    unsigned const x = *(uchar const *) a;
    return  ((Vwbu){x,x,x,x});
}

INLINE(Vwbi,SCHAR_DUPWAC) (void const *a)
{
    signed const x = *(schar const *) a;
    return  ((Vwbi){x,x,x,x});
}

INLINE(Vwbc,CHAR_DUPWAC) (void const *a)
{
#if CHAR_MIN
    signed const x = *(schar const *) a;
#else
    unsigned const x = *(uchar const *) a;
#endif

    return  ((Vwbc){x,x,x,x});
}

INLINE(Vwhu,USHRT_DUPWAC) (void const *a)
{
    unsigned const x = ((HALF_TYPE const *) a)->M.U;
    return  ((Vwhu){x,x});
}

INLINE(Vwhi,SHRT_DUPWAC) (void const *a)
{
    signed const x = ((HALF_TYPE const *) a)->M.I;
    return  ((Vwhi){x,x});
}

INLINE(Vwhf,FLT16_DUPWAC) (void const *a)
{
    flt16_t const x = ((HALF_TYPE const *) a)->M.F;
    return  ((Vwhf){x,x});
}

INLINE(Vwwu,UINT_DUPWAC) (void const *a)
{
    return  (Vwwu){((WORD_TYPE const *) a)->M.U};
}

INLINE(Vwwi, INT_DUPWAC) (void const *a)
{
    return  (Vwwi){((WORD_TYPE const *) a)->M.I};
}

INLINE(Vwwf, FLT_DUPWAC) (void const *a)
{
    return  (Vwwf){((WORD_TYPE const *) a)->M.F};
}


INLINE(Vwyu,VWYU_DUPW) (Vwyu v, Rc(0, 31) k)
{
#define     VWYU_DUPW(V, K) \
(\
    (WORD_TYPE)\
    {\
        .I=-(1&(((WORD_TYPE){.M32.U=V}).U>>K))\
    }\
).M32.U

    return  VWYU_DUPW(v, k);
}


INLINE(Vwbu,VWBU_DUPW) (Vwbu v, Rc(0, 3) k)
{
#define     VWBU_DUPW(V, K)     UINT8_DUPW(VWBU_GET1(V,K))
    return  UINT8_DUPW((VWBU_GET1)(v, k));
}

INLINE(Vwbi,VWBI_DUPW) (Vwbi v, Rc(0, 3) k)
{
#define     VWBI_DUPW(V, K)     INT8_DUPW(VWBI_GET1(V,K))
    return  INT8_DUPW((VWBI_GET1)(v, k));
}

INLINE(Vwbc,VWBC_DUPW) (Vwbc v, Rc(0, 3) k)
{
#define     VWBC_DUPW(V, K)     CHAR_DUPW(VWBC_GET1(V,K))
    return  CHAR_DUPW((VWBC_GET1)(v, k));
}


INLINE(Vwhu,VWHU_DUPW) (Vwhu v, Rc(0, 1) k)
{
#define     VWHU_DUPW(V, K)     UINT16_DUPW(VWHU_GET1(V,K))
    return  UINT16_DUPW((VWHU_GET1)(v, k));
}

INLINE(Vwhi,VWHI_DUPW) (Vwhi v, Rc(0, 1) k)
{
#define     VWHI_DUPW(V, K)     INT16_DUPW(VWHI_GET1(V,K))
    return  INT16_DUPW((VWHI_GET1)(v, k));
}

INLINE(Vwhf,VWHF_DUPW) (Vwhf v, Rc(0, 1) k)
{
#define     VWHF_DUPW(V, K)     FLT16_DUPW(VWHF_GET1(V,K))
    return  FLT16_DUPW((VWHF_GET1)(v, k));
}


INLINE(Vwyu,VDYU_DUPW) (Vdyu v, Rc(0, 63) k)
{
#define     VDYU_DUPW(V, K) \
(\
    (DWRD_TYPE)\
    {\
        .I=-(1&(((DWRD_TYPE){.M64.U=V}).U>>K))\
    }\
).Lo.M32.U

    return  VDYU_DUPW(v, k);
}


INLINE(Vwbu,VDBU_DUPW) (Vdbu v, Rc(0, 7) k)
{
#define     VDBU_DUPW(V, K)     UINT8_DUPW(VDBU_GET1(V,K))
    return  UINT8_DUPW((VDBU_GET1)(v, k));
}

INLINE(Vwbi,VDBI_DUPW) (Vdbi v, Rc(0, 7) k)
{
#define     VDBI_DUPW(V, K)     INT8_DUPW(VDBI_GET1(V,K))
    return  INT8_DUPW((VDBI_GET1)(v, k));
}

INLINE(Vwbc,VDBC_DUPW) (Vdbc v, Rc(0, 7) k)
{
#define     VDBC_DUPW(V, K)     CHAR_DUPW(VDBC_GET1(V,K))
    return  CHAR_DUPW((VDBC_GET1)(v, k));
}



INLINE(Vwhu,VDHU_DUPW) (Vdhu v, Rc(0, 3) k)
{
#define     VDHU_DUPW(V, K)     UINT16_DUPW(VDHU_GET1(V,K))
    return  UINT16_DUPW((VDHU_GET1)(v, k));
}

INLINE(Vwhi,VDHI_DUPW) (Vdhi v, Rc(0, 3) k)
{
#define     VDHI_DUPW(V, K)     INT16_DUPW(VDHI_GET1(V,K))
    return  INT16_DUPW((VDHI_GET1)(v, k));
}

INLINE(Vwhf,VDHF_DUPW) (Vdhf v, Rc(0, 3) k)
{
#define     VDHF_DUPW(V, K)     FLT16_DUPW(VDHF_GET1(V,K))
    return  FLT16_DUPW((VDHF_GET1)(v, k));
}


INLINE(Vwwu,VDWU_DUPW) (Vdwu v, Rc(0, 1) k)
{
#define     VDWU_DUPW(V, K)     UINT32_DUPW(VDWU_GET1(V,K))
    return  UINT32_DUPW((VDWU_GET1)(v, k));
}

INLINE(Vwwi,VDWI_DUPW) (Vdwi v, Rc(0, 1) k)
{
#define     VDWI_DUPW(V, K)     INT32_DUPW(VDWI_GET1(V,K))
    return  INT32_DUPW((VDWI_GET1)(v, k));
}

INLINE(Vwwf,VDWF_DUPW) (Vdwf v, Rc(0, 1) k)
{
#define     VDWF_DUPW(V, K)     FLT_DUPW(VDWF_GET1(V,K))
    return  FLT_DUPW((VDWF_GET1)(v, k));
}


INLINE(Vwyu,VQYU_DUPW) (Vqyu v, Rc(0,127) k)
{
    QUAD_TYPE   r = {.M128.U=v};
    uint64_t    x;
    if (k < 64) x = r.Lo.U>>(k);
    else        x = r.Hi.U>>(k-64);
    r.Lo.I = -(1&x);
    return  r.W0.M32.U;
}


INLINE(Vwbu,VQBU_DUPW) (Vqbu v, Rc(0, 15) k)
{
#define     VQBU_DUPW(V, K)     UINT8_DUPW(VQBU_GET1(V,K))
    return  UINT8_DUPW((VQBU_GET1)(v, k));
}

INLINE(Vwbi,VQBI_DUPW) (Vqbi v, Rc(0, 15) k)
{
#define     VQBI_DUPW(V, K)     INT8_DUPW(VQBI_GET1(V,K))
    return  INT8_DUPW((VQBI_GET1)(v, k));
}

INLINE(Vwbc,VQBC_DUPW) (Vqbc v, Rc(0, 15) k)
{
#define     VQBC_DUPW(V, K)     CHAR_DUPW(VQBC_GET1(V,K))
    return  CHAR_DUPW((VQBC_GET1)(v, k));
}


INLINE(Vwhu,VQHU_DUPW) (Vqhu v, Rc(0, 7) k)
{
#define     VQHU_DUPW(V, K)     UINT16_DUPW(VQHU_GET1(V,K))
    return  UINT16_DUPW((VQHU_GET1)(v, k));
}

INLINE(Vwhi,VQHI_DUPW) (Vqhi v, Rc(0, 7) k)
{
#define     VQHI_DUPW(V, K)     INT16_DUPW(VQHI_GET1(V,K))
    return  INT16_DUPW((VQHI_GET1)(v, k));
}

INLINE(Vwhf,VQHF_DUPW) (Vqhf v, Rc(0, 7) k)
{
#define     VQHF_DUPW(V, K)     FLT16_DUPW(VQHF_GET1(V,K))
    return  FLT16_DUPW((VQHF_GET1)(v, k));
}


INLINE(Vwwu,VQWU_DUPW) (Vqwu v, Rc(0, 3) k)
{
#define     VQWU_DUPW(V, K)     UINT32_DUPW(VQWU_GET1(V,K))
    return  UINT32_DUPW((VQWU_GET1)(v, k));
}

INLINE(Vwwi,VQWI_DUPW) (Vqwi v, Rc(0, 3) k)
{
#define     VQWI_DUPW(V, K)     INT32_DUPW(VQWI_GET1(V,K))
    return  INT32_DUPW((VQWI_GET1)(v, k));
}

INLINE(Vwwf,VQWF_DUPW) (Vqwf v, Rc(0, 3) k)
{
#define     VQWF_DUPW(V, K)     FLT_DUPW(VQWF_GET1(V,K))
    return  FLT_DUPW((VQWF_GET1)(v, k));
}

#endif

#if 0 // _LEAVE_ALL_DUPW
}
#endif

#if 0 // _ENTER_ALL_DUPD
{
#endif

#ifdef SPC_NO_DUPD

INLINE(Vdyu,BOOL_DUPD) (_Bool x)
{
    DWRD_TYPE r = {.I=0ll-x};
    return  r.M64.U;
}


INLINE(Vdbu,UCHAR_DUPD) (unsigned x)
{
#define     UCHAR_DUPD(X) ((Vdbu){X,X,X,X,X,X,X,X})
    return  UCHAR_DUPD(x);
}

INLINE(Vdbi,SCHAR_DUPD) (signed x)
{
#define     SCHAR_DUPD(X)   ((Vdbi){X,X,X,X,X,X,X,X})
    return  SCHAR_DUPD(x);
}

INLINE(Vdbc, CHAR_DUPD)  (int x)
{
#define     CHAR_DUPD(X)    ((Vdbc){X,X,X,X,X,X,X,X})
    return  CHAR_DUPD(x);
}


INLINE(Vdhu,USHRT_DUPD) (unsigned x)
{
#define     USHRT_DUPD(X)   ((Vdhu){X,X,X,X})
    return  USHRT_DUPD(x);
}

INLINE(Vdhi,SHRT_DUPD) (signed x)
{
#define     SHRT_DUPD(X)    ((Vdhi){X,X,X,X})
    return  SHRT_DUPD(x);
}

INLINE(Vdwu,UINT_DUPD) (uint x)
{
#define     UINT_DUPD(X)    ((Vdwu){X,X})
    return  (Vdwu){x,x};
}

INLINE(Vdwi, INT_DUPD) (int x)
{
#define     INT_DUPD(X)     ((Vdwi){X,X})
    return  INT_DUPD(x);
}

#if DWRD_NLONG == 2

INLINE(Vdwu,ULONG_DUPD) (ulong x)
{
#define     ULONG_DUPD(X)   ((Vdwu){X,X})
    return  ULONG_DUPD(x);
}

INLINE(Vdwi, LONG_DUPD) (long x)
{
#define     LONG_DUPD(X)    ((Vdwi){X,X})
    return  LONG_DUPD(x);
}

#else

INLINE(Vddu,ULONG_DUPD) (ulong x)
{
#define     ULONG_DUPD(X)   ((Vddu){X})
    return  ULONG_DUPD(x);
}

INLINE(Vddi, LONG_DUPD) (long x)
{
#define     LONG_DUPD(X)    ((Vddi){X})
    return  LONG_DUPD(x);
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vddu,ULLONG_DUPD) (ullong x)
{
#define     ULLONG_DUPD(X)   ((Vddu){X})
    return  ULLONG_DUPD(x);
}

INLINE(Vddi, LLONG_DUPD)  (llong x)
{
#define     LLONG_DUPD(X)    ((Vddi){X})
    return  LLONG_DUPD(x);
}

#endif

INLINE(Vdhf,FLT16_DUPD) (flt16_t x)
{
#define     FLT16_DUPD(X)   ((Vdhf){X,X,X,X})
    return  FLT16_DUPD(x);
}

INLINE(Vdwf, FLT_DUPD) (float x)
{
#define     FLT_DUPD(X)     ((Vdwf){X,X})
    return  FLT_DUPD(x);
}

INLINE(Vddf, DBL_DUPD) (double x)
{
#define     DBL_DUPD(X)     ((Vddf){X})
    return  DBL_DUPD(x);
}


INLINE(Vdyu,BOOL_DUPDAC) (void const *a)
{
    DWRD_TYPE const v = {.U=0ull-*(_Bool const *) a};
    return  v.M64.U;
}


INLINE(Vdbu,UCHAR_DUPDAC) (void const *a)
{
    unsigned const x = *(uchar const *) a;
    return  UCHAR_DUPD(x);
}

INLINE(Vdbi,SCHAR_DUPDAC) (void const *a)
{
    signed const x = *(schar const *) a;
    return  SCHAR_DUPD(x);
}

INLINE(Vdbc, CHAR_DUPDAC) (void const *a)
{
#if CHAR_MIN
    signed const x = *(schar const *) a;
#else
    unsigned const x = *(uchar const *) a;
#endif

    return  CHAR_DUPD(x);
}


INLINE(Vdhu,USHRT_DUPDAC) (void const *a)
{
    unsigned const x = ((HALF_TYPE const *) a)->M.U;
    return  USHRT_DUPD(x);
}

INLINE(Vdhi, SHRT_DUPDAC) (void const *a)
{
    signed const x = ((HALF_TYPE const *) a)->M.I;
    return  SHRT_DUPD(x);
}


INLINE(Vdwu,UINT_DUPDAC) (void const *a)
{
    unsigned const x = ((WORD_TYPE const *) a)->M.U;
    return  UINT_DUPD(x);
}

INLINE(Vdwi, INT_DUPDAC) (void const *a)
{
    signed const x = ((WORD_TYPE const *) a)->M.I;
    return  INT_DUPD(x);
}

#if DWRD_NLONG == 2

INLINE(Vdwu,ULONG_DUPDAC) (void const *a)
{
    unsigned const x = ((WORD_TYPE const *) a)->M.U;
    return  ULONG_DUPD(x);
}

INLINE(Vdwi, LONG_DUPDAC) (void const *a)
{
    signed const x = ((WORD_TYPE const *) a)->M.I;
    return  LONG_DUPD(x);
}

#else


INLINE(Vddu,ULONG_DUPDAC) (void const *a)
{
    ulong const x = ((DWRD_TYPE const *) a)->M.U;
    return  ((Vddu){x});
}

INLINE(Vddi, LONG_DUPDAC) (void const *a)
{
    long const x = ((DWRD_TYPE const *) a)->M.I;
    return  ((Vddi){x});
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vddu,ULLONG_DUPDAC) (void const *a)
{
    ulong const x = ((DWRD_TYPE const *) a)->M.U;
    return  ((Vddu){x});
}

INLINE(Vddi, LLONG_DUPDAC) (void const *a)
{
    long const x = ((DWRD_TYPE const *) a)->M.I;
    return  ((Vddi){x});
}

#endif

INLINE(Vdhf,FLT16_DUPDAC) (void const *a)
{
    flt16_t const x = ((HALF_TYPE const *) a)->M.F;
    return  FLT16_DUPD(x);
}

INLINE(Vdwf, FLT_DUPDAC) (void const *a)
{
    float const x = ((WORD_TYPE const *) a)->M.F;
    return  FLT_DUPD(x);
}

INLINE(Vddf, DBL_DUPDAC) (void const *a)
{
    double const x = ((DWRD_TYPE const *) a)->M.F;
    return  DBL_DUPD(x);
}


INLINE(Vdyu,VWYU_DUPD) (Vwyu v, Rc(0, 31) k)
{
    DWRD_TYPE a = {.Lo.M32.U=v};
    a.U = 0u-(1&(a.Lo.U>>k));
    return  a.M64.U;
}


INLINE(Vdbu,VWBU_DUPD) (Vwbu v, Rc(0, 3) k)
{
#define     VWBU_DUPD(V, K)     UINT8_DUPD(VWBU_GET1(V,K))
    return  UINT8_DUPD((VWBU_GET1)(v, k));
}

INLINE(Vdbi,VWBI_DUPD) (Vwbi v, Rc(0, 3) k)
{
#define     VWBI_DUPD(V, K)     INT8_DUPD(VWBI_GET1(V,K))
    return  INT8_DUPD((VWBI_GET1)(v, k));
}

INLINE(Vdbc,VWBC_DUPD) (Vwbc v, Rc(0, 3) k)
{
#define     VWBC_DUPD(V, K)     CHAR_DUPD(VWBC_GET1(V,K))
    return  CHAR_DUPD((VWBC_GET1)(v, k));
}


INLINE(Vdhu,VWHU_DUPD) (Vwhu v, Rc(0, 1) k)
{
#define     VWHU_DUPD(V, K)     UINT16_DUPD(VWHU_GET1(V,K))
    return  UINT16_DUPD((VWHU_GET1)(v, k));
}

INLINE(Vdhi,VWHI_DUPD) (Vwhi v, Rc(0, 1) k)
{
#define     VWHI_DUPD(V, K)     INT16_DUPD(VWHI_GET1(V,K))
    return  INT16_DUPD((VWHI_GET1)(v, k));
}

INLINE(Vdhf,VWHF_DUPD) (Vwhf v, Rc(0, 1) k)
{
#define     VWHF_DUPD(V, K)     FLT16_DUPD(VWHF_GET1(V,K))
    return  FLT16_DUPD((VWHF_GET1)(v, k));
}


INLINE(Vdyu,VDYU_DUPD) (Vdyu v, Rc(0, 63) k)
{
#define     VDYU_DUPD(V, K) \
(\
    (DWRD_TYPE)\
    {\
        .I=-(1&(((DWRD_TYPE){.M64.U=V}).U>>K))\
    }\
).M64.U

    return  VDYU_DUPD(v, k);
}


INLINE(Vdbu,VDBU_DUPD) (Vdbu v, Rc(0, 7) k)
{
#define     VDBU_DUPD(V, K)     UINT8_DUPD(VDBU_GET1(V,K))
    return  UINT8_DUPD((VDBU_GET1)(v, k));
}

INLINE(Vdbi,VDBI_DUPD) (Vdbi v, Rc(0, 7) k)
{
#define     VDBI_DUPD(V, K)     INT8_DUPD(VDBI_GET1(V,K))
    return  INT8_DUPD((VDBI_GET1)(v, k));
}

INLINE(Vdbc,VDBC_DUPD) (Vdbc v, Rc(0, 7) k)
{
#define     VDBC_DUPD(V, K)     CHAR_DUPD(VDBC_GET1(V,K))
    return  CHAR_DUPD((VDBC_GET1)(v, k));
}


INLINE(Vdhu,VDHU_DUPD) (Vdhu v, Rc(0, 3) k)
{
#define     VDHU_DUPD(V, K)     UINT16_DUPD(VDHU_GET1(V,K))
    return  UINT16_DUPD((VDHU_GET1)(v, k));
}

INLINE(Vdhi,VDHI_DUPD) (Vdhi v, Rc(0, 3) k)
{
#define     VDHI_DUPD(V, K)     INT16_DUPD(VDHI_GET1(V,K))
    return  INT16_DUPD((VDHI_GET1)(v, k));
}

INLINE(Vdhf,VDHF_DUPD) (Vdhf v, Rc(0, 3) k)
{
#define     VDHF_DUPD(V, K)     FLT16_DUPD(VDHF_GET1(V,K))
    return  FLT16_DUPD((VDHF_GET1)(v, k));
}


INLINE(Vdwu,VDWU_DUPD) (Vdwu v, Rc(0, 1) k)
{
#define     VDWU_DUPD(V, K)     UINT32_DUPD(VDWU_GET1(V,K))
    return  UINT32_DUPD((VDWU_GET1)(v, k));
}

INLINE(Vdwi,VDWI_DUPD) (Vdwi v, Rc(0, 1) k)
{
#define     VDWI_DUPD(V, K)     INT32_DUPD(VDWI_GET1(V,K))
    return  INT32_DUPD((VDWI_GET1)(v, k));
}

INLINE(Vdwf,VDWF_DUPD) (Vdwf v, Rc(0, 1) k)
{
#define     VDWF_DUPD(V, K)     FLT_DUPD(VDWF_GET1(V,K))
    return  FLT_DUPD((VDWF_GET1)(v, k));
}


INLINE(Vdyu,VQYU_DUPD) (Vqyu v, Rc(0,127) k)
{
    QUAD_TYPE   r = {.M128.U=v};
    uint64_t    x;
    if (k < 64) x = r.Lo.U>>(k);
    else        x = r.Hi.U>>(k-64);
    r.Lo.I = -(1&x);
    return  r.D0.M64.U;
}


INLINE(Vdbu,VQBU_DUPD) (Vqbu v, Rc(0, 15) k)
{
#define     VQBU_DUPD(V, K)     UINT8_DUPD(VQBU_GET1(V,K))
    return  UINT8_DUPD((VQBU_GET1)(v, k));
}

INLINE(Vdbi,VQBI_DUPD) (Vqbi v, Rc(0, 15) k)
{
#define     VQBI_DUPD(V, K)     INT8_DUPD(VQBI_GET1(V,K))
    return  INT8_DUPD((VQBI_GET1)(v, k));
}

INLINE(Vdbc,VQBC_DUPD) (Vqbc v, Rc(0, 15) k)
{
#define     VQBC_DUPD(V, K)     CHAR_DUPD(VQBC_GET1(V,K))
    return  CHAR_DUPD((VQBC_GET1)(v, k));
}


INLINE(Vdhu,VQHU_DUPD) (Vqhu v, Rc(0, 7) k)
{
#define     VQHU_DUPD(V, K)     UINT16_DUPD(VQHU_GET1(V,K))
    return  UINT16_DUPD((VQHU_GET1)(v, k));
}

INLINE(Vdhi,VQHI_DUPD) (Vqhi v, Rc(0, 7) k)
{
#define     VQHI_DUPD(V, K)     INT16_DUPD(VQHI_GET1(V,K))
    return  INT16_DUPD((VQHI_GET1)(v, k));
}

INLINE(Vdhf,VQHF_DUPD) (Vqhf v, Rc(0, 7) k)
{
#define     VQHF_DUPD(V, K)     FLT16_DUPD(VQHF_GET1(V,K))
    return  FLT16_DUPD((VQHF_GET1)(v, k));
}


INLINE(Vdwu,VQWU_DUPD) (Vqwu v, Rc(0, 3) k)
{
#define     VQWU_DUPD(V, K)     UINT32_DUPD(VQWU_GET1(V,K))
    return  UINT32_DUPD((VQWU_GET1)(v, k));
}

INLINE(Vdwi,VQWI_DUPD) (Vqwi v, Rc(0, 3) k)
{
#define     VQWI_DUPD(V, K)     INT32_DUPD(VQWI_GET1(V,K))
    return  INT32_DUPD((VQWI_GET1)(v, k));
}

INLINE(Vdwf,VQWF_DUPD) (Vqwf v, Rc(0, 3) k)
{
#define     VQWF_DUPD(V, K)     FLT_DUPD(VQWF_GET1(V,K))
    return  FLT_DUPD((VQWF_GET1)(v, k));
}

#endif // defined(SPC_NO_DUPD)

#if 0 // _LEAVE_ALL_DUPD
}
#endif

#if 0 // _ENTER_ALL_DUPQ
{
#endif

#ifdef SPC_NO_DUPQ

INLINE(Vqyu,BOOL_DUPQ) (_Bool x)
{
    QUAD_TYPE r;
    r.Lo.I = 0ll-x;
    r.Hi.I = r.Lo.I;
    return  r.M128.U;
}


INLINE(Vqbu,UCHAR_DUPQ) (uchar x)
{
    return  ((Vqbu){x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x});
}

INLINE(Vqbi,SCHAR_DUPQ) (schar x)
{
    return  ((Vqbi){x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x});
}

INLINE(Vqbc, CHAR_DUPQ)  (char x)
{
    return  ((Vqbc){x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x});
}


INLINE(Vqhu,USHRT_DUPQ) (ushort x)
{
    return  ((Vqhu){x,x,x,x, x,x,x,x});
}

INLINE(Vqhi,SHRT_DUPQ) (short x)
{
    return  ((Vqhi){x,x,x,x, x,x,x,x});
}


INLINE(Vqwu,UINT_DUPQ) (uint x)
{
    return  ((Vqwu){x,x,x,x});
}

INLINE(Vqwi, INT_DUPQ) (int x)
{
    return  ((Vqwi){x,x,x,x});
}

#if DWRD_NLONG == 2

INLINE(Vqwu,ULONG_DUPQ) (ulong x)
{
    return  ((Vqwu){x,x,x,x});
}

INLINE(Vqwi, LONG_DUPQ)  (long x)
{
    return  ((Vqwi){x,x,x,x});
}

#else

INLINE(Vqdu,ULONG_DUPQ) (ulong x)
{
    return  ((Vqdu){x,x});
}

INLINE(Vqdi, LONG_DUPQ) (long x)
{
    return  ((Vqdi){x,x});
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vqdu,ULLONG_DUPQ) (ullong x)
{
    return  ((Vqdu){x,x});
}

INLINE(Vqdi, LLONG_DUPQ)  (llong x)
{
    return  ((Vqdi){x,x});
}

#else

INLINE(Vqqu,ULLONG_DUPQ) (ullong x)
{
    return  ((Vqqu){x});
}

INLINE(Vqqi, LLONG_DUPQ)  (llong x)
{
    return  ((Vqqi){x});
}

#endif

INLINE(Vqhf,FLT16_DUPQ) (flt16_t x)
{
    return  ((Vqhf){x,x,x,x, x,x,x,x});
}

INLINE(Vqwf, FLT_DUPQ) (float x)
{
    return  ((Vqwf){x,x,x,x});
}

INLINE(Vqdf, DBL_DUPQ) (double x)
{
    return  ((Vqdf){x,x});
}


INLINE(Vqyu,BOOL_DUPQAC) (void const *a)
{
    QUAD_TYPE v;
    v.Lo.U = 0ull-*(_Bool const *) a;
    v.Hi.U = v.Lo.U;
    return  v.M128.U;
}


INLINE(Vqbu,UCHAR_DUPQAC) (void const *a)
{
    unsigned const x = *(uchar const *) a;
    return  UCHAR_DUPQ(x);
}

INLINE(Vqbi,SCHAR_DUPQAC) (void const *a)
{
    signed const x = *(schar const *) a;
    return  SCHAR_DUPQ(x);
}

INLINE(Vqbc, CHAR_DUPQAC) (void const *a)
{
#if CHAR_MIN
    signed const x = *(schar const *) a;
#else
    unsigned const x = *(uchar const *) a;
#endif

    return  CHAR_DUPQ(x);
}


INLINE(Vqhu,USHRT_DUPQAC) (void const *a)
{
    unsigned const x = ((HALF_TYPE const *) a)->M.U;
    return  USHRT_DUPQ(x);
}

INLINE(Vqhi, SHRT_DUPQAC) (void const *a)
{
    signed const x = ((HALF_TYPE const *) a)->M.I;
    return  SHRT_DUPQ(x);
}


INLINE(Vqwu,UINT_DUPQAC) (void const *a)
{
    unsigned const x = ((WORD_TYPE const *) a)->M.U;
    return  UINT_DUPQ(x);
}

INLINE(Vqwi, INT_DUPQAC) (void const *a)
{
    signed const x = ((WORD_TYPE const *) a)->M.I;
    return  INT_DUPQ(x);
}

#if DWRD_NLONG == 2

INLINE(Vqwu,ULONG_DUPQAC) (void const *a)
{
    ulong const x = ((WORD_TYPE const *) a)->M.U;
    return  ULONG_DUPQ(x);
}

INLINE(Vqwi, LONG_DUPQAC) (void const *a)
{
    long const x = ((WORD_TYPE const *) a)->M.I;
    return  LONG_DUPQ(x);
}

#else


INLINE(Vqdu,ULONG_DUPQAC) (void const *a)
{
    ulong const x = ((DWRD_TYPE const *) a)->M.U;
    return  ULONG_DUPQ(x);
}

INLINE(Vqdi, LONG_DUPQAC) (void const *a)
{
    long const x = ((DWRD_TYPE const *) a)->M.I;
    return  LONG_DUPQ(x);
}

#endif

#if QUAD_NLLONG == 2

INLINE(Vqdu,ULLONG_DUPQAC) (void const *a)
{
    ullong const x = ((DWRD_TYPE const *) a)->M.U;
    return  ULLONG_DUPQ(x);
}

INLINE(Vqdi, LLONG_DUPQAC) (void const *a)
{
    llong const x = ((DWRD_TYPE const *) a)->M.I;
    return  LLONG_DUPQ(x);
}

#else

INLINE(Vqqu,ULLONG_DUPQAC) (void const *a)
{
    ullong const x = ((QUAD_TYPE const *) a)->M.U;
    return  ULLONG_DUPQ(x);
}

INLINE(Vqqi, LLONG_DUPQAC) (void const *a)
{
    llong const x = ((QUAD_TYPE const *) a)->M.I;
    return  LLONG_DUPQ(x);
}

#endif

INLINE(Vqhf,FLT16_DUPQAC) (void const *a)
{
    flt16_t const x = ((HALF_TYPE const *) a)->M.F;
    return  FLT16_DUPQ(x);
}

INLINE(Vqwf, FLT_DUPQAC) (void const *a)
{
    float const x = ((WORD_TYPE const *) a)->M.F;
    return  FLT_DUPQ(x);
}

INLINE(Vqdf, DBL_DUPQAC) (void const *a)
{
    double const x = ((DWRD_TYPE const *) a)->M.F;
    return  DBL_DUPQ(x);
}


INLINE(Vqyu,VWYU_DUPQ) (Vwyu v, Rc(0, 31) k)
{
    QUAD_TYPE a = {.W0.M32.U=v};
    a.Lo.U = 0ull-(1&(a.W0.U>>k));
    a.Hi.U = a.Lo.U;
    return  a.M128.U;
}


INLINE(Vqbu,VWBU_DUPQ) (Vwbu v, Rc(0, 3) k)
{
#define     VWBU_DUPQ(V, K)     UINT8_DUPQ(VWBU_GET1(V,K))
    return  UINT8_DUPQ((VWBU_GET1)(v, k));
}

INLINE(Vqbi,VWBI_DUPQ) (Vwbi v, Rc(0, 3) k)
{
#define     VWBI_DUPQ(V, K)     INT8_DUPQ(VWBI_GET1(V,K))
    return  INT8_DUPQ((VWBI_GET1)(v, k));
}

INLINE(Vqbc,VWBC_DUPQ) (Vwbc v, Rc(0, 3) k)
{
#define     VWBC_DUPQ(V, K)     CHAR_DUPQ(VWBC_GET1(V,K))
    return  CHAR_DUPQ((VWBC_GET1)(v, k));
}


INLINE(Vqhu,VWHU_DUPQ) (Vwhu v, Rc(0, 1) k)
{
#define     VWHU_DUPQ(V, K)     UINT16_DUPQ(VWHU_GET1(V,K))
    return  UINT16_DUPQ((VWHU_GET1)(v, k));
}

INLINE(Vqhi,VWHI_DUPQ) (Vwhi v, Rc(0, 1) k)
{
#define     VWHI_DUPQ(V, K)     INT16_DUPQ(VWHI_GET1(V,K))
    return  INT16_DUPQ((VWHI_GET1)(v, k));
}

INLINE(Vqhf,VWHF_DUPQ) (Vwhf v, Rc(0, 1) k)
{
#define     VWHF_DUPQ(V, K)     FLT16_DUPQ(VWHF_GET1(V,K))
    return  FLT16_DUPQ((VWHF_GET1)(v, k));
}


INLINE(Vqyu,VDYU_DUPQ) (Vdyu v, Rc(0, 63) k)
{
    QUAD_TYPE x = {.D0.M64.U=v};
    x.Lo.U = 0ull-(1&(x.Lo.U>>k));
    x.Hi.U = x.Lo.U;
    return  x.M128.U;
}


INLINE(Vqbu,VDBU_DUPQ) (Vdbu v, Rc(0, 7) k)
{
#define     VDBU_DUPQ(V, K)     UINT8_DUPQ(VDBU_GET1(V,K))
    return  UINT8_DUPQ((VDBU_GET1)(v, k));
}

INLINE(Vqbi,VDBI_DUPQ) (Vdbi v, Rc(0, 7) k)
{
#define     VDBI_DUPQ(V, K)     INT8_DUPQ(VDBI_GET1(V,K))
    return  INT8_DUPQ((VDBI_GET1)(v, k));
}

INLINE(Vqbc,VDBC_DUPQ) (Vdbc v, Rc(0, 7) k)
{
#define     VDBC_DUPQ(V, K)     CHAR_DUPQ(VDBC_GET1(V,K))
    return  CHAR_DUPQ((VDBC_GET1)(v, k));
}


INLINE(Vqhu,VDHU_DUPQ) (Vdhu v, Rc(0, 3) k)
{
#define     VDHU_DUPQ(V, K)     UINT16_DUPQ(VDHU_GET1(V,K))
    return  UINT16_DUPQ((VDHU_GET1)(v, k));
}

INLINE(Vqhi,VDHI_DUPQ) (Vdhi v, Rc(0, 3) k)
{
#define     VDHI_DUPQ(V, K)     INT16_DUPQ(VDHI_GET1(V,K))
    return  INT16_DUPQ((VDHI_GET1)(v, k));
}

INLINE(Vqhf,VDHF_DUPQ) (Vdhf v, Rc(0, 3) k)
{
#define     VDHF_DUPQ(V, K)     FLT16_DUPQ(VDHF_GET1(V,K))
    return  FLT16_DUPQ((VDHF_GET1)(v, k));
}


INLINE(Vqwu,VDWU_DUPQ) (Vdwu v, Rc(0, 1) k)
{
#define     VDWU_DUPQ(V, K)     UINT32_DUPQ(VDWU_GET1(V,K))
    return  UINT32_DUPQ((VDWU_GET1)(v, k));
}

INLINE(Vqwi,VDWI_DUPQ) (Vdwi v, Rc(0, 1) k)
{
#define     VDWI_DUPQ(V, K)     INT32_DUPQ(VDWI_GET1(V,K))
    return  INT32_DUPQ((VDWI_GET1)(v, k));
}

INLINE(Vqwf,VDWF_DUPQ) (Vdwf v, Rc(0, 1) k)
{
#define     VDWF_DUPQ(V, K)     FLT_DUPQ(VDWF_GET1(V,K))
    return  FLT_DUPQ((VDWF_GET1)(v, k));
}


INLINE(Vqyu,VQYU_DUPQ) (Vqyu v, Rc(0,127) k)
{
    QUAD_TYPE   r = {.M128.U=v};
    uint64_t    x;
    if (k < 64) x = r.Lo.U>>(k);
    else        x = r.Hi.U>>(k-64);
    r.Lo.I = -(1&x);
    r.Hi.I = r.Lo.I;
    return  r.M128.U;
}


INLINE(Vqbu,VQBU_DUPQ) (Vqbu v, Rc(0, 15) k)
{
#define     VQBU_DUPQ(V, K)     UINT8_DUPQ(VQBU_GET1(V,K))
    return  UINT8_DUPQ((VQBU_GET1)(v, k));
}

INLINE(Vqbi,VQBI_DUPQ) (Vqbi v, Rc(0, 15) k)
{
#define     VQBI_DUPQ(V, K)     INT8_DUPQ(VQBI_GET1(V,K))
    return  INT8_DUPQ((VQBI_GET1)(v, k));
}

INLINE(Vqbc,VQBC_DUPQ) (Vqbc v, Rc(0, 15) k)
{
#define     VQBC_DUPQ(V, K)     CHAR_DUPQ(VQBC_GET1(V,K))
    return  CHAR_DUPQ((VQBC_GET1)(v, k));
}


INLINE(Vqhu,VQHU_DUPQ) (Vqhu v, Rc(0, 7) k)
{
#define     VQHU_DUPQ(V, K)     UINT16_DUPQ(VQHU_GET1(V,K))
    return  UINT16_DUPQ((VQHU_GET1)(v, k));
}

INLINE(Vqhi,VQHI_DUPQ) (Vqhi v, Rc(0, 7) k)
{
#define     VQHI_DUPQ(V, K)     INT16_DUPQ(VQHI_GET1(V,K))
    return  INT16_DUPQ((VQHI_GET1)(v, k));
}

INLINE(Vqhf,VQHF_DUPQ) (Vqhf v, Rc(0, 7) k)
{
#define     VQHF_DUPQ(V, K)     FLT16_DUPQ(VQHF_GET1(V,K))
    return  FLT16_DUPQ((VQHF_GET1)(v, k));
}


INLINE(Vqwu,VQWU_DUPQ) (Vqwu v, Rc(0, 3) k)
{
#define     VQWU_DUPQ(V, K)     UINT32_DUPQ(VQWU_GET1(V,K))
    return  UINT32_DUPQ((VQWU_GET1)(v, k));
}

INLINE(Vqwi,VQWI_DUPQ) (Vqwi v, Rc(0, 3) k)
{
#define     VQWI_DUPQ(V, K)     INT32_DUPQ(VQWI_GET1(V,K))
    return  INT32_DUPQ((VQWI_GET1)(v, k));
}

INLINE(Vqwf,VQWF_DUPQ) (Vqwf v, Rc(0, 3) k)
{
#define     VQWF_DUPQ(V, K)     FLT_DUPQ(VQWF_GET1(V,K))
    return  FLT_DUPQ((VQWF_GET1)(v, k));
}

#endif // defined(SPC_NO_DUPQ)

#if 0 // _LEAVE_ALL_DUPQ
}
#endif


#if 0 // _ENTER_ALL_CBNS
{
#endif

INLINE(ptrdiff_t,  ADDR_CBNS)
(
    void volatile const *x,
    void volatile const *l,
    void volatile const *r
)
{
#define ADDR_CBNS(X, L, R) \
((ptrdiff_t) (((L <= ((void *) X)) && (((void *) X) <= R)) ? -1 : 0))

    return ((l <= x) && (x <= r)) ? PTRDIFF_C(-1) : PTRDIFF_C(0);
}


INLINE(    uchar, UCHAR_CBNS)
(
    unsigned x,
    Jc(0, UCHAR_MAX) l,
    Jc(0, UCHAR_MAX) r
)
{
#define     UCHAR_CBNS(X, L, R) \
((uchar) (((L<=((uchar) X))&&(((uchar) X)<=R))?UCHAR_MAX:0))

    uchar c = x;
    return  ((l <= c) && (c <= r)) ? UCHAR_MAX : 0;
}

INLINE(    schar, SCHAR_CBNS)
(
    signed x,
    Jc(SCHAR_MIN, SCHAR_MAX) l,
    Jc(SCHAR_MIN, SCHAR_MAX) r
)
{
#define     SCHAR_CBNS(X, L, R) \
((schar) (0-((L<=((schar) X))&&(((schar) X)<=R))))

    schar c = x;
    return  ((l <= c) && (c <= r)) ? -1 : 0;
}

INLINE(     char,  CHAR_CBNS)
(
    int x,
    Jc(CHAR_MIN, CHAR_MAX) l,
    Jc(CHAR_MIN, CHAR_MAX) r
)
{
#define     CHAR_CBNS(X, L, R) \
((char) (((L <= ((char) X)) && (((char) X) <= R)) ? -1 : 0))

    char c = x;
    return  ((l <= c) && (c <= r)) ? '\xff' : '\x00';
}


INLINE(   ushort, USHRT_CBNS)
(
    unsigned            x,
    Jc(0, USHRT_MAX)    l,
    Jc(0, USHRT_MAX)    r
)
{
#define     USHRT_CBNS(X, L, R) \
((ushort) (((L<=((ushort) X))&&(((ushort) X)<=R))?USHRT_MAX:0))

    ushort c = x;
    return  ((l <= c) && (c <= r)) ? USHRT_MAX : 0;
}

INLINE(    short,  SHRT_CBNS)
(
    signed                  x,
    Jc(SHRT_MIN, SHRT_MAX)  l,
    Jc(SHRT_MIN, SHRT_MAX)  r
)
{
#define     SHRT_CBNS(X, L, R) \
((short) (0-((L<=((short) X))&&(((short) X)<=R))))

    short c = x;
    return  ((l <= c) && (c <= r)) ? -1 : 0;
}


INLINE(     uint,  UINT_CBNS)
(
    uint x,
    Jc(0, UINT_MAX) l,
    Jc(0, UINT_MAX) r
)
{
#define     UINT_CBNS(X, L, R) \
(((L<=((uint)X))&&(((uint)X)<=R))?UINT_MAX:0U)

    return  ((l <= x) && (x <= r)) ? UINT_MAX : 0U;
}

INLINE(      int,   INT_CBNS)
(
    int x,
    Jc(INT_MIN, INT_MAX) l,
    Jc(INT_MIN, INT_MAX) r
)
{
#define     INT_CBNS(X, L, R) \
(0-((L<=((int) X))&&(((int) X)<=R)))

    return  ((l <= x) && (x <= r)) ? -1 : 0;
}


INLINE(    ulong, ULONG_CBNS)
(
    ulong x,
    unsigned Jc(0, ULONG_MAX) l,
    unsigned Jc(0, ULONG_MAX) r
)
{
#define     ULONG_CBNS(X, L, R) \
(((L<=((ulong)X))&&(((ulong)X)<=R))?ULONG_MAX:0UL)

    return  ((l <= x) && (x <= r)) ? UINT_MAX : 0UL;
}

INLINE(     long,  LONG_CBNS)
(
    long x,
    signed Jc(LONG_MIN, LONG_MAX) l,
    signed Jc(LONG_MIN, LONG_MAX) r
)
{
#define     LONG_CBNS(X, L, R) \
(0L-((L<=((long) X))&&(((long) X)<=R)))

    return  ((l <= x) && (x <= r)) ? -1L : 0L;
}


INLINE(   ullong,ULLONG_CBNS)
(
    ullong x,
    unsigned Jc(0, ULLONG_MAX) l,
    unsigned Jc(0, ULLONG_MAX) r
)
{
#define     ULLONG_CBNS(X, L, R) \
(((L<=((ullong)X))&&(((ullong)X)<=R))?ULLONG_MAX:0ULL)

    return  ((l <= x) && (x <= r)) ? ULONG_MAX : 0ULL;
}

INLINE(    llong, LLONG_CBNS)
(
    llong x,
    signed Jc(LLONG_MIN, LLONG_MAX) l,
    signed Jc(LLONG_MIN, LLONG_MAX) r
)
{
#define     LLONG_CBNS(X, L, R) \
(0LL-((L<=((llong) X))&&(((llong) X)<=R)))

    return  ((l <= x) && (x <= r)) ? -1LL : 0LL;
}

#if 0 // _LEAVE_ALL_CBNS
}
#endif

#if 0 // _ENTER_ALL_CBNY
{
#endif

INLINE(ptrdiff_t,  ADDR_CBNY)
(
    void volatile const *x,
    void volatile const *l,
    void volatile const *r
)
{
    return  (l <= x) && (x <= r);
}


INLINE(    uchar, UCHAR_CBNY)   
(
    unsigned            x, 
    Jc(0, UCHAR_MAX)    l,
    Jc(0, UCHAR_MAX)    r
)
{
#define     UCHAR_CBNY(X, L, R) \
((uchar) ((L <= ((uchar) X)) && (((uchar) X) <= R)))

    uchar c = x;
    return  (l <= c) && (x <= c);
}

INLINE(    schar, SCHAR_CBNY)   
(
    signed x, 
    Jc(SCHAR_MIN, SCHAR_MAX) l,
    Jc(SCHAR_MIN, SCHAR_MAX) r
)
{
#define     SCHAR_CBNY(X, L, R) \
((schar) ((L <= ((schar) X)) && (((schar) X) <= R)))

    schar c = x;
    return  (l <= c) && (c <= r);
}

INLINE(     char,  CHAR_CBNY)   
(
    int x, 
    Jc(CHAR_MIN, CHAR_MAX) l,
    Jc(CHAR_MIN, CHAR_MAX) r
)
{
#define     CHAR_CBNY(X, L, R) \
((char) ((L <= ((char) X)) && (((char) X) <= R)))

    char c = x;
    return  (l <= x) && (c <= r);
}


INLINE(   ushort, USHRT_CBNY)
(
    unsigned            x, 
    Jc(0, USHRT_MAX)    l,
    Jc(0, USHRT_MAX)    r
)
{
#define     USHRT_CBNY(X, L, R) \
((ushort) ((L <= ((ushort) X)) && (((ushort) X) <= R)))

    ushort c = x;
    return  (l <= c) && (c <= r);
}

INLINE(    short,  SHRT_CBNY)
(
    signed                  x, 
    Jc(SHRT_MIN, SHRT_MAX)  l,
    Jc(SHRT_MIN, SHRT_MAX)  r
)
{
#define     SHRT_CBNY(X, L, R) \
((short) ((L <= ((short) X)) && (((short) X) <= R)))

    short c = x;
    return  (l <= c) && (c <= r);
}


INLINE(     uint,  UINT_CBNY)
(
    uint                x, 
    Jc(0, UINT_MAX)     l,
    Jc(0, UINT_MAX)     r
)
{
#define     UINT_CBNY(X, L, R) \
((uint) ((L <= ((uint) X)) && (((uint) X) <= R)))

    return  (l <= x) && (x <= r);
}

INLINE(      int,   INT_CBNY)
(
    int                     x, 
    Jc(INT_MIN, INT_MAX)    l,
    Jc(INT_MIN, INT_MAX)    r
)
{
#define     INT_CBNY(X, L, R) \
((int) ((L <= ((int) X)) && (((int) X) <= R)))

    return  (l <= x) && (x <= r);
}


INLINE(    ulong, ULONG_CBNY)
(
    ulong                       x, 
    unsigned Jc(0, ULONG_MAX)   l,
    unsigned Jc(0, ULONG_MAX)   r
)
{
#define     ULONG_CBNY(X, L, R) \
((ulong) ((L <= ((ulong) X)) && (((ulong) X) <= R)))

    return  (l <= x) && (x <= r);
}

INLINE(     long,  LONG_CBNY)
(
    long                            x, 
    signed Jc(LONG_MIN, LONG_MAX)   l,
    signed Jc(LONG_MIN, LONG_MAX)   r
)
{
#define     LONG_CBNY(X, L, R) \
((long) ((L <= ((long) X)) && (((long) X) <= R)))

    return  (l <= x) && (x <= r);
}


INLINE(   ullong,ULLONG_CBNY)
(
    ullong                      x, 
    unsigned Jc(0, ULLONG_MAX)  l,
    unsigned Jc(0, ULLONG_MAX)  r
)
{
#define     ULLONG_CBNY(X, L, R) \
((ullong) ((L <= ((ullong) X)) && (((ullong) X) <= R)))

    return  (l <= x) && (x <= r);
}

INLINE(    llong, LLONG_CBNY)
(
    llong                           x, 
    signed Jc(LLONG_MIN, LLONG_MAX) l,
    signed Jc(LLONG_MIN, LLONG_MAX) r
)
{
#define     LLONG_CBNY(X, L, R) \
((llong) ((L <= ((llong) X)) && (((llong) X) <= R)))

    return  (l <= x) && (x <= r);
}

#if 0 // _LEAVE_ALL_CBNY
}
#endif


#if 0 // _ENTER_ALL_CNBS
{
#endif

INLINE(ptrdiff_t,  ADDR_CNBS)
(
    void volatile const *x,
    void volatile const *l,
    void volatile const *r
)
{
#define ADDR_CNBS(X, L, R) \
((ptrdiff_t) (((L > ((void *) X)) || (((void *) X) > R)) ? -1 : 0))

    return ((l > x) || (x > r)) ? PTRDIFF_C(-1) : PTRDIFF_C(0);
}


INLINE(    uchar, UCHAR_CNBS)
(
    uchar x,
    Jc(0, UCHAR_MAX) l,
    Jc(0, UCHAR_MAX) r
)
{
#define     UCHAR_CNBS(X, L, R) \
((uchar) (((L>((uchar) X))||(((uchar) X)>R))?UCHAR_MAX:0))

    return  ((l > x) || (x > r)) ? UCHAR_MAX : 0;
}

INLINE(    schar, SCHAR_CNBS)
(
    schar x,
    Jc(SCHAR_MIN, SCHAR_MAX) l,
    Jc(SCHAR_MIN, SCHAR_MAX) r
)
{
#define     SCHAR_CNBS(X, L, R) \
((schar) (0-((L>((schar) X))||(((schar) X)>R))))

    return  ((l > x) || (x > r)) ? -1 : 0;
}

INLINE(     char,  CHAR_CNBS)
(
    char x,
    Jc(CHAR_MIN, CHAR_MAX) l,
    Jc(CHAR_MIN, CHAR_MAX) r
)
{
#define     CHAR_CNBS(X, L, R) \
((char) (((L > ((char) X)) || (((char) X) > R)) ? -1 : 0))

    return  ((l > x) || (x > r)) ? '\xff' : '\x00';
}


INLINE(   ushort, USHRT_CNBS)
(
    ushort x,
    Jc(0, USHRT_MAX) l,
    Jc(0, USHRT_MAX) r
)
{
#define     USHRT_CNBS(X, L, R) \
((ushort) (((L>((ushort) X))||(((ushort) X)>R))?USHRT_MAX:0))

    return  ((l > x) || (x > r)) ? USHRT_MAX : 0;
}

INLINE(    short,  SHRT_CNBS)
(
    short x,
    Jc(SHRT_MIN, SHRT_MAX) l,
    Jc(SHRT_MIN, SHRT_MAX) r
)
{
#define     SHRT_CNBS(X, L, R) \
((short) (0-((L>((short) X))||(((short) X)>R))))

    return  ((l > x) || (x > r)) ? -1 : 0;
}


INLINE(     uint,  UINT_CNBS)
(
    uint x,
    Jc(0, UINT_MAX) l,
    Jc(0, UINT_MAX) r
)
{
#define     UINT_CNBS(X, L, R) \
(((L>((uint)X))||(((uint)X)>R))?UINT_MAX:0U)

    return  ((l > x) || (x > r)) ? UINT_MAX : 0U;
}

INLINE(      int,   INT_CNBS)
(
    int x,
    Jc(INT_MIN, INT_MAX) l,
    Jc(INT_MIN, INT_MAX) r
)
{
#define     INT_CNBS(X, L, R) \
(0-((L>((int) X))||(((int) X)>R)))

    return  ((l > x) || (x > r)) ? -1 : 0;
}


INLINE(    ulong, ULONG_CNBS)
(
    ulong x,
    unsigned Jc(0, ULONG_MAX) l,
    unsigned Jc(0, ULONG_MAX) r
)
{
#define     ULONG_CNBS(X, L, R) \
(((L>((ulong)X))||(((ulong)X)>R))?ULONG_MAX:0UL)

    return  ((l > x) || (x > r)) ? UINT_MAX : 0UL;
}

INLINE(     long,  LONG_CNBS)
(
    long x,
    signed Jc(LONG_MIN, LONG_MAX) l,
    signed Jc(LONG_MIN, LONG_MAX) r
)
{
#define     LONG_CNBS(X, L, R) \
(0L-((L>((long) X))||(((long) X)>R)))

    return  ((l > x) || (x > r)) ? -1L : 0L;
}


INLINE(   ullong,ULLONG_CNBS)
(
    ullong x,
    unsigned Jc(0, ULLONG_MAX) l,
    unsigned Jc(0, ULLONG_MAX) r
)
{
#define     ULLONG_CNBS(X, L, R) \
(((L>((ullong)X))||(((ullong)X)>R))?ULLONG_MAX:0ULL)

    return  ((l > x) || (x > r)) ? ULONG_MAX : 0ULL;
}

INLINE(    llong, LLONG_CNBS)
(
    llong x,
    signed Jc(LLONG_MIN, LLONG_MAX) l,
    signed Jc(LLONG_MIN, LLONG_MAX) r
)
{
#define     LLONG_CNBS(X, L, R) \
(0LL-((L>((llong) X))||(((llong) X)>R)))

    return  ((l > x) || (x > r)) ? -1LL : 0LL;
}

#if 0 // _LEAVE_ALL_CNBS
}
#endif

#if 0 // _ENTER_ALL_CNBY
{
#endif

INLINE(ptrdiff_t,  ADDR_CNBY)
(
    void volatile const *x,
    void volatile const *l,
    void volatile const *r
)
{

    return  (l > x) || (x > r);
}


INLINE(    uchar, UCHAR_CNBY)   
(
    uchar x, 
    Jc(0, UCHAR_MAX) l,
    Jc(0, UCHAR_MAX) r
)
{
#define     UCHAR_CNBY(X, L, R) \
((uchar) ((L > ((uchar) X)) || (((uchar) X) > R)))

    return  (l > x) || (x > r);
}

INLINE(    schar, SCHAR_CNBY)   
(
    schar x, 
    Jc(SCHAR_MIN, SCHAR_MAX) l,
    Jc(SCHAR_MIN, SCHAR_MAX) r
)
{
#define     SCHAR_CNBY(X, L, R) \
((schar) ((L > ((schar) X)) || (((schar) X) > R)))

    return  (l > x) || (x > r);
}

INLINE(     char,  CHAR_CNBY)   
(
    char x, 
    Jc(CHAR_MIN, CHAR_MAX) l,
    Jc(CHAR_MIN, CHAR_MAX) r
)
{
#define     CHAR_CNBY(X, L, R) \
((char) ((L > ((char) X)) || (((char) X) > R)))

    return  (l > x) || (x > r);
}


INLINE(   ushort, USHRT_CNBY)
(
    ushort x, 
    Jc(0, USHRT_MAX) l,
    Jc(0, USHRT_MAX) r
)
{
#define     USHRT_CNBY(X, L, R) \
((ushort) ((L > ((ushort) X)) || (((ushort) X) > R)))

    return  (l > x) || (x > r);
}

INLINE(    short,  SHRT_CNBY)
(
    short x, 
    Jc(SHRT_MIN, SHRT_MAX) l,
    Jc(SHRT_MIN, SHRT_MAX) r
)
{
#define     SHRT_CNBY(X, L, R) \
((short) ((L > ((short) X)) || (((short) X) > R)))

    return  (l > x) || (x > r);
}


INLINE(     uint,  UINT_CNBY)
(
    uint x, 
    Jc(0, UINT_MAX) l,
    Jc(0, UINT_MAX) r
)
{
#define     UINT_CNBY(X, L, R) \
((uint) ((L > ((uint) X)) || (((uint) X) > R)))

    return  (l > x) || (x > r);
}

INLINE(      int,   INT_CNBY)
(
    int x, 
    Jc(INT_MIN, INT_MAX) l,
    Jc(INT_MIN, INT_MAX) r
)
{
#define     INT_CNBY(X, L, R) \
((int) ((L > ((int) X)) || (((int) X) > R)))

    return  (l > x) || (x > r);
}


INLINE(    ulong, ULONG_CNBY)
(
    ulong x, 
    unsigned Jc(0, ULONG_MAX) l,
    unsigned Jc(0, ULONG_MAX) r
)
{
#define     ULONG_CNBY(X, L, R) \
((ulong) ((L > ((ulong) X)) || (((ulong) X) > R)))

    return  (l > x) || (x > r);
}

INLINE(     long,  LONG_CNBY)
(
    long x, 
    signed Jc(LONG_MIN, LONG_MAX) l,
    signed Jc(LONG_MIN, LONG_MAX) r
)
{
#define     LONG_CNBY(X, L, R) \
((long) ((L > ((long) X)) || (((long) X) > R)))

    return  (l > x) || (x > r);
}


INLINE(   ullong,ULLONG_CNBY)
(
    ullong x, 
    unsigned Jc(0, ULLONG_MAX) l,
    unsigned Jc(0, ULLONG_MAX) r
)
{
#define     ULLONG_CNBY(X, L, R) \
((ullong) ((L > ((ullong) X)) || (((ullong) X) > R)))

    return  (l > x) || (x > r);
}

INLINE(    llong, LLONG_CNBY)
(
    llong x, 
    signed Jc(LLONG_MIN, LLONG_MAX) l,
    signed Jc(LLONG_MIN, LLONG_MAX) r
)
{
#define     LLONG_CNBY(X, L, R) \
((llong) ((L > ((llong) X)) || (((llong) X) > R)))

    return  (l > x) || (x > r);
}

#if 0 // _LEAVE_ALL_CNBY
}
#endif


#if 0 // _ENTER_ALL_CEQS
{
#endif

#ifdef SPC_NO_CEQSZ

INLINE( uchar, UCHAR_CEQS)  (uchar a,  uchar b) {return  a==b ? -1 : 0;}
INLINE( schar, SCHAR_CEQS)  (schar a,  schar b) {return  a==b ? -1 : 0;}
INLINE(  char,  CHAR_CEQS)   (char a,   char b) {return  a==b ? -1 : 0;}
INLINE(ushort, USHRT_CEQS) (ushort a, ushort b) {return  a==b ? -1 : 0;}
INLINE( short,  SHRT_CEQS)  (short a,  short b) {return  a==b ? -1 : 0;}
INLINE(  uint,  UINT_CEQS)   (uint a,   uint b) {return  a==b ? -1 : 0;}
INLINE(   int,   INT_CEQS)    (int a,    int b) {return  a==b ? -1 : 0;}
INLINE( ulong, ULONG_CEQS)  (ulong a,  ulong b) {return  a==b ? -1 : 0;}
INLINE(  long,  LONG_CEQS)   (long a,   long b) {return  a==b ? -1 : 0;}
INLINE(ullong,ULLONG_CEQS) (ullong a, ullong b) {return  a==b ? -1 : 0;}
INLINE( llong, LLONG_CEQS)  (llong a,  llong b) {return  a==b ? -1 : 0;}

#endif

#if 0 // _LEAVE_ALL_CEQS
}
#endif

#if 0 // _ENTER_ALL_CEQY
{
#endif

INLINE(ptrdiff_t, ADDR_CEQY) (void volatile const *a, void volatile const *b)
{
    return  a==b;
}

INLINE(  _Bool,  BOOL_CEQY)   (_Bool a,   _Bool b) {return a==b;}
INLINE(  uchar, UCHAR_CEQY)   (uchar a,   uchar b) {return a==b;}
INLINE(  schar, SCHAR_CEQY)   (schar a,   schar b) {return a==b;}
INLINE(   char,  CHAR_CEQY)    (char a,    char b) {return a==b;}
INLINE( ushort, USHRT_CEQY)  (ushort a,  ushort b) {return a==b;}
INLINE(  short,  SHRT_CEQY)   (short a,   short b) {return a==b;}
INLINE(   uint,  UINT_CEQY)    (uint a,    uint b) {return a==b;}
INLINE(    int,   INT_CEQY)     (int a,     int b) {return a==b;}
INLINE(  ulong, ULONG_CEQY)   (ulong a,   ulong b) {return a==b;}
INLINE(   long,  LONG_CEQY)    (long a,    long b) {return a==b;}
INLINE( ullong,ULLONG_CEQY)  (ullong a,  ullong b) {return a==b;}
INLINE(  llong, LLONG_CEQY)   (llong a,   llong b) {return a==b;}

#if 0 // _LEAVE_ALL_CEQY
}
#endif

#if 0 // _ENTER_ALL_CNEY
{
#endif

INLINE(ptrdiff_t,ADDR_CNEY) (void volatile const *a, void volatile const *b)
{
    return  a!=b;
}

INLINE(  _Bool,  BOOL_CNEY)   (_Bool a,   _Bool b) {return a!=b;}
INLINE(  uchar, UCHAR_CNEY)   (uchar a,   uchar b) {return a!=b;}
INLINE(  schar, SCHAR_CNEY)   (schar a,   schar b) {return a!=b;}
INLINE(   char,  CHAR_CNEY)    (char a,    char b) {return a!=b;}
INLINE( ushort, USHRT_CNEY)  (ushort a,  ushort b) {return a!=b;}
INLINE(  short,  SHRT_CNEY)   (short a,   short b) {return a!=b;}
INLINE(   uint,  UINT_CNEY)    (uint a,    uint b) {return a!=b;}
INLINE(    int,   INT_CNEY)     (int a,     int b) {return a!=b;}
INLINE(  ulong, ULONG_CNEY)   (ulong a,   ulong b) {return a!=b;}
INLINE(   long,  LONG_CNEY)    (long a,    long b) {return a!=b;}
INLINE( ullong,ULLONG_CNEY)  (ullong a,  ullong b) {return a!=b;}
INLINE(  llong, LLONG_CNEY)   (llong a,   llong b) {return a!=b;}

#if 0 // _LEAVE_ALL_CNEY
}
#endif

#if 0 // _ENTER_ALL_CNES
{
#endif

#ifdef SPC_NO_CNESZ

INLINE( uchar, UCHAR_CNES)  (uchar a,  uchar b) {return  a!=b ? -1 : 0;}
INLINE( schar, SCHAR_CNES)  (schar a,  schar b) {return  a!=b ? -1 : 0;}
INLINE(  char,  CHAR_CNES)   (char a,   char b) {return  a!=b ? -1 : 0;}
INLINE(ushort, USHRT_CNES) (ushort a, ushort b) {return  a!=b ? -1 : 0;}
INLINE( short,  SHRT_CNES)  (short a,  short b) {return  a!=b ? -1 : 0;}
INLINE(  uint,  UINT_CNES)   (uint a,   uint b) {return  a!=b ? -1 : 0;}
INLINE(   int,   INT_CNES)    (int a,    int b) {return  a!=b ? -1 : 0;}
INLINE( ulong, ULONG_CNES)  (ulong a,  ulong b) {return  a!=b ? -1 : 0;}
INLINE(  long,  LONG_CNES)   (long a,   long b) {return  a!=b ? -1 : 0;}
INLINE(ullong,ULLONG_CNES) (ullong a, ullong b) {return  a!=b ? -1 : 0;}
INLINE( llong, LLONG_CNES)  (llong a,  llong b) {return  a!=b ? -1 : 0;}

#endif

#if 0 // _LEAVE_ALL_CNES
}
#endif

#if 0 // _ENTER_ALL_CLTS
{
#endif

#ifdef SPC_NO_CLTSZ

INLINE( uchar, UCHAR_CLTS)  (uchar a,  uchar b) {return  a<b ? -1 : 0;}
INLINE( schar, SCHAR_CLTS)  (schar a,  schar b) {return  a<b ? -1 : 0;}
INLINE(  char,  CHAR_CLTS)   (char a,   char b) {return  a<b ? -1 : 0;}
INLINE(ushort, USHRT_CLTS) (ushort a, ushort b) {return  a<b ? -1 : 0;}
INLINE( short,  SHRT_CLTS)  (short a,  short b) {return  a<b ? -1 : 0;}
INLINE(  uint,  UINT_CLTS)   (uint a,   uint b) {return  a<b ? -1 : 0;}
INLINE(   int,   INT_CLTS)    (int a,    int b) {return  a<b ? -1 : 0;}
INLINE( ulong, ULONG_CLTS)  (ulong a,  ulong b) {return  a<b ? -1 : 0;}
INLINE(  long,  LONG_CLTS)   (long a,   long b) {return  a<b ? -1 : 0;}
INLINE(ullong,ULLONG_CLTS) (ullong a, ullong b) {return  a<b ? -1 : 0;}
INLINE( llong, LLONG_CLTS)  (llong a,  llong b) {return  a<b ? -1 : 0;}

#endif

#if 0 // _LEAVE_ALL_CLTS
}
#endif

#if 0 // _ENTER_ALL_CLTY
{
#endif

INLINE(ptrdiff_t, ADDR_CLTY) (void volatile const *a, void volatile const *b)
{
    return  a<b;
}
INLINE( _Bool,   BOOL_CLTY)   (_Bool a,   _Bool b) {return a<b;}
INLINE(  uchar, UCHAR_CLTY)   (uchar a,   uchar b) {return a<b;}
INLINE(  schar, SCHAR_CLTY)   (schar a,   schar b) {return a<b;}
INLINE(   char,  CHAR_CLTY)    (char a,    char b) {return a<b;}
INLINE( ushort, USHRT_CLTY)  (ushort a,  ushort b) {return a<b;}
INLINE(  short,  SHRT_CLTY)   (short a,   short b) {return a<b;}
INLINE(   uint,  UINT_CLTY)    (uint a,    uint b) {return a<b;}
INLINE(    int,   INT_CLTY)     (int a,     int b) {return a<b;}
INLINE(  ulong, ULONG_CLTY)   (ulong a,   ulong b) {return a<b;}
INLINE(   long,  LONG_CLTY)    (long a,    long b) {return a<b;}
INLINE( ullong,ULLONG_CLTY)  (ullong a,  ullong b) {return a<b;}
INLINE(  llong, LLONG_CLTY)   (llong a,   llong b) {return a<b;}

#if 0 // _LEAVE_ALL_CLTY
}
#endif

#if 0 // _ENTER_ALL_CLES
{
#endif

#ifdef SPC_NO_CLESZ

INLINE( uchar, UCHAR_CLES)  (uchar a,  uchar b) {return  a<=b ? -1 : 0;}
INLINE( schar, SCHAR_CLES)  (schar a,  schar b) {return  a<=b ? -1 : 0;}
INLINE(  char,  CHAR_CLES)   (char a,   char b) {return  a<=b ? -1 : 0;}
INLINE(ushort, USHRT_CLES) (ushort a, ushort b) {return  a<=b ? -1 : 0;}
INLINE( short,  SHRT_CLES)  (short a,  short b) {return  a<=b ? -1 : 0;}
INLINE(  uint,  UINT_CLES)   (uint a,   uint b) {return  a<=b ? -1 : 0;}
INLINE(   int,   INT_CLES)    (int a,    int b) {return  a<=b ? -1 : 0;}
INLINE( ulong, ULONG_CLES)  (ulong a,  ulong b) {return  a<=b ? -1 : 0;}
INLINE(  long,  LONG_CLES)   (long a,   long b) {return  a<=b ? -1 : 0;}
INLINE(ullong,ULLONG_CLES) (ullong a, ullong b) {return  a<=b ? -1 : 0;}
INLINE( llong, LLONG_CLES)  (llong a,  llong b) {return  a<=b ? -1 : 0;}

#endif

#if 0 // _LEAVE_ALL_CLES
}
#endif

#if 0 // _ENTER_ALL_CLEY
{
#endif

INLINE(ptrdiff_t, ADDR_CLEY) (void volatile const *a, void volatile const *b)
{
    return  a<=b;
}

INLINE(  uchar, UCHAR_CLEY)   (uchar a,   uchar b) {return a<=b;}
INLINE(  schar, SCHAR_CLEY)   (schar a,   schar b) {return a<=b;}
INLINE(   char,  CHAR_CLEY)    (char a,    char b) {return a<=b;}
INLINE( ushort, USHRT_CLEY)  (ushort a,  ushort b) {return a<=b;}
INLINE(  short,  SHRT_CLEY)   (short a,   short b) {return a<=b;}
INLINE(   uint,  UINT_CLEY)    (uint a,    uint b) {return a<=b;}
INLINE(    int,   INT_CLEY)     (int a,     int b) {return a<=b;}
INLINE(  ulong, ULONG_CLEY)   (ulong a,   ulong b) {return a<=b;}
INLINE(   long,  LONG_CLEY)    (long a,    long b) {return a<=b;}
INLINE( ullong,ULLONG_CLEY)  (ullong a,  ullong b) {return a<=b;}
INLINE(  llong, LLONG_CLEY)   (llong a,   llong b) {return a<=b;}

#if 0 // _LEAVE_ALL_CLEY
}
#endif

#if 0 // _ENTER_ALL_CGTS
{
#endif

#ifdef SPC_NO_CGTSZ

INLINE( uchar, UCHAR_CGTS)  (uchar a,  uchar b) {return  a>b ? -1 : 0;}
INLINE( schar, SCHAR_CGTS)  (schar a,  schar b) {return  a>b ? -1 : 0;}
INLINE(  char,  CHAR_CGTS)   (char a,   char b) {return  a>b ? -1 : 0;}
INLINE(ushort, USHRT_CGTS) (ushort a, ushort b) {return  a>b ? -1 : 0;}
INLINE( short,  SHRT_CGTS)  (short a,  short b) {return  a>b ? -1 : 0;}
INLINE(  uint,  UINT_CGTS)   (uint a,   uint b) {return  a>b ? -1 : 0;}
INLINE(   int,   INT_CGTS)    (int a,    int b) {return  a>b ? -1 : 0;}
INLINE( ulong, ULONG_CGTS)  (ulong a,  ulong b) {return  a>b ? -1 : 0;}
INLINE(  long,  LONG_CGTS)   (long a,   long b) {return  a>b ? -1 : 0;}
INLINE(ullong,ULLONG_CGTS) (ullong a, ullong b) {return  a>b ? -1 : 0;}
INLINE( llong, LLONG_CGTS)  (llong a,  llong b) {return  a>b ? -1 : 0;}

#endif

#if 0 // _LEAVE_ALL_CGTS
}
#endif

#if 0 // _ENTER_ALL_CGTY
{
#endif

INLINE(ptrdiff_t, ADDR_CGTY) (void volatile const *a, void volatile const *b)
{
    return  a>b;
}
INLINE( _Bool,   BOOL_CGTY)   (_Bool a,   _Bool b) {return a>b;}
INLINE(  uchar, UCHAR_CGTY)   (uchar a,   uchar b) {return a>b;}
INLINE(  schar, SCHAR_CGTY)   (schar a,   schar b) {return a>b;}
INLINE(   char,  CHAR_CGTY)    (char a,    char b) {return a>b;}
INLINE( ushort, USHRT_CGTY)  (ushort a,  ushort b) {return a>b;}
INLINE(  short,  SHRT_CGTY)   (short a,   short b) {return a>b;}
INLINE(   uint,  UINT_CGTY)    (uint a,    uint b) {return a>b;}
INLINE(    int,   INT_CGTY)     (int a,     int b) {return a>b;}
INLINE(  ulong, ULONG_CGTY)   (ulong a,   ulong b) {return a>b;}
INLINE(   long,  LONG_CGTY)    (long a,    long b) {return a>b;}
INLINE( ullong,ULLONG_CGTY)  (ullong a,  ullong b) {return a>b;}
INLINE(  llong, LLONG_CGTY)   (llong a,   llong b) {return a>b;}

#if 0 // _LEAVE_ALL_CGTY
}
#endif

#if 0 // _ENTER_ALL_CGES
{
#endif

#ifdef SPC_NO_CGESZ

INLINE( uchar, UCHAR_CGES)  (uchar a,  uchar b) {return  a>=b ? -1 : 0;}
INLINE( schar, SCHAR_CGES)  (schar a,  schar b) {return  a>=b ? -1 : 0;}
INLINE(  char,  CHAR_CGES)   (char a,   char b) {return  a>=b ? -1 : 0;}
INLINE(ushort, USHRT_CGES) (ushort a, ushort b) {return  a>=b ? -1 : 0;}
INLINE( short,  SHRT_CGES)  (short a,  short b) {return  a>=b ? -1 : 0;}
INLINE(  uint,  UINT_CGES)   (uint a,   uint b) {return  a>=b ? -1 : 0;}
INLINE(   int,   INT_CGES)    (int a,    int b) {return  a>=b ? -1 : 0;}
INLINE( ulong, ULONG_CGES)  (ulong a,  ulong b) {return  a>=b ? -1 : 0;}
INLINE(  long,  LONG_CGES)   (long a,   long b) {return  a>=b ? -1 : 0;}
INLINE(ullong,ULLONG_CGES) (ullong a, ullong b) {return  a>=b ? -1 : 0;}
INLINE( llong, LLONG_CGES)  (llong a,  llong b) {return  a>=b ? -1 : 0;}

#endif

#if 0 // _LEAVE_ALL_CGES
}
#endif

#if 0 // _ENTER_ALL_CGEY
{
#endif

INLINE(ptrdiff_t, ADDR_CGEY) (void volatile const *a, void volatile const *b)
{
    return  a>=b;
}

INLINE(  uchar, UCHAR_CGEY)   (uchar a,   uchar b) {return a>=b;}
INLINE(  schar, SCHAR_CGEY)   (schar a,   schar b) {return a>=b;}
INLINE(   char,  CHAR_CGEY)    (char a,    char b) {return a>=b;}
INLINE( ushort, USHRT_CGEY)  (ushort a,  ushort b) {return a>=b;}
INLINE(  short,  SHRT_CGEY)   (short a,   short b) {return a>=b;}
INLINE(   uint,  UINT_CGEY)    (uint a,    uint b) {return a>=b;}
INLINE(    int,   INT_CGEY)     (int a,     int b) {return a>=b;}
INLINE(  ulong, ULONG_CGEY)   (ulong a,   ulong b) {return a>=b;}
INLINE(   long,  LONG_CGEY)    (long a,    long b) {return a>=b;}
INLINE( ullong,ULLONG_CGEY)  (ullong a,  ullong b) {return a>=b;}
INLINE(  llong, LLONG_CGEY)   (llong a,   llong b) {return a>=b;}

#if 0 // _LEAVE_ALL_CGEY
}
#endif


#if 0 // _ENTER_ALL_TSTS
{
#endif

#ifdef SPC_NO_TSTSZ

INLINE( uchar, UCHAR_TSTS) (unsigned a, unsigned b) 
{
    return  (UCHAR_MAXa&b) ? -1 : 0;
}

INLINE( schar, SCHAR_TSTS)   (signed a, unsigned b) 
{
    return  (UCHAR_MAX&a&b) ? -1 : 0;
}

INLINE(  char,  CHAR_TSTS)      (int a, unsigned b) 
{
    return  (UCHAR_MAX&a&b) ? -1 : 0;
}


INLINE(ushort, USHRT_TSTS) (unsigned a, unsigned b) 
{
    return  (USHRT_MAX&a&b) ? -1 : 0;
}

INLINE( short,  SHRT_TSTS)   (signed a, unsigned b) 
{
    return  (USHRT_MAX&a&b) ? -1 : 0;
}


INLINE(  uint,  UINT_TSTS)     (uint a,     uint b) 
{
    return  (a&b) ? -1 : 0;
}

INLINE(   int,   INT_TSTS)      (int a,     uint b) 
{
    return  (a&b) ? -1 : 0;
}


INLINE( ulong, ULONG_TSTS)    (ulong a,    ulong b) 
{
    return  (a&b) ? -1 : 0;
}

INLINE(  long,  LONG_TSTS)     (long a,    ulong b) 
{
    return  (a&b) ? -1 : 0;
}


INLINE(ullong,ULLONG_TSTS)   (ullong a,   ullong b) 
{
    return  (a&b) ? -1 : 0;
}

INLINE( llong, LLONG_TSTS)    (llong a,   ullong b) 
{
    return  (a&b) ? -1 : 0;
}

#endif

#if 0 // _LEAVE_ALL_TSTS
}
#endif

#if 0 // _ENTER_ALL_TSTY
{
#endif

#ifdef SPC_NO_TSTYZ

INLINE( uchar, UCHAR_TSTY) (unsigned a, unsigned b) 
{
    return  (UCHAR_MAXa&b) ? 1 : 0;
}

INLINE( schar, SCHAR_TSTY)   (signed a, unsigned b) 
{
    return  (UCHAR_MAX&a&b) ? 1 : 0;
}

INLINE(  char,  CHAR_TSTY)      (int a, unsigned b) 
{
    return  (UCHAR_MAX&a&b) ? 1 : 0;
}


INLINE(ushort, USHRT_TSTY) (unsigned a, unsigned b) 
{
    return  (USHRT_MAX&a&b) ? 1 : 0;
}

INLINE( short,  SHRT_TSTY)   (signed a, unsigned b) 
{
    return  (USHRT_MAX&a&b) ? 1 : 0;
}


INLINE(  uint,  UINT_TSTY)     (uint a,     uint b) 
{
    return  (a&b) ? 1 : 0;
}

INLINE(   int,   INT_TSTY)      (int a,     uint b) 
{
    return  (a&b) ? 1 : 0;
}


INLINE( ulong, ULONG_TSTY)    (ulong a,    ulong b) 
{
    return  (a&b) ? 1 : 0;
}

INLINE(  long,  LONG_TSTY)     (long a,    ulong b) 
{
    return  (a&b) ? 1 : 0;
}


INLINE(ullong,ULLONG_TSTY)   (ullong a,   ullong b) 
{
    return  (a&b) ? 1 : 0;
}

INLINE( llong, LLONG_TSTY)    (llong a,   ullong b) 
{
    return  (a&b) ? 1 : 0;
}

#endif

#if 0 // _LEAVE_ALL_TSTY
}
#endif

#if 0 // _ENTER_ALL_INVS
{
#endif

INLINE( _Bool,  BOOL_INVS)    (_Bool a) {return ~a;}
INLINE( uchar, UCHAR_INVS) (unsigned a) {return ~a;}
INLINE( schar, SCHAR_INVS)   (signed a) {return ~a;}
INLINE(  char,  CHAR_INVS)      (int a) {return ~a;}
INLINE(ushort, USHRT_INVS) (unsigned a) {return ~a;}
INLINE( short,  SHRT_INVS)   (signed a) {return ~a;}
INLINE(  uint,  UINT_INVS)     (uint a) {return ~a;}
INLINE(   int,   INT_INVS)      (int a) {return ~a;}
INLINE( ulong, ULONG_INVS)    (ulong a) {return ~a;}
INLINE(  long,  LONG_INVS)     (long a) {return ~a;}
INLINE(ullong,ULLONG_INVS)   (ullong a) {return ~a;}
INLINE( llong, LLONG_INVS)    (llong a) {return ~a;}

INLINE(flt16_t, FLT16_INVS) (flt16_t a)
{
#define     FLT16_INVS(A) ((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U}).F
    HALF_TYPE z = {.F=a};
    z.U = ~z.U;
    return  z.F;
}

INLINE(  float,   FLT_INVS)   (float a)
{
#define     FLT_INVS(A) ((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U}).F
    WORD_TYPE z = {.F=a};
    z.U = ~z.U;
    return  z.F;
}

INLINE( double,   DBL_INVS)  (double a)
{
#define     DBL_INVS(A) ((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U}).F
    DWRD_TYPE z = {.F=a};
    z.U = ~z.U;
    return  z.F;
}

#if 0 // _LEAVE_ALL_INVS
}
#endif


#if 0 // _ENTER_ALL_ANDS
{
#endif

INLINE(  _Bool,  BOOL_ANDS)   (_Bool a,   _Bool b) {return a&b;}
INLINE(  uchar, UCHAR_ANDS)   (uchar a,   uchar b) {return a&b;}
INLINE(  schar, SCHAR_ANDS)   (schar a,   schar b) {return a&b;}
INLINE(   char,  CHAR_ANDS)    (char a,    char b) {return a&b;}
INLINE( ushort, USHRT_ANDS)  (ushort a,  ushort b) {return a&b;}
INLINE(  short,  SHRT_ANDS)   (short a,   short b) {return a&b;}
INLINE(   uint,  UINT_ANDS)    (uint a,    uint b) {return a&b;}
INLINE(    int,   INT_ANDS)     (int a,     int b) {return a&b;}
INLINE(  ulong, ULONG_ANDS)   (ulong a,   ulong b) {return a&b;}
INLINE(   long,  LONG_ANDS)    (long a,    long b) {return a&b;}
INLINE( ullong,ULLONG_ANDS)  (ullong a,  ullong b) {return a&b;}
INLINE(  llong, LLONG_ANDS)   (llong a,   llong b) {return a&b;}

INLINE(flt16_t, FLT16_ANDS) (flt16_t a, flt16_t b)
{
#define     FLT16_ANDS(A, B) \
(((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U&((HALF_TYPE){.F=B}).U}).F)

    HALF_TYPE l={.F=a}, r={.F=b};
    l.U &=  r.U;
    return  l.F;
}

INLINE(  float,   FLT_ANDS)   (float a,   float b)
{
#define     FLT_ANDS(A, B) \
(((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U&((WORD_TYPE){.F=B}).U}).F)

    WORD_TYPE l={.F=a}, r={.F=b};
    l.U &=  r.U;
    return  l.F;
}

INLINE( double,   DBL_ANDS)  (double a,  double b)
{
#define     DBL_ANDS(A, B) \
(((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U&((DWRD_TYPE){.F=B}).U}).F)

    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U &=  r.U;
    return  l.F;
}

#if 0 // _LEAVE_ALL_ANDS
}
#endif

#if 0 // _ENTER_ALL_ANDN
{
#endif

INLINE(  _Bool,  BOOL_ANDN)   (_Bool a,   _Bool b) {return a&~b;}
INLINE(  uchar, UCHAR_ANDN)   (uchar a,   uchar b) {return a&~b;}
INLINE(  schar, SCHAR_ANDN)   (schar a,   schar b) {return a&~b;}
INLINE(   char,  CHAR_ANDN)    (char a,    char b) {return a&~b;}
INLINE( ushort, USHRT_ANDN)  (ushort a,  ushort b) {return a&~b;}
INLINE(  short,  SHRT_ANDN)   (short a,   short b) {return a&~b;}
INLINE(   uint,  UINT_ANDN)    (uint a,    uint b) {return a&~b;}
INLINE(    int,   INT_ANDN)     (int a,     int b) {return a&~b;}
INLINE(  ulong, ULONG_ANDN)   (ulong a,   ulong b) {return a&~b;}
INLINE(   long,  LONG_ANDN)    (long a,    long b) {return a&~b;}
INLINE( ullong,ULLONG_ANDN)  (ullong a,  ullong b) {return a&~b;}
INLINE(  llong, LLONG_ANDN)   (llong a,   llong b) {return a&~b;}

INLINE(flt16_t, FLT16_ANDN) (flt16_t a, flt16_t b)
{
#define     FLT16_ANDN(A, B) \
(((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U&~((HALF_TYPE){.F=B}).U}).F)

    HALF_TYPE l={.F=a}, r={.F=b};
    l.U &= ~r.U;
    return  l.F;
}

INLINE(  float,   FLT_ANDN)   (float a,   float b)
{
#define     FLT_ANDN(A, B) \
(((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U&~((WORD_TYPE){.F=B}).U}).F)

    WORD_TYPE l={.F=a}, r={.F=b};
    l.U &= ~r.U;
    return  l.F;
}

INLINE( double,   DBL_ANDN)  (double a,  double b)
{
#define     DBL_ANDN(A, B) \
(((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U&~((DWRD_TYPE){.F=B}).U}).F)

    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U &= ~r.U;
    return  l.F;
}

#if 0 // _LEAVE_ALL_ANDN
}
#endif


#if 0 // _ENTER_ALL_ORRS
{
#endif

INLINE(  _Bool,  BOOL_ORRS)   (_Bool a,   _Bool b) {return a|b;}
INLINE(  uchar, UCHAR_ORRS)   (uchar a,   uchar b) {return a|b;}
INLINE(  schar, SCHAR_ORRS)   (schar a,   schar b) {return a|b;}
INLINE(   char,  CHAR_ORRS)    (char a,    char b) {return a|b;}
INLINE( ushort, USHRT_ORRS)  (ushort a,  ushort b) {return a|b;}
INLINE(  short,  SHRT_ORRS)   (short a,   short b) {return a|b;}
INLINE(   uint,  UINT_ORRS)    (uint a,    uint b) {return a|b;}
INLINE(    int,   INT_ORRS)     (int a,     int b) {return a|b;}
INLINE(  ulong, ULONG_ORRS)   (ulong a,   ulong b) {return a|b;}
INLINE(   long,  LONG_ORRS)    (long a,    long b) {return a|b;}
INLINE( ullong,ULLONG_ORRS)  (ullong a,  ullong b) {return a|b;}
INLINE(  llong, LLONG_ORRS)   (llong a,   llong b) {return a|b;}

INLINE(flt16_t, FLT16_ORRS) (flt16_t a, flt16_t b)
{
#define     FLT16_ORRS(A, B) \
(((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U|((HALF_TYPE){.F=B}).U}).F)

    HALF_TYPE l={.F=a}, r={.F=b};
    l.U |=  r.U;
    return  l.F;
}

INLINE(  float,   FLT_ORRS)   (float a,   float b)
{
#define     FLT_ORRS(A, B) \
(((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U|((WORD_TYPE){.F=B}).U}).F)

    WORD_TYPE l={.F=a}, r={.F=b};
    l.U |=  r.U;
    return  l.F;
}

INLINE( double,   DBL_ORRS)  (double a,  double b)
{
#define     DBL_ORRS(A, B) \
(((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U|((DWRD_TYPE){.F=B}).U}).F)

    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U |=  r.U;
    return  l.F;
}

#if 0 // _LEAVE_ALL_ORRS
}
#endif

#if 0 // _ENTER_ALL_ORRN
{
#endif

INLINE(  _Bool,  BOOL_ORRN)   (_Bool a,   _Bool b) {return a|~b;}
INLINE(  uchar, UCHAR_ORRN)   (uchar a,   uchar b) {return a|~b;}
INLINE(  schar, SCHAR_ORRN)   (schar a,   schar b) {return a|~b;}
INLINE(   char,  CHAR_ORRN)    (char a,    char b) {return a|~b;}
INLINE( ushort, USHRT_ORRN)  (ushort a,  ushort b) {return a|~b;}
INLINE(  short,  SHRT_ORRN)   (short a,   short b) {return a|~b;}
INLINE(   uint,  UINT_ORRN)    (uint a,    uint b) {return a|~b;}
INLINE(    int,   INT_ORRN)     (int a,     int b) {return a|~b;}
INLINE(  ulong, ULONG_ORRN)   (ulong a,   ulong b) {return a|~b;}
INLINE(   long,  LONG_ORRN)    (long a,    long b) {return a|~b;}
INLINE( ullong,ULLONG_ORRN)  (ullong a,  ullong b) {return a|~b;}
INLINE(  llong, LLONG_ORRN)   (llong a,   llong b) {return a|~b;}

INLINE(flt16_t, FLT16_ORRN) (flt16_t a, flt16_t b)
{
#define     FLT16_ORRN(A, B) \
(((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U|~((HALF_TYPE){.F=B}).U}).F)

    HALF_TYPE l={.F=a}, r={.F=b};
    l.U |= ~r.U;
    return  l.F;
}

INLINE(  float,   FLT_ORRN)   (float a,   float b)
{
#define     FLT_ORRN(A, B) \
(((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U|~((WORD_TYPE){.F=B}).U}).F)

    WORD_TYPE l={.F=a}, r={.F=b};
    l.U |= ~r.U;
    return  l.F;
}

INLINE( double,   DBL_ORRN)  (double a,  double b)
{
#define     DBL_ORRN(A, B) \
(((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U|~((DWRD_TYPE){.F=B}).U}).F)

    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U |= ~r.U;
    return  l.F;
}

#if 0 // _LEAVE_ALL_ORRN
}
#endif


#if 0 // _ENTER_ALL_XORS
{
#endif

INLINE(  _Bool,  BOOL_XORS)   (_Bool a,   _Bool b) {return a^b;}
INLINE(  uchar, UCHAR_XORS)   (uchar a,   uchar b) {return a^b;}
INLINE(  schar, SCHAR_XORS)   (schar a,   schar b) {return a^b;}
INLINE(   char,  CHAR_XORS)    (char a,    char b) {return a^b;}
INLINE( ushort, USHRT_XORS)  (ushort a,  ushort b) {return a^b;}
INLINE(  short,  SHRT_XORS)   (short a,   short b) {return a^b;}
INLINE(   uint,  UINT_XORS)    (uint a,    uint b) {return a^b;}
INLINE(    int,   INT_XORS)     (int a,     int b) {return a^b;}
INLINE(  ulong, ULONG_XORS)   (ulong a,   ulong b) {return a^b;}
INLINE(   long,  LONG_XORS)    (long a,    long b) {return a^b;}
INLINE( ullong,ULLONG_XORS)  (ullong a,  ullong b) {return a^b;}
INLINE(  llong, LLONG_XORS)   (llong a,   llong b) {return a^b;}

INLINE(flt16_t, FLT16_XORS) (flt16_t a, flt16_t b)
{
#define     FLT16_XORS(A, B) \
(((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U^((HALF_TYPE){.F=B}).U}).F)

    HALF_TYPE l={.F=a}, r={.F=b};
    l.U ^=  r.U;
    return  l.F;
}

INLINE(  float,   FLT_XORS)   (float a,   float b)
{
#define     FLT_XORS(A, B) \
(((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U^((WORD_TYPE){.F=B}).U}).F)

    WORD_TYPE l={.F=a}, r={.F=b};
    l.U ^=  r.U;
    return  l.F;
}

INLINE( double,   DBL_XORS)  (double a,  double b)
{
#define     DBL_XORS(A, B) \
(((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U^((DWRD_TYPE){.F=B}).U}).F)

    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U ^=  r.U;
    return  l.F;
}

#if 0 // _LEAVE_ALL_XORS
}
#endif

#if 0 // _ENTER_ALL_XORN
{
#endif

INLINE(  _Bool,  BOOL_XORN)   (_Bool a,   _Bool b) {return a^~b;}
INLINE(  uchar, UCHAR_XORN)   (uchar a,   uchar b) {return a^~b;}
INLINE(  schar, SCHAR_XORN)   (schar a,   schar b) {return a^~b;}
INLINE(   char,  CHAR_XORN)    (char a,    char b) {return a^~b;}
INLINE( ushort, USHRT_XORN)  (ushort a,  ushort b) {return a^~b;}
INLINE(  short,  SHRT_XORN)   (short a,   short b) {return a^~b;}
INLINE(   uint,  UINT_XORN)    (uint a,    uint b) {return a^~b;}
INLINE(    int,   INT_XORN)     (int a,     int b) {return a^~b;}
INLINE(  ulong, ULONG_XORN)   (ulong a,   ulong b) {return a^~b;}
INLINE(   long,  LONG_XORN)    (long a,    long b) {return a^~b;}
INLINE( ullong,ULLONG_XORN)  (ullong a,  ullong b) {return a^~b;}
INLINE(  llong, LLONG_XORN)   (llong a,   llong b) {return a^~b;}

INLINE(flt16_t, FLT16_XORN) (flt16_t a, flt16_t b)
{
#define     FLT16_XORN(A, B) \
(((HALF_TYPE){.U=((HALF_TYPE){.F=A}).U^~((HALF_TYPE){.F=B}).U}).F)

    HALF_TYPE l={.F=a}, r={.F=b};
    l.U ^= ~r.U;
    return  l.F;
}

INLINE(  float,   FLT_XORN)   (float a,   float b)
{
#define     FLT_XORN(A, B) \
(((WORD_TYPE){.U=((WORD_TYPE){.F=A}).U^~((WORD_TYPE){.F=B}).U}).F)

    WORD_TYPE l={.F=a}, r={.F=b};
    l.U ^= ~r.U;
    return  l.F;
}

INLINE( double,   DBL_XORN)  (double a,  double b)
{
#define     DBL_XORN(A, B) \
(((DWRD_TYPE){.U=((DWRD_TYPE){.F=A}).U^~((DWRD_TYPE){.F=B}).U}).F)

    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U ^= ~r.U;
    return  l.F;
}

#if 0 // _LEAVE_ALL_XORN
}
#endif


#if 0 // _ENTER_ALL_SHLL
{
#endif

#define     shllwz(A, B) (((unsigned) A)<<B)
#define     shlldz(A, B) (((uint64_t) A)<<B)

INLINE( _Bool,  BOOL_SHLL)  (_Bool a, Rc(0,  1) b)
{
#define     BOOL_SHLL(A, B) ((_Bool) (A&&!B))
    return  a && !b;
}


INLINE( uchar, UCHAR_SHLL)  (uchar a, Rc(0, UCHAR_WIDTH) b) 
{
#define     UCHAR_SHLL(A, B) ((uchar) shllwz(A,B))
    return  shllwz(a, b);
}

INLINE( schar, SCHAR_SHLL)  (schar a, Rc(0, SCHAR_WIDTH) b) 
{
#define     SCHAR_SHLL(A, B) ((schar) ((SCHAR_MIN&A)|(SCHAR_MAX&shllwz(A,B))))
    unsigned q = SCHAR_MIN&a;
    unsigned p = SCHAR_MAX&shllwz(a, b);
    return  p|q;
}

INLINE(  char,  CHAR_SHLL)   (char a, Rc(0,  CHAR_WIDTH) b) 
{
#if CHAR_MIN
#   define     CHAR_SHLL(A, B) ((char) ((CHAR_MIN&A)|(CHAR_MAX&shllwz(A,B))))
    unsigned q = CHAR_MIN&a;
    unsigned p = CHAR_MAX&shllwz(a, b);
    return  p|q;
#else
#   define  CHAR_SHLL(A, B) ((char) shllwz(A,B))
    return  shllwz(a, b);
#endif
}


INLINE(ushort, USHRT_SHLL) (ushort a, Rc(0, USHRT_WIDTH) b)
{
#define     USHRT_SHLL(A, B) ((ushort) shllwz(A,B))
    return  shllwz(a, b);
}

INLINE( short,  SHRT_SHLL)  (short a, Rc(0,  SHRT_WIDTH) b)
{
#define     SHRT_SHLL(A, B) ((short) ((SHRT_MIN&A)|(SHRT_MAX&shllwz(A,B))))
    unsigned q = SHRT_MIN&a;
    unsigned p = SHRT_MAX&shllwz(a, b);
    return  p|q;
}


INLINE(  uint,  UINT_SHLL)   (uint a, Rc(0,  UINT_WIDTH) b)
{
#define     UINT_SHLL shllwz
    return  shllwz(a, b);
}

INLINE(   int,   INT_SHLL)    (int a, Rc(0,   INT_WIDTH) b)
{
#define     INT_SHLL(A, B) ((int) ((INT_MIN&A)|(INT_MAX&shllwz(A,B))))
    unsigned q = INT_MIN&a;
    unsigned p = INT_MAX&shllwz(a, b);
    return  p|q;
}


INLINE( ulong, ULONG_SHLL)  (ulong a, Rc(0, ULONG_WIDTH) b) 
{
#define  ULONG_SHLL(A, B) (((ulong) A)<<B)
    return  a<<b;
}

INLINE(  long,  LONG_SHLL)   (long a, Rc(0,  LONG_WIDTH) b) 
{
#define     LONG_SHLL(A, B) \
((long) ((LONG_MIN&A)|(LONG_MAX&ULONG_SHLL(A,B))))

    ulong q = LONG_MIN&a;
    ulong p = LONG_MAX&ULONG_SHLL(a, b);
    return  p|q;
}


INLINE(ullong,ULLONG_SHLL) (ullong a, Rc(0,ULLONG_WIDTH) b) 
{
#define  ULLONG_SHLL(A, B) (((ullong) A)<<B)
    return  a<<b;
}

INLINE( llong, LLONG_SHLL)  (llong a, Rc(0, LLONG_WIDTH) b)
{
#define     LLONG_SHLL(A, B) \
((llong) ((LLONG_MIN&A)|(LLONG_MAX&ULLONG_SHLL(A,B))))

    ullong q = LLONG_MIN&a;
    ullong p = LLONG_MAX&ULLONG_SHLL(a, b);
    return  p|q;
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,shllqu) (QUAD_UTYPE a, Rc(0, 128) b)
{
    QUAD_TYPE   c = {.U=a};
    QUAD_TYPE   z;
    if (b > 64)
    {
        z.Lo.U = 0;
        z.Hi.U = (c.Lo.U<<(b-64));
    }
    else 
    {
        z.Lo.U = (c.Lo.U<<b);
        z.Hi.U = (c.Lo.U>>(64-b));
        z.Hi.U = (c.Hi.U<<b)|z.Hi.U;
    }
    return  z.U;
}

INLINE(QUAD_ITYPE,shllqi) (QUAD_ITYPE a, Rc(0, 128) b)
{
    QUAD_TYPE z = {.I=a};
    uint64_t  r = z.Hi.U&INT64_MIN;
    z.U = shllqu(z.U, b);
    z.Hi.U &= INT64_MAX;
    z.Hi.U |= r;
    return  z.I;
}

#endif

#if 0 // _LEAVE_ALL_SHLL
}
#endif


#if 0 // _ENTER_ALL_UNOL
{
#endif


INLINE(void *, ADDR_UNOL) (Rc(0, ADDR_WIDTH) n)
{
    return (void *) (UINTPTR_MAX>>(ADDR_WIDTH-n));
}

INLINE( _Bool,  BOOL_UNOL) (Rc(0, 1) n)
{
    return n;
}


INLINE( uchar, UCHAR_UNOL) (Rc(0,  UCHAR_WIDTH) n)
{
#define     UCHAR_UNOL(N)   ((uchar)(UCHAR_MAX>>(UCHAR_WIDTH-N)))
    return  UCHAR_UNOL(n);
}

INLINE( schar, SCHAR_UNOL) (Rc(0,  SCHAR_WIDTH) n)
{
#define     SCHAR_UNOL(N)   ((schar)(UCHAR_MAX>>(SCHAR_WIDTH-N)))
    return  SCHAR_UNOL(n);
}

INLINE(  char,  CHAR_UNOL) (Rc(0,   CHAR_WIDTH) n)
{
#define     CHAR_UNOL(N)    ((char)(UCHAR_MAX>>(CHAR_WIDTH-N)))
    return  CHAR_UNOL(n);
}


INLINE(ushort, USHRT_UNOL) (Rc(0,  USHRT_WIDTH) n)
{
#define     USHRT_UNOL(N) ((ushort)(USHRT_MAX>>(USHRT_WIDTH-N)))
    return  USHRT_UNOL(n);
}

INLINE( short,  SHRT_UNOL) (Rc(0,   SHRT_WIDTH) n)
{
#define     SHRT_UNOL(N) ((short)(USHRT_MAX>>(SHRT_WIDTH-N)))
    return  SHRT_UNOL(n);
}


INLINE(  uint,  UINT_UNOL) (Rc(0,   UINT_WIDTH) n)
{
#define     UINT_UNOL(N) ((uint)(UINT_MAX>>(UINT_WIDTH-N)))
    return  UINT_UNOL(n);
}

INLINE(   int,   INT_UNOL) (Rc(0,    INT_WIDTH) n)
{
#define     INT_UNOL(N) ((int)(UINT_MAX>>(INT_WIDTH-N)))
    return  INT_UNOL(n);
}


INLINE( ulong, ULONG_UNOL) (Rc(0,  ULONG_WIDTH) n)
{
#define     ULONG_UNOL(N)   (ULONG_MAX>>(ULONG_WIDTH-N))
    return  ULONG_UNOL(n);
}

INLINE(  long,  LONG_UNOL) (Rc(0,   LONG_WIDTH) n)
{
#define     LONG_UNOL(N)    ((long) (ULONG_MAX>>(LONG_WIDTH-N)))
    return  LONG_UNOL(n);
}


INLINE(ullong,ULLONG_UNOL) (Rc(0, ULLONG_WIDTH) n)
{
#define     ULLONG_UNOL(N) ((ullong)(ULLONG_MAX>>(LLONG_WIDTH-N)))
    return  ULLONG_UNOL(n);
}

INLINE( llong, LLONG_UNOL) (Rc(0,  LLONG_WIDTH) n)
{
#define     LLONG_UNOL(N)   ((llong)(ULLONG_MAX>>(LLONG_WIDTH-N)))
    return  LLONG_UNOL(n);
}

#if 0 // _LEAVE_ALL_UNOL
}
#endif

#if 0 // _ENTER_ALL_UNOR
{
#endif


INLINE( _Bool,  BOOL_UNOR) (Rc(0, 1) n)
{
#define     BOOL_UNOR(N) ((_Bool) (N==1))
    return  n==1;
}


INLINE( uchar, UCHAR_UNOR) (Rc(0,  UCHAR_WIDTH) n)
{
#define     UCHAR_UNOR(N)   ((uchar)(UCHAR_MAX<<(UCHAR_WIDTH-N)))
    return  UCHAR_UNOR(n);
}

INLINE( schar, SCHAR_UNOR) (Rc(0,  SCHAR_WIDTH) n)
{
#define     SCHAR_UNOR(N)   ((schar)(UCHAR_MAX<<(SCHAR_WIDTH-N)))
    return  SCHAR_UNOR(n);
}

INLINE(  char,  CHAR_UNOR) (Rc(0,   CHAR_WIDTH) n)
{
#define     CHAR_UNOR(N)    ((char)(UCHAR_MAX<<(CHAR_WIDTH-N)))
    return  CHAR_UNOR(n);
}


INLINE(ushort, USHRT_UNOR) (Rc(0,  USHRT_WIDTH) n)
{
#define     USHRT_UNOR(N) ((ushort)(USHRT_MAX<<(USHRT_WIDTH-N)))
    return  USHRT_UNOR(n);
}

INLINE( short,  SHRT_UNOR) (Rc(0,   SHRT_WIDTH) n)
{
#define     SHRT_UNOR(N) ((short)(USHRT_MAX<<(SHRT_WIDTH-N)))
    return  SHRT_UNOR(n);
}


INLINE(  uint,  UINT_UNOR) (Rc(0,   UINT_WIDTH) n)
{
#define     UINT_UNOR(N) ((uint)(UINT_MAX<<(UINT_WIDTH-N)))
    return  UINT_UNOR(n);
}

INLINE(   int,   INT_UNOR) (Rc(0,    INT_WIDTH) n)
{
#define     INT_UNOR(N) ((int)(UINT_MAX<<(INT_WIDTH-N)))
    return  INT_UNOR(n);
}


INLINE( ulong, ULONG_UNOR) (Rc(0,  ULONG_WIDTH) n)
{
#define     ULONG_UNOR(N)   ((ulong)(ULONG_MAX<<(ULONG_WIDTH-N)))
    return  ULONG_UNOR(n);
}

INLINE(  long,  LONG_UNOR) (Rc(0,   LONG_WIDTH) n)
{
#define     LONG_UNOR(N)    ((long)(ULONG_MAX<<(LONG_WIDTH-N)))
    return  LONG_UNOR(n);
}


INLINE(ullong,ULLONG_UNOR) (Rc(0, ULLONG_WIDTH) n)
{
#define     ULLONG_UNOR(N) ((ullong)(ULLONG_MAX<<(ULLONG_WIDTH-N)))
    return  ULLONG_UNOR(n);
}

INLINE( llong, LLONG_UNOR) (Rc(0,  LLONG_WIDTH) n)
{
#define     LLONG_UNOR(N)   ((llong)(ULLONG_MAX<<(LLONG_WIDTH-N)))
    return  LLONG_UNOR(n);
}

#if 0 // _LEAVE_ALL_UNOR
}
#endif

#if 0 // _ENTER_ALL_ABSU
{
#endif

INLINE(uchar, SCHAR_ABSU)   (signed x)
{
    unsigned a = x;
    unsigned b = a>>(SCHAR_WIDTH-1);
    return  (a+b)^b;
}

INLINE(uchar, CHAR_ABSU)   (int x)
{
#if CHAR_MIN
    return  SCHAR_ABSU(x);
#else
    return  x;
#endif
}

INLINE(ushort,SHRT_ABSU)  (signed x)
{
    unsigned a = x;
    unsigned b = a>>(SHRT_WIDTH-1);
    return  (a+b)^b;
}

INLINE(  uint, INT_ABSU)    (int x)
{
    uint a = x;
    uint b = a>>(INT_WIDTH-1);
    return  (a+b)^b;
}

INLINE( ulong, LONG_ABSU)  (long x)
{
    ulong a = x;
    ulong b = a>>(LONG_WIDTH-1);
    return  (a+b)^b;
}

INLINE(ullong,LLONG_ABSU) (llong x)
{
    ullong a = x;
    ullong b = a>>(LLONG_WIDTH-1);
    return  (a+b)^b;
}

#if 0 // _LEAVE_ALL_ABSU
}
#endif

#if 0 // _ENTER_ALL_ABSL
{
#endif

INLINE(schar,SCHAR_ABSL) (signed x) {return (x<0) ? (0U  -x) : x;}
INLINE( char, CHAR_ABSL)    (int x) {return (x<0) ? (0U  -x) : x;}
INLINE(short, SHRT_ABSL) (signed x) {return (x<0) ? (0U  -x) : x;}
INLINE(  int,  INT_ABSL)    (int x) {return (x<0) ? (0U  -x) : x;}
INLINE( long, LONG_ABSL)   (long x) {return (x<0) ? (0UL -x) : x;}
INLINE(llong,LLONG_ABSL)  (llong x) {return (x<0) ? (0ULL-x) : x;}

#if 0 // _LEAVE_ALL_ABSL
}
#endif

#if 0 // _ENTER_ALL_NEGL
{
#endif

INLINE( uchar, UCHAR_NEGL) (unsigned x) {return -x;}
INLINE( schar, SCHAR_NEGL)   (signed x) {return -x;}
INLINE(  char,  CHAR_NEGL)      (int x) {return -x;}
INLINE(ushort, USHRT_NEGL) (unsigned x) {return -x;}
INLINE( short,  SHRT_NEGL)   (signed x) {return -x;}
INLINE(  uint,  UINT_NEGL)     (uint x) {return -x;}
INLINE(   int,   INT_NEGL)      (int x) {return -x;}
INLINE( ulong, ULONG_NEGL)    (ulong x) {return -x;}
INLINE(  long,  LONG_NEGL)     (long x) {return -x;}
INLINE(ullong,ULLONG_NEGL)   (ullong x) {return -x;}
INLINE( llong, LLONG_NEGL)    (llong x) {return -x;}

#if 0 // _LEAVE_ALL_NEGL
}
#endif

#if 0 // _ENTER_ALL_SHL2
{
#endif

INLINE(uint16_t, UCHAR_SHL2)  (unsigned a, Rc(0, UCHAR_WIDTH) b)
{
#define     UCHAR_SHL2(A, B) ((uint16_t) ((0xffULL&A)<<B))
    return  (0xffU&a)<<b;
}

INLINE( int16_t, SCHAR_SHL2)  (signed a, Rc(0,  SCHAR_WIDTH) b)
{
    unsigned q = INT16_MIN&a;
    unsigned p = a;
    return  q|(p<<b);
}

#if CHAR_MIN

INLINE( int16_t,  CHAR_SHL2)   (int a, Rc(0,   CHAR_WIDTH) b)
{
    return  SCHAR_SHL2(a, b);
}

#else

INLINE(uint16_t,  CHAR_SHL2)   (int a, Rc(0,   CHAR_WIDTH) b)
{
#   define  CHAR_SHL2(A, B) ((uint16_t) ((0xffULL&A)<<B))
    return  (0xffU&a)<<b;
}

#endif

INLINE(uint32_t, USHRT_SHL2) (unsigned a, Rc(0,  USHRT_WIDTH) b)
{
#define     USHRT_SHL2(A, B) ((uint32_t) ((0xffffULL&A)<<B))
    return  (0xffff&a)<<b;
}

INLINE( int32_t,  SHRT_SHL2)  (signed a, Rc(0,   SHRT_WIDTH) b)
{
    unsigned q = INT32_MIN&a;
    unsigned p = a;
    return  q|(p<<b);
}


INLINE(uint64_t,  UINT_SHL2)   (uint a, Rc(0,   UINT_WIDTH) b)
{
#define     UINT_SHL2(A, B) ((uint64_t) ((0xffffffffULL&A)<<B))
    return  (uint64_t) a<<b;
}

INLINE( int64_t,   INT_SHL2)    (int a, Rc(0,    INT_WIDTH) b)
{
    uint64_t q = INT64_MIN&a;
    uint64_t p = a;
    return  q|(p<<b);
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_SHL2)   (ulong a, Rc(0, ULONG_WIDTH) b)
{
#define     ULONG_SHL2 UINT_SHL2
    return  (UINT_SHL2)(a, b);
}

INLINE( int64_t,  LONG_SHL2)    (long a, Rc(0,  LONG_WIDTH) b)
{
    return (INT_SHL2)(a, b);
}

#endif

#if 0 // _LEAVE_ALL_SHL2
}
#endif

#if 0 // _ENTER_ALL_SHLR
{
#endif

INLINE( _Bool,  BOOL_SHLR)    (_Bool a, Rc(0,  1) b)
{
#define     BOOL_SHLR(A, B) ((_Bool) ((A==1) && (B==1)))
    return  a && b;
}


INLINE( uchar, UCHAR_SHLR) (unsigned a, Rc(0,  UCHAR_WIDTH) b)
{
#define     UCHAR_SHLR(A, B) ((uchar) (((unsigned) A)>>(UCHAR_WIDTH-B)))
    return  a>>(UCHAR_WIDTH-b);
}

INLINE( schar, SCHAR_SHLR)   (signed a, Rc(0,  SCHAR_WIDTH) b)
{
#define     SCHAR_SHLR(A, B) ((schar) (((unsigned) A)>>(SCHAR_WIDTH-B)))
    return  (unsigned) a>>(SCHAR_WIDTH-b);
}

INLINE(  char,  CHAR_SHLR)      (int a, Rc(0,   CHAR_WIDTH) b)
{
#define     CHAR_SHLR(A, B) ((char) (((unsigned) A)>>(CHAR_WIDTH-B)))
    return  (unsigned) a>>(CHAR_WIDTH-b);
}


INLINE(ushort, USHRT_SHLR) (unsigned a, Rc(0,  USHRT_WIDTH) b)
{
#define     USHRT_SHLR(A, B) ((ushort) (((unsigned) A)>>(USHRT_WIDTH-B)))
    return  a>>(USHRT_WIDTH-b);
}

INLINE( short,  SHRT_SHLR)   (signed a, Rc(0,   SHRT_WIDTH) b)
{
#define     SHRT_SHLR(A, B) ((short) (((unsigned) A)>>(SHRT_WIDTH-B)))
    return  (unsigned) a>>(SHRT_WIDTH-b);
}


INLINE(  uint,  UINT_SHLR)     (uint a, Rc(0,   UINT_WIDTH) b)
{
#define     UINT_SHLR(A, B) ((uint) A>>(UINT_WIDTH-B))
    return  a>>(UINT_WIDTH-b);
}

INLINE(   int,   INT_SHLR)      (int a, Rc(0,    INT_WIDTH) b)
{
#define     INT_SHLR(A, B) ((int) (((uint64_t) A)>>(INT_WIDTH-B)))
    return  (uint64_t) a>>(INT_WIDTH-b);
}


INLINE( ulong, ULONG_SHLR)    (ulong a, Rc(0,  ULONG_WIDTH) b)
{
#define     ULONG_SHLR(A, B) ((ulong) A>>(ULONG_WIDTH-B))
    return  a>>(ULONG_WIDTH-b);
}

INLINE(  long,  LONG_SHLR)     (long a, Rc(0,   LONG_WIDTH) b)
{
#if DWRD_NLONG == 2
#   define  LONG_SHLR(A, B) ((long) (((uint64_t) A)>>(LONG_WIDTH-B)))
    return  (uint64_t) a>>(64-b);
#else
    uint32_t c = 64-b;
    uint64_t z = a;
    uint64_t s = (0-(z>>63))<<c;
    return s|(z>>c);
#endif
}


INLINE(ullong,ULLONG_SHLR)   (ullong a, Rc(0, ULLONG_WIDTH) b)
{
#define     ULLONG_SHLR(A, B) ((ullong) A>>(ULLONG_WIDTH-B))
    return  a>>(ULLONG_WIDTH-b);
}

INLINE( llong, LLONG_SHLR)    (llong a, Rc(0,  LLONG_WIDTH) b)
{
    unsigned c = LLONG_WIDTH-b;
    ullong   z = a;
    ullong   s = (0-(z>>(LLONG_WIDTH-1)))<<c;
    return  s|(z>>c);
}

#if 0 // _LEAVE_ALL_SHLR
}
#endif

#if 0 // _ENTER_ALL_SILL
{
#endif
INLINE( _Bool,  BOOL_SILL)   
(
    unsigned a,  
    unsigned b, 
    Rc(0, 1) c
)
{
#define     BOOL_SILL(A, B, C)  ((_Bool)((C==1)?B:A))
    return  (c==1) ? b : a;
}

INLINE( uchar, UCHAR_SILL)  
(
    unsigned            a,  
    unsigned            b, 
    Rc(0, UCHAR_WIDTH)  c
)
{
#define     UCHAR_SILL(A, B, C) \
(\
    (uchar)\
    (((unsigned) A<<C)|(B&(UCHAR_MAX>>(UCHAR_WIDTH-C))))\
)

    return      (a<<c)|(b&(UCHAR_MAX>>(UCHAR_WIDTH-c)));
}

INLINE(  char,  CHAR_SILL)   
(
    int                 a,   
    int                 b,
    Rc(0,   CHAR_WIDTH) c
)
{
#define     CHAR_SILL(A, B, C) \
(\
    (char)\
    (((unsigned) A<<C)|(B&(UCHAR_MAX>>(CHAR_WIDTH-C))))\
)

    return      (a<<c)|(b&(UCHAR_MAX>>(CHAR_WIDTH-c)));
}

INLINE(ushort, USHRT_SILL)
(
    unsigned            a,  
    unsigned            b, 
    Rc(0, USHRT_WIDTH)  c
)
{
#define     USHRT_SILL(A, B, C) \
(\
    (ushort)\
    (((unsigned) A<<C)|(B&(USHRT_MAX>>(USHRT_WIDTH-C))))\
)

    return      (a<<c)|(b&(USHRT_MAX>>(USHRT_WIDTH-c)));
}

INLINE(  uint,  UINT_SILL) 
(
    uint                a,  
    uint                b, 
    Rc(0, UINT_WIDTH)   c
)
{
#define     UINT_SILL(A, B, C) \
((    (uint) A<<C)|(B&(UINT_MAX>>(UINT_WIDTH-C))))

    return  (a<<c)|(b&(UINT_MAX>>(UINT_WIDTH-c)));
}

INLINE( ulong, ULONG_SILL)  
(
    ulong               a,  
    ulong               b, 
    Rc(0, ULONG_WIDTH)  c
)
{
#define     ULONG_SILL(A, B, C) \
((   (ulong) A<<C)|(B&(ULONG_MAX>>(ULONG_WIDTH-C))))

    return  (a<<c)|(b&(ULONG_MAX>>(ULONG_WIDTH-c)));
}

INLINE(ullong,ULLONG_SILL)
(
    ullong              a,  
    ullong              b, 
    Rc(0, ULLONG_WIDTH) c
)
{
#define     ULLONG_SILL(A, B, C) \
((  (ullong) A<<C)|(B&(ULLONG_MAX>>(ULLONG_WIDTH-C))))

    return  (a<<c)|(b&(ULLONG_MAX>>(ULLONG_WIDTH-c)));
}


#if 0 // _LEAVE_ALL_SILL
}
#endif

#if 0 // _ENTER_ALL_SILR
{
#endif

INLINE( _Bool,  BOOL_SILR)  
(
    _Bool       a,
    _Bool       b, 
    Rc(0,  1)   c
)
{
#define     BOOL_SILR(A, B, C)  ((_Bool) ((C==1)?B:A))
    return  c ? b : a;
}

INLINE( uchar, UCHAR_SILR)  
(
    unsigned            a,  
    unsigned            b, 
    Rc(0,  UCHAR_WIDTH) c
)
{
#define     UCHAR_SILR(A, B, C)    \
((uchar)(((unsigned) A<<C)|((unsigned) B>>(UCHAR_WIDTH-C))))

    return  UCHAR_SILR(a, b, c);
}

INLINE(  char,  CHAR_SILR)   
(
    int                 a,  
    int                 b, 
    Rc(0, CHAR_WIDTH)   c
)
{
#define     CHAR_SILR(A, B, C)    \
((char)(((unsigned) A<<C)|((unsigned) B>>(CHAR_WIDTH-C))))

    return  CHAR_SILR(a, b, c);
}

INLINE(ushort, USHRT_SILR)
(
    unsigned            a,  
    unsigned            b, 
    Rc(0, USHRT_WIDTH)  c
)
{
#define     USHRT_SILR(A, B, C)    \
((ushort)(((unsigned) A<<C)|((unsigned) B>>(USHRT_WIDTH-C))))

    return  USHRT_SILR(a, b, c);
}

INLINE(  uint,  UINT_SILR)   
(
    uint                a,  
    uint                b, 
    Rc(0, UINT_WIDTH)   c
)
{
#define     UINT_SILR(A, B, C)    \
(((unsigned) A<<C)|((unsigned) B>>(UINT_WIDTH-C)))

    return  UINT_SILR(a, b, c);
}

INLINE( ulong, ULONG_SILR)  
(
    ulong               a,  
    ulong               b, 
    Rc(0, ULONG_WIDTH)  c
)
{
#define     ULONG_SILR(A, B, C)    \
(((ulong) A<<C)|((ulong) B>>(ULONG_WIDTH-C)))

    return  ULONG_SILR(a, b, c);
}

INLINE(ullong,ULLONG_SILR) 
(
    ullong              a,  
    ullong              b, 
    Rc(0, ULLONG_WIDTH) c
)
{
#define     ULLONG_SILR(A, B, C)    \
(((ullong) A<<C)|((ullong) B>>(ULLONG_WIDTH-C)))

    return  ULLONG_SILR(a, b, c);
}

#if 0 // _LEAVE_ALL_SILR
}
#endif

#if 0 // _ENTER_ALL_SILR
{
#endif

INLINE( _Bool,  BOOL_SIRL)   (_Bool a,  _Bool b, Rc(0,  1) c)
{
#define     BOOL_SIRL(A, B, C)  ((_Bool)(C ? B : A))
    return  c ? b : a;
}


INLINE( uchar, UCHAR_SIRL)  
(
    unsigned            a,  
    unsigned            b,
    Rc(0, UCHAR_WIDTH)  c
)
{
#define     UCHAR_SIRL(A, B, C)  \
((uchar) (((unsigned) A>>C)|((unsigned) B<<(UCHAR_WIDTH-C))))

    return  (a>>c)|(b<<(UCHAR_WIDTH-c));
}

INLINE(  char,  CHAR_SIRL)  
(
    int                 a,  
    int                 b,
    Rc(0, CHAR_WIDTH)   c
)
{
#define     CHAR_SIRL(A, B, C)  \
((char) (((unsigned) A>>C)|((unsigned) B<<(CHAR_WIDTH-C))))

    return  CHAR_SIRL(a, b, c);
}


INLINE(ushort, USHRT_SIRL)
(
    unsigned            a,  
    unsigned            b,
    Rc(0, USHRT_WIDTH)  c
)
{
#define     USHRT_SIRL(A, B, C)  \
((ushort) (((unsigned) A>>C)|((unsigned) B<<(USHRT_WIDTH-C))))

    return  (a>>c)|(b<<(USHRT_WIDTH-c));
}


INLINE(  uint,  UINT_SIRL)   
(
    uint                a,  
    uint                b,
    Rc(0, UINT_WIDTH)   c
)
{
#define     UINT_SIRL(A, B, C)  \
(((uint) A>>C)|((uint) B<<(UINT_WIDTH-C)))

    return  (a>>c)|(b<<(UINT_WIDTH-c));
}


INLINE( ulong, ULONG_SIRL)  
(
    ulong               a,  
    ulong               b,
    Rc(0, ULONG_WIDTH)  c
)
{
#define     ULONG_SIRL(A, B, C)  \
(((ulong) A>>C)|((ulong) B<<(ULONG_WIDTH-C)))

    return  (a>>c)|(b<<(ULONG_WIDTH-c));
}


INLINE(ullong,ULLONG_SIRL) 
(
    ullong              a,  
    ullong              b,
    Rc(0, ULONG_WIDTH)  c
)
{
#define     ULLONG_SIRL(A, B, C)  \
(((ullong) A>>C)|((ullong) B<<(ULLONG_WIDTH-C)))

    return  (a>>c)|(b<<(ULLONG_WIDTH-c));
}

#if 0 // _LEAVE_ALL_SILR
}
#endif

#if 0 // _ENTER_ALL_SIRR
{
#endif

INLINE( _Bool,  BOOL_SIRR)   (_Bool a,  _Bool b, Rc(0,  1) c)
{
#define     BOOL_SIRR(A, B, C)  ((_Bool) ((C==1)?B:A))
    return  (c==1) ? b : a;
}

INLINE( uchar, UCHAR_SIRR)  
(
    unsigned            a,  
    unsigned            b,
    Rc(0, UCHAR_WIDTH)  c
)
{
#define     UCHAR_SIRR(A, B, C)  \
((uchar) (((unsigned) A>>C)|((unsigned) B&(UCHAR_MAX<<(UCHAR_WIDTH-C)))))

    return  UCHAR_SIRR(a, b, c);
}

INLINE(  char,  CHAR_SIRR)  
(
    int                 a,  
    int                 b,
    Rc(0, CHAR_WIDTH)   c
)
{
#define     CHAR_SIRR(A, B, C)  \
((char) (((unsigned) A>>C)|((unsigned) B&(UCHAR_MAX<<(CHAR_WIDTH-C)))))

    return  CHAR_SIRR(a, b, c);
}

INLINE(ushort, USHRT_SIRR)
(
    unsigned            a,  
    unsigned            b,
    Rc(0, USHRT_WIDTH)  c
)
{
#define     USHRT_SIRR(A, B, C)  \
((ushort) (((unsigned) A>>C)|((unsigned) B&(USHRT_MAX<<(USHRT_WIDTH-C)))))

    return  USHRT_SIRR(a, b, c);
}

INLINE(  uint,  UINT_SIRR)   
(
    uint                a,  
    uint                b,
    Rc(0, UINT_WIDTH)   c
)
{
#define     UINT_SIRR(A, B, C)  \
(((uint) A>>C)|((uint) B&(UINT_MAX<<(UINT_WIDTH-C))))

    return  UINT_SIRR(a, b, c);
}

INLINE( ulong, ULONG_SIRR)  
(
    ulong               a,  
    ulong               b,
    Rc(0, ULONG_WIDTH)  c
)
{
#define     ULONG_SIRR(A, B, C)  \
(((ulong) A>>C)|((ulong) B&(ULONG_MAX<<(ULONG_WIDTH-C))))

    return  ULONG_SIRR(a, b, c);
}

INLINE(ullong,ULLONG_SIRR) 
(
    ullong              a,  
    ullong              b,
    Rc(0, ULLONG_WIDTH) c
)
{
#define     ULLONG_SIRR(A, B, C)  \
(((ullong) A>>C)|((ullong) B&(ULLONG_MAX<<(ULLONG_WIDTH-C))))

    return  ULLONG_SIRR(a, b, c);
}

#if 0 // _LEAVE_ALL_SIRR
}
#endif

#if 0 // _ENTER_ALL_ADDL
{
#endif

INLINE( _Bool,  BOOL_ADDL)    (_Bool a,    _Bool b) {return a^b;}
INLINE( uchar, UCHAR_ADDL) (unsigned a, unsigned b) 
{
    return (uchar) a+(uchar) b;
}

INLINE( schar, SCHAR_ADDL)   (signed a,   signed b) {return UCHAR_ADDL(a,b);}
INLINE(  char,  CHAR_ADDL)      (int a,      int b) {return UCHAR_ADDL(a,b);}
INLINE(ushort, USHRT_ADDL) (unsigned a, unsigned b) 
{
    return (ushort) a+(ushort) b;
}
INLINE( short,  SHRT_ADDL)   (signed a,   signed b) {return USHRT_ADDL(a,b);}

INLINE(  uint,  UINT_ADDL)     (uint a,     uint b) {return a+b;}
INLINE(   int,   INT_ADDL)      (int a,      int b) {return UINT_ADDL(a,b);}
INLINE( ulong, ULONG_ADDL)    (ulong a,    ulong b) {return a+b;}
INLINE(  long,  LONG_ADDL)     (long a,     long b) {return ULONG_ADDL(a,b);}
INLINE(ullong,ULLONG_ADDL)   (ullong a,   ullong b) {return a+b;}
INLINE( llong, LLONG_ADDL)    (llong a,    llong b) {return ULLONG_ADDL(a,b);}

#if 0 // _LEAVE_ALL_ADDL
}
#endif

#if 0 // _ENTER_ALL_ADD2
{
#endif

INLINE(uint16_t, UCHAR_ADD2) (unsigned a, unsigned b) 
{
#define     UCHAR_ADD2(A, B) ((uint16_t) ((UCHAR_MAX&A)+(UCHAR_MAX&B)))
    return  UCHAR_ADD2(a, b);
}

INLINE( int16_t, SCHAR_ADD2)   (signed a,   signed b) 
{
#define     SCHAR_ADD2(A, B) ((int16_t) ((unsigned) A+(unsigned) B))
    return  SCHAR_ADD2(a, b);
}

#if CHAR_MIN

INLINE( int16_t,  CHAR_ADD2)      (int a,      int b) 
{
#define     CHAR_ADD2(A, B) ((int16_t) ((unsigned) A+(unsigned) B))
    return  CHAR_ADD2(a, b);
}

#else

INLINE(uint16_t,  CHAR_ADD2)      (int a,      int b) 
{
#define     CHAR_ADD2(A, B) ((uint16_t) ((UCHAR_MAX&A)+(UCHAR_MAX&B)))
    return  CHAR_ADD2(a, b);
}

#endif

INLINE(uint32_t, USHRT_ADD2) (unsigned a, unsigned b) 
{
#define     USHRT_ADD2(A, B) ((uint32_t) ((USHRT_MAX&A)+(USHRT_MAX&B)))
    return  USHRT_ADD2(a, b);
}

INLINE( int32_t,  SHRT_ADD2)  (signed a,  signed b) 
{
#define     SHRT_ADD2(A, B) ((int32_t) ((unsigned) A+(unsigned) B))
    return  SHRT_ADD2(a, b);
}

INLINE(uint64_t,  UINT_ADD2)   (uint a,   uint b) 
{
#define     UINT_ADD2(A, B) ((uint64_t) ((UINT_MAX&A)+(UINT_MAX&B)))
    return  UINT_ADD2(a, b);
}

INLINE( int64_t,   INT_ADD2)    (int a,    int b) 
{
#define     INT_ADD2(A, B) ((int64_t) ((uint64_t) A+(uint64_t) B))
    return  INT_ADD2(a, b);
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_ADD2)  (ulong a, ulong b) 
{
#define     ULONG_ADD2(A, B) ((uint64_t) ((ULONG_MAX&A)+(ULONG_MAX&B)))
    return  ULONG_ADD2(a, b);
}

INLINE( int64_t,  LONG_ADD2)   (long a,  long b) 
{
#define     LONG_ADD2(A, B) ((int64_t) ((uint64_t) A+(uint64_t) B))
    return  LONG_ADD2(a, b);
}

#endif

#if 0 // _LEAVE_ALL_ADD2
}
#endif

#if 0 // _ENTER_ALL_ICRL
{
#endif

INLINE(void *,  ADDR_ICRL) (void const *a) {return (void *)(1+a);}
INLINE( _Bool,  BOOL_ICRL)       (_Bool a) {return a+1;}
INLINE( uchar, UCHAR_ICRL)    (unsigned a) {return a+1;}
INLINE( schar, SCHAR_ICRL)      (signed a) {return (schar) a+1;}
INLINE(  char,  CHAR_ICRL)         (int a) {return (char) a+1;}
INLINE(ushort, USHRT_ICRL)    (unsigned a) {return a+1;}
INLINE( short,  SHRT_ICRL)      (signed a) {return (short) a+1;}
INLINE(  uint,  UINT_ICRL)        (uint a) {return a+1u;}
INLINE(   int,   INT_ICRL)         (int a) {return a+1u;}
INLINE( ulong, ULONG_ICRL)       (ulong a) {return a+1ul;}
INLINE(  long,  LONG_ICRL)        (long a) {return a+1ul;}
INLINE(ullong,ULLONG_ICRL)      (ullong a) {return a+1ull;}
INLINE( llong, LLONG_ICRL)       (llong a) {return a+1ull;}

INLINE(void *,  ADDR_ICRLAC) (void const *const *a)    
{
    return (void *)(1+a);
}

INLINE(void *,  BOOL_ICRLAC)   (_Bool const *a) {return (void *)(1+a);}
INLINE(void *, UCHAR_ICRLAC)   (uchar const *a) {return (void *)(1+a);}
INLINE(void *, SCHAR_ICRLAC)   (schar const *a) {return (void *)(1+a);}
INLINE(void *,  CHAR_ICRLAC)    (char const *a) {return (void *)(1+a);}
INLINE(void *, USHRT_ICRLAC)  (ushort const *a) {return (void *)(1+a);}
INLINE(void *,  SHRT_ICRLAC)   (short const *a) {return (void *)(1+a);}
INLINE(void *,  UINT_ICRLAC)    (uint const *a) {return (void *)(1+a);}
INLINE(void *,   INT_ICRLAC)     (int const *a) {return (void *)(1+a);}
INLINE(void *, ULONG_ICRLAC)   (ulong const *a) {return (void *)(1+a);}
INLINE(void *,  LONG_ICRLAC)    (long const *a) {return (void *)(1+a);}
INLINE(void *,ULLONG_ICRLAC)  (ullong const *a) {return (void *)(1+a);}
INLINE(void *, LLONG_ICRLAC)   (llong const *a) {return (void *)(1+a);}
INLINE(void *, FLT16_ICRLAC) (flt16_t const *a) {return (void *)(1+a);}
INLINE(void *,   FLT_ICRLAC)   (float const *a) {return (void *)(1+a);}
INLINE(void *,   DBL_ICRLAC)  (double const *a) {return (void *)(1+a);}

#if 0 // _LEAVE_ALL_ICRL
}
#endif

#if 0 // _ENTER_ALL_DCRL
{
#endif

INLINE(void *,  ADDR_DCRL) (void const *a) {return (void *)(a-1);}
INLINE( _Bool,  BOOL_DCRL)       (_Bool a) {return a-1;}
INLINE( uchar, UCHAR_DCRL)    (unsigned a) {return a-1;}
INLINE( schar, SCHAR_DCRL)      (signed a) {return (schar) a-1;}
INLINE(  char,  CHAR_DCRL)         (int a) {return (char) a-1;}
INLINE(ushort, USHRT_DCRL)    (unsigned a) {return a-1;}
INLINE( short,  SHRT_DCRL)      (signed a) {return (short) a-1;}
INLINE(  uint,  UINT_DCRL)        (uint a) {return a-1u;}
INLINE(   int,   INT_DCRL)         (int a) {return a-1u;}
INLINE( ulong, ULONG_DCRL)       (ulong a) {return a-1ul;}
INLINE(  long,  LONG_DCRL)        (long a) {return a-1ul;}
INLINE(ullong,ULLONG_DCRL)      (ullong a) {return a-1ull;}
INLINE( llong, LLONG_DCRL)       (llong a) {return a-1ull;}

INLINE(void *,  ADDR_DCRLAC) (void const *const *a)    
{
    return (void *)(a-1);
}

INLINE(void *,  BOOL_DCRLAC)   (_Bool const *a) {return (void *)(a-1);}
INLINE(void *, UCHAR_DCRLAC)   (uchar const *a) {return (void *)(a-1);}
INLINE(void *, SCHAR_DCRLAC)   (schar const *a) {return (void *)(a-1);}
INLINE(void *,  CHAR_DCRLAC)    (char const *a) {return (void *)(a-1);}
INLINE(void *, USHRT_DCRLAC)  (ushort const *a) {return (void *)(a-1);}
INLINE(void *,  SHRT_DCRLAC)   (short const *a) {return (void *)(a-1);}
INLINE(void *,  UINT_DCRLAC)    (uint const *a) {return (void *)(a-1);}
INLINE(void *,   INT_DCRLAC)     (int const *a) {return (void *)(a-1);}
INLINE(void *, ULONG_DCRLAC)   (ulong const *a) {return (void *)(a-1);}
INLINE(void *,  LONG_DCRLAC)    (long const *a) {return (void *)(a-1);}
INLINE(void *,ULLONG_DCRLAC)  (ullong const *a) {return (void *)(a-1);}
INLINE(void *, LLONG_DCRLAC)   (llong const *a) {return (void *)(a-1);}
INLINE(void *, FLT16_DCRLAC) (flt16_t const *a) {return (void *)(a-1);}
INLINE(void *,   FLT_DCRLAC)   (float const *a) {return (void *)(a-1);}
INLINE(void *,   DBL_DCRLAC)  (double const *a) {return (void *)(a-1);}

#if 0 // _LEAVE_ALL_DCRL
}
#endif

#if 0 // _ENTER_ALL_AVGL
{
#endif

INLINE( _Bool,  BOOL_AVGL)    (_Bool a,    _Bool b) {return (a+b)/2;}

INLINE( uchar, UCHAR_AVGL) (unsigned a, unsigned b) 
{
    return  ((uchar) a+(uchar) b)>>1;
}

INLINE( schar, SCHAR_AVGL)   (signed a,   signed b) 
{
    return  ((schar) a+(schar) b)/2;
}

INLINE(  char,  CHAR_AVGL)      (int a,      int b) 
{
    return  ((char) a+(char) b)/2;
}

INLINE(ushort, USHRT_AVGL) (unsigned a, unsigned b) 
{
    return  ((ushort) a+(ushort) b)>>1;
}

INLINE( short,  SHRT_AVGL)   (signed a,   signed b) 
{
    return  ((short) a+(short) b)/2;
}


INLINE(  uint,  UINT_AVGL)     (uint a,     uint b) 
{
    return  ((uint64_t) a+b)>>1;
}

INLINE(   int,   INT_AVGL)      (int a,      int b) 
{
    return ((int64_t) a+b)/2;
}


INLINE( ulong, ULONG_AVGL)    (ulong a,    ulong b) 
{
#if DWRD_NLONG == 2
    return ((uint64_t) a+b)>>1;
#else
    return ((a>>1)+(b>>1))+(a&b&1);
#endif
}

INLINE(  long,  LONG_AVGL)     (long a,     long b) 
{
#if DWRD_NLONG == 2
    return ((int64_t) a+b)/2;
#else
    return ((a/2)+(b/2))+(a&b&1);
#endif

}

INLINE(ullong,ULLONG_AVGL)   (ullong a,   ullong b) 
{
    return ((a>>1)+(b>>1))+(a&b&1);
}

INLINE( llong, LLONG_AVGL)    (llong a,    llong b) 
{
    return ((a/2)+(b/2))+(a&b&1);
}


#if 0 // _LEAVE_ALL_AVGL
}
#endif

#if 0 // _ENTER_ALL_SUBL
{
#endif

INLINE( _Bool,  BOOL_SUBL)    (_Bool a,    _Bool b) {return a^b;}
INLINE( uchar, UCHAR_SUBL) (unsigned a, unsigned b) 
{
    return (uchar) a-(uchar) b;
}

INLINE( schar, SCHAR_SUBL)   (signed a,   signed b) {return UCHAR_SUBL(a,b);}
INLINE(  char,  CHAR_SUBL)      (int a,      int b) {return UCHAR_SUBL(a,b);}
INLINE(ushort, USHRT_SUBL) (unsigned a, unsigned b) 
{
    return (ushort) a-(ushort) b;
}
INLINE( short,  SHRT_SUBL)   (signed a,   signed b) {return USHRT_SUBL(a,b);}

INLINE(  uint,  UINT_SUBL)     (uint a,     uint b) {return a-b;}
INLINE(   int,   INT_SUBL)      (int a,      int b) {return UINT_SUBL(a,b);}
INLINE( ulong, ULONG_SUBL)    (ulong a,    ulong b) {return a-b;}
INLINE(  long,  LONG_SUBL)     (long a,     long b) {return ULONG_SUBL(a,b);}
INLINE(ullong,ULLONG_SUBL)   (ullong a,   ullong b) {return a-b;}
INLINE( llong, LLONG_SUBL)    (llong a,    llong b) {return ULLONG_SUBL(a,b);}

#if 0 // _LEAVE_ALL_SUBL
}
#endif

#if 0 // _ENTER_ALL_SUB2
{
#endif

INLINE(uint16_t, UCHAR_SUB2) (unsigned a, unsigned b) 
{
#define     UCHAR_SUB2(A, B) ((uint16_t) ((UCHAR_MAX&A)-(UCHAR_MAX&B)))
    return  UCHAR_SUB2(a, b);
}

INLINE( int16_t, SCHAR_SUB2)   (signed a,   signed b) 
{
#define     SCHAR_SUB2(A, B) ((int16_t) ((unsigned) A-(unsigned) B))
    return  SCHAR_SUB2(a, b);
}

#if CHAR_MIN

INLINE( int16_t,  CHAR_SUB2)      (int a,      int b) 
{
#define     CHAR_SUB2(A, B) ((int16_t) ((unsigned) A-(unsigned) B))
    return  CHAR_SUB2(a, b);
}

#else

INLINE(uint16_t,  CHAR_SUB2)      (int a,      int b) 
{
#define     CHAR_SUB2(A, B) ((uint16_t) ((UCHAR_MAX&A)-(UCHAR_MAX&B)))
    return  CHAR_SUB2(a, b);
}

#endif

INLINE(uint32_t, USHRT_SUB2) (unsigned a, unsigned b) 
{
#define     USHRT_SUB2(A, B) ((uint32_t) ((USHRT_MAX&A)-(USHRT_MAX&B)))
    return  USHRT_SUB2(a, b);
}

INLINE( int32_t,  SHRT_SUB2)  (signed a,  signed b) 
{
#define     SHRT_SUB2(A, B) ((int32_t) ((unsigned) A-(unsigned) B))
    return  SHRT_SUB2(a, b);
}

INLINE(uint64_t,  UINT_SUB2)   (uint a,   uint b) 
{
#define     UINT_SUB2(A, B) ((uint64_t) ((UINT_MAX&A)-(UINT_MAX&B)))
    return  UINT_SUB2(a, b);
}

INLINE( int64_t,   INT_SUB2)    (int a,    int b) 
{
#define     INT_SUB2(A, B) ((int64_t) ((uint64_t) A-(uint64_t) B))
    return  INT_SUB2(a, b);
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_SUB2)  (ulong a, ulong b) 
{
#define     ULONG_SUB2(A, B) ((uint64_t) ((ULONG_MAX&A)-(ULONG_MAX&B)))
    return  ULONG_SUB2(a, b);
}

INLINE( int64_t,  LONG_SUB2)   (long a,  long b) 
{
#define     LONG_SUB2(A, B) ((int64_t) ((uint64_t) A-(uint64_t) B))
    return  LONG_SUB2(a, b);
}

#endif

#if 0 // _LEAVE_ALL_SUB2
}
#endif

#if 0 // _ENTER_ALL_DIFU
{
#endif

INLINE(ptrdiff_t,ADDR_DIFU) 
(
    void const *a,
    void const *b
)
{
    return  a<b ? b-a : a-b;
}

INLINE( _Bool,  BOOL_DIFU)    (_Bool a,    _Bool b) {return (a&b)?  0 : a|b;}
INLINE( uchar, UCHAR_DIFU) (unsigned a, unsigned b) {return a<b ? b-a : a-b;}
INLINE( schar, SCHAR_DIFU)   (signed a,   signed b) {return a<b ? b-a : a-b;}
INLINE(  char,  CHAR_DIFU)      (int a,      int b) {return a<b ? b-a : a-b;}
INLINE(ushort, USHRT_DIFU) (unsigned a, unsigned b) {return a<b ? b-a : a-b;}
INLINE( short,  SHRT_DIFU)   (signed a,   signed b) {return a<b ? b-a : a-b;}
INLINE(  uint,  UINT_DIFU)     (uint a,     uint b) {return a<b ? b-a : a-b;}
INLINE(   int,   INT_DIFU)      (int a,      int b) {return a<b ? b-a : a-b;}
INLINE( ulong, ULONG_DIFU)    (ulong a,    ulong b) {return a<b ? b-a : a-b;}
INLINE(  long,  LONG_DIFU)     (long a,     long b) {return a<b ? b-a : a-b;}
INLINE(ullong,ULLONG_DIFU)   (ullong a,   ullong b) {return a<b ? b-a : a-b;}
INLINE( llong, LLONG_DIFU)    (llong a,    llong b) {return a<b ? b-a : a-b;}

#if 0 // _LEAVE_ALL_DIFU
}
#endif

#if 0 // _ENTER_ALL_MULL
{
#endif

INLINE( _Bool,  BOOL_MULL)    (_Bool a,    _Bool b) {return a&b;}
INLINE( uchar, UCHAR_MULL) (unsigned a, unsigned b) 
{
    return (uchar) a*(uchar) b;
}

INLINE( schar, SCHAR_MULL)   (signed a,   signed b) {return UCHAR_MULL(a,b);}
INLINE(  char,  CHAR_MULL)      (int a,      int b) {return UCHAR_MULL(a,b);}
INLINE(ushort, USHRT_MULL) (unsigned a, unsigned b) 
{
    return (ushort) a*(ushort) b;
}
INLINE( short,  SHRT_MULL)   (signed a,   signed b) {return USHRT_MULL(a,b);}

INLINE(  uint,  UINT_MULL)     (uint a,     uint b) {return a*b;}
INLINE(   int,   INT_MULL)      (int a,      int b) {return UINT_MULL(a,b);}
INLINE( ulong, ULONG_MULL)    (ulong a,    ulong b) {return a*b;}
INLINE(  long,  LONG_MULL)     (long a,     long b) {return ULONG_MULL(a,b);}
INLINE(ullong,ULLONG_MULL)   (ullong a,   ullong b) {return a*b;}
INLINE( llong, LLONG_MULL)    (llong a,    llong b) {return ULLONG_MULL(a,b);}

#if 0 // _LEAVE_ALL_MULL
}
#endif

#if 0 // _ENTER_ALL_MUL2
{
#endif

INLINE(uint16_t, UCHAR_MUL2)   (unsigned a, unsigned b)
{
    return  (uchar) a*(uchar) b;
}

INLINE( int16_t, SCHAR_MUL2)     (signed a,   signed b)
{
    return  UCHAR_MUL2(a, b);
}

#if CHAR_MIN

INLINE( int16_t,  CHAR_MUL2)        (int a,      int b)
{
    return  SCHAR_MUL2(a, b);
}

#else

INLINE(uint16_t,  CHAR_MUL2)        (int a,      int b)
{
    return  UCHAR_MUL2(a, b);
}

#endif

INLINE(uint32_t, USHRT_MUL2)   (unsigned a, unsigned b)
{
    return  (ushort) a*(ushort) b;
}

INLINE( int32_t,  SHRT_MUL2)     (signed a,   signed b)
{
    return  USHRT_MUL2(a, b);
}


INLINE(uint64_t,  UINT_MUL2)       (uint a,     uint b)
{
    return  (uint64_t) a*b;
}

INLINE( int64_t,   INT_MUL2)        (int a,      int b)
{
    return  UINT_MUL2(a, b);
}

#if DWRD_NLONG == 2

INLINE(   uint64_t, ULONG_MUL2)   (ulong a,   ulong b)
{
    return  (uint64_t) a*b;
}

INLINE(    int64_t,  LONG_MUL2)    (long a,    long b)
{
    return  ULONG_MUL2(a, b);
}

#endif

#if 0 // _LEAVE_ALL_MUL2
}
#endif

#if 0 // _ENTER_ALL_DIVL
{
#endif

INLINE( uchar, UCHAR_DIVL) (unsigned a, unsigned b) 
{
    return (uchar) a/(uchar) b;
}

INLINE( schar, SCHAR_DIVL)   (signed a,   signed b) 
{
    return (schar) a/(schar) b;
}

INLINE(  char,  CHAR_DIVL)      (int a,      int b) 
{
    return (char) a/(char) b;
}

INLINE(ushort, USHRT_DIVL) (unsigned a, unsigned b) 
{
    return  (ushort) a/(ushort) b;
}

INLINE( short,  SHRT_DIVL)   (signed a,   signed b) 
{
    return (short) a/(short) b;
}
INLINE(  uint,  UINT_DIVL)   (uint a,   uint b) {return a/b;}
INLINE(   int,   INT_DIVL)    (int a,    int b) {return a/b;}
INLINE( ulong, ULONG_DIVL)  (ulong a,  ulong b) {return a/b;}
INLINE(  long,  LONG_DIVL)   (long a,   long b) {return a/b;}
INLINE(ullong,ULLONG_DIVL) (ullong a, ullong b) {return a/b;}
INLINE( llong, LLONG_DIVL)  (llong a,  llong b) {return a/b;}
#if 0 // _LEAVE_ALL_DIVL
}
#endif

#if 0 // _ENTER_ALL_DIV2
{
#endif

INLINE( uint8_t, USHRT_DIV2) (unsigned a, unsigned b) 
{
    return  (ushort) a/(uint8_t) b;
}

INLINE(  int8_t,  SHRT_DIV2)   (signed a,   signed b) 
{
    return  (short) a/(int8_t) b;
}

INLINE(uint16_t,  UINT_DIV2)     (uint a, unsigned b) 
{
    return  a/(uint16_t) b;
}

INLINE( int16_t,   INT_DIV2)      (int a,   signed b) 
{
    return  a/(int16_t) b;
}


#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_DIV2)    (ulong a, unsigned b) 
{
    return  a/(uint16_t) b;
}

INLINE( int16_t,  LONG_DIV2)     (long a,   signed b) 
{
    return  a/(int16_t) b;
}

#else

INLINE(uint32_t, ULONG_DIV2)    (ulong a, uint32_t b) 
{
    return  a/b;
}

INLINE( int32_t,  LONG_DIV2)     (long a,  int32_t b) 
{
    return  a/b;
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_DIV2)   (ullong a, uint32_t b) 
{
    return a/b;
}

INLINE( int32_t, LLONG_DIV2)    (llong a,  int32_t b) 
{
    return a/b;
}

#endif

#if 0 // _LEAVE_ALL_DIV2
}
#endif

#if 0 // _ENTER_ALL_MODL
{
#endif

INLINE( uchar, UCHAR_MODL) (unsigned a, unsigned b) 
{
    return (uchar) a%(uchar) b;
}

INLINE( schar, SCHAR_MODL)   (signed a,   signed b) 
{
    return (schar) a%(schar) b;
}

INLINE(  char,  CHAR_MODL)      (int a,      int b) 
{
    return (char) a%(char) b;
}

INLINE(ushort, USHRT_MODL) (unsigned a, unsigned b) 
{
    return  (ushort) a%(ushort) b;
}

INLINE( short,  SHRT_MODL)   (signed a,   signed b) 
{
    return (short) a%(short) b;
}
INLINE(  uint,  UINT_MODL)   (uint a,   uint b) {return a%b;}
INLINE(   int,   INT_MODL)    (int a,    int b) {return a%b;}
INLINE( ulong, ULONG_MODL)  (ulong a,  ulong b) {return a%b;}
INLINE(  long,  LONG_MODL)   (long a,   long b) {return a%b;}
INLINE(ullong,ULLONG_MODL) (ullong a, ullong b) {return a%b;}
INLINE( llong, LLONG_MODL)  (llong a,  llong b) {return a%b;}
#if 0 // _LEAVE_ALL_MODL
}
#endif

#if 0 // _ENTER_ALL_MOD2
{
#endif

INLINE( uint8_t, USHRT_MOD2) (unsigned a, unsigned b) 
{
    return  (ushort) a%(uint8_t) b;
}

INLINE(  int8_t,  SHRT_MOD2)   (signed a,   signed b) 
{
    return  (short) a%(int8_t) b;
}

INLINE(uint16_t,  UINT_MOD2)     (uint a, unsigned b) 
{
    return  a%(uint16_t) b;
}

INLINE( int16_t,   INT_MOD2)      (int a,   signed b) 
{
    return  a%(int16_t) b;
}


#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_MOD2)    (ulong a, unsigned b) 
{
    return  a%(uint16_t) b;
}

INLINE( int16_t,  LONG_MOD2)     (long a,   signed b) 
{
    return  a%(int16_t) b;
}

#else

INLINE(uint32_t, ULONG_MOD2)    (ulong a, uint32_t b) 
{
    return  a%b;
}

INLINE( int32_t,  LONG_MOD2)     (long a,  int32_t b) 
{
    return  a%b;
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_MOD2)   (ullong a, uint32_t b) 
{
    return a%b;
}

INLINE( int32_t, LLONG_MOD2)    (llong a,  int32_t b) 
{
    return a%b;
}

#endif

#if 0 // _LEAVE_ALL_MOD2
}
#endif

#if 0 // _ENTER_ALL_MAXL
{
#endif

INLINE(void *,  ADDR_MAXL) 
(
    void const *a,
    void const *b
)
{
    return  (void *)(a < b ? b : a);
}

INLINE( _Bool,  BOOL_MAXL)    (_Bool a,    _Bool b) {return a|b;}
INLINE( uchar, UCHAR_MAXL) (unsigned a, unsigned b) {return a < b ? b : a;}
INLINE( schar, SCHAR_MAXL)   (signed a,   signed b) {return a < b ? b : a;}
INLINE(  char,  CHAR_MAXL)      (int a,      int b) {return a < b ? b : a;}
INLINE(ushort, USHRT_MAXL) (unsigned a, unsigned b) {return a < b ? b : a;}
INLINE( short,  SHRT_MAXL)   (signed a,   signed b) {return a < b ? b : a;}
INLINE(  uint,  UINT_MAXL)     (uint a,     uint b) {return a < b ? b : a;}
INLINE(   int,   INT_MAXL)      (int a,      int b) {return a < b ? b : a;}
INLINE( ulong, ULONG_MAXL)    (ulong a,    ulong b) {return a < b ? b : a;}
INLINE(  long,  LONG_MAXL)     (long a,     long b) {return a < b ? b : a;}
INLINE(ullong,ULLONG_MAXL)   (ullong a,   ullong b) {return a < b ? b : a;}
INLINE( llong, LLONG_MAXL)    (llong a,    llong b) {return a < b ? b : a;}

#if 0 // _LEAVE_ALL_MAXL
}
#endif

#if 0 // _ENTER_ALL_MINL
{
#endif

INLINE(void *,  ADDR_MINL) 
(
    void const *a,
    void const *b
)
{
    return  (void *)(a > b ? b : a);
}

INLINE( _Bool,  BOOL_MINL)    (_Bool a,    _Bool b) {return a&b;}
INLINE( uchar, UCHAR_MINL) (unsigned a, unsigned b) {return a > b ? b : a;}
INLINE( schar, SCHAR_MINL)   (signed a,   signed b) {return a > b ? b : a;}
INLINE(  char,  CHAR_MINL)      (int a,      int b) {return a > b ? b : a;}
INLINE(ushort, USHRT_MINL) (unsigned a, unsigned b) {return a > b ? b : a;}
INLINE( short,  SHRT_MINL)   (signed a,   signed b) {return a > b ? b : a;}
INLINE(  uint,  UINT_MINL)     (uint a,     uint b) {return a > b ? b : a;}
INLINE(   int,   INT_MINL)      (int a,      int b) {return a > b ? b : a;}
INLINE( ulong, ULONG_MINL)    (ulong a,    ulong b) {return a > b ? b : a;}
INLINE(  long,  LONG_MINL)     (long a,     long b) {return a > b ? b : a;}
INLINE(ullong,ULLONG_MINL)   (ullong a,   ullong b) {return a > b ? b : a;}
INLINE( llong, LLONG_MINL)    (llong a,    llong b) {return a > b ? b : a;}

#if 0 // _LEAVE_ALL_MINL
}
#endif
