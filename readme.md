
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

ungop - pronounced "ungop" - is the specification of a set
of generic low level operations intended to standardize and
replace the use of implementation defined "intrinsic"
functions. It includes a C reference implementation in which
each operation is defined as a macro that uses its first
parameter with the C11 _Generic operator to select a function
designator representing the type specific operation.

As what's effectively a major extension to the C11 standard
library, the most important thing we had to consider was C
namespace compatibility. None of the operation names may
conflict with any symbol defined by C11 nor any of its 
standard annexes; any version of POSIX/XSI; Microsoft's
"Win32" and own C library (msvcrt); Google's C library 
"bionic"; "glibc"; nor Apple's standard library. They also 
shouldn't be English words that might conflict with commonly
used variables. When possible, names should be designed to
avoid triggering *reasonable* profanity filters.

There are two possible methods to meet those requirements.
The first, chosen by the C standard, is to obfuscate by
encumbrance. For example:

    atomic_compare_exchange_strong

The other, chosen by us, is to obfuscate by algorithm. The
following is equivalent to the former:

    xeqt

All together while there are over 10000 unique type specific
operation names, it shouldn't take more than a few hours for
any competent programmer to recognize what one of them is or
how to spontaneously generate the name of a particular
operation plus type combination.

Reusing 'xeqt' as an example, we have two parts:

    * 'xeq'     (the prefix; means "eXchange if EQual")
    * 't'       (the variant modifier)

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


Although _Generic is a powerful and long needed feature, it 
has some rather severe limitations - primarily that most 
"intrinsic functions" are actually implemented as function
macros. The ones that require a compile time constant 
therefore cannot be directly used with _Generic. Since the
performance penalty of wrapping these intrinsics in a 
static inline function can be rather severe, we made the 
individual type specific operations that the _Generic 
expression calls part of the public interface. 

One example of an operation for which it is almost always
more efficient to use the type specific form is bit shifts.
When e.g. shifting a 16 bit unsigned integer left by 7 bits
and keeping the result's least significant bits, there are
two options: the generic `shll` or the type specific
`shllhu`. If the target architecture has an instruction
for shifting by a constant and another for shifting by a 
register, the former will obviously be faster. In practice, 
a competent compiler would be able to optimize the generic
form, which necessarily uses the register shift. Such a 
compiler is not always available and even when it is there 
is an obvious benefit in reducing the amount of optimizing 
a compiler must do.

Anyway, type specific operations like `shllhu` are named 
according to a strict and simple to remember scheme that is
always based on the first parameter. 

The following table lists the ~52 standard C types for which
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


## 128 bit SIMD vector types (13+3)

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
    *z      any integer                 (Z as in the symbol)
    *n      unsigned ints AND floats    (N as in natural)
    *s      signed ints AND floats      (S as in signed)
    *r      real numbers                (R as in real)


Some operations take a memory address as the first operator.
In this case, the type suffix is simply prefixed by "ac"
when the elements are read-only ("address of constant") and
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

INLINE(Vqwf,dupqwf) (float const *src);
/*  [dup]   DUPlicate
    [q]     quadword (128 bit) result
    [acwf]  float const * operand
*/

INLINE(Vwbi,dupwqbi) (Vqbi src, Rc(0,15) k)
*   dup
*   w   - word (32 bit) result
+   wbi - Vwbi (4×char) operand
```

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

The following figures demonstrate the relationship between
"vector lane" and "array index" of a particular element for
multibit types. For multibyte types, the lane's number label
is found at the same position as its least significant byte:

    Ltt = little endian
    Btt = big endian
    idx = index

    Lww: W0_________
    Lwh: H0___ H1___ 
    Lwb: B0 B1 B2 B3
          |  |  |  |
    idx:  0  1  2  3
          |  |  |  |  
    Bwb: B3 B2 B1 B0
    Bwh: ___H1 ___H0
    Bww: _________W0


    Ldd: D0_____________________
    Ldw: W0_________ W1_________
    Ldh: H0___ H1___ H2___ H3___
    Ldb: B0 B1 B2 B3 B4 B5 B6 B7
          |  |  |  |  |  |  |  |
    idx:  0  1  2  3  4  5  6  7
          |  |  |  |  |  |  |  |
    Bdb: B7 B6 B5 B4 B3 B2 B1 B0
    Bdh: ___H3 ___H2 ___H1 ___H0
    Bdw: _________W1 _________W0 
    Bdd: _____________________D0


    Lqq: Q0_____________________________________________
    Lqd: D0_____________________ D1_____________________
    Lqw: W0_________ W0_________ W0_________ W0_________ 
    Lqh: H0___ H1___ H2___ H3___ H4___ H5___ H6___ H7___    
    Lqb: B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 Ba Bb Bc Bd Be Bf
          |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    idx:  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
          |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    Bqb: Bf Be Bd Bc Bb Ba B9 B8 B7 B6 B5 B4 B3 B2 B1 B0
    Bqh: ___H7 ___H6 ___H5 ___H4 ___H3 ___H2 ___H1 ___H0
    Bqw: _________W3 _________W2 _________W1 _________W0
    Bqd: _____________________D1 _____________________D0  
    Bqq: _____________________________________________Q0


Our standardized vector representation might conflict with
the underlying architecture but in practice, this is 
irrelevant. 
    

# INDEX

Finally, the following is a complete operations listing,
including a brief description.

### unprefixed/special

    •pass:   forfeit the calling thread's remaining CPU time
    •unos:   f(N) => fill register with N sequential 1 bits
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
reordered across the barrier. Unlike CMB, execution time
reordering is also prevented.

    •hmba:  ≈ atomic_thread_fence(memory_order_acquire
    •hmbe:  ≈ atomic_thread_fence(memory_order_release)
    •hmbt:  ≈ atomic_thread_fence(memory_order_seq_cst)


### •smb· «Synchronizing Memory Barrier»
Identical to the corresponding HMB except that the thread 
executing the SMB is blocked until all memory accesses of 
the relevant type that preceded are completed. What exactly
"completed" means in this regard is obviously implementation
defined. At minimum, memory coherency is guaranteed.

    •smba:  hmbc() and wait for all preceding loads
    •smbe:  hmbc() and wait for all preceding stores
    •smbt:  hmbc() and wait for all preceding accesses


### •ast· «generic Reinterpret cASt»

Reinterpret the representation of a value as that of 
another equivalent width type.

    •astm   virtual as machine or machine as virtual
    •astv:  virtual as scalar or scalar as virtual
    •astu:  Ts as Tu
    •asti:  Tn as Ti
    •astf:  Tz as Tf


### •asy· «reinterpret cASt as boolean vector»

    •asyu:  V**r as V*yu


### •asb· «reinterpret cast AS Byte»

    •asbu:  Bs as Bu or Vt*s as Vtbu
    •asbi:  Bn as Bi or Vt*n as Vtbi
    •asbc:  Br as Bc or Vt*r as Vtbc


### •ash· «reinterpret cast AS Halfword»

    •ashu:  Hs as Hu or Vt*s as Vthu
    •ashi:  Hn as Hi or Vt*n as Vthi
    •ashf:  Hz as Hf or Vt*z as Vthf


### •asw· «reinterpret cast AS Word»

    •aswu:  Ws as Wu or Vt*s as Vtwu
    •aswi:  Wn as Wi or Vt*n as Vtwi
    •aswf:  Wz as Wf or Vt*z as Vtwf


### •asd· «reinterpret cast AS Doubleword»

    •asdu:  Dr as Du or Vt*r as Vtdu
    •asdi:  Dr as Di or Vt*r as Vtdi
    •asdf:  Dr as Df or Vt*r as Vtdf


### •asq· «reinterpret cast AS Quadword»

    •asqu:  Qr as Qu or Vt*r as Vtqu
    •asqi:  Qr as Qi or Vt*r as Vtqi
    •asqf:  Qr as Qf or Vt*r as Vtqf


### •toa· «TO Ascii representation»
Converts scalar to its text representation and stores it in
a sufficiently large byte array.

    •toay:  binary
    •toao:  octal
    •toad:  decimal
    •toau:  hexdecimal repr (uppercase alnum)
    •toax:  hexdecimal repr (lowercase alnum)


### •new· «Vector constructor»

Construct a vector from a sequence of values specified as a
list of numbered parameters.

    •newl:  parameters given lo to hi
    •newr:  parameters given hi to lo


### •lnq· «LiNear seQuence»

Construct a vector representing a linear range.

    •lnql: incrementing sequence 
    •lnqr: decrementing sequence


### •dup· «DUPlicate»

Construct a vector with all lanes set to the same value

    •dupw:  32 bit result
    •dupd:  64 bit result
    •dupq:  128 bit result
    •dupo:  256 bit result
    •dups:  512 bit result
    •dupl:  duplicates the first vector lane ("broadcast")


### •get· «Extract»

    •get1:  a single element
    •getl:  lower half
    •getr:  upper half


### •set· «Replace»

Construct a vector with the value of a single lane replaced 

    •set1:  a single element
    •setl:  the lower half
    •setr:  the upper half


### •cat· «conCATenate»

Concatenates the representations of two values.

    •catl:  L ## R
    •catr:  f(a, b) => catl(revs(b), revs(a))


### •rev· «REVerse»

    •revs:  sequence
    •revy:  element bits
    •revb:  element bytes
    •revh:  element halfwords
    •revt:  Unicode text


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
    •cntr:  redundant sign bits
    •cnta:  matching 7-bit range (ASCII)
    •cntb:  matching 8-bit range (ISO-8859-1/'latin-1')
    •cnth:  matching 16-bit range (Unicode BMP)
    •cntw:  matching 32-bit code points


### •csz· «Count Sequential Zeros»

    •cszl:  L to R (i.e. lsb to msb or 'count trailing zeros')
    •cszr:  R to L (i.e. msb to lsb or 'count leading zeros')


### •raz· «Round with ties Away from Zero»

Aka ties toward positive infinity for positive opeands and
negative infinity for negative operands.

    •razf:  as Tf integral
    •razh:  as Hi
    •razw:  as Wi
    •razd:  as Di
    •razq:  as Qi


### •rtz· «Round with ties Towards Zero»

    •rtzf:  as Tf integral
    •rtzh:  as Hi
    •rtzw:  as Wi
    •rtzd:  as Di
    •rtzq:  as Qi


### •rtp· «Round with ties Towards Positive infinity»

    •rtph:  as Tf integral
    •rtph:  as Hi
    •rtpw:  as Wi
    •rtpd:  as Di
    •rtpq:  as Qi


### •rtn· «Round with ties Towards Negative infinity»

    •rtnh:  as Tf integral
    •rtnh:  as Hi
    •rtnw:  as Wi
    •rtnd:  as Di
    •rtnq:  as Qi


### •cvb· «ConVert to Byte»

    •cvbc:  char
    •cvbu:  uint8_t
    •cvbi:  int8_t
    •cvbz:  saturated uint8_t
    •cvbs:  saturated int8_t
    •cvbf:  reserved (probably for bf16/brain float)


### •cvh· «ConVert to Halfword»

    •cvhu:  uint16_t
    •cvhi:  int16_t
    •cvhz:  saturated uint16_t
    •cvhs:  saturated int16_t
    •cvhf:  flt16_t (current rounding mode)


### •cvw· «ConVert to Word»

    •cvwu:  uint32_t
    •cvwi:  int32_t
    •cvwz:  saturated uint32_t
    •cvws:  saturated int32_t
    •cvwf:  float (current rounding mode)


### •cvd· «ConVert to Doubleword»

    •cvdu:  uint64_t
    •cvdi:  int64_t
    •cvdz:  saturated uint64_t
    •cvds:  saturated int64_t
    •cvdf:  double (current rounding mode)


### •cvq· «ConVert to Quadword»

    •cvqu: truncated QUAD_UTYPE
    •cvqi: truncated QUAD_ITYPE
    •cvdz: saturated QUAD_UTYPE
    •cvds: saturated QUAD_ITYPE
    •cvdf: QUAD_FTYPE (current rounding mode)


### •ldr· «LoaD Register from aligned»

The source memory must be aligned on a multiple of the size
of the result type. I.e. loading a 128 bit vector with ldrq
requires a 16 byte aligned address. On architectures with a
little endian vector representation, vector lanes are loaded
from the corresponding array index. If architectures with a
big endian vector representation were supported, the first 
lane of the result would be loaded from the last index of 
the corresponding array. Refer to SIMD.

    •ldr1: atomic_load_explicit(..., memory_order_relaxed)
    •ldra: atomic_load_explicit(..., memory_order_acquire)
    •ldrt: atomic_load_explicit(..., memory_order_seq_cst)
    •ldrw: load 4B as 32 bit vector
    •ldrd: load 8B as 64 bit vector
    •ldrq: load 16B as 128 bit vector
    •ldro: (not implemented)
    •ldrs: (not implemented)


### •lun· «Load UNaligned»

Identical to the corresponding ldr operation except that the
alignment of the operand is unconstrained.

    •lunn: nat-endian scalar
    •lunl: lil-endian scalar
    •lunb: big-endian scalar
    •lunw: load 32 bit vector
    •lund: load 64 bit vector
    •lunq: load 128 bit vector
    •luno: load 256 bit vector
    •luns: load 512 bit vector


### •str· «STore Register aligned»

    •str1: atomic_store_explicit(..., memory_order_relaxed)
    •stre: atomic_store_explicit(..., memory_order_release)
    •strt: atomic_store_explicit(..., memory_order_seq_cst)
    •strv: store entire vector


### •sun· «Store UNaligned»

    •sunn: nat-endian scalar
    •sunt: nat-endian scalar with temporality hint
    •sunl: lil-endian scalar
    •sunb: big-endian scalar
    •sunw: 4 bytes as 32 bit vector
    •sund: 8 bytes as 64 bit vector
    •sunq: 16 bytes as 128 bit vector
    •suno: 32 bytes as 256 bit vector
    •suns: 64 bytes as 512 bit vector


### •swp· «SWaP»

    •swp1: atomic_exchange_explicit(..., memory_order_relaxed)
    •swpa: atomic_exchange_explicit(..., memory_order_acquire)
    •swpe: atomic_exchange_explicit(..., memory_order_release)
    •swpt: atomic_exchange_explicit(..., memory_order_seq_cst)


### •xeq· «eXchange if EQual»

    •xeq1: succ=relaxed, fail=relaxed
    •xeqa: succ=acquire, fail=acquire
    •xeqe: succ=release, fail=acquire
    •xeqt: succ=seq_cst, fail=seq_cst


### •ceq· «Compare EQual»

    •ceqs: (a == b) ? -1 : 0
    •ceqy: (a == b) ? +1 : 0
    •ceqz: (a == 0) ? -1 : 0


### •cne· «Compare Not Equal»

    •cnes: (a != b) ? -1 : 0
    •cney: (a != b) ? +1 : 0
    •cnez: (a != 0) ? -1 : 0


### •clt· «Compare Less Than»

    •clts: (a < b) ? -1 : 0
    •clty: (a < b) ? +1 : 0
    •cltz: (a < 0) ? -1 : 0


### •cle· «Compare Less or Equal»

    •cles:  (a <= b) ? -1 : 0
    •cley:  (a <= b) ? +1 : 0
    •clez:  (a <= 0) ? -1 : 0


### •cgt· «Compare Greater Than»

    •cgts:  (a > b) ? -1 : 0
    •cgty:  (a > b) ? +1 : 0
    •cgtz:  (a > 0) ? -1 : 0


### •cge· «Compare Greater than or Equal»

    •cges:  (a >= b) ? -1 : 0
    •cgey:  (a >= b) ? +1 : 0
    •cgez:  (a >= 0) ? -1 : 0


### •any· «test if ANY bits in mask are set»

    •anys:  ((a&b) != 0) ? -1 : 0
    •anyy:  ((a&b) != 0) ? +1 : 0


### •avg· «AVeraGe»

    •avgs:  elementwise
    •avgv:  across vector


### •max· «MAXimum»

    •maxl:  f(a, b) => likely(a > b) ? a : b
    •maxv:  across vector


### •min· «MINimum»

    •minl:  f(a, b) => likely(a < b) ? a : b
    •minv:  across vector


### •rol· «ROtate representation Left»

    •rols:  by single int
    •rolv:  by corresponding vector element


### •ror· «ROtate representation Right»

    •rors:  by int
    •rorv:  by corresponding vector element

zsert = zeros are shifted in
lsert = the lower bits of second operand are shifted in
rsert = the upper bits of second operand are shifted in
ssert = the value of the sign bit us shifted in

shl2 (shift zsert by scalar left keep wider)
shll (shift zsert by scalar left keep lower)
shlr (shift zsert by scalar left keep upper)
shls (shift zsert by scalar left saturating)

svl2 (shift zsert left by vector with widen)
svll (shift zsert left by vector keep lower)
svlr (shift zsert left by vector keep upper)
svls (shift zsert left by vector saturating)

sill (shift lsert left by scalar keep lower)
silp (shift pair left by scalar×esize keep upper)

shrs (shift ssert rite by scalar)

svrs (shift ssert rite by vector)

sirr (shift rsert rite by scalar)
sirp (shift pair rite by scalar×esize keep lower)

### •shl· «SHift element bits Left by scalar»

    •shl2:  zfill keep wider
    •shll:  zfill keep lower
    •shlr:  zfill keep upper
    •shls:  zfill & saturate

### •svl· «Shift bits by corresponding Vector element Left»

    •svl2:  zfill keep wider
    •svll:  zfill keep lower
    •svlr:  zfill keep upper
    •svls:  zfill & saturate


### •sil· «Shift Insertion Left»

    •sill:  lsert
    •silv:  pair by scalar×esize


### •shr· «Shift element Bits Right by integer»

    •shrs:  sfill/saturated


### •svr· «Shift bits by corresponding Vector element Right»

    •svrs:  saturated

### •sir· «Shift Insert Right»

    •sirr:  rsert
    •sirp:  pair by scalar×esize

### •spl· «Shift Pair Left and extract»

    •spll:  shift in from lsb to msb
    •splr:  shift in from msb to lsb
    •splv:  vector




### •inv· «unary INVert»

    •invs:  ~a
    •inv1:  atomic_xor_explicit(a, -1, memory_order_relaxed)
    •inva:  atomic_xor_explicit(a, -1, memory_order_acquire)
    •inve:  atomic_xor_explicit(a, -1, memory_order_release)
    •invt:  atomic_xor_explicit(a, -1, memory_order_seq_cst)


### •neg· «unary NEGate»

    •negs:  saturated
    •negl:  truncated
    •neg2:  widened×2


### •abs· «ABSolute value»

    •absl:  truncated
    •abss:  saturated
    •absu:  unsigned result
    •abs2:  widened×2
    •absf:  floating result (using current rounding mode)


### •and· «bitwise AND»

    •ands:  a & b
    •andn:  a & ~b
    •andm:  a & b & c
    •and1:  atomic_and_explicit(..., memory_order_relaxed)
    •anda:  atomic_and_explicit(..., memory_order_acquire)
    •ande:  atomic_and_explicit(..., memory_order_release)
    •andt:  atomic_and_explicit(..., memory_order_seq_cst)


### •orr· «bitwise OR»

    •orrs:  a | b
    •orrn:  a | ~b
    •orrm:  a | b | c
    •orr1:  atomic_or_explicit(..., memory_order_relaxed)
    •orra:  atomic_or_explicit(..., memory_order_acquire)
    •orre:  atomic_or_explicit(..., memory_order_release)
    •orrt:  atomic_or_explicit(..., memory_order_seq_cst)


### •xor· «bitwise XOR»

    •xor1:  atomic_xor_explicit(..., memory_order_relaxed)
    •xora:  atomic_xor_explicit(..., memory_order_acquire)
    •xore:  atomic_xor_explicit(..., memory_order_release)
    •xort:  atomic_xor_explicit(..., memory_order_seq_cst)
    •xors:  a ^ b
    •xorm:  v[0] ^ v[1] ^ v[2] ^ ...


### •add· «ADDition»

    •addl:  truncated
    •adds:  saturated
    •add2:  widened×2
    •add1:  atomic_fetch_add(..., memory_order_relaxed)
    •adda:  atomic_fetch_add(..., memory_order_acquire)
    •adde:  atomic_fetch_add(..., memory_order_release)
    •addt: atomic_fetch_add(..., memory_order_seq_cst)


### •sum· «SUM (add across vector)»

    •suml:  truncated
    •sum2:  widened×2
    •sums:  saturated


### •sub· «SUBtract»

    •subl:  truncated
    •subs:  saturated
    •sub2:  widened×2
    •subm:  ((a-b)-c)
    •sub1:  atomic_fetch_sub(..., memory_order_relaxed)
    •suba:  atomic_fetch_sub(..., memory_order_acquire)
    •sube:  atomic_fetch_sub(..., memory_order_release)
    •subt:  atomic_fetch_sub(..., memory_order_seq_cst)


### •dif· «absolute DIFference»

    •difu:  unsigned
    •difs:  saturated
    •diff:  float


### •mul· «MULtiply»

    •mull:  truncated
    •muls:  saturated
    •mul2:  widened×2
    •mulp:  result is homogeneous aggregate pair
    •mulv:  result is vector pair


### •prd· «PRoDuct (multiply across vector)»

    •prdl:  truncated
    •prds:  saturated
    •prd2:  widened×2
    •prdp:  result is homogeneous aggregate pair
 

### •mad· «Multiply ADd»

    •madl:  truncated
    •mads:  saturated
    •mad2:  width of b and c are ½ of a
    •madp:  result is homogeneous aggregate pair {.Lo, .Hi}
    •madv:  result is vector pair {[0]=p.Lo, [1]=p.Hi}


### •div· «DIVide»

    •divl:  truncated
    •div2:  halfwidth dividend
    •divp:  result is homogeneous aggregate pair {quot,rem}
    •divv:  result is vector pair {quot,rem}


### •mod· «MODulus»

    •modl: truncated
    •mod2: halfwidth


### •pow· «POWer»

    •powf: truncated

### •sqr· «mathematical SQuare Root»

    •sqrf: as float


### •cbr· «mathematical CuBe Root»

    •cbrf: as float
    

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

    •rndr: range

    


