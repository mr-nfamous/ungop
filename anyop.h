/*
In the "generic" implementation, vector types are always 
defined as homogeneous aggregate types. Specifically, structs
consisting of 1, 2, 4, 8, 16, 32, 64, or 128 members that
represent each lane. For targets with little endian integer
representation, the vector elements will correspond in memory
to the array index.

    Vdhu        x = {0};
    uint16_t    y[4] = {0};
    offsetof(Vdhu, K0) == (y+0)-y;
    offsetof(Vdhu, K1) == (y+1)-y;
    offsetof(Vdhu, K2) == (y+2)-y;
    offsetof(Vdhu, K3) == (y+3)-y;

For targets with big endian integers, the lowest vector lane
will be at the end, which allows safely reinterpret casting
two differently sized views of the same vector, just like is
possibly for little endian. E.g.

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

    23-04-17
    * created anyop.h
    * implemented absu
    * implemented addl
    * implemented cvhs
    * implemented cvhz
    * implemented newl
    * implemented asbu
    * implemented asbi

*/

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

#define MY_VEC2IZE1(T, F, A, B) \
(                           \
    (T)                     \
    {                       \
        .K0 =F(A.K0,B.K0),  \
    }                       \
)

#define MY_VEC2IZE2(T, F, A, B) \
(                           \
    (T)                     \
    {                       \
        .K0 =F(A.K0,B.K0),  \
        .K1 =F(A.K1,B.K1),  \
    }                       \
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
        .K0 =F(A.K0,B.K0),      \
        .K1 =F(A.K1,B.K1),      \
        .K2 =F(A.K2,B.K2),      \
        .K3 =F(A.K3,B.K3),      \
        .K4 =F(A.K4,B.K4),      \
        .K5 =F(A.K5,B.K5),      \
        .K6 =F(A.K6,B.K6),      \
        .K7 =F(A.K7,B.K7),      \
        .K8 =F(A.K8,B.K8),      \
        .K9 =F(A.K9,B.K9),      \
        .K10=F(A.K10,B.K10),    \
        .K11=F(A.K11,B.K11),    \
        .K12=F(A.K12,B.K12),    \
        .K13=F(A.K13,B.K13),    \
        .K14=F(A.K14,B.K14),    \
        .K15=F(A.K15,B.K15),    \
    }                           \
)

#if _ENTER_ANY_ASBU
{
#endif

INLINE(Vwbu,VWYU_ASBU) (Vwyu v) {return ((Vw){.Y  =v}).B.U;}
INLINE(Vwbu,VWBI_ASBU) (Vwbi v) {return ((Vw){.B.I=v}).B.U;}
INLINE(Vwbu,VWBC_ASBU) (Vwbc v) {return ((Vw){.B.C=v}).B.U;}
INLINE(Vwbu,VWHU_ASBU) (Vwhu v) {return ((Vw){.H.U=v}).B.U;}
INLINE(Vwbu,VWHI_ASBU) (Vwhi v) {return ((Vw){.H.I=v}).B.U;}
INLINE(Vwbu,VWHF_ASBU) (Vwhf v) {return ((Vw){.H.F=v}).B.U;}
INLINE(Vwbu,VWWU_ASBU) (Vwwu v) {return ((Vw){.W.U=v}).B.U;}
INLINE(Vwbu,VWWI_ASBU) (Vwwi v) {return ((Vw){.W.I=v}).B.U;}
INLINE(Vwbu,VWWF_ASBU) (Vwwf v) {return ((Vw){.W.F=v}).B.U;}

INLINE(Vdbu,VDYU_ASBU) (Vdyu v) {return ((Vd){.Y  =v}).B.U;}
INLINE(Vdbu,VDBI_ASBU) (Vdbi v) {return ((Vd){.B.I=v}).B.U;}
INLINE(Vdbu,VDBC_ASBU) (Vdbc v) {return ((Vd){.B.C=v}).B.U;}
INLINE(Vdbu,VDHU_ASBU) (Vdhu v) {return ((Vd){.H.U=v}).B.U;}
INLINE(Vdbu,VDHI_ASBU) (Vdhi v) {return ((Vd){.H.I=v}).B.U;}
INLINE(Vdbu,VDHF_ASBU) (Vdhf v) {return ((Vd){.H.F=v}).B.U;}
INLINE(Vdbu,VDWU_ASBU) (Vdwu v) {return ((Vd){.W.U=v}).B.U;}
INLINE(Vdbu,VDWI_ASBU) (Vdwi v) {return ((Vd){.W.I=v}).B.U;}
INLINE(Vdbu,VDWF_ASBU) (Vdwf v) {return ((Vd){.W.F=v}).B.U;}
INLINE(Vdbu,VDDU_ASBU) (Vddu v) {return ((Vd){.D.U=v}).B.U;}
INLINE(Vdbu,VDDI_ASBU) (Vddi v) {return ((Vd){.D.I=v}).B.U;}
INLINE(Vdbu,VDDF_ASBU) (Vddf v) {return ((Vd){.D.F=v}).B.U;}

INLINE(Vqbu,VQYU_ASBU) (Vqyu v) {return ((Vq){.Y  =v}).B.U;}
INLINE(Vqbu,VQBI_ASBU) (Vqbi v) {return ((Vq){.B.I=v}).B.U;}
INLINE(Vqbu,VQBC_ASBU) (Vqbc v) {return ((Vq){.B.C=v}).B.U;}
INLINE(Vqbu,VQHU_ASBU) (Vqhu v) {return ((Vq){.H.U=v}).B.U;}
INLINE(Vqbu,VQHI_ASBU) (Vqhi v) {return ((Vq){.H.I=v}).B.U;}
INLINE(Vqbu,VQHF_ASBU) (Vqhf v) {return ((Vq){.H.F=v}).B.U;}
INLINE(Vqbu,VQWU_ASBU) (Vqwu v) {return ((Vq){.W.U=v}).B.U;}
INLINE(Vqbu,VQWI_ASBU) (Vqwi v) {return ((Vq){.W.I=v}).B.U;}
INLINE(Vqbu,VQWF_ASBU) (Vqwf v) {return ((Vq){.W.F=v}).B.U;}
INLINE(Vqbu,VQDU_ASBU) (Vqdu v) {return ((Vq){.D.U=v}).B.U;}
INLINE(Vqbu,VQDI_ASBU) (Vqdi v) {return ((Vq){.D.I=v}).B.U;}
INLINE(Vqbu,VQDF_ASBU) (Vqdf v) {return ((Vq){.D.F=v}).B.U;}

#if _LEAVE_ANY_ASBU
}
#endif


#if _ENTER_ANY_ASBI
{
#endif

INLINE(Vwbi,VWYU_ASBI) (Vwyu v) {return ((Vw){.Y=  v}).B.I;}
INLINE(Vwbi,VWBU_ASBI) (Vwbu v) {return ((Vw){.B.U=v}).B.I;}

INLINE(Vwbi,VWBC_ASBI) (Vwbc v) {return ((Vw){.B.C=v}).B.I;}
INLINE(Vwbi,VWHU_ASBI) (Vwhu v) {return ((Vw){.H.U=v}).B.I;}
INLINE(Vwbi,VWHI_ASBI) (Vwhi v) {return ((Vw){.H.I=v}).B.I;}
INLINE(Vwbi,VWHF_ASBI) (Vwhf v) {return ((Vw){.H.F=v}).B.I;}
INLINE(Vwbi,VWWU_ASBI) (Vwwu v) {return ((Vw){.W.U=v}).B.I;}
INLINE(Vwbi,VWWI_ASBI) (Vwwi v) {return ((Vw){.W.I=v}).B.I;}
INLINE(Vwbi,VWWF_ASBI) (Vwwf v) {return ((Vw){.W.F=v}).B.I;}


INLINE(Vdbi,VDYU_ASBI) (Vdyu v) {return ((Vd){.Y  =v}).B.I;}
INLINE(Vdbi,VDBU_ASBI) (Vdbu v) {return ((Vd){.B.U=v}).B.I;}

INLINE(Vdbi,VDBC_ASBI) (Vdbc v) {return ((Vd){.B.C=v}).B.I;}
INLINE(Vdbi,VDHU_ASBI) (Vdhu v) {return ((Vd){.H.U=v}).B.I;}
INLINE(Vdbi,VDHI_ASBI) (Vdhi v) {return ((Vd){.H.I=v}).B.I;}
INLINE(Vdbi,VDHF_ASBI) (Vdhf v) {return ((Vd){.H.F=v}).B.I;}
INLINE(Vdbi,VDWU_ASBI) (Vdwu v) {return ((Vd){.W.U=v}).B.I;}
INLINE(Vdbi,VDWI_ASBI) (Vdwi v) {return ((Vd){.W.I=v}).B.I;}
INLINE(Vdbi,VDWF_ASBI) (Vdwf v) {return ((Vd){.W.F=v}).B.I;}
INLINE(Vdbi,VDDU_ASBI) (Vddu v) {return ((Vd){.D.U=v}).B.I;}
INLINE(Vdbi,VDDI_ASBI) (Vddi v) {return ((Vd){.D.I=v}).B.I;}
INLINE(Vdbi,VDDF_ASBI) (Vddf v) {return ((Vd){.D.F=v}).B.I;}


INLINE(Vqbi,VQYU_ASBI) (Vqyu v) {return ((Vq){.Y  =v}).B.I;}
INLINE(Vqbi,VQBU_ASBI) (Vqbu v) {return ((Vq){.B.U=v}).B.I;}

INLINE(Vqbi,VQBC_ASBI) (Vqbc v) {return ((Vq){.B.C=v}).B.I;}
INLINE(Vqbi,VQHU_ASBI) (Vqhu v) {return ((Vq){.H.U=v}).B.I;}
INLINE(Vqbi,VQHI_ASBI) (Vqhi v) {return ((Vq){.H.I=v}).B.I;}
INLINE(Vqbi,VQHF_ASBI) (Vqhf v) {return ((Vq){.H.F=v}).B.I;}
INLINE(Vqbi,VQWU_ASBI) (Vqwu v) {return ((Vq){.W.U=v}).B.I;}
INLINE(Vqbi,VQWI_ASBI) (Vqwi v) {return ((Vq){.W.I=v}).B.I;}
INLINE(Vqbi,VQWF_ASBI) (Vqwf v) {return ((Vq){.W.F=v}).B.I;}
INLINE(Vqbi,VQDU_ASBI) (Vqdu v) {return ((Vq){.D.U=v}).B.I;}
INLINE(Vqbi,VQDI_ASBI) (Vqdi v) {return ((Vq){.D.I=v}).B.I;}
INLINE(Vqbi,VQDF_ASBI) (Vqdf v) {return ((Vq){.D.F=v}).B.I;}

#if _LEAVE_ANY_ASBI
}
#endif


#if _ENTER_ARM_NEWL
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

#if _LEAVE_ARM_NEWL
}
#endif


#if _ENTER_ANY_ABSU
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

#if _LEAVE_ANY_ABSU
}
#endif


#if _ENTER_ANY_ADDL
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

#if _LEAVE_ANY_ADDL
}
#endif


#if _ENTER_ANY_CVHS
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


#if _LEAVE_ANY_CVHS
}
#endif


#if _ENTER_ANY_CVHZ
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


#if _LEAVE_ANY_CVHZ
}
#endif
