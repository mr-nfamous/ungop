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

#define     MY_BINOP(F, A, B, ...)    ((F)(A,B))

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,neglqu) (QUAD_UTYPE x);
INLINE(QUAD_UTYPE,unolqu) (Rc(0, 128) n);
INLINE(QUAD_UTYPE,unorqu) (Rc(0, 128) n);

INLINE(QUAD_ITYPE,unolqi) (Rc(0, 128) n);
INLINE(QUAD_ITYPE,unorqi) (Rc(0, 128) n);
#endif

QUAD_UTYPE MY_MODLQU(QUAD_UTYPE l, QUAD_UTYPE r, QUAD_UTYPE *m);

INLINE( uchar, UCHAR_CSZR) (unsigned x);
INLINE( schar, SCHAR_CSZR)   (signed x); 
INLINE(  char,  CHAR_CSZR)      (int x); 
INLINE(ushort, USHRT_CSZR) (unsigned x); 
INLINE( short,  SHRT_CSZR)   (signed x);
INLINE(  uint,  UINT_CSZR)     (uint x);
INLINE(   int,   INT_CSZR)      (int x); 
INLINE( ulong, ULONG_CSZR)    (ulong x); 
INLINE(  long,  LONG_CSZR)     (long x); 
INLINE(ullong,ULLONG_CSZR)   (ullong x); 
INLINE( llong, LLONG_CSZR)    (llong x);

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,cszrqu) (QUAD_UTYPE x);
INLINE(QUAD_ITYPE,cszrqi) (QUAD_ITYPE x);
#endif

#if 0 // _ENTER_ALL_VOID
{
#endif

#define       ADDR_VOID ((void *) 0)
#define       BOOL_VOID  ((_Bool) 0)
#define      UCHAR_VOID  ((uchar) 0)
#define      SCHAR_VOID  ((schar) 0)
#define       CHAR_VOID   ((char) 0)
#define      USHRT_VOID ((ushort) 0)
#define       SHRT_VOID  ((short) 0)
#define       UINT_VOID         (0U)
#define        INT_VOID          (0)
#define      ULONG_VOID          (0UL)
#define       LONG_VOID          (0L)
#define     ULLONG_VOID          (0ULL)
#define      LLONG_VOID          (0LL)

#define       BOOL_VOIDA  ((_Bool *) 0)
#define      UCHAR_VOIDA  ((uchar *) 0)
#define      SCHAR_VOIDA  ((schar *) 0)
#define       CHAR_VOIDA   ((char *) 0)
#define      USHRT_VOIDA ((ushort *) 0)
#define       SHRT_VOIDA  ((short *) 0)
#define       UINT_VOIDA   ((uint *) 0)
#define        INT_VOIDA    ((int *) 0)
#define      ULONG_VOIDA  ((ulong *) 0)
#define       LONG_VOIDA   ((long *) 0)
#define     ULLONG_VOIDA ((ullong *) 0)
#define      LLONG_VOIDA  ((llong *) 0)

#define       BOOL_VOIDAC  ((_Bool const *) 0)
#define      UCHAR_VOIDAC  ((uchar const *) 0)
#define      SCHAR_VOIDAC  ((schar const *) 0)
#define       CHAR_VOIDAC   ((char const *) 0)
#define      USHRT_VOIDAC ((ushort const *) 0)
#define       SHRT_VOIDAC  ((short const *) 0)
#define       UINT_VOIDAC   ((uint const *) 0)
#define        INT_VOIDAC    ((int const *) 0)
#define      ULONG_VOIDAC  ((ulong const *) 0)
#define       LONG_VOIDAC   ((long const *) 0)
#define     ULLONG_VOIDAC ((ullong const *) 0)
#define      LLONG_VOIDAC  ((llong const *) 0)

#if QUAD_NLLONG == 2
#   define voidqu ((QUAD_UTYPE){0})
#   define voidaqu ((QUAD_UTYPE *) 0)
#   define voidacqu ((QUAD_UTYPE const *) 0)

#   define voidqi ((QUAD_ITYPE){0})
#   define voidaqi ((QUAD_ITYPE *) 0)
#   define voidacqi ((QUAD_ITYPE const *) 0)

#endif

#if 0 // _LEAVE_ALL_VOID
}
#endif

#if 0 // _ENTER_ALL_CKTY
{
#endif

#define       BOOL_CKTY(X) _Generic(X,  _Bool:1,default:0)
#define      UCHAR_CKTY(X) _Generic(X,  uchar:1,default:0)
#define      SCHAR_CKTY(X) _Generic(X,  schar:1,default:0)
#define       CHAR_CKTY(X) _Generic(X,   char:1,default:0)
#define      USHRT_CKTY(X) _Generic(X, ushort:1,default:0)
#define       SHRT_CKTY(X) _Generic(X,  short:1,default:0)
#define       UINT_CKTY(X) _Generic(X,   uint:1,default:0)
#define        INT_CKTY(X) _Generic(X,    int:1,default:0)
#define      ULONG_CKTY(X) _Generic(X,  ulong:1,default:0)
#define       LONG_CKTY(X) _Generic(X,   long:1,default:0)
#define     ULLONG_CKTY(X) _Generic(X, ullong:1,default:0)
#define      LLONG_CKTY(X) _Generic(X,  llong:1,default:0)
#define      FLT16_CKTY(X) _Generic(X,flt16_t:1,default:0)
#define        FLT_CKTY(X) _Generic(X,  float:1,default:0)
#define        DBL_CKTY(X) _Generic(X, double:1,default:0)

#define       VOID_CKTYA(X) _Generic(X,   void *:1,default:0)
#define       BOOL_CKTYA(X) _Generic(X,  _Bool *:1,default:0)
#define      UCHAR_CKTYA(X) _Generic(X,  uchar *:1,default:0)
#define      SCHAR_CKTYA(X) _Generic(X,  schar *:1,default:0)
#define       CHAR_CKTYA(X) _Generic(X,   char *:1,default:0)
#define      USHRT_CKTYA(X) _Generic(X, ushort *:1,default:0)
#define       SHRT_CKTYA(X) _Generic(X,  short *:1,default:0)
#define       UINT_CKTYA(X) _Generic(X,   uint *:1,default:0)
#define        INT_CKTYA(X) _Generic(X,    int *:1,default:0)
#define      ULONG_CKTYA(X) _Generic(X,  ulong *:1,default:0)
#define       LONG_CKTYA(X) _Generic(X,   long *:1,default:0)
#define     ULLONG_CKTYA(X) _Generic(X, ullong *:1,default:0)
#define      LLONG_CKTYA(X) _Generic(X,  llong *:1,default:0)
#define      FLT16_CKTYA(X) _Generic(X,flt16_t *:1,default:0)
#define        FLT_CKTYA(X) _Generic(X,  float *:1,default:0)
#define        DBL_CKTYA(X) _Generic(X, double *:1,default:0)

#define       VOID_CKTYAC(X) _Generic(X,   void const *:1,default:0)
#define       BOOL_CKTYAC(X) _Generic(X,  _Bool const *:1,default:0)
#define      UCHAR_CKTYAC(X) _Generic(X,  uchar const *:1,default:0)
#define      SCHAR_CKTYAC(X) _Generic(X,  schar const *:1,default:0)
#define       CHAR_CKTYAC(X) _Generic(X,   char const *:1,default:0)
#define      USHRT_CKTYAC(X) _Generic(X, ushort const *:1,default:0)
#define       SHRT_CKTYAC(X) _Generic(X,  short const *:1,default:0)
#define       UINT_CKTYAC(X) _Generic(X,   uint const *:1,default:0)
#define        INT_CKTYAC(X) _Generic(X,    int const *:1,default:0)
#define      ULONG_CKTYAC(X) _Generic(X,  ulong const *:1,default:0)
#define       LONG_CKTYAC(X) _Generic(X,   long const *:1,default:0)
#define     ULLONG_CKTYAC(X) _Generic(X, ullong const *:1,default:0)
#define      LLONG_CKTYAC(X) _Generic(X,  llong const *:1,default:0)
#define      FLT16_CKTYAC(X) _Generic(X,flt16_t const *:1,default:0)
#define        FLT_CKTYAC(X) _Generic(X,  float const *:1,default:0)
#define        DBL_CKTYAC(X) _Generic(X, double const *:1,default:0)

#if QUAD_NLLONG == 2
#   define  cktyqu(X)   _Generic(X,QUAD_UTYPE        :1,default:0)
#   define  cktyaqu(X)  _Generic(X,QUAD_UTYPE       *:1,default:0)
#   define  cktyacqu(X) _Generic(X,QUAD_UTYPE const *:1,default:0)

#   define  cktyqi(X)   _Generic(X,QUAD_ITYPE        :1,default:0)
#   define  cktyaqi(X)  _Generic(X,QUAD_ITYPE       *:1,default:0)
#   define  cktyacqi(X) _Generic(X,QUAD_ITYPE const *:1,default:0)
#endif

#define     cktywyu(X) _Generic(X,Vwyu:1,default:0)
#define     cktywbu(X) _Generic(X,Vwbu:1,default:0)
#define     cktywbi(X) _Generic(X,Vwbi:1,default:0)
#define     cktywbc(X) _Generic(X,Vwbc:1,default:0)
#define     cktywhu(X) _Generic(X,Vwhu:1,default:0)
#define     cktywhi(X) _Generic(X,Vwhi:1,default:0)
#define     cktywhf(X) _Generic(X,Vwhf:1,default:0)
#define     cktywwu(X) _Generic(X,Vwwu:1,default:0)
#define     cktywwi(X) _Generic(X,Vwwi:1,default:0)
#define     cktywwf(X) _Generic(X,Vwwf:1,default:0)

#define     cktydyu(X) _Generic(X,Vdyu:1,default:0)
#define     cktydbu(X) _Generic(X,Vdbu:1,default:0)
#define     cktydbi(X) _Generic(X,Vdbi:1,default:0)
#define     cktydbc(X) _Generic(X,Vdbc:1,default:0)
#define     cktydhu(X) _Generic(X,Vdhu:1,default:0)
#define     cktydhi(X) _Generic(X,Vdhi:1,default:0)
#define     cktydhf(X) _Generic(X,Vdhf:1,default:0)
#define     cktydwu(X) _Generic(X,Vdwu:1,default:0)
#define     cktydwi(X) _Generic(X,Vdwi:1,default:0)
#define     cktydwf(X) _Generic(X,Vdwf:1,default:0)
#define     cktyddu(X) _Generic(X,Vddu:1,default:0)
#define     cktyddi(X) _Generic(X,Vddi:1,default:0)
#define     cktyddf(X) _Generic(X,Vddf:1,default:0)

#define     cktyqyu(X) _Generic(X,Vqyu:1,default:0)
#define     cktyqbu(X) _Generic(X,Vqbu:1,default:0)
#define     cktyqbi(X) _Generic(X,Vqbi:1,default:0)
#define     cktyqbc(X) _Generic(X,Vqbc:1,default:0)
#define     cktyqhu(X) _Generic(X,Vqhu:1,default:0)
#define     cktyqhi(X) _Generic(X,Vqhi:1,default:0)
#define     cktyqhf(X) _Generic(X,Vqhf:1,default:0)
#define     cktyqwu(X) _Generic(X,Vqwu:1,default:0)
#define     cktyqwi(X) _Generic(X,Vqwi:1,default:0)
#define     cktyqwf(X) _Generic(X,Vqwf:1,default:0)
#define     cktyqdu(X) _Generic(X,Vqdu:1,default:0)
#define     cktyqdi(X) _Generic(X,Vqdi:1,default:0)
#define     cktyqdf(X) _Generic(X,Vqdf:1,default:0)
#define     cktyqqu(X) _Generic(X,Vqqu:1,default:0)
#define     cktyqqi(X) _Generic(X,Vqqi:1,default:0)
#define     cktyqqf(X) _Generic(X,Vqqf:1,default:0)

#if 0 // _LEAVE_ALL_CKTY
}
#endif

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
//efine     VQQU_ASTU
#define     VQQI_ASTU       VQQI_ASQU
#define     VQQF_ASTU       VQQF_ASQU

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
#define     VQQU_ASTI       VQQU_ASQI
//efine     VQQI_ASTI
#define     VQQF_ASTI       VQQF_ASQI

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
#define     VQQU_ASTF       VQQU_ASQF
#define     VQQI_ASTF       VQQI_ASQF
//efine     VQQF_ASTF

#if 0 // _LEAVE_ALL_ASTF
}
#endif

#if 0 // _ENTER_ALL_ASYU
{
#endif

INLINE(_Bool,  BOOL_ASYU)   (_Bool x) {return x;}
INLINE(Vwyu,VWYU_ASYU) (Vwyu x) {return x;}
INLINE(Vdyu,VDYU_ASYU) (Vdyu x) {return x;}
INLINE(Vqyu,VQYU_ASYU) (Vqyu x) {return x;}
#if 0 // _LEAVE_ALL_ASYU
}
#endif

#if 0 // _ENTER_ALL_ASBU
{
#endif

INLINE(uint8_t,UCHAR_ASBU) (unsigned x) {return x;}
INLINE(uint8_t,SCHAR_ASBU)   (signed x) {return x;}
INLINE(uint8_t, CHAR_ASBU)      (int x) {return x;}

INLINE(Vwbu,VWBU_ASBU) (Vwbu x) {return x;}
INLINE(Vdbu,VDBU_ASBU) (Vdbu x) {return x;}
INLINE(Vqbu,VQBU_ASBU) (Vqbu x) {return x;}

#if 0 // _LEAVE_ALL_ASBU
}
#endif

#if 0 // _ENTER_ALL_ASBI
{
#endif

INLINE(int8_t,UCHAR_ASBI) (unsigned x) {return x;}
INLINE(int8_t,SCHAR_ASBI) (signed x) {return x;}
INLINE(int8_t, CHAR_ASBI)  (int x) {return x;}
INLINE(Vdbi,VDBI_ASBI) (Vdbi v) {return v;}
INLINE(Vwbi,VWBI_ASBI) (Vwbi v) {return v;}
INLINE(Vqbi,VQBI_ASBI) (Vqbi v) {return v;}

#if 0 // _LEAVE_ALL_ASBI
}
#endif

#if 0 // _ENTER_ALL_ASBC
{
#endif

INLINE(char,UCHAR_ASBC) (unsigned x) {return x;}
INLINE(char,SCHAR_ASBC) (signed x) {return x;}
INLINE(char, CHAR_ASBC)  (int x) {return x;}

INLINE(Vwbc,VWBC_ASBC) (Vwbc v) {return v;}
INLINE(Vdbc,VDBC_ASBC) (Vdbc v) {return v;}
INLINE(Vqbc,VQBC_ASBC) (Vqbc v) {return v;}
#if 0 // _LEAVE_ALL_ASBC
}
#endif

#if 0 // _ENTER_ALL_ASHU
{
#endif

INLINE(uint16_t,USHRT_ASHU)  (unsigned x) {return x;}
INLINE(uint16_t, SHRT_ASHU)   (signed x) {return x;}
INLINE(uint16_t,FLT16_ASHU) (flt16_t x) {return FLT16_ASTG(x).U;}

INLINE(Vwhu,VWHU_ASHU) (Vwhu x) {return x;}
INLINE(Vdhu,VDHU_ASHU) (Vdhu x) {return x;}
INLINE(Vqhu,VQHU_ASHU) (Vqhu x) {return x;}

#if 0 // _LEAVE_ALL_ASHU
}
#endif

#if 0 // _ENTER_ALL_ASHI
{
#endif

INLINE(int16_t,USHRT_ASHI) (unsigned x) {return x;}
INLINE(int16_t, SHRT_ASHI)   (signed x) {return x;}
INLINE(int16_t,FLT16_ASHI)  (flt16_t x) {return FLT16_ASTG(x).I;}

INLINE(Vwhi,VWHI_ASHI) (Vwhi x) {return x;}
INLINE(Vdhi,VDHI_ASHI) (Vdhi x) {return x;}
INLINE(Vqhi,VQHI_ASHI) (Vqhi x) {return x;}

#if 0 // _LEAVE_ALL_ASHI
}
#endif

#if 0 // _ENTER_ALL_ASHF
{
#endif

INLINE(flt16_t,USHRT_ASHF)  (unsigned x) {return USHRT_ASTG(x).F;}
INLINE(flt16_t, SHRT_ASHF)   (signed x) {return  SHRT_ASTG(x).F;}
INLINE(flt16_t,FLT16_ASHF) (flt16_t x) {return x;}

INLINE(Vwhf,VWHF_ASHF) (Vwhf x) {return x;}
INLINE(Vdhf,VDHF_ASHF) (Vdhf x) {return x;}
INLINE(Vqhf,VQHF_ASHF) (Vqhf x) {return x;}

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
INLINE(Vwwu,VWWU_ASWU) (Vwwu x) {return x;}
INLINE(Vdwu,VDWU_ASWU) (Vdwu x) {return x;}
INLINE(Vqwu,VQWU_ASWU) (Vqwu x) {return x;}

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

INLINE(Vwwi,VWWI_ASWI) (Vwwi x) {return x;}
INLINE(Vdwi,VDWI_ASWI) (Vdwi x) {return x;}
INLINE(Vqwi,VQWI_ASWI) (Vqwi x) {return x;}

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

INLINE(Vwwf,VWWF_ASWF) (Vwwf x) {return x;}
INLINE(Vdwf,VDWF_ASWF) (Vdwf x) {return x;}
INLINE(Vqwf,VQWF_ASWF) (Vqwf x) {return x;}

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
INLINE(Vddu,VDDU_ASDU) (Vddu x) {return x;}
INLINE(Vqdu,VQDU_ASDU) (Vqdu x) {return x;}

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

INLINE(Vddi,VDDI_ASDI) (Vddi x) {return x;}
INLINE(Vqdi,VQDI_ASDI) (Vqdi x) {return x;}

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
INLINE(Vddf,VDDF_ASDF) (Vddf x) {return x;}
INLINE(Vqdf,VQDF_ASDF) (Vqdf x) {return x;}

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

INLINE(Vqqu,VQQU_ASQU) (Vqqu x) {return x;}

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

INLINE(Vqqi,VQQI_ASQI) (Vqqi x) {return x;}

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

INLINE(Vqqf,VQQF_ASQF) (Vqqf x) {return x;}

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

INLINE(_Bool, UCHAR_CVYU) (unsigned x) 
{
#define     UCHAR_CVYU(X) ((_Bool) ((uchar) X))
    return  (uchar) x;
}

INLINE(_Bool, SCHAR_CVYU)   (signed x) 
{
#define     SCHAR_CVYU(X) ((_Bool) ((schar) X))
    return  (schar) x;
}

INLINE(_Bool,  CHAR_CVYU)      (int x) 
{
#define     CHAR_CVYU(X) ((_Bool) ((char) X))
    return  (char) x;
}

INLINE(_Bool, USHRT_CVYU) (unsigned x) 
{
#define     USHRT_CVYU(X) ((_Bool) ((ushort) X))
    return  (ushort) x;
}

INLINE(_Bool,  SHRT_CVYU)   (signed x) 
{
#define     SHRT_CVYU(X) ((_Bool) ((short) X))
    return  (short) x;
}

INLINE(_Bool,  UINT_CVYU)     (uint x) 
{
#define     UINT_CVYU(X) ((_Bool) ((uint) X))
    return  x;
}

INLINE(_Bool,   INT_CVYU)      (int x) 
{
#define     INT_CVYU(X) ((_Bool) ((int) X))
    return x;
}

INLINE(_Bool, ULONG_CVYU)    (ulong x) 
{
#define     ULONG_CVYU(X) ((_Bool) ((ulong) X))
    return  x;
}

INLINE(_Bool,  LONG_CVYU)     (long x) 
{
#define     LONG_CVYU(X) ((_Bool) ((long) X))
    return  x;
}

INLINE(_Bool,ULLONG_CVYU)   (ullong x) 
{
#define     ULLONG_CVYU(X) ((_Bool) ((ullong) X))
    return  x;
}

INLINE(_Bool, LLONG_CVYU)    (llong x) 
{
#define     LLONG_CVYU(X) ((_Bool) ((llong) X))
    return  x;
}

#if QUAD_NLLONG == 2
INLINE(_Bool,cvyuqu) (QUAD_UTYPE x)
{
    QUAD_TYPE v = {.U=x};
    return  v.Lo.U|v.Hi.U;
}

INLINE(_Bool,cvyuqi) (QUAD_ITYPE x)
{
    QUAD_TYPE v = {.I=x};
    return  v.Lo.U|v.Hi.U;
}
#endif

#if 0 // _LEAVE_ALL_CVYU
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

#if QUAD_NLLONG == 2

INLINE(uint8_t,cvbuqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).B0.U;
}

INLINE(uint8_t,cvbuqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).B0.U;
}

#endif

INLINE(Vwbu,VWBU_CVBU) (Vwbu x) {return x;}
INLINE(Vdbu,VDBU_CVBU) (Vdbu x) {return x;}
INLINE(Vqbu,VQBU_CVBU) (Vqbu x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(int8_t,cvbiqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).B0.I;
}

INLINE(int8_t,cvbiqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).B0.I;
}

#endif

INLINE(Vwbi,VWBI_CVBI) (Vwbi x) {return x;}
INLINE(Vdbi,VDBI_CVBI) (Vdbi x) {return x;}
INLINE(Vqbi,VQBI_CVBI) (Vqbi x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(char,cvbcqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).C0;
}

INLINE(char,cvbcqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).C0;
}

#endif

INLINE(Vwbc,VWBC_CVBC) (Vwbc x) {return x;}

INLINE(Vdbc,VDBC_CVBC) (Vdbc x) {return x;}

INLINE(Vqbc,VQBC_CVBC) (Vqbc x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(uint16_t,cvhuqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).H0.U;
}

INLINE(uint16_t,cvhuqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).H0.U;
}

#endif

INLINE(Vwhu,VWHU_CVHU) (Vwhu x) {return  x;}

INLINE(Vdhu,VDHU_CVHU) (Vdhu x) {return  x;}

INLINE(Vqhu,VQHU_CVHU) (Vqhu x) {return  x;}

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

#if QUAD_NLLONG == 2

INLINE(uint16_t,cvhiqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).H0.I;
}

INLINE(uint16_t,cvhiqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).H0.I;
}

#endif

INLINE(Vwhi,VWHI_CVHI) (Vwhi x) {return x;}

INLINE(Vdhi,VDHI_CVHI) (Vdhi x) {return x;}

INLINE(Vqhi,VQHI_CVHI) (Vqhi x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(uint32_t,cvwuqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).W0.U;
}

INLINE(uint32_t,cvwuqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).W0.U;
}

#endif

INLINE(Vwwu,VWWU_CVWU) (Vwwu x) {return x;}

INLINE(Vdwu,VDWU_CVWU) (Vdwu x) {return x;}

INLINE(Vqwu,VQWU_CVWU) (Vqwu x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(int32_t,cvwiqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).W0.I;
}

INLINE(int32_t,cvwiqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).W0.I;
}

#endif

INLINE(Vwwi,VWWI_CVWI) (Vwwi x) {return x;}
INLINE(Vdwi,VDWI_CVWI) (Vdwi x) {return x;}
INLINE(Vqwi,VQWI_CVWI) (Vqwi x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(uint64_t,cvduqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).D0.U;
}

INLINE(uint32_t,cvduqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).D0.U;
}

#endif

INLINE(Vddu,VDDU_CVDU) (Vddu x) {return x;}

INLINE(Vqdu,VQDU_CVDU) (Vqdu x) {return x;}

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

#if QUAD_NLLONG == 2

INLINE(int64_t,cvdiqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).D0.I;
}

INLINE(int32_t,cvdiqi) (QUAD_ITYPE x)
{
    return  ((QUAD_TYPE){.I=x}).D0.I;
}

#endif

INLINE(Vddi,VDDI_CVDI) (Vddi x) {return x;}
INLINE(Vqdi,VQDI_CVDI) (Vqdi x) {return x;}

#if 0 // _LEAVE_ALL_CVDI
}
#endif

#if 0 // _ENTER_ALL_CVQU
{
#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,  BOOL_CVQU)    (_Bool x) 
{
#define     BOOL_CVQU(X) ((QUAD_TYPE){.Y0=X}).U
    return  BOOL_CVQU(x);
}


INLINE(QUAD_UTYPE, UCHAR_CVQU) (unsigned x) 
{
#define     UCHAR_CVQU(X) ((QUAD_TYPE){.B0.U=X}).U
    return  UCHAR_CVQU(x);
}

INLINE(QUAD_UTYPE, SCHAR_CVQU)   (signed x) 
{
/*  "Funny" story. This is the only possible way to get clang 
    to not split sign extending the upper 64 bits into two
    instructions without referencing __int128. Specifically,
    if "v.Lo.I>>7" is replaced with e.g. "x>>7", the upper
    extension is split into an "8 to 32" then "32 to 64".

    Hopefully, it actually is true that no architecture would
    be moronic enough to implement signed right shift any way 
    other than the obvious one.
*/
    QUAD_TYPE   v;
    v.Lo.I = (schar) x;
    v.Hi.I = v.Lo.I>>(SCHAR_WIDTH-1);
    return  v.U;
}

INLINE(QUAD_UTYPE,  CHAR_CVQU)      (int x) 
{
#if CHAR_MIN
    return SCHAR_CVQU(x);
#else
#   define  CHAR_CVQU(X) ((QUAD_TYPE){.C0=X}).U
    return  CHAR_CVQU(x);
#endif
}


INLINE(QUAD_UTYPE, USHRT_CVQU) (unsigned x)
{
#define     USHRT_CVQU(X) ((QUAD_TYPE){.H0.U=X}).U
    return  USHRT_CVQU(x);
}

INLINE(QUAD_UTYPE,  SHRT_CVQU)   (signed x) 
{
    QUAD_TYPE   v;
    v.Lo.I = (short) x;
    v.Hi.I = v.Lo.I>>(SHRT_WIDTH-1);
    return  v.U;
}

INLINE(QUAD_UTYPE,  UINT_CVQU)     (uint x) 
{
#define     UINT_CVQU(X) ((QUAD_TYPE){.W0.U=X}).U
    return  UINT_CVQU(x);
}

INLINE(QUAD_UTYPE,   INT_CVQU)      (int x) 
{
    QUAD_TYPE   v;
    v.Lo.I = x;
    v.Hi.I = v.Lo.I>>(INT_WIDTH-1);
    return  v.U;
}

INLINE(QUAD_UTYPE, ULONG_CVQU)    (ulong x) 
{
#if DWRD_NLONG == 2
#   define  ULONG_CVQU(X) ((QUAD_TYPE){.W0.U=X}).U
#else
#   define  ULONG_CVQU(X) ((QUAD_TYPE){.D0.U=X}).U
#endif
    return  ULONG_CVQU(x);
}

INLINE(QUAD_UTYPE,  LONG_CVQU)     (long x)
{
    QUAD_TYPE   v;
    v.Lo.I  = x;
    v.Hi.I  = v.Lo.I>>(LONG_WIDTH-1);
    return  v.U;
}

INLINE(QUAD_UTYPE,ULLONG_CVQU)   (ullong x) 
{
#if QUAD_NLLONG == 2
#   define  ULLONG_CVQU(X) ((QUAD_TYPE){.D0.U=X}).U
    return  ULLONG_CVQU(x);
#else
#   define  ULLONG_CVQU(X) ((ullong) X)
    return  x;
#endif
}

INLINE(QUAD_UTYPE, LLONG_CVQU)    (llong x) 
{
#if QUAD_NLLONG == 2
    QUAD_TYPE   v;
    v.Lo.I  = x;
    v.Hi.I  = v.Lo.I>>(LLONG_WIDTH-1);
    return  v.U;
#else
    return  x;
#endif
}

INLINE(QUAD_UTYPE,  ADDR_CVQU) (void volatile const *x)
{
#if ADDR_WIDTH == INT_WIDTH
    return  INT_CVQU(((intptr_t) x));
#elif ADDR_WIDTH == LONG_WIDTH
    return  LONG_CVQU(((intptr_t) x));
#else
    return  LLONG_CVQU(((intptr_t) x));
#endif
}

INLINE(QUAD_UTYPE,cvququ) (QUAD_UTYPE x) {return  x;}

INLINE(QUAD_UTYPE,cvquqi) (QUAD_ITYPE x) {return ((QUAD_TYPE){.I=x}).U;}

#else

INLINE(ullong,  BOOL_CVQU)    (_Bool x) {return x;}
INLINE(ullong, UCHAR_CVQU) (unsigned x) {return  (uchar) x;}
INLINE(ullong, SCHAR_CVQU)   (signed x) {return  (schar) x;}
INLINE(ullong,  CHAR_CVQU)      (int x) {return   (char) x;}
INLINE(ullong, USHRT_CVQU) (unsigned x) {return (ushort) x;}
INLINE(ullong,  SHRT_CVQU)   (signed x) {return  (short) x;}
INLINE(ullong,  UINT_CVQU)     (uint x) {return x;}
INLINE(ullong,   INT_CVQU)      (int x) {return x;}
INLINE(ullong, ULONG_CVQU)    (ulong x) {return x;}
INLINE(ullong,  LONG_CVQU)     (long x) {return x;}
INLINE(ullong,ULLONG_CVQU)   (ullong x) {return x;}
INLINE(ullong, LLONG_CVQU)    (llong x) {return x;}
INLINE(ullong,  ADDR_CVQU) (void volatile const *x) 
{
    return  (uintptr_t) x;
}

#endif

#if 0 // _LEAVE_ALL_CVQU
}
#endif

#if 0 // _ENTER_ALL_CVQI
{
#endif

#if QUAD_NLLONG == 2
INLINE(QUAD_ITYPE,   BOOL_CVQI)    (_Bool x) 
{
#define     BOOL_CVQI(X) ((QUAD_TYPE){.Y0=X}).I
    return  BOOL_CVQI(x);
}


INLINE(QUAD_ITYPE,  UCHAR_CVQI) (unsigned x) 
{
#define     UCHAR_CVQI(X) ((QUAD_TYPE){.B0.U=X}).I
    return  UCHAR_CVQI(x);
}

INLINE(QUAD_ITYPE,  SCHAR_CVQI)   (signed x) 
{
/*  "Funny" story. This is the only possible way to get clang 
    to not split sign extending the upper 64 bits into two
    instructions without referencing __int128. Specifically,
    if "v.Lo.I>>7" is replaced with e.g. "x>>7", the upper
    64 bit extension is split into an 8 to 32 bit, 32 to 64
    bit.

    Hopefully, it actually is true that no architecture would
    be moronic enough to implement signed right shift any way 
    other than the obvious one.
*/
    QUAD_TYPE   v;
    v.Lo.I = (schar) x;
    v.Hi.I = v.Lo.I>>(SCHAR_WIDTH-1);
    return  v.I;
}

INLINE(QUAD_ITYPE,   CHAR_CVQI)      (int x) 
{
#if CHAR_MIN
    return  SCHAR_CVQI(x);
#else
#   define  CHAR_CVQI(X) ((QUAD_TYPE){.C0=X}).I
    return  CHAR_CVQI(x);
#endif
}


INLINE(QUAD_ITYPE,  USHRT_CVQI) (unsigned x)
{
#define     USHRT_CVQI(X) ((QUAD_TYPE){.H0.U=X}).I
    return  USHRT_CVQI(x);
}

INLINE(QUAD_ITYPE,   SHRT_CVQI)   (signed x) 
{
    QUAD_TYPE   v;
    v.Lo.I = (short) x;
    v.Hi.I = v.Lo.I>>(SHRT_WIDTH-1);
    return  v.I;
}

INLINE(QUAD_ITYPE,   UINT_CVQI)     (uint x) 
{
#define     UINT_CVQI(X) ((QUAD_TYPE){.W0.U=X}).I
    return  UINT_CVQI(x);
}

INLINE(QUAD_ITYPE,    INT_CVQI)      (int x) 
{
    QUAD_TYPE   v;
    v.Lo.I = (int) x;
    v.Hi.I = v.Lo.I>>(INT_WIDTH-1);
    return  v.I;
}

INLINE(QUAD_ITYPE,  ULONG_CVQI)    (ulong x) 
{
#if DWRD_NLONG == 2
#   define  ULONG_CVQI(X) ((QUAD_TYPE){.W0.U=X}).I
#else
#   define  ULONG_CVQI(X) ((QUAD_TYPE){.D0.U=X}).I
#endif
    return  ULONG_CVQI(x);
}

INLINE(QUAD_ITYPE,   LONG_CVQI)     (long x)
{
    QUAD_TYPE   v;
    v.Lo.I  = x;
    v.Hi.I  = v.Lo.I>>(LONG_WIDTH-1);
    return  v.I;
}

INLINE(QUAD_ITYPE, ULLONG_CVQI)   (ullong x) 
{
#if QUAD_NLLONG == 2
#   define  ULLONG_CVQI(X) ((QUAD_TYPE){.D0.U=X}).I
    return  ULLONG_CVQI(x);
#else
    return  x;
#endif
}

INLINE(QUAD_ITYPE,  LLONG_CVQI)    (llong x) 
{
#if QUAD_NLLONG == 2
    QUAD_TYPE   v;
    v.Lo.I  = x;
    v.Hi.I  = v.Lo.I>>(LLONG_WIDTH-1);
    return  v.U;
#else
    return  x;
#endif
}

INLINE(QUAD_ITYPE,   ADDR_CVQI) (void volatile const *x)
{
#if ADDR_WIDTH == INT_WIDTH
    return  INT_CVQI(((intptr_t) x));
#elif ADDR_WIDTH == LONG_WIDTH
    return  LONG_CVQI(((intptr_t) x));
#else
    return  LLONG_CVQI(((intptr_t) x));
#endif
}

INLINE(QUAD_ITYPE,cvqiqu) (QUAD_UTYPE x)
{
    return  ((QUAD_TYPE){.U=x}).I;
}

INLINE(QUAD_ITYPE,cvqiqi) (QUAD_ITYPE x)
{
    return  x;
}

#else

INLINE(llong,  BOOL_CVQI)    (_Bool x) {return x;}
INLINE(llong, UCHAR_CVQI) (unsigned x) {return  (uchar) x;}
INLINE(llong, SCHAR_CVQI)   (signed x) {return  (schar) x;}
INLINE(llong,  CHAR_CVQI)      (int x) {return   (char) x;}
INLINE(llong, USHRT_CVQI) (unsigned x) {return (ushort) x;}
INLINE(llong,  SHRT_CVQI)   (signed x) {return  (short) x;}
INLINE(llong,  UINT_CVQI)     (uint x) {return x;}
INLINE(llong,   INT_CVQI)      (int x) {return x;}
INLINE(llong, ULONG_CVQI)    (ulong x) {return x;}
INLINE(llong,  LONG_CVQI)     (long x) {return x;}
INLINE(llong,ULLONG_CVQI)   (ullong x) {return x;}
INLINE(llong, LLONG_CVQI)    (llong x) {return x;}
INLINE(llong,  ADDR_CVQI) (void volatile const *x) 
{
    return  (uintptr_t) x;
}

#endif
#if 0 // _LEAVE_ALL_CVQI
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

INLINE(uint64_t,getlqu) (QUAD_UTYPE x)
{
    return ((QUAD_TYPE){.U=x}).Lo.U;
}

INLINE(int64_t,getlqi) (QUAD_ITYPE x)
{
    return ((QUAD_TYPE){.I=x}).Lo.I;
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

INLINE(uint64_t,getrqu) (QUAD_UTYPE x)
{
    return ((QUAD_TYPE){.U=x}).Hi.U;
}

INLINE(int64_t,getrqi) (QUAD_ITYPE x)
{
    return ((QUAD_TYPE){.I=x}).Hi.I;
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

INLINE(_Bool,  ADDR_CNBY)(void const *x,void const *l,void const *r)
{
    return  (l > x) || (x > r);
}


INLINE(_Bool, UCHAR_CNBY) 
(
    unsigned         x, 
    Jc(0, UCHAR_MAX) l, 
    Jc(l, UCHAR_MAX) r
)
{
    uchar c = x;
    return  (l > c) || (c > r);
}

INLINE(_Bool, SCHAR_CNBY)   
(
    signed                   x, 
    Jc(SCHAR_MIN, SCHAR_MAX) l,
    Jc(l,         SCHAR_MAX) r
)
{
    schar c = x;
    return  (l > c) || (c > r);
}

INLINE(_Bool,  CHAR_CNBY)   
(
    int                    x, 
    Jc(CHAR_MIN, CHAR_MAX) l,
    Jc(l,        CHAR_MAX) r
)
{
    char c = x;
    return  (l > c) || (c > r);
}


INLINE(_Bool, USHRT_CNBY)
(
    unsigned         x, 
    Jc(0, USHRT_MAX) l,
    Jc(l, USHRT_MAX) r
)
{
    ushort c = x;
    return  (l > c) || (c > r);
}

INLINE(_Bool,  SHRT_CNBY)
(
    signed                 x, 
    Jc(SHRT_MIN, SHRT_MAX) l,
    Jc(l,        SHRT_MAX) r
)
{
    short c = x;
    return  (l > c) || (c > r);
}


INLINE(_Bool,  UINT_CNBY)
(
    uint            x, 
    Jc(0, UINT_MAX) l,
    Jc(l, UINT_MAX) r
)
{
    return  (l > x) || (x > r);
}

INLINE(_Bool,   INT_CNBY)
(
    int                  x, 
    Jc(INT_MIN, INT_MAX) l,
    Jc(l,       INT_MAX) r
)
{
    return  (l > x) || (x > r);
}


INLINE(_Bool, ULONG_CNBY)
(
    ulong                     x, 
    unsigned Jc(0, ULONG_MAX) l,
    unsigned Jc(l, ULONG_MAX) r
)
{
    return  (l > x) || (x > r);
}

INLINE(_Bool,  LONG_CNBY)
(
    long                          x, 
    signed Jc(LONG_MIN, LONG_MAX) l,
    signed Jc(l,        LONG_MAX) r
)
{
    return  (l > x) || (x > r);
}


INLINE(_Bool,ULLONG_CNBY)
(
    ullong                     x, 
    unsigned Jc(0, ULLONG_MAX) l,
    unsigned Jc(l, ULLONG_MAX) r
)
{
    return  (l > x) || (x > r);
}

INLINE(_Bool, LLONG_CNBY)
(
    llong                           x, 
    signed Jc(LLONG_MIN, LLONG_MAX) l,
    signed Jc(l,         LLONG_MAX) r
)
{
    return  (l > x) || (x > r);
}

#if 0 // _LEAVE_ALL_CNBY
}
#endif


#if 0 // _ENTER_ALL_CEQL
{
#endif

INLINE(ptrdiff_t, ADDR_CEQL) (void const *a, void const *b)
{
    return a==b;
}

INLINE(uchar,  UCHAR_CEQL) (unsigned a, unsigned b) 
{
    return (uchar) a==(uchar) b;
}

INLINE(schar,  SCHAR_CEQL)   (signed a,   signed b) 
{
    return (schar) a==(schar) b;
}

INLINE(char,    CHAR_CEQL)      (int a,      int b) 
{
    return (char) a==(char) b;
}


INLINE(ushort, USHRT_CEQL) (unsigned a, unsigned b) 
{
    return  (ushort) a==(ushort) b;
}

INLINE(short,   SHRT_CEQL)   (signed a,   signed b) 
{
    return (short) a==(short) b;
}

INLINE(uint,    UINT_CEQL)     (uint a,     uint b) {return a==b;}
INLINE(int,      INT_CEQL)      (int a,      int b) {return a==b;}
INLINE(ulong,  ULONG_CEQL)    (ulong a,    ulong b) {return a==b;}
INLINE(long,    LONG_CEQL)     (long a,     long b) {return a==b;}
INLINE(ullong,ULLONG_CEQL)   (ullong a,   ullong b) {return a==b;}
INLINE(llong,  LLONG_CEQL)    (llong a,    llong b) {return a==b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,ceqlqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = (p.Lo.U==q.Lo.U) && (p.Hi.U==q.Hi.U);
    c.Hi.U = 0;
    return  c.U;
#else
    return a == b;
#endif
}

INLINE(QUAD_ITYPE,ceqlqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.U = (p.Lo.U==q.Lo.U) && (p.Hi.U==q.Hi.U);
    c.Hi.U = 0;
    return  c.U;
#else
    return a == b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CEQL
}
#endif

#if 0 // _ENTER_ALL_CEQS
{
#endif

INLINE(ptrdiff_t, ADDR_CEQS) (void const *a, void const *b)
{
    return -(a==b);
}

INLINE( uchar, UCHAR_CEQS) (unsigned a, unsigned b) 
{
    return -((uchar) a==(uchar) b);
}

INLINE( schar, SCHAR_CEQS)   (signed a,   signed b) 
{
    return -((schar) a==(schar) b);
}

INLINE(  char,  CHAR_CEQS)      (int a,      int b) 
{
    return -((char) a==(char) b);
}


INLINE(ushort, USHRT_CEQS) (unsigned a, unsigned b) 
{
    return  -((ushort) a==(ushort) b);
}

INLINE( short,  SHRT_CEQS)   (signed a,   signed b) 
{
    return -((short) a==(short) b);
}

INLINE(  uint,  UINT_CEQS)     (uint a,     uint b) {return -(a==b);}
INLINE(   int,   INT_CEQS)      (int a,      int b) {return -(a==b);}

INLINE( ulong, ULONG_CEQS)    (ulong a,    ulong b) {return -(a==b);}
INLINE(  long,  LONG_CEQS)     (long a,     long b) {return -(a==b);}

INLINE(ullong,ULLONG_CEQS)   (ullong a,   ullong b) {return -(a==b);}
INLINE( llong, LLONG_CEQS)    (llong a,    llong b) {return -(a==b);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,ceqsqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.I = -((p.Lo.I==q.Lo.I) && (p.Hi.I==q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.U;
}

INLINE(QUAD_ITYPE,ceqsqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.I = -((p.Lo.I==q.Lo.I) && (p.Hi.I==q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_CEQS
}
#endif

#if 0 // _ENTER_ALL_CEQY
{
#endif

INLINE(_Bool, ADDR_CEQY) (void const *a, void const *b)
{
    return  a==b;
}

INLINE(_Bool, BOOL_CEQY)    (_Bool a,    _Bool b) {return  a==b;}

INLINE(_Bool, UCHAR_CEQY) (unsigned a, unsigned b) 
{
    return (uchar) a==(uchar) b;
}

INLINE(_Bool, SCHAR_CEQY)   (signed a,   signed b) 
{
    return (schar) a==(schar) b;
}

INLINE(_Bool,  CHAR_CEQY)      (int a,      int b) 
{
    return (char) a==(char) b;
}


INLINE(_Bool, USHRT_CEQY) (unsigned a, unsigned b) 
{
    return  (ushort) a==(ushort) b;
}

INLINE(_Bool,  SHRT_CEQY)   (signed a,   signed b) 
{
    return (short) a==(short) b;
}

INLINE(_Bool,  UINT_CEQY)     (uint a,     uint b) {return a==b;}
INLINE(_Bool,   INT_CEQY)      (int a,      int b) {return a==b;}
INLINE(_Bool, ULONG_CEQY)    (ulong a,    ulong b) {return a==b;}
INLINE(_Bool,  LONG_CEQY)     (long a,     long b) {return a==b;}
INLINE(_Bool,ULLONG_CEQY)   (ullong a,   ullong b) {return a==b;}
INLINE(_Bool, LLONG_CEQY)    (llong a,    llong b) {return a==b;}

#if QUAD_NLLONG == 2

INLINE(_Bool,ceqyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return a==b;
#else
    QUAD_TYPE   p={.U=a}, q={.U=b};
    return  (p.Lo.U==q.Lo.U) && (p.Hi.U==q.Hi.U);
#endif
}

INLINE(_Bool,ceqyqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b};
    return  ceqyqu(p.U, q.U);
}

#endif

#if 0 // _LEAVE_ALL_CEQY
}
#endif


#if 0 // _ENTER_ALL_CNEL
{
#endif

INLINE(ptrdiff_t,ADDR_CNEL) (void const *a, void const *b)
{
    return a!=b;
}

INLINE( uchar, UCHAR_CNEL) (unsigned a, unsigned b) 
{
    return (uchar) a!=(uchar) b;
}

INLINE( schar, SCHAR_CNEL)   (signed a,   signed b) 
{
    return (schar) a!=(schar) b;
}

INLINE(  char,  CHAR_CNEL)      (int a,      int b) 
{
    return (char) a!=(char) b;
}


INLINE(ushort, USHRT_CNEL) (unsigned a, unsigned b) 
{
    return  (ushort) a!=(ushort) b;
}

INLINE( short,  SHRT_CNEL)   (signed a,   signed b) 
{
    return (short) a!=(short) b;
}

INLINE(  uint,  UINT_CNEL)     (uint a,     uint b) {return a!=b;}
INLINE(   int,   INT_CNEL)      (int a,      int b) {return a!=b;}
INLINE( ulong, ULONG_CNEL)    (ulong a,    ulong b) {return a!=b;}
INLINE(  long,  LONG_CNEL)     (long a,     long b) {return a!=b;}
INLINE(ullong,ULLONG_CNEL)   (ullong a,   ullong b) {return a!=b;}
INLINE( llong, LLONG_CNEL)    (llong a,    llong b) {return a!=b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cnelqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  a!=b;
#else
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = ((p.Lo.U!=q.Lo.U) || (p.Hi.U!=q.Hi.U));
    c.Hi.U = 0;
    return  c.U;
#endif
}

INLINE(QUAD_ITYPE,cnelqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b};
    p.U = cnelqu(p.U, q.U);
    return  p.I;
}

#endif

#if 0 // _LEAVE_ALL_CNEL
}
#endif

#if 0 // _ENTER_ALL_CNES
{
#endif

INLINE(ptrdiff_t, ADDR_CNES) (void const *a, void const *b)
{
    return -(a!=b);
}

INLINE( uchar, UCHAR_CNES) (unsigned a, unsigned b) 
{
    return -((uchar) a!=(uchar) b);
}

INLINE( schar, SCHAR_CNES)   (signed a,   signed b) 
{
    return -((schar) a!=(schar) b);
}

INLINE(  char,  CHAR_CNES)      (int a,      int b) 
{
    return -((char) a!=(char) b);
}


INLINE(ushort, USHRT_CNES) (unsigned a, unsigned b) 
{
    return  -((ushort) a!=(ushort) b);
}

INLINE( short,  SHRT_CNES)   (signed a,   signed b) 
{
    return -((short) a!=(short) b);
}

INLINE(  uint,  UINT_CNES)     (uint a,     uint b) {return -(a!=b);}
INLINE(   int,   INT_CNES)      (int a,      int b) {return -(a!=b);}

INLINE( ulong, ULONG_CNES)    (ulong a,    ulong b) {return -(a!=b);}
INLINE(  long,  LONG_CNES)     (long a,     long b) {return -(a!=b);}

INLINE(ullong,ULLONG_CNES)   (ullong a,   ullong b) {return -(a!=b);}
INLINE( llong, LLONG_CNES)    (llong a,    llong b) {return -(a!=b);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cnesqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  -(a!=b);
#else
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.I = -((p.Lo.I^q.Lo.I) || (p.Hi.I^q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.U;
#endif
}

INLINE(QUAD_ITYPE,cnesqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  -(a!=b);
#else
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.I = -((p.Lo.I^q.Lo.I) || (p.Hi.I^q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.I;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CNES
}
#endif

#if 0 // _ENTER_ALL_CNEY
{
#endif

INLINE(_Bool, ADDR_CNEY) (void const *a, void const *b)
{
    return a!=b;
}

INLINE(_Bool,  BOOL_CNEY)    (_Bool a,    _Bool b) {return a!=b;}
INLINE(_Bool, UCHAR_CNEY) (unsigned a, unsigned b) 
{
    return (uchar) a!=(uchar) b;
}

INLINE(_Bool, SCHAR_CNEY)   (signed a,   signed b) 
{
    return (schar) a!=(schar) b;
}

INLINE(_Bool,  CHAR_CNEY)      (int a,      int b) 
{
    return (char) a!=(char) b;
}


INLINE(_Bool, USHRT_CNEY) (unsigned a, unsigned b) 
{
    return  (ushort) a!=(ushort) b;
}

INLINE(_Bool,  SHRT_CNEY)   (signed a,   signed b) 
{
    return (short) a!=(short) b;
}

INLINE(_Bool,  UINT_CNEY)     (uint a,     uint b) {return a!=b;}
INLINE(_Bool,   INT_CNEY)      (int a,      int b) {return a!=b;}
INLINE(_Bool, ULONG_CNEY)    (ulong a,    ulong b) {return a!=b;}
INLINE(_Bool,  LONG_CNEY)     (long a,     long b) {return a!=b;}
INLINE(_Bool,ULLONG_CNEY)   (ullong a,   ullong b) {return a!=b;}
INLINE(_Bool, LLONG_CNEY)    (llong a,    llong b) {return a!=b;}

#if QUAD_NLLONG == 2

INLINE(_Bool,cneyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  a != b;
#else
    QUAD_TYPE   p={.U=a}, q={.U=b};
    return  ((p.Lo.U!=q.Lo.U) || (p.Hi.U!=q.Hi.U));
#endif
}

INLINE(_Bool,cneyqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   x={.I=a}, y={.I=b};
    return  cneyqu(x.U, y.U);
}

#endif

#if 0 // _LEAVE_ALL_CNEY
}
#endif


#if 0 // _ENTER_ALL_CLTL
{
#endif

INLINE(ptrdiff_t, ADDR_CLTL) (void const *a, void const *b)
{
    return a<b;
}

INLINE(uchar, UCHAR_CLTL) (unsigned a, unsigned b) 
{
    return (uchar) a<(uchar) b;
}

INLINE(schar, SCHAR_CLTL)   (signed a,   signed b) 
{
    return (schar) a<(schar) b;
}

INLINE(char,  CHAR_CLTL)      (int a,      int b) 
{
    return (char) a<(char) b;
}


INLINE(ushort, USHRT_CLTL) (unsigned a, unsigned b) 
{
    return  (ushort) a<(ushort) b;
}

INLINE(short,  SHRT_CLTL)   (signed a,   signed b) 
{
    return (short) a<(short) b;
}

INLINE(uint,  UINT_CLTL)     (uint a,     uint b) {return a<b;}
INLINE(int,   INT_CLTL)      (int a,      int b) {return a<b;}
INLINE(ulong, ULONG_CLTL)    (ulong a,    ulong b) {return a<b;}
INLINE(long,  LONG_CLTL)     (long a,     long b) {return a<b;}
INLINE(ullong,ULLONG_CLTL)   (ullong a,   ullong b) {return a<b;}
INLINE(llong, LLONG_CLTL)    (llong a,    llong b) {return a<b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cltlqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = (p.Hi.U==q.Hi.U)?(p.Lo.U<q.Lo.U):(p.Hi.U<q.Hi.U);
    c.Hi.U = 0;
    return  c.U;
#else
    return a < b;
#endif
}

INLINE(QUAD_ITYPE,cltlqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.U = (p.Hi.U==q.Hi.U)?(p.Lo.U<q.Lo.U):(p.Hi.I<q.Hi.I);
    c.Hi.U = 0;
    return  c.I;
#else
    return a < b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CLTL
}
#endif

#if 0 // _ENTER_ALL_CLTS
{
#endif

INLINE(ptrdiff_t, ADDR_CLTS) (void const *a, void const *b)
{
    return -(a<b);
}

INLINE( uchar, UCHAR_CLTS) (unsigned a, unsigned b) 
{
    return -((uchar) a<(uchar) b);
}

INLINE( schar, SCHAR_CLTS)   (signed a,   signed b) 
{
    return -((schar) a<(schar) b);
}

INLINE(  char,  CHAR_CLTS)      (int a,      int b) 
{
    return -((char) a<(char) b);
}


INLINE(ushort, USHRT_CLTS) (unsigned a, unsigned b) 
{
    return  -((ushort) a<(ushort) b);
}

INLINE( short,  SHRT_CLTS)   (signed a,   signed b) 
{
    return -((short) a<(short) b);
}

INLINE(  uint,  UINT_CLTS)     (uint a,     uint b) {return -(a<b);}
INLINE(   int,   INT_CLTS)      (int a,      int b) {return -(a<b);}

INLINE( ulong, ULONG_CLTS)    (ulong a,    ulong b) {return -(a<b);}
INLINE(  long,  LONG_CLTS)     (long a,     long b) {return -(a<b);}

INLINE(ullong,ULLONG_CLTS)   (ullong a,   ullong b) {return -(a<b);}
INLINE( llong, LLONG_CLTS)    (llong a,    llong b) {return -(a<b);}

#if QUAD_NLLONG < 2


INLINE(QUAD_UTYPE,cltsqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U<q.Lo.U):(p.Hi.U<q.Hi.U));
    c.Hi.I = c.Lo.I;
    return  c.U;
}

INLINE(QUAD_ITYPE,cltsqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U<q.Lo.U):(p.Hi.I<q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.U;
}

#endif

#if 0 // _LEAVE_ALL_CLTS
}
#endif

#if 0 // _ENTER_ALL_CLTY
{
#endif

INLINE(_Bool, ADDR_CLTY) (void const *a, void const *b)
{
    return a<b;
}

INLINE(_Bool, BOOL_CLTY)     (_Bool a,    _Bool b) {return a<b;}
INLINE(_Bool, UCHAR_CLTY) (unsigned a, unsigned b) 
{
    return (uchar) a<(uchar) b;
}

INLINE(_Bool, SCHAR_CLTY)   (signed a,   signed b) 
{
    return (schar) a<(schar) b;
}

INLINE(_Bool,  CHAR_CLTY)      (int a,      int b) 
{
    return (char) a<(char) b;
}


INLINE(_Bool, USHRT_CLTY) (unsigned a, unsigned b) 
{
    return  (ushort) a<(ushort) b;
}

INLINE(_Bool,  SHRT_CLTY)   (signed a,   signed b) 
{
    return (short) a<(short) b;
}

INLINE(_Bool,  UINT_CLTY)     (uint a,     uint b) {return a<b;}
INLINE(_Bool,   INT_CLTY)      (int a,      int b) {return a<b;}
INLINE(_Bool, ULONG_CLTY)    (ulong a,    ulong b) {return a<b;}
INLINE(_Bool,  LONG_CLTY)     (long a,     long b) {return a<b;}
INLINE(_Bool,ULLONG_CLTY)   (ullong a,   ullong b) {return a<b;}
INLINE(_Bool, LLONG_CLTY)    (llong a,    llong b) {return a<b;}

#if QUAD_NLLONG == 2

INLINE(_Bool,cltyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = (p.Hi.U==q.Hi.U)?(p.Lo.U<q.Lo.U):(p.Hi.U<q.Hi.U);
    c.Hi.U = 0;
    return  c.U;
#else
    return a < b;
#endif
}

INLINE(_Bool,cltyqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.U = (p.Hi.U==q.Hi.U)?(p.Lo.U<q.Lo.U):(p.Hi.I<q.Hi.I);
    c.Hi.U = 0;
    return  c.I;
#else
    return a < b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CLTY
}
#endif


#if 0 // _ENTER_ALL_CLEL
{
#endif

INLINE(ptrdiff_t, ADDR_CLEL) (void const *a, void const *b)
{
    return a<=b;
}

INLINE(uchar, UCHAR_CLEL) (unsigned a, unsigned b) 
{
    return (uchar) a<=(uchar) b;
}

INLINE(schar, SCHAR_CLEL)   (signed a,   signed b) 
{
    return (schar) a<=(schar) b;
}

INLINE(char,  CHAR_CLEL)      (int a,      int b) 
{
    return (char) a<=(char) b;
}


INLINE(ushort, USHRT_CLEL) (unsigned a, unsigned b) 
{
    return  (ushort) a<=(ushort) b;
}

INLINE(short,  SHRT_CLEL)   (signed a,   signed b) 
{
    return (short) a<=(short) b;
}

INLINE(uint,  UINT_CLEL)     (uint a,     uint b) {return a<=b;}
INLINE(int,   INT_CLEL)      (int a,      int b) {return a<=b;}
INLINE(ulong, ULONG_CLEL)    (ulong a,    ulong b) {return a<=b;}
INLINE(long,  LONG_CLEL)     (long a,     long b) {return a<=b;}
INLINE(ullong,ULLONG_CLEL)   (ullong a,   ullong b) {return a<=b;}
INLINE(llong, LLONG_CLEL)    (llong a,    llong b) {return a<=b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,clelqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = (p.Hi.U==q.Lo.U)?(p.Lo.U<=q.Lo.U):(p.Hi.U<q.Hi.U);
    c.Hi.U = 0;
    return c.U;
#else
    return a <= b;
#endif
}

INLINE(_Bool,clelqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.U = (p.Hi.U==q.Lo.U)?(p.Lo.U<=q.Lo.U):(p.Hi.I<q.Hi.I);
    c.Hi.U = 0;
    return  c.I;
#else
    return a <= b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CLEL
}
#endif

#if 0 // _ENTER_ALL_CLES
{
#endif

INLINE(ptrdiff_t, ADDR_CLES) (void const *a, void const *b)
{
    return -(a<=b);
}

INLINE( uchar, UCHAR_CLES) (unsigned a, unsigned b) 
{
    return -((uchar) a<=(uchar) b);
}

INLINE( schar, SCHAR_CLES)   (signed a,   signed b) 
{
    return -((schar) a<=(schar) b);
}

INLINE(  char,  CHAR_CLES)      (int a,      int b) 
{
    return -((char) a<=(char) b);
}


INLINE(ushort, USHRT_CLES) (unsigned a, unsigned b) 
{
    return  -((ushort) a<=(ushort) b);
}

INLINE( short,  SHRT_CLES)   (signed a,   signed b) 
{
    return -((short) a<=(short) b);
}

INLINE(  uint,  UINT_CLES)     (uint a,     uint b) {return -(a<=b);}
INLINE(   int,   INT_CLES)      (int a,      int b) {return -(a<=b);}

INLINE( ulong, ULONG_CLES)    (ulong a,    ulong b) {return -(a<=b);}
INLINE(  long,  LONG_CLES)     (long a,     long b) {return -(a<=b);}

INLINE(ullong,ULLONG_CLES)   (ullong a,   ullong b) {return -(a<=b);}
INLINE( llong, LLONG_CLES)    (llong a,    llong b) {return -(a<=b);}

#if QUAD_NLLONG <= 2


INLINE(QUAD_UTYPE,clesqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U<=q.Lo.U):(p.Hi.U<q.Hi.U));
    c.Hi.I = c.Lo.I;
    return  c.U;
}

INLINE(QUAD_ITYPE,clesqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U<=q.Lo.U):(p.Hi.I<q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_CLES
}
#endif

#if 0 // _ENTER_ALL_CLEY
{
#endif

INLINE(_Bool, ADDR_CLEY) (void const *a, void const *b)
{
    return  a<=b;
}

INLINE(_Bool, UCHAR_CLEY) (unsigned a, unsigned b) 
{
    return  (uchar) a<=(uchar) b;
}

INLINE(_Bool, SCHAR_CLEY)   (signed a,   signed b) 
{
    return  (schar) a<=(schar) b;
}

INLINE(_Bool,  CHAR_CLEY)      (int a,      int b) 
{
    return  (char) a<=(char) b;
}


INLINE(_Bool, USHRT_CLEY) (unsigned a, unsigned b) 
{
    return  (ushort) a<=(ushort) b;
}

INLINE(_Bool,  SHRT_CLEY)   (signed a,   signed b) 
{
    return  (short) a<=(short) b;
}

INLINE(_Bool,  UINT_CLEY)     (uint a,     uint b) {return a<=b;}
INLINE(_Bool,   INT_CLEY)      (int a,      int b) {return a<=b;}
INLINE(_Bool, ULONG_CLEY)    (ulong a,    ulong b) {return a<=b;}
INLINE(_Bool,  LONG_CLEY)     (long a,     long b) {return a<=b;}
INLINE(_Bool,ULLONG_CLEY)   (ullong a,   ullong b) {return a<=b;}
INLINE(_Bool, LLONG_CLEY)    (llong a,    llong b) {return a<=b;}

#if QUAD_NLLONG == 2

INLINE(_Bool,cleyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b};
    return  (p.Hi.U==q.Lo.U) ? (p.Lo.U<=q.Lo.U) : (p.Hi.U<q.Hi.U);
#else
    return  a<=b;
#endif
}

INLINE(_Bool,cleyqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b};
    return  (p.Hi.U==q.Lo.U) ? (p.Lo.U<=q.Lo.U) : (p.Hi.I<q.Hi.I);
#else
    return  a<=b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CLEY
}
#endif


#if 0 // _ENTER_ALL_CGTL
{
#endif

INLINE(ptrdiff_t, ADDR_CGTL) (void const *a, void const *b)
{
    return a>b;
}

INLINE( uchar, UCHAR_CGTL) (unsigned a, unsigned b) 
{
    return (uchar) a>(uchar) b;
}

INLINE( schar, SCHAR_CGTL)   (signed a,   signed b) 
{
    return (schar) a>(schar) b;
}

INLINE(  char,  CHAR_CGTL)      (int a,      int b) 
{
    return (char) a>(char) b;
}


INLINE(ushort, USHRT_CGTL) (unsigned a, unsigned b) 
{
    return  (ushort) a>(ushort) b;
}

INLINE( short,  SHRT_CGTL)   (signed a,   signed b) 
{
    return (short) a>(short) b;
}

INLINE(  uint,  UINT_CGTL)     (uint a,     uint b) {return a>b;}
INLINE(   int,   INT_CGTL)      (int a,      int b) {return a>b;}
INLINE( ulong, ULONG_CGTL)    (ulong a,    ulong b) {return a>b;}
INLINE(  long,  LONG_CGTL)     (long a,     long b) {return a>b;}
INLINE(ullong,ULLONG_CGTL)   (ullong a,   ullong b) {return a>b;}
INLINE( llong, LLONG_CGTL)    (llong a,    llong b) {return a>b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cgtlqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return a > b;
#else
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = (p.Hi.U==q.Hi.U) ? (p.Lo.U>q.Lo.U) : (p.Hi.U>q.Hi.U);
    c.Hi.U = 0;
    return  c.U;
#endif
}

INLINE(QUAD_ITYPE,cgtlqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    return a > b;
#else
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.U = (p.Hi.U==q.Hi.U) ? (p.Lo.U>q.Lo.U) : (p.Hi.I>q.Hi.I);
    c.Hi.U = 0;
    return  c.I;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CGTL
}
#endif

#if 0 // _ENTER_ALL_CGTS
{
#endif

INLINE(ptrdiff_t, ADDR_CGTS) (void const *a, void const *b)
{
    return -(a>b);
}

INLINE( uchar, UCHAR_CGTS) (unsigned a, unsigned b) 
{
    return -((uchar) a>(uchar) b);
}

INLINE( schar, SCHAR_CGTS)   (signed a,   signed b) 
{
    return -((schar) a>(schar) b);
}

INLINE(  char,  CHAR_CGTS)      (int a,      int b) 
{
    return -((char) a>(char) b);
}


INLINE(ushort, USHRT_CGTS) (unsigned a, unsigned b) 
{
    return  -((ushort) a>(ushort) b);
}

INLINE( short,  SHRT_CGTS)   (signed a,   signed b) 
{
    return -((short) a>(short) b);
}

INLINE(  uint,  UINT_CGTS)     (uint a,     uint b) {return -(a>b);}
INLINE(   int,   INT_CGTS)      (int a,      int b) {return -(a>b);}

INLINE( ulong, ULONG_CGTS)    (ulong a,    ulong b) {return -(a>b);}
INLINE(  long,  LONG_CGTS)     (long a,     long b) {return -(a>b);}

INLINE(ullong,ULLONG_CGTS)   (ullong a,   ullong b) {return -(a>b);}
INLINE( llong, LLONG_CGTS)    (llong a,    llong b) {return -(a>b);}

#if QUAD_NLLONG > 2

INLINE(QUAD_UTYPE,cgtsqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U>q.Lo.U):(p.Hi.U>q.Hi.U));
    c.Hi.I = c.Lo.I;
    return  c.U;
}

INLINE(QUAD_ITYPE,cgtsqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U>q.Lo.U):(p.Hi.I>q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_CGTS
}
#endif

#if 0 // _ENTER_ALL_CGTY
{
#endif

INLINE(_Bool, ADDR_CGTY) (void const *a, void const *b)
{
    return a>b;
}

INLINE(_Bool, BOOL_CGTY)     (_Bool a,    _Bool b) {return a>b;}
INLINE(_Bool, UCHAR_CGTY) (unsigned a, unsigned b) 
{
    return (uchar) a>(uchar) b;
}

INLINE(_Bool, SCHAR_CGTY)   (signed a,   signed b) 
{
    return (schar) a>(schar) b;
}

INLINE(_Bool,  CHAR_CGTY)      (int a,      int b) 
{
    return (char) a>(char) b;
}


INLINE(_Bool, USHRT_CGTY) (unsigned a, unsigned b) 
{
    return  (ushort) a>(ushort) b;
}

INLINE(_Bool,  SHRT_CGTY)   (signed a,   signed b) 
{
    return (short) a>(short) b;
}

INLINE(_Bool,  UINT_CGTY)     (uint a,     uint b) {return a>b;}
INLINE(_Bool,   INT_CGTY)      (int a,      int b) {return a>b;}
INLINE(_Bool, ULONG_CGTY)    (ulong a,    ulong b) {return a>b;}
INLINE(_Bool,  LONG_CGTY)     (long a,     long b) {return a>b;}
INLINE(_Bool,ULLONG_CGTY)   (ullong a,   ullong b) {return a>b;}
INLINE(_Bool, LLONG_CGTY)    (llong a,    llong b) {return a>b;}

#if QUAD_NLLONG == 2

INLINE(_Bool,cgtyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return a>b;
#else
    QUAD_TYPE   p={.U=a}, q={.U=b};
    return  (p.Hi.U==q.Hi.U) ? (p.Lo.U>q.Lo.U) : (p.Hi.U>q.Hi.U);
#endif
}

INLINE(_Bool,cgtyqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    return a>b;
#else
    QUAD_TYPE   p={.I=a}, q={.I=b};
    return  (p.Hi.U == q.Hi.U) ? (p.Lo.U>q.Lo.U) : (p.Hi.I>q.Hi.I);
#endif
}

#endif

#if 0 // _LEAVE_ALL_CGTY
}
#endif


#if 0 // _ENTER_ALL_CGEL
{
#endif

INLINE(ptrdiff_t, ADDR_CGEL) (void const *a, void const *b)
{
    return a>=b;
}

INLINE(uchar, UCHAR_CGEL) (unsigned a, unsigned b) 
{
    return (uchar) a>=(uchar) b;
}

INLINE(schar, SCHAR_CGEL)   (signed a,   signed b) 
{
    return (schar) a>=(schar) b;
}

INLINE(char,  CHAR_CGEL)      (int a,      int b) 
{
    return (char) a>=(char) b;
}


INLINE(ushort, USHRT_CGEL) (unsigned a, unsigned b) 
{
    return  (ushort) a>=(ushort) b;
}

INLINE(short,  SHRT_CGEL)   (signed a,   signed b) 
{
    return (short) a>=(short) b;
}

INLINE(uint,  UINT_CGEL)     (uint a,     uint b) {return a>=b;}
INLINE(int,   INT_CGEL)      (int a,      int b) {return a>=b;}
INLINE(ulong, ULONG_CGEL)    (ulong a,    ulong b) {return a>=b;}
INLINE(long,  LONG_CGEL)     (long a,     long b) {return a>=b;}
INLINE(ullong,ULLONG_CGEL)   (ullong a,   ullong b) {return a>=b;}
INLINE(llong, LLONG_CGEL)    (llong a,    llong b) {return a>=b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cgelqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.U = (p.Hi.U==q.Lo.U)?(p.Lo.U>=q.Lo.U):(p.Hi.U>q.Hi.U);
    c.Hi.U = 0;
    return  c.U;
#else
    return a >= b;
#endif
}

INLINE(QUAD_ITYPE,cgelqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.U = (p.Hi.U==q.Lo.U)?(p.Lo.U>=q.Lo.U):(p.Hi.I>q.Hi.I);
    c.Hi.U = 0;
    return  c.U;
#else
    return  a >= b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CGEL
}
#endif

#if 0 // _ENTER_ALL_CGES
{
#endif

INLINE(ptrdiff_t, ADDR_CGES) (void const *a, void const *b)
{
    return -(a>=b);
}

INLINE( uchar, UCHAR_CGES) (unsigned a, unsigned b) 
{
    return -((uchar) a>=(uchar) b);
}

INLINE( schar, SCHAR_CGES)   (signed a,   signed b) 
{
    return -((schar) a>=(schar) b);
}

INLINE(  char,  CHAR_CGES)      (int a,      int b) 
{
    return -((char) a>=(char) b);
}


INLINE(ushort, USHRT_CGES) (unsigned a, unsigned b) 
{
    return  -((ushort) a>=(ushort) b);
}

INLINE( short,  SHRT_CGES)   (signed a,   signed b) 
{
    return -((short) a>=(short) b);
}

INLINE(  uint,  UINT_CGES)     (uint a,     uint b) {return -(a>=b);}
INLINE(   int,   INT_CGES)      (int a,      int b) {return -(a>=b);}

INLINE( ulong, ULONG_CGES)    (ulong a,    ulong b) {return -(a>=b);}
INLINE(  long,  LONG_CGES)     (long a,     long b) {return -(a>=b);}

INLINE(ullong,ULLONG_CGES)   (ullong a,   ullong b) {return -(a>=b);}
INLINE( llong, LLONG_CGES)    (llong a,    llong b) {return -(a>=b);}

#if QUAD_NLLONG >= 2


INLINE(QUAD_UTYPE,cgesqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE   p={.U=a}, q={.U=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U>=q.Lo.U):(p.Hi.U>q.Hi.U));
    c.Hi.I = c.Lo.I;
    return  c.U;
}

INLINE(QUAD_ITYPE,cgesqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE   p={.I=a}, q={.I=b}, c;
    c.Lo.I = -((p.Hi.U==q.Hi.U)?(p.Lo.U>=q.Lo.U):(p.Hi.I>q.Hi.I));
    c.Hi.I = c.Lo.I;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_CGES
}
#endif

#if 0 // _ENTER_ALL_CGEY
{
#endif

INLINE(_Bool, ADDR_CGEY) (void const *a, void const *b)
{
    return a>=b;
}

INLINE(_Bool, UCHAR_CGEY) (unsigned a, unsigned b) 
{
    return (uchar) a>=(uchar) b;
}

INLINE(_Bool, SCHAR_CGEY)   (signed a,   signed b) 
{
    return (schar) a>=(schar) b;
}

INLINE(_Bool,  CHAR_CGEY)      (int a,      int b) 
{
    return (char) a>=(char) b;
}


INLINE(_Bool, USHRT_CGEY) (unsigned a, unsigned b) 
{
    return  (ushort) a>=(ushort) b;
}

INLINE(_Bool,  SHRT_CGEY)   (signed a,   signed b) 
{
    return (short) a>=(short) b;
}

INLINE(_Bool,  UINT_CGEY)     (uint a,     uint b) {return a>=b;}
INLINE(_Bool,   INT_CGEY)      (int a,      int b) {return a>=b;}
INLINE(_Bool, ULONG_CGEY)    (ulong a,    ulong b) {return a>=b;}
INLINE(_Bool,  LONG_CGEY)     (long a,     long b) {return a>=b;}
INLINE(_Bool,ULLONG_CGEY)   (ullong a,   ullong b) {return a>=b;}
INLINE(_Bool, LLONG_CGEY)    (llong a,    llong b) {return a>=b;}

#if QUAD_NLLONG == 2

INLINE(_Bool,cgeyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
#if 1
    QUAD_TYPE   p={.U=a}, q={.U=b};
    return  (p.Hi.U==q.Lo.U)?(p.Lo.U>=q.Lo.U):(p.Hi.U>q.Hi.U);
#else
    return a >= b;
#endif
}

INLINE(_Bool,cgeyqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#if 1
    QUAD_TYPE   p={.I=a}, q={.I=b};
    return  (p.Hi.U==q.Lo.U)?(p.Lo.U>=q.Lo.U):(p.Hi.I>q.Hi.I);
#else
    return  a >= b;
#endif
}

#endif

#if 0 // _LEAVE_ALL_CGEY
}
#endif


#if 0 // _ENTER_ALL_ZEQY
{
#endif

INLINE(ptrdiff_t,ADDR_ZEQY) (void volatile const *a)
{
    return  (NULL==a);
}

INLINE(_Bool,  BOOL_ZEQY)    (_Bool a) {return !a;}
INLINE(_Bool, UCHAR_ZEQY) (unsigned a) {return !((uchar) a);}
INLINE(_Bool, SCHAR_ZEQY)   (signed a) {return !((schar) a);}
INLINE(_Bool,  CHAR_ZEQY)      (int a) {return !((char) a);}
INLINE(_Bool, USHRT_ZEQY) (unsigned a) {return !((ushort) a);}
INLINE(_Bool,  SHRT_ZEQY)   (signed a) {return !((short) a);}
INLINE(_Bool,  UINT_ZEQY)     (uint a) {return !a;}
INLINE(_Bool,   INT_ZEQY)      (int a) {return !a;}
INLINE(_Bool, ULONG_ZEQY)    (ulong a) {return !a;}
INLINE(_Bool,  LONG_ZEQY)     (long a) {return !a;}
INLINE(_Bool,ULLONG_ZEQY)   (ullong a) {return !a;}
INLINE(_Bool, LLONG_ZEQY)    (llong a) {return !a;}

#if QUAD_NLLONG == 2

INLINE(_Bool,zeqyqu) (QUAD_UTYPE x)
{
#if 0
    QUAD_TYPE c = {.U=x};
    return !(c.Lo.U|c.Hi.U);
#else
    return 0 == x;
#endif
}

INLINE(_Bool,zeqyqi) (QUAD_ITYPE x)
{
#if 0
    QUAD_TYPE c = {.I=x};
    return !(c.Lo.I|c.Hi.I);
#else
    return 0 == x;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ZEQY
}
#endif

#if 0 // _ENTER_ALL_ZEQS
{
#endif

INLINE(ptrdiff_t,ADDR_ZEQS) (void volatile const *a)
{
    return  a ? 0 : -1;
}

INLINE(  uchar, UCHAR_ZEQS) (unsigned a) {return -!((uchar) a);}
INLINE(  schar, SCHAR_ZEQS)   (signed a) {return -!((schar) a);}
INLINE(   char,  CHAR_ZEQS)      (int a) {return -!((char) a);}
INLINE( ushort, USHRT_ZEQS) (unsigned a) {return -!((ushort) a);}
INLINE(  short,  SHRT_ZEQS)   (signed a) {return -!((short) a);}
INLINE(   uint,  UINT_ZEQS)     (uint a) {return -!a;}
INLINE(    int,   INT_ZEQS)      (int a) {return -!a;}
INLINE(  ulong, ULONG_ZEQS)    (ulong a) {return -!a;}
INLINE(   long,  LONG_ZEQS)     (long a) {return -!a;}
INLINE( ullong,ULLONG_ZEQS)   (ullong a) {return -!a;}
INLINE(  llong, LLONG_ZEQS)    (llong a) {return -!a;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,zeqsqu) (QUAD_UTYPE x)
{
    QUAD_TYPE   c = {.U=x};
    int64_t     z = -!(c.Lo.U|c.Hi.U);
    return ((QUAD_TYPE){.Lo.I=z, .Hi.I=z}).U;
}

INLINE(QUAD_ITYPE,zeqsqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   c = {.I=x};
    int64_t     z = -!(c.Lo.U|c.Hi.U);
    return ((QUAD_TYPE){.Lo.I=z, .Hi.I=z}).I;
}

#endif

#if 0 // _LEAVE_ALL_ZEQS
}
#endif

#if 0 // _ENTER_ALL_ZNEY
{
#endif

INLINE(_Bool, ADDR_ZNEY) (void const *x)
{
    return x!=NULL;
}

INLINE(_Bool,  BOOL_ZNEY)    (_Bool x) {return x;}
INLINE(_Bool, UCHAR_ZNEY) (unsigned x) {return  (uchar) x;}
INLINE(_Bool, SCHAR_ZNEY)   (signed x) {return  (schar) x;}
INLINE(_Bool,  CHAR_ZNEY)      (int x) {return   (char) x;}
INLINE(_Bool, USHRT_ZNEY) (unsigned x) {return (ushort) x;}
INLINE(_Bool,  SHRT_ZNEY)   (signed x) {return  (short) x;}
INLINE(_Bool,  UINT_ZNEY)     (uint x) {return x;}
INLINE(_Bool,   INT_ZNEY)      (int x) {return x;}
INLINE(_Bool, ULONG_ZNEY)    (ulong x) {return x;}
INLINE(_Bool,  LONG_ZNEY)     (long x) {return x;}
INLINE(_Bool,ULLONG_ZNEY)   (ullong x) {return x;}
INLINE(_Bool, LLONG_ZNEY)    (llong x) {return x;}


#if QUAD_NLLONG == 2

INLINE(_Bool,zneyqu) (QUAD_UTYPE x)
{
#if 1
    QUAD_TYPE c = {.U=x};
    return  c.Lo.U||c.Hi.U;
#else
    return 0 != x;
#endif
}

INLINE(_Bool,zneyqi) (QUAD_ITYPE x)
{
#if 1
    QUAD_TYPE c = {.I=x};
    return  c.Lo.U||c.Hi.U;
#else
    return 0 != x;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ZNEY
}
#endif

#if 0 // _ENTER_ALL_ZNES
{
#endif

INLINE(ptrdiff_t, ADDR_ZNES) (void volatile const *a)
{
    return a!=NULL;
}

INLINE( uchar, UCHAR_ZNES) (unsigned a) {return  (uchar) a?-1:0;}
INLINE( schar, SCHAR_ZNES)   (signed a) {return  (schar) a?-1:0;}
INLINE(  char,  CHAR_ZNES)      (int a) {return   (char) a?-1:0;}
INLINE(ushort, USHRT_ZNES) (unsigned a) {return (ushort) a?-1:0;}
INLINE( short,  SHRT_ZNES)   (signed a) {return  (short) a?-1:0;}
INLINE(  uint,  UINT_ZNES)     (uint a) {return          a?-1:0;}
INLINE(   int,   INT_ZNES)      (int a) {return          a?-1:0;}
INLINE( ulong, ULONG_ZNES)    (ulong a) {return          a?-1:0;}
INLINE(  long,  LONG_ZNES)     (long a) {return          a?-1:0;}
INLINE(ullong,ULLONG_ZNES)   (ullong a) {return          a?-1:0;}
INLINE( llong, LLONG_ZNES)    (llong a) {return          a?-1:0;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,znesqu) (QUAD_UTYPE x)
{
    QUAD_TYPE   c = {.U=x};
    int64_t     z = -(c.Lo.U||c.Hi.U);
    return ((QUAD_TYPE){.Lo.I=z, .Hi.I=z}).U;
}

INLINE(QUAD_ITYPE,znesqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   c = {.I=x};
    int64_t     z = -(c.Lo.U||c.Hi.U);
    return ((QUAD_TYPE){.Lo.I=z, .Hi.I=z}).I;
}

#endif

#if 0 // _LEAVE_ALL_ZNES
}
#endif

#if 0 // _ENTER_ALL_ZLTY
{
#endif

INLINE(_Bool, ADDR_ZLTY) (void volatile const *a)
{
    return NULL<a;
}

INLINE(_Bool, UCHAR_ZLTY) (unsigned a) {return  0 <  (uchar) a;}
INLINE(_Bool, SCHAR_ZLTY)   (signed a) {return  0 <  (schar) a;}
INLINE(_Bool,  CHAR_ZLTY)      (int a) {return  0 <   (char) a;}
INLINE(_Bool, USHRT_ZLTY) (unsigned a) {return  0 < (ushort) a;}
INLINE(_Bool,  SHRT_ZLTY)   (signed a) {return  0 <  (short) a;}
INLINE(_Bool,  UINT_ZLTY)     (uint a) {return  0 < a;}
INLINE(_Bool,   INT_ZLTY)      (int a) {return  0 < a;}
INLINE(_Bool, ULONG_ZLTY)    (ulong a) {return  0 < a;}
INLINE(_Bool,  LONG_ZLTY)     (long a) {return  0 < a;}
INLINE(_Bool,ULLONG_ZLTY)   (ullong a) {return  0 < a;}
INLINE(_Bool, LLONG_ZLTY)    (llong a) {return  0 < a;}

#if QUAD_NLLONG == 2

INLINE(_Bool,zltyqu) (QUAD_UTYPE x)
{
#if 1
    QUAD_TYPE   c = {.U=x};
    return  c.Lo.U||c.Hi.U;
#else
    return 0 < x;
#endif
}

INLINE(_Bool,zltyqi) (QUAD_ITYPE x)
{
#if 1
    QUAD_TYPE   c = {.I=x};
    return (c.Hi.I >= 0) && (c.Hi.U||c.Lo.U);
#else
    return 0 < x;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ZLTY
}
#endif

#if 0 // _ENTER_ALL_ZLTS
{
#endif

INLINE(ptrdiff_t, ADDR_ZLTS) (void volatile const *a)
{
    return -(NULL<a);
}

INLINE( uchar, UCHAR_ZLTS) (unsigned a) {return  -(0 <  (uchar) a);}
INLINE( schar, SCHAR_ZLTS)   (signed a) {return  -(0 <  (schar) a);}
INLINE(  char,  CHAR_ZLTS)      (int a) {return  -(0 <   (char) a);}
INLINE(ushort, USHRT_ZLTS) (unsigned a) {return  -(0 < (ushort) a);}
INLINE( short,  SHRT_ZLTS)   (signed a) {return  -(0 <  (short) a);}
INLINE(  uint,  UINT_ZLTS)     (uint a) {return  -(0 < a);}
INLINE(   int,   INT_ZLTS)      (int a) {return  -(0 < a);}
INLINE( ulong, ULONG_ZLTS)    (ulong a) {return  -(0 < a);}
INLINE(  long,  LONG_ZLTS)     (long a) {return  -(0 < a);}
INLINE(ullong,ULLONG_ZLTS)   (ullong a) {return  -(0 < a);}
INLINE( llong, LLONG_ZLTS)    (llong a) {return  -(0 < a);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,zltsqu) (QUAD_UTYPE x)
{
    QUAD_TYPE   c = {.U=x};
    int64_t     z = -(c.Lo.U||c.Hi.U);
    return  ((QUAD_TYPE){.Lo.I=z, .Hi.I=z}).U;
}

INLINE(QUAD_ITYPE,zltsqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   c = {.I=x};
    int64_t     z = (c.Hi.U>>63) ? 0 : -(c.Hi.U||c.Lo.U);
    return  ((QUAD_TYPE){.Lo.I=z, .Hi.I=z}).I;
}

#endif

#if 0 // _LEAVE_ALL_ZLTS
}
#endif

#if 0 // _ENTER_ALL_ZLEY
{
#endif

INLINE(_Bool, ADDR_ZLEY) (void const *x)
{
    return  NULL<=x;
}

INLINE(_Bool,SCHAR_ZLEY) (signed x) {return 0 <= (schar) x;}
INLINE(_Bool, CHAR_ZLEY)    (int x) 
{
#if CHAR_MIN
    return  0 <= (char) x;
#else
    return  1;
#endif
}

INLINE(_Bool, SHRT_ZLEY) (signed x) {return 0 <= (short) x;}
INLINE(_Bool,  INT_ZLEY)    (int x) {return 0 <= x;}
INLINE(_Bool, LONG_ZLEY)   (long x) {return 0 <= x;}
INLINE(_Bool,LLONG_ZLEY)  (llong x) {return 0 <= x;}

#if QUAD_NLLONG == 2

INLINE(_Bool,zleyqi) (QUAD_ITYPE x)
{
#if 1
    QUAD_TYPE   c = {.I=x};
    return (c.Hi.I >= 0);
    //return (c.Hi.I < 0) || (0 == (c.Hi.U|c.Lo.U));
#else
    return 0 <= x;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ZLEY
}
#endif

#if 0 // _ENTER_ALL_ZLES
{
#endif

INLINE(ptrdiff_t, ADDR_ZLES) (void volatile const *x) {return -(NULL<=x);}
INLINE( schar, SCHAR_ZLES) (signed x) {return -(0<=(schar) x);}

INLINE(  char,  CHAR_ZLES)    (int x) 
{
#if CHAR_MIN
    return  -(0<=(char) x);
#else
    return  -1;
#endif
}

INLINE( short,  SHRT_ZLES) (signed x) {return -(0<=(short) x);}

INLINE(   int,   INT_ZLES)    (int x) {return -(0<=x);}

INLINE(  long,  LONG_ZLES)   (long x) {return -(0<=x);}

INLINE( llong, LLONG_ZLES)  (llong x) {return -(0<=x);}

#if QUAD_NLLONG == 2

INLINE(QUAD_ITYPE,zlesqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   c = {.I=x};
    QUAD_TYPE   r;
    r.Lo.U = (c.Hi.U>>63) ? 0 : -1;
    r.Hi.U = r.Lo.U;
    return  r.I;
}

#endif

#if 0 // _LEAVE_ALL_ZLES
}
#endif

#if 0 // _ENTER_ALL_ZGTY
{
#endif

INLINE(_Bool,SCHAR_ZGTY) (signed x) {return 0 > (schar) x;}
INLINE(_Bool, CHAR_ZGTY)    (int x) 
{
#if CHAR_MIN
    return  0 > (char) x;
#else
    return  0;
#endif
}

INLINE(_Bool, SHRT_ZGTY) (signed x) {return 0 > (short) x;}
INLINE(_Bool,  INT_ZGTY)    (int x) {return 0 > x;}
INLINE(_Bool, LONG_ZGTY)   (long x) {return 0 > x;}
INLINE(_Bool,LLONG_ZGTY)  (llong x) {return 0 > x;}

#if QUAD_NLLONG == 2

INLINE(_Bool,zgtyqi) (QUAD_ITYPE x)
{
#if defined(__SIZEOF_INT128__)
    return  0 > x;
#else
    QUAD_TYPE   c = {.I=x};
    return  0 > c.Hi.I;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ZGTY
}
#endif

#if 0 // _ENTER_ALL_ZGTS
{
#endif

INLINE(schar,SCHAR_ZGTS) (signed x) {return -(0 > (schar) x);}
INLINE( char, CHAR_ZGTS)    (int x) 
{
#if CHAR_MIN
    return  0 >   (char) x;
#else
    return  0;
#endif
}

INLINE(short, SHRT_ZGTS) (signed x) {return -(0 > (short) x);}
INLINE(  int,  INT_ZGTS)    (int x) {return -(0 > x);}
INLINE( long, LONG_ZGTS)   (long x) {return -(0 > x);}
INLINE(llong,LLONG_ZGTS)  (llong x) {return -(0 > x);}

#if QUAD_NLLONG == 2

INLINE(QUAD_ITYPE,zgtsqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   c = {.I=x};
    c.Hi.I >>= 63;
    c.Lo.I = c.Hi.I;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_ZGTS
}
#endif

#if 0 // _ENTER_ALL_ZGEY
{
#endif

INLINE(_Bool,SCHAR_ZGEY) (signed x) {return 0 >= (schar) x;}
INLINE(_Bool, CHAR_ZGEY)    (int x) {return 0 >=  (char) x;}
INLINE(_Bool, SHRT_ZGEY) (signed x) {return 0 >= (short) x;}
INLINE(_Bool,  INT_ZGEY)    (int x) {return 0 >= x;}
INLINE(_Bool, LONG_ZGEY)   (long x) {return 0 >= x;}
INLINE(_Bool,LLONG_ZGEY)  (llong x) {return 0 >= x;}

#if QUAD_NLLONG == 2

INLINE(_Bool,zgeyqi) (QUAD_ITYPE x)
{
#if 1
    QUAD_TYPE   c={.I=x};
    return (c.Hi.I < 0) || (!(c.Lo.U|c.Hi.U));
#else
    return 0 >= x;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ZGEY
}
#endif

#if 0 // _ENTER_ALL_ZGES
{
#endif

INLINE(schar,SCHAR_ZGES) (signed x) {return -(0 >= (schar) x);}
INLINE( char, CHAR_ZGES)    (int x) {return -(0 >=  (char) x);}
INLINE(short, SHRT_ZGES) (signed x) {return -(0 >= (short) x);}
INLINE(  int,  INT_ZGES)    (int x) {return -(0 >= x);}
INLINE( long, LONG_ZGES)   (long x) {return -(0 >= x);}
INLINE(llong,LLONG_ZGES)  (llong x) {return -(0 >= x);}

#if QUAD_NLLONG == 2

INLINE(QUAD_ITYPE,zgesqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   c={.I=x};
    if (c.Lo.U || c.Hi.U)
        c.Lo.I >>= 63;
    else 
        c.Lo.I = -1;
    c.Hi.I = c.Lo.I;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_ZGES
}
#endif

#if 0 // _ENTER_ALL_TSTS
{
#endif

INLINE( uchar, UCHAR_TSTS) (unsigned a, unsigned b) 
{
    return  ((uchar) (a&b)) ? -1 : 0;
}

INLINE( schar, SCHAR_TSTS)   (signed a, unsigned b) 
{
    return  ((uchar) (a&b)) ? -1 : 0;
}

INLINE(  char,  CHAR_TSTS)      (int a, unsigned b) 
{
    return  ((uchar) (a&b)) ? -1 : 0;
}


INLINE(ushort, USHRT_TSTS) (unsigned a, unsigned b) 
{
    return  ((ushort) (a&b)) ? -1 : 0;
}

INLINE( short,  SHRT_TSTS)   (signed a, unsigned b) 
{
    return  ((ushort) (a&b)) ? -1 : 0;
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


#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,tstsqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE p={.U=a}, q={.U=b};
    p.Lo.I = -((p.Lo.U&q.Lo.U) || (p.Hi.U&q.Hi.U));
    p.Hi.I = p.Lo.I;
    return  p.U;
}

INLINE(QUAD_ITYPE,tstsqi) (QUAD_ITYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE p={.I=a}, q={.U=b};
    p.Lo.I = -((p.Lo.U&q.Lo.U) || (p.Hi.U&q.Hi.U));
    p.Hi.I = p.Lo.I;
    return  p.I;
}

#endif

#if 0 // _LEAVE_ALL_TSTS
}
#endif

#if 0 // _ENTER_ALL_TSTY
{
#endif

INLINE(_Bool, ADDR_TSTY) (void const *a, uintptr_t b)
{
    return b&(uintptr_t) a;
}
INLINE(_Bool, UCHAR_TSTY) (unsigned a, unsigned b) {return (uchar) a&b;}
INLINE(_Bool, SCHAR_TSTY)   (signed a, unsigned b) {return (uchar) a&b;}
INLINE(_Bool,  CHAR_TSTY)      (int a, unsigned b) {return (uchar) a&b;}
INLINE(_Bool, USHRT_TSTY) (unsigned a, unsigned b) {return (ushort) a&b;}
INLINE(_Bool,  SHRT_TSTY)   (signed a, unsigned b) {return (ushort) a&b;}
INLINE(_Bool,  UINT_TSTY)     (uint a,     uint b) {return a&b;}
INLINE(_Bool,   INT_TSTY)      (int a,     uint b) {return a&b;}
INLINE(_Bool, ULONG_TSTY)    (ulong a,    ulong b) {return a&b;}
INLINE(_Bool,  LONG_TSTY)     (long a,    ulong b) {return a&b;}
INLINE(_Bool,ULLONG_TSTY)   (ullong a,   ullong b) {return a&b;}
INLINE(_Bool, LLONG_TSTY)    (llong a,   ullong b) {return a&b;}

#if QUAD_NLLONG == 2
INLINE(_Bool,tstyqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE p={.U=a}, q={.U=b};
    return (p.Lo.U&q.Lo.U)|(p.Hi.U|q.Hi.U);
}

INLINE(_Bool,tstyqi) (QUAD_ITYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE p={.I=a}, q={.U=b};
    return ((p.Lo.U&q.Lo.U) || (p.Hi.U&q.Hi.U));
}

#endif

#if 0 // _LEAVE_ALL_TSTY
}
#endif


#if 0 // _ENTER_ALL_SUNN
{
#endif

INLINE(  _Bool,  BOOL_SUNNA) (void *dst,    _Bool src)
{
    return  (((_Bool *) dst)[0]=src);
}


INLINE(  uchar, UCHAR_SUNNA) (void *dst, unsigned src)
{
    return  (((uchar *) dst)[0]=src);
}

INLINE(  schar, SCHAR_SUNNA) (void *dst,   signed src)
{
    return  (((schar *) dst)[0]=src);
}

INLINE(   char,  CHAR_SUNNA) (void *dst,      int src)
{
    return  (((char *) dst)[0]=src);
}


INLINE( ushort, USHRT_SUNNA) (void *dst, unsigned src)
{
    return  (((HALF_TYPE *) dst)->M.U=src);
}

INLINE(  short,  SHRT_SUNNA) (void *dst,   signed src)
{
    return  (((HALF_TYPE *) dst)->M.I=src);
}


INLINE(   uint,  UINT_SUNNA) (void *dst,     uint src)
{
    return  (((WORD_TYPE *) dst)->M.U=src);
}

INLINE(    int,   INT_SUNNA) (void *dst,      int src)
{
    return  (((WORD_TYPE *) dst)->M.I=src);
}


INLINE(  ulong, ULONG_SUNNA) (void *dst,    ulong src)
{
#if DWRD_NLONG == 2
    return  (((WORD_TYPE *) dst)->M.U=src);
#else
    return  (((DWRD_TYPE *) dst)->M.U=src);
#endif
}

INLINE(   long,  LONG_SUNNA) (void *dst,     long src)
{
#if DWRD_NLONG == 2
    return  (((WORD_TYPE *) dst)->M.I=src);
#else
    return  (((DWRD_TYPE *) dst)->M.I=src);
#endif
}

#if QUAD_NLLONG == 2

INLINE( ullong,ULLONG_SUNNA) (void *dst,   ullong src)
{
    return  (((DWRD_TYPE *) dst)->M.U=src);
}

INLINE(  llong, LLONG_SUNNA) (void *dst,    llong src)
{
    return  (((DWRD_TYPE *) dst)->M.I=src);
}

INLINE(QUAD_UTYPE,sunnaqu) (void *dst, QUAD_UTYPE src)
{
    return  (((QUAD_TYPE *) dst)->M.U=src);
}

INLINE(QUAD_ITYPE,sunnaqi) (void *dst, QUAD_ITYPE src)
{
    return  (((QUAD_TYPE *) dst)->M.U=src);
}

#else

INLINE( ullong,ULLONG_SUNNA) (void *dst,   ullong src)
{
    return  (((QUAD_TYPE *) dst)->M.U=src);
}

INLINE(  llong, LLONG_SUNNA) (void *dst,    llong src)
{
    return  (((QUAD_TYPE *) dst)->M.I=src);
}

#endif

#if 0 // _LEAVE_ALL_SUNN
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

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,invsqu) (QUAD_UTYPE a)
{
    QUAD_TYPE z = {.U=a};
    z.Lo.U = ~z.Lo.U;
    z.Hi.U = ~z.Hi.U;
    return  z.U;
}

INLINE(QUAD_ITYPE,invsqi) (QUAD_ITYPE a)
{
    QUAD_TYPE z = {.I=a};
    z.Lo.U = ~z.Lo.U;
    z.Hi.U = ~z.Hi.U;
    return  z.I;
}
#endif

#if 0 // _LEAVE_ALL_INVS
}
#endif


#if 0 // _ENTER_ALL_ANDS
{
#endif

INLINE(  _Bool,  BOOL_ANDS)    (_Bool a,    _Bool b) {return a&b;}
INLINE(  uchar, UCHAR_ANDS) (unsigned a, unsigned b) {return a&b;}
INLINE(  schar, SCHAR_ANDS)   (signed a,   signed b) {return a&b;}
INLINE(   char,  CHAR_ANDS)      (int a,      int b) {return a&b;}
INLINE( ushort, USHRT_ANDS) (unsigned a, unsigned b) {return a&b;}
INLINE(  short,  SHRT_ANDS)   (signed a,   signed b) {return a&b;}
INLINE(   uint,  UINT_ANDS)     (uint a,     uint b) {return a&b;}
INLINE(    int,   INT_ANDS)      (int a,      int b) {return a&b;}
INLINE(  ulong, ULONG_ANDS)    (ulong a,    ulong b) {return a&b;}
INLINE(   long,  LONG_ANDS)     (long a,     long b) {return a&b;}
INLINE( ullong,ULLONG_ANDS)   (ullong a,   ullong b) {return a&b;}
INLINE(  llong, LLONG_ANDS)    (llong a,    llong b) {return a&b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,andsqu) (QUAD_UTYPE a,QUAD_UTYPE b) 
{
    QUAD_TYPE l={.U=a}, r={.U=b};
    l.Lo.U &= r.Lo.U;
    l.Hi.U &= r.Hi.U;
    return  l.U;
}

INLINE(QUAD_ITYPE,andsqi) (QUAD_ITYPE a,QUAD_ITYPE b) 
{
    QUAD_TYPE l={.I=a}, r={.I=b};
    l.Lo.U &= r.Lo.U;
    l.Hi.U &= r.Hi.U;
    return  l.I;
}

#endif

#if 0 // _LEAVE_ALL_ANDS
}
#endif

#if 0 // _ENTER_ALL_ANDY
{
#endif

INLINE(  _Bool,  BOOL_ANDY)    (_Bool a, _Bool b) {return a&b;}
INLINE(  uchar, UCHAR_ANDY) (unsigned a, _Bool b) {return a&b;}
INLINE(  schar, SCHAR_ANDY)   (signed a, _Bool b) {return a&b;}
INLINE(   char,  CHAR_ANDY)      (int a, _Bool b) {return a&b;}
INLINE( ushort, USHRT_ANDY) (unsigned a, _Bool b) {return a&b;}
INLINE(  short,  SHRT_ANDY)   (signed a, _Bool b) {return a&b;}
INLINE(   uint,  UINT_ANDY)     (uint a, _Bool b) {return a&b;}
INLINE(    int,   INT_ANDY)      (int a, _Bool b) {return a&b;}
INLINE(  ulong, ULONG_ANDY)    (ulong a, _Bool b) {return a&b;}
INLINE(   long,  LONG_ANDY)     (long a, _Bool b) {return a&b;}
INLINE( ullong,ULLONG_ANDY)   (ullong a, _Bool b) {return a&b;}
INLINE(  llong, LLONG_ANDY)    (llong a, _Bool b) {return a&b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,andyqu) (QUAD_UTYPE a,_Bool b) 
{
    QUAD_TYPE c={.U=a};
    c.Lo.U &= b;
    c.Hi.U = 0;
    return  c.U;
}

INLINE(QUAD_ITYPE,andyqi) (QUAD_ITYPE a,_Bool b) 
{
    QUAD_TYPE c={.U=a};
    c.Lo.U &= b;
    c.Hi.U = 0;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_ANDY
}
#endif

#if 0 // _ENTER_ALL_ANDN
{
#endif

INLINE(  _Bool,  BOOL_ANDN)    (_Bool a,    _Bool b) {return a&~b;}
INLINE(  uchar, UCHAR_ANDN) (unsigned a, unsigned b) {return a&~b;}
INLINE(  schar, SCHAR_ANDN)   (signed a,   signed b) {return a&~b;}
INLINE(   char,  CHAR_ANDN)      (int a,      int b) {return a&~b;}
INLINE( ushort, USHRT_ANDN) (unsigned a, unsigned b) {return a&~b;}
INLINE(  short,  SHRT_ANDN)   (signed a,   signed b) {return a&~b;}
INLINE(   uint,  UINT_ANDN)     (uint a,     uint b) {return a&~b;}
INLINE(    int,   INT_ANDN)      (int a,      int b) {return a&~b;}
INLINE(  ulong, ULONG_ANDN)    (ulong a,    ulong b) {return a&~b;}
INLINE(   long,  LONG_ANDN)     (long a,     long b) {return a&~b;}
INLINE( ullong,ULLONG_ANDN)   (ullong a,   ullong b) {return a&~b;}
INLINE(  llong, LLONG_ANDN)    (llong a,    llong b) {return a&~b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,andnqu) (QUAD_UTYPE a,QUAD_UTYPE b) 
{
    QUAD_TYPE l={.U=a}, r={.U=b};
    l.Lo.U &= ~r.Lo.U;
    l.Hi.U &= ~r.Hi.U;
    return  l.U;
}

INLINE(QUAD_ITYPE,andnqi) (QUAD_ITYPE a,QUAD_ITYPE b) 
{
    QUAD_TYPE l={.I=a}, r={.I=b};
    l.Lo.U &= ~r.Lo.U;
    l.Hi.U &= ~r.Hi.U;
    return  l.I;
}

#endif
#if 0
INLINE(flt16_t, FLT16_ANDN)  (flt16_t a,  flt16_t b)
{
#define     FLT16_ANDN(A, B) (((HALF_TYPE){.U=FLT16_ASHU(A)|FLT16_ASHU(B)}).F)
    HALF_TYPE l={.F=a}, r={.F=b};
    l.U &=  ~r.U;
    return  l.F;
}

INLINE(  float,   FLT_ANDN)   (float a,   float b)
{
#define     FLT_ANDN(A, B) (((WORD_TYPE){.U=FLT_ASWU(A)|FLT_ASWU(B)}).F)
    WORD_TYPE l={.F=a}, r={.F=b};
    l.U &=  ~r.U;
    return  l.F;
}

INLINE( double,   DBL_ANDN)  (double a,  double b)
{
#define     DBL_ANDN(A, B) (((DWRD_TYPE){.U=DBL_ASDU(A)|DBL_ASDU(B)}).F)
    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U &=  ~r.U;
    return  l.F;
}
#endif

#if 0 // _LEAVE_ALL_ANDN
}
#endif

#if 0 // _ENTER_ALL_ORRS
{
#endif

INLINE(  _Bool,  BOOL_ORRS)    (_Bool a,      _Bool b) {return a|b;}
INLINE(  uchar, UCHAR_ORRS) (unsigned a,   unsigned b) {return a|b;}
INLINE(  schar, SCHAR_ORRS)   (signed a,     signed b) {return a|b;}
INLINE(   char,  CHAR_ORRS)      (int a,        int b) {return a|b;}
INLINE( ushort, USHRT_ORRS) (unsigned a,   unsigned b) {return a|b;}
INLINE(  short,  SHRT_ORRS)   (signed a,     signed b) {return a|b;}
INLINE(   uint,  UINT_ORRS)     (uint a,       uint b) {return a|b;}
INLINE(    int,   INT_ORRS)      (int a,        int b) {return a|b;}
INLINE(  ulong, ULONG_ORRS)    (ulong a,      ulong b) {return a|b;}
INLINE(   long,  LONG_ORRS)     (long a,       long b) {return a|b;}
INLINE( ullong,ULLONG_ORRS)   (ullong a,     ullong b) {return a|b;}
INLINE(  llong, LLONG_ORRS)    (llong a,      llong b) {return a|b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,orrsqu) (QUAD_UTYPE a, QUAD_UTYPE b) 
{
    QUAD_TYPE p={.U=a}, q={.U=b};
    p.Lo.U |= q.Lo.U;
    p.Hi.U |= q.Hi.U;
    return  p.U;
}

INLINE(QUAD_ITYPE,orrsqi) (QUAD_ITYPE a, QUAD_ITYPE b) 
{
    QUAD_TYPE p={.I=a}, q={.I=b};
    p.Lo.U |= q.Lo.U;
    p.Hi.U |= q.Hi.U;
    return  p.U;
}

#endif
#if 0
INLINE(flt16_t, FLT16_ORRS)  (flt16_t a,  flt16_t b)
{
#define     FLT16_ORRS(A, B) (((HALF_TYPE){.U=FLT16_ASHU(A)|FLT16_ASHU(B)}).F)
    HALF_TYPE l={.F=a}, r={.F=b};
    l.U |=  r.U;
    return  l.F;
}

INLINE(  float,   FLT_ORRS)   (float a,   float b)
{
#define     FLT_ORRS(A, B) (((WORD_TYPE){.U=FLT_ASWU(A)|FLT_ASWU(B)}).F)
    WORD_TYPE l={.F=a}, r={.F=b};
    l.U |=  r.U;
    return  l.F;
}

INLINE( double,   DBL_ORRS)  (double a,  double b)
{
#define     DBL_ORRS(A, B) (((DWRD_TYPE){.U=DBL_ASDU(A)|DBL_ASDU(B)}).F)
    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U |=  r.U;
    return  l.F;
}
#endif

#if 0 // _LEAVE_ALL_ORRS
}
#endif

#if 0 // _ENTER_ALL_ORRN
{
#endif

INLINE(  _Bool,  BOOL_ORRN)    (_Bool a,    _Bool b) {return a|~b;}
INLINE(  uchar, UCHAR_ORRN) (unsigned a, unsigned b) {return a|~b;}
INLINE(  schar, SCHAR_ORRN)   (signed a,   signed b) {return a|~b;}
INLINE(   char,  CHAR_ORRN)      (int a,      int b) {return a|~b;}
INLINE( ushort, USHRT_ORRN) (unsigned a, unsigned b) {return a|~b;}
INLINE(  short,  SHRT_ORRN)   (signed a,   signed b) {return a|~b;}
INLINE(   uint,  UINT_ORRN)     (uint a,     uint b) {return a|~b;}
INLINE(    int,   INT_ORRN)      (int a,      int b) {return a|~b;}
INLINE(  ulong, ULONG_ORRN)    (ulong a,    ulong b) {return a|~b;}
INLINE(   long,  LONG_ORRN)     (long a,     long b) {return a|~b;}
INLINE( ullong,ULLONG_ORRN)   (ullong a,   ullong b) {return a|~b;}
INLINE(  llong, LLONG_ORRN)    (llong a,    llong b) {return a|~b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,orrnqu) (QUAD_UTYPE a,QUAD_UTYPE b) 
{
    QUAD_TYPE l={.U=a}, r={.U=b};
    l.Lo.U |= ~r.Lo.U;
    l.Hi.U |= ~r.Hi.U;
    return  l.U;
}

INLINE(QUAD_ITYPE,orrnqi) (QUAD_ITYPE a,QUAD_ITYPE b) 
{
    QUAD_TYPE l={.I=a}, r={.I=b};
    l.Lo.U |= ~r.Lo.U;
    l.Hi.U |= ~r.Hi.U;
    return  l.I;
}

#endif
#if 0
INLINE(flt16_t, FLT16_ORRN)  (flt16_t a,  flt16_t b)
{
#define     FLT16_ORRN(A, B) (((HALF_TYPE){.U=FLT16_ASHU(A)|FLT16_ASHU(B)}).F)
    HALF_TYPE l={.F=a}, r={.F=b};
    l.U |=  ~r.U;
    return  l.F;
}

INLINE(  float,   FLT_ORRN)   (float a,   float b)
{
#define     FLT_ORRN(A, B) (((WORD_TYPE){.U=FLT_ASWU(A)|FLT_ASWU(B)}).F)
    WORD_TYPE l={.F=a}, r={.F=b};
    l.U |=  ~r.U;
    return  l.F;
}

INLINE( double,   DBL_ORRN)  (double a,  double b)
{
#define     DBL_ORRN(A, B) (((DWRD_TYPE){.U=DBL_ASDU(A)|DBL_ASDU(B)}).F)
    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U |=  ~r.U;
    return  l.F;
}
#endif

#if 0 // _LEAVE_ALL_ORRN
}
#endif


#if 0 // _ENTER_ALL_XORS
{
#endif

INLINE(  _Bool,  BOOL_XORS)    (_Bool a,    _Bool b) {return a^b;}
INLINE(  uchar, UCHAR_XORS) (unsigned a, unsigned b) {return a^b;}
INLINE(  schar, SCHAR_XORS)   (signed a,   signed b) {return a^b;}
INLINE(   char,  CHAR_XORS)      (int a,      int b) {return a^b;}
INLINE( ushort, USHRT_XORS) (unsigned a, unsigned b) {return a^b;}
INLINE(  short,  SHRT_XORS)   (signed a,   signed b) {return a^b;}
INLINE(   uint,  UINT_XORS)     (uint a,     uint b) {return a^b;}
INLINE(    int,   INT_XORS)      (int a,      int b) {return a^b;}
INLINE(  ulong, ULONG_XORS)    (ulong a,    ulong b) {return a^b;}
INLINE(   long,  LONG_XORS)     (long a,     long b) {return a^b;}
INLINE( ullong,ULLONG_XORS)   (ullong a,   ullong b) {return a^b;}
INLINE(  llong, LLONG_XORS)    (llong a,    llong b) {return a^b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,xorsqu) (QUAD_UTYPE a,QUAD_UTYPE b) 
{
    QUAD_TYPE l={.U=a}, r={.U=b};
    l.Lo.U ^= r.Lo.U;
    l.Hi.U ^= r.Hi.U;
    return  l.U;
}

INLINE(QUAD_ITYPE,xorsqi) (QUAD_ITYPE a,QUAD_ITYPE b) 
{
    QUAD_TYPE l={.I=a}, r={.I=b};
    l.Lo.U ^= r.Lo.U;
    l.Hi.U ^= r.Hi.U;
    return  l.I;
}

#endif
#if 0
INLINE(flt16_t, FLT16_XORS)  (flt16_t a,  flt16_t b)
{
#define     FLT16_XORS(A, B) (((HALF_TYPE){.U=FLT16_ASHU(A)|FLT16_ASHU(B)}).F)
    HALF_TYPE l={.F=a}, r={.F=b};
    l.U ^=  r.U;
    return  l.F;
}

INLINE(  float,   FLT_XORS)   (float a,   float b)
{
#define     FLT_XORS(A, B) (((WORD_TYPE){.U=FLT_ASWU(A)|FLT_ASWU(B)}).F)
    WORD_TYPE l={.F=a}, r={.F=b};
    l.U ^=  r.U;
    return  l.F;
}

INLINE( double,   DBL_XORS)  (double a,  double b)
{
#define     DBL_XORS(A, B) (((DWRD_TYPE){.U=DBL_ASDU(A)|DBL_ASDU(B)}).F)
    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U ^=  r.U;
    return  l.F;
}
#endif
#if 0 // _LEAVE_ALL_XORS
}
#endif

#if 0 // _ENTER_ALL_XORN
{
#endif

INLINE(  _Bool,  BOOL_XORN)    (_Bool a,    _Bool b) {return a^~b;}
INLINE(  uchar, UCHAR_XORN) (unsigned a, unsigned b) {return a^~b;}
INLINE(  schar, SCHAR_XORN)   (signed a,   signed b) {return a^~b;}
INLINE(   char,  CHAR_XORN)      (int a,      int b) {return a^~b;}
INLINE( ushort, USHRT_XORN) (unsigned a, unsigned b) {return a^~b;}
INLINE(  short,  SHRT_XORN)   (signed a,   signed b) {return a^~b;}
INLINE(   uint,  UINT_XORN)     (uint a,     uint b) {return a^~b;}
INLINE(    int,   INT_XORN)      (int a,      int b) {return a^~b;}
INLINE(  ulong, ULONG_XORN)    (ulong a,    ulong b) {return a^~b;}
INLINE(   long,  LONG_XORN)     (long a,     long b) {return a^~b;}
INLINE( ullong,ULLONG_XORN)   (ullong a,   ullong b) {return a^~b;}
INLINE(  llong, LLONG_XORN)    (llong a,    llong b) {return a^~b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,xornqu) (QUAD_UTYPE a,QUAD_UTYPE b) 
{
    QUAD_TYPE l={.U=a}, r={.U=b};
    l.Lo.U ^= ~r.Lo.U;
    l.Hi.U ^= ~r.Hi.U;
    return  l.U;
}

INLINE(QUAD_ITYPE,xornqi) (QUAD_ITYPE a,QUAD_ITYPE b) 
{
    QUAD_TYPE l={.I=a}, r={.I=b};
    l.Lo.U ^= ~r.Lo.U;
    l.Hi.U ^= ~r.Hi.U;
    return  l.I;
}

#endif
#if 0
INLINE(flt16_t, FLT16_XORN)  (flt16_t a,  flt16_t b)
{
#define     FLT16_XORN(A, B) (((HALF_TYPE){.U=FLT16_ASHU(A)|FLT16_ASHU(B)}).F)
    HALF_TYPE l={.F=a}, r={.F=b};
    l.U ^=  ~r.U;
    return  l.F;
}

INLINE(  float,   FLT_XORN)   (float a,   float b)
{
#define     FLT_XORN(A, B) (((WORD_TYPE){.U=FLT_ASWU(A)|FLT_ASWU(B)}).F)
    WORD_TYPE l={.F=a}, r={.F=b};
    l.U ^=  ~r.U;
    return  l.F;
}

INLINE( double,   DBL_XORN)  (double a,  double b)
{
#define     DBL_XORN(A, B) (((DWRD_TYPE){.U=DBL_ASDU(A)|DBL_ASDU(B)}).F)
    DWRD_TYPE l={.F=a}, r={.F=b};
    l.U ^=  ~r.U;
    return  l.F;
}
#endif
#if 0 // _LEAVE_ALL_XORN
}
#endif


#if 0 // _ENTER_ALL_SHLL
{
#endif

#define     shllwz(A, B) (((unsigned) A)<<B)
#define     shlldz(A, B) (((uint64_t) A)<<B)

INLINE( _Bool,  BOOL_SHLL)    (_Bool a, Rc(0, BOOL_WIDTH) b)
{
#define  MY_BOOL_SHLL(A, B, ...) ((_Bool) (A&&!B))
#define     BOOL_SHLL(...) MY_BOOL_SHLL(__VA_ARGS__,1)
    return  a && !b;
}


INLINE( uchar, UCHAR_SHLL) (unsigned a, Rc(0, UCHAR_WIDTH) b) 
{
#define  MY_UCHAR_SHLL(A, B, ...) ((uchar) ((unsigned) A<<B))
#define     UCHAR_SHLL(...) MY_UCHAR_SHLL(__VA_ARGS__,1)
    return  a<<b;
}

INLINE( schar, SCHAR_SHLL)   (signed a, Rc(0, SCHAR_WIDTH) b) 
{
#define  MY_SCHAR_SHLL(A, B, ...) \
((schar) ((SCHAR_MIN&A)|(SCHAR_MAX&((unsigned) A<<B))))

#define     SCHAR_SHLL(...) MY_SCHAR_SHLL(__VA_ARGS__,1)
    unsigned q = SCHAR_MIN&a;
    unsigned p = SCHAR_MAX&((unsigned) a<<b);
    return  p|q;
}

INLINE(  char,  CHAR_SHLL)      (int a, Rc(0,  CHAR_WIDTH) b) 
{
#define     CHAR_SHLL(...) MY_CHAR_SHLL(__VA_ARGS__,1)
#if CHAR_MIN
#   define  MY_CHAR_SHLL(A, B, ...) \
((char) ((CHAR_MIN&A)|(CHAR_MAX&((unsigned) A<<B))))
    unsigned c = a;
    unsigned q = CHAR_MIN&c;
    unsigned p = CHAR_MAX&(c<<b);
    return  p|q;
#else
#   define  MY_CHAR_SHLL(A, B, ...) ((char) ((unsigned) A<<B))
    return  (unsigned) a<<b;
#endif
}


INLINE(ushort, USHRT_SHLL) (unsigned a, Rc(0, USHRT_WIDTH) b)
{
#define  MY_USHRT_SHLL(A, B, ...) ((ushort) ((unsigned) A<<B))
#define     USHRT_SHLL(...) MY_USHRT_SHLL(__VA_ARGS__,1)
    return  a<<b;
}

INLINE( short,  SHRT_SHLL)   (signed a, Rc(0,  SHRT_WIDTH) b)
{
#define  MY_SHRT_SHLL(A, B, ...) ((short) ((SHRT_MIN&A)|(SHRT_MAX&shllwz(A,B))))
#define     SHRT_SHLL(...) MY_SHRT_SHLL(__VA_ARGS__,1)
    unsigned q = SHRT_MIN&a;
    unsigned p = SHRT_MAX&((unsigned) a<<b);
    return  p|q;
}


INLINE(  uint,  UINT_SHLL)     (uint a, Rc(0,  UINT_WIDTH) b)
{
#define  MY_UINT_SHLL(A, B, ...) ((uint) A<<B)
#define     UINT_SHLL(...) MY_UINT_SHLL(__VA_ARGS__,1)
    return  a<<b;
}

INLINE(   int,   INT_SHLL)      (int a, Rc(0,   INT_WIDTH) b)
{
#define  MY_INT_SHLL(A, B, ...) ((int) ((INT_MIN&A)|(INT_MAX&shllwz(A,B))))
#define     INT_SHLL(...) MY_INT_SHLL(__VA_ARGS__,1)
    unsigned q = INT_MIN&a;
    unsigned p = INT_MAX&shllwz(a, b);
    return  p|q;
}


INLINE( ulong, ULONG_SHLL)    (ulong a, Rc(0, ULONG_WIDTH) b) 
{
#define  MY_ULONG_SHLL(A, B, ...) (((ulong) A)<<B)
#define     ULONG_SHLL(...) MY_ULONG_SHLL(__VA_ARGS__,1)
    return  a<<b;
}

INLINE(  long,  LONG_SHLL)     (long a, Rc(0,  LONG_WIDTH) b) 
{
#define  MY_LONG_SHLL(A, B, ...) \
((long) ((LONG_MIN&A)|(LONG_MAX&ULONG_SHLL(A,B))))

#define     LONG_SHLL(...) MY_LONG_SHLL(__VA_ARGS__,1)
    ulong q = LONG_MIN&a;
    ulong p = LONG_MAX&ULONG_SHLL(a, b);
    return  p|q;
}


INLINE(ullong,ULLONG_SHLL) (ullong a, Rc(0,ULLONG_WIDTH) b) 
{
#define MY_ULLONG_SHLL(A, B, ...) (((ullong) A)<<B)
#define    ULLONG_SHLL(...) MY_ULLONG_SHLL(__VA_ARGS__,1)
    return  a<<b;
}

INLINE( llong, LLONG_SHLL)  (llong a, Rc(0, LLONG_WIDTH) b)
{
#define  MY_LLONG_SHLL(A, B, ...) \
((llong) ((LLONG_MIN&A)|(LLONG_MAX&ULLONG_SHLL(A,B))))
#define     LLONG_SHLL(...) MY_LLONG_SHLL(__VA_ARGS__,1)
    ullong q = LLONG_MIN&a;
    ullong p = LLONG_MAX&ULLONG_SHLL(a, b);
    return  p|q;
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,shllqu) (QUAD_UTYPE a, Rc(0, +128) b)
{
#if defined(__SIZEOF_INT128)
#   define  MY_SHLLQU(A, B, ...) ((QUAD_UTYPE) A<<B)
#else
#   define  MY_SHLLQU(A, B, ...) ((shllqu)(A,B))
#endif

#define  shllqu(...) MY_SHLLQU(__VA_ARGS__,1)
    QUAD_TYPE   c = {.U=a};
    uint64_t    l = c.Lo.U;
    uint64_t    r = c.Hi.U;
    if (b < 64)
    {
        c.Lo.U = (l<<b);
        c.Hi.U = (r<<b)|(l>>(64-b));
    }
    else
    {
        c.Lo.U = 0;
        c.Hi.U = (l<<(b-64));
    }
    return  c.U;
}

INLINE(QUAD_ITYPE,shllqi) (QUAD_ITYPE a, Rc(0, 128) b)
{
#if defined(__SIZEOF_INT128__)
#   define  MY_SHLLQI(A, B, ...) ((QUAD_ITYPE) A<<B)
#else
#   define  MY_SHLLQI(A, B, ...) ((shllqi)(A,B))
#endif
#define  shllqi(...) MY_SHLLQI(__VA_ARGS__,1)
    QUAD_TYPE   c = {.I=a};
    uint64_t    l = c.Lo.U;
    uint64_t    r = c.Hi.U;
    uint64_t    s = r&INT64_MIN;
    if (b < 64)
    {
        c.Lo.U = (l<<b);
        c.Hi.U = (r<<b)|(l>>(64-b));
    }
    else
    {
        c.Lo.U = 0;
        c.Hi.U = (l<<(b-64));
    }
    c.Hi.U &= INT64_MAX;
    c.Hi.U |= s;
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_SHLL
}
#endif


#if 0 // _ENTER_ALL_SHRS
{
#endif

#ifndef     SPC_SHRS
#define     SPC_SHRS 0
#endif

INLINE( schar, SCHAR_SHRS)  (signed a, Rc(0,  SCHAR_WIDTH) b);
INLINE(  char,  CHAR_SHRS)     (int a, Rc(0,   CHAR_WIDTH) b);
INLINE( short,  SHRT_SHRS)  (signed a, Rc(0,   SHRT_WIDTH) b);
INLINE(   int,   INT_SHRS)     (int a, Rc(0,    INT_WIDTH) b);
INLINE(  long,  LONG_SHRS)    (long a, Rc(0,   LONG_WIDTH) b);
INLINE( llong, LLONG_SHRS)   (llong a, Rc(0,  LLONG_WIDTH) b);

INLINE( _Bool,  BOOL_SHRS)  (_Bool a, Rc(0,  1) b)
{
#define  MY_BOOL_SHRS(A, B, ...) ((_Bool) (A&&!B))
#define     BOOL_SHRS(...) MY_BOOL_SHRS(__VA_ARGS__,1)
    return  a && !b;
}

INLINE( uchar, UCHAR_SHRS)  (unsigned a, Rc(0,  UCHAR_WIDTH) b)
{
#define  MY_UCHAR_SHRS(A, B, ...)    ((uchar) ((unsigned) A>>B))
#define     UCHAR_SHRS(...) MY_UCHAR_SHRS(__VA_ARGS__,1)
    return  a>>b;
}


#if (SCHAR_SPC&SPC_SHRS)
INLINE( schar, SCHAR_SHRS)  (signed a, Rc(0, SCHAR_WIDTH) b)
{
#define  MY_SCHAR_SHRS(A, B, ...)    ((schar) ((signed) A>>B))
#define     SCHAR_SHRS(...) MY_SCHAR_SHRS(__VA_ARGS__,1)
    return  a>>b;
}

#endif

#if CHAR_MIN && (CHAR_SPC&SPC_SHRS)
INLINE(  char,  CHAR_SHRS)   (int a, Rc(0,   CHAR_WIDTH) b)
{
#   define  MY_CHAR_SHRS(A, B, ...) ((char) ((int) A>>B))
    return  (SCHAR_SHRS)(a, b);
}
#elif !CHAR_MIN
INLINE(  char,  CHAR_SHRS)   (int a, Rc(0,   CHAR_WIDTH) b)
{
#   define  MY_CHAR_SHRS(A, B, ...) ((char) ((uint) A>>B))
    return  (UCHAR_SHRS)(a, b);
}
#endif

#if defined(MY_CHAR_SHRS)
#   define     CHAR_SHRS(...) MY_CHAR_SHRS(__VA_ARGS__,1)
#endif

INLINE(ushort, USHRT_SHRS) (unsigned a, Rc(0,  USHRT_WIDTH) b)
{
#define  MY_USHRT_SHRS(A, B, ...) ((ushort) ((unsigned) A>>B))
#define     USHRT_SHRS(...) MY_USHRT_SHRS(__VA_ARGS__,1)
    return  a>>b;
}

#if (SHRT_SPC&SPC_SHRS)
INLINE( short,  SHRT_SHRS)  (signed a, Rc(0,   SHRT_WIDTH) b)
{
#   define  MY_SHRT_SHRS(A, B, ...) ((short) ((signed) A>>B))
#   define     SHRT_SHRS(...) MY_SHRT_SHRS(__VA_ARGS__,1)
    return  a>>b;
}
#endif

INLINE(  uint,  UINT_SHRS)   (uint a, Rc(0,   UINT_WIDTH) b)
{
#define  MY_UINT_SHRS(A, B, ...) (((uint) A)>>B)
#define     UINT_SHRS(...) MY_UINT_SHRS(__VA_ARGS__,1)
    return  a>>b;
}

#if (INT_SPC&SPC_SHRS)
INLINE(   int,   INT_SHRS)    (int a, Rc(0,   INT_WIDTH) b)
{
#   define  MY_INT_SHRS(A, B, ...) ((int) A>>B)
#   define     INT_SHRS(...) MY_INT_SHRS(__VA_ARGS__,1)
    return  a>>b;
}
#endif

INLINE( ulong, ULONG_SHRS)  (ulong a, Rc(0, ULONG_WIDTH) b)
{
#define  MY_ULONG_SHRS(A, B, ...) (((ulong) A)>>B)
#define     ULONG_SHRS(...) MY_ULONG_SHRS(__VA_ARGS__,1)
    return  a>>b;
}

#if ((DWRD_NLONG == 2) && (LONG_SPC&SPC_SHRS))
INLINE(  long,  LONG_SHRS)   (long a, Rc(0, LONG_WIDTH) b)
{
#   define  MY_LONG_SHRS(A, B, ...)  ((long) A>>B)
#   define     LONG_SHRS(...) MY_LONG_SHRS(__VA_ARGS__,1)
    return  a>>b;
}
#endif

INLINE(ullong,ULLONG_SHRS) (ullong a, Rc(0, ULLONG_WIDTH) b)
{
#define  MY_ULLONG_SHRS(A, B, ...) (((ullong) A)>>B)
#define     ULLONG_SHRS(...) MY_ULLONG_SHRS(__VA_ARGS__,1)
    return  a>>b;
}

#if ((QUAD_NLLONG == 2) && (LLONG_SPC&SPC_SHRS))
INLINE( llong, LLONG_SHRS)  (llong a, Rc(0, LONG_WIDTH) b)
{
#   define  MY_LLONG_SHRS(A, B, ...)  ((llong) A>>B)
#   define     LLONG_SHRS(...) MY_LLONG_SHRS(__VA_ARGS__,1)
    return  a>>b;
}
#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,shrsqu) (QUAD_UTYPE a, Rc(0, 128) b)
{
#define MY_SHRSQU(A, B, ...) ((shrsqu)(A,B))
#define shrsqu(...) MY_SHRSQU(__VA_ARGS__,1)
#if 0
    return a>>b;
#else
    QUAD_TYPE   c = {.U=a};
    uint64_t    l = c.Lo.U;
    uint64_t    r = c.Hi.U;
    if (b < 64)
    {
        c.Hi.U = (r>>b);
        c.Lo.U = (l>>b)|(r<<(64-b));
    }
    else
    {
        c.Hi.U = 0;
        c.Lo.U = (r>>(b-64));
    }
    return c.U;
#endif
}

INLINE(QUAD_ITYPE,shrsqi) (QUAD_ITYPE a, Rc(0, 128) b)
{
#define     MY_SHRSQI(A, B, ...) ((shrsqi)(A,B))
#define     shrsqi(...) MY_SHRSQI(__VA_ARGS__,1)
#if 0
    return  a>>b;
#else
    QUAD_TYPE   c = {.U=a};
    int64_t     l = c.Lo.I;
    int64_t     r = c.Hi.I;
    if (b < 64)
    {
        c.Hi.I = (r>>b);
        c.Lo.I = (l>>b)|((uint64_t) r<<(64-b));
    }
    else
    {
        c.Hi.I = (r>>63);
        c.Lo.I = (r>>(b-64));
    }
    return c.I;
#endif
}

#endif

#if 0 // _LEAVE_ALL_SHRS
}
#endif

#if 0 // _ENTER_ALL_UNOL
{
#endif


INLINE(void *, ADDR_UNOL) (Rc(0, ADDR_WIDTH) n)
{
#define     ADDR_UNOL(N) ((void *) (UINTPTR_MAX>>(ADDR_WIDTH-N)))
    return  ADDR_UNOL(n);
}

INLINE( _Bool,  BOOL_UNOL) (Rc(0, 1) n)
{
#define     BOOL_UNOL(N) ((_Bool) (1==N))
    return  1==n;
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

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,unolqu) (Rc(0, 128) n) 
{
#if defined(__SIZEOF_INT128__)
#   define  unolqu(N) ((QUAD_UTYPE) -1>>(128-N))
#endif

    QUAD_TYPE   z;
    if (n > 64)
    {
        z.Lo.U = (UINT64_MAX);
        z.Hi.U = (UINT64_MAX>>(128-n));
    }
    else
    {
        z.Lo.U = (UINT64_MAX>>(64-n));
        z.Hi.U = 0;
    }
    return z.U;
}

INLINE(QUAD_ITYPE,unolqi) (Rc(0, 128) n)
{
#if defined(__SIZEOF_INT128__)
#   define  unolqi(N) ((QUAD_ITYPE) ((QUAD_UTYPE) -1>>(128-N)))
#endif

    QUAD_TYPE   z;
    if (n > 64)
    {
        z.Lo.U = UINT64_MAX;
        z.Hi.U = (UINT64_MAX>>(128-n));
    }
    else
    {
        z.Lo.U = (UINT64_MAX>>(64-n));
        z.Hi.U = 0;
    }
    return z.I;
}

#endif

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

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,unorqu) (Rc(0, 128) n) 
{
    QUAD_TYPE   z;
    if (n > 64)
    {
        z.Hi.U = UINT64_MAX;
        z.Lo.U = (UINT64_MAX<<(128-n));
    }
    else
    {
        z.Hi.U = (UINT64_MAX<<(64-n));
        z.Lo.U = 0;
    }
    return z.U;
}

INLINE(QUAD_ITYPE,unorqi) (Rc(0, 128) n)
{
    QUAD_TYPE   z;
    if (n > 64)
    {
        z.Hi.U = UINT64_MAX;
        z.Lo.U = (UINT64_MAX<<(128-n));
    }
    else
    {
        z.Hi.U = (UINT64_MAX<<(64-n));
        z.Lo.U = 0;
    }
    return z.I;
}

#endif

#if 0 // _LEAVE_ALL_UNOR
}
#endif

#if 0 // _ENTER_ALL_NEGL
{
#endif

INLINE( uchar, UCHAR_NEGL) (unsigned x) {return 0U-(uchar) x;}
INLINE( schar, SCHAR_NEGL)   (signed x) {return 0U-(schar) x;}

INLINE(  char,  CHAR_NEGL)      (int x) {return 0U-(char) x;}
INLINE(ushort, USHRT_NEGL) (unsigned x) {return 0U-(ushort) x;}
INLINE( short,  SHRT_NEGL)   (signed x) {return 0U-(short) x;}
INLINE(  uint,  UINT_NEGL)     (uint x) {return -x;}
INLINE(   int,   INT_NEGL)      (int x) {return 0U-x;}
INLINE( ulong, ULONG_NEGL)    (ulong x) {return -x;}
INLINE(  long,  LONG_NEGL)     (long x) {return 0UL-x;}
INLINE(ullong,ULLONG_NEGL)   (ullong x) {return -x;}
INLINE( llong, LLONG_NEGL)    (llong x) {return 0ULL-x;}

#if QUAD_NLONG == 2

INLINE(QUAD_UTYPE,neglqu) (QUAD_UTYPE x)
{
#if  defined(__SIZEOF_INT128__)
    return -x;
#else
    QUAD_TYPE   c = {.U=x};
    uint64_t    r, l=~c.Lo.U;
    r = 1+l;
    if (r < l)
        c.Hi.U--;
    c.Hi.U = ~c.Hi.U;
    c.Lo.U = r;
    return c.U;
#endif
}

INLINE(QUAD_ITYPE,neglqi) (QUAD_ITYPE x) 
{
    QUAD_TYPE q = {.I=x};
    q.U = neglqu(q.U);
    return  q.I;
}
#endif

#if 0 // _LEAVE_ALL_NEGL
}
#endif

#if 0 // _ENTER_ALL_ABSU
{
#endif

INLINE(uchar, SCHAR_ABSU) (signed x)
{
    x = (schar) x;
    int y = -((uint) x>>(INT_WIDTH-1));
    return  (x+y)^y;
}

INLINE(uchar,  CHAR_ABSU)    (int x)
{
#if CHAR_MIN
    return  SCHAR_ABSU(x);
#else
    return  x;
#endif
}

INLINE(ushort, SHRT_ABSU) (signed x)
{
    x = (short) x;
    int y = -((uint) x>>(INT_WIDTH-1));
    return  (x+y)^y;
}

INLINE(  uint,  INT_ABSU)    (int x)
{
    int y = -((uint) x>>(INT_WIDTH-1));
    return  (x+y)^y;
}

INLINE( ulong, LONG_ABSU)   (long x)
{
    long y = -((ulong) x>>(LONG_WIDTH-1));
    return  (x+y)^y;
}

INLINE(ullong,LLONG_ABSU)  (llong x)
{
    llong y = -((ullong) x>>(LLONG_WIDTH-1));
    return  (x+y)^y;
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,absuqi) (QUAD_ITYPE x)
{
    QUAD_TYPE   y, z={.I=x};
#if 0 && defined(__SIZEOF_INT128__)
    y.U = -(z.U>>127);
    return  (x+y.I)^y.I;
#else
    QUAD_TYPE  c, p={.I=x}, q;
    y.Lo.I = z.Hi.I>>63;
    y.Hi.I = y.Lo.I;
    q = y;
    c.Lo.U = (p.Lo.U+q.Lo.U);
    c.Hi.U = (p.Hi.U+q.Hi.U)+(c.Lo.U<p.Lo.U);
    c.Lo.U ^= y.Lo.U;
    c.Hi.U ^= y.Hi.U;
    return  c.U;
#endif
}

#endif

#if 0 // _LEAVE_ALL_ABSU
}
#endif

#if 0 // _ENTER_ALL_ABSL
{
#endif

INLINE(schar,SCHAR_ABSL) (signed x) 
{
    x = (schar) x;
    return  (x < 0) ? (0U-x) : (0U+x);
}

INLINE(schar, CHAR_ABSL)    (int x) 
{
    x = (char) x;
    return  (x < 0) ? (0U-x) : (0U+x);
}

INLINE(short, SHRT_ABSL) (signed x) 
{
    x = (short) x;
    return  (x < 0) ? (0U-x) : (0U+x);
}

INLINE(  int,  INT_ABSL)    (int x) {return (x<0) ? (0U  -x) : (0U+x);}
INLINE( long, LONG_ABSL)   (long x) {return (x<0) ? (0UL -x) : (0UL+x);}
INLINE(llong,LLONG_ABSL)  (llong x) {return (x<0) ? (0ULL-x) : (0ULL+x);}

#if QUAD_NLLONG == 2
INLINE(QUAD_ITYPE,abslqi) (QUAD_ITYPE x)
{
    QUAD_TYPE a = {.I=x};
    return  (x < 0) ? neglqu(a.U) : a.U;
}
#endif

#if 0 // _LEAVE_ALL_ABSL
}
#endif

#if 0 // _ENTER_ALL_SHL2
{
#endif

INLINE(uint16_t, UCHAR_SHL2)  (unsigned a, Rc(0, UCHAR_WIDTH) b)
{
#define     UCHAR_SHL2(A, B) ((uint16_t) ((uchar) A<<B))
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
#define     USHRT_SHL2(A, B) ((uint32_t) ((ushort) A<<B))
    return  (ushort) a<<b;
}

INLINE( int32_t,  SHRT_SHL2)  (signed a, Rc(0,   SHRT_WIDTH) b)
{
#define     SHRT_SHL2(A, B) ((int32_t) ((UINT32_MAX&((short) A))<<B))
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
#define     ULONG_SHL2(...) UINT_SHL2(__VA_ARGS__)
    return  (UINT_SHL2)(a, b);
}

INLINE( int64_t,  LONG_SHL2)    (long a, Rc(0,  LONG_WIDTH) b)
{
#define     LONG_SHL2(...) INT_SHL2(__VA_ARGS__)
    return  (INT_SHL2)(a, b);
}

#else

INLINE(QUAD_UTYPE, ULONG_SHL2) (ulong a, Rc(0, ULONG_WIDTH) b)
{
    QUAD_TYPE   c;
    c.Lo.U = a<<b;
    c.Hi.U = a>>(ULONG_WIDTH-b);
    return  c.U;
}

INLINE(QUAD_ITYPE, LONG_SHL2) (long a, Rc(0, LONG_WIDTH) b)
{
    QUAD_TYPE   c = {.Lo.I=a, .Hi.I=a>>(LONG_WIDTH-1)};
    ulong       l = c.Lo.U;
    ulong       r = c.Hi.U;
    if (b < LONG_WIDTH)
    {
        c.Lo.U = (l<<b);
        c.Hi.U = (r<<b)|(l>>(LONG_WIDTH-b));
    }
    else
    {
        c.Lo.U = 0;
        c.Hi.U = (l<<(b-LONG_WIDTH));
    }
    return  c.I;
}

#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE, ULLONG_SHL2) (ullong a, Rc(0, ULLONG_WIDTH) b)
{
    QUAD_TYPE c;
    c.Lo.U = a<<b;
    c.Hi.U = a>>(ULLONG_WIDTH-b);
    return  c.U;
}

INLINE(QUAD_ITYPE, LLONG_SHL2) (llong a, Rc(0, LLONG_WIDTH) b)
{
    QUAD_TYPE   c = {.Lo.I=a, .Hi.I=a>>(LLONG_WIDTH-1)};
    ullong      l = c.Lo.U;
    ullong      r = c.Hi.U;
    if (b < LLONG_WIDTH)
    {
        c.Lo.U = (l<<b);
        c.Hi.U = (r<<b)|(l>>(LLONG_WIDTH-b));
    }
    else
    {
        c.Lo.U = 0;
        c.Hi.U = (l<<(b-LLONG_WIDTH));
    }
    return  c.I;
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
#define  MY_BOOL_SHLR(A, B, ...) ((_Bool) ((A==1) && (B==1)))
#define     BOOL_SHLR(...) MY_BOOL_SHLR(__VA_ARGS__,1)
    return  a && b;
}

INLINE( uchar, UCHAR_SHLR) (unsigned a, Rc(0,  UCHAR_WIDTH) b)
{
#define  MY_UCHAR_SHLR(A, B, ...) ((uchar) (((unsigned) A)>>(UCHAR_WIDTH-B)))
#define     UCHAR_SHLR(...) MY_UCHAR_SHLR(__VA_ARGS__,1)
    return  a>>(UCHAR_WIDTH-b);
}

INLINE( schar, SCHAR_SHLR)   (signed a, Rc(0,  SCHAR_WIDTH) b)
{
#define  MY_SCHAR_SHLR(A, B, ...) ((schar) (((unsigned) A)>>(SCHAR_WIDTH-B)))
#define     SCHAR_SHLR(...) MY_SCHAR_SHLR(__VA_ARGS__,1)
    return  (unsigned) a>>(SCHAR_WIDTH-b);
}

INLINE(  char,  CHAR_SHLR)      (int a, Rc(0,   CHAR_WIDTH) b)
{
#define  MY_CHAR_SHLR(A, B, ...) ((char) (((unsigned) A)>>(CHAR_WIDTH-B)))
#define     CHAR_SHLR(...) MY_CHAR_SHLR(__VA_ARGS__,1)
    return  (unsigned) a>>(CHAR_WIDTH-b);
}


INLINE(ushort, USHRT_SHLR) (unsigned a, Rc(0,  USHRT_WIDTH) b)
{
#define  MY_USHRT_SHLR(A, B, ...) ((ushort) (((unsigned) A)>>(USHRT_WIDTH-B)))
#define     USHRT_SHLR(...) MY_USHRT_SHLR(__VA_ARGS__,1)
    return  a>>(USHRT_WIDTH-b);
}

INLINE( short,  SHRT_SHLR)   (signed a, Rc(0,   SHRT_WIDTH) b)
{
#define  MY_SHRT_SHLR(A, B, ...) ((short) (((unsigned) A)>>(SHRT_WIDTH-B)))
#define     SHRT_SHLR(...) MY_SHRT_SHLR(__VA_ARGS__,1)
    return  (unsigned) a>>(SHRT_WIDTH-b);
}


INLINE(  uint,  UINT_SHLR)     (uint a, Rc(0,   UINT_WIDTH) b)
{
#define  MY_UINT_SHLR(A, B, ...) ((uint) A>>(UINT_WIDTH-B))
#define     UINT_SHLR(...) MY_UINT_SHLR(__VA_ARGS__,1)
    return  a>>(UINT_WIDTH-b);
}

INLINE(   int,   INT_SHLR)      (int a, Rc(0,    INT_WIDTH) b)
{
#define  MY_INT_SHLR(A, B, ...) ((int) (((uint64_t) A)>>(INT_WIDTH-B)))
#define     INT_SHLR(...) MY_INT_SHLR(__VA_ARGS__,1)
    return  (uint64_t) a>>(INT_WIDTH-b);
}


INLINE( ulong, ULONG_SHLR)    (ulong a, Rc(0,  ULONG_WIDTH) b)
{
#define  MY_ULONG_SHLR(A, B, ...) ((ulong) A>>(ULONG_WIDTH-B))
#define     ULONG_SHLR(...) MY_ULONG_SHLR(__VA_ARGS__,1)
    return  a>>(ULONG_WIDTH-b);
}

INLINE(  long,  LONG_SHLR)     (long a, Rc(0,   LONG_WIDTH) b)
{
#if DWRD_NLONG == 2
#   define  MY_LONG_SHLR(A, B, ...) ((long) (((uint64_t) A)>>(LONG_WIDTH-B)))
    return  (uint64_t) a>>(64-b);
#else
#   define  MY_LONG_SHLR(A, B, ...) ((LONG_SHLR)(A,B))
    uint32_t c = 64-b;
    uint64_t z = a;
    uint64_t s = (0-(z>>63))<<c;
    return s|(z>>c);
#endif
#define     LONG_SHLR(...) MY_LONG_SHLR(__VA_ARGS__,1)
}


INLINE(ullong,ULLONG_SHLR)   (ullong a, Rc(0, ULLONG_WIDTH) b)
{
#define  MY_ULLONG_SHLR(A, B, ...) ((ullong) A>>(ULLONG_WIDTH-B))
#define     ULLONG_SHLR(...) MY_ULLONG_SHLR(__VA_ARGS__,1)
    return  a>>(ULLONG_WIDTH-b);
}

INLINE( llong, LLONG_SHLR)    (llong a, Rc(0,  LLONG_WIDTH) b)
{
#define  MY_LLONG_SHLR(A, B, ...) ((LLONG_SHLR)(A,B))
#define     LLONG_SHLR(...) MY_LLONG_SHLR(__VA_ARGS__,1)
    unsigned c = LLONG_WIDTH-b;
    ullong   z = a;
    ullong   s = (0-(z>>(LLONG_WIDTH-1)))<<c;
    return  s|(z>>c);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,shlrqu) (QUAD_UTYPE a, Rc(0, 128) b) 
{
#if defined(__SIZEOF_INT128__)
#   define  shlrqu(A, B) ((QUAD_UTYPE) A>>(128-B))
    return  a>>(128-b);
#else
    unsigned n = 128-b;
    QUAD_TYPE   c = {.U=a};
    uint64_t    l = c.Lo.U;
    uint64_t    r = c.Hi.U;
    if (n < 64)
    {
        c.Lo.U = (l<<n);
        c.Hi.U = (r<<n)|(l>>(64-n));
    }
    else
    {
        c.Lo.U = 0;
        c.Hi.U = (l<<(n-64));
    }
    return  c.U;
#endif

}

INLINE(QUAD_ITYPE,shlrqi) (QUAD_ITYPE a, Rc(0, 128) b) 
{
    return  a>>(128-b);
}

#endif

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

INLINE(void *,ADDR_ADDL) (void const *a, ptrdiff_t b) 
{
    return (void *)(a+b);
}

INLINE( _Bool,  BOOL_ADDL)    (_Bool a,    _Bool b) {return a^b;}
INLINE( uchar, UCHAR_ADDL) (unsigned a, unsigned b) 
{
    return (uchar) a+(uchar) b;
}

INLINE( schar, SCHAR_ADDL)   (signed a,   signed b) 
{
    return (schar) a+(schar) b;
}

INLINE(  char,  CHAR_ADDL)      (int a,      int b) 
{
    return  (char) a+(char) b;
}

INLINE(ushort, USHRT_ADDL) (unsigned a, unsigned b) 
{
    return (ushort) a+(ushort) b;
}

INLINE( short,  SHRT_ADDL)   (signed a,   signed b) 
{
    return  (short) a+(short) b;
}

INLINE(  uint,  UINT_ADDL)     (uint a,     uint b) {return a+b;}
INLINE(   int,   INT_ADDL)      (int a,      int b) {return UINT_ADDL(a,b);}
INLINE( ulong, ULONG_ADDL)    (ulong a,    ulong b) {return a+b;}
INLINE(  long,  LONG_ADDL)     (long a,     long b) {return ULONG_ADDL(a,b);}
INLINE(ullong,ULLONG_ADDL)   (ullong a,   ullong b) {return a+b;}
INLINE( llong, LLONG_ADDL)    (llong a,    llong b) {return ULLONG_ADDL(a,b);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,addlqu) (QUAD_UTYPE a, QUAD_UTYPE b) 
{
#if defined(__SIZEOF_INT128__)
    return  a+b;
#else
    QUAD_TYPE c, p={.U=a}, q={.U=b};
    c.Lo.U = (p.Lo.U+q.Lo.U);
    c.Hi.U = (p.Hi.U+q.Hi.U)+(c.Lo.U<p.Lo.U);
    return  c.U;
#endif
}

INLINE(QUAD_ITYPE,addlqi) (QUAD_ITYPE a, QUAD_ITYPE b) 
{
    QUAD_TYPE c, p={.I=a}, q={.I=b};
#if defined(__SIZEOF_INT128__)
    c.U = p.U+q.U;
#else
    c.Lo.U = (p.Lo.U+q.Lo.U);
    c.Hi.U = (p.Hi.U+q.Hi.U)+(c.Lo.U<p.Lo.U);
#endif
    return  c.I;
}
#endif

#if 0 // _LEAVE_ALL_ADDL
}
#endif

#if 0 // _ENTER_ALL_ADD2
{
#endif

INLINE(uint16_t,UCHAR_ADD2) (unsigned a, unsigned b) 
{
    return  (uchar) a+(uint8_t) b;
}

INLINE( int16_t,SCHAR_ADD2)   (signed a,   signed b) 
{
    return  (schar) a+(int8_t) b;
}

#if CHAR_MIN

INLINE( int16_t, CHAR_ADD2)      (int a,      int b) 
{
    return  (char) a+(char) b;
}

#else

INLINE(uint16_t,CHAR_ADD2)       (int a,      int b) 
{
    return  (char) a+(char) b;
}

#endif

INLINE(uint32_t,USHRT_ADD2)  (unsigned a,  unsigned b) 
{
    return (ushort) a+(ushort) b;
}

INLINE( int32_t, SHRT_ADD2)    (signed a,    signed b) 
{
    return (short) a+(short) b;
}

INLINE(uint64_t,  UINT_ADD2)     (uint a,      uint b) 
{
    return (uint64_t) a+b;
}

INLINE( int64_t,   INT_ADD2)      (int a,       int b) 
{
    return (int64_t) a+b;
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_ADD2)    (ulong a,     ulong b) 
{
    return (uint64_t) a+b;
}

INLINE( int64_t,  LONG_ADD2)   (long a,  long b) 
{
    return (int64_t) a+b;
}

#else

INLINE(QUAD_UTYPE,ULONG_ADD2)  (ulong a, ulong b) 
{
    QUAD_TYPE   p={.Lo.U=a}, q={.Lo.U=b}, r;
    r.Lo.U = p.Lo.U+q.Lo.U;
    r.Hi.U = r.Lo.U < p.Lo.U;
    return  r.U;
}

INLINE(QUAD_ITYPE,LONG_ADD2)  (long a, long b) 
{
    QUAD_TYPE   p={.Lo.I=a}, q={.Lo.I=b}, r;
    r.Lo.U = p.Lo.U+q.Lo.U;
    r.Hi.U = r.Lo.U < p.Lo.U;
    return  r.I;
}

#endif

#if QUAD_NLLONG == 1

INLINE(ullong, ULONG_ADD2)  (ulong a, ulong b) 
{
    return (ullong) a+b;
}

INLINE( llong, LONG_ADD2)  (long a, long b) 
{
    return (llong) a+b;
}

#else

INLINE(QUAD_UTYPE,ULLONG_ADD2)  (ullong a, ullong b) 
{
    QUAD_TYPE   p={.Lo.U=a}, q={.Lo.U=b}, r;
    r.Lo.U = p.Lo.U+q.Lo.U;
    r.Hi.U = r.Lo.U < p.Lo.U;
    return  r.U;
}

INLINE(QUAD_ITYPE,LLONG_ADD2)  (llong a, llong b) 
{
    QUAD_TYPE   p={.Lo.I=a}, q={.Lo.I=b}, r;
    r.Lo.U = p.Lo.U+q.Lo.U;
    r.Hi.U = r.Lo.U < p.Lo.U;
    return  r.I;
}

#endif

#if 0 // _LEAVE_ALL_ADD2
}
#endif

#if 0 // _ENTER_ALL_ADD3
{
#endif

INLINE(uint,UINT_ADD3) (uint a, unsigned b) 
{
    return  a+(uint8_t) b;
}

INLINE(int, INT_ADD3) (int a, signed b) 
{
    return  (uint32_t) a+(uint8_t) b;
}


#if DWRD_NLONG == 2

INLINE(ulong, ULONG_ADD3)  (ulong a, unsigned b) 
{
    return a+(uint8_t) b;
}

INLINE( long,  LONG_ADD3)   (long a,  signed b) 
{
    return (uint32_t) a+(uint8_t) b;
}

#else

INLINE(ulong, ULONG_ADD3)  (ulong a, unsigned b) 
{
    return a+(uint16_t) b;
}

INLINE( long,  LONG_ADD3)   (long a,  signed b) 
{
    return (uint64_t) a+(uint16_t) b;
}

#endif


#if QUAD_NLLONG == 2

INLINE(ullong,ULLONG_ADD3)  (ullong a, unsigned b) 
{
    return a+(uint16_t) b;
}

INLINE( llong, LLONG_ADD3)   (llong a,  signed b) 
{
    return (uint64_t) a+(uint16_t) b;
}

INLINE(QUAD_UTYPE,add3qu)  (QUAD_UTYPE a, uint32_t b) 
{
    QUAD_TYPE   v = {.U=a};
    uint64_t    c = v.Lo.U;
    v.Lo.U += b;
    v.Hi.U += (v.Lo.U < c);
    return  v.U;
}

INLINE(QUAD_ITYPE,add3qi)  (QUAD_ITYPE a, int32_t b) 
{
    QUAD_TYPE   v = {.I=a};
    uint64_t    c = v.Lo.U;
    v.Lo.U += b;
    v.Hi.U += (v.Lo.U < c);
    return  v.I;
}

#else

INLINE(ullong,ULLONG_ADD3)  (ullong a, uint32_t b) 
{
    return a+b;
}

INLINE( llong, LLONG_ADD3)   (llong a,  int32_t b) 
{
    return (ullong) a+(uint32_t) b;
}

#endif

#if 0 // _LEAVE_ALL_ADD3
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
/*  Wouldn't (ushort) a*(ushort) b be undefined if a×b is 
    greater than INT_MAX, like would be the case for 
    USHRT_MUL2(65535, 65535), since ushort is implicitly
    converted to int? 
*/
    return  (0xffffU&a)*(ushort) b;
}

INLINE( int32_t,  SHRT_MUL2)     (signed a,   signed b)
{
    return  (short) a*(short) b;
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

INLINE(   uint64_t, ULONG_MUL2)   (ulong a,    ulong b)
{
    return  (uint64_t) a*b;
}

INLINE(    int64_t,  LONG_MUL2)    (long a,     long b)
{
    return  ULONG_MUL2(a, b);
}

#else

INLINE(QUAD_UTYPE,  ULONG_MUL2)   (ulong a,    ulong b)
{
    QUAD_TYPE   q;
#if defined(__SIZEOF_INT128__)
    q.U = (QUAD_UTYPE) a*b;
#elif defined(_MSC_VER)
    q.Lo.I = _mul128(a, b, ((void *) &q.Hi.I));
#else
    uint64_t p;
    uint64_t x = (uint32_t) a;
    uint64_t y = (uint32_t) b;
    uint64_t c = x*y;
    uint64_t l = (uint32_t) c;
    uint64_t r = c>>32;
    a >>= 32;
    c = (a * y) + r;
    r = (uint32_t) c;
    p = c>>32;
    b >>= 32;
    c = (x * b) + r;
    r = (c >> 32);
    q.Hi.U = (p+r)+a*b;
    q.Lo.U = l+(c<<32);
#endif
    return  q.U;
}

INLINE(QUAD_ITYPE,   LONG_MUL2)    (long a,     long b)
{
    QUAD_TYPE c = {.U=ULONG_MUL2(a, b)};
    return  c.I;
}

#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE, ULLONG_MUL2)  (ullong a,  ullong b)
{
    QUAD_TYPE   q;
#if defined(__SIZEOF_INT128__)
    q.U = (QUAD_UTYPE) a*b;
#elif defined(_MSC_VER)
    q.Lo.I = _umul128(a, b, ((void *) &q.Hi.U));
#else
    uint64_t p;
    uint64_t x = (uint32_t) a;
    uint64_t y = (uint32_t) b;
    uint64_t c = x*y;
    uint64_t l = (uint32_t) c;
    uint64_t r = c>>32;
    a >>= 32;
    c = (a * y) + r;
    r = (uint32_t) c;
    p = c>>32;
    b >>= 32;
    c = (x * b) + r;
    r = (c >> 32);
    q.Hi.U = (p+r)+a*b;
    q.Lo.U = l+(c<<32);
#endif
    return  q.U;
}

INLINE(QUAD_ITYPE,  LLONG_MUL2)   (llong a,   llong b)
{
    QUAD_TYPE c = {.U=ULLONG_MUL2(a, b)};
    return  c.I;
}

#endif

#if 0 // _LEAVE_ALL_MUL2
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

INLINE( schar, SCHAR_MULL)   (signed a,   signed b) 
{
    return  (schar) a*(schar) b;
}

INLINE(  char,  CHAR_MULL)      (int a,      int b) 
{
    return  (char) a*(char) b;
}

INLINE(ushort, USHRT_MULL) (unsigned a, unsigned b) 
{
    return  (a&USHRT_MAX)*(ushort) b;
}
INLINE( short,  SHRT_MULL)   (signed a,   signed b) 
{
    a = (short) a;
    return (unsigned) a*(short) b;
}

INLINE(  uint,  UINT_MULL)     (uint a,     uint b) {return a*b;}
INLINE(   int,   INT_MULL)      (int a,      int b) {return UINT_MULL(a,b);}
INLINE( ulong, ULONG_MULL)    (ulong a,    ulong b) {return a*b;}
INLINE(  long,  LONG_MULL)     (long a,     long b) {return ULONG_MULL(a,b);}
INLINE(ullong,ULLONG_MULL)   (ullong a,   ullong b) {return a*b;}
INLINE( llong, LLONG_MULL)    (llong a,    llong b) {return ULLONG_MULL(a,b);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,mullqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{    
#if 0 && defined(__SIZEOF_INT128__)
    return  a*b;
#else
    QUAD_TYPE x={.U=a}, y={.U=b}, z;
    z.U = UINT64_MUL2(x.Lo.U, y.Lo.U);
    z.Hi.U += x.Lo.U*y.Hi.U+x.Hi.U*y.Lo.U;
    return z.U;
#endif
}

INLINE(QUAD_ITYPE,mullqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    return  asqiqu(mullqu(asquqi(a), asquqi(b)));
}

#endif

#if 0 // _LEAVE_ALL_MULL
}
#endif


#if 0 // _ENTER_ALL_MULR
{
#endif

INLINE( uchar, UCHAR_MULR) (unsigned a, unsigned b)
{
    return  ((uchar) a*(uchar) b)>>UCHAR_WIDTH;
}

INLINE( schar, SCHAR_MULR)   (signed a,   signed b)
{
    return  ((schar) a*(schar) b)>>SCHAR_WIDTH;
}

INLINE( char,   CHAR_MULR)      (int a,      int b)
{
    return  ((char) a*(char) b)>>CHAR_WIDTH;
}

INLINE(ushort, USHRT_MULR) (unsigned a, unsigned b)
{
    return  ((ushort) a*(ushort) b)>>USHRT_WIDTH;
}

INLINE( short,  SHRT_MULR)   (signed a,   signed b)
{
    return  ((short) a*(short) b)>>SHRT_WIDTH;
}

INLINE(  uint,  UINT_MULR)     (uint a,     uint b)
{
    return  ((uint64_t) a*b)>>UINT_WIDTH;
}

INLINE(   int,   INT_MULR)      (int a,      int b)
{
    return  ((int64_t) a*b)>>INT_WIDTH;
}

INLINE( ulong, ULONG_MULR)    (ulong a,    ulong b)
{
#if ULONG_WIDTH == UINT_WIDTH
    return  UINT_MULR(a, b);

#elif defined(__SIZEOF_INT128__)
    return  ((unsigned __int128) a*b)>>64;

#elif defined(_MSC_VER)
    return  _umulh(a, b);

#else
    QUAD_TYPE c = {.U=ULONG_MUL2(a, b)};
    return  c.Hi.U;
#endif
}

INLINE(  long,  LONG_MULR)     (long a,     long b)
{
#if LONG_WIDTH == INT_WIDTH

#elif defined(__SIZEOF_INT128__)
    return  ((signed __int128) a*b)>>64;
#elif defined(_MSC_VER)
    return  _mulh(a, b);
#else
    QUAD_TYPE c = {.I=LONG_MUL2(a, b)};
    return  c.Hi.I;
#endif

}

#if QUAD_NLLONG == 2

INLINE(ullong,ULLONG_MULR)   (ullong a,   ullong b)
{
#if ULLONG_WIDTH == ULONG_WIDTH
    return  ULONG_MULR(a, b);
    
#elif defined(__SIZEOF_INT128__)
    return  ((unsigned __int128) a*b)>>64;

#elif defined(_MSC_VER)
    return  _umulh(a, b);

#else
    QUAD_TYPE c = {.U=ULONG_MUL2(a, b)};
    return  c.Hi.U;

#endif
}

INLINE( llong, LLONG_MULR)    (llong a,    llong b)
{
#if LLONG_WIDTH == LONG_WIDTH
    return  LONG_MULR(a, b);
    
#elif defined(__SIZEOF_INT128__)
    return  ((signed __int128) a*b)>>64;

#elif defined(_MSC_VER)
    return  _mulh(a, b);

#else
    QUAD_TYPE c = {.I=LONG_MUL2(a, b)};
    return  c.Hi.I;

#endif
}

#endif

#if 0 // _LEAVE_ALL_MULR
}
#endif


#if 0 // _ENTER_ALL_ICRL
{
#endif

INLINE(void *,  ADDR_ICRL) (void const *a) {return ADDR_ADDL(a, 1);}
INLINE( _Bool,  BOOL_ICRL)    (_Bool a) {return   BOOL_ADDL(a, 1);}
INLINE( uchar, UCHAR_ICRL) (unsigned a) {return  UCHAR_ADDL(a, 1);}
INLINE( schar, SCHAR_ICRL)   (signed a) {return  SCHAR_ADDL(a, 1);}
INLINE(  char,  CHAR_ICRL)      (int a) {return   CHAR_ADDL(a, 1);}
INLINE(ushort, USHRT_ICRL) (unsigned a) {return  USHRT_ADDL(a, 1);}
INLINE( short,  SHRT_ICRL)   (signed a) {return   SHRT_ADDL(a, 1);}
INLINE(  uint,  UINT_ICRL)     (uint a) {return   UINT_ADDL(a, 1);}
INLINE(   int,   INT_ICRL)      (int a) {return    INT_ADDL(a, 1);}
INLINE( ulong, ULONG_ICRL)    (ulong a) {return  ULONG_ADDL(a, 1);}
INLINE(  long,  LONG_ICRL)     (long a) {return   LONG_ADDL(a, 1);}
INLINE(ullong,ULLONG_ICRL)   (ullong a) {return ULLONG_ADDL(a, 1);}
INLINE( llong, LLONG_ICRL)    (llong a) {return  LLONG_ADDL(a, 1);}

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,icrlqu) (QUAD_UTYPE a) 
{
#if defined(__SIZEOF_INT128__)
    return  addlqu(a, 1);
#else
    return  addlqu(a, cvquwu(1));
#endif
}

INLINE(QUAD_ITYPE,icrlqi) (QUAD_ITYPE a) 
{
#if defined(__SIZEOF_INT128__)
    return  addlqi(a, 1);
#else
    return  addlqi(a, cvqiwu(1));
#endif
}

#endif

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

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,dcrlqu) (QUAD_UTYPE a) 
{
    QUAD_TYPE b={.U=a}, c;
    c.Lo.U = b.Lo.U-1;
    c.Hi.U = b.Hi.U-(c.Lo.U > b.Lo.U);
    return  c.U;
}

INLINE(QUAD_ITYPE,dcrlqi) (QUAD_ITYPE a) 
{
    QUAD_TYPE b={.I=a}, c;
    c.Lo.U = b.Lo.U-1;
    c.Hi.U = b.Hi.U-(b.Lo.U < c.Lo.U);
    return  c.I;
}
#endif

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

#if 0 // _ENTER_ALL_SUBL
{
#endif

INLINE(ptrdiff_t,ADDR_SUBL) (void const *a, void const *b)
{
    return a-b;
}

INLINE( _Bool,  BOOL_SUBL)    (_Bool a,    _Bool b) {return a^b;}
INLINE( uchar, UCHAR_SUBL) (unsigned a, unsigned b) 
{
    return  (uchar) a-(uchar) b;
}

INLINE( schar, SCHAR_SUBL)   (signed a,   signed b) 
{
    return  (schar) a-(schar) b;
}

INLINE(  char,  CHAR_SUBL)      (int a,      int b) 
{
    return  (char) a-(char) b;
}

INLINE(ushort, USHRT_SUBL) (unsigned a, unsigned b) 
{
    return  (ushort) a-(ushort) b;
}

INLINE( short,  SHRT_SUBL)   (signed a,   signed b) 
{
    return  (short) a-(short) b;
}

INLINE(  uint,  UINT_SUBL)     (uint a,     uint b) {return a-b;}
INLINE(   int,   INT_SUBL)      (int a,      int b) {return UINT_SUBL(a,b);}
INLINE( ulong, ULONG_SUBL)    (ulong a,    ulong b) {return a-b;}
INLINE(  long,  LONG_SUBL)     (long a,     long b) {return ULONG_SUBL(a,b);}
INLINE(ullong,ULLONG_SUBL)   (ullong a,   ullong b) {return a-b;}
INLINE( llong, LLONG_SUBL)    (llong a,    llong b) {return ULLONG_SUBL(a,b);}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,sublqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE c;
#if defined(__SIZEOF_INT128__)
    c.U = a-b;
#else
    QUAD_TYPE p={.U=a}, q={.U=b};
    c.Lo.U = (p.Lo.U-q.Lo.U);
    c.Hi.U = (p.Hi.U-q.Hi.U)-(c.Lo.U>p.Lo.U);
#endif
    return  c.U;
}

INLINE(QUAD_ITYPE,sublqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE x={.I=a}, y={.I=b};
    x.U = sublqu(x.U, y.U);
    return x.I;
}

#endif

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
INLINE( uchar, UCHAR_DIFU) (unsigned a, unsigned b) 
{
    uchar l=a, r=b;
    return  (l < r) ? r-l : l-r;
}

INLINE( uchar, SCHAR_DIFU)   (signed a,   signed b) 
{
    schar l=a, r=b;
    return  (l < r) ? r-l : l-r;
}

INLINE( uchar,  CHAR_DIFU)      (int a,      int b) 
{
    char l=a, r=b;
    return  (l < r) ? r-l : l-r;
}

INLINE(ushort, USHRT_DIFU) (unsigned a, unsigned b) 
{
    ushort l=a, r=b;
    return  (l < r) ? r-l : l-r;
}

INLINE(ushort,  SHRT_DIFU)   (signed a,   signed b) 
{
    short l=a, r=b;
    return  (l < r) ? r-l : l-r;
}

INLINE(  uint,  UINT_DIFU)     (uint a,     uint b) {return a<b ? b-a : a-b;}
INLINE(  uint,   INT_DIFU)      (int a,      int b) {return a<b ? b-a : a-b;}
INLINE( ulong, ULONG_DIFU)    (ulong a,    ulong b) {return a<b ? b-a : a-b;}
INLINE( ulong,  LONG_DIFU)     (long a,     long b) {return a<b ? b-a : a-b;}
INLINE(ullong,ULLONG_DIFU)   (ullong a,   ullong b) {return a<b ? b-a : a-b;}
INLINE(ullong, LLONG_DIFU)    (llong a,    llong b) {return a<b ? b-a : a-b;}
#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,difuqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    return (cltlqu(a, b)) ? sublqu(a, b) : sublqu(b, a);
}

INLINE(QUAD_UTYPE,difuqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    a = (cltlqi(a, b)) ? sublqi(a, b) : sublqi(b, a);
    return  cvquqi(a);
}
#endif

#if 0 // _LEAVE_ALL_DIFU
}
#endif

#if 0 // _ENTER_ALL_FAML
{
#endif

INLINE( void *,  ADDR_FAML) (void const *a, ptrdiff_t b, ptrdiff_t c)
{
    return  (void *) (a+(size_t) b*(size_t) c);
}

INLINE(  _Bool,  BOOL_FAML)       (_Bool a,     _Bool b,     _Bool c) 
{
    return a+b*c;
}

INLINE(  uchar, UCHAR_FAML)    (unsigned a,  unsigned b,  unsigned c) 
{
    return  (uchar) a+(uchar) b*(uchar) c;
}

INLINE(  schar, SCHAR_FAML)      (signed a,    signed b,    signed c) 
{
    return  (schar) a+(schar) b*(schar) c;
}

INLINE(   char,  CHAR_FAML)         (int a,       int b,       int c) 
{
#if CHAR_MIN
    return  SCHAR_FAML(a, b, c);
#else
    return  UCHAR_FAML(a, b, c);
#endif
}

INLINE( ushort, USHRT_FAML)    (unsigned a,  unsigned b,  unsigned c) 
{
    return  (ushort) a+(ushort) b*(ushort) c;
}

INLINE(  short,  SHRT_FAML)      (signed a,    signed b,    signed c) 
{
    return (short) a+(short) b*(short) c;
}

INLINE(   uint,  UINT_FAML)        (uint a,      uint b,      uint c) 
{
    return  a+b*c;
}

INLINE(    int,   INT_FAML)         (int a,       int b,       int c) 
{
    return  UINT_FAML(a, b, c);
}

INLINE(  ulong, ULONG_FAML)       (ulong a,     ulong b,     ulong c) 
{
    return  a+b*c;
}

INLINE(   long,  LONG_FAML)        (long a,      long b,      long c) 
{
    return  ULONG_FAML(a, b, c);
}

INLINE( ullong,ULLONG_FAML)      (ullong a,    ullong b,    ullong c) 
{
    return  a+b*c;
}

INLINE(  llong, LLONG_FAML)       (llong a,     llong b,     llong c) 
{
    return  ULLONG_FAML(a, b, c);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,famlqu) (QUAD_UTYPE a, QUAD_UTYPE b, QUAD_UTYPE c)
{
    return  addlqu(a, mullqu(b, c));
}

INLINE(QUAD_ITYPE,famlqi) (QUAD_ITYPE a, QUAD_ITYPE b, QUAD_ITYPE c)
{
    return  addlqi(a, mullqi(b, c));
}

#endif

#if 0 // _LEAVE_ALL_FAML
}
#endif

#if 0 // _ENTER_ALL_FAM2
{
#endif

INLINE(ushort, USHRT_FAM2) (unsigned a,  unsigned b,  unsigned c)
{
    return  (ushort) a+(uint8_t) b*(uint8_t) c;
}

INLINE(short, SHRT_FAM2) (signed a,  signed b,  signed c)
{
    return  (short) a+(int8_t) b*(int8_t) c;
}

INLINE(  uint,  UINT_FAM2)   (uint a,  unsigned b,  unsigned c)
{
    return a+(uint16_t) b*(uint16_t) c;
}

INLINE(   int,   INT_FAM2)    (int a,  signed b,  signed c)
{
    return  (int64_t) a+((int16_t) a*(int16_t) b);
}

#if DWRD_NLONG == 2

INLINE( ulong, ULONG_FAM2)  (ulong a, unsigned b, unsigned c)
{
    return  UINT_FAM2(a, b, c);
}

INLINE(  long,  LONG_FAM2)   (long a,  signed b,  signed c)
{
    return  INT_FAM2(a, b, c);
}

#else

INLINE( ulong, ULONG_FAM2)  (ulong a, uint32_t b, uint32_t c)
{
    return  a+((ulong) b*c);
}

INLINE(  long,  LONG_FAM2)   (long a,  int32_t b,  int32_t c)
{
    return  (ulong) a+((int64_t) b*c);
}

#endif

#if QUAD_NLLONG == 2

INLINE(ullong,ULLONG_FAM2) (ullong a, uint32_t b, uint32_t c)
{
    return  a+(ullong) b*c;
}

INLINE( llong, LLONG_FAM2)  (llong a,  int32_t b,  int32_t c)
{
    return  (ullong) a+((llong) b*c);
}

INLINE(QUAD_UTYPE,fam2qu) (QUAD_UTYPE a, uint64_t b, uint64_t c)
{
#if defined(__SIZEOF_INT128__)
    return  a+((unsigned __int128) b*c);
#else
    return  addlqu(a, mul2qu(b, c));
#endif
}

INLINE(QUAD_ITYPE,fam2qi) (QUAD_ITYPE a,  int64_t b,  int64_t c)
{
#if defined(__SIZEOF_INT128__)
    return  (unsigned __int128) a+((unsigned __int128) b*c);
#else
    return  addlqu(a, mul2qu(b, c));
#endif
}

#else

INLINE(ullong,ULLONG_FAM2) (ullong a, uint64_t b, uint64_t c)
{
    return a+(ullong) b*c;
}

INLINE( llong, LLONG_FAM2)  (llong a,  int64_t b,  int64_t c)
{
    return (ullong) a+((llong) b*c);
}

#endif

#if 0 // _LEAVE_ALL_FAM2
}
#endif

#if 0 // _ENTER_ALL_FSML
{
#endif

INLINE( void *,  ADDR_FSML) (void const *a, ptrdiff_t b, ptrdiff_t c)
{
    return  (void *) (a-(size_t) b*(size_t) c);
}

INLINE(  _Bool,  BOOL_FSML)       (_Bool a,     _Bool b,     _Bool c) 
{
    return a-b*c;
}

INLINE(  uchar, UCHAR_FSML)    (unsigned a,  unsigned b,  unsigned c) 
{
    return  (uchar) a-(uchar) b*(uchar) c;
}

INLINE(  schar, SCHAR_FSML)      (signed a,    signed b,    signed c) 
{
    return  (schar) a-(schar) b*(schar) c;
}

INLINE(   char,  CHAR_FSML)         (int a,       int b,       int c) 
{
#if CHAR_MIN
    return  SCHAR_FSML(a, b, c);
#else
    return  UCHAR_FSML(a, b, c);
#endif
}

INLINE( ushort, USHRT_FSML)    (unsigned a,  unsigned b,  unsigned c) 
{
    return  (ushort) a-(ushort) b*(ushort) c;
}

INLINE(  short,  SHRT_FSML)      (signed a,    signed b,    signed c) 
{
    return (short) a-(short) b*(short) c;
}

INLINE(   uint,  UINT_FSML)        (uint a,      uint b,      uint c) 
{
    return  a-b*c;
}

INLINE(    int,   INT_FSML)         (int a,       int b,       int c) 
{
    return  UINT_FSML(a, b, c);
}

INLINE(  ulong, ULONG_FSML)       (ulong a,     ulong b,     ulong c) 
{
    return  a-b*c;
}

INLINE(   long,  LONG_FSML)        (long a,      long b,      long c) 
{
    return  ULONG_FSML(a, b, c);
}

INLINE( ullong,ULLONG_FSML)      (ullong a,    ullong b,    ullong c) 
{
    return  a-b*c;
}

INLINE(  llong, LLONG_FSML)       (llong a,     llong b,     llong c) 
{
    return  ULLONG_FSML(a, b, c);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,fsmlqu)    (QUAD_UTYPE a, QUAD_UTYPE b, QUAD_UTYPE c)
{
#if defined(__SIZEOF_INT128__)
    return  a-b*c;
#else
    return  sublqu(a, mullqu(b, c));
#endif
}

INLINE(QUAD_ITYPE,fsmlqi) (QUAD_ITYPE a, QUAD_ITYPE b, QUAD_ITYPE c)
{
    QUAD_TYPE x={.I=a}, y={.I=b}, z={.I=c};
    x.U = fsmlqu(x.U, y.U, z.U);
    return  x.I;
}

#endif

#if 0 // _LEAVE_ALL_FSML
}
#endif


#if 0 // _ENTER_ALL_DIVL
{
#endif

INLINE( uchar, UCHAR_DIVL) (unsigned a, unsigned b) {return (uchar) a/b;}
INLINE( schar, SCHAR_DIVL)   (signed a,   signed b) {return (schar) a/b;}
INLINE(  char,  CHAR_DIVL)      (int a,      int b) {return (char) a/b;}
INLINE(ushort, USHRT_DIVL) (unsigned a, unsigned b) {return (ushort) a/b;}
INLINE( short,  SHRT_DIVL)   (signed a,   signed b) {return (short) a/b;}
INLINE(  uint,  UINT_DIVL)     (uint a,     uint b) {return a/b;}
INLINE(   int,   INT_DIVL)      (int a,      int b) {return a/b;}
INLINE( ulong, ULONG_DIVL)    (ulong a,    ulong b) {return a/b;}
INLINE(  long,  LONG_DIVL)     (long a,     long b) {return a/b;}
INLINE(ullong,ULLONG_DIVL)   (ullong a,   ullong b) {return a/b;}
INLINE( llong, LLONG_DIVL)    (llong a,    llong b) {return a/b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,divlqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE oria={.U=a}, orib={.U=b};
    if (ceqyqu(a, b)) 
        cvquwu(1U);
    if (cltyqu(a, b)) 
        return  ((QUAD_UTYPE){0});
    QUAD_TYPE   x, m, n, p, q={.U=a};
    if (q.Hi.U == 0)
    {
        p.U = b;
        q.Lo.U = UINT64_DIVL(q.Lo.U, p.Lo.U);
        return  q.U;
    }
    int y, z;
    p.U = cszrqu(a); 
    q.U = cszrqu(b);
    y = (128-cvwiqu(p.U));
    z = (128-cvwiqu(q.U));
    y = y-z;
    if ((y < 0) || (y > 128))
    {
        printf("(128-cszr(a))-(128-cszr(b)) = %d\n",y);
        return  cvquwi(-1);
    }
    if (1 == y)
    {
        n.U = shllqu(b, 1);
        if (ceqyqu(a, n.U))
            return  UINT32_CVQU(2);
        if (cltyqu(a, n.U))
            return  UINT32_CVQU(1);
        n.U = sublqu(a, n.U);
        if (cgtyqu(b, n.U))
            return  UINT32_CVQU(2);
        else
            return  UINT32_CVQU(3);
    }
    for (y++;; y--)
    {
        p.U = ((shllqu)(b, y));
        if (!cltyqu(a, p.U))
            break;
    }
    n.U = ((sublqu)(a, p.U));
    q.U = ((shllqu)(cvquwu(1), y));
    if (cltyqu(n.U, b))
        return q.U;
    do {
        y--;
        x.U = ((shllqu)(b, y));
        n.U = ((addlqu)(p.U, x.U));
        if (cltyqu(a, n.U))
        {
            m.U = sublqu(n.U, a);
            if (cltyqu(m.U, b))
            {
                x.U = cvquwu(1);
                x.U = (shllqu)(x.U, y);
                q.U = orrsqu(q.U, x.U);
                return  dcrlqu(q.U);
            }
        }
        else
        {
            x.U = ((shllqu)(cvquwu(1), y));
            q.U = orrsqu(q.U, x.U);
            m.U = sublqu(a, n.U);
            if (cltyqu(m.U, b))
                return  q.U;
            p = n;
        }

    } while (y > 0);
    char stra[256], strb[256], *enda, *endb;
    printf(
        "infinite loop in divlqu(%s, %s)", 
        safe_toadqu(oria.U, stra, &enda),
        safe_toadqu(orib.U, strb, &endb)
    );
    return  INT32_CVQU(-1);
}

#if 0
{
/*  unsigned 128 bit/64 bit division. Technically, divisors
    wider than 64 bits result in undefined behavior. However,
    as long as the dividend is greater than or equal to the
    divisor, all 128 bit inputs should return the correct
    quotient.
*/
#if defined(__SIZEOF_INT128__)
    return  a/b;
#else
//  if (a <= b), the quotient can only be 0 or 1
    QUAD_TYPE   x, m, n, p, q={.U=a};
    n.U = ceqlqu(a, b);
    if (n.Lo.U || cltyqu(a, b))
        return  n.U;

//  if (a.len <= 64), use 64 bit fast path
    if (q.Hi.U == 0)
    {
        q.Lo.U = UINT64_DIVL(q.Lo.U, ((QUAD_TYPE){.U=b}).Lo.U);
        return  q.U;
    }

    int y, z;
    p.U = cszrqu(a); 
    q.U = cszrqu(b);
    y = (128-cvwiqu(p.U));
    z = (128-cvwiqu(q.U));
    y = y-z;

    if (1 == y)
    {
/*
    When the difference in repr length is 1, the quotient 
    will be 1, 2, or 3. TODO: check if this branch can be 
    removed and if so, what the performance implications are
    for the cases it covers. The only possible time this 
    branch is taken without invoking undefined behavior is 
    with a 65 bit dividend and 64 bit divisor, which seems an
    extremely unlikely scenario. 
*/
        n.U = shllqu(b, 1);
        if (ceqyqu(a, n.U))
            return UINT32_CVQU(2);

        if (cltyqu(a, n.U))
            return UINT32_CVQU(1);

        n.U = sublqu(a, n.U);

        if (cgtyqu(b, n.U))
            return  UINT32_CVQU(2);
        else
            return  UINT32_CVQU(3);
    }
    for (y++;; y--)
    {
        p.U = ((shllqu)(b, y));
        if (!cltyqu(a, p.U))
            break;
    }
    n.U = ((sublqu)(a, p.U));
    q.U = ((shllqu)(cvquwu(1), y));
    if (cltyqu(n.U, b))
        return q.U;
    do {
        y--;
        x.U = ((shllqu)(b, y));
        n.U = ((addlqu)(p.U, x.U));
        if (cltyqu(a, n.U))
        {
            m.U = sublqu(n.U, a);
            if (cltyqu(m.U, b))
            {
                x.U = cvquwu(1);
                x.U = (shllqu)(x.U, y);
                q.U = orrsqu(q.U, x.U);
                return  dcrlqu(q.U);
            }
        }
        else
        {
            x.U = ((shllqu)(cvquwu(1), y));
            q.U = orrsqu(q.U, x.U);
            m.U = sublqu(a, n.U);
            if (cltyqu(m.U, b))
                return q.U;
            p = n;
        }
    } while (y > 0);
    printf("infinite loop %s:%d\n", __func__,__LINE__);
    return  INT32_CVQU(-1);
#endif
}
#endif

INLINE(QUAD_ITYPE,divlqi) (QUAD_ITYPE a, QUAD_ITYPE b) 
{
#if defined(__SIZEOF_INT128__) && 0
    return  a/b;
#else
    QUAD_TYPE   x={.I=a}, y={.I=b}, q, r;
    if (x.Hi.I < 0)
    {
        x.U = absuqi(x.I);
        if (y.Hi.I < 0)
        {
            y.U = absuqi(y.I);
            q.U = divlqu(x.U, y.U);
            return q.I;
        }
        else 
        {
            q.U = divlqu(x.U, y.U);
            return  neglqi(q.I);
        }
    }
    else
    {
        if (y.Hi.I < 0)
        {
            y.U = absuqi(y.I);
            q.U = divlqu(x.U, y.U);
            return  neglqi(q.I);
        }
        q.U = divlqu(x.U, y.U);
        return q.I;
    }
#endif
}

#endif

#if 0 // _LEAVE_ALL_DIVL
}
#endif

#if 0 // _ENTER_ALL_DIVN
{
#endif

INLINE(schar, UCHAR_DIVN) (unsigned a, signed b)
{
    a = SCHAR_MAX&a;
    int q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    a -= q*b;
    return  q+(a==b);
}

INLINE(schar, SCHAR_DIVN)   (signed a, signed b)
{
    signed q;
    a = (schar) a;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        unsigned n = SCHAR_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return  q+(a==b);
}

INLINE( char,  CHAR_DIVN)      (int a, signed b) 
{
#if CHAR_MIN
    return  SCHAR_DIVN(a, b);
#else
    return  UCHAR_DIVN(a, b);
#endif
}

INLINE(short, USHRT_DIVN) (unsigned a, signed b)
{
    a = SHRT_MAX&a;
    int q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    a -= q*b;
    return  q+(a==b);
}

INLINE(short,  SHRT_DIVN)   (signed a, signed b)
{
    signed q;
    a = (short) a;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        unsigned n = SHRT_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return  q+(a==b);
}

INLINE(  int,  UINT_DIVN)     (uint a,    int b)
{
    int q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    a -= q*b;
    return  q+(a==b);
}

INLINE(  int,   INT_DIVN)      (int a,    int b)
{
    int q;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((uint) a/b);
    }
    else
    {
        uint n = INT_ABSU(a);
        q = (b < 0) ? (n/INT_ABSU(b)) : ~(n/b);
    }
    a -= q*b;
    return  q+(a==b);
}

INLINE( long, ULONG_DIVN)    (ulong a,   long b)
{
    long q = (b < 0L) ? ~(a/(0UL-b)) : ((ulong) a/b);
    a -= q*b;
    return  q+(a==b);
}

INLINE( long,  LONG_DIVN)     (long a,   long b)
{
    long q;
    if (a >= 0L)
    {
        q = (b < 0L) ? ~(a/(0UL-b)) : ((ulong) a/b);
    }
    else
    {
        ulong n = LONG_ABSU(a);
        q = (b < 0L) ? (n/(0UL-b)) : ~(n/b);
    }
    a -= q*b;
    return  q+(a==b);
}

INLINE(llong,ULLONG_DIVN)   (ullong a,  llong b)
{
    llong q = (b < 0LL) ? ~(a/(0ULL-b)) : ((ullong) a/b);
    a -= q*b;
    return  q+(a==b);
}

INLINE(llong, LLONG_DIVN)    (llong a,  llong b)
{
    llong q;
    if (a >= 0LL)
    {
        q = (b < 0LL) ? ~(a/(0ULL-b)) : ((ullong) a/b);
    }
    else
    {
        ullong n = LLONG_ABSU(a);
        q = (b < 0LL) ? (n/(0ULL-b)) : ~(n/b);
    }
    a -= q*b;
    return  q+(a==b);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_ITYPE, divnqu) (QUAD_UTYPE a, QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    QUAD_ITYPE q = (b < 0) ? ~((QUAD_ITYPE) a/b) : (a/b);
    a -= q*b;
    return  q+(a==b);
#endif
}

INLINE(QUAD_ITYPE, divnqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#ifdef _MSC_VER
    QUAD_TYPE m;
#endif

    QUAD_TYPE q, n={.I=a}, d={.I=b};

    if (n.Hi.I < 0)
    {
        n.U = absuqi(n.I);

        if (d.Hi.I < 0)
        {
            d.U = absuqi(d.I);
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Lo.U = 0;
#elif 1
            q.U = n.U/d.U;
#endif
        }

        else
        {
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Lo.U = ~q.Lo.U;
            q.Hi.U = -1;
#elif 1
            q.U = ~(n.U/d.U);
#endif

        }
    }

    else
    {
        if (d.Hi.I < 0)
        {
            d.U = absuqi(d.I);
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Lo.U = ~q.Lo.U;
            q.Hi.U = -1;
#elif 1
            q.U = ~(n.U/d.U);
#endif

        }

        else
        {
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Hi.U = 0;
#elif 1
            q.U = n.U/d.U;
#endif

        }
    }
    a = fsmlqi(a, b, q.I);
    return ceqyqi(a, b) ? icrlqi(q.I) : q.I;
}

#endif

#if 0 // _LEAVE_ALL_DIVN
}
#endif

#if 0 // _ENTER_ALL_DIV2
{
#endif

INLINE( uint8_t, USHRT_DIV2) (unsigned a, unsigned b) 
{
    return  (ushort) a/(ushort) b;
}

INLINE(  int8_t,  SHRT_DIV2)   (signed a,   signed b) 
{
    return  (short) a/(short) b;
}

INLINE(uint16_t,  UINT_DIV2)     (uint a,     uint b) {return a/b;}
INLINE( int16_t,   INT_DIV2)      (int a,      int b) {return a/b;}


#if DWRD_NLONG == 2
INLINE(uint16_t, ULONG_DIV2)    (ulong a,    ulong b) {return a/b;}
INLINE( int16_t,  LONG_DIV2)     (long a,     long b) {return a/b;}
#else
INLINE(uint32_t, ULONG_DIV2)    (ulong a,    ulong b) {return a/b;}
INLINE( int32_t,  LONG_DIV2)     (long a,     long b) {return a/b;}
#endif

#if QUAD_NLLONG == 2
INLINE(uint32_t,ULLONG_DIV2)   (ullong a,   ullong b) {return a/b;}
INLINE( int32_t, LLONG_DIV2)    (llong a,    llong b) {return a/b;}

INLINE(uint64_t,div2qu)    (QUAD_UTYPE a, QUAD_UTYPE b) 
{
    a = divlqu(a, b);
    return  cvduqu(a);
}

INLINE( int64_t,div2qi) (QUAD_ITYPE a,  QUAD_ITYPE b) 
{
    a = divlqi(a, b);
    return  cvdiqi(a);
}
#else
INLINE(uint64_t,ULLONG_DIV2)   (ullong a,   ullong b) {return a/b;}
INLINE( int64_t, LLONG_DIV2)    (llong a,    llong b) {return a/b;}
#endif

#if 0 // _LEAVE_ALL_DIV2
}
#endif


#if 0 // _ENTER_ALL_MODL
{
#endif

INLINE( uchar, UCHAR_MODL) (unsigned a, unsigned b,  uchar r[1]) 
{
    a = (uchar) a;
    return  ((*r=a%b), (a/b));
}

INLINE( schar, SCHAR_MODL)   (signed a,   signed b,  schar r[1])
{
    a = (schar) a;
    div_t x = div(a, b);
    return  ((*r=x.rem), x.quot);
}

INLINE(  char,  CHAR_MODL)      (int a,      int b,   char r[1]) 
{
#if CHAR_MIN
    return  SCHAR_MODL(a, b, ((schar *) r));
#else
    return  UCHAR_MODL(a, b, ((uchar *) r));
#endif
}

INLINE(ushort, USHRT_MODL) (unsigned a, unsigned b, ushort r[1]) 
{
    a = (ushort) a;
    return  ((*r=a%b), (a/b));
}

INLINE( short,  SHRT_MODL)   (signed a,   signed b,  short r[1])
{
    a = (short) a;
    div_t x = div(a, b);
    return  ((*r=x.rem), x.quot);
}

INLINE(  uint,  UINT_MODL)     (uint a,     uint b,   uint r[1])
{
    return  ((*r=a%b), (a/b));
}

INLINE(   int,   INT_MODL)      (int a,      int b,    int r[1])
{
    div_t x = div(a, b);
    return  ((*r=x.rem), x.quot);
}

INLINE( ulong, ULONG_MODL)    (ulong a,    ulong b,  ulong r[1]) 
{
    return  ((*r=a%b), (a/b));
}

INLINE(  long,  LONG_MODL)     (long a,     long b,   long r[1])
{
    ldiv_t   x = ldiv(a, b);
    return  ((*r=x.rem), x.quot);
}

INLINE(ullong,ULLONG_MODL)   (ullong a,   ullong b, ullong r[1]) 
{
    return  ((*r=a%b), (a/b));
}

INLINE( llong, LLONG_MODL)    (llong a,    llong b,  llong r[1])
{
    lldiv_t   x = lldiv(a, b);
    return  ((*r=x.rem), x.quot);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,modlqu) (QUAD_UTYPE a, QUAD_UTYPE b, QUAD_UTYPE c[1])
{
    QUAD_TYPE oria={.U=a}, orib={.U=b};
//  if (a <= b), the quotient can only be 0 or 1
    if (ceqyqu(a, b))
        return  ((*c=((QUAD_UTYPE){0})), cvquwu(1U));
    if (cltyqu(a, b)) 
        return  ((*c=a), ((QUAD_UTYPE){0}));
    QUAD_TYPE   x, m, n, p, q={.U=a};

//  if (a.len <= 64), use 64 bit fast path
    if (q.Hi.U == 0)
    {
        QUAD_TYPE *r = (QUAD_TYPE *) c;
        p.U = b;
        q.Lo.U = UINT64_MODL(q.Lo.U, p.Lo.U, &r->Lo.U);
        r->Hi.U = 0;
        return  q.U;
    }

    int y, z;
    p.U = cszrqu(a); 
    q.U = cszrqu(b);
//  y = a.len-b.len
    y = (128-cvwiqu(p.U));
    z = (128-cvwiqu(q.U));
    y = y-z;
    //int y = (128-cvwiqu(p.U))-(128-cvwiqu(q.U));
    if ((y < 0) || (y > 128))
    {
        printf("(128-cszr(a))-(128-cszr(b)) = %d\n",y);
        return  cvquwi(-1);
    }

    //printf("y = %i\n", y);
    /*
    */
    if (1 == y)
    {
/*
        return (
            (2,   0) if (a == (n:=b<<1)) else 
            (1, a-b) if (a  < (n)) else
            (2,   p) if (b  > (n:=a-n)) else 
            (3, p-b)
        )
*/
        n.U = shllqu(b, 1);
        if (ceqyqu(a, n.U))
        {
            return  ((*c=((QUAD_UTYPE){0})), UINT32_CVQU(2));
        }

        if (cltyqu(a, n.U))
        {
            return ((*c = sublqu(a, b)), UINT32_CVQU(1));
        }

        n.U = sublqu(a, n.U);

        if (cgtyqu(b, n.U))
        {
            return  ((*c=n.U), UINT32_CVQU(2));
        }
        else
        {
            return  ((*c=sublqu(n.U, b)), UINT32_CVQU(3));
        }

    }

    for (y++;; y--)
    {
        p.U = ((shllqu)(b, y));
        if (!cltyqu(a, p.U)) //(a < p.U)
            break;
    }

    n.U = ((sublqu)(a, p.U)); //n.U = a-p.U;
    q.U = ((shllqu)(cvquwu(1), y));

    if (cltyqu(n.U, b))
    {
        return ((*c=n.U), q.U);
    }
/*
    while 1:
        y = y-1
        n = p+(r<<y)
        if l < n:
            m = n-l
            if m < r:
                return ((q|(1<<y))-1, r-m)
        else:
            q |= 1<<y
            m = l-n
            if m < r:
                return (q, m)
            p = n
        assert y >= 0
*/  

    do {
        y--;
        // n.U = p.U+(b<<y);
        x.U = ((shllqu)(b, y));
        n.U = ((addlqu)(p.U, x.U));
        if (cltyqu(a, n.U)) // (a < n.U)
        {
            m.U = sublqu(n.U, a); // m.U = n.U-a;
            if (cltyqu(m.U, b)) // (m.U < b)
            {
                // return  (q.U|((shllqu)(cvquwu(1),y)))-1;
                x.U = cvquwu(1);
                x.U = (shllqu)(x.U, y);
                q.U = orrsqu(q.U, x.U);
                *c = sublqu(b, m.U);
                return  dcrlqu(q.U);
            }
        }
        else
        {
            // q.U |= ((shllqu)(cvquwu(1),y));
            x.U = ((shllqu)(cvquwu(1), y));
            q.U = orrsqu(q.U, x.U);
            m.U = sublqu(a, n.U); //m.U = a-n.U;
            if (cltyqu(m.U, b)) // (m.U < b)
                return ((*c=m.U), q.U);
            p = n;
        }

    } while (y > 0);
    
/*
    y = y+1
    while a < (p:=b<<y):
        y -= 1
    n = a-p
    if n < b:
        return (1<<y, n)
    q = 1<<y
    while 1:
        y = y-1
        n = p+(b<<y)
        if a < n:
            m = n-a
            if m < b:
                return ((q|(1<<y))-1, b-m)
        else:
            q |= 1<<y
            m = a-n
            if m < b:
                return (q, m)
            p = n
        assert y >= 0
*/

/*
    b = b+1
    while l < (p:=r<<b):
        b -= 1
    n = l-p
    if n < r:
        return (1<<b, n)
    q = 1<<b
    while 1:
        b = b-1
        n = p+(r<<b)
        if l < n:
            m = n-l
            if m < r:
                return ((q|(1<<b))-1, r-m)
        else:
            q |= 1<<b
            m = l-n
            if m < r:
                return (q, m)
            p = n
        assert b >= 0
*/
    char stra[256], strb[256], *enda, *endb;
    printf(
        "infinite loop in %s:%d(%s, %s)", 
        __func__,__LINE__,
        safe_toadqu(oria.U, stra, &enda),
        safe_toadqu(orib.U, strb, &endb)
    );
    //printf("infinite loop %s/%i\n", __func__,__LINE__);
    return  INT32_CVQU(-1);
#if 0
    {
    QUAD_TYPE a, b, n, p, q;

    if (cleyqu(l, r)) 
    {
//  if l <= r, the quotient is (1 if l == r else 0)
        p.Lo.U = 0, p.Hi.U = 0; // p = 0
        q.Lo.U = 1, q.Hi.U = 0; // q = 1
        return (ceqyqu(l, r)) ? ((*m=p.U), q.U) :((*m=q.U), p.U);
    }

    p.U = cszrqu(l);
    q.U = cszrqu(r);
//  b = l.bit_length()-r.bit_length()
    b.U = cvquwu( ((128-p.W0.U)-(128-q.W0.U)) );

//  if b == 1:
    if ((b.Lo.U == 1) && (b.Hi.U == 0))
    {
        n.U = shllqu(r, 1);
        if (ceqyqu(l, n.U))
            return  ((*m=cvquwi(0)), cvquwi(2));

        if (cltyqu(l, n.U))
            return  ((*m=sublqu(l, r)), cvquwi(1));

        p.U = sublqu(l, n.U);
        if (cltyqu(p.U, r))
            return ((*m=p.U), cvquwi(2));

        return ((*m=sublqu(p.U, r)), cvquwi(3));
    }

    for (b.U=icrlqu(b.U);  ; b.U=dcrlqu(b.U))
    {
        p.U = (shllqu)(r, cvwiqu(b.U));
        if (!cltyqu(l, p.U)) 
            break;
    }

    n.U = sublqu(l, p.U);
    q.U = ((shllqu)(cvquwi(1), cvwiqu(b.U)));

    if (cltyqu(n.U, r))
        return ((*m=n.U), q.U);

    while (1) 
    {
        b.U =  dcrlqu(b.U);
        n.U = (shllqu)(r, cvwiqu(b.U));
        n.U =  addlqu(p.U, n.U);
        if (cltlqu(l, n.U))
        {
            *m = sublqu(n.U, l);
            if (cltlqu(*m, r))
            {
                *m = sublqu(r, *m);
                p.U = (shllqu)(cvquwi(1), cvwiqu(b.U));
                p.U = orrsqu(p.U, q.U);
                return  dcrlqu(p.U);
            }
        }
        else
        {
            q.U = orrsqu(q.U, ((shllqu)(cvquwi(1), cvwiqu(b.U))));
            *m = sublqu(l, n.U);
            if (cltyqu(*m, r))
                return q.U;
            p = n;
        }
        if (!zleyqi(b.I))
            break;
    }
    printf("infinite loop %s:%n\n", __func__,__LINE__);
    return  cvquwi(-1);
    }
#endif
}

INLINE(QUAD_ITYPE,modlqi) (QUAD_ITYPE a, QUAD_ITYPE b, QUAD_ITYPE c[1])
{
/*

+N/+D = +Q,+R
+N/-D = -Q,+R
-N/+D = -Q,-R
-N/-D = +Q,-R
*/
    QUAD_TYPE   x={.I=a}, y={.I=b}, q, r;
    if (x.Hi.I < 0)
    {
        x.U = absuqi(x.I);
        if (y.Hi.I < 0)
        {
            y.U = absuqi(y.I);
            q.U = modlqu(x.U, y.U, &r.U);
            return  ((*c=neglqi(r.I)), q.I);
        }
        else 
        {
            q.U = modlqu(x.U, y.U, &r.U);
            return  ((*c=neglqi(r.I)), neglqi(q.I));
        }
    }
    else
    {
        if (y.Hi.I < 0)
        {
            y.U = absuqi(y.I);
            q.U = modlqu(x.U, y.U, ((QUAD_UTYPE *) c));
            return  neglqi(q.I);
        }
        q.U = modlqu(x.U, y.U, ((QUAD_UTYPE *) c));
        return q.I;
    }
}

#endif

INLINE(int, mydiv)(int a, int b, int *c)
{
/*  emulate C 'div' ish */
    int n, d, q, r;
    b = (int16_t) b;
    if (a < 0)
    {
        n = -a;
        if (b < 1)
        {
            d = 0-b;
            return ((*c=0-(n%d)), (n/d));
        }
        q = 0-(n/b);
    }
    else {
        if (b < 1)
        {
            d = 0-b;
            q = 0-(a/d);
        }
        else
        {
            q = a/b;
        }
    }
    r = b*q;
    return ((*c=a-r), q);
}

#if 0 // _LEAVE_ALL_MODL
}
#endif

#if 0 // _ENTER_ALL_MODN
{
#endif

INLINE(schar, UCHAR_MODN) (unsigned a, signed b, void *c)
{
    a = SCHAR_MAX&a;
    int q = (b < 0) ? ~(a/(0U-b)) : (a/b);
    a -= q*b;
    return  (a == b) ? ((*(schar *) c=0), q+1) : ((*(schar *) c=a), q);
}

INLINE(schar, SCHAR_MODN)   (signed a, signed b, void *c)
{
    signed q;
    a = (schar) a;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        unsigned n = SCHAR_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a == b) ? ((*(schar *) c=0), q+1) : ((*(schar *) c=a), q);
}

INLINE(schar,  CHAR_MODN)      (int a,    int b, void *c) 
{
#if CHAR_MIN
    return  SCHAR_MODN(a, b, c);
#else
    return  UCHAR_MODN(a, b, c);
#endif
}

INLINE(short, USHRT_MODN) (unsigned a, signed b, short c[1])
{
    a = SHRT_MAX&a;
    int q = (b < 0) ? ~(a/(0U-b)) : (a/b);
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE(short,  SHRT_MODN)   (signed a, signed b, short c[1])
{
    signed q;
    a = (short) a;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        unsigned n = SHRT_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE(  int,  UINT_MODN)     (uint a,    int b,   int c[1])
{
    int q = (b < 0) ? ~(a/(0U-b)) : (a/b);
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE(  int,   INT_MODN)      (int a,    int b,   int c[1])
{
    int q;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        uint n = INT_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE( long, ULONG_MODN)    (ulong a,   long b,  long c[1])
{
    long q = (b < 0) ? ~(a/(0UL-b)) : (a/b);
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE( long,  LONG_MODN)     (long a,   long b,  long c[1])
{
    long q;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0UL-b)) : ((ulong) a/b);
    }
    else
    {
        ulong n = LONG_ABSU(a);
        q = (b < 0) ? (n/(0UL-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE(llong,ULLONG_MODN)   (ullong a,  llong b,  llong c[1])
{
    long q = (b < 0) ? ~(a/(0UL-b)) : (a/b);
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

INLINE(llong, LLONG_MODN)    (llong a,  llong b,  llong c[1])
{
    long q;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0UL-b)) : ((ulong) a/b);
    }
    else
    {
        ulong n = LONG_ABSU(a);
        q = (b < 0) ? (n/(0UL-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a == b) ? ((*c=0), q+1) : ((*c=a), q);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_ITYPE, modnqi) (QUAD_ITYPE a, QUAD_ITYPE b, QUAD_ITYPE c[1])
{
#if defined(__SIZEOF_INT128__)
    QUAD_TYPE  q;
    if (zltyqi(a))
    {
        q.U = (zgtyqi(b))
        //?   ~((QUAD_UTYPE) a/((QUAD_UTYPE) 0-b)) 
        ?   invsqu( divlqu(asquqi(a), absuqi(b)) )
        //:   (((QUAD_UTYPE) a/((QUAD_UTYPE)   b)))
        :   divlqu(asquqi(a), asquqi(b))
        ;
    }
    else
    {
        QUAD_UTYPE  n = absuqi(a);
        q.U = (zgtyqi(b))
        //?   ((n/((QUAD_UTYPE) 0-b)))
        ?   divlqu(n, absuqi(b))
        //:   ~(n/(QUAD_UTYPE)   b)
        :   invsqu(divlqu(n, asquqi(b)))
        ;
    }
    //a -= q.I*b;
    a = fsmlqi(a, q.I, b);
    if (a == b)
        return  ((*c=0), (q.I+1));
    else
        return  ((*c=a), q.I);

#else
    QUAD_TYPE x={.U=absuqi(a)}, y={.U=absuqi(b)}, q, r;
    q.U = modlqu(x.U, y.U, &r.U);
    if (zgtyqi(a))
    {
        if (zgtyqi(b))
            q.U = invsqu(q.U);
    }
    else
    {
        if (!zgtyqi(b))
            q.U = invsqu(q.U);
    }
    a = fsmlqi(a, q.I, b);
    if (ceqyqi(a, b))
    {
        return  ((*c=cvqiwu(0)), icrlqi(q.I));
    }
    else
    {
        return  ((*c=a), q.I);
    }
#endif

}

INLINE(QUAD_ITYPE, modnqu) (QUAD_UTYPE a, QUAD_ITYPE b, QUAD_ITYPE c[1])
{
    return  modnqi(asqiqu(a), b, c);
}
#endif

#if 0 // _LEAVE_ALL_MODN
}
#endif

#if 0 // _ENTER_ALL_REML
{
#endif

INLINE( uchar, UCHAR_REML) (unsigned a, unsigned b) {return (uchar) a%b;}
INLINE( schar, SCHAR_REML)   (signed a,   signed b) {return (schar) a%b;}
INLINE(  char,  CHAR_REML)      (int a,      int b) {return (char) a%b;}
INLINE(ushort, USHRT_REML) (unsigned a, unsigned b) {return (ushort) a%b;}
INLINE( short,  SHRT_REML)   (signed a,   signed b) {return (short) a%b;}
INLINE(  uint,  UINT_REML)     (uint a,     uint b) {return a%b;}
INLINE(   int,   INT_REML)      (int a,      int b) {return a%b;}
INLINE( ulong, ULONG_REML)    (ulong a,    ulong b) {return a%b;}
INLINE(  long,  LONG_REML)     (long a,     long b) {return a%b;}
INLINE(ullong,ULLONG_REML)   (ullong a,   ullong b) {return a%b;}
INLINE( llong, LLONG_REML)    (llong a,    llong b) {return a%b;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,remlqu) (QUAD_UTYPE a, QUAD_UTYPE b) 
{
    QUAD_UTYPE c;
    (void) modlqu(a, b, &c);
    return c;
}

INLINE(QUAD_ITYPE,remlqi) (QUAD_ITYPE a, QUAD_ITYPE b) 
{
    QUAD_ITYPE c;
    (void) modlqi(a, b, &c);
    return c;
}

#endif

#if 0 // _LEAVE_ALL_REML
}
#endif

#if 0 // _ENTER_ALL_REMN
{
#endif

INLINE(schar, UCHAR_REMN) (unsigned a, signed b)
{
    a = (uchar) a;
    int q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE(schar, SCHAR_REMN)   (signed a, signed b)
{
    signed q;
    a = (schar) a;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        unsigned n = SCHAR_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE( char,  CHAR_REMN)      (int a, signed b) 
{
#if CHAR_MIN
    return  SCHAR_REMN(a, b);
#else
    return  UCHAR_REMN(a, b);
#endif
}

INLINE(short, USHRT_REMN) (unsigned a, signed b)
{
    a = (ushort) a;
    int q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE(short,  SHRT_REMN)   (signed a, signed b)
{
    signed q;
    a = (short) a;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    }
    else
    {
        unsigned n = SHRT_ABSU(a);
        q = (b < 0) ? (n/(0U-b)) : ~(n/b);
    }
    a -= q*b;
    return (a==b) ? 0 : a;
}

INLINE(  int,  UINT_REMN)     (uint a,    int b)
{
    int q = (b < 0) ? ~(a/(0U-b)) : ((unsigned) a/b);
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE(  int,   INT_REMN)      (int a,    int b)
{
    int q;
    if (a >= 0)
    {
        q = (b < 0) ? ~(a/(0U-b)) : ((uint) a/b);
    }
    else
    {
        uint n = INT_ABSU(a);
        q = (b < 0) ? (n/INT_ABSU(b)) : ~(n/b);
    }
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE( long, ULONG_REMN)    (ulong a,   long b)
{
    long q = (b < 0L) ? ~(a/(0UL-b)) : ((ulong) a/b);
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE( long,  LONG_REMN)     (long a,   long b)
{
    long q;
    if (a >= 0L)
    {
        q = (b < 0L) ? ~(a/(0UL-b)) : ((ulong) a/b);
    }
    else
    {
        ulong n = LONG_ABSU(a);
        q = (b < 0L) ? (n/(0UL-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE(llong,ULLONG_REMN)   (ullong a,  llong b)
{
    llong q = (b < 0LL) ? ~(a/(0ULL-b)) : ((ullong) a/b);
    a -= q*b;
    return  (a==b) ? 0 : a;
}

INLINE(llong, LLONG_REMN)    (llong a,  llong b)
{
    llong q;
    if (a >= 0LL)
    {
        q = (b < 0LL) ? ~(a/(0ULL-b)) : ((ullong) a/b);
    }
    else
    {
        ullong n = LLONG_ABSU(a);
        q = (b < 0LL) ? (n/(0ULL-b)) : ~(n/b);
    }
    a -= q*b;
    return  (a==b) ? 0 : a;
}

#if QUAD_NLLONG == 2

INLINE(QUAD_ITYPE, remnqu) (QUAD_UTYPE a, QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    QUAD_ITYPE q = (b < 0) ? ~((QUAD_ITYPE) a/b) : (a/b);
    a -= q*b;
    return  (a==b) ? 0 : a;
#endif
}

INLINE(QUAD_ITYPE, remnqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
#ifdef _MSC_VER
    QUAD_TYPE m;
#endif

    QUAD_TYPE q, n={.I=a}, d={.I=b};

    if (n.Hi.I < 0)
    {
        n.U = absuqi(n.I);

        if (d.Hi.I < 0)
        {
            d.U = absuqi(d.I);
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Lo.U = 0;
#elif 1
            q.U = n.U/d.U;
#endif
        }

        else
        {
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Lo.U = ~q.Lo.U;
            q.Hi.U = -1;
#elif 1
            q.U = ~(n.U/d.U);
#endif

        }
    }

    else
    {
        if (d.Hi.I < 0)
        {
            d.U = absuqi(d.I);
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Lo.U = ~q.Lo.U;
            q.Hi.U = -1;
#elif 1
            q.U = ~(n.U/d.U);
#endif

        }

        else
        {
#if defined(_MSC_VER)
            q.Lo.U = _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &m.Lo.U);
            q.Hi.U = 0;
#elif 1
            q.U = n.U/d.U;
#endif

        }
    }
    a = fsmlqi(a, b, q.I);
    return ceqyqi(a, b) ? icrlqi(q.I) : q.I;
}

#endif

#if 0 // _LEAVE_ALL_REMN
}
#endif

#if 0 // _ENTER_ALL_REM2
{
#endif

INLINE( uint8_t, USHRT_REM2) (unsigned a, unsigned b) 
{
    return  (ushort) a%(uint8_t) b;
}

INLINE(  int8_t,  SHRT_REM2)   (signed a,   signed b) 
{
    return  (short) a%(int8_t) b;
}

INLINE(uint16_t,  UINT_REM2)     (uint a, unsigned b) 
{
    return  a%(uint16_t) b;
}

INLINE( int16_t,   INT_REM2)      (int a,     int b) 
{
    return  a%(int16_t) b;
}


#if DWRD_NLONG == 2

INLINE(uint16_t, ULONG_REM2)    (ulong a, ulong b) 
{
    return  UINT_REM2(a, b);
}

INLINE( int16_t,  LONG_REM2)     (long a,   long b) 
{
    return  INT_REM2(a, b);
}

#else

INLINE(uint32_t, ULONG_REM2)    (ulong a, ulong b) 
{
    return  a%(uint32_t) b;
}

INLINE( int32_t,  LONG_REM2)     (long a,  long b) 
{
    return  a%(int32_t) b;
}

#endif

#if QUAD_NLLONG == 2

INLINE(uint32_t,ULLONG_REM2)   (ullong a, ullong b) 
{
    return  a%(uint32_t) b;
}

INLINE( int32_t, LLONG_REM2)    (llong a,  llong b) 
{
    return a%(int32_t) b;
}

INLINE(uint64_t,rem2qu) (QUAD_UTYPE a, QUAD_UTYPE b) 
{
    QUAD_TYPE   n={.U=a}, d={.U=b}, r;
#if defined(_MSC_VER)
    (void) _udiv128(n.Hi.U, n.Lo.U, d.Lo.U, &r.Lo.U);
#else
    (void) modlqu(a, b, &r.U);
#endif
    return  r.Lo.U;
}

INLINE( int64_t,rem2qi) (QUAD_ITYPE a,  QUAD_ITYPE b) 
{
    QUAD_TYPE   n={.I=a}, d={.I=b}, r;
#if defined(_MSC_VER)
    (void) _div128(n.Hi.I, n.Lo.I, d.Lo.I, &r.Lo.I);
#else
    (void) modlqi(a, b, &r.I);
#endif
    return  r.Lo.I;
}

#else

INLINE(uint64_t,ULLONG_REM2)   (ullong a, ullong b) 
{
    return  a%(uint64_t) b;
}

INLINE( int64_t, LLONG_REM2)    (llong a,  ullong b) 
{
    return  a%(int64_t) b;
}

#endif

#if 0 // _LEAVE_ALL_REM2
}
#endif

#if 0 // _ENTER_ALL_CLTR
{
#endif

INLINE(void *,  ADDR_CLTR) (void const *a, void const *b)
{
    return  (void *)((a < b) ? b : a);
}

INLINE( _Bool,  BOOL_CLTR)    (_Bool a,    _Bool b) {return a|b;}
INLINE( uchar, UCHAR_CLTR) (unsigned a, unsigned b) 
{
    a=(uchar) a, b=(uchar) b;
    return  (a < b) ? b : a;
}

INLINE( schar, SCHAR_CLTR)   (signed a,   signed b) 
{
    a=(schar) a, b=(schar) b;
    return  (a < b) ? b : a;
}

INLINE(  char,  CHAR_CLTR)      (int a,      int b) 
{
    a=(char) a, b=(char) b;
    return  (a < b) ? b : a;
}

INLINE(ushort, USHRT_CLTR) (unsigned a, unsigned b) 
{
    a=(ushort) a, b=(ushort) b;
    return  (a < b) ? b : a;
}

INLINE( short,  SHRT_CLTR)   (signed a,   signed b) 
{
    a=(short) a, b=(short) b;
    return  (a < b) ? b : a;
}

INLINE(  uint,  UINT_CLTR)     (uint a,     uint b) {return a < b ? b : a;}
INLINE(   int,   INT_CLTR)      (int a,      int b) {return a < b ? b : a;}
INLINE( ulong, ULONG_CLTR)    (ulong a,    ulong b) {return a < b ? b : a;}
INLINE(  long,  LONG_CLTR)     (long a,     long b) {return a < b ? b : a;}
INLINE(ullong,ULLONG_CLTR)   (ullong a,   ullong b) {return a < b ? b : a;}
INLINE( llong, LLONG_CLTR)    (llong a,    llong b) {return a < b ? b : a;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cltrqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE x={.U=a}, y={.U=b};
    if (x.Hi.U < y.Hi.U)
        return  b;
    if (x.Hi.U > y.Hi.U)
        return  a;
    if (x.Lo.U < y.Lo.U)
        return  b;
    return  a;
}

INLINE(QUAD_ITYPE,cltrqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE x={.I=a}, y={.I=b};
    if (x.Hi.I < y.Hi.I)
        return  b;
    if (x.Hi.I > y.Hi.I)
        return  a;
    if (x.Lo.I < y.Lo.I)
        return  a;
    return  b;
}

#endif

#if 0 // _LEAVE_ALL_CLTR
}
#endif

#if 0 // _ENTER_ALL_CGTR
{
#endif

/*  cgtr(8, 9)  (8, 9)[8 > 9] => 8
    cgtr(9, 8)  (9, 8)[9 > 8] => 8
    
    
    !(1 > 0) ? 0
    
*/
INLINE(void *,  ADDR_CGTR) 
(
    void const *a,
    void const *b
)
{
    return  (void *)(a > b ? b : a);
}

INLINE( _Bool,  BOOL_CGTR)    (_Bool a,    _Bool b) {return a&b;}
INLINE( uchar, UCHAR_CGTR) (unsigned a, unsigned b) 
{
    a = (uchar) a;
    b = (uchar) b;
    return  (a>b) ? b : a;
}

INLINE( schar, SCHAR_CGTR)   (signed a,   signed b) 
{
    a = (schar) a;
    b = (schar) b;
    return  (a>b) ? b : a;
}

INLINE(  char,  CHAR_CGTR)      (int a,      int b) 
{
    a = (char) a;
    b = (char) b;
    return  (a>b) ? b : a;
}

INLINE(ushort, USHRT_CGTR) (unsigned a, unsigned b) 
{
    a = (ushort) a;
    b = (ushort) b;
    return  (a>b) ? b : a;
}

INLINE( short,  SHRT_CGTR)   (signed a,   signed b) 
{
    a = (short) a;
    b = (short) b;
    return  (a>b) ? b : a;
}

INLINE(  uint,  UINT_CGTR)     (uint a,     uint b) {return (a>b) ? b : a;}
INLINE(   int,   INT_CGTR)      (int a,      int b) {return (a>b) ? b : a;}
INLINE( ulong, ULONG_CGTR)    (ulong a,    ulong b) {return (a>b) ? b : a;}
INLINE(  long,  LONG_CGTR)     (long a,     long b) {return (a>b) ? b : a;}
INLINE(ullong,ULLONG_CGTR)   (ullong a,   ullong b) {return (a>b) ? b : a;}
INLINE( llong, LLONG_CGTR)    (llong a,    llong b) {return (a>b) ? b : a;}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,cgtrqu) (QUAD_UTYPE a, QUAD_UTYPE b)
{
    QUAD_TYPE x={.U=a}, y={.U=b};
    if (x.Hi.U > y.Hi.U)
        return  b;
    if (x.Hi.U < y.Hi.U)
        return  a;
    if (x.Lo.U > y.Lo.U)
        return  b;
    return  a;
}

INLINE(QUAD_ITYPE,cgtrqi) (QUAD_ITYPE a, QUAD_ITYPE b)
{
    QUAD_TYPE x={.I=a}, y={.I=b};
    if (x.Hi.I > y.Hi.I)
        return  b;
    if (x.Hi.I < y.Hi.I)
        return  a;
    if (x.Lo.I > y.Lo.I)
        return  a;
    return  b;
}

#endif

#if 0 // _LEAVE_ALL_CGTR
}
#endif

#if 0 // _ENTER_ALL_ZIPP
{
#endif

INLINE(uint16_t, UCHAR_ZIPP) (unsigned a, unsigned b)
{
    a = (uchar) a;
    a = 0x0f0f&(a|(a<<4));
    a = 0x3333&(a|(a<<2));
    a = 0x5555&(a|(a<<1));

    b = (uchar) b;
    b = 0x0f0f&(b|(b<<4));
    b = 0x3333&(b|(b<<2));
    b = 0x5555&(b|(b<<1));

    return a|(b<<1);
}

INLINE(uint16_t, CHAR_ZIPP) (int a, int b)
{
    return  UCHAR_ZIPP(a, b);
}

INLINE(uint32_t, USHRT_ZIPP) (unsigned a, unsigned b)
{
    a = (ushort) a;
    a = UINT32_C(0x00ff00ff)&(a|(a<<8));
    a = UINT32_C(0x0f0f0f0f)&(a|(a<<4));
    a = UINT32_C(0x33333333)&(a|(a<<2));
    a = UINT32_C(0x55555555)&(a|(a<<1));

    b = (ushort) b;
    b = UINT32_C(0x00ff00ff)&(b|(b<<8));
    b = UINT32_C(0x0f0f0f0f)&(b|(b<<4));
    b = UINT32_C(0x33333333)&(b|(b<<2));
    b = UINT32_C(0x55555555)&(b|(b<<1));

    return a|(b<<1);
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

    return  x|(y<<1);
}

#if DWRD_NLONG == 2

INLINE(uint64_t, ULONG_ZIPP) (ulong a, ulong b)
{
    return  UINT_ZIPP(a, b);
}

#else

INLINE(QUAD_UTYPE, ULONG_ZIPP) (ulong a, ulong b)
{
    QUAD_TYPE   q;
    q.Lo.U = UINT_ZIPP(a, b);
    q.Hi.U = UINT_ZIPP((a>>32), (b>>32));
    return  q.U;
}

#endif

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE, ULLONG_ZIPP) (ullong a, ullong b)
{
    QUAD_TYPE   q;
    q.Lo.U = UINT_ZIPP(a, b);
    q.Hi.U = UINT_ZIPP((a>>32), (b>>32));
    return  q.U;
}
#endif

#if 0 // _LEAVE_ALL_ZIPP
}
#endif


#if 0 // _ENTER_ALL_XRDZ
{
#endif

INLINE(  uint16_t, UCHAR_XRDZ) (unsigned x) {return (uchar) x;}
INLINE(   int16_t, SCHAR_XRDZ)   (signed x) {return (uchar) x;}
#if CHAR_MIN
INLINE(   int16_t,  CHAR_XRDZ)      (int x) {return (uchar) x;}
#else
INLINE(  uint16_t,  CHAR_XRDZ)      (int x) {return (uchar) x;}
#endif

INLINE(  uint32_t, USHRT_XRDZ) (unsigned x) {return (ushort) x;}
INLINE(   int32_t,  SHRT_XRDZ)   (signed x) {return (ushort) x;}
INLINE(  uint64_t,  UINT_XRDZ)     (uint x) {return x;}
INLINE(   int64_t,   INT_XRDZ)      (int x) {return  (uint) x;}

#if DWRD_NLONG == 2
INLINE(  uint64_t, ULONG_XRDZ)    (ulong x) {return x;}
INLINE(   int64_t,  LONG_XRDZ)     (long x) {return (uint64_t) x;}
#else

INLINE(QUAD_UTYPE, ULONG_XRDZ)    (ulong x) 
{
    QUAD_TYPE z={.Lo.U=x};
    return  z.U;
}
INLINE(QUAD_ITYPE,  LONG_XRDZ)     (long x) 
{
    QUAD_TYPE z={.Lo.U=x};
    return  z.I;
}

#endif

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,ULLONG_XRDZ)   (ullong x) 
{
    QUAD_TYPE z={.Lo.U=x};
    return  z.U;
}

INLINE(QUAD_ITYPE, LLONG_XRDZ)    (llong x) 
{
    QUAD_TYPE z={.Lo.U=x};
    return  z.I;
}

#endif

#if 0 // _LEAVE_ALL_XRDZ
}
#endif

#if 0 // _ENTER_ALL_XRDS
{
#endif

INLINE(  uint16_t, UCHAR_XRDS) (unsigned x) {return (schar) x;}
INLINE(   int16_t, SCHAR_XRDS)   (signed x) {return (schar) x;}
#if CHAR_MIN
INLINE(   int16_t,  CHAR_XRDS)      (int x) {return (schar) x;}
#else
INLINE(  uint16_t,  CHAR_XRDS)      (int x) {return (schar) x;}
#endif

INLINE(  uint32_t, USHRT_XRDS) (unsigned x) {return (short) x;}
INLINE(   int32_t,  SHRT_XRDS)   (signed x) {return (short) x;}
INLINE(  uint64_t,  UINT_XRDS)     (uint x) {return   (int) x;}
INLINE(   int64_t,   INT_XRDS)      (int x) {return x;}

#if DWRD_NLONG == 2
INLINE(  uint64_t, ULONG_XRDS)    (ulong x) {return (int32_t) x;}
INLINE(   int64_t,  LONG_XRDS)     (long x) {return x;}
#else

INLINE(QUAD_UTYPE, ULONG_XRDS)    (ulong x) 
{
    QUAD_TYPE z={.Lo.I=x};
    z.Hi.I = z.Lo.I>>63;
    return  z.U;
}
INLINE(QUAD_ITYPE,  LONG_XRDS)     (long x) 
{
    QUAD_TYPE z={.Lo.I=x};
    z.Hi.I = z.Lo.I>>63;
    return  z.I;
}

#endif

#if QUAD_NLLONG == 2
INLINE(QUAD_UTYPE,ULLONG_XRDS)   (ullong x) 
{
    QUAD_TYPE z={.Lo.I=x};
    z.Hi.I = z.Lo.I>>63;
    return  z.U;
}
INLINE(QUAD_ITYPE, LLONG_XRDS)    (llong x) 
{
    QUAD_TYPE z={.Lo.I=x};
    z.Hi.I = z.Lo.I>>63;
    return  z.I;
}
#endif

#if 0 // _LEAVE_ALL_XRDS
}
#endif

#if 0 // _ENTER_ALL_XRQZ
{
#endif

INLINE(  uint32_t, UCHAR_XRQZ) (unsigned x) {return (uchar) x;}
INLINE(   int32_t, SCHAR_XRQZ)   (signed x) {return (uchar) x;}
#if CHAR_MIN
INLINE(   int32_t,  CHAR_XRQZ)      (int x) {return (uchar) x;}
#else
INLINE(  uint32_t,  CHAR_XRQZ)      (int x) {return (uchar) x;}
#endif

INLINE(  uint64_t, USHRT_XRQZ) (unsigned x) {return (ushort) x;}
INLINE(   int64_t,  SHRT_XRQZ)   (signed x) {return (ushort) x;}

INLINE(QUAD_UTYPE,  UINT_XRQZ)     (uint x) 
{
    QUAD_TYPE z = {.W0.U=x};
    return  z.U;
}

INLINE(QUAD_ITYPE,   INT_XRQZ)      (int x) 
{
    QUAD_TYPE z = {.W0.U=x};
    return  z.I;
}

#if DWRD_NLONG == 2
INLINE(QUAD_UTYPE,  ULONG_XRQZ)     (ulong x) 
{
    QUAD_TYPE z = {.W0.U=x};
    return  z.U;
}

INLINE(QUAD_ITYPE,   LONG_XRQZ)      (long x) 
{
    QUAD_TYPE z = {.W0.U=x};
    return  z.I;
}

#endif

#if 0 // _LEAVE_ALL_XRQZ
}
#endif

#if 0 // _ENTER_ALL_XRQS
{
#endif

INLINE(  uint32_t, UCHAR_XRQS) (unsigned x) {return (schar) x;}
INLINE(   int32_t, SCHAR_XRQS)   (signed x) {return (schar) x;}
#if CHAR_MIN
INLINE(   int32_t,  CHAR_XRQS)      (int x) {return (schar) x;}
#else
INLINE(  uint32_t,  CHAR_XRQS)      (int x) {return (schar) x;}
#endif

INLINE(  uint64_t, USHRT_XRQS) (unsigned x) {return (short) x;}
INLINE(   int64_t,  SHRT_XRQS)   (signed x) {return (short) x;}
INLINE(QUAD_UTYPE,  UINT_XRQS)     (uint x) 
{
    QUAD_TYPE z = {.Lo.I=(int) x};
    z.Hi.I = z.Lo.I>>63;
    return  z.U;
}

INLINE(QUAD_ITYPE,   INT_XRQS)      (int x) 
{
    QUAD_TYPE z = {.Lo.I=x};
    z.Hi.I = z.Lo.I>>63;
    return  z.I;
}

#if DWRD_NLONG == 2
INLINE(QUAD_UTYPE, ULONG_XRQS)    (ulong x) {return UINT_XRQS(x);}
INLINE(QUAD_ITYPE,  LONG_XRQS)     (long x) {return  INT_XRQS(x);}
#endif

#if 0 // _LEAVE_ALL_XRQS
}
#endif


#if 0 // _ENTER_ALL_XROZ
{
#endif
INLINE(   uint8_t, BOOL_XROZ)    (_Bool x) {return x;}
INLINE(  uint64_t,UCHAR_XROZ) (unsigned x) {return (uchar) x;}
INLINE(   int64_t,SCHAR_XROZ)   (signed x) {return (uchar) x;}
#if CHAR_MIN
INLINE(   int64_t, CHAR_XROZ)      (int x) {return (uchar) x;}
#else
INLINE(  uint64_t, CHAR_XROZ)      (int x) {return (uchar) x;}
#endif

INLINE(QUAD_UTYPE,USHRT_XROZ) (unsigned x) 
{
    QUAD_TYPE z = {.H0.U=x};
    return  z.U;
}

INLINE(QUAD_ITYPE, SHRT_XROZ)   (signed x) 
{
    QUAD_TYPE z = {.H0.U=x};
    return  z.I;
}

#if 0 // _LEAVE_ALL_XROZ
}
#endif

#if 0 // _ENTER_ALL_XROS
{
#endif

INLINE(   uint8_t, BOOL_XROS)    (_Bool x) {return 0-x;}
INLINE(  uint64_t,UCHAR_XROS) (unsigned x) {return (schar) x;}
INLINE(   int64_t,SCHAR_XROS)   (signed x) {return (schar) x;}
#if CHAR_MIN
INLINE(   int64_t, CHAR_XROS)      (int x) {return (schar) x;}
#else
INLINE(  uint64_t, CHAR_XROS)      (int x) {return (schar) x;}
#endif

INLINE(QUAD_UTYPE,USHRT_XROS) (unsigned x) 
{
    QUAD_TYPE z = {.Lo.I=(short) x};
    z.Hi.I = z.Lo.I>>63;
    return  z.U;
}

INLINE(QUAD_ITYPE, SHRT_XROS)  (signed x) 
{
    QUAD_TYPE z = {.Lo.I=(short) x};
    z.Hi.I = z.Lo.I>>63;
    return  z.I;
}

#if 0 // _LEAVE_ALL_XROS
}
#endif

#if 0 // _ENTER_ALL_AVGL
{
#endif
/*  average (round by truncation)

    -1.5 => -1
    -0.5 => -0
    +0.5 => +0
    +1.5 => +1
*/

INLINE( uchar, UCHAR_AVGL) (unsigned a, unsigned b) 
{
#define     UCHAR_AVGL(...) MY_BINOP(UCHAR_AVGL,__VA_ARGS__,0)
    return  ((uchar) a+(uchar) b)>>1;
}

INLINE( schar, SCHAR_AVGL)   (signed a,   signed b) 
{
#define     SCHAR_AVGL(...) MY_BINOP(SCHAR_AVGL,__VA_ARGS__,0)
    return  ((schar) a+(schar) b)/2;
}

INLINE(  char,  CHAR_AVGL)      (int a,      int b) 
{
#define     CHAR_AVGL(...) MY_BINOP(CHAR_AVGL,__VA_ARGS__,0)
#if CHAR_MIN
    return  SCHAR_AVGL(a, b);
#else
    return  UCHAR_AVGL(a, b);
#endif
}

INLINE(ushort, USHRT_AVGL) (unsigned a, unsigned b) 
{
#define     USHRT_AVGL(...) MY_BINOP(USHRT_AVGL,__VA_ARGS__,0)
    return  ((ushort) a+(ushort) b)>>1;
}

INLINE( short,  SHRT_AVGL)   (signed a,   signed b) 
{
#define     SHRT_AVGL(...) MY_BINOP(UCHAR_AVGL,__VA_ARGS__,0)
    return  ((short) a+(short) b)/2;
}


INLINE(  uint,  UINT_AVGL)     (uint a,     uint b) 
{
#define     UINT_AVGL(...) MY_BINOP(UINT_AVGL,__VA_ARGS__,0)
    return  ((uint64_t) a+b)>>1;
}

INLINE(   int,   INT_AVGL)      (int a,      int b) 
{
#define     INT_AVGL(...) MY_BINOP(INT_AVGL,__VA_ARGS__,0)
    return  ((int64_t) a+b)/2;
}


INLINE( ulong, ULONG_AVGL)    (ulong a,    ulong b) 
{
#define     ULONG_AVGL(...) MY_BINOP(ULONG_AVGL,__VA_ARGS__,0)
#if DWRD_NLONG == 2
    return UINT_AVGL(a, b);
#else
    return (a>>1)+(b>>1)+(a&b&1);
#endif
}

INLINE(  long,  LONG_AVGL)     (long a,     long b) 
{
#define     LONG_AVGL(...) MY_BINOP(LONG_AVGL,__VA_ARGS__,0)
#if DWRD_NLONG == 2
    return  INT_AVGL(a, b);
#else
    return (a/2)+(b/2)+(1&a&b);
#endif
}


INLINE(ullong,ULLONG_AVGL)   (ullong a,   ullong b) 
{
#define     ULLONG_AVGL(...) MY_BINOP(ULLONG_AVGL,__VA_ARGS__,0)
    return (a>>1)+(b>>1)+(1&a&b);
}

INLINE( llong, LLONG_AVGL)    (llong a,    llong b) 
{
#define     LLONG_AVGL(...) MY_BINOP(LLONG_AVGL,__VA_ARGS__,0)
    return (a/2)+(b/2)+(1&a&b);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,MY_AVGLQU) (QUAD_UTYPE a, int UNUSED(b))
{   
#define MY_AVGLQU(A, B, ...) \
(_Generic(B,int:(MY_AVGLQU),default:(avglqu))(A,B))

    (void) b;
    QUAD_TYPE x = {.U=a};
    x.Lo.U >>= 1;
    x.Lo.U |= (1&x.Hi.U)<<63;
    x.Hi.U >>= 1;
    return  x.U;
}

INLINE(QUAD_ITYPE,MY_AVGLQI) (QUAD_ITYPE a, int UNUSED(b))
{
#define MY_AVGLQI(A, B, ...) \
(_Generic(B,int:(MY_AVGLQI),default:(avglqi))(A,B))

#if defined(__SIZEOF_INT128__)
    return  a/2;
#endif
}

INLINE(QUAD_UTYPE,avglqu)    (QUAD_UTYPE a, QUAD_UTYPE b) 
{
#define     avglqu(...) MY_BINOP(MY_AVGLQU,__VA_ARGS__,0)
#if defined(__SIZEOF_INT128__)
    return (a>>1)+(b>>1)+(1&a&b);
#else
    QUAD_TYPE x={.U=a}, y={.U=b}, z;
    z.Lo.U = 1&x.Lo.U&y.Lo.U;
    z.Hi.U = 0;
    x.U = shrsqu(x.U, 1);
    y.U = shrsqu(y.U, 1);
    x.U = addlqu(x.U, y.U);
    x.U = addlqu(x.U, z.U);
    return  x.U;
#endif
}

INLINE(QUAD_ITYPE,avglqi)    (QUAD_ITYPE a, QUAD_ITYPE b) 
{
#define     avglqi(...) MY_BINOP(MY_AVGLQI,__VA_ARGS__,0)
#if defined(__SIZEOF_INT128__)
    return (a/2)+(b/2)+(1&a&b);
#else
    QUAD_ITYPE z = andsqi(a, b);
    z = andyqi(z, 1);
    a = divlqi(a, INT_CVQI(2));
    b = divlqi(a, INT_CVQI(2));
    a = addlqi(a, b);
    return addlqi(a, z);
#endif

}

#endif

#if 0 // _LEAVE_ALL_AVGL
}
#endif

#if 0 // _ENTER_ALL_AVGP
{
#endif

/*  average (round to +inf, i.e. ceil)

    -1.5 => -1
    -0.5 => -0
    +0.5 => +1
    +1.5 => +2
*/
INLINE( uchar, UCHAR_AVGP) (unsigned a, unsigned b)
{
    return  (1+(uchar) a+(uchar) b)>>1;
}

INLINE( schar, SCHAR_AVGP)   (signed a,   signed b)
{
    return  (1+(schar) a+(schar) b)>>1;
}

INLINE(  char,  CHAR_AVGP)      (int a,      int b)
{      
#if CHAR_MIN
    return  SCHAR_AVGP(a, b);
#else
    return  UCHAR_AVGP(a, b);
#endif
}

INLINE(ushort, USHRT_AVGP) (unsigned a, unsigned b)
{
    return  (1+(ushort) a+(ushort) b)>>1;
}

INLINE( short,  SHRT_AVGP)   (signed a,   signed b)
{
    return  (1+(short) a+(short) b)>>1;
}

INLINE(  uint,  UINT_AVGP)     (uint a,     uint b)
{
    return  (UINT64_C(1)+a+b)>>1;
}

INLINE(   int,   INT_AVGP)      (int a,      int b)
{
    return  (INT64_C(1)+a+b)>>1;
}

INLINE( ulong, ULONG_AVGP)    (ulong a,    ulong b)
{
#if DWRD_NLONG == 2
    return  UINT_AVGP(a, b);
#else
    return  (a>>1)+(b>>1)+(1&(a|b));
#endif
}

INLINE(  long,  LONG_AVGP)     (long a,     long b)
{
#if DWRD_NLONG == 2
    return  INT_AVGP(a, b);
#else
    return  (a>>1)+(b>>1)+(1&(a|b));
#endif
}

INLINE(ullong,ULLONG_AVGP)   (ullong a,   ullong b)
{
    return  (a>>1)+(b>>1)+(1&(a|b));
}

INLINE( llong, LLONG_AVGP)    (llong a,    llong b)
{
    return  (a>>1)+(b>>1)+(1&(a|b));
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,avgpqu)  (QUAD_UTYPE a,  QUAD_UTYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  (a>>1)+(b>>1)+(1&(a|b));
#else
    QUAD_UTYPE c = orrsqu(a, b);
    c = andyqu(c, 1);
    a = shrsqu(a);
    b = shrsqu(b);
    a = addlqu(a, b);
    return  addlqu(a, c);
#endif
}

INLINE(QUAD_ITYPE,avgpqi)  (QUAD_ITYPE a,  QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  (a>>1)+(b>>1)+(1&(a|b));
#else
    QUAD_ITYPE c = orrsqi(a, b);
    c = andyqi(c, 1);
    a = shrsqi(a);
    b = shrsqi(b);
    a = addlqi(a, b);
    return  addlqi(a, c);
#endif
}

#endif

#if 0 // _LEAVE_ALL_AVGP
}
#endif

#if 0 // _ENTER_ALL_AVGN
{
#endif
/*  average (round to -inf, i.e. floor)
    -1.5 => -2
    -0.5 => -1
    +0.5 => +0
    +1.5 => +1
*/

INLINE( uchar, UCHAR_AVGN) (unsigned a, unsigned b)
{
    return  UCHAR_AVGL(a, b);
}

INLINE( schar, SCHAR_AVGN)   (signed a,   signed b)
{
    return  ((schar) a+(schar) b)>>1;
}

INLINE(  char,  CHAR_AVGN)      (int a,      int b)
{      
#if CHAR_MIN
    return  SCHAR_AVGN(a, b);
#else
    return  UCHAR_AVGN(a, b);
#endif
}

INLINE(ushort, USHRT_AVGN) (unsigned a, unsigned b)
{
    return  USHRT_AVGL(a, b);
}

INLINE( short,  SHRT_AVGN)   (signed a,   signed b)
{
    return  ((short) a+(short) b)>>1;
}

INLINE(  uint,  UINT_AVGN)     (uint a,     uint b)
{
    return  UINT_AVGL(a, b);
}

INLINE(   int,   INT_AVGN)      (int a,      int b)
{
    return  ((int64_t) a+b)>>1;
}

INLINE( ulong, ULONG_AVGN)    (ulong a,    ulong b)
{
    return  ULONG_AVGL(a, b);
}

INLINE(  long,  LONG_AVGN)     (long a,     long b)
{
#if DWRD_NLONG == 2
    return  INT_AVGN(a, b);
#else
/*  (+1>>1=+0)+(+1>>1=+0) = 0
    (-1>>1=-1)+(-1>>1=-1) = -2
    
*/
    return  (a>>1)+(b>>1)+(1&a&b);
#endif
}

INLINE(ullong,ULLONG_AVGN)   (ullong a,   ullong b)
{
    return  ULLONG_AVGL(a, b);
}

INLINE( llong, LLONG_AVGN)    (llong a,    llong b)
{
    return  (a>>1)+(b>>1)+(1&a&b);
}

#if QUAD_NLLONG == 2

INLINE(QUAD_UTYPE,avgnqu)  (QUAD_UTYPE a,  QUAD_UTYPE b)
{
    return  avglqu(a, b);
}

INLINE(QUAD_ITYPE,avgnqi)  (QUAD_ITYPE a,  QUAD_ITYPE b)
{
#if defined(__SIZEOF_INT128__)
    return  (a>>1)+(b>>1)+(1&a&b);
#else
    QUAD_ITYPE c = orrsqi(a, b);
    a = shrsqi(a);
    b = shrsqi(b);
    return  addlqi(a, b);
#endif
}

#endif

#if 0 // _LEAVE_ALL_AVGN
}
#endif

/*

SCHAR_AVGN(-4) => -2
SCHAR_AVGP(-3) => -1
SCHAR_AVGP(-2) => -1 
SCHAR_AVGP(-1) => +0 
SCHAR_AVGP(+0) => +0 
SCHAR_AVGP(+1) => +1 
SCHAR_AVGP(+2) => +1 
SCHAR_AVGP(+3) => +2 
SCHAR_AVGP(+4) => +2

LLONG_AVGP(-4) => -2     
LLONG_AVGP(-3) => -1    
LLONG_AVGP(-2) => -1   
LLONG_AVGP(-1) => +0     
LLONG_AVGP(+0) => +0    
LLONG_AVGP(+1) => +1    
LLONG_AVGP(+2) => +1    
LLONG_AVGP(+3) => +2   
LLONG_AVGP(+4) => +2


hadd( {+4,+3,+2,+1}) => {+2,+1,+1,+0}
hadd( {-1,-2,-3,-4}) => {-1,-1,-2,-2}

        -4  -3  -2  -1  +1  +2  +3  +4
hadd    -2  -2  -1  -1  +0  +1  +1  +2

        -4  -3  -2  -1  +1  +2  +3  +4
rhadd   -2  -1  -1  +0  +1  +1  +2  +2


rhadd({+4,+3,+2,+1}) => {+2,+2,+1,+1}    
rhadd({-1,-2,-3,-4}) => {+0,-1,-1,-2}
    hadd            rhadd
    avgl(-1) => +0  avgp(-1) => -1
    avgl(-2) => -1  avgp(-2) => -1
    avgl(-3) => -1  avgp(-3) => 
    avgl(-4) => -2  avgp(-4)

vhaddq_s32( {0,0,0,0},{-1,-2,-3,-4}) => {-1,-1,-2,-2}

vrhaddq_s32({0,0,0,0},{-1,-2,-3,-4}) => {+0,-1,-1,-2}

vrhaddq_s32({0,0,0,0},{+1,+2,+3,+4}) => {+1,+1,+2,+2} 
0  
>>> posix.system('clang -o single -march=armv8.2-A -ferror-limit=5 -std=c11 /sdcard/C/ungop.c -I/sdcard/C -fsigned-char')  

0                                                     >>> posix.system("./single")                       
vhaddq_s32({0,0,0,0},{+1,+2,+3,+4}) => {+0,+1,+1,+2}  0

*/
