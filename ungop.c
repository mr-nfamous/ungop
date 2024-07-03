#include "/sdcard/C/ungop.h"

#if 0

#undef MY_TEST 

#define MY_TEST(F, X) _Static_assert(F(X), "!" #F "(" #X ")\n" )
MY_TEST(BOOL_CKTY, BOOL_VOID);
MY_TEST(UCHAR_CKTY, UCHAR_VOID);
MY_TEST(SCHAR_CKTY, SCHAR_VOID);
MY_TEST(CHAR_CKTY, CHAR_VOID);
MY_TEST(USHRT_CKTY, USHRT_VOID);
MY_TEST(SHRT_CKTY, SHRT_VOID);
MY_TEST(UINT_CKTY, UINT_VOID);
MY_TEST(INT_CKTY, INT_VOID);
MY_TEST(ULONG_CKTY, ULONG_VOID);
MY_TEST(LONG_CKTY, LONG_VOID);
MY_TEST(ULLONG_CKTY, ULLONG_VOID);
MY_TEST(LLONG_CKTY, LLONG_VOID);
MY_TEST(FLT16_CKTY, FLT16_VOID);
MY_TEST(FLT_CKTY, FLT_VOID);
MY_TEST(DBL_CKTY, DBL_VOID);

MY_TEST(cktyyu,voidyu);
MY_TEST(cktyayu,voidayu);
MY_TEST(cktyacyu,voidacyu);

MY_TEST(cktybu,voidbu);
MY_TEST(cktyabu,voidabu);
MY_TEST(cktyacbu,voidacbu);

MY_TEST(cktybi,voidbi);
MY_TEST(cktyabi,voidabi);
MY_TEST(cktyacbi,voidacbi);

MY_TEST(cktybc,voidbc);
MY_TEST(cktyabc,voidabc);
MY_TEST(cktyacbc,voidacbc);

MY_TEST(cktyhu,voidhu);
MY_TEST(cktyahu,voidahu);
MY_TEST(cktyachu,voidachu);

MY_TEST(cktyhi,voidhi);
MY_TEST(cktyahi,voidahi);
MY_TEST(cktyachi,voidachi);

MY_TEST(cktyhf,voidhf);
MY_TEST(cktyahf,voidahf);
MY_TEST(cktyachf,voidachf);

MY_TEST(cktywu,voidwu);
MY_TEST(cktyawu,voidawu);
MY_TEST(cktyacwu,voidacwu);

MY_TEST(cktywi,voidwi);
MY_TEST(cktyawi,voidawi);
MY_TEST(cktyacwi,voidacwi);

MY_TEST(cktywf,voidwf);
MY_TEST(cktyawf,voidawf);
MY_TEST(cktyacwf,voidacwf);

MY_TEST(cktydu,voiddu);
MY_TEST(cktyadu,voidadu);
MY_TEST(cktyacdu,voidacdu);

MY_TEST(cktydi,voiddi);
MY_TEST(cktyadi,voidadi);
MY_TEST(cktyacdi,voidacdi);

MY_TEST(cktydf,voiddf);
MY_TEST(cktyadf,voidadf);
MY_TEST(cktyacdf,voidacdf);
MY_TEST(cktywyu,voidwyu);
MY_TEST(cktywbu,voidwbu);
MY_TEST(cktywbi,voidwbi);
MY_TEST(cktywbc,voidwbc);
MY_TEST(cktywhu,voidwhu);
MY_TEST(cktywhi,voidwhi);
MY_TEST(cktywhf,voidwhf);

MY_TEST(cktywwu,voidwwu);
MY_TEST(cktywwi,voidwwi);
MY_TEST(cktywwf,voidwwf);

MY_TEST(cktydyu,voiddyu);
MY_TEST(cktydbu,voiddbu);
MY_TEST(cktydbi,voiddbi);
MY_TEST(cktydbc,voiddbc);
MY_TEST(cktydhu,voiddhu);
MY_TEST(cktydhi,voiddhi);
MY_TEST(cktydhf,voiddhf);
MY_TEST(cktydwu,voiddwu);
MY_TEST(cktydwi,voiddwi);
MY_TEST(cktydwf,voiddwf);
MY_TEST(cktyddu,voidddu);
MY_TEST(cktyddi,voidddi);
MY_TEST(cktyddf,voidddf);

MY_TEST(cktyqyu,voidqyu);
MY_TEST(cktyqbu,voidqbu);
MY_TEST(cktyqbi,voidqbi);
MY_TEST(cktyqbc,voidqbc);
MY_TEST(cktyqhu,voidqhu);
MY_TEST(cktyqhi,voidqhi);
MY_TEST(cktyqhf,voidqhf);
MY_TEST(cktyqwu,voidqwu);
MY_TEST(cktyqwi,voidqwi);
MY_TEST(cktyqwf,voidqwf);
MY_TEST(cktyqdu,voidqdu);
MY_TEST(cktyqdi,voidqdi);
MY_TEST(cktyqdf,voidqdf);
MY_TEST(cktyqqu,voidqqu);
MY_TEST(cktyqqi,voidqqi);
MY_TEST(cktyqqf,voidqqf);

#endif

#if 1

int MY_CEQTEST(void)
{
    char const *why;
    int lno = -1;
#undef MY_TEST
#define MY_TEST(F, A, Y, N) lno = __LINE__; \
    do {    \
        if (!ceqy##F(A,Y))\
        {\
            why = "!ceqy" #F "( "#A ", " #Y ")";\
            goto fail;\
        }\
        if (ceqy##F(A,N))\
        {\
            why = "ceqy" #F "(" #A ", " #N ")";\
            goto fail;\
        }\
        if (!ckty##F(ceql##F(A,Y))) \
        {\
            why = "!ckty" #F "(ceql" #F "(" #A "," #Y "))";\
            goto fail;\
        }\
        if (!ckty##F(ceql##F(A,N))) \
        {\
            why = "!ckty" #F "(ceql" #F "(" #A "," #N "))";\
            goto fail;\
        }\
        if (+1 != cvwi##F(ceql##F(A,Y)))\
        {\
            why = "+1 != cvwi" #F "(ceql" #F"(" #A ", " #Y "))";\
            goto fail;\
        }\
        if (+0 != cvwi##F(ceql##F(A,N)))\
        {\
            why = "+1 != cvwi" #F "(ceql" #F"(" #A ", " #N "))";\
            goto fail;\
        }\
        if (!ckty##F(ceqs##F(A,Y))) \
        {\
            why = "!ckty" #F "(ceqs" #F "(" #A "," #Y "))";\
            goto fail;\
        }\
        if (!ckty##F(ceqs##F(A,N))) \
        {\
            why = "!ckty" #F "(ceqs" #F "(" #A "," #N "))";\
            goto fail;\
        }\
        if (cv##F##wi(-1) != cvwi##F(ceqs##F(A,Y)))\
        {\
            why = "cv"#F "wi(-1) != cvwi" #F "(ceqs" #F"(" #A ", " #Y "))";\
            goto fail;\
        }\
        if (+0 != cvwi##F(ceqs##F(A,N)))\
        {\
            why = "+0 != cvwi" #F "(ceqs" #F"(" #A ", " #N "))";\
            goto fail;\
        }\
    } while (0)

    MY_TEST(bu, +1, +1, ~+1);
    MY_TEST(bu, -1, -1, ~-1);
    MY_TEST(bu, UINT8_MAX, UINT8_MAX, ~UINT8_MAX);

    MY_TEST(bi, +1, +1, ~+0);
    MY_TEST(bi, -1, -1, ~-1);
    MY_TEST(bi, INT8_MAX, INT8_MAX, ~INT_MAX);
    MY_TEST(bi, INT8_MIN, INT8_MIN, ~INT_MIN);

    MY_TEST(bc, 1, 1, 0);
    MY_TEST(bc, CHAR_MAX, CHAR_MAX, ~CHAR_MAX);
    MY_TEST(bc, CHAR_MIN, CHAR_MIN, ~CHAR_MIN);

    MY_TEST(hu, +1, +1, ~+1);
    MY_TEST(hu, -1, -1, ~-1);
    MY_TEST(hu, UINT16_MAX, UINT16_MAX, ~UINT16_MAX);

    MY_TEST(hi, +1, +1, ~+0);
    MY_TEST(hi, -1, -1, ~-1);
    MY_TEST(hi, INT16_MAX, INT16_MAX, ~INT16_MAX);
    MY_TEST(hi, INT16_MIN, INT16_MIN, ~INT16_MIN);

    MY_TEST(wu, +1, +1, ~+1);
    MY_TEST(wu, -1, -1, ~-1);
    MY_TEST(wu, UINT32_MAX, UINT32_MAX, ~UINT32_MAX);
    
    MY_TEST(wi, +1, +1, ~+0);
    MY_TEST(wi, -1, -1, ~-1);
    MY_TEST(wi, INT32_MAX, INT32_MAX, ~INT32_MAX);
    MY_TEST(wi, INT32_MIN, INT32_MIN, ~INT32_MIN);

    MY_TEST(du, +1, +1, ~+1);
    MY_TEST(du, -1, -1, ~-1);
    MY_TEST(du, UINT64_MAX, UINT64_MAX, ~UINT64_MAX);

    MY_TEST(di, +1, +1, ~+0);
    MY_TEST(di, -1, -1, ~-1);
    MY_TEST(di, INT64_MAX, INT64_MAX, ~INT64_MAX);
    MY_TEST(di, INT64_MIN, INT64_MIN, ~INT64_MIN);

    QUAD_TYPE negq = QUAD_UMAX;
    QUAD_TYPE nilq = {0};
    QUAD_TYPE minq = QUAD_IMIN;
    QUAD_TYPE maxq = QUAD_IMAX;
    QUAD_TYPE posq = {.Lo.U=1};
    
    MY_TEST(qu, negq.U, negq.U, nilq.U); // -1q,-1q,+0q
    MY_TEST(qu, nilq.U, nilq.U, negq.U); // +0q,+0q,-1q
    MY_TEST(qu, posq.U, posq.U, nilq.U); // +1q,+1q,+0q
    MY_TEST(qu, maxq.U, maxq.U, minq.U); // max,max,min
    MY_TEST(qu, minq.U, minq.U, maxq.U); // max,max,min
    
    MY_TEST(qi, negq.I, negq.I, nilq.I); // -1q,-1q,+0q
    MY_TEST(qi, nilq.I, nilq.I, negq.I); // +0q,+0q,-1q
    MY_TEST(qi, posq.I, posq.I, nilq.I); // +1q,+1q,+0q
    MY_TEST(qi, maxq.I, maxq.I, minq.I); // max,max,min
    MY_TEST(qi, minq.I, minq.I, maxq.I); // max,max,min

    (void) printf("passed %s\n", __func__);
    return 0;
    fail: {return printf("failed test on line %i: %s\n", lno, why);}

#undef MY_TEST
}

#endif

#if 1 // mh_ceql_test

int ceqy_test(void)
{
    int lno;
    char const *why;
    union {
        union {     _Bool U;} Y;
        union {   uint8_t U;     int8_t I;       char C;} B;
        union {  uint16_t U;    int16_t I;    flt16_t F;} H;
        union {  uint32_t U;    int32_t I;      float F;} W;
        union {  uint64_t U;    int64_t I;     double F;} D;
        union {QUAD_UTYPE U; QUAD_ITYPE I; QUAD_FTYPE F;} Q;
    } k;
    WORD_VTYPE w = {0};
    DWRD_VTYPE d = {0};
    QUAD_VTYPE q = {0};
#undef TEST

#define TEST(T, V, X) \
if (!cktyyu(ceqy ## T(V.X, V.X))) \
do {\
    lno = __LINE__;\
    why = "!cktyyu(ceqy" #T "(" #V "." #X ", " #V "." #X "))\n";\
    goto fail;\
} while (0)

#define TESTK(T, X) TEST(T, k, X)
    TESTK(bu, B.U); TESTK(bi, B.I); TESTK(bc, B.C);
    TESTK(hu, H.U); TESTK(hi, H.I); TESTK(hf, H.F);
    TESTK(wu, W.U); TESTK(wi, W.I); TESTK(wf, W.F);
    TESTK(du, D.U); TESTK(di, D.I); TESTK(df, D.F);
    TESTK(qu, Q.U); TESTK(qi, Q.I); 
    
#undef TEST
#undef TESTK
#define TEST(F, X, A, B) \
if (X != ceqy##F(A,B)) do {\
    lno = __LINE__;\
    why = #X " != ceqy" #F "(" #A ", " #B ")\n";\
    goto fail;\
} while(0)

#define TESTWB(X, T, L0,L1,L2,L3,  R0,R1,R2,R3) \
if (X != ((ceqywb##T)(newwb##T(L0,L1,L2,L3), newwb##T(R0,R1,R2,R3)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqywh" #T "(" \
"newwb" #T "(" #L0 "," #L1 "," #L2 "," #L3 "), "\
"newwb" #T "(" #R0 "," #R1 "," #R2 "," #R3 "))\n";\
    goto fail;\
} while(0)

    TESTWB(1,u, +4,+3,+2,+1,  +4,+3,+2,+1);
    TESTWB(1,u, +1,+1,+1,+1,  +1,+1,+1,+1);
    TESTWB(1,u, +0,+0,+0,+0,  +0,+0,+0,+0);
    TESTWB(1,u, -1,-1,-1,-1,  -1,-1,-1,-1);

    TESTWB(0,u, +4,+3,+2,+1,  +4,+3,+2,+0);
    TESTWB(0,u, +4,+3,+2,+1,  +4,+3,+2,-1);
    TESTWB(0,u, +1,+1,+1,+1,  +2,+2,+2,+2);
    TESTWB(0,u, +1,+1,+1,+1,  -1,-1,-1,-1);
    TESTWB(0,u, +1,+1,+1,+1,  +0,+0,+0,+0);
    TESTWB(0,u, +0,+0,+0,+0,  +1,+1,+1,+1);
    TESTWB(0,u, 00,00,00,00,  -1,-1,-1,-1);

    TESTWB(1,i, +4,+3,+2,+1,  +4,+3,+2,+1);
    TESTWB(1,i, +1,+1,+1,+1,  +1,+1,+1,+1);
    TESTWB(1,i, +0,+0,+0,+0,  +0,+0,+0,+0);
    TESTWB(1,i, -1,-1,-1,-1,  -1,-1,-1,-1);

    TESTWB(0,i, +4,+3,+2,+1,  +4,+3,+2,+0);
    TESTWB(0,i, +4,+3,+2,+1,  +4,+3,+2,-1);
    TESTWB(0,i, +1,+1,+1,+1,  +2,+2,+2,+2);
    TESTWB(0,i, +1,+1,+1,+1,  -1,-1,-1,-1);
    TESTWB(0,i, +1,+1,+1,+1,  +0,+0,+0,+0);
    TESTWB(0,i, +0,+0,+0,+0,  +1,+1,+1,+1);
    TESTWB(0,i, 00,00,00,00,  -1,-1,-1,-1);

    TESTWB(1,c, +4,+3,+2,+1,  +4,+3,+2,+1);
    TESTWB(1,c, +1,+1,+1,+1,  +1,+1,+1,+1);
    TESTWB(1,c, +0,+0,+0,+0,  +0,+0,+0,+0);
    TESTWB(1,c, -1,-1,-1,-1,  -1,-1,-1,-1);

    TESTWB(0,c, +4,+3,+2,+1,  +4,+3,+2,+0);
    TESTWB(0,c, +4,+3,+2,+1,  +4,+3,+2,-1);
    TESTWB(0,c, +1,+1,+1,+1,  +2,+2,+2,+2);
    TESTWB(0,c, +1,+1,+1,+1,  -1,-1,-1,-1);
    TESTWB(0,c, +1,+1,+1,+1,  +0,+0,+0,+0);
    TESTWB(0,c, +0,+0,+0,+0,  +1,+1,+1,+1);
    TESTWB(0,c, 00,00,00,00,  -1,-1,-1,-1);
#undef TESTWB

#define TESTWH(X, T, L0,L1,  R0,R1) \
if (X != ((ceqywh##T)(newwh##T(L0,L1), newwh##T(R0,R1)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqywh" #T "(" \
"newwh" #T "(" #L0 "," #L1 "), "\
"newwh" #T "(" #R0 "," #R1 "))\n";\
    goto fail;\
} while(0)

    TESTWH(1,u, -1,-1,  -1,-1);
    TESTWH(1,u, +0,+0,  +0,+0);
    TESTWH(1,u, +1,+1,  +1,+1);
    TESTWH(1,u, +4,+3,  +4,+3);

    TESTWH(0,u, +3,+4,  +4,+3);
    TESTWH(0,u, +1,+1,  +0,+1);
    TESTWH(0,u, +1,+1,  +1,+0);
    TESTWH(0,u, +1,+1,  +0,+0);
    TESTWH(0,u, +0,+0,  +0,+1);
    TESTWH(0,u, +0,+0,  +1,+0);
    TESTWH(0,u, +0,+0,  +1,+1);
    TESTWH(0,u, -1,-1,  -1,+0);
    TESTWH(0,u, -1,-1,  +0,-1);
    TESTWH(0,u, -1,-1,  +0,+1);
    TESTWH(0,u, -1,-1,  +0,+0);

    TESTWH(1,i, -1,-1,  -1,-1);
    TESTWH(1,i, +0,+0,  +0,+0);
    TESTWH(1,i, +1,+1,  +1,+1);
    TESTWH(1,i, +4,+3,  +4,+3);

    TESTWH(0,i, +3,+4,  +4,+3);
    TESTWH(0,i, +1,+1,  +0,+1);
    TESTWH(0,i, +1,+1,  +1,+0);
    TESTWH(0,i, +1,+1,  +0,+0);
    TESTWH(0,i, +0,+0,  +0,+1);
    TESTWH(0,i, +0,+0,  +1,+0);
    TESTWH(0,i, +0,+0,  +1,+1);
    TESTWH(0,i, -1,-1,  -1,+0);
    TESTWH(0,i, -1,-1,  +0,-1);
    TESTWH(0,i, -1,-1,  +0,+1);
    TESTWH(0,i, -1,-1,  +0,+0);
#undef TESTWH

#define TESTWW(X, T, L0,  R0) \
if (X != ((ceqyww##T)(newww##T(L0), newww##T(R0)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqyww" #T "(" \
"newww" #T "(" #L0 "), "\
"newww" #T "(" #R0 "))\n";\
    goto fail;\
} while(0)

    TESTWW(1,u, 0x00000000U, 0x00000000U);
    TESTWW(1,u, 0x00000001U, 0x00000001U);
    TESTWW(1,u,   UINT8_MAX,   UINT8_MAX);
    TESTWW(1,u,    INT8_MAX,    INT8_MAX);
    TESTWW(1,u,  UINT16_MAX,  UINT16_MAX);
    TESTWW(1,u,   INT16_MAX,   INT16_MAX);
    TESTWW(1,u,  UINT32_MAX,  UINT32_MAX);
    TESTWW(1,u,   INT32_MAX,   INT32_MAX);
    
    TESTWW(0,u, 0x00000000U, 0x00000001U);
    TESTWW(0,u, 0x00000001U, 0x00000000U);
    TESTWW(0,u, 0xD3ADBEEFU, 0xDEADBEEFU);
    TESTWW(0,u,   UINT8_MAX,    INT8_MAX);
    TESTWW(0,u,  UINT16_MAX,   INT16_MAX);
    TESTWW(0,u,  UINT32_MAX,  UINT16_MAX);
    
    TESTWW(1,i, +0,+0);
    TESTWW(1,i, +1,+1);
    TESTWW(1,i, -1,-1);

    TESTWW(0,i, -1,+1);
    TESTWW(0,i, +1,-1);
    TESTWW(0,i, +1,+0);
    TESTWW(0,i, +0,+1);
    TESTWW(0,i, +0,-1);
    TESTWW(0,i, -1,+0);
    
    TESTWW(1,f, +0.0F, +0.0F);
    TESTWW(1,f, -0.0F, +0.0F);
    TESTWW(1,f, +0.0F, -0.0F);
    TESTWW(1,f, +1.0F, +1.0F);
    TESTWW(1,f, -1.0F, -1.0F);

    TESTWW(0,f, -1.0F, -0.0F);
    TESTWW(0,f, -1.0F, +0.0F);
    TESTWW(0,f, -1.0F, +1.0F);
    TESTWW(0,f, -0.0F, -1.0F);
    TESTWW(0,f, -0.0F, +1.0F);
    TESTWW(0,f, +0.0F, -1.0F);
    TESTWW(0,f, +0.0F, +1.0F);
    TESTWW(0,f, +1.0F, -1.0F);
    TESTWW(0,f, +1.0F, -0.0F);
#undef TESTWW

    
#define TESTDB(X, T, L0,L1,L2,L3,L4,L5,L6,L7, R0,R1,R2,R3,R4,R5,R6,R7) \
if (X != \
((ceqydb##T)(\
newdb##T(L0,L1,L2,L3,L4,L5,L6,L7), \
newdb##T(R0,R1,R2,R3,R4,R5,R6,R7)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqywh" #T "(" \
"newdb"#T"("#L0","#L1","#L2","#L3","#L4","#L5","#L6","#L7"), "\
"newdb"#T"("#R0","#R1","#R2","#R3","#R4","#R5","#R6","#R7"))\n";\
    goto fail;\
} while(0)

    TESTDB(1,u, +0,+0,+0,+0,+0,+0,+0,+0,  +0,+0,+0,+0,+0,+0,+0,+0);
    TESTDB(1,u, +0,+0,+0,+0,+0,+0,+0,+1,  +0,+0,+0,+0,+0,+0,+0,+1);
    TESTDB(1,u, +1,+1,+1,+1,+1,+1,+1,+1,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(1,u, +1,+1,+1,+1,+1,+1,+1,+0,  +1,+1,+1,+1,+1,+1,+1,+0);
    TESTDB(1,u, -1,-1,-1,-1,-1,-1,-1,-1,  -1,-1,-1,-1,-1,-1,-1,-1);
    TESTDB(1,u, -1,-1,-1,-1,-1,-1,-1,+0,  -1,-1,-1,-1,-1,-1,-1,+0);
    TESTDB(1,u, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,+1);

    TESTDB(0,u, +0,+0,+0,+0,+0,+0,+0,+0,  +0,+0,+0,+0,+0,+0,+0,+1);
    TESTDB(0,u, +0,+0,+0,+0,+0,+0,+0,+1,  +0,+0,+0,+0,+0,+0,+0,+0);
    TESTDB(0,u, +0,+1,+1,+1,+1,+1,+1,+1,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(0,u, +1,+1,+1,+1,+1,+1,+1,+0,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(0,u, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,-1);
    TESTDB(0,u, -1,-1,-1,-1,-1,-1,-1,+0,  -1,-1,-1,-1,-1,-1,-1,+1);
    TESTDB(0,u, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,+0);

    TESTDB(1,i, +0,+0,+0,+0,+0,+0,+0,+0,  +0,+0,+0,+0,+0,+0,+0,+0);
    TESTDB(1,i, +0,+0,+0,+0,+0,+0,+0,+1,  +0,+0,+0,+0,+0,+0,+0,+1);
    TESTDB(1,i, +1,+1,+1,+1,+1,+1,+1,+1,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(1,i, +1,+1,+1,+1,+1,+1,+1,+0,  +1,+1,+1,+1,+1,+1,+1,+0);
    TESTDB(1,i, -1,-1,-1,-1,-1,-1,-1,-1,  -1,-1,-1,-1,-1,-1,-1,-1);
    TESTDB(1,i, -1,-1,-1,-1,-1,-1,-1,+0,  -1,-1,-1,-1,-1,-1,-1,+0);
    TESTDB(1,i, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,+1);

    TESTDB(0,i, +0,+0,+0,+0,+0,+0,+0,+0,  +0,+0,+0,+0,+0,+0,+0,+1);
    TESTDB(0,i, +0,+0,+0,+0,+0,+0,+0,+1,  +0,+0,+0,+0,+0,+0,+0,+0);
    TESTDB(0,i, +0,+1,+1,+1,+1,+1,+1,+1,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(0,i, +1,+1,+1,+1,+1,+1,+1,+0,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(0,i, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,-1);
    TESTDB(0,i, -1,-1,-1,-1,-1,-1,-1,+0,  -1,-1,-1,-1,-1,-1,-1,+1);
    TESTDB(0,i, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,+0);

    TESTDB(0,c, +0,+0,+0,+0,+0,+0,+0,+0,  +0,+0,+0,+0,+0,+0,+0,+1);
    TESTDB(0,c, +0,+0,+0,+0,+0,+0,+0,+1,  +0,+0,+0,+0,+0,+0,+0,+0);
    TESTDB(0,c, +0,+1,+1,+1,+1,+1,+1,+1,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(0,c, +1,+1,+1,+1,+1,+1,+1,+0,  +1,+1,+1,+1,+1,+1,+1,+1);
    TESTDB(0,c, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,-1);
    TESTDB(0,c, -1,-1,-1,-1,-1,-1,-1,+0,  -1,-1,-1,-1,-1,-1,-1,+1);
    TESTDB(0,c, -1,-1,-1,-1,-1,-1,-1,+1,  -1,-1,-1,-1,-1,-1,-1,+0);
#undef TESTDB

#define TESTDH(X, T, L0,L1,L2,L3,  R0,R1,R2,R3) \
if (X != ((ceqydh##T)(newdh##T(L0,L1,L2,L3),newdh##T(R0,R1,R2,R3)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqydh" #T "(" \
"newdh" #T "(" #L0 "," #L1 "," #L2 "," #L3 "), "\
"newdh" #T "(" #R0 "," #R1 "," #R2 "," #R3 "))\n";\
    goto fail;\
} while(0)

    TESTDH(1,u, +4,+3,+2,+1,  +4,+3,+2,+1);
    TESTDH(1,u, +1,+1,+1,+1,  +1,+1,+1,+1);
    TESTDH(1,u, +0,+0,+0,+0,  +0,+0,+0,+0);
    TESTDH(1,u, -1,-1,-1,-1,  -1,-1,-1,-1);

    TESTDH(0,u, +4,+3,+2,+1,  +4,+3,+2,+0);
    TESTDH(0,u, +4,+3,+2,+1,  +4,+3,+2,-1);
    TESTDH(0,u, +1,+1,+1,+1,  +2,+2,+2,+2);
    TESTDH(0,u, +1,+1,+1,+1,  -1,-1,-1,-1);
    TESTDH(0,u, +1,+1,+1,+1,  +0,+0,+0,+0);
    TESTDH(0,u, +0,+0,+0,+0,  +1,+1,+1,+1);
    TESTDH(0,u, 00,00,00,00,  -1,-1,-1,-1);

    TESTDH(1,i, +4,+3,+2,+1,  +4,+3,+2,+1);
    TESTDH(1,i, +1,+1,+1,+1,  +1,+1,+1,+1);
    TESTDH(1,i, +0,+0,+0,+0,  +0,+0,+0,+0);
    TESTDH(1,i, -1,-1,-1,-1,  -1,-1,-1,-1);

    TESTDH(0,i, +4,+3,+2,+1,  +4,+3,+2,+0);
    TESTDH(0,i, +4,+3,+2,+1,  +4,+3,+2,-1);
    TESTDH(0,i, +1,+1,+1,+1,  +2,+2,+2,+2);
    TESTDH(0,i, +1,+1,+1,+1,  -1,-1,-1,-1);
    TESTDH(0,i, +1,+1,+1,+1,  +0,+0,+0,+0);
    TESTDH(0,i, +0,+0,+0,+0,  +1,+1,+1,+1);
    TESTDH(0,i, 00,00,00,00,  -1,-1,-1,-1);

#undef TESTDH

#define TESTDW(X, T, L0,L1,  R0,R1) \
if (X != ((ceqydw##T)(newdw##T(L0,L1), newdw##T(R0,R1)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqydw" #T "(" \
"newdw" #T "(" #L0 "," #L1 "), "\
"newdw" #T "(" #R0 "," #R1 "))\n";\
    goto fail;\
} while(0)
    TESTDW(1,u, -1,-1,  -1,-1);
    TESTDW(1,u, +0,+0,  +0,+0);
    TESTDW(1,u, +1,+1,  +1,+1);
    TESTDW(1,u, +4,+3,  +4,+3);

    TESTDW(0,u, +3,+4,  +4,+3);
    TESTDW(0,u, +1,+1,  +0,+1);
    TESTDW(0,u, +1,+1,  +1,+0);
    TESTDW(0,u, +1,+1,  +0,+0);
    TESTDW(0,u, +0,+0,  +0,+1);
    TESTDW(0,u, +0,+0,  +1,+0);
    TESTDW(0,u, +0,+0,  +1,+1);
    TESTDW(0,u, -1,-1,  -1,+0);
    TESTDW(0,u, -1,-1,  +0,-1);
    TESTDW(0,u, -1,-1,  +0,+1);
    TESTDW(0,u, -1,-1,  +0,+0);

    TESTDW(1,i, -1,-1,  -1,-1);
    TESTDW(1,i, +0,+0,  +0,+0);
    TESTDW(1,i, +1,+1,  +1,+1);
    TESTDW(1,i, +4,+3,  +4,+3);

    TESTDW(0,i, +3,+4,  +4,+3);
    TESTDW(0,i, +1,+1,  +0,+1);
    TESTDW(0,i, +1,+1,  +1,+0);
    TESTDW(0,i, +1,+1,  +0,+0);
    TESTDW(0,i, +0,+0,  +0,+1);
    TESTDW(0,i, +0,+0,  +1,+0);
    TESTDW(0,i, +0,+0,  +1,+1);
    TESTDW(0,i, -1,-1,  -1,+0);
    TESTDW(0,i, -1,-1,  +0,-1);
    TESTDW(0,i, -1,-1,  +0,+1);
    TESTDW(0,i, -1,-1,  +0,+0);
#undef TESTDW

#define TESTDD(X, T, L0,  R0) \
if (X != ((ceqydd##T)(newdd##T(L0), newdd##T(R0)))) \
do {\
    lno = __LINE__;\
    why = #X " != ceqydd" #T "(" \
"newdd" #T "(" #L0 "), "\
"newdd" #T "(" #R0 "))\n";\
    goto fail;\
} while(0)

    TESTDD(1,u, 0x00000000U, 0x00000000U);
    TESTDD(1,u, 0x00000001U, 0x00000001U);
    TESTDD(1,u,   UINT8_MAX,   UINT8_MAX);
    TESTDD(1,u,    INT8_MAX,    INT8_MAX);
    TESTDD(1,u,  UINT16_MAX,  UINT16_MAX);
    TESTDD(1,u,   INT16_MAX,   INT16_MAX);
    TESTDD(1,u,  UINT32_MAX,  UINT32_MAX);
    TESTDD(1,u,   INT32_MAX,   INT32_MAX);
    
    TESTDD(0,u, 0x00000000U, 0x00000001U);
    TESTDD(0,u, 0x00000001U, 0x00000000U);
    TESTDD(0,u, 0xD3ADBEEFU, 0xDEADBEEFU);
    TESTDD(0,u,   UINT8_MAX,    INT8_MAX);
    TESTDD(0,u,  UINT16_MAX,   INT16_MAX);
    TESTDD(0,u,  UINT32_MAX,  UINT16_MAX);
    
    TESTDD(1,i, +0,+0);
    TESTDD(1,i, +1,+1);
    TESTDD(1,i, -1,-1);

    TESTDD(0,i, -1,+1);
    TESTDD(0,i, +1,-1);
    TESTDD(0,i, +1,+0);
    TESTDD(0,i, +0,+1);
    TESTDD(0,i, +0,-1);
    TESTDD(0,i, -1,+0);
    
    TESTDD(1,f, +0.0, +0.0);
    TESTDD(1,f, -0.0, +0.0);
    TESTDD(1,f, +0.0, -0.0);
    TESTDD(1,f, +1.0, +1.0);
    TESTDD(1,f, -1.0, -1.0);

    TESTDD(0,f, -1.0, -0.0);
    TESTDD(0,f, -1.0, +0.0);
    TESTDD(0,f, -1.0, +1.0);
    TESTDD(0,f, -0.0, -1.0);
    TESTDD(0,f, -0.0, +1.0);
    TESTDD(0,f, +0.0, -1.0);
    TESTDD(0,f, +0.0, +1.0);
    TESTDD(0,f, +1.0, -1.0);
    TESTDD(0,f, +1.0, -0.0);
#undef TESTDD

#define TESTQBU(X, L0,L1,  R0,R1) \
if (X != ((ceqyqbu)(\
catldbu(vcreate_u8(L0##ULL),vcreate_u8(L1##ULL)),\
catldbu(vcreate_u8(R0##ULL),vcreate_u8(R1##ULL)))))\
do {\
    lno = __LINE__;\
    why = #X " != ceqyqbu(" \
"newqbu(" #L0 "," #L1 "), "\
"newqbu(" #R0 "," #R1 "))\n";\
    goto fail;\
} while(0)

    TESTQBU(
        1, 
        0x0000000000000000,0x0000000000000000,
        0x0000000000000000,0x0000000000000000
    );
    TESTQBU(
        1, 
        0x0000000000000001,0x0000000000000000,
        0x0000000000000001,0x0000000000000000
    );

    TEST(bu, 1, 0xff, 0xffff);
    TEST(bu, 1, 0x00, 0xff00);
    TEST(bu, 0, 0x00, 0xff01);

    TEST(bi, 1,        0,        0);
    TEST(bi, 1, INT8_MIN, INT8_MIN);
    TEST(bi, 1, INT8_MAX, INT8_MAX);
    TEST(bi, 1,   0x117f, 0xff7f);
    TEST(bi, 0,   0x1170, 0xff7f);

    TEST(bc, 1, '\0',           '\0');
    TEST(bc, 0, '\0',           '\1');
    TEST(bc, 1, 'a',            'a');
    TEST(bc, 1, 0x000|CHAR_MIN, CHAR_MIN);
    TEST(bc, 1, 0xf00|CHAR_MAX, CHAR_MAX);
    TEST(bc, 1, 0x07f,          0xff7f);
    TEST(bc, 0, 0x1170,         0xff7f);

    TEST(hu, 1, 0xffff, 0xffffffffU);
    TEST(hu, 1, 0xf000, 0xfffff000U);
    TEST(hu, 1, 0x0001, 0xffff0001U);
    TEST(hu, 0, 0x0001, 0xffff0000U);

    TEST(hi, 1,        0,        0);
    TEST(hi, 1,  INT16_MIN,  INT16_MIN);
    TEST(hi, 1,  INT16_MAX,  INT16_MAX);
    TEST(hi, 1, 0x12345678, 0x00005678);
    TEST(hi, 0,     0x1170,     0x1171);

    TEST(wu, 1, 0x0000ffffffffULL, 0xffffffffU);
    TEST(wu, 1, 0x00000000f000ULL, 0xf000U);
    TEST(wu, 1, 0x0000ffff0001ULL, 0xffff0001U);
    TEST(wu, 0, 0x000000000001ULL, 0x00000000U);

    TEST(wi, 1,               0,        0);
    TEST(wi, 1,       INT32_MIN,  INT32_MIN);
    TEST(wi, 1,       INT32_MAX,  INT32_MAX);
    TEST(wi, 1, 0x000012345678LL, 0x12345678);
    TEST(wi, 0, 0x000000001170LL,     0x1171);

    TEST(wf, 1, +1.0F, +1.0F);
    TEST(wf, 0, -1.0F, +1.0F);
    TEST(wf, 1, ((WORD_TYPE){.U=1U<<31}).F, 0.0F);

    TEST(du, 1, 0x0000ffffffffULL, 0xffffffffU);
    TEST(du, 1, 0x00000000f000ULL, 0xf000U);
    TEST(du, 1, 0x0000ffff0001ULL, 0xffff0001U);
    TEST(du, 0, 0x000000000001ULL, 0x00000000U);
    
    TEST(di, 1,               0,        0);
    TEST(di, 0,       INT64_MAX,  INT32_MAX);
    TEST(di, 1,       INT64_MIN,  INT64_MIN);
    TEST(di, 1,       INT64_MAX,  INT64_MAX);
    TEST(di, 1, 0x000012345678LL, 0x12345678);
    TEST(di, 0, 0x000000001170LL,     0x1171);

    TEST(df, 1, +1.0, +1.0);
    TEST(df, 0, -1.0, +1.0);
    TEST(df, 1, ((DWRD_TYPE){.U=1ULL<<63}).F, 0.0);


#if 0
#define TESTW(R,V,T,L,R) TEST(w##V##T,w##V##K,w.L,w.R)

    TESTW(u,b,u, B.U, B.U); 
    TESTW(i,b,i, B.I, B.I);
    TESTW(c,b,c, B.C, B.C);
    TESTW(u,h,u, H.U, H.U); 
    TESTW(u,h,i, H.I, H.I);
    TESTW(i,h,i, W.U, W.U); 
    TESTW(u,w,u, W.I, W.I);

    TESTW(i,w,f, W.I, W.F);
#undef TESTW

#define TESTD(V,K,T,L,R) TEST(d##V##T,d##V##K,d.L,d.R)
    TESTD(u,b,u, B.U, B.U); 
    TESTD(i,b,i, B.I, B.I);
    TESTD(c,b,c, B.C, B.C);
    TESTD(u,h,u, H.U, H.U); 
    TESTD(u,h,i, H.I, H.I);
    TESTD(i,h,i, W.U, W.U); 
    TESTD(u,w,u, W.I, W.I);
    TESTD(i,w,f, W.I, W.F);
    TESTD(u,d,u, D.U, D.U); 
    TESTD(i,d,i, D.I, D.I);
    TESTD(i,d,f, D.F, D.F);
#undef TESTD

#define TESTQ(V,K,T,L,R) TEST(q##V##T,q##V##K,q.L,q.R)
    TESTQ(u,b,u, B.U, B.U); 
    TESTQ(i,b,i, B.I, B.I);
    TESTQ(c,b,c, B.C, B.C);
    TESTQ(u,h,u, H.U, H.U); 
    TESTQ(u,h,i, H.I, H.I);
    TESTQ(i,h,i, W.U, W.U); 
    TESTQ(u,w,u, W.I, W.I);
    TESTQ(i,w,f, W.I, W.F);
    TESTQ(u,d,u, D.U, D.U); 
    TESTQ(i,d,i, D.I, D.I);
    TESTQ(i,d,f, D.F, D.F);
    TESTQ(u,q,u, Q.U, Q.U); 
    TESTQ(i,q,i, Q.I, Q.I); 
#undef TESTQ
#endif

    printf("%s passed\n", __func__);
    return 0;
    fail:
    {
        return printf("failed %s on line %i: %s", __func__,lno, why);
    }
}
#endif // my_ceqlty

int my_addlty(void)
{
    return 0;
#if 0

    int lno;
    char const *why;
#undef TEST

#define TEST(T, A, B) \
if (!ckty##T(addl##T(A,B))) \
do {\
    lno = __LINE__;\
    why = "!ckty" #T "(addl" #T "(" #A ", " #B "))\n";\
    goto fail;\
} while (0)

    TEST(yu, 0, 0);
    TEST(bu, 0, 0); TEST(bi, 0, 0); TEST(bc, 0, 0);
    TEST(hu, 0, 0); TEST(hi, 0, 0);
    TEST(wu, 0, 0); TEST(wi, 0, 0);
    TEST(du, 0, 0); TEST(di, 0, 0);
    TEST(qu, 0, 0); TEST(qi, 0, 0);
    WORD_VTYPE w = {0};
    TEST(wyu,w.Y.U, w.Y.U);
    TEST(wbu,w.B.U, w.B.U); TEST(wbi,w.B.I, w.B.I); TEST(wbc,w.B.C, w.B.C);
    TEST(whu,w.H.U, w.H.U); TEST(whi,w.H.I, w.H.I);
    TEST(wwu,w.W.U, w.W.U); TEST(wwi,w.W.I, w.W.I);
    DWRD_VTYPE d = {0};
    TEST(dyu,d.Y.U, d.Y.U);
    TEST(dbu,d.B.U, d.B.U); TEST(dbi,d.B.I, d.B.I); TEST(dbc,d.B.C, d.B.C);
    TEST(dhu,d.H.U, d.H.U); TEST(dhi,d.H.I, d.H.I);
    TEST(dwu,d.W.U, d.W.U); TEST(dwi,d.W.I, d.W.I);
    TEST(ddu,d.D.U, d.D.U); TEST(ddi,d.D.I, d.D.I);
    QUAD_VTYPE q = {0};
    TEST(qyu,q.Y.U, q.Y.U);
    TEST(qbu,q.B.U, q.B.U); TEST(qbi,q.B.I, q.B.I); TEST(qbc,q.B.C, q.B.C);
    TEST(qhu,q.H.U, q.H.U); TEST(qhi,q.H.I, q.H.I);
    TEST(qwu,q.W.U, q.W.U); TEST(qwi,q.W.I, q.W.I);
    TEST(qdu,q.D.U, q.D.U); TEST(qdi,q.D.I, q.D.I);
    TEST(qqu,q.Q.U, q.Q.U); TEST(qqi,q.Q.I, q.Q.I);

#undef TEST
#define TEST(T, A, B, C)    \
if (ceqladdl##T(A,B) != C) do { \
    lno = __LINE__;     \
    why = "addl"#T"("#A", "#B") != "#C"\n";\
    goto fail;\
} while (0)

    TEST(yu,0,0,0);TEST(yu,0,1,1);TEST(yu,1,0,1);TEST(yu,1,1,0);
    TEST(bu, 0x00, 0x00, 0x00);
    TEST(bu, 0x00, 0x01, 0x01);
    TEST(bu, 0xfe, 0x01, 0xff);
    TEST(bu, 0xff, 0x01, 0x00);
    TEST(bu, 0xff,   -1, 0xfe);
    TEST(bi,        0,  0,  0);
    TEST(bi,        0,  1,  1);
    TEST(bi,        1,  1,  2);
    TEST(bi,        1, -1,  0);
    TEST(bi,        1, -2, -1);
    TEST(bi, INT8_MAX,  1, INT8_MIN);
    TEST(bi, INT8_MIN, -1, INT8_MAX);

    TEST(hu, 0x0000, 0x0000, 0x0000);
    TEST(hu, 0x0000, 0x0001, 0x0001);
    TEST(hu, 0xfffe, 0x0001, 0xffff);
    TEST(hu, 0xffff, 0x0001, 0x0000);
    TEST(hu, 0xffff,     -1, 0xfffe);
    TEST(hi,         0,   0,  0);
    TEST(hi,         0,   1,  1);
    TEST(hi,         1,   1,  2);
    TEST(hi,         1,  -1,  0);
    TEST(hi,         1,  -2, -1);
    TEST(hi, INT16_MAX,   1, INT16_MIN);
    TEST(hi, INT16_MIN,  -1, INT16_MAX);

    TEST(wu, 0x00000000U, 0x00000000U, 0x00000000U);
    TEST(wu, 0x00000000U, 0x00000001U, 0x00000001U);
    TEST(wu, 0xfffffffeU, 0x00000001U, 0xffffffffU);
    TEST(wu, 0xffffffffU, 0x00000001U, 0x00000000U);
    TEST(wu, 0xffffffffU,         -1,  0xfffffffeU);
    TEST(wi,           0,          0,            0);
    TEST(wi,           0,          1,            1);
    TEST(wi,           1,          1,            2);
    TEST(wi,           1,         -1,            0);
    TEST(wi,           1,         -2,           -1);
    TEST(wi,   INT32_MAX,          1, INT32_MIN);
    TEST(wi,   INT32_MIN,         -1, INT32_MAX);

    TEST(du, UINT64_C(0), UINT64_C(0), UINT64_C(0));
    TEST(du, UINT64_C(0), UINT64_C(1), UINT64_C(1));
    TEST(du, UINT64_MAX,  UINT64_C(1), UINT64_C(0));
    TEST(du, UINT64_MAX,          -1,  UINT64_C(0xfffffffffffffffe));
    TEST(di,           0,          0,            0);
    TEST(di,           0,          1,            1);
    TEST(di,           1,          1,            2);
    TEST(di,           1,         -1,            0);
    TEST(di,           1,         -2,           -1);
    TEST(di,   INT64_MAX,          1, INT32_MIN);
    TEST(wi,   INT32_MIN,         -1, INT32_MAX);


    printf("addl passed\n");
    return 0;
    fail:
    {
        return printf("failed test on line %i: %s", lno, why);
    }
    
#endif

}

uint8x8_t 
my_cvbubyu(uint32_t j)
{
/*
    0b.0000.0000.0000.1111 =
    0b.0001.0001.0001.0001
    0b.0001.<<<<.<<<<.< = 9
    0b.0001.<<<<.<<<<.< = 9
    (49, 42, 35, 28, 21, 14, 7)
    {(j<<42), (j<<28)
*/
    uint64_t    d0 = j&0xff;
    uint64_t    d1 = (d0<<7);
    uint64_t    d2 = (d0<<14);
    uint64_t    d3 = (d0<<21);
    uint64_t    d4 = (d0|d1|d2|d3);
    d1 = (d0<<28);
    d2 = (d0<<35);
    d3 = (d0<<42);
    d0 = (d0<<49);
    d4 = (d0|d1|d2|d3|d4);
    d4 = 0x0101010101010101ULL&d4;
    return vcreate_u8(d4);
}

#if 0
unsigned MY_CNTW(unsigned v)
{

    unsigned int c; // store the total here
    static const int S[] = {1, 2, 4, 8, 16}; // Magic Binary Numbers
    static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};
    c = v - ((v >> 1) & B[0]);
    c = ((c >> S[1]) & B[1]) + (c & B[1]);
    c = ((c >> S[2]) + c) & B[2];
    c = ((c >> S[3]) + c) & B[3];
    c = ((c >> S[4]) + c) & B[4];
    return c;
}
#endif

#if 1
unsigned MY_CNTW(unsigned v)
{
    v = v-(0x55555555&(v>>001));
    v = (0x33333333&v)+(0x33333333&(v>>002));
    return ((v+(v>>04)&0xF0F0F0F)*0x1010101)>>24;
/*
This is the only version clang -O3 is capable of optimizing
into the cnt sequence:

        fmov    s0,     w0
        cnt     v0.8b,  v0.8b
        uaddlv  h0,     v0.8b
        fmov    w0,     s0

Note that this is best for 8, 16, and 32 bit operands, since
armv8's 'cnt' instruction simply sets each byte in a 64 or 
128 bit vector register to its hamming weight.
*/

}
#endif
#if 0
unsigned MY_CNTW(unsigned v)
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

uint64_t MY_CNTD(uint64_t v)
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

int main(int argc, char *argv[], char *envp[])
{
    for (uint64_t k=0; k < 8; k++)
    {
        uint64_t l = 8*k;
        uint64_t n = (1<<l)-1;
        for (uint64_t j=0; j < 256; j++)
        {
            uint64_t x = n+(j<<l);
            uint64_t y = revydu(x);
            uint64_t z = revydux86(x);
            if (y != z)
            {

                return printf(
                    "revyduarm(%"UINT64_DFMT") => %" UINT64_DFMT
                    "\n"
                    "revydux86(%"UINT64_DFMT") => %" UINT64_DFMT
                    "\n",
                    x,y,x,z
                );
            }
        }
    }
#if 0

    for (unsigned i=0, bj, mj; i <= 0xffff; i++)
    {
        if ((bj=__builtin_popcountll(i)) != (mj=MY_CNTD(i)))
        {
            printf("i=%u, b=%u, m=%u\n", i,bj,mj);
            exit(0);
        }
    }
    printf("cntd(0..0xffff) works bitches!\n");

    for (uint64_t i=(1+UINT32_MAX+1), j=(0xffff+i), bj, mj; i <= j; i++)
    {
        if ((bj=__builtin_popcountll(i)) != (mj=MY_CNTD(i)))
        {
            printf("i=%lu, b=%lu, m=%lu\n", i,bj,mj);
            exit(0);
        }
    }
    printf("cntd(0x1'0000'0000..0x1'0000'ffff) works bitches!\n");
    
    

    for (uint64_t i=(1ull<<48), j=(0xffff+i), bj, mj; i <= j; i++)
    {
        if ((bj=__builtin_popcountll(i)) != (mj=MY_CNTD(i)))
        {
            printf("i=%lu, b=%lu, m=%lu\n", i,bj,mj);
            exit(0);
        }
    }
    printf(
        "cntd("
        "0x1'0000'0000'0000.."
        "0x1'0000'0000'ffff) works bitches!\n"
    );
    
    

    for (uint64_t i=(1ull<<56), j=(0xffff+i), bj, mj; i <= j; i++)
    {
        if ((bj=__builtin_popcountll(i)) != (mj=MY_CNTD(i)))
        {
            printf("i=%lu, b=%lu, m=%lu\n", i,bj,mj);
            exit(0);
        }
    }
    printf(
        "cntd("
        "0x100'0000'0000'0000.."
        "0x100'0000'0000'ffff) works bitches!\n"
    );
    
    
#endif
#if 0

    if (0)
    {
        printf(
            "sillbu(0x0f, 0x0e, 4) => %u\n",
            (sillbu(0x0f, 0x0e, 4))
        );
    }

#if 0

    if (0)
    {
        outfwbu(
            subl(seqwbu('a', 1), dupwbu(32)),
            stdout,
            "{" DUP4("'%c'", ", ") "}\n"
        );
/*
    seqw    v0.wbu, 'A', 1d
    dupw    v1.wbu, 1d
    addl    v0.wbu, v0.wbu, v1.wbu

*/

    }

#endif

    if (0)
    {
        outfwbi(
            mull(seqwbi(0, 64), dupwbi(2)),
            stdout,
            "{" DUP4("%" INT8_DFMT , ", ") "}\n"
        );

    }

    if (0)
    {
        printf(
            "cvws(0xfeedf00du) => %d\n",
            (cvws(0xfeedf00du))
        );
    }

    if (0)
    {
        printf(
            "cgts(0xff, 0xfe) => %i\n",
            (cgts(0xff, 0xfe))
        );
    }

    if (0)
    {
        printf(
            "%g\n",
            cvdf( ((uint8_t) 69) )
        );

    }

    if (0)
    {

        printf(
            "0x%" UINT16_XFMT "\n",
            getr(0xdeadbeef)
        );
    }

    if (0)
    {
        int next = 0;
        int prev = invt(&next);
        printf("next=%i, prev=%i\n",next,prev);
    }

    if (0)
    {
        printf("rem2(31u, 8) => %hu\n", rem2(31u, 8));
    }

    if (0)
    {
        printf("rtnf(+1.99) => %g\n", rtnf(+1.99));
        printf("rtnf(-1.99) => %g\n", rtnf(-1.99));
    }

    if (0)
    {
        outfqwu(
            zlty(newlqwu(0,1,2,3)),
            stdout,
            "{" DUP4("%" UINT32_DFMT, ", ") "}\n"
        );
    }

    if (0)
    {
        outfqwi(
            abss(newlqwi(-1, INT_MIN, +1, INT_MAX)),
            stdout,
            "{" DUP4("%" INT32_DFMT, ", ") "}\n"
        );
    }

    if (0)
    {
        uint32x2_t a = newldwu(100, 100);
        uint32x2_t b = newldwu(200, 200);
        a = vhadd_u32(a, b);
        outfdwu(a, stdout, "{" DUP2("%" UINT32_DFMT,",") "}\n");
    }

    if (0)
    {
        int64x2_t a = newlqdi(+200,-200);
        int64x2_t b = newlqdi(-100,-100);
        a = avglqdi(a, b);
        outfqdi(a, stdout, "{" DUP2("%" INT64_DFMT,",") "}\n");
    }

    if (0)
    {
        uint32_t a = 69;
        uint32_t b = subt(&a, 9);
        printf(
            "a=%" UINT32_DFMT ", "
            "b=%" UINT32_DFMT "\n",
            a, b
        );
    }

    if (0)
    {
        printf("dcrl(70u) => %u\n", dcrl(70u));
    }

    if (0)
    {
        uint32_t var = 0xdead0000u;
        uint32_t old = orr1awu(&var, 0xbeefu);
        printf(
            "var=0x%08x, old=0x%08x\n",
            var, old
        );
    }

    if (0)
    {
        printf("icrl(68u) => %uu\n", icrl(68u));
        Vwhu smfd = newlwhu(0xdeac, 0xbeee);
        smfd = astu(icrl(smfd));
        outfwhu(
            smfd,
            stdout,
            "{" DUP2("0x%hx", ", ") "}\n"
        );

    }

    if (0)
    {
        printf(
            "shll(+2147483647, 1) => %i, "
            "shll(-1073741824, 1) => %i\n",
            (shll(+2147483647, 1)),
            (shll(-1073741824, 1))
        );
    }

    if (0)
    {
        printf(
            "vshld_s64(+2147483647, 1) => "
            "%d\n",
            (int) vshld_s64(+2147483647, 1)
        );
        printf(
            "vshld_n_s64(+2147483647, 1) => "
            "%d\n",
            (int) vshld_n_s64(+2147483647, 1)
        );
    }

    if (0)
    {
        uchar x;
        str1(&x, 0);
        (void) xort(&x, 0);
        (void) addt(&x, 1);
        (void) orrt(&x, 2);
        (void) andt(&x, 3);
        (void) subt(&x, 4);
        (void) icra(&x);
        (void) inve(&x);
        printf("x = %hhu\n", swptabu(&x, 255));
    }

    if (0)
    {
        int x[16];
        (void) sunq(x+1, dupqwi(0));
        (void) strw(x+0, newlwwi(12345678));
        printf("x = {%d}\n", *x);
    }

    if (0)
    {
        int a = 555;
        int b = xeqt(&a, 555, 69);
        printf("a=%i, b=%i\n", a, b);
    }

    if (0)
    {
        printf("1.1+2.2 = %g\n",sumf(newlqdf(1.1,2.2)));
    }

    if (0)
    {
        char const src[] = "0123456789abcdef";
        printf(
            "my_strlen(\"%s\"+7) => %zu\n", src,
            (my_strlen(src+7))
        );
        printf(
            "my_strlen(\"%s\"+13) => %zu\n", src,
            (my_strlen(src+13))
        );
    }
    
    if (0)
    {
        char txt[] = "How y'all doing 69?";
        (void) my_strupr(txt+3);
        printf(
            "my_strupr(txt+3) => \"%s\"\n",
            txt
        );
    }
    
    if (1) 
    {
        int arg = argc > 1 ? atoi(argv[1]) : 0;
        if (arg < 0)
        {
            return 0;
        }
        testupr_src = memset(
            ((char[256]){0}),
            'a',
            32
        );
        testupr(arg, 100000);
    }

#endif

    _Bool       kyu = 0;

    uint8_t     kbu = 0;
    int8_t      kbi = 0;
    char        kbc = 0;

    uint16_t    khu = 0;
    int16_t     khi = 0;
    flt16_t     khf = 0;
    
    uint32_t    kwu = 0;
    int32_t     kwi = 0;
    float       kwf = 0;
    
    uint64_t    kdu = 0;
    int64_t     kdi = 0;
    double      kdf = 0;

    Vwyu        vwyu = {0};
    Vwbu        vwbu = {0};
    Vwbi        vwbi = {0};
    Vwbc        vwbc = {0};
    Vwhu        vwhu = {0};
    Vwhi        vwhi = {0};
    Vwhf        vwhf = {0};
    Vwwu        vwwu = {0};
    Vwwi        vwwi = {0};
    Vwwf        vwwf = {0};

    Vdyu        vdyu = {0};
    Vdbu        vdbu = {0};
    Vdbi        vdbi = {0};
    Vdbc        vdbc = {0};
    Vdhu        vdhu = {0};
    Vdhi        vdhi = {0};
    Vdhf        vdhf = {0};
    Vdwu        vdwu = {0};
    Vdwi        vdwi = {0};
    Vdwf        vdwf = {0};
    Vddu        vddu = {0};
    Vddi        vddi = {0};
    Vddf        vddf = {0};

    Vqyu        vqyu = {0};
    Vqbu        vqbu = {0};
    Vqbi        vqbi = {0};
    Vqbc        vqbc = {0};
    Vqhu        vqhu = {0};
    Vqhi        vqhi = {0};
    Vqhf        vqhf = {0};
    Vqwu        vqwu = {0};
    Vqwi        vqwi = {0};
    Vqwf        vqwf = {0};
    Vqdu        vqdu = {0};
    Vqdi        vqdi = {0};
    Vqdf        vqdf = {0};
    Vqqu        vqqu = {0};
    
    char const *expr;
    int         line;
    
#define TASSERT(...) \
(\
    (expr = "(" #__VA_ARGS__ ")"),\
    (line = __LINE__),  \
    (__VA_ARGS__)      \
)

#define FASSERT(X) ((expr="!(" #X ")"), (line=__LINE__), !(X))

#define MY_FUNCOF_TESTS 1
/*  
The following tests ensure the type generic forms at least
resolve the appropriate function designator.
*/
#if 0 // enter 
{
#endif

#if 0 // leave 
}
#endif


#if 0 // enter ___
{
#endif

#if MY_FUNCOF_TESTS


#if 0 // DONE AND DUSTED

#if 0 // enter abs_
{
#endif
//  ABSH=BDS
    if (!TASSERT(absh_funcof( kbi) ==   (INT8_ABSH))) goto fail;
    if (!TASSERT(absh_funcof( khi) ==  (INT16_ABSH))) goto fail;
    if (!TASSERT(absh_funcof( kwi) ==  (INT32_ABSH))) goto fail;
    if (!TASSERT(absh_funcof( kdi) ==  (INT64_ABSH))) goto fail;
//  ABSHW=WHS
    if (!TASSERT(absh_funcof(vwbi) ==   (VWBI_ABSH))) goto fail;
    if (!TASSERT(absh_funcof(vwhi) ==   (VWHI_ABSH))) goto fail;
//  ABSBD=BWS
    if (!TASSERT(absh_funcof(vdbi) ==   (VDBI_ABSH))) goto fail;
    if (!TASSERT(absh_funcof(vdhi) ==   (VDHI_ABSH))) goto fail;
    if (!TASSERT(absh_funcof(vdwi) ==   (VDWI_ABSH))) goto fail;
//  ABSHQ=HDS
    if (!TASSERT(absh_funcof(vqhi) ==   (VQHI_ABSH))) goto fail;
    if (!TASSERT(absh_funcof(vqwi) ==   (VQWI_ABSH))) goto fail;
    if (!TASSERT(absh_funcof(vqdi) ==   (VQDI_ABSH))) goto fail;
 // ABSW=BDS
    if (!TASSERT(absw_funcof( kbi) ==   (INT8_ABSW))) goto fail;
    if (!TASSERT(absw_funcof( khi) ==  (INT16_ABSW))) goto fail;
    if (!TASSERT(absw_funcof( khf) ==  (FLT16_ABSW))) goto fail;
    if (!TASSERT(absw_funcof( kwi) ==  (INT32_ABSW))) goto fail;
    if (!TASSERT(absw_funcof( kwf) ==    (FLT_ABSW))) goto fail;
    if (!TASSERT(absw_funcof( kdi) ==  (INT64_ABSW))) goto fail;
    if (!TASSERT(absw_funcof( kdf) ==    (DBL_ABSW))) goto fail;
 // ABSWW=BWS
    if (!TASSERT(absw_funcof(vwbi) ==   (VWBI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vwhi) ==   (VWHI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vwhf) ==   (VWHF_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vwwi) ==   (VWWI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vwwf) ==   (VWWF_ABSW))) goto fail;
//  ABSWD=HDS
    if (!TASSERT(absw_funcof(vdhi) ==   (VDHI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vdhf) ==   (VDHF_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vdwi) ==   (VDWI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vdwf) ==   (VDWF_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vddi) ==   (VDDI_ABSW))) goto fail;
//  ABSWQ=WDS
    if (!TASSERT(absw_funcof(vqwi) ==   (VQWI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vqwf) ==   (VQWF_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vqdi) ==   (VQDI_ABSW))) goto fail;
    if (!TASSERT(absw_funcof(vqdf) ==   (VQDF_ABSW))) goto fail;
//  ABSD=BDS
    if (!TASSERT(absd_funcof( kbi) ==   (INT8_ABSD))) goto fail;
    if (!TASSERT(absd_funcof( khi) ==  (INT16_ABSD))) goto fail;
    if (!TASSERT(absd_funcof( khf) ==  (FLT16_ABSD))) goto fail;
    if (!TASSERT(absd_funcof( kwi) ==  (INT32_ABSD))) goto fail;
    if (!TASSERT(absd_funcof( kwf) ==    (FLT_ABSD))) goto fail;
    if (!TASSERT(absd_funcof( kdi) ==  (INT64_ABSD))) goto fail;
    if (!TASSERT(absd_funcof( kdf) ==    (DBL_ABSD))) goto fail;
//  ABSDW=HWS
    if (!TASSERT(absd_funcof(vwhi) ==   (VWHI_ABSD))) goto fail;
    if (!TASSERT(absd_funcof(vwhf) ==   (VWHF_ABSD))) goto fail;
    if (!TASSERT(absd_funcof(vwwi) ==   (VWWI_ABSD))) goto fail;
    if (!TASSERT(absd_funcof(vwwf) ==   (VWWF_ABSD))) goto fail;
//  ABSDD=WDS
    if (!TASSERT(absd_funcof(vdwi) ==   (VDWI_ABSD))) goto fail;
    if (!TASSERT(absd_funcof(vdwf) ==   (VDWF_ABSD))) goto fail;
    if (!TASSERT(absd_funcof(vddi) ==   (VDDI_ABSD))) goto fail;
//  ABSDQ=DS
    if (!TASSERT(absd_funcof(vqdi) ==   (VQDI_ABSD))) goto fail;
    if (!TASSERT(absd_funcof(vqdf) ==   (VQDF_ABSD))) goto fail;
//  ABSL=BDI
    if (!TASSERT(absl_funcof( kbi) ==   (INT8_ABSL))) goto fail;
    if (!TASSERT(absl_funcof( khi) ==  (INT16_ABSL))) goto fail;
    if (!TASSERT(absl_funcof( kwi) ==  (INT32_ABSL))) goto fail;
    if (!TASSERT(absl_funcof( kdi) ==  (INT64_ABSL))) goto fail;
//  ABSLW=BWI
    if (!TASSERT(absl_funcof(vwbi) ==   (VWBI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vwhi) ==   (VWHI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vwwi) ==   (VWWI_ABSL))) goto fail;
//  ABSLD=BDI
    if (!TASSERT(absl_funcof(vdbi) ==   (VDBI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vdhi) ==   (VDHI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vdwi) ==   (VDWI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vddi) ==   (VDDI_ABSL))) goto fail;
//  ABSLQ=BDI
    if (!TASSERT(absl_funcof(vqbi) ==   (VQBI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vqhi) ==   (VQHI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vqwi) ==   (VQWI_ABSL))) goto fail;
    if (!TASSERT(absl_funcof(vqdi) ==   (VQDI_ABSL))) goto fail;
//  ABSS=BDI
    if (!TASSERT(abss_funcof( kbi) ==   (INT8_ABSS))) goto fail;
    if (!TASSERT(abss_funcof( khi) ==  (INT16_ABSS))) goto fail;
    if (!TASSERT(abss_funcof( kwi) ==  (INT32_ABSS))) goto fail;
    if (!TASSERT(abss_funcof( kdi) ==  (INT64_ABSS))) goto fail;
//  ABSSW=BWI
    if (!TASSERT(abss_funcof(vwbi) ==   (VWBI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vwhi) ==   (VWHI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vwwi) ==   (VWWI_ABSS))) goto fail;
//  ABSSD=BDI
    if (!TASSERT(abss_funcof(vdbi) ==   (VDBI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vdhi) ==   (VDHI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vdwi) ==   (VDWI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vddi) ==   (VDDI_ABSS))) goto fail;
//  ABSSQ=BDI
    if (!TASSERT(abss_funcof(vqbi) ==   (VQBI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vqhi) ==   (VQHI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vqwi) ==   (VQWI_ABSS))) goto fail;
    if (!TASSERT(abss_funcof(vqdi) ==   (VQDI_ABSS))) goto fail;
//  ABSU=BDI
    if (!TASSERT(absu_funcof( kbi) ==   (INT8_ABSU))) goto fail;
    if (!TASSERT(absu_funcof( khi) ==  (INT16_ABSU))) goto fail;
    if (!TASSERT(absu_funcof( kwi) ==  (INT32_ABSU))) goto fail;
    if (!TASSERT(absu_funcof( kdi) ==  (INT64_ABSU))) goto fail;
//  ABSUW=BWI
    if (!TASSERT(absu_funcof(vwbi) ==   (VWBI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vwhi) ==   (VWHI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vwwi) ==   (VWWI_ABSU))) goto fail;
//  ABSUD=BDI
    if (!TASSERT(absu_funcof(vdbi) ==   (VDBI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vdhi) ==   (VDHI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vdwi) ==   (VDWI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vddi) ==   (VDDI_ABSU))) goto fail;
//  ABSUQ=BDI
    if (!TASSERT(absu_funcof(vqbi) ==   (VQBI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vqhi) ==   (VQHI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vqwi) ==   (VQWI_ABSU))) goto fail;
    if (!TASSERT(absu_funcof(vqdi) ==   (VQDI_ABSU))) goto fail;
#if 0 // leave abs_
}
#endif

#if 0 // enter add_
{
#endif
//  ADD1A=YDZ
    if (!TASSERT(add1_funcof(&kyu) ==   (BOOL_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&kbu) ==  (UINT8_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&kbi) ==   (INT8_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&khu) == (UINT16_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&khi) ==  (INT16_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&kwu) == (UINT32_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&kwi) ==  (INT32_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&kdu) == (UINT64_ADD1A))) goto fail;
    if (!TASSERT(add1_funcof(&kdi) ==  (INT64_ADD1A))) goto fail;
//  ADDAA=YDZ
    if (!TASSERT(adda_funcof(&kyu) ==   (BOOL_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&kbu) ==  (UINT8_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&kbi) ==   (INT8_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&khu) == (UINT16_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&khi) ==  (INT16_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&kwu) == (UINT32_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&kwi) ==  (INT32_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&kdu) == (UINT64_ADDAA))) goto fail;
    if (!TASSERT(adda_funcof(&kdi) ==  (INT64_ADDAA))) goto fail;
//  ADDEA=YDZ
    if (!TASSERT(adde_funcof(&kyu) ==   (BOOL_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&kbu) ==  (UINT8_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&kbi) ==   (INT8_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&khu) == (UINT16_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&khi) ==  (INT16_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&kwu) == (UINT32_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&kwi) ==  (INT32_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&kdu) == (UINT64_ADDEA))) goto fail;
    if (!TASSERT(adde_funcof(&kdi) ==  (INT64_ADDEA))) goto fail;
//  ADDTA=YDZ
    if (!TASSERT(addt_funcof(&kyu) ==   (BOOL_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&kbu) ==  (UINT8_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&kbi) ==   (INT8_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&khu) == (UINT16_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&khi) ==  (INT16_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&kwu) == (UINT32_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&kwi) ==  (INT32_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&kdu) == (UINT64_ADDTA))) goto fail;
    if (!TASSERT(addt_funcof(&kdi) ==  (INT64_ADDTA))) goto fail;
//  ADDL=YDZ
    if (!TASSERT(addl_funcof( kyu) ==   (BOOL_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( kbu) ==  (UINT8_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( kbi) ==   (INT8_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( khu) == (UINT16_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( khi) ==  (INT16_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( kwu) == (UINT32_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( kwi) ==  (INT32_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( kdu) == (UINT64_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof( kdi) ==  (INT64_ADDL)))  goto fail;
//  ADD2=YWZ
    if (!TASSERT(add2_funcof( kbu) ==  (UINT8_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof( kbi) ==   (INT8_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof( khu) == (UINT16_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof( khi) ==  (INT16_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof( kwu) == (UINT32_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof( kwi) ==  (INT32_ADD2)))  goto fail;
//  ADD2W=YWZ
    if (!TASSERT(add2_funcof(vwbu) ==   (VWBU_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vwbi) ==   (VWBI_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vwhu) ==   (VWHU_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vwhi) ==   (VWHI_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vwwu) ==   (VWWU_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vwwi) ==   (VWWI_ADD2)))  goto fail;
//  ADD2D=YWZ
    if (!TASSERT(add2_funcof(vdbu) ==   (VDBU_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vdbi) ==   (VDBI_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vdhu) ==   (VDHU_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vdhi) ==   (VDHI_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vdwu) ==   (VDWU_ADD2)))  goto fail;
    if (!TASSERT(add2_funcof(vdwi) ==   (VDWI_ADD2)))  goto fail;
//  ADD2Q=NONE
//  ADDLW=YWZ
    if (!TASSERT(addl_funcof(vwyu) ==   (VWYU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vwbu) ==   (VWBU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vwbi) ==   (VWBI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vwhu) ==   (VWHU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vwhi) ==   (VWHI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vwwu) ==   (VWWU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vwwi) ==   (VWWI_ADDL)))  goto fail;
//  ADDLD=YDZ
    if (!TASSERT(addl_funcof(vdyu) ==   (VDYU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vdbu) ==   (VDBU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vdbi) ==   (VDBI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vdhu) ==   (VDHU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vdhi) ==   (VDHI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vdwu) ==   (VDWU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vdwi) ==   (VDWI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vddu) ==   (VDDU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vddi) ==   (VDDI_ADDL)))  goto fail;
//  ADDLQ=YDZ
    if (!TASSERT(addl_funcof(vqyu) ==   (VQYU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqbu) ==   (VQBU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqbi) ==   (VQBI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqhu) ==   (VQHU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqhi) ==   (VQHI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqwu) ==   (VQWU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqwi) ==   (VQWI_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqdu) ==   (VQDU_ADDL)))  goto fail;
    if (!TASSERT(addl_funcof(vqdi) ==   (VQDI_ADDL)))  goto fail;
//  ADDS=YDZ
    if (!TASSERT(adds_funcof( kyu) ==   (BOOL_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( kbu) ==  (UINT8_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( kbi) ==   (INT8_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( khu) == (UINT16_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( khi) ==  (INT16_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( kwu) == (UINT32_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( kwi) ==  (INT32_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( kdu) == (UINT64_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof( kdi) ==  (INT64_ADDS)))  goto fail;
//  ADDSW=YWZ
    if (!TASSERT(adds_funcof(vwyu) ==   (VWYU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vwbu) ==   (VWBU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vwbi) ==   (VWBI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vwhu) ==   (VWHU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vwhi) ==   (VWHI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vwwu) ==   (VWWU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vwwi) ==   (VWWI_ADDS)))  goto fail;
//  ADDDD=YDZ
    if (!TASSERT(adds_funcof(vdyu) ==   (VDYU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vdbu) ==   (VDBU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vdbi) ==   (VDBI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vdhu) ==   (VDHU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vdhi) ==   (VDHI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vdwu) ==   (VDWU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vdwi) ==   (VDWI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vddu) ==   (VDDU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vddi) ==   (VDDI_ADDS)))  goto fail;
//  ADDSQ=YDZ
    if (!TASSERT(adds_funcof(vqbu) ==   (VQBU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqyu) ==   (VQYU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqbu) ==   (VQBU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqbi) ==   (VQBI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqhu) ==   (VQHU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqhi) ==   (VQHI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqwu) ==   (VQWU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqwi) ==   (VQWI_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqdu) ==   (VQDU_ADDS)))  goto fail;
    if (!TASSERT(adds_funcof(vqdi) ==   (VQDI_ADDS)))  goto fail;
//  ADDH=YDR
    if (!TASSERT(addh_funcof( kyu) ==   (BOOL_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kbu) ==  (UINT8_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kbi) ==   (INT8_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( khu) == (UINT16_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( khi) ==  (INT16_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( khf) ==  (FLT16_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kwu) == (UINT32_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kwi) ==  (INT32_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kwf) ==    (FLT_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kdu) == (UINT64_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kdi) ==  (INT64_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof( kdf) ==    (DBL_ADDH)))  goto fail;
//  ADDHW=BHR
    if (!TASSERT(addh_funcof(vwbu) ==   (VWBU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vwbi) ==   (VWBI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vwhu) ==   (VWHU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vwhi) ==   (VWHI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vwhf) ==   (VWHF_ADDH)))  goto fail;
//  ADDHD=BWR
    if (!TASSERT(addh_funcof(vdbu) ==   (VDBU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdbi) ==   (VDBI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdhu) ==   (VDHU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdhi) ==   (VDHI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdhf) ==   (VDHF_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdwu) ==   (VDWU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdwi) ==   (VDWI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vdwf) ==   (VDWF_ADDH)))  goto fail;
//  ADDHQ=HDR
    if (!TASSERT(addh_funcof(vqhu) ==   (VQHU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqhi) ==   (VQHI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqhf) ==   (VQHF_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqwu) ==   (VQWU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqwi) ==   (VQWI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqwf) ==   (VQWF_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqdu) ==   (VQDU_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqdi) ==   (VQDI_ADDH)))  goto fail;
    if (!TASSERT(addh_funcof(vqdf) ==   (VQDF_ADDH)))  goto fail;
//  ADDW=YDR
    if (!TASSERT(addw_funcof( kyu) ==   (BOOL_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kbu) ==  (UINT8_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kbi) ==   (INT8_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( khu) == (UINT16_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( khi) ==  (INT16_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( khf) ==  (FLT16_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kwu) == (UINT32_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kwi) ==  (INT32_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kwf) ==    (FLT_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kdu) == (UINT64_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kdi) ==  (INT64_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof( kdf) ==    (DBL_ADDW)))  goto fail;
//  ADDWW=BHR
    if (!TASSERT(addw_funcof(vwbu) ==   (VWBU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwbi) ==   (VWBI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwhu) ==   (VWHU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwhi) ==   (VWHI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwhf) ==   (VWHF_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwwu) ==   (VWWU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwwi) ==   (VWWI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vwwf) ==   (VWWF_ADDW)))  goto fail;
//  ADDWD=HDR
    if (!TASSERT(addw_funcof(vdhu) ==   (VDHU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vdhi) ==   (VDHI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vdhf) ==   (VDHF_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vdwu) ==   (VDWU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vdwi) ==   (VDWI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vdwf) ==   (VDWF_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vddu) ==   (VDDU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vddi) ==   (VDDI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vddf) ==   (VDDF_ADDW)))  goto fail;
//  ADDWQ=WDR
    if (!TASSERT(addw_funcof(vqwu) ==   (VQWU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vqwi) ==   (VQWI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vqwf) ==   (VQWF_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vqdu) ==   (VQDU_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vqdi) ==   (VQDI_ADDW)))  goto fail;
    if (!TASSERT(addw_funcof(vqdf) ==   (VQDF_ADDW)))  goto fail;
//  ADDD=YDR
    if (!TASSERT(addd_funcof( kyu) ==   (BOOL_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kbu) ==  (UINT8_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kbi) ==   (INT8_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( khu) == (UINT16_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( khi) ==  (INT16_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( khf) ==  (FLT16_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kwu) == (UINT32_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kwi) ==  (INT32_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kwf) ==    (FLT_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kdu) == (UINT64_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kdi) ==  (INT64_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof( kdf) ==    (DBL_ADDD)))  goto fail;
//  ADDDW=HWR
    if (!TASSERT(addd_funcof(vwhu) ==   (VWHU_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vwhi) ==   (VWHI_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vwhf) ==   (VWHF_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vwwu) ==   (VWWU_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vwwi) ==   (VWWI_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vwwf) ==   (VWWF_ADDD)))  goto fail;
//  ADDDD=WDR
    if (!TASSERT(addd_funcof(vdwu) ==   (VDWU_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vdwi) ==   (VDWI_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vdwf) ==   (VDWF_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vddu) ==   (VDDU_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vddi) ==   (VDDI_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vddf) ==   (VDDF_ADDD)))  goto fail;
//  ADDDQ=DR
    if (!TASSERT(addd_funcof(vqdu) ==   (VQDU_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vqdi) ==   (VQDI_ADDD)))  goto fail;
    if (!TASSERT(addd_funcof(vqdf) ==   (VQDF_ADDD)))  goto fail;
#if 0 // leave add_
}
#endif

#if 0 // enter and_
{
#endif
//  ANDS=YDZ
    if (!TASSERT(ands_funcof( kyu) ==   (BOOL_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( kbu) ==  (UINT8_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( kbi) ==   (INT8_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( khu) == (UINT16_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( khi) ==  (INT16_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( kwu) == (UINT32_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( kwi) ==  (INT32_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( kdu) == (UINT64_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof( kdi) ==  (INT64_ANDS)))  goto fail;
//  ANDSW=YWZ
    if (!TASSERT(ands_funcof(vwyu) ==   (VWYU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vwbu) ==   (VWBU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vwbi) ==   (VWBI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vwhu) ==   (VWHU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vwhi) ==   (VWHI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vwwu) ==   (VWWU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vwwi) ==   (VWWI_ANDS)))  goto fail;
//  ANDSD=YDZ
    if (!TASSERT(ands_funcof(vdyu) ==   (VDYU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vdbu) ==   (VDBU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vdbi) ==   (VDBI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vdhu) ==   (VDHU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vdhi) ==   (VDHI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vdwu) ==   (VDWU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vdwi) ==   (VDWI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vddu) ==   (VDDU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vddi) ==   (VDDI_ANDS)))  goto fail;
//  ANDSQ=YDZ
    if (!TASSERT(ands_funcof(vqbu) ==   (VQBU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqyu) ==   (VQYU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqbu) ==   (VQBU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqbi) ==   (VQBI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqhu) ==   (VQHU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqhi) ==   (VQHI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqwu) ==   (VQWU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqwi) ==   (VQWI_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqdu) ==   (VQDU_ANDS)))  goto fail;
    if (!TASSERT(ands_funcof(vqdi) ==   (VQDI_ANDS)))  goto fail;
//  ANDN=YDZ
    if (!TASSERT(andn_funcof( kyu) ==   (BOOL_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( kbu) ==  (UINT8_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( kbi) ==   (INT8_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( khu) == (UINT16_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( khi) ==  (INT16_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( kwu) == (UINT32_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( kwi) ==  (INT32_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( kdu) == (UINT64_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof( kdi) ==  (INT64_ANDN)))  goto fail;
//  ANDNW=YWZ
    if (!TASSERT(andn_funcof(vwyu) ==   (VWYU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vwbu) ==   (VWBU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vwbi) ==   (VWBI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vwhu) ==   (VWHU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vwhi) ==   (VWHI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vwwu) ==   (VWWU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vwwi) ==   (VWWI_ANDN)))  goto fail;
//  ANDND=YDZ
    if (!TASSERT(andn_funcof(vdyu) ==   (VDYU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vdbu) ==   (VDBU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vdbi) ==   (VDBI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vdhu) ==   (VDHU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vdhi) ==   (VDHI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vdwu) ==   (VDWU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vdwi) ==   (VDWI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vddu) ==   (VDDU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vddi) ==   (VDDI_ANDN)))  goto fail;
//  ANDNQ=YDZ
    if (!TASSERT(andn_funcof(vqyu) ==   (VQYU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqbu) ==   (VQBU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqyu) ==   (VQYU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqbu) ==   (VQBU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqbi) ==   (VQBI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqhu) ==   (VQHU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqhi) ==   (VQHI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqwu) ==   (VQWU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqwi) ==   (VQWI_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqdu) ==   (VQDU_ANDN)))  goto fail;
    if (!TASSERT(andn_funcof(vqdi) ==   (VQDI_ANDN)))  goto fail;
//  AND1A=YDZ
    if (!TASSERT(and1_funcof(&kyu) ==   (BOOL_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&kbu) ==  (UINT8_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&kbi) ==   (INT8_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&khu) == (UINT16_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&khi) ==  (INT16_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&kwu) == (UINT32_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&kwi) ==  (INT32_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&kdu) == (UINT64_AND1A))) goto fail;
    if (!TASSERT(and1_funcof(&kdi) ==  (INT64_AND1A))) goto fail;
//  ANDAA=YDZ
    if (!TASSERT(anda_funcof(&kyu) ==   (BOOL_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&kbu) ==  (UINT8_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&kbi) ==   (INT8_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&khu) == (UINT16_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&khi) ==  (INT16_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&kwu) == (UINT32_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&kwi) ==  (INT32_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&kdu) == (UINT64_ANDAA))) goto fail;
    if (!TASSERT(anda_funcof(&kdi) ==  (INT64_ANDAA))) goto fail;
//  ANDEA=YDZ
    if (!TASSERT(ande_funcof(&kyu) ==   (BOOL_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&kbu) ==  (UINT8_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&kbi) ==   (INT8_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&khu) == (UINT16_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&khi) ==  (INT16_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&kwu) == (UINT32_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&kwi) ==  (INT32_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&kdu) == (UINT64_ANDEA))) goto fail;
    if (!TASSERT(ande_funcof(&kdi) ==  (INT64_ANDEA))) goto fail;
//  ANDTA=YDZ
    if (!TASSERT(andt_funcof(&kyu) ==   (BOOL_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&kbu) ==  (UINT8_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&kbi) ==   (INT8_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&khu) == (UINT16_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&khi) ==  (INT16_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&kwu) == (UINT32_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&kwi) ==  (INT32_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&kdu) == (UINT64_ANDTA))) goto fail;
    if (!TASSERT(andt_funcof(&kdi) ==  (INT64_ANDTA))) goto fail;
#if 0 // leave and_
}
#endif

#if 0 // enter asy_
{
#endif
//  ASYU=YU
    if (!TASSERT(asyu_funcof( kyu) ==   (BOOL_ASYU)))  goto fail;
//  ASYUW=YWR
    if (!TASSERT(asyu_funcof(vwyu) ==   (VWYU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwbu) ==   (VWBU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwbi) ==   (VWBI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwhu) ==   (VWHU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwhi) ==   (VWHI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwhf) ==   (VWHF_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwwu) ==   (VWWU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwwi) ==   (VWWI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vwwf) ==   (VWWF_ASYU)))  goto fail;
//  ASYUD=YDR
    if (!TASSERT(asyu_funcof(vdyu) ==   (VDYU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdbu) ==   (VDBU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdbi) ==   (VDBI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdhu) ==   (VDHU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdhi) ==   (VDHI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdhf) ==   (VDHF_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdwu) ==   (VDWU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdwi) ==   (VDWI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vdwf) ==   (VDWF_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vddu) ==   (VDDU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vddi) ==   (VDDI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vddf) ==   (VDDF_ASYU)))  goto fail;
//  ASYUQ=YDR
    if (!TASSERT(asyu_funcof(vqyu) ==   (VQYU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqbu) ==   (VQBU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqbi) ==   (VQBI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqhu) ==   (VQHU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqhi) ==   (VQHI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqhf) ==   (VQHF_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqwu) ==   (VQWU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqwi) ==   (VQWI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqwf) ==   (VQWF_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqdu) ==   (VQDU_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqdi) ==   (VQDI_ASYU)))  goto fail;
    if (!TASSERT(asyu_funcof(vqdf) ==   (VQDF_ASYU)))  goto fail;
#if 0 // leave asy_
}
#endif

#if 0 // enter asb_
{
#endif
//  ASBU=BZ
    if (!TASSERT(asbu_funcof( kbu) ==  (UINT8_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof( kbi) ==   (INT8_ASBU)))  goto fail;
//  ASBUW=YWR
    if (!TASSERT(asbu_funcof(vwyu) ==   (VWYU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwbu) ==   (VWBU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwbi) ==   (VWBI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwhu) ==   (VWHU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwhi) ==   (VWHI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwhf) ==   (VWHF_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwwu) ==   (VWWU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwwi) ==   (VWWI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vwwf) ==   (VWWF_ASBU)))  goto fail;
//  ASBUD=YDR
    if (!TASSERT(asbu_funcof(vdyu) ==   (VDYU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdbu) ==   (VDBU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdbi) ==   (VDBI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdhu) ==   (VDHU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdhi) ==   (VDHI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdhf) ==   (VDHF_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdwu) ==   (VDWU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdwi) ==   (VDWI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vdwf) ==   (VDWF_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vddu) ==   (VDDU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vddi) ==   (VDDI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vddf) ==   (VDDF_ASBU)))  goto fail;
//  ASBUQ=YDR
    if (!TASSERT(asbu_funcof(vqyu) ==   (VQYU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqbu) ==   (VQBU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqbi) ==   (VQBI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqhu) ==   (VQHU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqhi) ==   (VQHI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqhf) ==   (VQHF_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqwu) ==   (VQWU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqwi) ==   (VQWI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqwf) ==   (VQWF_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqdu) ==   (VQDU_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqdi) ==   (VQDI_ASBU)))  goto fail;
    if (!TASSERT(asbu_funcof(vqdf) ==   (VQDF_ASBU)))  goto fail;
//  ASBI=BZ
    if (!TASSERT(asbi_funcof( kbu) ==  (UINT8_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof( kbi) ==   (INT8_ASBI)))  goto fail;
//  ASBIW=YWR
    if (!TASSERT(asbi_funcof(vwyu) ==   (VWYU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwbu) ==   (VWBU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwbi) ==   (VWBI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwhu) ==   (VWHU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwhi) ==   (VWHI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwhf) ==   (VWHF_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwwu) ==   (VWWU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwwi) ==   (VWWI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vwwf) ==   (VWWF_ASBI)))  goto fail;
//  ASBID=YDR
    if (!TASSERT(asbi_funcof(vdyu) ==   (VDYU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdbu) ==   (VDBU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdbi) ==   (VDBI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdhu) ==   (VDHU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdhi) ==   (VDHI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdhf) ==   (VDHF_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdwu) ==   (VDWU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdwi) ==   (VDWI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vdwf) ==   (VDWF_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vddu) ==   (VDDU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vddi) ==   (VDDI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vddf) ==   (VDDF_ASBI)))  goto fail;
//  ASBIQ=YDR
    if (!TASSERT(asbi_funcof(vqyu) ==   (VQYU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqbu) ==   (VQBU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqbi) ==   (VQBI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqhu) ==   (VQHU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqhi) ==   (VQHI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqhf) ==   (VQHF_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqwu) ==   (VQWU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqwi) ==   (VQWI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqwf) ==   (VQWF_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqdu) ==   (VQDU_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqdi) ==   (VQDI_ASBI)))  goto fail;
    if (!TASSERT(asbi_funcof(vqdf) ==   (VQDF_ASBI)))  goto fail;
//  ASBC=BZ
    if (!TASSERT(asbc_funcof( kbu) ==  (UINT8_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof( kbi) ==   (INT8_ASBC)))  goto fail;
//  ASBCW=YWR
    if (!TASSERT(asbc_funcof(vwyu) ==   (VWYU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwbu) ==   (VWBU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwbi) ==   (VWBI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwhu) ==   (VWHU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwhi) ==   (VWHI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwhf) ==   (VWHF_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwwu) ==   (VWWU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwwi) ==   (VWWI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vwwf) ==   (VWWF_ASBC)))  goto fail;
//  ASBCD=YDR
    if (!TASSERT(asbc_funcof(vdyu) ==   (VDYU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdbu) ==   (VDBU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdbi) ==   (VDBI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdhu) ==   (VDHU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdhi) ==   (VDHI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdhf) ==   (VDHF_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdwu) ==   (VDWU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdwi) ==   (VDWI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vdwf) ==   (VDWF_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vddu) ==   (VDDU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vddi) ==   (VDDI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vddf) ==   (VDDF_ASBC)))  goto fail;
//  ASBCQ=YDR
    if (!TASSERT(asbc_funcof(vqyu) ==   (VQYU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqbu) ==   (VQBU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqbi) ==   (VQBI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqhu) ==   (VQHU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqhi) ==   (VQHI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqhf) ==   (VQHF_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqwu) ==   (VQWU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqwi) ==   (VQWI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqwf) ==   (VQWF_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqdu) ==   (VQDU_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqdi) ==   (VQDI_ASBC)))  goto fail;
    if (!TASSERT(asbc_funcof(vqdf) ==   (VQDF_ASBC)))  goto fail;
#if 0 // leave asb_
}
#endif

#if 0 // enter ash_
{
#endif
//  ASHU=HR
    if (!TASSERT(ashu_funcof( khu) == (UINT16_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof( khi) ==  (INT16_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof( khf) ==  (FLT16_ASHU)))  goto fail;
//  ASHUW=YWR
    if (!TASSERT(ashu_funcof(vwyu) ==   (VWYU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwbu) ==   (VWBU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwbi) ==   (VWBI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwhu) ==   (VWHU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwhi) ==   (VWHI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwhf) ==   (VWHF_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwwu) ==   (VWWU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwwi) ==   (VWWI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vwwf) ==   (VWWF_ASHU)))  goto fail;
//  ASHUD=YDR
    if (!TASSERT(ashu_funcof(vdyu) ==   (VDYU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdbu) ==   (VDBU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdbi) ==   (VDBI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdhu) ==   (VDHU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdhi) ==   (VDHI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdhf) ==   (VDHF_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdwu) ==   (VDWU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdwi) ==   (VDWI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vdwf) ==   (VDWF_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vddu) ==   (VDDU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vddi) ==   (VDDI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vddf) ==   (VDDF_ASHU)))  goto fail;
//  ASHUQ=YDR
    if (!TASSERT(ashu_funcof(vqyu) ==   (VQYU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqbu) ==   (VQBU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqbi) ==   (VQBI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqhu) ==   (VQHU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqhi) ==   (VQHI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqhf) ==   (VQHF_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqwu) ==   (VQWU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqwi) ==   (VQWI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqwf) ==   (VQWF_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqdu) ==   (VQDU_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqdi) ==   (VQDI_ASHU)))  goto fail;
    if (!TASSERT(ashu_funcof(vqdf) ==   (VQDF_ASHU)))  goto fail;
//  ASHI=HR
    if (!TASSERT(ashi_funcof( khu) == (UINT16_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof( khi) ==  (INT16_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof( khf) ==  (FLT16_ASHI)))  goto fail;
//  ASHIW=YWR
    if (!TASSERT(ashi_funcof(vwyu) ==   (VWYU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwbu) ==   (VWBU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwbi) ==   (VWBI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwhu) ==   (VWHU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwhi) ==   (VWHI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwhf) ==   (VWHF_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwwu) ==   (VWWU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwwi) ==   (VWWI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vwwf) ==   (VWWF_ASHI)))  goto fail;
//  ASHID=YDR
    if (!TASSERT(ashi_funcof(vdyu) ==   (VDYU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdbu) ==   (VDBU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdbi) ==   (VDBI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdhu) ==   (VDHU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdhi) ==   (VDHI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdhf) ==   (VDHF_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdwu) ==   (VDWU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdwi) ==   (VDWI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vdwf) ==   (VDWF_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vddu) ==   (VDDU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vddi) ==   (VDDI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vddf) ==   (VDDF_ASHI)))  goto fail;
//  ASHIQ=YDR
    if (!TASSERT(ashi_funcof(vqyu) ==   (VQYU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqbu) ==   (VQBU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqbi) ==   (VQBI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqhu) ==   (VQHU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqhi) ==   (VQHI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqhf) ==   (VQHF_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqwu) ==   (VQWU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqwi) ==   (VQWI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqwf) ==   (VQWF_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqdu) ==   (VQDU_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqdi) ==   (VQDI_ASHI)))  goto fail;
    if (!TASSERT(ashi_funcof(vqdf) ==   (VQDF_ASHI)))  goto fail;
//  ASHF=HR
    if (!TASSERT(ashf_funcof( khu) == (UINT16_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof( khi) ==  (INT16_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof( khf) ==  (FLT16_ASHF)))  goto fail;
//  ASHFW=YWR
    if (!TASSERT(ashf_funcof(vwyu) ==   (VWYU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwbu) ==   (VWBU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwbi) ==   (VWBI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwhu) ==   (VWHU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwhi) ==   (VWHI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwhf) ==   (VWHF_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwwu) ==   (VWWU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwwi) ==   (VWWI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vwwf) ==   (VWWF_ASHF)))  goto fail;
//  ASHFD=YDR
    if (!TASSERT(ashf_funcof(vdyu) ==   (VDYU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdbu) ==   (VDBU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdbi) ==   (VDBI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdhu) ==   (VDHU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdhi) ==   (VDHI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdhf) ==   (VDHF_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdwu) ==   (VDWU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdwi) ==   (VDWI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vdwf) ==   (VDWF_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vddu) ==   (VDDU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vddi) ==   (VDDI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vddf) ==   (VDDF_ASHF)))  goto fail;
//  ASHFQ=YDR
    if (!TASSERT(ashf_funcof(vqyu) ==   (VQYU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqbu) ==   (VQBU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqbi) ==   (VQBI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqhu) ==   (VQHU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqhi) ==   (VQHI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqhf) ==   (VQHF_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqwu) ==   (VQWU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqwi) ==   (VQWI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqwf) ==   (VQWF_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqdu) ==   (VQDU_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqdi) ==   (VQDI_ASHF)))  goto fail;
    if (!TASSERT(ashf_funcof(vqdf) ==   (VQDF_ASHF)))  goto fail;
#if 0 // leave ash_
}
#endif

#if 0 // enter asw_
{
#endif
//  ASWU=WR
    if (!TASSERT(aswu_funcof( kwu) == (UINT32_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof( kwi) ==  (INT32_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof( kwf) ==    (FLT_ASWU)))  goto fail;
//  ASWUW=YWR
    if (!TASSERT(aswu_funcof(vwyu) ==   (VWYU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwbu) ==   (VWBU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwbi) ==   (VWBI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwhu) ==   (VWHU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwhi) ==   (VWHI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwhf) ==   (VWHF_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwwu) ==   (VWWU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwwi) ==   (VWWI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vwwf) ==   (VWWF_ASWU)))  goto fail;
//  ASWUD=YDR
    if (!TASSERT(aswu_funcof(vdyu) ==   (VDYU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdbu) ==   (VDBU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdbi) ==   (VDBI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdhu) ==   (VDHU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdhi) ==   (VDHI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdhf) ==   (VDHF_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdwu) ==   (VDWU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdwi) ==   (VDWI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vdwf) ==   (VDWF_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vddu) ==   (VDDU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vddi) ==   (VDDI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vddf) ==   (VDDF_ASWU)))  goto fail;
//  ASWUQ=YDR
    if (!TASSERT(aswu_funcof(vqyu) ==   (VQYU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqbu) ==   (VQBU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqbi) ==   (VQBI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqhu) ==   (VQHU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqhi) ==   (VQHI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqhf) ==   (VQHF_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqwu) ==   (VQWU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqwi) ==   (VQWI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqwf) ==   (VQWF_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqdu) ==   (VQDU_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqdi) ==   (VQDI_ASWU)))  goto fail;
    if (!TASSERT(aswu_funcof(vqdf) ==   (VQDF_ASWU)))  goto fail;
//  ASWI=WR
    if (!TASSERT(aswi_funcof( kwu) == (UINT32_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof( kwi) ==  (INT32_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof( kwf) ==    (FLT_ASWI)))  goto fail;
//  ASWIW=YWR
    if (!TASSERT(aswi_funcof(vwyu) ==   (VWYU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwbu) ==   (VWBU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwbi) ==   (VWBI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwhu) ==   (VWHU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwhi) ==   (VWHI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwhf) ==   (VWHF_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwwu) ==   (VWWU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwwi) ==   (VWWI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vwwf) ==   (VWWF_ASWI)))  goto fail;
//  ASWID=YDR
    if (!TASSERT(aswi_funcof(vdyu) ==   (VDYU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdbu) ==   (VDBU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdbi) ==   (VDBI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdhu) ==   (VDHU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdhi) ==   (VDHI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdhf) ==   (VDHF_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdwu) ==   (VDWU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdwi) ==   (VDWI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vdwf) ==   (VDWF_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vddu) ==   (VDDU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vddi) ==   (VDDI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vddf) ==   (VDDF_ASWI)))  goto fail;
//  ASWIQ=YDR
    if (!TASSERT(aswi_funcof(vqyu) ==   (VQYU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqbu) ==   (VQBU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqbi) ==   (VQBI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqhu) ==   (VQHU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqhi) ==   (VQHI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqhf) ==   (VQHF_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqwu) ==   (VQWU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqwi) ==   (VQWI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqwf) ==   (VQWF_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqdu) ==   (VQDU_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqdi) ==   (VQDI_ASWI)))  goto fail;
    if (!TASSERT(aswi_funcof(vqdf) ==   (VQDF_ASWI)))  goto fail;
//  ASWF=WR
    if (!TASSERT(aswf_funcof( kwu) == (UINT32_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof( kwi) ==  (INT32_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof( kwf) ==    (FLT_ASWF)))  goto fail;
//  ASWFW=YWR
    if (!TASSERT(aswf_funcof(vwyu) ==   (VWYU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwbu) ==   (VWBU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwbi) ==   (VWBI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwhu) ==   (VWHU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwhi) ==   (VWHI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwhf) ==   (VWHF_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwwu) ==   (VWWU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwwi) ==   (VWWI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vwwf) ==   (VWWF_ASWF)))  goto fail;
//  ASWFD=YDR
    if (!TASSERT(aswf_funcof(vdyu) ==   (VDYU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdbu) ==   (VDBU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdbi) ==   (VDBI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdhu) ==   (VDHU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdhi) ==   (VDHI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdhf) ==   (VDHF_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdwu) ==   (VDWU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdwi) ==   (VDWI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vdwf) ==   (VDWF_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vddu) ==   (VDDU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vddi) ==   (VDDI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vddf) ==   (VDDF_ASWF)))  goto fail;
//  ASWFQ=YDR
    if (!TASSERT(aswf_funcof(vqyu) ==   (VQYU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqbu) ==   (VQBU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqbi) ==   (VQBI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqhu) ==   (VQHU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqhi) ==   (VQHI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqhf) ==   (VQHF_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqwu) ==   (VQWU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqwi) ==   (VQWI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqwf) ==   (VQWF_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqdu) ==   (VQDU_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqdi) ==   (VQDI_ASWF)))  goto fail;
    if (!TASSERT(aswf_funcof(vqdf) ==   (VQDF_ASWF)))  goto fail;
#if 0 // leave asw_
}
#endif

#if 0 // enter asd_
{
#endif
//  ASDU=DR
    if (!TASSERT(asdu_funcof( kdu) == (UINT64_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof( kdi) ==  (INT64_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof( kdf) ==    (DBL_ASDU)))  goto fail;
//  ASDUW=NONE
//  ASDUD=YDR
    if (!TASSERT(asdu_funcof(vdyu) ==   (VDYU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdbu) ==   (VDBU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdbi) ==   (VDBI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdhu) ==   (VDHU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdhi) ==   (VDHI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdhf) ==   (VDHF_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdwu) ==   (VDWU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdwi) ==   (VDWI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vdwf) ==   (VDWF_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vddu) ==   (VDDU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vddi) ==   (VDDI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vddf) ==   (VDDF_ASDU)))  goto fail;
//  ASDUQ=YDR
    if (!TASSERT(asdu_funcof(vqyu) ==   (VQYU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqbu) ==   (VQBU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqbi) ==   (VQBI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqhu) ==   (VQHU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqhi) ==   (VQHI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqhf) ==   (VQHF_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqwu) ==   (VQWU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqwi) ==   (VQWI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqwf) ==   (VQWF_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqdu) ==   (VQDU_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqdi) ==   (VQDI_ASDU)))  goto fail;
    if (!TASSERT(asdu_funcof(vqdf) ==   (VQDF_ASDU)))  goto fail;
//  ASDI=DR
    if (!TASSERT(asdi_funcof( kdu) == (UINT64_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof( kdi) ==  (INT64_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof( kdf) ==    (DBL_ASDI)))  goto fail;
//  ASDIW=NONE
//  ASDID=YDR
    if (!TASSERT(asdi_funcof(vdyu) ==   (VDYU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdbu) ==   (VDBU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdbi) ==   (VDBI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdhu) ==   (VDHU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdhi) ==   (VDHI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdhf) ==   (VDHF_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdwu) ==   (VDWU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdwi) ==   (VDWI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vdwf) ==   (VDWF_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vddu) ==   (VDDU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vddi) ==   (VDDI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vddf) ==   (VDDF_ASDI)))  goto fail;
//  ASDIQ=YDR
    if (!TASSERT(asdi_funcof(vqyu) ==   (VQYU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqbu) ==   (VQBU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqbi) ==   (VQBI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqhu) ==   (VQHU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqhi) ==   (VQHI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqhf) ==   (VQHF_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqwu) ==   (VQWU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqwi) ==   (VQWI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqwf) ==   (VQWF_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqdu) ==   (VQDU_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqdi) ==   (VQDI_ASDI)))  goto fail;
    if (!TASSERT(asdi_funcof(vqdf) ==   (VQDF_ASDI)))  goto fail;
//  ASDF=DR
    if (!TASSERT(asdf_funcof( kdu) == (UINT64_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof( kdi) ==  (INT64_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof( kdf) ==    (DBL_ASDF)))  goto fail;
//  ASDFW=NONE
//  ASDFD=YDR
    if (!TASSERT(asdf_funcof(vdyu) ==   (VDYU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdbu) ==   (VDBU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdbi) ==   (VDBI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdhu) ==   (VDHU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdhi) ==   (VDHI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdhf) ==   (VDHF_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdwu) ==   (VDWU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdwi) ==   (VDWI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vdwf) ==   (VDWF_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vddu) ==   (VDDU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vddi) ==   (VDDI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vddf) ==   (VDDF_ASDF)))  goto fail;
//  ASDFQ=YDR
    if (!TASSERT(asdf_funcof(vqyu) ==   (VQYU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqbu) ==   (VQBU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqbi) ==   (VQBI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqhu) ==   (VQHU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqhi) ==   (VQHI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqhf) ==   (VQHF_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqwu) ==   (VQWU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqwi) ==   (VQWI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqwf) ==   (VQWF_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqdu) ==   (VQDU_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqdi) ==   (VQDI_ASDF)))  goto fail;
    if (!TASSERT(asdf_funcof(vqdf) ==   (VQDF_ASDF)))  goto fail;
#if 0 // leave asd_
}
#endif

#if 0 // enter ast_
{
#endif
//  ASTU=YDR
    if (!TASSERT(astu_funcof( kyu) ==   (BOOL_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kbu) ==  (UINT8_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kbi) ==   (INT8_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( khu) == (UINT16_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( khi) ==  (INT16_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( khf) ==  (FLT16_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kwu) == (UINT32_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kwi) ==  (INT32_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kwf) ==    (FLT_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kdu) == (UINT64_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kdi) ==  (INT64_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof( kdf) ==    (DBL_ASTU)))  goto fail;
//  ASTUW=YWR
    if (!TASSERT(astu_funcof(vwyu) ==   (VWYU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwbu) ==   (VWBU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwbi) ==   (VWBI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwhu) ==   (VWHU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwhi) ==   (VWHI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwhf) ==   (VWHF_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwwu) ==   (VWWU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwwi) ==   (VWWI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vwwf) ==   (VWWF_ASTU)))  goto fail;
//  ASTUD=YDR
    if (!TASSERT(astu_funcof(vdyu) ==   (VDYU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdbu) ==   (VDBU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdbi) ==   (VDBI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdhu) ==   (VDHU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdhi) ==   (VDHI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdhf) ==   (VDHF_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdwu) ==   (VDWU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdwi) ==   (VDWI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vdwf) ==   (VDWF_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vddu) ==   (VDDU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vddi) ==   (VDDI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vddf) ==   (VDDF_ASTU)))  goto fail;
//  ASTUQ=YDR
    if (!TASSERT(astu_funcof(vqyu) ==   (VQYU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqbu) ==   (VQBU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqbi) ==   (VQBI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqhu) ==   (VQHU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqhi) ==   (VQHI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqhf) ==   (VQHF_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqwu) ==   (VQWU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqwi) ==   (VQWI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqwf) ==   (VQWF_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqdu) ==   (VQDU_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqdi) ==   (VQDI_ASTU)))  goto fail;
    if (!TASSERT(astu_funcof(vqdf) ==   (VQDF_ASTU)))  goto fail;
//  ASTI=BDR
    if (!TASSERT(asti_funcof( kbu) ==  (UINT8_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kbi) ==   (INT8_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( khu) == (UINT16_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( khi) ==  (INT16_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( khf) ==  (FLT16_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kwu) == (UINT32_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kwi) ==  (INT32_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kwf) ==    (FLT_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kdu) == (UINT64_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kdi) ==  (INT64_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof( kdf) ==    (DBL_ASTI)))  goto fail;
//  ASTIW=BWR
    if (!TASSERT(asti_funcof(vwbu) ==   (VWBU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwbi) ==   (VWBI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwhu) ==   (VWHU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwhi) ==   (VWHI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwhf) ==   (VWHF_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwwu) ==   (VWWU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwwi) ==   (VWWI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vwwf) ==   (VWWF_ASTI)))  goto fail;
//  ASTID=BDR
    if (!TASSERT(asti_funcof(vdbu) ==   (VDBU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdbi) ==   (VDBI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdhu) ==   (VDHU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdhi) ==   (VDHI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdhf) ==   (VDHF_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdwu) ==   (VDWU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdwi) ==   (VDWI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vdwf) ==   (VDWF_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vddu) ==   (VDDU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vddi) ==   (VDDI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vddf) ==   (VDDF_ASTI)))  goto fail;
//  ASTIQ=BDR
    if (!TASSERT(asti_funcof(vqbu) ==   (VQBU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqbi) ==   (VQBI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqhu) ==   (VQHU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqhi) ==   (VQHI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqhf) ==   (VQHF_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqwu) ==   (VQWU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqwi) ==   (VQWI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqwf) ==   (VQWF_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqdu) ==   (VQDU_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqdi) ==   (VQDI_ASTI)))  goto fail;
    if (!TASSERT(asti_funcof(vqdf) ==   (VQDF_ASTI)))  goto fail;
//  ASTF=HDR
    if (!TASSERT(astf_funcof( khu) == (UINT16_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( khi) ==  (INT16_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( khf) ==  (FLT16_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( kwu) == (UINT32_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( kwi) ==  (INT32_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( kwf) ==    (FLT_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( kdu) == (UINT64_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( kdi) ==  (INT64_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof( kdf) ==    (DBL_ASTF)))  goto fail;
//  ASTFW=HWR
    if (!TASSERT(astf_funcof(vwhu) ==   (VWHU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vwhi) ==   (VWHI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vwhf) ==   (VWHF_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vwwu) ==   (VWWU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vwwi) ==   (VWWI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vwwf) ==   (VWWF_ASTF)))  goto fail;
//  ASTFD=HDR
    if (!TASSERT(astf_funcof(vdhu) ==   (VDHU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vdhi) ==   (VDHI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vdhf) ==   (VDHF_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vdwu) ==   (VDWU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vdwi) ==   (VDWI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vdwf) ==   (VDWF_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vddu) ==   (VDDU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vddi) ==   (VDDI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vddf) ==   (VDDF_ASTF)))  goto fail;
//  ASTFQ=HDR
    if (!TASSERT(astf_funcof(vqhu) ==   (VQHU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqhi) ==   (VQHI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqhf) ==   (VQHF_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqwu) ==   (VQWU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqwi) ==   (VQWI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqwf) ==   (VQWF_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqdu) ==   (VQDU_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqdi) ==   (VQDI_ASTF)))  goto fail;
    if (!TASSERT(astf_funcof(vqdf) ==   (VQDF_ASTF)))  goto fail;
//  ASTV=WDR;
    if (!TASSERT(astv_funcof( kwu) == (UINT32_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof( kwi) ==  (INT32_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof( kwf) ==    (FLT_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof( kdu) == (UINT64_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof( kdi) ==  (INT64_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof( kdf) ==    (DBL_ASTV)))  goto fail;
//  ASTVW=WR
    if (!TASSERT(astv_funcof(vwwu) ==   (VWWU_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof(vwwi) ==   (VWWI_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof(vwwf) ==   (VWWF_ASTV)))  goto fail;
//  ASTVD=DR
    if (!TASSERT(astv_funcof(vddu) ==   (VDDU_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof(vddi) ==   (VDDI_ASTV)))  goto fail;
    if (!TASSERT(astv_funcof(vddf) ==   (VDDF_ASTV)))  goto fail;
//  ASTVQ=NONE
#if 0 // leave ast_
}
#endif

#if 0 // enter avg_
{
#endif
//  AVGL=YDZ
    if (!TASSERT(avgl_funcof( kyu) ==   (BOOL_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( kbu) ==  (UINT8_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( kbi) ==   (INT8_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( khu) == (UINT16_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( khi) ==  (INT16_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( kwu) == (UINT32_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( kwi) ==  (INT32_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( kdu) == (UINT64_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof( kdi) ==  (INT64_AVGL)))  goto fail;
//  AVGLW=YWZ
    if (!TASSERT(avgl_funcof(vwyu) ==   (VWYU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vwbu) ==   (VWBU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vwbi) ==   (VWBI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vwhu) ==   (VWHU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vwhi) ==   (VWHI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vwwu) ==   (VWWU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vwwi) ==   (VWWI_AVGL)))  goto fail;
//  AVGLD=YDZ
    if (!TASSERT(avgl_funcof(vdyu) ==   (VDYU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vdbu) ==   (VDBU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vdbi) ==   (VDBI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vdhu) ==   (VDHU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vdhi) ==   (VDHI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vdwu) ==   (VDWU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vdwi) ==   (VDWI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vddu) ==   (VDDU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vddi) ==   (VDDI_AVGL)))  goto fail;
//  AVGLQ=YDZ
    if (!TASSERT(avgl_funcof(vqyu) ==   (VQYU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqbu) ==   (VQBU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqbi) ==   (VQBI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqhu) ==   (VQHU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqhi) ==   (VQHI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqwu) ==   (VQWU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqwi) ==   (VQWI_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqdu) ==   (VQDU_AVGL)))  goto fail;
    if (!TASSERT(avgl_funcof(vqdi) ==   (VQDI_AVGL)))  goto fail;
#if 0 // leave avg_
}
#endif

#if 0 // enter bfg_
{
#endif
//  BFG1=YDZ
    if (!TASSERT(bfg1_funcof( kbu) ==  (UINT8_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( kbi) ==   (INT8_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( khu) == (UINT16_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( khi) ==  (INT16_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( kwu) == (UINT32_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( kwi) ==  (INT32_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( kdu) == (UINT64_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof( kdi) ==  (INT64_BFG1)))  goto fail;
//  BFG1W=YWZ
    if (!TASSERT(bfg1_funcof(vwyu) ==   (VWYU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vwbu) ==   (VWBU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vwbi) ==   (VWBI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vwhu) ==   (VWHU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vwhi) ==   (VWHI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vwwu) ==   (VWWU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vwwi) ==   (VWWI_BFG1)))  goto fail;
//  BFG1D=YDZ
    if (!TASSERT(bfg1_funcof(vdyu) ==   (VDYU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vdbu) ==   (VDBU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vdbi) ==   (VDBI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vdhu) ==   (VDHU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vdhi) ==   (VDHI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vdwu) ==   (VDWU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vdwi) ==   (VDWI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vddu) ==   (VDDU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vddi) ==   (VDDI_BFG1)))  goto fail;
//  BFG1Q=YDZ
    if (!TASSERT(bfg1_funcof(vqyu) ==   (VQYU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqbu) ==   (VQBU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqbi) ==   (VQBI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqhu) ==   (VQHU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqhi) ==   (VQHI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqwu) ==   (VQWU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqwi) ==   (VQWI_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqdu) ==   (VQDU_BFG1)))  goto fail;
    if (!TASSERT(bfg1_funcof(vqdi) ==   (VQDI_BFG1)))  goto fail;
#if 0 // leave bfg_
}
#endif

#if 0 // enter bfs_
{
#endif
//  BFSL=BDZ
    if (!TASSERT(bfs1_funcof( kbu) ==  (UINT8_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( kbi) ==   (INT8_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( khu) == (UINT16_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( khi) ==  (INT16_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( kwu) == (UINT32_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( kwi) ==  (INT32_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( kdu) == (UINT64_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof( kdi) ==  (INT64_BFSL)))  goto fail;
//  BFSLW=YWZ
    if (!TASSERT(bfs1_funcof(vwyu) ==   (VWYU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vwbu) ==   (VWBU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vwbi) ==   (VWBI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vwhu) ==   (VWHU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vwhi) ==   (VWHI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vwwu) ==   (VWWU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vwwi) ==   (VWWI_BFSL)))  goto fail;
//  BFSLD=YDZ
    if (!TASSERT(bfs1_funcof(vdyu) ==   (VDYU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vdbu) ==   (VDBU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vdbi) ==   (VDBI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vdhu) ==   (VDHU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vdhi) ==   (VDHI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vdwu) ==   (VDWU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vdwi) ==   (VDWI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vddu) ==   (VDDU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vddi) ==   (VDDI_BFSL)))  goto fail;
//  BFSLQ=YDZ
#if 0
    if (!TASSERT(bfs1_funcof(vqyu) ==   (VQYU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqbu) ==   (VQBU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqbi) ==   (VQBI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqhu) ==   (VQHU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqhi) ==   (VQHI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqwu) ==   (VQWU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqwi) ==   (VQWI_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqdu) ==   (VQDU_BFSL)))  goto fail;
    if (!TASSERT(bfs1_funcof(vqdi) ==   (VQDI_BFSL)))  goto fail;
#endif

#if 0 // leave bfs_
}
#endif

#if 0 // enter bfc_
{
#endif
//  BFC1=YDZ
    if (!TASSERT(bfc1_funcof( kbu) ==  (UINT8_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( kbi) ==   (INT8_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( khu) == (UINT16_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( khi) ==  (INT16_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( kwu) == (UINT32_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( kwi) ==  (INT32_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( kdu) == (UINT64_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof( kdi) ==  (INT64_BFC1)))  goto fail;
//  BFC1W=YWZ
    if (!TASSERT(bfc1_funcof(vwyu) ==   (VWYU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vwbu) ==   (VWBU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vwbi) ==   (VWBI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vwhu) ==   (VWHU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vwhi) ==   (VWHI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vwwu) ==   (VWWU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vwwi) ==   (VWWI_BFC1)))  goto fail;
//  BFC1D=YDZ
    if (!TASSERT(bfc1_funcof(vdyu) ==   (VDYU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vdbu) ==   (VDBU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vdbi) ==   (VDBI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vdhu) ==   (VDHU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vdhi) ==   (VDHI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vdwu) ==   (VDWU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vdwi) ==   (VDWI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vddu) ==   (VDDU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vddi) ==   (VDDI_BFC1)))  goto fail;
#if 0
//  BFC1Q=YDZ
    if (!TASSERT(bfc1_funcof(vqyu) ==   (VQYU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqbu) ==   (VQBU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqbi) ==   (VQBI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqhu) ==   (VQHU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqhi) ==   (VQHI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqwu) ==   (VQWU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqwi) ==   (VQWI_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqdu) ==   (VQDU_BFC1)))  goto fail;
    if (!TASSERT(bfc1_funcof(vqdi) ==   (VQDI_BFC1)))  goto fail;
#endif
#if 0 // leave bfc_
}
#endif

#if 0 // enter bln_
{
#endif
//  BLNMW=BHR
    if (!TASSERT(blnm_funcof(vwbu) ==   (VWBU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vwbi) ==   (VWBI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vwhu) ==   (VWHU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vwhi) ==   (VWHI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vwhf) ==   (VWHF_BLNM)))  goto fail;
//  BLNMD=BWR
    if (!TASSERT(blnm_funcof(vdbu) ==   (VDBU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdbi) ==   (VDBI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdhu) ==   (VDHU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdhi) ==   (VDHI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdhf) ==   (VDHF_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdwu) ==   (VDWU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdwi) ==   (VDWI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vdwf) ==   (VDWF_BLNM)))  goto fail;
//  BLNMQ=BDR
    if (!TASSERT(blnm_funcof(vqbu) ==   (VQBU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqbi) ==   (VQBI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqhu) ==   (VQHU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqhi) ==   (VQHI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqhf) ==   (VQHF_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqwu) ==   (VQWU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqwi) ==   (VQWI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqwf) ==   (VQWF_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqdu) ==   (VQDU_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqdi) ==   (VQDI_BLNM)))  goto fail;
    if (!TASSERT(blnm_funcof(vqdf) ==   (VQDF_BLNM)))  goto fail;
#if 0 // leave bln_
}
#endif

#if 0 // enter cat_
{
#endif
//  CATL=BWR
    if (!TASSERT(catl_funcof( kbu) ==  (UINT8_CATL)))  goto fail;
    if (!TASSERT(catl_funcof( kbi) ==   (INT8_CATL)))  goto fail;
    if (!TASSERT(catl_funcof( khu) == (UINT16_CATL)))  goto fail;
    if (!TASSERT(catl_funcof( khi) ==  (INT16_CATL)))  goto fail;
    if (!TASSERT(catl_funcof( kwu) == (UINT32_CATL)))  goto fail;
    if (!TASSERT(catl_funcof( kwi) ==  (INT32_CATL)))  goto fail;
//  CATLW=YWR
    if (!TASSERT(catl_funcof(vwyu) ==   (VWYU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwbu) ==   (VWBU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwbi) ==   (VWBI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwhu) ==   (VWHU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwhi) ==   (VWHI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwhf) ==   (VWHF_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwwu) ==   (VWWU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwwi) ==   (VWWI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vwwf) ==   (VWWF_CATL)))  goto fail;
//  CATLD=YDR
    if (!TASSERT(catl_funcof(vdyu) ==   (VDYU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdbu) ==   (VDBU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdbi) ==   (VDBI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdhu) ==   (VDHU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdhi) ==   (VDHI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdhf) ==   (VDHF_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdwu) ==   (VDWU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdwi) ==   (VDWI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vdwf) ==   (VDWF_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vddu) ==   (VDDU_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vddi) ==   (VDDI_CATL)))  goto fail;
    if (!TASSERT(catl_funcof(vddf) ==   (VDDF_CATL)))  goto fail;
#if 0 // leave cat_
}
#endif

#if 0 // enter cbn_
{
#endif
//  CBNS=BDR
    if (!TASSERT(cbns_funcof( kbu) ==  (UINT8_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kbi) ==   (INT8_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( khu) == (UINT16_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( khi) ==  (INT16_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( khf) ==  (FLT16_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kwu) == (UINT32_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kwi) ==  (INT32_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kwf) ==    (FLT_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kdu) == (UINT64_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kdi) ==  (INT64_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof( kdf) ==    (DBL_CBNS)))  goto fail;
//  CBNSW=BWR
    if (!TASSERT(cbns_funcof(vwbu) ==   (VWBU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwbi) ==   (VWBI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwhu) ==   (VWHU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwhi) ==   (VWHI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwhf) ==   (VWHF_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwwu) ==   (VWWU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwwi) ==   (VWWI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vwwf) ==   (VWWF_CBNS)))  goto fail;
//  CBNSD=BDR
    if (!TASSERT(cbns_funcof(vdbu) ==   (VDBU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdbi) ==   (VDBI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdhu) ==   (VDHU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdhi) ==   (VDHI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdhf) ==   (VDHF_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdwu) ==   (VDWU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdwi) ==   (VDWI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vdwf) ==   (VDWF_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vddu) ==   (VDDU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vddi) ==   (VDDI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vddf) ==   (VDDF_CBNS)))  goto fail;
//  CBNSQ=BDR
    if (!TASSERT(cbns_funcof(vqbu) ==   (VQBU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqbi) ==   (VQBI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqhu) ==   (VQHU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqhi) ==   (VQHI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqhf) ==   (VQHF_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqwu) ==   (VQWU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqwi) ==   (VQWI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqwf) ==   (VQWF_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqdu) ==   (VQDU_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqdi) ==   (VQDI_CBNS)))  goto fail;
    if (!TASSERT(cbns_funcof(vqdf) ==   (VQDF_CBNS)))  goto fail;
//  CBNY=BDR
    if (!TASSERT(cbny_funcof( kbu) ==  (UINT8_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kbi) ==   (INT8_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( khu) == (UINT16_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( khi) ==  (INT16_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( khf) ==  (FLT16_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kwu) == (UINT32_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kwi) ==  (INT32_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kwf) ==    (FLT_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kdu) == (UINT64_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kdi) ==  (INT64_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof( kdf) ==    (DBL_CBNY)))  goto fail;
//  CBNYW=BWR
    if (!TASSERT(cbny_funcof(vwbu) ==   (VWBU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwbi) ==   (VWBI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwhu) ==   (VWHU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwhi) ==   (VWHI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwhf) ==   (VWHF_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwwu) ==   (VWWU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwwi) ==   (VWWI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vwwf) ==   (VWWF_CBNY)))  goto fail;
//  CBNYD=BDR
    if (!TASSERT(cbny_funcof(vdbu) ==   (VDBU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdbi) ==   (VDBI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdhu) ==   (VDHU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdhi) ==   (VDHI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdhf) ==   (VDHF_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdwu) ==   (VDWU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdwi) ==   (VDWI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vdwf) ==   (VDWF_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vddu) ==   (VDDU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vddi) ==   (VDDI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vddf) ==   (VDDF_CBNY)))  goto fail;
//  CBNYQ=BDR
    if (!TASSERT(cbny_funcof(vqbu) ==   (VQBU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqbi) ==   (VQBI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqhu) ==   (VQHU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqhi) ==   (VQHI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqhf) ==   (VQHF_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqwu) ==   (VQWU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqwi) ==   (VQWI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqwf) ==   (VQWF_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqdu) ==   (VQDU_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqdi) ==   (VQDI_CBNY)))  goto fail;
    if (!TASSERT(cbny_funcof(vqdf) ==   (VQDF_CBNY)))  goto fail;
#if 0 // leave cbn_
}
#endif

#if 0 // enter cnb_
{
#endif
//  CNBS=BDR
    if (!TASSERT(cnbs_funcof( kbu) ==  (UINT8_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kbi) ==   (INT8_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( khu) == (UINT16_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( khi) ==  (INT16_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( khf) ==  (FLT16_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kwu) == (UINT32_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kwi) ==  (INT32_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kwf) ==    (FLT_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kdu) == (UINT64_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kdi) ==  (INT64_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof( kdf) ==    (DBL_CNBS)))  goto fail;
//  CNBSW=BWR
    if (!TASSERT(cnbs_funcof(vwbu) ==   (VWBU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwbi) ==   (VWBI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwhu) ==   (VWHU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwhi) ==   (VWHI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwhf) ==   (VWHF_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwwu) ==   (VWWU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwwi) ==   (VWWI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vwwf) ==   (VWWF_CNBS)))  goto fail;
//  CNBSD=BDR
    if (!TASSERT(cnbs_funcof(vdbu) ==   (VDBU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdbi) ==   (VDBI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdhu) ==   (VDHU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdhi) ==   (VDHI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdhf) ==   (VDHF_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdwu) ==   (VDWU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdwi) ==   (VDWI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vdwf) ==   (VDWF_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vddu) ==   (VDDU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vddi) ==   (VDDI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vddf) ==   (VDDF_CNBS)))  goto fail;
//  CNBSQ=BDR
    if (!TASSERT(cnbs_funcof(vqbu) ==   (VQBU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqbi) ==   (VQBI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqhu) ==   (VQHU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqhi) ==   (VQHI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqhf) ==   (VQHF_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqwu) ==   (VQWU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqwi) ==   (VQWI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqwf) ==   (VQWF_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqdu) ==   (VQDU_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqdi) ==   (VQDI_CNBS)))  goto fail;
    if (!TASSERT(cnbs_funcof(vqdf) ==   (VQDF_CNBS)))  goto fail;
//  CNBY=BDR
    if (!TASSERT(cnby_funcof( kbu) ==  (UINT8_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kbi) ==   (INT8_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( khu) == (UINT16_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( khi) ==  (INT16_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( khf) ==  (FLT16_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kwu) == (UINT32_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kwi) ==  (INT32_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kwf) ==    (FLT_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kdu) == (UINT64_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kdi) ==  (INT64_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof( kdf) ==    (DBL_CNBY)))  goto fail;
//  CNBYW=BWR
    if (!TASSERT(cnby_funcof(vwbu) ==   (VWBU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwbi) ==   (VWBI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwhu) ==   (VWHU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwhi) ==   (VWHI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwhf) ==   (VWHF_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwwu) ==   (VWWU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwwi) ==   (VWWI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vwwf) ==   (VWWF_CNBY)))  goto fail;
//  CNBYD=BDR
    if (!TASSERT(cnby_funcof(vdbu) ==   (VDBU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdbi) ==   (VDBI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdhu) ==   (VDHU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdhi) ==   (VDHI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdhf) ==   (VDHF_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdwu) ==   (VDWU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdwi) ==   (VDWI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vdwf) ==   (VDWF_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vddu) ==   (VDDU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vddi) ==   (VDDI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vddf) ==   (VDDF_CNBY)))  goto fail;
//  CNBYQ=BDR
    if (!TASSERT(cnby_funcof(vqbu) ==   (VQBU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqbi) ==   (VQBI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqhu) ==   (VQHU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqhi) ==   (VQHI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqhf) ==   (VQHF_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqwu) ==   (VQWU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqwi) ==   (VQWI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqwf) ==   (VQWF_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqdu) ==   (VQDU_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqdi) ==   (VQDI_CNBY)))  goto fail;
    if (!TASSERT(cnby_funcof(vqdf) ==   (VQDF_CNBY)))  goto fail;
#if 0 // leave cnb_
}
#endif

#if 0 // enter ceq_
{
#endif
//  CEQS=BDR
    if (!TASSERT(ceqs_funcof( kbu) ==  (UINT8_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kbi) ==   (INT8_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( khu) == (UINT16_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( khi) ==  (INT16_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( khf) ==  (FLT16_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kwu) == (UINT32_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kwi) ==  (INT32_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kwf) ==    (FLT_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kdu) == (UINT64_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kdi) ==  (INT64_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof( kdf) ==    (DBL_CEQS)))  goto fail;
//  CEQSW=BWR
    if (!TASSERT(ceqs_funcof(vwbu) ==   (VWBU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwbi) ==   (VWBI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwhu) ==   (VWHU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwhi) ==   (VWHI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwhf) ==   (VWHF_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwwu) ==   (VWWU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwwi) ==   (VWWI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vwwf) ==   (VWWF_CEQS)))  goto fail;
//  CEQSD=BDR
    if (!TASSERT(ceqs_funcof(vdbu) ==   (VDBU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdbi) ==   (VDBI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdhu) ==   (VDHU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdhi) ==   (VDHI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdhf) ==   (VDHF_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdwu) ==   (VDWU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdwi) ==   (VDWI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vdwf) ==   (VDWF_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vddu) ==   (VDDU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vddi) ==   (VDDI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vddf) ==   (VDDF_CEQS)))  goto fail;
//  CEQSQ=BDR
    if (!TASSERT(ceqs_funcof(vqbu) ==   (VQBU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqbi) ==   (VQBI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqhu) ==   (VQHU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqhi) ==   (VQHI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqhf) ==   (VQHF_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqwu) ==   (VQWU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqwi) ==   (VQWI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqwf) ==   (VQWF_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqdu) ==   (VQDU_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqdi) ==   (VQDI_CEQS)))  goto fail;
    if (!TASSERT(ceqs_funcof(vqdf) ==   (VQDF_CEQS)))  goto fail;
//  CEQL=BDR
    if (!TASSERT(ceql_funcof( kbu) ==  (UINT8_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kbi) ==   (INT8_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( khu) == (UINT16_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( khi) ==  (INT16_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( khf) ==  (FLT16_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kwu) == (UINT32_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kwi) ==  (INT32_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kwf) ==    (FLT_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kdu) == (UINT64_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kdi) ==  (INT64_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof( kdf) ==    (DBL_CEQL)))  goto fail;
//  CEQLW=BWR
    if (!TASSERT(ceql_funcof(vwbu) ==   (VWBU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwbi) ==   (VWBI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwhu) ==   (VWHU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwhi) ==   (VWHI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwhf) ==   (VWHF_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwwu) ==   (VWWU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwwi) ==   (VWWI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vwwf) ==   (VWWF_CEQL)))  goto fail;
//  CEQLD=BDR
    if (!TASSERT(ceql_funcof(vdbu) ==   (VDBU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdbi) ==   (VDBI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdhu) ==   (VDHU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdhi) ==   (VDHI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdhf) ==   (VDHF_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdwu) ==   (VDWU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdwi) ==   (VDWI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vdwf) ==   (VDWF_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vddu) ==   (VDDU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vddi) ==   (VDDI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vddf) ==   (VDDF_CEQL)))  goto fail;
//  CEQLQ=BDR
    if (!TASSERT(ceql_funcof(vqbu) ==   (VQBU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqbi) ==   (VQBI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqhu) ==   (VQHU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqhi) ==   (VQHI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqhf) ==   (VQHF_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqwu) ==   (VQWU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqwi) ==   (VQWI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqwf) ==   (VQWF_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqdu) ==   (VQDU_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqdi) ==   (VQDI_CEQL)))  goto fail;
    if (!TASSERT(ceql_funcof(vqdf) ==   (VQDF_CEQL)))  goto fail;
#if 0 // leave ceq_
}
#endif

#if 0 // enter cne_
{
#endif
//  CNES=BDR
    if (!TASSERT(cnes_funcof( kbu) ==  (UINT8_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kbi) ==   (INT8_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( khu) == (UINT16_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( khi) ==  (INT16_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( khf) ==  (FLT16_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kwu) == (UINT32_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kwi) ==  (INT32_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kwf) ==    (FLT_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kdu) == (UINT64_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kdi) ==  (INT64_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof( kdf) ==    (DBL_CNES)))  goto fail;
//  CNESW=BWR
    if (!TASSERT(cnes_funcof(vwbu) ==   (VWBU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwbi) ==   (VWBI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwhu) ==   (VWHU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwhi) ==   (VWHI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwhf) ==   (VWHF_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwwu) ==   (VWWU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwwi) ==   (VWWI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vwwf) ==   (VWWF_CNES)))  goto fail;
//  CNESD=BDR
    if (!TASSERT(cnes_funcof(vdbu) ==   (VDBU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdbi) ==   (VDBI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdhu) ==   (VDHU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdhi) ==   (VDHI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdhf) ==   (VDHF_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdwu) ==   (VDWU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdwi) ==   (VDWI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vdwf) ==   (VDWF_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vddu) ==   (VDDU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vddi) ==   (VDDI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vddf) ==   (VDDF_CNES)))  goto fail;
//  CNESQ=BDR
    if (!TASSERT(cnes_funcof(vqbu) ==   (VQBU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqbi) ==   (VQBI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqhu) ==   (VQHU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqhi) ==   (VQHI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqhf) ==   (VQHF_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqwu) ==   (VQWU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqwi) ==   (VQWI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqwf) ==   (VQWF_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqdu) ==   (VQDU_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqdi) ==   (VQDI_CNES)))  goto fail;
    if (!TASSERT(cnes_funcof(vqdf) ==   (VQDF_CNES)))  goto fail;
//  CNEY=BDR
    if (!TASSERT(cney_funcof( kbu) ==  (UINT8_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kbi) ==   (INT8_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( khu) == (UINT16_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( khi) ==  (INT16_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( khf) ==  (FLT16_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kwu) == (UINT32_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kwi) ==  (INT32_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kwf) ==    (FLT_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kdu) == (UINT64_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kdi) ==  (INT64_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof( kdf) ==    (DBL_CNEY)))  goto fail;
//  CNEYW=BWR
    if (!TASSERT(cney_funcof(vwbu) ==   (VWBU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwbi) ==   (VWBI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwhu) ==   (VWHU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwhi) ==   (VWHI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwhf) ==   (VWHF_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwwu) ==   (VWWU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwwi) ==   (VWWI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vwwf) ==   (VWWF_CNEY)))  goto fail;
//  CNEYD=BDR
    if (!TASSERT(cney_funcof(vdbu) ==   (VDBU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdbi) ==   (VDBI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdhu) ==   (VDHU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdhi) ==   (VDHI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdhf) ==   (VDHF_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdwu) ==   (VDWU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdwi) ==   (VDWI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vdwf) ==   (VDWF_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vddu) ==   (VDDU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vddi) ==   (VDDI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vddf) ==   (VDDF_CNEY)))  goto fail;
//  CNEYQ=BDR
    if (!TASSERT(cney_funcof(vqbu) ==   (VQBU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqbi) ==   (VQBI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqhu) ==   (VQHU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqhi) ==   (VQHI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqhf) ==   (VQHF_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqwu) ==   (VQWU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqwi) ==   (VQWI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqwf) ==   (VQWF_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqdu) ==   (VQDU_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqdi) ==   (VQDI_CNEY)))  goto fail;
    if (!TASSERT(cney_funcof(vqdf) ==   (VQDF_CNEY)))  goto fail;
#if 0 // leave cne_
}
#endif

#if 0 // enter cge_
{
#endif
//  CGES=BDR
    if (!TASSERT(cges_funcof( kbu) ==  (UINT8_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kbi) ==   (INT8_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( khu) == (UINT16_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( khi) ==  (INT16_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( khf) ==  (FLT16_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kwu) == (UINT32_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kwi) ==  (INT32_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kwf) ==    (FLT_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kdu) == (UINT64_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kdi) ==  (INT64_CGES)))  goto fail;
    if (!TASSERT(cges_funcof( kdf) ==    (DBL_CGES)))  goto fail;
//  CGESW=BWR
    if (!TASSERT(cges_funcof(vwbu) ==   (VWBU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwbi) ==   (VWBI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwhu) ==   (VWHU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwhi) ==   (VWHI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwhf) ==   (VWHF_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwwu) ==   (VWWU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwwi) ==   (VWWI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vwwf) ==   (VWWF_CGES)))  goto fail;
//  CGESD=BDR
    if (!TASSERT(cges_funcof(vdbu) ==   (VDBU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdbi) ==   (VDBI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdhu) ==   (VDHU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdhi) ==   (VDHI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdhf) ==   (VDHF_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdwu) ==   (VDWU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdwi) ==   (VDWI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vdwf) ==   (VDWF_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vddu) ==   (VDDU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vddi) ==   (VDDI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vddf) ==   (VDDF_CGES)))  goto fail;
//  CGESQ=BDR
    if (!TASSERT(cges_funcof(vqbu) ==   (VQBU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqbi) ==   (VQBI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqhu) ==   (VQHU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqhi) ==   (VQHI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqhf) ==   (VQHF_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqwu) ==   (VQWU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqwi) ==   (VQWI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqwf) ==   (VQWF_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqdu) ==   (VQDU_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqdi) ==   (VQDI_CGES)))  goto fail;
    if (!TASSERT(cges_funcof(vqdf) ==   (VQDF_CGES)))  goto fail;
//  CGEY=BDR
    if (!TASSERT(cgey_funcof( kbu) ==  (UINT8_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kbi) ==   (INT8_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( khu) == (UINT16_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( khi) ==  (INT16_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( khf) ==  (FLT16_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kwu) == (UINT32_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kwi) ==  (INT32_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kwf) ==    (FLT_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kdu) == (UINT64_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kdi) ==  (INT64_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof( kdf) ==    (DBL_CGEY)))  goto fail;
//  CGEYW=BWR
    if (!TASSERT(cgey_funcof(vwbu) ==   (VWBU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwbi) ==   (VWBI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwhu) ==   (VWHU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwhi) ==   (VWHI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwhf) ==   (VWHF_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwwu) ==   (VWWU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwwi) ==   (VWWI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vwwf) ==   (VWWF_CGEY)))  goto fail;
//  CGEYD=BDR
    if (!TASSERT(cgey_funcof(vdbu) ==   (VDBU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdbi) ==   (VDBI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdhu) ==   (VDHU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdhi) ==   (VDHI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdhf) ==   (VDHF_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdwu) ==   (VDWU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdwi) ==   (VDWI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vdwf) ==   (VDWF_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vddu) ==   (VDDU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vddi) ==   (VDDI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vddf) ==   (VDDF_CGEY)))  goto fail;
//  CGEYQ=BDR
    if (!TASSERT(cgey_funcof(vqbu) ==   (VQBU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqbi) ==   (VQBI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqhu) ==   (VQHU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqhi) ==   (VQHI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqhf) ==   (VQHF_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqwu) ==   (VQWU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqwi) ==   (VQWI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqwf) ==   (VQWF_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqdu) ==   (VQDU_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqdi) ==   (VQDI_CGEY)))  goto fail;
    if (!TASSERT(cgey_funcof(vqdf) ==   (VQDF_CGEY)))  goto fail;
#if 0 // leave cge_
}
#endif

#if 0 // enter cgt_
{
#endif
//  CGTS=BDR
    if (!TASSERT(cgts_funcof( kbu) ==  (UINT8_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kbi) ==   (INT8_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( khu) == (UINT16_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( khi) ==  (INT16_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( khf) ==  (FLT16_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kwu) == (UINT32_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kwi) ==  (INT32_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kwf) ==    (FLT_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kdu) == (UINT64_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kdi) ==  (INT64_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof( kdf) ==    (DBL_CGTS)))  goto fail;
//  CGTSW=BWR
    if (!TASSERT(cgts_funcof(vwbu) ==   (VWBU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwbi) ==   (VWBI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwhu) ==   (VWHU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwhi) ==   (VWHI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwhf) ==   (VWHF_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwwu) ==   (VWWU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwwi) ==   (VWWI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vwwf) ==   (VWWF_CGTS)))  goto fail;
//  CGTSD=BDR
    if (!TASSERT(cgts_funcof(vdbu) ==   (VDBU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdbi) ==   (VDBI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdhu) ==   (VDHU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdhi) ==   (VDHI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdhf) ==   (VDHF_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdwu) ==   (VDWU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdwi) ==   (VDWI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vdwf) ==   (VDWF_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vddu) ==   (VDDU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vddi) ==   (VDDI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vddf) ==   (VDDF_CGTS)))  goto fail;
//  CGTSQ=BDR
    if (!TASSERT(cgts_funcof(vqbu) ==   (VQBU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqbi) ==   (VQBI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqhu) ==   (VQHU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqhi) ==   (VQHI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqhf) ==   (VQHF_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqwu) ==   (VQWU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqwi) ==   (VQWI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqwf) ==   (VQWF_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqdu) ==   (VQDU_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqdi) ==   (VQDI_CGTS)))  goto fail;
    if (!TASSERT(cgts_funcof(vqdf) ==   (VQDF_CGTS)))  goto fail;
//  CGTY=BDR
    if (!TASSERT(cgty_funcof( kbu) ==  (UINT8_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kbi) ==   (INT8_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( khu) == (UINT16_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( khi) ==  (INT16_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( khf) ==  (FLT16_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kwu) == (UINT32_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kwi) ==  (INT32_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kwf) ==    (FLT_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kdu) == (UINT64_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kdi) ==  (INT64_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof( kdf) ==    (DBL_CGTY)))  goto fail;
//  CGTYW=BWR
    if (!TASSERT(cgty_funcof(vwbu) ==   (VWBU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwbi) ==   (VWBI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwhu) ==   (VWHU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwhi) ==   (VWHI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwhf) ==   (VWHF_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwwu) ==   (VWWU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwwi) ==   (VWWI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vwwf) ==   (VWWF_CGTY)))  goto fail;
//  CGTYD=BDR
    if (!TASSERT(cgty_funcof(vdbu) ==   (VDBU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdbi) ==   (VDBI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdhu) ==   (VDHU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdhi) ==   (VDHI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdhf) ==   (VDHF_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdwu) ==   (VDWU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdwi) ==   (VDWI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vdwf) ==   (VDWF_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vddu) ==   (VDDU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vddi) ==   (VDDI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vddf) ==   (VDDF_CGTY)))  goto fail;
//  CGTYQ=BDR
    if (!TASSERT(cgty_funcof(vqbu) ==   (VQBU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqbi) ==   (VQBI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqhu) ==   (VQHU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqhi) ==   (VQHI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqhf) ==   (VQHF_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqwu) ==   (VQWU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqwi) ==   (VQWI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqwf) ==   (VQWF_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqdu) ==   (VQDU_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqdi) ==   (VQDI_CGTY)))  goto fail;
    if (!TASSERT(cgty_funcof(vqdf) ==   (VQDF_CGTY)))  goto fail;
#if 0 // leave cgt_
}
#endif

#if 0 // enter cle_
{
#endif
//  CLES=BDR
    if (!TASSERT(cles_funcof( kbu) ==  (UINT8_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kbi) ==   (INT8_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( khu) == (UINT16_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( khi) ==  (INT16_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( khf) ==  (FLT16_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kwu) == (UINT32_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kwi) ==  (INT32_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kwf) ==    (FLT_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kdu) == (UINT64_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kdi) ==  (INT64_CLES)))  goto fail;
    if (!TASSERT(cles_funcof( kdf) ==    (DBL_CLES)))  goto fail;
//  CLESW=BWR
    if (!TASSERT(cles_funcof(vwbu) ==   (VWBU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwbi) ==   (VWBI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwhu) ==   (VWHU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwhi) ==   (VWHI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwhf) ==   (VWHF_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwwu) ==   (VWWU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwwi) ==   (VWWI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vwwf) ==   (VWWF_CLES)))  goto fail;
//  CLESD=BDR
    if (!TASSERT(cles_funcof(vdbu) ==   (VDBU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdbi) ==   (VDBI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdhu) ==   (VDHU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdhi) ==   (VDHI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdhf) ==   (VDHF_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdwu) ==   (VDWU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdwi) ==   (VDWI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vdwf) ==   (VDWF_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vddu) ==   (VDDU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vddi) ==   (VDDI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vddf) ==   (VDDF_CLES)))  goto fail;
//  CLESQ=BDR
    if (!TASSERT(cles_funcof(vqbu) ==   (VQBU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqbi) ==   (VQBI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqhu) ==   (VQHU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqhi) ==   (VQHI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqhf) ==   (VQHF_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqwu) ==   (VQWU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqwi) ==   (VQWI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqwf) ==   (VQWF_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqdu) ==   (VQDU_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqdi) ==   (VQDI_CLES)))  goto fail;
    if (!TASSERT(cles_funcof(vqdf) ==   (VQDF_CLES)))  goto fail;
//  CLEY=BDR
    if (!TASSERT(cley_funcof( kbu) ==  (UINT8_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kbi) ==   (INT8_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( khu) == (UINT16_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( khi) ==  (INT16_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( khf) ==  (FLT16_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kwu) == (UINT32_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kwi) ==  (INT32_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kwf) ==    (FLT_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kdu) == (UINT64_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kdi) ==  (INT64_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof( kdf) ==    (DBL_CLEY)))  goto fail;
//  CLEYW=BWR
    if (!TASSERT(cley_funcof(vwbu) ==   (VWBU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwbi) ==   (VWBI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwhu) ==   (VWHU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwhi) ==   (VWHI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwhf) ==   (VWHF_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwwu) ==   (VWWU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwwi) ==   (VWWI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vwwf) ==   (VWWF_CLEY)))  goto fail;
//  CLEYD=BDR
    if (!TASSERT(cley_funcof(vdbu) ==   (VDBU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdbi) ==   (VDBI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdhu) ==   (VDHU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdhi) ==   (VDHI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdhf) ==   (VDHF_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdwu) ==   (VDWU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdwi) ==   (VDWI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vdwf) ==   (VDWF_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vddu) ==   (VDDU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vddi) ==   (VDDI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vddf) ==   (VDDF_CLEY)))  goto fail;
//  CLEYQ=BDR
    if (!TASSERT(cley_funcof(vqbu) ==   (VQBU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqbi) ==   (VQBI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqhu) ==   (VQHU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqhi) ==   (VQHI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqhf) ==   (VQHF_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqwu) ==   (VQWU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqwi) ==   (VQWI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqwf) ==   (VQWF_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqdu) ==   (VQDU_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqdi) ==   (VQDI_CLEY)))  goto fail;
    if (!TASSERT(cley_funcof(vqdf) ==   (VQDF_CLEY)))  goto fail;
#if 0 // leave cle_
}
#endif

#if 0 // enter clt_
{
#endif
//  CLTS=BDR
    if (!TASSERT(clts_funcof( kbu) ==  (UINT8_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kbi) ==   (INT8_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( khu) == (UINT16_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( khi) ==  (INT16_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( khf) ==  (FLT16_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kwu) == (UINT32_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kwi) ==  (INT32_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kwf) ==    (FLT_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kdu) == (UINT64_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kdi) ==  (INT64_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof( kdf) ==    (DBL_CLTS)))  goto fail;
//  CLTSW=BWR
    if (!TASSERT(clts_funcof(vwbu) ==   (VWBU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwbi) ==   (VWBI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwhu) ==   (VWHU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwhi) ==   (VWHI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwhf) ==   (VWHF_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwwu) ==   (VWWU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwwi) ==   (VWWI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vwwf) ==   (VWWF_CLTS)))  goto fail;
//  CLTSD=BDR
    if (!TASSERT(clts_funcof(vdbu) ==   (VDBU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdbi) ==   (VDBI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdhu) ==   (VDHU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdhi) ==   (VDHI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdhf) ==   (VDHF_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdwu) ==   (VDWU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdwi) ==   (VDWI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vdwf) ==   (VDWF_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vddu) ==   (VDDU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vddi) ==   (VDDI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vddf) ==   (VDDF_CLTS)))  goto fail;
//  CLTSQ=BDR
    if (!TASSERT(clts_funcof(vqbu) ==   (VQBU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqbi) ==   (VQBI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqhu) ==   (VQHU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqhi) ==   (VQHI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqhf) ==   (VQHF_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqwu) ==   (VQWU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqwi) ==   (VQWI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqwf) ==   (VQWF_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqdu) ==   (VQDU_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqdi) ==   (VQDI_CLTS)))  goto fail;
    if (!TASSERT(clts_funcof(vqdf) ==   (VQDF_CLTS)))  goto fail;
//  CLTY=BDR
    if (!TASSERT(clty_funcof( kbu) ==  (UINT8_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kbi) ==   (INT8_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( khu) == (UINT16_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( khi) ==  (INT16_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( khf) ==  (FLT16_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kwu) == (UINT32_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kwi) ==  (INT32_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kwf) ==    (FLT_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kdu) == (UINT64_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kdi) ==  (INT64_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof( kdf) ==    (DBL_CLTY)))  goto fail;
//  CLTYW=BWR
    if (!TASSERT(clty_funcof(vwbu) ==   (VWBU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwbi) ==   (VWBI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwhu) ==   (VWHU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwhi) ==   (VWHI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwhf) ==   (VWHF_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwwu) ==   (VWWU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwwi) ==   (VWWI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vwwf) ==   (VWWF_CLTY)))  goto fail;
//  CLTYD=BDR
    if (!TASSERT(clty_funcof(vdbu) ==   (VDBU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdbi) ==   (VDBI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdhu) ==   (VDHU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdhi) ==   (VDHI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdhf) ==   (VDHF_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdwu) ==   (VDWU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdwi) ==   (VDWI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vdwf) ==   (VDWF_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vddu) ==   (VDDU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vddi) ==   (VDDI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vddf) ==   (VDDF_CLTY)))  goto fail;
//  CLTYQ=BDR
    if (!TASSERT(clty_funcof(vqbu) ==   (VQBU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqbi) ==   (VQBI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqhu) ==   (VQHU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqhi) ==   (VQHI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqhf) ==   (VQHF_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqwu) ==   (VQWU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqwi) ==   (VQWI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqwf) ==   (VQWF_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqdu) ==   (VQDU_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqdi) ==   (VQDI_CLTY)))  goto fail;
    if (!TASSERT(clty_funcof(vqdf) ==   (VQDF_CLTY)))  goto fail;
#if 0 // leave clt_
}
#endif

#if 0 // enter cnt_
{
#endif
//  CNT1=BDZ
    if (!TASSERT(cnt1_funcof( kbu) ==  (UINT8_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( kbi) ==   (INT8_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( khu) == (UINT16_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( khi) ==  (INT16_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( kwu) == (UINT32_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( kwi) ==  (INT32_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( kdu) == (UINT64_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof( kdi) ==  (INT64_CNT1)))  goto fail;
//  CNT1W=BWZ
    if (!TASSERT(cnt1_funcof(vwbu) ==   (VWBU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vwbi) ==   (VWBI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vwhu) ==   (VWHU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vwhi) ==   (VWHI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vwwu) ==   (VWWU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vwwi) ==   (VWWI_CNT1)))  goto fail;
//  CNT1D=BDZ
    if (!TASSERT(cnt1_funcof(vdbu) ==   (VDBU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vdbi) ==   (VDBI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vdhu) ==   (VDHU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vdhi) ==   (VDHI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vdwu) ==   (VDWU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vdwi) ==   (VDWI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vddu) ==   (VDDU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vddi) ==   (VDDI_CNT1)))  goto fail;
//  CNT1Q=BDZ
    if (!TASSERT(cnt1_funcof(vqbu) ==   (VQBU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqbi) ==   (VQBI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqhu) ==   (VQHU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqhi) ==   (VQHI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqwu) ==   (VQWU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqwi) ==   (VQWI_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqdu) ==   (VQDU_CNT1)))  goto fail;
    if (!TASSERT(cnt1_funcof(vqdi) ==   (VQDI_CNT1)))  goto fail;
//  CNTS=BDZ
    if (!TASSERT(cnts_funcof( kbu) ==  (UINT8_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( kbi) ==   (INT8_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( khu) == (UINT16_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( khi) ==  (INT16_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( kwu) == (UINT32_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( kwi) ==  (INT32_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( kdu) == (UINT64_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof( kdi) ==  (INT64_CNTS)))  goto fail;
//  CNTSW=BWZ
    if (!TASSERT(cnts_funcof(vwbu) ==   (VWBU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vwbi) ==   (VWBI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vwhu) ==   (VWHU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vwhi) ==   (VWHI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vwwu) ==   (VWWU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vwwi) ==   (VWWI_CNTS)))  goto fail;
//  CNTSD=BDZ
    if (!TASSERT(cnts_funcof(vdbu) ==   (VDBU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vdbi) ==   (VDBI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vdhu) ==   (VDHU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vdhi) ==   (VDHI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vdwu) ==   (VDWU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vdwi) ==   (VDWI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vddu) ==   (VDDU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vddi) ==   (VDDI_CNTS)))  goto fail;
//  CNTSQ=BDZ
    if (!TASSERT(cnts_funcof(vqbu) ==   (VQBU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqbi) ==   (VQBI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqhu) ==   (VQHU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqhi) ==   (VQHI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqwu) ==   (VQWU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqwi) ==   (VQWI_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqdu) ==   (VQDU_CNTS)))  goto fail;
    if (!TASSERT(cnts_funcof(vqdi) ==   (VQDI_CNTS)))  goto fail;
#if 0 // leave cnt_
}
#endif

#if 0 // enter csz_
{
#endif
//  CSZL=BDZ
    if (!TASSERT(cszl_funcof( kbu) ==  (UINT8_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( kbi) ==   (INT8_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( khu) == (UINT16_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( khi) ==  (INT16_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( kwu) == (UINT32_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( kwi) ==  (INT32_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( kdu) == (UINT64_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof( kdi) ==  (INT64_CSZL)))  goto fail;
//  CSZLW=BWZ
    if (!TASSERT(cszl_funcof(vwbu) ==   (VWBU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vwbi) ==   (VWBI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vwhu) ==   (VWHU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vwhi) ==   (VWHI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vwwu) ==   (VWWU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vwwi) ==   (VWWI_CSZL)))  goto fail;
//  CSZLD=BDZ
    if (!TASSERT(cszl_funcof(vdbu) ==   (VDBU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vdbi) ==   (VDBI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vdhu) ==   (VDHU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vdhi) ==   (VDHI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vdwu) ==   (VDWU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vdwi) ==   (VDWI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vddu) ==   (VDDU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vddi) ==   (VDDI_CSZL)))  goto fail;
//  CSZLQ=BDZ
    if (!TASSERT(cszl_funcof(vqbu) ==   (VQBU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqbi) ==   (VQBI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqhu) ==   (VQHU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqhi) ==   (VQHI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqwu) ==   (VQWU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqwi) ==   (VQWI_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqdu) ==   (VQDU_CSZL)))  goto fail;
    if (!TASSERT(cszl_funcof(vqdi) ==   (VQDI_CSZL)))  goto fail;
//  CSZR=BDZ
    if (!TASSERT(cszr_funcof( kbu) ==  (UINT8_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( kbi) ==   (INT8_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( khu) == (UINT16_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( khi) ==  (INT16_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( kwu) == (UINT32_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( kwi) ==  (INT32_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( kdu) == (UINT64_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof( kdi) ==  (INT64_CSZR)))  goto fail;
//  CSZRW=BWZ
    if (!TASSERT(cszr_funcof(vwbu) ==   (VWBU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vwbi) ==   (VWBI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vwhu) ==   (VWHU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vwhi) ==   (VWHI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vwwu) ==   (VWWU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vwwi) ==   (VWWI_CSZR)))  goto fail;
//  CSZRD=BDZ
    if (!TASSERT(cszr_funcof(vdbu) ==   (VDBU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vdbi) ==   (VDBI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vdhu) ==   (VDHU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vdhi) ==   (VDHI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vdwu) ==   (VDWU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vdwi) ==   (VDWI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vddu) ==   (VDDU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vddi) ==   (VDDI_CSZR)))  goto fail;
//  CSZRQ=BDZ
    if (!TASSERT(cszr_funcof(vqbu) ==   (VQBU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqbi) ==   (VQBI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqhu) ==   (VQHU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqhi) ==   (VQHI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqwu) ==   (VQWU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqwi) ==   (VQWI_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqdu) ==   (VQDU_CSZR)))  goto fail;
    if (!TASSERT(cszr_funcof(vqdi) ==   (VQDI_CSZR)))  goto fail;
#if 0 // leave csz_
}
#endif

#if 0 // enter cvb_
{
#endif
//  CVBU=YDR
    if (!TASSERT(cvbu_funcof( kyu) ==   (BOOL_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kbu) ==  (UINT8_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kbi) ==   (INT8_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( khu) == (UINT16_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( khi) ==  (INT16_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( khf) ==  (FLT16_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kwu) == (UINT32_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kwi) ==  (INT32_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kwf) ==    (FLT_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kdu) == (UINT64_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kdi) ==  (INT64_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof( kdf) ==    (DBL_CVBU)))  goto fail;
//  CVBUW=BR
    if (!TASSERT(cvbu_funcof(vwbu) ==   (VWBU_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vwbi) ==   (VWBI_CVBU)))  goto fail;
//  CVBUD=BHR
    if (!TASSERT(cvbu_funcof(vdbu) ==   (VDBU_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vdbi) ==   (VDBI_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vdhu) ==   (VDHU_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vdhi) ==   (VDHI_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vdhf) ==   (VDHF_CVBU)))  goto fail;
//  CVBUQ=BWR
    if (!TASSERT(cvbu_funcof(vqbu) ==   (VQBU_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqbi) ==   (VQBI_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqhu) ==   (VQHU_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqhi) ==   (VQHI_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqhf) ==   (VQHF_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqwu) ==   (VQWU_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqwi) ==   (VQWI_CVBU)))  goto fail;
    if (!TASSERT(cvbu_funcof(vqwf) ==   (VQWF_CVBU)))  goto fail;
//  CVBZ=YDR
    if (!TASSERT(cvbz_funcof( kyu) ==   (BOOL_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kbu) ==  (UINT8_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kbi) ==   (INT8_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( khu) == (UINT16_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( khi) ==  (INT16_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( khf) ==  (FLT16_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kwu) == (UINT32_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kwi) ==  (INT32_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kwf) ==    (FLT_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kdu) == (UINT64_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kdi) ==  (INT64_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof( kdf) ==    (DBL_CVBZ)))  goto fail;
//  CVBZW=BR
    if (!TASSERT(cvbz_funcof(vwbu) ==   (VWBU_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vwbi) ==   (VWBI_CVBZ)))  goto fail;
//  CVBZD=BHR
    if (!TASSERT(cvbz_funcof(vdbu) ==   (VDBU_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vdbi) ==   (VDBI_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vdhu) ==   (VDHU_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vdhi) ==   (VDHI_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vdhf) ==   (VDHF_CVBZ)))  goto fail;
//  CVBZQ=BWR
    if (!TASSERT(cvbz_funcof(vqbu) ==   (VQBU_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqbi) ==   (VQBI_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqhu) ==   (VQHU_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqhi) ==   (VQHI_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqhf) ==   (VQHF_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqwu) ==   (VQWU_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqwi) ==   (VQWI_CVBZ)))  goto fail;
    if (!TASSERT(cvbz_funcof(vqwf) ==   (VQWF_CVBZ)))  goto fail;
//  CVBI=YDR
    if (!TASSERT(cvbi_funcof( kyu) ==   (BOOL_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kbu) ==  (UINT8_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kbi) ==   (INT8_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( khu) == (UINT16_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( khi) ==  (INT16_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( khf) ==  (FLT16_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kwu) == (UINT32_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kwi) ==  (INT32_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kwf) ==    (FLT_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kdu) == (UINT64_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kdi) ==  (INT64_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof( kdf) ==    (DBL_CVBI)))  goto fail;
//  CVBIW=BR
    if (!TASSERT(cvbi_funcof(vwbu) ==   (VWBU_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vwbi) ==   (VWBI_CVBI)))  goto fail;
//  CVBID=BHR
    if (!TASSERT(cvbi_funcof(vdbu) ==   (VDBU_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vdbi) ==   (VDBI_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vdhu) ==   (VDHU_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vdhi) ==   (VDHI_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vdhf) ==   (VDHF_CVBI)))  goto fail;
//  CVBIQ=BWR
    if (!TASSERT(cvbi_funcof(vqbu) ==   (VQBU_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqbi) ==   (VQBI_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqhu) ==   (VQHU_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqhi) ==   (VQHI_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqhf) ==   (VQHF_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqwu) ==   (VQWU_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqwi) ==   (VQWI_CVBI)))  goto fail;
    if (!TASSERT(cvbi_funcof(vqwf) ==   (VQWF_CVBI)))  goto fail;
//  CVBS=YDR
    if (!TASSERT(cvbs_funcof( kyu) ==   (BOOL_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kbu) ==  (UINT8_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kbi) ==   (INT8_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( khu) == (UINT16_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( khi) ==  (INT16_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( khf) ==  (FLT16_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kwu) == (UINT32_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kwi) ==  (INT32_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kwf) ==    (FLT_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kdu) == (UINT64_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kdi) ==  (INT64_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof( kdf) ==    (DBL_CVBS)))  goto fail;
//  CVBSW=BR
    if (!TASSERT(cvbs_funcof(vwbu) ==   (VWBU_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vwbi) ==   (VWBI_CVBS)))  goto fail;
//  CVBSD=BHR
    if (!TASSERT(cvbs_funcof(vdbu) ==   (VDBU_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vdbi) ==   (VDBI_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vdhu) ==   (VDHU_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vdhi) ==   (VDHI_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vdhf) ==   (VDHF_CVBS)))  goto fail;
//  CVBSQ=BWR
    if (!TASSERT(cvbs_funcof(vqbu) ==   (VQBU_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqbi) ==   (VQBI_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqhu) ==   (VQHU_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqhi) ==   (VQHI_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqhf) ==   (VQHF_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqwu) ==   (VQWU_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqwi) ==   (VQWI_CVBS)))  goto fail;
    if (!TASSERT(cvbs_funcof(vqwf) ==   (VQWF_CVBS)))  goto fail;
//  CVBC=YDR
    if (!TASSERT(cvbc_funcof( kyu) ==   (BOOL_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kbu) ==  (UINT8_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kbi) ==   (INT8_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( khu) == (UINT16_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( khi) ==  (INT16_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( khf) ==  (FLT16_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kwu) == (UINT32_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kwi) ==  (INT32_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kwf) ==    (FLT_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kdu) == (UINT64_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kdi) ==  (INT64_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof( kdf) ==    (DBL_CVBC)))  goto fail;
//  CVBCW=BR
    if (!TASSERT(cvbc_funcof(vwbu) ==   (VWBU_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vwbi) ==   (VWBI_CVBC)))  goto fail;
//  CVBCD=BHR
    if (!TASSERT(cvbc_funcof(vdbu) ==   (VDBU_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vdbi) ==   (VDBI_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vdhu) ==   (VDHU_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vdhi) ==   (VDHI_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vdhf) ==   (VDHF_CVBC)))  goto fail;
//  CVBCQ=BWR
    if (!TASSERT(cvbc_funcof(vqbu) ==   (VQBU_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqbi) ==   (VQBI_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqhu) ==   (VQHU_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqhi) ==   (VQHI_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqhf) ==   (VQHF_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqwu) ==   (VQWU_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqwi) ==   (VQWI_CVBC)))  goto fail;
    if (!TASSERT(cvbc_funcof(vqwf) ==   (VQWF_CVBC)))  goto fail;
#if 0 // leave cvb_
}
#endif

#if 0 // enter cvh_
{
#endif
//  CVHU=YDR
    if (!TASSERT(cvhu_funcof( kyu) ==   (BOOL_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kbu) ==  (UINT8_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kbi) ==   (INT8_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( khu) == (UINT16_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( khi) ==  (INT16_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( khf) ==  (FLT16_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kwu) == (UINT32_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kwi) ==  (INT32_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kwf) ==    (FLT_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kdu) == (UINT64_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kdi) ==  (INT64_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof( kdf) ==    (DBL_CVHU)))  goto fail;
//  CVHUW=BHR
    if (!TASSERT(cvhu_funcof(vwbu) ==   (VWBU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vwbi) ==   (VWBI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vwhu) ==   (VWHU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vwhi) ==   (VWHI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vwhf) ==   (VWHF_CVHU)))  goto fail;
//  CVHUD=BWR
    if (!TASSERT(cvhu_funcof(vdbu) ==   (VDBU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdbi) ==   (VDBI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdhu) ==   (VDHU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdhi) ==   (VDHI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdhf) ==   (VDHF_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdwu) ==   (VDWU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdwi) ==   (VDWI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vdwf) ==   (VDWF_CVHU)))  goto fail;
//  CVHUQ=HDR
    if (!TASSERT(cvhu_funcof(vqhu) ==   (VQHU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqhi) ==   (VQHI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqhf) ==   (VQHF_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqwu) ==   (VQWU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqwi) ==   (VQWI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqwf) ==   (VQWF_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqdu) ==   (VQDU_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqdi) ==   (VQDI_CVHU)))  goto fail;
    if (!TASSERT(cvhu_funcof(vqdf) ==   (VQDF_CVHU)))  goto fail;
//  CVHZ=YDR
    if (!TASSERT(cvhz_funcof( kyu) ==   (BOOL_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kbu) ==  (UINT8_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kbi) ==   (INT8_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( khu) == (UINT16_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( khi) ==  (INT16_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( khf) ==  (FLT16_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kwu) == (UINT32_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kwi) ==  (INT32_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kwf) ==    (FLT_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kdu) == (UINT64_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kdi) ==  (INT64_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof( kdf) ==    (DBL_CVHZ)))  goto fail;
//  CVHZW=BHR
    if (!TASSERT(cvhz_funcof(vwbu) ==   (VWBU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vwbi) ==   (VWBI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vwhu) ==   (VWHU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vwhi) ==   (VWHI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vwhf) ==   (VWHF_CVHZ)))  goto fail;
//  CVHZD=BWR
    if (!TASSERT(cvhz_funcof(vdbu) ==   (VDBU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdbi) ==   (VDBI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdhu) ==   (VDHU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdhi) ==   (VDHI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdhf) ==   (VDHF_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdwu) ==   (VDWU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdwi) ==   (VDWI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vdwf) ==   (VDWF_CVHZ)))  goto fail;
//  CVHZQ=HDR
    if (!TASSERT(cvhz_funcof(vqhu) ==   (VQHU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqhi) ==   (VQHI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqhf) ==   (VQHF_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqwu) ==   (VQWU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqwi) ==   (VQWI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqwf) ==   (VQWF_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqdu) ==   (VQDU_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqdi) ==   (VQDI_CVHZ)))  goto fail;
    if (!TASSERT(cvhz_funcof(vqdf) ==   (VQDF_CVHZ)))  goto fail;
//  CVHI=YDR
    if (!TASSERT(cvhi_funcof( kyu) ==   (BOOL_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kbu) ==  (UINT8_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kbi) ==   (INT8_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( khu) == (UINT16_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( khi) ==  (INT16_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( khf) ==  (FLT16_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kwu) == (UINT32_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kwi) ==  (INT32_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kwf) ==    (FLT_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kdu) == (UINT64_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kdi) ==  (INT64_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof( kdf) ==    (DBL_CVHI)))  goto fail;
//  CVHIW=BHR
    if (!TASSERT(cvhi_funcof(vwbu) ==   (VWBU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vwbi) ==   (VWBI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vwhu) ==   (VWHU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vwhi) ==   (VWHI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vwhf) ==   (VWHF_CVHI)))  goto fail;
//  CVHID=BWR
    if (!TASSERT(cvhi_funcof(vdbu) ==   (VDBU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdbi) ==   (VDBI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdhu) ==   (VDHU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdhi) ==   (VDHI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdhf) ==   (VDHF_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdwu) ==   (VDWU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdwi) ==   (VDWI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vdwf) ==   (VDWF_CVHI)))  goto fail;
//  CVHIQ=HDR
    if (!TASSERT(cvhi_funcof(vqhu) ==   (VQHU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqhi) ==   (VQHI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqhf) ==   (VQHF_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqwu) ==   (VQWU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqwi) ==   (VQWI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqwf) ==   (VQWF_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqdu) ==   (VQDU_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqdi) ==   (VQDI_CVHI)))  goto fail;
    if (!TASSERT(cvhi_funcof(vqdf) ==   (VQDF_CVHI)))  goto fail;
//  CVHS=YDR
    if (!TASSERT(cvhs_funcof( kyu) ==   (BOOL_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kbu) ==  (UINT8_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kbi) ==   (INT8_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( khu) == (UINT16_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( khi) ==  (INT16_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( khf) ==  (FLT16_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kwu) == (UINT32_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kwi) ==  (INT32_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kwf) ==    (FLT_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kdu) == (UINT64_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kdi) ==  (INT64_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof( kdf) ==    (DBL_CVHS)))  goto fail;
//  CVHSW=BHR
    if (!TASSERT(cvhs_funcof(vwbu) ==   (VWBU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vwbi) ==   (VWBI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vwhu) ==   (VWHU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vwhi) ==   (VWHI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vwhf) ==   (VWHF_CVHS)))  goto fail;
//  CVHSD=BWR
    if (!TASSERT(cvhs_funcof(vdbu) ==   (VDBU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdbi) ==   (VDBI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdhu) ==   (VDHU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdhi) ==   (VDHI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdhf) ==   (VDHF_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdwu) ==   (VDWU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdwi) ==   (VDWI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vdwf) ==   (VDWF_CVHS)))  goto fail;
//  CVHSQ=HDR
    if (!TASSERT(cvhs_funcof(vqhu) ==   (VQHU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqhi) ==   (VQHI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqhf) ==   (VQHF_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqwu) ==   (VQWU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqwi) ==   (VQWI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqwf) ==   (VQWF_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqdu) ==   (VQDU_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqdi) ==   (VQDI_CVHS)))  goto fail;
    if (!TASSERT(cvhs_funcof(vqdf) ==   (VQDF_CVHS)))  goto fail;
//  CVHF=YDR
    if (!TASSERT(cvhf_funcof( kyu) ==   (BOOL_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kbu) ==  (UINT8_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kbi) ==   (INT8_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( khu) == (UINT16_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( khi) ==  (INT16_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( khf) ==  (FLT16_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kwu) == (UINT32_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kwi) ==  (INT32_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kwf) ==    (FLT_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kdu) == (UINT64_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kdi) ==  (INT64_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof( kdf) ==    (DBL_CVHF)))  goto fail;
//  CVHFW=BHR
    if (!TASSERT(cvhf_funcof(vwbu) ==   (VWBU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vwbi) ==   (VWBI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vwhu) ==   (VWHU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vwhi) ==   (VWHI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vwhf) ==   (VWHF_CVHF)))  goto fail;
//  CVHFD=BWR
    if (!TASSERT(cvhf_funcof(vdbu) ==   (VDBU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdbi) ==   (VDBI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdhu) ==   (VDHU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdhi) ==   (VDHI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdhf) ==   (VDHF_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdwu) ==   (VDWU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdwi) ==   (VDWI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vdwf) ==   (VDWF_CVHF)))  goto fail;
//  CVHFQ=HDR
    if (!TASSERT(cvhf_funcof(vqhu) ==   (VQHU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqhi) ==   (VQHI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqhf) ==   (VQHF_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqwu) ==   (VQWU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqwi) ==   (VQWI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqwf) ==   (VQWF_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqdu) ==   (VQDU_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqdi) ==   (VQDI_CVHF)))  goto fail;
    if (!TASSERT(cvhf_funcof(vqdf) ==   (VQDF_CVHF)))  goto fail;
#if 0 // leave cvh_
}
#endif

#if 0 // enter cvw_
{
#endif
//  CVWU=BDR
    if (!TASSERT(cvwu_funcof( kbu) ==  (UINT8_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kbi) ==   (INT8_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( khu) == (UINT16_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( khi) ==  (INT16_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( khf) ==  (FLT16_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kwu) == (UINT32_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kwi) ==  (INT32_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kwf) ==    (FLT_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kdu) == (UINT64_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kdi) ==  (INT64_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof( kdf) ==    (DBL_CVWU)))  goto fail;
//  CVWUW=BWR
    if (!TASSERT(cvwu_funcof(vwbu) ==   (VWBU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwbi) ==   (VWBI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwhu) ==   (VWHU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwhi) ==   (VWHI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwhf) ==   (VWHF_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwwu) ==   (VWWU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwwi) ==   (VWWI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vwwf) ==   (VWWF_CVWU)))  goto fail;
//  CVWUD=HDR
    if (!TASSERT(cvwu_funcof(vdhu) ==   (VDHU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vdhi) ==   (VDHI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vdhf) ==   (VDHF_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vdwu) ==   (VDWU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vdwi) ==   (VDWI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vdwf) ==   (VDWF_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vddu) ==   (VDDU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vddi) ==   (VDDI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vddf) ==   (VDDF_CVWU)))  goto fail;
//  CVWUQ=WDR
    if (!TASSERT(cvwu_funcof(vqwu) ==   (VQWU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vqwi) ==   (VQWI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vqwf) ==   (VQWF_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vqdu) ==   (VQDU_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vqdi) ==   (VQDI_CVWU)))  goto fail;
    if (!TASSERT(cvwu_funcof(vqdf) ==   (VQDF_CVWU)))  goto fail;
//  CVWZ=BDR
    if (!TASSERT(cvwz_funcof( kbu) ==  (UINT8_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kbi) ==   (INT8_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( khu) == (UINT16_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( khi) ==  (INT16_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( khf) ==  (FLT16_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kwu) == (UINT32_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kwi) ==  (INT32_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kwf) ==    (FLT_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kdu) == (UINT64_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kdi) ==  (INT64_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof( kdf) ==    (DBL_CVWZ)))  goto fail;
//  CVWZW=BWR
    if (!TASSERT(cvwz_funcof(vwbu) ==   (VWBU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwbi) ==   (VWBI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwhu) ==   (VWHU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwhi) ==   (VWHI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwhf) ==   (VWHF_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwwu) ==   (VWWU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwwi) ==   (VWWI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vwwf) ==   (VWWF_CVWZ)))  goto fail;
//  CVWZD=HDR
    if (!TASSERT(cvwz_funcof(vdhu) ==   (VDHU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vdhi) ==   (VDHI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vdhf) ==   (VDHF_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vdwu) ==   (VDWU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vdwi) ==   (VDWI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vdwf) ==   (VDWF_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vddu) ==   (VDDU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vddi) ==   (VDDI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vddf) ==   (VDDF_CVWZ)))  goto fail;
//  CVWZQ=WDR
    if (!TASSERT(cvwz_funcof(vqwu) ==   (VQWU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vqwi) ==   (VQWI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vqwf) ==   (VQWF_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vqdu) ==   (VQDU_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vqdi) ==   (VQDI_CVWZ)))  goto fail;
    if (!TASSERT(cvwz_funcof(vqdf) ==   (VQDF_CVWZ)))  goto fail;
//  CVWI=BDR
    if (!TASSERT(cvwi_funcof( kbu) ==  (UINT8_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kbi) ==   (INT8_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( khu) == (UINT16_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( khi) ==  (INT16_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( khf) ==  (FLT16_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kwu) == (UINT32_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kwi) ==  (INT32_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kwf) ==    (FLT_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kdu) == (UINT64_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kdi) ==  (INT64_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof( kdf) ==    (DBL_CVWI)))  goto fail;
//  CVWIW=BWR
    if (!TASSERT(cvwi_funcof(vwbu) ==   (VWBU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwbi) ==   (VWBI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwhu) ==   (VWHU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwhi) ==   (VWHI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwhf) ==   (VWHF_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwwu) ==   (VWWU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwwi) ==   (VWWI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vwwf) ==   (VWWF_CVWI)))  goto fail;
//  CVWID=HDR
    if (!TASSERT(cvwi_funcof(vdhu) ==   (VDHU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vdhi) ==   (VDHI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vdhf) ==   (VDHF_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vdwu) ==   (VDWU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vdwi) ==   (VDWI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vdwf) ==   (VDWF_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vddu) ==   (VDDU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vddi) ==   (VDDI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vddf) ==   (VDDF_CVWI)))  goto fail;
//  CVWIQ=WDR
    if (!TASSERT(cvwi_funcof(vqwu) ==   (VQWU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vqwi) ==   (VQWI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vqwf) ==   (VQWF_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vqdu) ==   (VQDU_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vqdi) ==   (VQDI_CVWI)))  goto fail;
    if (!TASSERT(cvwi_funcof(vqdf) ==   (VQDF_CVWI)))  goto fail;
//  CVWS=BDR
    if (!TASSERT(cvws_funcof( kbu) ==  (UINT8_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kbi) ==   (INT8_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( khu) == (UINT16_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( khi) ==  (INT16_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( khf) ==  (FLT16_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kwu) == (UINT32_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kwi) ==  (INT32_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kwf) ==    (FLT_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kdu) == (UINT64_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kdi) ==  (INT64_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof( kdf) ==    (DBL_CVWS)))  goto fail;
//  CVWSW=BWR
    if (!TASSERT(cvws_funcof(vwbu) ==   (VWBU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwbi) ==   (VWBI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwhu) ==   (VWHU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwhi) ==   (VWHI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwhf) ==   (VWHF_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwwu) ==   (VWWU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwwi) ==   (VWWI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vwwf) ==   (VWWF_CVWS)))  goto fail;
//  CVWSD=HDR
    if (!TASSERT(cvws_funcof(vdhu) ==   (VDHU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vdhi) ==   (VDHI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vdhf) ==   (VDHF_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vdwu) ==   (VDWU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vdwi) ==   (VDWI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vdwf) ==   (VDWF_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vddu) ==   (VDDU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vddi) ==   (VDDI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vddf) ==   (VDDF_CVWS)))  goto fail;
//  CVWSQ=WDR
    if (!TASSERT(cvws_funcof(vqwu) ==   (VQWU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vqwi) ==   (VQWI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vqwf) ==   (VQWF_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vqdu) ==   (VQDU_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vqdi) ==   (VQDI_CVWS)))  goto fail;
    if (!TASSERT(cvws_funcof(vqdf) ==   (VQDF_CVWS)))  goto fail;
//  CVWF=BDR
    if (!TASSERT(cvwf_funcof( kbu) ==  (UINT8_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kbi) ==   (INT8_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( khu) == (UINT16_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( khi) ==  (INT16_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( khf) ==  (FLT16_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kwu) == (UINT32_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kwi) ==  (INT32_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kwf) ==    (FLT_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kdu) == (UINT64_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kdi) ==  (INT64_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof( kdf) ==    (DBL_CVWF)))  goto fail;
//  CVWFW=BWR
    if (!TASSERT(cvwf_funcof(vwbu) ==   (VWBU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwbi) ==   (VWBI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwhu) ==   (VWHU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwhi) ==   (VWHI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwhf) ==   (VWHF_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwwu) ==   (VWWU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwwi) ==   (VWWI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vwwf) ==   (VWWF_CVWF)))  goto fail;
//  CVWFD=HDR
    if (!TASSERT(cvwf_funcof(vdhu) ==   (VDHU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vdhi) ==   (VDHI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vdhf) ==   (VDHF_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vdwu) ==   (VDWU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vdwi) ==   (VDWI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vdwf) ==   (VDWF_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vddu) ==   (VDDU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vddi) ==   (VDDI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vddf) ==   (VDDF_CVWF)))  goto fail;
//  CVWFQ=WDR
    if (!TASSERT(cvwf_funcof(vqwu) ==   (VQWU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vqwi) ==   (VQWI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vqwf) ==   (VQWF_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vqdu) ==   (VQDU_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vqdi) ==   (VQDI_CVWF)))  goto fail;
    if (!TASSERT(cvwf_funcof(vqdf) ==   (VQDF_CVWF)))  goto fail;
#if 0 // leave cvw_
}
#endif

#if 0 // enter cvd_
{
#endif
//  CVDU=YDR
    if (!TASSERT(cvdu_funcof( kyu) ==   (BOOL_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kbu) ==  (UINT8_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kbi) ==   (INT8_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( khu) == (UINT16_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( khi) ==  (INT16_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( khf) ==  (FLT16_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kwu) == (UINT32_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kwi) ==  (INT32_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kwf) ==    (FLT_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kdu) == (UINT64_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kdi) ==  (INT64_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof( kdf) ==    (DBL_CVDU)))  goto fail;
//  CVDUW=HWR
    if (!TASSERT(cvdu_funcof(vwhu) ==   (VWHU_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vwhi) ==   (VWHI_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vwhf) ==   (VWHF_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vwwu) ==   (VWWU_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vwwi) ==   (VWWI_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vwwf) ==   (VWWF_CVDU)))  goto fail;
//  CVDUD=WDR
    if (!TASSERT(cvdu_funcof(vdwu) ==   (VDWU_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vdwi) ==   (VDWI_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vdwf) ==   (VDWF_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vddu) ==   (VDDU_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vddi) ==   (VDDI_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vddf) ==   (VDDF_CVDU)))  goto fail;
//  CVDUQ=DR
    if (!TASSERT(cvdu_funcof(vqdu) ==   (VQDU_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vqdi) ==   (VQDI_CVDU)))  goto fail;
    if (!TASSERT(cvdu_funcof(vqdf) ==   (VQDF_CVDU)))  goto fail;
//  CVDZ=YDR
    if (!TASSERT(cvdz_funcof( kyu) ==   (BOOL_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kbu) ==  (UINT8_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kbi) ==   (INT8_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( khu) == (UINT16_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( khi) ==  (INT16_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( khf) ==  (FLT16_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kwu) == (UINT32_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kwi) ==  (INT32_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kwf) ==    (FLT_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kdu) == (UINT64_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kdi) ==  (INT64_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof( kdf) ==    (DBL_CVDZ)))  goto fail;
//  CVDZW=HWR
    if (!TASSERT(cvdz_funcof(vwhu) ==   (VWHU_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vwhi) ==   (VWHI_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vwhf) ==   (VWHF_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vwwu) ==   (VWWU_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vwwi) ==   (VWWI_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vwwf) ==   (VWWF_CVDZ)))  goto fail;
//  CVDZD=WDR
    if (!TASSERT(cvdz_funcof(vdwu) ==   (VDWU_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vdwi) ==   (VDWI_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vdwf) ==   (VDWF_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vddu) ==   (VDDU_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vddi) ==   (VDDI_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vddf) ==   (VDDF_CVDZ)))  goto fail;
//  CVDZQ=DR
    if (!TASSERT(cvdz_funcof(vqdu) ==   (VQDU_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vqdi) ==   (VQDI_CVDZ)))  goto fail;
    if (!TASSERT(cvdz_funcof(vqdf) ==   (VQDF_CVDZ)))  goto fail;
//  CVDI=YDR
    if (!TASSERT(cvdi_funcof( kyu) ==   (BOOL_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kbu) ==  (UINT8_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kbi) ==   (INT8_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( khu) == (UINT16_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( khi) ==  (INT16_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( khf) ==  (FLT16_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kwu) == (UINT32_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kwi) ==  (INT32_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kwf) ==    (FLT_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kdu) == (UINT64_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kdi) ==  (INT64_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof( kdf) ==    (DBL_CVDI)))  goto fail;
//  CVDIW=HWR
    if (!TASSERT(cvdi_funcof(vwhu) ==   (VWHU_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vwhi) ==   (VWHI_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vwhf) ==   (VWHF_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vwwu) ==   (VWWU_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vwwi) ==   (VWWI_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vwwf) ==   (VWWF_CVDI)))  goto fail;
//  CVDID=WDR
    if (!TASSERT(cvdi_funcof(vdwu) ==   (VDWU_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vdwi) ==   (VDWI_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vdwf) ==   (VDWF_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vddu) ==   (VDDU_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vddi) ==   (VDDI_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vddf) ==   (VDDF_CVDI)))  goto fail;
//  CVDIQ=DR
    if (!TASSERT(cvdi_funcof(vqdu) ==   (VQDU_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vqdi) ==   (VQDI_CVDI)))  goto fail;
    if (!TASSERT(cvdi_funcof(vqdf) ==   (VQDF_CVDI)))  goto fail;
//  CVDS=YDR
    if (!TASSERT(cvds_funcof( kyu) ==   (BOOL_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kbu) ==  (UINT8_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kbi) ==   (INT8_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( khu) == (UINT16_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( khi) ==  (INT16_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( khf) ==  (FLT16_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kwu) == (UINT32_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kwi) ==  (INT32_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kwf) ==    (FLT_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kdu) == (UINT64_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kdi) ==  (INT64_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof( kdf) ==    (DBL_CVDS)))  goto fail;
//  CVDSW=HWR
    if (!TASSERT(cvds_funcof(vwhu) ==   (VWHU_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vwhi) ==   (VWHI_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vwhf) ==   (VWHF_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vwwu) ==   (VWWU_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vwwi) ==   (VWWI_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vwwf) ==   (VWWF_CVDS)))  goto fail;
//  CVDSD=WDR
    if (!TASSERT(cvds_funcof(vdwu) ==   (VDWU_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vdwi) ==   (VDWI_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vdwf) ==   (VDWF_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vddu) ==   (VDDU_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vddi) ==   (VDDI_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vddf) ==   (VDDF_CVDS)))  goto fail;
//  CVDSQ=DR
    if (!TASSERT(cvds_funcof(vqdu) ==   (VQDU_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vqdi) ==   (VQDI_CVDS)))  goto fail;
    if (!TASSERT(cvds_funcof(vqdf) ==   (VQDF_CVDS)))  goto fail;
//  CVDF=YDR
    if (!TASSERT(cvdf_funcof( kyu) ==   (BOOL_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kbu) ==  (UINT8_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kbi) ==   (INT8_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( khu) == (UINT16_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( khi) ==  (INT16_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( khf) ==  (FLT16_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kwu) == (UINT32_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kwi) ==  (INT32_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kwf) ==    (FLT_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kdu) == (UINT64_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kdi) ==  (INT64_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof( kdf) ==    (DBL_CVDF)))  goto fail;
//  CVDFW=HWR
    if (!TASSERT(cvdf_funcof(vwhu) ==   (VWHU_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vwhi) ==   (VWHI_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vwhf) ==   (VWHF_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vwwu) ==   (VWWU_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vwwi) ==   (VWWI_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vwwf) ==   (VWWF_CVDF)))  goto fail;
//  CVDFD=WDR
    if (!TASSERT(cvdf_funcof(vdwu) ==   (VDWU_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vdwi) ==   (VDWI_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vdwf) ==   (VDWF_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vddu) ==   (VDDU_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vddi) ==   (VDDI_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vddf) ==   (VDDF_CVDF)))  goto fail;
//  CVDFQ=DR
    if (!TASSERT(cvdf_funcof(vqdu) ==   (VQDU_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vqdi) ==   (VQDI_CVDF)))  goto fail;
    if (!TASSERT(cvdf_funcof(vqdf) ==   (VQDF_CVDF)))  goto fail;
#if 0 // leave cvd_
}
#endif

#if 0 // enter dcr_
{
#endif
//  DCR1A=YDZ
    if (!TASSERT(dcr1_funcof(&kyu) ==   (BOOL_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&kbu) ==  (UINT8_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&kbi) ==   (INT8_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&khu) == (UINT16_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&khi) ==  (INT16_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&kwu) == (UINT32_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&kwi) ==  (INT32_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&kdu) == (UINT64_DCR1A))) goto fail;
    if (!TASSERT(dcr1_funcof(&kdi) ==  (INT64_DCR1A))) goto fail;
//  DCRAA=YDZ
    if (!TASSERT(dcra_funcof(&kyu) ==   (BOOL_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&kbu) ==  (UINT8_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&kbi) ==   (INT8_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&khu) == (UINT16_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&khi) ==  (INT16_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&kwu) == (UINT32_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&kwi) ==  (INT32_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&kdu) == (UINT64_DCRAA))) goto fail;
    if (!TASSERT(dcra_funcof(&kdi) ==  (INT64_DCRAA))) goto fail;
//  DCREA=YDZ
    if (!TASSERT(dcre_funcof(&kyu) ==   (BOOL_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&kbu) ==  (UINT8_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&kbi) ==   (INT8_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&khu) == (UINT16_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&khi) ==  (INT16_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&kwu) == (UINT32_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&kwi) ==  (INT32_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&kdu) == (UINT64_DCREA))) goto fail;
    if (!TASSERT(dcre_funcof(&kdi) ==  (INT64_DCREA))) goto fail;
//  DCRTA=YDZ
    if (!TASSERT(dcrt_funcof(&kyu) ==   (BOOL_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&kbu) ==  (UINT8_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&kbi) ==   (INT8_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&khu) == (UINT16_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&khi) ==  (INT16_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&kwu) == (UINT32_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&kwi) ==  (INT32_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&kdu) == (UINT64_DCRTA))) goto fail;
    if (!TASSERT(dcrt_funcof(&kdi) ==  (INT64_DCRTA))) goto fail;
//  DCRL=YDZ
    if (!TASSERT(dcrl_funcof( kyu) ==   (BOOL_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( kbu) ==  (UINT8_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( kbi) ==   (INT8_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( khu) == (UINT16_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( khi) ==  (INT16_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( kwu) == (UINT32_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( kwi) ==  (INT32_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( kdu) == (UINT64_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof( kdi) ==  (INT64_DCRL)))  goto fail;
//  DCRLW=YWZ
    if (!TASSERT(dcrl_funcof(vwyu) ==   (VWYU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vwbu) ==   (VWBU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vwbi) ==   (VWBI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vwhu) ==   (VWHU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vwhi) ==   (VWHI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vwwu) ==   (VWWU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vwwi) ==   (VWWI_DCRL)))  goto fail;
//  DCRLD=YDZ
    if (!TASSERT(dcrl_funcof(vdyu) ==   (VDYU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vdbu) ==   (VDBU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vdbi) ==   (VDBI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vdhu) ==   (VDHU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vdhi) ==   (VDHI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vdwu) ==   (VDWU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vdwi) ==   (VDWI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vddu) ==   (VDDU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vddi) ==   (VDDI_DCRL)))  goto fail;
//  DCRLQ=YDZ
    if (!TASSERT(dcrl_funcof(vqyu) ==   (VQYU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqbu) ==   (VQBU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqbi) ==   (VQBI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqhu) ==   (VQHU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqhi) ==   (VQHI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqwu) ==   (VQWU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqwi) ==   (VQWI_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqdu) ==   (VQDU_DCRL)))  goto fail;
    if (!TASSERT(dcrl_funcof(vqdi) ==   (VQDI_DCRL)))  goto fail;
#if 0 // leave dcr_
}
#endif

#if 0 // enter dif_
{
#endif
//  DIFU=YDZ
    if (!TASSERT(difu_funcof( kyu) ==   (BOOL_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( kbu) ==  (UINT8_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( kbi) ==   (INT8_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( khu) == (UINT16_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( khi) ==  (INT16_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( kwu) == (UINT32_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( kwi) ==  (INT32_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( kdu) == (UINT64_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof( kdi) ==  (INT64_DIFU)))  goto fail;
//  DIFUW=YWZ
    if (!TASSERT(difu_funcof(vwyu) ==   (VWYU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vwbu) ==   (VWBU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vwbi) ==   (VWBI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vwhu) ==   (VWHU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vwhi) ==   (VWHI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vwwu) ==   (VWWU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vwwi) ==   (VWWI_DIFU)))  goto fail;
//  DIFUD=YDZ
    if (!TASSERT(difu_funcof(vdyu) ==   (VDYU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vdbu) ==   (VDBU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vdbi) ==   (VDBI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vdhu) ==   (VDHU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vdhi) ==   (VDHI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vdwu) ==   (VDWU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vdwi) ==   (VDWI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vddu) ==   (VDDU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vddi) ==   (VDDI_DIFU)))  goto fail;
//  DIFUQ=YDZ
    if (!TASSERT(difu_funcof(vqyu) ==   (VQYU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqbu) ==   (VQBU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqbi) ==   (VQBI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqhu) ==   (VQHU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqhi) ==   (VQHI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqwu) ==   (VQWU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqwi) ==   (VQWI_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqdu) ==   (VQDU_DIFU)))  goto fail;
    if (!TASSERT(difu_funcof(vqdi) ==   (VQDI_DIFU)))  goto fail;
#if 0 // leave dif_
}
#endif

#if 0 // enter div_
{
#endif
//  DIVN=YDZ
    if (!TASSERT(divn_funcof( kyu) ==   (BOOL_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( kbu) ==  (UINT8_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( kbi) ==   (INT8_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( khu) == (UINT16_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( khi) ==  (INT16_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( kwu) == (UINT32_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( kwi) ==  (INT32_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( kdu) == (UINT64_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof( kdi) ==  (INT64_DIVN)))  goto fail;
//  DIVNW=YWZ
    if (!TASSERT(divn_funcof(vwyu) ==   (VWYU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vwbu) ==   (VWBU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vwbi) ==   (VWBI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vwhu) ==   (VWHU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vwhi) ==   (VWHI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vwwu) ==   (VWWU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vwwi) ==   (VWWI_DIVN)))  goto fail;
//  DIVND=YDZ
    if (!TASSERT(divn_funcof(vdyu) ==   (VDYU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vdbu) ==   (VDBU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vdbi) ==   (VDBI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vdhu) ==   (VDHU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vdhi) ==   (VDHI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vdwu) ==   (VDWU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vdwi) ==   (VDWI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vddu) ==   (VDDU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vddi) ==   (VDDI_DIVN)))  goto fail;
//  DIVNQ=YDZ
    if (!TASSERT(divn_funcof(vqyu) ==   (VQYU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqbu) ==   (VQBU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqbi) ==   (VQBI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqhu) ==   (VQHU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqhi) ==   (VQHI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqwu) ==   (VQWU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqwi) ==   (VQWI_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqdu) ==   (VQDU_DIVN)))  goto fail;
    if (!TASSERT(divn_funcof(vqdi) ==   (VQDI_DIVN)))  goto fail;
//  DIV2=HDZ
    if (!TASSERT(div2_funcof( khu) == (UINT16_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof( khi) ==  (INT16_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof( kwu) == (UINT32_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof( kwi) ==  (INT32_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof( kdu) == (UINT64_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof( kdi) ==  (INT64_DIV2)))  goto fail;
//  DIV2W=NONE
//  DIV2D=HDZ
    if (!TASSERT(div2_funcof(vdhu) ==   (VDHU_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vdhi) ==   (VDHI_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vdwu) ==   (VDWU_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vdwi) ==   (VDWI_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vddu) ==   (VDDU_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vddi) ==   (VDDI_DIV2)))  goto fail;
//  DIV2Q=HDZ
    if (!TASSERT(div2_funcof(vqhu) ==   (VQHU_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vqhi) ==   (VQHI_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vqwu) ==   (VQWU_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vqwi) ==   (VQWI_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vqdu) ==   (VQDU_DIV2)))  goto fail;
    if (!TASSERT(div2_funcof(vqdi) ==   (VQDI_DIV2)))  goto fail;
//  DIVH=YDR
    if (!TASSERT(divh_funcof( kyu) ==   (BOOL_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kbu) ==  (UINT8_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kbi) ==   (INT8_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( khu) == (UINT16_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( khi) ==  (INT16_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( khf) ==  (FLT16_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kwu) == (UINT32_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kwi) ==  (INT32_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kwf) ==    (FLT_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kdu) == (UINT64_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kdi) ==  (INT64_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof( kdf) ==    (DBL_DIVH)))  goto fail;
//  DIVHW=BHR
    if (!TASSERT(divh_funcof(vwbu) ==   (VWBU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vwbi) ==   (VWBI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vwhu) ==   (VWHU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vwhi) ==   (VWHI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vwhf) ==   (VWHF_DIVH)))  goto fail;
//  DIVHD=BWR
    if (!TASSERT(divh_funcof(vdbu) ==   (VDBU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdbi) ==   (VDBI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdhu) ==   (VDHU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdhi) ==   (VDHI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdhf) ==   (VDHF_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdwu) ==   (VDWU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdwi) ==   (VDWI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vdwf) ==   (VDWF_DIVH)))  goto fail;
//  DIVHQ=HDR
    if (!TASSERT(divh_funcof(vqhu) ==   (VQHU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqhi) ==   (VQHI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqhf) ==   (VQHF_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqwu) ==   (VQWU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqwi) ==   (VQWI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqwf) ==   (VQWF_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqdu) ==   (VQDU_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqdi) ==   (VQDI_DIVH)))  goto fail;
    if (!TASSERT(divh_funcof(vqdf) ==   (VQDF_DIVH)))  goto fail;
//  DIVW=YDR
    if (!TASSERT(divw_funcof( kyu) ==   (BOOL_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kbu) ==  (UINT8_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kbi) ==   (INT8_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( khu) == (UINT16_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( khi) ==  (INT16_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( khf) ==  (FLT16_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kwu) == (UINT32_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kwi) ==  (INT32_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kwf) ==    (FLT_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kdu) == (UINT64_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kdi) ==  (INT64_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof( kdf) ==    (DBL_DIVW)))  goto fail;
//  DIVWW=BWR
    if (!TASSERT(divw_funcof(vwbu) ==   (VWBU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwbi) ==   (VWBI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwhu) ==   (VWHU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwhi) ==   (VWHI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwhf) ==   (VWHF_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwwu) ==   (VWWU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwwi) ==   (VWWI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vwwf) ==   (VWWF_DIVW)))  goto fail;
//  DIVWD=HDR
    if (!TASSERT(divw_funcof(vdhu) ==   (VDHU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vdhi) ==   (VDHI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vdhf) ==   (VDHF_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vdwu) ==   (VDWU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vdwi) ==   (VDWI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vdwf) ==   (VDWF_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vddu) ==   (VDDU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vddi) ==   (VDDI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vddf) ==   (VDDF_DIVW)))  goto fail;
//  DIVWQ=WDR
    if (!TASSERT(divw_funcof(vqwu) ==   (VQWU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vqwi) ==   (VQWI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vqwf) ==   (VQWF_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vqdu) ==   (VQDU_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vqdi) ==   (VQDI_DIVW)))  goto fail;
    if (!TASSERT(divw_funcof(vqdf) ==   (VQDF_DIVW)))  goto fail;
//  DIVD=YDR
    if (!TASSERT(divd_funcof( kyu) ==   (BOOL_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kbu) ==  (UINT8_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kbi) ==   (INT8_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( khu) == (UINT16_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( khi) ==  (INT16_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( khf) ==  (FLT16_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kwu) == (UINT32_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kwi) ==  (INT32_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kwf) ==    (FLT_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kdu) == (UINT64_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kdi) ==  (INT64_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof( kdf) ==    (DBL_DIVD)))  goto fail;
//  DIVDW=HWR
    if (!TASSERT(divd_funcof(vwhu) ==   (VWHU_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vwhi) ==   (VWHI_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vwhf) ==   (VWHF_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vwwu) ==   (VWWU_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vwwi) ==   (VWWI_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vwwf) ==   (VWWF_DIVD)))  goto fail;
//  DIVDD=WDR
    if (!TASSERT(divd_funcof(vdwu) ==   (VDWU_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vdwi) ==   (VDWI_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vdwf) ==   (VDWF_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vddu) ==   (VDDU_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vddi) ==   (VDDI_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vddf) ==   (VDDF_DIVD)))  goto fail;
//  DIVDQ=DR
    if (!TASSERT(divd_funcof(vqdu) ==   (VQDU_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vqdi) ==   (VQDI_DIVD)))  goto fail;
    if (!TASSERT(divd_funcof(vqdf) ==   (VQDF_DIVD)))  goto fail;
#if 0 // leave div_
}
#endif

#if 0 // enter dup_
{
#endif
//  DUPL=NONE
//  DUPLW=YWR
    if (!TASSERT(dupl_funcof(vwyu) ==   (VWYU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwbu) ==   (VWBU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwbi) ==   (VWBI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwhu) ==   (VWHU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwhi) ==   (VWHI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwhf) ==   (VWHF_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwwu) ==   (VWWU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwwi) ==   (VWWI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vwwf) ==   (VWWF_DUPL)))  goto fail;
//  DUPLD=YDR
    if (!TASSERT(dupl_funcof(vdyu) ==   (VDYU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdbu) ==   (VDBU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdbi) ==   (VDBI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdhu) ==   (VDHU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdhi) ==   (VDHI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdhf) ==   (VDHF_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdwu) ==   (VDWU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdwi) ==   (VDWI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vdwf) ==   (VDWF_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vddu) ==   (VDDU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vddi) ==   (VDDI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vddf) ==   (VDDF_DUPL)))  goto fail;
//  DUPLQ=YDR
    if (!TASSERT(dupl_funcof(vqyu) ==   (VQYU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqbu) ==   (VQBU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqbi) ==   (VQBI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqhu) ==   (VQHU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqhi) ==   (VQHI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqhf) ==   (VQHF_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqwu) ==   (VQWU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqwi) ==   (VQWI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqwf) ==   (VQWF_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqdu) ==   (VQDU_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqdi) ==   (VQDI_DUPL)))  goto fail;
    if (!TASSERT(dupl_funcof(vqdf) ==   (VQDF_DUPL)))  goto fail;
//  DUPW=BDR
    if (!TASSERT(dupw_funcof( kyu) ==   (BOOL_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( kbu) ==  (UINT8_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( kbi) ==   (INT8_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( khu) == (UINT16_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( khi) ==  (INT16_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( khf) ==  (FLT16_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( kwu) == (UINT32_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( kwi) ==  (INT32_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof( kwf) ==    (FLT_DUPW)))  goto fail;
//  DUPWA=YWR
    if (!TASSERT(dupw_funcof(&kyu) ==   (BOOL_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&kbu) ==  (UINT8_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&kbi) ==   (INT8_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&khu) == (UINT16_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&khi) ==  (INT16_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&khf) ==  (FLT16_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&kwu) == (UINT32_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&kwi) ==  (INT32_DUPWAC))) goto fail;
    if (!TASSERT(dupw_funcof(&kwf) ==    (FLT_DUPWAC))) goto fail;
//  DUPWW=YWR
    if (!TASSERT(dupw_funcof(vwbu) ==   (VWBU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwbi) ==   (VWBI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwhu) ==   (VWHU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwhi) ==   (VWHI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwhf) ==   (VWHF_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwwu) ==   (VWWU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwwi) ==   (VWWI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vwwf) ==   (VWWF_DUPW)))  goto fail;
//  DUPWD=YDR
    if (!TASSERT(dupw_funcof(vdyu) ==   (VDYU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdbu) ==   (VDBU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdbi) ==   (VDBI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdhu) ==   (VDHU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdhi) ==   (VDHI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdhf) ==   (VDHF_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdwu) ==   (VDWU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdwi) ==   (VDWI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vdwf) ==   (VDWF_DUPW)))  goto fail;
//  DUPWQ=YDR
    if (!TASSERT(dupw_funcof(vqyu) ==   (VQYU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqbu) ==   (VQBU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqbi) ==   (VQBI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqhu) ==   (VQHU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqhi) ==   (VQHI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqhf) ==   (VQHF_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqwu) ==   (VQWU_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqwi) ==   (VQWI_DUPW)))  goto fail;
    if (!TASSERT(dupw_funcof(vqwf) ==   (VQWF_DUPW)))  goto fail;
//  DUPD=BDR
    if (!TASSERT(dupd_funcof( kyu) ==   (BOOL_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kbu) ==  (UINT8_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kbi) ==   (INT8_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( khu) == (UINT16_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( khi) ==  (INT16_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( khf) ==  (FLT16_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kwu) == (UINT32_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kwi) ==  (INT32_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kwf) ==    (FLT_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kdu) == (UINT64_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kdi) ==  (INT64_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof( kdf) ==    (DBL_DUPD)))  goto fail;
//  DUPDA=YWR
    if (!TASSERT(dupd_funcof(&kyu) ==   (BOOL_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kbu) ==  (UINT8_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kbi) ==   (INT8_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&khu) == (UINT16_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&khi) ==  (INT16_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&khf) ==  (FLT16_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kwu) == (UINT32_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kwi) ==  (INT32_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kwf) ==    (FLT_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kdu) == (UINT64_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kdi) ==  (INT64_DUPDAC))) goto fail;
    if (!TASSERT(dupd_funcof(&kdf) ==    (DBL_DUPDAC))) goto fail;
//  DUPDW=YWR
    if (!TASSERT(dupd_funcof(vwbu) ==   (VWBU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwbi) ==   (VWBI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwhu) ==   (VWHU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwhi) ==   (VWHI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwhf) ==   (VWHF_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwwu) ==   (VWWU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwwi) ==   (VWWI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vwwf) ==   (VWWF_DUPD)))  goto fail;
//  DUPDD=YDR
    if (!TASSERT(dupd_funcof(vdyu) ==   (VDYU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdbu) ==   (VDBU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdbi) ==   (VDBI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdhu) ==   (VDHU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdhi) ==   (VDHI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdhf) ==   (VDHF_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdwu) ==   (VDWU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdwi) ==   (VDWI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vdwf) ==   (VDWF_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vddu) ==   (VDDU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vddi) ==   (VDDI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vddf) ==   (VDDF_DUPD)))  goto fail;
//  DUPDQ=YDR
    if (!TASSERT(dupd_funcof(vqyu) ==   (VQYU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqbu) ==   (VQBU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqbi) ==   (VQBI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqhu) ==   (VQHU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqhi) ==   (VQHI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqhf) ==   (VQHF_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqwu) ==   (VQWU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqwi) ==   (VQWI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqwf) ==   (VQWF_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqdu) ==   (VQDU_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqdi) ==   (VQDI_DUPD)))  goto fail;
    if (!TASSERT(dupd_funcof(vqdf) ==   (VQDF_DUPD)))  goto fail;
//  DUPQ=BDR
    if (!TASSERT(dupq_funcof( kyu) ==   (BOOL_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kbu) ==  (UINT8_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kbi) ==   (INT8_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( khu) == (UINT16_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( khi) ==  (INT16_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( khf) ==  (FLT16_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kwu) == (UINT32_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kwi) ==  (INT32_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kwf) ==    (FLT_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kdu) == (UINT64_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kdi) ==  (INT64_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof( kdf) ==    (DBL_DUPQ)))  goto fail;
//  DUPQA=YWR
    if (!TASSERT(dupq_funcof(&kyu) ==   (BOOL_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kbu) ==  (UINT8_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kbi) ==   (INT8_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&khu) == (UINT16_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&khi) ==  (INT16_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&khf) ==  (FLT16_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kwu) == (UINT32_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kwi) ==  (INT32_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kwf) ==    (FLT_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kdu) == (UINT64_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kdi) ==  (INT64_DUPQAC))) goto fail;
    if (!TASSERT(dupq_funcof(&kdf) ==    (DBL_DUPQAC))) goto fail;
//  DUPQW=YWR
    if (!TASSERT(dupq_funcof(vwbu) ==   (VWBU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwbi) ==   (VWBI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwhu) ==   (VWHU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwhi) ==   (VWHI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwhf) ==   (VWHF_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwwu) ==   (VWWU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwwi) ==   (VWWI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vwwf) ==   (VWWF_DUPQ)))  goto fail;
//  DUPQD=YDR
    if (!TASSERT(dupq_funcof(vdyu) ==   (VDYU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdbu) ==   (VDBU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdbi) ==   (VDBI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdhu) ==   (VDHU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdhi) ==   (VDHI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdhf) ==   (VDHF_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdwu) ==   (VDWU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdwi) ==   (VDWI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vdwf) ==   (VDWF_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vddu) ==   (VDDU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vddi) ==   (VDDI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vddf) ==   (VDDF_DUPQ)))  goto fail;
//  DUPQQ=YDR
    if (!TASSERT(dupq_funcof(vqyu) ==   (VQYU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqbu) ==   (VQBU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqbi) ==   (VQBI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqhu) ==   (VQHU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqhi) ==   (VQHI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqhf) ==   (VQHF_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqwu) ==   (VQWU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqwi) ==   (VQWI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqwf) ==   (VQWF_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqdu) ==   (VQDU_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqdi) ==   (VQDI_DUPQ)))  goto fail;
    if (!TASSERT(dupq_funcof(vqdf) ==   (VQDF_DUPQ)))  goto fail;
#if 0 // leave dup_
}
#endif

#if 0 // enter fam_
{
#endif
//  FAML=YDZ
    if (!TASSERT(faml_funcof( kyu) ==   (BOOL_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( kbu) ==  (UINT8_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( kbi) ==   (INT8_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( khu) == (UINT16_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( khi) ==  (INT16_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( kwu) == (UINT32_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( kwi) ==  (INT32_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( kdu) == (UINT64_FAML)))  goto fail;
    if (!TASSERT(faml_funcof( kdi) ==  (INT64_FAML)))  goto fail;
//  FAMLW=YWZ
    if (!TASSERT(faml_funcof(vwyu) ==   (VWYU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vwbu) ==   (VWBU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vwbi) ==   (VWBI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vwhu) ==   (VWHU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vwhi) ==   (VWHI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vwwu) ==   (VWWU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vwwi) ==   (VWWI_FAML)))  goto fail;
//  FAMLD=YDZ
    if (!TASSERT(faml_funcof(vdyu) ==   (VDYU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vdbu) ==   (VDBU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vdbi) ==   (VDBI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vdhu) ==   (VDHU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vdhi) ==   (VDHI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vdwu) ==   (VDWU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vdwi) ==   (VDWI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vddu) ==   (VDDU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vddi) ==   (VDDI_FAML)))  goto fail;
//  FAMLQ=YDZ
    if (!TASSERT(faml_funcof(vqyu) ==   (VQYU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqbu) ==   (VQBU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqbi) ==   (VQBI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqhu) ==   (VQHU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqhi) ==   (VQHI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqwu) ==   (VQWU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqwi) ==   (VQWI_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqdu) ==   (VQDU_FAML)))  goto fail;
    if (!TASSERT(faml_funcof(vqdi) ==   (VQDI_FAML)))  goto fail;
//  FAM2=HDZ
    if (!TASSERT(fam2_funcof( khu) == (UINT16_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof( khi) ==  (INT16_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof( kwu) == (UINT32_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof( kwi) ==  (INT32_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof( kdu) == (UINT64_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof( kdi) ==  (INT64_FAM2)))  goto fail;
//  FAM2W=NONE
//  FAM2D=HDZ
    if (!TASSERT(fam2_funcof(vdhu) ==   (VDHU_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vdhi) ==   (VDHI_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vdwu) ==   (VDWU_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vdwi) ==   (VDWI_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vddu) ==   (VDDU_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vddi) ==   (VDDI_FAM2)))  goto fail;
//  FAM2Q=HDZ
    if (!TASSERT(fam2_funcof(vqhu) ==   (VQHU_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vqhi) ==   (VQHI_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vqwu) ==   (VQWU_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vqwi) ==   (VQWI_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vqdu) ==   (VQDU_FAM2)))  goto fail;
    if (!TASSERT(fam2_funcof(vqdi) ==   (VQDI_FAM2)))  goto fail;
//  FAMF=HDF
    if (!TASSERT(famf_funcof( khf) ==  (FLT16_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof( kwf) ==    (FLT_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof( kdf) ==    (DBL_FAMF)))  goto fail;
//  FAMFW=HWF
    if (!TASSERT(famf_funcof(vwhf) ==   (VWHF_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof(vwwf) ==   (VWWF_FAMF)))  goto fail;
//  FAMFD=HDF
    if (!TASSERT(famf_funcof(vdhf) ==   (VDHF_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof(vdwf) ==   (VDWF_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof(vddf) ==   (VDDF_FAMF)))  goto fail;
//  FAMFQ=HDF
    if (!TASSERT(famf_funcof(vqhf) ==   (VQHF_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof(vqwf) ==   (VQWF_FAMF)))  goto fail;
    if (!TASSERT(famf_funcof(vqdf) ==   (VQDF_FAMF)))  goto fail;
#if 0 // leave fam_
}
#endif

#if 0 // enter get_
{
#endif
//  GET1=NONE
//  GET1W=YHR
    if (!TASSERT(get1_funcof(vwyu) ==   (VWYU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vwbu) ==   (VWBU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vwbi) ==   (VWBI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vwhu) ==   (VWHU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vwhi) ==   (VWHI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vwhf) ==   (VWHF_GET1)))  goto fail;
//  GET1D=YWR
    if (!TASSERT(get1_funcof(vdyu) ==   (VDYU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdbu) ==   (VDBU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdbi) ==   (VDBI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdhu) ==   (VDHU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdhi) ==   (VDHI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdhf) ==   (VDHF_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdwu) ==   (VDWU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdwi) ==   (VDWI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vdwf) ==   (VDWF_GET1)))  goto fail;
//  GET1Q=YDR
    if (!TASSERT(get1_funcof(vqyu) ==   (VQYU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqbu) ==   (VQBU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqbi) ==   (VQBI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqhu) ==   (VQHU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqhi) ==   (VQHI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqhf) ==   (VQHF_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqwu) ==   (VQWU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqwi) ==   (VQWI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqwf) ==   (VQWF_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqdu) ==   (VQDU_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqdi) ==   (VQDI_GET1)))  goto fail;
    if (!TASSERT(get1_funcof(vqdf) ==   (VQDF_GET1)))  goto fail;
//  GETLW=NONE
//  GETLD=YWR
    if (!TASSERT(getl_funcof(vdyu) ==   (VDYU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdbu) ==   (VDBU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdbi) ==   (VDBI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdhu) ==   (VDHU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdhi) ==   (VDHI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdhf) ==   (VDHF_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdwu) ==   (VDWU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdwi) ==   (VDWI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vdwf) ==   (VDWF_GETL)))  goto fail;
//  GETLQ=YDR
    if (!TASSERT(getl_funcof(vqyu) ==   (VQYU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqbu) ==   (VQBU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqbi) ==   (VQBI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqhu) ==   (VQHU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqhi) ==   (VQHI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqhf) ==   (VQHF_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqwu) ==   (VQWU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqwi) ==   (VQWI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqwf) ==   (VQWF_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqdu) ==   (VQDU_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqdi) ==   (VQDI_GETL)))  goto fail;
    if (!TASSERT(getl_funcof(vqdf) ==   (VQDF_GETL)))  goto fail;
//  GETRW=NONE
//  GETRD=YWR
    if (!TASSERT(getr_funcof(vdyu) ==   (VDYU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdbu) ==   (VDBU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdbi) ==   (VDBI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdhu) ==   (VDHU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdhi) ==   (VDHI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdhf) ==   (VDHF_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdwu) ==   (VDWU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdwi) ==   (VDWI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vdwf) ==   (VDWF_GETR)))  goto fail;
//  GETRQ=YDR
    if (!TASSERT(getr_funcof(vqyu) ==   (VQYU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqbu) ==   (VQBU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqbi) ==   (VQBI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqhu) ==   (VQHU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqhi) ==   (VQHI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqhf) ==   (VQHF_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqwu) ==   (VQWU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqwi) ==   (VQWI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqwf) ==   (VQWF_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqdu) ==   (VQDU_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqdi) ==   (VQDI_GETR)))  goto fail;
    if (!TASSERT(getr_funcof(vqdf) ==   (VQDF_GETR)))  goto fail;
#if 0 // leave get_
}
#endif

#if 0 // enter icr_
{
#endif
//  ICR1A=YDZ
    if (!TASSERT(icr1_funcof(&kyu) ==   (BOOL_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&kbu) ==  (UINT8_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&kbi) ==   (INT8_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&khu) == (UINT16_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&khi) ==  (INT16_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&kwu) == (UINT32_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&kwi) ==  (INT32_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&kdu) == (UINT64_ICR1A))) goto fail;
    if (!TASSERT(icr1_funcof(&kdi) ==  (INT64_ICR1A))) goto fail;
//  ICRAA=YDZ
    if (!TASSERT(icra_funcof(&kyu) ==   (BOOL_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&kbu) ==  (UINT8_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&kbi) ==   (INT8_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&khu) == (UINT16_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&khi) ==  (INT16_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&kwu) == (UINT32_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&kwi) ==  (INT32_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&kdu) == (UINT64_ICRAA))) goto fail;
    if (!TASSERT(icra_funcof(&kdi) ==  (INT64_ICRAA))) goto fail;
//  ICREA=YDZ
    if (!TASSERT(icre_funcof(&kyu) ==   (BOOL_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&kbu) ==  (UINT8_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&kbi) ==   (INT8_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&khu) == (UINT16_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&khi) ==  (INT16_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&kwu) == (UINT32_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&kwi) ==  (INT32_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&kdu) == (UINT64_ICREA))) goto fail;
    if (!TASSERT(icre_funcof(&kdi) ==  (INT64_ICREA))) goto fail;
//  ICRTA=YDZ
    if (!TASSERT(icrt_funcof(&kyu) ==   (BOOL_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&kbu) ==  (UINT8_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&kbi) ==   (INT8_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&khu) == (UINT16_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&khi) ==  (INT16_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&kwu) == (UINT32_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&kwi) ==  (INT32_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&kdu) == (UINT64_ICRTA))) goto fail;
    if (!TASSERT(icrt_funcof(&kdi) ==  (INT64_ICRTA))) goto fail;
//  ICRL=YDZ
    if (!TASSERT(icrl_funcof( kyu) ==   (BOOL_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( kbu) ==  (UINT8_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( kbi) ==   (INT8_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( khu) == (UINT16_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( khi) ==  (INT16_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( kwu) == (UINT32_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( kwi) ==  (INT32_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( kdu) == (UINT64_ICRL)))  goto fail;
    if (!TASSERT(icrl_funcof( kdi) ==  (INT64_ICRL)))  goto fail;
#if 0 // leave icr_
}
#endif

#if 0 // enter inv_
{
#endif
//  INV1A=YDZ
    if (!TASSERT(inv1_funcof(&kyu) ==   (BOOL_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&kbu) ==  (UINT8_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&kbi) ==   (INT8_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&khu) == (UINT16_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&khi) ==  (INT16_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&kwu) == (UINT32_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&kwi) ==  (INT32_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&kdu) == (UINT64_INV1A))) goto fail;
    if (!TASSERT(inv1_funcof(&kdi) ==  (INT64_INV1A))) goto fail;
//  INVAA=YDZ
    if (!TASSERT(inva_funcof(&kyu) ==   (BOOL_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&kbu) ==  (UINT8_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&kbi) ==   (INT8_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&khu) == (UINT16_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&khi) ==  (INT16_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&kwu) == (UINT32_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&kwi) ==  (INT32_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&kdu) == (UINT64_INVAA))) goto fail;
    if (!TASSERT(inva_funcof(&kdi) ==  (INT64_INVAA))) goto fail;
//  INVEA=YDZ
    if (!TASSERT(inve_funcof(&kyu) ==   (BOOL_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&kbu) ==  (UINT8_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&kbi) ==   (INT8_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&khu) == (UINT16_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&khi) ==  (INT16_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&kwu) == (UINT32_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&kwi) ==  (INT32_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&kdu) == (UINT64_INVEA))) goto fail;
    if (!TASSERT(inve_funcof(&kdi) ==  (INT64_INVEA))) goto fail;
//  INVTA=YDZ
    if (!TASSERT(invt_funcof(&kyu) ==   (BOOL_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&kbu) ==  (UINT8_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&kbi) ==   (INT8_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&khu) == (UINT16_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&khi) ==  (INT16_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&kwu) == (UINT32_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&kwi) ==  (INT32_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&kdu) == (UINT64_INVTA))) goto fail;
    if (!TASSERT(invt_funcof(&kdi) ==  (INT64_INVTA))) goto fail;
//  INVS=YDZ
    if (!TASSERT(invs_funcof( kyu) ==   (BOOL_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( kbu) ==  (UINT8_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( kbi) ==   (INT8_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( khu) == (UINT16_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( khi) ==  (INT16_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( kwu) == (UINT32_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( kwi) ==  (INT32_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( kdu) == (UINT64_INVS)))  goto fail;
    if (!TASSERT(invs_funcof( kdi) ==  (INT64_INVS)))  goto fail;
#if 0 // leave inv_
}
#endif

#if 0 // enter ldr_
{
#endif
//  LDR1AC=YDZ
    if (!TASSERT(ldr1_funcof(&kyu) ==   (BOOL_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&kbu) ==  (UINT8_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&kbi) ==   (INT8_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&khu) == (UINT16_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&khi) ==  (INT16_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&kwu) == (UINT32_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&kwi) ==  (INT32_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&kdu) == (UINT64_LDR1AC)))  goto fail;
    if (!TASSERT(ldr1_funcof(&kdi) ==  (INT64_LDR1AC)))  goto fail;
//  LDRAAC=YDZ
    if (!TASSERT(ldra_funcof(&kyu) ==   (BOOL_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&kbu) ==  (UINT8_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&kbi) ==   (INT8_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&khu) == (UINT16_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&khi) ==  (INT16_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&kwu) == (UINT32_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&kwi) ==  (INT32_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&kdu) == (UINT64_LDRAAC)))  goto fail;
    if (!TASSERT(ldra_funcof(&kdi) ==  (INT64_LDRAAC)))  goto fail;
//  LDRTAC=YDZ
    if (!TASSERT(ldrt_funcof(&kyu) ==   (BOOL_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&kbu) ==  (UINT8_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&kbi) ==   (INT8_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&khu) == (UINT16_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&khi) ==  (INT16_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&kwu) == (UINT32_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&kwi) ==  (INT32_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&kdu) == (UINT64_LDRTAC)))  goto fail;
    if (!TASSERT(ldrt_funcof(&kdi) ==  (INT64_LDRTAC)))  goto fail;
//  LDRWAC=BWR
    if (!TASSERT(ldrw_funcof(&kbu) ==  (UINT8_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&kbi) ==   (INT8_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&khu) == (UINT16_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&khi) ==  (INT16_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&khf) ==  (FLT16_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&kwu) == (UINT32_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&kwi) ==  (INT32_LDRWAC)))  goto fail;
    if (!TASSERT(ldrw_funcof(&kwf) ==    (FLT_LDRWAC)))  goto fail;
//  LDRDAC=BDR
    if (!TASSERT(ldrd_funcof(&kbu) ==  (UINT8_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kbi) ==   (INT8_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&khu) == (UINT16_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&khi) ==  (INT16_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&khf) ==  (FLT16_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kwu) == (UINT32_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kwi) ==  (INT32_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kwf) ==    (FLT_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kdu) == (UINT64_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kdi) ==  (INT64_LDRDAC)))  goto fail;
    if (!TASSERT(ldrd_funcof(&kdf) ==    (DBL_LDRDAC)))  goto fail;
//  LDRQAC=BDR
    if (!TASSERT(ldrq_funcof(&kbu) ==  (UINT8_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kbi) ==   (INT8_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&khu) == (UINT16_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&khi) ==  (INT16_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&khf) ==  (FLT16_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kwu) == (UINT32_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kwi) ==  (INT32_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kwf) ==    (FLT_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kdu) == (UINT64_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kdi) ==  (INT64_LDRQAC)))  goto fail;
    if (!TASSERT(ldrq_funcof(&kdf) ==    (DBL_LDRQAC)))  goto fail;
#if 0 // leave ldr_
}
#endif

#if 0 // enter lun_
{
#endif
//  LUN1=NONE
//  LUN1W=YHR
    if (!TASSERT(lun1_funcof(vwyu) ==   (VWYU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vwbu) ==   (VWBU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vwbi) ==   (VWBI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vwhu) ==   (VWHU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vwhi) ==   (VWHI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vwhf) ==   (VWHF_LUN1)))  goto fail;
//  LUN1D=YWR
    if (!TASSERT(lun1_funcof(vdyu) ==   (VDYU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdbu) ==   (VDBU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdbi) ==   (VDBI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdhu) ==   (VDHU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdhi) ==   (VDHI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdhf) ==   (VDHF_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdwu) ==   (VDWU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdwi) ==   (VDWI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vdwf) ==   (VDWF_LUN1)))  goto fail;
//  LUN1Q=YDR
    if (!TASSERT(lun1_funcof(vqyu) ==   (VQYU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqbu) ==   (VQBU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqbi) ==   (VQBI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqhu) ==   (VQHU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqhi) ==   (VQHI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqhf) ==   (VQHF_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqwu) ==   (VQWU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqwi) ==   (VQWI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqwf) ==   (VQWF_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqdu) ==   (VQDU_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqdi) ==   (VQDI_LUN1)))  goto fail;
    if (!TASSERT(lun1_funcof(vqdf) ==   (VQDF_LUN1)))  goto fail;
//  LUNNAC=YDR
    if (!TASSERT(lunn_funcof(&kyu) ==   (BOOL_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kbu) ==  (UINT8_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kbi) ==   (INT8_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&khu) == (UINT16_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&khi) ==  (INT16_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&khf) ==  (FLT16_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kwu) == (UINT32_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kwi) ==  (INT32_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kwf) ==    (FLT_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kdu) == (UINT64_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kdi) ==  (INT64_LUNNAC)))  goto fail;
    if (!TASSERT(lunn_funcof(&kdf) ==    (DBL_LUNNAC)))  goto fail;
//  LUNWAC=BWR
    if (!TASSERT(lunw_funcof(&kbu) ==  (UINT8_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&kbi) ==   (INT8_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&khu) == (UINT16_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&khi) ==  (INT16_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&khf) ==  (FLT16_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&kwu) == (UINT32_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&kwi) ==  (INT32_LUNWAC)))  goto fail;
    if (!TASSERT(lunw_funcof(&kwf) ==    (FLT_LUNWAC)))  goto fail;
//  LUNDAC=BDR
    if (!TASSERT(lund_funcof(&kbu) ==  (UINT8_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kbi) ==   (INT8_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&khu) == (UINT16_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&khi) ==  (INT16_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&khf) ==  (FLT16_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kwu) == (UINT32_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kwi) ==  (INT32_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kwf) ==    (FLT_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kdu) == (UINT64_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kdi) ==  (INT64_LUNDAC)))  goto fail;
    if (!TASSERT(lund_funcof(&kdf) ==    (DBL_LUNDAC)))  goto fail;
//  LUNQAC=BDR
    if (!TASSERT(lunq_funcof(&kbu) ==  (UINT8_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kbi) ==   (INT8_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&khu) == (UINT16_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&khi) ==  (INT16_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&khf) ==  (FLT16_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kwu) == (UINT32_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kwi) ==  (INT32_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kwf) ==    (FLT_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kdu) == (UINT64_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kdi) ==  (INT64_LUNQAC)))  goto fail;
    if (!TASSERT(lunq_funcof(&kdf) ==    (DBL_LUNQAC)))  goto fail;
#if 0 // leave lun_
}
#endif

#if 0 // enter max_
{
#endif
//  CLTR=YDR
    if (!TASSERT(cltr_funcof( kyu) ==   (BOOL_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kbu) ==  (UINT8_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kbi) ==   (INT8_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( khu) == (UINT16_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( khi) ==  (INT16_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( khf) ==  (FLT16_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kwu) == (UINT32_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kwi) ==  (INT32_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kwf) ==    (FLT_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kdu) == (UINT64_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kdi) ==  (INT64_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof( kdf) ==    (DBL_CLTR)))  goto fail;
//  CLTRW=YWR
    if (!TASSERT(cltr_funcof(vwyu) ==   (VWYU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwbu) ==   (VWBU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwbi) ==   (VWBI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwhu) ==   (VWHU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwhi) ==   (VWHI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwhf) ==   (VWHF_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwwu) ==   (VWWU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwwi) ==   (VWWI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vwwf) ==   (VWWF_CLTR)))  goto fail;
//  CLTRD=YDR
    if (!TASSERT(cltr_funcof(vdyu) ==   (VDYU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdbu) ==   (VDBU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdbi) ==   (VDBI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdhu) ==   (VDHU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdhi) ==   (VDHI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdhf) ==   (VDHF_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdwu) ==   (VDWU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdwi) ==   (VDWI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vdwf) ==   (VDWF_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vddu) ==   (VDDU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vddi) ==   (VDDI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vddf) ==   (VDDF_CLTR)))  goto fail;
//  CLTRQ=YDR
    if (!TASSERT(cltr_funcof(vqyu) ==   (VQYU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqbu) ==   (VQBU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqbi) ==   (VQBI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqhu) ==   (VQHU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqhi) ==   (VQHI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqhf) ==   (VQHF_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqwu) ==   (VQWU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqwi) ==   (VQWI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqwf) ==   (VQWF_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqdu) ==   (VQDU_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqdi) ==   (VQDI_CLTR)))  goto fail;
    if (!TASSERT(cltr_funcof(vqdf) ==   (VQDF_CLTR)))  goto fail;
//  MAXVW=YHR
    if (!TASSERT(maxv_funcof(vwyu) ==   (VWYU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vwbu) ==   (VWBU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vwbi) ==   (VWBI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vwhu) ==   (VWHU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vwhi) ==   (VWHI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vwhf) ==   (VWHF_MAXV)))  goto fail;
//  MAXVD=YWR
    if (!TASSERT(maxv_funcof(vdyu) ==   (VDYU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdbu) ==   (VDBU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdbi) ==   (VDBI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdhu) ==   (VDHU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdhi) ==   (VDHI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdhf) ==   (VDHF_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdwu) ==   (VDWU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdwi) ==   (VDWI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vdwf) ==   (VDWF_MAXV)))  goto fail;
//  MAXVQ=YDR
    if (!TASSERT(maxv_funcof(vqyu) ==   (VQYU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqbu) ==   (VQBU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqbi) ==   (VQBI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqhu) ==   (VQHU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqhi) ==   (VQHI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqhf) ==   (VQHF_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqwu) ==   (VQWU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqwi) ==   (VQWI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqwf) ==   (VQWF_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqdu) ==   (VQDU_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqdi) ==   (VQDI_MAXV)))  goto fail;
    if (!TASSERT(maxv_funcof(vqdf) ==   (VQDF_MAXV)))  goto fail;
#if 0 // leave max_
}
#endif

#if 0 // enter min_
{
#endif
//  CGTR=YDR
    if (!TASSERT(cgtr_funcof( kyu) ==   (BOOL_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kbu) ==  (UINT8_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kbi) ==   (INT8_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( khu) == (UINT16_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( khi) ==  (INT16_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( khf) ==  (FLT16_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kwu) == (UINT32_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kwi) ==  (INT32_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kwf) ==    (FLT_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kdu) == (UINT64_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kdi) ==  (INT64_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof( kdf) ==    (DBL_CGTR)))  goto fail;
//  CGTRW=YWR
    if (!TASSERT(cgtr_funcof(vwyu) ==   (VWYU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwbu) ==   (VWBU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwbi) ==   (VWBI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwhu) ==   (VWHU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwhi) ==   (VWHI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwhf) ==   (VWHF_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwwu) ==   (VWWU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwwi) ==   (VWWI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vwwf) ==   (VWWF_CGTR)))  goto fail;
//  CGTRD=YDR
    if (!TASSERT(cgtr_funcof(vdyu) ==   (VDYU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdbu) ==   (VDBU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdbi) ==   (VDBI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdhu) ==   (VDHU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdhi) ==   (VDHI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdhf) ==   (VDHF_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdwu) ==   (VDWU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdwi) ==   (VDWI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vdwf) ==   (VDWF_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vddu) ==   (VDDU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vddi) ==   (VDDI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vddf) ==   (VDDF_CGTR)))  goto fail;
//  CGTRQ=YDR
    if (!TASSERT(cgtr_funcof(vqyu) ==   (VQYU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqbu) ==   (VQBU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqbi) ==   (VQBI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqhu) ==   (VQHU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqhi) ==   (VQHI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqhf) ==   (VQHF_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqwu) ==   (VQWU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqwi) ==   (VQWI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqwf) ==   (VQWF_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqdu) ==   (VQDU_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqdi) ==   (VQDI_CGTR)))  goto fail;
    if (!TASSERT(cgtr_funcof(vqdf) ==   (VQDF_CGTR)))  goto fail;
//  MINVW=YHR
    if (!TASSERT(minv_funcof(vwyu) ==   (VWYU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vwbu) ==   (VWBU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vwbi) ==   (VWBI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vwhu) ==   (VWHU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vwhi) ==   (VWHI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vwhf) ==   (VWHF_MINV)))  goto fail;
//  MINVD=YWR
    if (!TASSERT(minv_funcof(vdyu) ==   (VDYU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdbu) ==   (VDBU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdbi) ==   (VDBI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdhu) ==   (VDHU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdhi) ==   (VDHI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdhf) ==   (VDHF_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdwu) ==   (VDWU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdwi) ==   (VDWI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vdwf) ==   (VDWF_MINV)))  goto fail;
//  MINVQ=YDR
    if (!TASSERT(minv_funcof(vqyu) ==   (VQYU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqbu) ==   (VQBU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqbi) ==   (VQBI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqhu) ==   (VQHU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqhi) ==   (VQHI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqhf) ==   (VQHF_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqwu) ==   (VQWU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqwi) ==   (VQWI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqwf) ==   (VQWF_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqdu) ==   (VQDU_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqdi) ==   (VQDI_MINV)))  goto fail;
    if (!TASSERT(minv_funcof(vqdf) ==   (VQDF_MINV)))  goto fail;
#if 0 // leave min_
}
#endif

#if 0 // enter mod_
{
#endif
//  REML=BDZ
    if (!TASSERT(reml_funcof( kbu) ==  (UINT8_REML)))  goto fail;
    if (!TASSERT(reml_funcof( kbi) ==   (INT8_REML)))  goto fail;
    if (!TASSERT(reml_funcof( khu) == (UINT16_REML)))  goto fail;
    if (!TASSERT(reml_funcof( khi) ==  (INT16_REML)))  goto fail;
    if (!TASSERT(reml_funcof( kwu) == (UINT32_REML)))  goto fail;
    if (!TASSERT(reml_funcof( kwi) ==  (INT32_REML)))  goto fail;
    if (!TASSERT(reml_funcof( kdu) == (UINT64_REML)))  goto fail;
    if (!TASSERT(reml_funcof( kdi) ==  (INT64_REML)))  goto fail;
//  REMLW=BWZ
    if (!TASSERT(reml_funcof(vwbu) ==   (VWBU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vwbi) ==   (VWBI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vwhu) ==   (VWHU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vwhi) ==   (VWHI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vwwu) ==   (VWWU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vwwi) ==   (VWWI_REML)))  goto fail;
//  REMLD=BDZ
    if (!TASSERT(reml_funcof(vdbu) ==   (VDBU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vdbi) ==   (VDBI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vdhu) ==   (VDHU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vdhi) ==   (VDHI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vdwu) ==   (VDWU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vdwi) ==   (VDWI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vddu) ==   (VDDU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vddi) ==   (VDDI_REML)))  goto fail;
//  REMLQ=BDZ
    if (!TASSERT(reml_funcof(vqbu) ==   (VQBU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqbi) ==   (VQBI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqhu) ==   (VQHU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqhi) ==   (VQHI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqwu) ==   (VQWU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqwi) ==   (VQWI_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqdu) ==   (VQDU_REML)))  goto fail;
    if (!TASSERT(reml_funcof(vqdi) ==   (VQDI_REML)))  goto fail;
//  REM2=HDZ
    if (!TASSERT(rem2_funcof( khu) == (UINT16_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof( khi) ==  (INT16_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof( kwu) == (UINT32_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof( kwi) ==  (INT32_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof( kdu) == (UINT64_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof( kdi) ==  (INT64_REM2)))  goto fail;
//  REM2W=NONE
//  REM2D=HDZ
    if (!TASSERT(rem2_funcof(vdhu) ==   (VDHU_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vdhi) ==   (VDHI_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vdwu) ==   (VDWU_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vdwi) ==   (VDWI_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vddu) ==   (VDDU_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vddi) ==   (VDDI_REM2)))  goto fail;
//  REM2Q=HDZ
    if (!TASSERT(rem2_funcof(vqhu) ==   (VQHU_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vqhi) ==   (VQHI_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vqwu) ==   (VQWU_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vqwi) ==   (VQWI_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vqdu) ==   (VQDU_REM2)))  goto fail;
    if (!TASSERT(rem2_funcof(vqdi) ==   (VQDI_REM2)))  goto fail;
#if 0 // leave mod_
}
#endif

#if 0 // enter mul_
{
#endif
//  MULL=YDZ
    if (!TASSERT(mull_funcof( kyu) ==   (BOOL_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( kbu) ==  (UINT8_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( kbi) ==   (INT8_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( khu) == (UINT16_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( khi) ==  (INT16_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( kwu) == (UINT32_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( kwi) ==  (INT32_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( kdu) == (UINT64_MULL)))  goto fail;
    if (!TASSERT(mull_funcof( kdi) ==  (INT64_MULL)))  goto fail;
//  MULLW=YWZ
    if (!TASSERT(mull_funcof(vwyu) ==   (VWYU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vwbu) ==   (VWBU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vwbi) ==   (VWBI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vwhu) ==   (VWHU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vwhi) ==   (VWHI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vwwu) ==   (VWWU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vwwi) ==   (VWWI_MULL)))  goto fail;
//  MULLD=YDZ
    if (!TASSERT(mull_funcof(vdyu) ==   (VDYU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vdbu) ==   (VDBU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vdbi) ==   (VDBI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vdhu) ==   (VDHU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vdhi) ==   (VDHI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vdwu) ==   (VDWU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vdwi) ==   (VDWI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vddu) ==   (VDDU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vddi) ==   (VDDI_MULL)))  goto fail;
//  MULLQ=YDZ
    if (!TASSERT(mull_funcof(vqyu) ==   (VQYU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqbu) ==   (VQBU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqbi) ==   (VQBI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqhu) ==   (VQHU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqhi) ==   (VQHI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqwu) ==   (VQWU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqwi) ==   (VQWI_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqdu) ==   (VQDU_MULL)))  goto fail;
    if (!TASSERT(mull_funcof(vqdi) ==   (VQDI_MULL)))  goto fail;
//  MUL2=BWZ
    if (!TASSERT(mul2_funcof( kbu) ==  (UINT8_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof( kbi) ==   (INT8_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof( khu) == (UINT16_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof( khi) ==  (INT16_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof( kwu) == (UINT32_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof( kwi) ==  (INT32_MUL2)))  goto fail;
//  MUL2W=BWZ
    if (!TASSERT(mul2_funcof(vwbu) ==   (VWBU_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vwbi) ==   (VWBI_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vwhu) ==   (VWHU_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vwhi) ==   (VWHI_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vwwu) ==   (VWWU_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vwwi) ==   (VWWI_MUL2)))  goto fail;
//  MUL2D=BWZ
    if (!TASSERT(mul2_funcof(vdbu) ==   (VDBU_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vdbi) ==   (VDBI_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vdhu) ==   (VDHU_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vdhi) ==   (VDHI_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vdwu) ==   (VDWU_MUL2)))  goto fail;
    if (!TASSERT(mul2_funcof(vdwi) ==   (VDWI_MUL2)))  goto fail;
//  MUL2Q=NONE
//  MULS=YDZ
    if (!TASSERT(muls_funcof( kyu) ==   (BOOL_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( kbu) ==  (UINT8_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( kbi) ==   (INT8_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( khu) == (UINT16_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( khi) ==  (INT16_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( kwu) == (UINT32_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( kwi) ==  (INT32_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( kdu) == (UINT64_MULS)))  goto fail;
    if (!TASSERT(muls_funcof( kdi) ==  (INT64_MULS)))  goto fail;
//  MULSW=YWZ
    if (!TASSERT(muls_funcof(vwyu) ==   (VWYU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vwbu) ==   (VWBU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vwbi) ==   (VWBI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vwhu) ==   (VWHU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vwhi) ==   (VWHI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vwwu) ==   (VWWU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vwwi) ==   (VWWI_MULS)))  goto fail;
//  MULDD=YDZ
    if (!TASSERT(muls_funcof(vdyu) ==   (VDYU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vdbu) ==   (VDBU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vdbi) ==   (VDBI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vdhu) ==   (VDHU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vdhi) ==   (VDHI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vdwu) ==   (VDWU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vdwi) ==   (VDWI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vddu) ==   (VDDU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vddi) ==   (VDDI_MULS)))  goto fail;
//  MULSQ=YDZ
    if (!TASSERT(muls_funcof(vqbu) ==   (VQBU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqyu) ==   (VQYU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqbu) ==   (VQBU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqbi) ==   (VQBI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqhu) ==   (VQHU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqhi) ==   (VQHI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqwu) ==   (VQWU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqwi) ==   (VQWI_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqdu) ==   (VQDU_MULS)))  goto fail;
    if (!TASSERT(muls_funcof(vqdi) ==   (VQDI_MULS)))  goto fail;
//  MULH=YDR
    if (!TASSERT(mulh_funcof( kyu) ==   (BOOL_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kbu) ==  (UINT8_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kbi) ==   (INT8_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( khu) == (UINT16_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( khi) ==  (INT16_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( khf) ==  (FLT16_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kwu) == (UINT32_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kwi) ==  (INT32_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kwf) ==    (FLT_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kdu) == (UINT64_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kdi) ==  (INT64_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof( kdf) ==    (DBL_MULH)))  goto fail;
//  MULHW=BHR
    if (!TASSERT(mulh_funcof(vwbu) ==   (VWBU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vwbi) ==   (VWBI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vwhu) ==   (VWHU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vwhi) ==   (VWHI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vwhf) ==   (VWHF_MULH)))  goto fail;
//  MULHD=BWR
    if (!TASSERT(mulh_funcof(vdbu) ==   (VDBU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdbi) ==   (VDBI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdhu) ==   (VDHU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdhi) ==   (VDHI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdhf) ==   (VDHF_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdwu) ==   (VDWU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdwi) ==   (VDWI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vdwf) ==   (VDWF_MULH)))  goto fail;
//  MULHQ=HDR
    if (!TASSERT(mulh_funcof(vqhu) ==   (VQHU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqhi) ==   (VQHI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqhf) ==   (VQHF_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqwu) ==   (VQWU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqwi) ==   (VQWI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqwf) ==   (VQWF_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqdu) ==   (VQDU_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqdi) ==   (VQDI_MULH)))  goto fail;
    if (!TASSERT(mulh_funcof(vqdf) ==   (VQDF_MULH)))  goto fail;
//  MULW=YDR
    if (!TASSERT(mulw_funcof( kyu) ==   (BOOL_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kbu) ==  (UINT8_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kbi) ==   (INT8_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( khu) == (UINT16_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( khi) ==  (INT16_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( khf) ==  (FLT16_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kwu) == (UINT32_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kwi) ==  (INT32_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kwf) ==    (FLT_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kdu) == (UINT64_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kdi) ==  (INT64_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof( kdf) ==    (DBL_MULW)))  goto fail;
//  MULWW=BHR
    if (!TASSERT(mulw_funcof(vwbu) ==   (VWBU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwbi) ==   (VWBI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwhu) ==   (VWHU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwhi) ==   (VWHI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwhf) ==   (VWHF_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwwu) ==   (VWWU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwwi) ==   (VWWI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vwwf) ==   (VWWF_MULW)))  goto fail;
//  MULWD=HDR
    if (!TASSERT(mulw_funcof(vdhu) ==   (VDHU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vdhi) ==   (VDHI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vdhf) ==   (VDHF_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vdwu) ==   (VDWU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vdwi) ==   (VDWI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vdwf) ==   (VDWF_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vddu) ==   (VDDU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vddi) ==   (VDDI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vddf) ==   (VDDF_MULW)))  goto fail;
//  MULWQ=WDR
    if (!TASSERT(mulw_funcof(vqwu) ==   (VQWU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vqwi) ==   (VQWI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vqwf) ==   (VQWF_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vqdu) ==   (VQDU_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vqdi) ==   (VQDI_MULW)))  goto fail;
    if (!TASSERT(mulw_funcof(vqdf) ==   (VQDF_MULW)))  goto fail;
//  MULD=YDR
    if (!TASSERT(muld_funcof( kyu) ==   (BOOL_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kbu) ==  (UINT8_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kbi) ==   (INT8_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( khu) == (UINT16_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( khi) ==  (INT16_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( khf) ==  (FLT16_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kwu) == (UINT32_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kwi) ==  (INT32_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kwf) ==    (FLT_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kdu) == (UINT64_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kdi) ==  (INT64_MULD)))  goto fail;
    if (!TASSERT(muld_funcof( kdf) ==    (DBL_MULD)))  goto fail;
//  MULDW=HWR
    if (!TASSERT(muld_funcof(vwhu) ==   (VWHU_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vwhi) ==   (VWHI_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vwhf) ==   (VWHF_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vwwu) ==   (VWWU_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vwwi) ==   (VWWI_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vwwf) ==   (VWWF_MULD)))  goto fail;
//  MULDD=WDR
    if (!TASSERT(muld_funcof(vdwu) ==   (VDWU_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vdwi) ==   (VDWI_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vdwf) ==   (VDWF_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vddu) ==   (VDDU_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vddi) ==   (VDDI_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vddf) ==   (VDDF_MULD)))  goto fail;
//  MULDQ=DR
    if (!TASSERT(muld_funcof(vqdu) ==   (VQDU_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vqdi) ==   (VQDI_MULD)))  goto fail;
    if (!TASSERT(muld_funcof(vqdf) ==   (VQDF_MULD)))  goto fail;
#if 0 // leave mul_
}
#endif

#if 0 // enter neg_
{
#endif
//  NEGL=BDZ
    if (!TASSERT(negl_funcof( kbu) ==  (UINT8_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( kbi) ==   (INT8_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( khu) == (UINT16_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( khi) ==  (INT16_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( kwu) == (UINT32_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( kwi) ==  (INT32_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( kdu) == (UINT64_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof( kdi) ==  (INT64_NEGL)))  goto fail;
//  NEGLW=BWZ
    if (!TASSERT(negl_funcof(vwbu) ==   (VWBU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vwbi) ==   (VWBI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vwhu) ==   (VWHU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vwhi) ==   (VWHI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vwwu) ==   (VWWU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vwwi) ==   (VWWI_NEGL)))  goto fail;
//  NEGLD=BDZ
    if (!TASSERT(negl_funcof(vdbu) ==   (VDBU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vdbi) ==   (VDBI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vdhu) ==   (VDHU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vdhi) ==   (VDHI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vdwu) ==   (VDWU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vdwi) ==   (VDWI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vddu) ==   (VDDU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vddi) ==   (VDDI_NEGL)))  goto fail;
//  NEGLQ=BDZ
    if (!TASSERT(negl_funcof(vqbu) ==   (VQBU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqbi) ==   (VQBI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqhu) ==   (VQHU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqhi) ==   (VQHI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqwu) ==   (VQWU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqwi) ==   (VQWI_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqdu) ==   (VQDU_NEGL)))  goto fail;
    if (!TASSERT(negl_funcof(vqdi) ==   (VQDI_NEGL)))  goto fail;
//  NEGS=BDR
    if (!TASSERT(negs_funcof( kbu) ==  (UINT8_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( kbi) ==   (INT8_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( khu) == (UINT16_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( khi) ==  (INT16_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( kwu) == (UINT32_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( kwi) ==  (INT32_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( kdu) == (UINT64_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof( kdi) ==  (INT64_NEGS)))  goto fail;
//  NEGSW=BWR
    if (!TASSERT(negs_funcof(vwbu) ==   (VWBU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vwbi) ==   (VWBI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vwhu) ==   (VWHU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vwhi) ==   (VWHI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vwwu) ==   (VWWU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vwwi) ==   (VWWI_NEGS)))  goto fail;
//  NEGSD=BDR
    if (!TASSERT(negs_funcof(vdbu) ==   (VDBU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vdbi) ==   (VDBI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vdhu) ==   (VDHU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vdhi) ==   (VDHI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vdwu) ==   (VDWU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vdwi) ==   (VDWI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vddu) ==   (VDDU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vddi) ==   (VDDI_NEGS)))  goto fail;
//  NEGSQ=BDR
    if (!TASSERT(negs_funcof(vqbu) ==   (VQBU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqbi) ==   (VQBI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqhu) ==   (VQHU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqhi) ==   (VQHI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqwu) ==   (VQWU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqwi) ==   (VQWI_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqdu) ==   (VQDU_NEGS)))  goto fail;
    if (!TASSERT(negs_funcof(vqdi) ==   (VQDI_NEGS)))  goto fail;
//  NEGH=YDR
    if (!TASSERT(negh_funcof( kbu) ==  (UINT8_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kbi) ==   (INT8_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( khu) == (UINT16_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( khi) ==  (INT16_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( khf) ==  (FLT16_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kwu) == (UINT32_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kwi) ==  (INT32_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kwf) ==    (FLT_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kdu) == (UINT64_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kdi) ==  (INT64_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof( kdf) ==    (DBL_NEGH)))  goto fail;
//  NEGHW=BHR
    if (!TASSERT(negh_funcof(vwbu) ==   (VWBU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vwbi) ==   (VWBI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vwhu) ==   (VWHU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vwhi) ==   (VWHI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vwhf) ==   (VWHF_NEGH)))  goto fail;
//  NEGHD=BWR
    if (!TASSERT(negh_funcof(vdbu) ==   (VDBU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdbi) ==   (VDBI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdhu) ==   (VDHU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdhi) ==   (VDHI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdhf) ==   (VDHF_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdwu) ==   (VDWU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdwi) ==   (VDWI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vdwf) ==   (VDWF_NEGH)))  goto fail;
//  NEGHQ=HDR
    if (!TASSERT(negh_funcof(vqhu) ==   (VQHU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqhi) ==   (VQHI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqhf) ==   (VQHF_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqwu) ==   (VQWU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqwi) ==   (VQWI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqwf) ==   (VQWF_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqdu) ==   (VQDU_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqdi) ==   (VQDI_NEGH)))  goto fail;
    if (!TASSERT(negh_funcof(vqdf) ==   (VQDF_NEGH)))  goto fail;
//  NEGW=YDR
    if (!TASSERT(negw_funcof( kyu) ==   (BOOL_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kbu) ==  (UINT8_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kbi) ==   (INT8_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( khu) == (UINT16_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( khi) ==  (INT16_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( khf) ==  (FLT16_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kwu) == (UINT32_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kwi) ==  (INT32_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kwf) ==    (FLT_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kdu) == (UINT64_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kdi) ==  (INT64_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof( kdf) ==    (DBL_NEGW)))  goto fail;
//  NEGWW=BWR
    if (!TASSERT(negw_funcof(vwbu) ==   (VWBU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwbi) ==   (VWBI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwhu) ==   (VWHU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwhi) ==   (VWHI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwhf) ==   (VWHF_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwwu) ==   (VWWU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwwi) ==   (VWWI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vwwf) ==   (VWWF_NEGW)))  goto fail;
//  NEGWD=HDR
    if (!TASSERT(negw_funcof(vdhu) ==   (VDHU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vdhi) ==   (VDHI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vdhf) ==   (VDHF_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vdwu) ==   (VDWU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vdwi) ==   (VDWI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vdwf) ==   (VDWF_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vddu) ==   (VDDU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vddi) ==   (VDDI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vddf) ==   (VDDF_NEGW)))  goto fail;
//  NEGWQ=WDR
    if (!TASSERT(negw_funcof(vqwu) ==   (VQWU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vqwi) ==   (VQWI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vqwf) ==   (VQWF_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vqdu) ==   (VQDU_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vqdi) ==   (VQDI_NEGW)))  goto fail;
    if (!TASSERT(negw_funcof(vqdf) ==   (VQDF_NEGW)))  goto fail;
//  NEGD=YDR
    if (!TASSERT(negd_funcof( kyu) ==   (BOOL_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kbu) ==  (UINT8_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kbi) ==   (INT8_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( khu) == (UINT16_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( khi) ==  (INT16_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( khf) ==  (FLT16_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kwu) == (UINT32_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kwi) ==  (INT32_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kwf) ==    (FLT_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kdu) == (UINT64_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kdi) ==  (INT64_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof( kdf) ==    (DBL_NEGD)))  goto fail;
//  NEGDW=HWR
    if (!TASSERT(negd_funcof(vwhu) ==   (VWHU_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vwhi) ==   (VWHI_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vwhf) ==   (VWHF_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vwwu) ==   (VWWU_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vwwi) ==   (VWWI_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vwwf) ==   (VWWF_NEGD)))  goto fail;
//  NEGDD=WDR
    if (!TASSERT(negd_funcof(vdwu) ==   (VDWU_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vdwi) ==   (VDWI_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vdwf) ==   (VDWF_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vddu) ==   (VDDU_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vddi) ==   (VDDI_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vddf) ==   (VDDF_NEGD)))  goto fail;
//  NEGDQ=DR
    if (!TASSERT(negd_funcof(vqdu) ==   (VQDU_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vqdi) ==   (VQDI_NEGD)))  goto fail;
    if (!TASSERT(negd_funcof(vqdf) ==   (VQDF_NEGD)))  goto fail;
    
#if 0 // leave neg_
}
#endif

#if 0 // enter orr_
{
#endif
//  ORRS=YDZ
    if (!TASSERT(orrs_funcof( kyu) ==   (BOOL_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( kbu) ==  (UINT8_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( kbi) ==   (INT8_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( khu) == (UINT16_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( khi) ==  (INT16_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( kwu) == (UINT32_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( kwi) ==  (INT32_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( kdu) == (UINT64_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof( kdi) ==  (INT64_ORRS)))  goto fail;
//  ORRSW=YWZ
    if (!TASSERT(orrs_funcof(vwyu) ==   (VWYU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vwbu) ==   (VWBU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vwbi) ==   (VWBI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vwhu) ==   (VWHU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vwhi) ==   (VWHI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vwwu) ==   (VWWU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vwwi) ==   (VWWI_ORRS)))  goto fail;
//  ORRSD=YDZ
    if (!TASSERT(orrs_funcof(vdyu) ==   (VDYU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vdbu) ==   (VDBU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vdbi) ==   (VDBI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vdhu) ==   (VDHU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vdhi) ==   (VDHI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vdwu) ==   (VDWU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vdwi) ==   (VDWI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vddu) ==   (VDDU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vddi) ==   (VDDI_ORRS)))  goto fail;
//  ORRSQ=YDZ
    if (!TASSERT(orrs_funcof(vqbu) ==   (VQBU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqyu) ==   (VQYU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqbu) ==   (VQBU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqbi) ==   (VQBI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqhu) ==   (VQHU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqhi) ==   (VQHI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqwu) ==   (VQWU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqwi) ==   (VQWI_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqdu) ==   (VQDU_ORRS)))  goto fail;
    if (!TASSERT(orrs_funcof(vqdi) ==   (VQDI_ORRS)))  goto fail;
//  ORRN=YDZ
    if (!TASSERT(orrn_funcof( kyu) ==   (BOOL_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( kbu) ==  (UINT8_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( kbi) ==   (INT8_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( khu) == (UINT16_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( khi) ==  (INT16_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( kwu) == (UINT32_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( kwi) ==  (INT32_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( kdu) == (UINT64_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof( kdi) ==  (INT64_ORRN)))  goto fail;
//  ORRNW=YWZ
    if (!TASSERT(orrn_funcof(vwyu) ==   (VWYU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vwbu) ==   (VWBU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vwbi) ==   (VWBI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vwhu) ==   (VWHU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vwhi) ==   (VWHI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vwwu) ==   (VWWU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vwwi) ==   (VWWI_ORRN)))  goto fail;
//  ORRND=YDZ
    if (!TASSERT(orrn_funcof(vdyu) ==   (VDYU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vdbu) ==   (VDBU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vdbi) ==   (VDBI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vdhu) ==   (VDHU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vdhi) ==   (VDHI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vdwu) ==   (VDWU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vdwi) ==   (VDWI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vddu) ==   (VDDU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vddi) ==   (VDDI_ORRN)))  goto fail;
//  ORRNQ=YDZ
    if (!TASSERT(orrn_funcof(vqyu) ==   (VQYU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqbu) ==   (VQBU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqyu) ==   (VQYU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqbu) ==   (VQBU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqbi) ==   (VQBI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqhu) ==   (VQHU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqhi) ==   (VQHI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqwu) ==   (VQWU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqwi) ==   (VQWI_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqdu) ==   (VQDU_ORRN)))  goto fail;
    if (!TASSERT(orrn_funcof(vqdi) ==   (VQDI_ORRN)))  goto fail;
//  ORR1A=YDZ
    if (!TASSERT(orr1_funcof(&kyu) ==   (BOOL_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&kbu) ==  (UINT8_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&kbi) ==   (INT8_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&khu) == (UINT16_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&khi) ==  (INT16_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&kwu) == (UINT32_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&kwi) ==  (INT32_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&kdu) == (UINT64_ORR1A))) goto fail;
    if (!TASSERT(orr1_funcof(&kdi) ==  (INT64_ORR1A))) goto fail;
//  ORRAA=YDZ
    if (!TASSERT(orra_funcof(&kyu) ==   (BOOL_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&kbu) ==  (UINT8_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&kbi) ==   (INT8_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&khu) == (UINT16_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&khi) ==  (INT16_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&kwu) == (UINT32_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&kwi) ==  (INT32_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&kdu) == (UINT64_ORRAA))) goto fail;
    if (!TASSERT(orra_funcof(&kdi) ==  (INT64_ORRAA))) goto fail;
//  ORREA=YDZ
    if (!TASSERT(orre_funcof(&kyu) ==   (BOOL_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&kbu) ==  (UINT8_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&kbi) ==   (INT8_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&khu) == (UINT16_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&khi) ==  (INT16_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&kwu) == (UINT32_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&kwi) ==  (INT32_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&kdu) == (UINT64_ORREA))) goto fail;
    if (!TASSERT(orre_funcof(&kdi) ==  (INT64_ORREA))) goto fail;
//  ORRTA=YDZ
    if (!TASSERT(orrt_funcof(&kyu) ==   (BOOL_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&kbu) ==  (UINT8_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&kbi) ==   (INT8_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&khu) == (UINT16_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&khi) ==  (INT16_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&kwu) == (UINT32_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&kwi) ==  (INT32_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&kdu) == (UINT64_ORRTA))) goto fail;
    if (!TASSERT(orrt_funcof(&kdi) ==  (INT64_ORRTA))) goto fail;
#if 0 // leave orr_
}
#endif

#if 0 // enter per_
{
#endif
//  PERS=NONE
//  PERSW=BHR
    if (!TASSERT(pers_funcof(vwbu) ==   (VWBU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vwbi) ==   (VWBI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vwhu) ==   (VWHU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vwhi) ==   (VWHI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vwhf) ==   (VWHF_PERS)))  goto fail;
//  PERSD=BWR
    if (!TASSERT(pers_funcof(vdbu) ==   (VDBU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdbi) ==   (VDBI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdhu) ==   (VDHU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdhi) ==   (VDHI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdhf) ==   (VDHF_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdwu) ==   (VDWU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdwi) ==   (VDWI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vdwf) ==   (VDWF_PERS)))  goto fail;
//  PERSQ=BDR
    if (!TASSERT(pers_funcof(vqbu) ==   (VQBU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqbi) ==   (VQBI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqhu) ==   (VQHU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqhi) ==   (VQHI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqhf) ==   (VQHF_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqwu) ==   (VQWU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqwi) ==   (VQWI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqwf) ==   (VQWF_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqdu) ==   (VQDU_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqdi) ==   (VQDI_PERS)))  goto fail;
    if (!TASSERT(pers_funcof(vqdf) ==   (VQDF_PERS)))  goto fail;
//  PERM=NONE
//  PERMW=BHR
    if (!TASSERT(perm_funcof(vwbu) ==   (VWBU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vwbi) ==   (VWBI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vwhu) ==   (VWHU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vwhi) ==   (VWHI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vwhf) ==   (VWHF_PERM)))  goto fail;
//  PERMD=BWR
    if (!TASSERT(perm_funcof(vdbu) ==   (VDBU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdbi) ==   (VDBI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdhu) ==   (VDHU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdhi) ==   (VDHI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdhf) ==   (VDHF_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdwu) ==   (VDWU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdwi) ==   (VDWI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vdwf) ==   (VDWF_PERM)))  goto fail;
//  PERMQ=BDR
    if (!TASSERT(perm_funcof(vqbu) ==   (VQBU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqbi) ==   (VQBI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqhu) ==   (VQHU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqhi) ==   (VQHI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqhf) ==   (VQHF_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqwu) ==   (VQWU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqwi) ==   (VQWI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqwf) ==   (VQWF_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqdu) ==   (VQDU_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqdi) ==   (VQDI_PERM)))  goto fail;
    if (!TASSERT(perm_funcof(vqdf) ==   (VQDF_PERM)))  goto fail;
#if 0 // leave per_
}
#endif

#if 0 // enter rev_
{
#endif
//  REVY=BDZ
    if (!TASSERT(revy_funcof( kbu) ==  (UINT8_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( kbi) ==   (INT8_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( khu) == (UINT16_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( khi) ==  (INT16_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( kwu) == (UINT32_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( kwi) ==  (INT32_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( kdu) == (UINT64_REVY)))  goto fail;
    if (!TASSERT(revy_funcof( kdi) ==  (INT64_REVY)))  goto fail;
//  REVYW=BWZ
    if (!TASSERT(revy_funcof(vwbu) ==   (VWBU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vwbi) ==   (VWBI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vwhu) ==   (VWHU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vwhi) ==   (VWHI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vwwu) ==   (VWWU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vwwi) ==   (VWWI_REVY)))  goto fail;
//  REVYD=BDZ
    if (!TASSERT(revy_funcof(vdbu) ==   (VDBU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vdbi) ==   (VDBI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vdhu) ==   (VDHU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vdhi) ==   (VDHI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vdwu) ==   (VDWU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vdwi) ==   (VDWI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vddu) ==   (VDDU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vddi) ==   (VDDI_REVY)))  goto fail;
//  REVYQ=BDZ
    if (!TASSERT(revy_funcof(vqbu) ==   (VQBU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqbi) ==   (VQBI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqhu) ==   (VQHU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqhi) ==   (VQHI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqwu) ==   (VQWU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqwi) ==   (VQWI_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqdu) ==   (VQDU_REVY)))  goto fail;
    if (!TASSERT(revy_funcof(vqdi) ==   (VQDI_REVY)))  goto fail;
//  REVSW=YHR
    if (!TASSERT(revs_funcof(vwyu) ==   (VWYU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vwbu) ==   (VWBU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vwbi) ==   (VWBI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vwhu) ==   (VWHU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vwhi) ==   (VWHI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vwhf) ==   (VWHF_REVS)))  goto fail;
//  REVSD=YWR
    if (!TASSERT(revs_funcof(vdyu) ==   (VDYU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdbu) ==   (VDBU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdbi) ==   (VDBI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdhu) ==   (VDHU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdhi) ==   (VDHI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdhf) ==   (VDHF_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdwu) ==   (VDWU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdwi) ==   (VDWI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vdwf) ==   (VDWF_REVS)))  goto fail;
//  REVSQ=YDR
    if (!TASSERT(revs_funcof(vqyu) ==   (VQYU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqbu) ==   (VQBU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqbi) ==   (VQBI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqhu) ==   (VQHU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqhi) ==   (VQHI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqhf) ==   (VQHF_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqwu) ==   (VQWU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqwi) ==   (VQWI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqwf) ==   (VQWF_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqdu) ==   (VQDU_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqdi) ==   (VQDI_REVS)))  goto fail;
    if (!TASSERT(revs_funcof(vqdf) ==   (VQDF_REVS)))  goto fail;
//  REVB=HDR
    if (!TASSERT(revb_funcof( khu) == (UINT16_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( khi) ==  (INT16_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( khf) ==  (FLT16_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( kwu) == (UINT32_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( kwi) ==  (INT32_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( kwf) ==    (FLT_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( kdu) == (UINT64_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( kdi) ==  (INT64_REVB)))  goto fail;
    if (!TASSERT(revb_funcof( kdf) ==    (DBL_REVB)))  goto fail;
//  REVBW=HWR
    if (!TASSERT(revb_funcof(vwhu) ==   (VWHU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vwhi) ==   (VWHI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vwhf) ==   (VWHF_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vwwu) ==   (VWWU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vwwi) ==   (VWWI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vwwf) ==   (VWWF_REVB)))  goto fail;
//  REVBD=HDR
    if (!TASSERT(revb_funcof(vdhu) ==   (VDHU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vdhi) ==   (VDHI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vdhf) ==   (VDHF_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vdwu) ==   (VDWU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vdwi) ==   (VDWI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vdwf) ==   (VDWF_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vddu) ==   (VDDU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vddi) ==   (VDDI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vddf) ==   (VDDF_REVB)))  goto fail;
//  REVBQ=HDR
    if (!TASSERT(revb_funcof(vqhu) ==   (VQHU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqhi) ==   (VQHI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqhf) ==   (VQHF_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqwu) ==   (VQWU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqwi) ==   (VQWI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqwf) ==   (VQWF_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqdu) ==   (VQDU_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqdi) ==   (VQDI_REVB)))  goto fail;
    if (!TASSERT(revb_funcof(vqdf) ==   (VQDF_REVB)))  goto fail;
//  REVH=WDR
    if (!TASSERT(revh_funcof( kwu) == (UINT32_REVH)))  goto fail;
    if (!TASSERT(revh_funcof( kwi) ==  (INT32_REVH)))  goto fail;
    if (!TASSERT(revh_funcof( kwf) ==    (FLT_REVH)))  goto fail;
    if (!TASSERT(revh_funcof( kdu) == (UINT64_REVH)))  goto fail;
    if (!TASSERT(revh_funcof( kdi) ==  (INT64_REVH)))  goto fail;
    if (!TASSERT(revh_funcof( kdf) ==    (DBL_REVH)))  goto fail;
//  REVHW=WR
    if (!TASSERT(revh_funcof(vwwu) ==   (VWWU_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vwwi) ==   (VWWI_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vwwf) ==   (VWWF_REVH)))  goto fail;
//  REVHD=WDR
    if (!TASSERT(revh_funcof(vdwu) ==   (VDWU_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vdwi) ==   (VDWI_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vdwf) ==   (VDWF_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vddu) ==   (VDDU_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vddi) ==   (VDDI_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vddf) ==   (VDDF_REVH)))  goto fail;
//  REVHQ=WDR
    if (!TASSERT(revh_funcof(vqwu) ==   (VQWU_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vqwi) ==   (VQWI_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vqwf) ==   (VQWF_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vqdu) ==   (VQDU_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vqdi) ==   (VQDI_REVH)))  goto fail;
    if (!TASSERT(revh_funcof(vqdf) ==   (VQDF_REVH)))  goto fail;
#if 0 // leave rev_
}
#endif

#if 0 // enter raz_
{
#endif
//  RAZB=BDF
    if (!TASSERT(razb_funcof( khf) ==  (FLT16_RAZB)))  goto fail;
    if (!TASSERT(razb_funcof( kwf) ==    (FLT_RAZB)))  goto fail;
    if (!TASSERT(razb_funcof( kdf) ==    (DBL_RAZB)))  goto fail;
//  RAZBW=NONE
//  RAZBD=HF
    if (!TASSERT(razb_funcof(vdhf) ==   (VDHF_RAZB)))  goto fail;
//  RAZBQ=BWF
    if (!TASSERT(razb_funcof(vqhf) ==   (VQHF_RAZB)))  goto fail;
    if (!TASSERT(razb_funcof(vqwf) ==   (VQWF_RAZB)))  goto fail;
//  RAZH=BDF
    if (!TASSERT(razh_funcof( khf) ==  (FLT16_RAZH)))  goto fail;
    if (!TASSERT(razh_funcof( kwf) ==    (FLT_RAZH)))  goto fail;
    if (!TASSERT(razh_funcof( kdf) ==    (DBL_RAZH)))  goto fail;
//  RAZHW=BHF
    if (!TASSERT(razh_funcof(vwhf) ==   (VWHF_RAZH)))  goto fail;
//  RAZHD=BWF
    if (!TASSERT(razh_funcof(vdhf) ==   (VDHF_RAZH)))  goto fail;
    if (!TASSERT(razh_funcof(vdwf) ==   (VDWF_RAZH)))  goto fail;
//  RAZHQ=BDF
    if (!TASSERT(razh_funcof(vqhf) ==   (VQHF_RAZH)))  goto fail;
    if (!TASSERT(razh_funcof(vqwf) ==   (VQWF_RAZH)))  goto fail;
    if (!TASSERT(razh_funcof(vqdf) ==   (VQDF_RAZH)))  goto fail;
//  RAZW=BDF
    if (!TASSERT(razw_funcof( khf) ==  (FLT16_RAZW)))  goto fail;
    if (!TASSERT(razw_funcof( kwf) ==    (FLT_RAZW)))  goto fail;
    if (!TASSERT(razw_funcof( kdf) ==    (DBL_RAZW)))  goto fail;
//  RAZWW=BWF
    if (!TASSERT(razw_funcof(vwhf) ==   (VWHF_RAZW)))  goto fail;
    if (!TASSERT(razw_funcof(vwwf) ==   (VWWF_RAZW)))  goto fail;
//  RAZWD=HDF
    if (!TASSERT(razw_funcof(vdhf) ==   (VDHF_RAZW)))  goto fail;
    if (!TASSERT(razw_funcof(vdwf) ==   (VDWF_RAZW)))  goto fail;
    if (!TASSERT(razw_funcof(vddf) ==   (VDDF_RAZW)))  goto fail;
//  RAZWQ=WDF
    if (!TASSERT(razw_funcof(vqwf) ==   (VQWF_RAZW)))  goto fail;
    if (!TASSERT(razw_funcof(vqdf) ==   (VQDF_RAZW)))  goto fail;
//  RAZD=BDF
    if (!TASSERT(razd_funcof( khf) ==  (FLT16_RAZD)))  goto fail;
    if (!TASSERT(razd_funcof( kwf) ==    (FLT_RAZD)))  goto fail;
    if (!TASSERT(razd_funcof( kdf) ==    (DBL_RAZD)))  goto fail;
//  RAZDW=HWF
    if (!TASSERT(razd_funcof(vwhf) ==   (VWHF_RAZD)))  goto fail;
    if (!TASSERT(razd_funcof(vwwf) ==   (VWWF_RAZD)))  goto fail;
//  RAZDD=WDF
    if (!TASSERT(razd_funcof(vdwf) ==   (VDWF_RAZD)))  goto fail;
    if (!TASSERT(razd_funcof(vddf) ==   (VDDF_RAZD)))  goto fail;
//  RAZDQ=DF
    if (!TASSERT(razd_funcof(vqdf) ==   (VQDF_RAZD)))  goto fail;
//  RAZF=BDF
    if (!TASSERT(razf_funcof( khf) ==  (FLT16_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof( kwf) ==    (FLT_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof( kdf) ==    (DBL_RAZF)))  goto fail;
//  RAZFW=BWF
    if (!TASSERT(razf_funcof(vwhf) ==   (VWHF_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof(vwwf) ==   (VWWF_RAZF)))  goto fail;
//  RAZFD=BDF
    if (!TASSERT(razf_funcof(vdhf) ==   (VDHF_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof(vdwf) ==   (VDWF_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof(vddf) ==   (VDDF_RAZF)))  goto fail;
//  RAZFQ=BDF
    if (!TASSERT(razf_funcof(vqhf) ==   (VQHF_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof(vqwf) ==   (VQWF_RAZF)))  goto fail;
    if (!TASSERT(razf_funcof(vqdf) ==   (VQDF_RAZF)))  goto fail;
#if 0 // leave raz_
}
#endif

#if 0 // enter rtn_
{
#endif
//  RTNB=BDF
    if (!TASSERT(rtnb_funcof( khf) ==  (FLT16_RTNB)))  goto fail;
    if (!TASSERT(rtnb_funcof( kwf) ==    (FLT_RTNB)))  goto fail;
    if (!TASSERT(rtnb_funcof( kdf) ==    (DBL_RTNB)))  goto fail;
//  RTNBW=NONE
//  RTNBD=HF
    if (!TASSERT(rtnb_funcof(vdhf) ==   (VDHF_RTNB)))  goto fail;
//  RTNBQ=BWF
    if (!TASSERT(rtnb_funcof(vqhf) ==   (VQHF_RTNB)))  goto fail;
    if (!TASSERT(rtnb_funcof(vqwf) ==   (VQWF_RTNB)))  goto fail;
//  RTNH=BDF
    if (!TASSERT(rtnh_funcof( khf) ==  (FLT16_RTNH)))  goto fail;
    if (!TASSERT(rtnh_funcof( kwf) ==    (FLT_RTNH)))  goto fail;
    if (!TASSERT(rtnh_funcof( kdf) ==    (DBL_RTNH)))  goto fail;
//  RTNHW=BHF
    if (!TASSERT(rtnh_funcof(vwhf) ==   (VWHF_RTNH)))  goto fail;
//  RTNHD=BWF
    if (!TASSERT(rtnh_funcof(vdhf) ==   (VDHF_RTNH)))  goto fail;
    if (!TASSERT(rtnh_funcof(vdwf) ==   (VDWF_RTNH)))  goto fail;
//  RTNHQ=BDF
    if (!TASSERT(rtnh_funcof(vqhf) ==   (VQHF_RTNH)))  goto fail;
    if (!TASSERT(rtnh_funcof(vqwf) ==   (VQWF_RTNH)))  goto fail;
    if (!TASSERT(rtnh_funcof(vqdf) ==   (VQDF_RTNH)))  goto fail;
//  RTNW=BDF
    if (!TASSERT(rtnw_funcof( khf) ==  (FLT16_RTNW)))  goto fail;
    if (!TASSERT(rtnw_funcof( kwf) ==    (FLT_RTNW)))  goto fail;
    if (!TASSERT(rtnw_funcof( kdf) ==    (DBL_RTNW)))  goto fail;
//  RTNWW=BWF
    if (!TASSERT(rtnw_funcof(vwhf) ==   (VWHF_RTNW)))  goto fail;
    if (!TASSERT(rtnw_funcof(vwwf) ==   (VWWF_RTNW)))  goto fail;
//  RTNWD=HDF
    if (!TASSERT(rtnw_funcof(vdhf) ==   (VDHF_RTNW)))  goto fail;
    if (!TASSERT(rtnw_funcof(vdwf) ==   (VDWF_RTNW)))  goto fail;
    if (!TASSERT(rtnw_funcof(vddf) ==   (VDDF_RTNW)))  goto fail;
//  RTNWQ=WDF
    if (!TASSERT(rtnw_funcof(vqwf) ==   (VQWF_RTNW)))  goto fail;
    if (!TASSERT(rtnw_funcof(vqdf) ==   (VQDF_RTNW)))  goto fail;
//  RTND=BDF
    if (!TASSERT(rtnd_funcof( khf) ==  (FLT16_RTND)))  goto fail;
    if (!TASSERT(rtnd_funcof( kwf) ==    (FLT_RTND)))  goto fail;
    if (!TASSERT(rtnd_funcof( kdf) ==    (DBL_RTND)))  goto fail;
//  RTNDW=HWF
    if (!TASSERT(rtnd_funcof(vwhf) ==   (VWHF_RTND)))  goto fail;
    if (!TASSERT(rtnd_funcof(vwwf) ==   (VWWF_RTND)))  goto fail;
//  RTNDD=WDF
    if (!TASSERT(rtnd_funcof(vdwf) ==   (VDWF_RTND)))  goto fail;
    if (!TASSERT(rtnd_funcof(vddf) ==   (VDDF_RTND)))  goto fail;
//  RTNDQ=DF
    if (!TASSERT(rtnd_funcof(vqdf) ==   (VQDF_RTND)))  goto fail;
//  RTNF=BDF
    if (!TASSERT(rtnf_funcof( khf) ==  (FLT16_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof( kwf) ==    (FLT_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof( kdf) ==    (DBL_RTNF)))  goto fail;
//  RTNFW=BWF
    if (!TASSERT(rtnf_funcof(vwhf) ==   (VWHF_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof(vwwf) ==   (VWWF_RTNF)))  goto fail;
//  RTNFD=BDF
    if (!TASSERT(rtnf_funcof(vdhf) ==   (VDHF_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof(vdwf) ==   (VDWF_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof(vddf) ==   (VDDF_RTNF)))  goto fail;
//  RTNFQ=BDF
    if (!TASSERT(rtnf_funcof(vqhf) ==   (VQHF_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof(vqwf) ==   (VQWF_RTNF)))  goto fail;
    if (!TASSERT(rtnf_funcof(vqdf) ==   (VQDF_RTNF)))  goto fail;
#if 0 // leave rtn_
}
#endif

#if 0 // enter rtp_
{
#endif
//  RTPB=BDF
    if (!TASSERT(rtpb_funcof( khf) ==  (FLT16_RTPB)))  goto fail;
    if (!TASSERT(rtpb_funcof( kwf) ==    (FLT_RTPB)))  goto fail;
    if (!TASSERT(rtpb_funcof( kdf) ==    (DBL_RTPB)))  goto fail;
//  RTPBW=NONE
//  RTPBD=HF
    if (!TASSERT(rtpb_funcof(vdhf) ==   (VDHF_RTPB)))  goto fail;
//  RTPBQ=BWF
    if (!TASSERT(rtpb_funcof(vqhf) ==   (VQHF_RTPB)))  goto fail;
    if (!TASSERT(rtpb_funcof(vqwf) ==   (VQWF_RTPB)))  goto fail;
//  RTPH=BDF
    if (!TASSERT(rtph_funcof( khf) ==  (FLT16_RTPH)))  goto fail;
    if (!TASSERT(rtph_funcof( kwf) ==    (FLT_RTPH)))  goto fail;
    if (!TASSERT(rtph_funcof( kdf) ==    (DBL_RTPH)))  goto fail;
//  RTPHW=BHF
    if (!TASSERT(rtph_funcof(vwhf) ==   (VWHF_RTPH)))  goto fail;
//  RTPHD=BWF
    if (!TASSERT(rtph_funcof(vdhf) ==   (VDHF_RTPH)))  goto fail;
    if (!TASSERT(rtph_funcof(vdwf) ==   (VDWF_RTPH)))  goto fail;
//  RTPHQ=BDF
    if (!TASSERT(rtph_funcof(vqhf) ==   (VQHF_RTPH)))  goto fail;
    if (!TASSERT(rtph_funcof(vqwf) ==   (VQWF_RTPH)))  goto fail;
    if (!TASSERT(rtph_funcof(vqdf) ==   (VQDF_RTPH)))  goto fail;
//  RTPW=BDF
    if (!TASSERT(rtpw_funcof( khf) ==  (FLT16_RTPW)))  goto fail;
    if (!TASSERT(rtpw_funcof( kwf) ==    (FLT_RTPW)))  goto fail;
    if (!TASSERT(rtpw_funcof( kdf) ==    (DBL_RTPW)))  goto fail;
//  RTPWW=BWF
    if (!TASSERT(rtpw_funcof(vwhf) ==   (VWHF_RTPW)))  goto fail;
    if (!TASSERT(rtpw_funcof(vwwf) ==   (VWWF_RTPW)))  goto fail;
//  RTPWD=HDF
    if (!TASSERT(rtpw_funcof(vdhf) ==   (VDHF_RTPW)))  goto fail;
    if (!TASSERT(rtpw_funcof(vdwf) ==   (VDWF_RTPW)))  goto fail;
    if (!TASSERT(rtpw_funcof(vddf) ==   (VDDF_RTPW)))  goto fail;
//  RTPWQ=WDF
    if (!TASSERT(rtpw_funcof(vqwf) ==   (VQWF_RTPW)))  goto fail;
    if (!TASSERT(rtpw_funcof(vqdf) ==   (VQDF_RTPW)))  goto fail;
//  RTPD=BDF
    if (!TASSERT(rtpd_funcof( khf) ==  (FLT16_RTPD)))  goto fail;
    if (!TASSERT(rtpd_funcof( kwf) ==    (FLT_RTPD)))  goto fail;
    if (!TASSERT(rtpd_funcof( kdf) ==    (DBL_RTPD)))  goto fail;
//  RTPDW=HWF
    if (!TASSERT(rtpd_funcof(vwhf) ==   (VWHF_RTPD)))  goto fail;
    if (!TASSERT(rtpd_funcof(vwwf) ==   (VWWF_RTPD)))  goto fail;
//  RTPDD=WDF
    if (!TASSERT(rtpd_funcof(vdwf) ==   (VDWF_RTPD)))  goto fail;
    if (!TASSERT(rtpd_funcof(vddf) ==   (VDDF_RTPD)))  goto fail;
//  RTPDQ=DF
    if (!TASSERT(rtpd_funcof(vqdf) ==   (VQDF_RTPD)))  goto fail;
//  RTPF=BDF
    if (!TASSERT(rtpf_funcof( khf) ==  (FLT16_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof( kwf) ==    (FLT_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof( kdf) ==    (DBL_RTPF)))  goto fail;
//  RTPFW=BWF
    if (!TASSERT(rtpf_funcof(vwhf) ==   (VWHF_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof(vwwf) ==   (VWWF_RTPF)))  goto fail;
//  RTPFD=BDF
    if (!TASSERT(rtpf_funcof(vdhf) ==   (VDHF_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof(vdwf) ==   (VDWF_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof(vddf) ==   (VDDF_RTPF)))  goto fail;
//  RTPFQ=BDF
    if (!TASSERT(rtpf_funcof(vqhf) ==   (VQHF_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof(vqwf) ==   (VQWF_RTPF)))  goto fail;
    if (!TASSERT(rtpf_funcof(vqdf) ==   (VQDF_RTPF)))  goto fail;
#if 0 // leave rtp_
}
#endif

#if 0 // enter rot_
{
#endif
//  ROTL=BDU
    if (!TASSERT(rotl_funcof( kbu) ==  (UINT8_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof( khu) == (UINT16_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof( kwu) == (UINT32_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof( kdu) == (UINT64_ROTL)))  goto fail;
//  ROTLW=BWU
    if (!TASSERT(rotl_funcof(vwbu) ==   (VWBU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vwhu) ==   (VWHU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vwwu) ==   (VWWU_ROTL)))  goto fail;
//  ROTLD=BDU
    if (!TASSERT(rotl_funcof(vdbu) ==   (VDBU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vdhu) ==   (VDHU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vdwu) ==   (VDWU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vddu) ==   (VDDU_ROTL)))  goto fail;
//  ROTLQ=BDU
    if (!TASSERT(rotl_funcof(vqbu) ==   (VQBU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vqhu) ==   (VQHU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vqwu) ==   (VQWU_ROTL)))  goto fail;
    if (!TASSERT(rotl_funcof(vqdu) ==   (VQDU_ROTL)))  goto fail;
    if (!TASSERT(rotr_funcof( kbu) ==  (UINT8_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof( khu) == (UINT16_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof( kwu) == (UINT32_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof( kdu) == (UINT64_ROTR)))  goto fail;
//  ROTRW=BWU
    if (!TASSERT(rotr_funcof(vwbu) ==   (VWBU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vwhu) ==   (VWHU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vwwu) ==   (VWWU_ROTR)))  goto fail;
//  ROTRD=BDU
    if (!TASSERT(rotr_funcof(vdbu) ==   (VDBU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vdhu) ==   (VDHU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vdwu) ==   (VDWU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vddu) ==   (VDDU_ROTR)))  goto fail;
//  ROTRQ=BDU
    if (!TASSERT(rotr_funcof(vqbu) ==   (VQBU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vqhu) ==   (VQHU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vqwu) ==   (VQWU_ROTR)))  goto fail;
    if (!TASSERT(rotr_funcof(vqdu) ==   (VQDU_ROTR)))  goto fail;
#if 0 // leave rot_
}
#endif

#if 0 // enter rov_
{
#endif
//  ROVL=NONE
//  ROVLW=BWU
    if (!TASSERT(rovl_funcof(vwbu) ==   (VWBU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vwhu) ==   (VWHU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vwwu) ==   (VWWU_ROVL)))  goto fail;
//  ROVLD=BDU
    if (!TASSERT(rovl_funcof(vdbu) ==   (VDBU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vdhu) ==   (VDHU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vdwu) ==   (VDWU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vddu) ==   (VDDU_ROVL)))  goto fail;
//  ROVLQ=BDU
    if (!TASSERT(rovl_funcof(vqbu) ==   (VQBU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vqhu) ==   (VQHU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vqwu) ==   (VQWU_ROVL)))  goto fail;
    if (!TASSERT(rovl_funcof(vqdu) ==   (VQDU_ROVL)))  goto fail;
//  ROVR=NONE
//  ROVRW=BWU
    if (!TASSERT(rovr_funcof(vwbu) ==   (VWBU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vwhu) ==   (VWHU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vwwu) ==   (VWWU_ROVR)))  goto fail;
//  ROVRD=BDU
    if (!TASSERT(rovr_funcof(vdbu) ==   (VDBU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vdhu) ==   (VDHU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vdwu) ==   (VDWU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vddu) ==   (VDDU_ROVR)))  goto fail;
//  ROVRQ=BDU
    if (!TASSERT(rovr_funcof(vqbu) ==   (VQBU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vqhu) ==   (VQHU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vqwu) ==   (VQWU_ROVR)))  goto fail;
    if (!TASSERT(rovr_funcof(vqdu) ==   (VQDU_ROVR)))  goto fail;
#if 0 // leave rov_
}
#endif

#if 0 // enter seq_
{
#endif
//  SEQW=BHZ
    if (!TASSERT(seqw_funcof( kbu) ==  (UINT8_SEQW)))  goto fail;
    if (!TASSERT(seqw_funcof( kbi) ==   (INT8_SEQW)))  goto fail;
    if (!TASSERT(seqw_funcof( khu) == (UINT16_SEQW)))  goto fail;
    if (!TASSERT(seqw_funcof( khi) ==  (INT16_SEQW)))  goto fail;
//  SEQWW=NONE
//  SEQWD=NONE
//  SEQWQ=NONE
//  SEQD=BWZ
    if (!TASSERT(seqd_funcof( kbu) ==  (UINT8_SEQD)))  goto fail;
    if (!TASSERT(seqd_funcof( kbi) ==   (INT8_SEQD)))  goto fail;
    if (!TASSERT(seqd_funcof( khu) == (UINT16_SEQD)))  goto fail;
    if (!TASSERT(seqd_funcof( khi) ==  (INT16_SEQD)))  goto fail;
    if (!TASSERT(seqd_funcof( kwu) == (UINT32_SEQD)))  goto fail;
    if (!TASSERT(seqd_funcof( kwi) ==  (INT32_SEQD)))  goto fail;
//  SEQDW=NONE
//  SEQDD=NONE
//  SEQDQ=NONE
//  SEQQ=BDZ
    if (!TASSERT(seqq_funcof( kbu) ==  (UINT8_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( kbi) ==   (INT8_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( khu) == (UINT16_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( khi) ==  (INT16_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( kwu) == (UINT32_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( kwi) ==  (INT32_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( kdu) == (UINT64_SEQQ)))  goto fail;
    if (!TASSERT(seqq_funcof( kdi) ==  (INT64_SEQQ)))  goto fail;
//  SEQQW=NONE
//  SEQQD=NONE
//  SEQQQ=NONE
#if 0 // leave seq_
}
#endif

#if 0 // enter set_
{
#endif
//  SET1=NONE
//  SET1W=YHR
    if (!TASSERT(set1_funcof(vwyu) ==   (VWYU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vwbi) ==   (VWBI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vwhu) ==   (VWHU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vwhi) ==   (VWHI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vwhf) ==   (VWHF_SET1)))  goto fail;
//  SET1D=YWR
    if (!TASSERT(set1_funcof(vdyu) ==   (VDYU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdbi) ==   (VDBI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdhu) ==   (VDHU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdhi) ==   (VDHI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdhf) ==   (VDHF_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdwu) ==   (VDWU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdwi) ==   (VDWI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vdwf) ==   (VDWF_SET1)))  goto fail;
//  SET1Q=YDR
    if (!TASSERT(set1_funcof(vqyu) ==   (VQYU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqbu) ==   (VQBU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqbi) ==   (VQBI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqhu) ==   (VQHU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqhi) ==   (VQHI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqhf) ==   (VQHF_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqwu) ==   (VQWU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqwi) ==   (VQWI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqwf) ==   (VQWF_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqdu) ==   (VQDU_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqdi) ==   (VQDI_SET1)))  goto fail;
    if (!TASSERT(set1_funcof(vqdf) ==   (VQDF_SET1)))  goto fail;
//  SETL=HDZ
    if (!TASSERT(setl_funcof( khu) == (UINT16_SETL)))  goto fail;
    if (!TASSERT(setl_funcof( khi) ==  (INT16_SETL)))  goto fail;
    if (!TASSERT(setl_funcof( kwu) == (UINT32_SETL)))  goto fail;
    if (!TASSERT(setl_funcof( kwi) ==  (INT32_SETL)))  goto fail;
    if (!TASSERT(setl_funcof( kdu) == (UINT64_SETL)))  goto fail;
    if (!TASSERT(setl_funcof( kdi) ==  (INT64_SETL)))  goto fail;
//  SETLW=NONE
//  SETLD=YWR
    if (!TASSERT(setl_funcof(vdyu) ==   (VDYU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdbi) ==   (VDBI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdhu) ==   (VDHU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdhi) ==   (VDHI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdhf) ==   (VDHF_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdwu) ==   (VDWU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdwi) ==   (VDWI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vdwf) ==   (VDWF_SETL)))  goto fail;
//  SETLQ=YDR
    if (!TASSERT(setl_funcof(vqyu) ==   (VQYU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqbu) ==   (VQBU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqbi) ==   (VQBI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqhu) ==   (VQHU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqhi) ==   (VQHI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqhf) ==   (VQHF_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqwu) ==   (VQWU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqwi) ==   (VQWI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqwf) ==   (VQWF_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqdu) ==   (VQDU_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqdi) ==   (VQDI_SETL)))  goto fail;
    if (!TASSERT(setl_funcof(vqdf) ==   (VQDF_SETL)))  goto fail;
//  SETR=HDZ
    if (!TASSERT(setr_funcof( khu) == (UINT16_SETR)))  goto fail;
    if (!TASSERT(setr_funcof( khi) ==  (INT16_SETR)))  goto fail;
    if (!TASSERT(setr_funcof( kwu) == (UINT32_SETR)))  goto fail;
    if (!TASSERT(setr_funcof( kwi) ==  (INT32_SETR)))  goto fail;
    if (!TASSERT(setr_funcof( kdu) == (UINT64_SETR)))  goto fail;
    if (!TASSERT(setr_funcof( kdi) ==  (INT64_SETR)))  goto fail;
//  SETRW=NONE
//  SETRD=YWR
    if (!TASSERT(setr_funcof(vdyu) ==   (VDYU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdbi) ==   (VDBI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdhu) ==   (VDHU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdhi) ==   (VDHI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdhf) ==   (VDHF_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdwu) ==   (VDWU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdwi) ==   (VDWI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vdwf) ==   (VDWF_SETR)))  goto fail;
//  SETRQ=YDR
    if (!TASSERT(setr_funcof(vqyu) ==   (VQYU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqbu) ==   (VQBU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqbi) ==   (VQBI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqhu) ==   (VQHU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqhi) ==   (VQHI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqhf) ==   (VQHF_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqwu) ==   (VQWU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqwi) ==   (VQWI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqwf) ==   (VQWF_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqdu) ==   (VQDU_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqdi) ==   (VQDI_SETR)))  goto fail;
    if (!TASSERT(setr_funcof(vqdf) ==   (VQDF_SETR)))  goto fail;
#if 0 // leave set_
}
#endif

#if 0 // enter shl_
{
#endif
//  SHLL=YDZ
    if (!TASSERT(shll_funcof( kyu) ==   (BOOL_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( kbu) ==  (UINT8_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( kbi) ==   (INT8_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( khu) == (UINT16_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( khi) ==  (INT16_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( kwu) == (UINT32_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( kwi) ==  (INT32_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( kdu) == (UINT64_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof( kdi) ==  (INT64_SHLL)))  goto fail;
//  SHLLW=YWZ
    if (!TASSERT(shll_funcof(vwyu) ==   (VWYU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vwbu) ==   (VWBU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vwbi) ==   (VWBI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vwhu) ==   (VWHU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vwhi) ==   (VWHI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vwwu) ==   (VWWU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vwwi) ==   (VWWI_SHLL)))  goto fail;
//  SHLLD=YDZ
    if (!TASSERT(shll_funcof(vdyu) ==   (VDYU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vdbu) ==   (VDBU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vdbi) ==   (VDBI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vdhu) ==   (VDHU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vdhi) ==   (VDHI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vdwu) ==   (VDWU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vdwi) ==   (VDWI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vddu) ==   (VDDU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vddi) ==   (VDDI_SHLL)))  goto fail;
//  SHLLQ=YDZ
    if (!TASSERT(shll_funcof(vqyu) ==   (VQYU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqbu) ==   (VQBU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqbi) ==   (VQBI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqhu) ==   (VQHU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqhi) ==   (VQHI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqwu) ==   (VQWU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqwi) ==   (VQWI_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqdu) ==   (VQDU_SHLL)))  goto fail;
    if (!TASSERT(shll_funcof(vqdi) ==   (VQDI_SHLL)))  goto fail;
//  SHLS=BDZ
    if (!TASSERT(shls_funcof( kbu) ==  (UINT8_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( kbi) ==   (INT8_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( khu) == (UINT16_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( khi) ==  (INT16_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( kwu) == (UINT32_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( kwi) ==  (INT32_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( kdu) == (UINT64_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof( kdi) ==  (INT64_SHLS)))  goto fail;
//  SHLSW=BWZ
    if (!TASSERT(shls_funcof(vwbu) ==   (VWBU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vwbi) ==   (VWBI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vwhu) ==   (VWHU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vwhi) ==   (VWHI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vwwu) ==   (VWWU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vwwi) ==   (VWWI_SHLS)))  goto fail;
//  SHLSD=BDZ
    if (!TASSERT(shls_funcof(vdbu) ==   (VDBU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vdbi) ==   (VDBI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vdhu) ==   (VDHU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vdhi) ==   (VDHI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vdwu) ==   (VDWU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vdwi) ==   (VDWI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vddu) ==   (VDDU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vddi) ==   (VDDI_SHLS)))  goto fail;
//  SHLSQ=BDZ
    if (!TASSERT(shls_funcof(vqbu) ==   (VQBU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqbi) ==   (VQBI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqhu) ==   (VQHU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqhi) ==   (VQHI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqwu) ==   (VQWU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqwi) ==   (VQWI_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqdu) ==   (VQDU_SHLS)))  goto fail;
    if (!TASSERT(shls_funcof(vqdi) ==   (VQDI_SHLS)))  goto fail;
//  SHLR=YDZ
    if (!TASSERT(shlr_funcof( kyu) ==   (BOOL_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( kbu) ==  (UINT8_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( kbi) ==   (INT8_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( khu) == (UINT16_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( khi) ==  (INT16_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( kwu) == (UINT32_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( kwi) ==  (INT32_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( kdu) == (UINT64_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof( kdi) ==  (INT64_SHLR)))  goto fail;
//  SHLRW=YWZ
    if (!TASSERT(shlr_funcof(vwyu) ==   (VWYU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vwbu) ==   (VWBU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vwbi) ==   (VWBI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vwhu) ==   (VWHU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vwhi) ==   (VWHI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vwwu) ==   (VWWU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vwwi) ==   (VWWI_SHLR)))  goto fail;
//  SHLRD=YDZ
    if (!TASSERT(shlr_funcof(vdyu) ==   (VDYU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vdbu) ==   (VDBU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vdbi) ==   (VDBI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vdhu) ==   (VDHU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vdhi) ==   (VDHI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vdwu) ==   (VDWU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vdwi) ==   (VDWI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vddu) ==   (VDDU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vddi) ==   (VDDI_SHLR)))  goto fail;
//  SHLRQ=YDZ
    if (!TASSERT(shlr_funcof(vqyu) ==   (VQYU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqbu) ==   (VQBU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqbi) ==   (VQBI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqhu) ==   (VQHU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqhi) ==   (VQHI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqwu) ==   (VQWU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqwi) ==   (VQWI_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqdu) ==   (VQDU_SHLR)))  goto fail;
    if (!TASSERT(shlr_funcof(vqdi) ==   (VQDI_SHLR)))  goto fail;
//  SHL2=BWZ
    if (!TASSERT(shl2_funcof( kbu) ==  (UINT8_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof( kbi) ==   (INT8_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof( khu) == (UINT16_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof( khi) ==  (INT16_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof( kwu) == (UINT32_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof( kwi) ==  (INT32_SHL2)))  goto fail;
//  SHL2W=BWZ
    if (!TASSERT(shl2_funcof(vwbu) ==   (VWBU_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vwbi) ==   (VWBI_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vwhu) ==   (VWHU_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vwhi) ==   (VWHI_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vwwu) ==   (VWWU_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vwwi) ==   (VWWI_SHL2)))  goto fail;
//  SHL2D=BWZ
    if (!TASSERT(shl2_funcof(vdbu) ==   (VDBU_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vdbi) ==   (VDBI_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vdhu) ==   (VDHU_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vdhi) ==   (VDHI_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vdwu) ==   (VDWU_SHL2)))  goto fail;
    if (!TASSERT(shl2_funcof(vdwi) ==   (VDWI_SHL2)))  goto fail;
//  SHL2Q=NONE
#if 0 // leave shl_
}
#endif

#if 0 // enter shr_
{
#endif
//  SHRS=BDZ
    if (!TASSERT(shrs_funcof( kbu) ==  (UINT8_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( kbi) ==   (INT8_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( khu) == (UINT16_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( khi) ==  (INT16_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( kwu) == (UINT32_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( kwi) ==  (INT32_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( kdu) == (UINT64_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof( kdi) ==  (INT64_SHRS)))  goto fail;
//  SHRSW=BWZ
    if (!TASSERT(shrs_funcof(vwbu) ==   (VWBU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vwbi) ==   (VWBI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vwhu) ==   (VWHU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vwhi) ==   (VWHI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vwwu) ==   (VWWU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vwwi) ==   (VWWI_SHRS)))  goto fail;
//  SHRSD=BDZ
    if (!TASSERT(shrs_funcof(vdbu) ==   (VDBU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vdbi) ==   (VDBI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vdhu) ==   (VDHU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vdhi) ==   (VDHI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vdwu) ==   (VDWU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vdwi) ==   (VDWI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vddu) ==   (VDDU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vddi) ==   (VDDI_SHRS)))  goto fail;
//  SHRSQ=BDZ
    if (!TASSERT(shrs_funcof(vqbu) ==   (VQBU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqbi) ==   (VQBI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqhu) ==   (VQHU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqhi) ==   (VQHI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqwu) ==   (VQWU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqwi) ==   (VQWI_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqdu) ==   (VQDU_SHRS)))  goto fail;
    if (!TASSERT(shrs_funcof(vqdi) ==   (VQDI_SHRS)))  goto fail;
#if 0 // leave shr_
}
#endif

#if 0 // enter sil_
{
#endif
//  SILL=YDU
    if (!TASSERT(sill_funcof( kyu) ==   (BOOL_SILL)))  goto fail;
    if (!TASSERT(sill_funcof( kbu) ==  (UINT8_SILL)))  goto fail;
    if (!TASSERT(sill_funcof( khu) == (UINT16_SILL)))  goto fail;
    if (!TASSERT(sill_funcof( kwu) == (UINT32_SILL)))  goto fail;
    if (!TASSERT(sill_funcof( kdu) == (UINT64_SILL)))  goto fail;
//  SILLW=YWU
    if (!TASSERT(sill_funcof(vwyu) ==   (VWYU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vwbu) ==   (VWBU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vwhu) ==   (VWHU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vwwu) ==   (VWWU_SILL)))  goto fail;
//  SILLD=YDU
    if (!TASSERT(sill_funcof(vdyu) ==   (VDYU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vdbu) ==   (VDBU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vdhu) ==   (VDHU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vdwu) ==   (VDWU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vddu) ==   (VDDU_SILL)))  goto fail;
//  SILLQ=YDU
    if (!TASSERT(sill_funcof(vqyu) ==   (VQYU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vqbu) ==   (VQBU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vqhu) ==   (VQHU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vqwu) ==   (VQWU_SILL)))  goto fail;
    if (!TASSERT(sill_funcof(vqdu) ==   (VQDU_SILL)))  goto fail;
//  SILR=YDU
    if (!TASSERT(silr_funcof( kyu) ==   (BOOL_SILR)))  goto fail;
    if (!TASSERT(silr_funcof( kbu) ==  (UINT8_SILR)))  goto fail;
    if (!TASSERT(silr_funcof( khu) == (UINT16_SILR)))  goto fail;
    if (!TASSERT(silr_funcof( kwu) == (UINT32_SILR)))  goto fail;
    if (!TASSERT(silr_funcof( kdu) == (UINT64_SILR)))  goto fail;
//  SILRW=YWU
    if (!TASSERT(silr_funcof(vwyu) ==   (VWYU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vwbu) ==   (VWBU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vwhu) ==   (VWHU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vwwu) ==   (VWWU_SILR)))  goto fail;
//  SILRD=YDU
    if (!TASSERT(silr_funcof(vdyu) ==   (VDYU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vdbu) ==   (VDBU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vdhu) ==   (VDHU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vdwu) ==   (VDWU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vddu) ==   (VDDU_SILR)))  goto fail;
//  SILRQ=YDU
    if (!TASSERT(silr_funcof(vqyu) ==   (VQYU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vqbu) ==   (VQBU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vqhu) ==   (VQHU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vqwu) ==   (VQWU_SILR)))  goto fail;
    if (!TASSERT(silr_funcof(vqdu) ==   (VQDU_SILR)))  goto fail;
#if 0 // leave sil_
}
#endif

#if 0 // enter sir_
{
#endif
//  SIRL=YDU
    if (!TASSERT(sirl_funcof( kyu) ==   (BOOL_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof( kbu) ==  (UINT8_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof( khu) == (UINT16_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof( kwu) == (UINT32_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof( kdu) == (UINT64_SIRL)))  goto fail;
//  SIRLW=YWU
    if (!TASSERT(sirl_funcof(vwyu) ==   (VWYU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vwbu) ==   (VWBU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vwhu) ==   (VWHU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vwwu) ==   (VWWU_SIRL)))  goto fail;
//  SIRLD=YDU
    if (!TASSERT(sirl_funcof(vdyu) ==   (VDYU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vdbu) ==   (VDBU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vdhu) ==   (VDHU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vdwu) ==   (VDWU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vddu) ==   (VDDU_SIRL)))  goto fail;
//  SIRLQ=YDU
    if (!TASSERT(sirl_funcof(vqyu) ==   (VQYU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vqbu) ==   (VQBU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vqhu) ==   (VQHU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vqwu) ==   (VQWU_SIRL)))  goto fail;
    if (!TASSERT(sirl_funcof(vqdu) ==   (VQDU_SIRL)))  goto fail;
//  SIRR=YDU
    if (!TASSERT(sirr_funcof( kyu) ==   (BOOL_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof( kbu) ==  (UINT8_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof( khu) == (UINT16_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof( kwu) == (UINT32_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof( kdu) == (UINT64_SIRR)))  goto fail;
//  SIRRW=YWU
    if (!TASSERT(sirr_funcof(vwyu) ==   (VWYU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vwbu) ==   (VWBU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vwhu) ==   (VWHU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vwwu) ==   (VWWU_SIRR)))  goto fail;
//  SIRRD=YDU
    if (!TASSERT(sirr_funcof(vdyu) ==   (VDYU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vdbu) ==   (VDBU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vdhu) ==   (VDHU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vdwu) ==   (VDWU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vddu) ==   (VDDU_SIRR)))  goto fail;
//  SIRRQ=YDU
    if (!TASSERT(sirr_funcof(vqyu) ==   (VQYU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vqbu) ==   (VQBU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vqhu) ==   (VQHU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vqwu) ==   (VQWU_SIRR)))  goto fail;
    if (!TASSERT(sirr_funcof(vqdu) ==   (VQDU_SIRR)))  goto fail;
#if 0 // leave sir_
}
#endif

#if 0 // enter spr_
{
#endif
//  SPRL=NONE
//  SPRLW=YHR
    if (!TASSERT(sprl_funcof(vwyu) ==   (VWYU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vwbu) ==   (VWBU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vwbi) ==   (VWBI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vwhu) ==   (VWHU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vwhi) ==   (VWHI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vwhf) ==   (VWHF_SPRL)))  goto fail;
//  SPRLD=YWR
    if (!TASSERT(sprl_funcof(vdyu) ==   (VDYU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdbu) ==   (VDBU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdbi) ==   (VDBI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdhu) ==   (VDHU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdhi) ==   (VDHI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdhf) ==   (VDHF_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdwu) ==   (VDWU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdwi) ==   (VDWI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vdwf) ==   (VDWF_SPRL)))  goto fail;
//  SPRLQ=YDR
    if (!TASSERT(sprl_funcof(vqyu) ==   (VQYU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqbu) ==   (VQBU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqbi) ==   (VQBI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqhu) ==   (VQHU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqhi) ==   (VQHI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqhf) ==   (VQHF_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqwu) ==   (VQWU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqwi) ==   (VQWI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqwf) ==   (VQWF_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqdu) ==   (VQDU_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqdi) ==   (VQDI_SPRL)))  goto fail;
    if (!TASSERT(sprl_funcof(vqdf) ==   (VQDF_SPRL)))  goto fail;
#if 0 // leave spr_
}
#endif

#if 0 // enter str_
{
#endif
//  STR1A=YDZ
    if (!TASSERT(str1_funcof(&kyu) ==   (BOOL_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&kbu) ==  (UINT8_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&kbi) ==   (INT8_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&khu) == (UINT16_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&khi) ==  (INT16_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&kwu) == (UINT32_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&kwi) ==  (INT32_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&kdu) == (UINT64_STR1A))) goto fail;
    if (!TASSERT(str1_funcof(&kdi) ==  (INT64_STR1A))) goto fail;
//  STREA=YDZ
    if (!TASSERT(stre_funcof(&kyu) ==   (BOOL_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&kbu) ==  (UINT8_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&kbi) ==   (INT8_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&khu) == (UINT16_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&khi) ==  (INT16_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&kwu) == (UINT32_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&kwi) ==  (INT32_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&kdu) == (UINT64_STREA))) goto fail;
    if (!TASSERT(stre_funcof(&kdi) ==  (INT64_STREA))) goto fail;
//  STRTA=YDZ
    if (!TASSERT(strt_funcof(&kyu) ==   (BOOL_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&kbu) ==  (UINT8_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&kbi) ==   (INT8_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&khu) == (UINT16_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&khi) ==  (INT16_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&kwu) == (UINT32_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&kwi) ==  (INT32_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&kdu) == (UINT64_STRTA))) goto fail;
    if (!TASSERT(strt_funcof(&kdi) ==  (INT64_STRTA))) goto fail;
//  STRWA=YDZ
    if (!TASSERT(strw_funcof(&kyu) ==   (BOOL_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&kbu) ==  (UINT8_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&kbi) ==   (INT8_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&khu) == (UINT16_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&khi) ==  (INT16_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&khf) ==  (FLT16_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&kwu) == (UINT32_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&kwi) ==  (INT32_STRWA))) goto fail;
    if (!TASSERT(strw_funcof(&kwf) ==    (FLT_STRWA))) goto fail;
//  STRDA=YDZ
    if (!TASSERT(strd_funcof(&kyu) ==   (BOOL_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kbu) ==  (UINT8_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kbi) ==   (INT8_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&khu) == (UINT16_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&khi) ==  (INT16_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&khf) ==  (FLT16_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kwu) == (UINT32_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kwi) ==  (INT32_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kwf) ==    (FLT_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kdu) == (UINT64_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kdi) ==  (INT64_STRDA))) goto fail;
    if (!TASSERT(strd_funcof(&kdf) ==    (DBL_STRDA))) goto fail;
//  STRQA=YDZ
    if (!TASSERT(strq_funcof(&kyu) ==   (BOOL_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kbu) ==  (UINT8_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kbi) ==   (INT8_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&khu) == (UINT16_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&khi) ==  (INT16_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&khf) ==  (FLT16_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kwu) == (UINT32_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kwi) ==  (INT32_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kwf) ==    (FLT_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kdu) == (UINT64_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kdi) ==  (INT64_STRQA))) goto fail;
    if (!TASSERT(strq_funcof(&kdf) ==    (DBL_STRQA))) goto fail;
#if 0 // leave str_
}
#endif

#if 0 // enter svl_
{
#endif
//  SVLL=NONE
//  SVLLW=BWZ
    if (!TASSERT(svll_funcof(vwbu) ==   (VWBU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vwbi) ==   (VWBI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vwhu) ==   (VWHU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vwhi) ==   (VWHI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vwwu) ==   (VWWU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vwwi) ==   (VWWI_SVLL)))  goto fail;
//  SVLLD=BDZ
    if (!TASSERT(svll_funcof(vdbu) ==   (VDBU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vdbi) ==   (VDBI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vdhu) ==   (VDHU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vdhi) ==   (VDHI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vdwu) ==   (VDWU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vdwi) ==   (VDWI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vddu) ==   (VDDU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vddi) ==   (VDDI_SVLL)))  goto fail;
//  SVLLQ=BDZ
    if (!TASSERT(svll_funcof(vqbu) ==   (VQBU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqbi) ==   (VQBI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqhu) ==   (VQHU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqhi) ==   (VQHI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqwu) ==   (VQWU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqwi) ==   (VQWI_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqdu) ==   (VQDU_SVLL)))  goto fail;
    if (!TASSERT(svll_funcof(vqdi) ==   (VQDI_SVLL)))  goto fail;
//  SVLS=NONE
//  SVLSW=BWZ
    if (!TASSERT(svls_funcof(vwbu) ==   (VWBU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vwbi) ==   (VWBI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vwhu) ==   (VWHU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vwhi) ==   (VWHI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vwwu) ==   (VWWU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vwwi) ==   (VWWI_SVLS)))  goto fail;
//  SVLSD=BDZ
    if (!TASSERT(svls_funcof(vdbu) ==   (VDBU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vdbi) ==   (VDBI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vdhu) ==   (VDHU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vdhi) ==   (VDHI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vdwu) ==   (VDWU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vdwi) ==   (VDWI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vddu) ==   (VDDU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vddi) ==   (VDDI_SVLS)))  goto fail;
//  SVLSQ=BDZ
    if (!TASSERT(svls_funcof(vqbu) ==   (VQBU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqbi) ==   (VQBI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqhu) ==   (VQHU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqhi) ==   (VQHI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqwu) ==   (VQWU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqwi) ==   (VQWI_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqdu) ==   (VQDU_SVLS)))  goto fail;
    if (!TASSERT(svls_funcof(vqdi) ==   (VQDI_SVLS)))  goto fail;
//  SVL2=NONE
//  SVL2W=BWZ
    if (!TASSERT(svl2_funcof(vwbu) ==   (VWBU_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vwbi) ==   (VWBI_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vwhu) ==   (VWHU_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vwhi) ==   (VWHI_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vwwu) ==   (VWWU_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vwwi) ==   (VWWI_SVL2)))  goto fail;
//  SVL2D=BDZ
    if (!TASSERT(svl2_funcof(vdbu) ==   (VDBU_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vdbi) ==   (VDBI_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vdhu) ==   (VDHU_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vdhi) ==   (VDHI_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vdwu) ==   (VDWU_SVL2)))  goto fail;
    if (!TASSERT(svl2_funcof(vdwi) ==   (VDWI_SVL2)))  goto fail;
//  SVL2Q=NONE
#if 0 // leave svl_
}
#endif

#if 0 // enter svr_
{
#endif
//  SVRS=NONE
//  SVRSW=BWZ
    if (!TASSERT(svrs_funcof(vwbu) ==   (VWBU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vwbi) ==   (VWBI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vwhu) ==   (VWHU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vwhi) ==   (VWHI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vwwu) ==   (VWWU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vwwi) ==   (VWWI_SVRS)))  goto fail;
//  SVRSD=BDZ
    if (!TASSERT(svrs_funcof(vdbu) ==   (VDBU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vdbi) ==   (VDBI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vdhu) ==   (VDHU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vdhi) ==   (VDHI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vdwu) ==   (VDWU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vdwi) ==   (VDWI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vddu) ==   (VDDU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vddi) ==   (VDDI_SVRS)))  goto fail;
//  SVRSQ=BDZ
    if (!TASSERT(svrs_funcof(vqbu) ==   (VQBU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqbi) ==   (VQBI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqhu) ==   (VQHU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqhi) ==   (VQHI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqwu) ==   (VQWU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqwi) ==   (VQWI_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqdu) ==   (VQDU_SVRS)))  goto fail;
    if (!TASSERT(svrs_funcof(vqdi) ==   (VQDI_SVRS)))  goto fail;
#if 0 // leave svr_
}
#endif

#if 0 // enter swp_
{
#endif
//  SWP1A=YDZ
    if (!TASSERT(swp1_funcof(&kyu) ==   (BOOL_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&kbu) ==  (UINT8_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&kbi) ==   (INT8_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&khu) == (UINT16_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&khi) ==  (INT16_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&kwu) == (UINT32_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&kwi) ==  (INT32_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&kdu) == (UINT64_SWP1A))) goto fail;
    if (!TASSERT(swp1_funcof(&kdi) ==  (INT64_SWP1A))) goto fail;
//  SWPAA=YDZ
    if (!TASSERT(swpa_funcof(&kyu) ==   (BOOL_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&kbu) ==  (UINT8_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&kbi) ==   (INT8_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&khu) == (UINT16_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&khi) ==  (INT16_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&kwu) == (UINT32_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&kwi) ==  (INT32_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&kdu) == (UINT64_SWPAA))) goto fail;
    if (!TASSERT(swpa_funcof(&kdi) ==  (INT64_SWPAA))) goto fail;
//  SWPEA=YDZ
    if (!TASSERT(swpe_funcof(&kyu) ==   (BOOL_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&kbu) ==  (UINT8_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&kbi) ==   (INT8_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&khu) == (UINT16_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&khi) ==  (INT16_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&kwu) == (UINT32_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&kwi) ==  (INT32_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&kdu) == (UINT64_SWPEA))) goto fail;
    if (!TASSERT(swpe_funcof(&kdi) ==  (INT64_SWPEA))) goto fail;
//  SWPTA=YDZ
    if (!TASSERT(swpt_funcof(&kyu) ==   (BOOL_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&kbu) ==  (UINT8_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&kbi) ==   (INT8_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&khu) == (UINT16_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&khi) ==  (INT16_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&kwu) == (UINT32_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&kwi) ==  (INT32_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&kdu) == (UINT64_SWPTA))) goto fail;
    if (!TASSERT(swpt_funcof(&kdi) ==  (INT64_SWPTA))) goto fail;
#if 0 // leave swp_
}
#endif

#if 0 // enter tst_
{
#endif
//  TSTS=BDZ
    if (!TASSERT(tsts_funcof( kbu) ==  (UINT8_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( kbi) ==   (INT8_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( khu) == (UINT16_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( khi) ==  (INT16_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( kwu) == (UINT32_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( kwi) ==  (INT32_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( kdu) == (UINT64_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof( kdi) ==  (INT64_TSTS)))  goto fail;
//  TSTSW=BWZ
    if (!TASSERT(tsts_funcof(vwbu) ==   (VWBU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vwbi) ==   (VWBI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vwhu) ==   (VWHU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vwhi) ==   (VWHI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vwwu) ==   (VWWU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vwwi) ==   (VWWI_TSTS)))  goto fail;
//  TSTSD=BDZ
    if (!TASSERT(tsts_funcof(vdbu) ==   (VDBU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vdbi) ==   (VDBI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vdhu) ==   (VDHU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vdhi) ==   (VDHI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vdwu) ==   (VDWU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vdwi) ==   (VDWI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vddu) ==   (VDDU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vddi) ==   (VDDI_TSTS)))  goto fail;
//  TSTSQ=BDZ
    if (!TASSERT(tsts_funcof(vqbu) ==   (VQBU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqbi) ==   (VQBI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqhu) ==   (VQHU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqhi) ==   (VQHI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqwu) ==   (VQWU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqwi) ==   (VQWI_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqdu) ==   (VQDU_TSTS)))  goto fail;
    if (!TASSERT(tsts_funcof(vqdi) ==   (VQDI_TSTS)))  goto fail;
//  TSTY=BDZ
    if (!TASSERT(tsty_funcof( kbu) ==  (UINT8_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( kbi) ==   (INT8_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( khu) == (UINT16_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( khi) ==  (INT16_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( kwu) == (UINT32_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( kwi) ==  (INT32_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( kdu) == (UINT64_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof( kdi) ==  (INT64_TSTY)))  goto fail;
//  TSTYW=BWZ
    if (!TASSERT(tsty_funcof(vwbu) ==   (VWBU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vwbi) ==   (VWBI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vwhu) ==   (VWHU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vwhi) ==   (VWHI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vwwu) ==   (VWWU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vwwi) ==   (VWWI_TSTY)))  goto fail;
//  TSTYD=BDZ
    if (!TASSERT(tsty_funcof(vdbu) ==   (VDBU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vdbi) ==   (VDBI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vdhu) ==   (VDHU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vdhi) ==   (VDHI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vdwu) ==   (VDWU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vdwi) ==   (VDWI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vddu) ==   (VDDU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vddi) ==   (VDDI_TSTY)))  goto fail;
//  TSTYQ=BDZ
    if (!TASSERT(tsty_funcof(vqbu) ==   (VQBU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqbi) ==   (VQBI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqhu) ==   (VQHU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqhi) ==   (VQHI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqwu) ==   (VQWU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqwi) ==   (VQWI_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqdu) ==   (VQDU_TSTY)))  goto fail;
    if (!TASSERT(tsty_funcof(vqdi) ==   (VQDI_TSTY)))  goto fail;
#if 0 // leave tst_
}
#endif

#endif // DONE AND DUSTED



#if 0 // DONE AND DUSTED 2

#if 0 // enter uno_
{
#endif
//  UNOL=BDZ
    if (!TASSERT(unol_funcof(uint8_t) ==  (UINT8_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof( int8_t) ==   (INT8_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(uint16_t) == (UINT16_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof( int16_t) ==  (INT16_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(uint32_t) == (UINT32_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof( int32_t) ==  (INT32_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(uint64_t) == (UINT64_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof( int64_t) ==  (INT64_UNOL)))  goto fail;
//  UNOLW=BWZ
    if (!TASSERT(unol_funcof(Vwbu) ==   (VWBU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vwbi) ==   (VWBI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vwhu) ==   (VWHU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vwhi) ==   (VWHI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vwwu) ==   (VWWU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vwwi) ==   (VWWI_UNOL)))  goto fail;
//  UNOLD=BDZ
    if (!TASSERT(unol_funcof(Vdbu) ==   (VDBU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vdbi) ==   (VDBI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vdhu) ==   (VDHU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vdhi) ==   (VDHI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vdwu) ==   (VDWU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vdwi) ==   (VDWI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vddu) ==   (VDDU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vddi) ==   (VDDI_UNOL)))  goto fail;
//  UNOLQ=BDZ
    if (!TASSERT(unol_funcof(Vqbu) ==   (VQBU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqbi) ==   (VQBI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqhu) ==   (VQHU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqhi) ==   (VQHI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqwu) ==   (VQWU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqwi) ==   (VQWI_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqdu) ==   (VQDU_UNOL)))  goto fail;
    if (!TASSERT(unol_funcof(Vqdi) ==   (VQDI_UNOL)))  goto fail;
//  UNOR=BDZ
    if (!TASSERT(unor_funcof(uint8_t) ==  (UINT8_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof( int8_t) ==   (INT8_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(uint16_t) == (UINT16_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof( int16_t) ==  (INT16_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(uint32_t) == (UINT32_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof( int32_t) ==  (INT32_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(uint64_t) == (UINT64_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof( int64_t) ==  (INT64_UNOR)))  goto fail;
//  UNORW=BWZ
    if (!TASSERT(unor_funcof(Vwbu) ==   (VWBU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vwbi) ==   (VWBI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vwhu) ==   (VWHU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vwhi) ==   (VWHI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vwwu) ==   (VWWU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vwwi) ==   (VWWI_UNOR)))  goto fail;
//  UNORD=BDZ
    if (!TASSERT(unor_funcof(Vdbu) ==   (VDBU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vdbi) ==   (VDBI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vdhu) ==   (VDHU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vdhi) ==   (VDHI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vdwu) ==   (VDWU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vdwi) ==   (VDWI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vddu) ==   (VDDU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vddi) ==   (VDDI_UNOR)))  goto fail;
//  UNORQ=BDZ
    if (!TASSERT(unor_funcof(Vqbu) ==   (VQBU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqbi) ==   (VQBI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqhu) ==   (VQHU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqhi) ==   (VQHI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqwu) ==   (VQWU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqwi) ==   (VQWI_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqdu) ==   (VQDU_UNOR)))  goto fail;
    if (!TASSERT(unor_funcof(Vqdi) ==   (VQDI_UNOR)))  goto fail;
#if 0 // leave uno_
}
#endif

#endif // DONE AND DUSTED 2



#if 0 // DONE AND DUSTED 3

#if 0 // enter uzp_
{
#endif
//  UZPL=NONE
//  UZPLW=BHR
    if (!TASSERT(uzpl_funcof(vwbu) ==   (VWBU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vwbi) ==   (VWBI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vwhu) ==   (VWHU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vwhi) ==   (VWHI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vwhf) ==   (VWHF_UZPL)))  goto fail;
//  UZPLD=BWR
    if (!TASSERT(uzpl_funcof(vdbu) ==   (VDBU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdbi) ==   (VDBI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdhu) ==   (VDHU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdhi) ==   (VDHI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdhf) ==   (VDHF_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdwu) ==   (VDWU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdwi) ==   (VDWI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vdwf) ==   (VDWF_UZPL)))  goto fail;
//  UZPLQ=BDR
    if (!TASSERT(uzpl_funcof(vqbu) ==   (VQBU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqbi) ==   (VQBI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqhu) ==   (VQHU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqhi) ==   (VQHI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqhf) ==   (VQHF_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqwu) ==   (VQWU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqwi) ==   (VQWI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqwf) ==   (VQWF_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqdu) ==   (VQDU_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqdi) ==   (VQDI_UZPL)))  goto fail;
    if (!TASSERT(uzpl_funcof(vqdf) ==   (VQDF_UZPL)))  goto fail;
//  UZPR=NONE
//  UZPRW=BHR
    if (!TASSERT(uzpr_funcof(vwbu) ==   (VWBU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vwbi) ==   (VWBI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vwhu) ==   (VWHU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vwhi) ==   (VWHI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vwhf) ==   (VWHF_UZPR)))  goto fail;
//  UZPRD=BWR
    if (!TASSERT(uzpr_funcof(vdbu) ==   (VDBU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdbi) ==   (VDBI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdhu) ==   (VDHU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdhi) ==   (VDHI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdhf) ==   (VDHF_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdwu) ==   (VDWU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdwi) ==   (VDWI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vdwf) ==   (VDWF_UZPR)))  goto fail;
//  UZPRQ=BDR
    if (!TASSERT(uzpr_funcof(vqbu) ==   (VQBU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqbi) ==   (VQBI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqhu) ==   (VQHU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqhi) ==   (VQHI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqhf) ==   (VQHF_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqwu) ==   (VQWU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqwi) ==   (VQWI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqwf) ==   (VQWF_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqdu) ==   (VQDU_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqdi) ==   (VQDI_UZPR)))  goto fail;
    if (!TASSERT(uzpr_funcof(vqdf) ==   (VQDF_UZPR)))  goto fail;
#if 0 // leave uzp_
}
#endif

#if 0 // enter veq_
{
#endif
//  VEQS=NONE
//  VEQSW=BHR
    if (!TASSERT(veqs_funcof(vwbu) ==   (VWBU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vwbi) ==   (VWBI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vwhu) ==   (VWHU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vwhi) ==   (VWHI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vwhf) ==   (VWHF_VEQS)))  goto fail;
//  VEQSD=BWR
    if (!TASSERT(veqs_funcof(vdbu) ==   (VDBU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdbi) ==   (VDBI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdhu) ==   (VDHU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdhi) ==   (VDHI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdhf) ==   (VDHF_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdwu) ==   (VDWU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdwi) ==   (VDWI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vdwf) ==   (VDWF_VEQS)))  goto fail;
//  VEQSQ=BDR
    if (!TASSERT(veqs_funcof(vqbu) ==   (VQBU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqbi) ==   (VQBI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqhu) ==   (VQHU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqhi) ==   (VQHI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqhf) ==   (VQHF_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqwu) ==   (VQWU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqwi) ==   (VQWI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqwf) ==   (VQWF_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqdu) ==   (VQDU_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqdi) ==   (VQDI_VEQS)))  goto fail;
    if (!TASSERT(veqs_funcof(vqdf) ==   (VQDF_VEQS)))  goto fail;
//  VEQY=NONE
//  VEQYW=BHR
    if (!TASSERT(veqy_funcof(vwbu) ==   (VWBU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vwbi) ==   (VWBI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vwhu) ==   (VWHU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vwhi) ==   (VWHI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vwhf) ==   (VWHF_VEQY)))  goto fail;
//  VEQYD=BWR
    if (!TASSERT(veqy_funcof(vdbu) ==   (VDBU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdbi) ==   (VDBI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdhu) ==   (VDHU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdhi) ==   (VDHI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdhf) ==   (VDHF_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdwu) ==   (VDWU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdwi) ==   (VDWI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vdwf) ==   (VDWF_VEQY)))  goto fail;
//  VEQYQ=BDR
    if (!TASSERT(veqy_funcof(vqbu) ==   (VQBU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqbi) ==   (VQBI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqhu) ==   (VQHU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqhi) ==   (VQHI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqhf) ==   (VQHF_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqwu) ==   (VQWU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqwi) ==   (VQWI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqwf) ==   (VQWF_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqdu) ==   (VQDU_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqdi) ==   (VQDI_VEQY)))  goto fail;
    if (!TASSERT(veqy_funcof(vqdf) ==   (VQDF_VEQY)))  goto fail;
#if 0 // leave veq_
}
#endif

#if 0 // enter xeq_
{
#endif
//  XEQ1A=YDZ
    if (!TASSERT(xeq1_funcof(&kyu) ==   (BOOL_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&kbu) ==  (UINT8_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&kbi) ==   (INT8_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&khu) == (UINT16_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&khi) ==  (INT16_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&kwu) == (UINT32_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&kwi) ==  (INT32_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&kdu) == (UINT64_XEQ1A))) goto fail;
    if (!TASSERT(xeq1_funcof(&kdi) ==  (INT64_XEQ1A))) goto fail;
//  XEQAA=YDZ
    if (!TASSERT(xeqa_funcof(&kyu) ==   (BOOL_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&kbu) ==  (UINT8_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&kbi) ==   (INT8_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&khu) == (UINT16_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&khi) ==  (INT16_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&kwu) == (UINT32_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&kwi) ==  (INT32_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&kdu) == (UINT64_XEQAA))) goto fail;
    if (!TASSERT(xeqa_funcof(&kdi) ==  (INT64_XEQAA))) goto fail;
//  XEQEA=YDZ
    if (!TASSERT(xeqe_funcof(&kyu) ==   (BOOL_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&kbu) ==  (UINT8_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&kbi) ==   (INT8_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&khu) == (UINT16_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&khi) ==  (INT16_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&kwu) == (UINT32_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&kwi) ==  (INT32_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&kdu) == (UINT64_XEQEA))) goto fail;
    if (!TASSERT(xeqe_funcof(&kdi) ==  (INT64_XEQEA))) goto fail;
//  XEQTA=YDZ
    if (!TASSERT(xeqt_funcof(&kyu) ==   (BOOL_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&kbu) ==  (UINT8_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&kbi) ==   (INT8_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&khu) == (UINT16_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&khi) ==  (INT16_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&kwu) == (UINT32_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&kwi) ==  (INT32_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&kdu) == (UINT64_XEQTA))) goto fail;
    if (!TASSERT(xeqt_funcof(&kdi) ==  (INT64_XEQTA))) goto fail;
#if 0 // leave xeq_
}
#endif

#if 0 // enter xor_
{
#endif
//  XORS=YDZ
    if (!TASSERT(xors_funcof( kyu) ==   (BOOL_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( kbu) ==  (UINT8_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( kbi) ==   (INT8_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( khu) == (UINT16_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( khi) ==  (INT16_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( kwu) == (UINT32_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( kwi) ==  (INT32_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( kdu) == (UINT64_XORS)))  goto fail;
    if (!TASSERT(xors_funcof( kdi) ==  (INT64_XORS)))  goto fail;
//  XORSW=YWZ
    if (!TASSERT(xors_funcof(vwyu) ==   (VWYU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vwbu) ==   (VWBU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vwbi) ==   (VWBI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vwhu) ==   (VWHU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vwhi) ==   (VWHI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vwwu) ==   (VWWU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vwwi) ==   (VWWI_XORS)))  goto fail;
//  XORSD=YDZ
    if (!TASSERT(xors_funcof(vdyu) ==   (VDYU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vdbu) ==   (VDBU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vdbi) ==   (VDBI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vdhu) ==   (VDHU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vdhi) ==   (VDHI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vdwu) ==   (VDWU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vdwi) ==   (VDWI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vddu) ==   (VDDU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vddi) ==   (VDDI_XORS)))  goto fail;
//  XORSQ=YDZ
    if (!TASSERT(xors_funcof(vqbu) ==   (VQBU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqyu) ==   (VQYU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqbu) ==   (VQBU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqbi) ==   (VQBI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqhu) ==   (VQHU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqhi) ==   (VQHI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqwu) ==   (VQWU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqwi) ==   (VQWI_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqdu) ==   (VQDU_XORS)))  goto fail;
    if (!TASSERT(xors_funcof(vqdi) ==   (VQDI_XORS)))  goto fail;
//  XORN=YDZ
    if (!TASSERT(xorn_funcof( kyu) ==   (BOOL_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( kbu) ==  (UINT8_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( kbi) ==   (INT8_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( khu) == (UINT16_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( khi) ==  (INT16_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( kwu) == (UINT32_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( kwi) ==  (INT32_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( kdu) == (UINT64_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof( kdi) ==  (INT64_XORN)))  goto fail;
//  XORNW=YWZ
    if (!TASSERT(xorn_funcof(vwyu) ==   (VWYU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vwbu) ==   (VWBU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vwbi) ==   (VWBI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vwhu) ==   (VWHU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vwhi) ==   (VWHI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vwwu) ==   (VWWU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vwwi) ==   (VWWI_XORN)))  goto fail;
//  XORND=YDZ
    if (!TASSERT(xorn_funcof(vdyu) ==   (VDYU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vdbu) ==   (VDBU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vdbi) ==   (VDBI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vdhu) ==   (VDHU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vdhi) ==   (VDHI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vdwu) ==   (VDWU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vdwi) ==   (VDWI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vddu) ==   (VDDU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vddi) ==   (VDDI_XORN)))  goto fail;
//  XORNQ=YDZ
    if (!TASSERT(xorn_funcof(vqyu) ==   (VQYU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqbu) ==   (VQBU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqyu) ==   (VQYU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqbu) ==   (VQBU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqbi) ==   (VQBI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqhu) ==   (VQHU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqhi) ==   (VQHI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqwu) ==   (VQWU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqwi) ==   (VQWI_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqdu) ==   (VQDU_XORN)))  goto fail;
    if (!TASSERT(xorn_funcof(vqdi) ==   (VQDI_XORN)))  goto fail;
//  XOR1A=YDZ
    if (!TASSERT(xor1_funcof(&kyu) ==   (BOOL_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&kbu) ==  (UINT8_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&kbi) ==   (INT8_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&khu) == (UINT16_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&khi) ==  (INT16_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&kwu) == (UINT32_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&kwi) ==  (INT32_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&kdu) == (UINT64_XOR1A))) goto fail;
    if (!TASSERT(xor1_funcof(&kdi) ==  (INT64_XOR1A))) goto fail;
//  XORAA=YDZ
    if (!TASSERT(xora_funcof(&kyu) ==   (BOOL_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&kbu) ==  (UINT8_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&kbi) ==   (INT8_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&khu) == (UINT16_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&khi) ==  (INT16_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&kwu) == (UINT32_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&kwi) ==  (INT32_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&kdu) == (UINT64_XORAA))) goto fail;
    if (!TASSERT(xora_funcof(&kdi) ==  (INT64_XORAA))) goto fail;
//  XOREA=YDZ
    if (!TASSERT(xore_funcof(&kyu) ==   (BOOL_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&kbu) ==  (UINT8_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&kbi) ==   (INT8_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&khu) == (UINT16_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&khi) ==  (INT16_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&kwu) == (UINT32_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&kwi) ==  (INT32_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&kdu) == (UINT64_XOREA))) goto fail;
    if (!TASSERT(xore_funcof(&kdi) ==  (INT64_XOREA))) goto fail;
//  XORTA=YDZ
    if (!TASSERT(xort_funcof(&kyu) ==   (BOOL_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&kbu) ==  (UINT8_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&kbi) ==   (INT8_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&khu) == (UINT16_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&khi) ==  (INT16_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&kwu) == (UINT32_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&kwi) ==  (INT32_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&kdu) == (UINT64_XORTA))) goto fail;
    if (!TASSERT(xort_funcof(&kdi) ==  (INT64_XORTA))) goto fail;
#if 0 // leave xor_
}
#endif

#if 0 // enter zeq_
{
#endif
//  ZEQS=BDR
    if (!TASSERT(zeqs_funcof( kbu) ==  (UINT8_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kbi) ==   (INT8_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( khu) == (UINT16_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( khi) ==  (INT16_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( khf) ==  (FLT16_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kwu) == (UINT32_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kwi) ==  (INT32_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kwf) ==    (FLT_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kdu) == (UINT64_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kdi) ==  (INT64_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof( kdf) ==    (DBL_ZEQS)))  goto fail;
//  ZEQSW=BWR
    if (!TASSERT(zeqs_funcof(vwbu) ==   (VWBU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwbi) ==   (VWBI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwhu) ==   (VWHU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwhi) ==   (VWHI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwhf) ==   (VWHF_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwwu) ==   (VWWU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwwi) ==   (VWWI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vwwf) ==   (VWWF_ZEQS)))  goto fail;
//  ZEQSD=BDR
    if (!TASSERT(zeqs_funcof(vdbu) ==   (VDBU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdbi) ==   (VDBI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdhu) ==   (VDHU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdhi) ==   (VDHI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdhf) ==   (VDHF_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdwu) ==   (VDWU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdwi) ==   (VDWI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vdwf) ==   (VDWF_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vddu) ==   (VDDU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vddi) ==   (VDDI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vddf) ==   (VDDF_ZEQS)))  goto fail;
//  ZEQSQ=BDR
    if (!TASSERT(zeqs_funcof(vqbu) ==   (VQBU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqbi) ==   (VQBI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqhu) ==   (VQHU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqhi) ==   (VQHI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqhf) ==   (VQHF_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqwu) ==   (VQWU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqwi) ==   (VQWI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqwf) ==   (VQWF_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqdu) ==   (VQDU_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqdi) ==   (VQDI_ZEQS)))  goto fail;
    if (!TASSERT(zeqs_funcof(vqdf) ==   (VQDF_ZEQS)))  goto fail;
//  ZEQY=BDR
    if (!TASSERT(zeqy_funcof( kbu) ==  (UINT8_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kbi) ==   (INT8_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( khu) == (UINT16_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( khi) ==  (INT16_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( khf) ==  (FLT16_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kwu) == (UINT32_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kwi) ==  (INT32_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kwf) ==    (FLT_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kdu) == (UINT64_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kdi) ==  (INT64_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof( kdf) ==    (DBL_ZEQY)))  goto fail;
//  ZEQYW=BWR
    if (!TASSERT(zeqy_funcof(vwbu) ==   (VWBU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwbi) ==   (VWBI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwhu) ==   (VWHU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwhi) ==   (VWHI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwhf) ==   (VWHF_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwwu) ==   (VWWU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwwi) ==   (VWWI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vwwf) ==   (VWWF_ZEQY)))  goto fail;
//  ZEQYD=BDR
    if (!TASSERT(zeqy_funcof(vdbu) ==   (VDBU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdbi) ==   (VDBI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdhu) ==   (VDHU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdhi) ==   (VDHI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdhf) ==   (VDHF_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdwu) ==   (VDWU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdwi) ==   (VDWI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vdwf) ==   (VDWF_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vddu) ==   (VDDU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vddi) ==   (VDDI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vddf) ==   (VDDF_ZEQY)))  goto fail;
//  ZEQYQ=BDR
    if (!TASSERT(zeqy_funcof(vqbu) ==   (VQBU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqbi) ==   (VQBI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqhu) ==   (VQHU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqhi) ==   (VQHI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqhf) ==   (VQHF_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqwu) ==   (VQWU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqwi) ==   (VQWI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqwf) ==   (VQWF_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqdu) ==   (VQDU_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqdi) ==   (VQDI_ZEQY)))  goto fail;
    if (!TASSERT(zeqy_funcof(vqdf) ==   (VQDF_ZEQY)))  goto fail;
#if 0 // leave zeq_
}
#endif

#if 0 // enter zne_
{
#endif
//  ZNES=BDR
    if (!TASSERT(znes_funcof( kbu) ==  (UINT8_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kbi) ==   (INT8_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( khu) == (UINT16_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( khi) ==  (INT16_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( khf) ==  (FLT16_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kwu) == (UINT32_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kwi) ==  (INT32_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kwf) ==    (FLT_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kdu) == (UINT64_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kdi) ==  (INT64_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof( kdf) ==    (DBL_ZNES)))  goto fail;
//  ZNESW=BWR
    if (!TASSERT(znes_funcof(vwbu) ==   (VWBU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwbi) ==   (VWBI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwhu) ==   (VWHU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwhi) ==   (VWHI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwhf) ==   (VWHF_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwwu) ==   (VWWU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwwi) ==   (VWWI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vwwf) ==   (VWWF_ZNES)))  goto fail;
//  ZNESD=BDR
    if (!TASSERT(znes_funcof(vdbu) ==   (VDBU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdbi) ==   (VDBI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdhu) ==   (VDHU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdhi) ==   (VDHI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdhf) ==   (VDHF_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdwu) ==   (VDWU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdwi) ==   (VDWI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vdwf) ==   (VDWF_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vddu) ==   (VDDU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vddi) ==   (VDDI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vddf) ==   (VDDF_ZNES)))  goto fail;
//  ZNESQ=BDR
    if (!TASSERT(znes_funcof(vqbu) ==   (VQBU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqbi) ==   (VQBI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqhu) ==   (VQHU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqhi) ==   (VQHI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqhf) ==   (VQHF_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqwu) ==   (VQWU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqwi) ==   (VQWI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqwf) ==   (VQWF_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqdu) ==   (VQDU_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqdi) ==   (VQDI_ZNES)))  goto fail;
    if (!TASSERT(znes_funcof(vqdf) ==   (VQDF_ZNES)))  goto fail;
//  ZNEY=BDR
    if (!TASSERT(zney_funcof( kbu) ==  (UINT8_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kbi) ==   (INT8_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( khu) == (UINT16_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( khi) ==  (INT16_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( khf) ==  (FLT16_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kwu) == (UINT32_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kwi) ==  (INT32_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kwf) ==    (FLT_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kdu) == (UINT64_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kdi) ==  (INT64_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof( kdf) ==    (DBL_ZNEY)))  goto fail;
//  ZNEYW=BWR
    if (!TASSERT(zney_funcof(vwbu) ==   (VWBU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwbi) ==   (VWBI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwhu) ==   (VWHU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwhi) ==   (VWHI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwhf) ==   (VWHF_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwwu) ==   (VWWU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwwi) ==   (VWWI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vwwf) ==   (VWWF_ZNEY)))  goto fail;
//  ZNEYD=BDR
    if (!TASSERT(zney_funcof(vdbu) ==   (VDBU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdbi) ==   (VDBI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdhu) ==   (VDHU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdhi) ==   (VDHI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdhf) ==   (VDHF_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdwu) ==   (VDWU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdwi) ==   (VDWI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vdwf) ==   (VDWF_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vddu) ==   (VDDU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vddi) ==   (VDDI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vddf) ==   (VDDF_ZNEY)))  goto fail;
//  ZNEYQ=BDR
    if (!TASSERT(zney_funcof(vqbu) ==   (VQBU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqbi) ==   (VQBI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqhu) ==   (VQHU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqhi) ==   (VQHI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqhf) ==   (VQHF_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqwu) ==   (VQWU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqwi) ==   (VQWI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqwf) ==   (VQWF_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqdu) ==   (VQDU_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqdi) ==   (VQDI_ZNEY)))  goto fail;
    if (!TASSERT(zney_funcof(vqdf) ==   (VQDF_ZNEY)))  goto fail;
#if 0 // leave zne_
}
#endif

#if 0 // enter zgt_
{
#endif
//  ZGTS=BDS
    if (!TASSERT(zgts_funcof( kbi) ==   (INT8_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof( khi) ==  (INT16_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof( khf) ==  (FLT16_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof( kwi) ==  (INT32_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof( kwf) ==    (FLT_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof( kdi) ==  (INT64_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof( kdf) ==    (DBL_ZGTS)))  goto fail;
//  ZGTSW=BWS
    if (!TASSERT(zgts_funcof(vwbi) ==   (VWBI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vwhi) ==   (VWHI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vwhf) ==   (VWHF_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vwwi) ==   (VWWI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vwwf) ==   (VWWF_ZGTS)))  goto fail;
//  ZGTSD=BDS
    if (!TASSERT(zgts_funcof(vdbi) ==   (VDBI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vdhi) ==   (VDHI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vdhf) ==   (VDHF_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vdwi) ==   (VDWI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vdwf) ==   (VDWF_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vddi) ==   (VDDI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vddf) ==   (VDDF_ZGTS)))  goto fail;
//  ZGTSQ=BDS
    if (!TASSERT(zgts_funcof(vqbi) ==   (VQBI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vqhi) ==   (VQHI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vqhf) ==   (VQHF_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vqwi) ==   (VQWI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vqwf) ==   (VQWF_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vqdi) ==   (VQDI_ZGTS)))  goto fail;
    if (!TASSERT(zgts_funcof(vqdf) ==   (VQDF_ZGTS)))  goto fail;
//  ZGTY=BDS
    if (!TASSERT(zgty_funcof( kbi) ==   (INT8_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof( khi) ==  (INT16_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof( khf) ==  (FLT16_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof( kwi) ==  (INT32_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof( kwf) ==    (FLT_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof( kdi) ==  (INT64_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof( kdf) ==    (DBL_ZGTY)))  goto fail;
//  ZGTYW=BWS
    if (!TASSERT(zgty_funcof(vwbi) ==   (VWBI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vwhi) ==   (VWHI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vwhf) ==   (VWHF_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vwwi) ==   (VWWI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vwwf) ==   (VWWF_ZGTY)))  goto fail;
//  ZGTYD=BDS
    if (!TASSERT(zgty_funcof(vdbi) ==   (VDBI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vdhi) ==   (VDHI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vdhf) ==   (VDHF_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vdwi) ==   (VDWI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vdwf) ==   (VDWF_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vddi) ==   (VDDI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vddf) ==   (VDDF_ZGTY)))  goto fail;
//  ZGTYQ=BDS
    if (!TASSERT(zgty_funcof(vqbi) ==   (VQBI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vqhi) ==   (VQHI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vqhf) ==   (VQHF_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vqwi) ==   (VQWI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vqwf) ==   (VQWF_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vqdi) ==   (VQDI_ZGTY)))  goto fail;
    if (!TASSERT(zgty_funcof(vqdf) ==   (VQDF_ZGTY)))  goto fail;
#if 0 // leave zgt_
}
#endif

#if 0 // enter zge_
{
#endif
//  ZGES=BDS
    if (!TASSERT(zges_funcof( kbi) ==   (INT8_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof( khi) ==  (INT16_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof( khf) ==  (FLT16_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof( kwi) ==  (INT32_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof( kwf) ==    (FLT_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof( kdi) ==  (INT64_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof( kdf) ==    (DBL_ZGES)))  goto fail;
//  ZGESW=BWS
    if (!TASSERT(zges_funcof(vwbi) ==   (VWBI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vwhi) ==   (VWHI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vwhf) ==   (VWHF_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vwwi) ==   (VWWI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vwwf) ==   (VWWF_ZGES)))  goto fail;
//  ZGESD=BDS
    if (!TASSERT(zges_funcof(vdbi) ==   (VDBI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vdhi) ==   (VDHI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vdhf) ==   (VDHF_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vdwi) ==   (VDWI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vdwf) ==   (VDWF_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vddi) ==   (VDDI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vddf) ==   (VDDF_ZGES)))  goto fail;
//  ZGESQ=BDS
    if (!TASSERT(zges_funcof(vqbi) ==   (VQBI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vqhi) ==   (VQHI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vqhf) ==   (VQHF_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vqwi) ==   (VQWI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vqwf) ==   (VQWF_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vqdi) ==   (VQDI_ZGES)))  goto fail;
    if (!TASSERT(zges_funcof(vqdf) ==   (VQDF_ZGES)))  goto fail;
//  ZGEY=BDS
    if (!TASSERT(zgey_funcof( kbi) ==   (INT8_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof( khi) ==  (INT16_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof( khf) ==  (FLT16_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof( kwi) ==  (INT32_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof( kwf) ==    (FLT_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof( kdi) ==  (INT64_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof( kdf) ==    (DBL_ZGEY)))  goto fail;
//  ZGEYW=BWS
    if (!TASSERT(zgey_funcof(vwbi) ==   (VWBI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vwhi) ==   (VWHI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vwhf) ==   (VWHF_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vwwi) ==   (VWWI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vwwf) ==   (VWWF_ZGEY)))  goto fail;
//  ZGEYD=BDS
    if (!TASSERT(zgey_funcof(vdbi) ==   (VDBI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vdhi) ==   (VDHI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vdhf) ==   (VDHF_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vdwi) ==   (VDWI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vdwf) ==   (VDWF_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vddi) ==   (VDDI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vddf) ==   (VDDF_ZGEY)))  goto fail;
//  ZGEYQ=BDS
    if (!TASSERT(zgey_funcof(vqbi) ==   (VQBI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vqhi) ==   (VQHI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vqhf) ==   (VQHF_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vqwi) ==   (VQWI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vqwf) ==   (VQWF_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vqdi) ==   (VQDI_ZGEY)))  goto fail;
    if (!TASSERT(zgey_funcof(vqdf) ==   (VQDF_ZGEY)))  goto fail;
#if 0 // leave zge_
}
#endif

#if 0 // enter zlt_
{
#endif
//  ZLTS=BDS
    if (!TASSERT(zlts_funcof( kbi) ==   (INT8_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof( khi) ==  (INT16_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof( khf) ==  (FLT16_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof( kwi) ==  (INT32_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof( kwf) ==    (FLT_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof( kdi) ==  (INT64_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof( kdf) ==    (DBL_ZLTS)))  goto fail;
//  ZLTSW=BWS
    if (!TASSERT(zlts_funcof(vwbi) ==   (VWBI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vwhi) ==   (VWHI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vwhf) ==   (VWHF_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vwwi) ==   (VWWI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vwwf) ==   (VWWF_ZLTS)))  goto fail;
//  ZLTSD=BDS
    if (!TASSERT(zlts_funcof(vdbi) ==   (VDBI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vdhi) ==   (VDHI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vdhf) ==   (VDHF_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vdwi) ==   (VDWI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vdwf) ==   (VDWF_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vddi) ==   (VDDI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vddf) ==   (VDDF_ZLTS)))  goto fail;
//  ZLTSQ=BDS
    if (!TASSERT(zlts_funcof(vqbi) ==   (VQBI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vqhi) ==   (VQHI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vqhf) ==   (VQHF_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vqwi) ==   (VQWI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vqwf) ==   (VQWF_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vqdi) ==   (VQDI_ZLTS)))  goto fail;
    if (!TASSERT(zlts_funcof(vqdf) ==   (VQDF_ZLTS)))  goto fail;
//  ZLTY=BDS
    if (!TASSERT(zlty_funcof( kbi) ==   (INT8_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof( khi) ==  (INT16_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof( khf) ==  (FLT16_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof( kwi) ==  (INT32_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof( kwf) ==    (FLT_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof( kdi) ==  (INT64_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof( kdf) ==    (DBL_ZLTY)))  goto fail;
//  ZLTYW=BWS
    if (!TASSERT(zlty_funcof(vwbi) ==   (VWBI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vwhi) ==   (VWHI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vwhf) ==   (VWHF_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vwwi) ==   (VWWI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vwwf) ==   (VWWF_ZLTY)))  goto fail;
//  ZLTYD=BDS
    if (!TASSERT(zlty_funcof(vdbi) ==   (VDBI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vdhi) ==   (VDHI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vdhf) ==   (VDHF_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vdwi) ==   (VDWI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vdwf) ==   (VDWF_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vddi) ==   (VDDI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vddf) ==   (VDDF_ZLTY)))  goto fail;
//  ZLTYQ=BDS
    if (!TASSERT(zlty_funcof(vqbi) ==   (VQBI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vqhi) ==   (VQHI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vqhf) ==   (VQHF_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vqwi) ==   (VQWI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vqwf) ==   (VQWF_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vqdi) ==   (VQDI_ZLTY)))  goto fail;
    if (!TASSERT(zlty_funcof(vqdf) ==   (VQDF_ZLTY)))  goto fail;
#if 0 // leave zlt_
}
#endif

#if 0 // enter zle_
{
#endif
//  ZLES=BDS
    if (!TASSERT(zles_funcof( kbi) ==   (INT8_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof( khi) ==  (INT16_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof( khf) ==  (FLT16_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof( kwi) ==  (INT32_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof( kwf) ==    (FLT_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof( kdi) ==  (INT64_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof( kdf) ==    (DBL_ZLES)))  goto fail;
//  ZLESW=BWS
    if (!TASSERT(zles_funcof(vwbi) ==   (VWBI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vwhi) ==   (VWHI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vwhf) ==   (VWHF_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vwwi) ==   (VWWI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vwwf) ==   (VWWF_ZLES)))  goto fail;
//  ZLESD=BDS
    if (!TASSERT(zles_funcof(vdbi) ==   (VDBI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vdhi) ==   (VDHI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vdhf) ==   (VDHF_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vdwi) ==   (VDWI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vdwf) ==   (VDWF_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vddi) ==   (VDDI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vddf) ==   (VDDF_ZLES)))  goto fail;
//  ZLESQ=BDS
    if (!TASSERT(zles_funcof(vqbi) ==   (VQBI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vqhi) ==   (VQHI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vqhf) ==   (VQHF_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vqwi) ==   (VQWI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vqwf) ==   (VQWF_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vqdi) ==   (VQDI_ZLES)))  goto fail;
    if (!TASSERT(zles_funcof(vqdf) ==   (VQDF_ZLES)))  goto fail;
//  ZLEY=BDS
    if (!TASSERT(zley_funcof( kbi) ==   (INT8_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof( khi) ==  (INT16_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof( khf) ==  (FLT16_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof( kwi) ==  (INT32_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof( kwf) ==    (FLT_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof( kdi) ==  (INT64_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof( kdf) ==    (DBL_ZLEY)))  goto fail;
//  ZLEYW=BWS
    if (!TASSERT(zley_funcof(vwbi) ==   (VWBI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vwhi) ==   (VWHI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vwhf) ==   (VWHF_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vwwi) ==   (VWWI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vwwf) ==   (VWWF_ZLEY)))  goto fail;
//  ZLEYD=BDS
    if (!TASSERT(zley_funcof(vdbi) ==   (VDBI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vdhi) ==   (VDHI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vdhf) ==   (VDHF_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vdwi) ==   (VDWI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vdwf) ==   (VDWF_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vddi) ==   (VDDI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vddf) ==   (VDDF_ZLEY)))  goto fail;
//  ZLEYQ=BDS
    if (!TASSERT(zley_funcof(vqbi) ==   (VQBI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vqhi) ==   (VQHI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vqhf) ==   (VQHF_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vqwi) ==   (VQWI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vqwf) ==   (VQWF_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vqdi) ==   (VQDI_ZLEY)))  goto fail;
    if (!TASSERT(zley_funcof(vqdf) ==   (VQDF_ZLEY)))  goto fail;
#if 0 // leave zle_
}
#endif

#if 0 // enter zip_
{
#endif
//  ZIPL=NONE
//  ZIPLW=BHR
    if (!TASSERT(zipl_funcof(vwbu) ==   (VWBU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vwbi) ==   (VWBI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vwhu) ==   (VWHU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vwhi) ==   (VWHI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vwhf) ==   (VWHF_ZIPL)))  goto fail;
//  ZIPLD=BWR
    if (!TASSERT(zipl_funcof(vdbu) ==   (VDBU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdbi) ==   (VDBI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdhu) ==   (VDHU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdhi) ==   (VDHI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdhf) ==   (VDHF_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdwu) ==   (VDWU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdwi) ==   (VDWI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vdwf) ==   (VDWF_ZIPL)))  goto fail;
//  ZIPLQ=BDR
    if (!TASSERT(zipl_funcof(vqbu) ==   (VQBU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqbi) ==   (VQBI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqhu) ==   (VQHU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqhi) ==   (VQHI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqhf) ==   (VQHF_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqwu) ==   (VQWU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqwi) ==   (VQWI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqwf) ==   (VQWF_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqdu) ==   (VQDU_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqdi) ==   (VQDI_ZIPL)))  goto fail;
    if (!TASSERT(zipl_funcof(vqdf) ==   (VQDF_ZIPL)))  goto fail;
//  ZIPR=NONE
//  ZIPRW=BHR
    if (!TASSERT(zipr_funcof(vwbu) ==   (VWBU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vwbi) ==   (VWBI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vwhu) ==   (VWHU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vwhi) ==   (VWHI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vwhf) ==   (VWHF_ZIPR)))  goto fail;
//  ZIPRD=BWR
    if (!TASSERT(zipr_funcof(vdbu) ==   (VDBU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdbi) ==   (VDBI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdhu) ==   (VDHU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdhi) ==   (VDHI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdhf) ==   (VDHF_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdwu) ==   (VDWU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdwi) ==   (VDWI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vdwf) ==   (VDWF_ZIPR)))  goto fail;
//  ZIPRQ=BDR
    if (!TASSERT(zipr_funcof(vqbu) ==   (VQBU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqbi) ==   (VQBI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqhu) ==   (VQHU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqhi) ==   (VQHI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqhf) ==   (VQHF_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqwu) ==   (VQWU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqwi) ==   (VQWI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqwf) ==   (VQWF_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqdu) ==   (VQDU_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqdi) ==   (VQDI_ZIPR)))  goto fail;
    if (!TASSERT(zipr_funcof(vqdf) ==   (VQDF_ZIPR)))  goto fail;
//  ZIPP=NONE
//  ZIPPW=BHR
    if (!TASSERT(zipp_funcof(vwbu) ==   (VWBU_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vwbi) ==   (VWBI_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vwhu) ==   (VWHU_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vwhi) ==   (VWHI_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vwhf) ==   (VWHF_ZIPP)))  goto fail;
//  ZIPPD=BWR
    if (!TASSERT(zipp_funcof(vdbu) ==   (VDBU_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdbi) ==   (VDBI_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdhu) ==   (VDHU_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdhi) ==   (VDHI_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdhf) ==   (VDHF_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdwu) ==   (VDWU_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdwi) ==   (VDWI_ZIPP)))  goto fail;
    if (!TASSERT(zipp_funcof(vdwf) ==   (VDWF_ZIPP)))  goto fail;
//  ZIPPQ=NONE
#if 0 // leave zip_
}
#endif

#endif // DONE AND DUSTED 3


#if 0 // enter mvw_
{
#endif
//  MVWL=YDR
    if (!TASSERT(mvwl_funcof( kyu) ==   (BOOL_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( kbu) ==  (UINT8_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( kbi) ==   (INT8_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( khu) == (UINT16_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( khi) ==  (INT16_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( khf) ==  (FLT16_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( kwu) == (UINT32_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( kwi) ==  (INT32_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof( kwf) ==    (FLT_MVWL)))  goto fail;
//  MVWLW=NONE
    if (!TASSERT(mvwl_funcof(vwyu) ==   (VWYU_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwbu) ==   (VWBU_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwbi) ==   (VWBI_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwhu) ==   (VWHU_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwhi) ==   (VWHI_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwhf) ==   (VWHF_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwwu) ==   (VWWU_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwwi) ==   (VWWI_MVWL)))  goto fail;
    if (!TASSERT(mvwl_funcof(vwwf) ==   (VWWF_MVWL)))  goto fail;
//  MVWLD=NONE;
//  MVWLQ=NONE;
#if 0 // leave mvw_
}
#endif

#if 0 // enter mvd_
{
#endif
//  MVDL=YDR
    if (!TASSERT(mvdl_funcof( kyu) ==   (BOOL_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kbu) ==  (UINT8_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kbi) ==   (INT8_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( khu) == (UINT16_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( khi) ==  (INT16_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( khf) ==  (FLT16_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kwu) == (UINT32_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kwi) ==  (INT32_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kwf) ==    (FLT_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kdu) == (UINT64_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kdi) ==  (INT64_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof( kdf) ==    (DBL_MVDL)))  goto fail;
//  MVDLW=NONE
//  MVDLD=BDR
    if (!TASSERT(mvdl_funcof(vdyu) ==   (VDYU_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdbu) ==   (VDBU_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdbi) ==   (VDBI_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdhu) ==   (VDHU_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdhi) ==   (VDHI_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdhf) ==   (VDHF_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdwu) ==   (VDWU_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdwi) ==   (VDWI_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vdwf) ==   (VDWF_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vddu) ==   (VDDU_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vddi) ==   (VDDI_MVDL)))  goto fail;
    if (!TASSERT(mvdl_funcof(vddf) ==   (VDDF_MVDL)))  goto fail;
//  MVDLQ=NONE
#if 0 // leave mvd_
}
#endif

#if 0 // enter mvq_
{
#endif
//  MVQL=YDR
    if (!TASSERT(mvql_funcof( kyu) ==   (BOOL_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kbu) ==  (UINT8_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kbi) ==   (INT8_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( khu) == (UINT16_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( khi) ==  (INT16_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( khf) ==  (FLT16_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kwu) == (UINT32_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kwi) ==  (INT32_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kwf) ==    (FLT_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kdu) == (UINT64_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kdi) ==  (INT64_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof( kdf) ==    (DBL_MVQL)))  goto fail;
//  MVQLW=NONE
//  MVQLD=NONE
//  MVQLQ=YDR
    if (!TASSERT(mvql_funcof(vqyu) ==   (VQYU_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqbu) ==   (VQBU_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqbi) ==   (VQBI_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqhu) ==   (VQHU_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqhi) ==   (VQHI_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqhf) ==   (VQHF_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqwu) ==   (VQWU_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqwi) ==   (VQWI_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqwf) ==   (VQWF_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqdu) ==   (VQDU_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqdi) ==   (VQDI_MVQL)))  goto fail;
    if (!TASSERT(mvql_funcof(vqdf) ==   (VQDF_MVQL)))  goto fail;
#if 0 // leave mvq_
}
#endif

#endif // MY_FUNCOF_TESTS

#if 0 // leave ___
}
#endif



// enter test absu
#if 0
    if (!TASSERT(0x0000000000000080ULL == absubi(( INT8_MIN+0)))) goto fail;
    if (!TASSERT(0x000000000000007fULL == absubi(( INT8_MIN+1)))) goto fail;
    if (!TASSERT(0x0000000000008000ULL == absuhi((INT16_MIN+0)))) goto fail;
    if (!TASSERT(0x0000000000007fffULL == absuhi((INT16_MIN+1)))) goto fail;
    if (!TASSERT(0x0000000080000000ULL == absuwi((INT32_MIN+0)))) goto fail;
    if (!TASSERT(0x000000007fffffffULL == absuwi((INT32_MIN+1)))) goto fail;
    if (!TASSERT(0x8000000000000000ULL == absudi((INT64_MIN+0)))) goto fail;
    if (!TASSERT(0x7fffffffffffffffULL == absudi((INT64_MIN+1)))) goto fail;

    vwbu = absuwbi(dupwbi(INT8_MIN));
    vwhu = absuwhi(dupwhi(INT16_MIN));
    vwwu = absuwwi(astvwi(INT32_MIN));

    if (!TASSERT(astvwwu(aswuwbu(vwbu))==0x80808080ull)) goto fail;
    if (!TASSERT(astvwwu(aswuwhu(vwhu))==0x80008000ull)) goto fail;
    if (!TASSERT(astvwwu(aswuwwu(vwwu))==0x80000000ull)) goto fail;

    vdbu = absudbi(dupdbi(INT8_MIN));
    vdhu = absudhi(dupdhi(INT16_MIN));
    vdwu = absudwi(dupdwi(INT32_MIN));
    vddu = absuddi(astvdi(INT64_MIN));

    if (!TASSERT(astvddu(asdudbu(vdbu))==0x8080808080808080ull)) goto fail;
    if (!TASSERT(astvddu(asdudhu(vdhu))==0x8000800080008000ull)) goto fail;
    if (!TASSERT(astvddu(asdudwu(vdwu))==0x8000000080000000ull)) goto fail;
    if (!TASSERT(astvddu(asduddu(vddu))==0x8000000000000000ull)) goto fail;

// leave test absu

// enter test abss
    if (!TASSERT(0x000000000000007fULL == abssbi(( INT8_MIN+0)))) goto fail;
    if (!TASSERT(0x000000000000007fULL == abssbi(( INT8_MIN+1)))) goto fail;
    if (!TASSERT(0x0000000000007fffULL == absshi((INT16_MIN+0)))) goto fail;
    if (!TASSERT(0x0000000000007fffULL == absshi((INT16_MIN+1)))) goto fail;
    if (!TASSERT(0x000000007fffffffULL == absswi((INT32_MIN+0)))) goto fail;
    if (!TASSERT(0x000000007fffffffULL == absswi((INT32_MIN+1)))) goto fail;
    if (!TASSERT(0x7fffffffffffffffULL == abssdi((INT64_MIN+0)))) goto fail;
    if (!TASSERT(0x7fffffffffffffffULL == abssdi((INT64_MIN+1)))) goto fail;
// leave test abss

    if (!TASSERT((int8_t) 0x0000000000000080ULL == abslbi(( INT8_MIN+0)))) goto fail;
    if (!TASSERT((int8_t) 0x000000000000007fULL == abslbi(( INT8_MIN+1)))) goto fail;
    if (!TASSERT((int16_t)0x0000000000008000ULL == abslhi((INT16_MIN+0)))) goto fail;
    if (!TASSERT((int16_t)0x0000000000007fffULL == abslhi((INT16_MIN+1)))) goto fail;
    if (!TASSERT((int32_t)0x0000000080000000ULL == abslwi((INT32_MIN+0)))) goto fail;
    if (!TASSERT((int32_t)0x000000007fffffffULL == abslwi((INT32_MIN+1)))) goto fail;
    if (!TASSERT((int64_t)0x8000000000000000ULL == absldi((INT64_MIN+0)))) goto fail;
    if (!TASSERT((int64_t)0x7fffffffffffffffULL == absldi((INT64_MIN+1)))) goto fail;

    kbu = -1;
    kbi = -1;
    khu = -1;
    khi = -1;
    kwu = -1;
    kwi = -1;
    kdu = -1;
    kdi = -1;

    if (!TASSERT(kbu == ceqsbu(1, 1))) goto fail;
    if (!TASSERT(kbu != ceqsbu(1, 0))) goto fail;

    if (!TASSERT(kbu == cnesbu(1, 0))) goto fail;
    if (!TASSERT(kbu != cnesbu(1, 1))) goto fail;

    if (!TASSERT(kbu == cgtsbu(1, 0))) goto fail;
    if (!TASSERT(kbu != cgtsbu(1, 1))) goto fail;

    if (!TASSERT(kbu == cgesbu(1, 0))) goto fail;
    if (!TASSERT(kbu == cgesbu(1, 1))) goto fail;
    if (!TASSERT(kbu != cgesbu(0, 1))) goto fail;

    if (!TASSERT(kbu == cltsbu(0, 1))) goto fail;
    if (!TASSERT(kbu != cltsbu(1, 1))) goto fail;

    if (!TASSERT(kbu == clesbu(0, 1))) goto fail;
    if (!TASSERT(kbu == clesbu(1, 1))) goto fail;
    if (!TASSERT(kbu != clesbu(1, 0))) goto fail;
    
    kyu = 1;
    kbc= INT8_MAX;
    kbi= INT8_MIN, khi= INT16_MIN, kwi= INT32_MIN, kdi= INT64_MIN;
    kbu=UINT8_MAX, khu=UINT16_MAX, kwu=UINT32_MAX, kdu=UINT64_MAX;

    if (!TASSERT(cvbzbu(kyu) == 1))         goto fail;
    if (!TASSERT(cvbzbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvbzbi(kbi) == 0))         goto fail;
    if (!TASSERT(cvbzbc(kbc) == kbc))       goto fail;
    if (!TASSERT(cvbzhu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvbzhi(khi) == 0))         goto fail;
    if (!TASSERT(cvbzwu(kwu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvbzwi(kwi) == 0))         goto fail;
    if (!TASSERT(cvbzdu(kdu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvbzdi(kdi) == 0))         goto fail;

    if (!TASSERT(cvbsyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvbsbu(kbu) == INT8_MAX))  goto fail;
    if (!TASSERT(cvbsbi(kbi) == INT8_MIN))  goto fail;
    if (!TASSERT(cvbsbc(kbc) == kbc))       goto fail;
    if (!TASSERT(cvbshu(khu) == INT8_MAX))  goto fail;
    if (!TASSERT(cvbshi(khi) == INT8_MIN))  goto fail;
    if (!TASSERT(cvbswu(kwu) == INT8_MAX))  goto fail;
    if (!TASSERT(cvbswi(kwi) == INT8_MIN))  goto fail;
    if (!TASSERT(cvbsdu(kdu) == INT8_MAX))  goto fail;
    if (!TASSERT(cvbsdi(kdi) == INT8_MIN))  goto fail;
    if (!TASSERT(cvbsdu(kdu) == INT8_MAX))  goto fail;

    if (!TASSERT(cvhzyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvhzbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvhzbi(kbi) == 0))         goto fail;
    if (!TASSERT(cvhzbc(kbc) == kbc))       goto fail;
    if (!TASSERT(cvhzhu(khu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvhzhi(khi) == 0))         goto fail;
    if (!TASSERT(cvhzwu(kwu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvhzwi(kwi) == 0))         goto fail;
    if (!TASSERT(cvhzdu(kdu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvhzdi(kdi) == 0))         goto fail;

    if (!TASSERT(cvhsyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvhsbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvhsbi(kbi) ==  INT8_MIN)) goto fail;
    if (!TASSERT(cvhsbc(kbc) ==  kbc))      goto fail;
    if (!TASSERT(cvhshu(khu) == INT16_MAX)) goto fail;
    if (!TASSERT(cvhshi(khi) == INT16_MIN)) goto fail;
    if (!TASSERT(cvhswu(kwu) == INT16_MAX)) goto fail;
    if (!TASSERT(cvhswi(kwi) == INT16_MIN)) goto fail;
    if (!TASSERT(cvhsdu(kdu) == INT16_MAX)) goto fail;
    if (!TASSERT(cvhsdi(kdi) == INT16_MIN)) goto fail;
    if (!TASSERT(cvhsdu(kdu) == INT16_MAX)) goto fail;

    if (!TASSERT(cvwzyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvwzbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvwzbi(kbi) == 0))         goto fail;
    if (!TASSERT(cvwzbc(kbc) == kbc))       goto fail;
    if (!TASSERT(cvwzhu(khu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvwzhi(khi) == 0))         goto fail;
    if (!TASSERT(cvwzwu(kwu) == UINT32_MAX))goto fail;
    if (!TASSERT(cvwzwi(kwi) == 0))         goto fail;
    if (!TASSERT(cvwzdu(kdu) == UINT32_MAX))goto fail;
    if (!TASSERT(cvwzdi(kdi) == 0))         goto fail;

    if (!TASSERT(cvwsyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvwsbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvwsbi(kbi) ==  INT8_MIN)) goto fail;
    if (!TASSERT(cvwsbc(kbc) ==  kbc))      goto fail;
    if (!TASSERT(cvwshu(khu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvwshi(khi) ==  INT16_MIN))goto fail;
    if (!TASSERT(cvwswu(kwu) == INT32_MAX)) goto fail;
    if (!TASSERT(cvwswi(kwi) == INT32_MIN)) goto fail;
    if (!TASSERT(cvwsdu(kdu) == INT32_MAX)) goto fail;
    if (!TASSERT(cvwsdi(kdi) == INT32_MIN)) goto fail;
    if (!TASSERT(cvwsdu(kdu) == INT32_MAX)) goto fail;

    if (!TASSERT(cvdzyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvdzbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvdzbi(kbi) == 0))         goto fail;
    if (!TASSERT(cvdzbc(kbc) == kbc))       goto fail;
    if (!TASSERT(cvdzhu(khu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvdzhi(khi) == 0))         goto fail;
    if (!TASSERT(cvdzwu(kwu) == UINT32_MAX))goto fail;
    if (!TASSERT(cvdzwi(kwi) == 0))         goto fail;
    if (!TASSERT(cvdzdu(kdu) == UINT64_MAX))goto fail;
    if (!TASSERT(cvdzdi(kdi) == 0))         goto fail;

    if (!TASSERT(cvdsyu(kyu) == 1))         goto fail;
    if (!TASSERT(cvdsbu(kbu) == UINT8_MAX)) goto fail;
    if (!TASSERT(cvdsbi(kbi) ==  INT8_MIN)) goto fail;
    if (!TASSERT(cvdsbc(kbc) ==  kbc))      goto fail;
    if (!TASSERT(cvdshu(khu) == UINT16_MAX))goto fail;
    if (!TASSERT(cvdshi(khi) ==  INT16_MIN))goto fail;
    if (!TASSERT(cvdswu(kwu) == UINT32_MAX))goto fail;
    if (!TASSERT(cvdswi(kwi) ==  INT32_MIN))goto fail;
    if (!TASSERT(cvdsdu(kdu) ==  INT64_MAX))goto fail;
    if (!TASSERT(cvdsdi(kdi) ==  INT64_MIN))goto fail;
    if (!TASSERT(cvdsdu(kdu) ==  INT64_MAX))goto fail;
#endif

#if 0
    union {
        struct {
            uint64_t 
                Pad: 37,
                Boy: 9,
                :0;
        };
        uint64_t R;
    } cow={.Boy=510}, dgh;
    
    vdhu = bfs1dhu(vdhu, 37, 9, 510);
    vddu = asdudhu(vdhu);
    kdu  = astvddu(vddu);
    dgh.R = kdu;
    printf(
        "cow.Boy=>%" UINT64_DFMT ", "
        "dgh.Boy=>%" UINT64_DFMT "\n",
        ((uint64_t) cow.Boy), 
        ((uint64_t) dgh.Boy)
    );
#endif

#if 0
    Vdhu t = newldhu(0, 1,0,0);
    t = vrev32_u16(t);
    printf("t[0] => %hu\n", vget_lane_u16(t,0));
#endif

#if 0
    Vwbu l = newlwbu('0', '1', '2', '3');
    Vwbu r = newlwbu('4', '5', '6', '7');
    Vwbu c = sprl(l, r, 1);
    outfwbu(
        c,
        stdout,
        "{" DUP4("'%c'", ", ") "}\n"
    );
#endif
    
    char yu64[65] = {0};
#if 0
    (void) toaydu(
        vsrid_n_u64(
            (0x1ull<<63),
            UINT64_MAX,
            56
        ), 
        yu64
    );
    printf("yu64#1 => %s\n", yu64);
    kdu = 1;
    kdu = kdu<<63;
    vddu = astv(kdu);
    kdu = sirr(UINT64_MAX, kdu, 56);
    (void) toaydu(kdu, yu64);
    printf("yu64#2 => %s\n", yu64);
    vddu = sirr(vdup_n_u64(UINT64_MAX), vddu, 56);
    (void) toaydu(astvddu(vddu), yu64);
    printf("yu64#3 => %s\n", yu64);
#endif

#if 0
    uchar data[77] = {0};
    sunradu((data+3), 1);
    uint64x1_t a = vdup_n_u64( lunracdu( (data+3) ));
    uint64x1_t b = vdup_n_u64(0b1);
    uint64x1_t c = sirlddu(a, b, 1);
    (void) toaydu(astvddu(c), yu64);
    
    printf("yu64#4 => %s\n", yu64);
    printf("vddu => %" UINT64_DFMT "\n", astvddu(c));
#endif

#if 0
    vwhu = unorwhu(15);
    printf("0x%04"  UINT16_XFMT ", ", get1whu(vwhu, 0));
    vdwu = unordwu(31);
    printf("0x%08"  UINT32_XFMT ", ", get1dwu(vdwu, 0));
    vqdu = unorqdu(63);
    printf("0x%016" UINT64_XFMT ", ", get1qdu(vqdu, 0));
    printf("\n");

#endif

#if 0
    printf("shl2hi(-12345, 1) => %i\n", shl2hi(-12345, 1));
    printf("shl2hi(-12345, 6) => %i\n", shl2hi(-12345, 6));
#endif
#if 0
    Quad q = {.B1.U=0, .B2.I=INT8_MIN};
    printf("q[8:24].i => %hi\n", lunnachu(&q.B1));
#endif
#if 0
    vqdu = mvql(0xdeadbeefULL);

    printf("vqdu[0] => 0x%" UINT64_XFMT "\n", vgetq_lane_u64(vqdu,0));
    printf("vqdu[1] => 0x%" UINT64_XFMT "\n", vgetq_lane_u64(vqdu,1));
#endif
#if 0
    printf(
        "yu  => 0x%04x\n"
        "bu  => 0x%04x\n""bi  => 0x%04x\n"
        "hu  => 0x%04x\n""hi  => 0x%04x\n""hf  => 0x%04x\n"
        "wu  => 0x%04x\n""wi  => 0x%04x\n""wf  => 0x%04x\n"
        "du  => 0x%04x\n""di  => 0x%04x\n""df  => 0x%04x\n",
        BOOL_REPR,
        UINT8_REPR, INT8_REPR,
        UINT16_REPR, INT16_REPR, FLT16_REPR,
        UINT32_REPR, INT32_REPR, FLT_REPR,
        UINT64_REPR, INT64_REPR, DBL_REPR
    );
#endif
#if 0
    printf(
        "kyu => 0x%04x\n"
        "kbu => 0x%04x\n""kbi => 0x%04x\n"
        ,
        reprof(kyu),
        reprof(kbu),reprof(kbi)
    );
    printf(
        "kyu => \"%s\"\n"
        "kbu => \"%s\"\n""kbi => \"%s\"\n"
        "khu => \"%s\"\n""khi => \"%s\"\n""khf => \"%s\"\n"
        "kwu => \"%s\"\n""kwi => \"%s\"\n""kwf => \"%s\"\n"
        "kdu => \"%s\"\n""kdi => \"%s\"\n""kdf => \"%s\"\n"
        ,
        reprof_sfx(reprof(kyu)),
        reprof_sfx(reprof(kbu)),reprof_sfx(reprof(kbi)),
        reprof_sfx(reprof(khu)),reprof_sfx(reprof(khi)),reprof_sfx(reprof(khf)),
        reprof_sfx(reprof(kwu)),reprof_sfx(reprof(kwi)),reprof_sfx(reprof(kwf)),
        reprof_sfx(reprof(kdu)),reprof_sfx(reprof(kdi)),reprof_sfx(reprof(kdf))
    );
#endif
    /*
    printf("kyu => \"%s\"\n", reprof_sfx(kyu));
    printf("kbu => \"%s\"\n", reprof_sfx(kbu));
    printf("kbi => \"%s\"\n", reprof_sfx(kbi));
    printf("khu => \"%s\"\n", reprof_sfx(khu));
    printf("khi => \"%s\"\n", reprof_sfx(khi));
    printf("khf => \"%s\"\n", reprof_sfx(FLT16_REPR));
    */
#if 0
    printf("reprof(khf) => 0x%04x\n", reprof(khf));
    printf("FLT16_REPR  => 0x%04x\n", FLT16_REPR);
    printf("reprof(khi) => 0x%04x\n", reprof(khi));
    printf("INT16_REPR  => 0x%04x\n", INT16_REPR);
#endif
    char const *rof;

#if 0
    if ((rof=reprof_sfx(  BOOL_REPR))) printf("_Bool:    \"%s\"\n",rof);
    if ((rof=reprof_sfx( UINT8_REPR))) printf("uint8_t:  \"%s\"\n",rof);
    if ((rof=reprof_sfx(  INT8_REPR))) printf("int8_t:   \"%s\"\n",rof);
    if ((rof=reprof_sfx(UINT16_REPR))) printf("uint16_t: \"%s\"\n",rof);
    if ((rof=reprof_sfx( INT16_REPR))) printf("int16_t:  \"%s\"\n",rof);
    if ((rof=reprof_sfx( FLT16_REPR))) printf("flt16_t:  \"%s\"\n",rof);
    if ((rof=reprof_sfx(UINT32_REPR))) printf("uint32_t: \"%s\"\n",rof);
    if ((rof=reprof_sfx( INT32_REPR))) printf("int32_t:  \"%s\"\n",rof);
    if ((rof=reprof_sfx(   FLT_REPR))) printf("float:    \"%s\"\n",rof);
    if ((rof=reprof_sfx(UINT64_REPR))) printf("uint64_t: \"%s\"\n",rof);
    if ((rof=reprof_sfx( INT64_REPR))) printf("int64_t:  \"%s\"\n",rof);
    if ((rof=reprof_sfx(   DBL_REPR))) printf("double:   \"%s\"\n",rof);
#endif

#if 0
    if ((rof=reprof_sfx(  VWYU_REPR))) printf("Vwyu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWBU_REPR))) printf("Vwbu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWBI_REPR))) printf("Vwbi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWHU_REPR))) printf("Vwhu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWHI_REPR))) printf("Vwhi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWHF_REPR))) printf("Vwhf: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWWU_REPR))) printf("Vwwu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWWI_REPR))) printf("Vwwi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VWWF_REPR))) printf("Vwwf: \"%s\"\n",rof);
#endif

#if 0
    if ((rof=reprof_sfx(  VDYU_REPR))) printf("Vdyu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDBU_REPR))) printf("Vdbu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDBI_REPR))) printf("Vdbi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDHU_REPR))) printf("Vdhu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDHI_REPR))) printf("Vdhi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDHF_REPR))) printf("Vdhf: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDWU_REPR))) printf("Vdwu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDWI_REPR))) printf("Vdwi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDWF_REPR))) printf("Vdwf: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDDU_REPR))) printf("Vddu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDDI_REPR))) printf("Vddi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VDDF_REPR))) printf("Vddf: \"%s\"\n",rof);
#endif

#if 0
    if ((rof=reprof_sfx(  VQYU_REPR))) printf("Vqyu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQBU_REPR))) printf("Vqbu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQBI_REPR))) printf("Vqbi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQHU_REPR))) printf("Vqhu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQHI_REPR))) printf("Vqhi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQHF_REPR))) printf("Vqhf: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQWU_REPR))) printf("Vqwu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQWI_REPR))) printf("Vqwi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQWF_REPR))) printf("Vqwf: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQDU_REPR))) printf("Vqdu: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQDI_REPR))) printf("Vqdi: \"%s\"\n",rof);
    if ((rof=reprof_sfx(  VQDF_REPR))) printf("Vqdf: \"%s\"\n",rof);
#endif

#if 0
    rof = reprof_sfx(reprof( kyu)); printf("kyu:%s\n", rof);
    rof = reprof_sfx(reprof( kbu)); printf("kbu:%s\n", rof);
    rof = reprof_sfx(reprof( kbi)); printf("kbi:%s\n", rof);
    rof = reprof_sfx(reprof( khu)); printf("khu:%s\n", rof);
    rof = reprof_sfx(reprof( khi)); printf("khi:%s\n", rof);
    rof = reprof_sfx(reprof( khf)); printf("khf:%s\n", rof);
    rof = reprof_sfx(reprof( kwu)); printf("kwu:%s\n", rof);
    rof = reprof_sfx(reprof( kwi)); printf("kwi:%s\n", rof);
    rof = reprof_sfx(reprof( kwf)); printf("kwf:%s\n", rof);
    rof = reprof_sfx(reprof( kdu)); printf("kdu:%s\n", rof);
    rof = reprof_sfx(reprof( kdi)); printf("kdi:%s\n", rof);
    rof = reprof_sfx(reprof( kdf)); printf("kdf:%s\n", rof);
#endif

#if 0
    rof = reprof_sfx(reprof(vwyu)); printf("wyu:%s\n", rof);
    rof = reprof_sfx(reprof(vwbu)); printf("wbu:%s\n", rof);
    rof = reprof_sfx(reprof(vwbi)); printf("wbi:%s\n", rof);
    rof = reprof_sfx(reprof(vwhu)); printf("whu:%s\n", rof);
    rof = reprof_sfx(reprof(vwhi)); printf("whi:%s\n", rof);
    rof = reprof_sfx(reprof(vwhf)); printf("whf:%s\n", rof);
    rof = reprof_sfx(reprof(vwwu)); printf("wwu:%s\n", rof);
    rof = reprof_sfx(reprof(vwwi)); printf("wwi:%s\n", rof);
    rof = reprof_sfx(reprof(vwwf)); printf("wwf:%s\n", rof);

    rof = reprof_sfx(reprof(vdyu)); printf("dyu:%s\n", rof);
    rof = reprof_sfx(reprof(vdbu)); printf("dbu:%s\n", rof);
    rof = reprof_sfx(reprof(vdbi)); printf("dbi:%s\n", rof);
    rof = reprof_sfx(reprof(vdhu)); printf("dhu:%s\n", rof);
    rof = reprof_sfx(reprof(vdhi)); printf("dhi:%s\n", rof);
    rof = reprof_sfx(reprof(vdhf)); printf("dhf:%s\n", rof);
    rof = reprof_sfx(reprof(vdwu)); printf("dwu:%s\n", rof);
    rof = reprof_sfx(reprof(vdwi)); printf("dwi:%s\n", rof);
    rof = reprof_sfx(reprof(vdwf)); printf("dwf:%s\n", rof);
    rof = reprof_sfx(reprof(vddu)); printf("ddu:%s\n", rof);
    rof = reprof_sfx(reprof(vddi)); printf("ddi:%s\n", rof);
    rof = reprof_sfx(reprof(vddf)); printf("ddf:%s\n", rof);

    rof = reprof_sfx(reprof(vqyu)); printf("qyu:%s\n", rof);
    rof = reprof_sfx(reprof(vqbu)); printf("qbu:%s\n", rof);
    rof = reprof_sfx(reprof(vqbi)); printf("qbi:%s\n", rof);
    rof = reprof_sfx(reprof(vqhu)); printf("qhu:%s\n", rof);
    rof = reprof_sfx(reprof(vqhi)); printf("qhi:%s\n", rof);
    rof = reprof_sfx(reprof(vqhf)); printf("qhf:%s\n", rof);
    rof = reprof_sfx(reprof(vqwu)); printf("qwu:%s\n", rof);
    rof = reprof_sfx(reprof(vqwi)); printf("qwi:%s\n", rof);
    rof = reprof_sfx(reprof(vqwf)); printf("qwf:%s\n", rof);
    rof = reprof_sfx(reprof(vqdu)); printf("qdu:%s\n", rof);
    rof = reprof_sfx(reprof(vqdi)); printf("qdi:%s\n", rof);
    rof = reprof_sfx(reprof(vqdf)); printf("qdf:%s\n", rof);
    
    kbu = 250;
    kbi = -50;
    printf("addlbu((kbu=250), (kbi=-50)) => %" UINT8_DFMT "\n", addlbu(kbu, kbi));
    /*
    else        printf("FLT16_REPR: NULL\n");
    */
#endif
#if 0
    printf("shllbi(-1, 0) => %hhi\n", shllbi(-1, 0));
    printf("shllbi(-1, 1) => %hhi\n", shllbi(-1, 1));
    printf("shllbi(-1, 6) => %hhi\n", shllbi(-1, 6));
    printf("shllbi(-1, 7) => %hhi\n", shllbi(-1, 7));
    printf("shllbi(-1, 8) => %hhi\n", shllbi(-1, 8));
#endif
#if 0
    vdbi = newldbi(-8, -4, -2, -1,   +0, +1, +3, +7);
    vdbi = shlldbi(vdbi,4);
    (void) outfdbi(vdbi, stdout, "{" DUP8("%hhi", ", ") "}");
    vwbu = lunwacbu("smfd");
    vdhu = newdhu(0xcdef, 0x89ab, 0x4567, 0x0123);
    vdhu = newddhu(vdhu, 3, 2, 1, 0);
    (void) outfdhu(vdhu, stdout, "{" DUP4("0x%hx", ", ") "}\n");
    printf("%x\n", unorwu(16));
    kwu = bfglwu(0xff0, 4, 4);
    printf("%x\n", kwu);
    vdbi = vcreate_u8(0x0706050403020100ULL);
    vdbu = bfgl(vdbu, 4, 4);
#endif
    struct {
        union {signed V0; struct {signed     I_0_7:7, :0;};};
        union {signed V1; struct {signed :1, I_1_7:7, :0;};};
        union {signed V2; struct {signed :2, I_2_7:7, :0;};};
        union {signed V3; struct {signed :3, I_3_7:7, :0;};};
    } bfgli = {
        .I_0_7=-64, 
        .I_1_7=-64,
        .I_2_7=-64, 
        .I_3_7=-64
    };

#if 0
    printf("I_0_7 = %hhi\n", (bfglbi)(bfgli.V0, 0, 7));
    printf("I_1_7 = %hhi\n", (bfglbi)(bfgli.V1, 1, 7));
    printf("I_2_7 = %hhi\n", (bfglbi)(bfgli.V2, 2, 7));
    printf("I_3_7 = %hhi\n", (bfglbi)(bfgli.V3, 3, 7));
#endif

#if 0
    struct {
        union {long V0; struct {long :1, Di_1_27:27, :0;};};
        union {long V1; struct {long :2, Di_2_27:27, :0;};};
    } bfgldi = {
        .Di_1_27=-67108864,
        .Di_2_27=+67108863,
    };
    printf("Di_1_27 = %li\n", bfgldi(bfgldi.V0, 1, 27));
    printf("Di_2_27 = %li\n", bfgldi(bfgldi.V1, 2, 27));
#endif

#if 0
    vdbu = vcreate_u8(0x0706050403020100ULL);
    vqbu = vcombine_u8(vdbu, vcreate_u8(0x0f0e0d0c0b0a0908ULL));
    vqbu = VQBU_BFGL(vqbu, 6, 4);
    (void) outfqbu(vqbu, stdout, "{" DUP16("0x%hhx", ", ") "}\n");
#endif

#if 0
    vdhu = vcreate_u16(0x0003000200010000ULL);
    vqhu = vcombine_u16(vdhu, vcreate_u8(0x0007000600050004ULL));
    vqhu = bfglqhu(vqhu, 5, 3);
    (void) outfqhu(vqhu, stdout, "{" DUP8("0x%hx", ", ") "}\n");
#endif

#if 0
    vdhu = vcreate_u16(0x0003000200010000ULL);
    vdhu = bfgldhu(vdhu, 1, 3);
    (void) outfdhu(vdhu, stdout, "{" DUP4("0x%hx", ", ") "}\n");
    printf("absuwi(INT_MAX) => %u\n", absuwi(INT_MAX));
    printf("absuwi(INT_MIN) => %u\n", absuwi(INT_MIN));
#endif

#if 0
    printf("absuwi(INT_MAX-0) => %u\n", abslwi((INT_MAX-0)));
    printf("absuwi(INT_MIN+1) => %u\n", abslwi((INT_MIN+1)));
#endif
#if 0
    printf("shl2bi( INT8_MIN, 8) => %hi\n",INT8_SHL2(INT8_MIN, 8));
    printf("shl2hi(INT16_MIN,16) => %i\n", INT16_SHL2(INT16_MIN,16));
#endif
#if 0
    q.W0.I = shllwi(-100,3);
    q.W1.I = shlrwi(-100,3);
    printf("(-100<<3) => %+" INT64_DFMT " (-800?)\n", q.D0.I);
    q.W0.I = shllwi(+100,3);
    q.W1.I = shlrwi(+100,3);
    printf("(-100<<3) => %+" INT64_DFMT " (+800?)\n", q.D0.I);
    printf("mul2(255,255) => %hu\n", mul2bu(255,255));
#endif


#if 0
    Vdbu nie    = newdbu('1','2','3','.',  '.','.','.','.');
    vdbu = bfsldbu(vdbu, 1, 3, nie);
    Vddu sel = unolddu(24);
    sel = vshl_n_u64(sel, 8);
    nie = vshl_n_u64(nie, 8);
    nie = vand_u64(nie, sel);
    (void) outfdbu(nie, stdout, "nie => '" DUP8("%hhu",",") "'\n");
   // printf("sel = 0x%016" UINT64_XFMT "\n", vget_lane_u64(sel,0));
    vdbu = vbic_u64(vdbu, sel);
    vdbu = vorr_u64(vdbu, nie);
#endif

#if 0
    vddu = asdudbu(nie);
    vddu = vshl_n_u64(vddu, 8);
    Vddu sel = vdup_n_u64( ((UINT64_MAX>>(64-24))<<8) );
    vddu = vbic_u64(vddu, sel);
    nie = vand_u64(nie, sel);
    vddu = vorr_u64(vddu, nie);
    vdbu = asbuddu(vddu);
#endif

#if 0
    vqbu        = newqbu(
        '0','_','_','_',  '_','_','_','_',
        '_','_','a','b',  'c','d','e','f'
    );
    Vqbu nie    = newqbu(
        '1','2','3','4',  '5','6','7','8',
        '9','.','.','.', '.','.','.','.'
    );
    //vqbu = bfslqbu(vqbu, 1, 9, nie);
    vqbu = bfslqbu(vqbu, 0,16,nie);
    (void) outfqbu(vqbu, stdout, "qbu => " DUP16("'%c'",",") "\n");
  //  (void) outfqbu(vqbu, stdout, "qbu => '" DUP16("%hhu",",") "'\n");
#endif
    char str[256] = {0};
    char *end = str;
    
#if 0
    vqbu = dupqbu(' ');
    (void) outfqbu(vqbu, stdout, "qbu => " DUP16("'%c'",",") "\n");
    vqbu = (dupqbu)(' ',+5);
    (void) outfqbu(vqbu, stdout, "qbu => " DUP16("'\\x%02hhx'",",") "\n");
#endif

#if 0
    vqhu = dupqhu(0xbeef);
    outfqhu(vqhu, stdout, "dupqhu(0xbeef) => " DUP8("%04hx", ", ") "\n");
    vqhu = dupqhu(0xbeef,+2);
    outfqhu(vqhu, stdout, "dupqhu(0xbeef,+2) => " DUP8("%04hx", ", ") "\n");
    vqhu = dupqhu(0xbeef,-2);
    outfqhu(vqhu, stdout, "dupqhu(0xbeef,-2) => " DUP8("%04hx", ", ") "\n");
    vqhu = (dupqhu)(0xbeef, 0);
    outfqhu(vqhu, stdout, "(dupqhu)(0xbeef) => " DUP8("%04hx", ", ") "\n");
    vqhu = (dupqhu)(0xbeef,+2);
    outfqhu(vqhu, stdout, "(dupqhu)(0xbeef,+2) => " DUP8("%04hx", ", ") "\n");
    vqhu = (dupqhu)(0xbeef,-2);
    outfqhu(vqhu, stdout, "(dupqhu)(0xbeef,-2) => " DUP8("%04hx", ", ") "\n");
    vqwu = dupqwu(0xdeadbeef, 0);
    outfqwu(vqwu, stdout, "dupqwu(0xdeadbeef, 0) => " DUP4("%04x", ", ") "\n");
#endif

#if 0
    vdbu = dupdbu(8, +0);
    outfdbu(vdbu, stdout, "(dupdbu(8,+0)) => " DUP8("%hhd", "," ) "\n");
    vdbu = (dupdbu)(8, +0);
    outfdbu(vdbu, stdout, "(dupdbu)(8,+0) => " DUP8("%hhd", "," ) "\n");

    vdbu = dupdbu(8, +2);
    outfdbu(vdbu, stdout, "(dupdbu(8,+2)) => " DUP8("%hhd", "," ) "\n");
    vdbu = (dupdbu)(8, +2);
    outfdbu(vdbu, stdout, "(dupdbu)(8,+2) => " DUP8("%hhd", "," ) "\n");

    vdbu = dupdbu(8, -2);
    outfdbu(vdbu, stdout, "(dupdbu(8,-2)) => " DUP8("%hhd", "," ) "\n");
    vdbu = (dupdbu)(8, -2);
    outfdbu(vdbu, stdout, "(dupdbu)(8,-2) => " DUP8("%hhd", "," ) "\n");
#endif

#if 0
// +7
    vdbu = (dupdbu(123,+7));
    outfdbu(vdbu, stdout, "(dupdbu(123,+7)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,+7);
    outfdbu(vdbu, stdout, "(dupdbu)(123,+7) => " DUP8("%hhu", "," ) "\n");

// +6
    vdbu = (dupdbu(123,+6));
    outfdbu(vdbu, stdout, "(dupdbu(123,+6)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,+6);
    outfdbu(vdbu, stdout, "(dupdbu)(123,+6) => " DUP8("%hhu", "," ) "\n");

// +1
    vdbu = (dupdbu(123,+1));
    outfdbu(vdbu, stdout, "(dupdbu(123,+1)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,+1);
    outfdbu(vdbu, stdout, "(dupdbu)(123,+1) => " DUP8("%hhu", "," ) "\n");

// +0
    vdbu = (dupdbu(123,+0));
    outfdbu(vdbu, stdout, "(dupdbu(123,+0)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu(123));
    outfdbu(vdbu, stdout, "(dupdbu(123))    => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,+0);
    outfdbu(vdbu, stdout, "(dupdbu)(123,+0) => " DUP8("%hhu", "," ) "\n");

// -1
    vdbu = (dupdbu(123,-1));
    outfdbu(vdbu, stdout, "(dupdbu(123,-1)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,-1);
    outfdbu(vdbu, stdout, "(dupdbu)(123,-1) => " DUP8("%hhu", "," ) "\n");

// -2
    vdbu = (dupdbu(123,-2));
    outfdbu(vdbu, stdout, "(dupdbu(123,-2)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,-2);
    outfdbu(vdbu, stdout, "(dupdbu)(123,-2) => " DUP8("%hhu", "," ) "\n");

// -7
    vdbu = (dupdbu(123,-7));
    outfdbu(vdbu, stdout, "(dupdbu(123,-7)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,-7);
    outfdbu(vdbu, stdout, "(dupdbu)(123,-7) => " DUP8("%hhu", "," ) "\n");

// -7
    vdbu = (dupdbu(123,-8));
    outfdbu(vdbu, stdout, "(dupdbu(123,-8)) => " DUP8("%hhu", "," ) "\n");
    vdbu = (dupdbu)(123,-8);
    outfdbu(vdbu, stdout, "(dupdbu)(123,-8) => " DUP8("%hhu", "," ) "\n");
#endif

#if 0
// +3
    vdhi = (dupdhi(12345,+3));
    outfdhi(vdhi, stdout, "(dupdhi(12345,+3)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,+3);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,+3) => " DUP4("%hi", "," ) "\n");

// +2
    vdhi = (dupdhi(12345,+2));
    outfdhi(vdhi, stdout, "(dupdhi(12345,+2)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,+2);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,+2) => " DUP4("%hi", "," ) "\n");

// +1
    vdhi = (dupdhi(12345,+1));
    outfdhi(vdhi, stdout, "(dupdhi(12345,+1)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,+1);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,+1) => " DUP4("%hi", "," ) "\n");

// 0
    vdhi = (dupdhi(12345,0));
    outfdhi(vdhi, stdout, "(dupdhi(12345,+0)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi(12345));
    outfdhi(vdhi, stdout, "(dupdhi(12345))    => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,0);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,+0) => " DUP4("%hi", "," ) "\n");

// -1
    vdhi = (dupdhi(12345,-1));
    outfdhi(vdhi, stdout, "(dupdhi(12345,-1)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,-1);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,-1) => " DUP4("%hi", "," ) "\n");

// -2
    vdhi = (dupdhi(12345,-2));
    outfdhi(vdhi, stdout, "(dupdhi(12345,-2)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,-2);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,-2) => " DUP4("%hi", "," ) "\n");

// -3
    vdhi = (dupdhi(12345,-3));
    outfdhi(vdhi, stdout, "(dupdhi(12345,-3)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,-3);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,-3) => " DUP4("%hi", "," ) "\n");

// -4
    vdhi = (dupdhi(12345,-4));
    outfdhi(vdhi, stdout, "(dupdhi(12345,-4)) => " DUP4("%hi", "," ) "\n");

    vdhi = (dupdhi)(12345,-4);
    outfdhi(vdhi, stdout, "(dupdhi)(12345,-4) => " DUP4("%hi", "," ) "\n");
#endif

#if 0

// +1
    vdwu = (dupdwu(0xf00d,+2));
    outfdwu(vdwu, stdout, "(dupdwu(0xf00d,+2)) => " DUP2("%04x", "," ) "\n");

    vdwu = (dupdwu)(0xf00d,+2);
    outfdwu(vdwu, stdout, "(dupdwu)(0xf00d,+2) => " DUP2("%04x", "," ) "\n");

// +1
    vdwu = (dupdwu(0xf00d,+1));
    outfdwu(vdwu, stdout, "(dupdwu(0xf00d,+1)) => " DUP2("%04x", "," ) "\n");

    vdwu = (dupdwu)(0xf00d,+1);
    outfdwu(vdwu, stdout, "(dupdwu)(0xf00d,+1) => " DUP2("%04x", "," ) "\n");

// 0
    vdwu = (dupdwu(0xf00d,0));
    outfdwu(vdwu, stdout, "(dupdwu(0xf00d,+0)) => " DUP2("%04x", "," ) "\n");

    vdwu = (dupdwu(0xf00d));
    outfdwu(vdwu, stdout, "(dupdwu(0xf00d))    => " DUP2("%04x", "," ) "\n");

    vdwu = (dupdwu)(0xf00d,0);
    outfdwu(vdwu, stdout, "(dupdwu)(0xf00d,+0) => " DUP2("%04x", "," ) "\n");

// -1
    vdwu = (dupdwu(0xf00d,-1));
    outfdwu(vdwu, stdout, "(dupdwu(0xf00d,-1)) => " DUP2("%04x", "," ) "\n");

    vdwu = (dupdwu)(0xf00d,-1);
    outfdwu(vdwu, stdout, "(dupdwu)(0xf00d,-1) => " DUP2("%04x", "," ) "\n");

// -2
    vdwu = (dupdwu(0xf00d,-2));
    outfdwu(vdwu, stdout, "(dupdwu(0xf00d,-2)) => " DUP2("%04x", "," ) "\n");

    vdwu = (dupdwu)(0xf00d,-2);
    outfdwu(vdwu, stdout, "(dupdwu)(0xf00d,-2) => " DUP2("%04x", "," ) "\n");

#endif

// +3
#if 0
    vwbu = (dupwbu(1,+3));
    outfwbu(vwbu, stdout, "(dupwbu(1,+3)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,+3);
    outfwbu(vwbu, stdout, "(dupwbu)(1,+3) => " DUP4("%hhu", "," ) "\n");

// +2
    vwbu = (dupwbu(1,+2));
    outfwbu(vwbu, stdout, "(dupwbu(1,+2)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,+2);
    outfwbu(vwbu, stdout, "(dupwbu)(1,+2) => " DUP4("%hhu", "," ) "\n");

// +1
    vwbu = (dupwbu(1,+1));
    outfwbu(vwbu, stdout, "(dupwbu(1,+1)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,+1);
    outfwbu(vwbu, stdout, "(dupwbu)(1,+1) => " DUP4("%hhu", "," ) "\n");

// +0
    vwbu = (dupwbu(1,+0));
    outfwbu(vwbu, stdout, "(dupwbu(1,+0)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu(1));
    outfwbu(vwbu, stdout, "(dupwbu(1))    => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,+0);
    outfwbu(vwbu, stdout, "(dupwbu)(1,+0) => " DUP4("%hhu", "," ) "\n");

// -1
    vwbu = (dupwbu(1,-1));
    outfwbu(vwbu, stdout, "(dupwbu(1,-1)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,-1);
    outfwbu(vwbu, stdout, "(dupwbu)(1,-1) => " DUP4("%hhu", "," ) "\n");

// -2
    vwbu = (dupwbu(1,-2));
    outfwbu(vwbu, stdout, "(dupwbu(1,-2)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,-2);
    outfwbu(vwbu, stdout, "(dupwbu)(1,-2) => " DUP4("%hhu", "," ) "\n");

// -3
    vwbu = (dupwbu(1,-3));
    outfwbu(vwbu, stdout, "(dupwbu(1,-3)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,-3);
    outfwbu(vwbu, stdout, "(dupwbu)(1,-3) => " DUP4("%hhu", "," ) "\n");

// -4
    vwbu = (dupwbu(1,-4));
    outfwbu(vwbu, stdout, "(dupwbu(1,-4)) => " DUP4("%hhu", "," ) "\n");
    vwbu = (dupwbu)(1,-4);
    outfwbu(vwbu, stdout, "(dupwbu)(1,-4) => " DUP4("%hhu", "," ) "\n");
#endif

    
#if 0
    printf("SCHAR_ABSU(SCHAR_MIN+0) => %hhu\n", SCHAR_ABSU((SCHAR_MIN+0)));
    printf("SCHAR_ABSU(SCHAR_MIN+1) => %hhu\n", SCHAR_ABSU((SCHAR_MIN+1)));
    printf("SCHAR_ABSU(         -2) => %hhu\n", SCHAR_ABSU(-2));
    printf("SCHAR_ABSU(         -1) => %hhu\n", SCHAR_ABSU(-1));
    printf("SCHAR_ABSU(         +0) => %hhu\n", SCHAR_ABSU(+0));
    printf("SCHAR_ABSU(         +1) => %hhu\n", SCHAR_ABSU(+1));
    printf("SCHAR_ABSU(SCHAR_MAX-1) => %hhu\n", SCHAR_ABSU((SCHAR_MAX-1)));
    printf("SCHAR_ABSU(SCHAR_MAX-0) => %hhu\n", SCHAR_ABSU((SCHAR_MAX-0)));
    printf("\n");

    printf("SHRT_ABSU(SHRT_MIN+0) => %hu\n", SHRT_ABSU((SHRT_MIN+0)));
    printf("SHRT_ABSU(SHRT_MIN+1) => %hu\n", SHRT_ABSU((SHRT_MIN+1)));
    printf("SHRT_ABSU(        -2) => %hu\n", SHRT_ABSU(-2));
    printf("SHRT_ABSU(        -1) => %hu\n", SHRT_ABSU(-1));
    printf("SHRT_ABSU(        +0) => %hu\n", SHRT_ABSU(+0));
    printf("SHRT_ABSU(        +1) => %hu\n", SHRT_ABSU(+1));
    printf("SHRT_ABSU(SHRT_MAX-1) => %hu\n", SHRT_ABSU((SHRT_MAX-1)));
    printf("SHRT_ABSU(SHRT_MAX-0) => %hu\n", SHRT_ABSU((SHRT_MAX-0)));
    printf("\n");

    printf("INT_ABSU(INT_MIN+0) => %u\n", INT_ABSU((INT_MIN+0)));
    printf("INT_ABSU(INT_MIN+1) => %u\n", INT_ABSU((INT_MIN+1)));
    printf("INT_ABSU(       -2) => %u\n", INT_ABSU(-2));
    printf("INT_ABSU(       -1) => %u\n", INT_ABSU(-1));
    printf("INT_ABSU(       +0) => %u\n", INT_ABSU(+0));
    printf("INT_ABSU(       +1) => %u\n", INT_ABSU(+1));
    printf("INT_ABSU(INT_MAX-1) => %u\n", INT_ABSU((INT_MAX-1)));
    printf("INT_ABSU(INT_MAX-0) => %u\n", INT_ABSU((INT_MAX-0)));

    printf("LONG_ABSU(LONG_MIN+0) => %lu\n", LONG_ABSU((LONG_MIN+0)));
    printf("LONG_ABSU(LONG_MIN+1) => %lu\n", LONG_ABSU((LONG_MIN+1)));
    printf("LONG_ABSU(        -2) => %lu\n", LONG_ABSU(-2));
    printf("LONG_ABSU(        -1) => %lu\n", LONG_ABSU(-1));
    printf("LONG_ABSU(        +0) => %lu\n", LONG_ABSU(+0));
    printf("LONG_ABSU(        +1) => %lu\n", LONG_ABSU(+1));
    printf("LONG_ABSU(LONG_MAX-1) => %lu\n", LONG_ABSU((LONG_MAX-1)));
    printf("LONG_ABSU(LONG_MAX-0) => %lu\n", LONG_ABSU((LONG_MAX-0)));
    printf("\n");

    printf("LLONG_ABSU(LLONG_MIN+0) => %llu\n", LLONG_ABSU((LLONG_MIN+0)));
    printf("LLONG_ABSU(LLONG_MIN+1) => %llu\n", LLONG_ABSU((LLONG_MIN+1)));
    printf("LLONG_ABSU(         -2) => %llu\n", LLONG_ABSU(-2));
    printf("LLONG_ABSU(         -1) => %llu\n", LLONG_ABSU(-1));
    printf("LLONG_ABSU(         +0) => %llu\n", LLONG_ABSU(+0));
    printf("LLONG_ABSU(         +1) => %llu\n", LLONG_ABSU(+1));
    printf("LLONG_ABSU(LLONG_MAX-1) => %llu\n", LLONG_ABSU((LLONG_MAX-1)));
    printf("LLONG_ABSU(LLONG_MAX-0) => %llu\n", LLONG_ABSU((LLONG_MAX-0)));
    printf("\n");

    printf("absuqi(QUAD_IMIN+0) => %s\n",toadqu(absuqi(QUAD_IMIN.I), str, &end));
    printf("absuqi(QUAD_IMIN+1) => %s\n",toadqu(absuqi(icrlqi(QUAD_IMIN.I)),str,&end));
    printf("absuqi(INT64_MIN+0) => %s\n",toadqu(absuqi(cvqidi((INT64_MIN+0))),str,&end));
    printf("absuqi(INT64_MIN+1) => %s\n",toadqu(absuqi(cvqidi((INT64_MIN+1))),str,&end));
    printf("absuqi(INT32_MIN+0) => %s\n",toadqu(absuqi(cvqidi((INT32_MIN+0))),str,&end));
    printf("absuqi(INT32_MIN+1) => %s\n",toadqu(absuqi(cvqidi((INT32_MIN+1))),str,&end));
    printf("absuqi(INT16_MIN+0) => %s\n",toadqu(absuqi(cvqidi((INT16_MIN+0))),str,&end));
    printf("absuqi(INT16_MIN+1) => %s\n",toadqu(absuqi(cvqidi((INT16_MIN+1))),str,&end));
    printf("absuqi( INT8_MIN+0) => %s\n",toadqu(absuqi(cvqidi((INT8_MIN+0))),str,&end));
    printf("absuqi( INT8_MIN+1) => %s\n",toadqu(absuqi(cvqidi((INT8_MIN+1))),str,&end));
    printf("absuqi(         -2) => %s\n",toadqu(absuqi(cvqiwi(-2)),str,&end));
    printf("absuqi(         -1) => %s\n",toadqu(absuqi(cvqiwi(-1)),str,&end));
    printf("absuqi(         +0) => %s\n",toadqu(absuqi(cvqiwi(+0)),str,&end));
    printf("absuqi(         +1) => %s\n",toadqu(absuqi(cvqiwi(+1)),str,&end));
    printf("absuqi(         +2) => %s\n",toadqu(absuqi(cvqiwi(+2)),str,&end));
    printf("absuqi( INT8_MAX-1) => %s\n",toadqu(absuqi(cvqidi((INT8_MAX-1))),str,&end));
    printf("absuqi( INT8_MAX-0) => %s\n",toadqu(absuqi(cvqidi((INT8_MAX-0))),str,&end));
    printf("absuqi(INT16_MAX-1) => %s\n",toadqu(absuqi(cvqidi((INT16_MAX-1))),str,&end));
    printf("absuqi(INT16_MAX-0) => %s\n",toadqu(absuqi(cvqidi((INT16_MAX-0))),str,&end));
    printf("absuqi(INT32_MAX-1) => %s\n",toadqu(absuqi(cvqidi((INT32_MAX-1))),str,&end));
    printf("absuqi(INT32_MAX-0) => %s\n",toadqu(absuqi(cvqidi((INT32_MAX-0))),str,&end));
    printf("absuqi(INT64_MAX-1) => %s\n",toadqu(absuqi(cvqidi((INT64_MAX-1))),str,&end));
    printf("absuqi(INT64_MAX-0) => %s\n",toadqu(absuqi(cvqidi((INT64_MAX-0))),str,&end));
    printf("absuqi(QUAD_IMAX-1) => %s\n",toadqu(absuqi(dcrlqi(QUAD_IMAX.I)),str,&end));
    printf("absuqi(QUAD_IMAX-0) => %s\n",toadqu(absuqi(QUAD_IMAX.I), str, &end));
#endif

#if 0
    printf("SCHAR_REMN(+5, +2) => %+hhi\n", SCHAR_REMN(+5,+2));
    printf("SCHAR_REMN(+4, +2) => %+hhi\n", SCHAR_REMN(+4,+2));
    printf("SCHAR_REMN(+3, +2) => %+hhi\n", SCHAR_REMN(+3,+2));
    printf("SCHAR_REMN(+2, +2) => %+hhi\n", SCHAR_REMN(+2,+2));
    printf("SCHAR_REMN(+1, +2) => %+hhi\n", SCHAR_REMN(+1,+2));
    printf("SCHAR_REMN(+0, +2) => %+hhi\n", SCHAR_REMN(+0,+2));
    printf("SCHAR_REMN(-1, +2) => %+hhi\n", SCHAR_REMN(-1,+2));
    printf("SCHAR_REMN(-2, +2) => %+hhi\n", SCHAR_REMN(-2,+2));
    printf("SCHAR_REMN(-3, +2) => %+hhi\n", SCHAR_REMN(-3,+2));
    printf("SCHAR_REMN(-4, +2) => %+hhi\n", SCHAR_REMN(-4,+2));
    printf("SCHAR_REMN(-5, +2) => %+hhi\n", SCHAR_REMN(-5,+2));
#endif

#if 0
    printf("SCHAR_REMN(+5, -2) => %+hhi\n", SCHAR_REMN(+5,-2));
    printf("SCHAR_REMN(+4, -2) => %+hhi\n", SCHAR_REMN(+4,-2));
    printf("SCHAR_REMN(+3, -2) => %+hhi\n", SCHAR_REMN(+3,-2));
    printf("SCHAR_REMN(+2, -2) => %+hhi\n", SCHAR_REMN(+2,-2));
    printf("SCHAR_REMN(+1, -2) => %+hhi\n", SCHAR_REMN(+1,-2));
    printf("SCHAR_REMN(+0, -2) => %+hhi\n", SCHAR_REMN(+0,-2));
    printf("SCHAR_REMN(-1, -2) => %+hhi\n", SCHAR_REMN(-1,-2));
    printf("SCHAR_REMN(-2, -2) => %+hhi\n", SCHAR_REMN(-2,-2));
    printf("SCHAR_REMN(-3, -2) => %+hhi\n", SCHAR_REMN(-3,-2));
    printf("SCHAR_REMN(-4, -2) => %+hhi\n", SCHAR_REMN(-4,-2));
    printf("SCHAR_REMN(-5, -2) => %+hhi\n", SCHAR_REMN(-5,-2));
#endif

#if 0
    for (int lhs=-2; lhs < 3; lhs++)
    {
        printf("lhs=%+i\n", lhs);
        for (int rhs=1; rhs < 4; rhs++)
        {
            if (lhs > 0)
            printf(" UCHAR_DIVN(%+i, %+i) => %+hhi\n", lhs, rhs, UCHAR_DIVN(lhs,rhs));
            printf(" SCHAR_DIVN(%+i, %+i) => %+hhi\n", lhs, rhs, SCHAR_DIVN(lhs,rhs));
            if (lhs > 0)
            printf(" USHRT_DIVN(%+i, %+i) => %+hi\n", lhs, rhs, USHRT_DIVN(lhs,rhs));
            printf("  SHRT_DIVN(%+i, %+i) => %+hi\n", lhs, rhs,  SHRT_DIVN(lhs,rhs));
            if (lhs > 0)
            printf("  UINT_DIVN(%+i, %+i) => %+i\n", lhs, rhs, UINT_DIVN(lhs,rhs));
            printf("   INT_DIVN(%+i, %+i) => %+i\n", lhs, rhs,  INT_DIVN(lhs,rhs));
            if (lhs > 0)
            printf(" ULONG_DIVN(%+i, %+i) => %+li\n", lhs, rhs, ULONG_DIVN(lhs,rhs));
            printf("  LONG_DIVN(%+i, %+i) => %+li\n", lhs, rhs,  LONG_DIVN(lhs,rhs));
            if (lhs > 0)
            printf("ULLONG_DIVN(%+i, %+i) => %+lli\n", lhs, rhs, ULLONG_DIVN(lhs,rhs));
            printf(" LLONG_DIVN(%+i, %+i) => %+lli\n", lhs, rhs,  LLONG_DIVN(lhs,rhs));
            printf("\n");
        }
    }
#endif
 
#if 0
    schar rbi;
    
    kbi = SCHAR_MODN(+5,+2,&rbi); 
    printf("SCHAR_MODN(+5, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(+4,+2,&rbi); 
    printf("SCHAR_MODN(+4, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(+3,+2,&rbi); 
    printf("SCHAR_MODN(+3, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(+2,+2,&rbi); 
    printf("SCHAR_MODN(+2, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(+1,+2,&rbi); 
    printf("SCHAR_MODN(+1, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(+0,+2,&rbi); 
    printf("SCHAR_MODN(+0, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(-1,+2,&rbi); 
    printf("SCHAR_MODN(-1, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(-2,+2,&rbi); 
    printf("SCHAR_MODN(-2, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(-3,+2,&rbi); 
    printf("SCHAR_MODN(-3, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(-4,+2,&rbi); 
    printf("SCHAR_MODN(-4, +2) => {%+hhi,%+hhi}\n", kbi,rbi);
    kbi = SCHAR_MODN(-5,+2,&rbi); 
    printf("SCHAR_MODN(-5, +2) => {%+hhi,%+hhi}\n", kbi,rbi);

#endif
#if 0
    if (0)
    {
        
    
    printf("UCHAR_CSZR( UCHAR_MAX) => %hhu\n", UCHAR_CSZR(UCHAR_MAX));
    printf("UCHAR_CSZR((0&(1<<0))) => %hhu\n", UCHAR_CSZR(0));

    printf("UCHAR_CSZR((0|(1<<0))) => %hhu\n", UCHAR_CSZR( (0|(1<<0)) ));
    printf("UCHAR_CSZR((1|(1<<0))) => %hhu\n", UCHAR_CSZR( (1|(1<<0)) ));

    printf("UCHAR_CSZR((0|(1<<1))) => %hhu\n", UCHAR_CSZR( (0|(1<<1)) ));
    printf("UCHAR_CSZR((1|(1<<1))) => %hhu\n", UCHAR_CSZR( (1|(1<<1)) ));

    printf("UCHAR_CSZR((0|(1<<2))) => %hhu\n", UCHAR_CSZR( (0|(1<<2)) ));
    printf("UCHAR_CSZR((1|(1<<2))) => %hhu\n", UCHAR_CSZR( (1|(1<<2)) ));

    printf("UCHAR_CSZR((0|(1<<6))) => %hhu\n", UCHAR_CSZR( (0|(1<<6)) ));
    printf("UCHAR_CSZR((1|(1<<6))) => %hhu\n", UCHAR_CSZR( (1|(1<<6)) ));

    printf("UCHAR_CSZR((0|(1<<7))) => %hhu\n", UCHAR_CSZR( (0|(1<<7)) ));
    printf("UCHAR_CSZR((1|(1<<7))) => %hhu\n", UCHAR_CSZR( (1|(1<<7)) ));

    printf("UCHAR_CSZR((0|(1<<8))) => %hhu\n", UCHAR_CSZR( (0|(1<<8)) ));
    printf("UCHAR_CSZR((1|(1<<8))) => %hhu\n", UCHAR_CSZR( (1|(1<<8)) ));
    printf("\n");

    printf("SCHAR_CSZR( SCHAR_MAX) => %hhi\n", SCHAR_CSZR(SCHAR_MAX));
    printf("SCHAR_CSZR((0&(1<<0))) => %hhi\n", SCHAR_CSZR(0));

    printf("SCHAR_CSZR((0|(1<<0))) => %hhi\n", SCHAR_CSZR( (0|(1<<0)) ));
    printf("SCHAR_CSZR((1|(1<<0))) => %hhi\n", SCHAR_CSZR( (1|(1<<0)) ));

    printf("SCHAR_CSZR((0|(1<<1))) => %hhi\n", SCHAR_CSZR( (0|(1<<1)) ));
    printf("SCHAR_CSZR((1|(1<<1))) => %hhi\n", SCHAR_CSZR( (1|(1<<1)) ));

    printf("SCHAR_CSZR((0|(1<<2))) => %hhi\n", SCHAR_CSZR( (0|(1<<2)) ));
    printf("SCHAR_CSZR((1|(1<<2))) => %hhi\n", SCHAR_CSZR( (1|(1<<2)) ));

    printf("SCHAR_CSZR((0|(1<<6))) => %hhi\n", SCHAR_CSZR( (0|(1<<6)) ));
    printf("SCHAR_CSZR((1|(1<<6))) => %hhi\n", SCHAR_CSZR( (1|(1<<6)) ));

    printf("SCHAR_CSZR((0|(1<<7))) => %hhi\n", SCHAR_CSZR( (0|(1<<7)) ));
    printf("SCHAR_CSZR((1|(1<<7))) => %hhi\n", SCHAR_CSZR( (1|(1<<7)) ));

    printf("SCHAR_CSZR((0|(1<<8))) => %hhi\n", SCHAR_CSZR( (0|(1<<8)) ));
    printf("SCHAR_CSZR((1|(1<<8))) => %hhi\n", SCHAR_CSZR( (1|(1<<8)) ));
    printf("\n");

    printf("CHAR_CSZR( CHAR_MAX) => %u\n", CHAR_CSZR(CHAR_MAX));
    printf("CHAR_CSZR((0&(1<<0))) => %u\n", CHAR_CSZR(0));

    printf("CHAR_CSZR((0|(1<<0))) => %u\n", CHAR_CSZR( (0|(1<<0)) ));
    printf("CHAR_CSZR((1|(1<<0))) => %u\n", CHAR_CSZR( (1|(1<<0)) ));

    printf("CHAR_CSZR((0|(1<<1))) => %u\n", CHAR_CSZR( (0|(1<<1)) ));
    printf("CHAR_CSZR((1|(1<<1))) => %u\n", CHAR_CSZR( (1|(1<<1)) ));

    printf("CHAR_CSZR((0|(1<<2))) => %u\n", CHAR_CSZR( (0|(1<<2)) ));
    printf("CHAR_CSZR((1|(1<<2))) => %u\n", CHAR_CSZR( (1|(1<<2)) ));

    printf("CHAR_CSZR((0|(1<<6))) => %u\n", CHAR_CSZR( (0|(1<<6)) ));
    printf("CHAR_CSZR((1|(1<<6))) => %u\n", CHAR_CSZR( (1|(1<<6)) ));

    printf("CHAR_CSZR((0|(1<<7))) => %u\n", CHAR_CSZR( (0|(1<<7)) ));
    printf("CHAR_CSZR((1|(1<<7))) => %u\n", CHAR_CSZR( (1|(1<<7)) ));

    printf("CHAR_CSZR((0|(1<<8))) => %u\n", CHAR_CSZR( (0|(1<<8)) ));
    printf("CHAR_CSZR((1|(1<<8))) => %u\n", CHAR_CSZR( (1|(1<<8)) ));
    printf("\n");
    printf("USHRT_CSZR( USHRT_MAX) => %hu\n", USHRT_CSZR(USHRT_MAX));
    printf("USHRT_CSZR((0&(1<<0))) => %hu\n", USHRT_CSZR(0));

    printf("USHRT_CSZR((0|(1<<0))) => %hu\n", USHRT_CSZR( (0|(1<<0)) ));
    printf("USHRT_CSZR((1|(1<<0))) => %hu\n", USHRT_CSZR( (1|(1<<0)) ));

    printf("USHRT_CSZR((0|(1<<1))) => %hu\n", USHRT_CSZR( (0|(1<<1)) ));
    printf("USHRT_CSZR((1|(1<<1))) => %hu\n", USHRT_CSZR( (1|(1<<1)) ));

    printf("USHRT_CSZR((0|(1<<2))) => %hu\n", USHRT_CSZR( (0|(1<<2)) ));
    printf("USHRT_CSZR((1|(1<<2))) => %hu\n", USHRT_CSZR( (1|(1<<2)) ));

    printf("USHRT_CSZR((0|(1<<14))) => %hu\n", USHRT_CSZR( (0|(1<<14)) ));
    printf("USHRT_CSZR((1|(1<<14))) => %hu\n", USHRT_CSZR( (1|(1<<14)) ));

    printf("USHRT_CSZR((0|(1<<15))) => %hu\n", USHRT_CSZR( (0|(1<<15)) ));
    printf("USHRT_CSZR((1|(1<<15))) => %hu\n", USHRT_CSZR( (1|(1<<15)) ));

    printf("USHRT_CSZR((0|(1<<16))) => %hu\n", USHRT_CSZR( (0|(1<<16)) ));
    printf("USHRT_CSZR((1|(1<<16))) => %hu\n", USHRT_CSZR( (1|(1<<16)) ));
    printf("\n");

    printf("SHRT_CSZR( SHRT_MAX) => %hi\n", SHRT_CSZR(SHRT_MAX));
    printf("SHRT_CSZR((0&(1<<0))) => %hi\n", SHRT_CSZR(0));

    printf("SHRT_CSZR((0|(1<<0))) => %hi\n", SHRT_CSZR( (0|(1<<0)) ));
    printf("SHRT_CSZR((1|(1<<0))) => %hi\n", SHRT_CSZR( (1|(1<<0)) ));

    printf("SHRT_CSZR((0|(1<<1))) => %hi\n", SHRT_CSZR( (0|(1<<1)) ));
    printf("SHRT_CSZR((1|(1<<1))) => %hi\n", SHRT_CSZR( (1|(1<<1)) ));

    printf("SHRT_CSZR((0|(1<<2))) => %hi\n", SHRT_CSZR( (0|(1<<2)) ));
    printf("SHRT_CSZR((1|(1<<2))) => %hi\n", SHRT_CSZR( (1|(1<<2)) ));

    printf("SHRT_CSZR((0|(1<<14))) => %hi\n", SHRT_CSZR( (0|(1<<14)) ));
    printf("SHRT_CSZR((1|(1<<14))) => %hi\n", SHRT_CSZR( (1|(1<<14)) ));

    printf("SHRT_CSZR((0|(1<<15))) => %hi\n", SHRT_CSZR( (0|(1<<15)) ));
    printf("SHRT_CSZR((1|(1<<15))) => %hi\n", SHRT_CSZR( (1|(1<<15)) ));

    printf("SHRT_CSZR((0|(1<<16))) => %hi\n", SHRT_CSZR( (0|(1<<16)) ));
    printf("SHRT_CSZR((1|(1<<16))) => %hi\n", SHRT_CSZR( (1|(1<<16)) ));
    printf("\n");
    printf("UINT_CSZR( UINT_MAX) => %u\n", UINT_CSZR(UINT_MAX));
    printf("UINT_CSZR((0&(1<<0))) => %u\n", UINT_CSZR(0));

    printf("UINT_CSZR((0|(1<<0))) => %u\n", UINT_CSZR( (0|(1<<0)) ));
    printf("UINT_CSZR((1|(1<<0))) => %u\n", UINT_CSZR( (1|(1<<0)) ));

    printf("UINT_CSZR((0|(1<<1))) => %u\n", UINT_CSZR( (0|(1<<1)) ));
    printf("UINT_CSZR((1|(1<<1))) => %u\n", UINT_CSZR( (1|(1<<1)) ));

    printf("UINT_CSZR((0|(1<<2))) => %u\n", UINT_CSZR( (0|(1<<2)) ));
    printf("UINT_CSZR((1|(1<<2))) => %u\n", UINT_CSZR( (1|(1<<2)) ));

    printf("UINT_CSZR((0|(1<<15))) => %u\n", UINT_CSZR( (0|(1<<15)) ));
    printf("UINT_CSZR((1|(1<<15))) => %u\n", UINT_CSZR( (1|(1<<15)) ));

    printf("UINT_CSZR((0|(1U<<31))) => %u\n", UINT_CSZR( (0|(1U<<31)) ));
    printf("UINT_CSZR((1|(1U<<31))) => %u\n", UINT_CSZR( (1|(1U<<31)) ));
    printf("\n");

    printf("INT_CSZR( INT_MAX) => %i\n", INT_CSZR(INT_MAX));
    printf("INT_CSZR((0&(1<<0))) => %i\n", INT_CSZR(0));

    printf("INT_CSZR((0|(1<<0))) => %i\n", INT_CSZR( (0|(1<<0)) ));
    printf("INT_CSZR((1|(1<<0))) => %i\n", INT_CSZR( (1|(1<<0)) ));

    printf("INT_CSZR((0|(1<<1))) => %i\n", INT_CSZR( (0|(1<<1)) ));
    printf("INT_CSZR((1|(1<<1))) => %i\n", INT_CSZR( (1|(1<<1)) ));

    printf("INT_CSZR((0|(1<<2))) => %i\n", INT_CSZR( (0|(1<<2)) ));
    printf("INT_CSZR((1|(1<<2))) => %i\n", INT_CSZR( (1|(1<<2)) ));

    printf("INT_CSZR((0|(1<<15))) => %i\n", INT_CSZR( (0|(1<<15)) ));
    printf("INT_CSZR((1|(1<<15))) => %i\n", INT_CSZR( (1|(1<<15)) ));

    printf("INT_CSZR((0|(1U<<31))) => %i\n", INT_CSZR( (0|(1U<<31)) ));
    printf("INT_CSZR((1|(1U<<31))) => %i\n", INT_CSZR( (1|(1U<<31)) ));
    printf("\n");
    printf("ULONG_CSZR( ULONG_MAX) => %lu\n", ULONG_CSZR(ULONG_MAX));
    printf("ULONG_CSZR((0&(1<<0))) => %lu\n", ULONG_CSZR(0));

    printf("ULONG_CSZR((0|(1<<0))) => %lu\n", ULONG_CSZR( (0|(1<<0)) ));
    printf("ULONG_CSZR((1|(1<<0))) => %lu\n", ULONG_CSZR( (1|(1<<0)) ));

    printf("ULONG_CSZR((0|(1<<1))) => %lu\n", ULONG_CSZR( (0|(1<<1)) ));
    printf("ULONG_CSZR((1|(1<<1))) => %lu\n", ULONG_CSZR( (1|(1<<1)) ));

    printf("ULONG_CSZR((0|(1<<2))) => %lu\n", ULONG_CSZR( (0|(1<<2)) ));
    printf("ULONG_CSZR((1|(1<<2))) => %lu\n", ULONG_CSZR( (1|(1<<2)) ));

    printf("ULONG_CSZR((0|(1<<15))) => %lu\n", ULONG_CSZR( (0|(1<<15)) ));
    printf("ULONG_CSZR((1|(1<<15))) => %lu\n", ULONG_CSZR( (1|(1<<15)) ));

    printf("ULONG_CSZR((0|(1U<<31))) => %lu\n", ULONG_CSZR( (0|(1U<<31)) ));
    printf("ULONG_CSZR((1|(1U<<31))) => %lu\n", ULONG_CSZR( (1|(1U<<31)) ));
    printf("\n");

    printf("LONG_CSZR( LONG_MAX) => %li\n", LONG_CSZR(LONG_MAX));
    printf("LONG_CSZR((0&(1<<0))) => %li\n", LONG_CSZR(0));

    printf("LONG_CSZR((0|(1<<0))) => %li\n", LONG_CSZR( (0|(1<<0)) ));
    printf("LONG_CSZR((1|(1<<0))) => %li\n", LONG_CSZR( (1|(1<<0)) ));

    printf("LONG_CSZR((0|(1<<1))) => %li\n", LONG_CSZR( (0|(1<<1)) ));
    printf("LONG_CSZR((1|(1<<1))) => %li\n", LONG_CSZR( (1|(1<<1)) ));

    printf("LONG_CSZR((0|(1<<2))) => %li\n", LONG_CSZR( (0|(1<<2)) ));
    printf("LONG_CSZR((1|(1<<2))) => %li\n", LONG_CSZR( (1|(1<<2)) ));

    printf("LONG_CSZR((0|(1<<15))) => %li\n", LONG_CSZR( (0|(1<<15)) ));
    printf("LONG_CSZR((1|(1<<15))) => %li\n", LONG_CSZR( (1|(1<<15)) ));

    printf("LONG_CSZR((0|(1U<<31))) => %li\n", LONG_CSZR( (0|(1U<<31)) ));
    printf("LONG_CSZR((1|(1U<<31))) => %li\n", LONG_CSZR( (1|(1U<<31)) ));
    printf("\n");

    printf("ULLONG_CSZR( ULLONG_MAX) => %llu\n", ULLONG_CSZR(ULLONG_MAX));
    printf("ULLONG_CSZR((0&(1<<0))) => %llu\n", ULLONG_CSZR(0));

    printf("ULLONG_CSZR((0|(1<<0))) => %llu\n", ULLONG_CSZR( (0|(1<<0)) ));
    printf("ULLONG_CSZR((1|(1<<0))) => %llu\n", ULLONG_CSZR( (1|(1<<0)) ));

    printf("ULLONG_CSZR((0|(1<<1))) => %llu\n", ULLONG_CSZR( (0|(1<<1)) ));
    printf("ULLONG_CSZR((1|(1<<1))) => %llu\n", ULLONG_CSZR( (1|(1<<1)) ));

    printf("ULLONG_CSZR((0|(1<<2))) => %llu\n", ULLONG_CSZR( (0|(1<<2)) ));
    printf("ULLONG_CSZR((1|(1<<2))) => %llu\n", ULLONG_CSZR( (1|(1<<2)) ));

    printf("ULLONG_CSZR((0|(1<<15))) => %llu\n", ULLONG_CSZR( (0|(1<<15)) ));
    printf("ULLONG_CSZR((1|(1<<15))) => %llu\n", ULLONG_CSZR( (1|(1<<15)) ));

    printf("ULLONG_CSZR((0|(1U<<31))) => %llu\n", ULLONG_CSZR( (0|(1U<<31)) ));
    printf("ULLONG_CSZR((1|(1U<<31))) => %llu\n", ULLONG_CSZR( (1|(1U<<31)) ));
    printf("\n");

    printf("LLONG_CSZR( LLONG_MAX) => %lli\n", LLONG_CSZR(LLONG_MAX));
    printf("LLONG_CSZR((0&(1<<0))) => %lli\n", LLONG_CSZR(0));

    printf("LLONG_CSZR((0|(1<<0))) => %lli\n", LLONG_CSZR( (0|(1<<0)) ));
    printf("LLONG_CSZR((1|(1<<0))) => %lli\n", LLONG_CSZR( (1|(1<<0)) ));

    printf("LLONG_CSZR((0|(1<<1))) => %lli\n", LLONG_CSZR( (0|(1<<1)) ));
    printf("LLONG_CSZR((1|(1<<1))) => %lli\n", LLONG_CSZR( (1|(1<<1)) ));

    printf("LLONG_CSZR((0|(1<<2))) => %lli\n", LLONG_CSZR( (0|(1<<2)) ));
    printf("LLONG_CSZR((1|(1<<2))) => %lli\n", LLONG_CSZR( (1|(1<<2)) ));

    printf("LLONG_CSZR((0|(1<<15))) => %lli\n", LLONG_CSZR( (0|(1<<15)) ));
    printf("LLONG_CSZR((1|(1<<15))) => %lli\n", LLONG_CSZR( (1|(1<<15)) ));

    printf("LLONG_CSZR((0|(1U<<31))) => %lli\n", LLONG_CSZR( (0|(1U<<31)) ));
    printf("LLONG_CSZR((1|(1U<<31))) => %lli\n", LLONG_CSZR( (1|(1U<<31)) ));
    printf("\n");
    }
    
#endif
    //outfdwu(cnt1dwu(newdwu(-1,-1)), stdout, DUP2("%u", ", ") "\n");
#if 0
    QUAD_TYPE qq, qm, qn, qd, qt, qx;
    char *res;
    if (1)
    {
        qn.U = catldu(0, 67108864ULL);  // 1<<90
        qd.U = catldu(4, 0);
        qq.U = divlqu(qn.U, qd.U);
        //printf("qq.Lo.U = %" UINT64_DFMT "\n", qq.Lo.U);
        //printf("qq.Hi.U = %" UINT64_DFMT "\n", qq.Hi.U);
        
        my_divlqu(qn.U, qd.U);  // (1<<90)/4
#if 1
        qn.U = cvquwu(0);
        qd.U = cvquwu(1);
        my_divlqu(qn.U, qd.U);
        my_divlqu(qn.U, icrlqu(qd.U));
    
        qn.U = cvquwu(1);
        qd.U = qn.U;
        my_divlqu(qn.U, qd.U);
        my_divlqu(qn.U, icrlqu(qd.U));
        
    //#if 1
    
        qn.U = catldu(0, 1);        // 18446744073709551616
        qd.U = cvquwu(536870911U);  // (1<<29)-1
        // (also (1<<90)>>64)
        qx.U = cvquwu(67108864U);   // (1<<29)/8
    
        my_divlqu(qn.U, qd.U);
        my_divlqu(qn.U, icrlqu(qd.U));
    
        qd.U = addlqu(qd.U, qx.U); 
        my_divlqu(qn.U, qd.U);
        my_divlqu(qn.U, icrlqu(qd.U));
    

        qd.U = catldu(1, 0);            // 1
        my_divlqu(qn.U, qd.U);          // (1<<90)/1
        my_divlqu(qn.U, icrlqu(qd.U));  // (1<<90)/2

        qd.U = catldu(3, 0);
        my_divlqu(qn.U, qd.U);          // (1<<90)/3


        qd.U = catldu(5, 0);
        my_divlqu(qn.U, qd.U);          // (1<<90)/5
        my_divlqu(qn.U, icrlqu(qd.U));  // (1<<90)/6
        qd.U = catldu(7, 0);
        my_divlqu(qn.U, qd.U);          // (1<<90)/7
        my_divlqu(qn.U, icrlqu(qd.U));  // (1<<90)/8
    
        qd.U = catldu(1073741824ULL, 0);// (1<<30)
        my_divlqu(qn.U, qd.U);          // ((1<<90)/((1<<30)*8/8)
        qd.U = addlqu(qd.U, qx.U);
        my_divlqu(qn.U, qd.U); 
#endif
    }
    if (0)
    {

        div_t dj[] = {
            div(+5,+2),
            div(+2,+2),
            div(+1,+2),
            div(+0,+2),
            div(-1,+2),
            div(-2,+2),
            div(-5,+2),
            div(+5,-2),
            div(+2,-2),
            div(+1,-2),
            div(+0,-2),
            div(-1,-2),
            div(-2,-2),
            div(-5,-2),
        }, *dx=dj;
    
        printf("div(+5,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+2,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+1,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+0,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(-1,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(-2,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(-5,+2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+5,-2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+2,-2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+1,-2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(+0,-2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(-1,-2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(-2,-2)==(%+i,%+i)\n",dx->quot,dx->rem);dx++;
        printf("div(-5,-2)==(%+i,%+i)\n",dx->quot,dx->rem);
        
    }
    //printf("toadqi(-1) => %s\n", toadqi(qq.I, str, &end));
    if (0)
    {
        qn.U = catldu(7766279631452241920ULL, 5ULL);
        qd.U = cvqudu(3402823669209384634ULL);
        printf(
            "(100000000000000000000*3402823669209384634)==%s\n",
            toadqu(mullqu(qn.U,qd.U),str,&end)
        );
        
    }

    if (0)
    {

        my_modnqi(cvqiwi(+5), cvqiwi(+2));
        my_modnqi(cvqiwi(+2), cvqiwi(+2));
        my_modnqi(cvqiwi(+1), cvqiwi(+2));
        my_modnqi(cvqiwi(+0), cvqiwi(+2));
        my_modnqi(cvqiwi(-1), cvqiwi(+2));
        my_modnqi(cvqiwi(-2), cvqiwi(+2));
        my_modnqi(cvqiwi(-5), cvqiwi(+2));
        
        my_modnqi(cvqiwi(+5), cvqiwi(-2));
        my_modnqi(cvqiwi(+2), cvqiwi(-2));
        my_modnqi(cvqiwi(+1), cvqiwi(-2));
        my_modnqi(cvqiwi(+0), cvqiwi(-2));
        my_modnqi(cvqiwi(-1), cvqiwi(-2));
        my_modnqi(cvqiwi(-2), cvqiwi(-2));
        my_modnqi(cvqiwi(-5), cvqiwi(-2));

        
    }
    if (0)
    {
        //  when (y == 1) && n=b<<1

        //  when (a == n)
        //  e.g. (a=24, b=12, n=24)
        qn.U = catldu(9223372036854775808ULL,1);// 24<<60
        qd.U = cvqudu(13835058055282163712ULL); // 12<<60
        my_modlqu(qn.U, qd.U);

        // when (a < n)
        // e.g. (a=23, b=12, n=24); 23 < 24
        qn.U = catldu(8070450532247928832ULL,1);// 23<<60
        my_modlqu(qn.U, qd.U);
       
        // when (b > (a-n))
        // e.g. (a=25, b=12, n=24); 12 > (25-24)=1
        qn.U = catldu(10376293541461622784ULL,1);//25<<60
        my_modlqu(qn.U, qd.U);
        
        // else 
        // e.g. (a=25, b=8, n=16); 8 > (t=25-16)=9
        // q=3, r=t-b
        qd.U = cvqudu(9223372036854775808ULL); // 8<<60
        my_modlqu(qn.U, qd.U);

    }
    if (0)
    {
        qn.U = cvquwu(0);
        qd.U = cvquwu(1);
        my_modlqu(qn.U, qd.U);
        my_modlqu(qn.U, icrlqu(qd.U));
    
        qn.U = cvquwu(1);
        qd.U = qn.U;
        my_modlqu(qn.U, qd.U);
        my_modlqu(qn.U, icrlqu(qd.U));
        
    //#if 1
    
        qn.U = catldu(0, 1);        // 18446744073709551616
        qd.U = cvquwu(536870911U);  // (1<<29)-1
        // (also (1<<90)>>64)
        qx.U = cvquwu(67108864U);   // (1<<29)/8
    
        my_modlqu(qn.U, qd.U);
        my_modlqu(qn.U, icrlqu(qd.U));
    
        qd.U = addlqu(qd.U, qx.U); 
        my_modlqu(qn.U, qd.U);
        my_modlqu(qn.U, icrlqu(qd.U));
    
        qn.U = catldu(0, 67108864ULL);  // 1<<90

        qd.U = catldu(1, 0);            // 1
        my_modlqu(qn.U, qd.U);          // (1<<90)/1
        my_modlqu(qn.U, icrlqu(qd.U));  // (1<<90)/2

        qd.U = catldu(3, 0);
        my_modlqu(qn.U, qd.U);          // (1<<90)/3
        my_modlqu(qn.U, icrlqu(qd.U));  // (1<<90)/4

        qd.U = catldu(5, 0);
        my_modlqu(qn.U, qd.U);          // (1<<90)/5
        my_modlqu(qn.U, icrlqu(qd.U));  // (1<<90)/6
        qd.U = catldu(7, 0);
        my_modlqu(qn.U, qd.U);          // (1<<90)/7
        my_modlqu(qn.U, icrlqu(qd.U));  // (1<<90)/8
    
        qd.U = catldu(1073741824ULL, 0);// (1<<30)
        my_modlqu(qn.U, qd.U);          // ((1<<90)/((1<<30)*8/8)
        qd.U = addlqu(qd.U, qx.U);
        my_modlqu(qn.U, qd.U); 
    }
    
    if (0)
    {

    // 1000000000000000000000000
    // qn.U = catldu(2003764205206896640, 54210);
    qd.U = cvqudu(1000000000);

    // 1099511627776000000000000000000000000
    qn.U = addlqu(cvqudu(UINT64_MAX), cvquwu(0));
    my_modlqu(qn.U, qd.U);
    
    qn.U = addlqu(cvqudu(UINT64_MAX), cvquwu(1));
    my_modlqu(qn.U, qd.U);

    qn.U = addlqu(cvqudu(UINT64_MAX), cvquwu(2));
    my_modlqu(qn.U, qd.U);
 
    // (1<<64) / 8
    qt.U = cvqudu(2305843009213693952ULL);

    // UINT64_MAX + (1<<64)*1/8
    qn.U = addlqu(cvqudu(UINT64_MAX), qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*2/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*3/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*4/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*5/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*6/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*7/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // UINT64_MAX + (1<<64)*8/8
    qn.U = addlqu(qn.U, qt.U);
    my_modlqu(qn.U, qd.U);

    // printf("addlqu(UINT64_MAX, 0) => %s\n", toadqu(qn.U, str, &end));
    // printf("addlqu(UINT64_MAX, 1) => %s\n", toadqu(qn.U, str, &end));
    // printf("addlqu(UINT64_MAX, 2) => %s\n", toadqu(qn.U, str, &end));
    
    // 157826832055758874199829281500807947557
    qn.U = catldu(0x351f57675571e525ULL, 0x76bc5799a8a2731cULL);

    }
    
    // my_modlqu(cvquwu(5), 2);
    // my_modlqu(qn.U, 2);
    

    // qn.U = catldu(0, 59604644775390625ULL);

    //qd.U = cvqudu(536870912); // 1<<29
    // 134152415008314323914487006899938229818
    // qn.U = catldu(5665841356952796730ULL, 7272416989809569018ULL); 

#endif
    
    //vdbc = ldrdbc(0x626f63614aULL);
    //vdwf = newdwf(1.234F, 5.678F);
#if 0
    outfdwu(
        vhadd_u32(UINT_LDPD(2,3), UINT_LDPD(2,2)),
        stdout, 
        "vhadd( {2,3},{2,2}) => {" DUP2("%u",", ") "}\n"
    );
    
    outfdwu(
        vrhadd_u32(UINT_LDPD(2,3), UINT_LDPD(2,2)),
        stdout, 
        "vrhadd({2,3},{2,2}) => {" DUP2("%u",", ") "}\n"
    );
#endif

#if 0
    //printf("%u\n",vget_lane_u32(vclz_u32(vcreate_u32(1)),0));
    vdbu = VDBU_VEQL(
        newdbu('S', 'a', 't', 'u', 'r', 'n', '\0', '\0'),
        dupdbu('u')
    );
    outfdbu(vdbu, stdout, "{" DUP8("%u", ", ") "}\n");
#endif

    char *qstr = ((char[1+QUAD_IDIG]){0});
    
#if 0
    if (MY_CEQTEST()) return 0;
    
    printf("SCHAR_AVGL(-4) => %+hhi\n", SCHAR_AVGL(-4,0));
    printf("SCHAR_AVGL(-3) => %+hhi\n", SCHAR_AVGL(-3,0));
    printf("SCHAR_AVGL(-2) => %+hhi\n", SCHAR_AVGL(-2,0));
    printf("SCHAR_AVGL(-1) => %+hhi\n", SCHAR_AVGL(-1,0));
    printf("SCHAR_AVGL(+0) => %+hhi\n", SCHAR_AVGL(+0,0));
    printf("SCHAR_AVGL(+1) => %+hhi\n", SCHAR_AVGL(+1,0));
    printf("SCHAR_AVGL(+2) => %+hhi\n", SCHAR_AVGL(+2,0));
    printf("SCHAR_AVGL(+3) => %+hhi\n", SCHAR_AVGL(+3,0));
    printf("SCHAR_AVGL(+4) => %+hhi\n", SCHAR_AVGL(+4,0));
#endif

#if 0
    printf("\n");
    printf("SHRT_AVGL(-4) => %+hi\n", SHRT_AVGL(-4,0));
    printf("SHRT_AVGL(-3) => %+hi\n", SHRT_AVGL(-3,0));
    printf("SHRT_AVGL(-2) => %+hi\n", SHRT_AVGL(-2,0));
    printf("SHRT_AVGL(-1) => %+hi\n", SHRT_AVGL(-1,0));
    printf("SHRT_AVGL(+0) => %+hi\n", SHRT_AVGL(+0,0));
    printf("SHRT_AVGL(+1) => %+hi\n", SHRT_AVGL(+1,0));
    printf("SHRT_AVGL(+2) => %+hi\n", SHRT_AVGL(+2,0));
    printf("SHRT_AVGL(+3) => %+hi\n", SHRT_AVGL(+3,0));
    printf("SHRT_AVGL(+4) => %+hi\n", SHRT_AVGL(+4,0));
#endif

#if 0
    printf("\n");
    printf("INT_AVGL(-4) => %+i\n", INT_AVGL(-4,0));
    printf("INT_AVGL(-3) => %+i\n", INT_AVGL(-3,0));
    printf("INT_AVGL(-2) => %+i\n", INT_AVGL(-2,0));
    printf("INT_AVGL(-1) => %+i\n", INT_AVGL(-1,0));
    printf("INT_AVGL(+0) => %+i\n", INT_AVGL(+0,0));
    printf("INT_AVGL(+1) => %+i\n", INT_AVGL(+1,0));
    printf("INT_AVGL(+2) => %+i\n", INT_AVGL(+2,0));
    printf("INT_AVGL(+3) => %+i\n", INT_AVGL(+3,0));
    printf("INT_AVGL(+4) => %+i\n", INT_AVGL(+4,0));
#endif

#if 0
    printf("\n");
    printf("LONG_AVGL(-4) => %+li\n", LONG_AVGL(-4,0));
    printf("LONG_AVGL(-3) => %+li\n", LONG_AVGL(-3,0));
    printf("LONG_AVGL(-2) => %+li\n", LONG_AVGL(-2,0));
    printf("LONG_AVGL(-1) => %+li\n", LONG_AVGL(-1,0));
    printf("LONG_AVGL(+0) => %+li\n", LONG_AVGL(+0,0));
    printf("LONG_AVGL(+1) => %+li\n", LONG_AVGL(+1,0));
    printf("LONG_AVGL(+2) => %+li\n", LONG_AVGL(+2,0));
    printf("LONG_AVGL(+3) => %+li\n", LONG_AVGL(+3,0));
    printf("LONG_AVGL(+4) => %+li\n", LONG_AVGL(+4,0));
#endif

#if 0
    printf("\n");
    printf("LLONG_AVGL(-4) => %+lli\n", LLONG_AVGL(-4,0));
    printf("LLONG_AVGL(-3) => %+lli\n", LLONG_AVGL(-3,0));
    printf("LLONG_AVGL(-2) => %+lli\n", LLONG_AVGL(-2,0));
    printf("LLONG_AVGL(-1) => %+lli\n", LLONG_AVGL(-1,0));
    printf("LLONG_AVGL(+0) => %+lli\n", LLONG_AVGL(+0,0));
    printf("LLONG_AVGL(+1) => %+lli\n", LLONG_AVGL(+1,0));
    printf("LLONG_AVGL(+2) => %+lli\n", LLONG_AVGL(+2,0));
    printf("LLONG_AVGL(+3) => %+lli\n", LLONG_AVGL(+3,0));
    printf("LLONG_AVGL(+4) => %+lli\n", LLONG_AVGL(+4,0));
#endif

#if 0
    outfdbi(
        VDBI_AVGL(newdbi(-4,-3,-2,-1,+1,+2,+3,+4), dupdbi(0)),
        stdout,
        "avgldbi(...-4) => %+hhi\n"
        "avgldbi(...-3) => %+hhi\n"
        "avgldbi(...-2) => %+hhi\n"
        "avgldbi(...-1) => %+hhi\n"
        "avgldbi(...+1) => %+hhi\n"
        "avgldbi(...+2) => %+hhi\n"
        "avgldbi(...+3) => %+hhi\n"
        "avgldbi(...+4) => %+hhi\n"
    );
#endif

#if 0
    outfdwi(
        VDWI_AVGL(newdwi(-4, -3), dupdwi(0)),
        stdout,
        "avgldwi(...-4) => %+i\n"
        "avgldwi(...-3) => %+i\n"
    );
    outfdwi(
        VDWI_AVGL(newdwi(-2, -1), dupdwi(0)),
        stdout,
        "avgldwi(...-2) => %+i\n"
        "avgldwi(...-1) => %+i\n"
    );
    outfdwi(
        VDWI_AVGL(newdwi(+1, +2), dupdwi(0)),
        stdout,
        "avgldwi(...+1) => %+i\n"
        "avgldwi(...+2) => %+i\n"
    );
    outfdwi(
        VDWI_AVGL(newdwi(+3, +4), dupdwi(0)),
        stdout,
        "avgldwi(...+3) => %+i\n"
        "avgldwi(...+4) => %+i\n"
    );
#endif

#if 0
    printf( "LONG_AVGP(-4) => %+li\n",   LONG_AVGP(-4,0));
    printf( "LONG_AVGP(-3) => %+li\n",   LONG_AVGP(-3,0));
    printf( "LONG_AVGP(-2) => %+li\n",   LONG_AVGP(-2,0));
    printf( "LONG_AVGP(-1) => %+li\n",   LONG_AVGP(-1,0));
    printf( "LONG_AVGP(+0) => %+li\n",   LONG_AVGP(+0,0));
    printf( "LONG_AVGP(+1) => %+li\n",   LONG_AVGP(+1,0));
    printf( "LONG_AVGP(+2) => %+li\n",   LONG_AVGP(+2,0));
    printf( "LONG_AVGP(+3) => %+li\n",   LONG_AVGP(+3,0));
    printf( "LONG_AVGP(+4) => %+li\n",   LONG_AVGP(+4,0));

    printf( "\n");
    printf("LLONG_AVGP(-4) => %+lli\n", LLONG_AVGP(-4,0));
    printf("LLONG_AVGP(-3) => %+lli\n", LLONG_AVGP(-3,0));
    printf("LLONG_AVGP(-2) => %+lli\n", LLONG_AVGP(-2,0));
    printf("LLONG_AVGP(-1) => %+lli\n", LLONG_AVGP(-1,0));
    printf("LLONG_AVGP(+0) => %+lli\n", LLONG_AVGP(+0,0));
    printf("LLONG_AVGP(+1) => %+lli\n", LLONG_AVGP(+1,0));
    printf("LLONG_AVGP(+2) => %+lli\n", LLONG_AVGP(+2,0));
    printf("LLONG_AVGP(+3) => %+lli\n", LLONG_AVGP(+3,0));
    printf("LLONG_AVGP(+4) => %+lli\n", LLONG_AVGP(+4,0));
#endif

#if 0
    printf( "INT_AVGN(-2,-3) @-5 => %+i\n", INT_AVGN(-2,-3));
    printf( "INT_AVGN(-2,-2) @-4 => %+i\n", INT_AVGN(-2,-2));
    printf( "INT_AVGN(-2,-1) @-3 => %+i\n", INT_AVGN(-2,-1));
    printf( "INT_AVGN(-2,+0) @-2 => %+i\n", INT_AVGN(-2,+0));
    printf( "INT_AVGN(-2,+1) @-1 => %+i\n", INT_AVGN(-2,+1));
    printf( "INT_AVGN(-2,+2) @+0 => %+i\n", INT_AVGN(-2,+2));
    printf( "INT_AVGN(-2,+3) @+1 => %+i\n", INT_AVGN(-2,+3));
    printf( "INT_AVGN(-2,+4) @+2 => %+i\n", INT_AVGN(-2,+4));
    printf( "\n");
    printf( "INT_AVGN(-1,-3) @-4 => %+i\n", INT_AVGN(-1,-3));
    printf( "INT_AVGN(-1,-2) @-3 => %+i\n", INT_AVGN(-1,-2));
    printf( "INT_AVGN(-1,-1) @-2 => %+i\n", INT_AVGN(-1,-1));
    printf( "INT_AVGN(-1,+0) @-1 => %+i\n", INT_AVGN(-1,+0));
    printf( "INT_AVGN(-1,+1) @+0 => %+i\n", INT_AVGN(-1,+1));
    printf( "INT_AVGN(-1,+2) @+1 => %+i\n", INT_AVGN(-1,+2));
    printf( "INT_AVGN(-1,+3) @+2 => %+i\n", INT_AVGN(-1,+3));
    printf( "INT_AVGN(-1,+4) @+3 => %+i\n", INT_AVGN(-1,+4));
    printf( "\n");
    printf( "LONG_AVGN(-2,-3) @-5 => %+li\n", LONG_AVGN(-2,-3));
    printf( "LONG_AVGN(-2,-2) @-4 => %+li\n", LONG_AVGN(-2,-2));
    printf( "LONG_AVGN(-2,-1) @-3 => %+li\n", LONG_AVGN(-2,-1));
    printf( "LONG_AVGN(-2,+0) @-2 => %+li\n", LONG_AVGN(-2,+0));
    printf( "LONG_AVGN(-2,+1) @-1 => %+li\n", LONG_AVGN(-2,+1));
    printf( "LONG_AVGN(-2,+2) @+0 => %+li\n", LONG_AVGN(-2,+2));
    printf( "LONG_AVGN(-2,+3) @+1 => %+li\n", LONG_AVGN(-2,+3));
    printf( "LONG_AVGN(-2,+4) @+2 => %+li\n", LONG_AVGN(-2,+4));
    printf( "\n");
    printf( "LONG_AVGN(-1,-3) @-4 => %+li\n", LONG_AVGN(-1,-3));
    printf( "LONG_AVGN(-1,-2) @-3 => %+li\n", LONG_AVGN(-1,-2));
    printf( "LONG_AVGN(-1,-1) @-2 => %+li\n", LONG_AVGN(-1,-1));
    printf( "LONG_AVGN(-1,+0) @-1 => %+li\n", LONG_AVGN(-1,+0));
    printf( "LONG_AVGN(-1,+1) @+0 => %+li\n", LONG_AVGN(-1,+1));
    printf( "LONG_AVGN(-1,+2) @+1 => %+li\n", LONG_AVGN(-1,+2));
    printf( "LONG_AVGN(-1,+3) @+2 => %+li\n", LONG_AVGN(-1,+3));
    printf( "LONG_AVGN(-1,+4) @+3 => %+li\n", LONG_AVGN(-1,+4));
#endif

    
#if 0
    outfqwi(
        avgnqwi(newqwi(-2,-2,-2,-2),newqwi(-4,-3,-2,-1)),
        stdout,
        "AVGN "
        "{-2,-4}=%+" INT32_DFMT ", "
        "{-2,-3}=%+" INT32_DFMT ", "
        "{-2,-2}=%+" INT32_DFMT ", "
        "{-2,-1}=%+" INT32_DFMT ", "
        "\n"
    );
    outfqwi(
        avgnqwi(newqwi(-2,-2,-2,-2),newqwi(+1,+2,+3,+4)),
        stdout,
        "AVGN "
        "{-2,+1}=%+" INT32_DFMT ", "
        "{-2,+2}=%+" INT32_DFMT ", "
        "{-2,+3}=%+" INT32_DFMT ", "
        "{-2,+4}=%+" INT32_DFMT ", "
        "\n"
    );
    outfqwi(
        avgnqwi(newqwi(-1,-1,-1,-1),newqwi(-4,-3,-2,-1)),
        stdout,
        "AVGN "
        "{-1,-4}=%+" INT32_DFMT ", "
        "{-1,-3}=%+" INT32_DFMT ", "
        "{-1,-2}=%+" INT32_DFMT ", "
        "{-1,-1}=%+" INT32_DFMT ", "
        "\n"
    );
    outfqwi(
        avgnqwi(newqwi(-1,-1,-1,-1),newqwi(+1,+2,+3,+4)),
        stdout,
        "AVGN "
        "{-1,+1}=%+" INT32_DFMT ", "
        "{-1,+2}=%+" INT32_DFMT ", "
        "{-1,+3}=%+" INT32_DFMT ", "
        "{-1,+4}=%+" INT32_DFMT ", "
        "\n"
    );

#endif

/*

    return (n < 0)
    ?   (d < 0)
        ?   ((*r=x.rem),   x.quot)  
        :   ((*r=x.rem+d), x.quot-1)
    :   (d < 0)                     
        ?   ((*r=x.rem+d), x.quot-1)
        :   ((*r=x.rem),   x.quot); 


n=±3
    div(-3,-2) => {+1,-1} pyd(-3,-2) => (+1,-1) 
    div(-3,-1) => {+3,+0} pyd(-3,-1) => (+3,+0)
    div(-3,+1) => {-3,+0} pyd(-3,+1) => (-3,+0)
    div(-3,+2) => {-1,-1} pyd(-3,+2) => (-2,+1)
    div(+3,-2) => {-1,+1} pyd(+3,-2) => (-2,-1) 
    div(+3,-1) => {-3,+0} pyd(+3,-1) => (-3,+0)  
    div(+3,+1) => {+3,+0} pyd(+3,+1) => (+3,+0)
    div(+3,+2) => {+1,+1} pyd(+3,+2) => (+1,+1)

n=±2
    div(-2,-2) => {+1,+0} pyd(-2,-2) => (+1, 0)
    div(-2,-1) => {+2,+0} pyd(-2,-1) => (+2, 0)
    div(-2,+1) => {-2,+0} pyd(-2,+1) => (-2, 0)
    div(-2,+2) => {-1,+0} pyd(-2,+2) => (-1, 0)
    div(+2,-2) => {-1,+0} pyd(+2,-2) => (-1, 0)
    div(+2,-1) => {-2,+0} pyd(+2,-1) => (-2, 0)
    div(+2,+1) => {+2,+0} pyd(+2,+1) => (+2, 0)
    div(+2,+2) => {+1,+0} pyd(+2,+2) => (+1, 0)

n=±1
    div(-1,-2) => {+0,-1} pyd(-1,-2) => (+0,-1)
    div(-1,-1) => {+1,+0} pyd(-1,-1) => (+1,+0)
    div(-1,+1) => {-1,+0} pyd(-1,+1) => (-1,+0)

    div(-1,+2) => {+0,-1} pyd(-1,+2) => (-1,+1)
    div(+1,-2) => {+0,+1} pyd(+1,-2) => (-1,-1)

    div(+1,-1) => {-1,+0} pyd(+1,-1) => (-1,+0)
    div(+1,+1) => {+1,+0} pyd(+1,+1) => (+1,+0) 
    div(+1,+2) => {+0,+1} pyd(+1,+2) => (+0,+1)


    printf("div(+3, -2), => {%+i,%+i}\n",(dr+0)->quot,(dr+0)->rem);
    
    +3 / -2 = {-1,+1} (-2,-1)
    
    -3 / +2 = {-1,-1} (-2,+1)
    
    div(-3, +2) => {-1,-1}
        +3 / +2: 
            q = -1
        -1 * +2 = -2
        -3 - -2 = r = -1
   
    div(+3, -2) => {-1, +1}
        +3 / +2:
            q = -1
        -1 * -2=+2
               /
        +3 - +2 = +1
    
    +3/-2 = -1 % -1
        +3 / +2 = -1
        
        -1 * -2 = =2
        2-3 = -1
        
*/

    //int8_t  dn[8] = {-3,-3,-3,-3, +3,+3,+3,+3};
    int8_t  dn[8] = {-2,-2,-2,-2, +2,+2,+2,+2};
    int8_t  dd[8] = {-2,-1,+1,+2, -2,-1,+1,+2};

#if 0

#   define TWOP "%+hhi,%+hhi"
    struct {int8_t quot, rem;} dr[8];
    dr[0].quot = INT8_DIVR(dn[0], dd[0], &dr[0].rem);
    dr[1].quot = INT8_DIVR(dn[1], dd[1], &dr[1].rem);
    dr[2].quot = INT8_DIVR(dn[2], dd[2], &dr[2].rem);
    dr[3].quot = INT8_DIVR(dn[3], dd[3], &dr[3].rem);
    dr[4].quot = INT8_DIVR(dn[4], dd[4], &dr[4].rem);
    dr[5].quot = INT8_DIVR(dn[5], dd[5], &dr[5].rem);
    dr[6].quot = INT8_DIVR(dn[6], dd[6], &dr[6].rem);
    dr[7].quot = INT8_DIVR(dn[7], dd[7], &dr[7].rem);
#elif 0
#   define TWOP "%+i,%+i"
    div_t dr[8];
    dr[0] = div(dn[0], dd[0]);
    dr[1] = div(dn[1], dd[1]);
    dr[2] = div(dn[2], dd[2]);
    dr[3] = div(dn[3], dd[3]);
    dr[4] = div(dn[4], dd[4]);
    dr[5] = div(dn[5], dd[5]);
    dr[6] = div(dn[6], dd[6]);
    dr[7] = div(dn[7], dd[7]);
#else
#   define TWOP "%+i,%+i"
    div_t dr[8];
    dr[0].quot = mydiv(dn[0], dd[0], &dr[0].rem);
    dr[1].quot = mydiv(dn[1], dd[1], &dr[1].rem);
    dr[2].quot = mydiv(dn[2], dd[2], &dr[2].rem);
    dr[3].quot = mydiv(dn[3], dd[3], &dr[3].rem);
    dr[4].quot = mydiv(dn[4], dd[4], &dr[4].rem);
    dr[5].quot = mydiv(dn[5], dd[5], &dr[5].rem);
    dr[6].quot = mydiv(dn[6], dd[6], &dr[6].rem);
    dr[7].quot = mydiv(dn[7], dd[7], &dr[7].rem);
#endif

#if 0
#   define SMFD(I) dn[I], dd[I], dr[I].quot, dr[I].rem
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(0));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(1));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(2));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(3));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(4));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(5));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(6));
    printf("div(" TWOP ") => {" TWOP "}\n",SMFD(7));

#endif

#if 0
    printf("avglwi(-2,+1) => %i\n", INT_AVGL(-2,+1));
    printf("avglwi(-2,-1) => %i\n", INT_AVGL(-2,-1));
#endif

#if 0
    printf("toadqi(cvqidi(-2)) => %s\n", toadqi(cvqidi(-2),qstr,&qstr));
    printf("toadqi(cvqidi(-1)) => %s\n", toadqi(cvqidi(-1),qstr,&qstr));
    printf("toadqi(cvqidi(+0)) => %s\n", toadqi(cvqidi(+0),qstr,&qstr));
    printf("toadqi(cvqidi(+1)) => %s\n", toadqi(cvqidi(+1),qstr,&qstr));
    printf("toadqi(cvqidi(+2)) => %s\n", toadqi(cvqidi(+2),qstr,&qstr));
#endif

#if 0
    printf(
        "avglqi(+0,+1) => %s\n",
        toadqi(avglqi(cvqidi(+0),cvqidi(+1)), qstr, &qstr)
    );
    printf(
        "avglqi(+1,+1) => %s\n",
        toadqi(avglqi(cvqidi(+1),cvqidi(+1)), qstr, &qstr)
    );
    printf(
        "avglqi(+1,+2) => %s\n",
        toadqi(avglqi(cvqidi(+1),cvqidi(+2)), qstr, &qstr)
    );
    printf(
        "avglqi(+2,+2) => %s\n",
        toadqi(avglqi(cvqidi(+2),cvqidi(+2)), qstr, &qstr)
    );
    printf(
        "avglqi(-2,+2) => %s\n",
        toadqi(avglqi(cvqidi(-2),cvqidi(+2)), qstr, &qstr)
    );
    printf(
        "avglqi(-2,+1) => %s\n",
        toadqi(avglqi(cvqidi(-2),cvqidi(+1)), qstr, &qstr)
    );
    printf(
        "avglqi(-2,+0) => %s\n",
        toadqi(avglqi(cvqidi(-2),cvqidi(+0)), qstr, &qstr)
    );
    printf(
        "avglqi(-2,-1) => %s\n",
        toadqi(avglqi(cvqidi(-2),cvqidi(-1)), qstr, &qstr)
    );
    printf(
        "avglqi(-2,-2) => %s\n",
        toadqi(avglqi(cvqidi(-2),cvqidi(-2)), qstr, &qstr)
    );
#endif

#if 0
    printf(
        "vshld_s64(-64, 1) => %" INT64_DFMT "\n",
        (vshld_s64(-64,-1))
    );
    
    vdwf = ldrdwf(0x40b5b22d3f9df3b6ULL);
    printf(
        "%g, %g\n", 
        vget_lane_f32(vdwf,0),
        vget_lane_f32(vdwf,1)
    );
#endif
//    printf(
//        "{1.234F, 5.678F} => (0x%016" UINT64_XFMT "ULL)\n",
//        ldrddwf(vdwf)
//    );
//    outfdbc(vdbc, stdout, "{" DUP8("'%c'", ", ") "}\n");
    
#if 0
    QUAD_TYPE qq, qr;
    qq.U = MY_DIVRQU(qn.U, qd.U, &qr.U);
    (void) toadqu(qq.U, str);
    printf("qq.U => \"%s\"\n", str);
        
    // 123456789876543212345678987654321
    // nbit=107
    QUAD_TYPE m;
    m.U = catldu(0, 9223372036854775808ULL);
    vqqu = dupqqu(m.U);
    
    m.I = cvqibi(-1);
    m.U = catldu(13449124896223392945ULL, 6692605989611ULL);
    m.I = neglqi(m.I);
    printf("absubi(-1) => %hhu\n", absubi(-1));
    printf("absubi(-128) => %hhu\n", absubi(-128));
    m.U = absuqi(m.I);
    (void) toadqu(m.I, str);
#endif

#if 0
// veql
    outfqbu(
        QBU_VEQL(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('f')
        ),
        stdout,
        "veqlqbc(\"f00dfeeddeadbeef\", 'f') => "
        "{" DUP16("%hhu", ", ") "}\n"
    );

    outfqbu(
        QBU_VEQL(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('0')
        ),
        stdout,
        "veqlqbc(\"f00dfeeddeadbeef\", '0') => "
        "{" DUP16("%hhu", ", ") "}\n"
    );

    outfqbu(
        QBU_VEQL(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('d')
        ),
        stdout,
        "veqlqbc(\"f00dfeeddeadbeef\", 'd') => "
        "{" DUP16("%hhu", ", ") "}\n"
    );

    outfqbu(
        QBU_VEQL(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('e')
        ),
        stdout,
        "veqlqbc(\"f00dfeeddeadbeef\", 'e') => "
        "{" DUP16("%hhu", ", ") "}\n"
    );

    outfqbu(
        QBU_VEQL(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('a')
        ),
        stdout,
        "veqlqbc(\"f00dfeeddeadbeef\", 'a') => "
        "{" DUP16("%hhu", ", ") "}\n"
    );
#endif

#if 0
    outfqhu(
        QHU_VEQL(
            newqhu(0,1,2,3, 4,5,6,7),
            dupqhu(6)
        ),
        stdout,
        "veqlqbc({0,1,2,3,4,5,6,7}, 6) => "
        "{" DUP8("%hu", ", ") "}\n"
    );
#endif

#if 0
    outfdbu(
        DBU_VEQR(
            newdbu(0,1,2,3, 4,5,6,7),
            dupdbu(1)
        ),
        stdout,
        "veqrdbu({0,1,2,3, 4,5,6,7}, 1) => "
        "{" DUP8("%hu", ",") "}\n"
    );

    outfdbu(
        DBU_VEQR(
            newdbu(0,1,6,3, 4,5,6,7),
            dupdbu(6)
        ),
        stdout,
        "veqrdbu({0,1,6,3, 4,5,6,7}, 6) => "
        "{" DUP8("%hu", ",") "}\n"
    );
    outfdbu(
        DBU_VEQR(
            newdbu(0,1,2,3, 4,5,6,7),
            dupdbu(8)
        ),
        stdout,
        "veqrdbu({0,1,2,3, 4,5,6,7}, 8) => "
        "{" DUP8("%hu", ",") "}\n"
    );
#endif

#if 0
    outfdhu(
        DHU_VEQR(
            newdhu(0xf, 0xe, 0xe, 0xd),
            dupdhu(0xf)
        ),
        stdout,
        "veqrdhu({0xf,0xe,0xe,0xd}, 0xf) => "
        "{" DUP4("0x%hx", ",") "}\n"
    );

    outfdhu(
        DHU_VEQR(
            newdhu(0xf, 0xe, 0xe, 0xd),
            dupdhu(0xe)
        ),
        stdout,
        "veqrdhu({0xf,0xe,0xe,0xd}, 0xe) => "
        "{" DUP4("0x%hx", ",") "}\n"
    );

    outfdhu(
        DHU_VEQR(
            newdhu(0xf, 0xe, 0xe, 0xd),
            dupdhu(0xd)
        ),
        stdout,
        "veqrdhu({0xf,0xe,0xe,0xd}, 0xd) => "
        "{" DUP4("0x%hx", ",") "}\n"
    );

    outfdhu(
        DHU_VEQR(
            newdhu(0xf, 0xe, 0xe, 0xd),
            dupdhu(0xfeed)
        ),
        stdout,
        "veqrdhu({0xf,0xe,0xe,0xd}, 0xfeed) => "
        "{" DUP4("0x%hx", ",") "}\n"
    );
#endif

#if 0
// veqr
    outfqbu(
        QBU_VEQR(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('f')
        ),
        stdout,
        "veqrqbc(\"f00dfeeddeadbeef\",'f')=>"
        "{" DUP16("%hhu", ",") "}\n"
    );

    outfqbu(
        QBU_VEQR(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('0')
        ),
        stdout,
        "veqrqbc(\"f00dfeeddeadbeef\",'0')=>"
        "{" DUP16("%hhu", ",") "}\n"
    );

    outfqbu(
        QBU_VEQR(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('d')
        ),
        stdout,
        "veqrqbc(\"f00dfeeddeadbeef\",'d')=>"
        "{" DUP16("%hhu", ",") "}\n"
    );

    outfqbu(
        QBU_VEQR(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('e')
        ),
        stdout,
        "veqrqbc(\"f00dfeeddeadbeef\",'e')=>"
        "{" DUP16("%hhu", ",") "}\n"
    );

    outfqbu(
        QBU_VEQR(
            VQBC_ASBU(lunqacbc("f00dfeeddeadbeef")),
            dupqbu('a')
        ),
        stdout,
        "veqrqbc(\"f00dfeeddeadbeef\",'a')=>"
        "{" DUP16("%hhu", ",") "}\n"
    );
#endif

#if 0
    outfdbu(
        DBU_VEQL(
            VDBC_ASBU(lundacbc("01234567")),
            dupdbu('6')
        ),
        stdout,
        "{" DUP8("%hhu", ", ") "}\n"
    );
#endif

#if 0
    outfqhu(
        QHU_VEQL(
            ldpqhu(
                0x0003beef00010000ULL,
                0x0007beef00050004ULL
            ),
            dupqhu(0xbeef)
        ),
        stdout,
        "{" DUP8("%hu", ", ") "}\n"
    );
#endif

#if 0
    outfqhu(
        QHU_VEQS(
            newqhu(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhu(0xf)
        ),
        stdout,
        "veqsqhu(\"deafbeef\", 0xf)=>"
        "{" DUP8("%hu", ",") "}\n"
    );

    outfqhu(
        QHU_VEQS(
            newqhu(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhu(0x9)
        ),
        stdout,
        "veqsqhu(\"deafbeef\", 0x9)=>"
        "{" DUP8("%hu", ",") "}\n"
    );
#endif
    
#if 0
    outfwbu(
        VWBU_VNES(newwbu(+0,+1,+2,+3),newwbu(+0,+1,+2,+3)),
        stdout,
        "vneswbu({+0,+1,+2,+3},{+0,+1,+2,+3}) => "
        "{" DUP4("%+hhi", ",") "}\n"
    );

    outfwbu(
        VWBU_VNES(newwbu(-1,+1,+2,+3),newwbu(+0,+1,+2,+3)),
        stdout,
        "vneswbu({-1,+1,+2,+3},{+0,+1,+2,+3}) => "
        "{" DUP4("%+hhi", ",") "}\n"
    );
#endif

#if 0
    outfdbu(
        DBU_VNES(
            newdbu(+0,+1,+2,+3,+4,+5,+6,+7),
            newdbu(+0,+1,+2,+3,+4,+5,+6,+7)
        ),
        stdout,
        "vnesdbu({+0,+1,+2,+3,+4,+5,+6,+7},{...[0..7]}) => "
        "{" DUP8("%+hhi", ",") "}\n"
    );
    outfdbu(
        DBU_VNES(
            newdbu(+0,+1,+2,+3,+4,+5,+6,+7),
            newdbu(+0,+1,+2,+3,+4,+5,+6,+8)
        ),
        stdout,
        "vnesdbu({+0,+1,+2,+3,+4,+5,+6,+8},{...[0..7]}) => "
        "{" DUP8("%+hhi", ",") "}\n"
    );
#endif
#if 0
    outfqwi(
        QWI_VNES(
            newqwi(-1,-1,-1,-1),
            newqwi(-1,-1,-1,-1)
        ),
        stdout,
        "vnesqwi({-1,-1,-1,-1},{-1,-1,-1,-1})=>"
        "{" DUP4("%+i", ",") "}\n"
    );
    outfqwi(
        QWI_VNES(
            newqwi(-1,-1,-1,-2),
            newqwi(-1,-1,-1,-1)
        ),
        stdout,
        "vnesqwi({-1,-1,-1,-2},{-1,-1,-1,-1})=>"
        "{" DUP4("%+i", ",") "}\n"
    );
    outfqwi(
        QWI_VNES(
            newqwi(+0,+0,+0,+0),
            newqwi(+0,+0,+0,+0)
        ),
        stdout,
        "vnesqwi({+0,+0,+0,+0},{+0,+0,+0,+0})=>"
        "{" DUP4("%+i", ",") "}\n"
    );
    outfqwi(
        QWI_VNES(
            newqwi(+0,+0,+0,+1),
            newqwi(+0,+0,+0,+0)
        ),
        stdout,
        "vnesqwi({+0,+0,+0,+1},{+0,+0,+0,+0})=>"
        "{" DUP4("%+i", ",") "}\n"
    );
    outfqwi(
        QWI_VNES(
            newqwi(+0,+0,+0,+0),
            newqwi(+0,+0,+0,+1)
        ),
        stdout,
        "vnesqwi({+0,+0,+0,+0},{+0,+0,+0,+1})=>"
        "{" DUP4("%+i", ",") "}\n"
    );
    outfqwi(
        QWI_VNES(
            newqwi(+0,+1,+2,+3),
            newqwi(+0,+1,+2,+3)
        ),
        stdout,
        "vnesqwi({+0,+1,+2,+3},{+0,+1,+2,+3})=>"
        "{" DUP4("%+i", ",") "}\n"
    );
#endif

#if 0
    outfqhi(
        QHI_VEQR(
            newqhi(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhi(0xf)
        ),
        stdout,
        "veqrqhi(\"deafbeef\", 0xf)=>"
        "{" DUP8("%hi", ",") "}\n"
    );
    outfqhi(
        QHI_VEQR(
            newqhi(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhi(0xe)
        ),
        stdout,
        "veqrqhi(\"deafbeef\", 0xe)=>"
        "{" DUP8("%hi", ",") "}\n"
    );
    outfqhi(
        QHI_VEQR(
            newqhi(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhi(0xb)
        ),
        stdout,
        "veqrqhi(\"deafbeef\", 0xb)=>"
        "{" DUP8("%hi", ",") "}\n"
    );
    outfqhi(
        QHI_VEQR(
            newqhi(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhi(0xa)
        ),
        stdout,
        "veqrqhi(\"deafbeef\", 0xa)=>"
        "{" DUP8("%hi", ",") "}\n"
    );
    outfqhi(
        QHI_VEQR(
            newqhi(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhi(0xd)
        ),
        stdout,
        "veqrqhi(\"deafbeef\", 0xd)=>"
        "{" DUP8("%hi", ",") "}\n"
    );
    outfqhi(
        QHI_VEQR(
            newqhi(0xd,0xe,0xa,0xf, 0xb,0xe,0xe,0xf),
            dupqhi(-1)
        ),
        stdout,
        "veqrqhi(\"deafbeef\", -1)=>"
        "{" DUP8("%hi", ",") "}\n"
    );

#endif

#if 0
    outfqbc(
        VQBC_VEQL(
            lunqacbc("deadf00d" "faadba7s"),
            dupqbc('5')
        ),
        stdout,
        "{" DUP16("%hhu", ", ") "}\n"
    );
#endif

#if 0
    outfdbu(
        DBU_MULR(seqdbu(1,1), vdup_n_u8(255)),
        stdout,
        "{" DUP8("%hhu", ",") "}\n"
    );
#endif
#if 0
    printf(
        "vneydwi({+0,+0}, {+0,+0}) => %i\n",
        VDWI_VNEY(newdwi(0,0), newdwi(0,0))
    );
    printf(
        "vneydwi({+0,+0}, {+0,+1}) => %i\n",
        VDWI_VNEY(newdwi(0,0), newdwi(0,1))
    );
#endif
#if 0
    outfdbu(
        DBU_VNEN(seqdbu(1,1), newdbu(1,2,3,0, 0,0,0,0)),
        stdout,
        "{" DUP8("%hhu", ",") "}\n"
    );
#endif
    outfdbu(
        DBU_VNEL(
            newdbu(0,1,2,3, 4,5,6,7), 
            newdbu(0,1,2,3, 9,5,6,7)
        ),
        stdout,
        "vneldbu({0,1,2,3, 4,5,6,7}, {0,1,2,3, 9,5,6,7}) => "
        "{" DUP8("%hhu", ",") "}\n"
    );

    if (0)
    {
        struct my_tests t;
        int verbose = 1;
        if (!inittests(&t, AT_FDCWD, "ungop.shm"))
            return  printf("inittests failed??");
        if (opentests(&t)) 
            return -1;
        do 
        {
            if (absl_test(&t, verbose)) break;
            if (addl_test(&t, verbose)) break;
        } 
        while (0);
        
        (void) snprintf(t.Mm, t.Fs.st_size, "%s", "hell nah");
        return shuttests(&t);
    }
    
#if 0
    vdbu = DBU_VEQN(
        newdbu('i','n','i','t', 't','e','s','t'),
        dupdbu('t')
    );
    outfdbu(vdbu,stdout,"{"DUP8("%hhu",",")"}\n");
#endif

    return 0;
    fail:
    {
        return printf("failed test on line %d: %s\n", line, expr);
    }

    
}
