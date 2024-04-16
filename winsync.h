/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

Atomic memory ops for Windows targets

TODO: capitalize macro parameters

*/
#if 1

#include <stdint.h>

typedef signed char schar;
typedef unsigned char uchar;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;

typedef long long llong;
typedef unsigned long long ullong;

#define ADDR_WIDTH 64

#define INLINE(T,K) static inline K

#endif

#define     ATOMIC_FLAG_INIT            {0}

#define     ATOMIC_BOOL_LOCK_FREE       (2)
#define     ATOMIC_CHAR_LOCK_FREE       (2)
#define     ATOMIC_CHAR16_T_LOCK_FREE   (2)
#define     ATOMIC_CHAR32_T_LOCK_FREE   (2)
#define     ATOMIC_WCHAR_T_LOCK_FREE    (2)
#define     ATOMIC_SHORT_LOCK_FREE      (2)
#define     ATOMIC_INT_LOCK_FREE        (2)
#define     ATOMIC_LONG_LOCK_FREE       (2)
#define     ATOMIC_LLONG_LOCK_FREE      (2)
#define     ATOMIC_POINTER_LOCK_FREE    (2)

typedef enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
} memory_order;

typedef long my_atomic_flag;

typedef struct {my_atomic_flag Self;} atomic_flag;

INLINE(memory_order,my_cas_check)
(
    memory_order succ,
    memory_order fail
)
{
    switch (fail)
    {
        case memory_order_release:
        case memory_order_acq_rel: break;
        case memory_order_relaxed:
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_seq_cst:
        {
            if (fail > succ) break;
            if (succ > memory_order_seq_cst) break;
            return succ;
        }
    }
    UNREACHABLE();
    return -1;
}

#define     MY_ILOCKED2(  ...)  __VA_ARGS__
#define     MY_ILOCKED1(F,...)  MY_ILOCKED2(F(__VA_ARGS__))
#define     MY_ILOCKED(F, ...)  MY_ILOCKED1(_Interlocked##F,__VA_ARGS__)

#if defined(_M_ARM) || defined(_M_ARM64)
#   define  MY_RELAXED(F, ...)  MY_ILOCKED(F## _nf,__VA_ARGS__)
#   define  MY_ACQUIRE(F, ...)  MY_ILOCKED(F##_acq,__VA_ARGS__)
#   define  MY_RELEASE(F, ...)  MY_ILOCKED(F##_rel,__VA_ARGS__)
#   define  MY_SEQ_CST(F, ...)  MY_ILOCKED(      F,__VA_ARGS__)
#else
#   define  MY_RELAXED(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#   define  MY_ACQUIRE(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#   define  MY_RELEASE(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#   define  MY_SEQ_CST(F, ...)  MY_ILOCKED(F,__VA_ARGS__)
#endif

INLINE(void, cmba) (void) {_ReadWriteBarrier();}
INLINE(void, cmbe) (void) {_ReadWriteBarrier();}
INLINE(void, cmbt) (void) {_ReadWriteBarrier();}

#if     defined(_M_ARM)
INLINE(void, hmba) (void) {__dmb(_ARM_BARRIER_ISHLD);}
INLINE(void, hmbe) (void) {__dmb(_ARM_BARRIER_ISHST);}
INLINE(void, hmbt) (void) {__dmb(_ARM_BARRIER_ISH);}

INLINE(void, smba) (void) {__dsb(_ARM_BARRIER_ISHLD);}
INLINE(void, smbe) (void) {__dsb(_ARM_BARRIER_ISHST);}
INLINE(void, smbt) (void) {__dsb(_ARM_BARRIER_ISH);}

#elif   defined(_M_ARM64)
INLINE(void, hmba) (void) {__dmb(_ARM64_BARRIER_ISHLD);}
INLINE(void, hmbe) (void) {__dmb(_ARM64_BARRIER_ISHST);}
INLINE(void, hmbt) (void) {__dmb(_ARM64_BARRIER_ISH);}

INLINE(void, smba) (void) {__dsb(_ARM64_BARRIER_ISHLD);}
INLINE(void, smbe) (void) {__dsb(_ARM64_BARRIER_ISHST);}
INLINE(void, smbt) (void) {__dsb(_ARM64_BARRIER_ISH);}

#elif defined(_M_X64)
INLINE(void, hmba) (void) {_ReadWriteBarrier();}
INLINE(void, hmbe) (void) {_ReadWriteBarrier();}
INLINE(void, hmbt) (void) {_ReadWriteBarrier();}

INLINE(void, smba) (void) {_mm_lfence();}
INLINE(void, smbe) (void) {_mm_sfence();}
INLINE(void, smbt) (void) {_mm_mfence();}

#else
INLINE(void, hmba) (void) {_ReadWriteBarrier();}
INLINE(void, hmbe) (void) {_ReadWriteBarrier();}
INLINE(void, hmbt) (void) {_ReadWriteBarrier();}

INLINE(void, smba) (void) {_mm_lfence();}
INLINE(void, smbe) (void) {_mm_sfence();}
INLINE(void, smbt) (void) {_mm_mfence();}

#endif

#if !defined(_MSC_VER)
#   error "expected msvc"

#elif defined(_M_ARM)
#   define  MY_HMBT             __dmb(_ARM_BARRIER_ISH)
#   define  MY_LDR1(W, A)       __iso_volatile_load##W(A)
#   define  MY_STR1(W, A, B)    __iso_volatile_store##W(A,B)
#   define  MY_STRT(W, A, B)        \
do {                                \
    MY_HMBT;                        \
    __iso_volatile_store##W(A,B);   \
    MY_HMBT;                        \
} while(0)

#elif defined(_M_ARM64)
#   define  MY_HMBT             __dmb(_ARM64_BARRIER_ISH)
#   define  MY_LDR1(W, A)       __iso_volatile_load##W(A)
#   define  MY_STR1(W, A, B)    __iso_volatile_store##W(A,B)
#   define  MY_STRT(W, A, B)        \
do {                                \
    MY_HMBT;                        \
    __iso_volatile_store##W(A,B);   \
    MY_HMBT;                        \
} while(0)

#elif defined(_M_X64)

#   define  MY_HMBT             _ReadWriteBarrier
#   define  MY_LDR1(W, S)       (*S)
#   define  MY_STR1(W, D, S)    (*D=S)
#   define  MY_STRT(W, D, S)    ((void) MY_SWPT##W(D,S))

#else
#   define  MY_HMBT             _ReadWriteBarrier
#   define  MY_LDR1(W, A)       \
(                               \
    ((sizeof *(A)) < 8)         \
    ?   *(A)                    \
    :   _InterlockedOr64(       \
            ((void volatile*)A),\
            0                   \
        )                       \
)

#   define  MY_STR1(W, A, B)    \
(                               \
    ((sizeof*(A)) < 8)          \
    ?   ((*(B))=(A))            \
    :   _InterlockedExchange64( \
            ((void volatile*)A),\
            B                   \
        )                       \
)

#   define  MY_STRT(W, A, B)    ((void) MY_SWPT##W(A,B))
#endif

#define MY_SWPT8  MY_SWPTB
#define MY_SWPT16 MY_SWPTH
#define MY_SWPT32 MY_SWPTW
#define MY_SWPT64 MY_SWPTD



INLINE( char, MY_SWP1B)  (void volatile *a, char b)
{
    return  MY_RELAXED(Exchange8, a, b);
}

INLINE(short, MY_SWP1H) (void volatile *a, short b)
{
    return  MY_RELAXED(Exchange16, a, b);
}

INLINE(  int, MY_SWP1W) (void volatile *a, long b)
{
    return  MY_RELAXED(Exchange, a, b);
}

INLINE(llong, MY_SWP1D) (void volatile *a, llong b)
{
    return  MY_RELAXED(Exchange64, a, b);
}


INLINE( char, MY_SWPAB)  (void volatile *a, char b)
{
    return  MY_ACQUIRE(Exchange8, a, b);
}

INLINE(short, MY_SWPAH) (void volatile *a, short b)
{
    return  MY_ACQUIRE(Exchange16, a, b);
}

INLINE(  int, MY_SWPAW) (void volatile *a, long b)
{
    return  MY_ACQUIRE(Exchange, a, b);
}

INLINE(llong, MY_SWPAD) (void volatile *a, llong b)
{
    return  MY_ACQUIRE(Exchange64, a, b);
}


INLINE( char, MY_SWPEB)  (void volatile *a, char b)
{
    return  MY_RELEASE(Exchange8, a, b);
}

INLINE(short, MY_SWPEH) (void volatile *a, short b)
{
    return  MY_RELEASE(Exchange16, a, b);
}

INLINE(  int, MY_SWPEW) (void volatile *a, long b)
{
    return  MY_RELEASE(Exchange, a, b);
}

INLINE(llong, MY_SWPED) (void volatile *a, llong b)
{
    return  MY_RELEASE(Exchange64, a, b);
}


INLINE( char, MY_SWPTB)  (void volatile *a, char b)
{
    return  MY_SEQ_CST(Exchange8, a, b);
}

INLINE(short, MY_SWPTH) (void volatile *a, short b)
{
    return  MY_SEQ_CST(Exchange16, a, b);
}

INLINE(  int,MY_SWPTW) (void volatile *a, long b)
{
    return  MY_SEQ_CST(Exchange, a, b);
}

INLINE(llong,MY_SWPTD) (void volatile *a, llong b)
{
    return  MY_SEQ_CST(Exchange64, a, b);
}


INLINE( char,MY_XEQ1B) (void volatile *a,  char b,  char c)
{

    return  MY_RELAXED(CompareExchange8, a, c, b);
}

INLINE(short,MY_XEQ1H) (void volatile *a, short b, short c)
{
    return  MY_RELAXED(CompareExchange16, a, c, b);
}

INLINE( long,MY_XEQ1W) (void volatile *a,  long b,  long c)
{
    return  MY_RELAXED(CompareExchange, a, c, b);
}

INLINE(llong,MY_XEQ1D) (void volatile *a, llong b, llong c)
{
    return  MY_RELAXED(CompareExchange64, a, c, b);
}


INLINE( char,MY_XEQAB) (void volatile *a,  char b,  char c)
{
    return  MY_ACQUIRE(CompareExchange8, a, c, b);
}

INLINE(short,MY_XEQAH) (void volatile *a, short b, short c)
{
    return  MY_ACQUIRE(CompareExchange16, a, c, b);
}

INLINE( long,MY_XEQAW) (void volatile *a,  long b,  long c)
{
    return  MY_ACQUIRE(CompareExchange, a, c, b);
}

INLINE(llong,MY_XEQAD) (void volatile *a, llong b, llong c)
{
    return  MY_ACQUIRE(CompareExchange64, a, c, b);
}


INLINE( char,MY_XEQEB) (void volatile *a,  char b,  char c)
{
    return  MY_RELEASE(CompareExchange8, a, c, b);
}

INLINE(short,MY_XEQEH) (void volatile *a, short b, short c)
{
    return  MY_RELEASE(CompareExchange16, a, c, b);
}

INLINE( long,MY_XEQEW) (void volatile *a,  long b,  long c)
{
    return  MY_RELEASE(CompareExchange, a, c, b);
}

INLINE(llong,MY_XEQED) (void volatile *a, llong b, llong c)
{
    return  MY_RELEASE(CompareExchange64, a, c, b);
}


INLINE( char,MY_XEQTB) (void volatile *a,  char b,  char c)
{
    return  MY_SEQ_CST(CompareExchange8, a, c, b);
}

INLINE(short,MY_XEQTH) (void volatile *a, short b, short c)
{
    return  MY_SEQ_CST(CompareExchange16, a, c, b);
}

INLINE( long,MY_XEQTW) (void volatile *a,  long b,  long c)
{
    return  MY_SEQ_CST(CompareExchange, a, c, b);
}

INLINE(llong,MY_XEQTD) (void volatile *a, llong b, llong c)
{
    return  MY_SEQ_CST(CompareExchange64, a, c, b);
}


INLINE( char,MY_LDR1B) (void volatile const *src)
{
    return  MY_LDR1(8, ((char volatile const *) src));
}

INLINE(short,MY_LDR1H) (void volatile const *src)
{
    return  MY_LDR1(16, ((short volatile const *) src));
}

INLINE(  int,MY_LDR1W) (void volatile const *src)
{
    return  MY_LDR1(32, ((int volatile const *) src));
}

INLINE(llong,MY_LDR1D) (void volatile const *src)
{
    return  MY_LDR1(64, ((llong volatile const *) src));
}



INLINE( char,MY_LDRAB) (void volatile const *src)
{
    return  MY_LDR1(8, ((char volatile const *) src));
}

INLINE(short,MY_LDRAH) (void volatile const *src)
{
    return  MY_LDR1(16, ((short volatile const *) src));
}

INLINE(  int,MY_LDRAW) (void volatile const *src)
{
    return  MY_LDR1(32, ((int volatile const *) src));
}

INLINE(llong,MY_LDRAD) (void volatile const *src)
{
    return  MY_LDR1(64, ((llong volatile const *) src));
}


INLINE( char,MY_LDRTB) (void volatile const *src)
{
    char r = MY_LDR1B(src);
    MY_HMBT();
    return r;
}

INLINE(short,MY_LDRTH) (void volatile const *src)
{
    short r = MY_LDR1H(src);
    MY_HMBT();
    return r;
}

INLINE(  int,MY_LDRTW) (void volatile const *src)
{
    int r = MY_LDR1W(src);
    MY_HMBT();
    return r;
}

INLINE(llong,MY_LDRTD) (void volatile const *src)
{
    llong r = MY_LDR1D(src);
    MY_HMBT();
    return r;
}




INLINE( char,MY_STR1B)  (void volatile *dst,  char src)
{
    MY_STR1(8, ((char volatile *) dst), src);
    return  src;
}

INLINE(short,MY_STR1H)  (void volatile *dst, short src)
{
    MY_STR1(16, ((short volatile *) dst), src);
    return  src;
}

INLINE(  int,MY_STR1W)  (void volatile *dst,   int src)
{
    MY_STR1(32, ((int volatile *) dst), src);
    return  src;
}

INLINE(llong,MY_STR1D)  (void volatile *dst, llong src)
{
    MY_STR1(64, ((llong volatile *) dst), src);
    return  src;
}


INLINE( char,MY_STREB)  (void volatile *dst,  char src)
{
    MY_STR1(8, ((char volatile *) dst), src);
    return  src;
}

INLINE(short,MY_STREH)  (void volatile *dst, short src)
{
    MY_STR1(16, ((short volatile *) dst), src);
    return  src;
}

INLINE(  int,MY_STREW)  (void volatile *dst,   int src)
{
    MY_STR1(32, ((int volatile *) dst), src);
    return  src;
}

INLINE(llong,MY_STRED)  (void volatile *dst, llong src)
{
    MY_STR1(64, ((llong volatile *) dst), src);
    return  src;
}


INLINE( char,MY_STRTB)  (void volatile *dst,  char src)
{
    MY_STRT(8, ((char volatile *) dst), src);
    return  src;
}

INLINE(short,MY_STRTH)  (void volatile *dst, short src)
{
    MY_STRT(16, ((short volatile *) dst), src);
    return  src;
}

INLINE(  int,MY_STRTW)  (void volatile *dst,   int src)
{
    MY_STRT(32, ((int volatile *) dst), src);
    return  src;
}

INLINE(llong,MY_STRTD)  (void volatile *dst, llong src)
{
    MY_STRT(64, ((llong volatile *) dst), src);
    return  src;
}




INLINE( char,MY_ADD1B) (void volatile *a,  char b)
{
    return  MY_RELAXED(ExchangeAdd8, a, b);
}

INLINE(short,MY_ADD1H) (void volatile *a, short b)
{
    return  MY_RELAXED(ExchangeAdd16, a, b);
}

INLINE( long,MY_ADD1W) (void volatile *a,  long b)
{
    return  MY_RELAXED(ExchangeAdd, a, b);
}

INLINE(llong,MY_ADD1D) (void volatile *a, llong b)
{
    return  MY_RELAXED(ExchangeAdd64, a, b);
}


INLINE( char,MY_ADDAB) (void volatile *a,  char b)
{
    return  MY_ACQUIRE(ExchangeAdd8, a, b);
}

INLINE(short,MY_ADDAH) (void volatile *a, short b)
{
    return  MY_ACQUIRE(ExchangeAdd16, a, b);
}

INLINE( long,MY_ADDAW) (void volatile *a,  long b)
{
    return  MY_ACQUIRE(ExchangeAdd, a, b);
}

INLINE(llong,MY_ADDAD) (void volatile *a, llong b)
{
    return  MY_ACQUIRE(ExchangeAdd64, a, b);
}



INLINE( char,MY_ADDEB) (void volatile *a,  char b)
{
    return  MY_RELEASE(ExchangeAdd8, a, b);
}

INLINE(short,MY_ADDEH) (void volatile *a, short b)
{
    return  MY_RELEASE(ExchangeAdd16, a, b);
}

INLINE( long,MY_ADDEW) (void volatile *a,  long b)
{
    return  MY_RELEASE(ExchangeAdd, a, b);
}

INLINE(llong,MY_ADDED) (void volatile *a, llong b)
{
    return  MY_RELEASE(ExchangeAdd64, a, b);
}


INLINE( char,MY_ADDTB) (void volatile *a,  char b)
{
    return  MY_SEQ_CST(ExchangeAdd8, a, b);
}

INLINE(short,MY_ADDTH) (void volatile *a, short b)
{
    return  MY_SEQ_CST(ExchangeAdd16, a, b);
}

INLINE( long,MY_ADDTW) (void volatile *a,  long b)
{
    return  MY_SEQ_CST(ExchangeAdd, a, b);
}

INLINE(llong,MY_ADDTD) (void volatile *a, llong b)
{
    return  MY_SEQ_CST(ExchangeAdd64, a, b);
}



INLINE( char,MY_SUB1B) (void volatile *a,  char b)
{
    return  MY_RELAXED(Add8, a, -b);
}

INLINE(short,MY_SUB1H) (void volatile *a, short b)
{
    return  MY_RELAXED(Add16, a, -b);
}

INLINE( long,MY_SUB1W) (void volatile *a,  long b)
{
    return  MY_RELAXED(Add, a, -b);
}

INLINE(llong,MY_SUB1D) (void volatile *a, llong b)
{
    return  MY_RELAXED(Add64, a, -b);
}


INLINE( char,MY_SUBAB) (void volatile *a,  char b)
{
    return  MY_ACQUIRE(Add8, a, -b);
}

INLINE(short,MY_SUBAH) (void volatile *a, short b)
{
    return  MY_ACQUIRE(Add16, a, -b);
}

INLINE( long,MY_SUBAW) (void volatile *a,  long b)
{
    return  MY_ACQUIRE(Add, a, -b);
}

INLINE(llong,MY_SUBAD) (void volatile *a, llong b)
{
    return  MY_ACQUIRE(Add64, a, -b);
}



INLINE( char,MY_SUBEB) (void volatile *a,  char b)
{
    return  MY_RELEASE(Add8, a, -b);
}

INLINE(short,MY_SUBEH) (void volatile *a, short b)
{
    return  MY_RELEASE(Add16, a, -b);
}

INLINE( long,MY_SUBEW) (void volatile *a,  long b)
{
    return  MY_RELEASE(Add, a, -b);
}

INLINE(llong,MY_SUBED) (void volatile *a, llong b)
{
    return  MY_RELEASE(Add64, a, -b);
}


INLINE( char,MY_SUBTB) (void volatile *a,  char b)
{
    return  MY_SEQ_CST(Add8, a, -b);
}

INLINE(short,MY_SUBTH) (void volatile *a, short b)
{
    return  MY_SEQ_CST(Add16, a, -b);
}

INLINE( long,MY_SUBTW) (void volatile *a,  long b)
{
    return  MY_SEQ_CST(Add, a, -b);
}

INLINE(llong,MY_SUBTD) (void volatile *a, llong b)
{
    return  MY_SEQ_CST(Add64, a, -b);
}




INLINE( char,MY_AND1B) (void volatile *a,  char b)
{
    return  MY_RELAXED(And8, a, b);
}

INLINE(short,MY_AND1H) (void volatile *a, short b)
{
    return  MY_RELAXED(And16, a, b);
}

INLINE( long,MY_AND1W) (void volatile *a,  long b)
{
    return  MY_RELAXED(And, a, b);
}

INLINE(llong,MY_AND1D) (void volatile *a, llong b)
{
    return  MY_RELAXED(And64, a, b);
}


INLINE( char,MY_ANDAB) (void volatile *a,  char b)
{
    return  MY_ACQUIRE(And8, a, b);
}

INLINE(short,MY_ANDAH) (void volatile *a, short b)
{
    return  MY_ACQUIRE(And16, a, b);
}

INLINE( long,MY_ANDAW) (void volatile *a,  long b)
{
    return  MY_ACQUIRE(And, a, b);
}

INLINE(llong,MY_ANDAD) (void volatile *a, llong b)
{
    return  MY_ACQUIRE(And64, a, b);
}



INLINE( char,MY_ANDEB) (void volatile *a,  char b)
{
    return  MY_RELEASE(And8, a, b);
}

INLINE(short,MY_ANDEH) (void volatile *a, short b)
{
    return  MY_RELEASE(And16, a, b);
}

INLINE( long,MY_ANDEW) (void volatile *a,  long b)
{
    return  MY_RELEASE(And, a, b);
}

INLINE(llong,MY_ANDED) (void volatile *a, llong b)
{
    return  MY_RELEASE(And64, a, b);
}


INLINE( char,MY_ANDTB) (void volatile *a,  char b)
{
    return  MY_SEQ_CST(And8, a, b);
}

INLINE(short,MY_ANDTH) (void volatile *a, short b)
{
    return  MY_SEQ_CST(And16, a, b);
}

INLINE( long,MY_ANDTW) (void volatile *a,  long b)
{
    return  MY_SEQ_CST(And, a, b);
}

INLINE(llong,MY_ANDTD) (void volatile *a, llong b)
{
    return  MY_SEQ_CST(And64, a, b);
}




INLINE( char,MY_ORR1B) (void volatile *a,  char b)
{
    return  MY_RELAXED(Or8, a, b);
}

INLINE(short,MY_ORR1H) (void volatile *a, short b)
{
    return  MY_RELAXED(Or16, a, b);
}

INLINE( long,MY_ORR1W) (void volatile *a,  long b)
{
    return  MY_RELAXED(Or, a, b);
}

INLINE(llong,MY_ORR1D) (void volatile *a, llong b)
{
    return  MY_RELAXED(Or64, a, b);
}


INLINE( char,MY_ORRAB) (void volatile *a,  char b)
{
    return  MY_ACQUIRE(Or8, a, b);
}

INLINE(short,MY_ORRAH) (void volatile *a, short b)
{
    return  MY_ACQUIRE(Or16, a, b);
}

INLINE( long,MY_ORRAW) (void volatile *a,  long b)
{
    return  MY_ACQUIRE(Or, a, b);
}

INLINE(llong,MY_ORRAD) (void volatile *a, llong b)
{
    return  MY_ACQUIRE(Or64, a, b);
}



INLINE( char,MY_ORREB) (void volatile *a,  char b)
{
    return  MY_RELEASE(Or8, a, b);
}

INLINE(short,MY_ORREH) (void volatile *a, short b)
{
    return  MY_RELEASE(Or16, a, b);
}

INLINE( long,MY_ORREW) (void volatile *a,  long b)
{
    return  MY_RELEASE(Or, a, b);
}

INLINE(llong,MY_ORRED) (void volatile *a, llong b)
{
    return  MY_RELEASE(Or64, a, b);
}


INLINE( char,MY_ORRTB) (void volatile *a,  char b)
{
    return  MY_SEQ_CST(Or8, a, b);
}

INLINE(short,MY_ORRTH) (void volatile *a, short b)
{
    return  MY_SEQ_CST(Or16, a, b);
}

INLINE( long,MY_ORRTW) (void volatile *a,  long b)
{
    return  MY_SEQ_CST(Or, a, b);
}

INLINE(llong,MY_ORRTD) (void volatile *a, llong b)
{
    return  MY_SEQ_CST(Or64, a, b);
}




INLINE( char,MY_XOR1B) (void volatile *a,  char b)
{
    return  MY_RELAXED(Xor8, a, b);
}

INLINE(short,MY_XOR1H) (void volatile *a, short b)
{
    return  MY_RELAXED(Xor16, a, b);
}

INLINE( long,MY_XOR1W) (void volatile *a,  long b)
{
    return  MY_RELAXED(Xor, a, b);
}

INLINE(llong,MY_XOR1D) (void volatile *a, llong b)
{
    return  MY_RELAXED(Xor64, a, b);
}


INLINE( char,MY_XORAB) (void volatile *a,  char b)
{
    return  MY_ACQUIRE(Xor8, a, b);
}

INLINE(short,MY_XORAH) (void volatile *a, short b)
{
    return  MY_ACQUIRE(Xor16, a, b);
}

INLINE( long,MY_XORAW) (void volatile *a,  long b)
{
    return  MY_ACQUIRE(Xor, a, b);
}

INLINE(llong,MY_XORAD) (void volatile *a, llong b)
{
    return  MY_ACQUIRE(Xor64, a, b);
}



INLINE( char,MY_XOREB) (void volatile *a,  char b)
{
    return  MY_RELEASE(Xor8, a, b);
}

INLINE(short,MY_XOREH) (void volatile *a, short b)
{
    return  MY_RELEASE(Xor16, a, b);
}

INLINE( long,MY_XOREW) (void volatile *a,  long b)
{
    return  MY_RELEASE(Xor, a, b);
}

INLINE(llong,MY_XORED) (void volatile *a, llong b)
{
    return  MY_RELEASE(Xor64, a, b);
}


INLINE( char,MY_XORTB) (void volatile *a,  char b)
{
    return  MY_SEQ_CST(Xor8, a, b);
}

INLINE(short,MY_XORTH) (void volatile *a, short b)
{
    return  MY_SEQ_CST(Xor16, a, b);
}

INLINE( long,MY_XORTW) (void volatile *a,  long b)
{
    return  MY_SEQ_CST(Xor, a, b);
}

INLINE(llong,MY_XORTD) (void volatile *a, llong b)
{
    return  MY_SEQ_CST(Xor64, a, b);
}






INLINE( char,MY_INV1B) (void volatile *a)
{
    return  MY_RELAXED(Xor8, a, -1);
}

INLINE(short,MY_INV1H) (void volatile *a)
{
    return  MY_RELAXED(Xor16, a, -1);
}

INLINE( long,MY_INV1W) (void volatile *a)
{
    return  MY_RELAXED(Xor, a, -1);
}

INLINE(llong,MY_INV1D) (void volatile *a)
{
    return  MY_RELAXED(Xor64, a, -1);
}


INLINE( char,MY_INVAB) (void volatile *a)
{
    return  MY_ACQUIRE(Xor8, a, -1);
}

INLINE(short,MY_INVAH) (void volatile *a)
{
    return  MY_ACQUIRE(Xor16, a, -1);
}

INLINE( long,MY_INVAW) (void volatile *a)
{
    return  MY_ACQUIRE(Xor, a, -1);
}

INLINE(llong,MY_INVAD) (void volatile *a)
{
    return  MY_ACQUIRE(Xor64, a, -1);
}



INLINE( char,MY_INVEB) (void volatile *a)
{
    return  MY_RELEASE(Xor8, a, -1);
}

INLINE(short,MY_INVEH) (void volatile *a)
{
    return  MY_RELEASE(Xor16, a, -1);
}

INLINE( long,MY_INVEW) (void volatile *a)
{
    return  MY_RELEASE(Xor, a, -1);
}

INLINE(llong,MY_INVED) (void volatile *a)
{
    return  MY_RELEASE(Xor64, a, -1);
}


INLINE( char,MY_INVTB) (void volatile *a)
{
    return  MY_SEQ_CST(Xor8, a, -1);
}

INLINE(short,MY_INVTH) (void volatile *a)
{
    return  MY_SEQ_CST(Xor16, a, -1);
}

INLINE( long,MY_INVTW) (void volatile *a)
{
    return  MY_SEQ_CST(Xor, a, -1);
}

INLINE(llong,MY_INVTD) (void volatile *a)
{
    return  MY_SEQ_CST(Xor64, a, -1);
}






INLINE( char,MY_DCR1B) (void volatile *a)
{
    return  MY_RELAXED(Add8, a, -1);
}

INLINE(short,MY_DCR1H) (void volatile *a)
{
    return  MY_RELAXED(Add16, a, -1);
}

INLINE( long,MY_DCR1W) (void volatile *a)
{
    return  MY_RELAXED(Add, a, -1);
}

INLINE(llong,MY_DCR1D) (void volatile *a)
{
    return  MY_RELAXED(Add64, a, -1);
}


INLINE( char,MY_DCRAB) (void volatile *a)
{
    return  MY_ACQUIRE(Add8, a, -1);
}

INLINE(short,MY_DCRAH) (void volatile *a)
{
    return  MY_ACQUIRE(Add16, a, -1);
}

INLINE( long,MY_DCRAW) (void volatile *a)
{
    return  MY_ACQUIRE(Add, a, -1);
}

INLINE(llong,MY_DCRAD) (void volatile *a)
{
    return  MY_ACQUIRE(Add64, a, -1);
}



INLINE( char,MY_DCREB) (void volatile *a)
{
    return  MY_RELEASE(Add8, a, -1);
}

INLINE(short,MY_DCREH) (void volatile *a)
{
    return  MY_RELEASE(Add16, a, -1);
}

INLINE( long,MY_DCREW) (void volatile *a)
{
    return  MY_RELEASE(Add, a, -1);
}

INLINE(llong,MY_DCRED) (void volatile *a)
{
    return  MY_RELEASE(Add64, a, -1);
}


INLINE( char,MY_DCRTB) (void volatile *a)
{
    return  MY_SEQ_CST(Add8, a, -1);
}

INLINE(short,MY_DCRTH) (void volatile *a)
{
    return  MY_SEQ_CST(Add16, a, -1);
}

INLINE( long,MY_DCRTW) (void volatile *a)
{
    return  MY_SEQ_CST(Add, a, -1);
}

INLINE(llong,MY_DCRTD) (void volatile *a)
{
    return  MY_SEQ_CST(Add64, a, -1);
}





INLINE( char,MY_ICR1B) (void volatile *a)
{
    return  MY_RELAXED(Add8, a, 1);
}

INLINE(short,MY_ICR1H) (void volatile *a)
{
    return  MY_RELAXED(Add16, a, 1);
}

INLINE( long,MY_ICR1W) (void volatile *a)
{
    return  MY_RELAXED(Add, a, 1);
}

INLINE(llong,MY_ICR1D) (void volatile *a)
{
    return  MY_RELAXED(Add64, a, 1);
}


INLINE( char,MY_ICRAB) (void volatile *a)
{
    return  MY_ACQUIRE(Add8, a, 1);
}

INLINE(short,MY_ICRAH) (void volatile *a)
{
    return  MY_ACQUIRE(Add16, a, 1);
}

INLINE( long,MY_ICRAW) (void volatile *a)
{
    return  MY_ACQUIRE(Add, a, 1);
}

INLINE(llong,MY_ICRAD) (void volatile *a)
{
    return  MY_ACQUIRE(Add64, a, 1);
}


INLINE( char,MY_ICREB) (void volatile *a)
{
    return  MY_RELEASE(Add8, a, 1);
}

INLINE(short,MY_ICREH) (void volatile *a)
{
    return  MY_RELEASE(Add16, a, 1);
}

INLINE( long,MY_ICREW) (void volatile *a)
{
    return  MY_RELEASE(Add, a, 1);
}

INLINE(llong,MY_ICRED) (void volatile *a)
{
    return  MY_RELEASE(Add64, a, 1);
}


INLINE( char,MY_ICRTB) (void volatile *a)
{
    return  MY_SEQ_CST(Add8, a, 1);
}

INLINE(short,MY_ICRTH) (void volatile *a)
{
    return  MY_SEQ_CST(Add16, a, 1);
}

INLINE( long,MY_ICRTW) (void volatile *a)
{
    return  MY_SEQ_CST(Add, a, 1);
}

INLINE(llong,MY_ICRTD) (void volatile *a)
{
    return  MY_SEQ_CST(Add64, a, 1);
}




#if _ENTER_MSVC_SWP1
{
#endif

INLINE( _Bool,  BOOL_SWP1)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_SWP1B(a, b);
}

INLINE( uchar, UCHAR_SWP1)  (uchar volatile a[1],  uchar b)
{
    return  MY_SWP1B(a, b);
}

INLINE( schar, SCHAR_SWP1)  (schar volatile a[1],  schar b)
{
    return  MY_SWP1B(a, b);
}

INLINE(  char,  CHAR_SWP1)   (char volatile a[1],   char b)
{
    return  MY_SWP1B(a, b);
}


INLINE(ushort, USHRT_SWP1) (ushort volatile a[1], ushort b)
{
    return  MY_SWP1H(a, b);
}

INLINE( short,  SHRT_SWP1) (short volatile  a[1],  short b)
{
    return  MY_SWP1H(a, b);
}


INLINE(  uint,  UINT_SWP1)   (uint volatile a[1],   uint b)
{
    return  MY_SWP1W(a, b);
}

INLINE(   int,   INT_SWP1)    (int volatile a[1],    int b)
{
    return  MY_SWP1W(a, b);
}


INLINE( ulong, ULONG_SWP1)  (ulong volatile a[1], ulong b)
{
    return  MY_SWP1W(a, b);
}

INLINE(  long,  LONG_SWP1)   (long volatile a[1],   long b)
{
    return  MY_SWP1W(a, b);
}


INLINE(ullong,ULLONG_SWP1) (ullong volatile a[1], ullong b)
{
    return  MY_SWP1D(a, b);
}

INLINE( llong, LLONG_SWP1)  (llong volatile a[1],  llong b)
{
    return  MY_SWP1D(a, b);
}


INLINE(void *,  ADDR_SWP1A)
(
    void const *volatile    a[1],
    void const *            b
)
{
#if ADDR_WIDTH == 32
    return  INT_SWP1(((int volatile *) a), ((int) b));
#else
    return  LLONG_SWP1(((llong volatile *) a), ((llong) b));
#endif

}


#if _LEAVE_MSVC_SWP1
}
#endif

#if _ENTER_MSVC_SWPA
{
#endif

INLINE( _Bool,  BOOL_SWPA)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_SWPAB(a, b);
}

INLINE( uchar, UCHAR_SWPA)  (uchar volatile a[1],  uchar b)
{
    return  MY_SWPAB(a, b);
}

INLINE( schar, SCHAR_SWPA)  (schar volatile a[1],  schar b)
{
    return  MY_SWPAB(a, b);
}

INLINE(  char,  CHAR_SWPA)   (char volatile a[1],   char b)
{
    return  MY_SWPAB(a, b);
}


INLINE(ushort, USHRT_SWPA) (ushort volatile a[1], ushort b)
{
    return  MY_SWPAH(a, b);
}

INLINE( short,  SHRT_SWPA) (short volatile  a[1],  short b)
{
    return  MY_SWPAH(a, b);
}


INLINE(  uint,  UINT_SWPA)   (uint volatile a[1],   uint b)
{
    return  MY_SWPAW(a, b);
}

INLINE(   int,   INT_SWPA)    (int volatile a[1],    int b)
{
    return  MY_SWPAW(a, b);
}


INLINE( ulong, ULONG_SWPA)  (ulong volatile a[1], ulong b)
{
    return  MY_SWPAW(a, b);
}

INLINE(  long,  LONG_SWPA)   (long volatile a[1],   long b)
{
    return  MY_SWPAW(a, b);
}


INLINE(ullong,ULLONG_SWPA) (ullong volatile a[1], ullong b)
{
    return  MY_SWPAD(a, b);
}

INLINE( llong, LLONG_SWPA)  (llong volatile a[1],  llong b)
{
    return  MY_SWPAD(a, b);
}


INLINE(void *,  ADDR_SWPAA)
(
    void const *volatile    a[1],
    void const *            b
)
{
#if ADDR_WIDTH == 32
    return  INT_SWPA(((int volatile *) a), ((int) b));
#else
    return  LLONG_SWPA(((llong volatile *) a), ((llong) b));
#endif

}


#if _LEAVE_MSVC_SWPA
}
#endif

#if _ENTER_MSVC_SWPE
{
#endif

INLINE( _Bool,  BOOL_SWPE)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_SWPEB(a, b);
}


INLINE( uchar, UCHAR_SWPE)  (uchar volatile a[1],  uchar b)
{
    return  MY_SWPEB(a, b);
}

INLINE( schar, SCHAR_SWPE)  (schar volatile a[1],  schar b)
{
    return  MY_SWPEB(a, b);
}

INLINE(  char,  CHAR_SWPE)   (char volatile a[1],   char b)
{
    return  MY_SWPEB(a, b);
}


INLINE(ushort, USHRT_SWPE) (ushort volatile a[1], ushort b)
{
    return  MY_SWPEH(a, b);
}

INLINE( short,  SHRT_SWPE) (short volatile  a[1],  short b)
{
    return  MY_SWPEH(a, b);
}


INLINE(  uint,  UINT_SWPE)   (uint volatile a[1],   uint b)
{
    return  MY_SWPEW(a, b);
}

INLINE(   int,   INT_SWPE)    (int volatile a[1],    int b)
{
    return  MY_SWPEW(a, b);
}


INLINE( ulong, ULONG_SWPE)  (ulong volatile a[1], ulong b)
{
    return  MY_SWPEW(a, b);
}

INLINE(  long,  LONG_SWPE)   (long volatile a[1],   long b)
{
    return  MY_SWPEW(a, b);
}


INLINE(ullong,ULLONG_SWPE) (ullong volatile a[1], ullong b)
{
    return  MY_SWPED(a, b);
}

INLINE( llong, LLONG_SWPE)  (llong volatile a[1],  llong b)
{
    return  MY_SWPED(a, b);
}


INLINE(void *,  ADDR_SWPEA)
(
    void const *volatile    a[1],
    void const *            b
)
{
#if ADDR_WIDTH == 32
    return  INT_SWPE(((int volatile *) a), ((int) b));
#else
    return  LLONG_SWPE(((llong volatile *) a), ((llong) b));
#endif

}

#if _LEAVE_MSVC_SWPE
}
#endif

#if _ENTER_MSVC_SWPT
{
#endif

INLINE( _Bool,  BOOL_SWPT)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_SWPTB(a, b);
}

INLINE( uchar, UCHAR_SWPT)  (uchar volatile a[1],  uchar b)
{
    return  MY_SWPTB(a, b);
}

INLINE( schar, SCHAR_SWPT)  (schar volatile a[1],  schar b)
{
    return  MY_SWPTB(a, b);
}

INLINE(  char,  CHAR_SWPT)   (char volatile a[1],   char b)
{
    return  MY_SWPTB(a, b);
}


INLINE(ushort, USHRT_SWPT) (ushort volatile a[1], ushort b)
{
    return  MY_SWPTH(a, b);
}

INLINE( short,  SHRT_SWPT) (short volatile  a[1],  short b)
{
    return  MY_SWPTH(a, b);
}


INLINE(  uint,  UINT_SWPT)   (uint volatile a[1],   uint b)
{
    return  MY_SWPTW(a, b);
}

INLINE(   int,   INT_SWPT)    (int volatile a[1],    int b)
{
    return  MY_SWPTW(a, b);
}


INLINE( ulong, ULONG_SWPT)  (ulong volatile a[1], ulong b)
{
    return  MY_SWPTW(a, b);
}

INLINE(  long,  LONG_SWPT)   (long volatile a[1],   long b)
{
    return  MY_SWPTW(a, b);
}


INLINE(ullong,ULLONG_SWPT) (ullong volatile a[1], ullong b)
{
    return  MY_SWPTD(a, b);
}

INLINE( llong, LLONG_SWPT)  (llong volatile a[1],  llong b)
{
    return  MY_SWPTD(a, b);
}


INLINE(void *,  ADDR_SWPTA)
(
    void const *volatile    a[1],
    void const *            b
)
{
#if ADDR_WIDTH == 32
    return  INT_SWPT(((int volatile *) a), ((int) b));
#else
    return  LLONG_SWPT(((llong volatile *) a), ((llong) b));
#endif

}


#if _LEAVE_MSVC_SWPT
}
#endif


#if _ENTER_MSVC_ADD1
{
#endif

INLINE( _Bool,  BOOL_ADD1)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XOR1B(a, b);
}


INLINE( uchar, UCHAR_ADD1)  (uchar volatile a[1],  uchar b)
{
    return  MY_ADD1B(a, b);
}

INLINE( schar, SCHAR_ADD1)  (schar volatile a[1],  schar b)
{
    return  MY_ADD1B(a, b);
}

INLINE(  char,  CHAR_ADD1)   (char volatile a[1],   char b)
{
    return  MY_ADD1B(a, b);
}


INLINE(ushort, USHRT_ADD1) (ushort volatile a[1], ushort b)
{
    return  MY_ADD1H(a, b);
}

INLINE( short,  SHRT_ADD1) (short volatile  a[1],  short b)
{
    return  MY_ADD1H(a, b);
}


INLINE(  uint,  UINT_ADD1)   (uint volatile a[1],   uint b)
{
    return  MY_ADD1W(a, b);
}

INLINE(   int,   INT_ADD1)    (int volatile a[1],    int b)
{
    return  MY_ADD1W(a, b);
}


INLINE( ulong, ULONG_ADD1)  (ulong volatile a[1], ulong b)
{
    return  MY_ADD1W(a, b);
}

INLINE(  long,  LONG_ADD1)   (long volatile a[1],   long b)
{
    return  MY_ADD1W(a, b);
}


INLINE(ullong,ULLONG_ADD1) (ullong volatile a[1], ullong b)
{
    return  MY_ADD1D(a, b);
}

INLINE( llong, LLONG_ADD1)  (llong volatile a[1],  llong b)
{
    return  MY_ADD1D(a, b);
}

#if _LEAVE_MSVC_ADD1
}
#endif

#if _ENTER_MSVC_ADDA
{
#endif

INLINE( _Bool,  BOOL_ADDA)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XORAB(a, b);
}


INLINE( uchar, UCHAR_ADDA)  (uchar volatile a[1],  uchar b)
{
    return  MY_ADDAB(a, b);
}

INLINE( schar, SCHAR_ADDA)  (schar volatile a[1],  schar b)
{
    return  MY_ADDAB(a, b);
}

INLINE(  char,  CHAR_ADDA)   (char volatile a[1],   char b)
{
    return  MY_ADDAB(a, b);
}


INLINE(ushort, USHRT_ADDA) (ushort volatile a[1], ushort b)
{
    return  MY_ADDAH(a, b);
}

INLINE( short,  SHRT_ADDA) (short volatile  a[1],  short b)
{
    return  MY_ADDAH(a, b);
}


INLINE(  uint,  UINT_ADDA)   (uint volatile a[1],   uint b)
{
    return  MY_ADDAW(a, b);
}

INLINE(   int,   INT_ADDA)    (int volatile a[1],    int b)
{
    return  MY_ADDAW(a, b);
}


INLINE( ulong, ULONG_ADDA)  (ulong volatile a[1], ulong b)
{
    return  MY_ADDAW(a, b);
}

INLINE(  long,  LONG_ADDA)   (long volatile a[1],   long b)
{
    return  MY_ADDAW(a, b);
}


INLINE(ullong,ULLONG_ADDA) (ullong volatile a[1], ullong b)
{
    return  MY_ADDAD(a, b);
}

INLINE( llong, LLONG_ADDA)  (llong volatile a[1],  llong b)
{
    return  MY_ADDAD(a, b);
}


#if _LEAVE_MSVC_ADDA
}
#endif

#if _ENTER_MSVC_ADDE
{
#endif

INLINE( _Bool,  BOOL_ADDE)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XOREB(a, b);
}


INLINE( uchar, UCHAR_ADDE)  (uchar volatile a[1],  uchar b)
{
    return  MY_ADDEB(a, b);
}

INLINE( schar, SCHAR_ADDE)  (schar volatile a[1],  schar b)
{
    return  MY_ADDEB(a, b);
}

INLINE(  char,  CHAR_ADDE)   (char volatile a[1],   char b)
{
    return  MY_ADDEB(a, b);
}


INLINE(ushort, USHRT_ADDE) (ushort volatile a[1], ushort b)
{
    return  MY_ADDEH(a, b);
}

INLINE( short,  SHRT_ADDE) (short volatile  a[1],  short b)
{
    return  MY_ADDEH(a, b);
}


INLINE(  uint,  UINT_ADDE)   (uint volatile a[1],   uint b)
{
    return  MY_ADDEW(a, b);
}

INLINE(   int,   INT_ADDE)    (int volatile a[1],    int b)
{
    return  MY_ADDEW(a, b);
}


INLINE( ulong, ULONG_ADDE)  (ulong volatile a[1], ulong b)
{
    return  MY_ADDEW(a, b);
}

INLINE(  long,  LONG_ADDE)   (long volatile a[1],   long b)
{
    return  MY_ADDEW(a, b);
}


INLINE(ullong,ULLONG_ADDE) (ullong volatile a[1], ullong b)
{
    return  MY_ADDED(a, b);
}

INLINE( llong, LLONG_ADDE)  (llong volatile a[1],  llong b)
{
    return  MY_ADDED(a, b);
}


#if _LEAVE_MSVC_ADDE
}
#endif

#if _ENTER_MSVC_ADDT
{
#endif

INLINE( _Bool,  BOOL_ADDT)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XORTB(a, b);
}


INLINE( uchar, UCHAR_ADDT)  (uchar volatile a[1],  uchar b)
{
    return  MY_ADDTB(a, b);
}

INLINE( schar, SCHAR_ADDT)  (schar volatile a[1],  schar b)
{
    return  MY_ADDTB(a, b);
}

INLINE(  char,  CHAR_ADDT)   (char volatile a[1],   char b)
{
    return  MY_ADDTB(a, b);
}


INLINE(ushort, USHRT_ADDT) (ushort volatile a[1], ushort b)
{
    return  MY_ADDTH(a, b);
}

INLINE( short,  SHRT_ADDT) (short volatile  a[1],  short b)
{
    return  MY_ADDTH(a, b);
}


INLINE(  uint,  UINT_ADDT)   (uint volatile a[1],   uint b)
{
    return  MY_ADDTW(a, b);
}

INLINE(   int,   INT_ADDT)    (int volatile a[1],    int b)
{
    return  MY_ADDTW(a, b);
}


INLINE( ulong, ULONG_ADDT)  (ulong volatile a[1], ulong b)
{
    return  MY_ADDTW(a, b);
}

INLINE(  long,  LONG_ADDT)   (long volatile a[1],   long b)
{
    return  MY_ADDTW(a, b);
}


INLINE(ullong,ULLONG_ADDT) (ullong volatile a[1], ullong b)
{
    return  MY_ADDTD(a, b);
}

INLINE( llong, LLONG_ADDT)  (llong volatile a[1],  llong b)
{
    return  MY_ADDTD(a, b);
}

#if _LEAVE_MSVC_ADDT
}
#endif


#if _ENTER_MSVC_SUB1
{
#endif

INLINE( _Bool,  BOOL_SUB1)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XOR1B(a, b);
}


INLINE( uchar, UCHAR_SUB1)  (uchar volatile a[1],  uchar b)
{
    return  MY_SUB1B(a, b);
}

INLINE( schar, SCHAR_SUB1)  (schar volatile a[1],  schar b)
{
    return  MY_SUB1B(a, b);
}

INLINE(  char,  CHAR_SUB1)   (char volatile a[1],   char b)
{
    return  MY_SUB1B(a, b);
}


INLINE(ushort, USHRT_SUB1) (ushort volatile a[1], ushort b)
{
    return  MY_SUB1H(a, b);
}

INLINE( short,  SHRT_SUB1) (short volatile  a[1],  short b)
{
    return  MY_SUB1H(a, b);
}


INLINE(  uint,  UINT_SUB1)   (uint volatile a[1],   uint b)
{
    return  MY_SUB1W(a, b);
}

INLINE(   int,   INT_SUB1)    (int volatile a[1],    int b)
{
    return  MY_SUB1W(a, b);
}


INLINE( ulong, ULONG_SUB1)  (ulong volatile a[1], ulong b)
{
    return  MY_SUB1W(a, b);
}

INLINE(  long,  LONG_SUB1)   (long volatile a[1],   long b)
{
    return  MY_SUB1W(a, b);
}


INLINE(ullong,ULLONG_SUB1) (ullong volatile a[1], ullong b)
{
    return  MY_SUB1D(a, b);
}

INLINE( llong, LLONG_SUB1)  (llong volatile a[1],  llong b)
{
    return  MY_SUB1D(a, b);
}


#if _LEAVE_MSVC_SUB1
}
#endif

#if _ENTER_MSVC_SUBA
{
#endif

INLINE( _Bool,  BOOL_SUBA)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XORAB(a, b);
}


INLINE( uchar, UCHAR_SUBA)  (uchar volatile a[1],  uchar b)
{
    return  MY_SUBAB(a, b);
}

INLINE( schar, SCHAR_SUBA)  (schar volatile a[1],  schar b)
{
    return  MY_SUBAB(a, b);
}

INLINE(  char,  CHAR_SUBA)   (char volatile a[1],   char b)
{
    return  MY_SUBAB(a, b);
}


INLINE(ushort, USHRT_SUBA) (ushort volatile a[1], ushort b)
{
    return  MY_SUBAH(a, b);
}

INLINE( short,  SHRT_SUBA) (short volatile  a[1],  short b)
{
    return  MY_SUBAH(a, b);
}


INLINE(  uint,  UINT_SUBA)   (uint volatile a[1],   uint b)
{
    return  MY_SUBAW(a, b);
}

INLINE(   int,   INT_SUBA)    (int volatile a[1],    int b)
{
    return  MY_SUBAW(a, b);
}


INLINE( ulong, ULONG_SUBA)  (ulong volatile a[1], ulong b)
{
    return  MY_SUBAW(a, b);
}

INLINE(  long,  LONG_SUBA)   (long volatile a[1],   long b)
{
    return  MY_SUBAW(a, b);
}


INLINE(ullong,ULLONG_SUBA) (ullong volatile a[1], ullong b)
{
    return  MY_SUBAD(a, b);
}

INLINE( llong, LLONG_SUBA)  (llong volatile a[1],  llong b)
{
    return  MY_SUBAD(a, b);
}


#if _LEAVE_MSVC_SUBA
}
#endif

#if _ENTER_MSVC_SUBE
{
#endif

INLINE( _Bool,  BOOL_SUBE)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XOREB(a, b);
}


INLINE( uchar, UCHAR_SUBE)  (uchar volatile a[1],  uchar b)
{
    return  MY_SUBEB(a, b);
}

INLINE( schar, SCHAR_SUBE)  (schar volatile a[1],  schar b)
{
    return  MY_SUBEB(a, b);
}

INLINE(  char,  CHAR_SUBE)   (char volatile a[1],   char b)
{
    return  MY_SUBEB(a, b);
}


INLINE(ushort, USHRT_SUBE) (ushort volatile a[1], ushort b)
{
    return  MY_SUBEH(a, b);
}

INLINE( short,  SHRT_SUBE) (short volatile  a[1],  short b)
{
    return  MY_SUBEH(a, b);
}


INLINE(  uint,  UINT_SUBE)   (uint volatile a[1],   uint b)
{
    return  MY_SUBEW(a, b);
}

INLINE(   int,   INT_SUBE)    (int volatile a[1],    int b)
{
    return  MY_SUBEW(a, b);
}


INLINE( ulong, ULONG_SUBE)  (ulong volatile a[1], ulong b)
{
    return  MY_SUBEW(a, b);
}

INLINE(  long,  LONG_SUBE)   (long volatile a[1],   long b)
{
    return  MY_SUBEW(a, b);
}


INLINE(ullong,ULLONG_SUBE) (ullong volatile a[1], ullong b)
{
    return  MY_SUBED(a, b);
}

INLINE( llong, LLONG_SUBE)  (llong volatile a[1],  llong b)
{
    return  MY_SUBED(a, b);
}


#if _LEAVE_MSVC_SUBE
}
#endif

#if _ENTER_MSVC_SUBT
{
#endif

INLINE( _Bool,  BOOL_SUBT)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XORTB(a, b);
}


INLINE( uchar, UCHAR_SUBT)  (uchar volatile a[1],  uchar b)
{
    return  MY_SUBTB(a, b);
}

INLINE( schar, SCHAR_SUBT)  (schar volatile a[1],  schar b)
{
    return  MY_SUBTB(a, b);
}

INLINE(  char,  CHAR_SUBT)   (char volatile a[1],   char b)
{
    return  MY_SUBTB(a, b);
}


INLINE(ushort, USHRT_SUBT) (ushort volatile a[1], ushort b)
{
    return  MY_SUBTH(a, b);
}

INLINE( short,  SHRT_SUBT) (short volatile  a[1],  short b)
{
    return  MY_SUBTH(a, b);
}


INLINE(  uint,  UINT_SUBT)   (uint volatile a[1],   uint b)
{
    return  MY_SUBTW(a, b);
}

INLINE(   int,   INT_SUBT)    (int volatile a[1],    int b)
{
    return  MY_SUBTW(a, b);
}


INLINE( ulong, ULONG_SUBT)  (ulong volatile a[1], ulong b)
{
    return  MY_SUBTW(a, b);
}

INLINE(  long,  LONG_SUBT)   (long volatile a[1],   long b)
{
    return  MY_SUBTW(a, b);
}


INLINE(ullong,ULLONG_SUBT) (ullong volatile a[1], ullong b)
{
    return  MY_SUBTD(a, b);
}

INLINE( llong, LLONG_SUBT)  (llong volatile a[1],  llong b)
{
    return  MY_SUBTD(a, b);
}


#if _LEAVE_MSVC_SUBT
}
#endif


#if _ENTER_MSVC_XEQ1
{
#endif

INLINE( _Bool,   BOOL_XEQ1A)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return  MY_XEQ1B(a, b, c);
}


INLINE( uchar,  UCHAR_XEQ1A)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_XEQ1B(a, b, c);
}

INLINE( schar,  SCHAR_XEQ1A)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_XEQ1B(a, b, c);
}

INLINE(  char,   CHAR_XEQ1A)   (char volatile a[1],   char b,   char c)
{
    return  MY_XEQ1B(a, b, c);
}


INLINE(ushort,  USHRT_XEQ1A) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_XEQ1H(a, b, c);
}

INLINE( short,   SHRT_XEQ1A)  (short volatile a[1],  short b,  short c)
{
    return  MY_XEQ1H(a, b, c);
}


INLINE(  uint,   UINT_XEQ1A)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_XEQ1W(a, b, c);
}

INLINE(   int,    INT_XEQ1A)    (int volatile a[1],    int b,    int c)
{
    return  MY_XEQ1W(a, b, c);
}


INLINE( ulong,  ULONG_XEQ1A)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_XEQ1W(a, b, c);
}

INLINE(  long,   LONG_XEQ1A)   (long volatile a[1],   long b,   long c)
{
    return  MY_XEQ1W(a, b, c);
}


INLINE(ullong, ULLONG_XEQ1A) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_XEQ1D(a, b, c);
}

INLINE( llong,  LLONG_XEQ1A)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_XEQ1D(a, b, c);
}

#if _LEAVE_MSVC_XEQ1
}
#endif

#if _ENTER_MSVC_XEQA
{
#endif

INLINE( _Bool,   BOOL_XEQAA)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return  MY_XEQAB(a, b, c);
}


INLINE( uchar,  UCHAR_XEQAA)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_XEQAB(a, b, c);
}

INLINE( schar,  SCHAR_XEQAA)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_XEQAB(a, b, c);
}

INLINE(  char,   CHAR_XEQAA)   (char volatile a[1],   char b,   char c)
{
    return  MY_XEQAB(a, b, c);
}


INLINE(ushort,  USHRT_XEQAA) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_XEQAH(a, b, c);
}

INLINE( short,   SHRT_XEQAA)  (short volatile a[1],  short b,  short c)
{
    return  MY_XEQAH(a, b, c);
}


INLINE(  uint,   UINT_XEQAA)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_XEQAW(a, b, c);
}

INLINE(   int,    INT_XEQAA)    (int volatile a[1],    int b,    int c)
{
    return  MY_XEQAW(a, b, c);
}


INLINE( ulong,  ULONG_XEQAA)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_XEQAW(a, b, c);
}

INLINE(  long,   LONG_XEQAA)   (long volatile a[1],   long b,   long c)
{
    return  MY_XEQAW(a, b, c);
}


INLINE(ullong, ULLONG_XEQAA) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_XEQAD(a, b, c);
}

INLINE( llong,  LLONG_XEQAA)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_XEQAD(a, b, c);
}

#if _LEAVE_MSVC_XEQA
}
#endif

#if _ENTER_MSVC_XEQE
{
#endif

INLINE( _Bool,   BOOL_XEQEA)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return  MY_XEQEB(a, b, c);
}


INLINE( uchar,  UCHAR_XEQEA)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_XEQEB(a, b, c);
}

INLINE( schar,  SCHAR_XEQEA)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_XEQEB(a, b, c);
}

INLINE(  char,   CHAR_XEQEA)   (char volatile a[1],   char b,   char c)
{
    return  MY_XEQEB(a, b, c);
}


INLINE(ushort,  USHRT_XEQEA) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_XEQEH(a, b, c);
}

INLINE( short,   SHRT_XEQEA)  (short volatile a[1],  short b,  short c)
{
    return  MY_XEQEH(a, b, c);
}


INLINE(  uint,   UINT_XEQEA)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_XEQEW(a, b, c);
}

INLINE(   int,    INT_XEQEA)    (int volatile a[1],    int b,    int c)
{
    return  MY_XEQEW(a, b, c);
}


INLINE( ulong,  ULONG_XEQEA)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_XEQEW(a, b, c);
}

INLINE(  long,   LONG_XEQEA)   (long volatile a[1],   long b,   long c)
{
    return  MY_XEQEW(a, b, c);
}


INLINE(ullong, ULLONG_XEQEA) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_XEQED(a, b, c);
}

INLINE( llong,  LLONG_XEQEA)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_XEQED(a, b, c);
}


#if _LEAVE_MSVC_XEQE
}
#endif

#if _ENTER_MSVC_XEQT
{
#endif

INLINE( _Bool,   BOOL_XEQTA)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return  MY_XEQTB(a, b, c);
}


INLINE( uchar,  UCHAR_XEQTA)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_XEQTB(a, b, c);
}

INLINE( schar,  SCHAR_XEQTA)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_XEQTB(a, b, c);
}

INLINE(  char,   CHAR_XEQTA)   (char volatile a[1],   char b,   char c)
{
    return  MY_XEQTB(a, b, c);
}


INLINE(ushort,  USHRT_XEQTA) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_XEQTH(a, b, c);
}

INLINE( short,   SHRT_XEQTA)  (short volatile a[1],  short b,  short c)
{
    return  MY_XEQTH(a, b, c);
}


INLINE(  uint,   UINT_XEQTA)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_XEQTW(a, b, c);
}

INLINE(   int,    INT_XEQTA)    (int volatile a[1],    int b,    int c)
{
    return  MY_XEQTW(a, b, c);
}


INLINE( ulong,  ULONG_XEQTA)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_XEQTW(a, b, c);
}

INLINE(  long,   LONG_XEQTA)   (long volatile a[1],   long b,   long c)
{
    return  MY_XEQTW(a, b, c);
}


INLINE(ullong, ULLONG_XEQTA) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_XEQTD(a, b, c);
}

INLINE( llong,  LLONG_XEQTA)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_XEQTD(a, b, c);
}

#if _LEAVE_MSVC_XEQT
}
#endif


#if _ENTER_MSVC_LDR1
{
#endif

INLINE( _Bool,   BOOL_LDR1AC)  (_Bool volatile const src[1])
{
    return  MY_LDR1B(src);
}


INLINE( uchar,  UCHAR_LDR1AC)  (uchar volatile const src[1])
{
    return  MY_LDR1B(src);
}

INLINE( schar,  SCHAR_LDR1AC)  (schar volatile const src[1])
{
    return  MY_LDR1B(src);
}

INLINE(  char,   CHAR_LDR1AC)   (char volatile const src[1])
{
    return  MY_LDR1B(src);
}


INLINE(ushort,  USHRT_LDR1AC) (ushort volatile const src[1])
{
    return  MY_LDR1H(src);
}

INLINE( short,   SHRT_LDR1AC)  (short volatile const src[1])
{
    return  MY_LDR1H(src);
}


INLINE(  uint,   UINT_LDR1AC)   (uint volatile const src[1])
{
    return  MY_LDR1W(src);
}

INLINE(   int,    INT_LDR1AC)    (int volatile const src[1])
{
    return  MY_LDR1W(src);
}


INLINE( ulong,  ULONG_LDR1AC)  (ulong volatile const src[1])
{
    return  MY_LDR1W(src);
}

INLINE(  long,   LONG_LDR1AC)   (long volatile const src[1])
{
    return  MY_LDR1W(src);
}


INLINE(ullong, ULLONG_LDR1AC) (ullong volatile const src[1])
{
    return  MY_LDR1D(src);
}

INLINE( llong,  LLONG_LDR1AC)  (llong volatile const src[1])
{
    return  MY_LDR1D(src);
}


#if _LEAVE_MSVC_LDR1
}
#endif

#if _ENTER_MSVC_LDRA
{
#endif

INLINE( _Bool,   BOOL_LDRAAC)  (_Bool volatile const src[1])
{
    return  MY_LDRAB(src);
}


INLINE( uchar,  UCHAR_LDRAAC)  (uchar volatile const src[1])
{
    return  MY_LDRAB(src);
}

INLINE( schar,  SCHAR_LDRAAC)  (schar volatile const src[1])
{
    return  MY_LDRAB(src);
}

INLINE(  char,   CHAR_LDRAAC)   (char volatile const src[1])
{
    return  MY_LDRAB(src);
}


INLINE(ushort,  USHRT_LDRAAC) (ushort volatile const src[1])
{
    return  MY_LDRAH(src);
}

INLINE( short,   SHRT_LDRAAC)  (short volatile const src[1])
{
    return  MY_LDRAH(src);
}


INLINE(  uint,   UINT_LDRAAC)   (uint volatile const src[1])
{
    return  MY_LDRAW(src);
}

INLINE(   int,    INT_LDRAAC)    (int volatile const src[1])
{
    return  MY_LDRAW(src);
}


INLINE( ulong,  ULONG_LDRAAC)  (ulong volatile const src[1])
{
    return  MY_LDRAW(src);
}

INLINE(  long,   LONG_LDRAAC)   (long volatile const src[1])
{
    return  MY_LDRAW(src);
}


INLINE(ullong, ULLONG_LDRAAC) (ullong volatile const src[1])
{
    return  MY_LDRAD(src);
}

INLINE( llong,  LLONG_LDRAAC)  (llong volatile const src[1])
{
    return  MY_LDRAD(src);
}


#if _LEAVE_MSVC_LDRA
}
#endif

#if _ENTER_MSVC_LDRT
{
#endif

INLINE( _Bool,   BOOL_LDRTAC)  (_Bool volatile const src[1])
{
    return  MY_LDRTB(src);
}


INLINE( uchar,  UCHAR_LDRTAC)  (uchar volatile const src[1])
{
    return  MY_LDRTB(src);
}

INLINE( schar,  SCHAR_LDRTAC)  (schar volatile const src[1])
{
    return  MY_LDRTB(src);
}

INLINE(  char,   CHAR_LDRTAC)   (char volatile const src[1])
{
    return  MY_LDRTB(src);
}


INLINE(ushort,  USHRT_LDRTAC) (ushort volatile const src[1])
{
    return  MY_LDRTH(src);
}

INLINE( short,   SHRT_LDRTAC)  (short volatile const src[1])
{
    return  MY_LDRTH(src);
}


INLINE(  uint,   UINT_LDRTAC)   (uint volatile const src[1])
{
    return  MY_LDRTW(src);
}

INLINE(   int,    INT_LDRTAC)    (int volatile const src[1])
{
    return  MY_LDRTW(src);
}


INLINE( ulong,  ULONG_LDRTAC)  (ulong volatile const src[1])
{
    return  MY_LDRTW(src);
}

INLINE(  long,   LONG_LDRTAC)   (long volatile const src[1])
{
    return  MY_LDRTW(src);
}


INLINE(ullong, ULLONG_LDRTAC) (ullong volatile const src[1])
{
    return  MY_LDRTD(src);
}

INLINE( llong,  LLONG_LDRTAC)  (llong volatile const src[1])
{
    return  MY_LDRTD(src);
}


#if _LEAVE_MSVC_LDRT
}
#endif


#if _ENTER_MSVC_STR1
{
#endif

INLINE( _Bool,   BOOL_STR1A)  (_Bool volatile dst[1],  _Bool src)
{
    return  MY_STR1B(dst, src);
}


INLINE( uchar,  UCHAR_STR1A)  (uchar volatile dst[1],  uchar src)
{
    return  MY_STR1B(dst, src);
}

INLINE( schar,  SCHAR_STR1A)  (schar volatile dst[1],  schar src)
{
    return  MY_STR1B(dst, src);
}

INLINE(  char,   CHAR_STR1A)   (char volatile dst[1],   char src)
{
    return  MY_STR1B(dst, src);
}


INLINE(ushort,  USHRT_STR1A) (ushort volatile dst[1], ushort src)
{
    return  MY_STR1H(dst, src);
}

INLINE( short,   SHRT_STR1A)  (short volatile dst[1], short src)
{
    return  MY_STR1H(dst, src);
}


INLINE(  uint,   UINT_STR1A)   (uint volatile dst[1],  uint src)
{
    return  MY_STR1W(dst, src);
}

INLINE(   int,    INT_STR1A)    (int volatile dst[1],   int src)
{
    return  MY_STR1W(dst, src);
}


INLINE( ulong,  ULONG_STR1A)  (ulong volatile dst[1],  ulong src)
{
    return  MY_STR1W(dst, src);
}

INLINE(  long,   LONG_STR1A)   (long volatile dst[1],   long src)
{
    return  MY_STR1W(dst, src);
}


INLINE(ullong, ULLONG_STR1A) (ullong volatile dst[1], ullong src)
{
    return  MY_STR1D(dst, src);
}

INLINE( llong,  LLONG_STR1A)  (llong volatile dst[1],  llong src)
{
    return  MY_STR1D(dst, src);
}

#if _LEAVE_MSVC_STR1
}
#endif

#if _ENTER_MSVC_STRE
{
#endif

INLINE( _Bool,   BOOL_STREA)  (_Bool volatile dst[1],  _Bool src)
{
    return  MY_STREB(dst, src);
}


INLINE( uchar,  UCHAR_STREA)  (uchar volatile dst[1],  uchar src)
{
    return  MY_STREB(dst, src);
}

INLINE( schar,  SCHAR_STREA)  (schar volatile dst[1],  schar src)
{
    return  MY_STREB(dst, src);
}

INLINE(  char,   CHAR_STREA)   (char volatile dst[1],   char src)
{
    return  MY_STREB(dst, src);
}


INLINE(ushort,  USHRT_STREA) (ushort volatile dst[1], ushort src)
{
    return  MY_STREH(dst, src);
}

INLINE( short,   SHRT_STREA)  (short volatile dst[1], short src)
{
    return  MY_STREH(dst, src);
}


INLINE(  uint,   UINT_STREA)   (uint volatile dst[1],  uint src)
{
    return  MY_STREW(dst, src);
}

INLINE(   int,    INT_STREA)    (int volatile dst[1],   int src)
{
    return  MY_STREW(dst, src);
}


INLINE( ulong,  ULONG_STREA)  (ulong volatile dst[1],  ulong src)
{
    return  MY_STREW(dst, src);
}

INLINE(  long,   LONG_STREA)   (long volatile dst[1],   long src)
{
    return  MY_STREW(dst, src);
}


INLINE(ullong, ULLONG_STREA) (ullong volatile dst[1], ullong src)
{
    return  MY_STRED(dst, src);
}

INLINE( llong,  LLONG_STREA)  (llong volatile dst[1],  llong src)
{
    return  MY_STRED(dst, src);
}

#if _LEAVE_MSVC_STRE
}
#endif

#if _ENTER_MSVC_STRT
{
#endif

INLINE( _Bool,   BOOL_STRTA)  (_Bool volatile dst[1],  _Bool src)
{
    return  MY_STRTB(dst, src);
}


INLINE( uchar,  UCHAR_STRTA)  (uchar volatile dst[1],  uchar src)
{
    return  MY_STRTB(dst, src);
}

INLINE( schar,  SCHAR_STRTA)  (schar volatile dst[1],  schar src)
{
    return  MY_STRTB(dst, src);
}

INLINE(  char,   CHAR_STRTA)   (char volatile dst[1],   char src)
{
    return  MY_STRTB(dst, src);
}


INLINE(ushort,  USHRT_STRTA) (ushort volatile dst[1], ushort src)
{
    return  MY_STRTH(dst, src);
}

INLINE( short,   SHRT_STRTA)  (short volatile dst[1], short src)
{
    return  MY_STRTH(dst, src);
}


INLINE(  uint,   UINT_STRTA)   (uint volatile dst[1],  uint src)
{
    return  MY_STRTW(dst, src);
}

INLINE(   int,    INT_STRTA)    (int volatile dst[1],   int src)
{
    return  MY_STRTW(dst, src);
}


INLINE( ulong,  ULONG_STRTA)  (ulong volatile dst[1],  ulong src)
{
    return  MY_STRTW(dst, src);
}

INLINE(  long,   LONG_STRTA)   (long volatile dst[1],   long src)
{
    return  MY_STRTW(dst, src);
}


INLINE(ullong, ULLONG_STRTA) (ullong volatile dst[1], ullong src)
{
    return  MY_STRTD(dst, src);
}

INLINE( llong,  LLONG_STRTA)  (llong volatile dst[1],  llong src)
{
    return  MY_STRTD(dst, src);
}

#if _LEAVE_MSVC_STRT
}
#endif


#if _ENTER_MSVC_AND1
{
#endif

INLINE( _Bool,  BOOL_AND1)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_AND1B(a, b);
}

INLINE( uchar, UCHAR_AND1)  (uchar volatile a[1],  uchar b)
{
    return  MY_AND1B(a, b);
}

INLINE( schar, SCHAR_AND1)  (schar volatile a[1],  schar b)
{
    return  MY_AND1B(a, b);
}

INLINE(  char,  CHAR_AND1)   (char volatile a[1],   char b)
{
    return  MY_AND1B(a, b);
}


INLINE(ushort, USHRT_AND1) (ushort volatile a[1], ushort b)
{
    return  MY_AND1H(a, b);
}

INLINE( short,  SHRT_AND1) (short volatile  a[1],  short b)
{
    return  MY_AND1H(a, b);
}


INLINE(  uint,  UINT_AND1)   (uint volatile a[1],   uint b)
{
    return  MY_AND1W(a, b);
}

INLINE(   int,   INT_AND1)    (int volatile a[1],    int b)
{
    return  MY_AND1W(a, b);
}


INLINE( ulong, ULONG_AND1)  (ulong volatile a[1], ulong b)
{
    return  MY_AND1W(a, b);
}

INLINE(  long,  LONG_AND1)   (long volatile a[1],   long b)
{
    return  MY_AND1W(a, b);
}


INLINE(ullong,ULLONG_AND1) (ullong volatile a[1], ullong b)
{
    return  MY_AND1D(a, b);
}

INLINE( llong, LLONG_AND1)  (llong volatile a[1],  llong b)
{
    return  MY_AND1D(a, b);
}

#if _LEAVE_MSVC_AND1
}
#endif

#if _ENTER_MSVC_ANDA
{
#endif

INLINE( _Bool,  BOOL_ANDA)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ANDAB(a, b);
}

INLINE( uchar, UCHAR_ANDA)  (uchar volatile a[1],  uchar b)
{
    return  MY_ANDAB(a, b);
}

INLINE( schar, SCHAR_ANDA)  (schar volatile a[1],  schar b)
{
    return  MY_ANDAB(a, b);
}

INLINE(  char,  CHAR_ANDA)   (char volatile a[1],   char b)
{
    return  MY_ANDAB(a, b);
}


INLINE(ushort, USHRT_ANDA) (ushort volatile a[1], ushort b)
{
    return  MY_ANDAH(a, b);
}

INLINE( short,  SHRT_ANDA) (short volatile  a[1],  short b)
{
    return  MY_ANDAH(a, b);
}


INLINE(  uint,  UINT_ANDA)   (uint volatile a[1],   uint b)
{
    return  MY_ANDAW(a, b);
}

INLINE(   int,   INT_ANDA)    (int volatile a[1],    int b)
{
    return  MY_ANDAW(a, b);
}


INLINE( ulong, ULONG_ANDA)  (ulong volatile a[1], ulong b)
{
    return  MY_ANDAW(a, b);
}

INLINE(  long,  LONG_ANDA)   (long volatile a[1],   long b)
{
    return  MY_ANDAW(a, b);
}


INLINE(ullong,ULLONG_ANDA) (ullong volatile a[1], ullong b)
{
    return  MY_ANDAD(a, b);
}

INLINE( llong, LLONG_ANDA)  (llong volatile a[1],  llong b)
{
    return  MY_ANDAD(a, b);
}


#if _LEAVE_MSVC_ANDA
}
#endif

#if _ENTER_MSVC_ANDE
{
#endif

INLINE( _Bool,  BOOL_ANDE)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ANDEB(a, b);
}


INLINE( uchar, UCHAR_ANDE)  (uchar volatile a[1],  uchar b)
{
    return  MY_ANDEB(a, b);
}

INLINE( schar, SCHAR_ANDE)  (schar volatile a[1],  schar b)
{
    return  MY_ANDEB(a, b);
}

INLINE(  char,  CHAR_ANDE)   (char volatile a[1],   char b)
{
    return  MY_ANDEB(a, b);
}


INLINE(ushort, USHRT_ANDE) (ushort volatile a[1], ushort b)
{
    return  MY_ANDEH(a, b);
}

INLINE( short,  SHRT_ANDE) (short volatile  a[1],  short b)
{
    return  MY_ANDEH(a, b);
}


INLINE(  uint,  UINT_ANDE)   (uint volatile a[1],   uint b)
{
    return  MY_ANDEW(a, b);
}

INLINE(   int,   INT_ANDE)    (int volatile a[1],    int b)
{
    return  MY_ANDEW(a, b);
}


INLINE( ulong, ULONG_ANDE)  (ulong volatile a[1], ulong b)
{
    return  MY_ANDEW(a, b);
}

INLINE(  long,  LONG_ANDE)   (long volatile a[1],   long b)
{
    return  MY_ANDEW(a, b);
}


INLINE(ullong,ULLONG_ANDE) (ullong volatile a[1], ullong b)
{
    return  MY_ANDED(a, b);
}

INLINE( llong, LLONG_ANDE)  (llong volatile a[1],  llong b)
{
    return  MY_ANDED(a, b);
}

#if _LEAVE_MSVC_ANDE
}
#endif

#if _ENTER_MSVC_ANDT
{
#endif

INLINE( _Bool,  BOOL_ANDT)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ANDTB(a, b);
}


INLINE( uchar, UCHAR_ANDT)  (uchar volatile a[1],  uchar b)
{
    return  MY_ANDTB(a, b);
}

INLINE( schar, SCHAR_ANDT)  (schar volatile a[1],  schar b)
{
    return  MY_ANDTB(a, b);
}

INLINE(  char,  CHAR_ANDT)   (char volatile a[1],   char b)
{
    return  MY_ANDTB(a, b);
}


INLINE(ushort, USHRT_ANDT) (ushort volatile a[1], ushort b)
{
    return  MY_ANDTH(a, b);
}

INLINE( short,  SHRT_ANDT) (short volatile  a[1],  short b)
{
    return  MY_ANDTH(a, b);
}


INLINE(  uint,  UINT_ANDT)   (uint volatile a[1],   uint b)
{
    return  MY_ANDTW(a, b);
}

INLINE(   int,   INT_ANDT)    (int volatile a[1],    int b)
{
    return  MY_ANDTW(a, b);
}


INLINE( ulong, ULONG_ANDT)  (ulong volatile a[1], ulong b)
{
    return  MY_ANDTW(a, b);
}

INLINE(  long,  LONG_ANDT)   (long volatile a[1],   long b)
{
    return  MY_ANDTW(a, b);
}


INLINE(ullong,ULLONG_ANDT) (ullong volatile a[1], ullong b)
{
    return  MY_ANDTD(a, b);
}

INLINE( llong, LLONG_ANDT)  (llong volatile a[1],  llong b)
{
    return  MY_ANDTD(a, b);
}

#if _LEAVE_MSVC_ANDT
}
#endif


#if _ENTER_MSVC_ORR1
{
#endif

INLINE( _Bool,  BOOL_ORR1)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ORR1B(a, b);
}

INLINE( uchar, UCHAR_ORR1)  (uchar volatile a[1],  uchar b)
{
    return  MY_ORR1B(a, b);
}

INLINE( schar, SCHAR_ORR1)  (schar volatile a[1],  schar b)
{
    return  MY_ORR1B(a, b);
}

INLINE(  char,  CHAR_ORR1)   (char volatile a[1],   char b)
{
    return  MY_ORR1B(a, b);
}


INLINE(ushort, USHRT_ORR1) (ushort volatile a[1], ushort b)
{
    return  MY_ORR1H(a, b);
}

INLINE( short,  SHRT_ORR1) (short volatile  a[1],  short b)
{
    return  MY_ORR1H(a, b);
}


INLINE(  uint,  UINT_ORR1)   (uint volatile a[1],   uint b)
{
    return  MY_ORR1W(a, b);
}

INLINE(   int,   INT_ORR1)    (int volatile a[1],    int b)
{
    return  MY_ORR1W(a, b);
}


INLINE( ulong, ULONG_ORR1)  (ulong volatile a[1], ulong b)
{
    return  MY_ORR1W(a, b);
}

INLINE(  long,  LONG_ORR1)   (long volatile a[1],   long b)
{
    return  MY_ORR1W(a, b);
}


INLINE(ullong,ULLONG_ORR1) (ullong volatile a[1], ullong b)
{
    return  MY_ORR1D(a, b);
}

INLINE( llong, LLONG_ORR1)  (llong volatile a[1],  llong b)
{
    return  MY_ORR1D(a, b);
}

#if _LEAVE_MSVC_ORR1
}
#endif

#if _ENTER_MSVC_ORRA
{
#endif

INLINE( _Bool,  BOOL_ORRA)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ORRAB(a, b);
}

INLINE( uchar, UCHAR_ORRA)  (uchar volatile a[1],  uchar b)
{
    return  MY_ORRAB(a, b);
}

INLINE( schar, SCHAR_ORRA)  (schar volatile a[1],  schar b)
{
    return  MY_ORRAB(a, b);
}

INLINE(  char,  CHAR_ORRA)   (char volatile a[1],   char b)
{
    return  MY_ORRAB(a, b);
}


INLINE(ushort, USHRT_ORRA) (ushort volatile a[1], ushort b)
{
    return  MY_ORRAH(a, b);
}

INLINE( short,  SHRT_ORRA) (short volatile  a[1],  short b)
{
    return  MY_ORRAH(a, b);
}


INLINE(  uint,  UINT_ORRA)   (uint volatile a[1],   uint b)
{
    return  MY_ORRAW(a, b);
}

INLINE(   int,   INT_ORRA)    (int volatile a[1],    int b)
{
    return  MY_ORRAW(a, b);
}


INLINE( ulong, ULONG_ORRA)  (ulong volatile a[1], ulong b)
{
    return  MY_ORRAW(a, b);
}

INLINE(  long,  LONG_ORRA)   (long volatile a[1],   long b)
{
    return  MY_ORRAW(a, b);
}


INLINE(ullong,ULLONG_ORRA) (ullong volatile a[1], ullong b)
{
    return  MY_ORRAD(a, b);
}

INLINE( llong, LLONG_ORRA)  (llong volatile a[1],  llong b)
{
    return  MY_ORRAD(a, b);
}


#if _LEAVE_MSVC_ORRA
}
#endif

#if _ENTER_MSVC_ORRE
{
#endif

INLINE( _Bool,  BOOL_ORRE)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ORREB(a, b);
}


INLINE( uchar, UCHAR_ORRE)  (uchar volatile a[1],  uchar b)
{
    return  MY_ORREB(a, b);
}

INLINE( schar, SCHAR_ORRE)  (schar volatile a[1],  schar b)
{
    return  MY_ORREB(a, b);
}

INLINE(  char,  CHAR_ORRE)   (char volatile a[1],   char b)
{
    return  MY_ORREB(a, b);
}


INLINE(ushort, USHRT_ORRE) (ushort volatile a[1], ushort b)
{
    return  MY_ORREH(a, b);
}

INLINE( short,  SHRT_ORRE) (short volatile  a[1],  short b)
{
    return  MY_ORREH(a, b);
}


INLINE(  uint,  UINT_ORRE)   (uint volatile a[1],   uint b)
{
    return  MY_ORREW(a, b);
}

INLINE(   int,   INT_ORRE)    (int volatile a[1],    int b)
{
    return  MY_ORREW(a, b);
}


INLINE( ulong, ULONG_ORRE)  (ulong volatile a[1], ulong b)
{
    return  MY_ORREW(a, b);
}

INLINE(  long,  LONG_ORRE)   (long volatile a[1],   long b)
{
    return  MY_ORREW(a, b);
}


INLINE(ullong,ULLONG_ORRE) (ullong volatile a[1], ullong b)
{
    return  MY_ORRED(a, b);
}

INLINE( llong, LLONG_ORRE)  (llong volatile a[1],  llong b)
{
    return  MY_ORRED(a, b);
}

#if _LEAVE_MSVC_ORRE
}
#endif

#if _ENTER_MSVC_ORRT
{
#endif

INLINE( _Bool,  BOOL_ORRT)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_ORRTB(a, b);
}


INLINE( uchar, UCHAR_ORRT)  (uchar volatile a[1],  uchar b)
{
    return  MY_ORRTB(a, b);
}

INLINE( schar, SCHAR_ORRT)  (schar volatile a[1],  schar b)
{
    return  MY_ORRTB(a, b);
}

INLINE(  char,  CHAR_ORRT)   (char volatile a[1],   char b)
{
    return  MY_ORRTB(a, b);
}


INLINE(ushort, USHRT_ORRT) (ushort volatile a[1], ushort b)
{
    return  MY_ORRTH(a, b);
}

INLINE( short,  SHRT_ORRT) (short volatile  a[1],  short b)
{
    return  MY_ORRTH(a, b);
}


INLINE(  uint,  UINT_ORRT)   (uint volatile a[1],   uint b)
{
    return  MY_ORRTW(a, b);
}

INLINE(   int,   INT_ORRT)    (int volatile a[1],    int b)
{
    return  MY_ORRTW(a, b);
}


INLINE( ulong, ULONG_ORRT)  (ulong volatile a[1], ulong b)
{
    return  MY_ORRTW(a, b);
}

INLINE(  long,  LONG_ORRT)   (long volatile a[1],   long b)
{
    return  MY_ORRTW(a, b);
}


INLINE(ullong,ULLONG_ORRT) (ullong volatile a[1], ullong b)
{
    return  MY_ORRTD(a, b);
}

INLINE( llong, LLONG_ORRT)  (llong volatile a[1],  llong b)
{
    return  MY_ORRTD(a, b);
}

#if _LEAVE_MSVC_ORRT
}
#endif


#if _ENTER_MSVC_XOR1
{
#endif

INLINE( _Bool,  BOOL_XOR1)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XOR1B(a, b);
}

INLINE( uchar, UCHAR_XOR1)  (uchar volatile a[1],  uchar b)
{
    return  MY_XOR1B(a, b);
}

INLINE( schar, SCHAR_XOR1)  (schar volatile a[1],  schar b)
{
    return  MY_XOR1B(a, b);
}

INLINE(  char,  CHAR_XOR1)   (char volatile a[1],   char b)
{
    return  MY_XOR1B(a, b);
}


INLINE(ushort, USHRT_XOR1) (ushort volatile a[1], ushort b)
{
    return  MY_XOR1H(a, b);
}

INLINE( short,  SHRT_XOR1) (short volatile  a[1],  short b)
{
    return  MY_XOR1H(a, b);
}


INLINE(  uint,  UINT_XOR1)   (uint volatile a[1],   uint b)
{
    return  MY_XOR1W(a, b);
}

INLINE(   int,   INT_XOR1)    (int volatile a[1],    int b)
{
    return  MY_XOR1W(a, b);
}


INLINE( ulong, ULONG_XOR1)  (ulong volatile a[1], ulong b)
{
    return  MY_XOR1W(a, b);
}

INLINE(  long,  LONG_XOR1)   (long volatile a[1],   long b)
{
    return  MY_XOR1W(a, b);
}


INLINE(ullong,ULLONG_XOR1) (ullong volatile a[1], ullong b)
{
    return  MY_XOR1D(a, b);
}

INLINE( llong, LLONG_XOR1)  (llong volatile a[1],  llong b)
{
    return  MY_XOR1D(a, b);
}

#if _LEAVE_MSVC_XOR1
}
#endif

#if _ENTER_MSVC_XORA
{
#endif

INLINE( _Bool,  BOOL_XORA)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XORAB(a, b);
}

INLINE( uchar, UCHAR_XORA)  (uchar volatile a[1],  uchar b)
{
    return  MY_XORAB(a, b);
}

INLINE( schar, SCHAR_XORA)  (schar volatile a[1],  schar b)
{
    return  MY_XORAB(a, b);
}

INLINE(  char,  CHAR_XORA)   (char volatile a[1],   char b)
{
    return  MY_XORAB(a, b);
}


INLINE(ushort, USHRT_XORA) (ushort volatile a[1], ushort b)
{
    return  MY_XORAH(a, b);
}

INLINE( short,  SHRT_XORA) (short volatile  a[1],  short b)
{
    return  MY_XORAH(a, b);
}


INLINE(  uint,  UINT_XORA)   (uint volatile a[1],   uint b)
{
    return  MY_XORAW(a, b);
}

INLINE(   int,   INT_XORA)    (int volatile a[1],    int b)
{
    return  MY_XORAW(a, b);
}


INLINE( ulong, ULONG_XORA)  (ulong volatile a[1], ulong b)
{
    return  MY_XORAW(a, b);
}

INLINE(  long,  LONG_XORA)   (long volatile a[1],   long b)
{
    return  MY_XORAW(a, b);
}


INLINE(ullong,ULLONG_XORA) (ullong volatile a[1], ullong b)
{
    return  MY_XORAD(a, b);
}

INLINE( llong, LLONG_XORA)  (llong volatile a[1],  llong b)
{
    return  MY_XORAD(a, b);
}


#if _LEAVE_MSVC_XORA
}
#endif

#if _ENTER_MSVC_XORE
{
#endif

INLINE( _Bool,  BOOL_XORE)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XOREB(a, b);
}


INLINE( uchar, UCHAR_XORE)  (uchar volatile a[1],  uchar b)
{
    return  MY_XOREB(a, b);
}

INLINE( schar, SCHAR_XORE)  (schar volatile a[1],  schar b)
{
    return  MY_XOREB(a, b);
}

INLINE(  char,  CHAR_XORE)   (char volatile a[1],   char b)
{
    return  MY_XOREB(a, b);
}


INLINE(ushort, USHRT_XORE) (ushort volatile a[1], ushort b)
{
    return  MY_XOREH(a, b);
}

INLINE( short,  SHRT_XORE) (short volatile  a[1],  short b)
{
    return  MY_XOREH(a, b);
}


INLINE(  uint,  UINT_XORE)   (uint volatile a[1],   uint b)
{
    return  MY_XOREW(a, b);
}

INLINE(   int,   INT_XORE)    (int volatile a[1],    int b)
{
    return  MY_XOREW(a, b);
}


INLINE( ulong, ULONG_XORE)  (ulong volatile a[1], ulong b)
{
    return  MY_XOREW(a, b);
}

INLINE(  long,  LONG_XORE)   (long volatile a[1],   long b)
{
    return  MY_XOREW(a, b);
}


INLINE(ullong,ULLONG_XORE) (ullong volatile a[1], ullong b)
{
    return  MY_XORED(a, b);
}

INLINE( llong, LLONG_XORE)  (llong volatile a[1],  llong b)
{
    return  MY_XORED(a, b);
}

#if _LEAVE_MSVC_XORE
}
#endif

#if _ENTER_MSVC_XORT
{
#endif

INLINE( _Bool,  BOOL_XORT)  (_Bool volatile a[1],  _Bool b)
{
    return  MY_XORTB(a, b);
}


INLINE( uchar, UCHAR_XORT)  (uchar volatile a[1],  uchar b)
{
    return  MY_XORTB(a, b);
}

INLINE( schar, SCHAR_XORT)  (schar volatile a[1],  schar b)
{
    return  MY_XORTB(a, b);
}

INLINE(  char,  CHAR_XORT)   (char volatile a[1],   char b)
{
    return  MY_XORTB(a, b);
}


INLINE(ushort, USHRT_XORT) (ushort volatile a[1], ushort b)
{
    return  MY_XORTH(a, b);
}

INLINE( short,  SHRT_XORT) (short volatile  a[1],  short b)
{
    return  MY_XORTH(a, b);
}


INLINE(  uint,  UINT_XORT)   (uint volatile a[1],   uint b)
{
    return  MY_XORTW(a, b);
}

INLINE(   int,   INT_XORT)    (int volatile a[1],    int b)
{
    return  MY_XORTW(a, b);
}


INLINE( ulong, ULONG_XORT)  (ulong volatile a[1], ulong b)
{
    return  MY_XORTW(a, b);
}

INLINE(  long,  LONG_XORT)   (long volatile a[1],   long b)
{
    return  MY_XORTW(a, b);
}


INLINE(ullong,ULLONG_XORT) (ullong volatile a[1], ullong b)
{
    return  MY_XORTD(a, b);
}

INLINE( llong, LLONG_XORT)  (llong volatile a[1],  llong b)
{
    return  MY_XORTD(a, b);
}

#if _LEAVE_MSVC_XORT
}
#endif


#if _ENTER_MSVC_ICR1
{
#endif

INLINE( _Bool,  BOOL_ICR1)  (_Bool volatile a[1])
{
    return  MY_XOR1B(a, 1);
}


INLINE( uchar, UCHAR_ICR1)  (uchar volatile a[1])
{
    return  MY_ICR1B(a);
}

INLINE( schar, SCHAR_ICR1)  (schar volatile a[1])
{
    return  MY_ICR1B(a);
}

INLINE(  char,  CHAR_ICR1)   (char volatile a[1])
{
    return  MY_ICR1B(a);
}


INLINE(ushort, USHRT_ICR1) (ushort volatile a[1])
{
    return  MY_ICR1H(a);
}

INLINE( short,  SHRT_ICR1) (short volatile  a[1])
{
    return  MY_ICR1H(a);
}


INLINE(  uint,  UINT_ICR1)   (uint volatile a[1])
{
    return  MY_ICR1W(a);
}

INLINE(   int,   INT_ICR1)    (int volatile a[1])
{
    return  MY_ICR1W(a);
}


INLINE( ulong, ULONG_ICR1)  (ulong volatile a[1])
{
    return  MY_ICR1W(a);
}

INLINE(  long,  LONG_ICR1)   (long volatile a[1])
{
    return  MY_ICR1W(a);
}


INLINE(ullong,ULLONG_ICR1) (ullong volatile a[1])
{
    return  MY_ICR1D(a);
}

INLINE( llong, LLONG_ICR1)  (llong volatile a[1])
{
    return  MY_ICR1D(a);
}

#if _LEAVE_MSVC_ICR1
}
#endif

#if _ENTER_MSVC_ICRA
{
#endif

INLINE( _Bool,  BOOL_ICRA)  (_Bool volatile a[1])
{
    return  MY_XORAB(a, 1);
}


INLINE( uchar, UCHAR_ICRA)  (uchar volatile a[1])
{
    return  MY_ICRAB(a);
}

INLINE( schar, SCHAR_ICRA)  (schar volatile a[1])
{
    return  MY_ICRAB(a);
}

INLINE(  char,  CHAR_ICRA)   (char volatile a[1])
{
    return  MY_ICRAB(a);
}


INLINE(ushort, USHRT_ICRA) (ushort volatile a[1])
{
    return  MY_ICRAH(a);
}

INLINE( short,  SHRT_ICRA) (short volatile  a[1])
{
    return  MY_ICRAH(a);
}


INLINE(  uint,  UINT_ICRA)   (uint volatile a[1])
{
    return  MY_ICRAW(a);
}

INLINE(   int,   INT_ICRA)    (int volatile a[1])
{
    return  MY_ICRAW(a);
}


INLINE( ulong, ULONG_ICRA)  (ulong volatile a[1])
{
    return  MY_ICRAW(a);
}

INLINE(  long,  LONG_ICRA)   (long volatile a[1])
{
    return  MY_ICRAW(a);
}

INLINE(ullong,ULLONG_ICRA) (ullong volatile a[1])
{
    return  MY_ICRAD(a);
}

INLINE( llong, LLONG_ICRA)  (llong volatile a[1])
{
    return  MY_ICRAD(a);
}

#if _LEAVE_MSVC_ICRA
}
#endif

#if _ENTER_MSVC_ICRE
{
#endif

INLINE( _Bool,  BOOL_ICRE)  (_Bool volatile a[1])
{
    return  MY_XOREB(a, 1);
}


INLINE( uchar, UCHAR_ICRE)  (uchar volatile a[1])
{
    return  MY_ICREB(a);
}

INLINE( schar, SCHAR_ICRE)  (schar volatile a[1])
{
    return  MY_ICREB(a);
}

INLINE(  char,  CHAR_ICRE)   (char volatile a[1])
{
    return  MY_ICREB(a);
}


INLINE(ushort, USHRT_ICRE) (ushort volatile a[1])
{
    return  MY_ICREH(a);
}

INLINE( short,  SHRT_ICRE) (short volatile  a[1])
{
    return  MY_ICREH(a);
}


INLINE(  uint,  UINT_ICRE)   (uint volatile a[1])
{
    return  MY_ICREW(a);
}

INLINE(   int,   INT_ICRE)    (int volatile a[1])
{
    return  MY_ICREW(a);
}


INLINE( ulong, ULONG_ICRE)  (ulong volatile a[1])
{
    return  MY_ICREW(a);
}

INLINE(  long,  LONG_ICRE)   (long volatile a[1])
{
    return  MY_ICREW(a);
}

INLINE(ullong,ULLONG_ICRE) (ullong volatile a[1])
{
    return  MY_ICRED(a);
}

INLINE( llong, LLONG_ICRE)  (llong volatile a[1])
{
    return  MY_ICRED(a);
}


#if _LEAVE_MSVC_ICRE
}
#endif

#if _ENTER_MSVC_ICRT
{
#endif

INLINE( _Bool,  BOOL_ICRT)  (_Bool volatile a[1])
{
    return  MY_XORTB(a, 1);
}


INLINE( uchar, UCHAR_ICRT)  (uchar volatile a[1])
{
    return  MY_ICRTB(a);
}

INLINE( schar, SCHAR_ICRT)  (schar volatile a[1])
{
    return  MY_ICRTB(a);
}

INLINE(  char,  CHAR_ICRT)   (char volatile a[1])
{
    return  MY_ICRTB(a);
}


INLINE(ushort, USHRT_ICRT) (ushort volatile a[1])
{
    return  MY_ICRTH(a);
}

INLINE( short,  SHRT_ICRT) (short volatile  a[1])
{
    return  MY_ICRTH(a);
}


INLINE(  uint,  UINT_ICRT)   (uint volatile a[1])
{
    return  MY_ICRTW(a);
}

INLINE(   int,   INT_ICRT)    (int volatile a[1])
{
    return  MY_ICRTW(a);
}


INLINE( ulong, ULONG_ICRT)  (ulong volatile a[1])
{
    return  MY_ICRTW(a);
}

INLINE(  long,  LONG_ICRT)   (long volatile a[1])
{
    return  MY_ICRTW(a);
}

INLINE(ullong,ULLONG_ICRT) (ullong volatile a[1])
{
    return  MY_ICRTD(a);
}

INLINE( llong, LLONG_ICRT)  (llong volatile a[1])
{
    return  MY_ICRTD(a);
}


#if _LEAVE_MSVC_ICRT
}
#endif


#if _ENTER_MSVC_DCR1
{
#endif

INLINE( _Bool,  BOOL_DCR1)  (_Bool volatile a[1])
{
    return  MY_XOR1B(a, 1);
}


INLINE( uchar, UCHAR_DCR1)  (uchar volatile a[1])
{
    return  MY_DCR1B(a);
}

INLINE( schar, SCHAR_DCR1)  (schar volatile a[1])
{
    return  MY_DCR1B(a);
}

INLINE(  char,  CHAR_DCR1)   (char volatile a[1])
{
    return  MY_DCR1B(a);
}


INLINE(ushort, USHRT_DCR1) (ushort volatile a[1])
{
    return  MY_DCR1H(a);
}

INLINE( short,  SHRT_DCR1) (short volatile  a[1])
{
    return  MY_DCR1H(a);
}


INLINE(  uint,  UINT_DCR1)   (uint volatile a[1])
{
    return  MY_DCR1W(a);
}

INLINE(   int,   INT_DCR1)    (int volatile a[1])
{
    return  MY_DCR1W(a);
}


INLINE( ulong, ULONG_DCR1)  (ulong volatile a[1])
{
    return  MY_DCR1W(a);
}

INLINE(  long,  LONG_DCR1)   (long volatile a[1])
{
    return  MY_DCR1W(a);
}


INLINE(ullong,ULLONG_DCR1) (ullong volatile a[1])
{
    return  MY_DCR1D(a);
}

INLINE( llong, LLONG_DCR1)  (llong volatile a[1])
{
    return  MY_DCR1D(a);
}

#if _LEAVE_MSVC_DCR1
}
#endif

#if _ENTER_MSVC_DCRA
{
#endif

INLINE( _Bool,  BOOL_DCRA)  (_Bool volatile a[1])
{
    return  MY_XORAB(a, 1);
}


INLINE( uchar, UCHAR_DCRA)  (uchar volatile a[1])
{
    return  MY_DCRAB(a);
}

INLINE( schar, SCHAR_DCRA)  (schar volatile a[1])
{
    return  MY_DCRAB(a);
}

INLINE(  char,  CHAR_DCRA)   (char volatile a[1])
{
    return  MY_DCRAB(a);
}


INLINE(ushort, USHRT_DCRA) (ushort volatile a[1])
{
    return  MY_DCRAH(a);
}

INLINE( short,  SHRT_DCRA) (short volatile  a[1])
{
    return  MY_DCRAH(a);
}


INLINE(  uint,  UINT_DCRA)   (uint volatile a[1])
{
    return  MY_DCRAW(a);
}

INLINE(   int,   INT_DCRA)    (int volatile a[1])
{
    return  MY_DCRAW(a);
}


INLINE( ulong, ULONG_DCRA)  (ulong volatile a[1])
{
    return  MY_DCRAW(a);
}

INLINE(  long,  LONG_DCRA)   (long volatile a[1])
{
    return  MY_DCRAW(a);
}

INLINE(ullong,ULLONG_DCRA) (ullong volatile a[1])
{
    return  MY_DCRAD(a);
}

INLINE( llong, LLONG_DCRA)  (llong volatile a[1])
{
    return  MY_DCRAD(a);
}

#if _LEAVE_MSVC_DCRA
}
#endif

#if _ENTER_MSVC_DCRE
{
#endif

INLINE( _Bool,  BOOL_DCRE)  (_Bool volatile a[1])
{
    return  MY_XOREB(a, 1);
}


INLINE( uchar, UCHAR_DCRE)  (uchar volatile a[1])
{
    return  MY_DCREB(a);
}

INLINE( schar, SCHAR_DCRE)  (schar volatile a[1])
{
    return  MY_DCREB(a);
}

INLINE(  char,  CHAR_DCRE)   (char volatile a[1])
{
    return  MY_DCREB(a);
}


INLINE(ushort, USHRT_DCRE) (ushort volatile a[1])
{
    return  MY_DCREH(a);
}

INLINE( short,  SHRT_DCRE) (short volatile  a[1])
{
    return  MY_DCREH(a);
}


INLINE(  uint,  UINT_DCRE)   (uint volatile a[1])
{
    return  MY_DCREW(a);
}

INLINE(   int,   INT_DCRE)    (int volatile a[1])
{
    return  MY_DCREW(a);
}


INLINE( ulong, ULONG_DCRE)  (ulong volatile a[1])
{
    return  MY_DCREW(a);
}

INLINE(  long,  LONG_DCRE)   (long volatile a[1])
{
    return  MY_DCREW(a);
}


INLINE(ullong,ULLONG_DCRE) (ullong volatile a[1])
{
    return  MY_DCRED(a);
}

INLINE( llong, LLONG_DCRE)  (llong volatile a[1])
{
    return  MY_DCRED(a);
}


#if _LEAVE_MSVC_DCRE
}
#endif

#if _ENTER_MSVC_DCRT
{
#endif

INLINE( _Bool,  BOOL_DCRT)  (_Bool volatile a[1])
{
    return  MY_XORTB(a, 1);
}


INLINE( uchar, UCHAR_DCRT)  (uchar volatile a[1])
{
    return  MY_DCRTB(a);
}

INLINE( schar, SCHAR_DCRT)  (schar volatile a[1])
{
    return  MY_DCRTB(a);
}

INLINE(  char,  CHAR_DCRT)   (char volatile a[1])
{
    return  MY_DCRTB(a);
}


INLINE(ushort, USHRT_DCRT) (ushort volatile a[1])
{
    return  MY_DCRTH(a);
}

INLINE( short,  SHRT_DCRT) (short volatile  a[1])
{
    return  MY_DCRTH(a);
}


INLINE(  uint,  UINT_DCRT)   (uint volatile a[1])
{
    return  MY_DCRTW(a);
}

INLINE(   int,   INT_DCRT)    (int volatile a[1])
{
    return  MY_DCRTW(a);
}


INLINE( ulong, ULONG_DCRT)  (ulong volatile a[1])
{
    return  MY_DCRTW(a);
}

INLINE(  long,  LONG_DCRT)   (long volatile a[1])
{
    return  MY_DCRTW(a);
}

INLINE(ullong,ULLONG_DCRT) (ullong volatile a[1])
{
    return  MY_DCRTD(a);
}

INLINE( llong, LLONG_DCRT)  (llong volatile a[1])
{
    return  MY_DCRTD(a);
}

#if _LEAVE_MSVC_DCRT
}
#endif


#if _ENTER_MSVC_INV1
{
#endif

INLINE( _Bool,  BOOL_INV1)  (_Bool volatile a[1])
{
    return  MY_XOR1B(a, 1);
}


INLINE( uchar, UCHAR_INV1)  (uchar volatile a[1])
{
    return  MY_INV1B(a);
}

INLINE( schar, SCHAR_INV1)  (schar volatile a[1])
{
    return  MY_INV1B(a);
}

INLINE(  char,  CHAR_INV1)   (char volatile a[1])
{
    return  MY_INV1B(a);
}


INLINE(ushort, USHRT_INV1) (ushort volatile a[1])
{
    return  MY_INV1H(a);
}

INLINE( short,  SHRT_INV1) (short volatile  a[1])
{
    return  MY_INV1H(a);
}


INLINE(  uint,  UINT_INV1)   (uint volatile a[1])
{
    return  MY_INV1W(a);
}

INLINE(   int,   INT_INV1)    (int volatile a[1])
{
    return  MY_INV1W(a);
}


INLINE( ulong, ULONG_INV1)  (ulong volatile a[1])
{
    return  MY_INV1W(a);
}

INLINE(  long,  LONG_INV1)   (long volatile a[1])
{
    return  MY_INV1W(a);
}


INLINE(ullong,ULLONG_INV1) (ullong volatile a[1])
{
    return  MY_INV1D(a);
}

INLINE( llong, LLONG_INV1)  (llong volatile a[1])
{
    return  MY_INV1D(a);
}

#if _LEAVE_MSVC_INV1
}
#endif

#if _ENTER_MSVC_INVA
{
#endif

INLINE( _Bool,  BOOL_INVA)  (_Bool volatile a[1])
{
    return  MY_XORAB(a, 1);
}


INLINE( uchar, UCHAR_INVA)  (uchar volatile a[1])
{
    return  MY_INVAB(a);
}

INLINE( schar, SCHAR_INVA)  (schar volatile a[1])
{
    return  MY_INVAB(a);
}

INLINE(  char,  CHAR_INVA)   (char volatile a[1])
{
    return  MY_INVAB(a);
}


INLINE(ushort, USHRT_INVA) (ushort volatile a[1])
{
    return  MY_INVAH(a);
}

INLINE( short,  SHRT_INVA) (short volatile  a[1])
{
    return  MY_INVAH(a);
}


INLINE(  uint,  UINT_INVA)   (uint volatile a[1])
{
    return  MY_INVAW(a);
}

INLINE(   int,   INT_INVA)    (int volatile a[1])
{
    return  MY_INVAW(a);
}


INLINE( ulong, ULONG_INVA)  (ulong volatile a[1])
{
    return  MY_INVAW(a);
}

INLINE(  long,  LONG_INVA)   (long volatile a[1])
{
    return  MY_INVAW(a);
}


INLINE(ullong,ULLONG_INVA) (ullong volatile a[1])
{
    return  MY_INVAD(a);
}

INLINE( llong, LLONG_INVA)  (llong volatile a[1])
{
    return  MY_INVAD(a);
}

#if _LEAVE_MSVC_INVA
}
#endif

#if _ENTER_MSVC_INVE
{
#endif

INLINE( _Bool,  BOOL_INVE)  (_Bool volatile a[1])
{
    return  MY_XOREB(a, 1);
}


INLINE( uchar, UCHAR_INVE)  (uchar volatile a[1])
{
    return  MY_INVEB(a);
}

INLINE( schar, SCHAR_INVE)  (schar volatile a[1])
{
    return  MY_INVEB(a);
}

INLINE(  char,  CHAR_INVE)   (char volatile a[1])
{
    return  MY_INVEB(a);
}


INLINE(ushort, USHRT_INVE) (ushort volatile a[1])
{
    return  MY_INVEH(a);
}

INLINE( short,  SHRT_INVE) (short volatile  a[1])
{
    return  MY_INVEH(a);
}


INLINE(  uint,  UINT_INVE)   (uint volatile a[1])
{
    return  MY_INVEW(a);
}

INLINE(   int,   INT_INVE)    (int volatile a[1])
{
    return  MY_INVEW(a);
}


INLINE( ulong, ULONG_INVE)  (ulong volatile a[1])
{
    return  MY_INVEW(a);
}

INLINE(  long,  LONG_INVE)   (long volatile a[1])
{
    return  MY_INVEW(a);
}


INLINE(ullong,ULLONG_INVE) (ullong volatile a[1])
{
    return  MY_INVED(a);
}

INLINE( llong, LLONG_INVE)  (llong volatile a[1])
{
    return  MY_INVED(a);
}


#if _LEAVE_MSVC_INVE
}
#endif

#if _ENTER_MSVC_INVT
{
#endif

INLINE( _Bool,  BOOL_INVT)  (_Bool volatile a[1])
{
    return  MY_XORTB(a, 1);
}


INLINE( uchar, UCHAR_INVT)  (uchar volatile a[1])
{
    return  MY_INVTB(a);
}

INLINE( schar, SCHAR_INVT)  (schar volatile a[1])
{
    return  MY_INVTB(a);
}

INLINE(  char,  CHAR_INVT)   (char volatile a[1])
{
    return  MY_INVTB(a);
}


INLINE(ushort, USHRT_INVT) (ushort volatile a[1])
{
    return  MY_INVTH(a);
}

INLINE( short,  SHRT_INVT) (short volatile  a[1])
{
    return  MY_INVTH(a);
}


INLINE(  uint,  UINT_INVT)   (uint volatile a[1])
{
    return  MY_INVTW(a);
}

INLINE(   int,   INT_INVT)    (int volatile a[1])
{
    return  MY_INVTW(a);
}


INLINE( ulong, ULONG_INVT)  (ulong volatile a[1])
{
    return  MY_INVTW(a);
}

INLINE(  long,  LONG_INVT)   (long volatile a[1])
{
    return  MY_INVTW(a);
}

INLINE(ullong,ULLONG_INVT) (ullong volatile a[1])
{
    return  MY_INVTD(a);
}

INLINE( llong, LLONG_INVT)  (llong volatile a[1])
{
    return  MY_INVTD(a);
}

#if _LEAVE_MSVC_INVT
}
#endif


llong 
LLONG_INV1s(llong volatile a[1])
{
    return MY_XOR1D(a, -1ll);
}