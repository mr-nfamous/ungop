/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

    This file defines the following operations for targets
    that implement the GNU C atomics:

    * cmba  (signal_fence @ memory_order_acquire)
    * cmbe  (signal_fence @ memory_order_release)
    * cmbt  (signal_fence @ memory_order_release)

    * hmba  (thread_fence @ memory_order_acquire) †
    * hmbe  (thread_fence @ memory_order_release) †
    * hmbt  (thread_fence @ memory_order_release) †

    * ldr1  (load @ memory_order_relaxed)
    * ldra  (load @ memory_order_acquire)
    * ldrt  (load @ memory_order_seq_cst)

    * str1  (store @ memory_order_acquire)
    * stre  (store @ memory_order_release)
    * strt  (store @ memory_order_seq_cst)

    * swp1  (exchange @ memory_order_relaxed)
    * swpa  (exchange @ memory_order_acquire)
    * swpe  (exchange @ memory_order_release)
    * swpt  (exchange @ memory_order_seq_cst)

    * xeq1  (compare_exchange @ memory_order_relaxed) ‡
    * xeqa  (compare_exchange @ memory_order_acquire) ‡
    * xeqe  (compare_exchange @ memory_order_release) ‡
    * xeqt  (compare_exchange @ memory_order_seq_cst) ‡
    ‡   atomic_compare_exchange_* exchanges the contents of
        two pointers while xeq* exchanges the contents of a
        register with the contents of a pointer. On Windows
        targets, xeq* can be perfectly mapped to one of the
        InterlockedCompareExchange family functions; on other
        targets, we might need to use inline asm to generate
        the appropriate instruction sequence

    * add1  (fetch_add @ memory_order_relaxed)
    * adda  (fetch_add @ memory_order_acquire)
    * adde  (fetch_add @ memory_order_release)
    * addt  (fetch_add @ memory_order_seq_cst)

    * sub1  (fetch_sub @ memory_order_relaxed)
    * suba  (fetch_sub @ memory_order_acquire)
    * sube  (fetch_sub @ memory_order_release)
    * subt  (fetch_sub @ memory_order_seq_cst)

    * and1  (fetch_and @ memory_order_relaxed)
    * anda  (fetch_and @ memory_order_acquire)
    * ande  (fetch_and @ memory_order_release)
    * andt  (fetch_and @ memory_order_seq_cst)

    * orr1  (fetch_or @ memory_order_relaxed)
    * orra  (fetch_or @ memory_order_acquire)
    * orre  (fetch_or @ memory_order_release)
    * orrt  (fetch_or @ memory_order_seq_cst)

    * xor1  (fetch_xor @ memory_order_relaxed)
    * xora  (fetch_xor @ memory_order_acquire)
    * xore  (fetch_xor @ memory_order_release)
    * xort  (fetch_xor @ memory_order_seq_cst)

There are no "op_fetch" ops, nor are there any plans to
implement them. 

The add/sub atomics for pointers are kinda exceptional in
that they take a ptrdiff_t as the first operand. That is, 
add1, adda, adde, addt, sub1, suba, sube, and subt are 
semantically equivalent to something like:

    void *
    subaac(ptrdiff_t a, void const *b[1])
    {
        void *prev = ldr1acac(b);
        str1ac((prev+a), b);
        return prev;
    }

"Kinda" exceptional because the "ac" suffix, which roughly
means "address constant", is a catch-all for anything pointer
related.

*/

typedef enum memory_order {
    memory_order_relaxed=__ATOMIC_RELAXED,
    memory_order_consume=__ATOMIC_CONSUME,
    memory_order_acquire=__ATOMIC_ACQUIRE,
    memory_order_release=__ATOMIC_RELEASE,
    memory_order_acq_rel=__ATOMIC_ACQ_REL,
    memory_order_seq_cst=__ATOMIC_SEQ_CST,
} memory_order;

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


#if _ENTER_GNUC_CMB
{
#endif

INLINE(void, cmba) (void) {MY_ACQUIRE(signal_fence);}

INLINE(void, cmbe) (void) {MY_RELEASE(signal_fence);}

INLINE(void, cmbt) (void) {MY_SEQ_CST(signal_fence);}

#if _LEAVE_GNUC_
}
#endif


#if _ENTER_GNUC_HMB
{
#endif

INLINE(void, hmba) (void) {MY_ACQUIRE(thread_fence);}

INLINE(void, hmbe) (void) {MY_RELEASE(thread_fence);}

INLINE(void, hmbt) (void) {MY_SEQ_CST(thread_fence);}

#if _LEAVE_GNUC_
}
#endif


#if _ENTER_GNUC_SMB
{
#endif

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


#if _LEAVE_GNUC_SMB_
}
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

INLINE( _Bool,  BOOL_STR1)  (_Bool src,  _Bool volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}


INLINE( uchar, UCHAR_STR1)  (uchar src,  uchar volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}

INLINE( schar, SCHAR_STR1)  (schar src,  schar volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}

INLINE(  char,  CHAR_STR1)   (char src,   char volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}


INLINE(ushort, USHRT_STR1) (ushort src, ushort volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}

INLINE( short,  SHRT_STR1)  (short src,  short volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}


INLINE(  uint,  UINT_STR1)   (uint src,   uint volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}

INLINE(   int,   INT_STR1)    (int src,    int volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}


INLINE( ulong, ULONG_STR1)  (ulong src,  ulong volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}

INLINE(  long,  LONG_STR1)   (long src,   long volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return  src;
}


INLINE(ullong,ULLONG_STR1) (ullong src, ullong volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}

INLINE( llong, LLONG_STR1)  (llong src,  llong volatile dst[1])
{
    MY_RELAXED(store_n, dst, src);
    return src;
}


INLINE(void *,  ADDR_STR1)
(
    void const *            src,
    void const *volatile    dst[1]
)
{
    MY_RELAXED(store_n, dst, src);
    return (void *) src;
}

#if _LEAVE_GNUC_STR1
}
#endif

#if _ENTER_GNUC_STRE
{
#endif


INLINE( _Bool,  BOOL_STRE)  (_Bool src,  _Bool volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}


INLINE( uchar, UCHAR_STRE)  (uchar src,  uchar volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE( schar, SCHAR_STRE)  (schar src,  schar volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE(  char,  CHAR_STRE)   (char src,   char volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}


INLINE(ushort, USHRT_STRE) (ushort src, ushort volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE( short,  SHRT_STRE)  (short src,  short volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}


INLINE(  uint,  UINT_STRE)   (uint src,   uint volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE(   int,   INT_STRE)    (int src,    int volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}


INLINE( ulong, ULONG_STRE)  (ulong src,  ulong volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE(  long,  LONG_STRE)   (long src,   long volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return  src;
}


INLINE(ullong,ULLONG_STRE) (ullong src, ullong volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE( llong, LLONG_STRE)  (llong src,  llong volatile dst[1])
{
    MY_RELEASE(store_n, dst, src);
    return src;
}

INLINE(void *,  ADDR_STRE)
(
    void const *            src,
    void const *volatile    dst[1]
)
{
    MY_RELEASE(store_n, dst, src);
    return (void *) src;
}

#if _LEAVE_GNUC_STRE
}
#endif

#if _ENTER_GNUC_STRT
{
#endif

INLINE(void *,  ADDR_STRT)
(
    void const *            src,
    void const *volatile    dst[1]
)
{
    MY_SEQ_CST(store_n, dst, src);
    return (void *) src;
}


INLINE( _Bool,  BOOL_STRT)  (_Bool src,  _Bool volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}


INLINE( uchar, UCHAR_STRT)  (uchar src,  uchar volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

INLINE( schar, SCHAR_STRT)  (schar src,  schar volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

INLINE(  char,  CHAR_STRT)   (char src,   char volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}


INLINE(ushort, USHRT_STRT) (ushort src, ushort volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

INLINE( short,  SHRT_STRT)  (short src,  short volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}


INLINE(  uint,  UINT_STRT)   (uint src,   uint volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

INLINE(   int,   INT_STRT)    (int src,    int volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}


INLINE( ulong, ULONG_STRT)  (ulong src,  ulong volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

INLINE(  long,  LONG_STRT)   (long src,   long volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return  src;
}


INLINE(ullong,ULLONG_STRT) (ullong src, ullong volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

INLINE( llong, LLONG_STRT)  (llong src,  llong volatile dst[1])
{
    MY_SEQ_CST(store_n, dst, src);
    return src;
}

#if _LEAVE_GNUC_STRT
}
#endif


#if _ENTER_GNUC_SWP1
{
#endif

INLINE( _Bool, BOOL_SWP1)  (_Bool b,  _Bool volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE( uchar, UCHAR_SWP1)  (uchar b,  uchar volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE( schar, SCHAR_SWP1)  (schar b,  schar volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(  char,  CHAR_SWP1)   (char b,   char volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(ushort, USHRT_SWP1) (ushort b, ushort volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE( short,  SHRT_SWP1)  (short b,  short volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(  uint,  UINT_SWP1)   (uint b,   uint volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(   int,   INT_SWP1)    (int b,    int volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE( ulong, ULONG_SWP1)  (ulong b,  ulong volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE(  long,  LONG_SWP1)   (long b,   long volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(ullong,ULLONG_SWP1) (ullong b, ullong volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}

INLINE( llong, LLONG_SWP1)  (llong b,  llong volatile a[1])
{
    return  MY_RELAXED(exchange_n, a, b);
}


INLINE(void *,  ADDR_SWP1)
(
    void const *            a,
    void const *volatile    b[1]
)
{
    return (void *) MY_RELAXED(
        exchange_n,
        (intptr_t volatile *) b,
        (intptr_t) a
    );
}

#if _LEAVE_GNUC_SWP1
}
#endif

#if _ENTER_GNUC_SWPA
{
#endif

INLINE( _Bool, BOOL_SWPA)  (_Bool b,  _Bool volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE( uchar, UCHAR_SWPA)  (uchar b,  uchar volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE( schar, SCHAR_SWPA)  (schar b,  schar volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(  char,  CHAR_SWPA)   (char b,   char volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(ushort, USHRT_SWPA) (ushort b, ushort volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE( short,  SHRT_SWPA)  (short b,  short volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(  uint,  UINT_SWPA)   (uint b,   uint volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(   int,   INT_SWPA)    (int b,    int volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE( ulong, ULONG_SWPA)  (ulong b,  ulong volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE(  long,  LONG_SWPA)   (long b,   long volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(ullong,ULLONG_SWPA) (ullong b, ullong volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}

INLINE( llong, LLONG_SWPA)  (llong b,  llong volatile a[1])
{
    return  MY_ACQUIRE(exchange_n, a, b);
}


INLINE(void *,  ADDR_SWPA)
(
    void const *            a,
    void const *volatile    b[1]
)
{
    return (void *) MY_ACQUIRE(
        exchange_n,
        (intptr_t volatile *) b,
        (intptr_t) a
    );
}

#if _LEAVE_GNUC_SWPA
}
#endif

#if _ENTER_GNUC_SWPE
{
#endif


INLINE( _Bool, BOOL_SWPE)  (_Bool b,  _Bool volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE( uchar, UCHAR_SWPE)  (uchar b,  uchar volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE( schar, SCHAR_SWPE)  (schar b,  schar volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(  char,  CHAR_SWPE)   (char b,   char volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(ushort, USHRT_SWPE) (ushort b, ushort volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE( short,  SHRT_SWPE)  (short b,  short volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(  uint,  UINT_SWPE)   (uint b,   uint volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(   int,   INT_SWPE)    (int b,    int volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE( ulong, ULONG_SWPE)  (ulong b,  ulong volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE(  long,  LONG_SWPE)   (long b,   long volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(ullong,ULLONG_SWPE) (ullong b, ullong volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}

INLINE( llong, LLONG_SWPE)  (llong b,  llong volatile a[1])
{
    return  MY_RELEASE(exchange_n, a, b);
}


INLINE(void *,                ADDR_SWPE)
(
    void const *            a,
    void const *volatile    b[1]
)
{
    return (void *) MY_RELEASE(
        exchange_n,
        (intptr_t volatile *) b,
        (intptr_t) a
    );
}

#if _LEAVE_GNUC_SWPE
}
#endif

#if _ENTER_GNUC_SWPT
{
#endif


INLINE( _Bool, BOOL_SWPT)  (_Bool b,  _Bool volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE( uchar, UCHAR_SWPT)  (uchar b,  uchar volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE( schar, SCHAR_SWPT)  (schar b,  schar volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(  char,  CHAR_SWPT)   (char b,   char volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE(ushort, USHRT_SWPT) (ushort b, ushort volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE( short,  SHRT_SWPT)  (short b,  short volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE(  uint,  UINT_SWPT)   (uint b,   uint volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(   int,   INT_SWPT)    (int b,    int volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE( ulong, ULONG_SWPT)  (ulong b,  ulong volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(  long,  LONG_SWPT)   (long b,   long volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}


INLINE(ullong,ULLONG_SWPT) (ullong b, ullong volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE( llong, LLONG_SWPT)  (llong b,  llong volatile a[1])
{
    return  MY_SEQ_CST(exchange_n, a, b);
}

INLINE(void *,                ADDR_SWPT)
(
    void const *            a,
    void const *volatile    b[1]
)
{
    return (void *) MY_SEQ_CST(
        exchange_n,
        (intptr_t volatile *) b,
        (intptr_t) a
    );
}

#if _LEAVE_GNUC_SWPT
}
#endif

INLINE(uchar, UCHAR_XEQ1) (uchar c, uchar volatile a[1], uchar b);
INLINE(uchar, UCHAR_XEQA) (uchar c, uchar volatile a[1], uchar b);
INLINE(uchar, UCHAR_XEQE) (uchar c, uchar volatile a[1], uchar b);
INLINE(uchar, UCHAR_XEQT) (uchar c, uchar volatile a[1], uchar b);

#if _ENTER_GNUC_XEQ1
{
#endif

INLINE( _Bool,  BOOL_XEQ1)  (_Bool c,  _Bool volatile a[1],  _Bool b)
{
    union my_bool_xeq1 {uchar B; _Bool Y;};
    return (
        (union my_bool_xeq1)
        {
            UCHAR_XEQ1(
                (union my_bool_xeq1){.Y=c}.B,
                (uchar volatile *) a,
                (union my_bool_xeq1){.Y=b}.B
            )
        }
    ).Y;
}


INLINE( uchar, UCHAR_XEQ1)  (uchar c,  uchar volatile a[1],  uchar b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( schar, SCHAR_XEQ1)  (schar c,  schar volatile a[1],  schar b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  char,  CHAR_XEQ1)   (char c,   char volatile a[1],   char b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ushort, USHRT_XEQ1) (ushort c, ushort volatile a[1], ushort b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( short,  SHRT_XEQ1)  (short c,  short volatile a[1],  short b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(  uint,  UINT_XEQ1)   (uint c,   uint volatile a[1],   uint b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(   int,   INT_XEQ1)    (int c,    int volatile a[1],    int b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE( ulong, ULONG_XEQ1)  (ulong c,  ulong volatile a[1],  ulong b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  long,  LONG_XEQ1)   (long c,   long volatile a[1],   long b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ullong,ULLONG_XEQ1) (ullong c, ullong volatile a[1], ullong b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( llong, LLONG_XEQ1)  (llong c,  llong volatile a[1],  llong b)
{
    return  MY_RELAXED(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(void *,  ADDR_XEQ1)
(
    void const *c,
    void const *volatile a[1],
    void const *b
)
{
    return (void *)
#if   INTPTR_REPR == INT_REPR
        INT_XEQ1(  (intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQ1((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQ1((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQ1
}
#endif

#if _ENTER_GNUC_XEQA
{
#endif

INLINE( _Bool,  BOOL_XEQA)  (_Bool c,  _Bool volatile a[1],  _Bool b)
{
    union my_bool_xeqa {uchar B; _Bool Y;};
    return (
        (union my_bool_xeqa)
        {
            UCHAR_XEQA(
                (union my_bool_xeqa){.Y=c}.B,
                (uchar volatile *) a,
                (union my_bool_xeqa){.Y=b}.B
            )
        }
    ).Y;
}


INLINE( uchar, UCHAR_XEQA)  (uchar c,  uchar volatile a[1],  uchar b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( schar, SCHAR_XEQA)  (schar c,  schar volatile a[1],  schar b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  char,  CHAR_XEQA)   (char c,   char volatile a[1],   char b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ushort, USHRT_XEQA) (ushort c, ushort volatile a[1], ushort b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( short,  SHRT_XEQA)  (short c,  short volatile a[1],  short b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(  uint,  UINT_XEQA)   (uint c,   uint volatile a[1],   uint b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(   int,   INT_XEQA)    (int c,    int volatile a[1],    int b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE( ulong, ULONG_XEQA)  (ulong c,  ulong volatile a[1],  ulong b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  long,  LONG_XEQA)   (long c,   long volatile a[1],   long b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ullong,ULLONG_XEQA) (ullong c, ullong volatile a[1], ullong b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( llong, LLONG_XEQA)  (llong c,  llong volatile a[1],  llong b)
{
    return  MY_ACQUIRE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(void *,  ADDR_XEQA)
(
    void const *c,
    void const *volatile a[1],
    void const *b
)
{
    return (void *)
#if   INTPTR_REPR == INT_REPR
        INT_XEQA(  (intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQA((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQA((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQA
}
#endif

#if _ENTER_GNUC_XEQE
{
#endif

INLINE( _Bool,  BOOL_XEQE)  (_Bool c,  _Bool volatile a[1],  _Bool b)
{
    union my_bool_xeqe {uchar B; _Bool Y;};
    return (
        (union my_bool_xeqe)
        {
            UCHAR_XEQE(
                (union my_bool_xeqe){.Y=c}.B,
                (uchar volatile *) a,
                (union my_bool_xeqe){.Y=b}.B
            )
        }
    ).Y;
}


INLINE( uchar, UCHAR_XEQE)  (uchar c,  uchar volatile a[1],  uchar b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( schar, SCHAR_XEQE)  (schar c,  schar volatile a[1],  schar b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  char,  CHAR_XEQE)   (char c,   char volatile a[1],   char b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ushort, USHRT_XEQE) (ushort c, ushort volatile a[1], ushort b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( short,  SHRT_XEQE)  (short c,  short volatile a[1],  short b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(  uint,  UINT_XEQE)   (uint c,   uint volatile a[1],   uint b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(   int,   INT_XEQE)    (int c,    int volatile a[1],    int b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( ulong, ULONG_XEQE)  (ulong c,  ulong volatile a[1],  ulong b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE(  long,  LONG_XEQE)   (long c,   long volatile a[1],   long b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(ullong,ULLONG_XEQE) (ullong c, ullong volatile a[1], ullong b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}

INLINE( llong, LLONG_XEQE)  (llong c,  llong volatile a[1],  llong b)
{
    return  MY_RELEASE(compare_exchange_n, a, &b, c, 0, __ATOMIC_RELAXED), b;
}


INLINE(void *,  ADDR_XEQE)
(
    void const *c,
    void const *volatile a[1],
    void const *b
)
{
    return (void *)
#if   INTPTR_REPR == INT_REPR
        INT_XEQE(  (intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQE((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQE((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQE
}
#endif

#if _ENTER_GNUC_XEQT
{
#endif

INLINE( _Bool,  BOOL_XEQT)  (_Bool c,  _Bool volatile a[1],  _Bool b)
{
    union my_bool_xeqt {uchar B; _Bool Y;};
    return (
        (union my_bool_xeqt)
        {
            UCHAR_XEQT(
                (union my_bool_xeqt){.Y=c}.B,
                (uchar volatile *) a,
                (union my_bool_xeqt){.Y=b}.B
            )
        }
    ).Y;
}


INLINE( uchar, UCHAR_XEQT)  (uchar c,  uchar volatile a[1],  uchar b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE( schar, SCHAR_XEQT)  (schar c,  schar volatile a[1],  schar b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(  char,  CHAR_XEQT)   (char c,   char volatile a[1],   char b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(ushort, USHRT_XEQT) (ushort c, ushort volatile a[1], ushort b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE( short,  SHRT_XEQT)  (short c,  short volatile a[1],  short b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(  uint,  UINT_XEQT)   (uint c,   uint volatile a[1],   uint b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(   int,   INT_XEQT)    (int c,    int volatile a[1],    int b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE( ulong, ULONG_XEQT)  (ulong c,  ulong volatile a[1],  ulong b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE(  long,  LONG_XEQT)   (long c,   long volatile a[1],   long b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(ullong,ULLONG_XEQT) (ullong c, ullong volatile a[1], ullong b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}

INLINE( llong, LLONG_XEQT)  (llong c,  llong volatile a[1],  llong b)
{
    return  MY_SEQ_CST(compare_exchange_n, a, &b, c, 0, __ATOMIC_SEQ_CST), b;
}


INLINE(void *,                ADDR_XEQT)
(
    void const *c,
    void const *volatile a[1],
    void const *b
)
{
    return (void *)
#if   INTPTR_REPR == INT_REPR
        INT_XEQT(  (intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LONG_REPR
        LONG_XEQT((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#elif INTPTR_REPR == LLONG_REPR
        LLONG_XEQT((intptr_t) c, (intptr_t volatile *) a, (intptr_t) b);
#else
#   error "INTPTR_REPR"
#endif

}

#if _LEAVE_GNUC_XEQT
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


#if defined(SPC_ARM_NEON) || defined(SPC_X86_SSE2)
#endif

#if defined(SPC_ARM_NEON)

#elif defined(SPC_X86_SSE2)

INLINE(Vdbu,VDBU_STRD) (Vdbu src, uint8_t volatile dst[8])
{
#define     VDBU_STRD   VDBU_STRD
    return (((DWRD_TYPE *) dst)->F=VDBU_ASTM(src)), src;
}

INLINE(Vdbi,VDBI_STRD) (Vdbi src,  int8_t volatile dst[8])
{
#define     VDBI_STRD   VDBI_STRD
    return (((DWRD_TYPE *) dst)->F=VDBI_ASTM(src)), src;
}

INLINE(Vdbc,VDBC_STRD) (Vdbc src,    char volatile dst[8])
{
#define     VDBC_STRD   VDBC_STRD
    return (((DWRD_TYPE *) dst)->F=VDBC_ASTM(src)), src;
}


INLINE(Vdhu,VDHU_STRD) (Vdhu src, uint16_t volatile dst[4])
{
#define     VDHU_STRD   VDHU_STRD
    return (((DWRD_TYPE *) dst)->F=VDHU_ASTM(src)), src;
}

INLINE(Vdhi,VDHI_STRD) (Vdhi src, int16_t volatile dst[4])
{
#define     VDHI_STRD   VDHI_STRD
    return (((DWRD_TYPE *) dst)->F=VDHI_ASTM(src)), src;
}

INLINE(Vdhf,VDHF_STRD) (Vdhf src, flt16_t volatile dst[4])
{
#define     VDHF_STRD   VDHF_STRD
    return (((DWRD_TYPE *) dst)->F=VDHF_ASTM(src)), src;
}


INLINE(Vdwu,VDWU_STRD) (Vdwu src, uint32_t volatile dst[2])
{
#define     VDWU_STRD   VDWU_STRD
    return (((DWRD_TYPE *) dst)->F=VDWU_ASTM(src)), src;
}

INLINE(Vdwi,VDWI_STRD) (Vdwi src, int32_t volatile dst[2])
{
#define     VDWI_STRD   VDWI_STRD
    return (((DWRD_TYPE *) dst)->F=VDWU_ASTM(src)), src;
    return (((DWRD_TYPE *) dst)->F=src.V0), src;
}

INLINE(Vdwf,VDWF_STRD) (Vdwf src, float volatile dst[2])
{
#define     VDWF_STRD   VDWF_STRD
    return (((DWRD_TYPE *) dst)->F=src.V0), src;
}


INLINE(Vddu,VDDU_STRD) (Vddu src, uint64_t volatile dst[1])
{
#define     VDDU_STRD   VDDU_STRD
    return (((DWRD_TYPE *) dst)->F=src.V0), src;
}

INLINE(Vddi,VDDI_STRD) (Vddi src, int64_t volatile dst[1])
{
#define     VDDI_STRD   VDDI_STRD
    return (((DWRD_TYPE *) dst)->F=src.V0), src;
}

INLINE(Vddf,VDDF_STRD) (Vddf src, double volatile dst[1])
{
#define     VDDF_STRD   VDDF_STRD
    return (((DWRD_TYPE *) dst)->F=src.V0), src;
}

#else

#endif



#if defined(SPC_ARM_NEON)

#elif defined(SPC_X86_SSE2)

INLINE(Vqbc,VQBC_STRQ) (Vqbc src, char volatile dst[16])
{
#   define  VQBC_STRQ   VQBC_STRQ
    _mm_store_si128((void *)dst, src.V0;
    return  src;
}

INLINE(Vqbu,VQBU_STRQ) (Vqbu src, uint8_t volatile dst[16])
{
#   define  VQBU_STRQ   VQBU_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqbi,VQBI_STRQ) (Vqbi src, int8_t volatile dst[16])
{
#   define  VQBI_STRQ   VQBI_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqhu,VQHU_STRQ) (Vqhu src, uint16_t volatile dst[8])
{
#   define VQHU_STRQ   VQHU_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqhi,VQHI_STRQ) (Vqhi src, int16_t volatile dst[8])
{
#   define  VQHI_STRQ   VQHI_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqhf,VQHF_STRQ) (Vqhf src, flt16_t volatile dst[8])
{
#   define  VQHF_STRQ   VQHF_STRQ
#   if defined(SPC_X86_AVX512FP16)
    _mm_store_ph((void *) dst, src);
#   else
    _mm_store_si128((void *) dst, src.V0);
#   endif
    return  src;
}

INLINE(Vqwu,VQWU_STRQ) (Vqwu src, uint32_t volatile dst[4])
{
#   define  VQWU_STRQ   VQWU_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqwi,VQWI_STRQ) (Vqwi src, int32_t volatile dst[4])
{
#   define  VQWI_STRQ   VQWI_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqwf,VQWF_STRQ) (Vqwf src, float volatile dst[4])
{
#   define  VQWF_STRQ   VQWF_STRQ
    _mm_store_ps((void *) dst, src);
    return  src;
}

INLINE(Vqdu,VQDU_STRQ) (Vqdu src, uint64_t volatile dst[2])
{
#   define  VQDU_STRQ   VQDU_STRQ
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqdi,VQDI_STRQ) (Vqdi src, int64_t volatile dst[2])
{
#   define  VQDI_STRQ   VQDI_STRQ
    vst1q_s64((void *) dst, src);
    _mm_store_si128((void *) dst, src.V0);
    return  src;
}

INLINE(Vqdf,VQDF_STRQ) (Vqdf src, double volatile dst[2])
{
#   define  VQDF_STRQ   VQDF_STRQ
    _mm_store_pd((void *) dst, src);
    return  src;
}

#endif

#if _ENTER_EXTGOP_ARM_STR1
{
#endif


#if _LEAVE_EXTGOP_ARM_STR1
}
#endif
