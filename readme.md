
# HISTORY

    ...
    |
    +-- V15:
    |   *   Renamed 'ldn' to 'lun'
    |   *   Renamed 'stn' to 'sun'
    |
    +-- V16:
    |   *   Renamed 'vxt' to 'get'
    |   *   Renamed 'vst' to 'set'
    |
    +-- V17:
    |   *   Renamed neq to cne
    |   *   Deleted nlt
    |   *   Deleted nle
    |   *   Deleted ngt
    |   *   Deleted nge
    |
    +-- V18:
    |   *   Merged multiple sources into singular the "ungop.h"
    |
    +-- V19:
    |   *   Renamed invt to invs
    |   *   Deleted several kilobytes worth of trailing spaces

NOTE: the version number is completely arbitrary at this
point.

# ABOUT

ungop - pronounced "ungop" - is the name of an instruction
set architecture specification, including a reference C
implementation for a suite of intrinsic functions and macros,
which gives users the ability to access the full capabilities
of modern processors, most importantly SIMD/vector operations.

As what's effectively a major extension to the C11 standard
library, the most important thing we had to consider was C
namespace compatibility. None of the instruction names may
conflict with any symbol defined by:

*   C11 nor any of its standard annexes; 
*   any version of POSIX/XSI; 
*   Microsoft's "Win32 API" or own C library (msvcrt);
*   Google's C library "bionic"
*   "glibc" 
*   Apple's standard library. 

They also shouldn't be English words that might conflict with
commonly used variable names. Finally, we want to ensure
profanity filters aren't *reasonably* triggered.

There are two possible methods to meet those requirements.
The first, which was chosen by the C standard in C11 / C2x, 
is to obfuscate by encumbrance. For example:

    atomic_compare_exchange_strong
    stdc_trailing_zeros

The other, chosen by us, is to obfuscate by algorithm. That 
is, all instructions consist of a three letter prefix plus a
single letter variant indicator, which together form a four
letter operation name. 

    xeqt = atomic_compare_exchange_strong
    cszr = stdc_trailing_zeros

Reusing 'cszr' as an example, we have two parts:

    * 'csz' -> "Count Sequential Zeros"
    * 'r'   -> rtl, aka right to left, aka high to low

The following table shows how the variant modifiers are 
typically used:

    '1':

        *   C11 'memory_order_relaxed' semantics
        *   Literally '1', as in 'cnt1', which counts the
            number of '1' digits of each operand element
        *   Limit SIMD op to specific lane

    '2':
        *   width×2
        *   width÷2

    'a':
        *   C11 'memory_order_acquire' semantics
        *   7 bit / ASCII
        *   Base85

    'b':
        *   8 bit / 1 byte
        *   Big/network endian

    'c':
        *   char

    'd':
        *   64 bit / 8 byte
        *   Decimal, i.e. base 10

    'e':
        *   C11 'memory_order_release' semantics

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

    's':
        *   All
        *   Saturated
        *   512 bit / 64 byte
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


Since we aren't a compiler, implementing the four letter
generic form of each operation requires _Generic, and 
although it is a powerful and long needed feature, it has
some rather severe limitations - primarily that evaluation
occurs long after preprocessing. This requires making the
_Generic operator evaluate to a function designator. Not
all operations can be efficiently inlined so it is very
important that users be able to bypass the generic form and
directly invoke the type specific form. How type specific
operations are named must therefore be easy to learn and 
consistent.

The following table lists the ~57 standard C types for which
operations may be available in the reference implementation
and their type specific suffix:

## Arithmetic types (15+3)

    suffix  type

    yu      bool
    bu      uint8_t
    bi      int8_t
    bc      char
    hu      uint16_t
    hi      int16_t
    hf      flt16_t [†]
    wu      uint32_t
    wi      int32_t
    wf      float
    du      uint64_t
    di      int64_t
    df      double
    qu      QUAD_UTYPE [‡]
    qi      QUAD_ITYPE [‡]
    qf      QUAD_FTYPE [‡]
    lu      ulong or ullong [‡‡]
    li      long or llong [‡‡]


## 32 bit SIMD vector types (10)

    suffix  type

    wyu     (32 × bool)
    wbu     (4 × uint8_t)
    wbi     (4 × int8_t)
    wbc     (4 × char)
    whu     (2 × uint16_t)
    whi     (2 × int16_t)
    whf     (2 × flt16_t)
    wwu     (1 × uint32_t)
    wwi     (1 × int32_t)
    wwf     (1 × float)


## 64 bit SIMD vector types (13)

    suffix  type

    dyu     (64 × bool)

    dbu     (8 × uint8_t)
    dbi     (8 × int8_t)
    dbc     (8 × char)

    dhu     (4 × uint16_t)
    dhi     (4 × int16_t)
    dhf     (4 × flt16_t)

    dwu     (2 × uint32_t)
    dwi     (2 × int32_t)
    dwf     (2 × float)

    ddu     (1 × uint64_t)
    ddi     (1 × int64_t)
    ddf     (1 × double)


## 128 bit SIMD vector types (16)

    suffix  type

    qyu     (128 × bool)

    qbu     (16 × uint8_t)
    qbi     (16 × int8_t)
    qbc     (16 × char)

    qhu     (8 × uint16_t)
    qhi     (8 × int16_t)
    qhf     (8 × flt16_t)

    qwu     (4 × uint32_t)
    qwi     (4 × int32_t)
    qwf     (4 × float)

    qdu     (2 × uint64_t)
    qdi     (2 × int64_t)
    qdf     (2 × double)

    qqu     (1 × QUAD_UTYPE) ‡‡‡
    qqi     (1 × QUAD_ITYPE) ‡‡‡
    qqf     (1 × QUAD_FTYPE) ‡‡‡


## 256 bit SIMD vector types (unused at present)

    suffix  type

    oyu     (256 × bool)

    obu     (32 × uint8_t)
    obi     (32 × int8_t)
    obc     (32 × char)

    ohu     (16 × uint16_t)
    ohi     (16 × int16_t)
    ohf     (16 × flt16_t)

    owu     (8 × uint32_t)
    owi     (8 × int32_t)
    owf     (8 × float)

    odu     (4 × uint64_t)
    odi     (4 × int64_t)
    odf     (4 × double)

    oqu     (2 × QUAD_UTYPE) ‡‡‡
    oqi     (2 × QUAD_ITYPE) ‡‡‡
    oqf     (2 × QUAD_FTYPE) ‡‡‡

    oou     (1 × OCTA_UTYPE) ‡‡‡‡
    ooi     (1 × OCTA_ITYPE) ‡‡‡‡
    oof     (1 × OCTA_FTYPE) ‡‡‡‡

## 512 bit SIMD vector types (unused at present)

    suffix  type

    syu     (512 × bool)

    sbu     (64 × uint8_t)
    sbi     (64 × int8_t)
    sbc     (64 × char)

    shu     (32 × uint16_t)
    shi     (32 × int16_t)
    shf     (32 × flt16_t)

    swu     (16 × uint32_t)
    swi     (16 × int32_t)
    swf     (16 × float)

    sdu     (8 × uint64_t)
    sdi     (8 × int64_t)
    sdf     (8 × double)

    squ     (4 × QUAD_UTYPE) ‡‡‡
    sqi     (4 × QUAD_ITYPE) ‡‡‡
    sqf     (4 × QUAD_FTYPE) ‡‡‡

    sou     (2 × OCTA_UTYPE) ‡‡‡‡
    soi     (2 × OCTA_ITYPE) ‡‡‡‡
    sof     (2 × OCTA_FTYPE) ‡‡‡‡

    ssu     (1 × SEXD_UTYPE) ‡‡‡‡
    ssi     (1 × SEXD_ITYPE) ‡‡‡‡
    ssf     (1 × SEXD_FTYPE) ‡‡‡‡


    † flt16_t is defined as a half precision ieee 754 float.
    If the target ABI has a dedicated C type, that's what
    it will be a typedef of. E.g. arm's __fp16 or when the
    AVX-512FP16 x86 extension is supported, _Float16.
    Otherwise, flt16_t will be a unique, single element
    homogeneous 16 bit unsigned integer aggregate type.

    ‡ 128 bit operations are provisionally available. That 
    is, if the target supports __int128 or a binary128 based
    long double, operations are available for those types.
    Otherwise, the corresponding int type will be defined as
    a unique, two element 64 bit integer aggregate, while 
    the float type will be a unique floating point aggregate
    type composed of two doubles. In both cases, the Lo 
    member may be used to access the value's least
    significant 64 bits and the Hi member its most 
    significant 64 bits. 128 bit operations are *not* 
    available in the generic API.

    ‡‡ Hosted 64 bit C implementations will have either a 32
    bit int AND long or 64 bit long and llong. the 'lu' and
    'li' suffixes are reserved in the former for long and in
    the latter for llong. This allows values of these types 
    to be compatible with the generic operation. However, be
    aware that unless explicitly stated, when an operation
    results in a value of a different size, its type is 
    always the lowest ranked type with that width. E.g. if 
    long and llong are both 64 bit, the return type of 
    add2wi is long since it has lower rank than long long.
    When the result width doesn't change, the return type is
    always identical unless otherwise specified. E.g. xorslu
    on the same LP64 based target returns a ullong.

    ‡‡‡ The 128 bit numeric types presently have no SIMD
    vector implementations.

    ‡‡‡‡ The 256 and 512 bit numeric types presently have
    no implementations at all.


The arithmetic types can be, and are, grouped by the generic
machinery into sets:

    *u      unsigned integers
    *i      signed integers
    *f      floats
    *z      any integer                 (Z like the symbol)
    *n      unsigned ints AND floats    (N as in natural)
    *s      signed ints AND floats      (S as in signed)
    *r      real numbers                (R like the symbol)

Note that char is always included if one of the 8 bit 
integers is. That is, for targets with a signed char, "bz" 
will include char and unsigned char. This profoundly
simplifies the implementation of generic 8 bit integer ops,
especially considering MSVC, which incorrectly doesn't
consider `char`, `unsigned char`, and `signed char` as three
distinct types.


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
all vector operation signatures but unfortunately, GCC 
intrinsics don't work with register qualified vectors. We
therefore *_STRONGLY_* advise avoiding `register`

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
32, or 64 bit "lanes", the number of which being however
many can fit in the containing vector. There are never any
padding bits between vector elements.

Like arrays, the type of value stored in a lane is known as
the vector's element type. On architectures with a little
endian vector representation, which are the only targets we
presently support, the vector lane number and array index
of a particular multibit element are equivalent, while on 
architectures with a big endian vector representation, the
lowest lane will be the highest index. Boolean vector lanes
are numbered according to the bits position and are thus 
the same on all platforms.

The following figures illustrate the relationship between
"vector lane" and "array index" of a particular element for
multibit types. For multibyte types, the lane's number label
is found at the same position as its least significant byte:

    Ltt = little endian
    Btt = big endian
    idx = index

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


Operations described as "left shifts" move the elements 
such that the least significant bit of the shifted region 
is located at a higher index. This includes both bitwise 
and elementwise shifts. E.g. the following illustrates the
left shift of a Vdbu by 2 elements, with B6 and B7 being
"shifted out" and zeros being "shifted in", on a little 
endian vector representation:


    Before: || B0 B1 B2 B3 B4 B5 B6 B7 ||
    After:  || zz zz B0 B1 B2 B3 B4 B5 || B6 B7

Note: our illustrations of the positions of vector elements
will always order stuff as it would appear if stored in 
memory - with "byte 0" coming before / to the left of 
"byte 1".


# OP INDEX

Finally, the following is a complete instruction listing,
including a brief description.

### unprefixed/special

    •pass:   forfeit the calling thread's remaining CPU time
    •unos:   f(N) => generate N sequential 1 bits
    •void:   the zero constant 
    •sign:   extract sign bit (no generic)
    •expo:   extract exponent of float (no generic)
    •mant:   extract mantissa of float (no generic)


### •cmb· «Compiler Memory Barrier»
Prevent memory access reordering across the barrier by the
compiler. Execution time reordering may still occur.

    •cmba:  ≈ atomic_signal_fence(memory_order_acquire)
    •cmbe:  ≈ atomic_signal_fence(memory_order_release)
    •cmbt:  ≈ atomic_signal_fence(memory_order_seq_cst)


### •hmb· «Hardware Memory Barrier»
Prevent all memory accesses of the relevant type from being
reordered across the barrier. Unlike cmb, reordering at 
execution time is also prevented.

    •hmba:  ≈ atomic_thread_fence(memory_order_acquire
    •hmbe:  ≈ atomic_thread_fence(memory_order_release)
    •hmbt:  ≈ atomic_thread_fence(memory_order_seq_cst)


### •smb· «Synchronizing Memory Barrier»
Identical to the corresponding hmb except that the thread 
executing the smb spins until all previously initiated but 
unfinished memory accesses of the relevant type complete.
What exactly "complete" means in this regard is obviously 
implementation defined. At minimum, memory coherency is 
guaranteed.

    •smba:  hmbc() and wait for all preceding loads
    •smbe:  hmbc() and wait for all preceding stores
    •smbt:  hmbc() and wait for all preceding accesses


### •ast· «generic Reinterpret cASt»
Reinterpret the representation of a value as that of 
another equivalent width type.

    •astm   interpet virtual as machine or machine as virtual
    •astv:  interpret virtual as scalar or scalar as virtual
    •astu:  interpret Ts as Tu
    •asti:  interpret Tn as Ti
    •astf:  interpret Tz as Tf


### •asy· «reinterpret cASt as boolean vector»

    •asyu:  interpet V**r as V*yu


### •asb· «reinterpret cast AS Byte»

    •asbu:  interpret Bs as Bu or Vt*s as Vtbu
    •asbi:  interpret Bn as Bi or Vt*n as Vtbi
    •asbc:  interpret Br as Bc or Vt*r as Vtbc


### •ash· «reinterpret cast AS Halfword»

    •ashu:  interpret Hs as Hu or Vt*s as Vthu
    •ashi:  interpret Hn as Hi or Vt*n as Vthi
    •ashf:  interpret Hz as Hf or Vt*z as Vthf


### •asw· «reinterpret cast AS Word»

    •aswu:  interpret Ws as Wu or Vt*s as Vtwu
    •aswi:  interpret Wn as Wi or Vt*n as Vtwi
    •aswf:  interpret Wz as Wf or Vt*z as Vtwf


### •asd· «reinterpret cast AS Doubleword»

    •asdu:  interpret Dr as Du or Vt*r as Vtdu
    •asdi:  interpret Dr as Di or Vt*r as Vtdi
    •asdf:  interpret Dr as Df or Vt*r as Vtdf


### •asq· «reinterpret cast AS Quadword»

    •asqu:  interpret Qr as Qu or Vt*r as Vtqu
    •asqi:  interpret Qr as Qi or Vt*r as Vtqi
    •asqf:  interpret Qr as Qf or Vt*r as Vtqf


### •toa· «TO Ascii representation»
Convert scalar to its text representation and store it in
a sufficiently large byte array.

    •toay:  store binary repr
    •toao:  store octal repr
    •toad:  store decimal repr
    •toal:  store lowercase hexdecimal repr
    •toau:  store uppercase hexdecimal repr 


### •new· «Vector constructor»
Construct a vector from a sequence of values specified as a
list of numbered parameters.

    •newl:  vector ctor, parameters given lo to hi
    •newr:  vector ctor, parameters given hi to lo


### •seq· «linear SEQuence»
Construct a vector with each element representing the next
element in a range.

    •seqw: 4×8b or 2×16b bit range
    •seqd: 8×8b, 4×16b, of 2×32b range
    •seqq: 16×8b, 8×16b, 4×32b, or 2×64b range
    •seqo: 32×8b, 16×16b, 8×32b, or 4×64b range
    •seqs: 64×8b, 32×16b, 16×32b, or 8×64b range



### •dup· «DUPlicate»
Construct a vector with all lanes set to the same value

    •dupl:  duplicates the first vector lane ("broadcast")
    •dupw:  set all lanes of new 32 bit vector
    •dupd:  set all lanes of new 64 bit vector
    •dupq:  set all lanes of new 128 bit vector
    •dupo:  set all lanes of new 256 bit vector
    •dups:  set all lanes of new 512 bit vector


### •get· «Extract»

    •get1:  extract single vector element
    •get2:  extract pair
    •getl:  extract lower half
    •getr:  extract upper half


### •set· «Replace»

    •set1:  replace single element
    •setl:  replace lower half
    •setr:  replace upper half


### •cat· «conCATenate»

    •catl:  concatenate L ## R
    •catr:  concatenate revs(R) ## revs(L)


### •rev· «REVerse»

    •revs:  reverse vector
    •revy:  reverse element bits
    •revb:  reverse element bytes


### •zip· «interleave pair»

    •zipl:  keep the lower ½
    •zipr:  keep the upper ½
    •zipp:  keep entire result


### •uzp· «UnZip Pair»

    •uzpl:  extract the even numbered lanes of a vector pair
    •uzpr:  extract odd numbered lanes


### •bln· «BLeNd»
Construct a new vector consisting of elements selected from
one of two source vectors using a mask

    •blnm:  mask given via multiple parameters


### •per· «PERmute»
Construct a new N element vector from a source vector and a
sequence of N vector lanes given as a list of integer 
parameters. The lane numbers must either be -1, indicating a
default value should be used, or a valid lane number. All 
operations read the first parameter as the result's lane 0,
the second parameter as its lane 1, and so on.

    •perm:  lane copied from first source
    •perp:  lane copied from a second source vector
    •perz:  each bit in lane set to 0
    •pers:  each bit in lane set to 1


### •cnt· «CouNt Total»

    •cnt1:  one digits (i.e. hamming weight/popcount)
    •cnts:  redundant sign bits
    •cnta:  matching 7-bit range (ASCII)
    •cntb:  matching 8-bit range (ISO-8859-1/'latin-1')
    •cnth:  matching 16-bit range (Unicode BMP)
    •cntw:  matching 32-bit code points


### •csz· «Count Sequential Zeros»

    •cszl:  L to R (i.e. lsb to msb or 'count trailing zeros')
    •cszr:  R to L (i.e. msb to lsb or 'count leading zeros')


### •raz· «Round with ties Away from Zero»

Aka ties toward positive infinity for positive operands and
negative infinity for negative operands.

    •razf:  as Tf integral
    •razh:  as Hi
    •razw:  as Wi
    •razd:  as Di
    •razq:  as Qi


### •rtz· «Round with ties Towards Zero»

    •rtzf:  round with ties to zero as Tf integral
    •rtzh:  round with ties to zero as Hi
    •rtzw:  round with ties to zero as Wi
    •rtzd:  round with ties to zero as Di
    •rtzq:  round with ties to zero as Qi


### •rtp· «Round with ties Towards Positive infinity»

    •rtph:  round with ties to +inf as Tf integral
    •rtph:  round with ties to +inf as Hi
    •rtpw:  round with ties to +inf  as Wi
    •rtpd:  round with ties to +inf  as Di
    •rtpq:  round with ties to +inf  as Qi


### •rtn· «Round with ties Towards Negative infinity»

    •rtnh:  round with ties to -inf as Tf integral
    •rtnh:  round with ties to -inf as Hi
    •rtnw:  round with ties to -inf as Wi
    •rtnd:  round with ties to -inf as Di
    •rtnq:  round with ties to -inf as Qi


### •cvb· «ConVert to Byte»

    •cvbc:  convert to truncated char
    •cvbu:  convert to truncated uint8_t
    •cvbi:  convert to truncated int8_t
    •cvbz:  convert to saturated uint8_t
    •cvbs:  convert to saturated int8_t
    •cvbf:  reserved (probably for bf16/brain float)


### •cvh· «ConVert to Halfword»

    •cvhu:  convert to truncated uint16_t
    •cvhi:  convert to truncated int16_t
    •cvhz:  convert to saturated uint16_t
    •cvhs:  convert to saturated int16_t
    •cvhf:  convert to flt16_t (current rounding mode)


### •cvw· «ConVert to Word»

    •cvwu:  convert to truncated uint32_t
    •cvwi:  convert to truncated int32_t
    •cvwz:  saturated uint32_t
    •cvws:  saturated int32_t
    •cvwf:  convert to float (current rounding mode)


### •cvd· «ConVert to Doubleword»

    •cvdu:  convert to truncated uint64_t
    •cvdi:  convert to truncated int64_t
    •cvdz:  convert to saturated uint64_t
    •cvds:  convert to saturated int64_t
    •cvdf:  double (current rounding mode)


### •cvq· «ConVert to Quadword»

    •cvqu: convert to truncated QUAD_UTYPE
    •cvqi: convert to truncated QUAD_ITYPE
    •cvqz: convert to saturated QUAD_UTYPE
    •cvqs: convert to saturated QUAD_ITYPE
    •cvqf: convert to QUAD_FTYPE (current rounding mode)


### •ldr· «LoaD Register from aligned»

The source address must be aligned on a multiple of the size
of the result type. I.e. loading a 128 bit vector with ldrq
requires a 16 byte aligned address. On architectures with a
little endian vector representation, vector lanes are loaded
from the corresponding array index. If architectures with a
big endian vector representation were supported, the first 
lane of the result would be loaded from the last index of 
the corresponding array. Refer to SIMD.

    •ldrn: nonatomic nat-endian scalar load
    •ldrl: nonatomic lil-endian scalar load
    •ldrb: nonatomic big-endian scalar load
    •ldr1: atomic_load_explicit(..., memory_order_relaxed)
    •ldra: atomic_load_explicit(..., memory_order_acquire)
    •ldrt: atomic_load_explicit(..., memory_order_seq_cst)
    •ldrw: load aligned 4B as 32 bit vector
    •ldrd: load aligned 8B as 64 bit vector
    •ldrq: load aligned 16B as 128 bit vector
    •ldro: (not implemented)
    •ldrs: (not implemented)


### •lun· «Load UNaligned»

Identical to the corresponding ldr operation except that the
alignment of the operand is irrelevant.

    •lunn: load nat-endian scalar from unaligned
    •lunl: load lil-endian scalar from unaligned
    •lunb: big-endian scalar from unaligned
    •lunw: load 32 bit vector from unaligned
    •lund: load 64 bit vector from unaligned
    •lunq: load 128 bit vector from unaligned
    •luno: (not implemented)
    •luns: (not implemented)


### •str· «STore Register aligned»

Store value at address aligned on the size of the operand 
type. I.e. storing a 128 bit vector requires an address 
that is a multiple of 16. Vectors are stored such that a 
store of A at address Z using the appropriate STR, followed
by a load at Z with the appropriate LDR results in a new 
vector with exactly the same binary representation as A.
The result is the destination address.

    •str1: atomic_store_explicit(...,memory_order_relaxed)
    •stre: atomic_store_explicit(...,memory_order_release)
    •strt: atomic_store_explicit(...,memory_order_seq_cst)
    •strv: store entire vector


### •sun· «Store UNaligned»

Identical to the corresponding STR operation except the
alignment is irrelevant.

    •sunn: stored nat-endian scalar to unaligned
    •sunl: store lil-endian scalar to unaligned
    •sunb: store big-endian scalar to unaligned
    •sunw: store 32 bit vector as 4 unaligned bytes 
    •sund: store 64 bit vector as 8 unaligned bytes
    •sunq: store 128 bit vector as 16 unaligned bytes


### •swp· «SWaP»

E.g. swp1(src, dst) atomically performs:

```
    tmp=*dst, *dst=src, src=tmp
```

If dst isn't properly aligned, the result is undefined

    •swp1: atomic_exchange_explicit(...,memory_order_relaxed)
    •swpa: atomic_exchange_explicit(...,memory_order_acquire)
    •swpe: atomic_exchange_explicit(...,memory_order_release)
    •swpt: atomic_exchange_explicit(...,memory_order_seq_cst)


### •xeq· «eXchange if EQual»

E.g. xeq1(cmp, src, dst) atomically performs:

```
    tmp=*dst;
    if (tm)
    *dst=src, src=tmp
```
If dst isn't properly aligned, the result is undefined

    •xeq1: succ=relaxed, fail=relaxed
    •xeqa: succ=acquire, fail=acquire
    •xeqe: succ=release, fail=acquire
    •xeqt: succ=seq_cst, fail=seq_cst

### •ceq· «Compare EQual»

    •ceqs: (a == b) ? -1 : 0
    •ceqy: (a == b) ? +1 : 0


### •cne· «Compare Not Equal»

    •cnes: (a != b) ? -1 : 0
    •cney: (a != b) ? +1 : 0


### •clt· «Compare Less Than»

    •clts: (a < b) ? -1 : 0
    •clty: (a < b) ? +1 : 0


### •cle· «Compare Less or Equal»

    •cles:  (a <= b) ? -1 : 0
    •cley:  (a <= b) ? +1 : 0


### •cgt· «Compare Greater Than»

    •cgts:  (a > b) ? -1 : 0
    •cgty:  (a > b) ? +1 : 0


### •cge· «Compare Greater than or Equal»

    •cgey:  (a >= b) ? +1 : 0
    •cgez:  (a >= 0) ? -1 : 0


### •zeq· «Zero EQuals»

    •zeqs: (0 == a) ? -1 : 0
    •zeqy: (0 == a) ? +1 : 0

### •zne· «Zero does Not Equal»

    •znes: (0 != a) ? -1 : 0
    •zney: (0 != a) ? +1 : 0

### •zlt· «Zero Less Than»

    •zlts: (0 < a) ? -1 : 0
    •zlty: (0 < a) ? +1 : 0

### •zle· «Zero Less than or Equal to»

    •zles: (0 < a) ? -1 : 0
    •zley: (0 < a) ? +1 : 0

### •zgt· «Zero Greater Than»

    •zgts: (0 > a) ? -1 : 0
    •zgty: (0 > a) ? +1 : 0

### •zle· «Zero Greater than or Equal to»

    •zges: (0 < a) ? -1 : 0
    •zgey: (0 < a) ? +1 : 0


### •veq· «Vector match EQual»

Test if any element in a vector is equal to the second 
operand

    •veqs: saturated vector result
    •veqy: bool result
    
### •cbn· «Compare BetweeN»

Takes three operands: a scalar or vector as A and two 
scalars as L and R. For each element E in A, determine if
L <= E <= R.

    •cbns:  (l <= e) && (e <= r) ? -1 : 0
    •cbny:  (l <= e) && (e <= r) ? +1 : 0


### •cnb· «Compare Not Between»

Performs the complement of cbn.


    •cnbs:  (l > e) || (e > r) ? -1 : 0
    •cnby:  (l > e) || (e > r) ? +1 : 0


### •tst· «TeST if any bits in mask are set»

    •tsts:  ((a&b) != 0) ? -1 : 0
    •tsty:  ((a&b) != 0) ? +1 : 0


### •avg· «AVeraGe»

    •avgs:  average of corresponding elements
    •avgv:  average across vector


### •max· «MAXimum»

    •maxl:  f(a, b) => likely(a > b) ? a : b
    •maxp:  pairwise maximum
    •maxv:  maximum across vector


### •min· «MINimum»

    •minl:  f(a, b) => likely(a < b) ? a : b
    •minp:  
    •minv:  minimum across vector


### •rot· «ROTate binary representation by int»

    •rotl:  rotate binary repr left by uint
    •rolr:  rotate binary repr right by uint
    •rots:  left by pos, right by neg


### •rov· «ROtate binary representation by Vector element»

    •rovl:  rotate binary repr left by corresponding 
    •rovr:  rotate binary repr rite by corresponding 
    •rovs:  rotate binary repr left by pos, right by neg


zsert = zeros are shifted in
lsert = the lower bits of second operand are shifted in
rsert = the upper bits of second operand are shifted in
ssert = the value of the sign bit us shifted in

all elements by same unsigned int:

    rotl (left by uint)
    rotr (rite by uint)
    rots (left by +int, rite by abs(-int))

    shl2 (shift ssert by scalar left and widen)
    shll (shift zsert by scalar left keep lower)
    shlr (shift zsert by scalar left keep upper)
    shls (shift zsert by scalar left saturating)
    
    shrs (shift ssert rite by scalar)

    sill (shift lsert left by scalar)
    silr (shift rsert left by scalar)
    
    sirl (shift lsert rite by scalar)
    sirr (shift rsert rite by scalar)
    
    spll (shift pair left from lo)
    splr (shift pair left from hi)
    
    sprl (shift pair right from lo)
    sprr (shift pair right from hi)

each element by corresponding vector element:

    rovl (left by uint)
    rovr (rite by uint)
    rovs (left by +int, rite by abs(-int))

    svl2 (shift zsert left by vector and widen)
    svll (shift zsert left by vector keep lower)
    svlr (shift zsert left by vector keep upper)
    svls (shift zsert left by vector saturating)
    
    svrs (shift ssert rite by vector)

### •shl· «SHift Left by scalar»

For integers, each element in the operand is shifted left
by a constant number of bits, which has the effect of 
multiplying the operand by a power of two. For floats, the
shift amount is added to the object's exponent member, 
which is semantically equivalent to left shifting an int.

Implementations commonly define a macro form, giving users
the ability to explicitly use the faster constant shift 
instructions. 
    •shl2:  sfill keep wider
    •shls:  sfill
    •shll:  zfill keep lower
    •shlr:  zfill keep upper

### •svl· «Shift bits by corresponding Vector element Left»

Like shl_ except instead of using a constant shift amount
for each element, the corresponding unsigned element in a 
second vector is used.

TODO: debate the possible addition of svlr

    •svl2:  zfill keep wider
    •svll:  zfill keep lower
    •svls:  saturate


### •shr· «SHift Right by scalar»

Shifts each element in the first operand A right by the
number of bits specified as the second operand B. With 
unsigned operands, a zero is shifted in at the MSB for each
bit shifted out at the LSB. For signed operands, copies of
the sign bit are shifted in.

TODO: debate renaming shrs/svrs to shrl/svrl. Both suffixes
make sense semantically.

    •shrs:  sfill/saturated


### •svr· «Shift bits by corresponding Vector element Right»

Like shr_ except instead of using a constant shift amount
for each element, the corresponding unsigned element in a 
second vector is used.

    •svrs:  saturated
    

### •sil· «Shift/Insert Left»

Shifts each element in the first operand A left by the 
number of bits specified by the third operand C. A slice 
of C bits are taken from one end of the corresponding 
element in B and inserted in the space opened by the shift.

    •sill:  (A<<C)|B[0:C]
    •silr:  (A<<C)|B[-C:]

### •sir· «Shift Insert Right»

Shifts each element in the first operand A right by the 
number of bits specified by the third operand C. Instead of
shifting in zeros, a contiguous sequence of bits from one 
of the ends of the second integer operand B is inserted.

    •sirr:  rsert
    •sirp:  pair by scalar×esize


### •spl· «Shift Pair Left»

Shifts the binary representation of a vector left by a 
multiple of its lane size. Instead of shifting in zeros, a
sequence of consecutive elements taken from the end of a 
second vector is inserted.

    •spll:  insert lo slice
    •splr:  insert hi slice


### •spr· «Shift Pair Right»

Shift the binary representation of a vector right by a 
multiple of its lane size. Instead of shifting in zeros, a
sequence of consecutive elements taken from the end of a 
second vector is inserted.

E.g. on a little endian arch:

    A = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7}
    B = {0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf}
    
    A[:2] = {0x2, 0x3,  0x4, 0x5, 0x6, 0x7}
    B[:2] = {0x8, 0x9}

    v = sprldbu(A, B, 2) => A[2:] ## B[2:]
    (   {0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9} )

NOTE/TODO: some implementations only implement dedicated 
instructions for one of the "shift by element size × N"
ops. E.g. arm has vext and x86 has _mm_alignr, both 
corresponding to sprl. In theory, compilers should often be
able to detect that a user is using a less optimal spr/spl
but we need a way for users to be able to detect if a 
particular version has a dedicated operation.

    •sprl:  insert lo slice
    •sprr:  insert hi slice


### •inv· «unary INVert»

    •invs:  ~a
    •inv1:  atomic_xor_explicit(a, -1, memory_order_relaxed)
    •inva:  atomic_xor_explicit(a, -1, memory_order_acquire)
    •inve:  atomic_xor_explicit(a, -1, memory_order_release)
    •invt:  atomic_xor_explicit(a, -1, memory_order_seq_cst)


### •and· «bitwise AND»

    •ands:  a & b
    •andn:  a & ~b
    •andv:  across vector
    •and1:  atomic_and_explicit(..., memory_order_relaxed)
    •anda:  atomic_and_explicit(..., memory_order_acquire)
    •ande:  atomic_and_explicit(..., memory_order_release)
    •andt:  atomic_and_explicit(..., memory_order_seq_cst)


### •orr· «bitwise OR»

    •orrs:  a | b
    •orrn:  a | ~b
    •orrv:  across vector
    •orr1:  atomic_or_explicit(..., memory_order_relaxed)
    •orra:  atomic_or_explicit(..., memory_order_acquire)
    •orre:  atomic_or_explicit(..., memory_order_release)
    •orrt:  atomic_or_explicit(..., memory_order_seq_cst)


### •xor· «bitwise XOR»

    •xors:  a ^ b
    •xorn:  a ^ ~b
    •xorv:  across vector 
    •xor1:  atomic_xor_explicit(..., memory_order_relaxed)
    •xora:  atomic_xor_explicit(..., memory_order_acquire)
    •xore:  atomic_xor_explicit(..., memory_order_release)
    •xort:  atomic_xor_explicit(..., memory_order_seq_cst)


### •neg· «unary NEGate»

    •negl:  truncated
    •negs:  saturated
    •negf:  negate as float


### •abs· «ABSolute value»

    •absl:  truncated
    •abss:  saturated
    •absu:  unsigned result
    •absh:  flt16_t result (using current rounding mode)
    •absw:  float result (using current rounding mode)
    •absd:  double result (using current rounding mode)

### •add· «ADDition»

    •addl:  truncated
    •adds:  saturated
    •add2:  widened×2
    •add1:  atomic_fetch_add(..., memory_order_relaxed)
    •adda:  atomic_fetch_add(..., memory_order_acquire)
    •adde:  atomic_fetch_add(..., memory_order_release)
    •addt:  atomic_fetch_add(..., memory_order_seq_cst)
    •addh:  flt16_t c = (flt16_t) a+b
    •addw:  float   c = (float) a+b
    •addd:  double  c = (double) a+b

### •inc· «INCrement by 1»

    •incl:  truncated
    •incs:  saturated
    •inc2:  widened×2
    •inch:  flt16_t
    •incw:  float 
    •incd:  double

### •sum· «SUM (add across vector)»

    •suml:  truncated
    •sum2:  widened×2
    •sums:  saturated
    •sumh:  flt16_t
    •sumw:  float 
    •sumd:  double


### •sub· «SUBtract»

    •subl:  truncated
    •subs:  saturated
    •sub2:  widened×2
    •sub1:  atomic_fetch_sub(..., memory_order_relaxed)
    •suba:  atomic_fetch_sub(..., memory_order_acquire)
    •sube:  atomic_fetch_sub(..., memory_order_release)
    •subt:  atomic_fetch_sub(..., memory_order_seq_cst)
    •subh:  flt16_t
    •subw:  float 
    •subd:  double


### •dec· «DECrement by 1»

    •decl:  truncated
    •decs:  saturated
    •dec2:  widened×2
    •dech:  flt16_t
    •decw:  float 
    •decd:  double


### •dif· «absolute DIFference»

    •difu:  unsigned
    •difs:  saturated


### •mul· «MULtiply»

    •mull:  truncated
    •muls:  saturated
    •mul2:  widened×2
    •mulp:  result is homogeneous aggregate pair
    •mulv:  result is vector pair {[0]=lower, [1]=upper}
    •mulh:  result is flt16_t
    •mulw:  result is float
    •muld:  result is double


### •mad· «Multiply ADd»

    •madl:  truncated
    •mads:  saturated
    •mad2:  width of b and c are ½ of a
    •madp:  result is homogeneous aggregate pair {.Lo, .Hi}
    •madv:  result is vector pair {[0]=p.Lo, [1]=p.Hi}
    •madh:  result is fl16_t
    •madw:  result is float
    •madd:  result is double

### •div· «DIVide»

    •divl:  truncated
    •div2:  halfwidth dividend
    •divp:  result is homogeneous aggregate pair {quot,rem}
    •divv:  result is vector pair {quot,rem}


### •mod· «MODulus»

    •modl: truncated
    •mod2: halfwidth


### •pow· «POWer»

    •powl: truncated


### •sqr· «mathematical SQuare Root»

    •sqrl: truncated
    •sqrh: as flt16_t
    •sqrw: as float
    •sqrd: as double


### •cbr· «mathematical CuBe Root»

    •cbrl: truncated
    •cbrh: as flt16_t
    •cbrw: as float
    •cbrd: as double


### •log· «logarithm»

    •loge: base e
    •log2: base 2
    •logd: base 10


### •sin· «mathematical SINe»

    •sinr: radians
    •sinh: hyperbolic 


### •cos· «mathematical coSINe»

    •cosr: radians
    •cosh: hyperbolic 


### •tan· «mathematical TANgent»

    •tanr: radians
    •tanh: hyperbolic 


### •rnd· «RaNDom number»

    •rndy: fill each element of result with random bits
    
    


