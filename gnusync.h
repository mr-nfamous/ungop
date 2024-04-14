/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

This file defines the following operations for targets
that implement the GNU C atomics:

* cmba() => atomic_signal_fence(memory_order_acquire)
* cmbe() => atomic_signal_fence(memory_order_release)
* cmbt() => atomic_signal_fence(memory_order_release)

* hmba() => atomic_thread_fence(memory_order_acquire)
* hmbe() => atomic_thread_fence(memory_order_release)
* hmbt() => atomic_thread_fence(memory_order_release)

* smba() => hmbt() + synced reads
* smbe() => hmbt() + synced writes
* smbt() => hmbt() + synced all

* ldr1(s) => atomic_load_explicit(s,memory_order_relaxed)
* ldra(s) => atomic_load_explicit(s,memory_order_acquire)
* ldrt(s) => atomic_load_explicit(s,memory_order_seq_cst)

* str1(d, s) => atomic_load_explicit(d, s,memory_order_relaxed)
* stre(d, s) => atomic_load_explicit(d, s,memory_order_release)
* strt(d, s) => atomic_load_explicit(d, s,memory_order_seq_cst)

* swp1(a, b) => atomic_exchange_explicit(a, b, memory_order_relaxed)
* swpa(a, b) => atomic_exchange_explicit(a, b, memory_order_acquire)
* swpe(a, b) => atomic_exchange_explicit(a, b, memory_order_release)
* swpt(a, b) => atomic_exchange_explicit(a, b, memory_order_seq_cst)

* xeq1(a, b, c) => (compare_exchange @ memory_order_relaxed) ‡
* xeqa(a, b, c) => (compare_exchange @ memory_order_acquire) ‡
* xeqe(a, b, c) => (compare_exchange @ memory_order_release) ‡
* xeqt(a, b, c) => (compare_exchange @ memory_order_seq_cst) ‡
‡   atomic_compare_exchange_* exchanges the contents of
    two pointers while xeq* exchanges the contents of a
    register with the contents of a pointer. On Windows
    targets, xeq* can be perfectly mapped to one of the
    InterlockedCompareExchange family functions; on other
    targets, we might need to use inline asm to generate
    the appropriate instruction sequence

* add1(a, b) => fetch_add_explicit(a, b, memory_order_relaxed)
* adda(a, b) => fetch_add_explicit(a, b, memory_order_acquire)
* adde(a, b) => fetch_add_explicit(a, b, memory_order_release)
* addt(a, b) => fetch_add_explicit(a, b, memory_order_seq_cst)

* sub1(a, b) => fetch_sub_explicit(a, b, memory_order_relaxed)
* suba(a, b) => fetch_sub_explicit(a, b, memory_order_acquire)
* sube(a, b) => fetch_sub_explicit(a, b, memory_order_release)
* subt(a, b) => fetch_sub_explicit(a, b, memory_order_seq_cst)

* and1(a, b) => fetch_and_explicit(a, b, memory_order_relaxed)
* anda(a, b) => fetch_and_explicit(a, b, memory_order_acquire)
* ande(a, b) => fetch_and_explicit(a, b, memory_order_release)
* andt(a, b) => fetch_and_explicit(a, b, memory_order_seq_cst)

* orr1(a, b) => fetch_or_explicit(a, b, memory_order_relaxed)
* orra(a, b) => fetch_or_explicit(a, b, memory_order_acquire)
* orre(a, b) => fetch_or_explicit(a, b, memory_order_release)
* orrt(a, b) => fetch_or_explicit(a, b, memory_order_seq_cst)

* xor1(a, b) => fetch_xor_explicit(a, b, memory_order_relaxed)
* xora(a, b) => fetch_xor_explicit(a, b, memory_order_acquire)
* xore(a, b) => fetch_xor_explicit(a, b, memory_order_release)
* xort(a, b) => fetch_xor_explicit(a, b, memory_order_seq_cst)

* icr1(a) => fetch_add_explicit(a, +1, memory_order_relaxed)
* icra(a) => fetch_add_explicit(a, +1, memory_order_acquire)
* icre(a) => fetch_add_explicit(a, +1, memory_order_release)
* icrt(a) => fetch_add_explicit(a, +1, memory_order_seq_cst)

* dcr1(a) => fetch_add_explicit(a, -1, memory_order_relaxed)
* dcra(a) => fetch_add_explicit(a, -1, memory_order_acquire)
* dcre(a) => fetch_add_explicit(a, -1, memory_order_release)
* dcrt(a) => fetch_add_explicit(a, -1, memory_order_seq_cst)

* inv1(a) => fetch_xor_explicit(a, -1, memory_order_relaxed)
* inva(a) => fetch_xor_explicit(a, -1, memory_order_acquire)
* inve(a) => fetch_xor_explicit(a, -1, memory_order_release)
* invt(a) => fetch_xor_explicit(a, -1, memory_order_seq_cst)

There are no "op_fetch" ops, nor are there any plans to
implement them. 

TODO: something about lack of atomic_flag
*/


#define     MY_RELAXED(F, ...) \
__atomic_##F(__VA_OPT__(__VA_ARGS__,)__ATOMIC_RELAXED)

#define     MY_ACQUIRE(F, ...) \
__atomic_##F(__VA_OPT__(__VA_ARGS__,)__ATOMIC_ACQUIRE)

#define     MY_RELEASE(F, ...) \
__atomic_##F(__VA_OPT__(__VA_ARGS__,)__ATOMIC_RELEASE)

#define     MY_ACQ_REL(F, ...) \
__atomic_##F(__VA_OPT__(__VA_ARGS__,)__ATOMIC_ACQ_REL)

#define     MY_SEQ_CST(F, ...) \
__atomic_##F(__VA_OPT__(__VA_ARGS__,)__ATOMIC_SEQ_CST)


union my_bool_xeq {uchar B; _Bool Y;};

typedef enum memory_order {
    memory_order_relaxed=__ATOMIC_RELAXED,
    memory_order_consume=__ATOMIC_CONSUME,
    memory_order_acquire=__ATOMIC_ACQUIRE,
    memory_order_release=__ATOMIC_RELEASE,
    memory_order_acq_rel=__ATOMIC_ACQ_REL,
    memory_order_seq_cst=__ATOMIC_SEQ_CST,
} memory_order;

INLINE(uchar, UCHAR_XEQ1A) (uchar volatile[1], uchar, uchar);
INLINE(uchar, UCHAR_XEQAA) (uchar volatile[1], uchar, uchar);
INLINE(uchar, UCHAR_XEQEA) (uchar volatile[1], uchar, uchar);
INLINE(uchar, UCHAR_XEQTA) (uchar volatile[1], uchar, uchar);


INLINE(void, cmba) (void) {MY_ACQUIRE(signal_fence);}

INLINE(void, cmbe) (void) {MY_RELEASE(signal_fence);}

INLINE(void, cmbt) (void) {MY_SEQ_CST(signal_fence);}


INLINE(void, hmba) (void) {MY_ACQUIRE(thread_fence);}

INLINE(void, hmbe) (void) {MY_RELEASE(thread_fence);}

INLINE(void, hmbt) (void) {MY_SEQ_CST(thread_fence);}


#if     defined(SPC_ARM_ACLE)

INLINE(void, smba) (void) {__dsb(0x9);}

INLINE(void, smbe) (void) {__dsb(0xa);}

INLINE(void, smbt) (void) {__dsb(0xb);}

#elif   defined(SPC_X86_SSE2)

INLINE(void, smba) (void) {_mm_lfence();}

INLINE(void, smbe) (void) {_mm_sfence();}

INLINE(void, smbt) (void) {_mm_mfence();}

#else

#error "unknown arch"

#endif

#if _ENTER_GNUC_LDR1
{
#endif

INLINE( _Bool,  BOOL_LDR1AC)  (_Bool volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}


INLINE( uchar, UCHAR_LDR1AC)  (uchar volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}

INLINE( schar, SCHAR_LDR1AC)  (schar volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}

INLINE( char,   CHAR_LDR1AC)   (char volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}


INLINE(ushort, USHRT_LDR1AC) (ushort volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}

INLINE( short,  SHRT_LDR1AC)  (short volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}


INLINE(  uint,  UINT_LDR1AC)   (uint volatile const src[1])     
{
    return MY_RELAXED(load_n, src);
}

INLINE(   int,   INT_LDR1AC)    (int volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}


INLINE( ulong, ULONG_LDR1AC)  (ulong volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}

INLINE(  long,  LONG_LDR1AC)   (long volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}


INLINE(ullong,ULLONG_LDR1AC) (ullong volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}

INLINE( llong,  LLONG_LDR1AC) (llong volatile const src[1])
{
    return MY_RELAXED(load_n, src);
}


INLINE(void *,  ADDR_LDR1AC) (void const *volatile const src[1])
{
    return (void *) MY_RELAXED(load_n, src);
}

#if _LEAVE_GNUC_LDR1
}
#endif

#if _ENTER_GNUC_LDRA
{
#endif

INLINE( _Bool,  BOOL_LDRAAC)  (_Bool volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}


INLINE( uchar, UCHAR_LDRAAC)  (uchar volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}

INLINE( schar, SCHAR_LDRAAC)  (schar volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}

INLINE( char,   CHAR_LDRAAC)   (char volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}


INLINE(ushort, USHRT_LDRAAC) (ushort volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}

INLINE( short,  SHRT_LDRAAC)  (short volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}


INLINE(  uint,  UINT_LDRAAC)   (uint volatile const src[1])     
{
    return MY_ACQUIRE(load_n, src);
}

INLINE(   int,   INT_LDRAAC)    (int volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}


INLINE( ulong, ULONG_LDRAAC)  (ulong volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}

INLINE(  long,  LONG_LDRAAC)   (long volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}


INLINE(ullong,ULLONG_LDRAAC) (ullong volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}

INLINE( llong,  LLONG_LDRAAC) (llong volatile const src[1])
{
    return MY_ACQUIRE(load_n, src);
}


INLINE(void *,  ADDR_LDRAAC) (void const *volatile const src[1])
{
    return (void *) MY_ACQUIRE(load_n, src);
}

#if _LEAVE_GNUC_LDRA
}
#endif

#if _ENTER_GNUC_LDRT
{
#endif

INLINE( _Bool,  BOOL_LDRTAC)  (_Bool volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}


INLINE( uchar, UCHAR_LDRTAC)  (uchar volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}

INLINE( schar, SCHAR_LDRTAC)  (schar volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}

INLINE( char,   CHAR_LDRTAC)   (char volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}


INLINE(ushort, USHRT_LDRTAC) (ushort volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}

INLINE( short,  SHRT_LDRTAC)  (short volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}


INLINE(  uint,  UINT_LDRTAC)   (uint volatile const src[1])     
{
    return MY_SEQ_CST(load_n, src);
}

INLINE(   int,   INT_LDRTAC)    (int volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}


INLINE( ulong, ULONG_LDRTAC)  (ulong volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}

INLINE(  long,  LONG_LDRTAC)   (long volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}


INLINE(ullong,ULLONG_LDRTAC) (ullong volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}

INLINE( llong,  LLONG_LDRTAC) (llong volatile const src[1])
{
    return MY_SEQ_CST(load_n, src);
}


INLINE(void *,  ADDR_LDRTAC) (void const *volatile const src[1])
{
    return (void *) MY_SEQ_CST(load_n, src);
}

#if _LEAVE_GNUC_LDRT
}
#endif


#if _ENTER_GNUC_STR1
{
#endif

INLINE( _Bool,   BOOL_STR1A)  (_Bool volatile dst[1], _Bool src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE( uchar,  UCHAR_STR1A)  (uchar volatile dst[1], uchar src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}

INLINE( schar,  SCHAR_STR1A)  (schar volatile dst[1], schar src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}

INLINE(  char,   CHAR_STR1A)   (char volatile dst[1], char src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE(ushort,  USHRT_STR1A) (ushort volatile dst[1], ushort src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}

INLINE( short,   SHRT_STR1A)  (short volatile dst[1], short src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE(  uint,   UINT_STR1A)   (uint volatile dst[1], uint src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}

INLINE(   int,    INT_STR1A)    (int volatile dst[1], int src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE( ulong,  ULONG_STR1A)  (ulong volatile dst[1], ulong src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}

INLINE(  long,   LONG_STR1A)   (long volatile dst[1], long src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE(ullong, ULLONG_STR1A) (ullong volatile dst[1], ullong src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}

INLINE( llong,  LLONG_STR1A)  (llong volatile dst[1], llong src)
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE(void *,  ADDR_STR1A)
(
    void const *volatile   dst[1],
    void const *           src
)
{
    MY_RELAXED(store_n, ((intptr_t volatile *) dst), ((intptr_t) src));
    return  (void *) src;
}

#if _LEAVE_GNUC_STR1
}
#endif

#if _ENTER_GNUC_STRE
{
#endif

INLINE( _Bool,   BOOL_STREA)  (_Bool volatile dst[1], _Bool src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE( uchar,  UCHAR_STREA)  (uchar volatile dst[1], uchar src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}

INLINE( schar,  SCHAR_STREA)  (schar volatile dst[1], schar src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}

INLINE(  char,   CHAR_STREA)   (char volatile dst[1], char src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE(ushort,  USHRT_STREA) (ushort volatile dst[1], ushort src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}

INLINE( short,   SHRT_STREA)  (short volatile dst[1], short src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE(  uint,   UINT_STREA)   (uint volatile dst[1], uint src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}

INLINE(   int,    INT_STREA)    (int volatile dst[1], int src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE( ulong,  ULONG_STREA)  (ulong volatile dst[1], ulong src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}

INLINE(  long,   LONG_STREA)   (long volatile dst[1], long src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE(ullong, ULLONG_STREA) (ullong volatile dst[1], ullong src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}

INLINE( llong,  LLONG_STREA)  (llong volatile dst[1], llong src)
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE(void *,  ADDR_STREA)
(
    void const *volatile   dst[1],
    void const *           src
)
{
    MY_RELEASE(store_n, ((intptr_t volatile *) dst), ((intptr_t) src));
    return  (void *) src;
}

#if _LEAVE_GNUC_STRE
}
#endif

#if _ENTER_GNUC_STRT
{
#endif

INLINE( _Bool,   BOOL_STRTA)  (_Bool volatile dst[1], _Bool src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE( uchar,  UCHAR_STRTA)  (uchar volatile dst[1], uchar src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}

INLINE( schar,  SCHAR_STRTA)  (schar volatile dst[1], schar src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}

INLINE(  char,   CHAR_STRTA)   (char volatile dst[1], char src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE(ushort,  USHRT_STRTA) (ushort volatile dst[1], ushort src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}

INLINE( short,   SHRT_STRTA)  (short volatile dst[1], short src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE(  uint,   UINT_STRTA)   (uint volatile dst[1], uint src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}

INLINE(   int,    INT_STRTA)    (int volatile dst[1], int src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE( ulong,  ULONG_STRTA)  (ulong volatile dst[1], ulong src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}

INLINE(  long,   LONG_STRTA)   (long volatile dst[1], long src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE(ullong, ULLONG_STRTA) (ullong volatile dst[1], ullong src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}

INLINE( llong,  LLONG_STRTA)  (llong volatile dst[1], llong src)
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE(void *,  ADDR_STRTA)
(
    void const *volatile   dst[1],
    void const *           src
)
{
    MY_SEQ_CST(store_n, ((intptr_t volatile *) dst), ((intptr_t) src));
    return  (void *) src;
}

#if _LEAVE_GNUC_STRT
}
#endif


#if _ENTER_GNUC_SWP1
{
#endif

INLINE( _Bool,   BOOL_SWP1A)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE( uchar,  UCHAR_SWP1A)  (uchar volatile a[1], uchar b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE( schar,  SCHAR_SWP1A)  (schar volatile a[1], schar b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(  char,   CHAR_SWP1A)   (char volatile a[1], char b)
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(ushort,  USHRT_SWP1A) (ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE( short,   SHRT_SWP1A)  (short volatile a[1], short b)
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(  uint,   UINT_SWP1A)   (uint volatile a[1], uint b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(   int,    INT_SWP1A)    (int volatile a[1], int b)
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE( ulong,  ULONG_SWP1A)  (ulong volatile a[1], ulong b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(  long,   LONG_SWP1A)   (long volatile a[1], long b)
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(ullong, ULLONG_SWP1A) (ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE( llong,  LLONG_SWP1A)  (llong volatile a[1], llong b)
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(void *,  ADDR_SWP1A)
(
    void const *volatile    a[1],
    void const *            b
)
{
    return (void *) MY_RELAXED(
        exchange_n,
        (intptr_t volatile *) a,
        (intptr_t) b
    );
}

#if _LEAVE_GNUC_SWP1
}
#endif

#if _ENTER_GNUC_SWPA
{
#endif

INLINE( _Bool,   BOOL_SWPAA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE( uchar,  UCHAR_SWPAA)  (uchar volatile a[1], uchar b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE( schar,  SCHAR_SWPAA)  (schar volatile a[1], schar b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(  char,   CHAR_SWPAA)   (char volatile a[1], char b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(ushort,  USHRT_SWPAA) (ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE( short,   SHRT_SWPAA)  (short volatile a[1], short b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(  uint,   UINT_SWPAA)   (uint volatile a[1], uint b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(   int,    INT_SWPAA)    (int volatile a[1], int b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE( ulong,  ULONG_SWPAA)  (ulong volatile a[1], ulong b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(  long,   LONG_SWPAA)   (long volatile a[1], long b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(ullong, ULLONG_SWPAA) (ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE( llong,  LLONG_SWPAA)  (llong volatile a[1], llong b)
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(void *,  ADDR_SWPAA)
(
    void const *volatile    a[1],
    void const *            b
)
{
    return (void *) MY_ACQUIRE(
        exchange_n,
        (intptr_t volatile *) a,
        (intptr_t) b
    );
}

#if _LEAVE_GNUC_SWPA
}
#endif

#if _ENTER_GNUC_SWPE
{
#endif

INLINE( _Bool,   BOOL_SWPEA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE( uchar,  UCHAR_SWPEA)  (uchar volatile a[1], uchar b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE( schar,  SCHAR_SWPEA)  (schar volatile a[1], schar b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(  char,   CHAR_SWPEA)   (char volatile a[1], char b)
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(ushort,  USHRT_SWPEA) (ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE( short,   SHRT_SWPEA)  (short volatile a[1], short b)
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(  uint,   UINT_SWPEA)   (uint volatile a[1], uint b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(   int,    INT_SWPEA)    (int volatile a[1], int b)
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE( ulong,  ULONG_SWPEA)  (ulong volatile a[1], ulong b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(  long,   LONG_SWPEA)   (long volatile a[1], long b)
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(ullong, ULLONG_SWPEA) (ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE( llong,  LLONG_SWPEA)  (llong volatile a[1], llong b)
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(void *,  ADDR_SWPEA)
(
    void const *volatile    a[1],
    void const *            b
)
{
    return (void *) MY_RELEASE(
        exchange_n,
        (intptr_t volatile *) a,
        (intptr_t) b
    );
}

#if _LEAVE_GNUC_SWPE
}
#endif

#if _ENTER_GNUC_SWPT
{
#endif

INLINE( _Bool,   BOOL_SWPTA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE( uchar,  UCHAR_SWPTA)  (uchar volatile a[1], uchar b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE( schar,  SCHAR_SWPTA)  (schar volatile a[1], schar b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(  char,   CHAR_SWPTA)   (char volatile a[1], char b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE(ushort,  USHRT_SWPTA) (ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE( short,   SHRT_SWPTA)  (short volatile a[1], short b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE(  uint,   UINT_SWPTA)   (uint volatile a[1], uint b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(   int,    INT_SWPTA)    (int volatile a[1], int b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE( ulong,  ULONG_SWPTA)  (ulong volatile a[1], ulong b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(  long,   LONG_SWPTA)   (long volatile a[1], long b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE(ullong, ULLONG_SWPTA) (ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE( llong,  LLONG_SWPTA)  (llong volatile a[1], llong b)
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(void *,  ADDR_SWPTA)
(
    void const *volatile    a[1],
    void const *            b
)
{
    return (void *) MY_SEQ_CST(
        exchange_n,
        (intptr_t volatile *) a,
        (intptr_t) b
    );
}

#if _LEAVE_GNUC_SWPT
}
#endif


#if _ENTER_GNUC_XEQ1A
{
#endif



INLINE( _Bool,  BOOL_XEQ1A)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return (
        (union my_bool_xeq)
        {
            UCHAR_XEQ1A(
                (uchar volatile *) a,
                (union my_bool_xeq){.Y=b}.B,
                (union my_bool_xeq){.Y=c}.B
            )
        }
    ).Y;
}


INLINE( schar, SCHAR_XEQ1A)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( uchar, UCHAR_XEQ1A)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  char,  CHAR_XEQ1A)   (char volatile a[1],   char b,   char c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ushort, USHRT_XEQ1A) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( short,  SHRT_XEQ1A)  (short volatile a[1],  short b,  short c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(  uint,  UINT_XEQ1A)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(   int,   INT_XEQ1A)    (int volatile a[1],    int b,    int c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE( ulong, ULONG_XEQ1A)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  long,  LONG_XEQ1A)   (long volatile a[1],   long b,   long c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(ullong,ULLONG_XEQ1A) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( llong, LLONG_XEQ1A)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(void *,  ADDR_XEQ1A)
(
    void const *volatile a[1],
    void const *b,
    void const *c
)
{
    return (void *)
#if   INTPTR_WIDTH == INT_WIDTH
        INT_XEQ1A(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQ1A(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQ1A(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQ1A
}
#endif

#if _ENTER_GNUC_XEQAA
{
#endif

INLINE( _Bool,  BOOL_XEQAA)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return (
        (union my_bool_xeq)
        {
            UCHAR_XEQAA(
                (uchar volatile *) a,
                (union my_bool_xeq){.Y=b}.B,
                (union my_bool_xeq){.Y=c}.B
            )
        }
    ).Y;
}


INLINE( schar, SCHAR_XEQAA)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE( uchar, UCHAR_XEQAA)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE(  char,  CHAR_XEQAA)   (char volatile a[1],   char b,   char c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}


INLINE(ushort, USHRT_XEQAA) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE( short,  SHRT_XEQAA)  (short volatile a[1],  short b,  short c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}


INLINE(  uint,  UINT_XEQAA)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE(   int,   INT_XEQAA)    (int volatile a[1],    int b,    int c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}


INLINE( ulong, ULONG_XEQAA)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE(  long,  LONG_XEQAA)   (long volatile a[1],   long b,   long c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE(ullong,ULLONG_XEQAA) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}

INLINE( llong, LLONG_XEQAA)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_ACQUIRE), b;
}


INLINE(void *,  ADDR_XEQAA)
(
    void const *volatile a[1],
    void const *b,
    void const *c
)
{
    return (void *)
#if   INTPTR_WIDTH == INT_WIDTH
        INT_XEQAA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQAA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQAA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQAA
}
#endif

#if _ENTER_GNUC_XEQEA
{
#endif

INLINE( _Bool,  BOOL_XEQEA)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return (
        (union my_bool_xeq)
        {
            UCHAR_XEQEA(
                (uchar volatile *) a,
                (union my_bool_xeq){.Y=b}.B,
                (union my_bool_xeq){.Y=c}.B
            )
        }
    ).Y;
}


INLINE( schar, SCHAR_XEQEA)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE( uchar, UCHAR_XEQEA)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE(  char,  CHAR_XEQEA)   (char volatile a[1],   char b,   char c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}


INLINE(ushort, USHRT_XEQEA) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE( short,  SHRT_XEQEA)  (short volatile a[1],  short b,  short c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}


INLINE(  uint,  UINT_XEQEA)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE(   int,   INT_XEQEA)    (int volatile a[1],    int b,    int c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}


INLINE( ulong, ULONG_XEQEA)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE(  long,  LONG_XEQEA)   (long volatile a[1],   long b,   long c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE(ullong,ULLONG_XEQEA) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}

INLINE( llong, LLONG_XEQEA)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELEASE), b;
}


INLINE(void *,  ADDR_XEQEA)
(
    void const *volatile a[1],
    void const *b,
    void const *c
)
{
    return (void *)
#if   INTPTR_WIDTH == INT_WIDTH
        INT_XEQEA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQEA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQEA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQEA
}
#endif

#if _ENTER_GNUC_XEQTA
{
#endif

INLINE( _Bool,  BOOL_XEQTA)  (_Bool volatile a[1],  _Bool b,  _Bool c)
{
    return (
        (union my_bool_xeq)
        {
            UCHAR_XEQTA(
                (uchar volatile *) a,
                (union my_bool_xeq){.Y=b}.B,
                (union my_bool_xeq){.Y=c}.B
            )
        }
    ).Y;
}


INLINE( schar, SCHAR_XEQTA)  (schar volatile a[1],  schar b,  schar c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE( uchar, UCHAR_XEQTA)  (uchar volatile a[1],  uchar b,  uchar c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(  char,  CHAR_XEQTA)   (char volatile a[1],   char b,   char c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(ushort, USHRT_XEQTA) (ushort volatile a[1], ushort b, ushort c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE( short,  SHRT_XEQTA)  (short volatile a[1],  short b,  short c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(  uint,  UINT_XEQTA)   (uint volatile a[1],   uint b,   uint c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(   int,   INT_XEQTA)    (int volatile a[1],    int b,    int c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE( ulong, ULONG_XEQTA)  (ulong volatile a[1],  ulong b,  ulong c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(  long,  LONG_XEQTA)   (long volatile a[1],   long b,   long c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(ullong,ULLONG_XEQTA) (ullong volatile a[1], ullong b, ullong c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE( llong, LLONG_XEQTA)  (llong volatile a[1],  llong b,  llong c)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(void *,  ADDR_XEQTA)
(
    void const *volatile a[1],
    void const *b,
    void const *c
)
{
    return (void *)
#if   INTPTR_WIDTH == INT_WIDTH
        INT_XEQTA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQTA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQTA(((intptr_t volatile *) a), ((intptr_t) b), ((intptr_t) c));
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQTA
}
#endif


#if _ENTER_GNUC_AND1
{
#endif

INLINE( _Bool,   BOOL_AND1A)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELAXED(fetch_and, a, b);
}


INLINE( uchar,  UCHAR_AND1A)  (uchar volatile a[1], uchar b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

INLINE( schar,  SCHAR_AND1A)  (schar volatile a[1], schar b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

INLINE(  char,   CHAR_AND1A)   (char volatile a[1], char b)
{
    return  MY_RELAXED(fetch_and, a, b);
}


INLINE(ushort,  USHRT_AND1A) (ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

INLINE( short,   SHRT_AND1A)  (short volatile a[1], short b)
{
    return  MY_RELAXED(fetch_and, a, b);
}


INLINE(  uint,   UINT_AND1A)   (uint volatile a[1], uint b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

INLINE(   int,    INT_AND1A)    (int volatile a[1], int b)
{
    return  MY_RELAXED(fetch_and, a, b);
}


INLINE( ulong,  ULONG_AND1A)  (ulong volatile a[1], ulong b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

INLINE(  long,   LONG_AND1A)   (long volatile a[1], long b)
{
    return  MY_RELAXED(fetch_and, a, b);
}


INLINE(ullong, ULLONG_AND1A) (ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

INLINE( llong,  LLONG_AND1A)  (llong volatile a[1], llong b)
{
    return  MY_RELAXED(fetch_and, a, b);
}

#if _LEAVE_GNUC_AND1
}
#endif

#if _ENTER_GNUC_ANDA
{
#endif

INLINE( _Bool,   BOOL_ANDAA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}


INLINE( uchar,  UCHAR_ANDAA)  (uchar volatile a[1], uchar b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

INLINE( schar,  SCHAR_ANDAA)  (schar volatile a[1], schar b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

INLINE(  char,   CHAR_ANDAA)   (char volatile a[1], char b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}


INLINE(ushort,  USHRT_ANDAA) (ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

INLINE( short,   SHRT_ANDAA)  (short volatile a[1], short b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}


INLINE(  uint,   UINT_ANDAA)   (uint volatile a[1], uint b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

INLINE(   int,    INT_ANDAA)    (int volatile a[1], int b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}


INLINE( ulong,  ULONG_ANDAA)  (ulong volatile a[1], ulong b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

INLINE(  long,   LONG_ANDAA)   (long volatile a[1], long b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}


INLINE(ullong, ULLONG_ANDAA) (ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

INLINE( llong,  LLONG_ANDAA)  (llong volatile a[1], llong b)
{
    return  MY_ACQUIRE(fetch_and, a, b);
}

#if _LEAVE_GNUC_ANDA
}
#endif

#if _ENTER_GNUC_ANDE
{
#endif

INLINE( _Bool,   BOOL_ANDEA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELEASE(fetch_and, a, b);
}


INLINE( uchar,  UCHAR_ANDEA)  (uchar volatile a[1], uchar b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

INLINE( schar,  SCHAR_ANDEA)  (schar volatile a[1], schar b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

INLINE(  char,   CHAR_ANDEA)   (char volatile a[1], char b)
{
    return  MY_RELEASE(fetch_and, a, b);
}


INLINE(ushort,  USHRT_ANDEA) (ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

INLINE( short,   SHRT_ANDEA)  (short volatile a[1], short b)
{
    return  MY_RELEASE(fetch_and, a, b);
}


INLINE(  uint,   UINT_ANDEA)   (uint volatile a[1], uint b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

INLINE(   int,    INT_ANDEA)    (int volatile a[1], int b)
{
    return  MY_RELEASE(fetch_and, a, b);
}


INLINE( ulong,  ULONG_ANDEA)  (ulong volatile a[1], ulong b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

INLINE(  long,   LONG_ANDEA)   (long volatile a[1], long b)
{
    return  MY_RELEASE(fetch_and, a, b);
}


INLINE(ullong, ULLONG_ANDEA) (ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

INLINE( llong,  LLONG_ANDEA)  (llong volatile a[1], llong b)
{
    return  MY_RELEASE(fetch_and, a, b);
}

#if _LEAVE_GNUC_ANDE
}
#endif

#if _ENTER_GNUC_ANDT
{
#endif

INLINE( _Bool,   BOOL_ANDTA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}


INLINE( uchar,  UCHAR_ANDTA)  (uchar volatile a[1], uchar b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

INLINE( schar,  SCHAR_ANDTA)  (schar volatile a[1], schar b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

INLINE(  char,   CHAR_ANDTA)   (char volatile a[1], char b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}


INLINE(ushort,  USHRT_ANDTA) (ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

INLINE( short,   SHRT_ANDTA)  (short volatile a[1], short b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}


INLINE(  uint,   UINT_ANDTA)   (uint volatile a[1], uint b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

INLINE(   int,    INT_ANDTA)    (int volatile a[1], int b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}


INLINE( ulong,  ULONG_ANDTA)  (ulong volatile a[1], ulong b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

INLINE(  long,   LONG_ANDTA)   (long volatile a[1], long b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}


INLINE(ullong, ULLONG_ANDTA) (ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

INLINE( llong,  LLONG_ANDTA)  (llong volatile a[1], llong b)
{
    return  MY_SEQ_CST(fetch_and, a, b);
}

#if _LEAVE_GNUC_ANDT
}
#endif


#if _ENTER_GNUC_ORR1
{
#endif

INLINE( _Bool,   BOOL_ORR1A)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELAXED(fetch_or, a, b);
}


INLINE( uchar,  UCHAR_ORR1A)  (uchar volatile a[1], uchar b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

INLINE( schar,  SCHAR_ORR1A)  (schar volatile a[1], schar b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

INLINE(  char,   CHAR_ORR1A)   (char volatile a[1], char b)
{
    return  MY_RELAXED(fetch_or, a, b);
}


INLINE(ushort,  USHRT_ORR1A) (ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

INLINE( short,   SHRT_ORR1A)  (short volatile a[1], short b)
{
    return  MY_RELAXED(fetch_or, a, b);
}


INLINE(  uint,   UINT_ORR1A)   (uint volatile a[1], uint b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

INLINE(   int,    INT_ORR1A)    (int volatile a[1], int b)
{
    return  MY_RELAXED(fetch_or, a, b);
}


INLINE( ulong,  ULONG_ORR1A)  (ulong volatile a[1], ulong b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

INLINE(  long,   LONG_ORR1A)   (long volatile a[1], long b)
{
    return  MY_RELAXED(fetch_or, a, b);
}


INLINE(ullong, ULLONG_ORR1A) (ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

INLINE( llong,  LLONG_ORR1A)  (llong volatile a[1], llong b)
{
    return  MY_RELAXED(fetch_or, a, b);
}

#if _LEAVE_GNUC_ORR1
}
#endif

#if _ENTER_GNUC_ORRA
{
#endif

INLINE( _Bool,   BOOL_ORRAA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}


INLINE( uchar,  UCHAR_ORRAA)  (uchar volatile a[1], uchar b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

INLINE( schar,  SCHAR_ORRAA)  (schar volatile a[1], schar b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

INLINE(  char,   CHAR_ORRAA)   (char volatile a[1], char b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}


INLINE(ushort,  USHRT_ORRAA) (ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

INLINE( short,   SHRT_ORRAA)  (short volatile a[1], short b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}


INLINE(  uint,   UINT_ORRAA)   (uint volatile a[1], uint b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

INLINE(   int,    INT_ORRAA)    (int volatile a[1], int b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}


INLINE( ulong,  ULONG_ORRAA)  (ulong volatile a[1], ulong b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

INLINE(  long,   LONG_ORRAA)   (long volatile a[1], long b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}


INLINE(ullong, ULLONG_ORRAA) (ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

INLINE( llong,  LLONG_ORRAA)  (llong volatile a[1], llong b)
{
    return  MY_ACQUIRE(fetch_or, a, b);
}

#if _LEAVE_GNUC_ORRA
}
#endif

#if _ENTER_GNUC_ORRE
{
#endif

INLINE( _Bool,   BOOL_ORREA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELEASE(fetch_or, a, b);
}


INLINE( uchar,  UCHAR_ORREA)  (uchar volatile a[1], uchar b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

INLINE( schar,  SCHAR_ORREA)  (schar volatile a[1], schar b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

INLINE(  char,   CHAR_ORREA)   (char volatile a[1], char b)
{
    return  MY_RELEASE(fetch_or, a, b);
}


INLINE(ushort,  USHRT_ORREA) (ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

INLINE( short,   SHRT_ORREA)  (short volatile a[1], short b)
{
    return  MY_RELEASE(fetch_or, a, b);
}


INLINE(  uint,   UINT_ORREA)   (uint volatile a[1], uint b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

INLINE(   int,    INT_ORREA)    (int volatile a[1], int b)
{
    return  MY_RELEASE(fetch_or, a, b);
}


INLINE( ulong,  ULONG_ORREA)  (ulong volatile a[1], ulong b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

INLINE(  long,   LONG_ORREA)   (long volatile a[1], long b)
{
    return  MY_RELEASE(fetch_or, a, b);
}


INLINE(ullong, ULLONG_ORREA) (ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

INLINE( llong,  LLONG_ORREA)  (llong volatile a[1], llong b)
{
    return  MY_RELEASE(fetch_or, a, b);
}

#if _LEAVE_GNUC_ORRE
}
#endif

#if _ENTER_GNUC_ORRT
{
#endif

INLINE( _Bool,   BOOL_ORRTA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}


INLINE( uchar,  UCHAR_ORRTA)  (uchar volatile a[1], uchar b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

INLINE( schar,  SCHAR_ORRTA)  (schar volatile a[1], schar b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

INLINE(  char,   CHAR_ORRTA)   (char volatile a[1], char b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}


INLINE(ushort,  USHRT_ORRTA) (ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

INLINE( short,   SHRT_ORRTA)  (short volatile a[1], short b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}


INLINE(  uint,   UINT_ORRTA)   (uint volatile a[1], uint b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

INLINE(   int,    INT_ORRTA)    (int volatile a[1], int b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}


INLINE( ulong,  ULONG_ORRTA)  (ulong volatile a[1], ulong b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

INLINE(  long,   LONG_ORRTA)   (long volatile a[1], long b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}


INLINE(ullong, ULLONG_ORRTA) (ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

INLINE( llong,  LLONG_ORRTA)  (llong volatile a[1], llong b)
{
    return  MY_SEQ_CST(fetch_or, a, b);
}

#if _LEAVE_GNUC_ORRT
}
#endif


#if _ENTER_GNUC_XOR1
{
#endif

INLINE( _Bool,   BOOL_XOR1A)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}


INLINE( uchar,  UCHAR_XOR1A)  (uchar volatile a[1], uchar b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

INLINE( schar,  SCHAR_XOR1A)  (schar volatile a[1], schar b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

INLINE(  char,   CHAR_XOR1A)   (char volatile a[1], char b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}


INLINE(ushort,  USHRT_XOR1A) (ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

INLINE( short,   SHRT_XOR1A)  (short volatile a[1], short b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}


INLINE(  uint,   UINT_XOR1A)   (uint volatile a[1], uint b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

INLINE(   int,    INT_XOR1A)    (int volatile a[1], int b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}


INLINE( ulong,  ULONG_XOR1A)  (ulong volatile a[1], ulong b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

INLINE(  long,   LONG_XOR1A)   (long volatile a[1], long b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}


INLINE(ullong, ULLONG_XOR1A) (ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

INLINE( llong,  LLONG_XOR1A)  (llong volatile a[1], llong b)
{
    return  MY_RELAXED(fetch_xor, a, b);
}

#if _LEAVE_GNUC_XOR1
}
#endif

#if _ENTER_GNUC_XORA
{
#endif

INLINE( _Bool,   BOOL_XORAA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}


INLINE( uchar,  UCHAR_XORAA)  (uchar volatile a[1], uchar b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

INLINE( schar,  SCHAR_XORAA)  (schar volatile a[1], schar b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

INLINE(  char,   CHAR_XORAA)   (char volatile a[1], char b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}


INLINE(ushort,  USHRT_XORAA) (ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

INLINE( short,   SHRT_XORAA)  (short volatile a[1], short b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}


INLINE(  uint,   UINT_XORAA)   (uint volatile a[1], uint b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

INLINE(   int,    INT_XORAA)    (int volatile a[1], int b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}


INLINE( ulong,  ULONG_XORAA)  (ulong volatile a[1], ulong b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

INLINE(  long,   LONG_XORAA)   (long volatile a[1], long b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}


INLINE(ullong, ULLONG_XORAA) (ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

INLINE( llong,  LLONG_XORAA)  (llong volatile a[1], llong b)
{
    return  MY_ACQUIRE(fetch_xor, a, b);
}

#if _LEAVE_GNUC_XORA
}
#endif

#if _ENTER_GNUC_XORE
{
#endif

INLINE( _Bool,   BOOL_XOREA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}


INLINE( uchar,  UCHAR_XOREA)  (uchar volatile a[1], uchar b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

INLINE( schar,  SCHAR_XOREA)  (schar volatile a[1], schar b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

INLINE(  char,   CHAR_XOREA)   (char volatile a[1], char b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}


INLINE(ushort,  USHRT_XOREA) (ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

INLINE( short,   SHRT_XOREA)  (short volatile a[1], short b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}


INLINE(  uint,   UINT_XOREA)   (uint volatile a[1], uint b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

INLINE(   int,    INT_XOREA)    (int volatile a[1], int b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}


INLINE( ulong,  ULONG_XOREA)  (ulong volatile a[1], ulong b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

INLINE(  long,   LONG_XOREA)   (long volatile a[1], long b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}


INLINE(ullong, ULLONG_XOREA) (ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

INLINE( llong,  LLONG_XOREA)  (llong volatile a[1], llong b)
{
    return  MY_RELEASE(fetch_xor, a, b);
}

#if _LEAVE_GNUC_XORE
}
#endif

#if _ENTER_GNUC_XORT
{
#endif

INLINE( _Bool,   BOOL_XORTA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}


INLINE( uchar,  UCHAR_XORTA)  (uchar volatile a[1], uchar b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

INLINE( schar,  SCHAR_XORTA)  (schar volatile a[1], schar b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

INLINE(  char,   CHAR_XORTA)   (char volatile a[1], char b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}


INLINE(ushort,  USHRT_XORTA) (ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

INLINE( short,   SHRT_XORTA)  (short volatile a[1], short b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}


INLINE(  uint,   UINT_XORTA)   (uint volatile a[1], uint b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

INLINE(   int,    INT_XORTA)    (int volatile a[1], int b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}


INLINE( ulong,  ULONG_XORTA)  (ulong volatile a[1], ulong b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

INLINE(  long,   LONG_XORTA)   (long volatile a[1], long b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}


INLINE(ullong, ULLONG_XORTA) (ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

INLINE( llong,  LLONG_XORTA)  (llong volatile a[1], llong b)
{
    return  MY_SEQ_CST(fetch_xor, a, b);
}

#if _LEAVE_GNUC_XORT
}
#endif


#if _ENTER_GNUC_INV1
{
#endif

INLINE( _Bool,   BOOL_INV1A)  (_Bool volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_INV1A)  (uchar volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}

INLINE( schar,  SCHAR_INV1A)  (schar volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}

INLINE(  char,   CHAR_INV1A)   (char volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}


INLINE(ushort,  USHRT_INV1A) (ushort volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}

INLINE( short,   SHRT_INV1A)  (short volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}


INLINE(  uint,   UINT_INV1A)   (uint volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}

INLINE(   int,    INT_INV1A)    (int volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}


INLINE( ulong,  ULONG_INV1A)  (ulong volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}

INLINE(  long,   LONG_INV1A)   (long volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}


INLINE(ullong, ULLONG_INV1A) (ullong volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}

INLINE( llong,  LLONG_INV1A)  (llong volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, -1);
}


INLINE(void *,   ADDR_INV1A) (void const *volatile b[1])
{
    return (void *) MY_RELAXED(
        fetch_xor,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_INV1
}
#endif

#if _ENTER_GNUC_INVA
{
#endif

INLINE( _Bool,   BOOL_INVAA)  (_Bool volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_INVAA)  (uchar volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}

INLINE( schar,  SCHAR_INVAA)  (schar volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}

INLINE(  char,   CHAR_INVAA)   (char volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}


INLINE(ushort,  USHRT_INVAA) (ushort volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}

INLINE( short,   SHRT_INVAA)  (short volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}


INLINE(  uint,   UINT_INVAA)   (uint volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}

INLINE(   int,    INT_INVAA)    (int volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}


INLINE( ulong,  ULONG_INVAA)  (ulong volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}

INLINE(  long,   LONG_INVAA)   (long volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}


INLINE(ullong, ULLONG_INVAA) (ullong volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}

INLINE( llong,  LLONG_INVAA)  (llong volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, -1);
}


INLINE(void *,   ADDR_INVAA) (void const *volatile b[1])
{
    return (void *) MY_ACQUIRE(
        fetch_xor,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_INVA
}
#endif

#if _ENTER_GNUC_INVE
{
#endif

INLINE( _Bool,   BOOL_INVEA)  (_Bool volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_INVEA)  (uchar volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}

INLINE( schar,  SCHAR_INVEA)  (schar volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}

INLINE(  char,   CHAR_INVEA)   (char volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}


INLINE(ushort,  USHRT_INVEA) (ushort volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}

INLINE( short,   SHRT_INVEA)  (short volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}


INLINE(  uint,   UINT_INVEA)   (uint volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}

INLINE(   int,    INT_INVEA)    (int volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}


INLINE( ulong,  ULONG_INVEA)  (ulong volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}

INLINE(  long,   LONG_INVEA)   (long volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}


INLINE(ullong, ULLONG_INVEA) (ullong volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}

INLINE( llong,  LLONG_INVEA)  (llong volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, -1);
}


INLINE(void *,   ADDR_INVEA) (void const *volatile b[1])
{
    return (void *) MY_RELEASE(
        fetch_xor,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_INVE
}
#endif

#if _ENTER_GNUC_INVT
{
#endif

INLINE( _Bool,   BOOL_INVTA)  (_Bool volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_INVTA)  (uchar volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}

INLINE( schar,  SCHAR_INVTA)  (schar volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}

INLINE(  char,   CHAR_INVTA)   (char volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}


INLINE(ushort,  USHRT_INVTA) (ushort volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}

INLINE( short,   SHRT_INVTA)  (short volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}


INLINE(  uint,   UINT_INVTA)   (uint volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}

INLINE(   int,    INT_INVTA)    (int volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}


INLINE( ulong,  ULONG_INVTA)  (ulong volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}

INLINE(  long,   LONG_INVTA)   (long volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}


INLINE(ullong, ULLONG_INVTA) (ullong volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}

INLINE( llong,  LLONG_INVTA)  (llong volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, -1);
}


INLINE(void *,   ADDR_INVTA) (void const *volatile b[1])
{
    return (void *) MY_SEQ_CST(
        fetch_xor,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_INVT
}
#endif


#if _ENTER_GNUC_ADD1
{
#endif

INLINE( _Bool,   BOOL_ADD1A)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELAXED(fetch_add, a, b);
}


INLINE( uchar,  UCHAR_ADD1A)  (uchar volatile a[1], uchar b)
{
    return  MY_RELAXED(fetch_add, a, b);
}

INLINE( schar,  SCHAR_ADD1A)  (schar volatile a[1], schar b)
{
    return  MY_RELAXED(fetch_add, a, b);
}

INLINE(  char,   CHAR_ADD1A)   (char volatile a[1], char b)
{
    return  MY_RELAXED(fetch_add, a, b);
}


INLINE(ushort,  USHRT_ADD1A) (ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(fetch_add, a, b);
}

INLINE( short,   SHRT_ADD1A)  (short volatile a[1], short b)
{
    return  MY_RELAXED(fetch_add, a, b);
}


INLINE(  uint,   UINT_ADD1A)   (uint volatile a[1], uint b)
{
    return  MY_RELAXED(fetch_add, a, b);
}

INLINE(   int,    INT_ADD1A)    (int volatile a[1], int b)
{
    return  MY_RELAXED(fetch_add, a, b);
}


INLINE( ulong,  ULONG_ADD1A)  (ulong volatile a[1], ulong b)
{
    return  MY_RELAXED(fetch_add, a, b);
}

INLINE(  long,   LONG_ADD1A)   (long volatile a[1], long b)
{
    return  MY_RELAXED(fetch_add, a, b);
}


INLINE(ullong, ULLONG_ADD1A) (ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(fetch_add, a, b);
}

INLINE( llong,  LLONG_ADD1A)  (llong volatile a[1], llong b)
{
    return  MY_RELAXED(fetch_add, a, b);
}


INLINE(void *,   ADDR_ADD1A)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_RELAXED(
        fetch_add,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_ADD1
}
#endif

#if _ENTER_GNUC_ADDA
{
#endif

INLINE( _Bool,   BOOL_ADDAA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}


INLINE( uchar,  UCHAR_ADDAA)  (uchar volatile a[1], uchar b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}

INLINE( schar,  SCHAR_ADDAA)  (schar volatile a[1], schar b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}

INLINE(  char,   CHAR_ADDAA)   (char volatile a[1], char b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}


INLINE(ushort,  USHRT_ADDAA) (ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}

INLINE( short,   SHRT_ADDAA)  (short volatile a[1], short b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}


INLINE(  uint,   UINT_ADDAA)   (uint volatile a[1], uint b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}

INLINE(   int,    INT_ADDAA)    (int volatile a[1], int b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}


INLINE( ulong,  ULONG_ADDAA)  (ulong volatile a[1], ulong b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}

INLINE(  long,   LONG_ADDAA)   (long volatile a[1], long b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}


INLINE(ullong, ULLONG_ADDAA) (ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}

INLINE( llong,  LLONG_ADDAA)  (llong volatile a[1], llong b)
{
    return  MY_ACQUIRE(fetch_add, a, b);
}


INLINE(void *,   ADDR_ADDAA)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_ACQUIRE(
        fetch_add,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_ADDA
}
#endif

#if _ENTER_GNUC_ADDE
{
#endif

INLINE( _Bool,   BOOL_ADDEA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELEASE(fetch_add, a, b);
}


INLINE( uchar,  UCHAR_ADDEA)  (uchar volatile a[1], uchar b)
{
    return  MY_RELEASE(fetch_add, a, b);
}

INLINE( schar,  SCHAR_ADDEA)  (schar volatile a[1], schar b)
{
    return  MY_RELEASE(fetch_add, a, b);
}

INLINE(  char,   CHAR_ADDEA)   (char volatile a[1], char b)
{
    return  MY_RELEASE(fetch_add, a, b);
}


INLINE(ushort,  USHRT_ADDEA) (ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(fetch_add, a, b);
}

INLINE( short,   SHRT_ADDEA)  (short volatile a[1], short b)
{
    return  MY_RELEASE(fetch_add, a, b);
}


INLINE(  uint,   UINT_ADDEA)   (uint volatile a[1], uint b)
{
    return  MY_RELEASE(fetch_add, a, b);
}

INLINE(   int,    INT_ADDEA)    (int volatile a[1], int b)
{
    return  MY_RELEASE(fetch_add, a, b);
}


INLINE( ulong,  ULONG_ADDEA)  (ulong volatile a[1], ulong b)
{
    return  MY_RELEASE(fetch_add, a, b);
}

INLINE(  long,   LONG_ADDEA)   (long volatile a[1], long b)
{
    return  MY_RELEASE(fetch_add, a, b);
}


INLINE(ullong, ULLONG_ADDEA) (ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(fetch_add, a, b);
}

INLINE( llong,  LLONG_ADDEA)  (llong volatile a[1], llong b)
{
    return  MY_RELEASE(fetch_add, a, b);
}


INLINE(void *,   ADDR_ADDEA)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_RELEASE(
        fetch_add,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_ADDE
}
#endif

#if _ENTER_GNUC_ADDT
{
#endif

INLINE( _Bool,   BOOL_ADDTA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}


INLINE( uchar,  UCHAR_ADDTA)  (uchar volatile a[1], uchar b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}

INLINE( schar,  SCHAR_ADDTA)  (schar volatile a[1], schar b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}

INLINE(  char,   CHAR_ADDTA)   (char volatile a[1], char b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}


INLINE(ushort,  USHRT_ADDTA) (ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}

INLINE( short,   SHRT_ADDTA)  (short volatile a[1], short b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}


INLINE(  uint,   UINT_ADDTA)   (uint volatile a[1], uint b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}

INLINE(   int,    INT_ADDTA)    (int volatile a[1], int b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}


INLINE( ulong,  ULONG_ADDTA)  (ulong volatile a[1], ulong b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}

INLINE(  long,   LONG_ADDTA)   (long volatile a[1], long b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}


INLINE(ullong, ULLONG_ADDTA) (ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}

INLINE( llong,  LLONG_ADDTA)  (llong volatile a[1], llong b)
{
    return  MY_SEQ_CST(fetch_add, a, b);
}


INLINE(void *,   ADDR_ADDTA)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_SEQ_CST(
        fetch_add,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_ADDT
}
#endif


#if _ENTER_GNUC_ICR1
{
#endif

INLINE( _Bool,   BOOL_ICR1A)  (_Bool volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_ICR1A)  (uchar volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}

INLINE( schar,  SCHAR_ICR1A)  (schar volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}

INLINE(  char,   CHAR_ICR1A)   (char volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}


INLINE(ushort,  USHRT_ICR1A) (ushort volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}

INLINE( short,   SHRT_ICR1A)  (short volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}


INLINE(  uint,   UINT_ICR1A)   (uint volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}

INLINE(   int,    INT_ICR1A)    (int volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}


INLINE( ulong,  ULONG_ICR1A)  (ulong volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}

INLINE(  long,   LONG_ICR1A)   (long volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}


INLINE(ullong, ULLONG_ICR1A) (ullong volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}

INLINE( llong,  LLONG_ICR1A)  (llong volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, 1);
}


INLINE(void *,   ADDR_ICR1A) (void const *volatile b[1])
{
    return (void *) MY_RELAXED(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_ICR1
}
#endif

#if _ENTER_GNUC_ICRA
{
#endif

INLINE( _Bool,   BOOL_ICRAA)  (_Bool volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_ICRAA)  (uchar volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}

INLINE( schar,  SCHAR_ICRAA)  (schar volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}

INLINE(  char,   CHAR_ICRAA)   (char volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}


INLINE(ushort,  USHRT_ICRAA) (ushort volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}

INLINE( short,   SHRT_ICRAA)  (short volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}


INLINE(  uint,   UINT_ICRAA)   (uint volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}

INLINE(   int,    INT_ICRAA)    (int volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}


INLINE( ulong,  ULONG_ICRAA)  (ulong volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}

INLINE(  long,   LONG_ICRAA)   (long volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}


INLINE(ullong, ULLONG_ICRAA) (ullong volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}

INLINE( llong,  LLONG_ICRAA)  (llong volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, 1);
}


INLINE(void *,   ADDR_ICRAA) (void const *volatile b[1])
{
    return (void *) MY_ACQUIRE(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_ICRA
}
#endif

#if _ENTER_GNUC_ICRE
{
#endif

INLINE( _Bool,   BOOL_ICREA)  (_Bool volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_ICREA)  (uchar volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}

INLINE( schar,  SCHAR_ICREA)  (schar volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}

INLINE(  char,   CHAR_ICREA)   (char volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}


INLINE(ushort,  USHRT_ICREA) (ushort volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}

INLINE( short,   SHRT_ICREA)  (short volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}


INLINE(  uint,   UINT_ICREA)   (uint volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}

INLINE(   int,    INT_ICREA)    (int volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}


INLINE( ulong,  ULONG_ICREA)  (ulong volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}

INLINE(  long,   LONG_ICREA)   (long volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}


INLINE(ullong, ULLONG_ICREA) (ullong volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}

INLINE( llong,  LLONG_ICREA)  (llong volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, 1);
}


INLINE(void *,   ADDR_ICREA) (void const *volatile b[1])
{
    return (void *) MY_RELEASE(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_ICRE
}
#endif

#if _ENTER_GNUC_ICRT
{
#endif

INLINE( _Bool,   BOOL_ICRTA)  (_Bool volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_ICRTA)  (uchar volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}

INLINE( schar,  SCHAR_ICRTA)  (schar volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}

INLINE(  char,   CHAR_ICRTA)   (char volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}


INLINE(ushort,  USHRT_ICRTA) (ushort volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}

INLINE( short,   SHRT_ICRTA)  (short volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}


INLINE(  uint,   UINT_ICRTA)   (uint volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}

INLINE(   int,    INT_ICRTA)    (int volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}


INLINE( ulong,  ULONG_ICRTA)  (ulong volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}

INLINE(  long,   LONG_ICRTA)   (long volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}


INLINE(ullong, ULLONG_ICRTA) (ullong volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}

INLINE( llong,  LLONG_ICRTA)  (llong volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, 1);
}


INLINE(void *,   ADDR_ICRTA) (void const *volatile b[1])
{
    return (void *) MY_SEQ_CST(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_ICRT
}
#endif


#if _ENTER_GNUC_SUB1
{
#endif

INLINE( _Bool,   BOOL_SUB1A)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}


INLINE( uchar,  UCHAR_SUB1A)  (uchar volatile a[1], uchar b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}

INLINE( schar,  SCHAR_SUB1A)  (schar volatile a[1], schar b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}

INLINE(  char,   CHAR_SUB1A)   (char volatile a[1], char b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}


INLINE(ushort,  USHRT_SUB1A) (ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}

INLINE( short,   SHRT_SUB1A)  (short volatile a[1], short b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}


INLINE(  uint,   UINT_SUB1A)   (uint volatile a[1], uint b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}

INLINE(   int,    INT_SUB1A)    (int volatile a[1], int b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}


INLINE( ulong,  ULONG_SUB1A)  (ulong volatile a[1], ulong b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}

INLINE(  long,   LONG_SUB1A)   (long volatile a[1], long b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}


INLINE(ullong, ULLONG_SUB1A) (ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}

INLINE( llong,  LLONG_SUB1A)  (llong volatile a[1], llong b)
{
    return  MY_RELAXED(fetch_sub, a, b);
}


INLINE(void *,   ADDR_SUB1A)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_RELAXED(
        fetch_sub,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_SUB1
}
#endif

#if _ENTER_GNUC_SUBA
{
#endif

INLINE( _Bool,   BOOL_SUBAA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}


INLINE( uchar,  UCHAR_SUBAA)  (uchar volatile a[1], uchar b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}

INLINE( schar,  SCHAR_SUBAA)  (schar volatile a[1], schar b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}

INLINE(  char,   CHAR_SUBAA)   (char volatile a[1], char b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}


INLINE(ushort,  USHRT_SUBAA) (ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}

INLINE( short,   SHRT_SUBAA)  (short volatile a[1], short b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}


INLINE(  uint,   UINT_SUBAA)   (uint volatile a[1], uint b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}

INLINE(   int,    INT_SUBAA)    (int volatile a[1], int b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}


INLINE( ulong,  ULONG_SUBAA)  (ulong volatile a[1], ulong b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}

INLINE(  long,   LONG_SUBAA)   (long volatile a[1], long b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}


INLINE(ullong, ULLONG_SUBAA) (ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}

INLINE( llong,  LLONG_SUBAA)  (llong volatile a[1], llong b)
{
    return  MY_ACQUIRE(fetch_sub, a, b);
}


INLINE(void *,   ADDR_SUBAA)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_ACQUIRE(
        fetch_sub,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_SUBA
}
#endif

#if _ENTER_GNUC_SUBE
{
#endif

INLINE( _Bool,   BOOL_SUBEA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}


INLINE( uchar,  UCHAR_SUBEA)  (uchar volatile a[1], uchar b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}

INLINE( schar,  SCHAR_SUBEA)  (schar volatile a[1], schar b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}

INLINE(  char,   CHAR_SUBEA)   (char volatile a[1], char b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}


INLINE(ushort,  USHRT_SUBEA) (ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}

INLINE( short,   SHRT_SUBEA)  (short volatile a[1], short b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}


INLINE(  uint,   UINT_SUBEA)   (uint volatile a[1], uint b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}

INLINE(   int,    INT_SUBEA)    (int volatile a[1], int b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}


INLINE( ulong,  ULONG_SUBEA)  (ulong volatile a[1], ulong b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}

INLINE(  long,   LONG_SUBEA)   (long volatile a[1], long b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}


INLINE(ullong, ULLONG_SUBEA) (ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}

INLINE( llong,  LLONG_SUBEA)  (llong volatile a[1], llong b)
{
    return  MY_RELEASE(fetch_sub, a, b);
}


INLINE(void *,   ADDR_SUBEA)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_RELEASE(
        fetch_sub,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_SUBE
}
#endif

#if _ENTER_GNUC_SUBT
{
#endif

INLINE( _Bool,   BOOL_SUBTA)  (_Bool volatile a[1], _Bool b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}


INLINE( uchar,  UCHAR_SUBTA)  (uchar volatile a[1], uchar b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}

INLINE( schar,  SCHAR_SUBTA)  (schar volatile a[1], schar b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}

INLINE(  char,   CHAR_SUBTA)   (char volatile a[1], char b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}


INLINE(ushort,  USHRT_SUBTA) (ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}

INLINE( short,   SHRT_SUBTA)  (short volatile a[1], short b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}


INLINE(  uint,   UINT_SUBTA)   (uint volatile a[1], uint b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}

INLINE(   int,    INT_SUBTA)    (int volatile a[1], int b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}


INLINE( ulong,  ULONG_SUBTA)  (ulong volatile a[1], ulong b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}

INLINE(  long,   LONG_SUBTA)   (long volatile a[1], long b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}


INLINE(ullong, ULLONG_SUBTA) (ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}

INLINE( llong,  LLONG_SUBTA)  (llong volatile a[1], llong b)
{
    return  MY_SEQ_CST(fetch_sub, a, b);
}


INLINE(void *,   ADDR_SUBTA)
(
    void const *volatile    a[1],
    ptrdiff_t               b
)
{
    return (void *) MY_SEQ_CST(
        fetch_sub,
        (ptrdiff_t volatile *) a,
        (ptrdiff_t) b
    );
}

#if _LEAVE_GNUC_SUBT
}
#endif



#if _ENTER_GNUC_DCR1
{
#endif

INLINE( _Bool,   BOOL_DCR1A)  (_Bool volatile b[1])
{
    return  MY_RELAXED(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_DCR1A)  (uchar volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}

INLINE( schar,  SCHAR_DCR1A)  (schar volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}

INLINE(  char,   CHAR_DCR1A)   (char volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}


INLINE(ushort,  USHRT_DCR1A) (ushort volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}

INLINE( short,   SHRT_DCR1A)  (short volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}


INLINE(  uint,   UINT_DCR1A)   (uint volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}

INLINE(   int,    INT_DCR1A)    (int volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}


INLINE( ulong,  ULONG_DCR1A)  (ulong volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}

INLINE(  long,   LONG_DCR1A)   (long volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}


INLINE(ullong, ULLONG_DCR1A) (ullong volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}

INLINE( llong,  LLONG_DCR1A)  (llong volatile b[1])
{
    return  MY_RELAXED(fetch_add, b, -1);
}


INLINE(void *,   ADDR_DCR1A) (void const *volatile b[1])
{
    return (void *) MY_RELAXED(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_DCR1
}
#endif

#if _ENTER_GNUC_DCRA
{
#endif

INLINE( _Bool,   BOOL_DCRAA)  (_Bool volatile b[1])
{
    return  MY_ACQUIRE(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_DCRAA)  (uchar volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}

INLINE( schar,  SCHAR_DCRAA)  (schar volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}

INLINE(  char,   CHAR_DCRAA)   (char volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}


INLINE(ushort,  USHRT_DCRAA) (ushort volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}

INLINE( short,   SHRT_DCRAA)  (short volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}


INLINE(  uint,   UINT_DCRAA)   (uint volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}

INLINE(   int,    INT_DCRAA)    (int volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}


INLINE( ulong,  ULONG_DCRAA)  (ulong volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}

INLINE(  long,   LONG_DCRAA)   (long volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}


INLINE(ullong, ULLONG_DCRAA) (ullong volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}

INLINE( llong,  LLONG_DCRAA)  (llong volatile b[1])
{
    return  MY_ACQUIRE(fetch_add, b, -1);
}


INLINE(void *,   ADDR_DCRAA) (void const *volatile b[1])
{
    return (void *) MY_ACQUIRE(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_DCRA
}
#endif

#if _ENTER_GNUC_DCRE
{
#endif

INLINE( _Bool,   BOOL_DCREA)  (_Bool volatile b[1])
{
    return  MY_RELEASE(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_DCREA)  (uchar volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}

INLINE( schar,  SCHAR_DCREA)  (schar volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}

INLINE(  char,   CHAR_DCREA)   (char volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}


INLINE(ushort,  USHRT_DCREA) (ushort volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}

INLINE( short,   SHRT_DCREA)  (short volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}


INLINE(  uint,   UINT_DCREA)   (uint volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}

INLINE(   int,    INT_DCREA)    (int volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}


INLINE( ulong,  ULONG_DCREA)  (ulong volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}

INLINE(  long,   LONG_DCREA)   (long volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}


INLINE(ullong, ULLONG_DCREA) (ullong volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}

INLINE( llong,  LLONG_DCREA)  (llong volatile b[1])
{
    return  MY_RELEASE(fetch_add, b, -1);
}


INLINE(void *,   ADDR_DCREA) (void const *volatile b[1])
{
    return (void *) MY_RELEASE(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_DCRE
}
#endif

#if _ENTER_GNUC_DCRT
{
#endif

INLINE( _Bool,   BOOL_DCRTA)  (_Bool volatile b[1])
{
    return  MY_SEQ_CST(fetch_xor, b, 1);
}


INLINE( uchar,  UCHAR_DCRTA)  (uchar volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}

INLINE( schar,  SCHAR_DCRTA)  (schar volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}

INLINE(  char,   CHAR_DCRTA)   (char volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}


INLINE(ushort,  USHRT_DCRTA) (ushort volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}

INLINE( short,   SHRT_DCRTA)  (short volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}


INLINE(  uint,   UINT_DCRTA)   (uint volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}

INLINE(   int,    INT_DCRTA)    (int volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}


INLINE( ulong,  ULONG_DCRTA)  (ulong volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}

INLINE(  long,   LONG_DCRTA)   (long volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}


INLINE(ullong, ULLONG_DCRTA) (ullong volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}

INLINE( llong,  LLONG_DCRTA)  (llong volatile b[1])
{
    return  MY_SEQ_CST(fetch_add, b, -1);
}


INLINE(void *,   ADDR_DCRTA) (void const *volatile b[1])
{
    return (void *) MY_SEQ_CST(
        fetch_add,
        ((ptrdiff_t volatile *) b),
        ((ptrdiff_t) 1)
    );
}

#if _LEAVE_GNUC_DCRT
}
#endif

