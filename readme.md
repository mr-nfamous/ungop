# HISTORY

2024-04-20
* started adding notes
* added avgl to readme.md

2024-05-14
* added cvwv, cvdv, cvqv
* added mvwu, mvwi, mvwf
* added mvdu, mvdi, mvdf
* added mvqu, mvqi, mvqf
* Use mv**(x) to reinterpret scalars as vectors and viceversa

* added cplw, cpld, cplq
* added cprw, cprd, cprq
* added cpmw, cpmd, cpmq

# ABOUT

Perhaps this isn't self explanatory after all... To use, save
a copy of all of the ".h" files in the top level include
directory of your project. Then, put:

    #include "ungop.h"
    
somewhere, preferably at the top, of each translation unit.

This will automatically include several standard library 
headers and detect the target architecture based on whatever
well known feature test macros are available. Once we know
the target and what supplementary processor features are
available, one or more of the target specific headers will be 
included. E.g. arm's intrinsics are defined in <arm_acle.h>
and <arm_neon.h> while x86 has <immintrin.h> and the dozens 
of extension specific headers it implicitly includes.


ungop - pronounced "ungop" - is the name of an abstract
complex instruction set architecture specification, which
includes a reference C implementation for a suite of macros
and functions that give users the means to take advantage of
modern processor features, most importantly direct access to
vector/SIMD instructions and standardized types.

The most important consideration when designing a low level
interface is namespace compatibility with existing libraries.
We guarantee no name conflicts with any of the following:

*   C11 including any symbols defined in its standard annexes;
*   any version of POSIX/XSI;
*   Microsoft's "Win32 API" or own C library (msvcrt);
*   Google's C library "bionic"
*   "glibc"
*   Apple's standard library

Names also shouldn't be English words that may conflict with
commonly used variable names. Finally, we try not to trigger
reasonably designed profanity filters.

There are two possible ways these requirements can be met.
The first, which was chosen by the C standard committees is
obfuscation by encumbrance. E.g.

    atomic_compare_exchange_strong
    stdc_trailing_zeros

The other, chosen by us, is to obfuscate by algorithm. That
is, all ungop instruction names follow exactly the same
pattern, without exception. Specifically, each name begins
with a three ASCII letter prefix, followed by a single letter
variant modifier. Most instructions also have type specific 
variants, which are named by appending an algorithmically
derived suffix to the base name, but more on that later.

Compare the following ungop instructions with the equivalent
C2x standard library function names:

    xeqt = atomic_compare_exchange_strong
    cszr = stdc_trailing_zeros

Reusing 'cszr' to illustrate:

    * 'csz' -> "Count Sequential Zeros"
    * 'r'   -> rtl, aka right to left, aka high to low

Great care went into ensuring consistency of the variant
modifer letters. The following table shows which letters
are used and how:

    '1':

        *   atomic with C11 'memory_order_relaxed' semantics
        *   Literally '1', as in 'cnt1', which counts the
            number of '1' digits of each operand element
        *   Limit SIMD op to specific lane

    '2':
        *   result width is half or double operand width

    'a':
        *   atomic with C11 'memory_order_acquire' semantics
        *   7 bit / ASCII
        *   Base85

    'b':
        *   8 bit / 1 byte

    'c':
        *   char

    'd':
        *   64 bit / 8 byte
        *   Decimal, i.e. base 10

    'e':
        *   atomic with C11 'memory_order_release' semantics

    'f':
        *   Floating point

    'g' (unused)

    'h':
        *   16 bit / 2 byte

    'i':
        *   signed integer

    'j' (unused)

    'k' (unused)

    'l':
        *   Lower / leftmost / lsb
        *   Truncated
        *   Lil endian

    'm':
        *   Multiple parameters

    'n':
         *  Native endian

    'o':
        *   256 bit / 32 byte
        *   Octal, i.e. base 8

    'p':
        *   Pair/two

    'q':
        *   128 bit / 16 byte

    'r':
        *   Upper/rightmost/msb
        *   Big/network endian

    's':
        *   512 bit / 64 byte
        *   All/saturated
        *   Sign bits / 1 digits

    't':
        *   C11 'memory_order_seq_cst' semantics

    'u':
        *   Unsigned integer
        *   Hexdecimal, i.e. base 16 using uppercase alpha

    'v':
        *   Vector

    'w':
        *   32 bit / 4 byte

    'x':
        *   Hexdecimal, i.e. base 16 using lowercase alpha

    'y':
        *   1 bit/bool
        *   Binary, i.e. base 2

    'z':
        *   Integer
        *   Unsigned saturated
        *   Zero digits


In the C reference implementation, _Generic facilitates the
usage of the base instructions in user code. Unfortunately,
it has some rather severe limitations, so we are stating up
front that we recommend using the type specific forms of
operations from the getgo.

Anyway, it works by choosing the type specific operation
name based on the first operand. As briefly mentioned before,
the type specific name is algorithmically determined using
a very easy to memorize system. The following table lists
the ~57 C types for which operations may be available in the
reference implementation and their type specific suffix:

## Arithmetic types

    suffix ewidth   C type

    yu      1       bool

    bu      8       uint8_t
    bi      8       int8_t
    bc      8       char

    hu      16      uint16_t
    hi      16      int16_t
    hf      16      flt16_t [†]

    wu      32      uint32_t
    wi      32      int32_t
    wf      32      float 

    du      64      uint64_t
    di      64      int64_t
    df      64      double

    qu      128     QUAD_UTYPE [‡]
    qi      128     QUAD_ITYPE [‡]
    qf      128     QUAD_FTYPE [‡]

    lu      32|64   ulong or ullong [‡‡]
    li      32|64   long or llong [‡‡]


## 32 bit SIMD vector types

    suffix  ewidth  C type

    wyu     1       Vwyu (32 × bool)

    wbu     8       Vwbu (4 × uint8_t)
    wbi     8       Vwbi (4 × int8_t)
    wbc     8       Vwbc (4 × char)

    whu     16      Vwhu (2 × uint16_t)
    whi     16      Vwhi (2 × int16_t)
    whf     16      Vwhf (2 × flt16_t)

    wwu     32      Vwwu (1 × uint32_t)
    wwi     32      Vwwi (1 × int32_t)
    wwf     32      Vwwf (1 × float)


## 64 bit SIMD vector types (13)

    suffix  ewidth  C type

    dyu     1       Vdyu (64 × bool)

    dbu     8       Vdbu (8 × uint8_t)
    dbi     8       Vdbi (8 × int8_t)
    dbc     8       Vdbc (8 × char)

    dhu     16      Vdhu (4 × uint16_t)
    dhi     16      Vdhi (4 × int16_t)
    dhf     16      Vdhf (4 × flt16_t)

    dwu     32      Vdwu (2 × uint32_t)
    dwi     32      Vdwi (2 × int32_t)
    dwf     32      Vdwf (2 × float)

    ddu     64      Vddu (1 × uint64_t)
    ddi     64      Vddi (1 × int64_t)
    ddf     64      Vddf (1 × double)


## 128 bit SIMD vector types (16)

    suffix  ewidth  C type

    qyu     1       Vqyu (128 × bool)

    qbu     8       Vqbu (16 × uint8_t)
    qbi     8       Vqbi (16 × int8_t)
    qbc     8       Vqbc (16 × char)

    qhu     16      Vqhu (8 × uint16_t)
    qhi     16      Vqhi (8 × int16_t)
    qhf     16      Vqhf (8 × flt16_t)

    qwu     32      Vqwu (4 × uint32_t)
    qwi     32      Vqwi (4 × int32_t)
    qwf     32      Vqwf (4 × float)

    qdu     64      Vqdu (2 × uint64_t)
    qdi     64      Vqdi (2 × int64_t)
    qdf     64      Vqdf (2 × double)

    qqu     128     Vqqu (1 × QUAD_UTYPE) ‡‡‡
    qqi     128     Vqqi (1 × QUAD_ITYPE) ‡‡‡
    qqf     128     Vqqf (1 × QUAD_FTYPE) ‡‡‡

    † flt16_t is defined as a half precision IEEE 754 float.
    If the target ABI has a dedicated C type, that's what
    it will be a typedef of. E.g. arm's __fp16 or when the
    AVX-512FP16 x86 extension is supported, _Float16.
    Otherwise, flt16_t will be a unique, single element
    homogeneous 16 bit unsigned integer aggregate type.

    ‡ 128 bit operations are provisionally available via the
    QUAD_UTYPE, QUAD_ITYPE, and QUAD_FTYPE types.

    ‡‡ Hosted 64 bit C implementations will have either a 32
    bit int AND long or 64 bit long AND llong. The 'lu' and
    'li' suffixes are reserved in the former for long and in
    the latter for llong. This allows values of these types
    to be compatible with the generic operation. However, be
    aware that unless explicitly stated, when an operation
    results in a value of a different size, its type is
    always the lowest ranked type with that width. E.g. if
    long and llong are both 64 bit, the return type of
    add2wi is long since it has lower rank than llong.
    When the result width doesn't change, the return type is
    always identical unless otherwise specified. E.g. xorslu
    on the same LP64 based target returns a ullong.

    ‡‡‡ The 128 bit numeric types presently have no SIMD
    vector implementations.


The arithmetic types can be, and are, grouped by the generic
machinery into sets:

    *u      unsigned integers
    *i      signed integers
    *f      floats
    *z      any integer                 (Z like the symbol)
    *n      unsigned ints AND floats    (N as in natural)
    *s      signed ints AND floats      (S as in signed)
    *r      real numbers                (R like the symbol)

Note that on implementations with signed char, char ops are
always available when int8_t ops are and vice versa for 
unsigned char and uint8_t. This is to accommodate MSVC, 
which incorrectly fails to consider all 3 char types as 
unique for _Generic.

Some operations take a memory address as the first operator.
In this case, the type suffix is simply prefixed by "ac"
when the memory is read-only ("address of constant") and
"a" otherwise. The following (redundant) table contains the
suffixes for all one dimensional C pointer types:

    a       void *
    ayu     bool *
    abu     uint8_t *
    abi     int8_t *
    abc     char *
    ahu     uint16_t *
    ahi     int16_t *
    ahf     flt16_t *
    awu     uint32_t *
    awi     int32_t *
    awf     float *
    adu     uint64_t *
    adi     int64_t *
    adf     double *
    aqu     QUAD_UTYPE *
    aqi     QUAD_ITYPE *
    aqf     QUAD_FTYPE *
    alu     ulong * or ullong *
    ali     long * or llong *

    ac      void const *
    acyu    bool const *
    acbu    uint8_t const *
    acbi    int8_t const *
    acbc    char const *
    achu    uint16_t const *
    achi    int16_t const *
    achf    flt16_t const *
    acwu    uint32_t const *
    acwi    int32_t const *
    acwf    float const *
    acdu    uint64_t const *
    acdi    int64_t const *
    acdf    double const *
    acqu    QUAD_UTYPE const *
    acqi    QUAD_ITYPE const *
    acqf    QUAD_FTYPE const *
    aclu    ulong const * or ullong const *
    acli    long const * or llong const *

NOTE: ungop has no concept of a "pointer to a SIMD vector".
Users of the reference C implementation should consider all
SIMD vector values as inherently having the `register`
storage class. An early build actually used the keyword in
th3 vector operation signatures but unfortunately, GCC
intrinsics don't work with register qualified vectors. We
therefore *_STRONGLY_* advise avoiding `register`.

Here's some examples for the readme that break down the
combination of prefix+variant+typemod:

```C

INLINE(uint16_t,cszrhu) (uint16_t src);
/*  [csz]   Count Sequential Zeros
    [r]     from hi/msb to lo/lsb, i.e. "leading" bits
    [hu]    uint16_t operand
*/

INLINE(char *,strdabc) (char dst[8], Vdbc src);
/*  [str]   STore Register
    [d]     source is 64 bit vector
    [abc]   char * operand
*/

INLINE(Vqwf,dupqacwf) (float const *src);
/*  [dup]   DUPlicate
    [q]     quadword (128 bit) result
    [acwf]  float const * operand
*/

INLINE(Vwbi,dupwqbi) (Vqbi src, Rc(0,15) k)
*   dup
*   w   - word (32 bit) result
+   wbi - Vwbi (4×char) operand
```

Pointers to `volatile` qualified values will almost
certainly not work with the generic operations and we
strongly recommend users avoid its usage in new code.

# SIMD

While each architecture implements SIMD in its own way,
there are more than enough similarities to standardize it.
Vector values are represented by 32, 64, or 128 contiguous
bits packed into 4, 8, or 16 contiguous bytes, respectively.
This string of bits is then split into one or more 1, 8, 16,
32, or 64 bit numbered "lanes". The number of lanes is based
on the vector width divided by the element width. There are
never any padding bits between vector elements.

Like arrays, the type of value stored in a lane is known as
the vector's element type. On architectures with a little
endian vector representation, which are the only targets we
presently support, the vector lane number and array index
of a particular multibit element will be equivalent, while
on architectures with a big endian vector representation,
the lowest lane will have the highest index. Boolean vector
lanes are numbered according to the bits position and are
thus the same on all platforms.

The following figures illustrate the relationship between
"vector lane" and "array index" of a particular element for
multibit types. For multibyte types, the lane's number label
is found at the same position as its least significant byte:

    Ltt = little endian
    Btt = big endian
    idx = C bytearray index

    Lwb: B0 B1 B2 B3
    Lwh: H0___ H1___
    Lww: W0_________
          |  |  |  |
    idx:  0  1  2  3
          |  |  |  |
    Bww: _________W0
    Bwh: ___H1 ___H0
    Bwb: B3 B2 B1 B0


    Ldb: B0 B1 B2 B3 B4 B5 B6 B7
    Ldh: H0___ H1___ H2___ H3___
    Ldw: W0_________ W1_________
    Ldd: D0_____________________
          |  |  |  |  |  |  |  |
    idx:  0  1  2  3  4  5  6  7
          |  |  |  |  |  |  |  |
    Bdd: _____________________D0
    Bdw: _________W1 _________W0
    Bdh: ___H3 ___H2 ___H1 ___H0
    Bdb: B7 B6 B5 B4 B3 B2 B1 B0


    Lqb: B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 Ba Bb Bc Bd Be Bf
    Lqh: H0___ H1___ H2___ H3___ H4___ H5___ H6___ H7___
    Lqw: W0_________ W0_________ W0_________ W0_________
    Lqd: D0_____________________ D1_____________________
    Lqq: Q0_____________________________________________
          |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    idx:  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
          |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    Bqq: _____________________________________________Q0
    Bqd: _____________________D1 _____________________D0
    Bqw: _________W3 _________W2 _________W1 _________W0
    Bqh: ___H7 ___H6 ___H5 ___H4 ___H3 ___H2 ___H1 ___H0
    Bqb: Bf Be Bd Bc Bb Ba B9 B8 B7 B6 B5 B4 B3 B2 B1 B0


# INDEX

Finally, the following is a complete instruction listing,
including a brief description. For more details, see the
comments in the op's section in ungop.h

Key:

    TRUNCATE(x) of a N bit integer means the operation has 
    an intermediate result that's greater than N bits but 
    only the least significant N bits are kept. For example, 
    mullbu, at least semantically, generates a 16 bit 
    product from two 8 bit unsigned ints but discards the
    most significant 8 bits.

    KEEPHIGH is like TRUNCATE except it's the upper half
    that's kept

    SATURATE(x) means if the intermediate result is greater
    than the result type's maximum, the result is the max
    and vice versa for the minimum. E.g. addsbi(127,127)
    returns 127 since 127+127=254 and 254 is greater than
    INT8_MAX. Likewise, addsbi(-127,-127) returns -128,
    since -127+-127 is -254, which is less than INT8_MIN.

    WIDENED(x) means the result is twice as large as x

    UNSIGNED(x) means the result is an unsigned int of 
    equal width as x 

    SIGNED(x) means the result is an signed int of equal 
    width as x 

    FLOATING(x) means the result is a float of equal width
    as x 

    Square brackets are a slice notation subdividing the
    binary representation. 

        bits[START:STOP]

    Thus, bits[1:13] means a sequence of bits starting at 
    bit 1 and ending with 12, since perhaps confusingly, 
    STOP is exclusive. Put another way, bitswu[1:13] is 
    semantically identical to
    
        (bitswu>>1)&unoswu((12-1))
    
    and also
    
        bfg1wu(bitswu, 1, (12-1))
    

### •***· «unprefixed/misc»

    •void      => the zero constant (not a callable)
    •pass()    => forfeit calling thread's CPU time
    •sign(s)   => extract sign bit of signed
    •expo(f)   => extract exponent of float
    •mant(f)   => extract mantissa of float

### •abs· «ABSolute value»

    •absl(x) => TRUNCATE(|x|)
    •abss(x) => SATURATE(|x|)
    •absu(x) => UNSIGNED(|x|)
    •absh(x) => (flt16_t) |x|
    •absw(x) => (float) |x|
    •absd(x) => (double) |x|


### •add· «ADDition»

    •addl(a,b) => TRUNCATE(a+b)
    •adds(a,b) => SATURATE(a+b)
    •add2(a,b) => WIDENED(a)+b
    •addh(a,b) => (flt16_t) a+b
    •addw(a,b) => (float) a+b
    •addd(a,b) => (double) a+b
    •add1(...) => atomic add w/ memory_order_relaxed
    •adda(...) => atomic add w/ memory_order_acquire
    •adde(...) => atomic add w/ memory_order_release
    •addt(...) => atomic add w/ memory_order_seq_cst

### •and· «bitwise AND»

    •ands(a,b) => a AND b
    •andn(a,b) => a AND NOT b
    •andv(a)   => REDUCE(ands, a)
    •and1(...) => atomic and w/ memory_order_relaxed
    •anda(...) => atomic and w/ memory_order_acquire
    •ande(...) => atomic and w/ memory_order_release
    •andt(...) => atomic and w/ memory_order_seq_cst

### •asb· «reinterpret cASt Byte»

    •asbu(a) => ((BYTE_TYPE){a}).U
    •asbi(a) => ((BYTE_TYPE){a}).I
    •asbc(a) => ((BYTE_TYPE){a}).F

### •asd· «reinterpret cASt Doubleword»

    •asdu(a) => ((DWRD_TYPE){a}).U
    •asdi(a) => ((DWRD_TYPE){a}).I
    •asdf(a) => ((DWRD_TYPE){a}).F

### •ash· «reinterpret cASt Halfword»

    •ashu(a) => ((HALF_TYPE){a}).U
    •ashi(a) => ((HALF_TYPE){a}).I
    •ashf(a) => ((HALF_TYPE){a}).F

### •asq· «reinterpret cASt Quadword»

    •asqu(a) => ((QUAD_TYPE){a}).U
    •asqi(a) => ((QUAD_TYPE){a}).I
    •asqf(a) => ((QUAD_TYPE){a}).F

### •ast· «reinterpret cASt (generic)»

    •astm(a) => as machine
    •astv(a) => as virtual
    •astu(a) => ((STG_TYPE(a)){a}).U
    •asti(a) => ((STG_TYPE(a)){a}).I
    •astf(a) => ((STG_TYPE(a)){a}).F

### •asy· «reinterpret cASt (boolean)»

    •asyu(a) => only applies to vectors

### •asw· «reinterpret cASt Word»

    •aswu(a) => ((WORD_TYPE){a}).U
    •aswi(a) => ((WORD_TYPE){a}).I
    •aswf(a) => ((WORD_TYPE){a}).F

### •avg· «AVeraGe»

    •avgl(a, b) => truncating
    •avgp(a, b) => ceiling
    •avgn(a, b) => flooring
    
### •bfg· «BitField Get»

    •bfgl(a, b, c) => (a[b:c])

### •bfs· «BitField Set»

    •bfsl(a, b, c, d) => (a[b:c] = d)

### •bln· «BLeNd»

    •blnm(a, b, ...c) => {b[i] if c[i] else a[i] for ...}

### •cat· «conCATenation»

    •catl(l, r) => l ## r


### •tst· «Test Set biTs»

    •tsts(a, b) => ((a&b) != 0) ? -1 : 0
    •tsty(a, b) => ((a&b) != 0) ? +1 : 0


### •ceq· «Compare EQual»

    •ceqs(a, b) => a == b ? -1 : 0
    •ceql(a, b) => a == b ? +1 : 0
    •ceqy(a, b) => a == b

### •cne· «Compare Not Equal»

    •cnes(a, b) => a != b ? -1 : 0
    •cnel(a, b) => a != b ? +1 : 0
    •cney(a, b) => a != b

### •clt· «Compare Less Than»

    •clts(a, b) => a < b ? -1 : 0
    •cltl(a, b) => a < b ? +1 : 0
    •cltr(a, b) => a < b ?  b : a (unstable max)
    •clty(a, b) => a < b

### •cle· «Compare Less than or Equal»

    •cles(a, b) => a <= b ? -1 : 0
    •clel(a, b) => a <= b ? +1 : 0
    •cley(a, b) => a <= b

### •cgt· «Compare Greater Than»

    •cgts(a, b) => a > b ? -1 : 0
    •cgtl(a, b) => a > b ? +1 : 0
    •cgtr(a, b) => a < b ?  b : a (unstable min)
    •cgty(a, b) => a > b

### •cge· «Compare Greater than or Equal»

    •cges(a, b) => a >= b ? -1 : 0
    •cgel(a, b) => a >= b ? +1 : 0
    •cgey(a, b) => a >= b

### •cnb· «Compare Not Between»

    •cnbs(a, l, r) => (l <= a) && (a <= r) ? -1 : 0
    •cnbl(a, l, r) => (l <= a) && (a <= r) ? +1 : 0
    •cnby(a, l, r) => (l <= a) && (a <= r)

### •cmb· «Compiler Memory Barrier»

    •cmba() => atomic_signal_fence(memory_order_acquire)
    •cmbe() => atomic_signal_fence(memory_order_release)
    •cmbt() => atomic_signal_fence(memory_order_seq_cst)

### •cnt· «CouNt Total»

    •cnt1(a) => count one digits (i.e. hamming weight)
    •cnts(a) => sequential repetitions of most sig bit

### •csz· «Count Sequential Zeros»

    •cszl(a) => least to most aka "trailing zeros"
    •cszr(a) => most to least aka "leading zeros"

### •cvy· «Convert to Bool»

    •cvyu(a) => 


### •cvb· «Convert to Byte»

    •cvbc(a) => TRUNCATE(   (char) a)
    •cvbu(a) => TRUNCATE((uint8_t) a)
    •cvbi(a) => TRUNCATE( (int8_t) a)
    •cvbz(a) => SATURATE((uint8_t) a)
    •cvbs(a) => SATURATE( (int8_t) a)

### •cvd· «Convert to Doubleword»

    •cvdu(a) => TRUNCATE((uint64_t) a)
    •cvdi(a) => TRUNCATE( (int64_t) a)
    •cvdz(a) => SATURATE((uint64_t) a)
    •cvds(a) => SATURATE( (int64_t) a)
    •cvdf(a) => (double) a

### •cvh· «Convert to Halfword»

    •cvhu(a) => TRUNCATE((uint16_t) a)
    •cvhi(a) => TRUNCATE( (int16_t) a)
    •cvhz(a) => SATURATE((uint16_t) a)
    •cvhs(a) => SATURATE( (int16_t) a)
    •cvhf(a) => (flt16_t) a

### •cvw· «Convert to Word»

    •cvwu(a) => TRUNCATE((uint32_t) a)
    •cvwi(a) => TRUNCATE( (int32_t) a)
    •cvwz(a) => SATURATE((uint32_t) a)
    •cvws(a) => SATURATE( (int32_t) a)
    •cvwf(a) => (float) a

### •cvq· «Convert to Quadword»

    •cvqu(a) => TRUNCATE((QUAD_UTYPE) a)
    •cvqi(a) => TRUNCATE((QUAD_ITYPE) a)
    •cvqz(a) => SATURATE((QUAD_UTYPE) a)
    •cvqs(a) => SATURATE((QUAD_ITYPE) a)
    •cvqf(a) => (QUAD_FTYPE) a

### •dcr· «DeCRement»

    •dcrl(a) => TRUNCATE(a+1)
    •dcr1(a) => add1(a, -1)
    •dcra(a) => adda(a, -1)
    •dcre(a) => adde(a, -1)
    •dcrt(a) => addt(a, -1)

### •dif· «absolute DIFference»

    •difu(a, b) => absu(|a-b|)

### •div· «DIVision»

    •divl(a, b) => truncating division
    •divn(a, b) => flooring division
    •div2(a, b) => narrowing int division

### •dup· «DUPlicate vector element»

    •dupw(a, b) => as 32 bit vector 
    •dupd(a, b) => as 64 bit vector
    •dupq(a, b) => as 128 bit vector

### •fam· «Fused Add Multiply»

    •faml(a, b, c) => TRUNCATE(a+b*c)
    •fam2(a, b, c) => a+NARROWED(b)*NARROWED(c)
    •famf(a, b, c) => FLOATING(a+b*c)

### •fsm· «Fused Subtract Multiply»

    •fsml(a, b, c) => TRUNCATE(a-b*c)
    •fsm2(a, b, c) => a+NARROWED(b)*NARROWED(c)
    •fsmf(a, b, c) => FLOATING(a+b*c)

### •get· «vector GET»

    •get1(a, b) => (a[b])
    •getl(b)    => (b.Lo)
    •getr(a)    => (b.Hi)

### •hmb· «Hardware Memory Barrier»

    •hmba() => atomic_thread_fence(memory_order_acquire)
    •hmbe() => atomic_thread_fence(memory_order_release)
    •hmbt() => atomic_thread_fence(memory_order_seq_cst)

### •icr· «InCRement»

    •icr1(a) => atomic_add_explicif(a, 1, memory_order_relaxed)
    •icra(a) => atomic_add_explicif(a, 1, memory_order_acquire)
    •icre(a) => atomic_add_explicif(a, 1, memory_order_release)
    •icrt(a) => atomic_add_explicif(a, 1, memory_order_seq_cst)
    •icrl(a) => TRUNCATE(a+1)

### •inv· «bitwise INVert»

    •invs(a) => NOT a
    •inv1(a) => atomic_xor_explicit(a,-1,memory_order_relaxed)
    •inva(a) => atomic_xor_explicit(a,-1,memory_order_acquire)
    •inve(a) => atomic_xor_explicit(a,-1,memory_order_release)
    •invt(a) => atomic_xor_explicit(a,-1,memory_order_seq_cst)

### •ldr· «LoaD aligned to Register»

    •ldrn(a)   => *a
    •ldrw(a)   => *a (a points to 32 bit vector)
    •ldrd(a)   => *a (a points to 64 bit vector)
    •ldrq(a)   => *a (a points to 128 bit vector)
    •ldr1(...) => atomic_load_explicit(...order_relaxed)
    •ldra(...) => atomic_load_explicit(...order_acquire)
    •ldrt(...) => atomic_load_explicit(...order_seq_cst)

### •lun· «LoaD Unaligned to register»

    •lunn(a)   => READ(a)
    •lunw(a)   => READ(a) (a points to 32 bit vector)
    •lund(a)   => READ(a) (a points to 64 bit vector)
    •lunq(a)   => READ(a) (a points to 128 bit vector)

### •max· «MAXimum»

    •maxv(v)    => REDUCE(maxl, v)

### •min· «MINimum»

    •minv(v)    => REDUCE(minl, v)

### •mod· «MODulus (division with remainder)»

    •modl(a, b, *r) => truncating
    •modn(a, b, *r) => flooring
    •mod2(a, b, *r) => narrowing

### •mul· «MULtiply»

    •mull(a, b) => TRUNCATE(a*b)
    •mulr(a, b) => KEEPHIGH(a*b)
    •muls(a, b) => SATURATE(a*b)
    •mul2(a, b) => WIDENED(a)*b
    •mulh(a, b) => (flt16_t) a*b
    •mulw(a, b) => (float) a*b
    •muld(a, b) => (double) a*b

### •mvw· «MoVe Word»

    •mvwl(x) => to/from lo

### •mvd· «MoVe Doubleword»

    •mvdl(x) => to/from lo

### •mvq· «MoVe Quadword»

    •mvql(x) => to/from lo

### •neg· «NEGate»

    •negl(a) => TRUNCATE(-a)
    •negs(a) => SATURATE(-a)
    •negh(a) => (flt16_t) -a
    •negw(a) => (float) -a
    •negd(a) => (double) -a

### •new· «vector ctor»

    •neww(...) => 32 bit
    •newd(...) => 64 bit
    •newq(...) => 128 bit

### •orr· «bitwise ORR»

    •orrs(a, b) => a OR b
    •orrn(a, b) => a OR NOT b
    •orrv(v)    => REDUCE(orrs, v)
    •orr1(...)  => atomic_or_explicit(..., memory_order_relaxed)
    •orra(...)  => atomic_or_explicit(..., memory_order_acquire)
    •orre(...)  => atomic_or_explicit(..., memory_order_release)
    •orrt(...)  => atomic_or_explicit(..., memory_order_seq_cst)

### •per· «PERmute»

    •pers(a, ...)    => permute with 0 default
    •perm(a, b, ...) => permute with b default

### •rem· «REMainder of division»

    •reml(a, b, *r) => truncated
    •remn(a, b, *r) => floored
    •rem2(a, b, *r) => narrowed 

### •rev· «REVerse»

    •revy(a) => reverse element bits
    •revb(a) => reverse element bytes
    •revs(a) => REVERSE(a)

### •smb· «Synchronized Memory Barrier»

    •smba() => SYNC(hmba())
    •smbe() => SYNC(hmbe())
    •smbt() => SYNC(hmbt())

### •raz· «Round Away from Zero (toward)»

    •razf(a) => ROUND(a, DR_NEXT)
    •razb(a) => (int8_t) ROUND(a, DR_NEXT)
    •razh(a) => (int16_t) ROUND(a, DR_NEXT)
    •razw(a) => (int32_t) ROUND(a, DR_NEXT)
    •razd(a) => (int64_t) ROUND(a, DR_NEXT)
    •razq(a) => (QUAD_ITYPE) ROUND(a, DR_NEXT)

### •rot· «ROTate binary representation by int»

    •rotl(a, b) => (a[-b:] OR a[:+b])
    •rotr(a, b) => (a[+b:] OR a[:-b])

### •rov· «vectorized 'rot'»

    •rovl(a, b) => VECTORIZE(rotl, a, b)
    •rovr(a, b) => VECTORIZE(rotr, a, b)

### •rtz· «Round Toward Zero (trunc)»

    •rtzf(a) => ROUND(a, DR_ZERO)
    •rtzb(a) => (int8_t) ROUND(a, DR_ZERO)
    •rtzh(a) => (int16_t) ROUND(a, DR_ZERO)
    •rtzw(a) => (int32_t) ROUND(a, DR_ZERO)
    •rtzd(a) => (int64_t) ROUND(a, DR_ZERO)
    •rtzq(a) => (QUAD_ITYPE) ROUND(a, DR_ZERO)

### •rtp· «Round Toward Positive inf (ceil)»

    •rtpf(a) => ROUND(a, DR_NINF)
    •rtpb(a) => (int8_t) ROUND(a, DR_PINF)
    •rtph(a) => (int16_t) ROUND(a, DR_PINF)
    •rtpw(a) => (int32_t) ROUND(a, DR_PINF)
    •rtpd(a) => (int64_t) ROUND(a, DR_PINF)
    •rtpq(a) => (QUAD_ITYPE) ROUND(a, DR_PINF)

### •rtn· «Round Toward Negative inf (floor)»

    •rtnf(a) => ROUND(a, DR_NINF)
    •rtnb(a) => (int8_t) ROUND(a, DR_NINF)
    •rtnh(a) => (int16_t) ROUND(a, DR_NINF)
    •rtnw(a) => (int32_t) ROUND(a, DR_NINF)
    •rtnd(a) => (int64_t) ROUND(a, DR_NINF)
    •rtnq(a) => (QUAD_ITYPE) ROUND(a, DR_NINF)

### •seq· «linear SEQuence»

    •seqw(a, b) => {a, a+b×1, a+b×2, ...}
    •seqd(a, b) => {a, a+b×1, a+b×2, ...}
    •seqq(a, b) => {a, a+b×1, a+b×2, ...}

### •set· «vector SET»

    •set1(a, b, c)  => (a[b] = c)
    •setl(a, b)     => (a.Lo = b)
    •setr(a, b)     => (a.Hi = b)

### •shl· «SHift Left»

    •shl2(a, b) => WIDENED(a)<<b
    •shls(a, b) => SATURATE(a<<b)
    •shll(a, b) => TRUNCATE(a<<b)
    •shlr(a, b) => KEEPHIGH(a<<b)

### •shr· «SHift Right»

    •shrs(a, b) => SATURATE(a>>v)

### •sil· «Shift Insert Left»

    •sill(a, b, c) => (a<<c) OR b[:+c]
    •silr(a, b, c) => (a<<c) OR b[-c:]

### •sir· «Shift Insert Right»

    •sirl(a, b, c) => (a>>c) OR (b[:+c]<<(WIDTHOF(a)-c))
    •sirr(a, b, c) => (a>>c) OR (b[-c:]<<(WIDTHOF(a)-c))

### •spl· «Shift Pair Left»

    •spll(l, r, n) => l[n:] ## r[:+n]
    •splr(l, r, n) => l[n:] ## r[-n:]

### •spr· «Shift Pair Right»

    •sprl(l, r, n) => l[:n] ## r[:+n]
    •sprr(l, r, n) => l[:n] ## r[-n:]

### •str· «STore Register to aligned»

    •str1(...)  => atomic_store_explicit(...order_relaxed)
    •stre(...)  => atomic_store_explicit(...order_release)
    •strt(...)  => atomic_store_explicit(...order_seq_cst)

### •sub· «SUBtraction»

    •subl(a, b) => TRUNCATE(a-b)
    •subs(a, b) => SATURATE(a-b)
    •sub2(a, b) => WIDEN(a)-b
    •subh(a, b) => (flt16_t) a-b
    •subw(a, b) => (float) a-b
    •subd(a, b) => (double) a-b
    •sub1(...)  => atomic_fetch_sub(..., memory_order_relaxed)
    •suba(...)  => atomic_fetch_sub(..., memory_order_acquire)
    •sube(...)  => atomic_fetch_sub(..., memory_order_release)
    •subt(...)  => atomic_fetch_sub(..., memory_order_seq_cst)

### •sum· «across vector 'add'»

    •suml(a) => REDUCE(addl, a)
    •sum2(a) => REDUCE(add2, a)
    •sums(a) => REDUCE(adds, a)
    •sumf(a) => REDUCE(addf, a)

### •sun· «Store register to UNaligned»

    •sunw(a, b) => WRITE(a, b) (b is 32 bit vector)
    •sund(a, b) => WRITE(a, b) (b is 64 bit vector)
    •sunq(a, b) => WRITE(a, b) (b is 128 bit vector)

### •svl· «vectorized 'shl'»

    •svl2(a, b) => VECTORIZE(shl2, a, b)
    •svll(a, b) => VECTORIZE(shll, a, b)
    •svls(a, b) => VECTORIZE(shls, a, b)

### •svr· «vectorized 'shr'»

    •svrs(a, b) => VECTORIZE(shrs, a, b)

### •swp· «SWaP»

    •swp1(...) => atomic_exchange_explicit(...order_relaxed)
    •swpa(...) => atomic_exchange_explicit(...order_acquire)
    •swpe(...) => atomic_exchange_explicit(...order_release)
    •swpt(...) => atomic_exchange_explicit(...order_seq_cst)

### •toa· «TO Ascii representation»

    •toay(a) => BIN(a)
    •toao(a) => OCT(a)
    •toad(a) => DEC(a)
    •toal(a) => LOWERHEX(a)
    •toau(a) => UPPERHEX(a)

### •uno· «Generate consecutive '1' bits»

    •unol(N) => from lsb to msb
    •unor(N) => from msb to lsb

### •uzp· «UnZiP (deinterleave)»

    •uzpl(a, b) => extract evens
    •uzpr(a, b) => extract odds

### •veq· «Vector EQuality match»

    •veql(a, b) => lane of first match or -1
    •veqr(a, b) => lane of last match or -1
    •veqn(a, b) => match count
    •veqs(a, b) => saturated if any match 
    •veqy(a, b) => true if any match else false

### •vne· «Vector NonEquality match»

    •vnel(a, b) => lane of first match or -1
    •vner(a, b) => lane of last match or -1
    •vnen(a, b) => match count
    •vnes(a, b) => saturated if any match 
    •vney(a, b) => true if any match else false

### •vlt· «Vector Less Than match»

    •vltl(a, b) => lane of first match or -1
    •vltr(a, b) => lane of last match or -1
    •vltn(a, b) => match count
    •vlts(a, b) => saturated if any match 
    •vlty(a, b) => true if any match else false

### •vle· «Vector Less or Equal match»

    •vlel(a, b) => lane of first match or -1
    •vler(a, b) => lane of last match or -1
    •vlen(a, b) => match count
    •vles(a, b) => saturated if any match 
    •vley(a, b) => true if any match else false

### •vgt· «Vector Greater Than match»

    •vgtl(a, b) => lane of first match or -1
    •vgtr(a, b) => lane of last match or -1
    •vgtn(a, b) => match count
    •vgts(a, b) => saturated if any match 
    •vgty(a, b) => true if any match else false

### •vge· «Vector Greater or Equal match»

    •vgel(a, b) => lane of first match or -1
    •vger(a, b) => lane of last match or -1
    •vgen(a, b) => match count
    •vges(a, b) => saturated if any match 
    •vgey(a, b) => true if any match else false

### •vbn· «Vector BetweeN match»

    •vbnl(a, b) => lane of first match or -1
    •vbnr(a, b) => lane of last match or -1
    •vbnn(a, b) => match count
    •vbns(a, b) => saturated if any match 
    •vbny(a, b) => true if any match else false

### •vnb· «Vector Not Between match»

    •vnbl(a, b) => lane of first match or -1
    •vnbr(a, b) => lane of last match or -1
    •vnbn(a, b) => match count
    •vnbs(a, b) => saturated if any match 
    •vnby(a, b) => true if any match else false

### •xeq· «eXchange if EQual»

    •xeq1(...) => CAS(..., succ=relaxed, fail=relaxed)
    •xeqa(...) => CAS(..., succ=acquire, fail=acquire)
    •xeqe(...) => CAS(..., succ=release, fail=acquire)
    •xeqt(...) => CAS(..., succ=seq_cst, fail=seq_cst)

### •xor· «bitwise XOR»

    •xors(a, b) => a XOR b
    •xorn(a, b) => a XOR ~b
    •xorv(v)    => REDUCE(xors, v)
    •xor1(...)  => atomic_xor_explicit(..., memory_order_relaxed)
    •xora(...)  => atomic_xor_explicit(..., memory_order_acquire)
    •xore(...)  => atomic_xor_explicit(..., memory_order_release)
    •xort(...)  => atomic_xor_explicit(..., memory_order_seq_cst)

### •xrd  «eXtend Right Double»

    •xrdz(x) => zero extend
    •xrds(x) => sign extend

### •xrq  «eXtend Right Quadruple»

    •xrqz(x) => zero extend
    •xrqs(x) => sign extend

### •xro  «eXtend Right Octuple»

    •xroz(x) => zero extend
    •xros(x) => sign extend

### •zeq· «Zero EQuals»

    •zeqs(a) => (0 == a) ? -1 : 0
    •zeqy(a) => (0 == a) ? +1 : 0

### •zge· «Zero Greater than or Equal»

    •zges(a) => (0 >= a) ? -1 : 0
    •zgey(a) => (0 >= a) ? +1 : 0

### •zgt· «Zero Greater Than»

    •zgts(a) => (0 > a) ? -1 : 0
    •zgty(a) => (0 > a) ? +1 : 0

### •zle· «Zero Less than or Equal»

    •zles(a) => (0 <= a) ? -1 : 0
    •zley(a) => (0 <= a) ? +1 : 0

### •zlt· «Zero Less Than»

    •zlts(a) => (0 < a) ? -1 : 0
    •zlty(a) => (0 < a) ? +1 : 0

### •zne· «Zero uNEqual»

    •znes(a) => (0 != a) ? -1 : 0
    •zney(a) => (0 != a) ? +1 : 0

### •zip· «interleave»

    •zipl(a, b) => KEEPLOW(ZIP(a, b))
    •zipr(a, b) => KEEPHIGH(ZIP(a, b))
    •zipp(a, b) => ZIP(a, b)

#Highlights 

    * reinterpret casts, aka type punning. E.g. aswfwi 
    reinterprets the 4 byte representation of its 32 bit
    signed int operand as a 4 byte/32 bit float

    * Value conversions, with options to truncate, widen,
    or saturate. e.g. cvbuqhi converts the 128 bit vector 
    of eight signed 16 bit integers to a 64 bit vector of
    8 bit unsigned integers as if by C assignment; cvbzqhi
    also converts the eight 16 bit ints to 8 bit ints but
    clamps any negative elements to 0.

    * Comparisons that evaluate to +1 when true as well as 
    "saturated" comparisons that evaluate to -1 when true

    * Equivalents for all ops in C11's <stdatomic.h> except
    the atomic_flag. memory_order_consume and the related
    kill_dependency also have no equivalent, but this is
    irrelevant since modern architectures don't implement
    them anyway

    * Representation reversal (bits, bytes, entire vector)

    * Load any scalar or vector from possibly misaligned
    address. E.g. lunnadu safely loads an unsigned 64 bit 
    integer from any address using the most efficient way
    available
    
    * Vector blending, permutation, (de)interleaving, and
    concatenation/splitting.
    
    * Count set bits/Hamming weight
    
    * Count sequential zeros

    * Arithmetic with saturated, truncated, widened, or
    narrowed integer result. Mixed integer and float ops
    with implicit conversion to float.

    * Common CISC combo ops such as fused multiply add, 
    AND NOT, OR NOT, XOR NOT

    * Multiple forms of bit shift including widened left 
    shift, saturated arithmetic shifts, and insert shifts


    
    
    
    