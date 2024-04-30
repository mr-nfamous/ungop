
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

'''
clang
-std=c11
-o single
-march=armv8.2-A
-ferror-limit=5
/sdcard/C/ungop.c
-I/sdcard/C
'''

CHANGES:

24-04-17
* created anyop.h
* deleted some more 256/512 bit vector types

24-04-20
* deleted extraneous dupl ops

24-04-23
* fixed ldrw defs
* added missing lun1
* fixed lunw, lund, and lunq (they didn't work w/ floats)
* added add2 defs

24-04-25
* fix razwwwf, razdwwf, and razfwwf defs

24-04-28
* (re)add sirr

*/

#if _ENTER_EXTDEF
{
#endif
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

This used to be a file <extdef.h>

*/

#ifndef MY_EXTDEF_H // BOF
#define MY_EXTDEF_H

#ifndef __STDC_VERSION__
#error "__STDC_VERSION__ is unavailable"
#endif

#if   __STDC_VERSION__ < 201112L
#error "C11 is required"
#endif

#if     __STDC_HOSTED__ != 1
#error "__STDC_HOSTED__ != 1"
#endif

#undef  SAFECALL
#undef  MY_CALL
#undef  MY_SWAP
#undef  uchar
#undef  schar
#undef  ushrt
#undef  ushort
#undef  shrt
#undef  uint
#undef  ulong
#undef  ullong
#undef  llong

#undef  IGNORED
#undef  IDENTITY
#undef  INLINE
#undef  INTRIN
#undef  PUBLIC
#undef  RESTRICT

#undef  ASSERT

#undef  UNUSED
#undef  UNREACHABLE

#define Rc(...) int const
#define Wc(...) unsigned const
#define Lc(...) unsigned long const

#define     MY_REQS(T,X,Y) _Generic(X,T:Y)

#define     BOOL_REQS(X)    MY_REQS(   BOOL_TYPE,(X),(X))
#define     CHAR_REQS(X)    MY_REQS(   CHAR_TYPE,(X),(X))
#define     UCHAR_REQS(X)   MY_REQS(  UCHAR_TYPE,(X),(X))
#define     SCHAR_REQS(X)   MY_REQS(  SCHAR_TYPE,(X),(X))
#define     USHRT_REQS(X)   MY_REQS(  USHRT_TYPE,(X),(X))
#define     SHRT_REQS(X)    MY_REQS(   SHRT_TYPE,(X),(X))
#define     UINT_REQS(X)    MY_REQS(   UINT_TYPE,(X),(X))
#define     INT_REQS(X)     MY_REQS(    INT_TYPE,(X),(X))
#define     ULONG_REQS(X)   MY_REQS(  ULONG_TYPE,(X),(X))
#define     LONG_REQS(X)    MY_REQS(   LONG_TYPE,(X),(X))
#define     ULLONG_REQS(X)  MY_REQS( ULLONG_TYPE,(X),(X))
#define     LLONG_REQS(X)   MY_REQS(   LONG_TYPE,(X),(X))
#define     FLT16_REQS(X)   MY_REQS(  FLT16_TYPE,(X),(X))
#define     FLT_REQS(X)     MY_REQS(    FLT_TYPE,(X),(X))
#define     DBL_REQS(X)     MY_REQS(    DBL_TYPE,(X),(X))

#define     UINT8_REQS(X)   MY_REQS(  UINT8_TYPE,(X),(X))
#define     UINT16_REQS(X)  MY_REQS( UINT16_TYPE,(X),(X))
#define     UINT32_REQS(X)  MY_REQS( UINT32_TYPE,(X),(X))
#define     UINT64_REQS(X)  MY_REQS( UINT64_TYPE,(X),(X))
#define     UINTMAX_REQS(X) MY_REQS(UINTMAX_TYPE,(X),(X))
#define     UINTPTR_REQS(X) MY_REQS(UINTPTR_TYPE,(X),(X))
#define     SIZE_REQS(X)    MY_REQS(   SIZE_TYPE,(X),(X))

#define     INT8_REQS(X)    MY_REQS(    INT8_TYPE,(X),(X))
#define     INT16_REQS(X)   MY_REQS(   INT16_TYPE,(X),(X))
#define     INT32_REQS(X)   MY_REQS(   INT32_TYPE,(X),(X))
#define     INT64_REQS(X)   MY_REQS(   INT64_TYPE,(X),(X))
#define     INTPTR_REQS(X)  MY_REQS( INTPTR_TYPE,(X),(X))
#define     INTMAX_REQS(X)  MY_REQS(  INTMAX_TYPE,(X),(X))
#define     PTRDIFF_REQS(X) MY_REQS( PTRDIFF_TYPE,(X),(X))

#define     VWBU_REQS(X)    MY_REQS(VWBU_TYPE,(X),(X))
#define     VWBI_REQS(X)    MY_REQS(VWBI_TYPE,(X),(X))
#define     VWHU_REQS(X)    MY_REQS(VWHU_TYPE,(X),(X))
#define     VWHI_REQS(X)    MY_REQS(VWHI_TYPE,(X),(X))
#define     VWHF_REQS(X)    MY_REQS(VWHF_TYPE,(X),(X))
#define     VWWU_REQS(X)    MY_REQS(VWWU_TYPE,(X),(X))
#define     VWWI_REQS(X)    MY_REQS(VWWI_TYPE,(X),(X))
#define     VWWF_REQS(X)    MY_REQS(VWWF_TYPE,(X),(X))

#define     VDBU_REQS(X)    MY_REQS(VDBU_TYPE,(X),(X))
#define     VDBI_REQS(X)    MY_REQS(VDBI_TYPE,(X),(X))
#define     VDHU_REQS(X)    MY_REQS(VDHU_TYPE,(X),(X))
#define     VDHI_REQS(X)    MY_REQS(VDHI_TYPE,(X),(X))
#define     VDHF_REQS(X)    MY_REQS(VDHF_TYPE,(X),(X))
#define     VDWU_REQS(X)    MY_REQS(VDWU_TYPE,(X),(X))
#define     VDWI_REQS(X)    MY_REQS(VDWI_TYPE,(X),(X))
#define     VDWF_REQS(X)    MY_REQS(VDWF_TYPE,(X),(X))
#define     VDDU_REQS(X)    MY_REQS(VDDU_TYPE,(X),(X))
#define     VDDI_REQS(X)    MY_REQS(VDDI_TYPE,(X),(X))
#define     VDDF_REQS(X)    MY_REQS(VDDF_TYPE,(X),(X))

#define     VQBU_REQS(X)    MY_REQS(VQBU_TYPE,(X),(X))
#define     VQBI_REQS(X)    MY_REQS(VQBI_TYPE,(X),(X))
#define     VQHU_REQS(X)    MY_REQS(VQHU_TYPE,(X),(X))
#define     VQHI_REQS(X)    MY_REQS(VQHI_TYPE,(X),(X))
#define     VQHF_REQS(X)    MY_REQS(VQHF_TYPE,(X),(X))
#define     VQWU_REQS(X)    MY_REQS(VQWU_TYPE,(X),(X))
#define     VQWI_REQS(X)    MY_REQS(VQWI_TYPE,(X),(X))
#define     VQWF_REQS(X)    MY_REQS(VQWF_TYPE,(X),(X))
#define     VQDU_REQS(X)    MY_REQS(VQDU_TYPE,(X),(X))
#define     VQDI_REQS(X)    MY_REQS(VQDI_TYPE,(X),(X))
#define     VQDF_REQS(X)    MY_REQS(VQDF_TYPE,(X),(X))

#define     VOBU_REQS(X)    MY_REQS(VOBU_TYPE,(X),(X))
#define     VOBI_REQS(X)    MY_REQS(VOBI_TYPE,(X),(X))
#define     VOHU_REQS(X)    MY_REQS(VOHU_TYPE,(X),(X))
#define     VOHI_REQS(X)    MY_REQS(VOHI_TYPE,(X),(X))
#define     VOHF_REQS(X)    MY_REQS(VOHF_TYPE,(X),(X))
#define     VOWU_REQS(X)    MY_REQS(VOWU_TYPE,(X),(X))
#define     VOWI_REQS(X)    MY_REQS(VOWI_TYPE,(X),(X))
#define     VOWF_REQS(X)    MY_REQS(VOWF_TYPE,(X),(X))
#define     VODU_REQS(X)    MY_REQS(VODU_TYPE,(X),(X))
#define     VODI_REQS(X)    MY_REQS(VODI_TYPE,(X),(X))
#define     VODF_REQS(X)    MY_REQS(VODF_TYPE,(X),(X))

#define     VSBU_REQS(X)    MY_REQS(VSBU_TYPE,(X),(X))
#define     VSBI_REQS(X)    MY_REQS(VSBI_TYPE,(X),(X))
#define     VSHU_REQS(X)    MY_REQS(VSHU_TYPE,(X),(X))
#define     VSHI_REQS(X)    MY_REQS(VSHI_TYPE,(X),(X))
#define     VSHF_REQS(X)    MY_REQS(VSHF_TYPE,(X),(X))
#define     VSWU_REQS(X)    MY_REQS(VSWU_TYPE,(X),(X))
#define     VSWI_REQS(X)    MY_REQS(VSWI_TYPE,(X),(X))
#define     VSWF_REQS(X)    MY_REQS(VSWF_TYPE,(X),(X))
#define     VSDU_REQS(X)    MY_REQS(VSDU_TYPE,(X),(X))
#define     VSDI_REQS(X)    MY_REQS(VSDI_TYPE,(X),(X))
#define     VSDF_REQS(X)    MY_REQS(VSDF_TYPE,(X),(X))

#ifndef MY_STDIO_H
#include  <stdio.h>
#define MY_STDIO_H
#endif

#ifndef MY_STDLIB_H
#include  <stdlib.h>
#define MY_STDLIB_H
#endif

static inline void
MY_NOT_IMPLEMENTED(FILE *dst, char const *why, ...)
{
    va_list seq;
    va_start(seq, why);
    (void) vfprintf(!dst ? stdout : dst, why, seq);
    va_end(seq);
    abort();
}

#define REQZ(Z, X)              \
(                               \
    ((Z)==sizeof(X)) ? (X) :    \
    ((1)==sizeof(X)) ? _Generic((X), int:(X)) :\
    _Generic((X), char:(X)) \
)

#define IGNORED(...)
#define IDENTITY(...) __VA_ARGS__
#define VA_APPEND(_, ...) __VA_OPT__(__VA_ARGS__,) _

#define ENDIAN_OTH  (0)
#define ENDIAN_LIL  (1)
#define ENDIAN_BIG  (2)
#define ENDIAN_NAT  (3)

#if     __STDC_VERSION__ >= 201710L
#   define  ASSERT  static_assert
#endif

#ifndef ASSERT
#if defined(_MSC_VER)
#   define  ASSERT(C, ...) _Static_assert((C), #C)
#else
#   define  ASSERT(C, ...) \
    _Static_assert((C), #C __VA_OPT__(" => \n" #__VA_ARGS__))
#endif
#endif

#define LENGTHOF(x) (sizeof (x)\/sizeof *(x))

#if defined(unreachable)
#   define  UNREACHABLE     unreachable
#elif defined(_MSC_VER)
#   define  UNREACHABLE()   __assume(0)
#elif defined(__GNUC__)
#   define  UNREACHABLE     __builtin_unreachable
#else
#   ifndef  MY_STDLIB_H
#   define  MY_STDLIB_H
#   include   <stdlib.h>
#   define  UNREACHABLE     abort
#   endif
#endif

#if __STDC_VERSION__ <= 201710L
#   if defined(_MSC_VER)
#       define  UNUSED(...) _Pragma("warning(suppress:4100)\n") __VA_ARGS__
#   elif defined(__clang__) || !defined(__GNUC__)
#       define  UNUSED(...) __VA_ARGS__ __attribute__((unused))__
#   endif

#endif

#ifndef UNUSED
#define UNUSED(...) __VA_ARGS__ [[maybe_unused]]
#endif

#if defined(_MSC_VER)
#   define  INLINE(T, F)    static T __forceinline  F
#   define  PUBLIC(T, F)    extern T __vectorcall   F
#   define  INTRIN(T, F)    static T F
#else
#   define  INLINE(T, F)    static inline T F
#   define  PUBLIC(T, F)    extern T F
#   define  INTRIN(T, F)    static T F
#endif

#if defined(_MSC_VER)
#   define RESTRICT(...) __VA_OPT__(__restrict __VA_ARGS__)
#else
#   define RESTRICT(...) __VA_OPT__(  restrict __VA_ARGS__)
#endif

#ifndef MY_LIMITS_H
#define MY_LIMITS_H
#include  <limits.h>
#endif

#ifndef MY_ERRNO_H
#define MY_ERRNO_H
#include  <errno.h>
#endif

#ifndef MY_STDBOOL_H
#define MY_STDBOOL_H
#include  <stdbool.h>
#endif

#ifndef MY_STDDEF_H
#define MY_STDDEF_H
#include  <stddef.h>
#endif

#if _ENTER_EXTDEF_ISA
{
#endif

#define ISA_X86     1
#define ISA_ARM     3
#define ISA_RV      5
#define ISA_PPC     6
#define ISA_MIPS    7
#define ISA_IA64    8

#if defined(__x86_64__)
#   define  MY_ISA  ISA_X86
#   define  SPC_X86_X64

#elif defined(__ARM_ACLE)
#   define  MY_ISA  ISA_ARM

#elif defined(__riscv)
#   define  MY_ISA  ISA_RV

#   if  defined(__ILP32__)
#       define  SPC_RV_I32
#   elif  defined(__LP64__)
#       define  SPC_RV_I64
#   elif  (ULLONG_MAX>>63) > 18446744073709551615ull
#       define  SPC_RV_I128
#   else
#       error "unknown risc-v ISA"
#   endif

#elif defined(__PPC64__)
#   define  MY_ISA      ISA_PPC
#   define  MY_ENDIAN \
    ((__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)?ENDIAN_BIG:ENDIAN_LIL)

#elif defined(__PPC__)
#   define  MY_ISA      ISA_PPC
#   define  MY_ENDIAN \
    ((__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)?ENDIAN_BIG:ENDIAN_LIL)

#elif defined(__mips__)
#   define  MY_ISA       ISA_MIPS
#   ifdef   __MIPSEB__
#   define  MY_ENDIAN   ENDIAN_BIG
#   endif

#   ifdef   __MIPSEL__
#   define  MY_ENDIAN   ENDIAN_LIL
#   endif

#elif defined(_M_ARM64EC)
#   define  MY_ISA      ISA_X86
#   define  SPC_X86_X64

#elif defined(_M_X64) || defined(_M_AMD64)
#   define  MY_ISA      ISA_X86
#   define  SPC_X86_X64

#elif defined(_M_IA64)
#   define  MY_ISA      ISA_IA64

#elif defined(_M_IX86)
#   define  MY_ISA      ISA_X86

#elif defined(_M_ARM64)
#   define  MY_ISA      ISA_ARM

#elif defined(_M_ARM)
#   define  MY_ISA      ISA_ARM

#elif defined(_M_ARMV7VE)
#   define  MY_ISA      ISA_ARM

#elif defined(_M_ALPHA)
#   define  MY_ISA      ISA_ALPHA

#elif defined(_M_PPC)
#   define  MY_ISA      ISA_PPC

#elif defined(_M_MRX000)
#   error "wtf is this"

#else
#   error "unable to detect target instruction set architecture"
#endif

#if _LEAVE_EXTDEF_ISA
}
#endif

#if _ENTER_EXTDEF_SPC_ARM
{
#endif

#if MY_ISA == ISA_ARM

#   ifndef  MY_ARM_ACLE_H
#   define  MY_ARM_ACLE_H
#   include  <arm_acle.h>
#   endif

#   ifndef __ARM_ARCH_PROFILE
#   error "__ARM_ARCH_PROFILE undefined"
#   endif

#   ifndef __ARM_FP
#   error "__ARM_FP undefined"
#   endif

#   ifndef __ARM_NEON
#   error "__ARM_NEON undefined"
#   endif

#   if !(__ARM_FP&0x02)
#   error "hardware 'float' support is expected"
#   endif

#   if defined(__ARM_FP16_FORMAT_ALTERNATIVE)
#   error "__fp16 is expected to be based on binary16"
#   endif

#   if   __ARM_ARCH >= 900
#       define  SPC_ARM_V9  (__ARM_ARCH%100)
#       define  SPC_ARM_V8  (8)
#   elif __ARM_ARCH >= 800
#       define  SPC_ARM_V9  (0)
#       define  SPC_ARM_V8  (__ARM_ARCH%100)
#   elif defined(SPC_ARM_V8)
#       define  SPC_ARM_V9  (0)
#   else
#       define  SPC_ARM_V8  (1)
#       define  SPC_ARM_V9  (0)
#   endif

#   define  SPC_ARM_V7   (7)
#   define  SPC_ARM_ACLE
#   define  SPC_ARM_NEON
#   define  SPC_ARM_PROFILE  __ARM_ARCH_PROFILE

#   ifdef   __ARM_FEATURE_LDREX
#   define  SPC_ARM_LDREX    __ARM_FEATURE_LDREX
#   endif

#   ifndef  SPC_ARM_LDREX
#   define  SPC_ARM_LDREX   (0)
#   endif

#   define  SPC_ARM_LDREX_B ((0x01&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_H ((0x02&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_W ((0x04&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_D ((0x08&SPC_ARM_LDREX) != 0)
#   define  SPC_ARM_LDREX_Q ((0x10&SPC_ARM_LDREX) != 0)

#   ifdef   __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
#   define  SPC_ARM_FP16_MATH   __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
#   endif

#   ifdef   __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
#   define  SPC_ARM_FP16_SIMD   __ARM_FEATURE_FP16_VECTOR_ARITHMETIC

/*
The following NEON intrinsics are available only if
SPC_ARM_FP16_SIMD is defined:

vmulh_lane_f16, vmulh_laneq_f16
vabd_f16,       vabdq_f16
vabs_f16,       vabsq_f16
vadd_f16,       vaddq_f16
vbsl_f16,       vbslq_f16
vcage_f16,      vcageq_f16

vcagt_f16,      vcagtq_f16
vcale_f16,      vcaleq_f16
vcalt_f16,      vcaltq_f16
vceq_f16,       vceqq_f16
vceqz_f16,      vceqzq_f16
vcge_f16,       vcgeq_f16
vcgez_f16,      vcgezq_f16
vcgt_f16,       vcgtq_f16
vcgtz_f16,      vcgtzq_f16
vcle_f16,       vcleq_f16
vclez_f16,      vclezq_f16
vclt_f16,       vcltq_f16
vcltz_f16,      vcltzq_f16
vcvt_f16_u16,   vcvtq_f16_u16
vcvt_u16_f16,   vcvtq_u16_f16
vcvt_f16_s16,   vcvtq_f16_s16
vcvt_s16_f16,   vcvtq_s16_f16
vcvt_n_f16_s16, vcvtq_n_f16_s16
vcvt_n_f16_u16, vcvtq_n_f16_u16
vcvt_n_s16_f16, vcvtq_n_s16_f16
vcvt_n_u16_f16, vcvtq_n_u16_f16

vcvta_f16_u16,   vcvtaq_f16_u16
vcvta_u16_f16,   vcvtaq_u16_f16
vcvta_f16_s16,   vcvtaq_f16_s16
vcvta_s16_f16,   vcvtaq_s16_f16

vcvtm_f16_u16,   vcvtmq_f16_u16
vcvtm_u16_f16,   vcvtmq_u16_f16
vcvtm_f16_s16,   vcvtmq_f16_s16
vcvtm_s16_f16,   vcvtmq_s16_f16

vcvtn_f16_u16,   vcvtnq_f16_u16
vcvtn_u16_f16,   vcvtnq_u16_f16
vcvtn_f16_s16,   vcvtnq_f16_s16
vcvtn_s16_f16,   vcvtnq_s16_f16

vcvtp_f16_u16,   vcvtpq_f16_u16
vcvtp_u16_f16,   vcvtpq_u16_f16
vcvtp_f16_s16,   vcvtpq_f16_s16
vcvtp_s16_f16,   vcvtpq_s16_f16
vext_f16,       vextq_f16
vfma_f16,       vfmaq_f16
vfms_f16,       vfmsq_f16
vmax_f16,       vmaxq_f16
vmin_f16,       vminq_f16
vmul_f16,       vmulq_f16
vmul_lane_f16,  vmulq_lane_f16
vmul_n_f16,     vmulq_n_f16
vneg_f16,       vnegq_f16
vpadd_f16,      vpaddq_f16
vpmax_f16,      vpmaxq_f16
vpmin_f16,      vpminq_f16
vrecpe_f16,     vrecpeq_f16
vrecps_f16,     vrecpsq_f16
vrev64_f16,     vrev64q_f16

vrsqrte_f16,    vrsqrteq_f16
vrsqrts_f16,    vrsqrtsq_f16
vsub_f16,       vsubq_f16
vtrn_f16,       vtrnq_f16
vuzp_f16,       vuzpq_f16
vzip_f16,       vzipq_f16
vdiv_f16,       vdivq_f16
vduph_lane_f16, vduph_laneq_f16
vfmah_lane_f16
vfma_lane_f16,  vfmaq_lane_f16
vmaxv_f16,      vmaxvq_f16
vminv_f16,      vminq_f16
vmaxnmv_f16,    vmaxnmvq_f16
vminnmv_f16,    vminnmvq_f16
vmulq_laneq_f16
vmul_laneq_f16
vmulx_f16,      vmulxq_f16
*/

#   endif

#   ifdef   __ARM_FP16_ARGS
#   define  SPC_ARM_FP16_ARGS   __ARM_FP16_ARGS
#   endif

#   ifdef   __ARM_FP_FENV_ROUNDING
#   define  SPC_ARM_FENV         __ARM_FP_FENV_ROUNDING
#   endif

#   ifdef   __ARM_FEATURE_CLZ
#   define  SPC_ARM_CLZ         __ARM_FEATURE_CLZ
#   endif

#   ifdef   __ARM_FEATURE_IDIV
#   define  SPC_ARM_IDIV        __ARM_FEATURE_IDIV
#   endif

#   ifdef   __ARM_FEATURE_FMA
#   define  SPC_ARM_FMA         __ARM_FEATURE_FMA
#   endif

#   ifdef   __ARM_FEATURE_FP16_FML
#   define  SPC_ARM_FP16_FML
#   endif

#   ifdef   __ARM_FEATURE_UNALIGNED_ACCESS
#   define  SPC_ARM_UNALIGNED   __ARM_FEATURE_UNALIGNED_ACCESS
#   endif

#   ifdef   __ARM_FEATURE_BTI_DEFAULT
#   define  SPC_ARM_BTIDEF      __ARM_FEATURE_BTI_DEFAULT
#   endif

#   ifdef   __ARM_FEATURE_PAC_DEFAULT
#   define  SPC_ARM_PACDEF      __ARM_FEATURE_PAC_DEFAULT
#   endif

#   ifdef   __ARM_FEATURE_CRC32
#   define  SPC_ARM_CRC32       __ARM_FEATURE_CRC32
#   endif

#   ifdef   __ARM_FEATURE_AES
#   define  SPC_ARM_AES         __ARM_FEATURE_AES
#   endif

#   ifdef   __ARM_FEATURE_SHA2
#   define  SPC_ARM_SHA2        __ARM_FEATURE_SHA2
#   endif

#   ifdef   __ARM_FEATURE_SHA3
#   define  SPC_ARM_SHA3        __ARM_FEATURE_SHA3
#   endif

#   ifdef   __ARM_FEATURE_SHA512
#   define  SPC_ARM_SHA512      __ARM_FEATURE_SHA512
#   endif

#   ifdef   __ARM_FEATURE_SM3
#   define  SPC_ARM_SM3         __ARM_FEATURE_SM3
#   endif

#   ifdef   __ARM_FEATURE_SM4
#   define  SPC_ARM_SM4         __ARM_FEATURE_SM4
#   endif

#   ifdef   __ARM_FEATURE_DOTPROD
#   define  SPC_ARM_DOTPROD     __ARM_FEATURE_DOTPROD
#   endif

#   ifdef   __ARM_FEATURE_COMPLEX
#   define  SPC_ARM_COMPLEX     __ARM_FEATURE_COMPLEX
#   endif

#   ifdef   __ARM_FEATURE_JCVT
#   define  SPC_ARM_JCVT        __ARM_FEATURE_JCVT
#   endif

#   ifdef   __ARM_FEATURE_RNG
#   define  SPC_ARM_RNG         __ARM_FEATURE_RNG
#   endif

#   ifdef   __ARM_FEATURE_TME
#   define  SPC_ARM_TME         __ARM_FEATURE_TME
#   endif

#   ifdef   __ARM_FEATURE_MTE
#   define  SPC_ARM_MTE         __ARM_FEATURE_MTE
#   endif

#   ifdef   __ARM_FEATURE_FRINT
#   define  SPC_ARM_FRINT       __ARM_FEATURE_FRINT
#   endif

#   ifdef   __ARM_64BIT_STATE
#   define  SPC_ARM_A64         __ARM_64BIT_STATE
#   endif

#   ifdef   __ARM_FEATURE_MATMUL_INT8
#   define  SPC_ARM_MATMUL_INT8 __ARM_FEATURE_MATMUL_INT8
#   endif

#   ifdef   __ARM_FEATURE_DIRECTED_ROUNDING
#   define  SPC_ARM_DR          __ARM_FEATURE_DIRECTED_ROUNDING
#   endif

#   ifdef   __ARM_FEATURE_FMA
#   define  SPC_ARM_FMA         __ARM_FEATURE_FMA
#   endif

#   ifdef   __ARM_FEATURE_NUMERIC_MAXMIN
#   define  SPC_ARM_MAXMIN      __ARM_FEATURE_NUMERIC_MAXMIN
#   endif

#   ifdef   __ARM_FEATURE_LS64
#   define  SPC_ARM_LS64        __ARM_FEATURE_LS64
#   endif

#   if  defined(__ARM_BIG_ENDIAN)
#       define MY_ENDIAN   ENDIAN_BIG
#   else
#       define MY_ENDIAN   ENDIAN_LIL
#   endif

#endif

#if _LEAVE_EXTDEF_SPC_ARM
}
#endif

#if _ENTER_EXTDEF_SPC_X86
{
#endif

#if defined(__AVX512FP16__)
#   ifndef  SPC_X86_AVX512FP16
#   define  SPC_X86_AVX512FP16
#   endif
#endif

#if defined(__AVX512BF16__) || defined(SPC_X86_FP16)
#   ifndef  SPC_X86_AVX512BF16
#   define  SPC_X86_AVX512BF16
#   endif
#endif

#if defined(__AVX512VPOPCNTDQ__) || defined(SPC_X86_BF16)
#   ifndef  SPC_X86_AVX512VPOPCNTDQ
#   define  SPC_X86_AVX512VPOPCNTDQ
#   endif
#endif

#if defined(__AVX512BITALG__) || defined(SPC_X86_VPOPCNTDQ)
#   ifndef  SPC_X86_AVX512BITALG
#   define  SPC_X86_AVX512BITALG
#   endif
#endif

#if defined(__GFNI__) || defined(SPC_X86_AVX512BITALG)
#   ifndef  SPC_X86_AVX512GFNI
#   define  SPC_X86_AVX512GFNI
#   endif
#endif

#if defined(__AVX512VNNI__) || defined(SPC_X86_AVX512BITALG)
#   ifndef  SPC_X86_AVX512VNNI
#   define  SPC_X86_AVX512VNNI
#   endif
#endif

#if defined(__AVX512VBMI2__) || defined(SPC_X86_AVX512VNNI)
#   ifndef  SPC_X86_AVX512VBMI2
#   define  SPC_X86_AVX512VBMI2
#   endif
#endif

#if defined(__AVX512VBMI__) || defined(SPC_X86_AVX512VBMI2)
#   ifndef  SPC_X86_AVX512VBMI
#   define  SPC_X86_AVX512VBMI
#   endif
#endif

#if defined(__AVX512IFMA__) || defined(SPC_X86_AVX512VBMI)
#   ifndef  SPC_X86_AVX512IFMA
#   define  SPC_X86_AVX512IFMA
#   endif
#endif

#if defined(__AVX512VL__) || defined(SPC_X86_AVX512IFMA)
#   ifndef  SPC_X86_AVX512VL
#   define  SPC_X86_AVX512VL
#   endif
#endif

#if defined(__AVX512CD__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512CD
#   define  SPC_X86_AVX512CD
#   endif
#endif

#if defined(__AVX512BW__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512BW
#   define  SPC_X86_AVX512BW
#   endif
#endif

#if defined(__AVX512DQ__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512DQ
#   define  SPC_X86_AVX512DQ
#   endif
#endif

#if defined(__AVX512F__) || defined(SPC_X86_AVX512VL)
#   ifndef  SPC_X86_AVX512F
#   define  SPC_X86_AVX512F
#   endif
#endif

#if defined(__AVX2__) || defined(SPC_X86_AVX512F)
#   ifndef  SPC_X86_AVX2
#   define  SPC_X86_AVX2
#   endif
#endif

#if defined(__AVX__) || defined(SPC_X86_AVX2)
#   ifndef  SPC_X86_AVX
#   define  SPC_X86_AVX
#   endif
#endif

#if defined(__SSE4_2__) || defined(SPC_X86_AVX)
#   ifndef  SPC_X86_SSE42
#   define  SPC_X86_SSE42
#   endif
#endif

#if defined(__SSE4_1__) || defined(SPC_X86_SSE42)
#   ifndef  SPC_X86_SSE41
#   define  SPC_X86_SSE41
#   endif
#endif

#if defined(__SSSE3__) || defined(SPC_X86_SSE41)
#   ifndef  SPC_X86_SSSE3
#   define  SPC_X86_SSSE3
#   endif
#endif

#if defined(__SSE3__) || defined(SPC_X86_SSSE3)
#   ifndef  SPC_X86_SSE3
#   define  SPC_X86_SSE3
#   endif
#endif

#if defined(__SSE2__) || defined(SPC_X86_SSE3)
#   ifndef  SPC_X86_SSE2
#   define  SPC_X86_SSE2
#   endif
#endif

#if defined(__SSE__) || defined(SPC_X86_SSE2)
#   ifndef  SPC_X86_SSE
#   define  SPC_X86_SSE
#   endif
#endif

#if defined(__MMX__) || defined(SPC_X86_SSE)
#   ifndef  SPC_X86_MMX
#   define  SPC_X86_MMX
#   endif
#endif

#if _LEAVE_EXTDEF_SPC_X86
}
#endif

#if (MY_ISA==ISA_RV) || (MY_ISA==ISA_PPC)
#   ifndef  MY_ENDIAN
#   define  MY_ENDIAN                       \
(                                           \
    (__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)  \
    ?   ENDIAN_BIG                          \
    :   ENDIAN_LIL                          \
)
#   endif

#endif

#ifndef MY_ENDIAN
#define MY_ENDIAN   ENDIAN_LIL
#endif

#ifndef MY_VECTOR_ENDIAN
#define MY_VECTOR_ENDIAN    MY_ENDIAN
#endif

#if MY_VECTOR_ENDIAN == ENDIAN_NAT
#   undef   MY_VECTOR_ENDIAN
#   define  MY_VECTOR_ENDIAN    MY_ENDIAN
#endif

#ifndef MY_PAGESZ
#define MY_PAGESZ    (4096)
#endif

#define CONCAT1(_0,            ...) _0##__VA_ARGS__
#define CONCAT2(_0, _1,        ...) _0##__VA_ARGS__##_1
#define CONCAT3(_0, _1, _2,    ...) _0##__VA_ARGS__##_1##__VA_ARGS__##_2

#define MY_CONCAT1(_0,         ...) _0##__VA_ARGS__
#define MY_CONCAT2(_0, _1,     ...) _0##__VA_ARGS__##_1
#define MY_CONCAT3(_0, _1, _2, ...) _0##__VA_ARGS__##_1##__VA_ARGS__##_2

#define MY_STRIFY(prefix, string) prefix ## string
#define MY_LCSIFY(...) MY_STRIFY(L, #__VA_ARGS__)
#define MY_UCSIFY(...) MY_STRIFY(u, #__VA_ARGS__)
#define MY_WCSIZE(...) MY_STRIFY(U, #__VA_ARGS__)

#define MY_C16IZE0(...) MY_WCSIZE( u, #__VA_ARGS__)
#define MY_C16IZE1(...) MY_C16IZE0(__VA_ARGS__)
#define MY_C16IZE2(...) MY_C16IZE1(__VA_ARGS__)
#define MY_C16IZE3(...) MY_C16IZE2(__VA_ARGS__)
#define MY_C16IZE4(...) MY_C16IZE3(__VA_ARGS__)
#define MY_C16IZE5(...) MY_C16IZE4(__VA_ARGS__)
#define MY_C16IZE6(...) MY_C16IZE5(__VA_ARGS__)
#define MY_C16IZE7(...) MY_C16IZE6(__VA_ARGS__)
#define MY_C16IZE8(...) MY_C16IZE7(__VA_ARGS__)

#define MY_C32IZE0(...) MY_WCSIZE( U, #__VA_ARGS__)
#define MY_C32IZE1(...) MY_C32IZE0(__VA_ARGS__)
#define MY_C32IZE2(...) MY_C32IZE1(__VA_ARGS__)
#define MY_C32IZE3(...) MY_C32IZE2(__VA_ARGS__)
#define MY_C32IZE4(...) MY_C32IZE3(__VA_ARGS__)
#define MY_C32IZE5(...) MY_C32IZE4(__VA_ARGS__)
#define MY_C32IZE6(...) MY_C32IZE5(__VA_ARGS__)
#define MY_C32IZE7(...) MY_C32IZE6(__VA_ARGS__)
#define MY_C32IZE8(...) MY_C32IZE7(__VA_ARGS__)

#define MY_STRIZE0(...)           #__VA_ARGS__
#define MY_STRIZE1(...) MY_STRIZE0(__VA_ARGS__)
#define MY_STRIZE2(...) MY_STRIZE1(__VA_ARGS__)
#define MY_STRIZE3(...) MY_STRIZE2(__VA_ARGS__)
#define MY_STRIZE4(...) MY_STRIZE3(__VA_ARGS__)
#define MY_STRIZE5(...) MY_STRIZE4(__VA_ARGS__)
#define MY_STRIZE6(...) MY_STRIZE5(__VA_ARGS__)
#define MY_STRIZE7(...) MY_STRIZE6(__VA_ARGS__)
#define MY_STRIZE8(...) MY_STRIZE7(__VA_ARGS__)

#define STRIZE0(...)           #__VA_ARGS__
#define STRIZE1(...) MY_STRIZE0(__VA_ARGS__)
#define STRIZE2(...) MY_STRIZE1(__VA_ARGS__)
#define STRIZE3(...) MY_STRIZE2(__VA_ARGS__)
#define STRIZE4(...) MY_STRIZE3(__VA_ARGS__)
#define STRIZE5(...) MY_STRIZE4(__VA_ARGS__)
#define STRIZE6(...) MY_STRIZE5(__VA_ARGS__)
#define STRIZE7(...) MY_STRIZE6(__VA_ARGS__)
#define STRIZE8(...) MY_STRIZE7(__VA_ARGS__)

#define MY_EXPAND8(...) MY_EXPAND7(__VA_ARGS__)
#define MY_EXPAND7(...) MY_EXPAND6(__VA_ARGS__)
#define MY_EXPAND6(...) MY_EXPAND5(__VA_ARGS__)
#define MY_EXPAND5(...) MY_EXPAND4(__VA_ARGS__)
#define MY_EXPAND4(...) MY_EXPAND3(__VA_ARGS__)
#define MY_EXPAND3(...) MY_EXPAND2(__VA_ARGS__)
#define MY_EXPAND2(...) MY_EXPAND1(__VA_ARGS__)
#define MY_EXPAND1(...)            __VA_ARGS__

#define EXPAND8(...)    MY_EXPAND7(__VA_ARGS__)
#define EXPAND7(...)    MY_EXPAND6(__VA_ARGS__)
#define EXPAND6(...)    MY_EXPAND5(__VA_ARGS__)
#define EXPAND5(...)    MY_EXPAND4(__VA_ARGS__)
#define EXPAND4(...)    MY_EXPAND3(__VA_ARGS__)
#define EXPAND3(...)    MY_EXPAND2(__VA_ARGS__)
#define EXPAND2(...)    MY_EXPAND1(__VA_ARGS__)
#define EXPAND1(...)               __VA_ARGS__

#define SAFECALL(TYPE, _, FUNC, ...) \
_Generic((_), TYPE:FUNC(__VA_ARGS__))

#define MY_CALL(F, ...) F(__VA_ARGS__)
#define _SWAP(a, b) do                      \
{                                           \
    char _SWAP[sizeof(a)];                  \
    (void) memcpy(_SWAP, &(a), sizeof(a));  \
    (a)=(b);                                \
    (void) memcpy(&(b), _SWAP, sizeof(a));  \
} while(0)

#define DUP1(_1, ...) \
_1 __VA_ARGS__

#define DUP2(_2, ...) \
_2 __VA_ARGS__ _2

#define DUP3(_3, ...) \
_3 __VA_ARGS__ _3 __VA_ARGS__ _3

#define DUP4(_4, ...) \
_4 __VA_ARGS__ _4 __VA_ARGS__ _4 __VA_ARGS__ _4

#define DUP5(_5, ...) \
_5 __VA_ARGS__ _5 __VA_ARGS__ _5 __VA_ARGS__ _5 __VA_ARGS__ \
_5

#define DUP6(_6, ...) \
_6 __VA_ARGS__ _6 __VA_ARGS__ _6 __VA_ARGS__ _6 __VA_ARGS__ \
_6 __VA_ARGS__ _6

#define DUP7(_7, ...) \
_7 __VA_ARGS__ _7 __VA_ARGS__ _7 __VA_ARGS__ _7 __VA_ARGS__ \
_7 __VA_ARGS__ _7 __VA_ARGS__ _7

#define DUP8(_8, ...) \
_8 __VA_ARGS__ _8 __VA_ARGS__ _8 __VA_ARGS__ _8 __VA_ARGS__ \
_8 __VA_ARGS__ _8 __VA_ARGS__ _8 __VA_ARGS__ _8

#define DUP9(_9, ...) \
_9 __VA_ARGS__ _9 __VA_ARGS__ _9 __VA_ARGS__ _9 __VA_ARGS__ \
_9 __VA_ARGS__ _9 __VA_ARGS__ _9 __VA_ARGS__ _9 __VA_ARGS__ \
_9

#define DUP10(_A, ...) \
_A __VA_ARGS__ _A __VA_ARGS__ _A __VA_ARGS__ _A __VA_ARGS__ \
_A __VA_ARGS__ _A __VA_ARGS__ _A __VA_ARGS__ _A __VA_ARGS__ \
_A __VA_ARGS__ _A

#define DUP11(_B, ...) \
_B __VA_ARGS__ _B __VA_ARGS__ _B __VA_ARGS__ _B __VA_ARGS__ \
_B __VA_ARGS__ _B __VA_ARGS__ _B __VA_ARGS__ _B __VA_ARGS__ \
_B __VA_ARGS__ _B __VA_ARGS__ _B

#define DUP12(_C, ...) \
_C __VA_ARGS__ _C __VA_ARGS__ _C __VA_ARGS__ _C __VA_ARGS__ \
_C __VA_ARGS__ _C __VA_ARGS__ _C __VA_ARGS__ _C __VA_ARGS__ \
_C __VA_ARGS__ _C __VA_ARGS__ _C __VA_ARGS__ _C

#define DUP13(_D, ...) \
_D __VA_ARGS__ _D __VA_ARGS__ _D __VA_ARGS__ _D __VA_ARGS__ \
_D __VA_ARGS__ _D __VA_ARGS__ _D __VA_ARGS__ _D __VA_ARGS__ \
_D __VA_ARGS__ _D __VA_ARGS__ _D __VA_ARGS__ _D __VA_ARGS__ \
_D

#define DUP14(_E, ...) \
_E __VA_ARGS__ _E __VA_ARGS__ _E __VA_ARGS__ _E __VA_ARGS__ \
_E __VA_ARGS__ _E __VA_ARGS__ _E __VA_ARGS__ _E __VA_ARGS__ \
_E __VA_ARGS__ _E __VA_ARGS__ _E __VA_ARGS__ _E __VA_ARGS__ \
_E __VA_ARGS__ _E

#define DUP15(_F, ...) \
_F __VA_ARGS__ _F __VA_ARGS__ _F __VA_ARGS__ _F __VA_ARGS__ \
_F __VA_ARGS__ _F __VA_ARGS__ _F __VA_ARGS__ _F __VA_ARGS__ \
_F __VA_ARGS__ _F __VA_ARGS__ _F __VA_ARGS__ _F __VA_ARGS__ \
_F __VA_ARGS__ _F __VA_ARGS__ _F

#define DUP16(_X, ...) \
_X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ \
_X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ \
_X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ \
_X __VA_ARGS__ _X __VA_ARGS__ _X __VA_ARGS__ _X

#define MY_DUF2(_F, _2, ...)                    \
_F(_2,__VA_ARGS__)__VA_ARGS__ _F(_2,__VA_ARGS__)

#define MY_DUF4(_F, _4, ...)                     \
_F(_4,__VA_ARGS__)__VA_ARGS__ _F(_4,__VA_ARGS__) \
_F(_4,__VA_ARGS__)__VA_ARGS__ _F(_4,__VA_ARGS__)

#define MY_DUF8(_F, _8, ...)                     \
_F(_8,__VA_ARGS__)__VA_ARGS__ _F(_8,__VA_ARGS__) \
_F(_8,__VA_ARGS__)__VA_ARGS__ _F(_8,__VA_ARGS__) \
_F(_8,__VA_ARGS__)__VA_ARGS__ _F(_8,__VA_ARGS__) \
_F(_8,__VA_ARGS__)__VA_ARGS__ _F(_8,__VA_ARGS__)

#define MY_DUFF(_F, _P, _N, ...) _F(_P,_N,__VA_ARGS__)


#define MY_DUP32(...)   MY_DUFF(MY_DUF2,DUP16,__VA_ARGS__)
#define MY_DUP64(...)   MY_DUFF(MY_DUF4,DUP16,__VA_ARGS__)
#define MY_DUP128(...)  MY_DUFF(MY_DUF8,DUP16,__VA_ARGS__)

#define MY_EXTZ1(c, v, i, x, ...)   c((v)[(i)+x*0])
#define MY_EXTZ2(c, v, i, x, ...)   \
    c((v)[(i)]), c((v)[(i)+x])
#define MY_EXTZ4(c, v, i, x, ...)   \
    c((v)[(i)    ]), c((v)[(i)+x  ]),\
    c((v)[(i)+x*2]), c((v)[(i)+x*3])
#define MY_EXTZ8(c, v, i, x, ...)   \
    c((v)[(i)    ]), c((v)[(i)+x  ]),\
    c((v)[(i)+x*2]), c((v)[(i)+x*3]),\
    c((v)[(i)+x*4]), c((v)[(i)+x*5]),\
    c((v)[(i)+x*6]), c((v)[(i)+x*7])
#define MY_EXTZ16(c, v, i, x, ...)  \
    MY_EXTZ8(c, v,  i,      x),     \
    MY_EXTZ8(c, v, (i)+x*8, x)
#define MY_EXTZ32(c, v, i, x, ...) \
    MY_EXTZ16(c, v,  i ,      x),   \
    MY_EXTZ16(c, v, (i)+x*16, x)
#define MY_EXTZ64(c, v, i, x, ...)  \
    MY_EXTZ32(c, v,  i ,      x),   \
    MY_EXTZ32(c, v, (i)+x*32, x)
#define MY_EXTC1(c, v, i, ...)  \
    MY_EXTZ1(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC2(c, v, i, ...)  \
    MY_EXTZ2(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC4(c, v, i, ...)  \
    MY_EXTZ4(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC8(c, v, i, ...)  \
    MY_EXTZ8(c,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC16(c, v, i, ...)  \
    MY_EXTZ16(c, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC32(c, v, i, ...)  \
    MY_EXTZ32(c, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTC64(c, v, i, ...)  \
    MY_EXTZ64(c, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI1(v, i, ...)  \
    MY_EXTZ1(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI2(v, i, ...)  \
    MY_EXTZ2(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI4(v, i, ...)  \
    MY_EXTZ4(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI8(v, i, ...)  \
    MY_EXTZ8(IDENTITY,  v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI16(v, i, ...)  \
    MY_EXTZ16(IDENTITY, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI32(v, i, ...)  \
    MY_EXTZ32(IDENTITY, v, i, __VA_OPT__(__VA_ARGS__, ) 1)
#define MY_EXTI64(v, i, ...)  \
    MY_EXTZ64(IDENTITY, v, i, __VA_OPT__(__VA_ARGS__, ) 1)

#if 0
#define MY_SEQC1( c, n, x, ...) c(n+x* 0)
#define MY_SEQC2( c, n, x, ...) c(n+x* 0),c(n+x* 1)
#define MY_SEQC4( c, n, x, ...) \
c(n+x* 0),c(n+x* 1),c(n+x* 2), c(n+x* 3)
#define MY_SEQC8( c,n,x,...)            \
c(n+x*0),c(n+x*1),c(n+x*2),c(n+x*3),    \
c(n+x*4),c(n+x*5),c(n+x*6),c(n+x*7)
#define MY_SEQC16(c,n,x,...)            \
c(n+x* 0),c(n+x* 1),c(n+x* 2),c(n+x* 3),\
c(n+x* 4),c(n+x* 5),c(n+x* 6),c(n+x* 7),\
c(n+x* 8),c(n+x* 9),c(n+x*10),c(n+x*11),\
c(n+x*12),c(n+x*13),c(n+x*14),c(n+x*15)
#define MY_SEQC32(c,n,x,...)            \
c(n+x* 0),c(n+x* 1),c(n+x* 2),c(n+x* 3),\
c(n+x* 4),c(n+x* 5),c(n+x* 6),c(n+x* 7),\
c(n+x* 8),c(n+x* 9),c(n+x*10),c(n+x*11),\
c(n+x*12),c(n+x*13),c(n+x*14),c(n+x*15),\
c(n+x*16),c(n+x*17),c(n+x*18),c(n+x*19),\
c(n+x*20),c(n+x*21),c(n+x*22),c(n+x*23),\
c(n+x*24),c(n+x*25),c(n+x*26),c(n+x*27),\
c(n+x*28),c(n+x*29),c(n+x*30),c(n+x*31)
#define MY_SEQC64(c,n,x,...)            \
c(n+x* 0),c(n+x* 1),c(n+x* 2),c(n+x* 3),\
c(n+x* 4),c(n+x* 5),c(n+x* 6),c(n+x* 7),\
c(n+x* 8),c(n+x* 9),c(n+x*10),c(n+x*11),\
c(n+x*12),c(n+x*13),c(n+x*14),c(n+x*15),\
c(n+x*16),c(n+x*17),c(n+x*18),c(n+x*19),\
c(n+x*20),c(n+x*21),c(n+x*22),c(n+x*23),\
c(n+x*24),c(n+x*25),c(n+x*26),c(n+x*27),\
c(n+x*28),c(n+x*29),c(n+x*30),c(n+x*31),\
c(n+x*32),c(n+x*33),c(n+x*34),c(n+x*35),\
c(n+x*36),c(n+x*37),c(n+x*38),c(n+x*39),\
c(n+x*40),c(n+x*41),c(n+x*42),c(n+x*43),\
c(n+x*44),c(n+x*45),c(n+x*46),c(n+x*47),\
c(n+x*48),c(n+x*49),c(n+x*50),c(n+x*51),\
c(n+x*52),c(n+x*53),c(n+x*54),c(n+x*55),\
c(n+x*56),c(n+x*57),c(n+x*58),c(n+x*59),\
c(n+x*60),c(n+x*61),c(n+x*62),c(n+x*63)
#define SEQC1( c,n,...)  MY_SEQC1( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC2( c,n,...)  MY_SEQC2( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC4( c,n,...)  MY_SEQC4( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC8( c,n,...)  MY_SEQC8( c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC16(c,n,...)  MY_SEQC16(c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC32(c,n,...)  MY_SEQC32(c,n,__VA_OPT__(__VA_ARGS__,) 1)
#define SEQC64(c,n,...)  MY_SEQC64(c,n,__VA_OPT__(__VA_ARGS__,) 1)

#endif

#define     SEQC1(C, N, X)              \
N+X*C(0)

#define     SEQC2(C, N, X)              \
N+X*C( 0),N+X*C( 1)

#define     SEQC3(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2)

#define     SEQC4(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3)

#define     SEQC5(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4)

#define     SEQC6(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5)

#define     SEQC7(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6)

#define     SEQC8(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7)

#define     SEQC9(C, N, X)              \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8)

#define     SEQC10(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9)

#define     SEQC11(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10)

#define     SEQC12(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11)

#define     SEQC13(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12)

#define     SEQC14(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12),N+X*C(13)

#define     SEQC15(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12),N+X*C(13),N+X*C(14)

#define     SEQC16(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12),N+X*C(13),N+X*C(14),N+X*C(15)


#define     SEQC17(C, N, X) SEQ16(C,N,X),\
N+X*C(16)

#define     SEQC18(C, N, X) SEQ16(C,N,X),\
N+X*C(16),N+X*C(17)

#define     SEQC19(C, N, X) SEQ16(C,N,X),\
N+X*C(16),N+X*C(17),N+X*C(18)

#define     SEQC20(C, N, X) SEQ16(C,N,X),   \
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19)

#define     SEQC21(C, N, X) SEQ16(C,N,X),   \
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),    \
N+X*C(20)

#define     SEQC22(C, N, X) SEQ16(C,N,X),   \
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),    \
N+X*C(20),N+X*C(21)

#define     SEQC23(C, N, X) SEQ16(C,N,X),   \
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),    \
N+X*C(20),N+X*C(21),N+X*C(22)

#define     SEQC24(C, N, X) SEQ16(C,N,X),   \
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),    \
N+X*C(20),N+X*C(21),N+X*C(22),N+X*C(23)


#define     SEQC25(C, N, X)                 \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),    \
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),    \
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),    \
N+X*C(12),N+X*C(13),N+X*C(14),N+X*C(15),    \
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),    \
N+X*C(20),N+X*C(21),N+X*C(22),N+X*C(23),    \
N+X*C(24)


#define     SEQC26(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12),N+X*C(13),N+X*C(14),N+X*C(15),\
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),\
N+X*C(20),N+X*C(21),N+X*C(22),N+X*C(23),\
N+X*C(24),N+X*C(25)

#define     SEQC27(C, N, X) SEQC26(C,N,X),\
N+X*C(26)

#define     SEQC28(C, N, X) SEQC26(C,N,X),\
N+X*C(26),N+X*C(27)

#define     SEQC29(C, N, X) SEQC26(C,N,X),\
N+X*C(26),N+X*C(27),N+X*C(28)

#define     SEQC30(C, N, X) SEQC26(C,N,X),\
N+X*C(26),N+X*C(27),N+X*C(28),N+X*C(29)

#define     SEQC31(C, N, X) SEQC26(C,N,X),\
N+X*C(26),N+X*C(27),N+X*C(28),N+X*C(29),N+X*C(30)

#define     SEQC32(C, N, X)             \
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12),N+X*C(13),N+X*C(14),N+X*C(15),\
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),\
N+X*C(20),N+X*C(21),N+X*C(22),N+X*C(23),\
N+X*C(24),N+X*C(25),N+X*C(26),N+X*C(27),\
N+X*C(28),N+X*C(29),N+X*C(30),N+X*C(31)


#define     SEQC64(C, N, X) SEQC32(C,N,X),\
N+X*C( 0),N+X*C( 1),N+X*C( 2),N+X*C( 3),\
N+X*C( 4),N+X*C( 5),N+X*C( 6),N+X*C( 7),\
N+X*C( 8),N+X*C( 9),N+X*C(10),N+X*C(11),\
N+X*C(12),N+X*C(13),N+X*C(14),N+X*C(15),\
N+X*C(16),N+X*C(17),N+X*C(18),N+X*C(19),\
N+X*C(20),N+X*C(21),N+X*C(22),N+X*C(23),\
N+X*C(24),N+X*C(25),N+X*C(26),N+X*C(27),\
N+X*C(28),N+X*C(29),N+X*C(30),N+X*C(31),\
N+X*C(32),N+X*C(33),N+X*C(34),N+X*C(35),\
N+X*C(36),N+X*C(37),N+X*C(38),N+X*C(39),\
N+X*C(40),N+X*C(41),N+X*C(42),N+X*C(43),\
N+X*C(44),N+X*C(45),N+X*C(46),N+X*C(47),\
N+X*C(48),N+X*C(49),N+X*C(50),N+X*C(51),\
N+X*C(52),N+X*C(53),N+X*C(54),N+X*C(55),\
N+X*C(56),N+X*C(57),N+X*C(58),N+X*C(59),\
N+X*C(60),N+X*C(61),N+X*C(62),N+X*C(63)


#define     MY_SEQI(_) _

#define     SEQI1(N,X) SEQC1(MY_SEQI,N,X)
#define     SEQI2(N,X) SEQC2(MY_SEQI,N,X)
#define     SEQI4(N,X) SEQC4(MY_SEQI,N,X)

#define HALF_BYTEMASK(k)   (UINT16_C(0xff)<<((k)<<3))
#define WORD_BYTEMASK(k)   (UINT32_C(0x00ff)<<((k)<<3))
#define WORD_HALFMASK(k)   (UINT32_C(0xffff)<<((k)<<4))
#define DWRD_BYTEMASK(k)   (UINT64_C(0x000000ff)<<((k)<<3))
#define DWRD_HALFMASK(k)   (UINT64_C(0x0000ffff)<<((k)<<4))
#define DWRD_WORDMASK(k)   (UINT64_C(0xffffffff)<<((k)<<5))

typedef unsigned char        uchar;
typedef   signed char        schar;
typedef unsigned short       ushrt, ushort, ndig_t;
typedef   signed short        shrt;
typedef unsigned int          uint;
typedef unsigned long        ulong;
typedef unsigned long long  ullong;
typedef   signed long long   llong;

#define NDIG_MAX (65535)
#define NDIG_MIN (0)
#define NDIG_C(C) (C)
#define MY_CALL1(F, ...)    F(__VA_ARGS__)
#define MY_CALL2(F, ...)    MY_CALL1(F, __VA_ARGS__)
#define MY_CALL3(F, ...)    MY_CALL2(F, __VA_ARGS__)
#define MY_CALL4(F, ...)    MY_CALL3(F, __VA_ARGS__)

#endif // EOF

#if _LEAVE_EXTDEF
}
#endif

#if _ENTER_EXTNUM
{
#endif

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

<extnum.h>

    This file combines and extends the following C11 standard
    library headers:

    * <float.h>
    * <stdalign.h>
    * <stdbool.h>
    * <stddef.h>
    * <stdint.h>
*/
#ifndef MY_EXTNUM_H // BOF("extnum.h")
#define MY_EXTNUM_H

#ifndef MY_FLOAT_H
#define MY_FLOAT_H
#define __STDC_WANT_IEC_60559_TYPES_EXT__
#include <float.h>
#endif

#ifndef MY_STDINT_H
#define MY_STDINT_H
#include  <stdint.h>
#endif

#ifndef MY_EXTDEF_H
#include  "extdef.h"
#endif

#define DEFINE_GBM(S,W,K,M) ((M>>(K-W))<<S)

#define DEFINE_YBM(I)   (1u<<I##_BFS)
#define DEFINE_BBM(I,W) DEFINE_GBM(I##_BFS, W, 0010, 0xffu)
#define DEFINE_HBM(I,W) DEFINE_GBM(I##_BFS, W, 0020, 0xffffu)
#define DEFINE_WBM(I,W) DEFINE_GBM(I##_BFS, W, 0040, 0xffffffffu)
#define DEFINE_DBM(I,W) DEFINE_GBM(I##_BFS, W, 0100, 0xffffffffffffffffu)

#define MY_TGSN(_, F) F(_)

#if _ENTER_EXTNUM_NB
{
#endif
/*  Numeric classification
            <math.h>
    0                       NB_ZERO
    +0.0    FP_ZERO         NB_ZERO
    -0.0    FP_ZERO         NB_ZERO|NB_SIGN
    +1.0    FP_NORMAL       NB_NORM
    -1.0    FP_NORMAL       NB_NORM|NB_SIGN
            FP_SUBNORMAL    NB_TINY
            FP_INFINITY     NB_HUGE
    +inf    FP_INFINITY     NB_PINF = (NB_HUGE)
    -inf    FP_INFINITY     NB_NINF = (NB_HUGE|NB_SIGN)
    ±qnan   FP_NAN          NB_QNAN
    ±snan   FP_NAN          NB_SNAN
*/

#define NB_ZERO (0x00)              // zero
#define NB_NORM (0x01)              // normal
#define NB_TINY (0x02)              // subnormal
#define NB_HUGE (0x04)              // infinity
#define NB_QNAN (NB_TINY|NB_HUGE)   // NaN
#define NB_SNAN (NB_QNAN|NB_SIGN)   // NaN (signaling)
#define NB_SIGN (0x80)              // signed
#define NB_PINF (NB_HUGE)           // +∞
#define NB_NINF (NB_HUGE|NB_SIGN)   // -∞

#if _LEAVE_EXTNUM_NB
}
#endif

#if _ENTER_EXTNUM_DR
{
#endif

/*  Directed rounding modes:

    * DR_ZERO
        Toward zero, aka 'trunc'
        -2.1 => -2.0
        -1.9 => -1.0
        +1.9 => +1.0
        +2.1 => +2.0

    * DR_NEXT
        Toward the integer furthest from zero, i.e. to ±∞
        -2.1 => -3.0
        -1.9 => -2.0
        +1.9 => +2.0
        +2.1 => +3.0

    * DR_PINF
        Toward +∞, aka 'ceil'
        -2.1 => -2.0
        -1.9 => -1.0
        +1.9 => +2.0
        +2.1 => +3.0

    * DR_NINF
        Toward -∞, aka 'floor'
        -2.1 => -3.0
        -1.9 => -2.0
        +1.9 => +1.0
        +2.1 => +2.0

    * DR_EVEN
        Toward the closest even integer
        -2.1 => -2.0
        -1.9 => -2.0
        +1.1 => +2.0
        +2.1 => +2.0

    * DR_ODD
        Toward the closest odd integer
        -1.9 => -1.0
        -2.1 => -3.0
        +1.9 => +1.0
        +2.1 => +3.0

    * DR_NEAR
        Toward the nearest integer. May be combined with
        one of the others to control what happens on ties.
        Alone, ties are broken according to the current
        floating point environment.

*/

#define DR_NONE (0)
#define DR_ODD  (0b0001)
#define DR_EVEN (0b0010)
#define DR_NINF (0b0011)
#define DR_PINF (0b0100)
#define DR_NEXT (0b0101)
#define DR_ZERO (0b0110)
#define DR_DONT (0b0111)

#define DR_NEAR (0b1000)

#if _LEAVE_EXTNUM_DR
}
#endif

#if _ENTER_EXTNUM_ATTRS
{
#endif

#define BYTE_(_)    BYTE_##_
#define BYTE_TYPE   union Byte
#define BYTE_UTYPE  unsigned char
#define BYTE_ITYPE  signed char
#define BYTE_U      UCHAR_
#define BYTE_I      SCHAR_
#define BYTE_SN(_)  _##b
#define BYTE_SNU(_) _##bu
#define BYTE_SNI(_) _##bi
#define BYTE_SNC(_) _##bc
#define BYTE_LOG2SZ (0)
#define BYTE_SIZE   SIZE_C(1)
#define BYTE_WIDTH  NDIG_C(8)
#define BYTE_UDIG   NDIG_C(3)   // "255"
#define BYTE_IDIG   NDIG_C(4)   // "±127"
#define BYTE_XDIG   NDIG_C(2)   // "7f"
#define BYTE_ODIG   NDIG_C(3)   // "377"
#define BYTE_IMIN   ((BYTE_TYPE){.I=BYTE_I(MIN)})
#define BYTE_IMAX   ((BYTE_TYPE){.I=BYTE_I(MAX)})
#define BYTE_UMAX   ((BYTE_TYPE){.U=BYTE_U(MAX)})

#define HALF_(_)    HALF_##_
#define HALF_UTYPE  unsigned short
#define HALF_ITYPE  short
#define HALF_FTYPE  flt16_t
#define HALF_TYPE   union Half
#define HALF_LOTYPE union Byte
#define HALF_HITYPE union Byte
#define HALF_U      USHRT_
#define HALF_I      SHRT_
#define HALF_F      FLT16_
#define HALF_LO     BYTE_
#define HALF_HI     BYTE_
#define HALF_SN(_)  _##h
#define HALF_SNU(_) _##hu
#define HALF_SNI(_) _##hi
#define HALF_SNF(_) _##hf
#define HALF_LOG2SZ (1)
#define HALF_SIZE   (WORD_SIZE>>1)
#define HALF_WIDTH  NDIG_C(16)
#define HALF_UDIG   NDIG_C(5)   // "65535"
#define HALF_IDIG   NDIG_C(6)   // "-32768"
#define HALF_XDIG   NDIG_C(4)   // "7fff"
#define HALF_ODIG   NDIG_C(6)   // "177777"
#define HALF_IMIN   ((HALF_TYPE){.I=HALF_I(MIN)})
#define HALF_IMAX   ((HALF_TYPE){.I=HALF_I(MAX)})
#define HALF_UMAX   ((HALF_TYPE){.U=HALF_U(MAX)})
#define HALF_NMIN   ((HALF_TYPE){.U=UINT16_C(0x8400)})
#define HALF_PMIN   ((HALF_TYPE){.U=UINT16_C(0x0400)})
#define HALF_NMAX   ((HALF_TYPE){.U=UINT16_C(0xfbff)})
#define HALF_PMAX   ((HALF_TYPE){.U=UINT16_C(0x7bff)})
#define HALF_NINF   ((HALF_TYPE){.U=UINT16_C(0xfc00)})
#define HALF_PINF   ((HALF_TYPE){.U=UINT16_C(0x7c00)})
#define HALF_QNAN   ((HALF_TYPE){.U=UINT16_C(0x7e00)})

#define WORD_(_)    WORD_ ## _
#define WORD_TYPE   union Word
#define WORD_LOTYPE union Half
#define WORD_HITYPE union Half
#define WORD_UTYPE  unsigned int
#define WORD_ITYPE  int
#define WORD_FTYPE  float
#define WORD_U      UINT_
#define WORD_I      INT_
#define WORD_F      FLT_
#define WORD_LO     HALF_
#define WORD_HI     HALF_
#define WORD_SN(_)  _##w
#define WORD_SNU(_) _##wu
#define WORD_SNI(_) _##wi
#define WORD_SNF(_) _##wf
#define WORD_LOG2SZ (2)
#define WORD_SIZE   SIZE_C(4)
#define WORD_WIDTH  NDIG_C(32)
#define WORD_UDIG   NDIG_C(10)  // "4294967295"
#define WORD_IDIG   NDIG_C(11)  // "-2147483648"
#define WORD_XDIG   NDIG_C(8)   // "7fffffff"
#define WORD_ODIG   NDIG_C(11)  // "37777777777"
#define WORD_IMIN   ((WORD_TYPE){.I=WORD_I(MIN)})
#define WORD_IMAX   ((WORD_TYPE){.I=WORD_I(MAX)})
#define WORD_UMAX   ((WORD_TYPE){.U=WORD_U(MAX)})
#define WORD_NMIN   ((WORD_TYPE){.U=UINT32_C(0x80800000)})
#define WORD_PMIN   ((WORD_TYPE){.U=UINT32_C(0x00800000)})
#define WORD_NMAX   ((WORD_TYPE){.U=UINT32_C(0xff7fffff)})
#define WORD_PMAX   ((WORD_TYPE){.U=UINT32_C(0x7f7fffff)})
#define WORD_NINF   ((WORD_TYPE){.U=UINT32_C(0xff800000)})
#define WORD_PINF   ((WORD_TYPE){.U=UINT32_C(0x7f800000)})
#define WORD_QNAN   ((WORD_TYPE){.U=UINT32_C(0x7fc00000)})

#define DWRD_(_)    DWRD_ ## _
#define DWRD_TYPE   union Dwrd
#define DWRD_LOTYPE union Word
#define DWRD_HITYPE union Word
#define DWRD_FTYPE  double
#define DWRD_LO     WORD_
#define DWRD_HI     WORD_
#define DWRD_F      DBL_
#define DWRD_SN(_)  _##d
#define DWRD_SNU(_) _##du
#define DWRD_SNI(_) _##di
#define DWRD_SNF(_) _##df
#define DWRD_LOG2SZ (3)
#define DWRD_SIZE   (2*WORD_SIZE)
#define DWRD_WIDTH  NDIG_C(64)
#define DWRD_ODIG   NDIG_C(22)  // "1777777777777777777777"
#define DWRD_UDIG   NDIG_C(20)  // "18446744073709551615"
#define DWRD_IDIG   NDIG_C(20)  // "±9223372036854775808"
#define DWRD_XDIG   NDIG_C(16)  // "7fffffffffffffff"
#define DWRD_FDIG   NDIG_C(17)  // "±9.99999999999999"
#define DWRD_EDIG   NDIG_C(21)  // "±9.9999999999999e-200"
#define DWRD_UMAX   ((DWRD_TYPE){.U=DWRD_U(MAX)})
#define DWRD_IMAX   ((DWRD_TYPE){.I=DWRD_I(MAX)})
#define DWRD_IMIN   ((DWRD_TYPE){.I=DWRD_I(MIN)})
#define DWRD_NMIN   ((DWRD_TYPE){.U=UINT64_C(0x8010000000000000)})
#define DWRD_PMIN   ((DWRD_TYPE){.U=UINT64_C(0x0010000000000000)})
#define DWRD_NMAX   ((DWRD_TYPE){.U=UINT64_C(0xffefffffffffffff)})
#define DWRD_PMAX   ((DWRD_TYPE){.U=UINT64_C(0x7fefffffffffffff)})
#define DWRD_NINF   ((DWRD_TYPE){.U=UINT64_C(0xfff0000000000000)})
#define DWRD_PINF   ((DWRD_TYPE){.U=UINT64_C(0x7ff0000000000000)})
#define DWRD_QNAN   ((DWRD_TYPE){.U=UINT64_C(0x7ff8000000000000)})

#define QUAD_(_)    QUAD_##_
#define QUAD_SN(_)  _##q
#define QUAD_SNU(_) _##qu
#define QUAD_SNI(_) _##qi
#define QUAD_SNF(_) _##qf
#define QUAD_TYPE   union Quad
#define QUAD_LOTYPE union Dwrd
#define QUAD_HITYPE union Dwrd
#define QUAD_F      FLT128_
#define QUAD_LO     DWRD_
#define QUAD_HI     DWRD_
#define QUAD_LOG2SZ (4)
#define QUAD_SIZE   (4*WORD_SIZE)
#define QUAD_WIDTH  NDIG_C(128)
// "-170141183460469231731687303715884105728"
// "340282366920938463463374607431768211455"
#define QUAD_IDIG   NDIG_C(40)
#define QUAD_UDIG   NDIG_C(39)
#define QUAD_FDIG   NDIG_C(33)
#define QUAD_IMIN   ((QUAD_TYPE){.I=QUAD_I(MIN)})
#define QUAD_IMAX   ((QUAD_TYPE){.I=QUAD_I(MAX)})
#define QUAD_UMAX   ((QUAD_TYPE){.I=QUAD_U(MAX)})

// Minimum negative normal number representation
#define QUAD_NMIN   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000), \
        .Hi.U=UINT64_C(0x8001000000000000), \
    }               \
)
// Minimum positive normal number representation
#define QUAD_PMIN   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000),   \
        .Hi.U=UINT64_C(0x0001000000000000),   \
    }               \
)


// Maximum negative normal number representation
#define QUAD_NMAX   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0xffffffffffffffff),   \
        .Hi.U=UINT64_C(0xfffeffffffffffff),   \
    }               \
)

// Maximum positive normal number representation
#define QUAD_PMAX   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0xffffffffffffffff),   \
        .Hi.U=UINT64_C(0x7ffeffffffffffff),   \
    }               \
)

// -∞ representation
#define QUAD_NINF   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000),   \
        .Hi.U=UINT64_C(0xffff000000000000)    \
    }               \
)

// +∞ representation
#define QUAD_PINF   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000),   \
        .Hi.U=UINT64_C(0x7fff000000000000),   \
    }               \
)
// default quiet NaN representation
#define QUAD_QNAN   \
(                   \
    (QUAD_TYPE)     \
    {               \
        .Lo.U=UINT64_C(0x0000000000000000), \
        .Hi.U=UINT64_C(0x7fff800000000000), \
    }               \
)

#define OCTA_(_)    OCTA_##_
#define OCTA_SN(_)  _##o
#define OCTA_LOG2SZ (5)
#define OCTA_SIZE   (8*WORD_SIZE)
#define OCTA_WIDTH  (BYTE_WIDTH<<OCTA_LOG2SZ)

#define OCTA_NLONG  (DWRD_NLONG<<2)
#define OCTA_SN(_)  _##o

#define SEXD_(_)    SEXD_##_
#define SEXD_SN(_)  _##s
#define SEXD_LOG2SZ (6)
#define SEXD_SIZE   (16*WORD_SIZE)
#define SEXD_WIDTH  (BYTE_WIDTH<<SEXD_LOG2SZ)

#define DWRD_NLONG  (1+(LONG_MAX==INT_MAX))
#define QUAD_NLONG  (2*DWRD_NLONG)
#define QUAD_NLLONG (1+(LONG_MAX==LLONG_MAX))

#if QUAD_NLONG == 4
#   define  ULONG_SN(_)     _##lu
#   define  LONG_SN(_)      _##li
#   define  ULLONG_SN       DWRD_SNU
#   define  LLONG_SN        DWRD_SNI
#   define  ULONG_STG       WORD_
#   define  LONG_STG        WORD_
#   define  ULLONG_STG      DWRD_
#   define  LLONG_STG       DWRD_
#   define  WORD_LU         ULONG_
#   define  WORD_LI         LONG_
#   define  WORD_LTYPE      union Wl
#   define  WORD_LUTYPE     unsigned long
#   define  WORD_LITYPE     long
#   define  DWRD_U          ULLONG_
#   define  DWRD_I          LLONG_
#   define  DWRD_UTYPE      unsigned long long
#   define  DWRD_ITYPE      long long
#elif QUAD_NLLONG == 2
#   define  ULONG_SN        DWRD_SNU
#   define  LONG_SN         DWRD_SNI
#   define  ULLONG_SN(_)    _##lu
#   define  LLONG_SN(_)     _##li
#   define  ULONG_STG       DWRD_
#   define  LONG_STG        DWRD_
#   define  ULLONG_STG      DWRD_
#   define  LLONG_STG       DWRD_
#   define  DWRD_I          LONG_
#   define  DWRD_LI         LLONG_
#   define  DWRD_U          ULONG_
#   define  DWRD_LU         ULLONG_
#   define  DWRD_ITYPE      long
#   define  DWRD_LITYPE     long long
#   define  DWRD_UTYPE      unsigned long
#   define  DWRD_LUTYPE     unsigned long long
#   define  DWRD_LTYPE      union Dl
#else
#   define  ULONG_SN        DWRD_SNU
#   define  LONG_SN         DWRD_SNI
#   define  ULLONG_SN       QUAD_SNU
#   define  LLONG_SN        QUAD_SNI
#   define  LONG_STG        DWRD_
#   define  ULONG_STG       DWRD_
#   define  LLONG_STG       QUAD_
#   define  ULLONG_STG      QUAD_
#   define  DWRD_I          LONG_
#   define  DWRD_U          ULONG_
#   define  DWRD_ITYPE      long
#   define  DWRD_UTYPE      unsigned long
#   define  QUAD_I          LLONG_
#   define  QUAD_U          ULLONG_
#   define  QUAD_ITYPE      long long
#   define  QUAD_UTYPE      unsigned long long
#endif

#if defined(__SIZEOF_INT128__) && (QUAD_NLLONG==2)
#   define  UINT128X_(_)    UINT128X_##_
#   define  UINT128X_TYPE   unsigned __int128
#   define  UINT128X_STG    QUAD_
#   define  UINT128X_SN     QUAD_SNU
#   define  INT128X_(_)     INT128X_##_
#   define  INT128X_TYPE    __int128
#   define  INT128X_STG     QUAD_
#   define  INT128X_SN      QUAD_SNI
#   define  QUAD_I          INT128X_
#   define  QUAD_U          UINT128X_
#   define  QUAD_ITYPE      __int128
#   define  QUAD_UTYPE      unsigned __int128
#endif

#define BOOL_ENDIAN         MY_ENDIAN
#define UCHAR_ENDIAN        MY_ENDIAN
#define SCHAR_ENDIAN        MY_ENDIAN
#define USHRT_ENDIAN        MY_ENDIAN
#define SHRT_ENDIAN         MY_ENDIAN
#define UINT_ENDIAN         MY_ENDIAN
#define INT_ENDIAN          MY_ENDIAN
#define ULONG_ENDIAN        MY_ENDIAN
#define LONG_ENDIAN         MY_ENDIAN
#define ULLONG_ENDIAN       MY_ENDIAN
#define LLONG_ENDIAN        MY_ENDIAN

#ifndef FLT16_ENDIAN
#define FLT16_ENDIAN        MY_ENDIAN
#endif

#ifndef FLT_ENDIAN
#define FLT_ENDIAN          MY_ENDIAN
#endif

#ifndef DBL_ENDIAN
#define DBL_ENDIAN          MY_ENDIAN
#endif

#define BOOL_(_)            BOOL_##_
#define BOOL_SN(_)          _##yu
#define BOOL_SIGNEDNESS     (0)
#define BOOL_TYPE           _Bool
#define BOOL_WIDTH          NDIG_C(1)

#define CHAR_(_)            CHAR_##_
#define CHAR_SN             BYTE_SNC
#define CHAR_TYPE           char
#define CHAR_STG            BYTE_
#define CHAR_SIZE           CHAR_STG(SIZE)
#define CHAR_WIDTH          CHAR_STG(WIDTH)
#define CHAR_SIGNEDNESS     (0!=CHAR_MIN)
#define CHAR_C(C)           #C

#define UCHAR_(_)           UCHAR_##_
#define UCHAR_STG           BYTE_
#define UCHAR_SN            UCHAR_STG(SNC)
#define UCHAR_SIZE          UCHAR_STG(SIZE)
#define UCHAR_WIDTH         UCHAR_STG(WIDTH)
#define UCHAR_DIG           UCHAR_STG(UDIG)
#define UCHAR_ODIG          UCHAR_STG(ODIG)
#define UCHAR_XDIG          UCHAR_STG(XDIG)
#define UCHAR_SIGNEDNESS    (0)
#define UCHAR_OFMT          "hho"
#define UCHAR_DFMT          "hhu"
#define UCHAR_XFMT          "hhx"
#define UCHAR_UFMT          "hhX"

#if defined(_MSC_VER)
#   define  UCHAR_C(C)      C ## ui8
#else
#   define  UCHAR_C(C)      (C&255)
#endif

#define SCHAR_(_)           SCHAR_##_
#define SCHAR_SN            _##bi
#define SCHAR_STG           BYTE_
#define SCHAR_SIZE          SCHAR_STG(SIZE)
#define SCHAR_WIDTH         SCHAR_STG(WIDTH)
#define SCHAR_DIG           SCHAR_STG(IDIG)
#define SCHAR_SIGNEDNESS    (1)
#define SCHAR_DFMT          "hhi"
#define SCHAR_C(C)          (C&255)

#if defined(_MSC_VER)
#   ifdef   _CHAR_UNSIGNED
#   define  UCHAR_TYPE      char
#   define  SCHAR_TYPE      signed char
#   endif

#   ifndef  _CHAR_UNSIGNED
#   define  UCHAR_TYPE      unsigned char
#   define  SCHAR_TYPE      char
#   endif

#else
#   define  CHAR_TYPE       char
#   define  UCHAR_TYPE      unsigned char
#   define  SCHAR_TYPE      signed char
#endif

#define USHRT_(_)           USHRT_##_
#define USHRT_TYPE          unsigned short
#define USHRT_STG           HALF_
#define USHRT_SN            HALF_SNU
#define USHRT_SIZE          USHRT_STG(SIZE)
#define USHRT_WIDTH         USHRT_STG(WIDTH)
#define USHRT_DIG           USHRT_STG(UDIG)
#define USHRT_ODIG          USHRT_STG(ODIG)
#define USHRT_XDIG          USHRT_STG(XDIG)
#define USHRT_SIGNEDNESS    (0)
#define USHRT_OFMT          "ho"
#define USHRT_DFMT          "hu"
#define USHRT_XFMT          "hx"
#define USHRT_UFMT          "hX"
#define USHRT_C(C)          (C&65535)

#define SHRT_(_)            SHRT_##_
#define SHRT_TYPE           short
#define SHRT_STG            HALF_
#define SHRT_SN             HALF_SNI
#define SHRT_SIZE           SHRT_STG(SIZE)
#define SHRT_WIDTH          SHRT_STG(WIDTH)
#define SHRT_DIG            SHRT_STG(IDIG)
#define SHRT_SIGNEDNESS     (1)
#define SHRT_TGNAME(_)      _ ## hi
#define SHRT_DFMT           "hi"
#define SHRT_C(C)           (C&65535)

#define UINT_(_)            UINT_##_
#define UINT_TYPE           unsigned int
#define UINT_SN             WORD_SNU
#define UINT_STG            WORD_
#define UINT_SIZE           UINT_STG(SIZE)
#define UINT_WIDTH          UINT_STG(WIDTH)
#define UINT_DIG            UINT_STG(UDIG)
#define UINT_ODIG           UINT_STG(ODIG)
#define UINT_XDIG           UINT_STG(XDIG)
#define UINT_SIGNEDNESS     (0)
#define UINT_C(C)           (C##U)
#define UINT_OFMT           "o"
#define UINT_DFMT           "u"
#define UINT_XFMT           "x"
#define UINT_UFMT           "X"

#define INT_(_)             INT_##_
#define INT_SN              WORD_SNI
#define INT_TYPE            int
#define INT_STG             WORD_
#define INT_SIZE            INT_STG(SIZE)
#define INT_WIDTH           INT_STG(WIDTH)
#define INT_DIG             INT_STG(IDIG)
#define INT_SIGNEDNESS      (1)
#define INT_DFMT            "i"
#define INT_C(C)            (C)

#define ULONG_(_)           ULONG_##_
#define ULONG_TYPE          unsigned long
#define ULONG_SIZE          ULONG_STG(SIZE)
#define ULONG_WIDTH         ULONG_STG(WIDTH)
#define ULONG_DIG           ULONG_STG(UDIG)
#define ULONG_ODIG          ULONG_STG(ODIG)
#define ULONG_XDIG          ULONG_STG(XDIG)
#define ULONG_SIGNEDNESS    (0)
#define ULONG_OFMT          "lo"
#define ULONG_DFMT          "lu"
#define ULONG_XFMT          "lx"
#define ULONG_UFMT          "lX"
#define ULONG_C(C)          (C##UL)

#define LONG_(_)            LONG_##_
#define LONG_TYPE           long
#define LONG_SIZE           LONG_STG(SIZE)
#define LONG_WIDTH          LONG_STG(WIDTH)
#define LONG_DIG            LONG_STG(IDIG)
#define LONG_SIGNEDNESS     (1)
#define LONG_DFMT           "li"
#define LONG_C(C)           (C##L)

#define ULLONG_(_)          ULLONG_##_
#define ULLONG_TYPE         unsigned long long
#define ULLONG_SIZE         ULLONG_STG(SIZE)
#define ULLONG_WIDTH        ULLONG_STG(WIDTH)
#define ULLONG_DIG          ULLONG_STG(UDIG)
#define ULLONG_ODIG         ULLONG_STG(ODIG)
#define ULLONG_XDIG         ULLONG_STG(XDIG)
#define ULLONG_OFMT         "llo"
#define ULLONG_DFMT         "llu"
#define ULLONG_XFMT         "llx"
#define ULLONG_UFMT         "llX"
#define ULLONG_SIGNEDNESS   (0)
#define ULLONG_C(C)         (C##ULL)

#define LLONG_(_)           LLONG_##_
#define LLONG_TYPE          long long
#define LLONG_SIZE          LLONG_STG(SIZE)
#define LLONG_WIDTH         LLONG_STG(WIDTH)
#define LLONG_DIG           LLONG_STG(IDIG)
#define LLONG_SIGNEDNESS    (1)
#define LLONG_DFMT          "lli"
#define LLONG_C(C)          (C##LL)

#define UINT8_(_)           UINT8_##_
#define UINT8_TYPE          uint8_t
#define UINT8_SN            BYTE_SNU
#define UINT8_STG           BYTE_
#define UINT8_BASE          UINT8_STG(U)
#define UINT8_SIZE          UINT8_BASE(SIZE)
#define UINT8_WIDTH         UINT8_BASE(WIDTH)
#define UINT8_DIG           UINT8_BASE(DIG)
#define UINT8_ODIG          UINT8_BASE(ODIG)
#define UINT8_XDIG          UINT8_BASE(XDIG)
#define UINT8_SIGNEDNESS    UINT8_BASE(SIGNEDNESS)
#define UINT8_DFMT          UINT8_BASE(DFMT)
#define UINT8_OFMT          UINT8_BASE(OFMT)
#define UINT8_XFMT          UINT8_BASE(XFMT)
#define UINT8_UFMT          UINT8_BASE(UFMT)
#define UINT8_ENDIAN        UINT8_BASE(ENDIAN)

#define INT8_(_)            INT8_##_
#define INT8_SN             BYTE_SNI
#define INT8_TYPE           int8_t
#define INT8_STG            BYTE_
#define INT8_BASE           INT8_STG(I)
#define INT8_SIZE           INT8_BASE(SIZE)
#define INT8_WIDTH          INT8_BASE(WIDTH)
#define INT8_DIG            INT8_BASE(DIG)
#define INT8_ODIG           INT8_BASE(ODIG)
#define INT8_XDIG           INT8_BASE(XDIG)
#define INT8_SIGNEDNESS     INT8_BASE(SIGNEDNESS)
#define INT8_DFMT           INT8_BASE(DFMT)
#define INT8_ENDIAN         INT8_BASE(ENDIAN)


#define UINT16_(_)          UINT16_##_
#define UINT16_SN           HALF_SNU
#define UINT16_TYPE         uint16_t
#define UINT16_STG          HALF_
#define UINT16_BASE         UINT16_STG(U)
#define UINT16_DFMT         UINT16_BASE(DFMT)
#define UINT16_OFMT         UINT16_BASE(OFMT)
#define UINT16_XFMT         UINT16_BASE(XFMT)
#define UINT16_UFMT         UINT16_BASE(UFMT)
#define UINT16_SIZE         UINT16_BASE(SIZE)
#define UINT16_WIDTH        UINT16_BASE(WIDTH)
#define UINT16_DIG          UINT16_BASE(DIG)
#define UINT16_ODIG         UINT16_BASE(ODIG)
#define UINT16_XDIG         UINT16_BASE(XDIG)
#define UINT16_SIGNEDNESS   UINT16_BASE(SIGNEDNESS)
#define UINT16_ENDIAN       UINT16_BASE(ENDIAN)


#define INT16_(_)           INT16_##_
#define INT16_SN            HALF_SNI
#define INT16_TYPE          int16_t
#define INT16_STG           HALF_
#define INT16_BASE          INT16_STG(I)
#define INT16_SIZE          INT16_BASE(SIZE)
#define INT16_WIDTH         INT16_BASE(WIDTH)
#define INT16_DIG           INT16_BASE(DIG)
#define INT16_ODIG          INT16_BASE(ODIG)
#define INT16_XDIG          INT16_BASE(XDIG)
#define INT16_SIGNEDNESS    INT16_BASE(SIGNEDNESS)
#define INT16_UFMT          INT16_BASE(DFMT)
#define INT16_ENDIAN        INT16_BASE(ENDIAN)


#define UINT32_(_)          UINT32_##_
#define UINT32_SN           WORD_SNU
#define UINT32_TYPE         uint32_t
#define UINT32_STG          WORD_
#define UINT32_BASE         UINT32_STG(U)
#define UINT32_DFMT         UINT32_BASE(DFMT)
#define UINT32_OFMT         UINT32_BASE(OFMT)
#define UINT32_XFMT         UINT32_BASE(XFMT)
#define UINT32_UFMT         UINT32_BASE(UFMT)
#define UINT32_SIZE         UINT32_BASE(SIZE)
#define UINT32_WIDTH        UINT32_BASE(WIDTH)
#define UINT32_DIG          UINT32_BASE(DIG)
#define UINT32_ODIG         UINT32_BASE(ODIG)
#define UINT32_XDIG         UINT32_BASE(XDIG)
#define UINT32_SIGNEDNESS   UINT32_BASE(SIGNEDNESS)
#define UINT32_ENDIAN       UINT_BASE(ENDIAN)


#define INT32_(_)           INT32_##_
#define INT32_SN            WORD_SNI
#define INT32_TYPE          int32_t
#define INT32_STG           WORD_
#define INT32_BASE          INT32_STG(I)
#define INT32_SIZE          INT32_BASE(SIZE)
#define INT32_WIDTH         INT32_BASE(WIDTH)
#define INT32_DIG           INT32_BASE(DIG)
#define INT32_ODIG          INT32_BASE(ODIG)
#define INT32_XDIG          INT32_BASE(XDIG)
#define INT32_SIGNEDNESS    INT32_BASE(SIGNEDNESS)
#define INT32_DFMT          INT32_BASE(DFMT)
#define INT32_ENDIAN        INT32_BASE(ENDIAN)


#define UINT64_(_)          UINT64_##_
#define UINT64_SN           DWRD_SNU
#define UINT64_TYPE         uint64_t
#define UINT64_STG          DWRD_
#define UINT64_BASE         UINT64_STG(U)
#define UINT64_DFMT         UINT64_BASE(DFMT)
#define UINT64_OFMT         UINT64_BASE(OFMT)
#define UINT64_XFMT         UINT64_BASE(XFMT)
#define UINT64_UFMT         UINT64_BASE(UFMT)
#define UINT64_SIZE         UINT64_BASE(SIZE)
#define UINT64_WIDTH        UINT64_BASE(WIDTH)
#define UINT64_DIG          UINT64_BASE(DIG)
#define UINT64_ODIG         UINT64_BASE(ODIG)
#define UINT64_XDIG         UINT64_BASE(XDIG)
#define UINT64_SIGNEDNESS   UINT64_BASE(SIGNEDNESS)
#define UINT64_ENDIAN       UINT64_BASE(ENDIAN)


#define INT64_(_)           INT64_##_
#define INT64_SN            DWRD_SNI
#define INT64_TYPE          int64_t
#define INT64_STG           DWRD_
#define INT64_BASE          INT64_STG(I)
#define INT64_SIZE          INT64_BASE(SIZE)
#define INT64_WIDTH         INT64_BASE(WIDTH)
#define INT64_DIG           INT64_BASE(DIG)
#define INT64_ODIG          INT64_BASE(ODIG)
#define INT64_XDIG          INT64_BASE(XDIG)
#define INT64_SIGNEDNESS    INT64_BASE(SIGNEDNESS)
#define INT64_DFMT          INT64_BASE(DFMT)
#define INT64_ENDIAN        INT64_BASE(ENDIAN)


#ifndef SIZE_MAX
#error "SIZE_MAX is gone"
#elif  (SIZE_MAX>>15) == 1
#   define  ADDR_STG    HALF_
#   define  QUAD_NPTR   8
#   define  DWRD_NPTR   4
#   define  WORD_NPTR   2
#   define  HALF_NPTR   1
#elif (SIZE_MAX>>31) == 1
#   define  ADDR_STG    WORD_
#   define  QUAD_NPTR   4
#   define  DWRD_NPTR   2
#   define  WORD_NPTR   1
#   define  HALF_NPTR   0
#elif (SIZE_MAX>>63) == 1
#   define  ADDR_STG    DWRD_
#   define  QUAD_NPTR   2
#   define  DWRD_NPTR   1
#   define  WORD_NPTR   0
#   define  HALF_NPTR   0
#elif (SIZE_MAX>>64) == LONG_MAX
#   define  ADDR_STG    QUAD_
#   define  QUAD_NPTR   1
#   define  DWRD_NPTR   0
#   define  WORD_NPTR   0
#   define  HALF_NPTR   0
#else
#   error "invalid value of SIZE_MAX"
#endif

#define ADDR_SN(_)          _##a
#define ADDR_SNU(_)         ADDR_STG(SNU)
#define ADDR_SNI(_)         ADDR_STG(SNI)
#define ADDR_I              ADDR_STG(I)
#define ADDR_U              ADDR_STG(U)
#define ADDR_SIZE           ADDR_STG(SIZE)
#define ADDR_WIDTH          ADDR_STG(WIDTH)
#define ADDR_DEC            ADDR_STG(WIDTH)
#define ADDR_UDIG           ADDR_STG(UDIG)
#define ADDR_IDIG           ADDR_STG(IDIG)
#define ADDR_XDIG           ADDR_STG(XDIG)
#define ADDR_ODIG           ADDR_STG(ODIG)

#define ADDR_FMTP           "p"

#define UINTPTR_(_)         UINTPTR_##_
#define UINTPTR_TYPE        uintptr_t
#define UINTPTR_BASE        ADDR_U
#define UINTPTR_STG         ADDR_STG
#define UINTPTR_SIZE        ADDR_SIZE
#define UINTPTR_WIDTH       ADDR_WIDTH
#define UINTPTR_DIG         ADDR_UDIG
#define UINTPTR_XDIG        ADDR_XDIG
#define UINTPTR_ODIG        ADDR_STG(ODIG)
#define UINTPTR_SIGNEDNESS  (0)
#define UINTPTR_SN          ADDR_SNU
#ifndef UINTPTR_C
#define UINTPTR_C           ADDR_U(C)
#endif

#define INTPTR_(_)          INTPTR_##_
#define INTPTR_BASE         ADDR_I
#define INTPTR_TYPE         intptr_t
#define INTPTR_STG          ADDR_STG
#define INTPTR_SIZE         ADDR_SIZE
#define INTPTR_WIDTH        ADDR_WIDTH
#define INTPTR_DIG          ADDR_DIG
#define INTPTR_SIGNEDNESS   (1)
#define INTPTR_SN(_)        ADDR_SNI
#ifndef INTPTR_C
#define INTPTR_C            ADDR_I(C)
#endif

#define SIZE_(_)            SIZE_##_
#define SIZE_BASE           ADDR_U
#define SIZE_TYPE           size_t
#define SIZE_STG            ADDR_STG
#define SIZE_SIZE           ADDR_SIZE
#define SIZE_WIDTH          ADDR_WIDTH
#define SIZE_DIG            ADDR_DIG
#define SIZE_XDIG           ADDR_XDIG
#define SIZE_ODIG           ADDR_ODIG
#define SIZE_FMTO           "zo"
#define SIZE_FMTD           "zd"
#define SIZE_FMTX           "zx"
#define SIZE_SIGNEDNESS     (0)
#define SIZE_SN             ADDR_SNU
#ifndef SIZE_C
#define SIZE_C              ADDR_U(C)
#endif

#define PTRDIFF(_)          PTRDIFF_##_
#define PTRDIFF_BASE        ADDR_I
#define PTRDIFF_TYPE        ptrdiff_t
#define PTRDIFF_STG         ADDR_STG
#define PTRDIFF_SIZE        ADDR_SIZE
#define PTRDIFF_WIDTH       ADDR_WIDTH
#define PTRDIFF_DIG         ADDR_DIG
#define PTRDIFF_SIGNEDNESS  (1)
#define PTRDIFF_SN          ADDR_SNI
#define PTRDIFF_FMTO        "to"
#define PTRDIFF_FMTD        "ti"
#define PTRDIFF_FMTX        "tx"
#define PTRDIFF_FMTU        "tX"
#ifndef PTRDIFF_C
#define PTRDIFF_C           ADDR_I(C)
#endif

#define FLT16_(_)           FLT16_##_
#define FLT16_TYPE          flt16_t
#define FLT16_STG           HALF_
#define FLT16_SN(_)         FLT16_STG(SNF)
#define FLT16_SIZE          FLT16_STG(SIZE)
#define FLT16_WIDTH         FLT16_STG(WIDTH)
#define FLT16_SIGNEDNESS    (1)

#if defined(SPC_X86_AVX512FP16)
#   define  FLT16_MTYPE _Float16
#   define  FLT16_C_DEF _Float16: C
#endif

#if defined(SPC_ARM_FP16_ARGS)
#   define  FLT16_MTYPE __fp16
#   define  FLT16_C(C)  ((__fp16) C##f16)
#endif

#if defined(FLT16_MTYPE)
#   ifndef  FLT16_C
#   define  FLT16_C(C)  C##f16
#   endif
#endif

#define FLT_(_)         FLT_##_
#define FLT_SN          FLT_STG(SNF)
#define FLT_TYPE        float
#define FLT_STG         WORD_
#define FLT_SIZE        FLT_STG(SIZE)
#define FLT_WIDTH       FLT_STG(WIDTH)
#define FLT_SIGNEDNESS  (1)
#define FLT_C(C)        C##f

#define DBL_(_)         DBL_##_
#define DBL_SN          DWRD_SNF
#define DBL_TYPE        double
#define DBL_STG         DWRD_
#define DBL_SIZE        DBL_STG(SIZE)
#define DBL_WIDTH       DBL_STG(WIDTH)
#define DBL_SIGNEDNESS  (1)
#define DBL_C(C)        _Generic(C, double:C)

#if _LEAVE_EXTNUM_ATTRS
}
#endif

#if _ENTER_EXTNUM_NV
{
#endif

#define MY_BIG_PAIR(Lo, Hi, Z)  Hi Z, Lo Z
#define MY_LIL_PAIR(Lo, Hi, Z)  Lo Z, Hi Z

#define MY_LV1(M, N) M##0 N
#define MY_LV2(M, N) MY_LV1(M,N),M##1 N
#define MY_LV3(M, N) MY_LV2(M,N),M##2 N
#define MY_LV4(M, N) MY_LV3(M,N),M##3 N
#define MY_LV5(M, N) MY_LV4(M,N),M##4 N
#define MY_LV6(M, N) MY_LV5(M,N),M##5 N
#define MY_LV7(M, N) MY_LV6(M,N),M##6 N
#define MY_LV8(M, N) MY_LV7(M,N),M##7 N

#define MY_LV16(M,N) MY_LV8(M,N),\
M## 8 N,M## 9 N,M##10 N,M##11 N,M##12 N,M##13 N,M##14 N,M##15 N

#define MY_LV32(M,N) MY_LV16(M,N),\
M##16 N,M##17 N,M##18 N,M##19 N,M##20 N,M##21 N,M##22 N,M##23 N,\
M##24 N,M##25 N,M##26 N,M##27 N,M##28 N,M##29 N,M##30 N,M##31 N

#define MY_LV64(M,N) MY_LV32(M,N),\
M##32 N,M##33 N,M##34 N,M##35 N,M##36 N,M##37 N,M##38 N,M##39 N,\
M##40 N,M##41 N,M##42 N,M##43 N,M##44 N,M##45 N,M##46 N,M##47 N,\
M##48 N,M##49 N,M##50 N,M##51 N,M##52 N,M##53 N,M##54 N,M##55 N,\
M##56 N,M##57 N,M##58 N,M##59 N,M##60 N,M##61 N,M##62 N,M##63 N

#define MY_LV128(M,N) MY_LV64(M,N), \
M## 64 N,M## 65 N,M## 66 N,M## 67 N,M## 68 N,M## 69 N,M## 70 N,M## 71 N,\
M## 72 N,M## 73 N,M## 74 N,M## 75 N,M## 76 N,M## 77 N,M## 78 N,M## 79 N,\
M## 80 N,M## 81 N,M## 82 N,M## 83 N,M## 84 N,M## 85 N,M## 86 N,M## 87 N,\
M## 88 N,M## 89 N,M## 90 N,M## 91 N,M## 92 N,M## 93 N,M## 94 N,M## 95 N,\
M## 96 N,M## 97 N,M## 98 N,M## 99 N,M##100 N,M##101 N,M##102 N,M##103 N,\
M##104 N,M##105 N,M##106 N,M##107 N,M##108 N,M##109 N,M##110 N,M##111 N,\
M##112 N,M##113 N,M##114 N,M##115 N,M##116 N,M##117 N,M##118 N,M##119 N,\
M##120 N,M##121 N,M##122 N,M##123 N,M##124 N,M##125 N,M##126 N,M##127 N

#define MY_BV1(M, N)  M##0 N
#define MY_BV2(M, N)  M##1 N,MY_BV1(M,N)
#define MY_BV3(M, N)  M##2 N,MY_BV2(M,N)
#define MY_BV4(M, N)  M##3 N,MY_BV3(M,N)
#define MY_BV5(M, N)  M##4 N,MY_BV4(M,N)
#define MY_BV6(M, N)  M##5 N,MY_BV5(M,N)
#define MY_BV7(M, N)  M##6 N,MY_BV6(M,N)
#define MY_BV8(M, N)  M##7 N,MY_BV7(M,N)

#define MY_BV16(M, N) \
M##15 N,M##14 N,M##13 N,M##12 N,M##11 N,M##10 N,M## 9 N,M## 8 N,\
MY_BV8(M,N)

#define MY_BV32(M, N) \
M##31 N,M##30 N,M##29 N,M##28 N,M##27 N,M##26 N,M##25 N,M##24 N,\
M##23 N,M##22 N,M##21 N,M##20 N,M##19 N,M##18 N,M##17 N,M##16 N,\
MY_BV16(M,N)

#define MY_BV64(M, N) \
M##63 N,M##62 N,M##61 N,M##60 N,M##59 N,M##58 N,M##57 N,M##56 N,\
M##55 N,M##54 N,M##53 N,M##52 N,M##51 N,M##50 N,M##49 N,M##48 N,\
M##47 N,M##46 N,M##45 N,M##44 N,M##43 N,M##42 N,M##41 N,M##40 N,\
M##39 N,M##38 N,M##37 N,M##36 N,M##35 N,M##34 N,M##33 N,M##32 N,\
MY_BV32(M,N)

#define MY_BV128(M, N) \
M##127 N,M##126 N,M##125 N,M##124 N,M##123 N,M##122 N,M##121 N,M##120 N,\
M##119 N,M##118 N,M##117 N,M##116 N,M##115 N,M##114 N,M##113 N,M##112 N,\
M##111 N,M##110 N,M##109 N,M##108 N,M##107 N,M##106 N,M##105 N,M##104 N,\
M##103 N,M##102 N,M##101 N,M##100 N,M## 99 N,M## 98 N,M## 97 N,M## 96 N,\
M## 95 N,M## 94 N,M## 93 N,M## 92 N,M## 91 N,M## 90 N,M## 89 N,M## 88 N,\
M## 87 N,M## 86 N,M## 85 N,M## 84 N,M## 83 N,M## 82 N,M## 81 N,M## 80 N,\
M## 79 N,M## 78 N,M## 77 N,M## 76 N,M## 75 N,M## 74 N,M## 73 N,M## 72 N,\
M## 71 N,M## 70 N,M## 69 N,M## 68 N,M## 67 N,M## 66 N,M## 65 N,M## 64 N,\
MY_BV64(M,N)

#if MY_ENDIAN == ENDIAN_LIL
#   ifndef  MY_PAIR
#   define  MY_PAIR     MY_LIL_PAIR
#   endif

#   ifndef  MY_NVX
#   define  MY_NVX(N)   MY_LV##N
#   endif

#endif

#if MY_ENDIAN == ENDIAN_BIG
#   ifndef  MY_PAIR
#   define  MY_PAIR     MY_BIG_PAIR
#   endif

#   ifndef  MY_NVX
#   define  MY_NVX(N)   MY_BV##N
#   endif

#endif

#define MY_NV1      MY_NVX(1)
#define MY_NV2      MY_NVX(2)
#define MY_NV3      MY_NVX(3)
#define MY_NV4      MY_NVX(4)
#define MY_NV5      MY_NVX(5)
#define MY_NV6      MY_NVX(6)
#define MY_NV7      MY_NVX(7)
#define MY_NV8      MY_NVX(8)
#define MY_NV16     MY_NVX(16)
#define MY_NV32     MY_NVX(32)
#define MY_NV64     MY_NVX(64)
#define MY_NV128    MY_NVX(128)

#define MY_BZ {uint8_t  U; int8_t  I;}
#define MY_HZ {uint16_t U; int16_t I;}
#define MY_WZ {uint32_t U; int32_t I;}
#define MY_DZ {uint64_t U; int64_t I;}

#if _LEAVE_EXTNUM_NV
}
#endif

#if _ENTER_EXTNUM_XFLT
{
#endif

#if FLT16_ENDIAN == ENDIAN_LIL

struct Xhfl {
    union {
        struct {uint8_t Mant;};
        union MY_BZ;
    };
};

struct Xhfr {
    union {
        struct {uint8_t  Mant: 2, Expo: 5, Sign:1, :0;};
        union MY_BZ;
    };
};

typedef struct Xhf {
    union {
        struct {struct Xhfl Lo; struct Xhfr Hi;};
        struct {uint16_t Mant: 10, Expo: 5, Sign: 1, :0;};
        union MY_HZ;
    };
} Xhf;

#else
#error "berg endian flt16"
#endif

#if FLT_ENDIAN == ENDIAN_LIL

struct Xwfl {
    union {
        struct {uint16_t Mant;};
        union MY_HZ;
    };
};

struct Xwfr {
    union {
        struct {uint16_t Mant: 7, Expo: 8, Sign:1, :0;};
        union MY_HZ;
    };
};

typedef struct Xwf {
    union {
        struct {struct Xwfl Lo; struct Xwfr Hi;};
        struct {uint32_t Mant:23, Expo: 8, Sign:1, :0;};
        union MY_WZ;
    };
} Xwf;

#else
#error "berg endian flt32"
#endif

#if DBL_ENDIAN == ENDIAN_LIL

struct Xdfl {
    union {
        struct {uint32_t Mant;};
        union MY_WZ;
    };
};

struct Xdfr {
    union {
        struct {uint32_t Mant:20,Expo:11, Sign: 1, :0;};
        union MY_WZ;
    };
};

typedef struct Xdf {
    union {
        struct {struct Xdfl Lo; struct Xdfr Hi;};
        struct {uint64_t Mant:52, Expo:11, Sign:1, :0;};
        union MY_DZ;
    };
} Xdf;
#else
#error "berg endian flt64"
#endif

struct Xqfl {
    union {
        struct {uint64_t Mant;};
        union MY_DZ;
    };
};
struct Xqfr {
    union {
        struct {uint64_t Mant:48, Expo:15, Sign:1, :0;};
        union MY_DZ;
    };
};
typedef struct Xqf {
    union {
        struct {struct Xqfl Lo; struct Xqfr Hi;};
    };
} Xqf;

#if defined(FLT16_MTYPE)
typedef FLT16_MTYPE flt16_t;
#else
typedef struct Xhf flt16_t;
#endif

typedef float  flt32_t;
typedef double flt64_t;

#if LDBL_MANT_DIG == 113
#   define  QUAD_FTYPE long double
#else
#   define  QUAD_FTYPE struct Xqf
#endif

typedef QUAD_FTYPE flt128_t;

#if _LEAVE_XFLT
}
#endif

#if _ENTER_EXTNUM_HOMOGENOUS_AGGREGATES
{
#endif

typedef struct Yu8      {_Bool MY_NV8(K,:1);}   Yu8;
typedef struct Yu16     {_Bool MY_NV16(K,:1);}  Yu16;
typedef struct Yu32     {_Bool MY_NV32(K,:1);}  Yu32;
typedef struct Yu64     {_Bool MY_NV64(K,:1);}  Yu64;
typedef struct Yu128    {_Bool MY_NV128(K,:1);}  Yu128;

typedef struct Bc1  {char MY_NV1(K,);}      Bc1;
typedef struct Bc2  {char MY_NV2(K,);}      Bc2;
typedef struct Bc3  {char MY_NV3(K,);}      Bc3;
typedef struct Bc4  {char MY_NV4(K,);}      Bc4;
typedef struct Bc8  {char MY_NV8(K,);}      Bc8;
typedef struct Bc16 {char MY_NV16(K,);}     Bc16;
typedef struct Bc32 {char MY_NV32(K,);}     Bc32;
typedef struct Bc64 {char MY_NV64(K,);}     Bc64;

typedef struct Bu1  {uint8_t MY_NV1(K,);}   Bu1;
typedef struct Bu2  {uint8_t MY_NV2(K,);}   Bu2;
typedef struct Bu3  {uint8_t MY_NV3(K,);}   Bu3;
typedef struct Bu4  {uint8_t MY_NV4(K,);}   Bu4;
typedef struct Bu8  {uint8_t MY_NV8(K,);}   Bu8;
typedef struct Bu16 {uint8_t MY_NV16(K,);}  Bu16;
typedef struct Bu32 {uint8_t MY_NV32(K,);}  Bu32;
typedef struct Bu64 {uint8_t MY_NV64(K,);}  Bu64;

typedef struct Bi1  {int8_t MY_NV1(K,);}    Bi1;
typedef struct Bi2  {int8_t MY_NV2(K,);}    Bi2;
typedef struct Bi3  {int8_t MY_NV3(K,);}    Bi3;
typedef struct Bi4  {int8_t MY_NV4(K,);}    Bi4;
typedef struct Bi8  {int8_t MY_NV8(K,);}    Bi8;
typedef struct Bi16 {int8_t MY_NV16(K,);}   Bi16;
typedef struct Bi32 {int8_t MY_NV32(K,);}   Bi32;
typedef struct Bi64 {int8_t MY_NV64(K,);}   Bi64;

typedef struct Hu1  {uint16_t MY_NV1(K,);}  Hu1;
typedef struct Hu2  {uint16_t MY_NV2(K,);}  Hu2;
typedef struct Hu3  {uint16_t MY_NV3(K,);}  Hu3;
typedef struct Hu4  {uint16_t MY_NV4(K,);}  Hu4;
typedef struct Hu8  {uint16_t MY_NV8(K,);}  Hu8;
typedef struct Hu16 {uint16_t MY_NV16(K,);} Hu16;

typedef struct Hi1  {int16_t MY_NV1(K,);}   Hi1;
typedef struct Hi2  {int16_t MY_NV2(K,);}   Hi2;
typedef struct Hi3  {int16_t MY_NV3(K,);}   Hi3;
typedef struct Hi4  {int16_t MY_NV4(K,);}   Hi4;
typedef struct Hi8  {int16_t MY_NV8(K,);}   Hi8;
typedef struct Hi16 {int16_t MY_NV16(K,);}  Hi16;

typedef struct Hf1  {flt16_t MY_NV1(K,);}   Hf1;
typedef struct Hf2  {flt16_t MY_NV2(K,);}   Hf2;
typedef struct Hf3  {flt16_t MY_NV3(K,);}   Hf3;
typedef struct Hf4  {flt16_t MY_NV4(K,);}   Hf4;
typedef struct Hf8  {flt16_t MY_NV8(K,);}   Hf8;
typedef struct Hf16 {flt16_t MY_NV16(K,);}  Hf16;

typedef struct Wu1  {uint32_t MY_NV1(K,);}  Wu1;
typedef struct Wu2  {uint32_t MY_NV2(K,);}  Wu2;
typedef struct Wu3  {uint32_t MY_NV3(K,);}  Wu3;
typedef struct Wu4  {uint32_t MY_NV4(K,);}  Wu4;
typedef struct Wu8  {uint32_t MY_NV8(K,);}  Wu8;
typedef struct Wu16 {uint32_t MY_NV16(K,);} Wu16;

typedef struct Wi1  {int32_t MY_NV1(K,);}   Wi1;
typedef struct Wi2  {int32_t MY_NV2(K,);}   Wi2;
typedef struct Wi3  {int32_t MY_NV3(K,);}   Wi3;
typedef struct Wi4  {int32_t MY_NV4(K,);}   Wi4;
typedef struct Wi8  {int32_t MY_NV8(K,);}   Wi8;
typedef struct Wi16 {int32_t MY_NV16(K,);}  Wi16;

typedef struct Wf1  {float MY_NV1(K,);}     Wf1;
typedef struct Wf2  {float MY_NV2(K,);}     Wf2;
typedef struct Wf3  {float MY_NV3(K,);}     Wf3;
typedef struct Wf4  {float MY_NV4(K,);}     Wf4;
typedef struct Wf8  {float MY_NV8(K,);}     Wf8;
typedef struct Wf16 {float MY_NV16(K,);}    Wf16;

typedef struct Du1  {uint64_t MY_NV1(K,);}  Du1;
typedef struct Du2  {uint64_t MY_NV2(K,);}  Du2;
typedef struct Du3  {uint64_t MY_NV3(K,);}  Du3;
typedef struct Du4  {uint64_t MY_NV4(K,);}  Du4;
typedef struct Du8  {uint64_t MY_NV8(K,);}  Du8;

typedef struct Di1  {int64_t MY_NV1(K,);}   Di1;
typedef struct Di2  {int64_t MY_NV2(K,);}   Di2;
typedef struct Di3  {int64_t MY_NV3(K,);}   Di3;
typedef struct Di4  {int64_t MY_NV4(K,);}   Di4;
typedef struct Di8  {int64_t MY_NV8(K,);}   Di8;

typedef struct Df1  {double MY_NV1(K, );}   Df1;
typedef struct Df2  {double MY_NV2(K, );}   Df2;
typedef struct Df3  {double MY_NV3(K, );}   Df3;
typedef struct Df4  {double MY_NV4(K, );}   Df4;
typedef struct Df8  {double MY_NV8(K, );}   Df8;

typedef struct Qu1  {QUAD_UTYPE MY_NV1(K,);}    Qu1;
typedef struct Qu2  {QUAD_UTYPE MY_NV2(K,);}    Qu2;
typedef struct Qu3  {QUAD_UTYPE MY_NV3(K,);}    Qu3;
typedef struct Qu4  {QUAD_UTYPE MY_NV4(K,);}    Qu4;
typedef struct Qu8  {QUAD_UTYPE MY_NV8(K,);}    Qu8;

typedef struct Qi1  {QUAD_ITYPE MY_NV1(K, );}   Qi1;
typedef struct Qi2  {QUAD_ITYPE MY_NV2(K, );}   Qi2;
typedef struct Qi3  {QUAD_ITYPE MY_NV3(K, );}   Qi3;
typedef struct Qi4  {QUAD_ITYPE MY_NV4(K, );}   Qi4;
typedef struct Qi8  {QUAD_ITYPE MY_NV8(K, );}   Qi8;

typedef struct Qf1  {QUAD_FTYPE MY_NV1(K, );}   Qf1;
typedef struct Qf2  {QUAD_FTYPE MY_NV2(K, );}   Qf2;
typedef struct Qf3  {QUAD_FTYPE MY_NV3(K, );}   Qf3;
typedef struct Qf4  {QUAD_FTYPE MY_NV4(K, );}   Qf4;
typedef struct Qf8  {QUAD_FTYPE MY_NV8(K, );}   Qf8;

#if _LEAVE_EXTNUM_HOMOGENOUS_AGGREGATES
}
#endif

/*
The following union types may be used to replace almost
any throwaway union used for scalar type punning.

*   T.Lo contains the lower half of a value's
    representation while T.Hi contains its upper half.
    E.g. ((union Half){.U=0xff00}).Hi evaluates to 255
    (0xff), since the Hi member contains a halfword's
    upper 8 bits.

*   Individual bits can be referenced using the Y
    members. ((Dwrd){.U=x}).Y37 is equivalent to
    (((uint64_t) x)>>37)&1

*   The M.U, M.I, and M.F members contain packed
    versions of the U, I, F members. However, the lun*
    and sun* operations already guarantee the most
    efficient access of packed data, so these should
    only ever be used in their implementation.

*/

typedef union Byte {
    char        C[1];
    uint8_t     U;
    int8_t      I;
    _Bool       Y;
    union       {Bu1 U; Bi1 I; Bc1 C;} M1;
    struct      {bool       MY_NV8(Y,:1),:0;};
    struct      {char       MY_NV1(C,);};
    struct      {uint8_t    MY_NV1(U,);};
    struct      {int8_t     MY_NV1(I,);};
} Byte;

typedef union Half {
    char        C[2];
    Byte        B[2];
    union       {Hu1 U; Hi1 I; Hf1 F;} M1;
    union       {Bu2 U; Bi2 I; Bc2 C;} M2;
    uint16_t    U;
    int16_t     I;
    flt16_t     F;
    struct      {bool   MY_NV16(Y, :1), :0; };
    struct      {char   MY_NV2( C,  );      };
    struct      {Byte   MY_NV2( B,  );      };
    struct      {Byte   MY_PAIR(Lo, Hi,  ); };
#if HALF_NPTR
    void        *A[HALF_NPTR];
    struct      {void   MY_NV1(*A,  );      };
#endif

    struct {
        uint16_t
            Mant:   10,
            Expo:   5,
            Sign:   1,
            :       0;
    };

    union {
#if defined(_MSC_VER)
#   pragma pack(push,1)
        uint16_t    U;
        int16_t     I;
        flt16_t     F;
#   pragma pack(pop)
#else
        uint16_t    U __attribute__((packed));
        int16_t     I __attribute__((packed));
        flt16_t     F __attribute__((packed));
#endif

    } M;

} Half;

typedef union Word {
    char           C[4];
    Byte        B[4];
    Half        H[2];
    union       {Wu1 U; Wi1 I; Wf1 F;} M1;
    union       {Hu2 U; Hi2 I; Hf2 F;} M2;
    union       {Bu4 U; Bi4 I; Bc4 C;} M4;
    uint32_t    U;
    int32_t     I;
    float       F;
    struct      {bool   MY_NV32(Y, :1), :0; };
    struct      {char   MY_NV4( C,  );      };
    struct      {Byte   MY_NV4( B,  );      };
    struct      {Half   MY_NV2( H,  );      };
    struct      {Half   MY_PAIR(Lo, Hi,  ); };
#if WORD_NPTR
    void        *A[WORD_NPTR];
#   if WORD_NPTR == 2
    struct      {void   MY_NV2(*A,  );      };
#   else
    struct      {void   MY_NV1(*A,  );      };
#   endif

#endif

    struct {
        uint32_t
            Mant:   23,
            Expo:   8,
            Sign:   1,
            :       0;
    };
    union {
#if defined(_MSC_VER)
#   pragma pack(push,1)
        uint32_t    U;
        int32_t     I;
        float       F;
#   pragma pack(pop)
#else
        uint32_t    U __attribute__((packed));
        int32_t     I __attribute__((packed));
        float       F __attribute__((packed));
#endif

    } M;

} Word;

typedef union Dwrd {
    char        C[8];
    Byte        B[8];
    Half        H[4];
    Word        W[2];
    union       {Du1 U; Di1 I; Df1 F;} M1;
    union       {Wu2 U; Wi2 I; Wf2 F;} M2;
    union       {Hu4 U; Hi4 I; Hf4 F;} M4;
    union       {Bu8 U; Bi8 I; Bc8 C;} M8;
    uint64_t    U;
    int64_t     I;
    double      F;
    struct      {bool   MY_NV64(Y, :1), :0; };
    struct      {char   MY_NV8( C,  );      };
    struct      {Byte   MY_NV8( B,  );      };
    struct      {Half   MY_NV4( H,  );      };
    struct      {Word   MY_NV2( W,  );      };
    struct      {Word   MY_PAIR(Lo, Hi,  ); };
#if DWRD_NPTR
    void    *A[DWRD_NPTR];
#   if   DWRD_NPTR == 4
    struct      {void   MY_NV4(*A,  );      };
#   elif DWRD_NPTR == 2
    struct      {void   MY_NV2(*A,  );      };
#   else
    struct      {void   MY_NV1(*A,  );      };
#   endif

#endif
    struct {
        uint64_t
            Mant:   52,
            Expo:   11,
            Sign:   1,
            :       0;
    };
    union {
#if defined(_MSC_VER)
#   pragma pack(push,1)
        uint64_t    U;
        int64_t     I;
        double      F;
#   pragma pack(pop)
#else
        uint64_t    U __attribute__((packed));
        int64_t     I __attribute__((packed));
        double      F __attribute__((packed));
#endif

    } M;

} Dwrd;

typedef union Quad {
    char        C[16];
    Byte        B[16];
    Half        H[ 8];
    Word        W[ 4];
    Dwrd        D[ 2];
    union       {Qu1  U; Qi1  I; Qf1  F;} M1;
    union       {Du2  U; Di2  I; Df2  F;} M2;
    union       {Wu4  U; Wi4  I; Wf4  F;} M4;
    union       {Hu8  U; Hi8  I; Hf8  F;} M8;
    union       {Bu16 U; Bi16 I; Bc16 C;} M16;
    QUAD_UTYPE  U;
    QUAD_ITYPE  I;
    QUAD_FTYPE  F;
    struct  {bool   MY_NV128(Y, :1), :0;};
    struct  {char   MY_NV16( C, );      };
    struct  {Byte   MY_NV16( B, );      };
    struct  {Half   MY_NV8(  H, );      };
    struct  {Word   MY_NV4(  W, );      };
    struct  {Dwrd   MY_NV2(  D, );      };
    struct  {Dwrd   MY_PAIR(Lo, Hi,  ); };

    void    *A[QUAD_NPTR];
#   if   QUAD_NPTR == 8
    struct  {void   MY_NV8(*A,  );      };
#   elif DWRD_NPTR == 4
    struct  {void   MY_NV4(*A,  );      };
#   elif DWRD_NPTR == 2
    struct  {void   MY_NV2(*A,  );      };
#   else
    struct  {void   MY_NV1(*A,  );      };
#   endif

    union {
#if defined(_MSC_VER)
#   pragma  pack(push,1)
        struct {uint64_t Lo, Hi;} U;
        struct { int64_t Lo, Hi;} I;
        struct {uint64_t Lo, Hi;} F:
#   pragma  pack(pop)
#else

#   if QUAD_NLLONG == 2
        unsigned __int128   U __attribute__((packed));
        signed   __int128   I __attribute__((packed));
#   else
        unsigned long long  U __attribute__((packed));
        signed long long    I __attribute__((packed));
#   endif

#   if LDBL_MANT_DIG == 113
        long double         F __attribute__((packed));
#   else
        unsigned __int128   F __attribute__((packed));
#   endif

#endif

    } M;

} Quad;

#if _ENTER_EXTNUM_SIZES_TEST
{
#endif

#if 1

typedef union {
    struct {uint8_t MY_LV128(L, );};
    struct {uint8_t MY_BV128(B, );};
} MY_SIZES_TEST;

ASSERT(0 == offsetof(MY_SIZES_TEST,L0));
ASSERT(1 == offsetof(MY_SIZES_TEST,L1));
ASSERT(2 == offsetof(MY_SIZES_TEST,L2));
ASSERT(3 == offsetof(MY_SIZES_TEST,L3));
ASSERT(4 == offsetof(MY_SIZES_TEST,L4));
ASSERT(5 == offsetof(MY_SIZES_TEST,L5));
ASSERT(6 == offsetof(MY_SIZES_TEST,L6));
ASSERT(7 == offsetof(MY_SIZES_TEST,L7));
ASSERT(8 == offsetof(MY_SIZES_TEST,L8));

ASSERT(8*14+0  == offsetof(MY_SIZES_TEST,L112));
ASSERT(8*14+7  == offsetof(MY_SIZES_TEST,L119));
ASSERT(8*15+0  == offsetof(MY_SIZES_TEST,L120));
ASSERT(8*15+7  == offsetof(MY_SIZES_TEST,L127));

ASSERT(127-0*1 == offsetof(MY_SIZES_TEST,B0));
ASSERT(127-1*1 == offsetof(MY_SIZES_TEST,B1));
ASSERT(127-2*1 == offsetof(MY_SIZES_TEST,B2));
ASSERT(127-3*1 == offsetof(MY_SIZES_TEST,B3));
ASSERT(127-4*1 == offsetof(MY_SIZES_TEST,B4));
ASSERT(127-5*1 == offsetof(MY_SIZES_TEST,B5));
ASSERT(127-6*1 == offsetof(MY_SIZES_TEST,B6));
ASSERT(127-7*1 == offsetof(MY_SIZES_TEST,B7));
ASSERT(127-8*1 == offsetof(MY_SIZES_TEST,B8));
ASSERT(127-8*2 == offsetof(MY_SIZES_TEST,B16));
ASSERT(127-8*3 == offsetof(MY_SIZES_TEST,B24));
ASSERT(127-8*4 == offsetof(MY_SIZES_TEST,B32));

ASSERT(sizeof(BYTE_TYPE) == 1);
ASSERT(sizeof(BYTE_ITYPE) == 1);
ASSERT(sizeof(BYTE_UTYPE) == 1);

ASSERT(sizeof(HALF_TYPE) == 2);
ASSERT(sizeof(HALF_ITYPE) == 2);
ASSERT(sizeof(HALF_UTYPE) == 2);
ASSERT(sizeof(HALF_FTYPE) == 2);
ASSERT(sizeof(HALF_LOTYPE) == 1);
ASSERT(sizeof(HALF_HITYPE) == 1);

ASSERT(sizeof(WORD_TYPE) == 4);
ASSERT(sizeof(WORD_ITYPE) == 4);
ASSERT(sizeof(WORD_UTYPE) == 4);
ASSERT(sizeof(WORD_FTYPE) == 4);
ASSERT(sizeof(WORD_LOTYPE) == 2);
ASSERT(sizeof(WORD_HITYPE) == 2);

ASSERT(sizeof(DWRD_TYPE) == 8);
ASSERT(sizeof(DWRD_ITYPE) == 8);
ASSERT(sizeof(DWRD_UTYPE) == 8);
ASSERT(sizeof(DWRD_FTYPE) == 8);
ASSERT(sizeof(DWRD_LOTYPE) == 4);
ASSERT(sizeof(DWRD_HITYPE) == 4);

ASSERT(sizeof(QUAD_TYPE) == 16);
ASSERT(sizeof(QUAD_LOTYPE) == 8);
ASSERT(sizeof(QUAD_HITYPE) == 8);

ASSERT( 1 == sizeof(Byte));
ASSERT( 2 == sizeof(Half));
ASSERT( 4 == sizeof(Word));
ASSERT( 8 == sizeof(Dwrd));
ASSERT(16 == sizeof(Quad));

#endif

#if _LEAVE_EXTNUM_SIZES_TEST
}
#endif

#if MY_ENDIAN == ENDIAN_BIG
/*
Vqbu[0] is loaded from (uint8_t[16])[QUAD_B0]

*/

#   define  QUAD_B0     (15)
#   define  QUAD_B1     (14)
#   define  QUAD_B2     (13)
#   define  QUAD_B3     (12)
#   define  QUAD_B4     (11)
#   define  QUAD_B5     (10)
#   define  QUAD_B6     (9)
#   define  QUAD_B7     (8)
#   define  QUAD_B8     (7)
#   define  QUAD_B9     (6)
#   define  QUAD_B10    (5)
#   define  QUAD_B11    (4)
#   define  QUAD_B12    (3)
#   define  QUAD_B13    (2)
#   define  QUAD_B14    (1)
#   define  QUAD_B15    (0)

#   define  QUAD_H0     (15)
#   define  QUAD_H1     (13)
#   define  QUAD_H2     (11)
#   define  QUAD_H3     (9)
#   define  QUAD_H4     (7)
#   define  QUAD_H5     (5)
#   define  QUAD_H6     (3)
#   define  QUAD_H7     (1)

#   define  QUAD_W0     (15)
#   define  QUAD_W1     (11)
#   define  QUAD_W2     (7)
#   define  QUAD_W3     (3)

#   define  QUAD_D0     (15)
#   define  QUAD_D1     (7)

#   define  DWRD_B0     (7)
#   define  DWRD_B1     (6)
#   define  DWRD_B2     (5)
#   define  DWRD_B3     (4)
#   define  DWRD_B4     (3)
#   define  DWRD_B5     (2)
#   define  DWRD_B6     (1)
#   define  DWRD_B7     (0)

#   define  DWRD_H0     (7)
#   define  DWRD_H1     (5)
#   define  DWRD_H2     (3)
#   define  DWRD_H3     (1)

#   define  DWRD_W0     (7)
#   define  DWRD_W1     (3)

#   define  WORD_B0     (3)
#   define  WORD_B1     (2)
#   define  WORD_B2     (1)
#   define  WORD_B3     (0)

#   define  WORD_H0     (3)
#   define  WORD_H1     (1)

#   define  HALF_B0     (1)
#   define  HALF_B1     (0)

#else

#   define  QUAD_B0     (0)
#   define  QUAD_B1     (1)
#   define  QUAD_B2     (2)
#   define  QUAD_B3     (3)
#   define  QUAD_B4     (4)
#   define  QUAD_B5     (5)
#   define  QUAD_B6     (6)
#   define  QUAD_B7     (7)
#   define  QUAD_B8     (8)
#   define  QUAD_B9     (9)
#   define  QUAD_B10    (10)
#   define  QUAD_B11    (11)
#   define  QUAD_B12    (12)
#   define  QUAD_B13    (13)
#   define  QUAD_B14    (14)
#   define  QUAD_B15    (15)

#   define  QUAD_H0     (0)
#   define  QUAD_H1     (2)
#   define  QUAD_H2     (4)
#   define  QUAD_H3     (6)
#   define  QUAD_H4     (8)
#   define  QUAD_H5     (10)
#   define  QUAD_H6     (12)
#   define  QUAD_H7     (14)

#   define  QUAD_W0     (0)
#   define  QUAD_W1     (4)
#   define  QUAD_W2     (8)
#   define  QUAD_W3     (12)

#   define  QUAD_D0     (0)
#   define  QUAD_D1     (8)

#   define  DWRD_B0     (0)
#   define  DWRD_B1     (1)
#   define  DWRD_B2     (2)
#   define  DWRD_B3     (3)
#   define  DWRD_B4     (4)
#   define  DWRD_B5     (5)
#   define  DWRD_B6     (6)
#   define  DWRD_B7     (7)

#   define  DWRD_H0     (0)
#   define  DWRD_H1     (2)
#   define  DWRD_H2     (4)
#   define  DWRD_H3     (6)

#   define  DWRD_W0     (0)
#   define  DWRD_W1     (4)

#   define  WORD_B0     (0)
#   define  WORD_B1     (1)
#   define  WORD_B2     (2)
#   define  WORD_B3     (3)

#   define  WORD_H0     (0)
#   define  WORD_H1     (1)

#   define  HALF_B0     (0)
#   define  HALF_B1     (1)

#endif

#endif // EOF("extnum.h")

#if _LEAVE_EXTNUM
}
#endif

#if _ENTER_EXTREPR
{
#endif

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳

*_REPR codes are symbolic constants used to identify the C
type of a value. Each type fits in one of three categories:

*   (K) scalars, i.e. ints, floats, & pointers

*   (V) vectors (of ints & floats)

*   (A) aggregates, i.e. one or more scalars or vectors
    arranged consecutively in memory


Encoded in the first 8 bits of a REPR code are:

*   for scalars and vectors, its numeric class, i.e.
    signed, unsigned, or floating point

*   the log2 of its bit width. E.g. for 64 bit types,
    the width field will be set to REPR_K64, which is 5

*   its integer byteorder

*   its endianness, which is *not* the same thing as
    the previously mentioned integer byteorder


Scalar REPR codes can fit in a single byte. Aggregate and
vector types require 16 bits, the upper 8 of which contains:

*   its total log2 size in bytes

*   its homogeneous aggregate length

The number of elements in a vector can be determined by 
dividing the total size by the element size. Note that 
although a scalar typecode can be represented as a single
byte, it isn't necessary to do so. In such cases, if the
total size exceeds the element size, how the value is
encoded in the excessively large storage area must be
implementation defined.

*/

#ifndef     MY_EXTREPR_H // BOF("extrepr.h")
#define     MY_EXTREPR_H    1

#ifndef     MY_EXTNUM_H
#include      "extnum.h"
#endif

#ifndef     MY_LIMITS_H
#define     MY_LIMITS_H
#include      <limits.h>
#endif

//                      (  mmmmzzzcckkkttt)
// Type                               (ttt)
//                      (0b111111100000000)
#define     REPR_ZL     (0b000000000000000) // LIL_ENDIAN integer
#define     REPR_ZB     (0b000000000000001) // BIG_ENDIAN integer

#define     REPR_IL     (0b000000000000010) // LIL_ENDIAN signed int
#define     REPR_IB     (0b000000000000011) // BIG_ENDIAN signed int

#define     REPR_FLZL   (0b000000000000100) // le: Mant,Expo,Sign
#define     REPR_FBZL   (0b000000000000110) // le: Sign,Expo,Mant
#define     REPR_FLZB   (0b000000000000101) // be: Mant,Expo,Sign
#define     REPR_FBZB   (0b000000000000111) // be: Sign,Expo,Mant

// log2 element size              (kkk)
//                                00111000
#define     REPR_K1     (0b000000000000000) // (1<<0) = 1 bit
#define     REPR_K2     (0b000000000001000) // (1<<1) = 2 bit
#define     REPR_K4     (0b000000000010000) // (1<<2) = 4 bit
#define     REPR_K8     (0b000000000011000) // (1<<3) = 8 bit
#define     REPR_K16    (0b000000000100000) // (1<<4) = 16 bit
#define     REPR_K32    (0b000000000101000) // (1<<5) = 32 bit
#define     REPR_K64    (0b000000000110000) // (1<<6) = 64 bit
#define     REPR_K128   (0b000000000111000) // (1<<7) = 128 bit

// Category                      (cc)
//                                11000000
#define     REPR_K      (0b000000000000000) // scalar
#define     REPR_VL     (0b000000001000000) // lilvec
#define     REPR_VB     (0b000000010000000) // bigvec
#define     REPR_A      (0b000000011000000) // hva

#if MY_ENDIAN == ENDIAN_BIG
#   define  REPR_U      REPR_ZB     // be unsigned
#   define  REPR_I      REPR_IB     // be signed
#   define  REPR_FL     REPR_FLZB   // le flt_be.Mant
#   define  REPR_FB     REPR_FBZB   // be flt_be.Mant
#else
#   define  REPR_U      REPR_ZL
#   define  REPR_I      REPR_IL
#   define  REPR_FL     REPR_FLZL
#   define  REPR_FB     REPR_FBZL
#endif

#if MY_VECTOR_ENDIAN == ENDIAN_BIG
#   define  REPR_V      REPR_VB
#else
#   define  REPR_V      REPR_VL
#endif

//                      (0b111111100000000)
//                      (      zzz        )
// Object log2 size           (zzz)
#define     REPR_SZB    (0b000000000000000) // 1 byte
#define     REPR_SZH    (0b000000100000000) // 2 byte
#define     REPR_SZW    (0b000001000000000) // 4 byte
#define     REPR_SZD    (0b000001100000000) // 8 byte
#define     REPR_SZQ    (0b000010000000000) // 16 byte
#define     REPR_SZO    (0b000010100000000) // 32 byte
#define     REPR_SZS    (0b000011000000000) // 64 byte
#define     REPR_SZV    (0b000011100000000) // custom size

#define     REPR_SZL    ((INT_MAX==LONG_MAX)?REPR_SZW:REPR_SZD)
#define     REPR_SZLL   ((ULLONG_MAX>>64)?REPR_SZD:REPR_SZQ)

/*  Homogeneous aggregate length (HAL)

All typecodes with a nonzero HAL are homogeneous aggregate
types. Length (M) is encoded in 4 bits using the following:

    M = 8 << (MAX(8, x)-8)
*/

//                      (  mmmm           )
#define     REPR_M0     (0b000000000000000) // nohomo aggr
#define     REPR_M1     (0b000100000000000)
#define     REPR_M2     (0b001000000000000)
#define     REPR_M3     (0b001100000000000)
#define     REPR_M4     (0b010000000000000)
#define     REPR_M5     (0b010100000000000)
#define     REPR_M6     (0b011000000000000)
#define     REPR_M7     (0b011100000000000)
#define     REPR_M8     (0b100000000000000)
#define     REPR_M16    (0b100100000000000)
#define     REPR_M32    (0b101000000000000)
#define     REPR_M64    (0b101100000000000)
#define     REPR_M128   (0b110000000000000)
#define     REPR_M256   (0b110100000000000)
#define     REPR_M512   (0b111000000000000)
#define     REPR_M1024  (0b111100000000000)

//                      (  mmmmzzzcckkkttt)

#if INT_MAX == LONG_MAX
#   define  REPR_KL    REPR_K32
#else
#   define  REPR_KL    REPR_K64
#endif

#if (ULLONG_MAX>>63) > 1
#   define  REPR_KLL    REPR_K128
#else
#   define  REPR_KLL    REPR_K64
#endif

#define     REPR_YU     (REPR_U|REPR_K1)
#define     REPR_YU1    (REPR_YU|REPR_M1)
#define     REPR_YU2    (REPR_YU|REPR_M2)
#define     REPR_YU3    (REPR_YU|REPR_M3)
#define     REPR_YU4    (REPR_YU|REPR_M4)
#define     REPR_YU8    (REPR_YU|REPR_M8)
#define     REPR_YU16   (REPR_YU|REPR_M16)
#define     REPR_YU32   (REPR_YU|REPR_M32)
#define     REPR_YU64   (REPR_YU|REPR_M64)

#define     REPR_BU     (REPR_U|REPR_K8)
#define     REPR_BU1    (REPR_BU|REPR_M1)
#define     REPR_BU2    (REPR_BU|REPR_M2)
#define     REPR_BU3    (REPR_BU|REPR_M3)
#define     REPR_BU4    (REPR_BU|REPR_M4)
#define     REPR_BU8    (REPR_BU|REPR_M8)
#define     REPR_BU16   (REPR_BU|REPR_M16)
#define     REPR_BU32   (REPR_BU|REPR_M32)
#define     REPR_BU64   (REPR_BU|REPR_M64)

#define     REPR_BI     (REPR_I|REPR_K8)
#define     REPR_BI1    (REPR_BI|REPR_M1)
#define     REPR_BI2    (REPR_BI|REPR_M2)
#define     REPR_BI3    (REPR_BI|REPR_M3)
#define     REPR_BI4    (REPR_BI|REPR_M4)
#define     REPR_BI8    (REPR_BI|REPR_M8)
#define     REPR_BI16   (REPR_BI|REPR_M16)
#define     REPR_BI32   (REPR_BI|REPR_M32)
#define     REPR_BI64   (REPR_BI|REPR_M64)

#define     REPR_HU     (REPR_U|REPR_K16)
#define     REPR_HU1    (REPR_HU|REPR_M1)
#define     REPR_HU2    (REPR_HU|REPR_M2)
#define     REPR_HU3    (REPR_HU|REPR_M3)
#define     REPR_HU4    (REPR_HU|REPR_M4)
#define     REPR_HU8    (REPR_HU|REPR_M8)
#define     REPR_HU16   (REPR_HU|REPR_M16)
#define     REPR_HU32   (REPR_HU|REPR_M32)

#define     REPR_HI     (REPR_I|REPR_K16)
#define     REPR_HI1    (REPR_HI|REPR_M1)
#define     REPR_HI2    (REPR_HI|REPR_M2)
#define     REPR_HI3    (REPR_HI|REPR_M3)
#define     REPR_HI4    (REPR_HI|REPR_M4)
#define     REPR_HI8    (REPR_HI|REPR_M8)
#define     REPR_HI16   (REPR_HI|REPR_M16)
#define     REPR_HI32   (REPR_HI|REPR_M32)

#if FLT16_ENDIAN == ENDIAN_BIG
#   define  REPR_HF     (REPR_FB|REPR_K16)
#else
#   define  REPR_HF     (REPR_FL|REPR_K16)
#endif

#define     REPR_HF1    (REPR_HF|REPR_M1)
#define     REPR_HF2    (REPR_HF|REPR_M2)
#define     REPR_HF3    (REPR_HF|REPR_M3)
#define     REPR_HF4    (REPR_HF|REPR_M4)
#define     REPR_HF8    (REPR_HF|REPR_M8)
#define     REPR_HF16   (REPR_HF|REPR_M16)
#define     REPR_HF32   (REPR_HF|REPR_M32)


#define     REPR_WU     (REPR_U|REPR_K32)
#define     REPR_WU1    (REPR_WU|REPR_M1)
#define     REPR_WU2    (REPR_WU|REPR_M2)
#define     REPR_WU3    (REPR_WU|REPR_M3)
#define     REPR_WU4    (REPR_WU|REPR_M4)
#define     REPR_WU8    (REPR_WU|REPR_M8)
#define     REPR_WU16   (REPR_WU|REPR_M16)

#define     REPR_WI     (REPR_I|REPR_K32)
#define     REPR_WI1    (REPR_WI|REPR_M1)
#define     REPR_WI2    (REPR_WI|REPR_M2)
#define     REPR_WI3    (REPR_WI|REPR_M3)
#define     REPR_WI4    (REPR_WI|REPR_M4)
#define     REPR_WI8    (REPR_WI|REPR_M8)
#define     REPR_WI16   (REPR_WI|REPR_M16)

#if FLT16_ENDIAN == ENDIAN_BIG
#   define  REPR_WF     (REPR_FB|REPR_K32)
#else
#   define  REPR_WF     (REPR_FL|REPR_K32)
#endif

#define     REPR_WF1    (REPR_WF|REPR_M1)
#define     REPR_WF2    (REPR_WF|REPR_M2)
#define     REPR_WF3    (REPR_WF|REPR_M3)
#define     REPR_WF4    (REPR_WF|REPR_M4)
#define     REPR_WF8    (REPR_WF|REPR_M8)
#define     REPR_WF16   (REPR_WF|REPR_M16)

#define     REPR_DU     (REPR_U|REPR_K64)
#define     REPR_DU1    (REPR_DU|REPR_M1)
#define     REPR_DU2    (REPR_DU|REPR_M2)
#define     REPR_DU3    (REPR_DU|REPR_M3)
#define     REPR_DU4    (REPR_DU|REPR_M4)
#define     REPR_DU8    (REPR_DU|REPR_M8)

#define     REPR_DI     (REPR_I|REPR_K64)
#define     REPR_DI1    (REPR_DI|REPR_M1)
#define     REPR_DI2    (REPR_DI|REPR_M2)
#define     REPR_DI3    (REPR_DI|REPR_M3)
#define     REPR_DI4    (REPR_DI|REPR_M4)
#define     REPR_DI8    (REPR_DI|REPR_M8)

#if FLT16_ENDIAN == ENDIAN_BIG
#   define  REPR_DF     (REPR_FB|REPR_K32)
#else
#   define  REPR_DF     (REPR_FL|REPR_K32)
#endif

#define     REPR_DF1    (REPR_DF|REPR_M1)
#define     REPR_DF2    (REPR_DF|REPR_M2)
#define     REPR_DF3    (REPR_DF|REPR_M3)
#define     REPR_DF4    (REPR_DF|REPR_M4)
#define     REPR_DF8    (REPR_DF|REPR_M8)

#define     REPR_VW     (REPR_V|REPR_SZW)
#define     REPR_VD     (REPR_V|REPR_SZD)
#define     REPR_VQ     (REPR_V|REPR_SZQ)
#define     REPR_VO     (REPR_V|REPR_SZO)
#define     REPR_VS     (REPR_V|REPR_SZS)

#define     REPR_VWYU   (REPR_VW|REPR_YU)
#define     REPR_VDYU   (REPR_VD|REPR_YU)
#define     REPR_VQYU   (REPR_VQ|REPR_YU)
#define     REPR_VOYU   (REPR_VO|REPR_YU)
#define     REPR_VSYU   (REPR_VS|REPR_YU)

#define     REPR_VWBU   (REPR_VW|REPR_BU)
#define     REPR_VWBI   (REPR_VW|REPR_BI)
#define     REPR_VWHU   (REPR_VW|REPR_HU)
#define     REPR_VWHI   (REPR_VW|REPR_HI)
#define     REPR_VWHF   (REPR_VW|REPR_HF)
#define     REPR_VWWU   (REPR_VW|REPR_WU)
#define     REPR_VWWI   (REPR_VW|REPR_WI)
#define     REPR_VWWF   (REPR_VW|REPR_WF)

#define     REPR_VDBU   (REPR_VD|REPR_BU)
#define     REPR_VDBI   (REPR_VD|REPR_BI)
#define     REPR_VDHU   (REPR_VD|REPR_HU)
#define     REPR_VDHI   (REPR_VD|REPR_HI)
#define     REPR_VDHF   (REPR_VD|REPR_HF)
#define     REPR_VDWU   (REPR_VD|REPR_WU)
#define     REPR_VDWI   (REPR_VD|REPR_WI)
#define     REPR_VDWF   (REPR_VD|REPR_WF)
#define     REPR_VDDU   (REPR_VD|REPR_DU)
#define     REPR_VDDI   (REPR_VD|REPR_DI)
#define     REPR_VDDF   (REPR_VD|REPR_DF)

#define     REPR_VQBU   (REPR_VQ|REPR_BU)
#define     REPR_VQBI   (REPR_VQ|REPR_BI)
#define     REPR_VQHU   (REPR_VQ|REPR_HU)
#define     REPR_VQHI   (REPR_VQ|REPR_HI)
#define     REPR_VQHF   (REPR_VQ|REPR_HF)
#define     REPR_VQWU   (REPR_VQ|REPR_WU)
#define     REPR_VQWI   (REPR_VQ|REPR_WI)
#define     REPR_VQWF   (REPR_VQ|REPR_WF)
#define     REPR_VQDU   (REPR_VQ|REPR_DU)
#define     REPR_VQDI   (REPR_VQ|REPR_DI)
#define     REPR_VQDF   (REPR_VQ|REPR_DF)

#define     REPR_VOBU   (REPR_VO|REPR_BU)
#define     REPR_VOBI   (REPR_VO|REPR_BI)
#define     REPR_VOHU   (REPR_VO|REPR_HU)
#define     REPR_VOHI   (REPR_VO|REPR_HI)
#define     REPR_VOHF   (REPR_VO|REPR_HF)
#define     REPR_VOWU   (REPR_VO|REPR_WU)
#define     REPR_VOWI   (REPR_VO|REPR_WI)
#define     REPR_VOWF   (REPR_VO|REPR_WF)
#define     REPR_VODU   (REPR_VO|REPR_DU)
#define     REPR_VODI   (REPR_VO|REPR_DI)
#define     REPR_VODF   (REPR_VO|REPR_DF)

#define     REPR_VSBU   (REPR_VS|REPR_BU)
#define     REPR_VSBI   (REPR_VS|REPR_BI)
#define     REPR_VSHU   (REPR_VS|REPR_HU)
#define     REPR_VSHI   (REPR_VS|REPR_HI)
#define     REPR_VSHF   (REPR_VS|REPR_HF)
#define     REPR_VSWU   (REPR_VS|REPR_WU)
#define     REPR_VSWI   (REPR_VS|REPR_WI)
#define     REPR_VSWF   (REPR_VS|REPR_WF)
#define     REPR_VSDU   (REPR_VS|REPR_DU)
#define     REPR_VSDI   (REPR_VS|REPR_DI)
#define     REPR_VSDF   (REPR_VS|REPR_DF)

#define     BOOL_REPR   REPR_YU

#define     UCHAR_REPR  REPR_BU
#define     SCHAR_REPR  REPR_BI

#define     USHRT_REPR  REPR_HU
#define     SHRT_REPR   REPR_HI

#define     UINT_REPR   REPR_WU
#define     INT_REPR    REPR_WI

#if REPR_KL == REPR_K32
#   define  ULONG_REPR  REPR_WU
#   define  LONG_REPR   REPR_WI
#else
#   define  ULONG_REPR  REPR_DU
#   define  LONG_REPR   REPR_DI
#endif

#if REPR_KLL == REPR_K64
#   define  ULLONG_REPR REPR_DU
#   define  LLONG_REPR  REPR_DI
#else
#   define  ULLONG_REPR REPR_QU
#   define  LLONG_REPR  REPR_QI
#endif

#if defined(FLT16_MTYPE)
#   define  FLT16_REPR  REPR_HF
#else
#   define  FLT16_REPR  REPR_HU1
#endif

#define     FLT_REPR        REPR_WF
#define     DBL_REPR        REPR_DF

#define     UINT8_REPR      REPR_BU
#define     INT8_REPR       REPR_BI

#define     UINT16_REPR     REPR_HU
#define     INT16_REPR      REPR_HI

#define     UINT32_REPR     REPR_WU
#define     INT32_REPR      REPR_WI

#define     UINT64_REPR     REPR_DU
#define     INT64_REPR      REPR_DI

#if UINTMAX_MAX == UINT64_MAX
#   define  UINTMAX_REPR    REPR_DU
#   define  INTMAX_REPR     REPR_DI
#else
#   define  UINTMAX_REPR    REPR_QU
#   define  INTMAX_REPR     REPR_QI
#endif

#if ADDR_WIDTH == 16
#   define  UINTPTR_REPR    REPR_HU
#   define  INTPTR_REPR     REPR_HI
#elif ADDR_WIDTH == 32
#   define  UINTPTR_REPR    REPR_WU
#   define  INTPTR_REPR     REPR_WI
#elif ADDR_WIDTH == 64
#   define  UINTPTR_REPR    REPR_DU
#   define  INTPTR_REPR     REPR_DI
#elif ADDR_WIDTH == 128
#   define  UINTPTR_REPR    REPR_QU
#   define  INTPTR_REPR     REPR_QI
#endif

#endif // EOF("extrepr.h")

#if _LEAVE_EXTREPR
}
#endif

#if _ENTER_EXTVEC
{
#endif

#ifndef MY_EXTVEC_H // BOF("extvec.h")
#define MY_EXTVEC_H     1

#ifndef MY_EXTREPR_H
#include  "extrepr.h"
#endif

#if _ENTER_EXTVEC_VLANES
{
#endif

#define     VWYU_(_)    VWYU_##_
#define     VDYU_(_)    VDYU_##_
#define     VQYU_(_)    VOYU_##_
#define     VOYU_(_)    VOYU_##_
#define     VSYU_(_)    VSYU_##_

#define     VWBU_(_)    VWBU_##_
#define     VDBU_(_)    VDBU_##_
#define     VQBU_(_)    VQBU_##_
#define     VOBU_(_)    VOBU_##_
#define     VSBU_(_)    VSBU_##_

#define     VWBI_(_)    VWBI_##_
#define     VDBI_(_)    VDBI_##_
#define     VQBI_(_)    VQBI_##_
#define     VOBI_(_)    VOBI_##_
#define     VSBI_(_)    VSBI_##_

#define     VWBC_(_)    VWBC_##_
#define     VDBC_(_)    VDBC_##_
#define     VQBC_(_)    VQBC_##_
#define     VOBC_(_)    VOBC_##_
#define     VSBC_(_)    VSBC_##_


#define     VWHU_(_)    VWHU_##_
#define     VDHU_(_)    VDHU_##_
#define     VQHU_(_)    VQHU_##_
#define     VOHU_(_)    VOHU_##_
#define     VSHU_(_)    VSHU_##_

#define     VWHI_(_)    VWHI_##_
#define     VDHI_(_)    VDHI_##_
#define     VQHI_(_)    VQHI_##_
#define     VOHI_(_)    VOHI_##_
#define     VSHI_(_)    VSHI_##_

#define     VWHF_(_)    VWHF_##_
#define     VDHF_(_)    VDHF_##_
#define     VQHF_(_)    VQHF_##_
#define     VOHF_(_)    VOHF_##_
#define     VSHF_(_)    VSHF_##_

#define     VWWU_(_)    VWWU_##_
#define     VDWU_(_)    VDWU_##_
#define     VQWU_(_)    VQWU_##_
#define     VOWU_(_)    VOWU_##_
#define     VSWU_(_)    VSWU_##_

#define     VWWI_(_)    VWWI_##_
#define     VDWI_(_)    VDWI_##_
#define     VQWI_(_)    VQWI_##_
#define     VOWI_(_)    VOWI_##_
#define     VSWI_(_)    VSWI_##_

#define     VWWF_(_)    VWWF_##_
#define     VDWF_(_)    VDWF_##_
#define     VQWF_(_)    VQWF_##_
#define     VOWF_(_)    VOWF_##_
#define     VSWF_(_)    VSWF_##_

#define     VDDU_(_)    VDDU_##_
#define     VQDU_(_)    VQDU_##_
#define     VODU_(_)    VODU_##_
#define     VSDU_(_)    VSDU_##_

#define     VDDI_(_)    VDDI_##_
#define     VQDI_(_)    VQDI_##_
#define     VODI_(_)    VODI_##_
#define     VSDI_(_)    VSDI_##_

#define     VDDF_(_)    VDDF_##_
#define     VQDF_(_)    VQDF_##_
#define     VODF_(_)    VODF_##_
#define     VSDF_(_)    VSDF_##_

#if CHAR_MIN
#   define  VWBC_BASE   VWBI_
#   define  VDBC_BASE   VDBI_
#   define  VQBC_BASE   VQBI_
#   define  VOBC_BASE   VOBI_
#   define  VSBC_BASE   VSBI_
#else
#   define  VWBC_BASE   VWBU_
#   define  VDBC_BASE   VDBU_
#   define  VQBC_BASE   VQBU_
#   define  VOBC_BASE   VOBU_
#   define  VSBC_BASE   VSBU_
#endif

#define     VWBU_STG    WORD_
#define     VDBU_STG    DWRD_
#define     VQBU_STG    QUAD_
#define     VOBU_STG    OCTA_
#define     VSBU_STG    SEXD_

#define     VWBI_STG    WORD_
#define     VDBI_STG    DWRD_
#define     VQBI_STG    QUAD_
#define     VOBI_STG    OCTA_
#define     VSBI_STG    SEXD_

#define     VWBC_STG    VWBC_BASE(STG)
#define     VDBC_STG    VDBC_BASE(STG)
#define     VQBC_STG    VQBC_BASE(STG)
#define     VOBC_STG    VOBC_BASE(STG)
#define     VSBC_STG    VSBC_BASE(STG)

#define     VWHU_STG    WORD_
#define     VDHU_STG    DWRD_
#define     VQHU_STG    QUAD_
#define     VOHU_STG    OCTA_
#define     VSHU_STG    SEXD_

#define     VWHI_STG    WORD_
#define     VDHI_STG    DWRD_
#define     VQHI_STG    QUAD_
#define     VOHI_STG    OCTA_
#define     VSHI_STG    SEXD_

#define     VWHF_STG    WORD_
#define     VDHF_STG    DWRD_
#define     VQHI_STG    QUAD_
#define     VOHI_STG    OCTA_
#define     VSHI_STG    SEXD_

#define     VWWU_STG    WORD_
#define     VDWU_STG    DWRD_
#define     VQWU_STG    QUAD_
#define     VOWU_STG    OCTA_
#define     VSWU_STG    SEXD_

#define     VWWI_STG    WORD_
#define     VDWI_STG    DWRD_
#define     VQWI_STG    QUAD_
#define     VOWI_STG    OCTA_
#define     VSWI_STG    SEXD_

#define     VWWF_STG    WORD_
#define     VDWF_STG    DWRD_
#define     VQWI_STG    QUAD_
#define     VOWI_STG    OCTA_
#define     VSWI_STG    SEXD_

#define     VDDU_STG    DWRD_
#define     VQDU_STG    QUAD_
#define     VODU_STG    OCTA_
#define     VSDU_STG    SEXD_

#define     VDDI_STG    DWRD_
#define     VQDI_STG    QUAD_
#define     VODI_STG    OCTA_
#define     VSDI_STG    SEXD_

#define     VDDF_STG    DWRD_
#define     VQDF_STG    QUAD_
#define     VODF_STG    OCTA_
#define     VSDF_STG    SEXD_

#define     VWYU_K      BOOL_
#define     VDYU_K      BOOL_
#define     VQYU_K      BOOL_
#define     VOYU_K      BOOL_
#define     VSYU_K      BOOL_

#define     VWBU_K      BYTE_U
#define     VDBU_K      BYTE_U
#define     VQBU_K      BYTE_U
#define     VOBU_K      BYTE_U
#define     VQBU_K      BYTE_U

#define     VWBI_K      BYTE_I
#define     VDBI_K      BYTE_I
#define     VQBI_K      BYTE_I
#define     VOBI_K      BYTE_I
#define     VSBI_K      BYTE_I

#if CHAR_MIN
#   define  VWBC_K      BYTE_I
#   define  VDBC_K      BYTE_I
#   define  VQBC_K      BYTE_I
#   define  VOBC_K      BYTE_I
#   define  VSBC_K      BYTE_I
#else
#   define  VWBC_K      BYTE_U
#   define  VDBC_K      BYTE_U
#   define  VQBC_K      BYTE_U
#   define  VOBC_K      BYTE_U
#   define  VSBC_K      BYTE_U
#endif

#define     VWHU_K      HALF_U
#define     VDHU_K      HALF_U
#define     VQHU_K      HALF_U
#define     VOHU_K      HALF_U
#define     VSHU_K      HALF_U

#define     VWHI_K      HALF_I
#define     VDHI_K      HALF_I
#define     VQHI_K      HALF_I
#define     VOHI_K      HALF_I
#define     VSHI_K      HALF_I

#define     VWHF_K      HALF_F
#define     VDHF_K      HALF_F
#define     VQHF_K      HALF_F
#define     VOHF_K      HALF_F
#define     VSHF_K      HALF_F

#define     VWWU_K      WORD_U
#define     VDWU_K      WORD_U
#define     VQWU_K      WORD_U
#define     VOWU_K      WORD_U
#define     VSWU_K      WORD_U

#define     VWWI_K      WORD_I
#define     VDWI_K      WORD_I
#define     VQWI_K      WORD_I
#define     VOWI_K      WORD_I
#define     VSWI_K      WORD_I

#define     VWWF_K      WORD_F
#define     VDWF_K      WORD_F
#define     VQWF_K      WORD_F
#define     VOWF_K      WORD_F
#define     VSWF_K      WORD_F

#define     VDDU_K      DWRD_U
#define     VQDU_K      DWRD_U
#define     VODU_K      DWRD_U
#define     VSDU_K      DWRD_U

#define     VDDI_K      DWRD_I
#define     VQDI_K      DWRD_I
#define     VODI_K      DWRD_I
#define     VSDI_K      DWRD_I

#define     VDDF_K      DWRD_F
#define     VQDF_K      DWRD_F
#define     VODF_K      DWRD_F
#define     VSDF_K      DWRD_F

#define     VWYU_KTYPE  _Bool
#define     VDYU_KTYPE  _Bool
#define     VQYU_KTYPE  _Bool
#define     VOYU_KTYPE  _Bool
#define     VSYU_KTYPE  _Bool

#if CHAR_MIN || !defined(_MSC_VER)
#   define  VWBU_KTYPE  unsigned char
#   define  VDBU_KTYPE  unsigned char
#   define  VQBU_KTYPE  unsigned char
#   define  VOBU_KTYPE  unsigned char
#   define  VSBU_KTYPE  unsigned char
#else
#   define  VWBU_KTYPE  char
#   define  VDBU_KTYPE  char
#   define  VQBU_KTYPE  char
#   define  VOBU_KTYPE  char
#   define  VSBU_KTYPE  char
#endif

#if CHAR_MIN && defined(_MSC_VER)
#   define  VWBI_KTYPE  char
#   define  VDBI_KTYPE  char
#   define  VQBI_KTYPE  char
#   define  VOBI_KTYPE  char
#   define  VSBI_KTYPE  char
#else
#   define  VWBI_KTYPE  signed char
#   define  VDBI_KTYPE  signed char
#   define  VQBI_KTYPE  signed char
#   define  VOBI_KTYPE  signed char
#   define  VSBI_KTYPE  signed char
#endif

#define     VWHU_KTYPE  unsigned short
#define     VDHU_KTYPE  unsigned short
#define     VQHU_KTYPE  unsigned short
#define     VOHU_KTYPE  unsigned short
#define     VSHU_KTYPE  unsigned short

#define     VWHI_KTYPE  short
#define     VDHI_KTYPE  short
#define     VQHI_KTYPE  short
#define     VOHI_KTYPE  short
#define     VSHI_KTYPE  short

#define     VWHF_KTYPE  flt16_t
#define     VDHF_KTYPE  flt16_t
#define     VQHF_KTYPE  flt16_t
#define     VOHF_KTYPE  flt16_t
#define     VSHF_KTYPE  flt16_t

#define     VWWU_KTYPE  unsigned int
#define     VDWU_KTYPE  unsigned int
#define     VQWU_KTYPE  unsigned int
#define     VOWU_KTYPE  unsigned int
#define     VSWU_KTYPE  unsigned int

#define     VWWI_KTYPE  int
#define     VDWI_KTYPE  int
#define     VQWI_KTYPE  int
#define     VOWI_KTYPE  int
#define     VSWI_KTYPE  int

#define     VWWF_KTYPE  float
#define     VDWF_KTYPE  float
#define     VQWF_KTYPE  float
#define     VOWF_KTYPE  float
#define     VSWF_KTYPE  float

#if DWRD_NLONG == 2
#   define  VDDU_KTYPE  unsigned long long
#   define  VQDU_KTYPE  unsigned long long
#   define  VODU_KTYPE  unsigned long long
#   define  VSDU_KTYPE  unsigned long long

#   define  VDDI_KTYPE  long long
#   define  VQDI_KTYPE  long long
#   define  VODI_KTYPE  long long
#   define  VSDI_KTYPE  long long
#else
#   define  VDDU_KTYPE  unsigned long
#   define  VQDU_KTYPE  unsigned long
#   define  VODU_KTYPE  unsigned long
#   define  VSDU_KTYPE  unsigned long

#   define  VDDI_KTYPE  long
#   define  VQDI_KTYPE  long
#   define  VODI_KTYPE  long
#   define  VSDI_KTYPE  long
#endif

#define     VDDF_KTYPE  double
#define     VQDF_KTYPE  double
#define     VODF_KTYPE  double
#define     VSDF_KTYPE  double

#define     VWYU_WIDTH  32
#define     VDYU_WIDTH  64
#define     VQYU_WIDTH  128
#define     VOYU_WIDTH  256
#define     VSYU_WIDTH  512

#define     VWBU_WIDTH  32
#define     VDBU_WIDTH  64
#define     VQBU_WIDTH  128
#define     VOBU_WIDTH  256
#define     VSBU_WIDTH  512

#define     VWBI_WIDTH  32
#define     VDBI_WIDTH  64
#define     VQBI_WIDTH  128
#define     VOBI_WIDTH  256
#define     VSBI_WIDTH  512

#define     VWBC_WIDTH  32
#define     VDBC_WIDTH  64
#define     VQBC_WIDTH  128
#define     VOBC_WIDTH  256
#define     VSBC_WIDTH  512

#define     VWHU_WIDTH  32
#define     VDHU_WIDTH  64
#define     VQHU_WIDTH  128
#define     VOHU_WIDTH  256
#define     VSHU_WIDTH  512

#define     VWHI_WIDTH  32
#define     VDHI_WIDTH  64
#define     VQHI_WIDTH  128
#define     VOHI_WIDTH  256
#define     VSHI_WIDTH  512

#define     VWHF_WIDTH  32
#define     VDHF_WIDTH  64
#define     VQHF_WIDTH  128
#define     VOHF_WIDTH  256
#define     VSHF_WIDTH  512

#define     VWWU_WIDTH  32
#define     VDWU_WIDTH  64
#define     VQWU_WIDTH  128
#define     VOWU_WIDTH  256
#define     VSWU_WIDTH  512

#define     VWWI_WIDTH  32
#define     VDWI_WIDTH  64
#define     VQWI_WIDTH  128
#define     VOWI_WIDTH  256
#define     VSWI_WIDTH  512

#define     VWWF_WIDTH  32
#define     VDWF_WIDTH  64
#define     VQWF_WIDTH  128
#define     VOWF_WIDTH  256
#define     VSWF_WIDTH  512

#define     VDDU_WIDTH  64
#define     VQDU_WIDTH  128
#define     VODU_WIDTH  256
#define     VSDU_WIDTH  512

#define     VDDI_WIDTH  64
#define     VDDF_WIDTH  64
#define     VODI_WIDTH  256
#define     VSDI_WIDTH  512

#define     VQDI_WIDTH  128
#define     VQDF_WIDTH  128
#define     VODF_WIDTH  256
#define     VSDF_WIDTH  512


#define     VWYU_NEL    32
#define     VDYU_NEL    64
#define     VQYU_NEL    128
#define     VOYU_NEL    256
#define     VSYU_NEL    512

#define     VWBU_NEL    4
#define     VDBU_NEL    8
#define     VQBU_NEL    16
#define     VOBU_NEL    32
#define     VSBU_NEL    64

#define     VWBI_NEL    4
#define     VDBI_NEL    8
#define     VQBI_NEL    16
#define     VOBI_NEL    32
#define     VSBI_NEL    64

#define     VWBC_NEL    4
#define     VDBC_NEL    8
#define     VQBC_NEL    16
#define     VOBC_NEL    32
#define     VSBC_NEL    64

#define     VWHU_NEL    2
#define     VDHU_NEL    4
#define     VQHU_NEL    8
#define     VOHU_NEL    16
#define     VSHU_NEL    32

#define     VWHI_NEL    2
#define     VDHI_NEL    4
#define     VQHI_NEL    8
#define     VOHI_NEL    16
#define     VSHI_NEL    32

#define     VWWU_NEL    1
#define     VDWU_NEL    2
#define     VQWU_NEL    4
#define     VOWU_NEL    8
#define     VSWU_NEL    16

#define     VWWI_NEL    1
#define     VDWI_NEL    2
#define     VQWI_NEL    4
#define     VOWI_NEL    8
#define     VSWI_NEL    16

#define     VWWF_NEL    1
#define     VDWF_NEL    2
#define     VQWF_NEL    4
#define     VOWF_NEL    8
#define     VSWF_NEL    16

#define     VDDU_NEL    1
#define     VQDU_NEL    2
#define     VODU_NEL    4
#define     VSDU_NEL    8

#define     VDDI_NEL    1
#define     VQDI_NEL    2
#define     VODI_NEL    4
#define     VSDI_NEL    8

#define     VDDF_NEL    1
#define     VQDF_NEL    2
#define     VODF_NEL    4
#define     VSDF_NEL    8

/*  THESE ARE OBSOLETE
*/
#if MY_VECTOR_ENDIAN == ENDIAN_BIG

//  Used for Vwhr, Vdwr, Vqdr
#   define  V2_K0   (0x1)
#   define  V2_K1   (0x0)

//  Used for Vwbr, Vdhr, Vqwr, Vodr
#   define  V4_K0   (0x3)
#   define  V4_K1   (0x2)
#   define  V4_K2   (0x1)
#   define  V4_K3   (0x0)

//  Used for Vdbr, Vqhr, Vowr, Vsdr
#   define  V8_K0   (0x7)
#   define  V8_K1   (0x6)
#   define  V8_K2   (0x5)
#   define  V8_K3   (0x4)
#   define  V8_K4   (0x3)
#   define  V8_K5   (0x2)
#   define  V8_K6   (0x1)
#   define  V8_K7   (0x0)

//  Used for Vqbr, Vohr, Vswr
#   define  V16_K0  (0xf)
#   define  V16_K1  (0xe)
#   define  V16_K2  (0xd)
#   define  V16_K3  (0xc)
#   define  V16_K4  (0xb)
#   define  V16_K5  (0xa)
#   define  V16_K6  (0x9)
#   define  V16_K7  (0x8)
#   define  V16_K8  (0x7)
#   define  V16_K9  (0x6)
#   define  V16_K10 (0x5)
#   define  V16_K11 (0x4)
#   define  V16_K12 (0x3)
#   define  V16_K13 (0x2)
#   define  V16_K14 (0x1)
#   define  V16_K15 (0x0)

//  Used for Vwyu, Vobr, Vshr
#   define  V32_K0  (0x1f)
#   define  V32_K1  (0x1e)
#   define  V32_K2  (0x1d)
#   define  V32_K3  (0x1c)
#   define  V32_K4  (0x1b)
#   define  V32_K5  (0x1a)
#   define  V32_K6  (0x19)
#   define  V32_K7  (0x18)
#   define  V32_K8  (0x17)
#   define  V32_K9  (0x16)
#   define  V32_K10 (0x15)
#   define  V32_K11 (0x14)
#   define  V32_K12 (0x13)
#   define  V32_K13 (0x12)
#   define  V32_K14 (0x11)
#   define  V32_K15 (0x10)
#   define  V32_K16 (0x0f)
#   define  V32_K17 (0x0e)
#   define  V32_K18 (0x0d)
#   define  V32_K19 (0x0c)
#   define  V32_K20 (0x0b)
#   define  V32_K21 (0x0a)
#   define  V32_K22 (0x09)
#   define  V32_K23 (0x08)
#   define  V32_K24 (0x07)
#   define  V32_K25 (0x06)
#   define  V32_K26 (0x05)
#   define  V32_K27 (0x04)
#   define  V32_K28 (0x03)
#   define  V32_K29 (0x02)
#   define  V32_K30 (0x01)
#   define  V32_K31 (0x00)

//  Used for Vdyu, Vsbr
#   define  V64_K0  (0x3f)
#   define  V64_K1  (0x3e)
#   define  V64_K2  (0x3d)
#   define  V64_K3  (0x3c)
#   define  V64_K4  (0x3b)
#   define  V64_K5  (0x3a)
#   define  V64_K6  (0x39)
#   define  V64_K7  (0x38)
#   define  V64_K8  (0x37)
#   define  V64_K9  (0x36)
#   define  V64_K10 (0x35)
#   define  V64_K11 (0x34)
#   define  V64_K12 (0x33)
#   define  V64_K13 (0x32)
#   define  V64_K14 (0x31)
#   define  V64_K15 (0x30)
#   define  V64_K16 (0x2f)
#   define  V64_K17 (0x2e)
#   define  V64_K18 (0x2d)
#   define  V64_K19 (0x2c)
#   define  V64_K20 (0x2b)
#   define  V64_K21 (0x2a)
#   define  V64_K22 (0x29)
#   define  V64_K23 (0x28)
#   define  V64_K24 (0x27)
#   define  V64_K25 (0x26)
#   define  V64_K26 (0x25)
#   define  V64_K27 (0x24)
#   define  V64_K28 (0x23)
#   define  V64_K29 (0x22)
#   define  V64_K30 (0x21)
#   define  V64_K31 (0x20)
#   define  V64_K32 (0x1f)
#   define  V64_K33 (0x1e)
#   define  V64_K34 (0x1d)
#   define  V64_K35 (0x1c)
#   define  V64_K36 (0x1b)
#   define  V64_K37 (0x1a)
#   define  V64_K38 (0x19)
#   define  V64_K39 (0x18)
#   define  V64_K40 (0x17)
#   define  V64_K41 (0x16)
#   define  V64_K42 (0x15)
#   define  V64_K43 (0x14)
#   define  V64_K44 (0x13)
#   define  V64_K45 (0x12)
#   define  V64_K46 (0x11)
#   define  V64_K47 (0x10)
#   define  V64_K48 (0x0f)
#   define  V64_K49 (0x0e)
#   define  V64_K50 (0x0d)
#   define  V64_K51 (0x0c)
#   define  V64_K52 (0x0b)
#   define  V64_K53 (0x0a)
#   define  V64_K54 (0x09)
#   define  V64_K55 (0x08)
#   define  V64_K56 (0x07)
#   define  V64_K57 (0x06)
#   define  V64_K58 (0x05)
#   define  V64_K59 (0x04)
#   define  V64_K60 (0x03)
#   define  V64_K61 (0x02)
#   define  V64_K62 (0x01)
#   define  V64_K63 (0x00)

#elif MY_VECTOR_ENDIAN == ENDIAN_LIL

#   define  V2_K0   (0x0)
#   define  V2_K1   (0x1)

#   define  V4_K0   (0x0)
#   define  V4_K1   (0x1)
#   define  V4_K2   (0x2)
#   define  V4_K3   (0x3)

#   define  V8_K0   (0x0)
#   define  V8_K1   (0x1)
#   define  V8_K2   (0x2)
#   define  V8_K3   (0x3)
#   define  V8_K4   (0x4)
#   define  V8_K5   (0x5)
#   define  V8_K6   (0x6)
#   define  V8_K7   (0x7)

#   define  V16_K0  (0x00)
#   define  V16_K1  (0x01)
#   define  V16_K2  (0x02)
#   define  V16_K3  (0x03)
#   define  V16_K4  (0x04)
#   define  V16_K5  (0x05)
#   define  V16_K6  (0x06)
#   define  V16_K7  (0x07)
#   define  V16_K8  (0x08)
#   define  V16_K9  (0x09)
#   define  V16_K10 (0x0a)
#   define  V16_K11 (0x0b)
#   define  V16_K12 (0x0c)
#   define  V16_K13 (0x0d)
#   define  V16_K14 (0x0e)
#   define  V16_K15 (0x0f)

#   define  V32_K0  (0x00)
#   define  V32_K1  (0x01)
#   define  V32_K2  (0x02)
#   define  V32_K3  (0x03)
#   define  V32_K4  (0x04)
#   define  V32_K5  (0x05)
#   define  V32_K6  (0x06)
#   define  V32_K7  (0x07)
#   define  V32_K8  (0x08)
#   define  V32_K9  (0x09)
#   define  V32_K10 (0x0a)
#   define  V32_K11 (0x0b)
#   define  V32_K12 (0x0c)
#   define  V32_K13 (0x0d)
#   define  V32_K14 (0x0e)
#   define  V32_K15 (0x0f)
#   define  V32_K16 (0x10)
#   define  V32_K17 (0x11)
#   define  V32_K18 (0x12)
#   define  V32_K19 (0x13)
#   define  V32_K20 (0x14)
#   define  V32_K21 (0x15)
#   define  V32_K22 (0x16)
#   define  V32_K23 (0x17)
#   define  V32_K24 (0x18)
#   define  V32_K25 (0x19)
#   define  V32_K26 (0x1a)
#   define  V32_K27 (0x1b)
#   define  V32_K28 (0x1c)
#   define  V32_K29 (0x1d)
#   define  V32_K30 (0x1e)
#   define  V32_K31 (0x1f)

#   define  V64_K0  (0x00)
#   define  V64_K1  (0x01)
#   define  V64_K2  (0x02)
#   define  V64_K3  (0x03)
#   define  V64_K4  (0x04)
#   define  V64_K5  (0x05)
#   define  V64_K6  (0x06)
#   define  V64_K7  (0x07)
#   define  V64_K8  (0x08)
#   define  V64_K9  (0x09)
#   define  V64_K10 (0x0a)
#   define  V64_K11 (0x0b)
#   define  V64_K12 (0x0c)
#   define  V64_K13 (0x0d)
#   define  V64_K14 (0x0e)
#   define  V64_K15 (0x0f)
#   define  V64_K16 (0x10)
#   define  V64_K17 (0x11)
#   define  V64_K18 (0x12)
#   define  V64_K19 (0x13)
#   define  V64_K20 (0x14)
#   define  V64_K21 (0x15)
#   define  V64_K22 (0x16)
#   define  V64_K23 (0x17)
#   define  V64_K24 (0x18)
#   define  V64_K25 (0x19)
#   define  V64_K26 (0x1a)
#   define  V64_K27 (0x1b)
#   define  V64_K28 (0x1c)
#   define  V64_K29 (0x1d)
#   define  V64_K30 (0x1e)
#   define  V64_K31 (0x1f)
#   define  V64_K32 (0x20)
#   define  V64_K33 (0x21)
#   define  V64_K34 (0x22)
#   define  V64_K35 (0x23)
#   define  V64_K36 (0x24)
#   define  V64_K37 (0x25)
#   define  V64_K38 (0x26)
#   define  V64_K39 (0x27)
#   define  V64_K40 (0x28)
#   define  V64_K41 (0x29)
#   define  V64_K42 (0x2a)
#   define  V64_K43 (0x2b)
#   define  V64_K44 (0x2c)
#   define  V64_K45 (0x2d)
#   define  V64_K46 (0x2e)
#   define  V64_K47 (0x2f)
#   define  V64_K48 (0x30)
#   define  V64_K49 (0x31)
#   define  V64_K50 (0x32)
#   define  V64_K51 (0x33)
#   define  V64_K52 (0x34)
#   define  V64_K53 (0x35)
#   define  V64_K54 (0x36)
#   define  V64_K55 (0x37)
#   define  V64_K56 (0x38)
#   define  V64_K57 (0x39)
#   define  V64_K58 (0x3a)
#   define  V64_K59 (0x3b)
#   define  V64_K60 (0x3c)
#   define  V64_K61 (0x3d)
#   define  V64_K62 (0x3e)
#   define  V64_K63 (0x3f)
#else
#   error "why !(MY_ENDIAN==ENDIAN_LIL || MY_ENDIAN==ENDIAN_BIG)?"
#endif

#if _LEAVE_EXTVEC_VLANES
}
#endif

#if _ENTER_EXTVEC_VSN
{
#endif

#define     VWYU_SN(_)  _##wyu
#define     VWBU_SN(_)  _##wbu
#define     VWBI_SN(_)  _##wbi
#define     VWBC_SN(_)  _##wbc
#define     VWHU_SN(_)  _##whu
#define     VWHI_SN(_)  _##whi
#define     VWHF_SN(_)  _##whf
#define     VWWU_SN(_)  _##wwu
#define     VWWI_SN(_)  _##wwi
#define     VWWF_SN(_)  _##wwf

#define     VDYU_SN(_)  _##dyu
#define     VDBU_SN(_)  _##dbu
#define     VDBI_SN(_)  _##dbi
#define     VDBC_SN(_)  _##dbc
#define     VDHU_SN(_)  _##dhu
#define     VDHI_SN(_)  _##dhi
#define     VDHF_SN(_)  _##dhf
#define     VDWU_SN(_)  _##dwu
#define     VDWI_SN(_)  _##dwi
#define     VDWF_SN(_)  _##dwf
#define     VDDU_SN(_)  _##ddu
#define     VDDI_SN(_)  _##ddi
#define     VDDF_SN(_)  _##ddf

#define     VQYU_SN(_)  _##qyu
#define     VQBU_SN(_)  _##qbu
#define     VQBI_SN(_)  _##qbi
#define     VQBC_SN(_)  _##qbc
#define     VQHU_SN(_)  _##qhu
#define     VQHI_SN(_)  _##qhi
#define     VQHF_SN(_)  _##qhf
#define     VQWU_SN(_)  _##qwu
#define     VQWI_SN(_)  _##qwi
#define     VQWF_SN(_)  _##qwf
#define     VQDU_SN(_)  _##qdu
#define     VQDI_SN(_)  _##qdi
#define     VQDF_SN(_)  _##qdf
#define     VQQU_SN(_)  _##qqu
#define     VQQI_SN(_)  _##qqi
#define     VQQF_SN(_)  _##qqf

#define     VOYU_SN(_)  _##oyu
#define     VOBU_SN(_)  _##obu
#define     VOBI_SN(_)  _##obi
#define     VOBC_SN(_)  _##obc
#define     VOHU_SN(_)  _##ohu
#define     VOHI_SN(_)  _##ohi
#define     VOHF_SN(_)  _##ohf
#define     VOWU_SN(_)  _##owu
#define     VOWI_SN(_)  _##owi
#define     VOWF_SN(_)  _##owf
#define     VODU_SN(_)  _##odu
#define     VODI_SN(_)  _##odi
#define     VODF_SN(_)  _##odf
#define     VOQU_SN(_)  _##oqu
#define     VOQI_SN(_)  _##oqi
#define     VOQF_SN(_)  _##oqf

#define     VSYU_SN(_)  _##syu
#define     VSBU_SN(_)  _##sbu
#define     VSBI_SN(_)  _##sbi
#define     VSBC_SN(_)  _##sbc
#define     VSHU_SN(_)  _##shu
#define     VSHI_SN(_)  _##shi
#define     VSHF_SN(_)  _##shf
#define     VSWU_SN(_)  _##swu
#define     VSWI_SN(_)  _##swi
#define     VSWF_SN(_)  _##swf
#define     VSDU_SN(_)  _##sdu
#define     VSDI_SN(_)  _##sdi
#define     VSDF_SN(_)  _##sdf
#define     VSQU_SN(_)  _##squ
#define     VSQI_SN(_)  _##sqi
#define     VSQF_SN(_)  _##sqf
#if _LEAVE_EXTVEC_VSN
}
#endif

#if _ENTER_EXTVEC_X86_SIMD
{
#endif

#ifdef  SPC_X86_AVX512F

#ifndef SPC_X86_SSE2
#error "why is SPC_X86_AVX512F defined but SPC_X86_SSE2 ain't?"
#endif

#define     VOYU_REPR   REPR_VOYU
#define     VOYU_MTYPE  __m256i
#define     VOYU_TYPE   __m256i

#define     VOBU_REPR   (REPR_VOBU|REPR_M1)
#define     VOBU_MTYPE  __m256i
#define     VOBU_TYPE   struct Obu1

#define     VOBI_REPR   (REPR_VOBI|REPR_M1)
#define     VOBI_MTYPE  __m256i
#define     VOBI_TYPE   struct Obi1

#if CHAR_MIN
#   define  VOBC_REPR   VOBI_REPR
#   define  VOBC_TYPE   struct Obi1
#else
#   define  VOBC_REPR   VOBU_REPR
#   define  VOBC_TYPE   struct Obu1
#endif

#define     VOHU_REPR   (REPR_VOHU|REPR_M1)
#define     VOHU_MTYPE  __m256i
#define     VOHU_TYPE   struct Ohu1

#define     VOHI_REPR   (REPR_VOHI|REPR_M1)
#define     VOHI_MTYPE  __m256i
#define     VOHI_TYPE   struct Ohi1


#define     VOWU_REPR   (REPR_VOWU|REPR_M1)
#define     VOWU_MTYPE  __m256i
#define     VOWU_TYPE   struct Owu1

#define     VOWI_REPR   (REPR_VOWI|REPR_M1)
#define     VOWI_MTYPE  __m256i
#define     VOWI_TYPE   struct Owi1

#define     VOWF_REPR   REPR_VOWF
#define     VOWF_MTYPE  __m256
#define     VOWF_TYPE   __m256


#define     VODU_REPR   (REPR_VODU|REPR_M1)
#define     VODU_MTYPE  __m256i
#define     VODU_TYPE   struct Odu1

#define     VODI_REPR   (REPR_VODI|REPR_M1)
#define     VODI_MTYPE  __m256i
#define     VODI_TYPE   struct Odi1

#define     VODF_REPR   REPR_VODF
#define     VODF_MTYPE  __m256d
#define     VODF_TYPE   __m256d


#define     VSYU_REPR   REPR_VSYU
#define     VSYU_MTYPE  __m512i
#define     VSYU_TYPE   __m512i

#define     VSBU_REPR   (REPR_VSBU|REPR_M1)
#define     VSBU_MTYPE  __m512i
#define     VSBU_TYPE   struct Sbu1

#define     VSBI_REPR   (REPR_VSBI|REPR_M1)
#define     VSBI_MTYPE  __m512i
#define     VSBI_TYPE   struct Sbi1

#if CHAR_MIN
#   define  VSBC_REPR   VSBI_REPR
#   define  VSBC_TYPE   struct Sbi1
#else
#   define  VSBC_REPR   VSBU_REPR
#   define  VSBC_TYPE   struct Sbu1
#endif


#define     VSHU_REPR   (REPR_VSHU|REPR_M1)
#define     VSHU_MTYPE  __m512i
#define     VSHU_TYPE   struct Shu1

#define     VSHI_REPR   (REPR_VSHI|REPR_M1)
#define     VSHI_MTYPE  __m512i
#define     VSHI_TYPE   struct Shi1


#define     VSWU_REPR   (REPR_VSWU|REPR_M1)
#define     VSWU_MTYPE  __m512i
#define     VSWU_TYPE   struct Swu1

#define     VSWI_REPR   (REPR_VSWI|REPR_M1)
#define     VSWI_MTYPE  __m512i
#define     VSWI_TYPE   struct Swi1

#define     VSWF_REPR   REPR_VSWF
#define     VSWF_MTYPE  __m512
#define     VSWF_TYPE   __m512


#define     VSDU_REPR   (REPR_VSDU|REPR_M1)
#define     VSDU_MTYPE  __m512i
#define     VSDU_TYPE   struct Sdu1

#define     VSDI_REPR   (REPR_VSDI|REPR_M1)
#define     VSDI_MTYPE  __m512i
#define     VSDI_TYPE   struct Sdi1

#define     VSDF_REPR   REPR_VSDF
#define     VSDF_MTYPE  __m512d
#define     VSDF_TYPE   __m512d

#if defined(SPC_X86_AVX512FP16)
#   define  VQHF_REPR   REPR_VQHF
#   define  VQHF_MTYPE  __m128h
#   define  VQHF_TYPE   __m128h

#   define  VOHF_REPR   REPR_VOHF
#   define  VOHF_MTYPE  __m256h
#   define  VOHF_TYPE   __m256h

#   define  VSHF_REPR   REPR_VSHF
#   define  VSHF_MTYPE  __m512h
#   define  VSHF_TYPE   __m512h
#else
#   define  VQHF_REPR   (REPR_VQHU|REPR_M1)
#   define  VQHF_MTYPE  __m128i
#   define  VQHF_TYPE   struct Qhf1

#   define  VOHF_REPR   (REPR_VOHU|REPR_M1)
#   define  VOHF_MTYPE  __m256i
#   define  VOHF_TYPE   struct Ohf1

#   define  VSHF_REPR   (REPR_VOHU|REPR_M1)
#   define  VSHF_MTYPE  __m512i
#   define  VSHF_TYPE   struct Shf1
#endif

#endif

#if defined(SPC_X86_SSE2)

#   ifndef MY_IMMINTRIN_H
#   define MY_IMMINTRIN_H
#   include <immintrin.h>
#   endif

#   define  VWYU_MTYPE  float
#   define  VWYU_TYPE   struct Wyu1
#   define  VWYU_REPR   REPR_WF1

#   define  VWBU_MTYPE  float
#   define  VWBU_TYPE   struct Wbu1
#   define  VWBU_REPR   REPR_WF1

#   define  VWBI_MTYPE  float
#   define  VWBI_TYPE   struct Wbi1
#   define  VWBI_REPR   REPR_WF1

#   define  VWBC_MTYPE  float
#   define  VWBC_TYPE   struct Wbc1
#if CHAR_MIN
#   define  VWBC_REPR   REPR_VWBI
#else
#   define  VWBC_REPR   REPR_VWBU
#endif

#   define  VWHU_REPR   REPR_WF1
#   define  VWHU_MTYPE  float
#   define  VWHU_TYPE   struct Whu1

#   define  VWHI_REPR   REPR_WF1
#   define  VWHI_MTYPE  float
#   define  VWHI_TYPE   struct Whi1

#   define  VWHF_REPR   REPR_WF1
#   define  VWHF_MTYPE  float
#   define  VWHF_TYPE   struct Whf1


#   define  VWWU_REPR   REPR_WF1
#   define  VWWU_MTYPE  float
#   define  VWWU_TYPE   struct Wwu1

#   define  VWWI_REPR   REPR_WF1
#   define  VWWI_MTYPE  float
#   define  VWWI_TYPE   struct Wwi1

#   define  VWWF_REPR   REPR_WF1
#   define  VWWF_MTYPE  float
#   define  VWWF_TYPE   struct Wwf1


#   define  VDYU_REPR   REPR_DF1
#   define  VDYU_MTYPE  double
#   define  VDYU_TYPE   struct Dyu1

#   define  VDBU_REPR   REPR_DF1
#   define  VDBU_MTYPE  double
#   define  VDBU_TYPE   struct Dbu1

#   define  VDBI_REPR   REPR_DF1
#   define  VDBI_MTYPE  double
#   define  VDBI_TYPE   struct Dbi1

#   define  VDBC_MTYPE  double
#if CHAR_MIN
#   define  VDBC_REPR   REPR_VDBI
#   define  VDBC_TYPE   struct Dbi1
#else
#   define  VDBC_REPR   REPR_VDBU
#   define  VDBC_TYPE   struct Dbu1
#endif

#   define  VDHU_REPR   REPR_DF1
#   define  VDHU_MTYPE  double
#   define  VDHU_TYPE   struct Dhu1

#   define  VDHI_REPR   REPR_DF1
#   define  VDHI_MTYPE  double
#   define  VDHI_TYPE   struct Dhi1

#   define  VDHF_REPR   REPR_DF1
#   define  VDHF_MTYPE  double
#   define  VDHF_TYPE   struct Dhf1


#   define  VDWU_REPR   REPR_DF1
#   define  VDWU_MTYPE  double
#   define  VDWU_TYPE   struct Dwu1

#   define  VDWI_REPR   REPR_DF1
#   define  VDWI_MTYPE  double
#   define  VDWI_TYPE   struct Dwi1

#   define  VDWF_REPR   REPR_DF1
#   define  VDWF_MTYPE  double
#   define  VDWF_TYPE   struct Dwf1


#   define  VDDU_REPR   REPR_DF1
#   define  VDDU_MTYPE  double
#   define  VDDU_TYPE   struct Ddu1

#   define  VDDI_REPR   REPR_DF1
#   define  VDDI_MTYPE  double
#   define  VDDI_TYPE   struct Ddi1

#   define  VDDF_REPR   REPR_DF1
#   define  VDDF_MTYPE  double
#   define  VDDF_TYPE   struct Ddf1


#   define  VQYU_REPR   REPR_VQYU
#   define  VQYU_MTYPE  __m128i
#   define  VQYU_TYPE   __m128i

#   define  VQBU_REPR   (REPR_VQBU|REPR_M1)
#   define  VQBU_MTYPE  __m128i
#   define  VQBU_TYPE   struct Qbu1

#   define  VQBI_REPR   (REPR_VQBI|REPR_M1)
#   define  VQBI_MTYPE  __m128i
#   define  VQBI_TYPE   struct Qbi1

#   define  VQBC_MTYPE  __m128i
#if CHAR_MIN
#   define  VQBC_REPR   REPR_VQBI
#   define  VQBC_TYPE   struct Qbi1
#else
#   define  VQBC_REPR   REPR_VQBU
#   define  VQBC_TYPE   struct Qbu1
#endif


#   define  VQHU_REPR   (REPR_VQHU|REPR_M1)
#   define  VQHU_MTYPE  __m128i
#   define  VQHU_TYPE   struct Qhu1

#   define  VQHI_REPR   (REPR_VQHI|REPR_M1)
#   define  VQHI_MTYPE  __m128i
#   define  VQHI_TYPE   struct Qhi1

#   ifndef  SPC_X86_AVX512F
#   define  VQHF_REPR   (REPR_VQHU|REPR_M1)
#   define  VQHF_MTYPE  __m128i
#   define  VQHF_TYPE   struct Qhf1
#   endif


#   define  VQWU_REPR   (REPR_VQWU|REPR_M1)
#   define  VQWU_MTYPE  __m128i
#   define  VQWU_TYPE   struct Qwu1

#   define  VQWI_REPR   (REPR_VQWI|REPR_M1)
#   define  VQWI_MTYPE  __m128i
#   define  VQWI_TYPE   struct Qwi1

#   define  VQWF_REPR   REPR_VQWF
#   define  VQWF_MTYPE  __m128
#   define  VQWF_TYPE   __m128


#   define  VQDU_REPR   (REPR_VQDU|REPR_M1)
#   define  VQDU_MTYPE  __m128i
#   define  VQDU_TYPE   struct Qdu1

#   define  VQDI_REPR   (REPR_VQDI|REPR_M1)
#   define  VQDI_MTYPE  __m128i
#   define  VQDI_TYPE   struct Qdi1

#   define  VQDF_REPR   REPR_VQDF
#   define  VQDF_MTYPE  __m128d
#   define  VQDF_TYPE   __m128d

#   ifndef  SPC_X86_AVX512F

#   define  VOYU_REPR   (REPR_VQYU|REPR_M2)
#   define  VOYU_TYPE   struct Qyu2

#   define  VOBU_REPR   (REPR_VQBU|REPR_M2)
#   define  VOBU_TYPE   struct Qbu2

#   define  VOBI_REPR   (REPR_VQBI|REPR_M2)
#   define  VOBI_TYPE   struct Qbi2

#if CHAR_MIN
#   define  VOBC_REPR   REPR_VOBI
#   define  VOBC_TYPE   struct Qbi2
#else
#   define  VOBC_REPR   REPR_VOBU
#   define  VOBC_TYPE   struct Qbu2
#endif


#   define  VOHU_REPR   (REPR_VQHU|REPR_M2)
#   define  VOHU_TYPE   struct Qhu2

#   define  VOHI_REPR   (REPR_VQHI|REPR_M2)
#   define  VOHI_TYPE   struct Qhi2

#   define  VOHF_REPR   (REPR_VQHU|REPR_M2)
#   define  VOHF_TYPE   struct Qhf2


#   define  VOWU_REPR   (REPR_VQWU|REPR_M2)
#   define  VOWU_TYPE   struct Qwu2

#   define  VOWI_REPR   (REPR_VQWI|REPR_M2)
#   define  VOWI_TYPE   struct Qwi2

#   define  VOWF_REPR   (REPR_VQWF|REPR_M2)
#   define  VOWF_TYPE   struct Qwf2


#   define  VODU_REPR   (REPR_VQDU|REPR_M2)
#   define  VODU_TYPE   struct Qdu2

#   define  VODI_REPR   (REPR_VQDI|REPR_M2)
#   define  VODI_TYPE   struct Qdi2

#   define  VODF_REPR   (REPR_VQDF|REPR_M2)
#   define  VODF_TYPE   struct Qdf2


#   define  VSYU_REPR   (REPR_VQYU|REPR_M4)
#   define  VSYU_TYPE   struct Qyu4

#   define  VSBU_REPR   (REPR_VQBU|REPR_M4)
#   define  VSBU_TYPE   struct Qbu4

#   define  VSBI_REPR   (REPR_VQBI|REPR_M4)
#   define  VSBI_TYPE   struct Qbi4


#if CHAR_MIN
#   define  VSBC_REPR   REPR_VSBI
#   define  VSBC_TYPE   struct Qbi4
#else
#   define  VSBC_REPR   REPR_VSBU
#   define  VSBC_TYPE   struct Qbu4
#endif

#   define  VSHU_REPR   (REPR_VQHU|REPR_M4)
#   define  VSHU_TYPE   struct Qhu4

#   define  VSHI_REPR   (REPR_VQHI|REPR_M4)
#   define  VSHI_TYPE   struct Qhi4

#   define  VSHF_REPR   (REPR_VQHU|REPR_M4)
#   define  VSHF_TYPE   struct Qhf4


#   define  VSWU_REPR   (REPR_VQWU|REPR_M4)
#   define  VSWU_TYPE   struct Qwu4

#   define  VSWI_REPR   (REPR_VQWI|REPR_M4)
#   define  VSWI_TYPE   struct Qwi4

#   define  VSWF_REPR   (REPR_VQWF|REPR_M4)
#   define  VSWF_TYPE   struct Qwf4


#   define  VSDU_REPR   (REPR_VQDU|REPR_M4)
#   define  VSDU_TYPE   struct Qdu4

#   define  VSDI_REPR   (REPR_VQDI|REPR_M4)
#   define  VSDI_TYPE   struct Qdi4

#   define  VSDF_REPR   (REPR_VQDF|REPR_M4)
#   define  VSDF_TYPE   struct Qdf4

#   endif

#endif


#if _LEAVE_EXTVEC_X86_SIMD
}
#endif

#if _ENTER_EXTVEC_ARM_SIMD
{
#endif


#if defined(SPC_ARM_NEON)

/*  A clang/LLVM compiler is required for arm targets, at
    least until Microsoft implements the ACLE.
*/
#   ifndef  MY_ARM_NEON_H
#   define  MY_ARM_NEON_H
#   include   <arm_neon.h>
#   endif

#   define  VWYU_REPR       REPR_WF1
#   define  VWYU_MTYPE      float
#   define  VWYU_TYPE       struct Wyu1

#   define  VWBU_REPR       REPR_WF1
#   define  VWBU_MTYPE      float
#   define  VWBU_TYPE       struct Wbu1

#   define  VWBI_REPR       REPR_WF1
#   define  VWBI_MTYPE      float
#   define  VWBI_TYPE       struct Wbi1

#   define  VWBC_MTYPE      float
#   define  VWBC_TYPE       struct Wbc1
#if CHAR_MIN
#   define  VWBC_REPR       REPR_VWBI
#else
#   define  VWBC_REPR       REPR_VWBU
#endif

#   define  VWHU_REPR       REPR_WF1
#   define  VWHU_MTYPE      float
#   define  VWHU_TYPE       struct Whu1

#   define  VWHI_REPR       REPR_WF1
#   define  VWHI_MTYPE      float
#   define  VWHI_TYPE       struct Whi1

#   define  VWHF_REPR       REPR_WF1
#   define  VWHF_MTYPE      float
#   define  VWHF_TYPE       struct Whf1


#   define  VWWU_REPR       REPR_WF1
#   define  VWWU_MTYPE      float
#   define  VWWU_TYPE       struct Wwu1

#   define  VWWI_REPR       REPR_WF1
#   define  VWWI_MTYPE      float
#   define  VWWI_TYPE       struct Wwi1

#   define  VWWF_REPR       REPR_WF1
#   define  VWWF_MTYPE      float
#   define  VWWF_TYPE       struct Wwf1

#   define  VDYU_REPR       (REPR_VDDU|REPR_M1)
#   define  VDYU_MTYPE      uint64x1_t
#   define  VDYU_TYPE       struct Dyu1
#   define  VDYU_M2TYPE     uint64x1x2_t
#   define  VDYU_M3TYPE     uint64x1x3_t
#   define  VDYU_M4TYPE     uint64x1x4_t

#   define  VDBU_REPR       REPR_VDBU
#   define  VDBU_TYPE       uint8x8_t
#   define  VDBU_MTYPE      uint8x8_t
#   define  VDBU_M2TYPE     uint8x8x2_t
#   define  VDBU_M3TYPE     uint8x8x3_t
#   define  VDBU_M4TYPE     uint8x8x4_t

#   define  VDBI_REPR       REPR_VDBI
#   define  VDBI_TYPE       int8x8_t
#   define  VDBI_MTYPE      int8x8_t
#   define  VDBI_M2TYPE     int8x8x2_t
#   define  VDBI_M3TYPE     int8x8x3_t
#   define  VDBI_M4TYPE     int8x8x4_t

#   define  VDBC_TYPE       struct Dbc1
#if CHAR_MIN
#   define  VDBC_REPR       REPR_VDBI
#   define  VDBC_MTYPE      int8x8_t
#   define  VDBC_M2TYPE     int8x8x2_t
#   define  VDBC_M3TYPE     int8x8x3_t
#   define  VDBC_M4TYPE     int8x8x4_t
#else
#   define  VDBC_REPR       REPR_VDBU
#   define  VDBC_MTYPE      uint8x8_t
#   define  VDBC_M2TYPE     uint8x8x2_t
#   define  VDBC_M3TYPE     uint8x8x3_t
#   define  VDBC_M4TYPE     uint8x8x4_t
#endif

#   define  VDHU_REPR       REPR_VDHU
#   define  VDHU_TYPE       uint16x4_t
#   define  VDHU_MTYPE      uint16x4_t
#   define  VDHU_M2TYPE     uint16x4x2_t
#   define  VDHU_M3TYPE     uint16x4x3_t
#   define  VDHU_M4TYPE     uint16x4x4_t

#   define  VDHI_REPR       REPR_VDHI
#   define  VDHI_TYPE       int16x4_t
#   define  VDHI_MTYPE      int16x4_t
#   define  VDHI_M2TYPE     int16x4x2_t
#   define  VDHI_M3TYPE     int16x4x3_t
#   define  VDHI_M4TYPE     int16x4x4_t

#   define  VDHF_REPR       REPR_VDHF
#   define  VDHF_TYPE       float16x4_t
#   define  VDHF_MTYPE      float16x4_t
#   define  VDHF_M2TYPE     float16x4x2_t
#   define  VDHF_M3TYPE     float16x4x3_t
#   define  VDHF_M4TYPE     float16x4x4_t


#   define  VDWU_REPR       REPR_VDWU
#   define  VDWU_TYPE       uint32x2_t
#   define  VDWU_MTYPE      uint32x2_t
#   define  VDWU_M2TYPE     uint32x2x2_t
#   define  VDWU_M3TYPE     uint32x2x3_t
#   define  VDWU_M4TYPE     uint32x2x4_t

#   define  VDWI_REPR       REPR_VDWI
#   define  VDWI_TYPE       int32x2_t
#   define  VDWI_MTYPE      int32x2_t
#   define  VDWI_M2TYPE     int32x2x2_t
#   define  VDWI_M3TYPE     int32x2x3_t
#   define  VDWI_M4TYPE     int32x2x4_t

#   define  VDWF_REPR       REPR_VDWF
#   define  VDWF_TYPE       float32x2_t
#   define  VDWF_MTYPE      float32x2_t
#   define  VDWF_M2TYPE     float32x2x2_t
#   define  VDWF_M3TYPE     float32x2x3_t
#   define  VDWF_M4TYPE     float32x2x4_t

#   define  VDDU_REPR       REPR_VDDU
#   define  VDDU_TYPE       uint64x1_t
#   define  VDDU_MTYPE      uint64x1_t
#   define  VDDU_M2TYPE     uint64x1x2_t
#   define  VDDU_M3TYPE     uint64x1x3_t
#   define  VDDU_M4TYPE     uint64x1x4_t

#   define  VDDI_REPR       REPR_VDDI
#   define  VDDI_TYPE       int64x1_t
#   define  VDDI_MTYPE      int64x1_t
#   define  VDDI_M2TYPE     int64x1x2_t
#   define  VDDI_M3TYPE     int64x1x3_t
#   define  VDDI_M4TYPE     int64x1x4_t

#   define  VDDF_REPR       REPR_VDDF
#   define  VDDF_TYPE       float64x1_t
#   define  VDDF_MTYPE      float64x1_t
#   define  VDDF_M2TYPE     float64x1x2_t
#   define  VDDF_M3TYPE     float64x1x3_t
#   define  VDDF_M4TYPE     float64x1x4_t

#   define  VQYU_REPR       REPR_VQDU
#   define  VQYU_TYPE       struct Qyu1
#   define  VQYU_MTYPE      uint64x2_t
#   define  VQYU_M2TYPE     uint64x2x2_t
#   define  VQYU_M3TYPE     uint64x2x3_t
#   define  VQYU_M4TYPE     uint64x2x4_t

#   define  VQBU_REPR       REPR_VQBU
#   define  VQBU_TYPE       uint8x16_t
#   define  VQBU_MTYPE      uint8x16_t
#   define  VQBU_M2TYPE     uint8x16x2_t
#   define  VQBU_M3TYPE     uint8x16x3_t
#   define  VQBU_M4TYPE     uint8x16x4_t

#   define  VQBI_REPR       REPR_VQBI
#   define  VQBI_TYPE       int8x16_t
#   define  VQBI_MTYPE      int8x16_t
#   define  VQBI_M2TYPE     int8x16x2_t
#   define  VQBI_M3TYPE     int8x16x3_t
#   define  VQBI_M4TYPE     int8x16x4_t

#   define  VQBC_TYPE       struct Qbc1
#if CHAR_MIN
#   define  VQBC_REPR       REPR_VQBI
#   define  VQBC_MTYPE      int8x16_t
#   define  VQBC_M2TYPE     int8x16x2_t
#   define  VQBC_M3TYPE     int8x16x3_t
#   define  VQBC_M4TYPE     int8x16x4_t
#else
#   define  VQBC_REPR       REPR_VQBU
#   define  VQBC_MTYPE      uint8x16_t
#   define  VQBC_M2TYPE     uint8x16x2_t
#   define  VQBC_M3TYPE     uint8x16x3_t
#   define  VQBC_M4TYPE     uint8x16x4_t
#endif

#   define  VQHU_REPR       REPR_VQHU
#   define  VQHU_TYPE       uint16x8_t
#   define  VQHU_MTYPE      uint16x8_t
#   define  VQHU_M2TYPE     uint16x8x2_t
#   define  VQHU_M3TYPE     uint16x8x3_t
#   define  VQHU_M4TYPE     uint16x8x4_t

#   define  VQHI_REPR       REPR_VQHI
#   define  VQHI_TYPE       int16x8_t
#   define  VQHI_MTYPE      int16x8_t
#   define  VQHI_M2TYPE     int16x8x2_t
#   define  VQHI_M3TYPE     int16x8x3_t
#   define  VQHI_M4TYPE     int16x8x4_t

#   define  VQHF_REPR       REPR_VQHF
#   define  VQHF_TYPE       float16x8_t
#   define  VQHF_MTYPE      float16x8_t
#   define  VQHF_M2TYPE     float16x8x2_t
#   define  VQHF_M3TYPE     float16x8x3_t
#   define  VQHF_M4TYPE     float16x8x4_t

#   define  VQWU_REPR       REPR_VQWU
#   define  VQWU_TYPE       uint32x4_t
#   define  VQWU_MTYPE      uint32x4_t
#   define  VQWU_M2TYPE     uint32x4x2_t
#   define  VQWU_M3TYPE     uint32x4x3_t
#   define  VQWU_M4TYPE     uint32x4x4_t

#   define  VQWI_REPR       REPR_VQWI
#   define  VQWI_TYPE       int32x4_t
#   define  VQWI_MTYPE      int32x4_t
#   define  VQWI_M2TYPE     int32x4x2_t
#   define  VQWI_M3TYPE     int32x4x3_t
#   define  VQWI_M4TYPE     int32x4x4_t

#   define  VQWF_REPR       REPR_VQWF
#   define  VQWF_TYPE       float32x4_t
#   define  VQWF_MTYPE      float32x4_t
#   define  VQWF_M2TYPE     float32x4x2_t
#   define  VQWF_M3TYPE     float32x4x3_t
#   define  VQWF_M4TYPE     float32x4x4_t

#   define  VQDU_REPR       REPR_VQDU
#   define  VQDU_TYPE       uint64x2_t
#   define  VQDU_MTYPE      uint64x2_t
#   define  VQDU_M2TYPE     uint64x2x2_t
#   define  VQDU_M3TYPE     uint64x2x3_t
#   define  VQDU_M4TYPE     uint64x2x4_t

#   define  VQDI_REPR       REPR_VQDI
#   define  VQDI_TYPE       int64x2_t
#   define  VQDI_MTYPE      int64x2_t
#   define  VQDI_M2TYPE     int64x2x2_t
#   define  VQDI_M3TYPE     int64x2x3_t
#   define  VQDI_M4TYPE     int64x2x4_t

#   define  VQDF_REPR       REPR_VQDF
#   define  VQDF_TYPE       float64x2_t
#   define  VQDF_MTYPE      float64x2_t
#   define  VQDF_M2TYPE     float64x2x2_t
#   define  VQDF_M3TYPE     float64x2x3_t
#   define  VQDF_M4TYPE     float64x2x4_t

#   define  VQQU_TYPE       struct Qqu1
#   define  VQQU_MTYPE      uint64x2_t
#   define  VQQU_M2TYPE     uint64x2x2_t
#   define  VQQU_M3TYPE     uint64x2x3_t
#   define  VQQU_M4TYPE     uint64x2x4_t

#   define  VQQI_TYPE       struct Qqi1
#   define  VQQI_MTYPE      int64x2_t
#   define  VQQI_M2TYPE     int64x2x2_t
#   define  VQQI_M3TYPE     int64x2x3_t
#   define  VQQI_M4TYPE     int64x2x4_t

#   define  VQQF_TYPE       struct Qqf1
#   define  VQQF_MTYPE      long double

#   define  VOYU_REPR       (REPR_VQYU|REPR_M2)
#   define  VOYU_TYPE       struct Qyu2

#   define  VOBU_REPR       (REPR_VQBU|REPR_M2)
#   define  VOBU_TYPE       struct Qbu2

#   define  VOBI_REPR       (REPR_VQBI|REPR_M2)
#   define  VOBI_TYPE       struct Qbi2

#   define  VOBC_TYPE       struct Qbc2
#if CHAR_MIN
#   define  VOBC_REPR       VOBI_REPR
#else
#   define  VOBC_REPR       VOBU_REPR
#endif

#   define  VOHU_REPR       (REPR_VQHU|REPR_M2)
#   define  VOHU_TYPE       struct Qhu2

#   define  VOHI_REPR       (REPR_VQHI|REPR_M2)
#   define  VOHI_TYPE       struct Qhi2

#   define  VOHF_REPR       (REPR_VQHF|REPR_M2)
#   define  VOHF_TYPE       struct Qhf2

#   define  VOWU_REPR       (REPR_VQWU|REPR_M2)
#   define  VOWU_TYPE       struct Qwu2

#   define  VOWI_REPR       (REPR_VQWI|REPR_M2)
#   define  VOWI_TYPE       struct Qwi2

#   define  VOWF_REPR       (REPR_VQWF|REPR_M2)
#   define  VOWF_TYPE       struct Qwf2

#   define  VODU_REPR       (REPR_VQDU|REPR_M2)
#   define  VODU_TYPE       struct Qdu2

#   define  VODI_REPR       (REPR_VQDI|REPR_M2)
#   define  VODI_TYPE       struct Qdi2

#   define  VODF_REPR       (REPR_VQDF|REPR_M2)
#   define  VODF_TYPE       struct Qdf2


#   define  VSYU_REPR       (REPR_VQYU|REPR_M4)
#   define  VSYU_TYPE       struct Qyu4

#   define  VSBU_REPR       (REPR_VQBU|REPR_M4)
#   define  VSBU_TYPE       struct Qbu4

#   define  VSBI_REPR       (REPR_VQBI|REPR_M4)
#   define  VSBI_TYPE       struct Qbi4

#   define  VSBC_TYPE       struct Qbc4
#if CHAR_MIN
#   define  VSBC_REPR       VSBI_REPR
#else
#   define  VSBC_REPR       VSBU_REPR
#endif

#   define  VSHU_REPR       (REPR_VQHU|REPR_M4)
#   define  VSHU_TYPE       struct Qhu4

#   define  VSHI_REPR       (REPR_VQHI|REPR_M4)
#   define  VSHI_TYPE       struct Qhi4

#   define  VSHF_REPR       (REPR_VQHF|REPR_M4)
#   define  VSHF_TYPE       struct Qhf4


#   define  VSWU_REPR       (REPR_VQWU|REPR_M4)
#   define  VSWU_TYPE       struct Qwu4

#   define  VSWI_REPR       (REPR_VQWI|REPR_M4)
#   define  VSWI_TYPE       struct Qwi4

#   define  VSWF_REPR       (REPR_VQWF|REPR_M4)
#   define  VSWF_TYPE       struct Qwf4


#   define  VSDU_REPR       (REPR_VQDU|REPR_M4)
#   define  VSDU_TYPE       struct Qdu4

#   define  VSDI_REPR       (REPR_VQDI|REPR_M4)
#   define  VSDI_TYPE       struct Qdi4

#   define  VSDF_REPR       (REPR_VQDF|REPR_M4)
#   define  VSDF_TYPE       struct Qdf4

#endif

#if _LEAVE_EXTVEC_ARM_SIMD
}
#endif

#if _ENTER_EXTVEC_PPC_SIMD
{
#endif

#if defined(SPC_PPC_ALTIVEC)
/*  Altivec was the name used by Motorola to refer to the
    VMX (Power Vector Media Extension), which initially was
    limited to char, short, int, and float vectors.
    In ISA 2.07, VSX (Vector-Scalar Extension) added
    support for 64 bit ints and double.

    __VEC_ELEMENT_REG_ORDER__ is defined as
    __ORDER_BIG_ENDIAN__ or __ORDER_LITTLE_ENDIAN__

    The ELFv2 ABI for Power defines a `vector _Float16`
    type but as of 2023-10, no compiler actually implements
    it.

*/


#   define  VQBU_REPR       REPR_VQBU
#   define  VQBU_TYPE       vector unsigned char
#   define  VQBU_MTYPE      vector unsigned char

#   define  VQBI_REPR       REPR_VQBI
#   define  VQBI_TYPE       vector signed char
#   define  VQBI_MTYPE      vector signed char

#if CHAR_MIN
#   define  VQBC_REPR       VQBI_REPR
#   define  VQBC_TYPE       vector signed char
#else
#   define  VQBC_REPR       VQBU_REPR
#   define  VQBC_TYPE       vector unsigned char
#endif

#   define  VQHU_REPR       REPR_VQHU
#   define  VQHU_TYPE       vector unsigned short
#   define  VQHU_MTYPE      vector unsigned short

#   define  VQHI_REPR       REPR_VQHI
#   define  VQHI_TYPE       vector signed short
#   define  VQHI_MTYPE      vector signed short

#   define  VQHF_REPR       REPR_VQHF
#   define  VQHF_TYPE       vector unsigned short
#   define  VQHF_MTYPE      vector unsigned short

#   define  VQWU_REPR       REPR_VQWU
#   define  VQWU_TYPE       vector unsigned int
#   define  VQWU_MTYPE      vector unsigned int

#   define  VQWI_REPR       REPR_VQWI
#   define  VQWI_TYPE       vector signed int
#   define  VQWI_MTYPE      vector signed int

#   define  VQWF_REPR       REPR_VQWF
#   define  VQWF_TYPE       vector float
#   define  VQWF_MTYPE      vector float

#   define  VQDU_REPR       REPR_VQDU
#   define  VQDU_TYPE       vector unsigned long long
#   define  VQDU_MTYPE      vector unsigned long long

#   define  VQDI_REPR       REPR_VQDI
#   define  VQDI_TYPE       vector signed long long
#   define  VQDI_MTYPE      vector signed long long

#   define  VQDF_REPR       REPR_VQDF
#   define  VQDF_TYPE       vector double
#   define  VQDF_MTYPE      vector double

#   define  VOBU_REPR       (REPR_VQBU|REPR_M2)
#   define  VOBU_TYPE       struct Qbu2

#   define  VOBI_REPR       (REPR_VQBI|REPR_M2)
#   define  VOBI_TYPE       struct Qbi2

#   define  VOHU_REPR       (REPR_VQHU|REPR_M2)
#   define  VOHU_TYPE       struct Qhu2

#   define  VOHI_REPR       (REPR_VQHI|REPR_M2)
#   define  VOHI_TYPE       struct Qhi2

#   define  VOHF_REPR       (REPR_VQHF|REPR_M2)
#   define  VOHF_TYPE       struct Qhf2

#   define  VOWU_REPR       (REPR_VQWU|REPR_M2)
#   define  VOWU_TYPE       struct Qwu2

#   define  VOWI_REPR       (REPR_VQWI|REPR_M2)
#   define  VOWI_TYPE       struct Qwi2

#   define  VOWF_REPR       (REPR_VQWF|REPR_M2)
#   define  VOWF_TYPE       struct Qwf2

#   define  VODU_REPR       (REPR_VQDU|REPR_M2)
#   define  VODU_TYPE       struct Qdu2

#   define  VODI_REPR       (REPR_VQDI|REPR_M2)
#   define  VODI_TYPE       struct Qdi2

#   define  VODF_REPR       (REPR_VQDF|REPR_M2)
#   define  VODF_TYPE       struct Qdf2


#   define  VSBU_REPR       (REPR_VQBU|REPR_M4)
#   define  VSBU_TYPE       struct Qbu4

#   define  VSBI_REPR       (REPR_VQBI|REPR_M4)
#   define  VSBI_TYPE       struct Qbi4


#   define  VSHU_REPR       (REPR_VQHU|REPR_M4)
#   define  VSHU_TYPE       struct Qhu4

#   define  VSHI_REPR       (REPR_VQHI|REPR_M4)
#   define  VSHI_TYPE       struct Qhi4

#   define  VSHF_REPR       (REPR_VQHF|REPR_M4)
#   define  VSHF_TYPE       struct Qhf4


#   define  VSWU_REPR       (REPR_VQWU|REPR_M4)
#   define  VSWU_TYPE       struct Qwu4

#   define  VSWI_REPR       (REPR_VQWI|REPR_M4)
#   define  VSWI_TYPE       struct Qwi4

#   define  VSWF_REPR       (REPR_VQWF|REPR_M4)
#   define  VSWF_TYPE       struct Qwf4


#   define  VSDU_REPR       (REPR_VQDU|REPR_M4)
#   define  VSDU_TYPE       struct Qdu4

#   define  VSDI_REPR       (REPR_VQDI|REPR_M4)
#   define  VSDI_TYPE       struct Qdi4

#   define  VSDF_REPR       (REPR_VQDF|REPR_M4)
#   define  VSDF_TYPE       struct Qdf4

#endif

#if _LEAVE_EXTVEC_PPC_SIMD
}
#endif

#if CHAR_MIN

#   ifndef  VWBC_REPR
#   define  VWBC_REPR   REPR_VWBI
#   endif

#   ifndef  VDBC_REPR
#   define  VDBC_REPR   REPR_VDBI
#   endif

#   ifndef  VQBC_REPR
#   define  VQBC_REPR   REPR_VQBI
#   endif

#else

#   ifndef  VWBC_REPR
#   define  VWBC_REPR   REPR_VWBU
#   endif

#   ifndef  VDBC_REPR
#   define  VDBC_REPR   REPR_VDBU
#   endif

#   ifndef  VQBC_REPR
#   define  VQBC_REPR   REPR_VQBU
#   endif

#endif


#if _ENTER_EXTVEC_VW_REPR
{
#endif

#ifndef     VWYU_REPR
#define     VWYU_REPR   REPR_YU32
#define     VWYU_TYPE   struct Yu32
#endif

#ifndef     VWBU_REPR
#define     VWBU_REPR   REPR_BU4
#define     VWBU_TYPE   struct Bu4
#endif

#ifndef     VWBI_REPR
#define     VWBI_REPR   REPR_BI4
#define     VWBI_TYPE   struct Bi4
#endif

#ifndef     VWBC_TYPE
#define     VWBC_TYPE   struct Bc4
#endif

#ifndef     VWHU_REPR
#define     VWHU_REPR   REPR_HU2
#define     VWHU_TYPE   struct Hu2
#endif

#ifndef     VWHI_REPR
#define     VWHI_REPR   REPR_HI2
#define     VWHI_TYPE   struct Hi2
#endif

#ifndef     VWHF_REPR
#define     VWHF_REPR   REPR_HF2
#define     VWHF_TYPE   struct Hf2
#endif

#ifndef     VWWU_REPR
#define     VWWU_REPR   REPR_WU1
#define     VWWU_TYPE   struct Wu1
#endif

#ifndef     VWWI_REPR
#define     VWWI_REPR   REPR_WI1
#define     VWWI_TYPE   struct Wi1
#endif

#ifndef     VWWF_REPR
#define     VWWF_REPR   REPR_WF1
#define     VWWF_TYPE   struct Wf1
#endif

#if _LEAVE_EXTVEC_VW_REPR
}
#endif

#if _ENTER_EXTVEC_VD_REPR
{
#endif

#ifndef     VDYU_REPR
#define     VDYU_REPR   REPR_YU64
#define     VDYU_TYPE   struct Yu64
#endif

#ifndef     VDBU_REPR
#define     VDBU_REPR   REPR_BU8
#define     VDBU_TYPE   struct Bu8
#endif

#ifndef     VDBI_REPR
#define     VDBI_REPR   REPR_BI8
#define     VDBI_TYPE   struct Bi8
#endif

#ifndef     VDBC_TYPE
#define     VDBC_TYPE   struct Bc8
#endif

#ifndef     VDHU_REPR
#define     VDHU_REPR   REPR_HU4
#define     VDHU_TYPE   struct Hu4
#endif

#ifndef     VDHI_REPR
#define     VDHI_REPR   REPR_HI4
#define     VDHI_TYPE   struct Hi4
#endif

#ifndef     VDHF_REPR
#define     VDHF_REPR   REPR_HF4
#define     VDHF_TYPE   struct Hf4
#endif

#ifndef     VDWU_REPR
#define     VDWU_REPR   REPR_WU2
#define     VDWU_TYPE   struct Wu2
#endif

#ifndef     VDWI_REPR
#define     VDWI_REPR   REPR_WI2
#define     VDWI_TYPE   struct Wi2
#endif

#ifndef     VDWF_REPR
#define     VDWF_REPR   REPR_WF2
#define     VDWF_TYPE   struct Wf2
#endif

#ifndef     VDDU_REPR
#define     VDDU_REPR   REPR_DU1
#define     VDDU_TYPE   struct Du1
#endif

#ifndef     VDDI_REPR
#define     VDDI_REPR   REPR_DI1
#define     VDDI_TYPE   struct Di1
#endif

#ifndef     VDDF_REPR
#define     VDDF_REPR   REPR_DF1
#define     VDDF_TYPE   struct Df1
#endif

#if _LEAVE_EXTVEC_VD_REPR
}
#endif

#if _ENTER_EXTVEC_VQ_REPR
{
#endif

#ifndef     VQYU_REPR
#define     VQYU_REPR   REPR_YU128
#define     VQYU_TYPE   struct Yu128
#endif

#ifndef     VQBU_REPR
#define     VQBU_REPR   REPR_BU16
#define     VQBU_TYPE   struct Bu16
#endif

#ifndef     VQBI_REPR
#define     VQBI_REPR   REPR_BI16
#define     VQBI_TYPE   struct Bi16
#endif

#ifndef     VQBC_TYPE
#define     VQBC_TYPE   struct Bc16
#endif


#ifndef     VQHU_REPR
#define     VQHU_REPR   REPR_HU8
#define     VQHU_TYPE   struct Hu8
#endif

#ifndef     VQHI_REPR
#define     VQHI_REPR   REPR_HI8
#define     VQHI_TYPE   struct Hi8
#endif

#ifndef     VQHF_REPR
#define     VQHF_REPR   REPR_HF8
#define     VQHF_TYPE   struct Hf8
#endif

#ifndef     VQWU_REPR
#define     VQWU_REPR   REPR_WU4
#define     VQWU_TYPE   struct Wu4
#endif

#ifndef     VQWI_REPR
#define     VQWI_REPR   REPR_WI4
#define     VQWI_TYPE   struct Wi4
#endif

#ifndef     VQWF_REPR
#define     VQWF_REPR   REPR_WF4
#define     VQWF_TYPE   struct Wf4
#endif


#ifndef     VQDU_REPR
#define     VQDU_REPR   REPR_DU2
#define     VQDU_TYPE   struct Du2
#endif

#ifndef     VQDI_REPR
#define     VQDI_REPR   REPR_DI2
#define     VQDI_TYPE   struct Di2
#endif

#ifndef     VQDF_REPR
#define     VQDF_REPR   REPR_DF2
#define     VQDF_TYPE   struct Df2
#endif

#if _LEAVE_EXTVEC_VQ_REPR
}
#endif

#if _ENTER_EXTVEC_HWVA_REPR
{
#endif

#if  defined(VWYU_MTYPE)

typedef      VWYU_MTYPE Wyu;

struct Wyu1 {
    union {
#   if defined(VWYU_M1TYPE)
        VWYU_M1TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV1(V,);};
    };
};

struct Wyu2 {
    union {
#   if defined(VWYU_M2TYPE)
        VWYU_M2TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV2(V,);};
    };
};

struct Wyu3 {
    union {
#   if defined(VWYU_M3TYPE)
        VWYU_M3TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV3(V,);};
    };
};

struct Wyu4 {
    union {
#   if defined(VWYU_M4TYPE)
        VWYU_M4TYPE   M;
#   endif
        struct {VWYU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VWBU_MTYPE)

typedef      VWBU_MTYPE Wbu;

struct Wbu1 {
    union {
#   if defined(VWBU_M1TYPE)
        VWBU_M1TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV1(V,);};
    };
};

struct Wbu2 {
    union {
#   if defined(VWBU_M2TYPE)
        VWBU_M2TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV2(V,);};
    };
};

struct Wbu3 {
    union {
#   if defined(VWBU_M3TYPE)
        VWBU_M3TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV3(V,);};
    };
};

struct Wbu4 {
    union {
#   if defined(VWBU_M4TYPE)
        VWBU_M4TYPE   M;
#   endif
        struct {VWBU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VWBI_MTYPE)

typedef      VWBI_MTYPE Wbi;

struct Wbi1 {
    union {
#   if defined(VWBI_M1TYPE)
        VWBI_M1TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV1(V,);};
    };
};

struct Wbi2 {
    union {
#   if defined(VWBI_M2TYPE)
        VWBI_M2TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV2(V,);};
    };
};

struct Wbi3 {
    union {
#   if defined(VWBI_M3TYPE)
        VWBI_M3TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV3(V,);};
    };
};

struct Wbi4 {
    union {
#   if defined(VWBI_M4TYPE)
        VWBI_M4TYPE   M;
#   endif
        struct {VWBI_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWBC_MTYPE)

typedef      VWBC_MTYPE Wbc;

struct Wbc1 {
    union {
#   if defined(VWBC_M1TYPE)
        VWBC_M1TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV1(V,);};
    };
};

struct Wbc2 {
    union {
#   if defined(VWBC_M2TYPE)
        VWBC_M2TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV2(V,);};
    };
};

struct Wbc3 {
    union {
#   if defined(VWBC_M3TYPE)
        VWBC_M3TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV3(V,);};
    };
};

struct Wbc4 {
    union {
#   if defined(VWBC_M4TYPE)
        VWBC_M4TYPE   M;
#   endif
        struct {VWBC_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWHU_MTYPE)

typedef      VWHU_MTYPE Whu;

struct Whu1 {
    union {
#   if defined(VWHU_M1TYPE)
        VWHU_M1TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV1(V,);};
    };
};

struct Whu2 {
    union {
#   if defined(VWHU_M2TYPE)
        VWHU_M2TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV2(V,);};
    };
};

struct Whu3 {
    union {
#   if defined(VWHU_M3TYPE)
        VWHU_M3TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV3(V,);};
    };
};

struct Whu4 {
    union {
#   if defined(VWHU_M4TYPE)
        VWHU_M4TYPE   M;
#   endif
        struct {VWHU_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWHI_MTYPE)

typedef      VWHI_MTYPE Whi;

struct Whi1 {
    union {
#   if defined(VWHI_M1TYPE)
        VWHI_M1TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV1(V,);};
    };
};
struct Whi2 {
    union {
#   if defined(VWHI_M2TYPE)
        VWHI_M2TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV2(V,);};
    };
};
struct Whi3 {
    union {
#   if defined(VWHI_M3TYPE)
        VWHI_M3TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV3(V,);};
    };
};
struct Whi4 {
    union {
#   if defined(VWHI_M4TYPE)
        VWHI_M4TYPE   M;
#   endif
        struct {VWHI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VWHF_MTYPE)

typedef      VWHF_MTYPE Whf;

struct Whf1 {
    union {
#   if defined(VWHF_M1TYPE)
        VWHF_M1TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV1(V,);};
    };
};
struct Whf2 {
    union {
#   if defined(VWHF_M2TYPE)
        VWHF_M2TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV2(V,);};
    };
};
struct Whf3 {
    union {
#   if defined(VWHF_M3TYPE)
        VWHF_M3TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV3(V,);};
    };
};
struct Whf4 {
    union {
#   if defined(VWHF_M4TYPE)
        VWHF_M4TYPE   M;
#   endif
        struct {VWHF_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VWWU_MTYPE)

typedef      VWWU_MTYPE Wwu;

struct Wwu1 {
    union {
#   if defined(VWWU_M1TYPE)
        VWWU_M1TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV1(V,);};
    };
};
struct Wwu2 {
    union {
#   if defined(VWWU_M2TYPE)
        VWWU_M2TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV2(V,);};
    };
};
struct Wwu3 {
    union {
#   if defined(VWWU_M3TYPE)
        VWWU_M3TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV3(V,);};
    };
};
struct Wwu4 {
    union {
#   if defined(VWWU_M4TYPE)
        VWWU_M4TYPE   M;
#   endif
        struct {VWWU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VWWI_MTYPE)

typedef      VWWI_MTYPE Wwi;

struct Wwi1 {
    union {
#   if defined(VWWI_M1TYPE)
        VWWI_M1TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV1(V,);};
    };
};
struct Wwi2 {
    union {
#   if defined(VWWI_M2TYPE)
        VWWI_M2TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV2(V,);};
    };
};
struct Wwi3 {
    union {
#   if defined(VWWI_M3TYPE)
        VWWI_M3TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV3(V,);};
    };
};
struct Wwi4 {
    union {
#   if defined(VWWI_M4TYPE)
        VWWI_M4TYPE   M;
#   endif
        struct {VWWI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VWWF_MTYPE)

typedef      VWWF_MTYPE Wwf;

struct Wwf1 {
    union {
#   if defined(VWWF_M1TYPE)
        VWWF_M1TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV1(V,);};
    };
};
struct Wwf2 {
    union {
#   if defined(VWWF_M2TYPE)
        VWWF_M2TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV2(V,);};
    };
};
struct Wwf3 {
    union {
#   if defined(VWWF_M3TYPE)
        VWWF_M3TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV3(V,);};
    };
};
struct Wwf4 {
    union {
#   if defined(VWWF_M4TYPE)
        VWWF_M4TYPE   M;
#   endif
        struct {VWWF_MTYPE MY_NV4(V,);};
    };
};

#endif

#if defined(TST_HA_V32_SIZES)

#   if 0
    {
#   endif

#   if defined(VWBU_MTYPE)
ASSERT(004 == sizeof(       Wbu));
ASSERT(004 == sizeof(struct Wbu1));
ASSERT(010 == sizeof(struct Wbu2));
ASSERT(014 == sizeof(struct Wbu3));
ASSERT(020 == sizeof(struct Wbu4));
#   endif

#   if defined(VWBI_MTYPE)
ASSERT(004 == sizeof(       Wbi));
ASSERT(004 == sizeof(struct Wbi1));
ASSERT(010 == sizeof(struct Wbi2));
ASSERT(014 == sizeof(struct Wbi3));
ASSERT(020 == sizeof(struct Wbi4));
#   endif


#   if defined(VWHU_MTYPE)
ASSERT(004 == sizeof(       Whu));
ASSERT(004 == sizeof(struct Whu1));
ASSERT(010 == sizeof(struct Whu2));
ASSERT(014 == sizeof(struct Whu3));
ASSERT(020 == sizeof(struct Whu4));
#   endif

#   if defined(VWHI_MTYPE)
ASSERT(004 == sizeof(       Whi));
ASSERT(004 == sizeof(struct Whi1));
ASSERT(010 == sizeof(struct Whi2));
ASSERT(014 == sizeof(struct Whi3));
ASSERT(020 == sizeof(struct Whi4));
#   endif

#   if defined(VWHF_MTYPE)
ASSERT(004 == sizeof(       Whf));
ASSERT(004 == sizeof(struct Whf1));
ASSERT(010 == sizeof(struct Whf2));
ASSERT(014 == sizeof(struct Whf3));
ASSERT(020 == sizeof(struct Whf4));
#   endif


#   if defined(VWWU_MTYPE)
ASSERT(004 == sizeof(       Wwu));
ASSERT(004 == sizeof(struct Wwu1));
ASSERT(010 == sizeof(struct Wwu2));
ASSERT(014 == sizeof(struct Wwu3));
ASSERT(020 == sizeof(struct Wwu4));
#   endif

#   if defined(VWWI_MTYPE)
ASSERT(004 == sizeof(       Wwi));
ASSERT(004 == sizeof(struct Wwi1));
ASSERT(010 == sizeof(struct Wwi2));
ASSERT(014 == sizeof(struct Wwi3));
ASSERT(020 == sizeof(struct Wwi4));
#   endif

#   if defined(VWWF_MTYPE)
ASSERT(004 == sizeof(       Wwf));
ASSERT(004 == sizeof(struct Wwf1));
ASSERT(010 == sizeof(struct Wwf2));
ASSERT(014 == sizeof(struct Wwf3));
ASSERT(020 == sizeof(struct Wwf4));
#   endif


#   if 0
    }
#   endif

#endif // defined(TST_HA_V32_SIZES)


#if _LEAVE_EXTVEC_HWVA_REPR
}
#endif

#if _ENTER_EXTVEC_HDVA_REPR
{
#endif

#if  defined(VDYU_MTYPE)

typedef      VDYU_MTYPE Dyu;

struct Dyu1 {
    union {
#   if defined(VDYU_M1TYPE)
        VDYU_M1TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV1(V,);};
    };
};
struct Dyu2 {
    union {
#   if defined(VDYU_M2TYPE)
        VDYU_M2TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV2(V,);};
    };
};
struct Dyu3 {
    union {
#   if defined(VDYU_M3TYPE)
        VDYU_M3TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV3(V,);};
    };
};
struct Dyu4 {
    union {
#   if defined(VDYU_M4TYPE)
        VDBU_M4TYPE   M;
#   endif
        struct {VDYU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDBU_MTYPE)

typedef      VDBU_MTYPE Dbu;

struct Dbu1 {
    union {
#   if defined(VDBU_M1TYPE)
        VDBU_M1TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV1(V,);};
    };
};
struct Dbu2 {
    union {
#   if defined(VDBU_M2TYPE)
        VDBU_M2TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV2(V,);};
    };
};
struct Dbu3 {
    union {
#   if defined(VDBU_M3TYPE)
        VDBU_M3TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV3(V,);};
    };
};
struct Dbu4 {
    union {
#   if defined(VDBU_M4TYPE)
        VDBU_M4TYPE   M;
#   endif
        struct {VDBU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDBI_MTYPE)

typedef      VDBI_MTYPE Dbi;

struct Dbi1 {
    union {
#   if defined(VDBI_M1TYPE)
        VDBI_M1TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV1(V,);};
    };
};
struct Dbi2 {
    union {
#   if defined(VDBI_M2TYPE)
        VDBI_M2TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV2(V,);};
    };
};
struct Dbi3 {
    union {
#   if defined(VDBI_M3TYPE)
        VDBI_M3TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV3(V,);};
    };
};
struct Dbi4 {
    union {
#   if defined(VDBI_M4TYPE)
        VDBI_M4TYPE   M;
#   endif
        struct {VDBI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDBC_MTYPE)

typedef      VDBC_MTYPE Dbc;

struct Dbc1 {
    union {
#   if defined(VDBC_M1TYPE)
        VDBC_M1TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV1(V,);};
    };
};
struct Dbc2 {
    union {
#   if defined(VDBC_M2TYPE)
        VDBC_M2TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV2(V,);};
    };
};
struct Dbc3 {
    union {
#   if defined(VDBC_M3TYPE)
        VDBC_M3TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV3(V,);};
    };
};
struct Dbc4 {
    union {
#   if defined(VDBC_M4TYPE)
        VDBC_M4TYPE   M;
#   endif
        struct {VDBC_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDHU_MTYPE)

typedef      VDHU_MTYPE Dhu;

struct Dhu1 {
    union {
#   if defined(VDHU_M1TYPE)
        VDHU_M1TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV1(V,);};
    };
};
struct Dhu2 {
    union {
#   if defined(VDHU_M2TYPE)
        VDHU_M2TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV2(V,);};
    };
};
struct Dhu3 {
    union {
#   if defined(VDHU_M3TYPE)
        VDHU_M3TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV3(V,);};
    };
};
struct Dhu4 {
    union {
#   if defined(VDHU_M4TYPE)
        VDHU_M4TYPE   M;
#   endif
        struct {VDHU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDHI_MTYPE)

typedef      VDHI_MTYPE Dhi;

struct Dhi1 {
    union {
#   if defined(VDHI_M1TYPE)
        VDHI_M1TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV1(V,);};
    };
};
struct Dhi2 {
    union {
#   if defined(VDHI_M2TYPE)
        VDHI_M2TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV2(V,);};
    };
};
struct Dhi3 {
    union {
#   if defined(VDHI_M3TYPE)
        VDHI_M3TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV3(V,);};
    };
};
struct Dhi4 {
    union {
#   if defined(VDHI_M4TYPE)
        VDHI_M4TYPE   M;
#   endif
        struct {VDHI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDHF_MTYPE)

typedef      VDHF_MTYPE Dhf;

struct Dhf1 {
    union {
#   if defined(VDHF_M1TYPE)
        VDHF_M1TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV1(V,);};
    };
};
struct Dhf2 {
    union {
#   if defined(VDHF_M2TYPE)
        VDHF_M2TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV2(V,);};
    };
};
struct Dhf3 {
    union {
#   if defined(VDHF_M3TYPE)
        VDHF_M3TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV3(V,);};
    };
};
struct Dhf4 {
    union {
#   if defined(VDHF_M4TYPE)
        VDHF_M4TYPE   M;
#   endif
        struct {VDHF_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VDWU_MTYPE)

typedef      VDWU_MTYPE Dwu;

struct Dwu1 {
    union {
#   if defined(VDWU_M1TYPE)
        VDWU_M1TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV1(V,);};
    };
};
struct Dwu2 {
    union {
#   if defined(VDWU_M2TYPE)
        VDWU_M2TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV2(V,);};
    };
};
struct Dwu3 {
    union {
#   if defined(VDWU_M3TYPE)
        VDWU_M3TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV3(V,);};
    };
};
struct Dwu4 {
    union {
#   if defined(VDWU_M4TYPE)
        VDWU_M4TYPE   M;
#   endif
        struct {VDWU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDWI_MTYPE)

typedef      VDWI_MTYPE Dwi;

struct Dwi1 {
    union {
#   if defined(VDWI_M1TYPE)
        VDWI_M1TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV1(V,);};
    };
};
struct Dwi2 {
    union {
#   if defined(VDWI_M2TYPE)
        VDWI_M2TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV2(V,);};
    };
};
struct Dwi3 {
    union {
#   if defined(VDWI_M3TYPE)
        VDWI_M3TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV3(V,);};
    };
};
struct Dwi4 {
    union {
#   if defined(VDWI_M4TYPE)
        VDWI_M4TYPE   M;
#   endif
        struct {VDWI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDWF_MTYPE)

typedef      VDWF_MTYPE Dwf;

struct Dwf1 {
    union {
#   if defined(VDWF_M1TYPE)
        VDWF_M1TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV1(V,);};
    };
};
struct Dwf2 {
    union {
#   if defined(VDWF_M2TYPE)
        VDWF_M2TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV2(V,);};
    };
};
struct Dwf3 {
    union {
#   if defined(VDWF_M3TYPE)
        VDWF_M3TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV3(V,);};
    };
};
struct Dwf4 {
    union {
#   if defined(VDWF_M4TYPE)
        VDWF_M4TYPE   M;
#   endif
        struct {VDWF_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDDU_MTYPE)

typedef      VDDU_MTYPE Ddu;

struct Ddu1 {
    union {
#   if defined(VDDU_M1TYPE)
        VDDU_M1TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV1(V,);};
    };
};
struct Ddu2 {
    union {
#   if defined(VDDU_M2TYPE)
        VDDU_M2TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV2(V,);};
    };
};
struct Ddu3 {
    union {
#   if defined(VDDU_M3TYPE)
        VDDU_M3TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV3(V,);};
    };
};
struct Ddu4 {
    union {
#   if defined(VDDU_M4TYPE)
        VDDU_M4TYPE   M;
#   endif
        struct {VDDU_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDDI_MTYPE)

typedef      VDDI_MTYPE Ddi;

struct Ddi1 {
    union {
#   if defined(VDDI_M1TYPE)
        VDDI_M1TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV1(V,);};
    };
};
struct Ddi2 {
    union {
#   if defined(VDDI_M2TYPE)
        VDDI_M2TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV2(V,);};
    };
};
struct Ddi3 {
    union {
#   if defined(VDDI_M3TYPE)
        VDDI_M3TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV3(V,);};
    };
};
struct Ddi4 {
    union {
#   if defined(VDDI_M4TYPE)
        VDDI_M4TYPE   M;
#   endif
        struct {VDDI_MTYPE MY_NV4(V,);};
    };
};

#endif

#if  defined(VDDF_MTYPE)

typedef      VDDF_MTYPE Ddf;

struct Ddf1 {
    union {
#   if defined(VDDF_M1TYPE)
        VDDF_M1TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV1(V,);};
    };
};
struct Ddf2 {
    union {
#   if defined(VDDF_M2TYPE)
        VDDF_M2TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV2(V,);};
    };
};
struct Ddf3 {
    union {
#   if defined(VDDF_M3TYPE)
        VDDF_M3TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV3(V,);};
    };
};
struct Ddf4 {
    union {
#   if defined(VDDF_M4TYPE)
        VDDF_M4TYPE   M;
#   endif
        struct {VDDF_MTYPE MY_NV4(V,);};
    };
};

#endif


#if defined(TST_HA_V64_SIZES)

#   if 0
    {
#   endif

#   if defined(VDBU_MTYPE)
ASSERT(010 == sizeof(       Dbu));
ASSERT(010 == sizeof(struct Dbu1));
ASSERT(020 == sizeof(struct Dbu2));
ASSERT(030 == sizeof(struct Dbu3));
ASSERT(040 == sizeof(struct Dbu4));
#   endif

#   if defined(VDBI_MTYPE)
ASSERT(010 == sizeof(       Dbi));
ASSERT(010 == sizeof(struct Dbi1));
ASSERT(020 == sizeof(struct Dbi2));
ASSERT(030 == sizeof(struct Dbi3));
ASSERT(040 == sizeof(struct Dbi4));
#   endif


#   if defined(VDHU_MTYPE)
ASSERT(010 == sizeof(       Dhu));
ASSERT(010 == sizeof(struct Dhu1));
ASSERT(020 == sizeof(struct Dhu2));
ASSERT(030 == sizeof(struct Dhu3));
ASSERT(040 == sizeof(struct Dhu4));
#   endif

#   if defined(VDHI_MTYPE)
ASSERT(010 == sizeof(       Dhi));
ASSERT(010 == sizeof(struct Dhi1));
ASSERT(020 == sizeof(struct Dhi2));
ASSERT(030 == sizeof(struct Dhi3));
ASSERT(040 == sizeof(struct Dhi4));
#   endif

#   if defined(VDHF_MTYPE)
ASSERT(010 == sizeof(       Dhf));
ASSERT(010 == sizeof(struct Dhf1));
ASSERT(020 == sizeof(struct Dhf2));
ASSERT(030 == sizeof(struct Dhf3));
ASSERT(040 == sizeof(struct Dhf4));
#   endif


#   if defined(VDWU_MTYPE)
ASSERT(010 == sizeof(       Dwu));
ASSERT(010 == sizeof(struct Dwu1));
ASSERT(020 == sizeof(struct Dwu2));
ASSERT(030 == sizeof(struct Dwu3));
ASSERT(040 == sizeof(struct Dwu4));
#   endif

#   if defined(VDWI_MTYPE)
ASSERT(010 == sizeof(       Dwi));
ASSERT(010 == sizeof(struct Dwi1));
ASSERT(020 == sizeof(struct Dwi2));
ASSERT(030 == sizeof(struct Dwi3));
ASSERT(040 == sizeof(struct Dwi4));
#   endif

#   if defined(VDWF_MTYPE)
ASSERT(010 == sizeof(       Dwf));
ASSERT(010 == sizeof(struct Dwf1));
ASSERT(020 == sizeof(struct Dwf2));
ASSERT(030 == sizeof(struct Dwf3));
ASSERT(040 == sizeof(struct Dwf4));
#   endif


#   if defined(VDDU_MTYPE)
ASSERT(010 == sizeof(       Ddu));
ASSERT(010 == sizeof(struct Ddu1));
ASSERT(020 == sizeof(struct Ddu2));
ASSERT(030 == sizeof(struct Ddu3));
ASSERT(040 == sizeof(struct Ddu4));
#   endif

#   if defined(VDDI_MTYPE)
ASSERT(010 == sizeof(       Ddi));
ASSERT(010 == sizeof(struct Ddi1));
ASSERT(020 == sizeof(struct Ddi2));
ASSERT(030 == sizeof(struct Ddi3));
ASSERT(040 == sizeof(struct Ddi4));
#   endif

#   if defined(VDDF_MTYPE)
ASSERT(010 == sizeof(       Ddf));
ASSERT(010 == sizeof(struct Ddf1));
ASSERT(020 == sizeof(struct Ddf2));
ASSERT(030 == sizeof(struct Ddf3));
ASSERT(040 == sizeof(struct Ddf4));
#   endif

#   if 0
    }
#   endif

#endif // defined(TST_HA_V64_SIZES)


#if _LEAVE_EXTVEC_HDVA_REPR
}
#endif

#if _ENTER_EXTVEC_HQVA_REPR
{
#endif


#if  defined(VQYU_MTYPE)

typedef      VQYU_MTYPE Qyu;

struct Qyu1 {
    union {
#   if defined(VQYU_M1TYPE)
        VQYU_M1TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV1(V,);};
    };
};
struct Qyu2 {
    union {
#   if defined(VQYU_M2TYPE)
        VQYU_M2TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV2(V,);};
    };
};
struct Qyu3 {
    union {
#   if defined(VQYU_M3TYPE)
        VQYU_M3TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV3(V,);};
    };
};
struct Qyu4 {
    union {
#   if defined(VQYU_M4TYPE)
        VQYU_M4TYPE   M;
#   endif
        struct {VQYU_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQBU_MTYPE)

typedef      VQBU_MTYPE Qbu;

struct Qbu1 {
    union {
#   if defined(VQBU_M1TYPE)
        VQBU_M1TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV1(V,);};
    };
};
struct Qbu2 {
    union {
#   if defined(VQBU_M2TYPE)
        VQBU_M2TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV2(V,);};
    };
};
struct Qbu3 {
    union {
#   if defined(VQBU_M3TYPE)
        VQBU_M3TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV3(V,);};
    };
};
struct Qbu4 {
    union {
#   if defined(VQBU_M4TYPE)
        VQBU_M4TYPE   M;
#   endif
        struct {VQBU_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQBI_MTYPE)

typedef      VQBI_MTYPE Qbi;

struct Qbi1 {
    union {
#   if defined(VQBI_M1TYPE)
        VQBI_M1TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV1(V,);};
    };
};
struct Qbi2 {
    union {
#   if defined(VQBI_M2TYPE)
        VQBI_M2TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV2(V,);};
    };
};
struct Qbi3 {
    union {
#   if defined(VQBI_M3TYPE)
        VQBI_M3TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV3(V,);};
    };
};
struct Qbi4 {
    union {
#   if defined(VQBI_M4TYPE)
        VQBI_M4TYPE   M;
#   endif
        struct {VQBI_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQBC_MTYPE)

typedef      VQBC_MTYPE Qbc;

struct Qbc1 {
    union {
#   if defined(VQBC_M1TYPE)
        VQBC_M1TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV1(V,);};
    };
};
struct Qbc2 {
    union {
#   if defined(VQBC_M2TYPE)
        VQBC_M2TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV2(V,);};
    };
};
struct Qbc3 {
    union {
#   if defined(VQBC_M3TYPE)
        VQBC_M3TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV3(V,);};
    };
};
struct Qbc4 {
    union {
#   if defined(VQBC_M4TYPE)
        VQBC_M4TYPE   M;
#   endif
        struct {VQBC_MTYPE MY_NV4(V,);};
    };
};

#endif


#if  defined(VQHU_MTYPE)
typedef      VQHU_MTYPE Qhu;
struct Qhu1 {
    union {
#   if defined(VQHU_M1TYPE)
        VQHU_M1TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV1(V,);};
    };
};
struct Qhu2 {
    union {
#   if defined(VQHU_M2TYPE)
        VQHU_M2TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV2(V,);};
    };
};
struct Qhu3 {
    union {
#   if defined(VQHU_M3TYPE)
        VQHU_M3TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV3(V,);};
    };
};
struct Qhu4 {
    union {
#   if defined(VQHU_M4TYPE)
        VQHU_M4TYPE   M;
#   endif
        struct {VQHU_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VQHI_MTYPE)
typedef      VQHI_MTYPE Qhi;
struct Qhi1 {
    union {
#   if defined(VQHI_M1TYPE)
        VQHI_M1TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV1(V,);};
    };
};
struct Qhi2 {
    union {
#   if defined(VQHI_M2TYPE)
        VQHI_M2TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV2(V,);};
    };
};
struct Qhi3 {
    union {
#   if defined(VQHI_M3TYPE)
        VQHI_M3TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV3(V,);};
    };
};
struct Qhi4 {
    union {
#   if defined(VQHI_M4TYPE)
        VQHI_M4TYPE   M;
#   endif
        struct {VQHI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQHF_MTYPE)
typedef      VQHF_MTYPE Qhf;
struct Qhf1 {
    union {
#   if defined(VQHF_M1TYPE)
        VQHF_M1TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV1(V,);};
    };
};
struct Qhf2 {
    union {
#   if defined(VQHF_M2TYPE)
        VQHF_M2TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV2(V,);};
    };
};
struct Qhf3 {
    union {
#   if defined(VQHF_M3TYPE)
        VQHF_M3TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV3(V,);};
    };
};
struct Qhf4 {
    union {
#   if defined(VQHF_M4TYPE)
        VQHF_M4TYPE   M;
#   endif
        struct {VQHF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VQWU_MTYPE)
typedef      VQWU_MTYPE Qwu;
struct Qwu1 {
    union {
#   if defined(VQWU_M1TYPE)
        VQWU_M1TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV1(V,);};
    };
};
struct Qwu2 {
    union {
#   if defined(VQWU_M2TYPE)
        VQWU_M2TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV2(V,);};
    };
};
struct Qwu3 {
    union {
#   if defined(VQWU_M3TYPE)
        VQWU_M3TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV3(V,);};
    };
};
struct Qwu4 {
    union {
#   if defined(VQWU_M4TYPE)
        VQWU_M4TYPE   M;
#   endif
        struct {VQWU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQWI_MTYPE)
typedef      VQWI_MTYPE Qwi;
struct Qwi1 {
    union {
#   if defined(VQWI_M1TYPE)
        VQWI_M1TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV1(V,);};
    };
};
struct Qwi2 {
    union {
#   if defined(VQWI_M2TYPE)
        VQWI_M2TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV2(V,);};
    };
};
struct Qwi3 {
    union {
#   if defined(VQWI_M3TYPE)
        VQWI_M3TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV3(V,);};
    };
};
struct Qwi4 {
    union {
#   if defined(VQWI_M4TYPE)
        VQWI_M4TYPE   M;
#   endif
        struct {VQWI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQWF_MTYPE)
typedef      VQWF_MTYPE Qwf;
struct Qwf1 {
    union {
#   if defined(VQWF_M1TYPE)
        VQWF_M1TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV1(V,);};
    };
};
struct Qwf2 {
    union {
#   if defined(VQWF_M2TYPE)
        VQWF_M2TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV2(V,);};
    };
};
struct Qwf3 {
    union {
#   if defined(VQWF_M3TYPE)
        VQWF_M3TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV3(V,);};
    };
};
struct Qwf4 {
    union {
#   if defined(VQWF_M4TYPE)
        VQWF_M4TYPE   M;
#   endif
        struct {VQWF_MTYPE MY_NV4(V,);};
    };
};
#endif


#if  defined(VQDU_MTYPE)
typedef      VQDU_MTYPE Qdu;
struct Qdu1 {
    union {
#   if defined(VQDU_M1TYPE)
        VQDU_M1TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV1(V,);};
    };
};
struct Qdu2 {
    union {
#   if defined(VQDU_M2TYPE)
        VQDU_M2TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV2(V,);};
    };
};
struct Qdu3 {
    union {
#   if defined(VQDU_M3TYPE)
        VQDU_M3TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV3(V,);};
    };
};
struct Qdu4 {
    union {
#   if defined(VQDU_M4TYPE)
        VQDU_M4TYPE   M;
#   endif
        struct {VQDU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQDI_MTYPE)
typedef      VQDI_MTYPE Qdi;
struct Qdi1 {
    union {
#   if defined(VQDI_M1TYPE)
        VQDI_M1TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV1(V,);};
    };
};
struct Qdi2 {
    union {
#   if defined(VQDI_M2TYPE)
        VQDI_M2TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV2(V,);};
    };
};
struct Qdi3 {
    union {
#   if defined(VQDI_M3TYPE)
        VQDI_M3TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV3(V,);};
    };
};
struct Qdi4 {
    union {
#   if defined(VQDI_M4TYPE)
        VQDI_M4TYPE   M;
#   endif
        struct {VQDI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQDF_MTYPE)
typedef      VQDF_MTYPE Qdf;
struct Qdf1 {
    union {
#   if defined(VQDF_M1TYPE)
        VQDF_M1TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV1(V,);};
    };
};
struct Qdf2 {
    union {
#   if defined(VQDF_M2TYPE)
        VQDF_M2TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV2(V,);};
    };
};
struct Qdf3 {
    union {
#   if defined(VQDF_M3TYPE)
        VQDF_M3TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV3(V,);};
    };
};
struct Qdf4 {
    union {
#   if defined(VQDF_M4TYPE)
        VQDF_M4TYPE   M;
#   endif
        struct {VQDF_MTYPE MY_NV4(V,);};
    };
};
#endif

#if 0 // Vqq*

#if  defined(VQQU_MTYPE)
typedef      VQQU_MTYPE Qqu;
struct Qqu1 {
    union {
#   if defined(VQQU_M1TYPE)
        VQQU_M1TYPE   M;
#   endif
        struct {VQQU_MTYPE MY_NV1(V,);};
    };
};
struct Qqu2 {
    union {
#   if defined(VQQU_M2TYPE)
        VQQU_M2TYPE   M;
#   endif
        struct {VQQU_MTYPE MY_NV2(V,);};
    };
};
struct Qqu3 {
    union {
#   if defined(VQQU_M3TYPE)
        VQQU_M3TYPE   M;
#   endif
        struct {VQQU_MTYPE MY_NV3(V,);};
    };
};
struct Qqu4 {
    union {
#   if defined(VQQU_M4TYPE)
        VQQU_M4TYPE   M;
#   endif
        struct {VQQU_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQQI_MTYPE)
typedef      VQQI_MTYPE Qqi;
struct Qqi1 {
    union {
#   if defined(VQQI_M1TYPE)
        VQQI_M1TYPE   M;
#   endif
        struct {VQQI_MTYPE MY_NV1(V,);};
    };
};
struct Qqi2 {
    union {
#   if defined(VQQI_M2TYPE)
        VQQI_M2TYPE   M;
#   endif
        struct {VQQI_MTYPE MY_NV2(V,);};
    };
};
struct Qqi3 {
    union {
#   if defined(VQQI_M3TYPE)
        VQQI_M3TYPE   M;
#   endif
        struct {VQQI_MTYPE MY_NV3(V,);};
    };
};
struct Qqi4 {
    union {
#   if defined(VQQI_M4TYPE)
        VQQI_M4TYPE   M;
#   endif
        struct {VQQI_MTYPE MY_NV4(V,);};
    };
};
#endif

#if  defined(VQQF_MTYPE)
typedef      VQQF_MTYPE Qqf;
struct Qqf1 {
    union {
#   if defined(VQQF_M1TYPE)
        VQQF_M1TYPE   M;
#   endif
        struct {VQQF_MTYPE MY_NV1(V,);};
    };
};
struct Qqf2 {
    union {
#   if defined(VQQF_M2TYPE)
        VQQF_M2TYPE   M;
#   endif
        struct {VQQF_MTYPE MY_NV2(V,);};
    };
};
struct Qqf3 {
    union {
#   if defined(VQQF_M3TYPE)
        VQQF_M3TYPE   M;
#   endif
        struct {VQQF_MTYPE MY_NV3(V,);};
    };
};
struct Qqf4 {
    union {
#   if defined(VQQF_M4TYPE)
        VQQF_M4TYPE   M;
#   endif
        struct {VQQF_MTYPE MY_NV4(V,);};
    };
};
#endif

#endif // Vqq*

#if defined(TST_HA_V128_SIZES)

#   if 0
//      <ENTERTST=HA_V128_SIZES>
    {
#   endif

#   if defined(VQBU_MTYPE)
ASSERT(0x10 == sizeof(       Qbu));
ASSERT(0x10 == sizeof(struct Qbu1));
ASSERT(0x20 == sizeof(struct Qbu2));
ASSERT(0x30 == sizeof(struct Qbu3));
ASSERT(0x40 == sizeof(struct Qbu4));
#   endif

#   if defined(VQBI_MTYPE)
ASSERT(0x10 == sizeof(       Qbi));
ASSERT(0x10 == sizeof(struct Qbi1));
ASSERT(0x20 == sizeof(struct Qbi2));
ASSERT(0x30 == sizeof(struct Qbi3));
ASSERT(0x40 == sizeof(struct Qbi4));
#   endif

#   if defined(VQHU_MTYPE)
ASSERT(0x10 == sizeof(       Qhu));
ASSERT(0x10 == sizeof(struct Qhu1));
ASSERT(0x20 == sizeof(struct Qhu2));
ASSERT(0x30 == sizeof(struct Qhu3));
ASSERT(0x40 == sizeof(struct Qhu4));
#   endif

#   if defined(VQHI_MTYPE)
ASSERT(0x10 == sizeof(       Qhi));
ASSERT(0x10 == sizeof(struct Qhi1));
ASSERT(0x20 == sizeof(struct Qhi2));
ASSERT(0x30 == sizeof(struct Qhi3));
ASSERT(0x40 == sizeof(struct Qhi4));
#   endif

#   if defined(VQHF_MTYPE)
ASSERT(0x10 == sizeof(       Qhf));
ASSERT(0x10 == sizeof(struct Qhf1));
ASSERT(0x20 == sizeof(struct Qhf2));
ASSERT(0x30 == sizeof(struct Qhf3));
ASSERT(0x40 == sizeof(struct Qhf4));
#   endif


#   if defined(VQWU_MTYPE)
ASSERT(0x10 == sizeof(       Qwu));
ASSERT(0x10 == sizeof(struct Qwu1));
ASSERT(0x20 == sizeof(struct Qwu2));
ASSERT(0x30 == sizeof(struct Qwu3));
ASSERT(0x40 == sizeof(struct Qwu4));
#   endif

#   if defined(VQWI_MTYPE)
ASSERT(0x10 == sizeof(       Qwi));
ASSERT(0x10 == sizeof(struct Qwi1));
ASSERT(0x20 == sizeof(struct Qwi2));
ASSERT(0x30 == sizeof(struct Qwi3));
ASSERT(0x40 == sizeof(struct Qwi4));
#   endif

#   if defined(VQWF_MTYPE)
ASSERT(0x10 == sizeof(       Qwf));
ASSERT(0x10 == sizeof(struct Qwf1));
ASSERT(0x20 == sizeof(struct Qwf2));
ASSERT(0x30 == sizeof(struct Qwf3));
ASSERT(0x40 == sizeof(struct Qwf4));
#   endif

#   if defined(VQDU_MTYPE)
ASSERT(0x10 == sizeof(       Qdu));
ASSERT(0x10 == sizeof(struct Qdu1));
ASSERT(0x20 == sizeof(struct Qdu2));
ASSERT(0x30 == sizeof(struct Qdu3));
ASSERT(0x40 == sizeof(struct Qdu4));
#   endif

#   if defined(VQDI_MTYPE)
ASSERT(0x10 == sizeof(       Qdi));
ASSERT(0x10 == sizeof(struct Qdi1));
ASSERT(0x20 == sizeof(struct Qdi2));
ASSERT(0x30 == sizeof(struct Qdi3));
ASSERT(0x40 == sizeof(struct Qdi4));
#   endif

#   if defined(VQDF_MTYPE)
ASSERT(0x10 == sizeof(       Qdf));
ASSERT(0x10 == sizeof(struct Qdf1));
ASSERT(0x20 == sizeof(struct Qdf2));
ASSERT(0x30 == sizeof(struct Qdf3));
ASSERT(0x40 == sizeof(struct Qdf4));
#   endif

#   if 0
    }
//      <LEAVETST=HA_V128_SIZES>
#   endif

#endif // defined(TST_HA_V128_SIZES)

#if _LEAVE_EXTVEC_HQVA_REPR
}
#endif

#if _ENTER_EXTVEC_TYPEDEFS
{
#endif

typedef VWYU_TYPE   Vwyu;
typedef VWBU_TYPE   Vwbu;
typedef VWBI_TYPE   Vwbi;
typedef VWBC_TYPE   Vwbc;
typedef VWHU_TYPE   Vwhu;
typedef VWHI_TYPE   Vwhi;
typedef VWHF_TYPE   Vwhf;
typedef VWWU_TYPE   Vwwu;
typedef VWWI_TYPE   Vwwi;
typedef VWWF_TYPE   Vwwf;

typedef VDYU_TYPE   Vdyu;
typedef VDBU_TYPE   Vdbu;
typedef VDBI_TYPE   Vdbi;
typedef VDBC_TYPE   Vdbc;
typedef VDHU_TYPE   Vdhu;
typedef VDHI_TYPE   Vdhi;
typedef VDHF_TYPE   Vdhf;
typedef VDWU_TYPE   Vdwu;
typedef VDWI_TYPE   Vdwi;
typedef VDWF_TYPE   Vdwf;
typedef VDDU_TYPE   Vddu;
typedef VDDI_TYPE   Vddi;
typedef VDDF_TYPE   Vddf;

typedef VQYU_TYPE   Vqyu;
typedef VQBU_TYPE   Vqbu;
typedef VQBI_TYPE   Vqbi;
typedef VQBC_TYPE   Vqbc;
typedef VQHU_TYPE   Vqhu;
typedef VQHI_TYPE   Vqhi;
typedef VQHF_TYPE   Vqhf;
typedef VQWU_TYPE   Vqwu;
typedef VQWI_TYPE   Vqwi;
typedef VQWF_TYPE   Vqwf;
typedef VQDU_TYPE   Vqdu;
typedef VQDI_TYPE   Vqdi;
typedef VQDF_TYPE   Vqdf;

#if 0
typedef VQQU_TYPE   Vqqu;
typedef VQQI_TYPE   Vqqi;
typedef VQQF_TYPE   Vqqf;
#endif

typedef union Vwba {uint8_t  U[ 4];int8_t  I[ 4];char    C[ 4];} Vwba;
typedef union Vwha {uint16_t U[ 2];int16_t I[ 2];flt16_t F[ 2];} Vwha;
typedef union Vwwa {uint32_t U[ 1];int32_t I[ 1];float   F[ 1];} Vwwa;

typedef union Vdba {BYTE_UTYPE U[ 8];BYTE_ITYPE I[ 8];      char C[ 8];} Vdba;
typedef union Vdha {HALF_UTYPE U[ 4];HALF_ITYPE I[ 4];HALF_FTYPE F[ 8];} Vdha;
typedef union Vdwa {WORD_UTYPE U[ 2];WORD_ITYPE I[ 2];WORD_FTYPE F[ 4];} Vdwa;
typedef union Vdda {DWRD_UTYPE U[ 1];DWRD_ITYPE I[ 1];DWRD_FTYPE F[ 2];} Vdda;

typedef union Vqba {BYTE_UTYPE U[16];BYTE_ITYPE I[16];      char C[16];} Vqba;
typedef union Vqha {HALF_UTYPE U[ 8];HALF_ITYPE I[ 8];HALF_FTYPE F[ 8];} Vqha;
typedef union Vqwa {WORD_UTYPE U[ 4];WORD_ITYPE I[ 4];WORD_FTYPE F[ 4];} Vqwa;
typedef union Vqda {DWRD_UTYPE U[ 2];DWRD_ITYPE I[ 2];DWRD_FTYPE F[ 2];} Vqda;
#if 0
typedef union Vqqa {QUAD_UTYPE U[ 1];QUAD_ITYPE I[ 1];QUAD_FTYPE F[ 1];} Vqqa;
#endif

#if defined(VWBU_MTYPE) || defined(VWBI_MTYPE)

#   define  VWB_M1TYPE   union Vwb1

union Vwbm {
#   if defined(VWBU_MTYPE)
    VWBU_MTYPE      U;
#   endif

#   if defined(VWBI_MTYPE)
    VWBI_MTYPE      I;
#   endif

#   if defined(VWBC_MTYPE)
    VWBC_MTYPE      C;
#   endif

};
union Vwb1 {

#   if defined(VWBU_MTYPE)
    struct Wbu1    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi1    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc1    C;
#   endif

};
union Vwb2 {

#   if defined(VWBU_MTYPE)
    struct Wbu2    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi2    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc2    C;
#   endif

};
union Vwb3 {

#   if defined(VWBU_MTYPE)
    struct Wbu3    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi3    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc3    C;
#   endif

};
union Vwb4 {
#   if defined(VWBU_MTYPE)
    struct Wbu4    U;
#   endif

#   if defined(VWBI_MTYPE)
    struct Wbi4    I;
#   endif

#   if defined(VWBC_MTYPE)
    struct Wbc4    C;
#   endif

};

#endif

#if defined(VWHU_MTYPE) || defined(VWHI_MTYPE) || defined(VWHF_MTYPE)

#   define  VWH_M1TYPE   union Vwh1

union Vwhm {

#   if defined(VWHU_MTYPE)
    VWHU_MTYPE    U;
#   endif

#   if defined(VWHI_MTYPE)
    VWHI_MTYPE    I;
#   endif

#   if defined(VWHF_MTYPE)
    VWHF_MTYPE    F;
#   endif

};
union Vwh1 {

#   if defined(VWHU_MTYPE)
    struct Whu1    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi1    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf1    F;
#   endif

};
union Vwh2 {

#   if defined(VWHU_MTYPE)
    struct Whu2    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi2    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf2    F;
#   endif

};
union Vwh3 {
#   if defined(VWHU_MTYPE)
    struct Whu3    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi3    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf3    F;
#   endif

};
union Vwh4 {
#   if defined(VWHU_MTYPE)
    struct Whu4    U;
#   endif

#   if defined(VWHI_MTYPE)
    struct Whi4    I;
#   endif

#   if defined(VWHF_MTYPE)
    struct Whf4    F;
#   endif

};

#endif

#if defined(VWWU_MTYPE) || defined(VWWI_MTYPE) || defined(VWWF_MTYPE)

#   define  VWW_M1TYPE   union Vww1

union Vwwm {
#   if defined(VWWU_MTYPE)
    VWWU_MTYPE  U;
#   endif

#   if defined(VWWI_MTYPE)
    VWWI_MTYPE  I;
#   endif

#   if defined(VWWF_MTYPE)
    VWWF_MTYPE  F;
#   endif

};
union Vww1 {
#   if defined(VWWU_MTYPE)
    struct Wwu1    U;
#   endif

#   if defined(VWWI_MTYPE)
    struct Wwi1    I;
#   endif

#   if defined(VWWF_MTYPE)
    struct Wwf1    F;
#   endif

};
union Vww2 {
#   if defined(VWWU_MTYPE)
    struct Wwu2    U;
#   endif
#   if defined(VWWI_MTYPE)
    struct Wwi2    I;
#   endif
#   if defined(VWWF_MTYPE)
    struct Wwf2    F;
#   endif
};
union Vww3 {
#   if defined(VWWU_MTYPE)
    struct Wwu3    U;
#   endif
#   if defined(VWWI_MTYPE)
    struct Wwi3    I;
#   endif
#   if defined(VWWF_MTYPE)
    struct Wwf3    F;
#   endif
};
union Vww4 {
#   if defined(VWWU_MTYPE)
    struct Wwu4    U;
#   endif
#   if defined(VWWI_MTYPE)
    struct Wwi4    I;
#   endif
#   if defined(VWWF_MTYPE)
    struct Wwf4    F;
#   endif
};

#endif

typedef  union Vwb {
    Vwba        A;
    Vwbu        U;
    Vwbi        I;
    Vwbc        C;
#   if defined(VWB_M1TYPE)
    union Vwbm  M;
    union Vwb1  M1;
#   endif

    struct {
        union {uint8_t U0; int8_t I0; char C0;};
        union {uint8_t U1; int8_t I1; char C1;};
        union {uint8_t U2; int8_t I2; char C2;};
        union {uint8_t U3; int8_t I3; char C3;};
    };

} Vwb;
typedef  union Vwh {
    Vwha        A;
    Vwhu        U;
    Vwhi        I;
    Vwhf        F;
#   if defined(VWB_M1TYPE)
    union Vwhm  M;
    union Vwh1  M1;
#   endif

    struct {
        union {Half H0; uint16_t U0; int16_t I0; flt16_t F0;};
        union {Half H1; uint16_t U1; int16_t I1; flt16_t F1;};
    };

} Vwh;
typedef  union Vww {
    Vwwa        A;
    Vwwu        U;
    Vwwi        I;
    Vwwf        F;
#   if defined(VWB_M1TYPE)
    union Vwwm  M;
    union Vww1  M1;
#   endif
    struct {
        union {uint32_t U0; int32_t I0; float F0;};
    };

} Vww;
typedef  union Vw {
    Vwyu    Y;
    Vwb     B;
    Vwh     H;
    Vww     W;
} Vw;


#if defined(VDBU_MTYPE) || defined(VDBI_MTYPE) || defined(VDBC_MTYPE)

#   define  VDB_M1TYPE   union Vdb1

union Vdbm {

#   if defined(VDBU_MTYPE)
    VDBU_MTYPE      U;
#   endif

#   if defined(VDBI_MTYPE)
    VDBI_MTYPE      I;
#   endif

#   if defined(VDBC_MTYPE)
    VDBC_MTYPE      C;
#   endif

};
union Vdb1 {

#   if defined(VDBU_MTYPE)
    struct Dbu1     U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi1     I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc1     C;
#   endif

};
union Vdb2 {

#   if defined(VDBU_MTYPE)
    struct Dbu2     U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi2     I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc2     C;
#   endif

};
union Vdb3 {

#   if defined(VDBU_MTYPE)
    struct Dbu3 U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi3 I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc3 C;
#   endif

};
union Vdb4 {

#   if defined(VDBU_MTYPE)
    struct Dbu4    U;
#   endif

#   if defined(VDBI_MTYPE)
    struct Dbi4    I;
#   endif

#   if defined(VDBC_MTYPE)
    struct Dbc4      C;
#   endif

};

#endif

#if defined(VDHU_MTYPE) || defined(VDHI_MTYPE) || defined(VDHF_MTYPE)

#   define  VDH_M1TYPE   union Vdh1

union Vdhm {
#   if defined(VDHU_MTYPE)
    VDHU_MTYPE     U;
#   endif

#   if defined(VDHI_MTYPE)
    VDHI_MTYPE      I;
#   endif

#   if defined(VDHF_MTYPE)
    VDHF_MTYPE     F;
#   endif

};
union Vdh1 {

#   if defined(VDHU_MTYPE)
    struct Dhu1    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi1    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf1    F;
#   endif

};
union Vdh2 {

#   if defined(VDHU_MTYPE)
    struct Dhu2    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi2    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf2    F;
#   endif

};
union Vdh3 {
#   if defined(VDHU_MTYPE)
    struct Dhu3    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi3    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf3    F;
#   endif

};
union Vdh4 {
#   if defined(VDHU_MTYPE)
    struct Dhu4    U;
#   endif

#   if defined(VDHI_MTYPE)
    struct Dhi4    I;
#   endif

#   if defined(VDHF_MTYPE)
    struct Dhf4    F;
#   endif

};

#endif

#if defined(VDWU_MTYPE) || defined(VDWI_MTYPE) || defined(VDWF_MTYPE)

#   define  VDW_M1TYPE   union Vdw1

union Vdwm {

#   if defined(VDWU_MTYPE)
    VDWU_MTYPE     U;
#   endif

#   if defined(VDWI_MTYPE)
    VDWI_MTYPE     I;
#   endif

#   if defined(VDWF_MTYPE)
    VDWF_MTYPE     F;
#   endif

};
union Vdw1 {
#   if defined(VDWU_MTYPE)
    struct Dwu1    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi1    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf1    F;
#   endif

};
union Vdw2 {

#   if defined(VDWU_MTYPE)
    struct Dwu2    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi2    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf2    F;
#   endif

};
union Vdw3 {

#   if defined(VDWU_MTYPE)
    struct Dwu3    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi3    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf3    F;
#   endif

};
union Vdw4 {

#   if defined(VDWU_MTYPE)
    struct Dwu4    U;
#   endif

#   if defined(VDWI_MTYPE)
    struct Dwi4    I;
#   endif

#   if defined(VDWF_MTYPE)
    struct Dwf4    F;
#   endif

};

#endif

#if defined(VDDU_MTYPE) || defined(VDDI_MTYPE) || defined(VDDF_MTYPE)

#   define  VDD_M1TYPE   union Vdd1

union Vddm {

#   if defined(VDDU_MTYPE)
    VDDU_MTYPE      U;
#   endif

#   if defined(VDDI_MTYPE)
    VDDI_MTYPE     I;
#   endif

#   if defined(VDDF_MTYPE)
    VDDF_MTYPE     F;
#   endif

};
union Vdd1 {
    union Vddm      M;
#   if defined(VDDU_MTYPE)
    struct Ddu1     U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi1     I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf1     F;
#   endif

};
union Vdd2 {

#   if defined(VDDU_MTYPE)
    struct Ddu2    U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi2    I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf2    F;
#   endif

};
union Vdd3 {

#   if defined(VDDU_MTYPE)
    struct Ddu3    U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi3    I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf3    F;
#   endif

};
union Vdd4 {

#   if defined(VDDU_MTYPE)
    struct Ddu4    U;
#   endif

#   if defined(VDDI_MTYPE)
    struct Ddi4    I;
#   endif

#   if defined(VDDF_MTYPE)
    struct Ddf4    F;
#   endif

};

#endif

typedef  union Vdb {
    Vdba        A;
    Vdbu        U;
    Vdbi        I;
    Vdbc        C;
#   if defined(VWB_M2TYPE)
    union Vwb2  M2;
#   endif

#   if defined(VDB_M1TYPE)
    union Vdbm  M;
    union Vdb1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint8_t U0; int8_t I0; char C0;};
                union {uint8_t U1; int8_t I1; char C1;};
                union {uint8_t U2; int8_t I2; char C2;};
                union {uint8_t U3; int8_t I3; char C3;};
            };
            Vwb Lo;
        };
        union {
            struct {
                union {uint8_t U4; int8_t I4; char C4;};
                union {uint8_t U5; int8_t I5; char C5;};
                union {uint8_t U6; int8_t I6; char C6;};
                union {uint8_t U7; int8_t I7; char C7;};
            };
            Vwb Hi;
        };
    };

} Vdb;
typedef  union Vdh {

    Vdha    A;
    Vdhu    U;
    Vdhi    I;
    Vdhf    F;

#   if defined(VWH_M1TYPE)
    union Vwh2  M2;
#   endif

#   if defined(VDH_M1TYPE)
    union Vdhm  M;
    union Vdh1  M1;
#   endif

    struct {
        union {
            struct {
                union {uint16_t U0; int16_t I0; flt16_t F0;};
                union {uint16_t U1; int16_t I1; flt16_t F1;};
            };
            Vwh Lo;
        };
        union {
            struct {
                union {uint16_t U2; int16_t I2; flt16_t F2;};
                union {uint16_t U3; int16_t I3; flt16_t F3;};
            };
            Vwh Hi;
        };
    };

} Vdh;
typedef  union Vdw {
    Vdwa    A;
    Vdwu    U;
    Vdwi    I;
    Vdwf    F;
#   if defined(VWW_M1TYPE)
    union Vww2  M2;
#   endif

#   if defined(VDW_M1TYPE)
    union Vdw1  M1;
    union Vdwm  M;
#   endif

    struct {
        union {
            struct {
                union {unsigned U0; int I0; float F0;};
            };
            Vww Lo;
        };
        union {
            struct {

                union {unsigned U1; int I1; float F1;};
            };
            Vww Hi;
        };
    };

} Vdw;
typedef  union Vdd {
    Vdda    A;
    Vddu    U;
    Vddi    I;
    Vddf    F;
#   if defined(VDD_M1TYPE)
    union Vdd1  M1;
    union Vddm  M;
#   endif

    struct {
        union {uint64_t U0; int64_t I0; double F0;};
    };

} Vdd;
typedef  union Vd {
    struct {Vw Lo, Hi;};
    Vdyu    Y;
    Vdb     B;
    Vdh     H;
    Vdw     W;
    Vdd     D;
} Vd;

#if defined(VQBU_MTYPE) || defined(VQBI_MTYPE) || defined(VQBC_MTYPE)

#   define  VQB_M1TYPE   union Vqb1

union Vqb1 {

#   if defined(VQBU_MTYPE)
    struct Qbu1    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi1    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc1    C;
#   endif

};
union Vqb2 {

#   if defined(VQBU_MTYPE)
    struct Qbu2    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi2    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc2    C;
#   endif

};
union Vqb3 {

#   if defined(VQBU_MTYPE)
    struct Qbu3    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi3    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc3    C;
#   endif

};
union Vqb4 {

#   if defined(VQBU_MTYPE)
    struct Qbu4    U;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbi4    I;
#   endif

#   if defined(VQBI_MTYPE)
    struct Qbc4    C;
#   endif

};

#endif

#if defined(VQHU_MTYPE) || defined(VQHI_MTYPE) || defined(VQHF_MTYPE)

#   define  VQH_M1TYPE   union Vqh1

union Vqh1 {

#   if defined(VQHU_MTYPE)
    struct Qhu1    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi1    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf1    F;
#   endif

};
union Vqh2 {

#   if defined(VQHU_MTYPE)
    struct Qhu2    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi2    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf2    F;
#   endif

};
union Vqh3 {

#   if defined(VQHU_MTYPE)
    struct Qhu3    U;
#   endif

#   if defined(VQHI_MTYPE)
    struct Qhi3    I;
#   endif

#   if defined(VQHF_MTYPE)
    struct Qhf3    F;
#   endif

};
union Vqh4 {
#   if defined(VQHU_MTYPE)
    struct Qhu4    U;
#   endif
#   if defined(VQHI_MTYPE)
    struct Qhi4    I;
#   endif
#   if defined(VQHF_MTYPE)
    struct Qhf4    F;
#   endif
};

#endif

#if defined(VQWU_MTYPE) || defined(VQWI_MTYPE) || defined(VQWF_MTYPE)

#   define  VQW_M1TYPE   union Vqw1

union Vqw1 {

#   if defined(VQWU_MTYPE)
    struct Qwu1    U;
#   endif

#   if defined(VQWI_MTYPE)
    struct Qwi1    I;
#   endif

#   if defined(VQWF_MTYPE)
    struct Qwf1    F;
#   endif

};
union Vqw2 {

#   if defined(VQWU_MTYPE)
    struct Qwu2    U;
#   endif

#   if defined(VQWI_MTYPE)
    struct Qwi2    I;
#   endif

#   if defined(VQWF_MTYPE)
    struct Qwf2    F;
#   endif

};
union Vqw3 {
#   if defined(VQWU_MTYPE)
    struct Qwu3    U;
#   endif
#   if defined(VQWI_MTYPE)
    struct Qwi3    I;
#   endif
#   if defined(VQWF_MTYPE)
    struct Qwf3    F;
#   endif
};
union Vqw4 {
#   if defined(VQWU_MTYPE)
    struct Qwu4    U;
#   endif
#   if defined(VQWI_MTYPE)
    struct Qwi4    I;
#   endif
#   if defined(VQWF_MTYPE)
    struct Qwf4    F;
#   endif
};

#endif

#if defined(VQDU_MTYPE) || defined(VQDI_MTYPE) || defined(VQDF_MTYPE)

#   define  VQD_M1TYPE   union Vqd1

union Vqd1 {

#   if defined(VQDU_MTYPE)
    struct Qdu1    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi1    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf1    F;
#   endif

};
union Vqd2 {

#   if defined(VQDU_MTYPE)
    struct Qdu2    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi2    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf2    F;
#   endif

};
union Vqd3 {

#   if defined(VQDU_MTYPE)
    struct Qdu3    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi3    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf3    F;
#   endif

};
union Vqd4 {

#   if defined(VQDU_MTYPE)
    struct Qdu4    U;
#   endif

#   if defined(VQDI_MTYPE)
    struct Qdi4    I;
#   endif

#   if defined(VQDF_MTYPE)
    struct Qdf4    F;
#   endif

};

#endif

#if 0
#if defined(VQQU_MTYPE) || defined(VQQI_MTYPE) || defined(VQQF_MTYPE)

#   define  VQQ_M1TYPE   union Vqq1

union Vqqm {

#   if defined(VQQU_MTYPE)
    VQQU_MTYPE      U;
#   endif

#   if defined(VQQI_MTYPE)
    VQQI_MTYPE     I;
#   endif

#   if defined(VQQF_MTYPE)
    VQQF_MTYPE     F;
#   endif

};
union Vqq1 {

#   if defined(VQQU_MTYPE)
    struct Qqu1    U;
#   endif

#   if defined(VQQI_MTYPE)
    struct Qqi1    I;
#   endif

#   if defined(VQQF_MTYPE)
    struct Qqf1    F;
#   endif

};
union Vqq2 {

#   if defined(VQQU_MTYPE)
    struct Qqu2    U;
#   endif

#   if defined(VQQI_MTYPE)
    struct Qqi2    I;
#   endif

#   if defined(VQQF_MTYPE)
    struct Qqf2    F;
#   endif

};
union Vqq3 {

#   if defined(VQQU_MTYPE)
    struct Qqu3    U;
#   endif

#   if defined(VQQI_MTYPE)
    struct Qqi3    I;
#   endif

#   if defined(VQQF_MTYPE)
    struct Qqf3    F;
#   endif

};
union Vqq4 {

#   if defined(VQQU_MTYPE)
    struct Qqu4    U;
#   endif

#   if defined(VQQI_MTYPE)
    struct Qqi4    I;
#   endif

#   if defined(VQQF_MTYPE)
    struct Qqf4    F;
#   endif

};

#endif
#endif

typedef  union Vqb {

    Vqba    A;
    Vqbu    U;
    Vqbi    I;
    Vqbc    C;

#   if defined(VWB_M1TYPE)
    union Vwb4  M4;
#   endif

#   if defined(VDB_M1TYPE)
    union Vdb2  M2;
#   endif

#   if defined(VQB_M1TYPE)
    union Vqb1  M1;
#   endif

    struct {
        union {

            struct {

                union {uint8_t U0; int8_t I0; char C0;};
                union {uint8_t U1; int8_t I1; char C1;};
                union {uint8_t U2; int8_t I2; char C2;};
                union {uint8_t U3; int8_t I3; char C3;};
                union {uint8_t U4; int8_t I4; char C4;};
                union {uint8_t U5; int8_t I5; char C5;};
                union {uint8_t U6; int8_t I6; char C6;};
                union {uint8_t U7; int8_t I7; char C7;};
            };

            Vdb Lo;
        };
        union {

            struct {

                union {uint8_t U8;  int8_t I8;  char C8;};
                union {uint8_t U9;  int8_t I9;  char C9;};
                union {uint8_t U10; int8_t I10; char C10;};
                union {uint8_t U11; int8_t I11; char C11;};
                union {uint8_t U12; int8_t I12; char C12;};
                union {uint8_t U13; int8_t I13; char C13;};
                union {uint8_t U14; int8_t I14; char C14;};
                union {uint8_t U15; int8_t I15; char C15;};
            };
            Vdb Hi;
        };
    };

} Vqb;

typedef  union Vqh {

    Vqha    A;
    Vqhu    U;
    Vqhi    I;
    Vqhf    F;

#   if defined(VWH_M1TYPE)
    union Vwh4  M4;
#   endif

#   if defined(VDH_M1TYPE)
    union Vdh2  M2;
#   endif

#   if defined(VQH_M1TYPE)
    union Vqh1  M1;
#   endif

    struct {

        union {
            struct {
                union {uint16_t U0; int16_t I0; flt16_t F0;};
                union {uint16_t U1; int16_t I1; flt16_t F1;};
                union {uint16_t U2; int16_t I2; flt16_t F2;};
                union {uint16_t U3; int16_t I3; flt16_t F3;};
            };
            Vdh Lo;
        };

        union {
            struct {
                union {uint16_t U4; int16_t I4; flt16_t F4;};
                union {uint16_t U5; int16_t I5; flt16_t F5;};
                union {uint16_t U6; int16_t I6; flt16_t F6;};
                union {uint16_t U7; int16_t I7; flt16_t F7;};
            };
            Vdh Hi;
        };

    };

} Vqh;

typedef  union Vqw {

    Vqwa    A;
    Vqwu    U;
    Vqwi    I;
    Vqwf    F;

#   if defined(VWW_M1TYPE)
    union Vww4  M4;
#   endif

#   if defined(VDW_M1TYPE)
    union Vdw2  M2;
#   endif

#   if defined(VQW_M1TYPE)
    union Vqw1  M1;
#   endif

    struct {

        union {
            struct {
                union {unsigned U0; int I0; float F0;};
                union {unsigned U1; int I1; float F1;};
            };
            Vdw Lo;
        };

        union {
            struct {
                union {unsigned U2; int I2; float F2;};
                union {unsigned U3; int I3; float F3;};
            };
            Vdw Hi;
        };

    };

} Vqw;

typedef  union Vqd {

    Vqda        A;
    Vqdu        U;
    Vqdi        I;
    Vqdf        F;

#   if defined(VDD_M1TYPE)
    union Vdd2  M2;
#   endif

#   if defined(VQD_M1TYPE)
    union Vqd1  M1;
#   endif

    struct {

        union {
            union {uint64_t U0; int64_t I0; double F0;};
            Vdd Lo;
        };

        union {
            union {uint64_t U1; int64_t I1; double F1;};
            Vdd Hi;
        };

    };

} Vqd;

#if 0
typedef  union Vqq {
    Vqqa    A;
    Vqqu    U;
    Vqqi    I;
    Vqqf    F;
#   if defined(VQQ_M1TYPE)
    union Vqq1  M1;
    union Vqqm  M;
#   endif

    union {
        struct {QUAD_UTYPE  U0;};
        struct {QUAD_ITYPE  I0;};
        struct {QUAD_FTYPE  F0;};
    };

} Vqq;
#endif

typedef  union Vq {
    struct {Vd Lo, Hi;};
    Vqyu    Y;
    Vqb     B;
    Vqh     H;
    Vqw     W;
    Vqd     D;
    //Vqq     Q;
} Vq;

#if _LEAVE_EXTVEC_TYPEDEFS
}
#endif


INLINE(Vwyu,VWYU_ASYU) (Vwyu v) {return v;}

INLINE(Vwbu,VWBU_ASBU) (Vwbu v) {return v;}
INLINE(Vwbi,VWBI_ASBI) (Vwbi v) {return v;}
INLINE(Vwbc,VWBC_ASBC) (Vwbc v) {return v;}

INLINE(Vwhu,VWHU_ASHU) (Vwhu v) {return v;}
INLINE(Vwhi,VWHI_ASHI) (Vwhi v) {return v;}
INLINE(Vwhf,VWHF_ASHF) (Vwhf v) {return v;}

INLINE(Vwwu,VWWU_ASWU) (Vwwu v) {return v;}
INLINE(Vwwi,VWWI_ASWI) (Vwwi v) {return v;}
INLINE(Vwwf,VWWF_ASWF) (Vwwf v) {return v;}

#if 0
#define     VWYU_ASYU(V)    _Generic(V,Vwyu:V)

#define     VWBU_ASBU(V)    _Generic(V,Vwbu:V)
#define     VWBI_ASBI(V)    _Generic(V,Vwbi:V)
#define     VWBC_ASBC(V)    _Generic(V,Vwbc:V)

#define     VWHU_ASHU(V)    _Generic(V,Vwhu:V)
#define     VWHI_ASHI(V)    _Generic(V,Vwhi:V)
#define     VWHF_ASHF(V)    _Generic(V,Vwhf:V)

#define     VWWU_ASWU(V)    _Generic(V,Vwwu:V)
#define     VWWI_ASWI(V)    _Generic(V,Vwwi:V)
#define     VWWF_ASWF(V)    _Generic(V,Vwwf:V)
#endif

INLINE(Vdyu,VDYU_ASYU) (Vdyu v) {return v;}
INLINE(Vdbu,VDBU_ASBU) (Vdbu v) {return v;}
INLINE(Vdbi,VDBI_ASBI) (Vdbi v) {return v;}
INLINE(Vdbc,VDBC_ASBC) (Vdbc v) {return v;}
INLINE(Vdhu,VDHU_ASHU) (Vdhu v) {return v;}
INLINE(Vdhi,VDHI_ASHI) (Vdhi v) {return v;}
INLINE(Vdhf,VDHF_ASHF) (Vdhf v) {return v;}
INLINE(Vdwu,VDWU_ASWU) (Vdwu v) {return v;}
INLINE(Vdwi,VDWI_ASWI) (Vdwi v) {return v;}
INLINE(Vdwf,VDWF_ASWF) (Vdwf v) {return v;}
INLINE(Vddu,VDDU_ASDU) (Vddu v) {return v;}
INLINE(Vddi,VDDI_ASDI) (Vddi v) {return v;}
INLINE(Vddf,VDDF_ASDF) (Vddf v) {return v;}

#define     VDYU_ASYU(V)    _Generic(V,Vdyu:V)
#define     VDBU_ASBU(V)    _Generic(V,Vdbu:V)
#define     VDBI_ASBI(V)    _Generic(V,Vdbi:V)
#define     VDBC_ASBC(V)    _Generic(V,Vdbc:V)
#define     VDHU_ASHU(V)    _Generic(V,Vdhu:V)
#define     VDHI_ASHI(V)    _Generic(V,Vdhi:V)
#define     VDHF_ASHF(V)    _Generic(V,Vdhf:V)
#define     VDWU_ASWU(V)    _Generic(V,Vdwu:V)
#define     VDWI_ASWI(V)    _Generic(V,Vdwi:V)
#define     VDWF_ASWF(V)    _Generic(V,Vdwf:V)
#define     VDDU_ASDU(V)    _Generic(V,Vddu:V)
#define     VDDI_ASDI(V)    _Generic(V,Vddi:V)
#define     VDDF_ASDF(V)    _Generic(V,Vddf:V)

INLINE(Vqyu,VQYU_ASYU) (Vqyu v) {return v;}
INLINE(Vqbu,VQBU_ASBU) (Vqbu v) {return v;}
INLINE(Vqbi,VQBI_ASBI) (Vqbi v) {return v;}
INLINE(Vqbc,VQBC_ASBC) (Vqbc v) {return v;}
INLINE(Vqhu,VQHU_ASHU) (Vqhu v) {return v;}
INLINE(Vqhi,VQHI_ASHI) (Vqhi v) {return v;}
INLINE(Vqhf,VQHF_ASHF) (Vqhf v) {return v;}
INLINE(Vqwu,VQWU_ASWU) (Vqwu v) {return v;}
INLINE(Vqwi,VQWI_ASWI) (Vqwi v) {return v;}
INLINE(Vqwf,VQWF_ASWF) (Vqwf v) {return v;}
INLINE(Vqdu,VQDU_ASDU) (Vqdu v) {return v;}
INLINE(Vqdi,VQDI_ASDI) (Vqdi v) {return v;}
INLINE(Vqdf,VQDF_ASDF) (Vqdf v) {return v;}

#define     VQYU_ASYU(V)    _Generic(V,Vqyu:V)
#define     VQBU_ASBU(V)    _Generic(V,Vqbu:V)
#define     VQBI_ASBI(V)    _Generic(V,Vqbi:V)
#define     VQBC_ASBC(V)    _Generic(V,Vqbc:V)
#define     VQHU_ASHU(V)    _Generic(V,Vqhu:V)
#define     VQHI_ASHI(V)    _Generic(V,Vqhi:V)
#define     VQHF_ASHF(V)    _Generic(V,Vqhf:V)
#define     VQWU_ASWU(V)    _Generic(V,Vqwu:V)
#define     VQWI_ASWI(V)    _Generic(V,Vqwi:V)
#define     VQWF_ASWF(V)    _Generic(V,Vqwf:V)
#define     VQDU_ASDU(V)    _Generic(V,Vqdu:V)
#define     VQDI_ASDI(V)    _Generic(V,Vqdi:V)
#define     VQDF_ASDF(V)    _Generic(V,Vqdf:V)

#define     VWYU_ASTU   VWYU_ASYU
#define     VWBU_ASTU   VWBU_ASBU
#define     VWBI_ASTI   VWBI_ASBI
//          ??
#define     VWHU_ASTU   VWHU_ASHU
#define     VWHI_ASTI   VWHI_ASHI
#define     VWHF_ASTF   VWHF_ASHF
#define     VWWU_ASTU   VWWU_ASWU
#define     VWWI_ASTI   VWWI_ASWI
#define     VWWF_ASTF   VWWF_ASWF

#define     VDYU_ASTU   VDYU_ASYU
#define     VDBU_ASTU   VDBU_ASBU
#define     VDBI_ASTI   VDBI_ASBI
//          ??
#define     VDHU_ASTU   VDHU_ASHU
#define     VDHI_ASTI   VDHI_ASHI
#define     VDHF_ASTF   VDHF_ASHF
#define     VDWU_ASTU   VDWU_ASWU
#define     VDWI_ASTI   VDWI_ASWI
#define     VDWF_ASTF   VDWF_ASWF
#define     VDDU_ASTU   VDDU_ASDU
#define     VDDI_ASTI   VDDI_ASDI
#define     VDDF_ASTF   VDDF_ASDF

#define     VQYU_ASTU   VQYU_ASYU
#define     VQBU_ASTU   VQBU_ASBU
#define     VQBI_ASTI   VQBI_ASBI
//          ??
#define     VQHU_ASTU   VQHU_ASHU
#define     VQHI_ASTI   VQHI_ASHI
#define     VQHF_ASTF   VQHF_ASHF
#define     VQWU_ASTU   VQWU_ASWU
#define     VQWI_ASTI   VQWI_ASWI
#define     VQWF_ASTF   VQWF_ASWF
#define     VQDU_ASTU   VQDU_ASDU
#define     VQDI_ASTI   VQDI_ASDI
#define     VQDF_ASTF   VQDF_ASDF

#define     VOYU_ASTU   VOYU_ASYU
#define     VOBU_ASTU   VOBU_ASBU
#define     VOBI_ASTI   VOBI_ASBI
//          ??
#define     VOHU_ASTU   VOHU_ASHU
#define     VOHI_ASTI   VOHI_ASHI
#define     VOHF_ASTF   VOHF_ASHF
#define     VOWU_ASTU   VOWU_ASWU
#define     VOWI_ASTI   VOWI_ASWI
#define     VOWF_ASTF   VOWF_ASWF
#define     VODU_ASTU   VODU_ASDU
#define     VODI_ASTI   VODI_ASDI
#define     VODF_ASTF   VODF_ASDF

#define     VSYU_ASTU   VSYU_ASYU
#define     VSBU_ASTU   VSBU_ASBU
#define     VSBI_ASTI   VSBI_ASBI
//          ??
#define     VSHU_ASTU   VSHU_ASHU
#define     VSHI_ASTI   VSHI_ASHI
#define     VSHF_ASTF   VSHF_ASHF
#define     VSWU_ASTU   VSWU_ASWU
#define     VSWI_ASTI   VSWI_ASWI
#define     VSWF_ASTF   VSWF_ASWF
#define     VSDU_ASTU   VSDU_ASDU
#define     VSDI_ASTI   VSDI_ASDI
#define     VSDF_ASTF   VSDF_ASDF

#endif // EOF("extvec.h")

#if _EXTVEC_HDR_LEAVE
}
#endif


#if _ENTER_UNGOP
{
#endif

#ifndef MY_UNGOP_H // BOF("extgop.h")
#define MY_UNGOP_H

// type generic numbers
#if _ENTER_UNGOP_TGK
{
#endif

#define     TGK_NONE(MY, _)
#define     TGK_YU(MY, _)    MY(_Bool):BOOL_SN(_),
#define     TGK_YI(MY, _)
#define     TGK_YF(MY, _)

#if defined(MY_BROKEN_CHAR)
#   define  TGK_BU(MY, _)   MY(BYTE_UTYPE):BYTE_SNU(_),
#   define  TGK_BI(MY, _)   MY(BYTE_ITYPE):BYTE_SNI(_),
#elif CHAR_MIN
#   define  TGK_BU(MY, _)   MY(BYTE_UTYPE):BYTE_SNU(_),
#   define  TGK_BI(MY, _)   MY(BYTE_ITYPE):BYTE_SNI(_), MY(char):_##bc,
#else
#   define  TGK_BU(MY, _)   MY(BYTE_UTYPE):BYTE_SNU(_), MY(char):_##bc,
#   define  TGK_BI(MY, _)   MY(BYTE_ITYPE):BYTE_SNI(_),
#endif

#define     TGK_BF(MY, _)

#define     TGK_HU(MY, _)   MY(HALF_UTYPE):HALF_SNU(_),
#define     TGK_HI(MY, _)   MY(HALF_ITYPE):HALF_SNI(_),
#define     TGK_HF(MY, _)   MY(HALF_FTYPE):HALF_SNF(_),

#if defined(WORD_LUTYPE)
#   define  TGK_WU(MY, _)   MY(WORD_UTYPE):WORD_SNU(_), MY(WORD_LUTYPE):_##lu,
#else
#   define  TGK_WU(MY, _)   MY(WORD_UTYPE):WORD_SNU(_),
#endif

#if defined(WORD_LITYPE)
#   define  TGK_WI(MY, _)   MY(WORD_ITYPE):WORD_SNI(_), MY(WORD_LITYPE):_##li,
#else
#   define  TGK_WI(MY, _)   MY(WORD_ITYPE):WORD_SNI(_),
#endif

#define     TGK_WF(MY, _)   MY(WORD_FTYPE):WORD_SNF(_),

#if defined(DWRD_LUTYPE)
#   define  TGK_DU(MY, _)   MY(DWRD_UTYPE):DWRD_SNU(_), MY(DWRD_LUTYPE):_##lu,
#else
#   define  TGK_DU(MY, _)   MY(DWRD_UTYPE):DWRD_SNU(_),
#endif

#if defined(DWRD_LITYPE)
#   define  TGK_DI(MY, _)   MY(DWRD_ITYPE):DWRD_SNI(_), MY(DWRD_LITYPE):_##li,
#else
#   define  TGK_DI(MY, _)   MY(DWRD_ITYPE):DWRD_SNI(_),
#endif

#if defined(DWRD_LFTYPE)
#   define  TGK_DF(MY, _)   MY(DWRD_FTYPE):DWRD_SNF(_), MY(DWRD_LFTYPE):_##lf,
#else
#   define  TGK_DF(MY, _)   MY(DWRD_FTYPE):DWRD_SNF(_),
#endif


#define TGK_YZ(F,_) TGK_YU(F,_)
#define TGK_BZ(F,_) TGK_BU(F,_) TGK_BI(F,_)
#define TGK_HZ(F,_) TGK_HU(F,_) TGK_HI(F,_)
#define TGK_WZ(F,_) TGK_WU(F,_) TGK_WI(F,_)
#define TGK_DZ(F,_) TGK_DU(F,_) TGK_DI(F,_)

#define TGK_YN(F,_) TGK_YU(F,_)
#define TGK_BN(F,_) TGK_BU(F,_) TGK_BF(F,_)
#define TGK_HN(F,_) TGK_HU(F,_) TGK_HF(F,_)
#define TGK_WN(F,_) TGK_WU(F,_) TGK_WF(F,_)
#define TGK_DN(F,_) TGK_DU(F,_) TGK_DF(F,_)

#define TGK_YS(F,_)
#define TGK_BS(F,_) TGK_BI(F,_) TGK_BF(F,_)
#define TGK_HS(F,_) TGK_HI(F,_) TGK_HF(F,_)
#define TGK_WS(F,_) TGK_WI(F,_) TGK_WF(F,_)
#define TGK_DS(F,_) TGK_DI(F,_) TGK_DF(F,_)

#define TGK_YR(F,_) TGK_YU(F,_)
#define TGK_BR(F,_) TGK_BU(F,_) TGK_BF(F,_) TGK_BI(F,_)
#define TGK_HR(F,_) TGK_HU(F,_) TGK_HF(F,_) TGK_HI(F,_)
#define TGK_WR(F,_) TGK_WU(F,_) TGK_WF(F,_) TGK_WI(F,_)
#define TGK_DR(F,_) TGK_DU(F,_) TGK_DF(F,_) TGK_DI(F,_)

#define TGK_YBU(F,_) TGK_YU(F,_) TGK_BU(F,_)
#define TGK_YHU(F,_) TGK_YU(F,_) TGK_BU(F,_) TGK_HU(F,_)
#define TGK_YWU(F,_) TGK_YU(F,_) TGK_BU(F,_) TGK_HU(F,_) TGK_WU(F,_)
#define TGK_YDU(F,_) TGK_YU(F,_) TGK_BU(F,_) TGK_HU(F,_) TGK_WU(F,_) TGK_DU(F,_)
#define TGK_BHU(F,_)             TGK_BU(F,_) TGK_HU(F,_)
#define TGK_BWU(F,_)             TGK_BU(F,_) TGK_HU(F,_) TGK_WU(F,_)
#define TGK_BDU(F,_)             TGK_BU(F,_) TGK_HU(F,_) TGK_WU(F,_) TGK_DU(F,_)
#define TGK_HWU(F,_)                         TGK_HU(F,_) TGK_WU(F,_)
#define TGK_HDU(F,_)                         TGK_HU(F,_) TGK_WU(F,_) TGK_DU(F,_)
#define TGK_WDU(F,_)                                     TGK_WU(F,_) TGK_DU(F,_)

#define TGK_YBI(F,_) TGK_YI(F,_) TGK_BI(F,_)
#define TGK_YHI(F,_) TGK_YI(F,_) TGK_BI(F,_) TGK_HI(F,_)
#define TGK_YWI(F,_) TGK_YI(F,_) TGK_BI(F,_) TGK_HI(F,_) TGK_WI(F,_)
#define TGK_YDI(F,_) TGK_YI(F,_) TGK_BI(F,_) TGK_HI(F,_) TGK_WI(F,_) TGK_DI(F,_)
#define TGK_BHI(F,_)             TGK_BI(F,_) TGK_HI(F,_)
#define TGK_BWI(F,_)             TGK_BI(F,_) TGK_HI(F,_) TGK_WI(F,_)
#define TGK_BDI(F,_)             TGK_BI(F,_) TGK_HI(F,_) TGK_WI(F,_) TGK_DI(F,_)
#define TGK_HWI(F,_)                         TGK_HI(F,_) TGK_WI(F,_)
#define TGK_HDI(F,_)                         TGK_HI(F,_) TGK_WI(F,_) TGK_DI(F,_)
#define TGK_WDI(F,_)                                     TGK_WI(F,_) TGK_DI(F,_)

#define TGK_YBF(F,_) TGK_YF(F,_) TGK_BF(F,_) TGK_HF(F,_)
#define TGK_YHF(F,_) TGK_YF(F,_) TGK_BF(F,_) TGK_HF(F,_)
#define TGK_YWF(F,_) TGK_YF(F,_) TGK_BF(F,_) TGK_HF(F,_) TGK_WF(F,_)
#define TGK_YDF(F,_) TGK_YI(F,_) TGK_BF(F,_) TGK_HF(F,_) TGK_WF(F,_) TGK_DF(F,_)
#define TGK_BHF(F,_)             TGK_BF(F,_) TGK_HF(F,_)
#define TGK_BWF(F,_)             TGK_BF(F,_) TGK_HF(F,_) TGK_WF(F,_)
#define TGK_BDF(F,_)             TGK_BF(F,_) TGK_HF(F,_) TGK_WF(F,_) TGK_DF(F,_)
#define TGK_HWF(F,_)                         TGK_HF(F,_) TGK_WF(F,_)
#define TGK_HDF(F,_)                         TGK_HF(F,_) TGK_WF(F,_) TGK_DF(F,_)
#define TGK_WDF(F,_)                                     TGK_WF(F,_) TGK_DF(F,_)

#define TGK_YBZ(F,_) TGK_YZ(F,_) TGK_BZ(F,_)
#define TGK_YHZ(F,_) TGK_YZ(F,_) TGK_BZ(F,_) TGK_HZ(F,_)
#define TGK_YWZ(F,_) TGK_YZ(F,_) TGK_BZ(F,_) TGK_HZ(F,_) TGK_WZ(F,_)
#define TGK_YDZ(F,_) TGK_YZ(F,_) TGK_BZ(F,_) TGK_HZ(F,_) TGK_WZ(F,_) TGK_DZ(F,_)
#define TGK_BHZ(F,_)             TGK_BZ(F,_) TGK_HZ(F,_)
#define TGK_BWZ(F,_)             TGK_BZ(F,_) TGK_HZ(F,_) TGK_WZ(F,_)
#define TGK_BDZ(F,_)             TGK_BZ(F,_) TGK_HZ(F,_) TGK_WZ(F,_) TGK_DZ(F,_)
#define TGK_HWZ(F,_)                         TGK_HZ(F,_) TGK_WZ(F,_)
#define TGK_HDZ(F,_)                         TGK_HZ(F,_) TGK_WZ(F,_) TGK_DZ(F,_)
#define TGK_WDZ(F,_)                                     TGK_WZ(F,_) TGK_DZ(F,_)

#define TGK_YBN(F,_) TGK_YN(F,_) TGK_BN(F,_)
#define TGK_YHN(F,_) TGK_YN(F,_) TGK_BN(F,_) TGK_HN(F,_)
#define TGK_YWN(F,_) TGK_YN(F,_) TGK_BN(F,_) TGK_HN(F,_) TGK_WN(F,_)
#define TGK_YDN(F,_) TGK_YN(F,_) TGK_BN(F,_) TGK_HN(F,_) TGK_WN(F,_) TGK_DN(F,_)
#define TGK_BHN(F,_)             TGK_BN(F,_) TGK_HN(F,_)
#define TGK_BWN(F,_)             TGK_BN(F,_) TGK_HN(F,_) TGK_WN(F,_)
#define TGK_BDN(F,_)             TGK_BN(F,_) TGK_HN(F,_) TGK_WN(F,_) TGK_DN(F,_)
#define TGK_HWN(F,_)                         TGK_HN(F,_) TGK_WN(F,_)
#define TGK_HDN(F,_)                         TGK_HN(F,_) TGK_WN(F,_) TGK_DN(F,_)
#define TGK_WDN(F,_)                                     TGK_WN(F,_) TGK_DN(F,_)

#define TGK_YBS(F,_) TGK_YS(F,_) TGK_BS(F,_) TGK_HS(F,_)
#define TGK_YHS(F,_) TGK_YS(F,_) TGK_BS(F,_) TGK_HS(F,_)
#define TGK_YWS(F,_) TGK_YS(F,_) TGK_BS(F,_) TGK_HS(F,_) TGK_WS(F,_)
#define TGK_YDS(F,_) TGK_YS(F,_) TGK_BS(F,_) TGK_HS(F,_) TGK_WS(F,_) TGK_DS(F,_)
#define TGK_BHS(F,_)             TGK_BS(F,_) TGK_HS(F,_)
#define TGK_BWS(F,_)             TGK_BS(F,_) TGK_HS(F,_) TGK_WS(F,_)
#define TGK_BDS(F,_)             TGK_BS(F,_) TGK_HS(F,_) TGK_WS(F,_) TGK_DS(F,_)
#define TGK_HWS(F,_)                         TGK_HS(F,_) TGK_WS(F,_)
#define TGK_HDS(F,_)                         TGK_HS(F,_) TGK_WS(F,_) TGK_DS(F,_)
#define TGK_WDS(F,_)                                     TGK_WS(F,_) TGK_DS(F,_)

#define TGK_YBR(F,_) TGK_YR(F,_) TGK_BR(F,_) TGK_HR(F,_)
#define TGK_YHR(F,_) TGK_YR(F,_) TGK_BR(F,_) TGK_HR(F,_)
#define TGK_YWR(F,_) TGK_YR(F,_) TGK_BR(F,_) TGK_HR(F,_) TGK_WR(F,_)
#define TGK_YDR(F,_) TGK_YR(F,_) TGK_BR(F,_) TGK_HR(F,_) TGK_WR(F,_) TGK_DR(F,_)
#define TGK_BHR(F,_)             TGK_BR(F,_) TGK_HR(F,_)
#define TGK_BWR(F,_)             TGK_BR(F,_) TGK_HR(F,_) TGK_WR(F,_)
#define TGK_BDR(F,_)             TGK_BR(F,_) TGK_HR(F,_) TGK_WR(F,_) TGK_DR(F,_)
#define TGK_HWR(F,_)                         TGK_HR(F,_) TGK_WR(F,_)
#define TGK_HDR(F,_)                         TGK_HR(F,_) TGK_WR(F,_) TGK_DR(F,_)
#define TGK_WDR(F,_)                                     TGK_WR(F,_) TGK_DR(F,_)

#if _LEAVE_UNGOP_TGK
}
#endif

// type generic 32 bit vectors
#if _ENTER_UNGOP_TGW
{
#endif

#ifndef     TGW_NONE
#define     TGW_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGW_YU(_)   VWYU_TYPE:VWYU_SN(_),
#   define  TGW_YI(_)
#   define  TGW_YF(_)
#   if CHAR_MIN
#       define  TGW_BU(_)   VWBU_TYPE:VWBU_SN(_),
#       define  TGW_BI(_)   VWBI_TYPE:VWBI_SN(_), VWBC_TYPE:VWBC_SN(_),
#   else
#       define  TGW_BU(_)   VWBU_TYPE:VWBU_SN(_), VWBC_TYPE:VWBC_SN(_),
#       define  TGW_BI(_)   VWBI_TYPE:VWBI_SN(_),
#   endif
#   define  TGW_BF(_)
#   define  TGW_HU(_)   VWHU_TYPE:VWHU_SN(_),
#   define  TGW_HI(_)   VWHI_TYPE:VWHI_SN(_),
#   define  TGW_HF(_)   VWHF_TYPE:VWHF_SN(_),
#   define  TGW_WU(_)   VWWU_TYPE:VWWU_SN(_),
#   define  TGW_WI(_)   VWWI_TYPE:VWWI_SN(_),
#   define  TGW_WF(_)   VWWF_TYPE:VWWF_SN(_),
#else
#   define  TGW_YU(_) //VWYU_TYPE:VWYU_SN(_),
#   define  TGW_YI(_)
#   define  TGW_YF(_)
#   define  TGW_BU(_) //VWBU_TYPE:VWBU_SN(_),
#   define  TGW_BI(_) //VWBI_TYPE:VWBI_SN(_),
#   define  TGW_BF(_)
#   define  TGW_HU(_) //VWHU_TYPE:VWHU_SN(_),
#   define  TGW_HI(_) //VWHI_TYPE:VWHI_SN(_),
#   define  TGW_HF(_) //VWHF_TYPE:VWHF_SN(_),
#   define  TGW_WU(_) //VWWU_TYPE:VWWU_SN(_),
#   define  TGW_WI(_) //VWWI_TYPE:VWWI_SN(_),
#   define  TGW_WF(_) //VWWF_TYPE:VWWF_SN(_),
#endif

#ifndef     TGW_DU
#define     TGW_DU(_)
#endif

#ifndef     TGW_DI
#define     TGW_DI(_)
#endif

#ifndef     TGW_DF
#define     TGW_DF(_)
#endif

#define     TGW_YZ(_)   TGW_YU(_) TGW_YI(_)
#define     TGW_BZ(_)   TGW_BU(_) TGW_BI(_)
#define     TGW_HZ(_)   TGW_HU(_) TGW_HI(_)
#define     TGW_WZ(_)   TGW_WU(_) TGW_WI(_)
#define     TGW_DZ(_)   TGW_DU(_) TGW_DI(_)

#define     TGW_YN(_)   TGW_YU(_)           TGW_YF(_)
#define     TGW_BN(_)   TGW_BU(_)           TGW_BF(_)
#define     TGW_HN(_)   TGW_HU(_)           TGW_HF(_)
#define     TGW_WN(_)   TGW_WU(_)           TGW_WF(_)
#define     TGW_DN(_)   TGW_DU(_)           TGW_DF(_)

#define     TGW_YS(_)             TGW_YI(_) TGW_YF(_)
#define     TGW_BS(_)             TGW_BI(_) TGW_BF(_)
#define     TGW_BS(_)             TGW_BI(_) TGW_BF(_)
#define     TGW_HS(_)             TGW_HI(_) TGW_HF(_)
#define     TGW_WS(_)             TGW_WI(_) TGW_WF(_)
#define     TGW_DS(_)             TGW_DI(_) TGW_DF(_)

#define     TGW_YR(_)   TGW_YU(_) TGW_YI(_) TGW_YF(_)
#define     TGW_BR(_)   TGW_BU(_) TGW_BI(_) TGW_BF(_)
#define     TGW_HR(_)   TGW_HU(_) TGW_HI(_) TGW_HF(_)
#define     TGW_WR(_)   TGW_WU(_) TGW_WI(_) TGW_WF(_)
#define     TGW_DR(_)   TGW_DU(_) TGW_DI(_) TGW_DF(_)

#define     TGW_YBU(_)  TGW_YU(_) TGW_BU(_)
#define     TGW_YHU(_)  TGW_YU(_) TGW_BU(_) TGW_HU(_)
#define     TGW_YWU(_)  TGW_YU(_) TGW_BU(_) TGW_HU(_) TGW_WU(_)
#define     TGW_YDU(_)  TGW_YU(_) TGW_BU(_) TGW_HU(_) TGW_WU(_) TGW_DU(_)
#define     TGW_BHU(_)            TGW_BU(_) TGW_HU(_)
#define     TGW_BWU(_)            TGW_BU(_) TGW_HU(_) TGW_WU(_)
#define     TGW_BDU(_)            TGW_BU(_) TGW_HU(_) TGW_WU(_) TGW_DU(_)
#define     TGW_HWU(_)                      TGW_HU(_) TGW_WU(_)
#define     TGW_HDU(_)                      TGW_HU(_) TGW_WU(_) TGW_DU(_)
#define     TGW_WDU(_)                                TGW_WU(_) TGW_DU(_)

#define     TGW_YBI(_)  TGW_YI(_) TGW_BI(_)
#define     TGW_YHI(_)  TGW_YI(_) TGW_BI(_) TGW_HI(_)
#define     TGW_YWI(_)  TGW_YI(_) TGW_BI(_) TGW_HI(_) TGW_WI(_)
#define     TGW_YDI(_)  TGW_YI(_) TGW_BI(_) TGW_HI(_) TGW_WI(_) TGW_DI(_)
#define     TGW_BHI(_)            TGW_BI(_) TGW_HI(_)
#define     TGW_BWI(_)            TGW_BI(_) TGW_HI(_) TGW_WI(_)
#define     TGW_BDI(_)            TGW_BI(_) TGW_HI(_) TGW_WI(_) TGW_DI(_)
#define     TGW_HWI(_)                      TGW_HI(_) TGW_WI(_)
#define     TGW_HDI(_)                      TGW_HI(_) TGW_WI(_) TGW_DI(_)
#define     TGW_WDI(_)                                TGW_WI(_) TGW_DI(_)

#define     TGW_YBF(_)  TGW_YF(_) TGW_BF(_)
#define     TGW_YHF(_)  TGW_YF(_) TGW_BF(_) TGW_HF(_)
#define     TGW_YWF(_)  TGW_YF(_) TGW_BF(_) TGW_HF(_) TGW_WF(_)
#define     TGW_YDF(_)  TGW_YF(_) TGW_BF(_) TGW_HF(_) TGW_WF(_) TGW_DF(_)
#define     TGW_BHF(_)            TGW_BF(_) TGW_HF(_)
#define     TGW_BWF(_)            TGW_BF(_) TGW_HF(_) TGW_WF(_)
#define     TGW_BDF(_)            TGW_BF(_) TGW_HF(_) TGW_WF(_) TGW_DF(_)
#define     TGW_HWF(_)                      TGW_HF(_) TGW_WF(_)
#define     TGW_HDF(_)                      TGW_HF(_) TGW_WF(_) TGW_DF(_)
#define     TGW_WDF(_)                                TGW_WF(_) TGW_DF(_)

#define     TGW_YBZ(_)  TGW_YZ(_) TGW_BZ(_)
#define     TGW_YHZ(_)  TGW_YZ(_) TGW_BZ(_) TGW_HZ(_)
#define     TGW_YWZ(_)  TGW_YZ(_) TGW_BZ(_) TGW_HZ(_) TGW_WZ(_)
#define     TGW_YDZ(_)  TGW_YZ(_) TGW_BZ(_) TGW_HZ(_) TGW_WZ(_) TGW_DZ(_)
#define     TGW_BHZ(_)            TGW_BZ(_) TGW_HZ(_)
#define     TGW_BWZ(_)            TGW_BZ(_) TGW_HZ(_) TGW_WZ(_)
#define     TGW_BDZ(_)            TGW_BZ(_) TGW_HZ(_) TGW_WZ(_) TGW_DZ(_)
#define     TGW_HWZ(_)                      TGW_HZ(_) TGW_WZ(_)
#define     TGW_HDZ(_)                      TGW_HZ(_) TGW_WZ(_) TGW_DZ(_)
#define     TGW_WDZ(_)                                TGW_WZ(_) TGW_DZ(_)

#define     TGW_YBN(_)  TGW_YN(_) TGW_BN(_)
#define     TGW_YHN(_)  TGW_YN(_) TGW_BN(_) TGW_HN(_)
#define     TGW_YWN(_)  TGW_YN(_) TGW_BN(_) TGW_HN(_) TGW_WN(_)
#define     TGW_YDN(_)  TGW_YN(_) TGW_BN(_) TGW_HN(_) TGW_WN(_) TGW_DN(_)
#define     TGW_BHN(_)            TGW_BN(_) TGW_HN(_)
#define     TGW_BWN(_)            TGW_BN(_) TGW_HN(_) TGW_WN(_)
#define     TGW_BDN(_)            TGW_BN(_) TGW_HN(_) TGW_WN(_) TGW_DN(_)
#define     TGW_HWN(_)                      TGW_HN(_) TGW_WN(_)
#define     TGW_HDN(_)                      TGW_HN(_) TGW_WN(_) TGW_DN(_)
#define     TGW_WDN(_)                                TGW_WN(_) TGW_DN(_)

#define     TGW_YBS(_)  TGW_YS(_) TGW_BS(_)
#define     TGW_YHS(_)  TGW_YS(_) TGW_BS(_) TGW_HS(_)
#define     TGW_YWS(_)  TGW_YS(_) TGW_BS(_) TGW_HS(_) TGW_WS(_)
#define     TGW_YDS(_)  TGW_YS(_) TGW_BS(_) TGW_HS(_) TGW_WS(_) TGW_DS(_)
#define     TGW_BHS(_)            TGW_BS(_) TGW_HS(_)
#define     TGW_BWS(_)            TGW_BS(_) TGW_HS(_) TGW_WS(_)
#define     TGW_BDS(_)            TGW_BS(_) TGW_HS(_) TGW_WS(_) TGW_DS(_)
#define     TGW_HWS(_)                      TGW_HS(_) TGW_WS(_)
#define     TGW_HDS(_)                      TGW_HS(_) TGW_WS(_) TGW_DS(_)
#define     TGW_WDS(_)                                TGW_WS(_) TGW_DS(_)

#define     TGW_YBR(_)  TGW_YR(_) TGW_BR(_)
#define     TGW_YHR(_)  TGW_YR(_) TGW_BR(_) TGW_HR(_)
#define     TGW_YWR(_)  TGW_YR(_) TGW_BR(_) TGW_HR(_) TGW_WR(_)
#define     TGW_YDR(_)  TGW_YR(_) TGW_BR(_) TGW_HR(_) TGW_WR(_) TGW_DR(_)
#define     TGW_BHR(_)            TGW_BR(_) TGW_HR(_)
#define     TGW_BWR(_)            TGW_BR(_) TGW_HR(_) TGW_WR(_)
#define     TGW_BDR(_)            TGW_BR(_) TGW_HR(_) TGW_WR(_) TGW_DR(_)
#define     TGW_HWR(_)                      TGW_HR(_) TGW_WR(_)
#define     TGW_HDR(_)                      TGW_HR(_) TGW_WR(_) TGW_DR(_)
#define     TGW_WDR(_)                                TGW_WR(_) TGW_DR(_)

#if _LEAVE_UNGOP_TGW
}
#endif

#if _ENTER_UNGOP_TGD
{
#endif

#ifndef     TGD_NONE
#define     TGD_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGD_YU(_)   VDYU_TYPE:VDYU_SN(_),
#   define  TGD_YI(_)
#   define  TGD_YF(_)

#   if CHAR_MIN
#       define  TGD_BU(_)   VDBU_TYPE:VDBU_SN(_),
#       define  TGD_BI(_)   VDBI_TYPE:VDBI_SN(_), VDBC_TYPE:VDBC_SN(_),
#   else
#       define  TGD_BU(_)   VDBU_TYPE:VDBU_SN(_), VDBC_TYPE:VDBC_SN(_),
#       define  TGD_BI(_)   VDBI_TYPE:VDBI_SN(_),
#   endif

#   define  TGD_BF(_)
#   define  TGD_HU(_)   VDHU_TYPE:VDHU_SN(_),
#   define  TGD_HI(_)   VDHI_TYPE:VDHI_SN(_),
#   define  TGD_HF(_)   VDHF_TYPE:VDHF_SN(_),
#   define  TGD_WU(_)   VDWU_TYPE:VDWU_SN(_),
#   define  TGD_WI(_)   VDWI_TYPE:VDWI_SN(_),
#   define  TGD_WF(_)   VDWF_TYPE:VDWF_SN(_),
#   define  TGD_DU(_)   VDDU_TYPE:VDDU_SN(_),
#   define  TGD_DI(_)   VDDI_TYPE:VDDI_SN(_),
#   define  TGD_DF(_)   VDDF_TYPE:VDDF_SN(_),
#else
#   define  TGD_YU(_) //VDYU_TYPE:VDYU_SN(_),
#   define  TGD_YI(_)
#   define  TGD_YF(_)
#   define  TGD_BU(_) //VDBU_TYPE:VDBU_SN(_),
#   define  TGD_BI(_) //VDBI_TYPE:VDBI_SN(_),
#   define  TGD_BF(_)
#   define  TGD_HU(_) //VDHU_TYPE:VDHU_SN(_),
#   define  TGD_HI(_) //VDHI_TYPE:VDHI_SN(_),
#   define  TGD_HF(_) //VDHF_TYPE:VDHF_SN(_),
#   define  TGD_WU(_) //VDWU_TYPE:VDWU_SN(_),
#   define  TGD_WI(_) //VDWI_TYPE:VDWI_SN(_),
#   define  TGD_WF(_) //VDWF_TYPE:VDWF_SN(_),
#   define  TGD_DU(_) //VDDU_TYPE:VDDU_SN(_),
#   define  TGD_DI(_) //VDDI_TYPE:VDDI_SN(_),
#   define  TGD_DF(_) //VDDF_TYPE:VDDF_SN(_),
#endif

#define     TGD_YZ(_)   TGD_YU(_) TGD_YI(_)
#define     TGD_BZ(_)   TGD_BU(_) TGD_BI(_)
#define     TGD_HZ(_)   TGD_HU(_) TGD_HI(_)
#define     TGD_WZ(_)   TGD_WU(_) TGD_WI(_)
#define     TGD_DZ(_)   TGD_DU(_) TGD_DI(_)

#define     TGD_YN(_)   TGD_YU(_)           TGD_YF(_)
#define     TGD_BN(_)   TGD_BU(_)           TGD_BF(_)
#define     TGD_HN(_)   TGD_HU(_)           TGD_HF(_)
#define     TGD_WN(_)   TGD_WU(_)           TGD_WF(_)
#define     TGD_DN(_)   TGD_DU(_)           TGD_DF(_)

#define     TGD_YS(_)             TGD_YI(_) TGD_YF(_)
#define     TGD_BS(_)             TGD_BI(_) TGD_BF(_)
#define     TGD_HS(_)             TGD_HI(_) TGD_HF(_)
#define     TGD_WS(_)             TGD_WI(_) TGD_WF(_)
#define     TGD_DS(_)             TGD_DI(_) TGD_DF(_)

#define     TGD_YR(_)   TGD_YU(_) TGD_YI(_) TGD_YF(_)
#define     TGD_BR(_)   TGD_BU(_) TGD_BI(_) TGD_BF(_)
#define     TGD_HR(_)   TGD_HU(_) TGD_HI(_) TGD_HF(_)
#define     TGD_WR(_)   TGD_WU(_) TGD_WI(_) TGD_WF(_)
#define     TGD_DR(_)   TGD_DU(_) TGD_DI(_) TGD_DF(_)

#define     TGD_YBU(_)  TGD_YU(_) TGD_BU(_)
#define     TGD_YHU(_)  TGD_YU(_) TGD_BU(_) TGD_HU(_)
#define     TGD_YWU(_)  TGD_YU(_) TGD_BU(_) TGD_HU(_) TGD_WU(_)
#define     TGD_YDU(_)  TGD_YU(_) TGD_BU(_) TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_BHU(_)            TGD_BU(_) TGD_HU(_)
#define     TGD_BWU(_)            TGD_BU(_) TGD_HU(_) TGD_WU(_)
#define     TGD_BDU(_)            TGD_BU(_) TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_HWU(_)                      TGD_HU(_) TGD_WU(_)
#define     TGD_HDU(_)                      TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_WDU(_)                                TGD_WU(_) TGD_DU(_)

#define     TGD_YBI(_)  TGD_YI(_) TGD_BI(_)
#define     TGD_YHI(_)  TGD_YI(_) TGD_BI(_) TGD_HI(_)
#define     TGD_YWI(_)  TGD_YI(_) TGD_BI(_) TGD_HI(_) TGD_WI(_)
#define     TGD_YDI(_)  TGD_YI(_) TGD_BI(_) TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_BHI(_)            TGD_BI(_) TGD_HI(_)
#define     TGD_BWI(_)            TGD_BI(_) TGD_HI(_) TGD_WI(_)
#define     TGD_BDI(_)            TGD_BI(_) TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_HWI(_)                      TGD_HI(_) TGD_WI(_)
#define     TGD_HDI(_)                      TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_WDI(_)                                TGD_WI(_) TGD_DI(_)

#define     TGD_YBF(_)  TGD_YF(_) TGD_BF(_)
#define     TGD_YHF(_)  TGD_YF(_) TGD_BF(_) TGD_HF(_)
#define     TGD_YWF(_)  TGD_YF(_) TGD_BF(_) TGD_HF(_) TGD_WF(_)
#define     TGD_YDF(_)  TGD_YF(_) TGD_BF(_) TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_BHF(_)            TGD_BF(_) TGD_HF(_)
#define     TGD_BWF(_)            TGD_BF(_) TGD_HF(_) TGD_WF(_)
#define     TGD_BDF(_)            TGD_BF(_) TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_HWF(_)                      TGD_HF(_) TGD_WF(_)
#define     TGD_HDF(_)                      TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_WDF(_)                                TGD_WF(_) TGD_DF(_)

#define     TGD_YBZ(_)  TGD_YZ(_) TGD_BZ(_)
#define     TGD_YHZ(_)  TGD_YZ(_) TGD_BZ(_) TGD_HZ(_)
#define     TGD_YWZ(_)  TGD_YZ(_) TGD_BZ(_) TGD_HZ(_) TGD_WZ(_)
#define     TGD_YDZ(_)  TGD_YZ(_) TGD_BZ(_) TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_BHZ(_)            TGD_BZ(_) TGD_HZ(_)
#define     TGD_BWZ(_)            TGD_BZ(_) TGD_HZ(_) TGD_WZ(_)
#define     TGD_BDZ(_)            TGD_BZ(_) TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_HWZ(_)                      TGD_HZ(_) TGD_WZ(_)
#define     TGD_HDZ(_)                      TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_WDZ(_)                                TGD_WZ(_) TGD_DZ(_)

#define     TGD_YBN(_)  TGD_YN(_) TGD_BN(_)
#define     TGD_YHN(_)  TGD_YN(_) TGD_BN(_) TGD_HN(_)
#define     TGD_YWN(_)  TGD_YN(_) TGD_BN(_) TGD_HN(_) TGD_WN(_)
#define     TGD_YDN(_)  TGD_YN(_) TGD_BN(_) TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_BHN(_)            TGD_BN(_) TGD_HN(_)
#define     TGD_BWN(_)            TGD_BN(_) TGD_HN(_) TGD_WN(_)
#define     TGD_BDN(_)            TGD_BN(_) TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_HWN(_)                      TGD_HN(_) TGD_WN(_)
#define     TGD_HDN(_)                      TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_WDN(_)                                TGD_WN(_) TGD_DN(_)

#define     TGD_YBS(_)  TGD_YS(_) TGD_BS(_)
#define     TGD_YHS(_)  TGD_YS(_) TGD_BS(_) TGD_HS(_)
#define     TGD_YWS(_)  TGD_YS(_) TGD_BS(_) TGD_HS(_) TGD_WS(_)
#define     TGD_YDS(_)  TGD_YS(_) TGD_BS(_) TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_BHS(_)            TGD_BS(_) TGD_HS(_)
#define     TGD_BWS(_)            TGD_BS(_) TGD_HS(_) TGD_WS(_)
#define     TGD_BDS(_)            TGD_BS(_) TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_HWS(_)                      TGD_HS(_) TGD_WS(_)
#define     TGD_HDS(_)                      TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_WDS(_)                                TGD_WS(_) TGD_DS(_)

#define     TGD_YBR(_)  TGD_YR(_) TGD_BR(_)
#define     TGD_YHR(_)  TGD_YR(_) TGD_BR(_) TGD_HR(_)
#define     TGD_YWR(_)  TGD_YR(_) TGD_BR(_) TGD_HR(_) TGD_WR(_)
#define     TGD_YDR(_)  TGD_YR(_) TGD_BR(_) TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_BHR(_)            TGD_BR(_) TGD_HR(_)
#define     TGD_BWR(_)            TGD_BR(_) TGD_HR(_) TGD_WR(_)
#define     TGD_BDR(_)            TGD_BR(_) TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_HWR(_)                      TGD_HR(_) TGD_WR(_)
#define     TGD_HDR(_)                      TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_WDR(_)                                TGD_WR(_) TGD_DR(_)

#if _LEAVE_UNGOP_TGD
}
#endif

#if _ENTER_UNGOP_TGQ
{
#endif

#ifndef     TGQ_NONE
#define     TGQ_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGQ_YU(_)   VQYU_TYPE:VQYU_SN(_),
#   define  TGQ_YI(_)
#   define  TGQ_YF(_)
#   if CHAR_MIN
#       define  TGQ_BU(_)   VQBU_TYPE:VQBU_SN(_),
#       define  TGQ_BI(_)   VQBI_TYPE:VQBI_SN(_), VQBC_TYPE:VQBC_SN(_),
#   else
#       define  TGQ_BU(_)   VQBU_TYPE:VQBU_SN(_), VQBC_TYPE:VQBC_SN(_),
#       define  TGQ_BI(_)   VQBI_TYPE:VQBI_SN(_),
#   endif

#   define  TGQ_BF(_)
#   define  TGQ_HU(_)   VQHU_TYPE:VQHU_SN(_),
#   define  TGQ_HI(_)   VQHI_TYPE:VQHI_SN(_),
#   define  TGQ_HF(_)   VQHF_TYPE:VQHF_SN(_),
#   define  TGQ_WU(_)   VQWU_TYPE:VQWU_SN(_),
#   define  TGQ_WI(_)   VQWI_TYPE:VQWI_SN(_),
#   define  TGQ_WF(_)   VQWF_TYPE:VQWF_SN(_),
#   define  TGQ_DU(_)   VQDU_TYPE:VQDU_SN(_),
#   define  TGQ_DI(_)   VQDI_TYPE:VQDI_SN(_),
#   define  TGQ_DF(_)   VQDF_TYPE:VQDF_SN(_),
#else
#   define  TGQ_YU(_) //VQYU_TYPE:VQYU_SN(_),
#   define  TGQ_YI(_)
#   define  TGQ_YF(_)
#   define  TGQ_BU(_) //VQBU_TYPE:VQBU_SN(_),
#   define  TGQ_BI(_) //VQBI_TYPE:VQBI_SN(_),
#   define  TGQ_BF(_)
#   define  TGQ_HU(_) //VQHU_TYPE:VQHU_SN(_),
#   define  TGQ_HI(_) //VQHI_TYPE:VQHI_SN(_),
#   define  TGQ_HF(_) //VQHF_TYPE:VQHF_SN(_),
#   define  TGQ_WU(_) //VQWU_TYPE:VQWU_SN(_),
#   define  TGQ_WI(_) //VQWI_TYPE:VQWI_SN(_),
#   define  TGQ_WF(_) //VQWF_TYPE:VQWF_SN(_),
#   define  TGQ_DU(_) //VQDU_TYPE:VQDU_SN(_),
#   define  TGQ_DI(_) //VQDI_TYPE:VQDI_SN(_),
#   define  TGQ_DF(_) //VQDF_TYPE:VQDF_SN(_),
#endif

#define     TGQ_YZ(_)   TGQ_YU(_) TGQ_YI(_)
#define     TGQ_BZ(_)   TGQ_BU(_) TGQ_BI(_)
#define     TGQ_HZ(_)   TGQ_HU(_) TGQ_HI(_)
#define     TGQ_WZ(_)   TGQ_WU(_) TGQ_WI(_)
#define     TGQ_DZ(_)   TGQ_DU(_) TGQ_DI(_)

#define     TGQ_YN(_)   TGQ_YU(_)           TGQ_YF(_)
#define     TGQ_BN(_)   TGQ_BU(_)           TGQ_BF(_)
#define     TGQ_HN(_)   TGQ_HU(_)           TGQ_HF(_)
#define     TGQ_WN(_)   TGQ_WU(_)           TGQ_WF(_)
#define     TGQ_DN(_)   TGQ_DU(_)           TGQ_DF(_)

#define     TGQ_YS(_)             TGQ_YI(_) TGQ_YF(_)
#define     TGQ_BS(_)             TGQ_BI(_) TGQ_BF(_)
#define     TGQ_HS(_)             TGQ_HI(_) TGQ_HF(_)
#define     TGQ_WS(_)             TGQ_WI(_) TGQ_WF(_)
#define     TGQ_DS(_)             TGQ_DI(_) TGQ_DF(_)

#define     TGQ_YR(_)   TGQ_YU(_) TGQ_YI(_) TGQ_YF(_)
#define     TGQ_BR(_)   TGQ_BU(_) TGQ_BI(_) TGQ_BF(_)
#define     TGQ_HR(_)   TGQ_HU(_) TGQ_HI(_) TGQ_HF(_)
#define     TGQ_WR(_)   TGQ_WU(_) TGQ_WI(_) TGQ_WF(_)
#define     TGQ_DR(_)   TGQ_DU(_) TGQ_DI(_) TGQ_DF(_)

#define     TGQ_YBU(_)  TGQ_YU(_) TGQ_BU(_)
#define     TGQ_YHU(_)  TGQ_YU(_) TGQ_BU(_) TGQ_HU(_)
#define     TGQ_YWU(_)  TGQ_YU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_)
#define     TGQ_YDU(_)  TGQ_YU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_BHU(_)            TGQ_BU(_) TGQ_HU(_)
#define     TGQ_BWU(_)            TGQ_BU(_) TGQ_HU(_) TGQ_WU(_)
#define     TGQ_BDU(_)            TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_HWU(_)                      TGQ_HU(_) TGQ_WU(_)
#define     TGQ_HDU(_)                      TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_WDU(_)                                TGQ_WU(_) TGQ_DU(_)

#define     TGQ_YBI(_)  TGQ_YI(_) TGQ_BI(_)
#define     TGQ_YHI(_)  TGQ_YI(_) TGQ_BI(_) TGQ_HI(_)
#define     TGQ_YWI(_)  TGQ_YI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_)
#define     TGQ_YDI(_)  TGQ_YI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_BHI(_)            TGQ_BI(_) TGQ_HI(_)
#define     TGQ_BWI(_)            TGQ_BI(_) TGQ_HI(_) TGQ_WI(_)
#define     TGQ_BDI(_)            TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_HWI(_)                      TGQ_HI(_) TGQ_WI(_)
#define     TGQ_HDI(_)                      TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_WDI(_)                                TGQ_WI(_) TGQ_DI(_)

#define     TGQ_YBF(_)  TGQ_YF(_) TGQ_BF(_)
#define     TGQ_YHF(_)  TGQ_YF(_) TGQ_BF(_) TGQ_HF(_)
#define     TGQ_YWF(_)  TGQ_YF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_)
#define     TGQ_YDF(_)  TGQ_YF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_BHF(_)            TGQ_BF(_) TGQ_HF(_)
#define     TGQ_BWF(_)            TGQ_BF(_) TGQ_HF(_) TGQ_WF(_)
#define     TGQ_BDF(_)            TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_HWF(_)                      TGQ_HF(_) TGQ_WF(_)
#define     TGQ_HDF(_)                      TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_WDF(_)                                TGQ_WF(_) TGQ_DF(_)

#define     TGQ_YBZ(_)  TGQ_YZ(_) TGQ_BZ(_)
#define     TGQ_YHZ(_)  TGQ_YZ(_) TGQ_BZ(_) TGQ_HZ(_)
#define     TGQ_YWZ(_)  TGQ_YZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_)
#define     TGQ_YDZ(_)  TGQ_YZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_BHZ(_)            TGQ_BZ(_) TGQ_HZ(_)
#define     TGQ_BWZ(_)            TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_)
#define     TGQ_BDZ(_)            TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_HWZ(_)                      TGQ_HZ(_) TGQ_WZ(_)
#define     TGQ_HDZ(_)                      TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_WDZ(_)                                TGQ_WZ(_) TGQ_DZ(_)

#define     TGQ_YBN(_)  TGQ_YN(_) TGQ_BN(_)
#define     TGQ_YHN(_)  TGQ_YN(_) TGQ_BN(_) TGQ_HN(_)
#define     TGQ_YWN(_)  TGQ_YN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_)
#define     TGQ_YDN(_)  TGQ_YN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_BHN(_)            TGQ_BN(_) TGQ_HN(_)
#define     TGQ_BWN(_)            TGQ_BN(_) TGQ_HN(_) TGQ_WN(_)
#define     TGQ_BDN(_)            TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_HWN(_)                      TGQ_HN(_) TGQ_WN(_)
#define     TGQ_HDN(_)                      TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_WDN(_)                                TGQ_WN(_) TGQ_DN(_)

#define     TGQ_YBS(_)  TGQ_YS(_) TGQ_BS(_)
#define     TGQ_YHS(_)  TGQ_YS(_) TGQ_BS(_) TGQ_HS(_)
#define     TGQ_YWS(_)  TGQ_YS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_)
#define     TGQ_YDS(_)  TGQ_YS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_BHS(_)            TGQ_BS(_) TGQ_HS(_)
#define     TGQ_BWS(_)            TGQ_BS(_) TGQ_HS(_) TGQ_WS(_)
#define     TGQ_BDS(_)            TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_HWS(_)                      TGQ_HS(_) TGQ_WS(_)
#define     TGQ_HDS(_)                      TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_WDS(_)                                TGQ_WS(_) TGQ_DS(_)

#define     TGQ_YBR(_)  TGQ_YR(_) TGQ_BR(_)
#define     TGQ_YHR(_)  TGQ_YR(_) TGQ_BR(_) TGQ_HR(_)
#define     TGQ_YWR(_)  TGQ_YR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_)
#define     TGQ_YDR(_)  TGQ_YR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_BHR(_)            TGQ_BR(_) TGQ_HR(_)
#define     TGQ_BWR(_)            TGQ_BR(_) TGQ_HR(_) TGQ_WR(_)
#define     TGQ_BDR(_)            TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_HWR(_)                      TGQ_HR(_) TGQ_WR(_)
#define     TGQ_HDR(_)                      TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_WDR(_)                                TGQ_WR(_) TGQ_DR(_)

#if _LEAVE_UNGOP_TGQ
}
#endif

#if _ENTER_UNGOP_TGO
{
#endif

#ifndef     TGO_NONE
#define     TGO_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGO_YU(_) VOYU_TYPE:VOYU_SN(_),
#   define  TGO_YI(_)
#   define  TGO_YF(_)
#   if CHAR_MIN
#       define  TGO_BU(_)   VOBU_TYPE:VOBU_SN(_),
#       define  TGO_BI(_)   VOBI_TYPE:VOBI_SN(_), VOBC_TYPE:VOBC_SN(_),
#   else
#       define  TGO_BU(_)   VOBU_TYPE:VOBU_SN(_), VOBC_TYPE:VOBC_SN(_),
#       define  TGO_BI(_)   VOBI_TYPE:VOBI_SN(_),
#   endif

#   define  TGO_BF(_)
#   define  TGO_HU(_)   VOHU_TYPE:VOHU_SN(_),
#   define  TGO_HI(_)   VOHI_TYPE:VOHI_SN(_),
#   define  TGO_HF(_)   VOHF_TYPE:VOHF_SN(_),
#   define  TGO_WU(_)   VOWU_TYPE:VOWU_SN(_),
#   define  TGO_WI(_)   VOWI_TYPE:VOWI_SN(_),
#   define  TGO_WF(_)   VOWF_TYPE:VOWF_SN(_),
#   define  TGO_DU(_)   VODU_TYPE:VODU_SN(_),
#   define  TGO_DI(_)   VODI_TYPE:VODI_SN(_),
#   define  TGO_DF(_)   VODF_TYPE:VODF_SN(_),
#else
#   define  TGO_YU(_) //VOYU_TYPE:VOYU_SN(_),
#   define  TGO_YI(_)
#   define  TGO_YF(_)
#   define  TGO_BU(_) //VOBU_TYPE:VOBU_SN(_),
#   define  TGO_BI(_) //VOBI_TYPE:VOBI_SN(_),
#   define  TGO_BF(_)
#   define  TGO_HU(_) //VOHU_TYPE:VOHU_SN(_),
#   define  TGO_HI(_) //VOHI_TYPE:VOHI_SN(_),
#   define  TGO_HF(_) //VOHF_TYPE:VOHF_SN(_),
#   define  TGO_WU(_) //VOWU_TYPE:VOWU_SN(_),
#   define  TGO_WI(_) //VOWI_TYPE:VOWI_SN(_),
#   define  TGO_WF(_) //VOWF_TYPE:VOWF_SN(_),
#   define  TGO_DU(_) //VODU_TYPE:VODU_SN(_),
#   define  TGO_DI(_) //VODI_TYPE:VODI_SN(_),
#   define  TGO_DF(_) //VODF_TYPE:VODF_SN(_),
#endif // #if MY_EXTVEC_H

#define     TGO_YZ(_)   TGO_YU(_) TGO_YI(_)
#define     TGO_BZ(_)   TGO_BU(_) TGO_BI(_)
#define     TGO_HZ(_)   TGO_HU(_) TGO_HI(_)
#define     TGO_WZ(_)   TGO_WU(_) TGO_WI(_)
#define     TGO_DZ(_)   TGO_DU(_) TGO_DI(_)

#define     TGO_YN(_)   TGO_YU(_)           TGO_YF(_)
#define     TGO_BN(_)   TGO_BU(_)           TGO_BF(_)
#define     TGO_HN(_)   TGO_HU(_)           TGO_HF(_)
#define     TGO_WN(_)   TGO_WU(_)           TGO_WF(_)
#define     TGO_DN(_)   TGO_DU(_)           TGO_DF(_)

#define     TGO_YS(_)             TGO_YI(_) TGO_YF(_)
#define     TGO_BS(_)             TGO_BI(_) TGO_BF(_)
#define     TGO_HS(_)             TGO_HI(_) TGO_HF(_)
#define     TGO_WS(_)             TGO_WI(_) TGO_WF(_)
#define     TGO_DS(_)             TGO_DI(_) TGO_DF(_)

#define     TGO_YR(_)   TGO_YU(_) TGO_YI(_) TGO_YF(_)
#define     TGO_BR(_)   TGO_BU(_) TGO_BI(_) TGO_BF(_)
#define     TGO_HR(_)   TGO_HU(_) TGO_HI(_) TGO_HF(_)
#define     TGO_WR(_)   TGO_WU(_) TGO_WI(_) TGO_WF(_)
#define     TGO_DR(_)   TGO_DU(_) TGO_DI(_) TGO_DF(_)

#define     TGO_YBU(_)  TGO_YU(_) TGO_BU(_)
#define     TGO_YHU(_)  TGO_YU(_) TGO_BU(_) TGO_HU(_)
#define     TGO_YWU(_)  TGO_YU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_)
#define     TGO_YDU(_)  TGO_YU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_BHU(_)            TGO_BU(_) TGO_HU(_)
#define     TGO_BWU(_)            TGO_BU(_) TGO_HU(_) TGO_WU(_)
#define     TGO_BDU(_)            TGO_BU(_) TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_HWU(_)                      TGO_HU(_) TGO_WU(_)
#define     TGO_HDU(_)                      TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_WDU(_)                                TGO_WU(_) TGO_DU(_)

#define     TGO_YBI(_)  TGO_YI(_) TGO_BI(_)
#define     TGO_YHI(_)  TGO_YI(_) TGO_BI(_) TGO_HI(_)
#define     TGO_YWI(_)  TGO_YI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_)
#define     TGO_YDI(_)  TGO_YI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_BHI(_)            TGO_BI(_) TGO_HI(_)
#define     TGO_BWI(_)            TGO_BI(_) TGO_HI(_) TGO_WI(_)
#define     TGO_BDI(_)            TGO_BI(_) TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_HWI(_)                      TGO_HI(_) TGO_WI(_)
#define     TGO_HDI(_)                      TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_WDI(_)                                TGO_WI(_) TGO_DI(_)

#define     TGO_YBF(_)  TGO_YF(_) TGO_BF(_)
#define     TGO_YHF(_)  TGO_YF(_) TGO_BF(_) TGO_HF(_)
#define     TGO_YWF(_)  TGO_YF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_)
#define     TGO_YDF(_)  TGO_YF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_BHF(_)            TGO_BF(_) TGO_HF(_)
#define     TGO_BWF(_)            TGO_BF(_) TGO_HF(_) TGO_WF(_)
#define     TGO_BDF(_)            TGO_BF(_) TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_HWF(_)                      TGO_HF(_) TGO_WF(_)
#define     TGO_HDF(_)                      TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_WDF(_)                                TGO_WF(_) TGO_DF(_)

#define     TGO_YBZ(_)  TGO_YZ(_) TGO_BZ(_)
#define     TGO_YHZ(_)  TGO_YZ(_) TGO_BZ(_) TGO_HZ(_)
#define     TGO_YWZ(_)  TGO_YZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_)
#define     TGO_YDZ(_)  TGO_YZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_BHZ(_)            TGO_BZ(_) TGO_HZ(_)
#define     TGO_BWZ(_)            TGO_BZ(_) TGO_HZ(_) TGO_WZ(_)
#define     TGO_BDZ(_)            TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_HWZ(_)                      TGO_HZ(_) TGO_WZ(_)
#define     TGO_HDZ(_)                      TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_WDZ(_)                                TGO_WZ(_) TGO_DZ(_)

#define     TGO_YBN(_)  TGO_YN(_) TGO_BN(_)
#define     TGO_YHN(_)  TGO_YN(_) TGO_BN(_) TGO_HN(_)
#define     TGO_YWN(_)  TGO_YN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_)
#define     TGO_YDN(_)  TGO_YN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_BHN(_)            TGO_BN(_) TGO_HN(_)
#define     TGO_BWN(_)            TGO_BN(_) TGO_HN(_) TGO_WN(_)
#define     TGO_BDN(_)            TGO_BN(_) TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_HWN(_)                      TGO_HN(_) TGO_WN(_)
#define     TGO_HDN(_)                      TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_WDN(_)                                TGO_WN(_) TGO_DN(_)

#define     TGO_YBS(_)  TGO_YS(_) TGO_BS(_)
#define     TGO_YHS(_)  TGO_YS(_) TGO_BS(_) TGO_HS(_)
#define     TGO_YWS(_)  TGO_YS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_)
#define     TGO_YDS(_)  TGO_YS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_BHS(_)            TGO_BS(_) TGO_HS(_)
#define     TGO_BWS(_)            TGO_BS(_) TGO_HS(_) TGO_WS(_)
#define     TGO_BDS(_)            TGO_BS(_) TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_HWS(_)                      TGO_HS(_) TGO_WS(_)
#define     TGO_HDS(_)                      TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_WDS(_)                                TGO_WS(_) TGO_DS(_)

#define     TGO_YBR(_)  TGO_YR(_) TGO_BR(_)
#define     TGO_YHR(_)  TGO_YR(_) TGO_BR(_) TGO_HR(_)
#define     TGO_YWR(_)  TGO_YR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_)
#define     TGO_YDR(_)  TGO_YR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_BHR(_)            TGO_BR(_) TGO_HR(_)
#define     TGO_BWR(_)            TGO_BR(_) TGO_HR(_) TGO_WR(_)
#define     TGO_BDR(_)            TGO_BR(_) TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_HWR(_)                      TGO_HR(_) TGO_WR(_)
#define     TGO_HDR(_)                      TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_WDR(_)                                TGO_WR(_) TGO_DR(_)

#if _LEAVE_UNGOP_TGO
}
#endif

#if _ENTER_UNGOP_TGS
{
#endif

#ifndef     TGS_NONE
#define     TGS_NONE(_)
#endif

#if MY_EXTVEC_H
#   define  TGS_YU(_)   VSYU_TYPE:VSYU_SN(_),
#   define  TGS_YI(_)
#   define  TGS_YF(_)
#   if CHAR_MIN
#       define  TGS_BU(_)   VSBU_TYPE:VSBU_SN(_),
#       define  TGS_BI(_)   VSBI_TYPE:VSBI_SN(_), VSBC_TYPE:VSBC_SN(_),
#   else
#       define  TGS_BU(_)   VSBU_TYPE:VSBU_SN(_), VSBC_TYPE:VSBC_SN(_),
#       define  TGS_BI(_)   VSBI_TYPE:VSBI_SN(_),
#   endif

#   define  TGS_BF(_)
#   define  TGS_HU(_)   VSHU_TYPE:VSHU_SN(_),
#   define  TGS_HI(_)   VSHI_TYPE:VSHI_SN(_),
#   define  TGS_HF(_)   VSHF_TYPE:VSHF_SN(_),
#   define  TGS_WU(_)   VSWU_TYPE:VSWU_SN(_),
#   define  TGS_WI(_)   VSWI_TYPE:VSWI_SN(_),
#   define  TGS_WF(_)   VSWF_TYPE:VSWF_SN(_),
#   define  TGS_DU(_)   VSDU_TYPE:VSDU_SN(_),
#   define  TGS_DI(_)   VSDI_TYPE:VSDI_SN(_),
#   define  TGS_DF(_)   VSDF_TYPE:VSDF_SN(_),
#else
#   define  TGS_YU(_) //VSYU_TYPE:VSYU_SN(_),
#   define  TGS_YI(_)
#   define  TGS_YF(_)
#   define  TGS_BU(_) //VSBU_TYPE:VSBU_SN(_),
#   define  TGS_BI(_) //VSBI_TYPE:VSBI_SN(_),
#   define  TGS_BF(_)
#   define  TGS_HU(_) //VSHU_TYPE:VSHU_SN(_),
#   define  TGS_HI(_) //VSHI_TYPE:VSHI_SN(_),
#   define  TGS_HF(_) //VSHF_TYPE:VSHF_SN(_),
#   define  TGS_WU(_) //VSWU_TYPE:VSWU_SN(_),
#   define  TGS_WI(_) //VSWI_TYPE:VSWI_SN(_),
#   define  TGS_WF(_) //VSWF_TYPE:VSWF_SN(_),
#   define  TGS_DU(_) //VSDU_TYPE:VSDU_SN(_),
#   define  TGS_DI(_) //VSDI_TYPE:VSDI_SN(_),
#   define  TGS_DF(_) //VSDF_TYPE:VSDF_SN(_),
#endif // #if MY_EXTVEC_H

#define     TGS_YZ(_)   TGS_YU(_) TGS_YI(_)
#define     TGS_BZ(_)   TGS_BU(_) TGS_BI(_)
#define     TGS_HZ(_)   TGS_HU(_) TGS_HI(_)
#define     TGS_WZ(_)   TGS_WU(_) TGS_WI(_)
#define     TGS_DZ(_)   TGS_DU(_) TGS_DI(_)

#define     TGS_YN(_)   TGS_YU(_)           TGS_YF(_)
#define     TGS_BN(_)   TGS_BU(_)           TGS_BF(_)
#define     TGS_HN(_)   TGS_HU(_)           TGS_HF(_)
#define     TGS_WN(_)   TGS_WU(_)           TGS_WF(_)
#define     TGS_DN(_)   TGS_DU(_)           TGS_DF(_)

#define     TGS_YS(_)             TGS_YI(_) TGS_YF(_)
#define     TGS_BS(_)             TGS_BI(_) TGS_BF(_)
#define     TGS_HS(_)             TGS_HI(_) TGS_HF(_)
#define     TGS_WS(_)             TGS_WI(_) TGS_WF(_)
#define     TGS_DS(_)             TGS_DI(_) TGS_DF(_)

#define     TGS_YR(_)   TGS_YU(_) TGS_YI(_) TGS_YF(_)
#define     TGS_BR(_)   TGS_BU(_) TGS_BI(_) TGS_BF(_)
#define     TGS_HR(_)   TGS_HU(_) TGS_HI(_) TGS_HF(_)
#define     TGS_WR(_)   TGS_WU(_) TGS_WI(_) TGS_WF(_)
#define     TGS_DR(_)   TGS_DU(_) TGS_DI(_) TGS_DF(_)

#define     TGS_YBU(_)  TGS_YU(_) TGS_BU(_)
#define     TGS_YHU(_)  TGS_YU(_) TGS_BU(_) TGS_HU(_)
#define     TGS_YWU(_)  TGS_YU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_)
#define     TGS_YDU(_)  TGS_YU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_BHU(_)            TGS_BU(_) TGS_HU(_)
#define     TGS_BWU(_)            TGS_BU(_) TGS_HU(_) TGS_WU(_)
#define     TGS_BDU(_)            TGS_BU(_) TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_HWU(_)                      TGS_HU(_) TGS_WU(_)
#define     TGS_HDU(_)                      TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_WDU(_)                                TGS_WU(_) TGS_DU(_)

#define     TGS_YBI(_)  TGS_YI(_) TGS_BI(_)
#define     TGS_YHI(_)  TGS_YI(_) TGS_BI(_) TGS_HI(_)
#define     TGS_YWI(_)  TGS_YI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_)
#define     TGS_YDI(_)  TGS_YI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_BHI(_)            TGS_BI(_) TGS_HI(_)
#define     TGS_BWI(_)            TGS_BI(_) TGS_HI(_) TGS_WI(_)
#define     TGS_BDI(_)            TGS_BI(_) TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_HWI(_)                      TGS_HI(_) TGS_WI(_)
#define     TGS_HDI(_)                      TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_WDI(_)                                TGS_WI(_) TGS_DI(_)

#define     TGS_YBF(_)  TGS_YF(_) TGS_BF(_)
#define     TGS_YHF(_)  TGS_YF(_) TGS_BF(_) TGS_HF(_)
#define     TGS_YWF(_)  TGS_YF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_)
#define     TGS_YDF(_)  TGS_YF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_BHF(_)            TGS_BF(_) TGS_HF(_)
#define     TGS_BWF(_)            TGS_BF(_) TGS_HF(_) TGS_WF(_)
#define     TGS_BDF(_)            TGS_BF(_) TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_HWF(_)                      TGS_HF(_) TGS_WF(_)
#define     TGS_HDF(_)                      TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_WDF(_)                                TGS_WF(_) TGS_DF(_)

#define     TGS_YBZ(_)  TGS_YZ(_) TGS_BZ(_)
#define     TGS_YHZ(_)  TGS_YZ(_) TGS_BZ(_) TGS_HZ(_)
#define     TGS_YWZ(_)  TGS_YZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_)
#define     TGS_YDZ(_)  TGS_YZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_BHZ(_)            TGS_BZ(_) TGS_HZ(_)
#define     TGS_BWZ(_)            TGS_BZ(_) TGS_HZ(_) TGS_WZ(_)
#define     TGS_BDZ(_)            TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_HWZ(_)                      TGS_HZ(_) TGS_WZ(_)
#define     TGS_HDZ(_)                      TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_WDZ(_)                                TGS_WZ(_) TGS_DZ(_)

#define     TGS_YBN(_)  TGS_YN(_) TGS_BN(_)
#define     TGS_YHN(_)  TGS_YN(_) TGS_BN(_) TGS_HN(_)
#define     TGS_YWN(_)  TGS_YN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_)
#define     TGS_YDN(_)  TGS_YN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_BHN(_)            TGS_BN(_) TGS_HN(_)
#define     TGS_BWN(_)            TGS_BN(_) TGS_HN(_) TGS_WN(_)
#define     TGS_BDN(_)            TGS_BN(_) TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_HWN(_)                      TGS_HN(_) TGS_WN(_)
#define     TGS_HDN(_)                      TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_WDN(_)                                TGS_WN(_) TGS_DN(_)

#define     TGS_YBS(_)  TGS_YS(_) TGS_BS(_)
#define     TGS_YHS(_)  TGS_YS(_) TGS_BS(_) TGS_HS(_)
#define     TGS_YWS(_)  TGS_YS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_)
#define     TGS_YDS(_)  TGS_YS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_BHS(_)            TGS_BS(_) TGS_HS(_)
#define     TGS_BWS(_)            TGS_BS(_) TGS_HS(_) TGS_WS(_)
#define     TGS_BDS(_)            TGS_BS(_) TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_HWS(_)                      TGS_HS(_) TGS_WS(_)
#define     TGS_HDS(_)                      TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_WDS(_)                                TGS_WS(_) TGS_DS(_)

#define     TGS_YBR(_)  TGS_YR(_) TGS_BR(_)
#define     TGS_YHR(_)  TGS_YR(_) TGS_BR(_) TGS_HR(_)
#define     TGS_YWR(_)  TGS_YR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_)
#define     TGS_YDR(_)  TGS_YR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_BHR(_)            TGS_BR(_) TGS_HR(_)
#define     TGS_BWR(_)            TGS_BR(_) TGS_HR(_) TGS_WR(_)
#define     TGS_BDR(_)            TGS_BR(_) TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_HWR(_)                      TGS_HR(_) TGS_WR(_)
#define     TGS_HDR(_)                      TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_WDR(_)                                TGS_WR(_) TGS_DR(_)

#if _LEAVE_UNGOP_TGS
}
#endif

#define TGK_ID(T) T
#define TGK_AK(T) T *
#define TGK_AC(T) T const *

#define FUNCOF(_, X, K, W, D, Q, O, S, ...) \
_Generic(   \
    (X),            \
    TGK_##K(TGK_ID,_)   \
    TGW_##W(_)      \
    TGD_##D(_)  \
    TGQ_##Q(_)  \
    TGO_##O(_)  \
    TGS_##S(_)  \
    __VA_ARGS__ \
)

#define FUNCOF_AC(_, X, K, P, W, D, Q, O, S, ...) \
_Generic(   \
    (X),        \
    TGK_##K(TGK_ID,_)   \
    TGK_##P(TGK_AC,_##ac)   \
    TGK_##P(TGK_AK,_##ac)   \
    TGW_##W(_)          \
    TGD_##D(_)      \
    TGQ_##Q(_)  \
    TGO_##O(_)  \
    TGS_##S(_)  \
    __VA_ARGS__ \
)

#define FUNCOF_AK(_, X, K, P, W, D, Q, O, S, ...) _Generic(\
    (X),        \
    TGK_##K(TGK_ID, _)  \
    TGK_##P(TGK_AK,_##a)  \
    TGW_##W(_)  \
    TGD_##D(_)  \
    TGQ_##Q(_)  \
    TGO_##O(_)  \
    TGS_##S(_)  \
    __VA_ARGS__ \
)

#endif // EOF("extgop.h")

#if _LEAVE_UNGOP
}
#endif

#define       ADDR_VOID         ((void *) 0)
#define       BOOL_VOID          ((_Bool) 0)
#define      UCHAR_VOID  ((unsigned char) 0)
#define      SCHAR_VOID    ((signed char) 0)
#define       CHAR_VOID           ((char) 0)
#define      USHRT_VOID ((unsigned short) 0)
#define       SHRT_VOID          ((short) 0)
#define       UINT_VOID                  (0u)
#define        INT_VOID                  (0)
#define      ULONG_VOID                  (0ul)
#define     ULLONG_VOID                  (0ull)
#define      LLONG_VOID                  (0ll)
#define        FLT_VOID                  (0.0f)
#define        DBL_VOID                  (0.0)

#define    CHAR_ASTG(K)     (   (CHAR_STG(TYPE)){.C=(K)})
#define   UCHAR_ASTG(K)     (  (UCHAR_STG(TYPE)){.U=(K)})
#define   SCHAR_ASTG(K)     (  (SCHAR_STG(TYPE)){.I=(K)})
#define   USHRT_ASTG(K)     (  (USHRT_STG(TYPE)){.U=(K)})
#define    SHRT_ASTG(K)     (   (SHRT_STG(TYPE)){.I=(K)})
#define   FLT16_ASTG(K)     (  (FLT16_STG(TYPE)){.F=(K)})
#define    UINT_ASTG(K)     (   (UINT_STG(TYPE)){.U=(K)})
#define     INT_ASTG(K)     (    (INT_STG(TYPE)){.I=(K)})
#define     FLT_ASTG(K)     (    (FLT_STG(TYPE)){.F=(K)})
#define   ULONG_ASTG(K)     (  (ULONG_STG(TYPE)){.U=(K)})
#define    LONG_ASTG(K)     (   (LONG_STG(TYPE)){.I=(K)})
#define  ULLONG_ASTG(K)     ( (ULLONG_STG(TYPE)){.U=(K)})
#define   LLONG_ASTG(K)     (  (LLONG_STG(TYPE)){.I=(K)})
#define     DBL_ASTG(K)     (    (DBL_STG(TYPE)){.F=(K)})
#define    SIZE_ASTG(K)     (   (SIZE_STG(TYPE)){.U=(K)})
#define  INTPTR_ASTG(K)     ( (INTPTR_STG(TYPE)){.I=(K)})
#define UINTPTR_ASTG(K)     ((UINTPTR_STG(TYPE)){.U=(K)})
#define PTRDIFF_ASTG(K)     ((PTRDIFF_STG(TYPE)){.I=(K)})

INLINE(   _Bool,  BOOL_ASYU)   (_Bool x)
{
#define     BOOL_ASYU(X)   ((_Bool) X)
#define     BOOL_ASTU       BOOL_ASYU
    return  x;
}


INLINE( uint8_t, UCHAR_ASBU)   (uchar x) {return x;}
INLINE( uint8_t, SCHAR_ASBU)   (schar x) {return x;}
INLINE( uint8_t,  CHAR_ASBU)    (char x) {return x;}
#define     UCHAR_ASTU      UCHAR_ASBU
#define     SCHAR_ASTU      SCHAR_ASBU
#define      CHAR_ASTU       CHAR_ASBU
#define     UCHAR_ASTI      UCHAR_ASBI
#define     SCHAR_ASTI      SCHAR_ASBI
#define      CHAR_ASTI       CHAR_ASBI

INLINE(  int8_t, UCHAR_ASBI)   (uchar x) {return x;}
INLINE(  int8_t, SCHAR_ASBI)   (schar x) {return x;}
INLINE(  int8_t,  CHAR_ASBI)    (char x) {return x;}

INLINE(    char, UCHAR_ASBC)   (uchar x) {return x;}
INLINE(    char, SCHAR_ASBC)   (schar x) {return x;}
INLINE(    char,  CHAR_ASBC)    (char x) {return x;}


INLINE(uint16_t, USHRT_ASHU)  (ushort x) {return x;}
INLINE(uint16_t,  SHRT_ASHU)   (short x) {return x;}
#define     USHRT_ASTU      USHRT_ASHU
#define     SHRT_ASTU       SHRT_ASHU

INLINE(uint16_t, FLT16_ASHU) (flt16_t x)
{
#define     FLT16_ASHU(X)   (FLT16_ASTG(X).U)
#define     FLT16_ASTU      FLT16_ASHU
    return  FLT16_ASHU(x);
}


INLINE( int16_t, USHRT_ASHI)  (ushort x) {return x;}
INLINE( int16_t,  SHRT_ASHI)   (short x) {return x;}
#define     USHRT_ASTI      USHRT_ASHI
#define     SHRT_ASTI       SHRT_ASHI

INLINE( int16_t, FLT16_ASHI) (flt16_t x)
{
#define     FLT16_ASHI(X)   (FLT16_ASTG(X).I)
#define     FLT16_ASTI      FLT16_ASHI
    return  FLT16_ASTI(x);
}


INLINE(uint32_t,  UINT_ASWU)    (uint x)
{
#define     UINT_ASWU(X)    (UINT_ASTG(X).U)
#define     UINT_ASTU       UINT_ASWU
    return  x;
}

INLINE(uint32_t,   INT_ASWU)     (int x)
{
#define     INT_ASWU(X)     (INT_ASTG(X).U)
#define     INT_ASTU        INT_ASWU
    return  x;
}

#if DWRD_NLONG == 2

INLINE(uint32_t, ULONG_ASWU)   (ulong x)
{
#   define  ULONG_ASWU(X)   (ULONG_ASTG(X).U)
#   define  ULONG_ASTU      ULONG_ASWU
    return  x;
}

INLINE(uint32_t,  LONG_ASWU)    (long x)
{
#   define  LONG_ASWU(X)    (LONG_ASTG(X).U)
#   define  LONG_ASTU       LONG_ASWU
    return  LONG_ASWU(x);
}

#endif

INLINE(uint32_t,   FLT_ASWU)   (float x)
{
#define     FLT_ASWU(X)     (FLT_ASTG(X).U)
#define     FLT_ASTU        FLT_ASWU
    return  FLT_ASWU(x);
}


INLINE( int32_t,  UINT_ASWI)    (uint x)
{
#define     UINT_ASWI(X)    (UINT_ASTG(X).I)
#define     UINT_ASTI       UINT_ASWI
    return  UINT_ASWI(x);
}

INLINE( int32_t,   INT_ASWI)     (int x)
{
#define     INT_ASWI(X)     (INT_ASTG(X).I)
#define     INT_ASTI        INT_ASWI
    return  x;
}

#if DWRD_NLONG == 2

INLINE( int32_t, ULONG_ASWI)   (ulong x)
{
#   define  ULONG_ASWI(X)   ULONG_ASTG(X).I
#   define  ULONG_ASTI      ULONG_ASWI
    return  ULONG_ASWI(x);
}

INLINE( int32_t,  LONG_ASWI)    (long x)
{
#   define  LONG_ASWI(X)    (LONG_ASTG(X).I)
#   define  LONG_ASTI       LONG_ASWI
    return  x;
}

#endif

INLINE( int32_t,   FLT_ASWI)   (float x)
{
#define     FLT_ASWI(X)     (FLT_ASTG(X).I)
#define     FLT_ASTI        FLT_ASWI
    return  FLT_ASWI(x);
}


#if DWRD_NLONG == 1

INLINE(uint64_t, ULONG_ASDU)   (ulong x)
{
#   define  ULONG_ASDU(X)   (ULONG_ASTG(X).U)
#   define  ULONG_ASTU      ULONG_ASDU
    return  x;
}

INLINE(uint64_t,  LONG_ASDU)    (long x)
{
#   define  LONG_ASDU(X)    (LONG_ASTG(X).U)
#   define  LONG_ASTU       LONG_ASDU
    return  x;
}

#endif


#if QUAD_NLLONG == 2

INLINE(uint64_t,ULLONG_ASDU) (ullong x)
{
#   define  ULLONG_ASDU(X)   (ULLONG_ASTG(X).U)
#   define  ULLONG_ASTU      ULLONG_ASDU
    return  x;
}

INLINE(uint64_t, LLONG_ASDU)  (llong x)
{
#   define  LLONG_ASDU(X)   (LLONG_ASTG(X).U)
#   define  LLONG_ASTU      LLONG_ASDU
    return  x;
}

#else

INLINE(ullong,ULLONG_ASQU) (ullong x) {return x;}
INLINE(ullong, LLONG_ASQU)  (llong x) {return x;}

#endif

INLINE(uint64_t,   DBL_ASDU) (double x)
{
#define     DBL_ASDU(X)     (DBL_ASTG(X).U)
#define     DBL_ASTU        DBL_ASDU
    return  DBL_ASDU(x);
}


#if DWRD_NLONG == 1

INLINE( int64_t, ULONG_ASDI)  (ulong x)
{
#   define  ULONG_ASDI(X)   (ULONG_ASTG(X).I)
#   define  ULONG_ASTI      ULONG_ASDI
    return  ULONG_ASDI(x);
}

INLINE( int64_t,  LONG_ASDI)   (long x)
{
#   define  LONG_ASDI(X)    (LONG_ASTG(X).I)
#   define  LONG_ASTI       LONG_ASDI
    return  x;
}
#endif


#if QUAD_NLLONG == 2

INLINE( int64_t,ULLONG_ASDI) (ullong x)
{
#   define  ULLONG_ASDI(X)  (ULLONG_ASTG(X).I)
#   define  ULLONG_ASTI     ULLONG_ASDI
    return  ULLONG_ASDI(x);
}

INLINE( int64_t, LLONG_ASDI) (llong x)
{
#   define  LLONG_ASDI(X)   (LLONG_ASTG(X).I)
#   define  LLONG_ASTI      LLONG_ASDI
    return  x;
}

#endif

INLINE(int64_t,DBL_ASDI) (double x)
{
#define     DBL_ASDI(X)     (DBL_ASTG(X).I)
#define     DBL_ASTI        DBL_ASDI
    return  DBL_ASDI(x);
}


#if QUAD_NLLONG == 1

INLINE(  ullong,ULLONG_ASQU) (ullong x)
{
#   define  ULLONG_ASQU(X)   (ULLONG_ASTG(X).U)
#   define  ULLONG_ASTU      ULLONG_ASQU
    return  x;
}

INLINE(  ullong, LLONG_ASQU) (llong x)
{
#   define  LLONG_ASQU(X)   (LLONG_ASTG(X).U)
#   define  LLONG_ASTU      LLONG_ASQU
    return  x;
}

INLINE(  ullong,  LDBL_ASQU) (long double x)
{
#   define  LDBL_ASQU(X)    (LDBL_ASTG(X).U)
#   define  LDBL_ASTU       LDBL_ASQU
    return  LDBL_ASQU(x);
}


INLINE(   llong,ULLONG_ASQI) (ullong x)
{
#   define  ULLONG_ASQI(X)  (ULLONG_ASTG(X).I)
#   define  ULLONG_ASTI     ULLONG_ASQI
    return  ULLONG_ASQI(x);
}

INLINE(   llong, LLONG_ASQI)  (llong x)
{
#   define  LLONG_ASQI(X)   (LLONG_ASTG(X).I)
#   define  LLONG_ASTI      LLONG_ASQI
    return  LLONG_ASQI(x);
}

INLINE(   llong,  LDBL_ASQI) (long double x)
{
#   define  LDBL_ASQI(X)    (LDBL_ASTG(X).I)
#   define  LDBL_ASTI       LDBL_ASQU
    return  LDBL_ASQI(x);
}

#endif

#define  INTPTR_ASTU     INTPTR_BASE(ASTU)
#define PTRDIFF_ASTU    PTRDIFF_BASE(ASTU)
#define    SIZE_ASTI       SIZE_BASE(ASTI)
#define UINTPTR_ASTI    UINTPTR_BASE(ASTI)


INLINE(flt16_t,USHRT_ASHF)  (ushort x)
{
#define     USHRT_ASHF(X)   (USHRT_ASTG(X).F)
#define     USHRT_ASTF      USHRT_ASHF
    return  USHRT_ASHF(x);
}

INLINE(flt16_t, SHRT_ASHF)   (short x)
{
#define     SHRT_ASHF(X)    (SHRT_ASTG(X).F)
#define     SHRT_ASTF       SHRT_ASHF
    return  SHRT_ASHF(x);
}

INLINE(flt16_t,FLT16_ASHF) (flt16_t x)
{
#define     FLT16_ASHF(X)   (FLT16_ASTG(X).F)
#define     FLT16_ASTF      FLT16_ASHF
    return  x;
}


INLINE(float,   UINT_ASWF)    (uint x)
{
#define     UINT_ASWF(X)    (UINT_ASTG(X).F)
#define     UINT_ASTF       UINT_ASWF
    return  UINT_ASWF(x);
}

INLINE(float,    INT_ASWF)     (int x)
{
#define     INT_ASWF(X)    (INT_ASTG(X).F)
#define     INT_ASTF       INT_ASWF
    return  INT_ASWF(x);
}

INLINE(float,    FLT_ASWF)   (float x)
{
#define     FLT_ASWF(X)   (FLT_ASTG(X).F)
#define     FLT_ASTF      FLT_ASWF
    return  x;
}


#if DWRD_NLONG == 2
INLINE(float,   ULONG_ASWF)  (ulong x)
{
#define     ULONG_ASWF(X)   (ULONG_ASTG(X).F)
#define     ULONG_ASTF      ULONG_ASWF
    return  ULONG_ASWF(x);
}

INLINE(float,    LONG_ASWF)   (long x)
{
#define     LONG_ASWF(X)   (LONG_ASTG(X).F)
#define     LONG_ASTF      LONG_ASWF
    return  LONG_ASWF(x);
}

#endif


#if DWRD_NLONG == 1

INLINE(double,  ULONG_ASDF)  (ulong x)
{
#define     ULONG_ASDF(X)   (ULONG_ASTG(X).F)
#define     ULONG_ASTF      ULONG_ASDF
    return  ULONG_ASDF(x);
}

INLINE(double,   LONG_ASDF)   (long x)
{
#define     LONG_ASDF(X)    (LONG_ASTG(X).F)
#define     LONG_ASTF       LONG_ASDF
    return  LONG_ASDF(x);
}
#endif

#if QUAD_NLLONG == 2

INLINE(double, ULLONG_ASDF) (ullong x)
{
#define     ULLONG_ASDF(X)  (ULLONG_ASTG(X).F)
#define     ULLONG_ASTF     ULLONG_ASDF
    return  ULLONG_ASDF(x);
}

INLINE(double,  LLONG_ASDF)  (llong x)
{
#define     LLONG_ASDF(X)   (LLONG_ASTG(X).F)
#define     LLONG_ASTF      LLONG_ASDF
    return  LLONG_ASTF(x);
}

#endif

INLINE(double,   DBL_ASDF)  (double x)
{
#define     DBL_ASDF(X)   (DBL_ASTG(X).F)
#define     DBL_ASTF      DBL_ASDF
    return  x;
}


#if QUAD_NLLONG == 1

INLINE(flt128_t,ULLONG_ASQF) (ullong x)
{
#   define  ULLONG_ASQF(X)  (ULLONG_ASTG(X).F)
#   define  ULLONG_ASTF     ULLONG_ASQF
    return  ULLONG_ASQF(x);
}

INLINE(flt128_t, LLONG_ASQF) (llong x)
{
#   define  LLONG_ASQI(X)   (LLONG_ASTG(X).F)
#   define  LLONG_ASTF      LLONG_ASQF
    return  LLONG_ASQF(x);
}

INLINE(flt128_t,  LDBL_ASQF) (long double x)
{
#   define  LDBL_ASQF(X)    (LDBL_ASTG(X).F)
#   define  LDBL_ASTF       LDBL_ASQF
}

#endif

#define        SIZE_ASTF       SIZE_BASE(ASTF)
#define      INTPTR_ASTF     INTPTR_BASE(ASTF)
#define     UINTPTR_ASTF    UINTPTR_BASE(ASTF)
#define     PTRDIFF_ASTF    PTRDIFF_BASE(ASTF)

#define     UINT8_ADDL      UINT8_BASE(ADDL)
#define     UINT8_ADD2      UINT8_BASE(ADD2)
#define     UINT8_ADDS      UINT8_BASE(ADDS)
#define     UINT8_ADDH      UINT8_BASE(ADDH)
#define     UINT8_ADDW      UINT8_BASE(ADDW)
#define     UINT8_ADDD      UINT8_BASE(ADDD)
#define     UINT8_ADDQ      UINT8_BASE(ADDQ)
#define     UINT8_ADD1A     UINT8_BASE(ADD1A)
#define     UINT8_ADDAA     UINT8_BASE(ADDAA)
#define     UINT8_ADDEA     UINT8_BASE(ADDEA)
#define     UINT8_ADDTA     UINT8_BASE(ADDTA)

#define     UINT8_AND1A     UINT8_BASE(AND1A)
#define     UINT8_ANDAA     UINT8_BASE(ANDAA)
#define     UINT8_ANDEA     UINT8_BASE(ANDEA)
#define     UINT8_ANDN      UINT8_BASE(ANDN)
#define     UINT8_ANDS      UINT8_BASE(ANDS)
#define     UINT8_ANDTA     UINT8_BASE(ANDTA)

#define     UINT8_ASBC      UINT8_BASE(ASBC)
#define     UINT8_ASBI      UINT8_BASE(ASBI)
#define     UINT8_ASBU      UINT8_BASE(ASBU)
#define     UINT8_ASTI      UINT8_BASE(ASTI)
#define     UINT8_ASTU      UINT8_BASE(ASTU)

#define     UINT8_AVGL      UINT8_BASE(AVGL)

#define     UINT8_BFG1      UINT8_BASE(BFG1)

#define     UINT8_BFS1      UINT8_BASE(BFS1)

#define     UINT8_BFC1      UINT8_BASE(BFC1)

#define     UINT8_CATL      UINT8_BASE(CATL)

#define     UINT8_CBNS      UINT8_BASE(CBNS)
#define     UINT8_CBNY      UINT8_BASE(CBNY)

#define     UINT8_CEQS      UINT8_BASE(CEQS)
#define     UINT8_CEQY      UINT8_BASE(CEQY)

#define     UINT8_CGES      UINT8_BASE(CGES)
#define     UINT8_CGEY      UINT8_BASE(CGEY)

#define     UINT8_CGTS      UINT8_BASE(CGTS)
#define     UINT8_CGTY      UINT8_BASE(CGTY)

#define     UINT8_CLES      UINT8_BASE(CLES)
#define     UINT8_CLEY      UINT8_BASE(CLEY)

#define     UINT8_CLTS      UINT8_BASE(CLTS)
#define     UINT8_CLTY      UINT8_BASE(CLTY)

#define     UINT8_CNBS      UINT8_BASE(CNBS)
#define     UINT8_CNBY      UINT8_BASE(CNBY)

#define     UINT8_CNES      UINT8_BASE(CNES)
#define     UINT8_CNEY      UINT8_BASE(CNEY)

#define     UINT8_CNT0      UINT8_BASE(CNT0)
#define     UINT8_CNT1      UINT8_BASE(CNT1)
#define     UINT8_CNTS      UINT8_BASE(CNTS)

#define     UINT8_CSZL      UINT8_BASE(CSZL)
#define     UINT8_CSZR      UINT8_BASE(CSZR)

#define     UINT8_CVBC      UINT8_BASE(CVBC)
#define     UINT8_CVBI      UINT8_BASE(CVBI)
#define     UINT8_CVBS      UINT8_BASE(CVBS)
#define     UINT8_CVBU      UINT8_BASE(CVBU)
#define     UINT8_CVBZ      UINT8_BASE(CVBZ)

#define     UINT8_CVDF      UINT8_BASE(CVDF)
#define     UINT8_CVDI      UINT8_BASE(CVDI)
#define     UINT8_CVDS      UINT8_BASE(CVDS)
#define     UINT8_CVDU      UINT8_BASE(CVDU)
#define     UINT8_CVDZ      UINT8_BASE(CVDZ)

#define     UINT8_CVHF      UINT8_BASE(CVHF)
#define     UINT8_CVHI      UINT8_BASE(CVHI)
#define     UINT8_CVHS      UINT8_BASE(CVHS)
#define     UINT8_CVHU      UINT8_BASE(CVHU)
#define     UINT8_CVHZ      UINT8_BASE(CVHZ)

#define     UINT8_CVWF      UINT8_BASE(CVWF)
#define     UINT8_CVWI      UINT8_BASE(CVWI)
#define     UINT8_CVWS      UINT8_BASE(CVWS)
#define     UINT8_CVWU      UINT8_BASE(CVWU)
#define     UINT8_CVWZ      UINT8_BASE(CVWZ)

#define     UINT8_DIFU      UINT8_BASE(DIFU)
#define     UINT8_DIFS      UINT8_BASE(DIFS)

#define     UINT8_DIVL      UINT8_BASE(DIVL)
#define     UINT8_DIV2      UINT8_BASE(DIV2)
#define     UINT8_DIVH      UINT8_BASE(DIVH)
#define     UINT8_DIVW      UINT8_BASE(DIVW)
#define     UINT8_DIVD      UINT8_BASE(DIVD)
#define     UINT8_DIVQ      UINT8_BASE(DIVQ)

#define     UINT8_DCRL      UINT8_BASE(DCRL)
#define     UINT8_DCR1A     UINT8_BASE(DCR1A)
#define     UINT8_DCRAA     UINT8_BASE(DCRAA)
#define     UINT8_DCREA     UINT8_BASE(DCREA)
#define     UINT8_DCRTA     UINT8_BASE(DCRTA)

#define     UINT8_DUPD      UINT8_BASE(DUPD)
#define     UINT8_DUPDAC    UINT8_BASE(DUPDAC)
#define     UINT8_DUPO      UINT8_BASE(DUPO)
#define     UINT8_DUPOAC    UINT8_BASE(DUPOAC)
#define     UINT8_DUPQ      UINT8_BASE(DUPQ)
#define     UINT8_DUPQAC    UINT8_BASE(DUPQAC)
#define     UINT8_DUPS      UINT8_BASE(DUPS)
#define     UINT8_DUPSAC    UINT8_BASE(DUPSAC)
#define     UINT8_DUPW      UINT8_BASE(DUPW)
#define     UINT8_DUPWAC    UINT8_BASE(DUPWAC)

#define     UINT8_ICRL      UINT8_BASE(ICRL)
#define     UINT8_ICR1A     UINT8_BASE(ICR1A)
#define     UINT8_ICRAA     UINT8_BASE(ICRAA)
#define     UINT8_ICREA     UINT8_BASE(ICREA)
#define     UINT8_ICRTA     UINT8_BASE(ICRTA)

#define     UINT8_INVS      UINT8_BASE(INVS)
#define     UINT8_INV1A     UINT8_BASE(INV1A)
#define     UINT8_INVAA     UINT8_BASE(INVAA)
#define     UINT8_INVEA     UINT8_BASE(INVEA)
#define     UINT8_INVTA     UINT8_BASE(INVTA)

#define     UINT8_LDR1AC    UINT8_BASE(LDR1AC)
#define     UINT8_LDRAAC    UINT8_BASE(LDRAAC)
#define     UINT8_LDRDAC    UINT8_BASE(LDRDAC)
#define     UINT8_LDROAC    UINT8_BASE(LDROAC)
#define     UINT8_LDRQAC    UINT8_BASE(LDRQAC)
#define     UINT8_LDRSAC    UINT8_BASE(LDRSAC)
#define     UINT8_LDRTAC    UINT8_BASE(LDRTAC)
#define     UINT8_LDRWAC    UINT8_BASE(LDRWAC)

#define     UINT8_LUNNAC    UINT8_BASE(LUNNAC)
#define     UINT8_LUNLAC    UINT8_BASE(LUNLAC)
#define     UINT8_LUNRAC    UINT8_BASE(LUNRAC)
#define     UINT8_LUNWAC    UINT8_BASE(LUNWAC)
#define     UINT8_LUNDAC    UINT8_BASE(LUNDAC)
#define     UINT8_LUNQAC    UINT8_BASE(LUNQAC)
#define     UINT8_LUNOAC    UINT8_BASE(LUNOAC)
#define     UINT8_LUNSAC    UINT8_BASE(LUNSAC)

#define     UINT8_FAM2      UINT8_BASE(FAM2)
#define     UINT8_FAML      UINT8_BASE(FAML)
#define     UINT8_FAMS      UINT8_BASE(FAMS)

#define     UINT8_MAXL      UINT8_BASE(MAXL)

#define     UINT8_MINL      UINT8_BASE(MINL)

#define     UINT8_MODL      UINT8_BASE(MODL)
#define     UINT8_MOD2      UINT8_BASE(MOD2)
#define     UINT8_MODH      UINT8_BASE(MODH)
#define     UINT8_MODW      UINT8_BASE(MODW)
#define     UINT8_MODD      UINT8_BASE(MODD)
#define     UINT8_MODQ      UINT8_BASE(MODQ)

#define     UINT8_MUL2      UINT8_BASE(MUL2)
#define     UINT8_MULL      UINT8_BASE(MULL)
#define     UINT8_MULS      UINT8_BASE(MULS)
#define     UINT8_MULH      UINT8_BASE(MULH)
#define     UINT8_MULW      UINT8_BASE(MULW)
#define     UINT8_MULD      UINT8_BASE(MULD)
#define     UINT8_MULQ      UINT8_BASE(MULQ)

#define     UINT8_NEGL      UINT8_BASE(NEGL)
#define     UINT8_NEGS      UINT8_BASE(NEGS)
#define     UINT8_NEGH      UINT8_BASE(NEGH)
#define     UINT8_NEGW      UINT8_BASE(NEGW)
#define     UINT8_NEGD      UINT8_BASE(NEGD)
#define     UINT8_NEGQ      UINT8_BASE(NEGQ)

#define     UINT8_ORR1A     UINT8_BASE(ORR1A)
#define     UINT8_ORRAA     UINT8_BASE(ORRAA)
#define     UINT8_ORREA     UINT8_BASE(ORREA)
#define     UINT8_ORRN      UINT8_BASE(ORRN)
#define     UINT8_ORRS      UINT8_BASE(ORRS)
#define     UINT8_ORRTA     UINT8_BASE(ORRTA)

#define     UINT8_REVY      UINT8_BASE(REVY)

#define     UINT8_ROTL      UINT8_BASE(ROTL)
#define     UINT8_ROTR      UINT8_BASE(ROTR)

#define     UINT8_SEQW      UINT8_BASE(SEQW)
#define     UINT8_SEQD      UINT8_BASE(SEQD)
#define     UINT8_SEQQ      UINT8_BASE(SEQQ)

#define     UINT8_SHL2      UINT8_BASE(SHL2)
#define     UINT8_SHLL      UINT8_BASE(SHLL)
#define     UINT8_SHLR      UINT8_BASE(SHLR)
#define     UINT8_SHLS      UINT8_BASE(SHLS)

#define     UINT8_SHRS      UINT8_BASE(SHRS)

#define     UINT8_SILL      UINT8_BASE(SILL)
#define     UINT8_SILR      UINT8_BASE(SILR)

#define     UINT8_SIRL      UINT8_BASE(SIRL)
#define     UINT8_SIRR      UINT8_BASE(SIRR)

#define     UINT8_STR1A     UINT8_BASE(STR1A)
#define     UINT8_STRDA     UINT8_BASE(STRDA)
#define     UINT8_STREA     UINT8_BASE(STREA)
#define     UINT8_STRQA     UINT8_BASE(STRQA)
#define     UINT8_STRTA     UINT8_BASE(STRTA)
#define     UINT8_STRWA     UINT8_BASE(STRWA)

#define     UINT8_SUB2      UINT8_BASE(SUB2)
#define     UINT8_SUBS      UINT8_BASE(SUBS)
#define     UINT8_SUBH      UINT8_BASE(SUBH)
#define     UINT8_SUBW      UINT8_BASE(SUBW)
#define     UINT8_SUBD      UINT8_BASE(SUBD)
#define     UINT8_SUBQ      UINT8_BASE(SUBQ)
#define     UINT8_SUB1A     UINT8_BASE(SUB1A)
#define     UINT8_SUBAA     UINT8_BASE(SUBAA)
#define     UINT8_SUBEA     UINT8_BASE(SUBEA)
#define     UINT8_SUBTA     UINT8_BASE(SUBTA)

#define     UINT8_SUNNA     UINT8_BASE(SUNNA)
#define     UINT8_SUNLA     UINT8_BASE(SUNLA)
#define     UINT8_SUNRA     UINT8_BASE(SUNRA)
#define     UINT8_SUNWA     UINT8_BASE(SUNWA)
#define     UINT8_SUNDA     UINT8_BASE(SUNDA)
#define     UINT8_SUNQA     UINT8_BASE(SUNQA)

#define     UINT8_SWP1A     UINT8_BASE(SWP1A)
#define     UINT8_SWPAA     UINT8_BASE(SWPAA)
#define     UINT8_SWPEA     UINT8_BASE(SWPEA)
#define     UINT8_SWPTA     UINT8_BASE(SWPTA)

#define     UINT8_TSTS      UINT8_BASE(TSTS)
#define     UINT8_TSTY      UINT8_BASE(TSTY)

#define     UINT8_UNOS      UINT8_BASE(UNOS)

#define     UINT8_XEQ1A     UINT8_BASE(XEQ1A)
#define     UINT8_XEQAA     UINT8_BASE(XEQAA)
#define     UINT8_XEQEA     UINT8_BASE(XEQEA)
#define     UINT8_XEQTA     UINT8_BASE(XEQTA)

#define     UINT8_XOR1A     UINT8_BASE(XOR1A)
#define     UINT8_XORAA     UINT8_BASE(XORAA)
#define     UINT8_XOREA     UINT8_BASE(XOREA)
#define     UINT8_XORS      UINT8_BASE(XORS)
#define     UINT8_XORN      UINT8_BASE(XORN)
#define     UINT8_XORTA     UINT8_BASE(XORTA)

#define     UINT8_ZEQS      UINT8_BASE(ZEQS)
#define     UINT8_ZEQY      UINT8_BASE(ZEQY)

#define     UINT8_ZIPP      UINT8_BASE(ZIPP)

#define     UINT8_ZLTS      UINT8_BASE(ZLTS)
#define     UINT8_ZLTY      UINT8_BASE(ZLTY)

#define     UINT8_ZNES      UINT8_BASE(ZNES)
#define     UINT8_ZNEY      UINT8_BASE(ZNEY)


#define     INT8_ABSL       INT8_BASE(ABSL)
#define     INT8_ABSS       INT8_BASE(ABSS)
#define     INT8_ABSU       INT8_BASE(ABSU)
#define     INT8_ABSH       INT8_BASE(ABSH)
#define     INT8_ABSW       INT8_BASE(ABSW)
#define     INT8_ABSD       INT8_BASE(ABSD)
#define     INT8_ABSQ       INT8_BASE(ABSQ)

#define     INT8_ADD2       INT8_BASE(ADD2)
#define     INT8_ADDL       INT8_BASE(ADDL)
#define     INT8_ADDS       INT8_BASE(ADDS)
#define     INT8_ADDH       INT8_BASE(ADDH)
#define     INT8_ADDW       INT8_BASE(ADDW)
#define     INT8_ADDD       INT8_BASE(ADDD)
#define     INT8_ADDQ       INT8_BASE(ADDQ)
#define     INT8_ADD1A      INT8_BASE(ADD1A)
#define     INT8_ADDAA      INT8_BASE(ADDAA)
#define     INT8_ADDEA      INT8_BASE(ADDEA)
#define     INT8_ADDTA      INT8_BASE(ADDTA)

#define     INT8_AND1A      INT8_BASE(AND1A)
#define     INT8_ANDAA      INT8_BASE(ANDAA)
#define     INT8_ANDEA      INT8_BASE(ANDEA)
#define     INT8_ANDN       INT8_BASE(ANDN)
#define     INT8_ANDS       INT8_BASE(ANDS)
#define     INT8_ANDTA      INT8_BASE(ANDTA)

#define     INT8_ASBC       INT8_BASE(ASBC)
#define     INT8_ASBI       INT8_BASE(ASBI)
#define     INT8_ASBU       INT8_BASE(ASBU)

#define     INT8_ASTI       INT8_BASE(ASTI)
#define     INT8_ASTU       INT8_BASE(ASTU)

#define     INT8_AVGL       INT8_BASE(AVGL)

#define     INT8_BFG1       INT8_BASE(BFG1)

#define     INT8_BFS1       INT8_BASE(BFS1)

#define     INT8_BFC1       INT8_BASE(BFC1)

#define     INT8_CATL       INT8_BASE(CATL)

#define     INT8_CBNS       INT8_BASE(CBNS)
#define     INT8_CBNY       INT8_BASE(CBNY)

#define     INT8_CEQS       INT8_BASE(CEQS)
#define     INT8_CEQY       INT8_BASE(CEQY)

#define     INT8_CGES       INT8_BASE(CGES)
#define     INT8_CGEY       INT8_BASE(CGEY)

#define     INT8_CGTS       INT8_BASE(CGTS)
#define     INT8_CGTY       INT8_BASE(CGTY)

#define     INT8_CLES       INT8_BASE(CLES)
#define     INT8_CLEY       INT8_BASE(CLEY)

#define     INT8_CLTS       INT8_BASE(CLTS)
#define     INT8_CLTY       INT8_BASE(CLTY)

#define     INT8_CNBS       INT8_BASE(CNBS)
#define     INT8_CNBY       INT8_BASE(CNBY)

#define     INT8_CNES       INT8_BASE(CNES)
#define     INT8_CNEY       INT8_BASE(CNEY)

#define     INT8_CNT0       INT8_BASE(CNT0)
#define     INT8_CNT1       INT8_BASE(CNT1)
#define     INT8_CNTS       INT8_BASE(CNTS)

#define     INT8_CSZL       INT8_BASE(CSZL)
#define     INT8_CSZR       INT8_BASE(CSZR)

#define     INT8_CVBC       INT8_BASE(CVBC)
#define     INT8_CVBI       INT8_BASE(CVBI)
#define     INT8_CVBS       INT8_BASE(CVBS)
#define     INT8_CVBU       INT8_BASE(CVBU)
#define     INT8_CVBZ       INT8_BASE(CVBZ)

#define     INT8_CVDF       INT8_BASE(CVDF)
#define     INT8_CVDI       INT8_BASE(CVDI)
#define     INT8_CVDS       INT8_BASE(CVDS)
#define     INT8_CVDU       INT8_BASE(CVDU)
#define     INT8_CVDZ       INT8_BASE(CVDZ)

#define     INT8_CVHF       INT8_BASE(CVHF)
#define     INT8_CVHI       INT8_BASE(CVHI)
#define     INT8_CVHS       INT8_BASE(CVHS)
#define     INT8_CVHU       INT8_BASE(CVHU)
#define     INT8_CVHZ       INT8_BASE(CVHZ)

#define     INT8_CVWF       INT8_BASE(CVWF)
#define     INT8_CVWI       INT8_BASE(CVWI)
#define     INT8_CVWS       INT8_BASE(CVWS)
#define     INT8_CVWU       INT8_BASE(CVWU)
#define     INT8_CVWZ       INT8_BASE(CVWZ)

#define     INT8_DIFU       INT8_BASE(DIFU)
#define     INT8_DIFS       INT8_BASE(DIFS)

#define     INT8_DIVL       INT8_BASE(DIVL)
#define     INT8_DIV2       INT8_BASE(DIV2)
#define     INT8_DIVH       INT8_BASE(DIVH)
#define     INT8_DIVW       INT8_BASE(DIVW)
#define     INT8_DIVD       INT8_BASE(DIVD)
#define     INT8_DIVQ       INT8_BASE(DIVQ)

#define     INT8_DCRL       INT8_BASE(DCRL)
#define     INT8_DCR1A      INT8_BASE(DCR1A)
#define     INT8_DCRAA      INT8_BASE(DCRAA)
#define     INT8_DCREA      INT8_BASE(DCREA)
#define     INT8_DCRTA      INT8_BASE(DCRTA)

#define     INT8_DUPD       INT8_BASE(DUPD)
#define     INT8_DUPDAC     INT8_BASE(DUPDAC)
#define     INT8_DUPO       INT8_BASE(DUPO)
#define     INT8_DUPOAC     INT8_BASE(DUPOAC)
#define     INT8_DUPQ       INT8_BASE(DUPQ)
#define     INT8_DUPQAC     INT8_BASE(DUPQAC)
#define     INT8_DUPS       INT8_BASE(DUPS)
#define     INT8_DUPSAC     INT8_BASE(DUPSAC)
#define     INT8_DUPW       INT8_BASE(DUPW)
#define     INT8_DUPWAC     INT8_BASE(DUPWAC)

#define     INT8_ICRL       INT8_BASE(ICRL)
#define     INT8_ICR1A      INT8_BASE(ICR1A)
#define     INT8_ICRAA      INT8_BASE(ICRAA)
#define     INT8_ICREA      INT8_BASE(ICREA)
#define     INT8_ICRTA      INT8_BASE(ICRTA)

#define     INT8_INVS       INT8_BASE(INVS)
#define     INT8_INV1A      INT8_BASE(INV1A)
#define     INT8_INVAA      INT8_BASE(INVAA)
#define     INT8_INVEA      INT8_BASE(INVEA)
#define     INT8_INVTA      INT8_BASE(INVTA)

#define     INT8_LDR1AC     INT8_BASE(LDR1AC)
#define     INT8_LDRAAC     INT8_BASE(LDRAAC)
#define     INT8_LDRDAC     INT8_BASE(LDRDAC)
#define     INT8_LDROAC     INT8_BASE(LDROAC)
#define     INT8_LDRQAC     INT8_BASE(LDRQAC)
#define     INT8_LDRSAC     INT8_BASE(LDRSAC)
#define     INT8_LDRTAC     INT8_BASE(LDRTAC)
#define     INT8_LDRWAC     INT8_BASE(LDRWAC)

#define     INT8_LUNNAC     INT8_BASE(LUNNAC)
#define     INT8_LUNLAC     INT8_BASE(LUNLAC)
#define     INT8_LUNRAC     INT8_BASE(LUNRAC)
#define     INT8_LUNWAC     INT8_BASE(LUNWAC)
#define     INT8_LUNDAC     INT8_BASE(LUNDAC)
#define     INT8_LUNQAC     INT8_BASE(LUNQAC)
#define     INT8_LUNOAC     INT8_BASE(LUNOAC)
#define     INT8_LUNSAC     INT8_BASE(LUNSAC)

#define     INT8_FAM2       INT8_BASE(FAM2)
#define     INT8_FAML       INT8_BASE(FAML)
#define     INT8_FAMS       INT8_BASE(FAMS)

#define     INT8_MAXL       INT8_BASE(MAXL)

#define     INT8_MINL       INT8_BASE(MINL)

#define     INT8_MODL       INT8_BASE(MODL)
#define     INT8_MOD2       INT8_BASE(MOD2)
#define     INT8_MODH       INT8_BASE(MODH)
#define     INT8_MODW       INT8_BASE(MODW)
#define     INT8_MODD       INT8_BASE(MODD)
#define     INT8_MODQ       INT8_BASE(MODQ)

#define     INT8_MUL2       INT8_BASE(MUL2)
#define     INT8_MULL       INT8_BASE(MULL)
#define     INT8_MULS       INT8_BASE(MULS)
#define     INT8_MULH       INT8_BASE(MULH)
#define     INT8_MULW       INT8_BASE(MULW)
#define     INT8_MULD       INT8_BASE(MULD)
#define     INT8_MULQ       INT8_BASE(MULQ)

#define     INT8_NEGL       INT8_BASE(NEGL)
#define     INT8_NEGS       INT8_BASE(NEGS)
#define     INT8_NEGH       INT8_BASE(NEGH)
#define     INT8_NEGW       INT8_BASE(NEGW)
#define     INT8_NEGD       INT8_BASE(NEGD)
#define     INT8_NEGQ       INT8_BASE(NEGQ)

#define     INT8_ORR1A      INT8_BASE(ORR1A)
#define     INT8_ORRAA      INT8_BASE(ORRAA)
#define     INT8_ORREA      INT8_BASE(ORREA)
#define     INT8_ORRN       INT8_BASE(ORRN)
#define     INT8_ORRS       INT8_BASE(ORRS)
#define     INT8_ORRTA      INT8_BASE(ORRTA)

#define     INT8_REVY       INT8_BASE(REVY)

#define     INT8_SEQW       INT8_BASE(SEQW)
#define     INT8_SEQD       INT8_BASE(SEQD)
#define     INT8_SEQQ       INT8_BASE(SEQQ)

#define     INT8_SET1       INT8_BASE(SETL)
#define     INT8_SETR       INT8_BASE(SETR)

#define     INT8_SHL2       INT8_BASE(SHL2)
#define     INT8_SHLL       INT8_BASE(SHLL)
#define     INT8_SHLR       INT8_BASE(SHLR)
#define     INT8_SHLS       INT8_BASE(SHLS)

#define     INT8_SHRS       INT8_BASE(SHRS)

#define     INT8_SILL       INT8_BASE(SILL)
#define     INT8_SILR       INT8_BASE(SILR)

#define     INT8_SIRL       INT8_BASE(SIRL)
#define     INT8_SIRR       INT8_BASE(SIRR)

#define     INT8_STR1A      INT8_BASE(STR1A)
#define     INT8_STRDA      INT8_BASE(STRDA)
#define     INT8_STREA      INT8_BASE(STREA)
#define     INT8_STROA      INT8_BASE(STROA)
#define     INT8_STRQA      INT8_BASE(STRQA)
#define     INT8_STRSA      INT8_BASE(STRSA)
#define     INT8_STRTA      INT8_BASE(STRTA)
#define     INT8_STRWA      INT8_BASE(STRWA)

#define     INT8_SUB2       INT8_BASE(SUB2)
#define     INT8_SUBL       INT8_BASE(SUBL)
#define     INT8_SUBS       INT8_BASE(SUBS)
#define     INT8_SUBH       INT8_BASE(SUBH)
#define     INT8_SUBW       INT8_BASE(SUBW)
#define     INT8_SUBD       INT8_BASE(SUBD)
#define     INT8_SUBQ       INT8_BASE(SUBQ)
#define     INT8_SUB1A      INT8_BASE(SUB1A)
#define     INT8_SUBAA      INT8_BASE(SUBAA)
#define     INT8_SUBEA      INT8_BASE(SUBEA)
#define     INT8_SUBTA      INT8_BASE(SUBTA)

#define     INT8_SUNNA      INT8_BASE(SUNNA)
#define     INT8_SUNRA      INT8_BASE(SUNRA)
#define     INT8_SUNLA      INT8_BASE(SUNLA)
#define     INT8_SUNWA      INT8_BASE(SUNWA)
#define     INT8_SUNDA      INT8_BASE(SUNDA)
#define     INT8_SUNQA      INT8_BASE(SUNQA)

#define     INT8_SWP1A      INT8_BASE(SWP1A)
#define     INT8_SWPAA      INT8_BASE(SWPAA)
#define     INT8_SWPEA      INT8_BASE(SWPEA)
#define     INT8_SWPTA      INT8_BASE(SWPTA)

#define     INT8_TSTS       INT8_BASE(TSTS)
#define     INT8_TSTY       INT8_BASE(TSTY)

#define     INT8_UNOS       INT8_BASE(UNOS)

#define     INT8_XEQ1A      INT8_BASE(XEQ1A)
#define     INT8_XEQAA      INT8_BASE(XEQAA)
#define     INT8_XEQEA      INT8_BASE(XEQEA)
#define     INT8_XEQTA      INT8_BASE(XEQTA)

#define     INT8_XOR1A      INT8_BASE(XOR1A)
#define     INT8_XORAA      INT8_BASE(XORAA)
#define     INT8_XOREA      INT8_BASE(XOREA)
#define     INT8_XORS       INT8_BASE(XORS)
#define     INT8_XORN       INT8_BASE(XORN)
#define     INT8_XORTA      INT8_BASE(XORTA)

#define     INT8_ZEQS       INT8_BASE(ZEQS)
#define     INT8_ZEQY       INT8_BASE(ZEQY)

#define     INT8_ZGES       INT8_BASE(ZGES)
#define     INT8_ZGEY       INT8_BASE(ZGEY)

#define     INT8_ZGTS       INT8_BASE(ZGTS)
#define     INT8_ZGTY       INT8_BASE(ZGTY)

#define     INT8_ZLES       INT8_BASE(ZLES)
#define     INT8_ZLEY       INT8_BASE(ZLEY)

#define     INT8_ZLTS       INT8_BASE(ZLTS)
#define     INT8_ZLTY       INT8_BASE(ZLTY)

#define     INT8_ZNES       INT8_BASE(ZNES)
#define     INT8_ZNEY       INT8_BASE(ZNEY)


#define     UINT16_ADD2     UINT16_BASE(ADD2)
#define     UINT16_ADDL     UINT16_BASE(ADDL)
#define     UINT16_ADDS     UINT16_BASE(ADDS)
#define     UINT16_ADDH     UINT16_BASE(ADDH)
#define     UINT16_ADDW     UINT16_BASE(ADDW)
#define     UINT16_ADDD     UINT16_BASE(ADDD)
#define     UINT16_ADDQ     UINT16_BASE(ADDQ)
#define     UINT16_ADD1A    UINT16_BASE(ADD1A)
#define     UINT16_ADDAA    UINT16_BASE(ADDAA)
#define     UINT16_ADDEA    UINT16_BASE(ADDEA)
#define     UINT16_ADDTA    UINT16_BASE(ADDTA)

#define     UINT16_AND1A    UINT16_BASE(AND1A)
#define     UINT16_ANDAA    UINT16_BASE(ANDAA)
#define     UINT16_ANDEA    UINT16_BASE(ANDEA)
#define     UINT16_ANDN     UINT16_BASE(ANDN)
#define     UINT16_ANDS     UINT16_BASE(ANDS)
#define     UINT16_ANDTA    UINT16_BASE(ANDTA)

#define     UINT16_ASHF     UINT16_BASE(ASHF)
#define     UINT16_ASHI     UINT16_BASE(ASHI)
#define     UINT16_ASHU     UINT16_BASE(ASHU)

#define     UINT16_ASTF     UINT16_BASE(ASTF)
#define     UINT16_ASTI     UINT16_BASE(ASTI)
#define     UINT16_ASTU     UINT16_BASE(ASTU)

#define     UINT16_AVGL     UINT16_BASE(AVGL)

#define     UINT16_BFG1     UINT16_BASE(BFG1)

#define     UINT16_BFS1     UINT16_BASE(BFS1)

#define     UINT16_BFC1     UINT16_BASE(BFC1)

#define     UINT16_CATL     UINT16_BASE(CATL)

#define     UINT16_CBNS     UINT16_BASE(CBNS)
#define     UINT16_CBNY     UINT16_BASE(CBNY)

#define     UINT16_CEQS     UINT16_BASE(CEQS)
#define     UINT16_CEQY     UINT16_BASE(CEQY)

#define     UINT16_CGES     UINT16_BASE(CGES)
#define     UINT16_CGEY     UINT16_BASE(CGEY)

#define     UINT16_CGTS     UINT16_BASE(CGTS)
#define     UINT16_CGTY     UINT16_BASE(CGTY)

#define     UINT16_CLES     UINT16_BASE(CLES)
#define     UINT16_CLEY     UINT16_BASE(CLEY)

#define     UINT16_CLEZ     UINT16_BASE(CLEZ)
#define     UINT16_CLTS     UINT16_BASE(CLTS)

#define     UINT16_CLTY     UINT16_BASE(CLTY)
#define     UINT16_CLTZ     UINT16_BASE(CLTZ)

#define     UINT16_CNBS     UINT16_BASE(CNBS)
#define     UINT16_CNBY     UINT16_BASE(CNBY)

#define     UINT16_CNES     UINT16_BASE(CNES)
#define     UINT16_CNEY     UINT16_BASE(CNEY)

#define     UINT16_CNT0     UINT16_BASE(CNT0)
#define     UINT16_CNT1     UINT16_BASE(CNT1)
#define     UINT16_CNTS     UINT16_BASE(CNTS)

#define     UINT16_CSZL     UINT16_BASE(CSZL)
#define     UINT16_CSZR     UINT16_BASE(CSZR)

#define     UINT16_CVBC     UINT16_BASE(CVBC)
#define     UINT16_CVBI     UINT16_BASE(CVBI)
#define     UINT16_CVBS     UINT16_BASE(CVBS)
#define     UINT16_CVBU     UINT16_BASE(CVBU)
#define     UINT16_CVBZ     UINT16_BASE(CVBZ)

#define     UINT16_CVDF     UINT16_BASE(CVDF)
#define     UINT16_CVDI     UINT16_BASE(CVDI)
#define     UINT16_CVDS     UINT16_BASE(CVDS)
#define     UINT16_CVDU     UINT16_BASE(CVDU)
#define     UINT16_CVDZ     UINT16_BASE(CVDZ)

#define     UINT16_CVHF     UINT16_BASE(CVHF)
#define     UINT16_CVHI     UINT16_BASE(CVHI)
#define     UINT16_CVHS     UINT16_BASE(CVHS)
#define     UINT16_CVHU     UINT16_BASE(CVHU)
#define     UINT16_CVHZ     UINT16_BASE(CVHZ)

#define     UINT16_CVWF     UINT16_BASE(CVWF)
#define     UINT16_CVWI     UINT16_BASE(CVWI)
#define     UINT16_CVWS     UINT16_BASE(CVWS)
#define     UINT16_CVWU     UINT16_BASE(CVWU)
#define     UINT16_CVWZ     UINT16_BASE(CVWZ)

#define     UINT16_DIFU     UINT16_BASE(DIFU)
#define     UINT16_DIFS     UINT16_BASE(DIFS)

#define     UINT16_DIVL     UINT16_BASE(DIVL)
#define     UINT16_DIV2     UINT16_BASE(DIV2)
#define     UINT16_DIVH     UINT16_BASE(DIVH)
#define     UINT16_DIVW     UINT16_BASE(DIVW)
#define     UINT16_DIVD     UINT16_BASE(DIVD)
#define     UINT16_DIVQ     UINT16_BASE(DIVQ)

#define     UINT16_DCRL     UINT16_BASE(DCRL)
#define     UINT16_DCR1A    UINT16_BASE(DCR1A)
#define     UINT16_DCRAA    UINT16_BASE(DCRAA)
#define     UINT16_DCREA    UINT16_BASE(DCREA)
#define     UINT16_DCRTA    UINT16_BASE(DCRTA)

#define     UINT16_DUPD     UINT16_BASE(DUPD)
#define     UINT16_DUPDAC   UINT16_BASE(DUPDAC)
#define     UINT16_DUPO     UINT16_BASE(DUPO)
#define     UINT16_DUPOAC   UINT16_BASE(DUPOAC)
#define     UINT16_DUPQ     UINT16_BASE(DUPQ)
#define     UINT16_DUPQAC   UINT16_BASE(DUPQAC)
#define     UINT16_DUPS     UINT16_BASE(DUPS)
#define     UINT16_DUPSAC   UINT16_BASE(DUPSAC)
#define     UINT16_DUPW     UINT16_BASE(DUPW)
#define     UINT16_DUPWAC   UINT16_BASE(DUPWAC)

#define     UINT16_GETL     UINT16_BASE(GETL)
#define     UINT16_GETR     UINT16_BASE(GETR)

#define     UINT16_ICRL     UINT16_BASE(ICRL)
#define     UINT16_ICR1A    UINT16_BASE(ICR1A)
#define     UINT16_ICRAA    UINT16_BASE(ICRAA)
#define     UINT16_ICREA    UINT16_BASE(ICREA)
#define     UINT16_ICRTA    UINT16_BASE(ICRTA)

#define     UINT16_INVS     UINT16_BASE(INVS)
#define     UINT16_INV1A    UINT16_BASE(INV1A)
#define     UINT16_INVAA    UINT16_BASE(INVAA)
#define     UINT16_INVEA    UINT16_BASE(INVEA)
#define     UINT16_INVTA    UINT16_BASE(INVTA)

#define     UINT16_LDR1AC   UINT16_BASE(LDR1AC)
#define     UINT16_LDRAAC   UINT16_BASE(LDRAAC)
#define     UINT16_LDRDAC   UINT16_BASE(LDRDAC)
#define     UINT16_LDROAC   UINT16_BASE(LDROAC)
#define     UINT16_LDRQAC   UINT16_BASE(LDRQAC)
#define     UINT16_LDRSAC   UINT16_BASE(LDRSAC)
#define     UINT16_LDRTAC   UINT16_BASE(LDRTAC)
#define     UINT16_LDRWAC   UINT16_BASE(LDRWAC)

#define     UINT16_LUNNAC   UINT16_BASE(LUNNAC)
#define     UINT16_LUNLAC   UINT16_BASE(LUNLAC)
#define     UINT16_LUNRAC   UINT16_BASE(LUNRAC)
#define     UINT16_LUNWAC   UINT16_BASE(LUNWAC)
#define     UINT16_LUNDAC   UINT16_BASE(LUNDAC)
#define     UINT16_LUNQAC   UINT16_BASE(LUNQAC)
#define     UINT16_LUNOAC   UINT16_BASE(LUNOAC)
#define     UINT16_LUNSAC   UINT16_BASE(LUNSAC)

#define     UINT16_FAM2     UINT16_BASE(FAM2)
#define     UINT16_FAML     UINT16_BASE(FAML)
#define     UINT16_FAMS     UINT16_BASE(FAMS)

#define     UINT16_MAXL     UINT16_BASE(MAXL)

#define     UINT16_MINL     UINT16_BASE(MINL)

#define     UINT16_MODL     UINT16_BASE(MODL)
#define     UINT16_MOD2     UINT16_BASE(MOD2)
#define     UINT16_MODH     UINT16_BASE(MODH)
#define     UINT16_MODW     UINT16_BASE(MODW)
#define     UINT16_MODD     UINT16_BASE(MODD)
#define     UINT16_MODQ     UINT16_BASE(MODQ)

#define     UINT16_MUL2     UINT16_BASE(MUL2)
#define     UINT16_MULL     UINT16_BASE(MULL)
#define     UINT16_MULS     UINT16_BASE(MULS)
#define     UINT16_MULH     UINT16_BASE(MULH)
#define     UINT16_MULW     UINT16_BASE(MULW)
#define     UINT16_MULD     UINT16_BASE(MULD)
#define     UINT16_MULQ     UINT16_BASE(MULQ)

#define     UINT16_NEGL     UINT16_BASE(NEGL)
#define     UINT16_NEGS     UINT16_BASE(NEGS)
#define     UINT16_NEGH     UINT16_BASE(NEGH)
#define     UINT16_NEGW     UINT16_BASE(NEGW)
#define     UINT16_NEGD     UINT16_BASE(NEGD)
#define     UINT16_NEGQ     UINT16_BASE(NEGQ)

#define     UINT16_ORR1A    UINT16_BASE(ORR1A)
#define     UINT16_ORRAA    UINT16_BASE(ORRAA)
#define     UINT16_ORREA    UINT16_BASE(ORREA)
#define     UINT16_ORRN     UINT16_BASE(ORRN)
#define     UINT16_ORRS     UINT16_BASE(ORRS)
#define     UINT16_ORRTA    UINT16_BASE(ORRTA)

#define     UINT16_REVB     UINT16_BASE(REVB)

#define     UINT16_REVY     UINT16_BASE(REVY)

#define     UINT16_ROTL     UINT16_BASE(ROTL)
#define     UINT16_ROTR     UINT16_BASE(ROTR)

#define     UINT16_SEQD     UINT16_BASE(SEQD)
#define     UINT16_SEQQ     UINT16_BASE(SEQQ)
#define     UINT16_SEQW     UINT16_BASE(SEQW)

#define     UINT16_SETL     UINT16_BASE(SETL)
#define     UINT16_SETR     UINT16_BASE(SETR)

#define     UINT16_SHL2     UINT16_BASE(SHL2)
#define     UINT16_SHLL     UINT16_BASE(SHLL)
#define     UINT16_SHLR     UINT16_BASE(SHLR)
#define     UINT16_SHLS     UINT16_BASE(SHLS)

#define     UINT16_SHRS     UINT16_BASE(SHRS)

#define     UINT16_SILL     UINT16_BASE(SILL)
#define     UINT16_SILR     UINT16_BASE(SILR)

#define     UINT16_SIRL     UINT16_BASE(SIRL)
#define     UINT16_SIRR     UINT16_BASE(SIRR)

#define     UINT16_STR1A    UINT16_BASE(STR1A)
#define     UINT16_STRDA    UINT16_BASE(STRDA)
#define     UINT16_STREA    UINT16_BASE(STREA)
#define     UINT16_STROA    UINT16_BASE(STROA)
#define     UINT16_STRQA    UINT16_BASE(STRQA)
#define     UINT16_STRSA    UINT16_BASE(STRSA)
#define     UINT16_STRTA    UINT16_BASE(STRTA)
#define     UINT16_STRWA    UINT16_BASE(STRWA)

#define     UINT16_SUB2     UINT16_BASE(SUB2)
#define     UINT16_SUBL     UINT16_BASE(SUBL)
#define     UINT16_SUBS     UINT16_BASE(SUBS)
#define     UINT16_SUBH     UINT16_BASE(SUBH)
#define     UINT16_SUBW     UINT16_BASE(SUBW)
#define     UINT16_SUBD     UINT16_BASE(SUBD)
#define     UINT16_SUBQ     UINT16_BASE(SUBQ)
#define     UINT16_SUB1A    UINT16_BASE(SUB1A)
#define     UINT16_SUBAA    UINT16_BASE(SUBAA)
#define     UINT16_SUBEA    UINT16_BASE(SUBEA)
#define     UINT16_SUBTA    UINT16_BASE(SUBTA)

#define     UINT16_SUNNA    UINT16_BASE(SUNNA)
#define     UINT16_SUNLA    UINT16_BASE(SUNLA)
#define     UINT16_SUNRA    UINT16_BASE(SUNRA)
#define     UINT16_SUNWA    UINT16_BASE(SUNWA)
#define     UINT16_SUNDA    UINT16_BASE(SUNDA)
#define     UINT16_SUNQA    UINT16_BASE(SUNQA)

#define     UINT16_SWP1A    UINT16_BASE(SWP1A)
#define     UINT16_SWPAA    UINT16_BASE(SWPAA)
#define     UINT16_SWPEA    UINT16_BASE(SWPEA)
#define     UINT16_SWPTA    UINT16_BASE(SWPTA)

#define     UINT16_TSTS     UINT16_BASE(TSTS)
#define     UINT16_TSTY     UINT16_BASE(TSTY)

#define     UINT16_UNOS     UINT16_BASE(UNOS)

#define     UINT16_XEQ1A    UINT16_BASE(XEQ1A)
#define     UINT16_XEQAA    UINT16_BASE(XEQAA)
#define     UINT16_XEQEA    UINT16_BASE(XEQEA)
#define     UINT16_XEQTA    UINT16_BASE(XEQTA)

#define     UINT16_XOR1A    UINT16_BASE(XOR1A)
#define     UINT16_XORAA    UINT16_BASE(XORAA)
#define     UINT16_XOREA    UINT16_BASE(XOREA)
#define     UINT16_XORS     UINT16_BASE(XORS)
#define     UINT16_XORN     UINT16_BASE(XORN)
#define     UINT16_XORTA    UINT16_BASE(XORTA)

#define     UINT16_ZEQS     UINT16_BASE(ZEQS)
#define     UINT16_ZEQY     UINT16_BASE(ZEQY)

#define     UINT16_ZIPP     UINT16_BASE(ZIPP)

#define     UINT16_ZLTS     UINT16_BASE(ZLTS)
#define     UINT16_ZLTY     UINT16_BASE(ZLTY)

#define     UINT16_ZNES     UINT16_BASE(ZNES)
#define     UINT16_ZNEY     UINT16_BASE(ZNEY)


#define     INT16_ABSL      INT16_BASE(ABSL)
#define     INT16_ABSS      INT16_BASE(ABSS)
#define     INT16_ABSU      INT16_BASE(ABSU)
#define     INT16_ABSH      INT16_BASE(ABSH)
#define     INT16_ABSW      INT16_BASE(ABSW)
#define     INT16_ABSD      INT16_BASE(ABSD)
#define     INT16_ABSQ      INT16_BASE(ABSQ)

#define     INT16_ADD2      INT16_BASE(ADD2)
#define     INT16_ADDL      INT16_BASE(ADDL)
#define     INT16_ADDS      INT16_BASE(ADDS)
#define     INT16_ADDH      INT16_BASE(ADDH)
#define     INT16_ADDW      INT16_BASE(ADDW)
#define     INT16_ADDD      INT16_BASE(ADDD)
#define     INT16_ADDQ      INT16_BASE(ADDQ)
#define     INT16_ADD1A     INT16_BASE(ADD1A)
#define     INT16_ADDAA     INT16_BASE(ADDAA)
#define     INT16_ADDEA     INT16_BASE(ADDEA)
#define     INT16_ADDTA     INT16_BASE(ADDTA)

#define     INT16_AND1A     INT16_BASE(AND1A)
#define     INT16_ANDAA     INT16_BASE(ANDAA)
#define     INT16_ANDEA     INT16_BASE(ANDEA)
#define     INT16_ANDN      INT16_BASE(ANDN)
#define     INT16_ANDS      INT16_BASE(ANDS)
#define     INT16_ANDTA     INT16_BASE(ANDTA)

#define     INT16_ASHF      INT16_BASE(ASHF)
#define     INT16_ASHI      INT16_BASE(ASHI)
#define     INT16_ASHU      INT16_BASE(ASHU)

#define     INT16_ASTF      INT16_BASE(ASTF)
#define     INT16_ASTI      INT16_BASE(ASTI)
#define     INT16_ASTU      INT16_BASE(ASTU)

#define     INT16_AVGL      INT16_BASE(AVGL)

#define     INT16_BFG1      INT16_BASE(BFG1)

#define     INT16_BFC1      INT16_BASE(BFC1)

#define     INT16_BFS1      INT16_BASE(BFS1)

#define     INT16_CATL      INT16_BASE(CATL)

#define     INT16_CBNS      INT16_BASE(CBNS)
#define     INT16_CBNY      INT16_BASE(CBNY)

#define     INT16_CEQS      INT16_BASE(CEQS)
#define     INT16_CEQY      INT16_BASE(CEQY)

#define     INT16_CGES      INT16_BASE(CGES)
#define     INT16_CGEY      INT16_BASE(CGEY)

#define     INT16_CGTS      INT16_BASE(CGTS)
#define     INT16_CGTY      INT16_BASE(CGTY)

#define     INT16_CLES      INT16_BASE(CLES)
#define     INT16_CLEY      INT16_BASE(CLEY)

#define     INT16_CLTS      INT16_BASE(CLTS)
#define     INT16_CLTY      INT16_BASE(CLTY)

#define     INT16_CNBS      INT16_BASE(CNBS)
#define     INT16_CNBY      INT16_BASE(CNBY)

#define     INT16_CNES      INT16_BASE(CNES)
#define     INT16_CNEY      INT16_BASE(CNEY)

#define     INT16_CNT0      INT16_BASE(CNT0)
#define     INT16_CNT1      INT16_BASE(CNT1)
#define     INT16_CNTS      INT16_BASE(CNTS)

#define     INT16_CSZL      INT16_BASE(CSZL)
#define     INT16_CSZR      INT16_BASE(CSZR)

#define     INT16_CVBC      INT16_BASE(CVBC)
#define     INT16_CVBI      INT16_BASE(CVBI)
#define     INT16_CVBS      INT16_BASE(CVBS)
#define     INT16_CVBU      INT16_BASE(CVBU)
#define     INT16_CVBZ      INT16_BASE(CVBZ)

#define     INT16_CVDF      INT16_BASE(CVDF)
#define     INT16_CVDI      INT16_BASE(CVDI)
#define     INT16_CVDS      INT16_BASE(CVDS)
#define     INT16_CVDU      INT16_BASE(CVDU)
#define     INT16_CVDZ      INT16_BASE(CVDZ)

#define     INT16_CVHF      INT16_BASE(CVHF)
#define     INT16_CVHI      INT16_BASE(CVHI)
#define     INT16_CVHS      INT16_BASE(CVHS)
#define     INT16_CVHU      INT16_BASE(CVHU)
#define     INT16_CVHZ      INT16_BASE(CVHZ)

#define     INT16_CVWF      INT16_BASE(CVWF)
#define     INT16_CVWI      INT16_BASE(CVWI)
#define     INT16_CVWS      INT16_BASE(CVWS)
#define     INT16_CVWU      INT16_BASE(CVWU)
#define     INT16_CVWZ      INT16_BASE(CVWZ)

#define     INT16_DIFU      INT16_BASE(DIFU)
#define     INT16_DIFS      INT16_BASE(DIFS)

#define     INT16_DIVL      INT16_BASE(DIVL)
#define     INT16_DIV2      INT16_BASE(DIV2)
#define     INT16_DIVH      INT16_BASE(DIVH)
#define     INT16_DIVW      INT16_BASE(DIVW)
#define     INT16_DIVD      INT16_BASE(DIVD)
#define     INT16_DIVQ      INT16_BASE(DIVQ)

#define     INT16_DCRL      INT16_BASE(DCRL)
#define     INT16_DCR1A     INT16_BASE(DCR1A)
#define     INT16_DCRAA     INT16_BASE(DCRAA)
#define     INT16_DCREA     INT16_BASE(DCREA)
#define     INT16_DCRTA     INT16_BASE(DCRTA)

#define     INT16_DUPD      INT16_BASE(DUPD)
#define     INT16_DUPDAC    INT16_BASE(DUPDAC)
#define     INT16_DUPO      INT16_BASE(DUPO)
#define     INT16_DUPOAC    INT16_BASE(DUPOAC)
#define     INT16_DUPQ      INT16_BASE(DUPQ)
#define     INT16_DUPQAC    INT16_BASE(DUPQAC)
#define     INT16_DUPS      INT16_BASE(DUPS)
#define     INT16_DUPSAC    INT16_BASE(DUPSAC)
#define     INT16_DUPW      INT16_BASE(DUPW)
#define     INT16_DUPWAC    INT16_BASE(DUPWAC)

#define     INT16_GETL      INT16_BASE(GETL)
#define     INT16_GETR      INT16_BASE(GETR)

#define     INT16_ICRL      INT16_BASE(ICRL)
#define     INT16_ICR1A     INT16_BASE(ICR1A)
#define     INT16_ICRAA     INT16_BASE(ICRAA)
#define     INT16_ICREA     INT16_BASE(ICREA)
#define     INT16_ICRTA     INT16_BASE(ICRTA)

#define     INT16_INVS      INT16_BASE(INVS)
#define     INT16_INV1A     INT16_BASE(INV1A)
#define     INT16_INVAA     INT16_BASE(INVAA)
#define     INT16_INVEA     INT16_BASE(INVEA)
#define     INT16_INVTA     INT16_BASE(INVTA)

#define     INT16_LDR1AC    INT16_BASE(LDR1AC)
#define     INT16_LDRAAC    INT16_BASE(LDRAAC)
#define     INT16_LDRDAC    INT16_BASE(LDRDAC)
#define     INT16_LDROAC    INT16_BASE(LDROAC)
#define     INT16_LDRQAC    INT16_BASE(LDRQAC)
#define     INT16_LDRSAC    INT16_BASE(LDRSAC)
#define     INT16_LDRTAC    INT16_BASE(LDRTAC)
#define     INT16_LDRWAC    INT16_BASE(LDRWAC)

#define     INT16_LUNNAC    INT16_BASE(LUNNAC)
#define     INT16_LUNLAC    INT16_BASE(LUNLAC)
#define     INT16_LUNRAC    INT16_BASE(LUNRAC)
#define     INT16_LUNWAC    INT16_BASE(LUNWAC)
#define     INT16_LUNDAC    INT16_BASE(LUNDAC)
#define     INT16_LUNQAC    INT16_BASE(LUNQAC)
#define     INT16_LUNOAC    INT16_BASE(LUNOAC)
#define     INT16_LUNSAC    INT16_BASE(LUNSAC)

#define     INT16_FAM2      INT16_BASE(FAM2)
#define     INT16_FAML      INT16_BASE(FAML)
#define     INT16_FAMS      INT16_BASE(FAMS)

#define     INT16_MAXL      INT16_BASE(MAXL)

#define     INT16_MINL      INT16_BASE(MINL)

#define     INT16_MODL      INT16_BASE(MODL)
#define     INT16_MOD2      INT16_BASE(MOD2)
#define     INT16_MODH      INT16_BASE(MODH)
#define     INT16_MODW      INT16_BASE(MODW)
#define     INT16_MODD      INT16_BASE(MODD)
#define     INT16_MODQ      INT16_BASE(MODQ)

#define     INT16_MUL2      INT16_BASE(MUL2)
#define     INT16_MULL      INT16_BASE(MULL)
#define     INT16_MULS      INT16_BASE(MULS)
#define     INT16_MULH      INT16_BASE(MULH)
#define     INT16_MULW      INT16_BASE(MULW)
#define     INT16_MULD      INT16_BASE(MULD)
#define     INT16_MULQ      INT16_BASE(MULQ)

#define     INT16_NEGL      INT16_BASE(NEGL)
#define     INT16_NEGS      INT16_BASE(NEGS)
#define     INT16_NEGH      INT16_BASE(NEGH)
#define     INT16_NEGW      INT16_BASE(NEGW)
#define     INT16_NEGD      INT16_BASE(NEGD)
#define     INT16_NEGQ      INT16_BASE(NEGQ)

#define     INT16_ORR1A     INT16_BASE(ORR1A)
#define     INT16_ORRAA     INT16_BASE(ORRAA)
#define     INT16_ORREA     INT16_BASE(ORREA)
#define     INT16_ORRN      INT16_BASE(ORRN)
#define     INT16_ORRS      INT16_BASE(ORRS)
#define     INT16_ORRTA     INT16_BASE(ORRTA)

#define     INT16_REVB      INT16_BASE(REVB)
#define     INT16_REVY      INT16_BASE(REVY)

#define     INT16_SEQD      INT16_BASE(SEQD)
#define     INT16_SEQQ      INT16_BASE(SEQQ)
#define     INT16_SEQW      INT16_BASE(SEQW)

#define     INT16_SET1      INT16_BASE(SET1)
#define     INT16_SETL      INT16_BASE(SETL)
#define     INT16_SETR      INT16_BASE(SETR)

#define     INT16_SHL2      INT16_BASE(SHL2)
#define     INT16_SHLL      INT16_BASE(SHLL)
#define     INT16_SHLR      INT16_BASE(SHLR)
#define     INT16_SHLS      INT16_BASE(SHLS)

#define     INT16_SHRS      INT16_BASE(SHRS)

#define     INT16_SILL      INT16_BASE(SILL)
#define     INT16_SILR      INT16_BASE(SILR)

#define     INT16_SIRL      INT16_BASE(SIRL)
#define     INT16_SIRR      INT16_BASE(SIRR)

#define     INT16_STR1A     INT16_BASE(STR1A)
#define     INT16_STRDA     INT16_BASE(STRDA)
#define     INT16_STREA     INT16_BASE(STREA)
#define     INT16_STROA     INT16_BASE(STROA)
#define     INT16_STRQA     INT16_BASE(STRQA)
#define     INT16_STRSA     INT16_BASE(STRQA)
#define     INT16_STRTA     INT16_BASE(STRTA)
#define     INT16_STRWA     INT16_BASE(STRWA)

#define     INT16_SUB2      INT16_BASE(SUB2)
#define     INT16_SUBL      INT16_BASE(SUBL)
#define     INT16_SUBS      INT16_BASE(SUBS)
#define     INT16_SUBH      INT16_BASE(SUBH)
#define     INT16_SUBW      INT16_BASE(SUBW)
#define     INT16_SUBD      INT16_BASE(SUBD)
#define     INT16_SUBQ      INT16_BASE(SUBQ)
#define     INT16_SUB1A     INT16_BASE(SUB1A)
#define     INT16_SUBAA     INT16_BASE(SUBAA)
#define     INT16_SUBEA     INT16_BASE(SUBEA)
#define     INT16_SUBTA     INT16_BASE(SUBTA)

#define     INT16_SUNNA     INT16_BASE(SUNNA)
#define     INT16_SUNLA     INT16_BASE(SUNLA)
#define     INT16_SUNRA     INT16_BASE(SUNRA)
#define     INT16_SUNWA     INT16_BASE(SUNWA)
#define     INT16_SUNDA     INT16_BASE(SUNDA)
#define     INT16_SUNQA     INT16_BASE(SUNQA)

#define     INT16_SWP1A     INT16_BASE(SWP1A)
#define     INT16_SWPAA     INT16_BASE(SWPAA)
#define     INT16_SWPEA     INT16_BASE(SWPEA)
#define     INT16_SWPTA     INT16_BASE(SWPTA)

#define     INT16_TSTS      INT16_BASE(TSTS)
#define     INT16_TSTY      INT16_BASE(TSTY)

#define     INT16_UNOS      INT16_BASE(UNOS)

#define     INT16_XEQ1A     INT16_BASE(XEQ1A)
#define     INT16_XEQAA     INT16_BASE(XEQAA)
#define     INT16_XEQEA     INT16_BASE(XEQEA)
#define     INT16_XEQTA     INT16_BASE(XEQTA)

#define     INT16_XOR1A     INT16_BASE(XOR1A)
#define     INT16_XORAA     INT16_BASE(XORAA)
#define     INT16_XOREA     INT16_BASE(XOREA)
#define     INT16_XORS      INT16_BASE(XORS)
#define     INT16_XORN      INT16_BASE(XORN)
#define     INT16_XORTA     INT16_BASE(XORTA)

#define     INT16_ZEQS      INT16_BASE(ZEQS)
#define     INT16_ZEQY      INT16_BASE(ZEQY)

#define     INT16_ZGES      INT16_BASE(ZGES)
#define     INT16_ZGEY      INT16_BASE(ZGEY)

#define     INT16_ZGTS      INT16_BASE(ZGTS)
#define     INT16_ZGTY      INT16_BASE(ZGTY)

#define     INT16_ZLES      INT16_BASE(ZLES)
#define     INT16_ZLEY      INT16_BASE(ZLEY)

#define     INT16_ZLTS      INT16_BASE(ZLTS)
#define     INT16_ZLTY      INT16_BASE(ZLTY)

#define     INT16_ZNES      INT16_BASE(ZNES)
#define     INT16_ZNEY      INT16_BASE(ZNEY)


#define     UINT32_ADD2     UINT32_BASE(ADD2)
#define     UINT32_ADDL     UINT32_BASE(ADDL)
#define     UINT32_ADDS     UINT32_BASE(ADDS)
#define     UINT32_ADDH     UINT32_BASE(ADDH)
#define     UINT32_ADDW     UINT32_BASE(ADDW)
#define     UINT32_ADDD     UINT32_BASE(ADDD)
#define     UINT32_ADDQ     UINT32_BASE(ADDQ)
#define     UINT32_ADD1A    UINT32_BASE(ADD1A)
#define     UINT32_ADDAA    UINT32_BASE(ADDAA)
#define     UINT32_ADDEA    UINT32_BASE(ADDEA)
#define     UINT32_ADDTA    UINT32_BASE(ADDTA)

#define     UINT32_AND1A    UINT32_BASE(AND1A)
#define     UINT32_ANDAA    UINT32_BASE(ANDAA)
#define     UINT32_ANDEA    UINT32_BASE(ANDEA)
#define     UINT32_ANDN     UINT32_BASE(ANDN)
#define     UINT32_ANDS     UINT32_BASE(ANDS)
#define     UINT32_ANDTA    UINT32_BASE(ANDTA)

#define     UINT32_ASTF     UINT32_BASE(ASTF)
#define     UINT32_ASTI     UINT32_BASE(ASTI)
#define     UINT32_ASTU     UINT32_BASE(ASTU)
#define     UINT32_ASTV     UINT32_BASE(ASTV)

#define     UINT32_ASWF     UINT32_BASE(ASWF)
#define     UINT32_ASWI     UINT32_BASE(ASWI)
#define     UINT32_ASWU     UINT32_BASE(ASWU)

#define     UINT32_AVGL     UINT32_BASE(AVGL)

#define     UINT32_BFG1     UINT32_BASE(BFG1)

#define     UINT32_BFC1     UINT32_BASE(BFC1)

#define     UINT32_BFS1     UINT32_BASE(BFS1)

#define     UINT32_CATL     UINT32_BASE(CATL)

#define     UINT32_CBNS     UINT32_BASE(CBNS)
#define     UINT32_CBNY     UINT32_BASE(CBNY)

#define     UINT32_CEQS     UINT32_BASE(CEQS)
#define     UINT32_CEQY     UINT32_BASE(CEQY)

#define     UINT32_CGES     UINT32_BASE(CGES)
#define     UINT32_CGEY     UINT32_BASE(CGEY)

#define     UINT32_CGTS     UINT32_BASE(CGTS)
#define     UINT32_CGTY     UINT32_BASE(CGTY)

#define     UINT32_CLES     UINT32_BASE(CLES)
#define     UINT32_CLEY     UINT32_BASE(CLEY)

#define     UINT32_CLTS     UINT32_BASE(CLTS)
#define     UINT32_CLTY     UINT32_BASE(CLTY)

#define     UINT32_CNBS     UINT32_BASE(CNBS)
#define     UINT32_CNBY     UINT32_BASE(CNBY)

#define     UINT32_CNES     UINT32_BASE(CNES)
#define     UINT32_CNEY     UINT32_BASE(CNEY)

#define     UINT32_CNT0     UINT32_BASE(CNT0)
#define     UINT32_CNT1     UINT32_BASE(CNT1)
#define     UINT32_CNTS     UINT32_BASE(CNTS)

#define     UINT32_CSZL     UINT32_BASE(CSZL)
#define     UINT32_CSZR     UINT32_BASE(CSZR)

#define     UINT32_CVBC     UINT32_BASE(CVBC)
#define     UINT32_CVBI     UINT32_BASE(CVBI)
#define     UINT32_CVBS     UINT32_BASE(CVBS)
#define     UINT32_CVBU     UINT32_BASE(CVBU)
#define     UINT32_CVBZ     UINT32_BASE(CVBZ)

#define     UINT32_CVDF     UINT32_BASE(CVDF)
#define     UINT32_CVDI     UINT32_BASE(CVDI)
#define     UINT32_CVDS     UINT32_BASE(CVDS)
#define     UINT32_CVDU     UINT32_BASE(CVDU)
#define     UINT32_CVDZ     UINT32_BASE(CVDZ)

#define     UINT32_CVHF     UINT32_BASE(CVHF)
#define     UINT32_CVHI     UINT32_BASE(CVHI)
#define     UINT32_CVHS     UINT32_BASE(CVHS)
#define     UINT32_CVHU     UINT32_BASE(CVHU)
#define     UINT32_CVHZ     UINT32_BASE(CVHZ)

#define     UINT32_CVWF     UINT32_BASE(CVWF)
#define     UINT32_CVWI     UINT32_BASE(CVWI)
#define     UINT32_CVWS     UINT32_BASE(CVWS)
#define     UINT32_CVWU     UINT32_BASE(CVWU)
#define     UINT32_CVWZ     UINT32_BASE(CVWZ)

#define     UINT32_DIFU     UINT32_BASE(DIFU)
#define     UINT32_DIFS     UINT32_BASE(DIFS)

#define     UINT32_DIVL     UINT32_BASE(DIVL)
#define     UINT32_DIV2     UINT32_BASE(DIV2)
#define     UINT32_DIVH     UINT32_BASE(DIVH)
#define     UINT32_DIVW     UINT32_BASE(DIVW)
#define     UINT32_DIVD     UINT32_BASE(DIVD)
#define     UINT32_DIVQ     UINT32_BASE(DIVQ)

#define     UINT32_DCRL     UINT32_BASE(DCRL)
#define     UINT32_DCR1A    UINT32_BASE(DCR1A)
#define     UINT32_DCRAA    UINT32_BASE(DCRAA)
#define     UINT32_DCREA    UINT32_BASE(DCREA)
#define     UINT32_DCRTA    UINT32_BASE(DCRTA)

#define     UINT32_DUPD     UINT32_BASE(DUPD)
#define     UINT32_DUPDAC   UINT32_BASE(DUPDAC)
#define     UINT32_DUPO     UINT32_BASE(DUPO)
#define     UINT32_DUPOAC   UINT32_BASE(DUPOAC)
#define     UINT32_DUPQ     UINT32_BASE(DUPQ)
#define     UINT32_DUPQAC   UINT32_BASE(DUPQAC)
#define     UINT32_DUPS     UINT32_BASE(DUPS)
#define     UINT32_DUPSAC   UINT32_BASE(DUPSAC)
#define     UINT32_DUPW     UINT32_BASE(DUPW)
#define     UINT32_DUPWAC   UINT32_BASE(DUPWAC)

#define     UINT32_GETL     UINT32_BASE(GETL)
#define     UINT32_GETR     UINT32_BASE(GETR)

#define     UINT32_ICRL     UINT32_BASE(ICRL)
#define     UINT32_ICR1A    UINT32_BASE(ICR1A)
#define     UINT32_ICRAA    UINT32_BASE(ICRAA)
#define     UINT32_ICREA    UINT32_BASE(ICREA)
#define     UINT32_ICRTA    UINT32_BASE(ICRTA)

#define     UINT32_INVS     UINT32_BASE(INVS)
#define     UINT32_INV1A    UINT32_BASE(INV1A)
#define     UINT32_INVAA    UINT32_BASE(INVAA)
#define     UINT32_INVEA    UINT32_BASE(INVEA)
#define     UINT32_INVTA    UINT32_BASE(INVTA)

#define     UINT32_LDR1AC   UINT32_BASE(LDR1AC)
#define     UINT32_LDRAAC   UINT32_BASE(LDRAAC)
#define     UINT32_LDRDAC   UINT32_BASE(LDRDAC)
#define     UINT32_LDROAC   UINT32_BASE(LDROAC)
#define     UINT32_LDRQAC   UINT32_BASE(LDRQAC)
#define     UINT32_LDRSAC   UINT32_BASE(LDRSAC)
#define     UINT32_LDRTAC   UINT32_BASE(LDRTAC)
#define     UINT32_LDRWAC   UINT32_BASE(LDRWAC)

#define     UINT32_LUNNAC   UINT32_BASE(LUNNAC)
#define     UINT32_LUNLAC   UINT32_BASE(LUNLAC)
#define     UINT32_LUNRAC   UINT32_BASE(LUNRAC)
#define     UINT32_LUNWAC   UINT32_BASE(LUNWAC)
#define     UINT32_LUNDAC   UINT32_BASE(LUNDAC)
#define     UINT32_LUNQAC   UINT32_BASE(LUNQAC)
#define     UINT32_LUNOAC   UINT32_BASE(LUNOAC)
#define     UINT32_LUNSAC   UINT32_BASE(LUNSAC)

#define     UINT32_FAM2     UINT32_BASE(FAM2)
#define     UINT32_FAML     UINT32_BASE(FAML)
#define     UINT32_FAMS     UINT32_BASE(FAMS)

#define     UINT32_MAXL     UINT32_BASE(MAXL)

#define     UINT32_MINL     UINT32_BASE(MINL)

#define     UINT32_MODL     UINT32_BASE(MODL)
#define     UINT32_MOD2     UINT32_BASE(MOD2)
#define     UINT32_MODH     UINT32_BASE(MODH)
#define     UINT32_MODW     UINT32_BASE(MODW)
#define     UINT32_MODD     UINT32_BASE(MODD)
#define     UINT32_MODQ     UINT32_BASE(MODQ)

#define     UINT32_MUL2     UINT32_BASE(MUL2)
#define     UINT32_MULL     UINT32_BASE(MULL)
#define     UINT32_MULS     UINT32_BASE(MULS)
#define     UINT32_MULH     UINT32_BASE(MULH)
#define     UINT32_MULW     UINT32_BASE(MULW)
#define     UINT32_MULD     UINT32_BASE(MULD)
#define     UINT32_MULQ     UINT32_BASE(MULQ)

#define     UINT32_NEGL     UINT32_BASE(NEGL)
#define     UINT32_NEGS     UINT32_BASE(NEGS)
#define     UINT32_NEGH     UINT32_BASE(NEGH)
#define     UINT32_NEGW     UINT32_BASE(NEGW)
#define     UINT32_NEGD     UINT32_BASE(NEGD)
#define     UINT32_NEGQ     UINT32_BASE(NEGQ)

#define     UINT32_ORR1A    UINT32_BASE(ORR1A)
#define     UINT32_ORRAA    UINT32_BASE(ORRAA)
#define     UINT32_ORREA    UINT32_BASE(ORREA)
#define     UINT32_ORRN     UINT32_BASE(ORRN)
#define     UINT32_ORRS     UINT32_BASE(ORRS)
#define     UINT32_ORRTA    UINT32_BASE(ORRTA)

#define     UINT32_REVB     UINT32_BASE(REVB)
#define     UINT32_REVH     UINT32_BASE(REVH)
#define     UINT32_REVY     UINT32_BASE(REVY)

#define     UINT32_ROTL     UINT32_BASE(ROTL)
#define     UINT32_ROTR     UINT32_BASE(ROTR)

#define     UINT32_SEQD     UINT32_BASE(SEQD)
#define     UINT32_SEQQ     UINT32_BASE(SEQQ)

#define     UINT32_SETL     UINT32_BASE(SETL)
#define     UINT32_SETR     UINT32_BASE(SETR)

#define     UINT32_SHL2     UINT32_BASE(SHL2)
#define     UINT32_SHLL     UINT32_BASE(SHLL)
#define     UINT32_SHLR     UINT32_BASE(SHLR)
#define     UINT32_SHLS     UINT32_BASE(SHLS)

#define     UINT32_SHRS     UINT32_BASE(SHRS)

#define     UINT32_SILL     UINT32_BASE(SILL)
#define     UINT32_SILR     UINT32_BASE(SILR)

#define     UINT32_SIRL     UINT32_BASE(SIRL)
#define     UINT32_SIRR     UINT32_BASE(SIRR)

#define     UINT32_STR1A    UINT32_BASE(STR1A)
#define     UINT32_STRDA    UINT32_BASE(STRDA)
#define     UINT32_STREA    UINT32_BASE(STREA)
#define     UINT32_STROA    UINT32_BASE(STROA)
#define     UINT32_STRQA    UINT32_BASE(STRQA)
#define     UINT32_STRSA    UINT32_BASE(STRSA)
#define     UINT32_STRTA    UINT32_BASE(STRTA)
#define     UINT32_STRWA    UINT32_BASE(STRWA)

#define     UINT32_SUB2     UINT32_BASE(SUB2)
#define     UINT32_SUBL     UINT32_BASE(SUBL)
#define     UINT32_SUBS     UINT32_BASE(SUBS)
#define     UINT32_SUBH     UINT32_BASE(SUBH)
#define     UINT32_SUBW     UINT32_BASE(SUBW)
#define     UINT32_SUBD     UINT32_BASE(SUBD)
#define     UINT32_SUBQ     UINT32_BASE(SUBQ)
#define     UINT32_SUB1A    UINT32_BASE(SUB1A)
#define     UINT32_SUBAA    UINT32_BASE(SUBAA)
#define     UINT32_SUBEA    UINT32_BASE(SUBEA)
#define     UINT32_SUBTA    UINT32_BASE(SUBTA)

#define     UINT32_SUNNA    UINT32_BASE(SUNNA)
#define     UINT32_SUNLA    UINT32_BASE(SUNLA)
#define     UINT32_SUNRA    UINT32_BASE(SUNRA)
#define     UINT32_SUNWA    UINT32_BASE(SUNWA)
#define     UINT32_SUNDA    UINT32_BASE(SUNDA)
#define     UINT32_SUNQA    UINT32_BASE(SUNQA)

#define     UINT32_SWP1A    UINT32_BASE(SWP1A)
#define     UINT32_SWPAA    UINT32_BASE(SWPAA)
#define     UINT32_SWPEA    UINT32_BASE(SWPEA)
#define     UINT32_SWPTA    UINT32_BASE(SWPTA)

#define     UINT32_TSTS     UINT32_BASE(TSTS)
#define     UINT32_TSTY     UINT32_BASE(TSTY)

#define     UINT32_UNOS     UINT32_BASE(UNOS)

#define     UINT32_XEQ1A    UINT32_BASE(XEQ1A)
#define     UINT32_XEQAA    UINT32_BASE(XEQAA)
#define     UINT32_XEQEA    UINT32_BASE(XEQEA)
#define     UINT32_XEQTA    UINT32_BASE(XEQTA)

#define     UINT32_XOR1A    UINT32_BASE(XOR1A)
#define     UINT32_XORAA    UINT32_BASE(XORAA)
#define     UINT32_XOREA    UINT32_BASE(XOREA)
#define     UINT32_XORS     UINT32_BASE(XORS)
#define     UINT32_XORN     UINT32_BASE(XORN)
#define     UINT32_XORTA    UINT32_BASE(XORTA)

#define     UINT32_ZEQS     UINT32_BASE(ZEQS)
#define     UINT32_ZEQY     UINT32_BASE(ZEQY)

#define     UINT32_ZIPP     UINT32_BASE(ZIPP)

#define     UINT32_ZLTS     UINT32_BASE(ZLTS)
#define     UINT32_ZLTY     UINT32_BASE(ZLTY)

#define     UINT32_ZNES     UINT32_BASE(ZNES)
#define     UINT32_ZNEY     UINT32_BASE(ZNEY)


#define     INT32_ABSL      INT32_BASE(ABSL)
#define     INT32_ABSS      INT32_BASE(ABSS)
#define     INT32_ABSU      INT32_BASE(ABSU)
#define     INT32_ABSH      INT32_BASE(ABSH)
#define     INT32_ABSW      INT32_BASE(ABSW)
#define     INT32_ABSD      INT32_BASE(ABSD)
#define     INT32_ABSQ      INT32_BASE(ABSQ)

#define     INT32_ADD2      INT32_BASE(ADD2)
#define     INT32_ADDL      INT32_BASE(ADDL)
#define     INT32_ADDS      INT32_BASE(ADDS)
#define     INT32_ADDH      INT32_BASE(ADDH)
#define     INT32_ADDW      INT32_BASE(ADDW)
#define     INT32_ADDD      INT32_BASE(ADDD)
#define     INT32_ADDQ      INT32_BASE(ADDQ)
#define     INT32_ADD1A     INT32_BASE(ADD1A)
#define     INT32_ADDAA     INT32_BASE(ADDAA)
#define     INT32_ADDEA     INT32_BASE(ADDEA)
#define     INT32_ADDTA     INT32_BASE(ADDTA)

#define     INT32_AND1A     INT32_BASE(AND1A)
#define     INT32_ANDAA     INT32_BASE(ANDAA)
#define     INT32_ANDEA     INT32_BASE(ANDEA)
#define     INT32_ANDN      INT32_BASE(ANDN)
#define     INT32_ANDS      INT32_BASE(ANDS)
#define     INT32_ANDTA     INT32_BASE(ANDTA)

#define     INT32_ASTF      INT32_BASE(ASTF)
#define     INT32_ASTI      INT32_BASE(ASTI)
#define     INT32_ASTU      INT32_BASE(ASTU)
#define     INT32_ASTV      INT32_BASE(ASTV)

#define     INT32_ASWF      INT32_BASE(ASWF)
#define     INT32_ASWI      INT32_BASE(ASWI)
#define     INT32_ASWU      INT32_BASE(ASWU)

#define     INT32_AVGL      INT32_BASE(AVGL)

#define     INT32_BFG1      INT32_BASE(BFG1)

#define     INT32_BFC1      INT32_BASE(BFC1)

#define     INT32_BFS1      INT32_BASE(BFS1)

#define     INT32_CATL      INT32_BASE(CATL)

#define     INT32_CBNS      INT32_BASE(CBNS)
#define     INT32_CBNY      INT32_BASE(CBNY)

#define     INT32_CEQS      INT32_BASE(CEQS)
#define     INT32_CEQY      INT32_BASE(CEQY)

#define     INT32_CGES      INT32_BASE(CGES)
#define     INT32_CGEY      INT32_BASE(CGEY)

#define     INT32_CGTS      INT32_BASE(CGTS)
#define     INT32_CGTY      INT32_BASE(CGTY)

#define     INT32_CLES      INT32_BASE(CLES)
#define     INT32_CLEY      INT32_BASE(CLEY)

#define     INT32_CLTS      INT32_BASE(CLTS)
#define     INT32_CLTY      INT32_BASE(CLTY)

#define     INT32_CNBS      INT32_BASE(CNBS)
#define     INT32_CNBY      INT32_BASE(CNBY)

#define     INT32_CNES      INT32_BASE(CNES)
#define     INT32_CNEY      INT32_BASE(CNEY)

#define     INT32_CNT0      INT32_BASE(CNT0)
#define     INT32_CNT1      INT32_BASE(CNT1)
#define     INT32_CNTS      INT32_BASE(CNTS)

#define     INT32_CSZL      INT32_BASE(CSZL)
#define     INT32_CSZR      INT32_BASE(CSZR)

#define     INT32_CVBC      INT32_BASE(CVBC)
#define     INT32_CVBI      INT32_BASE(CVBI)
#define     INT32_CVBS      INT32_BASE(CVBS)
#define     INT32_CVBU      INT32_BASE(CVBU)
#define     INT32_CVBZ      INT32_BASE(CVBZ)

#define     INT32_CVDF      INT32_BASE(CVDF)
#define     INT32_CVDI      INT32_BASE(CVDI)
#define     INT32_CVDS      INT32_BASE(CVDS)
#define     INT32_CVDU      INT32_BASE(CVDU)
#define     INT32_CVDZ      INT32_BASE(CVDZ)

#define     INT32_CVHF      INT32_BASE(CVHF)
#define     INT32_CVHI      INT32_BASE(CVHI)
#define     INT32_CVHS      INT32_BASE(CVHS)
#define     INT32_CVHU      INT32_BASE(CVHU)
#define     INT32_CVHZ      INT32_BASE(CVHZ)

#define     INT32_CVWF      INT32_BASE(CVWF)
#define     INT32_CVWI      INT32_BASE(CVWI)
#define     INT32_CVWS      INT32_BASE(CVWS)
#define     INT32_CVWU      INT32_BASE(CVWU)
#define     INT32_CVWZ      INT32_BASE(CVWZ)

#define     INT32_DIFU      INT32_BASE(DIFU)
#define     INT32_DIFS      INT32_BASE(DIFS)

#define     INT32_DIVL      INT32_BASE(DIVL)
#define     INT32_DIV2      INT32_BASE(DIV2)
#define     INT32_DIVH      INT32_BASE(DIVH)
#define     INT32_DIVW      INT32_BASE(DIVW)
#define     INT32_DIVD      INT32_BASE(DIVD)
#define     INT32_DIVQ      INT32_BASE(DIVQ)

#define     INT32_DCRL      INT32_BASE(DCRL)
#define     INT32_DCR1A     INT32_BASE(DCR1A)
#define     INT32_DCRAA     INT32_BASE(DCRAA)
#define     INT32_DCREA     INT32_BASE(DCREA)
#define     INT32_DCRTA     INT32_BASE(DCRTA)

#define     INT32_DUPD      INT32_BASE(DUPD)
#define     INT32_DUPDAC    INT32_BASE(DUPDAC)
#define     INT32_DUPO      INT32_BASE(DUPO)
#define     INT32_DUPOAC    INT32_BASE(DUPOAC)
#define     INT32_DUPQ      INT32_BASE(DUPQ)
#define     INT32_DUPQAC    INT32_BASE(DUPQAC)
#define     INT32_DUPS      INT32_BASE(DUPS)
#define     INT32_DUPSAC    INT32_BASE(DUPSAC)
#define     INT32_DUPW      INT32_BASE(DUPW)
#define     INT32_DUPWAC    INT32_BASE(DUPWAC)

#define     INT32_GETL      INT32_BASE(GETL)
#define     INT32_GETR      INT32_BASE(GETR)

#define     INT32_ICRL      INT32_BASE(ICRL)
#define     INT32_ICR1A     INT32_BASE(ICR1A)
#define     INT32_ICRAA     INT32_BASE(ICRAA)
#define     INT32_ICREA     INT32_BASE(ICREA)
#define     INT32_ICRTA     INT32_BASE(ICRTA)

#define     INT32_INVS      INT32_BASE(INVS)
#define     INT32_INV1A     INT32_BASE(INV1A)
#define     INT32_INVAA     INT32_BASE(INVAA)
#define     INT32_INVEA     INT32_BASE(INVEA)
#define     INT32_INVTA     INT32_BASE(INVTA)

#define     INT32_LDR1AC    INT32_BASE(LDR1AC)
#define     INT32_LDRAAC    INT32_BASE(LDRAAC)
#define     INT32_LDRDAC    INT32_BASE(LDRDAC)
#define     INT32_LDROAC    INT32_BASE(LDROAC)
#define     INT32_LDRQAC    INT32_BASE(LDRQAC)
#define     INT32_LDRSAC    INT32_BASE(LDRSAC)
#define     INT32_LDRTAC    INT32_BASE(LDRTAC)
#define     INT32_LDRWAC    INT32_BASE(LDRWAC)

#define     INT32_LUNNAC    INT32_BASE(LUNNAC)
#define     INT32_LUNLAC    INT32_BASE(LUNLAC)
#define     INT32_LUNRAC    INT32_BASE(LUNRAC)
#define     INT32_LUNWAC    INT32_BASE(LUNWAC)
#define     INT32_LUNDAC    INT32_BASE(LUNDAC)
#define     INT32_LUNQAC    INT32_BASE(LUNQAC)
#define     INT32_LUNOAC    INT32_BASE(LUNOAC)
#define     INT32_LUNSAC    INT32_BASE(LUNSAC)

#define     INT32_FAM2      INT32_BASE(FAM2)
#define     INT32_FAML      INT32_BASE(FAML)
#define     INT32_FAMS      INT32_BASE(FAMS)

#define     INT32_MAXL      INT32_BASE(MAXL)

#define     INT32_MINL      INT32_BASE(MINL)

#define     INT32_MODL      INT32_BASE(MODL)
#define     INT32_MOD2      INT32_BASE(MOD2)
#define     INT32_MODH      INT32_BASE(MODH)
#define     INT32_MODW      INT32_BASE(MODW)
#define     INT32_MODD      INT32_BASE(MODD)
#define     INT32_MODQ      INT32_BASE(MODQ)

#define     INT32_MUL2      INT32_BASE(MUL2)
#define     INT32_MULL      INT32_BASE(MULL)
#define     INT32_MULS      INT32_BASE(MULS)
#define     INT32_MULH      INT32_BASE(MULH)
#define     INT32_MULW      INT32_BASE(MULW)
#define     INT32_MULD      INT32_BASE(MULD)
#define     INT32_MULQ      INT32_BASE(MULQ)

#define     INT32_NEGL      INT32_BASE(NEGL)
#define     INT32_NEGS      INT32_BASE(NEGS)
#define     INT32_NEGH      INT32_BASE(NEGH)
#define     INT32_NEGW      INT32_BASE(NEGW)
#define     INT32_NEGD      INT32_BASE(NEGD)
#define     INT32_NEGQ      INT32_BASE(NEGQ)

#define     INT32_ORR1A     INT32_BASE(ORR1A)
#define     INT32_ORRAA     INT32_BASE(ORRAA)
#define     INT32_ORREA     INT32_BASE(ORREA)
#define     INT32_ORRN      INT32_BASE(ORRN)
#define     INT32_ORRS      INT32_BASE(ORRS)
#define     INT32_ORRTA     INT32_BASE(ORRTA)

#define     INT32_REVB      INT32_BASE(REVB)
#define     INT32_REVH      INT32_BASE(REVH)
#define     INT32_REVY      INT32_BASE(REVY)

#define     INT32_SEQD      INT32_BASE(SEQD)
#define     INT32_SEQQ      INT32_BASE(SEQQ)

#define     INT32_SETL      INT32_BASE(SETL)
#define     INT32_SETR      INT32_BASE(SETR)

#define     INT32_SHL2      INT32_BASE(SHL2)
#define     INT32_SHLL      INT32_BASE(SHLL)
#define     INT32_SHLR      INT32_BASE(SHLR)
#define     INT32_SHLS      INT32_BASE(SHLS)

#define     INT32_SHRS      INT32_BASE(SHRS)

#define     INT32_SILL      INT32_BASE(SILL)
#define     INT32_SILR      INT32_BASE(SILR)

#define     INT32_SIRL      INT32_BASE(SIRL)
#define     INT32_SIRR      INT32_BASE(SIRR)

#define     INT32_STR1A     INT32_BASE(STR1A)
#define     INT32_STRDA     INT32_BASE(STRDA)
#define     INT32_STREA     INT32_BASE(STREA)
#define     INT32_STROA     INT32_BASE(STROA)
#define     INT32_STRQA     INT32_BASE(STRQA)
#define     INT32_STRSA     INT32_BASE(STRSA)
#define     INT32_STRTA     INT32_BASE(STRTA)
#define     INT32_STRWA     INT32_BASE(STRWA)

#define     INT32_SUB2      INT32_BASE(SUB2)
#define     INT32_SUBL      INT32_BASE(SUBL)
#define     INT32_SUBS      INT32_BASE(SUBS)
#define     INT32_SUBH      INT32_BASE(SUBH)
#define     INT32_SUBW      INT32_BASE(SUBW)
#define     INT32_SUBD      INT32_BASE(SUBD)
#define     INT32_SUBQ      INT32_BASE(SUBQ)
#define     INT32_SUB1A     INT32_BASE(SUB1A)
#define     INT32_SUBAA     INT32_BASE(SUBAA)
#define     INT32_SUBEA     INT32_BASE(SUBEA)
#define     INT32_SUBTA     INT32_BASE(SUBTA)

#define     INT32_SUNNA     INT32_BASE(SUNNA)
#define     INT32_SUNLA     INT32_BASE(SUNLA)
#define     INT32_SUNRA     INT32_BASE(SUNRA)
#define     INT32_SUNWA     INT32_BASE(SUNWA)
#define     INT32_SUNDA     INT32_BASE(SUNDA)
#define     INT32_SUNQA     INT32_BASE(SUNQA)

#define     INT32_SWP1A     INT32_BASE(SWP1A)
#define     INT32_SWPAA     INT32_BASE(SWPAA)
#define     INT32_SWPEA     INT32_BASE(SWPEA)
#define     INT32_SWPTA     INT32_BASE(SWPTA)

#define     INT32_TSTS      INT32_BASE(TSTS)
#define     INT32_TSTY      INT32_BASE(TSTY)

#define     INT32_UNOS      INT32_BASE(UNOS)

#define     INT32_XEQ1A     INT32_BASE(XEQ1A)
#define     INT32_XEQAA     INT32_BASE(XEQAA)
#define     INT32_XEQEA     INT32_BASE(XEQEA)
#define     INT32_XEQTA     INT32_BASE(XEQTA)

#define     INT32_XOR1A     INT32_BASE(XOR1A)
#define     INT32_XORAA     INT32_BASE(XORAA)
#define     INT32_XOREA     INT32_BASE(XOREA)
#define     INT32_XORS      INT32_BASE(XORS)
#define     INT32_XORN      INT32_BASE(XORN)
#define     INT32_XORTA     INT32_BASE(XORTA)

#define     INT32_ZEQS      INT32_BASE(ZEQS)
#define     INT32_ZEQY      INT32_BASE(ZEQY)

#define     INT32_ZGES      INT32_BASE(ZGES)
#define     INT32_ZGEY      INT32_BASE(ZGEY)

#define     INT32_ZGTS      INT32_BASE(ZGTS)
#define     INT32_ZGTY      INT32_BASE(ZGTY)

#define     INT32_ZLES      INT32_BASE(ZLES)
#define     INT32_ZLEY      INT32_BASE(ZLEY)

#define     INT32_ZLTS      INT32_BASE(ZLTS)
#define     INT32_ZLTY      INT32_BASE(ZLTY)

#define     INT32_ZNES      INT32_BASE(ZNES)
#define     INT32_ZNEY      INT32_BASE(ZNEY)


#define     UINT64_ADD2     UINT64_BASE(ADD2)
#define     UINT64_ADDL     UINT64_BASE(ADDL)
#define     UINT64_ADDS     UINT64_BASE(ADDS)
#define     UINT64_ADDH     UINT64_BASE(ADDH)
#define     UINT64_ADDW     UINT64_BASE(ADDW)
#define     UINT64_ADDD     UINT64_BASE(ADDD)
#define     UINT64_ADDQ     UINT64_BASE(ADDQ)
#define     UINT64_ADD1A    UINT64_BASE(ADD1A)
#define     UINT64_ADDAA    UINT64_BASE(ADDAA)
#define     UINT64_ADDEA    UINT64_BASE(ADDEA)
#define     UINT64_ADDTA    UINT64_BASE(ADDTA)

#define     UINT64_AND1A    UINT64_BASE(AND1A)
#define     UINT64_ANDAA    UINT64_BASE(ANDAA)
#define     UINT64_ANDEA    UINT64_BASE(ANDEA)
#define     UINT64_ANDN     UINT64_BASE(ANDN)
#define     UINT64_ANDS     UINT64_BASE(ANDS)
#define     UINT64_ANDTA    UINT64_BASE(ANDTA)

#define     UINT64_ASDF     UINT64_BASE(ASDF)
#define     UINT64_ASDI     UINT64_BASE(ASDI)
#define     UINT64_ASDU     UINT64_BASE(ASDU)

#define     UINT64_ASTF     UINT64_BASE(ASTF)
#define     UINT64_ASTI     UINT64_BASE(ASTI)
#define     UINT64_ASTU     UINT64_BASE(ASTU)
#define     UINT64_ASTV     UINT64_BASE(ASTV)

#define     UINT64_AVGL     UINT64_BASE(AVGL)

#define     UINT64_BFG1     UINT64_BASE(BFG1)

#define     UINT64_BFC1     UINT64_BASE(BFC1)

#define     UINT64_BFS1     UINT64_BASE(BFS1)

#define     UINT64_CATL     UINT64_BASE(CATL)

#define     UINT64_CBNS     UINT64_BASE(CBNS)
#define     UINT64_CBNY     UINT64_BASE(CBNY)

#define     UINT64_CEQS     UINT64_BASE(CEQS)
#define     UINT64_CEQY     UINT64_BASE(CEQY)

#define     UINT64_CGES     UINT64_BASE(CGES)
#define     UINT64_CGEY     UINT64_BASE(CGEY)

#define     UINT64_CGTS     UINT64_BASE(CGTS)
#define     UINT64_CGTY     UINT64_BASE(CGTY)

#define     UINT64_CLES     UINT64_BASE(CLES)
#define     UINT64_CLEY     UINT64_BASE(CLEY)

#define     UINT64_CLTS     UINT64_BASE(CLTS)
#define     UINT64_CLTY     UINT64_BASE(CLTY)

#define     UINT64_CNBS     UINT64_BASE(CNBS)
#define     UINT64_CNBY     UINT64_BASE(CNBY)

#define     UINT64_CNES     UINT64_BASE(CNES)
#define     UINT64_CNEY     UINT64_BASE(CNEY)

#define     UINT64_CNT0     UINT64_BASE(CNT0)
#define     UINT64_CNT1     UINT64_BASE(CNT1)
#define     UINT64_CNTS     UINT64_BASE(CNTS)

#define     UINT64_CSZL     UINT64_BASE(CSZL)
#define     UINT64_CSZR     UINT64_BASE(CSZR)

#define     UINT64_CVBC     UINT64_BASE(CVBC)
#define     UINT64_CVBI     UINT64_BASE(CVBI)
#define     UINT64_CVBS     UINT64_BASE(CVBS)
#define     UINT64_CVBU     UINT64_BASE(CVBU)
#define     UINT64_CVBZ     UINT64_BASE(CVBZ)

#define     UINT64_CVDF     UINT64_BASE(CVDF)
#define     UINT64_CVDI     UINT64_BASE(CVDI)
#define     UINT64_CVDS     UINT64_BASE(CVDS)
#define     UINT64_CVDU     UINT64_BASE(CVDU)
#define     UINT64_CVDZ     UINT64_BASE(CVDZ)

#define     UINT64_CVHF     UINT64_BASE(CVHF)
#define     UINT64_CVHI     UINT64_BASE(CVHI)
#define     UINT64_CVHS     UINT64_BASE(CVHS)
#define     UINT64_CVHU     UINT64_BASE(CVHU)
#define     UINT64_CVHZ     UINT64_BASE(CVHZ)

#define     UINT64_CVWF     UINT64_BASE(CVWF)
#define     UINT64_CVWI     UINT64_BASE(CVWI)
#define     UINT64_CVWS     UINT64_BASE(CVWS)
#define     UINT64_CVWU     UINT64_BASE(CVWU)
#define     UINT64_CVWZ     UINT64_BASE(CVWZ)

#define     UINT64_DIFU     UINT64_BASE(DIFU)
#define     UINT64_DIFS     UINT64_BASE(DIFS)

#define     UINT64_DIVL     UINT64_BASE(DIVL)
#define     UINT64_DIV2     UINT64_BASE(DIV2)
#define     UINT64_DIVH     UINT64_BASE(DIVH)
#define     UINT64_DIVW     UINT64_BASE(DIVW)
#define     UINT64_DIVD     UINT64_BASE(DIVD)
#define     UINT64_DIVQ     UINT64_BASE(DIVQ)

#define     UINT64_DCRL     UINT64_BASE(DCRL)
#define     UINT64_DCR1A    UINT64_BASE(DCR1A)
#define     UINT64_DCRAA    UINT64_BASE(DCRAA)
#define     UINT64_DCREA    UINT64_BASE(DCREA)
#define     UINT64_DCRTA    UINT64_BASE(DCRTA)

#define     UINT64_DUPD     UINT64_BASE(DUPD)
#define     UINT64_DUPDAC   UINT64_BASE(DUPDAC)
#define     UINT64_DUPO     UINT64_BASE(DUPO)
#define     UINT64_DUPOAC   UINT64_BASE(DUPOAC)
#define     UINT64_DUPQ     UINT64_BASE(DUPQ)
#define     UINT64_DUPQAC   UINT64_BASE(DUPQAC)
#define     UINT64_DUPS     UINT64_BASE(DUPS)
#define     UINT64_DUPSAC   UINT64_BASE(DUPSAC)
#define     UINT64_DUPW     UINT64_BASE(DUPW)
#define     UINT64_DUPWAC   UINT64_BASE(DUPWAC)

#define     UINT64_GETL     UINT64_BASE(GETL)
#define     UINT64_GETR     UINT64_BASE(GETR)

#define     UINT64_ICRL     UINT64_BASE(ICRL)
#define     UINT64_ICR1A    UINT64_BASE(ICR1A)
#define     UINT64_ICRAA    UINT64_BASE(ICRAA)
#define     UINT64_ICREA    UINT64_BASE(ICREA)
#define     UINT64_ICRTA    UINT64_BASE(ICRTA)

#define     UINT64_INVS     UINT64_BASE(INVS)
#define     UINT64_INV1A    UINT64_BASE(INV1A)
#define     UINT64_INVAA    UINT64_BASE(INVAA)
#define     UINT64_INVEA    UINT64_BASE(INVEA)
#define     UINT64_INVTA    UINT64_BASE(INVTA)

#define     UINT64_LDR1AC   UINT64_BASE(LDR1AC)
#define     UINT64_LDRAAC   UINT64_BASE(LDRAAC)
#define     UINT64_LDRDAC   UINT64_BASE(LDRDAC)
#define     UINT64_LDROAC   UINT64_BASE(LDROAC)
#define     UINT64_LDRQAC   UINT64_BASE(LDRQAC)
#define     UINT64_LDRSAC   UINT64_BASE(LDRSAC)
#define     UINT64_LDRTAC   UINT64_BASE(LDRTAC)

#define     UINT64_LUNNAC   UINT64_BASE(LUNNAC)
#define     UINT64_LUNLAC   UINT64_BASE(LUNLAC)
#define     UINT64_LUNRAC   UINT64_BASE(LUNRAC)
#define     UINT64_LUNWAC   UINT64_BASE(LUNWAC)
#define     UINT64_LUNDAC   UINT64_BASE(LUNDAC)
#define     UINT64_LUNQAC   UINT64_BASE(LUNQAC)
#define     UINT64_LUNOAC   UINT64_BASE(LUNOAC)
#define     UINT64_LUNSAC   UINT64_BASE(LUNSAC)

#define     UINT64_FAM2     UINT64_BASE(FAM2)
#define     UINT64_FAML     UINT64_BASE(FAML)
#define     UINT64_FAMS     UINT64_BASE(FAMS)

#define     UINT64_MAXL     UINT64_BASE(MAXL)

#define     UINT64_MINL     UINT64_BASE(MINL)

#define     UINT64_MODL     UINT64_BASE(MODL)
#define     UINT64_MOD2     UINT64_BASE(MOD2)
#define     UINT64_MODH     UINT64_BASE(MODH)
#define     UINT64_MODW     UINT64_BASE(MODW)
#define     UINT64_MODD     UINT64_BASE(MODD)
#define     UINT64_MODQ     UINT64_BASE(MODQ)

#define     UINT64_MUL2     UINT64_BASE(MUL2)
#define     UINT64_MULL     UINT64_BASE(MULL)
#define     UINT64_MULS     UINT64_BASE(MULS)
#define     UINT64_MULH     UINT64_BASE(MULH)
#define     UINT64_MULW     UINT64_BASE(MULW)
#define     UINT64_MULD     UINT64_BASE(MULD)
#define     UINT64_MULQ     UINT64_BASE(MULQ)

#define     UINT64_NEGL     UINT64_BASE(NEGL)
#define     UINT64_NEGS     UINT64_BASE(NEGS)
#define     UINT64_NEGH     UINT64_BASE(NEGH)
#define     UINT64_NEGW     UINT64_BASE(NEGW)
#define     UINT64_NEGD     UINT64_BASE(NEGD)
#define     UINT64_NEGQ     UINT64_BASE(NEGQ)

#define     UINT64_ORR1A    UINT64_BASE(ORR1A)
#define     UINT64_ORRAA    UINT64_BASE(ORRAA)
#define     UINT64_ORREA    UINT64_BASE(ORREA)
#define     UINT64_ORRN     UINT64_BASE(ORRN)
#define     UINT64_ORRS     UINT64_BASE(ORRS)
#define     UINT64_ORRTA    UINT64_BASE(ORRTA)

#define     UINT64_REVB     UINT64_BASE(REVB)
#define     UINT64_REVH     UINT64_BASE(REVH)
#define     UINT64_REVW     UINT64_BASE(REVW)
#define     UINT64_REVY     UINT64_BASE(REVY)

#define     UINT64_ROTL     UINT64_BASE(ROTL)
#define     UINT64_ROTR     UINT64_BASE(ROTR)

#define     UINT64_SEQQ     UINT64_BASE(SEQQ)

#define     UINT64_SETL     UINT64_BASE(SETL)
#define     UINT64_SETR     UINT64_BASE(SETR)

#define     UINT64_SHL2     UINT64_BASE(SHL2)
#define     UINT64_SHLL     UINT64_BASE(SHLL)
#define     UINT64_SHLR     UINT64_BASE(SHLR)
#define     UINT64_SHLS     UINT64_BASE(SHLS)

#define     UINT64_SHRS     UINT64_BASE(SHRS)

#define     UINT64_SILL     UINT64_BASE(SILL)
#define     UINT64_SILR     UINT64_BASE(SILR)

#define     UINT64_SIRL     UINT64_BASE(SIRL)
#define     UINT64_SIRR     UINT64_BASE(SIRR)

#define     UINT64_STR1A    UINT64_BASE(STR1A)
#define     UINT64_STRDA    UINT64_BASE(STRDA)
#define     UINT64_STREA    UINT64_BASE(STREA)
#define     UINT64_STROA    UINT64_BASE(STROA)
#define     UINT64_STRQA    UINT64_BASE(STRQA)
#define     UINT64_STRSA    UINT64_BASE(STRSA)
#define     UINT64_STRTA    UINT64_BASE(STRTA)
#define     UINT64_STRWA    UINT64_BASE(STRWA)

#define     UINT64_SUB2     UINT64_BASE(SUB2)
#define     UINT64_SUBL     UINT64_BASE(SUBL)
#define     UINT64_SUBS     UINT64_BASE(SUBS)
#define     UINT64_SUBH     UINT64_BASE(SUBH)
#define     UINT64_SUBW     UINT64_BASE(SUBW)
#define     UINT64_SUBD     UINT64_BASE(SUBD)
#define     UINT64_SUBQ     UINT64_BASE(SUBQ)
#define     UINT64_SUB1A    UINT64_BASE(SUB1A)
#define     UINT64_SUBAA    UINT64_BASE(SUBAA)
#define     UINT64_SUBEA    UINT64_BASE(SUBEA)
#define     UINT64_SUBTA    UINT64_BASE(SUBTA)


#define     UINT64_SUNNA    UINT64_BASE(SUNNA)
#define     UINT64_SUNLA    UINT64_BASE(SUNLA)
#define     UINT64_SUNRA    UINT64_BASE(SUNRA)
#define     UINT64_SUNWA    UINT64_BASE(SUNWA)
#define     UINT64_SUNDA    UINT64_BASE(SUNDA)
#define     UINT64_SUNQA    UINT64_BASE(SUNQA)

#define     UINT64_SWP1A    UINT64_BASE(SWP1A)
#define     UINT64_SWPAA    UINT64_BASE(SWPAA)
#define     UINT64_SWPEA    UINT64_BASE(SWPEA)
#define     UINT64_SWPTA    UINT64_BASE(SWPTA)

#define     UINT64_TSTS     UINT64_BASE(TSTS)
#define     UINT64_TSTY     UINT64_BASE(TSTY)

#define     UINT64_UNOS     UINT64_BASE(UNOS)

#define     UINT64_XEQ1A    UINT64_BASE(XEQ1A)
#define     UINT64_XEQAA    UINT64_BASE(XEQAA)
#define     UINT64_XEQEA    UINT64_BASE(XEQEA)
#define     UINT64_XEQTA    UINT64_BASE(XEQTA)

#define     UINT64_XOR1A    UINT64_BASE(XOR1A)
#define     UINT64_XORAA    UINT64_BASE(XORAA)
#define     UINT64_XOREA    UINT64_BASE(XOREA)
#define     UINT64_XORS     UINT64_BASE(XORS)
#define     UINT64_XORN     UINT64_BASE(XORN)
#define     UINT64_XORTA    UINT64_BASE(XORTA)

#define     UINT64_ZEQS     UINT64_BASE(ZEQS)
#define     UINT64_ZEQY     UINT64_BASE(ZEQY)

#define     UINT64_ZLTS     UINT64_BASE(ZLTS)
#define     UINT64_ZLTY     UINT64_BASE(ZLTY)

#define     UINT64_ZNES     UINT64_BASE(ZNES)
#define     UINT64_ZNEY     UINT64_BASE(ZNEY)

#define     INT64_ABSL      INT64_BASE(ABSL)
#define     INT64_ABSS      INT64_BASE(ABSS)
#define     INT64_ABSU      INT64_BASE(ABSU)
#define     INT64_ABSH      INT64_BASE(ABSH)
#define     INT64_ABSW      INT64_BASE(ABSW)
#define     INT64_ABSD      INT64_BASE(ABSD)
#define     INT64_ABSQ      INT64_BASE(ABSQ)

#define     INT64_ADD2      INT64_BASE(ADD2)
#define     INT64_ADDL      INT64_BASE(ADDL)
#define     INT64_ADDS      INT64_BASE(ADDS)
#define     INT64_ADDH      INT64_BASE(ADDH)
#define     INT64_ADDW      INT64_BASE(ADDW)
#define     INT64_ADDD      INT64_BASE(ADDD)
#define     INT64_ADDQ      INT64_BASE(ADDQ)
#define     INT64_ADD1A     INT64_BASE(ADD1A)
#define     INT64_ADDAA     INT64_BASE(ADDAA)
#define     INT64_ADDEA     INT64_BASE(ADDEA)
#define     INT64_ADDTA     INT64_BASE(ADDTA)

#define     INT64_AND1A     INT64_BASE(AND1A)
#define     INT64_ANDAA     INT64_BASE(ANDAA)
#define     INT64_ANDEA     INT64_BASE(ANDEA)
#define     INT64_ANDN      INT64_BASE(ANDN)
#define     INT64_ANDS      INT64_BASE(ANDS)
#define     INT64_ANDTA     INT64_BASE(ANDTA)

#define     INT64_ASDF      INT64_BASE(ASDF)
#define     INT64_ASDI      INT64_BASE(ASDI)
#define     INT64_ASDU      INT64_BASE(ASDU)

#define     INT64_ASTF      INT64_BASE(ASTF)
#define     INT64_ASTI      INT64_BASE(ASTI)
#define     INT64_ASTU      INT64_BASE(ASTU)
#define     INT64_ASTV      INT64_BASE(ASTV)

#define     INT64_AVGL      INT64_BASE(AVGL)

#define     INT64_BFG1      INT64_BASE(BFG1)

#define     INT64_BFC1      INT64_BASE(BFC1)

#define     INT64_BFS1      INT64_BASE(BFS1)

#define     INT64_CATL      INT64_BASE(CATL)

#define     INT64_CBNS      INT64_BASE(CBNS)
#define     INT64_CBNY      INT64_BASE(CBNY)

#define     INT64_CEQS      INT64_BASE(CEQS)
#define     INT64_CEQY      INT64_BASE(CEQY)

#define     INT64_CGES      INT64_BASE(CGES)
#define     INT64_CGEY      INT64_BASE(CGEY)

#define     INT64_CGTS      INT64_BASE(CGTS)
#define     INT64_CGTY      INT64_BASE(CGTY)

#define     INT64_CLES      INT64_BASE(CLES)
#define     INT64_CLEY      INT64_BASE(CLEY)

#define     INT64_CLTS      INT64_BASE(CLTS)
#define     INT64_CLTY      INT64_BASE(CLTY)

#define     INT64_CNBS      INT64_BASE(CNBS)
#define     INT64_CNBY      INT64_BASE(CNBY)

#define     INT64_CNES      INT64_BASE(CNES)
#define     INT64_CNEY      INT64_BASE(CNEY)

#define     INT64_CNT0      INT64_BASE(CNT0)
#define     INT64_CNT1      INT64_BASE(CNT1)
#define     INT64_CNTS      INT64_BASE(CNTS)

#define     INT64_CSZL      INT64_BASE(CSZL)
#define     INT64_CSZR      INT64_BASE(CSZR)

#define     INT64_CVBC      INT64_BASE(CVBC)
#define     INT64_CVBI      INT64_BASE(CVBI)
#define     INT64_CVBS      INT64_BASE(CVBS)
#define     INT64_CVBU      INT64_BASE(CVBU)
#define     INT64_CVBZ      INT64_BASE(CVBZ)

#define     INT64_CVDF      INT64_BASE(CVDF)
#define     INT64_CVDI      INT64_BASE(CVDI)
#define     INT64_CVDS      INT64_BASE(CVDS)
#define     INT64_CVDU      INT64_BASE(CVDU)
#define     INT64_CVDZ      INT64_BASE(CVDZ)

#define     INT64_CVHF      INT64_BASE(CVHF)
#define     INT64_CVHI      INT64_BASE(CVHI)
#define     INT64_CVHS      INT64_BASE(CVHS)
#define     INT64_CVHU      INT64_BASE(CVHU)
#define     INT64_CVHZ      INT64_BASE(CVHZ)

#define     INT64_CVWF      INT64_BASE(CVWF)
#define     INT64_CVWI      INT64_BASE(CVWI)
#define     INT64_CVWS      INT64_BASE(CVWS)
#define     INT64_CVWU      INT64_BASE(CVWU)
#define     INT64_CVWZ      INT64_BASE(CVWZ)

#define     INT64_DIFU      INT64_BASE(DIFU)
#define     INT64_DIFS      INT64_BASE(DIFS)

#define     INT64_DIVL      INT64_BASE(DIVL)
#define     INT64_DIV2      INT64_BASE(DIV2)
#define     INT64_DIVH      INT64_BASE(DIVH)
#define     INT64_DIVW      INT64_BASE(DIVW)
#define     INT64_DIVD      INT64_BASE(DIVD)
#define     INT64_DIVQ      INT64_BASE(DIVQ)

#define     INT64_DCRL      INT64_BASE(DCRL)
#define     INT64_DCR1A     INT64_BASE(DCR1A)
#define     INT64_DCRAA     INT64_BASE(DCRAA)
#define     INT64_DCREA     INT64_BASE(DCREA)
#define     INT64_DCRTA     INT64_BASE(DCRTA)

#define     INT64_DUPD      INT64_BASE(DUPD)
#define     INT64_DUPDAC    INT64_BASE(DUPDAC)
#define     INT64_DUPO      INT64_BASE(DUPO)
#define     INT64_DUPOAC    INT64_BASE(DUPOAC)
#define     INT64_DUPQ      INT64_BASE(DUPQ)
#define     INT64_DUPQAC    INT64_BASE(DUPQAC)
#define     INT64_DUPS      INT64_BASE(DUPS)
#define     INT64_DUPSAC    INT64_BASE(DUPSAC)
#define     INT64_DUPW      INT64_BASE(DUPW)
#define     INT64_DUPWAC    INT64_BASE(DUPWAC)

#define     INT64_GETL      INT64_BASE(GETL)
#define     INT64_GETR      INT64_BASE(GETR)

#define     INT64_ICRL      INT64_BASE(ICRL)
#define     INT64_ICR1A     INT64_BASE(ICR1A)
#define     INT64_ICRAA     INT64_BASE(ICRAA)
#define     INT64_ICREA     INT64_BASE(ICREA)
#define     INT64_ICRTA     INT64_BASE(ICRTA)

#define     INT64_INVS      INT64_BASE(INVS)
#define     INT64_INV1A     INT64_BASE(INV1A)
#define     INT64_INVAA     INT64_BASE(INVAA)
#define     INT64_INVEA     INT64_BASE(INVEA)
#define     INT64_INVTA     INT64_BASE(INVTA)

#define     INT64_LDR1AC    INT64_BASE(LDR1AC)
#define     INT64_LDRAAC    INT64_BASE(LDRAAC)
#define     INT64_LDRDAC    INT64_BASE(LDRDAC)
#define     INT64_LDROAC    INT64_BASE(LDROAC)
#define     INT64_LDRQAC    INT64_BASE(LDRQAC)
#define     INT64_LDRSAC    INT64_BASE(LDRSAC)
#define     INT64_LDRTAC    INT64_BASE(LDRTAC)

#define     INT64_LUNNAC    INT64_BASE(LUNNAC)
#define     INT64_LUNLAC    INT64_BASE(LUNLAC)
#define     INT64_LUNRAC    INT64_BASE(LUNRAC)
#define     INT64_LUNWAC    INT64_BASE(LUNWAC)
#define     INT64_LUNDAC    INT64_BASE(LUNDAC)
#define     INT64_LUNQAC    INT64_BASE(LUNQAC)
#define     INT64_LUNOAC    INT64_BASE(LUNOAC)
#define     INT64_LUNSAC    INT64_BASE(LUNSAC)

#define     INT64_FAM2      INT64_BASE(FAM2)
#define     INT64_FAML      INT64_BASE(FAML)
#define     INT64_FAMS      INT64_BASE(FAMS)

#define     INT64_MAXL      INT64_BASE(MAXL)

#define     INT64_MINL      INT64_BASE(MINL)

#define     INT64_MODL      INT64_BASE(MODL)
#define     INT64_MOD2      INT64_BASE(MOD2)
#define     INT64_MODH      INT64_BASE(MODH)
#define     INT64_MODW      INT64_BASE(MODW)
#define     INT64_MODD      INT64_BASE(MODD)
#define     INT64_MODQ      INT64_BASE(MODQ)

#define     INT64_MUL2      INT64_BASE(MUL2)
#define     INT64_MULL      INT64_BASE(MULL)
#define     INT64_MULS      INT64_BASE(MULS)
#define     INT64_MULH      INT64_BASE(MULH)
#define     INT64_MULW      INT64_BASE(MULW)
#define     INT64_MULD      INT64_BASE(MULD)
#define     INT64_MULQ      INT64_BASE(MULQ)

#define     INT64_NEGL      INT64_BASE(NEGL)
#define     INT64_NEGS      INT64_BASE(NEGS)
#define     INT64_NEGH      INT64_BASE(NEGH)
#define     INT64_NEGW      INT64_BASE(NEGW)
#define     INT64_NEGD      INT64_BASE(NEGD)
#define     INT64_NEGQ      INT64_BASE(NEGQ)

#define     INT64_ORR1A     INT64_BASE(ORR1A)
#define     INT64_ORRAA     INT64_BASE(ORRAA)
#define     INT64_ORREA     INT64_BASE(ORREA)
#define     INT64_ORRN      INT64_BASE(ORRN)
#define     INT64_ORRS      INT64_BASE(ORRS)
#define     INT64_ORRTA     INT64_BASE(ORRTA)

#define     INT64_REVB      INT64_BASE(REVB)
#define     INT64_REVH      INT64_BASE(REVH)
#define     INT64_REVW      INT64_BASE(REVW)
#define     INT64_REVY      INT64_BASE(REVY)

#define     INT64_SEQQ      INT64_BASE(SEQQ)

#define     INT64_SETL      INT64_BASE(SETL)
#define     INT64_SETR      INT64_BASE(SETR)

#define     INT64_SHL2      INT64_BASE(SHL2)
#define     INT64_SHLL      INT64_BASE(SHLL)
#define     INT64_SHLR      INT64_BASE(SHLR)
#define     INT64_SHLS      INT64_BASE(SHLS)

#define     INT64_SHRS      INT64_BASE(SHRS)

#define     INT64_SILL      INT64_BASE(SILL)
#define     INT64_SILR      INT64_BASE(SILR)

#define     INT64_SIRL      INT64_BASE(SIRL)
#define     INT64_SIRR      INT64_BASE(SIRR)

#define     INT64_STR1A     INT64_BASE(STR1A)
#define     INT64_STRDA     INT64_BASE(STRDA)
#define     INT64_STREA     INT64_BASE(STREA)
#define     INT64_STROA     INT64_BASE(STROA)
#define     INT64_STRQA     INT64_BASE(STRQA)
#define     INT64_STRSA     INT64_BASE(STRSA)
#define     INT64_STRTA     INT64_BASE(STRTA)
#define     INT64_STRWA     INT64_BASE(STRWA)

#define     INT64_SUB2      INT64_BASE(SUB2)
#define     INT64_SUBL      INT64_BASE(SUBL)
#define     INT64_SUBS      INT64_BASE(SUBS)
#define     INT64_SUBH      INT64_BASE(SUBH)
#define     INT64_SUBW      INT64_BASE(SUBW)
#define     INT64_SUBD      INT64_BASE(SUBD)
#define     INT64_SUBQ      INT64_BASE(SUBQ)
#define     INT64_SUB1A     INT64_BASE(SUB1A)
#define     INT64_SUBAA     INT64_BASE(SUBAA)
#define     INT64_SUBEA     INT64_BASE(SUBEA)
#define     INT64_SUBTA     INT64_BASE(SUBTA)

#define     INT64_SUNNA     INT64_BASE(SUNNA)
#define     INT64_SUNLA     INT64_BASE(SUNLA)
#define     INT64_SUNRA     INT64_BASE(SUNRA)
#define     INT64_SUNWA     INT64_BASE(SUNWA)
#define     INT64_SUNDA     INT64_BASE(SUNDA)
#define     INT64_SUNQA     INT64_BASE(SUNQA)

#define     INT64_SWP1A     INT64_BASE(SWP1A)
#define     INT64_SWPAA     INT64_BASE(SWPAA)
#define     INT64_SWPEA     INT64_BASE(SWPEA)
#define     INT64_SWPTA     INT64_BASE(SWPTA)

#define     INT64_TSTS      INT64_BASE(TSTS)
#define     INT64_TSTY      INT64_BASE(TSTY)

#define     INT64_UNOS      INT64_BASE(UNOS)

#define     INT64_XEQ1A     INT64_BASE(XEQ1A)
#define     INT64_XEQAA     INT64_BASE(XEQAA)
#define     INT64_XEQEA     INT64_BASE(XEQEA)
#define     INT64_XEQTA     INT64_BASE(XEQTA)

#define     INT64_XOR1A     INT64_BASE(XOR1A)
#define     INT64_XORAA     INT64_BASE(XORAA)
#define     INT64_XOREA     INT64_BASE(XOREA)
#define     INT64_XORS      INT64_BASE(XORS)
#define     INT64_XORN      INT64_BASE(XORN)
#define     INT64_XORTA     INT64_BASE(XORTA)

#define     INT64_ZEQS      INT64_BASE(ZEQS)
#define     INT64_ZEQY      INT64_BASE(ZEQY)

#define     INT64_ZGES      INT64_BASE(ZGES)
#define     INT64_ZGEY      INT64_BASE(ZGEY)

#define     INT64_ZGTS      INT64_BASE(ZGTS)
#define     INT64_ZGTY      INT64_BASE(ZGTY)

#define     INT64_ZLES      INT64_BASE(ZLES)
#define     INT64_ZLEY      INT64_BASE(ZLEY)

#define     INT64_ZLTS      INT64_BASE(ZLTS)
#define     INT64_ZLTY      INT64_BASE(ZLTY)

#define     INT64_ZNES      INT64_BASE(ZNES)
#define     INT64_ZNEY      INT64_BASE(ZNEY)

#if MY_ISA == ISA_ARM
#   include "a64op.h"

#elif MY_ISA == ISA_X86
#   include "x64op.h"

#endif

/*
    catldbu(l, r) takes two Df1 HVAs and returns a Qdf1.
    The __vectorcall spec says this means 'l' and 'r'
    should be passed in xmm0, and xmm1, respectively, and
    the result returned in xmm0, yet the following is what
    godbolt outputs with '-O2 -std:c11 -arch:SSE2 -Gv',
    the last argument supposedly implicitly declaring all
    functions `__vectorcall`. When that didn't work,
    PUBLIC was changed from an object macro to the current
    form, which formats the declaration in whatever screwed
    up method is syntactically valid, and this of course
    had no effect:

        catldbu PROC
            ms x64 -Gv (msvc)
                mov         QWORD PTR [rsp+24], r8
                mov         rax,                rcx
                vmovsd      xmm1,               QWORD PTR r$[rsp]
                mov         QWORD PTR [rsp+16], rdx
                vmovsd      xmm0,               QWORD PTR l$[rsp]
                vunpcklpd   xmm1, xmm0, xmm1
                vmovdqu     XMMWORD PTR [rcx], xmm1
                ret 0

            sysv x64 (clang)
                vmovlhps        xmm0, xmm0, xmm1

    The output should be identical to clang's, which uses
    vmovlhps to move the lower half of xmm1 to the upper
    half of xmm0, which is exactly what catl is supposed
    to for 64 bit operands...
*/

#if defined(_MSC_VER)
#   include "winsync.h"
#elif defined(__GNUC__)
#   include "gnusync.h"
#endif

//  TODO: add the 128 bit scalar ops
//  TODO: preemptively add the 256/512 bit vector op defs
//  TODO: implement the remaining 32 bit vector ops
//  TODO: fix parameter names

#if _ENTER_ABSL
{
#endif
/*  ABSolute value (truncated)

Compute the absolute value of each signed integer in the
operand.
*/

#define     absl(X) (absl_funcof(X)(X))
#define     absl_funcof(X, ...)  \
FUNCOF(             \
    absl, (   X   ),\
    BDI,  /* TGK */ \
    BWI,  /* TGW */ \
    BDI,  /* TGD */ \
    BDI,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     abslbi   INT8_ABSL
#define     abslbc   CHAR_ABSL
#define     abslhi  INT16_ABSL
#define     abslwi  INT32_ABSL
#define     absldi  INT64_ABSL
#if DWRD_NLONG == 2
#   define  abslli LONG_ABSL
#elif QUAD_NLLONG == 2
#   define  abslli LLONG_ABSL
#else
#endif

#define     abslwbi   VWBI_ABSL
#define     abslwbc   VWBC_ABSL
#define     abslwhi   VWHI_ABSL
#define     abslwwi   VWWI_ABSL

#define     absldbi   VDBI_ABSL
#define     absldbc   VDBC_ABSL
#define     absldhi   VDHI_ABSL
#define     absldwi   VDWI_ABSL
#define     abslddi   VDDI_ABSL

#define     abslqbi   VQBI_ABSL
#define     abslqbc   VQBC_ABSL
#define     abslqhi   VQHI_ABSL
#define     abslqwi   VQWI_ABSL
#define     abslqdi   VQDI_ABSL
#if _LEAVE_ABSL
}
#endif

#if _ENTER_ABSS
{
#endif
/*  ABSolute value (saturated)

Compute the absolute value of each signed integer in the
operand.
*/

#define     abss(X) (abss_funcof(X)(X))
#define     abss_funcof(X, ...)  \
FUNCOF(             \
    abss, (   X   ),\
    BDI,  /* TGK */ \
    BWI,  /* TGW */ \
    BDI,  /* TGD */ \
    BDI,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     abssbi   INT8_ABSS
#define     abssbc   CHAR_ABSS
#define     absshi  INT16_ABSS
#define     absswi  INT32_ABSS
#define     abssdi  INT64_ABSS
#if DWRD_NLONG == 2
#   define  abssli LONG_ABSS
#elif QUAD_NLLONG == 2
#   define  abssli LLONG_ABSS
#else
#endif

#define     absswbi   VWBI_ABSS
#define     absswbc   VWBC_ABSS
#define     absswhi   VWHI_ABSS
#define     absswwi   VWWI_ABSS

#define     abssdbi   VDBI_ABSS
#define     abssdbc   VDBC_ABSS
#define     abssdhi   VDHI_ABSS
#define     abssdwi   VDWI_ABSS
#define     abssddi   VDDI_ABSS

#define     abssqbi   VQBI_ABSS
#define     abssqbc   VQBC_ABSS
#define     abssqhi   VQHI_ABSS
#define     abssqwi   VQWI_ABSS
#define     abssqdi   VQDI_ABSS
#if _LEAVE_ABSS
}
#endif

#if _ENTER_ABSU
{
#endif
/*  ABSolute value (unsigned)

Compute absolute value as a saturated, unsigned result of
equivalent width.

TODO: debate renaming to absz since float ops saturate the
result
*/

#define     absu(X) (absu_funcof(X)(X))
#define     absu_funcof(X, ...)  \
FUNCOF(             \
    absu, (   X   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     absubi   INT8_ABSU
#define     absubc   CHAR_ABSU
#define     absuhi  INT16_ABSU
#define     absuhf  FLT16_ABSU
#define     absuwi  INT32_ABSU
#define     absuwf    FLT_ABSU
#define     absudi  INT64_ABSU
#define     absudf    DBL_ABSU
#if DWRD_NLONG == 2
#   define  absuli    LONG_ABSU
#elif QUAD_NLLONG == 2
#   define  absuli   LLONG_ABSU
#else
#   define  absuqi   LLONG_ABSU
#   define  absuqf    LDBL_ABSU
#endif

#define     absuwbi   VWBI_ABSU
#define     absuwbc   VWBC_ABSU
#define     absuwhi   VWHI_ABSU
#define     absuwhf   VWHF_ABSU
#define     absuwwi   VWWI_ABSU
#define     absuwwf   VWWF_ABSU

#define     absudbi   VDBI_ABSU
#define     absudbc   VDBC_ABSU
#define     absudhi   VDHI_ABSU
#define     absudhf   VDHF_ABSU
#define     absudwi   VDWI_ABSU
#define     absudwf   VDWF_ABSU
#define     absuddi   VDDI_ABSU
#define     absuddf   VDDF_ABSU

#define     absuqbi   VQBI_ABSU
#define     absuqbc   VQBC_ABSU
#define     absuqhi   VQHI_ABSU
#define     absuqhf   VQHF_ABSU
#define     absuqwi   VQWI_ABSU
#define     absuqwf   VQWF_ABSU
#define     absuqdi   VQDI_ABSU
#define     absuqdf   VQDF_ABSU
#if _LEAVE_ABSU
}
#endif

#if _ENTER_ABSH
{
#endif
/*  ABSolute value (as flt16_t)

Compute the absolute value of a signed number and convert
the result, if necessary, to a binary16 float.

If the absolute value of the operand cannot be represented
exactly as a binary16 float, the result is implementation
defined.
*/

#define     absh(X) (absh_funcof(X)(X))
#define     absh_funcof(X, ...)  \
FUNCOF(             \
    absh, (   X   ),\
    BDS,  /* TGK */ \
    BHS,  /* TGW */ \
    BWS,  /* TGD */ \
    HDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     abshbi    INT8_ABSH
#define     abshbc    CHAR_ABSH
#define     abshhi   INT16_ABSH
#define     abshhf   FLT16_ABSH
#define     abshwi   INT32_ABSH
#define     abshwf     FLT_ABSH
#define     abshdi   INT64_ABSH
#define     abshdf     DBL_ABSH
#if DWRD_NLONG == 2
#   define  abshli   LONG_ABSH
#elif QUAD_NLLONG == 2
#   define  abshli  LLONG_ABSH
#else
#   define  abshqi  LLONG_ABSH
#   define  abshqf   LDBL_ABSH
#endif

#define     abshwbi  VWBI_ABSH
#define     abshwbc  VWBC_ABSH
#define     abshwhi  VWHI_ABSH
#define     abshwhf  VWHF_ABSH

#define     abshdbi  VDBI_ABSH
#define     abshdbc  VDBC_ABSH
#define     abshdhi  VDHI_ABSH
#define     abshdhf  VDHF_ABSH
#define     abshdwi  VDWI_ABSH
#define     abshdwf  VDWF_ABSH

#define     abshqhi  VQHI_ABSH
#define     abshqhf  VQHF_ABSH
#define     abshqwi  VQWI_ABSH
#define     abshqwf  VQWF_ABSH
#define     abshqdi  VQDI_ABSH
#define     abshqdf  VQDF_ABSH
#if _LEAVE_ABSH
}
#endif

#if _ENTER_ABSW
{
#endif
/*  ABSolute value (as float)
*/

#define     absw(X) (absw_funcof(X)(X))
#define     absw_funcof(X, ...)  \
FUNCOF(             \
    absw, (   X   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    HDS,  /* TGD */ \
    WDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     abswbi    INT8_ABSW
#define     abswbc    CHAR_ABSW
#define     abswhi   INT16_ABSW
#define     abswhf   FLT16_ABSW
#define     abswwi   INT32_ABSW
#define     abswwf     FLT_ABSW
#define     abswdi   INT64_ABSW
#define     abswdf     DBL_ABSW
#if DWRD_NLONG == 2
#   define  abswli   LONG_ABSW
#elif QUAD_NLLONG == 2
#   define  abswli  LLONG_ABSW
#else
#   define  abswqi  LLONG_ABSW
#   define  abswqf   LDBL_ABSW
#endif

#define     abswwbi  VWBI_ABSW
#define     abswwbc  VWBC_ABSW
#define     abswwhi  VWHI_ABSW
#define     abswwhf  VWHF_ABSW
#define     abswwwi  VWWI_ABSW
#define     abswwwf  VWWF_ABSW

#define     abswdhi  VDHI_ABSW
#define     abswdhf  VDHF_ABSW
#define     abswdwi  VDWI_ABSW
#define     abswdwf  VDWF_ABSW
#define     abswddi  VDDI_ABSW
#define     abswddf  VDDF_ABSW

#define     abswqwi  VQWI_ABSW
#define     abswqwf  VQWF_ABSW
#define     abswqdi  VQDI_ABSW
#define     abswqdf  VQDF_ABSW
#if _LEAVE_ABSW
}
#endif

#if _ENTER_ABSD
{
#endif
/*  ABSolute value (as double)
*/

#define     absd(X) (absd_funcof(X)(X))
#define     absd_funcof(X, ...)  \
FUNCOF(             \
    absd, (   X   ),\
    BDS,  /* TGK */ \
    HWS,  /* TGW */ \
    WDS,  /* TGD */ \
    DS,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     absdbi    INT8_ABSD
#define     absdbc    CHAR_ABSD
#define     absdhi   INT16_ABSD
#define     absdhf   FLT16_ABSD
#define     absdwi   INT32_ABSD
#define     absdwf     FLT_ABSD
#define     absddi   INT64_ABSD
#define     absddf     DBL_ABSD
#if DWRD_NLONG == 2
#   define  absdli   LONG_ABSD
#elif QUAD_NLLONG == 2
#   define  absdli  LLONG_ABSD
#else
#   define  absdqi  LLONG_ABSD
#   define  absdqf   LDBL_ABSD
#endif

#define     absdwhi  VWHI_ABSD
#define     absdwhf  VWHF_ABSD
#define     absdwwi  VWWI_ABSD
#define     absdwwf  VWWF_ABSD

#define     absddwi  VDWI_ABSD
#define     absddwf  VDWF_ABSD
#define     absdddi  VDDI_ABSD
#define     absdddf  VDDF_ABSD

#define     absdqdi  VQDI_ABSD
#define     absdqdf  VQDF_ABSD
#if _LEAVE_ABSD
}
#endif


#if _ENTER_ADD1
{
#endif
/*  ADD (atomic fetch add w/ memory_order_relaxed)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the sum
of it and the second operand B.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification for
C11's atomic_fetch_add_explicit and memory_order_relaxed
*/

#define     add1(A, B)  (add1_funcof(A,B)(A,B))
#define     add1_funcof(A, ...) \
FUNCOF_AK(          \
    add1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     add1ayu    BOOL_ADD1A
#define     add1abu   UINT8_ADD1A
#define     add1abi    INT8_ADD1A
#define     add1abc    CHAR_ADD1A
#define     add1ahu  UINT16_ADD1A
#define     add1ahi   INT16_ADD1A
#define     add1awu  UINT32_ADD1A
#define     add1awi   INT32_ADD1A
#define     add1adu  UINT64_ADD1A
#define     add1adi   INT64_ADD1A
#if DWRD_NLONG == 2
#   define  add1alu   ULONG_ADD1A
#   define  add1ali    LONG_ADD1A
#elif QUAD_NLLONG == 2
#   define  add1alu  ULLONG_ADD1A
#   define  add1ali   LLONG_ADD1A
#else
#   define  add1aqu  ULLONG_ADD1A
#   define  add1aqi   LLONG_ADD1A
#endif
#if _LEAVE_ADD1
}
#endif

#if _ENTER_ADDA
{
#endif
/*  ADD (atomic fetch add w/ memory_order_acquire)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the sum
of it and the second operand B. Returns the previous value
stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification for
C11's atomic_fetch_add_explicit and memory_order_acquire
*/

#define     adda(A, B)  (adda_funcof(A,B)(A,B))
#define     adda_funcof(A, ...) \
FUNCOF_AK(          \
    adda, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addaayu    BOOL_ADDAA
#define     addaabu   UINT8_ADDAA
#define     addaabi    INT8_ADDAA
#define     addaabc    CHAR_ADDAA
#define     addaahu  UINT16_ADDAA
#define     addaahi   INT16_ADDAA
#define     addaawu  UINT32_ADDAA
#define     addaawi   INT32_ADDAA
#define     addaadu  UINT64_ADDAA
#define     addaadi   INT64_ADDAA
#if DWRD_NLONG == 2
#   define  addaalu   ULONG_ADDAA
#   define  addaali    LONG_ADDAA
#elif QUAD_NLLONG == 2
#   define  addaalu  ULLONG_ADDAA
#   define  addaali   LLONG_ADDAA
#else
#   define  addaaqu  ULLONG_ADDAA
#   define  addaaqi   LLONG_ADDAA
#endif
#if _LEAVE_ADDA
}
#endif

#if _ENTER_ADDE
{
#endif
/*  ADD (atomic fetch add w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the sum
of it and the second operand B. Returns the previous value
stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_add and memory_order_release
*/

#define     adde(A, B)  (adde_funcof(A,B)(A,B))
#define     adde_funcof(A, ...) \
FUNCOF_AK(          \
    adde, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addeayu    BOOL_ADDEA
#define     addeabu   UINT8_ADDEA
#define     addeabi    INT8_ADDEA
#define     addeabc    CHAR_ADDEA
#define     addeahu  UINT16_ADDEA
#define     addeahi   INT16_ADDEA
#define     addeawu  UINT32_ADDEA
#define     addeawi   INT32_ADDEA
#define     addeadu  UINT64_ADDEA
#define     addeadi   INT64_ADDEA
#if DWRD_NLONG == 2
#   define  addealu   ULONG_ADDEA
#   define  addeali    LONG_ADDEA
#elif QUAD_NLLONG == 2
#   define  addealu  ULLONG_ADDEA
#   define  addeali   LLONG_ADDEA
#else
#   define  addeaqu  ULLONG_ADDEA
#   define  addeaqi   LLONG_ADDEA
#endif
#if _LEAVE_ADDE
}
#endif

#if _ENTER_ADDT
{
#endif
/*  ADD (atomic fetch add w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the sum
of it and the second operand B. Returns the previous value
stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_add and memory_order_seq_cst
*/

#define     addt(...)  (addt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     addt_funcof(A, ...) \
FUNCOF_AK(          \
    addt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addtayu    BOOL_ADDTA
#define     addtabu   UINT8_ADDTA
#define     addtabi    INT8_ADDTA
#define     addtabc    CHAR_ADDTA
#define     addtahu  UINT16_ADDTA
#define     addtahi   INT16_ADDTA
#define     addtawu  UINT32_ADDTA
#define     addtawi   INT32_ADDTA
#define     addtadu  UINT64_ADDTA
#define     addtadi   INT64_ADDTA
#if DWRD_NLONG == 2
#   define  addtalu   ULONG_ADDTA
#   define  addtali    LONG_ADDTA
#elif QUAD_NLLONG == 2
#   define  addtalu  ULLONG_ADDTA
#   define  addtali   LLONG_ADDTA
#else
#   define  addtaqu  ULLONG_ADDTA
#   define  addtaqi   LLONG_ADDTA
#endif

#if _LEAVE_ADDT
}
#endif

#if _ENTER_ADDL
{
#endif
/*  ADD (truncated)

Add each N bit integer element in the first operand to the
corresponding N bit integer element in the second operand,
producing a N bit sum.

Only the least significant N bits of the result are kept.
*/

#define     addl(...) (addl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     addl_funcof(A, ...)  \
FUNCOF(             \
    addl, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addlyu    BOOL_ADDL
#define     addlbu   UINT8_ADDL
#define     addlbi    INT8_ADDL
#define     addlbc    CHAR_ADDL
#define     addlhu  UINT16_ADDL
#define     addlhi   INT16_ADDL
#define     addlwu  UINT32_ADDL
#define     addlwi   INT32_ADDL
#define     addldu  UINT64_ADDL
#define     addldi   INT64_ADDL
#if   DWRD_NLONG == 2
#   define  addllu   ULONG_ADDL
#   define  addlli    LONG_ADDL
#elif QUAD_NLLONG == 2
#   define  addllu  ULLONG_ADDL
#   define  addlli   LLONG_ADDL
#else
#   define  addlqu  ULLONG_ADDL
#   define  addlqi   LLONG_ADDL
#endif

#define     addlwyu   VWYU_ADDL
#define     addlwbu   VWBU_ADDL
#define     addlwbi   VWBI_ADDL
#define     addlwbc   VWBC_ADDL
#define     addlwhu   VWHU_ADDL
#define     addlwhi   VWHI_ADDL
#define     addlwwu   VWWU_ADDL
#define     addlwwi   VWWI_ADDL

#define     addldyu   VDYU_ADDL
#define     addldbu   VDBU_ADDL
#define     addldbi   VDBI_ADDL
#define     addldbc   VDBC_ADDL
#define     addldhu   VDHU_ADDL
#define     addldhi   VDHI_ADDL
#define     addldwu   VDWU_ADDL
#define     addldwi   VDWI_ADDL
#define     addlddu   VDDU_ADDL
#define     addlddi   VDDI_ADDL

#define     addlqyu   VQYU_ADDL
#define     addlqbu   VQBU_ADDL
#define     addlqbi   VQBI_ADDL
#define     addlqbc   VQBC_ADDL
#define     addlqhu   VQHU_ADDL
#define     addlqhi   VQHI_ADDL
#define     addlqwu   VQWU_ADDL
#define     addlqwi   VQWI_ADDL
#define     addlqdu   VQDU_ADDL
#define     addlqdi   VQDI_ADDL
#if _LEAVE_ADDL
}
#endif

#if _ENTER_ADD2
{
#endif
/*  ADD (widened sum)

Add each N bit integer element in the first operand to the
corresponding N bit integer element in the second operand,
producing a N×2 bit sum.

HINT: use add2 if it's important to detect overflow.

    Vdhu a = ...;
    Vdhu b = ...;
    Vqwu c = add2dhu(a, b);
    a = uzplqhu(ashuqwu(c)); // gets lo 16 bits of each elem
    a = uzprqhu(ashuqwu(c)); // gets hi 16 bits
    
    uint32_t x = ...;
    uint32_t y = ...;
    uint64_t z = add2wu(x, y);
    if (getrdu(z)) // equal to (z>>32)
        ...
        
*/

#define     add2(A, B) (add2_funcof(A,B)(A,B))
#define     add2_funcof(A, ...)  \
FUNCOF(             \
    add2, (   A   ),\
    BWZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BWZ,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     add2bu   UINT8_ADD2
#define     add2bi    INT8_ADD2
#define     add2bc    CHAR_ADD2
#define     add2hu  UINT16_ADD2
#define     add2hi   INT16_ADD2
#define     add2wu  UINT32_ADD2
#define     add2wi   INT32_ADD2
#define     add2du  UINT64_ADD2
#define     add2di   INT64_ADD2
#if   DWRD_NLONG == 2
#   define  add2lu   ULONG_ADD2
#   define  add2li    LONG_ADD2
#elif QUAD_NLLONG == 2
#   define  add2lu  ULLONG_ADD2
#   define  add2li   LLONG_ADD2
#else
#   define  add2qu  ULLONG_ADD2
#   define  add2qi   LLONG_ADD2
#endif

#define     add2wbu   VWBU_ADD2
#define     add2wbi   VWBI_ADD2
#define     add2wbc   VWBC_ADD2
#define     add2whu   VWHU_ADD2
#define     add2whi   VWHI_ADD2
#define     add2wwu   VWWU_ADD2
#define     add2wwi   VWWI_ADD2

#define     add2dbu   VDBU_ADD2
#define     add2dbi   VDBI_ADD2
#define     add2dbc   VDBC_ADD2
#define     add2dhu   VDHU_ADD2
#define     add2dhi   VDHI_ADD2
#define     add2dwu   VDWU_ADD2
#define     add2dwi   VDWI_ADD2
#define     add2ddu   VDDU_ADD2
#define     add2ddi   VDDI_ADD2

#define     add2qyu   VQYU_ADD2
#define     add2qbu   VQBU_ADD2
#define     add2qbi   VQBI_ADD2
#define     add2qbc   VQBC_ADD2
#define     add2qhu   VQHU_ADD2
#define     add2qhi   VQHI_ADD2
#define     add2qwu   VQWU_ADD2
#define     add2qwi   VQWI_ADD2
#define     add2qdu   VQDU_ADD2
#define     add2qdi   VQDI_ADD2
#if _LEAVE_ADD2
}
#endif

#if _ENTER_ADDS
{
#endif
/*  ADD (saturated)

Add each N bit integer element in the first operand to the
corresponding N bit integer element in the second operand,
producing a N bit sum.

If a sum exceeds the maximum representable by the element
type it is clamped to the maximum. Likewise, if the sum
of two negative integers is less than the minimum the
element type can represent, it is clamped to the minimum.

E.g.:
    addsbi(-100, -100)

computes:

    -100 + -100 = -200

Because -200 is less than -128, the result is clamped to
-128, as if:

    cvbshi(add2bi(-100, -100))

had been used instead.
*/

#define     adds(A, B) (adds_funcof(A,B)(A,B))
#define     adds_funcof(A, ...)  \
FUNCOF(             \
    adds, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addsyu    BOOL_ADDS
#define     addsbu   UINT8_ADDS
#define     addsbi    INT8_ADDS
#define     addsbc    CHAR_ADDS
#define     addshu  UINT16_ADDS
#define     addshi   INT16_ADDS
#define     addswu  UINT32_ADDS
#define     addswi   INT32_ADDS
#define     addsdu  UINT64_ADDS
#define     addsdi   INT64_ADDS
#if   DWRD_NLONG == 2
#   define  addslu   ULONG_ADDS
#   define  addsli    LONG_ADDS
#elif QUAD_NLLONG == 2
#   define  addslu  ULLONG_ADDS
#   define  addsli   LLONG_ADDS
#else
#   define  addsqu  ULLONG_ADDS
#   define  addsqi   LLONG_ADDS
#endif

#define     addswyu   VWYU_ADDS
#define     addswbu   VWBU_ADDS
#define     addswbi   VWBI_ADDS
#define     addswbc   VWBC_ADDS
#define     addswhu   VWHU_ADDS
#define     addswhi   VWHI_ADDS
#define     addswwu   VWWU_ADDS
#define     addswwi   VWWI_ADDS

#define     addsdyu   VDYU_ADDS
#define     addsdbu   VDBU_ADDS
#define     addsdbi   VDBI_ADDS
#define     addsdbc   VDBC_ADDS
#define     addsdhu   VDHU_ADDS
#define     addsdhi   VDHI_ADDS
#define     addsdwu   VDWU_ADDS
#define     addsdwi   VDWI_ADDS
#define     addsddu   VDDU_ADDS
#define     addsddi   VDDI_ADDS

#define     addsqyu   VQYU_ADDS
#define     addsqbu   VQBU_ADDS
#define     addsqbi   VQBI_ADDS
#define     addsqbc   VQBC_ADDS
#define     addsqhu   VQHU_ADDS
#define     addsqhi   VQHI_ADDS
#define     addsqwu   VQWU_ADDS
#define     addsqwi   VQWI_ADDS
#define     addsqdu   VQDU_ADDS
#define     addsqdi   VQDI_ADDS
#if _LEAVE_ADDS
}
#endif

#if _ENTER_ADDH
{
#endif
/*  ADD (flt16_t)

For each number A in the first operand and each flt16_t
element B in the second operand, compute A+B. The result's
element type is identical to the effective type of the
corresponding C expression A+B.

If the sum is too large for the result type to represent,
the result is implementation defined.
*/

#define     addh(A, B) (addh_funcof(A,B)(A,B))
#define     addh_funcof(A, ...)  \
FUNCOF(             \
    addh, (   A   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addhyu    BOOL_ADDH
#define     addhbu   UINT8_ADDH
#define     addhbi    INT8_ADDH
#define     addhbc    CHAR_ADDH
#define     addhhu  UINT16_ADDH
#define     addhhi   INT16_ADDH
#define     addhhf   FLT16_ADDH
#define     addhwu  UINT32_ADDH
#define     addhwi   INT32_ADDH
#define     addhwf     FLT_ADDH
#define     addhdu  UINT64_ADDH
#define     addhdi   INT64_ADDH
#define     addhdf     DBL_ADDH
#if   DWRD_NLONG == 2
#   define  addhlu   ULONG_ADDH
#   define  addhli    LONG_ADDH
#elif QUAD_NLLONG == 2
#   define  addhlu  ULLONG_ADDH
#   define  addhli   LLONG_ADDH
#else
#   define  addhqu  ULLONG_ADDH
#   define  addhqi   LLONG_ADDH
#   define  addhqf    LDBL_ADDH
#endif

#define     addhwbu   VWBU_ADDH
#define     addhwbi   VWBI_ADDH
#define     addhwbc   VWBC_ADDH
#define     addhwhu   VWHU_ADDH
#define     addhwhi   VWHI_ADDH
#define     addhwhf   VWHF_ADDH

#define     addhdbu   VDBU_ADDH
#define     addhdbi   VDBI_ADDH
#define     addhdbc   VDBC_ADDH
#define     addhdhu   VDHU_ADDH
#define     addhdhi   VDHI_ADDH
#define     addhdhf   VDHF_ADDH
#define     addhdwu   VDWU_ADDH
#define     addhdwi   VDWI_ADDH
#define     addhdwf   VDWF_ADDH

#define     addhqhu   VQHU_ADDH
#define     addhqhi   VQHI_ADDH
#define     addhqhf   VQHF_ADDH
#define     addhqwu   VQWU_ADDH
#define     addhqwi   VQWI_ADDH
#define     addhqwf   VQWF_ADDH
#define     addhqdu   VQDU_ADDH
#define     addhqdi   VQDI_ADDH
#define     addhqdf   VQDF_ADDH
#if _LEAVE_ADDH
}
#endif

#if _ENTER_ADDW
{
#endif
/*  ADD (float)

For each number A in the first operand and each float
element B in the second operand, compute A+B. The result's
element type is identical to the effective type of the
corresponding C expression A+B.

If the sum is too large for the result type to represent,
the result is implementation defined.
*/

#define     addw(...) (addw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     addw_funcof(A, ...)  \
FUNCOF(             \
    addw, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     addwyu    BOOL_ADDW
#define     addwbu   UINT8_ADDW
#define     addwbi    INT8_ADDW
#define     addwbc    CHAR_ADDW
#define     addwhu  UINT16_ADDW
#define     addwhi   INT16_ADDW
#define     addwhf   FLT16_ADDW
#define     addwwu  UINT32_ADDW
#define     addwwi   INT32_ADDW
#define     addwwf     FLT_ADDW
#define     addwdu  UINT64_ADDW
#define     addwdi   INT64_ADDW
#define     addwdf     DBL_ADDW
#if   DWRD_NLONG == 2
#   define  addwlu   ULONG_ADDW
#   define  addwli    LONG_ADDW
#elif QUAD_NLLONG == 2
#   define  addwlu  ULLONG_ADDW
#   define  addwli   LLONG_ADDW
#else
#   define  addwqu  ULLONG_ADDW
#   define  addwqi   LLONG_ADDW
#   define  addwqf    LDBL_ADDW
#endif

#define     addwwbu   VWBU_ADDW
#define     addwwbi   VWBI_ADDW
#define     addwwbc   VWBC_ADDW
#define     addwwhu   VWHU_ADDW
#define     addwwhi   VWHI_ADDW
#define     addwwhf   VWHF_ADDW
#define     addwwwu   VWWU_ADDW
#define     addwwwi   VWWI_ADDW
#define     addwwwf   VWWF_ADDW

#define     addwdhu   VDHU_ADDW
#define     addwdhi   VDHI_ADDW
#define     addwdhf   VDHF_ADDW
#define     addwdwu   VDWU_ADDW
#define     addwdwi   VDWI_ADDW
#define     addwdwf   VDWF_ADDW
#define     addwddu   VDDU_ADDW
#define     addwddi   VDDI_ADDW
#define     addwddf   VDDF_ADDW

#define     addwqwu   VQWU_ADDW
#define     addwqwi   VQWI_ADDW
#define     addwqwf   VQWF_ADDW
#define     addwqdu   VQDU_ADDW
#define     addwqdi   VQDI_ADDW
#define     addwqdf   VQDF_ADDW
#if _LEAVE_ADDW
}
#endif

#if _ENTER_ADDD
{
#endif
/*  ADD (double)

For each number A in the first operand and each double
element B in the second operand, compute A+B. The result's
element type is identical to the effective type of the
corresponding C expression A+B.

If the sum is too large for the result type to represent,
the result is implementation defined.
*/

#define     addd(...) (addd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     addd_funcof(A, ...)  \
FUNCOF(             \
    addd, (   A   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     adddyu    BOOL_ADDD
#define     adddbu   UINT8_ADDD
#define     adddbi    INT8_ADDD
#define     adddbc    CHAR_ADDD
#define     adddhu  UINT16_ADDD
#define     adddhi   INT16_ADDD
#define     adddhf   FLT16_ADDD
#define     adddwu  UINT32_ADDD
#define     adddwi   INT32_ADDD
#define     adddwf     FLT_ADDD
#define     addddu  UINT64_ADDD
#define     addddi   INT64_ADDD
#define     addddf     DBL_ADDD
#if   DWRD_NLONG == 2
#   define  adddlu   ULONG_ADDD
#   define  adddli    LONG_ADDD
#elif QUAD_NLLONG == 2
#   define  adddlu  ULLONG_ADDD
#   define  adddli   LLONG_ADDD
#else
#   define  adddqu  ULLONG_ADDD
#   define  adddqi   LLONG_ADDD
#   define  adddqf    LDBL_ADDD
#endif

#define     adddwhu   VWHU_ADDD
#define     adddwhi   VWHI_ADDD
#define     adddwhf   VWHF_ADDD
#define     adddwwu   VWWU_ADDD
#define     adddwwi   VWWI_ADDD
#define     adddwwf   VWWF_ADDD

#define     addddwu   VDWU_ADDD
#define     addddwi   VDWI_ADDD
#define     addddwf   VDWF_ADDD
#define     adddddu   VDDU_ADDD
#define     adddddi   VDDI_ADDD
#define     adddddf   VDDF_ADDD

#define     adddqdu   VQDU_ADDD
#define     adddqdi   VQDI_ADDD
#define     adddqdf   VQDF_ADDD
#if _LEAVE_ADDD
}
#endif

#if _ENTER_ANDS
{
#endif
/*  Bitwise AND

For each bit A in the first operand A and each bit B in
the second operand, compute the bitwise AND of A and B.
*/

#define     ands(...) (ands_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ands_funcof(X, ...)  \
FUNCOF(             \
    ands, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     andsyu    BOOL_ANDS
#define     andsbu   UINT8_ANDS
#define     andsbi    INT8_ANDS
#define     andsbc    CHAR_ANDS
#define     andshu  UINT16_ANDS
#define     andshi   INT16_ANDS
#define     andswu  UINT32_ANDS
#define     andswi   INT32_ANDS
#define     andsdu  UINT64_ANDS
#define     andsdi   INT64_ANDS
#if   DWRD_NLONG == 2
#   define  andslu   ULONG_ANDS
#   define  andsli    LONG_ANDS
#elif QUAD_NLLONG == 2
#   define  andslu  ULLONG_ANDS
#   define  andsli   LLONG_ANDS
#else
#   define  andsqu  ULLONG_ANDS
#   define  andsqi   LLONG_ANDS
#endif

#define     andswyu   VWYU_ANDS
#define     andswbu   VWBU_ANDS
#define     andswbi   VWBI_ANDS
#define     andswbc   VWBC_ANDS
#define     andswhu   VWHU_ANDS
#define     andswhi   VWHI_ANDS
#define     andswwu   VWWU_ANDS
#define     andswwi   VWWI_ANDS

#define     andsdyu   VDYU_ANDS
#define     andsdbu   VDBU_ANDS
#define     andsdbi   VDBI_ANDS
#define     andsdbc   VDBC_ANDS
#define     andsdhu   VDHU_ANDS
#define     andsdhi   VDHI_ANDS
#define     andsdwu   VDWU_ANDS
#define     andsdwi   VDWI_ANDS
#define     andsddu   VDDU_ANDS
#define     andsddi   VDDI_ANDS

#define     andsqyu   VQYU_ANDS
#define     andsqbu   VQBU_ANDS
#define     andsqbi   VQBI_ANDS
#define     andsqbc   VQBC_ANDS
#define     andsqhu   VQHU_ANDS
#define     andsqhi   VQHI_ANDS
#define     andsqwu   VQWU_ANDS
#define     andsqwi   VQWI_ANDS
#define     andsqdu   VQDU_ANDS
#define     andsqdi   VQDI_ANDS
#if _LEAVE_ANDS
}
#endif

#if _ENTER_ANDN
{
#endif
/*  Bitwise AND NOT

For each bit A in the first operand A and each bit B in
the second operand, compute the bitwise AND of A and NOT B.
*/

#define     andn(...) (andn_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     andn_funcof(X, ...)  \
FUNCOF(             \
    andn, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     andnyu    BOOL_ANDN
#define     andnbu   UINT8_ANDN
#define     andnbi    INT8_ANDN
#define     andnbc    CHAR_ANDN
#define     andnhu  UINT16_ANDN
#define     andnhi   INT16_ANDN
#define     andnwu  UINT32_ANDN
#define     andnwi   INT32_ANDN
#define     andndu  UINT64_ANDN
#define     andndi   INT64_ANDN

#if   DWRD_NLONG == 2
#   define  andnlu   ULONG_ANDN
#   define  andnli    LONG_ANDN
#elif QUAD_NLLONG == 2
#   define  andnlu  ULLONG_ANDN
#   define  andnli   LLONG_ANDN
#else
#   define  andnqu  ULLONG_ANDN
#   define  andnqi   LLONG_ANDN
#endif

#define     andnwyu   VWYU_ANDN
#define     andnwbu   VWBU_ANDN
#define     andnwbi   VWBI_ANDN
#define     andnwbc   VWBC_ANDN
#define     andnwhu   VWHU_ANDN
#define     andnwhi   VWHI_ANDN
#define     andnwwu   VWWU_ANDN
#define     andnwwi   VWWI_ANDN

#define     andndyu   VDYU_ANDN
#define     andndbu   VDBU_ANDN
#define     andndbi   VDBI_ANDN
#define     andndbc   VDBC_ANDN
#define     andndhu   VDHU_ANDN
#define     andndhi   VDHI_ANDN
#define     andndwu   VDWU_ANDN
#define     andndwi   VDWI_ANDN
#define     andnddu   VDDU_ANDN
#define     andnddi   VDDI_ANDN

#define     andnqyu   VQYU_ANDN
#define     andnqbu   VQBU_ANDN
#define     andnqbi   VQBI_ANDN
#define     andnqbc   VQBC_ANDN
#define     andnqhu   VQHU_ANDN
#define     andnqhi   VQHI_ANDN
#define     andnqwu   VQWU_ANDN
#define     andnqwi   VQWI_ANDN
#define     andnqdu   VQDU_ANDN
#define     andnqdi   VQDI_ANDN
#if _LEAVE_ANDN
}
#endif

#if _ENTER_ANDV
{
#endif
/*  Bitwise AND (across vector)

For 2 element vectors, compute V[0]&V[1]. For 4 element
vectore, compute V[0]&V[1]&V[2]&V[3], and so on.
*/

#define     andv(...) (andv_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     andv_funcof(X, ...)  \
FUNCOF(             \
    andv, (   X   ),\
    NONE, /* TGK */ \
    YHZ,  /* TGW */ \
    YWZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     andvwyu   VWYU_ANDV
#define     andvwbu   VWBU_ANDV
#define     andvwbi   VWBI_ANDV
#define     andvwbc   VWBC_ANDV
#define     andvwhu   VWHU_ANDV
#define     andvwhi   VWHI_ANDV

#define     andvdyu   VDYU_ANDV
#define     andvdbu   VDBU_ANDV
#define     andvdbi   VDBI_ANDV
#define     andvdbc   VDBC_ANDV
#define     andvdhu   VDHU_ANDV
#define     andvdhi   VDHI_ANDV
#define     andvdwu   VDWU_ANDV
#define     andvdwi   VDWI_ANDV

#define     andvqyu   VQYU_ANDV
#define     andvqbu   VQBU_ANDV
#define     andvqbi   VQBI_ANDV
#define     andvqbc   VQBC_ANDV
#define     andvqhu   VQHU_ANDV
#define     andvqhi   VQHI_ANDV
#define     andvqwu   VQWU_ANDV
#define     andvqwi   VQWI_ANDV
#define     andvqdu   VQDU_ANDV
#define     andvqdi   VQDI_ANDV
#if _LEAVE_ANDV
}
#endif

#if _ENTER_AND1
{
#endif
/*  AND (atomic fetch and w/ memory_order_relaxed)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise AND of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_and and memory_order_relaxed
*/

#define     and1(...)  (and1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     and1_funcof(A, ...) \
FUNCOF_AK(          \
    and1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     and1ayu    BOOL_AND1A
#define     and1abu   UINT8_AND1A
#define     and1abi    INT8_AND1A
#define     and1abc    CHAR_AND1A
#define     and1ahu  UINT16_AND1A
#define     and1ahi   INT16_AND1A
#define     and1awu  UINT32_AND1A
#define     and1awi   INT32_AND1A
#define     and1adu  UINT64_AND1A
#define     and1adi   INT64_AND1A
#if DWRD_NLONG == 2
#   define  and1alu   ULONG_AND1A
#   define  and1ali    LONG_AND1A
#elif QUAD_NLLONG == 2
#   define  and1alu  ULLONG_AND1A
#   define  and1ali   LLONG_AND1A
#else
#   define  and1aqu  ULLONG_AND1A
#   define  and1aqi   LLONG_AND1A
#endif

#if _LEAVE_AND1
}
#endif

#if _ENTER_ANDA
{
#endif
/*  AND (atomic fetch and w/ memory_order_acquire)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise AND of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_and and memory_order_acquire
*/

#define     anda(...)  (anda_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     anda_funcof(A, ...) \
FUNCOF_AK(          \
    anda, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     andaayu    BOOL_ANDAA
#define     andaabu   UINT8_ANDAA
#define     andaabi    INT8_ANDAA
#define     andaabc    CHAR_ANDAA
#define     andaahu  UINT16_ANDAA
#define     andaahi   INT16_ANDAA
#define     andaawu  UINT32_ANDAA
#define     andaawi   INT32_ANDAA
#define     andaadu  UINT64_ANDAA
#define     andaadi   INT64_ANDAA
#if DWRD_NLONG == 2
#   define  andaalu   ULONG_ANDAA
#   define  andaali    LONG_ANDAA
#elif QUAD_NLLONG == 2
#   define  andaalu  ULLONG_ANDAA
#   define  andaali   LLONG_ANDAA
#else
#   define  andaaqu  ULLONG_ANDAA
#   define  andaaqi   LLONG_ANDAA
#endif

#if _LEAVE_ANDA
}
#endif

#if _ENTER_ANDE
{
#endif
/*  AND (atomic fetch and w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise AND of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_and and memory_order_release
*/

#define     ande(...)  (ande_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ande_funcof(A, ...) \
FUNCOF_AK(          \
    ande, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     andeayu    BOOL_ANDEA
#define     andeabu   UINT8_ANDEA
#define     andeabi    INT8_ANDEA
#define     andeabc    CHAR_ANDEA
#define     andeahu  UINT16_ANDEA
#define     andeahi   INT16_ANDEA
#define     andeawu  UINT32_ANDEA
#define     andeawi   INT32_ANDEA
#define     andeadu  UINT64_ANDEA
#define     andeadi   INT64_ANDEA
#if DWRD_NLONG == 2
#   define  andealu   ULONG_ANDEA
#   define  andeali    LONG_ANDEA
#elif QUAD_NLLONG == 2
#   define  andealu  ULLONG_ANDEA
#   define  andeali   LLONG_ANDEA
#else
#   define  andeaqu  ULLONG_ANDEA
#   define  andeaqi   LLONG_ANDEA
#endif

#if _LEAVE_ANDE
}
#endif

#if _ENTER_ANDT
{
#endif
/*  AND (atomic fetch and w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise AND of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_and and memory_order_seq_cst
*/

#define     andt(...)  (andt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     andt_funcof(A, ...) \
FUNCOF_AK(          \
    andt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     andtayu    BOOL_ANDTA
#define     andtabu   UINT8_ANDTA
#define     andtabi    INT8_ANDTA
#define     andtabc    CHAR_ANDTA
#define     andtahu  UINT16_ANDTA
#define     andtahi   INT16_ANDTA
#define     andtawu  UINT32_ANDTA
#define     andtawi   INT32_ANDTA
#define     andtadu  UINT64_ANDTA
#define     andtadi   INT64_ANDTA
#if DWRD_NLONG == 2
#   define  andtalu   ULONG_ANDTA
#   define  andtali    LONG_ANDTA
#elif QUAD_NLLONG == 2
#   define  andtalu  ULLONG_ANDTA
#   define  andtali   LLONG_ANDTA
#else
#   define  andtaqu  ULLONG_ANDTA
#   define  andtaqi   LLONG_ANDTA
#endif

#if _LEAVE_ANDT
}
#endif



#if _ENTER_ASTV
{
#endif
/*  reinterpret cAST (vector to scalar or scalar to vector)

Reinterpret the binary representation of single element
vector as the scalar type or vice versa.

E.g. astvdu(12345u) reinterprets ((uint64_t) 12345u) as
Vddu, whereas astvddu((dupddu(12345u))) reinterprets the
Vddu as ((uint64_t) 12345u).
*/

#define     astv(X) (astv_funcof(X)(X))
#define     astv_funcof(X)  \
FUNCOF(             \
    astv, (   X   ),\
    WDR,  /* TGK */ \
    WR,   /* TGW */ \
    DR,   /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     astvwu   UINT32_ASTV
#define     astvwi    INT32_ASTV
#define     astvwf      FLT_ASTV
#if DWRD_NLONG == 2
#define     astvlu    ULONG_ASTV
#define     astvli     LONG_ASTV
#elif QUAD_NLLONG == 2
#define     astvlu   ULLONG_ASTV
#define     astvli    LLONG_ASTV
#endif

#define     astvdu   UINT64_ASTV
#define     astvdi    INT64_ASTV
#define     astvdf      DBL_ASTV

#define     astvwwu    VWWU_ASTV
#define     astvwwi    VWWI_ASTV
#define     astvwwf    VWWF_ASTV

#define     astvddu    VDDU_ASTV
#define     astvddi    VDDI_ASTV
#define     astvddf    VDDF_ASTV
#if _LEAVE_ASTV
}
#endif

#if _ENTER_ASTU
{
#endif
/*  reinterpret cAST (unsigned)

Reinterpret the binary representation of each element in
the operand as the equivalent width unsigned integer type.
*/

#define  astu(X) (astu_funcof(X)(X))
#define  astu_funcof(X) \
FUNCOF(             \
    astu, (   X   ),\
    YDR,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     astuyu    BOOL_ASTU
#define     astubu   UINT8_ASTU
#define     astubi    INT8_ASTU
#define     astubc    CHAR_ASTU
#define     astuhu  UINT16_ASTU
#define     astuhi   INT16_ASTU
#define     astuhf   FLT16_ASTU
#define     astuwu  UINT32_ASTU
#define     astuwi   INT32_ASTU
#define     astuwf     FLT_ASTU
#define     astudu  UINT64_ASTU
#define     astudi   INT64_ASTU
#define     astudf     DBL_ASTU
#if   DWRD_NLONG == 2
#   define  astulu   ULONG_ASTU
#   define  astuli    LONG_ASTU
#elif QUAD_NLLONG == 2
#   define  astulu  ULLONG_ASTU
#   define  astuli   LLONG_ASTU
#else
#   define  astuqu  ULLONG_ASTU
#   define  astuqi   LLONG_ASTU
#endif

#define     astuwyu  VWYU_ASTU
#define     astuwbu  VWBU_ASTU
#define     astuwbi  VWBI_ASTU
#define     astuwbc  VWBC_ASTU
#define     astuwhu  VWHU_ASTU
#define     astuwhi  VWHI_ASTU
#define     astuwhf  VWHF_ASTU
#define     astuwwu  VWWU_ASTU
#define     astuwwi  VWWI_ASTU
#define     astuwwf  VWWF_ASTU

#define     astudyu  VDYU_ASTU
#define     astudbu  VDBU_ASTU
#define     astudbi  VDBI_ASTU
#define     astudbc  VDBC_ASTU
#define     astudhu  VDHU_ASTU
#define     astudhi  VDHI_ASTU
#define     astudhf  VDHF_ASTU
#define     astudwu  VDWU_ASTU
#define     astudwi  VDWI_ASTU
#define     astudwf  VDWF_ASTU
#define     astuddu  VDDU_ASTU
#define     astuddi  VDDI_ASTU
#define     astuddf  VDDF_ASTU

#define     astuqyu  VQYU_ASTU
#define     astuqbu  VQBU_ASTU
#define     astuqbi  VQBI_ASTU
#define     astuqbc  VQBC_ASTU
#define     astuqhu  VQHU_ASTU
#define     astuqhi  VQHI_ASTU
#define     astuqhf  VQHF_ASTU
#define     astuqwu  VQWU_ASTU
#define     astuqwi  VQWI_ASTU
#define     astuqwf  VQWF_ASTU
#define     astuqdu  VQDU_ASTU
#define     astuqdi  VQDI_ASTU
#define     astuqdf  VQDF_ASTU
#if _LEAVE_ASTU
}
#endif

#if _ENTER_ASTI
{
#endif
/*  reinterpret cAST (signed int)

Reinterpret the binary representation of each element in
the operand as the equivalent width signed integer type.
*/

#define     asti(X)  (asti_funcof(X)(X))
#define     asti_funcof(X)  \
FUNCOF(             \
    asti, (   X   ),\
    BDR,  /* TGK */ \
    BDR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     astibu   UINT8_ASTI
#define     astibi    INT8_ASTI
#define     astibc    CHAR_ASTI
#define     astihu  UINT16_ASTI
#define     astihi   INT16_ASTI
#define     astihf   FLT16_ASTI
#define     astiwu  UINT32_ASTI
#define     astiwi   INT32_ASTI
#define     astiwf     FLT_ASTI
#define     astidu  UINT64_ASTI
#define     astidi   INT64_ASTI
#define     astidf     DBL_ASTI
#if   DWRD_NLONG == 2
#   define  astilu   ULONG_ASTI
#   define  astili    LONG_ASTI
#elif QUAD_NLLONG == 2
#   define  astilu  ULLONG_ASTI
#   define  astili   LLONG_ASTI
#endif

#define     astiwbu  VWBU_ASTI
#define     astiwbi  VWBI_ASTI
#define     astiwbc  VWBC_ASTI
#define     astiwhu  VWHU_ASTI
#define     astiwhi  VWHI_ASTI
#define     astiwhf  VWHF_ASTI
#define     astiwwu  VWWU_ASTI
#define     astiwwi  VWWI_ASTI
#define     astiwwf  VWWF_ASTI

#define     astidbu  VDBU_ASTI
#define     astidbi  VDBI_ASTI
#define     astidbc  VDBC_ASTI
#define     astidhu  VDHU_ASTI
#define     astidhi  VDHI_ASTI
#define     astidhf  VDHF_ASTI
#define     astidwu  VDWU_ASTI
#define     astidwi  VDWI_ASTI
#define     astidwf  VDWF_ASTI
#define     astiddu  VDDU_ASTI
#define     astiddi  VDDI_ASTI
#define     astiddf  VDDF_ASTI

#define     astiqbu  VQBU_ASTI
#define     astiqbi  VQBI_ASTI
#define     astiqbc  VQBC_ASTI
#define     astiqhu  VQHU_ASTI
#define     astiqhi  VQHI_ASTI
#define     astiqhf  VQHF_ASTI
#define     astiqwu  VQWU_ASTI
#define     astiqwi  VQWI_ASTI
#define     astiqwf  VQWF_ASTI
#define     astiqdu  VQDU_ASTI
#define     astiqdi  VQDI_ASTI
#define     astiqdf  VQDF_ASTI
#if _LEAVE_ASTI
}
#endif

#if _ENTER_ASTF
{
#endif
/*  reinterpret cAST (floating)

Reinterpret the binary representation of each element in
the operand as the equivalent width floating point type.
*/

#define astf(X)  (astf_funcof(X)(X))
#define astf_funcof(X)  \
FUNCOF(             \
    astf, (   X   ),\
    HDR,  /* TGK */ \
    HWR,  /* TGW */ \
    HDR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     astfhu  UINT16_ASTF
#define     astfhi   INT16_ASTF
#define     astfhf   FLT16_ASTF
#define     astfwu  UINT32_ASTF
#define     astfwi   INT32_ASTF
#define     astfwf     FLT_ASTF
#define     astfdu  UINT64_ASTF
#define     astfdi   INT64_ASTF
#define     astfdf     DBL_ASTF

#if   DWRD_NLONG == 2
#   define  astflu   ULONG_ASTF
#   define  astfli    LONG_ASTF
#elif QUAD_NLLONG == 2
#   define  astflu  ULLONG_ASTF
#   define  astfli   LLONG_ASTF
#endif

#define     astfwhu  VWHU_ASTF
#define     astfwhi  VWHI_ASTF
#define     astfwhf  VWHF_ASTF
#define     astfwwu  VWWU_ASTF
#define     astfwwi  VWWI_ASTF
#define     astfwwf  VWWF_ASTF

#define     astfdhu  VDHU_ASTF
#define     astfdhi  VDHI_ASTF
#define     astfdhf  VDHF_ASTF
#define     astfdwu  VDWU_ASTF
#define     astfdwi  VDWI_ASTF
#define     astfdwf  VDWF_ASTF
#define     astfddu  VDDU_ASTF
#define     astfddi  VDDI_ASTF
#define     astfddf  VDDF_ASTF

#define     astfqhu  VQHU_ASTF
#define     astfqhi  VQHI_ASTF
#define     astfqhf  VQHF_ASTF
#define     astfqwu  VQWU_ASTF
#define     astfqwi  VQWI_ASTF
#define     astfqwf  VQWF_ASTF
#define     astfqdu  VQDU_ASTF
#define     astfqdi  VQDI_ASTF
#define     astfqdf  VQDF_ASTF
#if _LEAVE_ASTF
}
#endif

#if _ENTER_ASYU
{
#endif
/*  reinterpret cAST (boolean)

Reinterpret the binary representation of a vector as a
vector or booleans
*/

#define     asyu(X) (asyu_funcof(X)(X))
#define     asyu_funcof(X)  \
FUNCOF(             \
    asyu, (   X   ),\
    YU,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asyuyu      BOOL_ASYU

#define     asyuwyu     VWYU_ASYU
#define     asyuwbu     VWBU_ASYU
#define     asyuwbi     VWBI_ASYU
#define     asyuwbc     VWBC_ASYU
#define     asyuwhu     VWHU_ASYU
#define     asyuwhi     VWHI_ASYU
#define     asyuwhf     VWHF_ASYU
#define     asyuwwu     VWWU_ASYU
#define     asyuwwi     VWWI_ASYU
#define     asyuwwf     VWWF_ASYU

#define     asyudyu     VDYU_ASYU
#define     asyudbu     VDBU_ASYU
#define     asyudbi     VDBI_ASYU
#define     asyudbc     VDBC_ASYU
#define     asyudhu     VDHU_ASYU
#define     asyudhi     VDHI_ASYU
#define     asyudhf     VDHF_ASYU
#define     asyudwu     VDWU_ASYU
#define     asyudwi     VDWI_ASYU
#define     asyudwf     VDWF_ASYU
#define     asyuddu     VDDU_ASYU
#define     asyuddi     VDDI_ASYU
#define     asyuddf     VDDF_ASYU

#define     asyuqyu     VQYU_ASYU
#define     asyuqbu     VQBU_ASYU
#define     asyuqbi     VQBI_ASYU
#define     asyuqbc     VQBC_ASYU
#define     asyuqhu     VQHU_ASYU
#define     asyuqhi     VQHI_ASYU
#define     asyuqhf     VQHF_ASYU
#define     asyuqwu     VQWU_ASYU
#define     asyuqwi     VQWI_ASYU
#define     asyuqwf     VQWF_ASYU
#define     asyuqdu     VQDU_ASYU
#define     asyuqdi     VQDI_ASYU
#define     asyuqdf     VQDF_ASYU
#if _LEAVE_ASYU
}
#endif

#if _ENTER_ASBU
{
#endif
/*  reinterpret cAST Byte (uint8_t)

Reinterpret 8 bit scalar as uint8_t or vectors as the
equivalent width uint8_t vector
*/

#define     asbu(X) (asbu_funcof(X)(X))
#define     asbu_funcof(X)  \
FUNCOF(             \
    asbu, (   X   ),\
    BR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asbubu   UINT8_ASBU
#define     asbubi    INT8_ASBU
#define     asbubc    CHAR_ASBU

#define     asbuwyu  VWYU_ASBU
#define     asbuwbu  VWBU_ASBU
#define     asbuwbi  VWBI_ASBU
#define     asbuwbc  VWBC_ASBU
#define     asbuwhu  VWHU_ASBU
#define     asbuwhi  VWHI_ASBU
#define     asbuwhf  VWHF_ASBU
#define     asbuwwu  VWWU_ASBU
#define     asbuwwi  VWWI_ASBU
#define     asbuwwf  VWWF_ASBU

#define     asbudyu  VDYU_ASBU
#define     asbudbu  VDBU_ASBU
#define     asbudbi  VDBI_ASBU
#define     asbudbc  VDBC_ASBU
#define     asbudhu  VDHU_ASBU
#define     asbudhi  VDHI_ASBU
#define     asbudhf  VDHF_ASBU
#define     asbudwu  VDWU_ASBU
#define     asbudwi  VDWI_ASBU
#define     asbudwf  VDWF_ASBU
#define     asbuddu  VDDU_ASBU
#define     asbuddi  VDDI_ASBU
#define     asbuddf  VDDF_ASBU

#define     asbuqyu  VQYU_ASBU
#define     asbuqbu  VQBU_ASBU
#define     asbuqbi  VQBI_ASBU
#define     asbuqbc  VQBC_ASBU
#define     asbuqhu  VQHU_ASBU
#define     asbuqhi  VQHI_ASBU
#define     asbuqhf  VQHF_ASBU
#define     asbuqwu  VQWU_ASBU
#define     asbuqwi  VQWI_ASBU
#define     asbuqwf  VQWF_ASBU
#define     asbuqdu  VQDU_ASBU
#define     asbuqdi  VQDI_ASBU
#define     asbuqdf  VQDF_ASBU
#if _LEAVE_ASBU
}
#endif

#if _ENTER_ASBI
{
#endif
/*  reinterpret cAST Byte (int8_t)

Reinterpret 8 bit scalar representation as int8_t or a
vector as the equivalent width int8_t vector

2024-04-19
* fixed TGK=BU not being TGK=BR
*/

#define     asbi(X) (asbi_funcof(X)(X))
#define     asbi_funcof(X)  \
FUNCOF(             \
    asbi, (   X   ),\
    BR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asbibu   UINT8_ASBI
#define     asbibi    INT8_ASBI
#define     asbibc    CHAR_ASBI

#define     asbiwyu  VWYU_ASBI
#define     asbiwbu  VWBU_ASBI
#define     asbiwbi  VWBI_ASBI
#define     asbiwbc  VWBC_ASBI
#define     asbiwhu  VWHU_ASBI
#define     asbiwhi  VWHI_ASBI
#define     asbiwhf  VWHF_ASBI
#define     asbiwwu  VWWU_ASBI
#define     asbiwwi  VWWI_ASBI
#define     asbiwwf  VWWF_ASBI

#define     asbidyu  VDYU_ASBI
#define     asbidbu  VDBU_ASBI
#define     asbidbi  VDBI_ASBI
#define     asbidbc  VDBC_ASBI
#define     asbidhu  VDHU_ASBI
#define     asbidhi  VDHI_ASBI
#define     asbidhf  VDHF_ASBI
#define     asbidwu  VDWU_ASBI
#define     asbidwi  VDWI_ASBI
#define     asbidwf  VDWF_ASBI
#define     asbiddu  VDDU_ASBI
#define     asbiddi  VDDI_ASBI
#define     asbiddf  VDDF_ASBI

#define     asbiqyu  VQYU_ASBI
#define     asbiqbu  VQBU_ASBI
#define     asbiqbi  VQBI_ASBI
#define     asbiqbc  VQBC_ASBI
#define     asbiqhu  VQHU_ASBI
#define     asbiqhi  VQHI_ASBI
#define     asbiqhf  VQHF_ASBI
#define     asbiqwu  VQWU_ASBI
#define     asbiqwi  VQWI_ASBI
#define     asbiqwf  VQWF_ASBI
#define     asbiqdu  VQDU_ASBI
#define     asbiqdi  VQDI_ASBI
#define     asbiqdf  VQDF_ASBI
#if _LEAVE_ASBI
}
#endif

#if _ENTER_ASBC
{
#endif
/*  reinterpret cAST Byte (uint8_t)

Reinterpret 8 bit scalar representation as char or a
vector as the equivalent width char vector
*/

#define     asbc(X) (asbc_funcof(X)(X))
#define     asbc_funcof(X)  \
FUNCOF(             \
    asbc, (   X   ),\
    BR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asbcbu   UINT8_ASBC
#define     asbcbi    INT8_ASBC
#define     asbcbc    CHAR_ASBC

#define     asbcwyu  VWYU_ASBC
#define     asbcwbu  VWBU_ASBC
#define     asbcwbi  VWBI_ASBC
#define     asbcwbc  VWBC_ASBC
#define     asbcwhu  VWHU_ASBC
#define     asbcwhi  VWHI_ASBC
#define     asbcwhf  VWHF_ASBC
#define     asbcwwu  VWWU_ASBC
#define     asbcwwi  VWWI_ASBC
#define     asbcwwf  VWWF_ASBC

#define     asbcdyu  VDYU_ASBC
#define     asbcdbu  VDBU_ASBC
#define     asbcdbi  VDBI_ASBC
#define     asbcdbc  VDBC_ASBC
#define     asbcdhu  VDHU_ASBC
#define     asbcdhi  VDHI_ASBC
#define     asbcdhf  VDHF_ASBC
#define     asbcdwu  VDWU_ASBC
#define     asbcdwi  VDWI_ASBC
#define     asbcdwf  VDWF_ASBC
#define     asbcddu  VDDU_ASBC
#define     asbcddi  VDDI_ASBC
#define     asbcddf  VDDF_ASBC

#define     asbcqyu  VQYU_ASBC
#define     asbcqbu  VQBU_ASBC
#define     asbcqbi  VQBI_ASBC
#define     asbcqbc  VQBC_ASBC
#define     asbcqhu  VQHU_ASBC
#define     asbcqhi  VQHI_ASBC
#define     asbcqhf  VQHF_ASBC
#define     asbcqwu  VQWU_ASBC
#define     asbcqwi  VQWI_ASBC
#define     asbcqwf  VQWF_ASBC
#define     asbcqdu  VQDU_ASBC
#define     asbcqdi  VQDI_ASBC
#define     asbcqdf  VQDF_ASBC
#if _LEAVE_ASBC
}
#endif

#if _ENTER_ASHU
{
#endif
/*  Reinterpret the binary representation of a 16 bit
    scalar as an unsigned integer or a vector as a vector
    of 16 bit unsigned integers.
*/

#define     ashu(X) (ashu_funcof(X)(X))
#define     ashu_funcof(X)  \
FUNCOF(             \
    ashu, (   X   ),\
    HR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ashuhu   UINT16_ASHU
#define     ashuhi    INT16_ASHU
#define     ashuhf    FLT16_ASHU

#define     ashuwyu  VWYU_ASHU
#define     ashuwbu  VWBU_ASHU
#define     ashuwbi  VWBI_ASHU
#define     ashuwbc  VWBC_ASHU
#define     ashuwhu  VWHU_ASHU
#define     ashuwhi  VWHI_ASHU
#define     ashuwhf  VWHF_ASHU
#define     ashuwwu  VWWU_ASHU
#define     ashuwwi  VWWI_ASHU
#define     ashuwwf  VWWF_ASHU

#define     ashudyu  VDYU_ASHU
#define     ashudbu  VDBU_ASHU
#define     ashudbi  VDBI_ASHU
#define     ashudbc  VDBC_ASHU
#define     ashudhu  VDHU_ASHU
#define     ashudhi  VDHI_ASHU
#define     ashudhf  VDHF_ASHU
#define     ashudwu  VDWU_ASHU
#define     ashudwi  VDWI_ASHU
#define     ashudwf  VDWF_ASHU
#define     ashuddu  VDDU_ASHU
#define     ashuddi  VDDI_ASHU
#define     ashuddf  VDDF_ASHU

#define     ashuqyu  VQYU_ASHU
#define     ashuqbu  VQBU_ASHU
#define     ashuqbi  VQBI_ASHU
#define     ashuqbc  VQBC_ASHU
#define     ashuqhu  VQHU_ASHU
#define     ashuqhi  VQHI_ASHU
#define     ashuqhf  VQHF_ASHU
#define     ashuqwu  VQWU_ASHU
#define     ashuqwi  VQWI_ASHU
#define     ashuqwf  VQWF_ASHU
#define     ashuqdu  VQDU_ASHU
#define     ashuqdi  VQDI_ASHU
#define     ashuqdf  VQDF_ASHU
#if _LEAVE_ASHU
}
#endif

#if _ENTER_ASHI
{
#endif
/*  Reinterpret the binary representation of a 16 bit
    scalar as a signed integer or a vector as a vector
    of 16 bit signed integers.
*/

#define     ashi(X) (ashi_funcof(X)(X))
#define     ashi_funcof(X)  \
FUNCOF(             \
    ashi, (   X   ),\
    HR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ashihu   UINT16_ASHI
#define     ashihi    INT16_ASHI
#define     ashihf    FLT16_ASHI

#define     ashiwyu  VWYU_ASHI
#define     ashiwbu  VWBU_ASHI
#define     ashiwbi  VWBI_ASHI
#define     ashiwbc  VWBC_ASHI
#define     ashiwhu  VWHU_ASHI
#define     ashiwhi  VWHI_ASHI
#define     ashiwhf  VWHF_ASHI
#define     ashiwwu  VWWU_ASHI
#define     ashiwwi  VWWI_ASHI
#define     ashiwwf  VWWF_ASHI

#define     ashidyu  VDYU_ASHI
#define     ashidbu  VDBU_ASHI
#define     ashidbi  VDBI_ASHI
#define     ashidbc  VDBC_ASHI
#define     ashidhu  VDHU_ASHI
#define     ashidhi  VDHI_ASHI
#define     ashidhf  VDHF_ASHI
#define     ashidwu  VDWU_ASHI
#define     ashidwi  VDWI_ASHI
#define     ashidwf  VDWF_ASHI
#define     ashiddu  VDDU_ASHI
#define     ashiddi  VDDI_ASHI
#define     ashiddf  VDDF_ASHI

#define     ashiqyu  VQYU_ASHI
#define     ashiqbu  VQBU_ASHI
#define     ashiqbi  VQBI_ASHI
#define     ashiqbc  VQBC_ASHI
#define     ashiqhu  VQHU_ASHI
#define     ashiqhi  VQHI_ASHI
#define     ashiqhf  VQHF_ASHI
#define     ashiqwu  VQWU_ASHI
#define     ashiqwi  VQWI_ASHI
#define     ashiqwf  VQWF_ASHI
#define     ashiqdu  VQDU_ASHI
#define     ashiqdi  VQDI_ASHI
#define     ashiqdf  VQDF_ASHI
#if _LEAVE_ASHI
}
#endif

#if _ENTER_ASHF
{
#endif
/*  Reinterpret the binary representation of a 16 bit
    scalar as a half precision binary16 float or a vector
    as a vector of half precision floats.
*/

#define     ashf(X) (ashf_funcof(X)(X))
#define     ashf_funcof(X)  \
FUNCOF(             \
    ashf, (   X   ),\
    HR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ashfhu   UINT16_ASHF
#define     ashfhi    INT16_ASHF
#define     ashfhf    FLT16_ASHF

#define     ashfwyu  VWYU_ASHF
#define     ashfwbu  VWBU_ASHF
#define     ashfwbi  VWBI_ASHF
#define     ashfwbc  VWBC_ASHF
#define     ashfwhu  VWHU_ASHF
#define     ashfwhi  VWHI_ASHF
#define     ashfwhf  VWHF_ASHF
#define     ashfwwu  VWWU_ASHF
#define     ashfwwi  VWWI_ASHF
#define     ashfwwf  VWWF_ASHF

#define     ashfdyu  VDYU_ASHF
#define     ashfdbu  VDBU_ASHF
#define     ashfdbi  VDBI_ASHF
#define     ashfdbc  VDBC_ASHF
#define     ashfdhu  VDHU_ASHF
#define     ashfdhi  VDHI_ASHF
#define     ashfdhf  VDHF_ASHF
#define     ashfdwu  VDWU_ASHF
#define     ashfdwi  VDWI_ASHF
#define     ashfdwf  VDWF_ASHF
#define     ashfddu  VDDU_ASHF
#define     ashfddi  VDDI_ASHF
#define     ashfddf  VDDF_ASHF

#define     ashfqyu  VQYU_ASHF
#define     ashfqbu  VQBU_ASHF
#define     ashfqbi  VQBI_ASHF
#define     ashfqbc  VQBC_ASHF
#define     ashfqhu  VQHU_ASHF
#define     ashfqhi  VQHI_ASHF
#define     ashfqhf  VQHF_ASHF
#define     ashfqwu  VQWU_ASHF
#define     ashfqwi  VQWI_ASHF
#define     ashfqwf  VQWF_ASHF
#define     ashfqdu  VQDU_ASHF
#define     ashfqdi  VQDI_ASHF
#define     ashfqdf  VQDF_ASHF
#if _LEAVE_ASHF
}
#endif

#if _ENTER_ASWU
{
#endif
/*  Reinterpret the binary representation of a 32 bit
    scalar as an unsigned integer or a vector as a vector
    of 32 bit unsigned integers.
*/

#define     aswu(X) (aswu_funcof(X)(X))
#define     aswu_funcof(X)  \
FUNCOF(             \
    aswu, (   X   ),\
    WR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     aswuwu   UINT32_ASWU
#define     aswuwi    INT32_ASWU
#define     aswuwf    FLT_ASWU
#if DWRD_NLONG == 2
#   define  aswulu  ULONG_ASWU
#   define  aswuli   LONG_ASWU
#endif

#define     aswuwyu  VWYU_ASWU
#define     aswuwbu  VWBU_ASWU
#define     aswuwbi  VWBI_ASWU
#define     aswuwbc  VWBC_ASWU
#define     aswuwhu  VWHU_ASWU
#define     aswuwhi  VWHI_ASWU
#define     aswuwhf  VWHF_ASWU
#define     aswuwwu  VWWU_ASWU
#define     aswuwwi  VWWI_ASWU
#define     aswuwwf  VWWF_ASWU

#define     aswudyu  VDYU_ASWU
#define     aswudbu  VDBU_ASWU
#define     aswudbi  VDBI_ASWU
#define     aswudbc  VDBC_ASWU
#define     aswudhu  VDHU_ASWU
#define     aswudhi  VDHI_ASWU
#define     aswudhf  VDHF_ASWU
#define     aswudwu  VDWU_ASWU
#define     aswudwi  VDWI_ASWU
#define     aswudwf  VDWF_ASWU
#define     aswuddu  VDDU_ASWU
#define     aswuddi  VDDI_ASWU
#define     aswuddf  VDDF_ASWU

#define     aswuqyu  VQYU_ASWU
#define     aswuqbu  VQBU_ASWU
#define     aswuqbi  VQBI_ASWU
#define     aswuqbc  VQBC_ASWU
#define     aswuqhu  VQHU_ASWU
#define     aswuqhi  VQHI_ASWU
#define     aswuqhf  VQHF_ASWU
#define     aswuqwu  VQWU_ASWU
#define     aswuqwi  VQWI_ASWU
#define     aswuqwf  VQWF_ASWU
#define     aswuqdu  VQDU_ASWU
#define     aswuqdi  VQDI_ASWU
#define     aswuqdf  VQDF_ASWU
#if _LEAVE_ASWU
}
#endif

#if _ENTER_ASWI
{
#endif
/*  Reinterpret the binary representation of a 32 bit
    scalar as a signed integer or a vector as a vector
    of 32 bit signed integers.
*/

#define     aswi(X) (aswi_funcof(X)(X))
#define     aswi_funcof(X)  \
FUNCOF(             \
    aswi, (   X   ),\
    WR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     aswiwu   UINT32_ASWI
#define     aswiwi    INT32_ASWI
#define     aswiwf    FLT_ASWI
#if DWRD_NLONG == 2
#   define  aswilu  ULONG_ASWI
#   define  aswili   LONG_ASWI
#endif

#define     aswiwyu  VWYU_ASWI
#define     aswiwbu  VWBU_ASWI
#define     aswiwbi  VWBI_ASWI
#define     aswiwbc  VWBC_ASWI
#define     aswiwhu  VWHU_ASWI
#define     aswiwhi  VWHI_ASWI
#define     aswiwhf  VWHF_ASWI
#define     aswiwwu  VWWU_ASWI
#define     aswiwwi  VWWI_ASWI
#define     aswiwwf  VWWF_ASWI

#define     aswidyu  VDYU_ASWI
#define     aswidbu  VDBU_ASWI
#define     aswidbi  VDBI_ASWI
#define     aswidbc  VDBC_ASWI
#define     aswidhu  VDHU_ASWI
#define     aswidhi  VDHI_ASWI
#define     aswidhf  VDHF_ASWI
#define     aswidwu  VDWU_ASWI
#define     aswidwi  VDWI_ASWI
#define     aswidwf  VDWF_ASWI
#define     aswiddu  VDDU_ASWI
#define     aswiddi  VDDI_ASWI
#define     aswiddf  VDDF_ASWI

#define     aswiqyu  VQYU_ASWI
#define     aswiqbu  VQBU_ASWI
#define     aswiqbi  VQBI_ASWI
#define     aswiqbc  VQBC_ASWI
#define     aswiqhu  VQHU_ASWI
#define     aswiqhi  VQHI_ASWI
#define     aswiqhf  VQHF_ASWI
#define     aswiqwu  VQWU_ASWI
#define     aswiqwi  VQWI_ASWI
#define     aswiqwf  VQWF_ASWI
#define     aswiqdu  VQDU_ASWI
#define     aswiqdi  VQDI_ASWI
#define     aswiqdf  VQDF_ASWI
#if _LEAVE_ASWI
}
#endif

#if _ENTER_ASWF
{
#endif
/*  Reinterpret the binary representation of a 32 bit
    scalar as a single precision binary32 float or a
    vector as a vector of single precision floats.
*/

#define     aswf(X) (aswf_funcof(X)(X))
#define     aswf_funcof(X)  \
FUNCOF(             \
    aswf, (   X   ),\
    WR,   /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     aswfwu   UINT32_ASWF
#define     aswfwi    INT32_ASWF
#define     aswfwf    FLT_ASWF
#if DWRD_NLONG == 2
#   define  aswflu  ULONG_ASWF
#   define  aswfli   LONG_ASWF
#endif

#define     aswfwyu  VWYU_ASWF
#define     aswfwbu  VWBU_ASWF
#define     aswfwbi  VWBI_ASWF
#define     aswfwbc  VWBC_ASWF
#define     aswfwhu  VWHU_ASWF
#define     aswfwhi  VWHI_ASWF
#define     aswfwhf  VWHF_ASWF
#define     aswfwwu  VWWU_ASWF
#define     aswfwwi  VWWI_ASWF
#define     aswfwwf  VWWF_ASWF

#define     aswfdyu  VDYU_ASWF
#define     aswfdbu  VDBU_ASWF
#define     aswfdbi  VDBI_ASWF
#define     aswfdbc  VDBC_ASWF
#define     aswfdhu  VDHU_ASWF
#define     aswfdhi  VDHI_ASWF
#define     aswfdhf  VDHF_ASWF
#define     aswfdwu  VDWU_ASWF
#define     aswfdwi  VDWI_ASWF
#define     aswfdwf  VDWF_ASWF
#define     aswfddu  VDDU_ASWF
#define     aswfddi  VDDI_ASWF
#define     aswfddf  VDDF_ASWF

#define     aswfqyu  VQYU_ASWF
#define     aswfqbu  VQBU_ASWF
#define     aswfqbi  VQBI_ASWF
#define     aswfqbc  VQBC_ASWF
#define     aswfqhu  VQHU_ASWF
#define     aswfqhi  VQHI_ASWF
#define     aswfqhf  VQHF_ASWF
#define     aswfqwu  VQWU_ASWF
#define     aswfqwi  VQWI_ASWF
#define     aswfqwf  VQWF_ASWF
#define     aswfqdu  VQDU_ASWF
#define     aswfqdi  VQDI_ASWF
#define     aswfqdf  VQDF_ASWF
#if _LEAVE_ASWF
}
#endif

#if _ENTER_ASDU
{
#endif
/*  Reinterpret the binary representation of a 64 bit
    scalar as an unsigned integer or a vector as a vector
    of 64 bit unsigned integers.
*/

#define     asdu(X) (asdu_funcof(X)(X))
#define     asdu_funcof(X)  \
FUNCOF(             \
    asdu, (   X   ),\
    DR,   /* TGK */ \
    NONE, /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asdudu UINT64_ASDU
#define     asdudi  INT64_ASDU
#define     asdudf    DBL_ASDU
#if QUAD_NLLONG == 2
#   define  asdulu ULLONG_ASDU
#   define  asduli  LLONG_ASDU
#endif

#define     asdudyu  VDYU_ASDU
#define     asdudbu  VDBU_ASDU
#define     asdudbi  VDBI_ASDU
#define     asdudbc  VDBC_ASDU
#define     asdudhu  VDHU_ASDU
#define     asdudhi  VDHI_ASDU
#define     asdudhf  VDHF_ASDU
#define     asdudwu  VDWU_ASDU
#define     asdudwi  VDWI_ASDU
#define     asdudwf  VDWF_ASDU
#define     asduddu  VDDU_ASDU
#define     asduddi  VDDI_ASDU
#define     asduddf  VDDF_ASDU

#define     asduqyu  VQYU_ASDU
#define     asduqbu  VQBU_ASDU
#define     asduqbi  VQBI_ASDU
#define     asduqbc  VQBC_ASDU
#define     asduqhu  VQHU_ASDU
#define     asduqhi  VQHI_ASDU
#define     asduqhf  VQHF_ASDU
#define     asduqwu  VQWU_ASDU
#define     asduqwi  VQWI_ASDU
#define     asduqwf  VQWF_ASDU
#define     asduqdu  VQDU_ASDU
#define     asduqdi  VQDI_ASDU
#define     asduqdf  VQDF_ASDU
#if _LEAVE_ASDU
}
#endif

#if _ENTER_ASDI
{
#endif
/*  Reinterpret the binary representation of a 64 bit
    scalar as an signed integer or a vector as a vector
    of 64 bit signed integers.
*/

#define     asdi(X) (asdi_funcof(X)(X))
#define     asdi_funcof(X)  \
FUNCOF(             \
    asdi, (   X   ),\
    DR,   /* TGK */ \
    NONE, /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asdidu UINT64_ASDI
#define     asdidi  INT64_ASDI
#define     asdidf    DBL_ASDI
#if QUAD_NLLONG == 2
#   define  asdilu ULLONG_ASDI
#   define  asdili  LLONG_ASDI
#endif

#define     asdidyu  VDYU_ASDI
#define     asdidbu  VDBU_ASDI
#define     asdidbi  VDBI_ASDI
#define     asdidbc  VDBC_ASDI
#define     asdidhu  VDHU_ASDI
#define     asdidhi  VDHI_ASDI
#define     asdidhf  VDHF_ASDI
#define     asdidwu  VDWU_ASDI
#define     asdidwi  VDWI_ASDI
#define     asdidwf  VDWF_ASDI
#define     asdiddu  VDDU_ASDI
#define     asdiddi  VDDI_ASDI
#define     asdiddf  VDDF_ASDI

#define     asdiqyu  VQYU_ASDI
#define     asdiqbu  VQBU_ASDI
#define     asdiqbi  VQBI_ASDI
#define     asdiqbc  VQBC_ASDI
#define     asdiqhu  VQHU_ASDI
#define     asdiqhi  VQHI_ASDI
#define     asdiqhf  VQHF_ASDI
#define     asdiqwu  VQWU_ASDI
#define     asdiqwi  VQWI_ASDI
#define     asdiqwf  VQWF_ASDI
#define     asdiqdu  VQDU_ASDI
#define     asdiqdi  VQDI_ASDI
#define     asdiqdf  VQDF_ASDI
#if _LEAVE_ASDI
}
#endif

#if _ENTER_ASDF
{
#endif
/*  Reinterpret the binary representation of a 64 bit
    scalar as a double precision binary64 float or a
    vector as a vector of double precision floats.
*/

#define     asdf(X) (asdf_funcof(X)(X))
#define     asdf_funcof(X)  \
FUNCOF(             \
    asdf, (   X   ),\
    DR,   /* TGK */ \
    NONE, /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     asdfdu UINT64_ASDF
#define     asdfdi  INT64_ASDF
#define     asdfdf    DBL_ASDF
#if QUAD_NLLONG == 2
#   define  asdflu ULLONG_ASDF
#   define  asdfli  LLONG_ASDF
#endif

#define     asdfdyu VDYU_ASDF
#define     asdfdbu VDBU_ASDF
#define     asdfdbi VDBI_ASDF
#define     asdfdbc VDBC_ASDF
#define     asdfdhu VDHU_ASDF
#define     asdfdhi VDHI_ASDF
#define     asdfdhf VDHF_ASDF
#define     asdfdwu VDWU_ASDF
#define     asdfdwi VDWI_ASDF
#define     asdfdwf VDWF_ASDF
#define     asdfddu VDDU_ASDF
#define     asdfddi VDDI_ASDF
#define     asdfddf VDDF_ASDF

#define     asdfqyu VQYU_ASDF
#define     asdfqbu VQBU_ASDF
#define     asdfqbi VQBI_ASDF
#define     asdfqbc VQBC_ASDF
#define     asdfqhu VQHU_ASDF
#define     asdfqhi VQHI_ASDF
#define     asdfqhf VQHF_ASDF
#define     asdfqwu VQWU_ASDF
#define     asdfqwi VQWI_ASDF
#define     asdfqwf VQWF_ASDF
#define     asdfqdu VQDU_ASDF
#define     asdfqdi VQDI_ASDF
#define     asdfqdf VQDF_ASDF
#if _LEAVE_ASDF
}
#endif


#if _ENTER_AVGL
{
#endif
/*  AVeraGe (truncated)

Compute the truncated average of each corresponding pair
of elements in the two operands.
*/

#define     avgl(...) (avgl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     avgl_funcof(A, ...)  \
FUNCOF(             \
    avgl, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     avglyu    BOOL_AVGL
#define     avglbu   UINT8_AVGL
#define     avglbi    INT8_AVGL
#define     avglbc    CHAR_AVGL
#define     avglhu  UINT16_AVGL
#define     avglhi   INT16_AVGL
#define     avglwu  UINT32_AVGL
#define     avglwi   INT32_AVGL
#define     avgldu  UINT64_AVGL
#define     avgldi   INT64_AVGL
#if   DWRD_NLONG == 2
#   define  avgllu   ULONG_AVGL
#   define  avglli    LONG_AVGL
#elif QUAD_NLLONG == 2
#   define  avgllu  ULLONG_AVGL
#   define  avglli   LLONG_AVGL
#else
#   define  avglqu  ULLONG_AVGL
#   define  avglqi   LLONG_AVGL
#endif

#define     avglwyu   VWYU_AVGL
#define     avglwbu   VWBU_AVGL
#define     avglwbi   VWBI_AVGL
#define     avglwbc   VWBC_AVGL
#define     avglwhu   VWHU_AVGL
#define     avglwhi   VWHI_AVGL
#define     avglwwu   VWWU_AVGL
#define     avglwwi   VWWI_AVGL

#define     avgldyu   VDYU_AVGL
#define     avgldbu   VDBU_AVGL
#define     avgldbi   VDBI_AVGL
#define     avgldbc   VDBC_AVGL
#define     avgldhu   VDHU_AVGL
#define     avgldhi   VDHI_AVGL
#define     avgldwu   VDWU_AVGL
#define     avgldwi   VDWI_AVGL
#define     avglddu   VDDU_AVGL
#define     avglddi   VDDI_AVGL

#define     avglqyu   VQYU_AVGL
#define     avglqbu   VQBU_AVGL
#define     avglqbi   VQBI_AVGL
#define     avglqbc   VQBC_AVGL
#define     avglqhu   VQHU_AVGL
#define     avglqhi   VQHI_AVGL
#define     avglqwu   VQWU_AVGL
#define     avglqwi   VQWI_AVGL
#define     avglqdu   VQDU_AVGL
#define     avglqdi   VQDI_AVGL
#if _LEAVE_AVGL
}
#endif


#if _ENTER_BFC1
{
#endif
/*  BitField Clear

Clear (set all zero) a contiguous sequence of bits within
a single allocation unit, specified as a starting offset
and length.

Perhaps somewhat unintuitively, the vector variants
operate on the entire vector as if it were an equivalent
length unsigned int.
*/

#define     bfc1(...)  (bfc1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     bfc1_funcof(S, ...) \
FUNCOF(             \
    bfc1, (   S   ),\
    BDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     bfc1bu   UINT8_BFC1
#define     bfc1bi    INT8_BFC1
#define     bfc1bc    CHAR_BFC1
#define     bfc1hu  UINT16_BFC1
#define     bfc1hi   INT16_BFC1
#define     bfc1wu  UINT32_BFC1
#define     bfc1wi   INT32_BFC1
#define     bfc1du  UINT64_BFC1
#define     bfc1di   INT64_BFC1
#if DWRD_NLONG == 2
#   define  bfc1lu   ULONG_BFC1
#   define  bfc1li    LONG_BFC1
#elif QUAD_NLLONG == 2
#   define  bfc1lu  ULLONG_BFC1
#   define  bfc1li   LLONG_BFC1
#else
#   define  bfc1qu  ULLONG_BFC1
#   define  bfc1qi   LLONG_BFC1
#endif

#define     bfc1wyu VWYU_BFC1
#define     bfc1wbu VWBU_BFC1
#define     bfc1wbi VWBI_BFC1
#define     bfc1wbc VWBC_BFC1
#define     bfc1whu VWHU_BFC1
#define     bfc1whi VWHI_BFC1
#define     bfc1wwu VWWU_BFC1
#define     bfc1wwi VWWI_BFC1

#define     bfc1dyu VDYU_BFC1
#define     bfc1dbu VDBU_BFC1
#define     bfc1dbi VDBI_BFC1
#define     bfc1dbc VDBC_BFC1
#define     bfc1dhu VDHU_BFC1
#define     bfc1dhi VDHI_BFC1
#define     bfc1dwu VDWU_BFC1
#define     bfc1dwi VDWI_BFC1
#define     bfc1ddu VDDU_BFC1
#define     bfc1ddi VDDI_BFC1

#define     bfc1qyu VQYU_BFC1
#define     bfc1qbu VQBU_BFC1
#define     bfc1qbi VQBI_BFC1
#define     bfc1qbc VQBC_BFC1
#define     bfc1qhu VQHU_BFC1
#define     bfc1qhi VQHI_BFC1
#define     bfc1qwu VQWU_BFC1
#define     bfc1qwi VQWI_BFC1
#define     bfc1qdu VQDU_BFC1
#define     bfc1qdi VQDI_BFC1
#if _LEAVE_BFC1
}
#endif

#if _ENTER_BFG1
{
#endif
/*  Bit Field Get

"Load" a bit field.

For scalars, the operation is semantically equivalent to
accessing a C bit field of the corresponding type. If the
sum of the offset and length operands exceeds the width of
the allocation unit/element type, the result is undefined.

An N bit vector is handled as an abstract allocation unit
for bfg, i.e. bfg1qhi interprets the first operand as an
array of 128 bits, and extracts 1 to 16 consecutive bits
from any valid offset as an int16_t.

The boolean vectors are special cases. The maximum value
of the third operand - LEN - is the length of the vector.
Thus, bfg1*yu may be used to efficiently slice any vector
with single bit precision.

Note that the 128 bit vector ops will be significantly
slower than the 64 bit ops on architecture without 128 bit
shift instructions, which is all targets at present.
*/

#define     bfg1(...)  (bfg1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     bfg1_funcof(S, ...) \
FUNCOF(             \
    bfg1, (   S   ),\
    BDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     bfg1bu   UINT8_BFG1
#define     bfg1bi    INT8_BFG1
#define     bfg1bc    CHAR_BFG1
#define     bfg1hu  UINT16_BFG1
#define     bfg1hi   INT16_BFG1
#define     bfg1wu  UINT32_BFG1
#define     bfg1wi   INT32_BFG1
#define     bfg1du  UINT64_BFG1
#define     bfg1di   INT64_BFG1
#if DWRD_NLONG == 2
#   define  bfg1lu   ULONG_BFG1
#   define  bfg1li    LONG_BFG1
#elif QUAD_NLLONG == 2
#   define  bfg1lu  ULLONG_BFG1
#   define  bfg1li   LLONG_BFG1
#else
#   define  bfg1qu  ULLONG_BFG1
#   define  bfg1qi   LLONG_BFG1
#endif

#define     bfg1wyu VWYU_BFG1
#define     bfg1wbu VWBU_BFG1
#define     bfg1wbi VWBI_BFG1
#define     bfg1wbc VWBC_BFG1
#define     bfg1whu VWHU_BFG1
#define     bfg1whi VWHI_BFG1
#define     bfg1wwu VWWU_BFG1
#define     bfg1wwi VWWI_BFG1

#define     bfg1dyu VDYU_BFG1
#define     bfg1dbu VDBU_BFG1
#define     bfg1dbi VDBI_BFG1
#define     bfg1dbc VDBC_BFG1
#define     bfg1dhu VDHU_BFG1
#define     bfg1dhi VDHI_BFG1
#define     bfg1dwu VDWU_BFG1
#define     bfg1dwi VDWI_BFG1
#define     bfg1ddu VDDU_BFG1
#define     bfg1ddi VDDI_BFG1

#define     bfg1qyu VQYU_BFG1
#define     bfg1qbu VQBU_BFG1
#define     bfg1qbi VQBI_BFG1
#define     bfg1qbc VQBC_BFG1
#define     bfg1qhu VQHU_BFG1
#define     bfg1qhi VQHI_BFG1
#define     bfg1qwu VQWU_BFG1
#define     bfg1qwi VQWI_BFG1
#define     bfg1qdu VQDU_BFG1
#define     bfg1qdi VQDI_BFG1
#if _LEAVE_BFG1
}
#endif

#if _ENTER_BFS1
{
#endif
/*  Bit Field Set

Takes 4 operands: the allocation unit DST; the offset in
bits of the field OFF; the size in bits of the field LEN;
and the value to store.

Like with bfg1, the vector variants use the entire vector
as the allocation unit, which allows manipulating the
vector's binary representation across lane boundaries.

TODO: arm implementation needs massive overhaul

*/

#define     bfs1(...)  (bfs1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     bfs1_funcof(S, ...) \
FUNCOF(             \
    bfs1, (   S   ),\
    BDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     bfs1bu   UINT8_BFS1
#define     bfs1bi    INT8_BFS1
#define     bfs1bc    CHAR_BFS1
#define     bfs1hu  UINT16_BFS1
#define     bfs1hi   INT16_BFS1
#define     bfs1wu  UINT32_BFS1
#define     bfs1wi   INT32_BFS1
#define     bfs1du  UINT64_BFS1
#define     bfs1di   INT64_BFS1
#if DWRD_NLONG == 2
#   define  bfs1lu   ULONG_BFS1
#   define  bfs1li    LONG_BFS1
#elif QUAD_NLLONG == 2
#   define  bfs1lu  ULLONG_BFS1
#   define  bfs1li   LLONG_BFS1
#else
#   define  bfs1qu  ULLONG_BFS1
#   define  bfs1qi   LLONG_BFS1
#endif

#define     bfs1wyu VWYU_BFS1
#define     bfs1wbu VWBU_BFS1
#define     bfs1wbi VWBI_BFS1
#define     bfs1wbc VWBC_BFS1
#define     bfs1whu VWHU_BFS1
#define     bfs1whi VWHI_BFS1
#define     bfs1wwu VWWU_BFS1
#define     bfs1wwi VWWI_BFS1

#define     bfs1dyu VDYU_BFS1
#define     bfs1dbu VDBU_BFS1
#define     bfs1dbi VDBI_BFS1
#define     bfs1dbc VDBC_BFS1
#define     bfs1dhu VDHU_BFS1
#define     bfs1dhi VDHI_BFS1
#define     bfs1dwu VDWU_BFS1
#define     bfs1dwi VDWI_BFS1
#define     bfs1ddu VDDU_BFS1
#define     bfs1ddi VDDI_BFS1

#define     bfs1qyu VQYU_BFS1
#define     bfs1qbu VQBU_BFS1
#define     bfs1qbi VQBI_BFS1
#define     bfs1qbc VQBC_BFS1
#define     bfs1qhu VQHU_BFS1
#define     bfs1qhi VQHI_BFS1
#define     bfs1qwu VQWU_BFS1
#define     bfs1qwi VQWI_BFS1
#define     bfs1qdu VQDU_BFS1
#define     bfs1qdi VQDI_BFS1
#if _LEAVE_BFS1
}
#endif


#if _ENTER_BLNM
{
#endif
/*  BLeNd

Construct a N element vector C of type T based on two T
vectors A and B plus N additional Boolean parameters, K.
Starting at lane I=0, if K[I] is false, C[I]=A[I], else
C[I]=B[I].
*/

#define     blnm(...)    (blnm_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     blnm_funcof(X,...)  \
FUNCOF(             \
    blnm, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     blnmwbu VWBU_BLNM
#define     blnmwbi VWBI_BLNM
#define     blnmwbc VWBC_BLNM
#define     blnmwhu VWHU_BLNM
#define     blnmwhi VWHI_BLNM
#define     blnmwhf VWHF_BLNM

#define     blnmdbu VDBU_BLNM
#define     blnmdbi VDBI_BLNM
#define     blnmdbc VDBC_BLNM
#define     blnmdhu VDHU_BLNM
#define     blnmdhi VDHI_BLNM
#define     blnmdhf VDHF_BLNM
#define     blnmdwu VDWU_BLNM
#define     blnmdwi VDWI_BLNM
#define     blnmdwf VDWF_BLNM

#define     blnmqbu VQBU_BLNM
#define     blnmqbi VQBI_BLNM
#define     blnmqbc VQBC_BLNM
#define     blnmqhu VQHU_BLNM
#define     blnmqhi VQHI_BLNM
#define     blnmqhf VQHF_BLNM
#define     blnmqwu VQWU_BLNM
#define     blnmqwi VQWI_BLNM
#define     blnmqwf VQWF_BLNM
#define     blnmqdu VQDU_BLNM
#define     blnmqdi VQDI_BLNM
#define     blnmqdf VQDF_BLNM
#if _LEAVE_BLNM
}
#endif


#if _ENTER_CATL
{
#endif
/*  Concatenate the binary representations of two values.

E.g. catlwu(a, z) takes two uint32_t values and returns a
uint64_t with its 32 most significant bits equal to z.
*/

#define     catl(...)  (catl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     catl_funcof(L,...)  \
FUNCOF(             \
    catl, (   L   ),\
    BWZ,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     catlbu    UINT8_CATL
#define     catlbi     INT8_CATL
#define     catlbc     CHAR_CATL
#define     catlhu   UINT16_CATL
#define     catlhi    INT16_CATL
#define     catlhf    FLT16_CATL
#define     catlwu   UINT32_CATL
#define     catlwi    INT32_CATL
#define     catldu   UINT64_CATL
#define     catldi    INT64_CATL
#if DWRD_NLONG == 2
#   define  catllu    ULONG_CATL
#   define  catlli     LONG_CATL
#elif QUAD_NLLONG == 2
#   define  catllu   ULLONG_CATL
#   define  catlli    LLONG_CATL
#else
#   define  catlqu   ULLONG_CATL
#   define  catlqi    LLONG_CATL
#endif

#define     catlwyu VWYU_CATL
#define     catlwbu VWBU_CATL
#define     catlwbi VWBI_CATL
#define     catlwbc VWBC_CATL
#define     catlwhu VWHU_CATL
#define     catlwhi VWHI_CATL
#define     catlwhf VWHF_CATL
#define     catlwwu VWWU_CATL
#define     catlwwi VWWI_CATL
#define     catlwwf VWWF_CATL

#define     catldyu VDYU_CATL
#define     catldbu VDBU_CATL
#define     catldbi VDBI_CATL
#define     catldbc VDBC_CATL
#define     catldhu VDHU_CATL
#define     catldhi VDHI_CATL
#define     catldhf VDHF_CATL
#define     catldwu VDWU_CATL
#define     catldwi VDWI_CATL
#define     catldwf VDWF_CATL
#define     catlddu VDDU_CATL
#define     catlddi VDDI_CATL
#define     catlddf VDDF_CATL

#if _LEAVE_CATL
}
#endif

#if _ENTER_CATR
{
#endif
/*  Combine catl with revs
*/

#define     catr(...)  (catr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     catr_funcof(L,...)  \
FUNCOF(             \
    catr, (   L   ),\
    NONE, /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     catrwyu VWYU_CATR
#define     catrwbu VWBU_CATR
#define     catrwbi VWBI_CATR
#define     catrwbc VWBC_CATR
#define     catrwhu VWHU_CATR
#define     catrwhi VWHI_CATR
#define     catrwhf VWHF_CATR
#define     catrwwu VWWU_CATR
#define     catrwwi VWWI_CATR
#define     catrwwf VWWF_CATR

#define     catrdyu VDYU_CATR
#define     catrdbu VDBU_CATR
#define     catrdbi VDBI_CATR
#define     catrdbc VDBC_CATR
#define     catrdhu VDHU_CATR
#define     catrdhi VDHI_CATR
#define     catrdhf VDHF_CATR
#define     catrdwu VDWU_CATR
#define     catrdwi VDWI_CATR
#define     catrdwf VDWF_CATR
#define     catrddu VDDU_CATR
#define     catrddi VDDI_CATR
#define     catrddf VDDF_CATR
#if _LEAVE_CATR
}
#endif


#if _ENTER_CBNS
{
#endif
/*  Compare BetweeN (saturated)

Test if each element in the first operand (A) is an
inclusive element of a range, setting all bits of the
corresponding result element to 1 if true and 0 otherwise.
The second operand (L) specifies the range's minimum bound
and the third (R) specifies its maximum. If R is less than
L, the result is undefined.
*/

#define     cbns(...) (cbns_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cbns_funcof(A, ...)  \
FUNCOF(             \
    cbns, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cbnsbu   UINT8_CBNS
#define     cbnsbi    INT8_CBNS
#define     cbnsbc    CHAR_CBNS
#define     cbnshu  UINT16_CBNS
#define     cbnshi   INT16_CBNS
#define     cbnshf   FLT16_CBNS
#define     cbnswu  UINT32_CBNS
#define     cbnswi   INT32_CBNS
#define     cbnswf     FLT_CBNS
#define     cbnsdu  UINT64_CBNS
#define     cbnsdi   INT64_CBNS
#define     cbnsdf     DBL_CBNS
#if DWRD_NLONG == 2
#   define  cbnslu   ULONG_CBNS
#   define  cbnsli    LONG_CBNS
#elif QUAD_NLLONG == 2
#   define  cbnslu  ULLONG_CBNS
#   define  cbnsli   LLONG_CBNS
#else
#   define  cbnsqu  ULLONG_CBNS
#   define  cbnsqi   LLONG_CBNS
#   define  cbnsqf    LDBL_CBNS
#endif

#define     cbnswbu   VWBU_CBNS
#define     cbnswbi   VWBI_CBNS
#define     cbnswbc   VWBC_CBNS
#define     cbnswhu   VWHU_CBNS
#define     cbnswhi   VWHI_CBNS
#define     cbnswhf   VWHF_CBNS
#define     cbnswwu   VWWU_CBNS
#define     cbnswwi   VWWI_CBNS
#define     cbnswwf   VWWF_CBNS

#define     cbnsdbu   VDBU_CBNS
#define     cbnsdbi   VDBI_CBNS
#define     cbnsdbc   VDBC_CBNS
#define     cbnsdhu   VDHU_CBNS
#define     cbnsdhi   VDHI_CBNS
#define     cbnsdhf   VDHF_CBNS
#define     cbnsdwu   VDWU_CBNS
#define     cbnsdwi   VDWI_CBNS
#define     cbnsdwf   VDWF_CBNS
#define     cbnsddu   VDDU_CBNS
#define     cbnsddi   VDDI_CBNS
#define     cbnsddf   VDDF_CBNS

#define     cbnsqbu   VQBU_CBNS
#define     cbnsqbi   VQBI_CBNS
#define     cbnsqbc   VQBC_CBNS
#define     cbnsqhu   VQHU_CBNS
#define     cbnsqhi   VQHI_CBNS
#define     cbnsqhf   VQHF_CBNS
#define     cbnsqwu   VQWU_CBNS
#define     cbnsqwi   VQWI_CBNS
#define     cbnsqwf   VQWF_CBNS
#define     cbnsqdu   VQDU_CBNS
#define     cbnsqdi   VQDI_CBNS
#define     cbnsqdf   VQDF_CBNS
#if _LEAVE_CBNS
}
#endif

#if _ENTER_CBNY
{
#endif
/*  Compare BetweeN (boolean)

Test if each element in the first operand (A) is an
inclusive element of a range, setting the least significant
bit of the corresponding result element to 1 if true and 0
otherwise. The second operand (L) specifies the range's
minimum bound and the third (R) specifies its maximum. If R
is less than L, the result is undefined.

*/

#define     cbny(...) (cbny_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cbny_funcof(A, ...)  \
FUNCOF(             \
    cbny, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cbnybu   UINT8_CBNY
#define     cbnybi    INT8_CBNY
#define     cbnybc    CHAR_CBNY
#define     cbnyhu  UINT16_CBNY
#define     cbnyhi   INT16_CBNY
#define     cbnyhf   FLT16_CBNY
#define     cbnywu  UINT32_CBNY
#define     cbnywi   INT32_CBNY
#define     cbnywf     FLT_CBNY
#define     cbnydu  UINT64_CBNY
#define     cbnydi   INT64_CBNY
#define     cbnydf     DBL_CBNY
#if DWRD_NLONG == 2
#   define  cbnylu   ULONG_CBNY
#   define  cbnyli    LONG_CBNY
#elif QUAD_NLLONG == 2
#   define  cbnylu  ULLONG_CBNY
#   define  cbnyli   LLONG_CBNY
#else
#   define  cbnyqu  ULLONG_CBNY
#   define  cbnyqi   LLONG_CBNY
#   define  cbnyqf    LDBL_CBNY
#endif

#define     cbnywbu   VWBU_CBNY
#define     cbnywbi   VWBI_CBNY
#define     cbnywbc   VWBC_CBNY
#define     cbnywhu   VWHU_CBNY
#define     cbnywhi   VWHI_CBNY
#define     cbnywhf   VWHF_CBNY
#define     cbnywwu   VWWU_CBNY
#define     cbnywwi   VWWI_CBNY
#define     cbnywwf   VWWF_CBNY

#define     cbnydbu   VDBU_CBNY
#define     cbnydbi   VDBI_CBNY
#define     cbnydbc   VDBC_CBNY
#define     cbnydhu   VDHU_CBNY
#define     cbnydhi   VDHI_CBNY
#define     cbnydhf   VDHF_CBNY
#define     cbnydwu   VDWU_CBNY
#define     cbnydwi   VDWI_CBNY
#define     cbnydwf   VDWF_CBNY
#define     cbnyddu   VDDU_CBNY
#define     cbnyddi   VDDI_CBNY
#define     cbnyddf   VDDF_CBNY

#define     cbnyqbu   VQBU_CBNY
#define     cbnyqbi   VQBI_CBNY
#define     cbnyqbc   VQBC_CBNY
#define     cbnyqhu   VQHU_CBNY
#define     cbnyqhi   VQHI_CBNY
#define     cbnyqhf   VQHF_CBNY
#define     cbnyqwu   VQWU_CBNY
#define     cbnyqwi   VQWI_CBNY
#define     cbnyqwf   VQWF_CBNY
#define     cbnyqdu   VQDU_CBNY
#define     cbnyqdi   VQDI_CBNY
#define     cbnyqdf   VQDF_CBNY
#if _LEAVE_CBNY
}
#endif


#if _ENTER_CEQS
{
#endif
/*  Elementwise compare 'A = B' (saturated)

For each element Ea in the first operand A and the
corresponding element Eb in the second operand B, set the
corresponding result element of the result to -1 if Ea
equals Eb. Otherwise, set it to zero.
*/

#define     ceqs(...) (ceqs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ceqs_funcof(A, ...)  \
FUNCOF(             \
    ceqs, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ceqsbu   UINT8_CEQS
#define     ceqsbi    INT8_CEQS
#define     ceqsbc    CHAR_CEQS
#define     ceqshu  UINT16_CEQS
#define     ceqshi   INT16_CEQS
#define     ceqshf   FLT16_CEQS
#define     ceqswu  UINT32_CEQS
#define     ceqswi   INT32_CEQS
#define     ceqswf     FLT_CEQS
#define     ceqsdu  UINT64_CEQS
#define     ceqsdi   INT64_CEQS
#define     ceqsdf     DBL_CEQS
#if DWRD_NLONG == 2
#   define  ceqslu   ULONG_CEQS
#   define  ceqsli    LONG_CEQS
#elif QUAD_NLLONG == 2
#   define  ceqslu  ULLONG_CEQS
#   define  ceqsli   LLONG_CEQS
#else
#   define  ceqsqu  ULLONG_CEQS
#   define  ceqsqi   LLONG_CEQS
#   define  ceqsqf    LDBL_CEQS
#endif

#define     ceqswbu   VWBU_CEQS
#define     ceqswbi   VWBI_CEQS
#define     ceqswbc   VWBC_CEQS
#define     ceqswhu   VWHU_CEQS
#define     ceqswhi   VWHI_CEQS
#define     ceqswhf   VWHF_CEQS
#define     ceqswwu   VWWU_CEQS
#define     ceqswwi   VWWI_CEQS
#define     ceqswwf   VWWF_CEQS

#define     ceqsdbu   VDBU_CEQS
#define     ceqsdbi   VDBI_CEQS
#define     ceqsdbc   VDBC_CEQS
#define     ceqsdhu   VDHU_CEQS
#define     ceqsdhi   VDHI_CEQS
#define     ceqsdhf   VDHF_CEQS
#define     ceqsdwu   VDWU_CEQS
#define     ceqsdwi   VDWI_CEQS
#define     ceqsdwf   VDWF_CEQS
#define     ceqsddu   VDDU_CEQS
#define     ceqsddi   VDDI_CEQS
#define     ceqsddf   VDDF_CEQS

#define     ceqsqbu   VQBU_CEQS
#define     ceqsqbi   VQBI_CEQS
#define     ceqsqbc   VQBC_CEQS
#define     ceqsqhu   VQHU_CEQS
#define     ceqsqhi   VQHI_CEQS
#define     ceqsqhf   VQHF_CEQS
#define     ceqsqwu   VQWU_CEQS
#define     ceqsqwi   VQWI_CEQS
#define     ceqsqwf   VQWF_CEQS
#define     ceqsqdu   VQDU_CEQS
#define     ceqsqdi   VQDI_CEQS
#define     ceqsqdf   VQDF_CEQS
#if _LEAVE_CEQS
}
#endif

#if _ENTER_CEQY
{
#endif
/*  Elementwise compare 'A = B' (boolean) */

#define     ceqy(...) (ceqy_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ceqy_funcof(A, ...)  \
FUNCOF(             \
    ceqy, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ceqyyu    BOOL_CEQY
#define     ceqybu   UINT8_CEQY
#define     ceqybi    INT8_CEQY
#define     ceqybc    CHAR_CEQY
#define     ceqyhu  UINT16_CEQY
#define     ceqyhi   INT16_CEQY
#define     ceqyhf   FLT16_CEQY
#define     ceqywu  UINT32_CEQY
#define     ceqywi   INT32_CEQY
#define     ceqywf     FLT_CEQY
#define     ceqydu  UINT64_CEQY
#define     ceqydi   INT64_CEQY
#define     ceqydf     DBL_CEQY
#if DWRD_NLONG == 2
#   define  ceqylu   ULONG_CEQY
#   define  ceqyli    LONG_CEQY
#elif QUAD_NLLONG == 2
#   define  ceqylu  ULLONG_CEQY
#   define  ceqyli   LLONG_CEQY
#else
#   define  ceqyqu  ULLONG_CEQY
#   define  ceqyqi   LLONG_CEQY
#   define  ceqyqf    LDBL_CEQY
#endif

#define     ceqywbu   VWBU_CEQY
#define     ceqywbi   VWBI_CEQY
#define     ceqywbc   VWBC_CEQY
#define     ceqywhu   VWHU_CEQY
#define     ceqywhi   VWHI_CEQY
#define     ceqywhf   VWHF_CEQY
#define     ceqywwu   VWWU_CEQY
#define     ceqywwi   VWWI_CEQY
#define     ceqywwf   VWWF_CEQY

#define     ceqydbu   VDBU_CEQY
#define     ceqydbi   VDBI_CEQY
#define     ceqydbc   VDBC_CEQY
#define     ceqydhu   VDHU_CEQY
#define     ceqydhi   VDHI_CEQY
#define     ceqydhf   VDHF_CEQY
#define     ceqydwu   VDWU_CEQY
#define     ceqydwi   VDWI_CEQY
#define     ceqydwf   VDWF_CEQY
#define     ceqyddu   VDDU_CEQY
#define     ceqyddi   VDDI_CEQY
#define     ceqyddf   VDDF_CEQY

#define     ceqyqbu   VQBU_CEQY
#define     ceqyqbi   VQBI_CEQY
#define     ceqyqbc   VQBC_CEQY
#define     ceqyqhu   VQHU_CEQY
#define     ceqyqhi   VQHI_CEQY
#define     ceqyqhf   VQHF_CEQY
#define     ceqyqwu   VQWU_CEQY
#define     ceqyqwi   VQWI_CEQY
#define     ceqyqwf   VQWF_CEQY
#define     ceqyqdu   VQDU_CEQY
#define     ceqyqdi   VQDI_CEQY
#define     ceqyqdf   VQDF_CEQY
#if _LEAVE_CEQY
}
#endif


#if _ENTER_CLTS
{
#endif
/*  Elementwise compare 'A < B' (saturated) */

#define     clts(...) (clts_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     clts_funcof(A, ...)  \
FUNCOF(             \
    clts, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cltsbu   UINT8_CLTS
#define     cltsbi    INT8_CLTS
#define     cltsbc    CHAR_CLTS
#define     cltshu  UINT16_CLTS
#define     cltshi   INT16_CLTS
#define     cltshf   FLT16_CLTS
#define     cltswu  UINT32_CLTS
#define     cltswi   INT32_CLTS
#define     cltswf     FLT_CLTS
#define     cltsdu  UINT64_CLTS
#define     cltsdi   INT64_CLTS
#define     cltsdf     DBL_CLTS
#if DWRD_NLONG == 2
#   define  cltslu   ULONG_CLTS
#   define  cltsli    LONG_CLTS
#elif QUAD_NLLONG == 2
#   define  cltslu  ULLONG_CLTS
#   define  cltsli   LLONG_CLTS
#else
#   define  cltsqu  ULLONG_CLTS
#   define  cltsqi   LLONG_CLTS
#   define  cltsqf    LDBL_CLTS
#endif

#define     cltswbu   VWBU_CLTS
#define     cltswbi   VWBI_CLTS
#define     cltswbc   VWBC_CLTS
#define     cltswhu   VWHU_CLTS
#define     cltswhi   VWHI_CLTS
#define     cltswhf   VWHF_CLTS
#define     cltswwu   VWWU_CLTS
#define     cltswwi   VWWI_CLTS
#define     cltswwf   VWWF_CLTS

#define     cltsdbu   VDBU_CLTS
#define     cltsdbi   VDBI_CLTS
#define     cltsdbc   VDBC_CLTS
#define     cltsdhu   VDHU_CLTS
#define     cltsdhi   VDHI_CLTS
#define     cltsdhf   VDHF_CLTS
#define     cltsdwu   VDWU_CLTS
#define     cltsdwi   VDWI_CLTS
#define     cltsdwf   VDWF_CLTS
#define     cltsddu   VDDU_CLTS
#define     cltsddi   VDDI_CLTS
#define     cltsddf   VDDF_CLTS

#define     cltsqbu   VQBU_CLTS
#define     cltsqbi   VQBI_CLTS
#define     cltsqbc   VQBC_CLTS
#define     cltsqhu   VQHU_CLTS
#define     cltsqhi   VQHI_CLTS
#define     cltsqhf   VQHF_CLTS
#define     cltsqwu   VQWU_CLTS
#define     cltsqwi   VQWI_CLTS
#define     cltsqwf   VQWF_CLTS
#define     cltsqdu   VQDU_CLTS
#define     cltsqdi   VQDI_CLTS
#define     cltsqdf   VQDF_CLTS
#if _LEAVE_CLTS
}
#endif

#if _ENTER_CLTY
{
#endif
/*  Elementwise compare 'A < B' (boolean) */

#define     clty(...) (clty_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     clty_funcof(A, ...)  \
FUNCOF(             \
    clty, (   A   ),\
    YDR,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cltyyu    BOOL_CLTY
#define     cltybu   UINT8_CLTY
#define     cltybi    INT8_CLTY
#define     cltybc    CHAR_CLTY
#define     cltyhu  UINT16_CLTY
#define     cltyhi   INT16_CLTY
#define     cltyhf   FLT16_CLTY
#define     cltywu  UINT32_CLTY
#define     cltywi   INT32_CLTY
#define     cltywf     FLT_CLTY
#define     cltydu  UINT64_CLTY
#define     cltydi   INT64_CLTY
#define     cltydf     DBL_CLTY
#if DWRD_NLONG == 2
#   define  cltylu   ULONG_CLTY
#   define  cltyli    LONG_CLTY
#elif QUAD_NLLONG == 2
#   define  cltylu  ULLONG_CLTY
#   define  cltyli   LLONG_CLTY
#else
#   define  cltyqu  ULLONG_CLTY
#   define  cltyqi   LLONG_CLTY
#   define  cltyqf    LDBL_CLTY
#endif

#define     cltywbu   VWBU_CLTY
#define     cltywbi   VWBI_CLTY
#define     cltywbc   VWBC_CLTY
#define     cltywhu   VWHU_CLTY
#define     cltywhi   VWHI_CLTY
#define     cltywhf   VWHF_CLTY
#define     cltywwu   VWWU_CLTY
#define     cltywwi   VWWI_CLTY
#define     cltywwf   VWWF_CLTY

#define     cltydbu   VDBU_CLTY
#define     cltydbi   VDBI_CLTY
#define     cltydbc   VDBC_CLTY
#define     cltydhu   VDHU_CLTY
#define     cltydhi   VDHI_CLTY
#define     cltydhf   VDHF_CLTY
#define     cltydwu   VDWU_CLTY
#define     cltydwi   VDWI_CLTY
#define     cltydwf   VDWF_CLTY
#define     cltyddu   VDDU_CLTY
#define     cltyddi   VDDI_CLTY
#define     cltyddf   VDDF_CLTY

#define     cltyqbu   VQBU_CLTY
#define     cltyqbi   VQBI_CLTY
#define     cltyqbc   VQBC_CLTY
#define     cltyqhu   VQHU_CLTY
#define     cltyqhi   VQHI_CLTY
#define     cltyqhf   VQHF_CLTY
#define     cltyqwu   VQWU_CLTY
#define     cltyqwi   VQWI_CLTY
#define     cltyqwf   VQWF_CLTY
#define     cltyqdu   VQDU_CLTY
#define     cltyqdi   VQDI_CLTY
#define     cltyqdf   VQDF_CLTY
#if _LEAVE_CLTY
}
#endif

#if _ENTER_CLES
{
#endif
/*  Elementwise compare 'A ≤ B' (saturated) */

#define     cles(...) (cles_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cles_funcof(A, ...)  \
FUNCOF(             \
    cles, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     clesbu   UINT8_CLES
#define     clesbi    INT8_CLES
#define     clesbc    CHAR_CLES
#define     cleshu  UINT16_CLES
#define     cleshi   INT16_CLES
#define     cleshf   FLT16_CLES
#define     cleswu  UINT32_CLES
#define     cleswi   INT32_CLES
#define     cleswf     FLT_CLES
#define     clesdu  UINT64_CLES
#define     clesdi   INT64_CLES
#define     clesdf     DBL_CLES
#if DWRD_NLONG == 2
#   define  cleslu   ULONG_CLES
#   define  clesli    LONG_CLES
#elif QUAD_NLLONG == 2
#   define  cleslu  ULLONG_CLES
#   define  clesli   LLONG_CLES
#else
#   define  clesqu  ULLONG_CLES
#   define  clesqi   LLONG_CLES
#   define  clesqf    LDBL_CLES
#endif

#define     cleswbu   VWBU_CLES
#define     cleswbi   VWBI_CLES
#define     cleswbc   VWBC_CLES
#define     cleswhu   VWHU_CLES
#define     cleswhi   VWHI_CLES
#define     cleswhf   VWHF_CLES
#define     cleswwu   VWWU_CLES
#define     cleswwi   VWWI_CLES
#define     cleswwf   VWWF_CLES

#define     clesdbu   VDBU_CLES
#define     clesdbi   VDBI_CLES
#define     clesdbc   VDBC_CLES
#define     clesdhu   VDHU_CLES
#define     clesdhi   VDHI_CLES
#define     clesdhf   VDHF_CLES
#define     clesdwu   VDWU_CLES
#define     clesdwi   VDWI_CLES
#define     clesdwf   VDWF_CLES
#define     clesddu   VDDU_CLES
#define     clesddi   VDDI_CLES
#define     clesddf   VDDF_CLES

#define     clesqbu   VQBU_CLES
#define     clesqbi   VQBI_CLES
#define     clesqbc   VQBC_CLES
#define     clesqhu   VQHU_CLES
#define     clesqhi   VQHI_CLES
#define     clesqhf   VQHF_CLES
#define     clesqwu   VQWU_CLES
#define     clesqwi   VQWI_CLES
#define     clesqwf   VQWF_CLES
#define     clesqdu   VQDU_CLES
#define     clesqdi   VQDI_CLES
#define     clesqdf   VQDF_CLES
#if _LEAVE_CLES
}
#endif

#if _ENTER_CLEY
{
#endif
/*  Elementwise compare 'A ≤ B' (boolean) */

#define     cley(...) (cley_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cley_funcof(A, ...)  \
FUNCOF(             \
    cley, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cleyyu    BOOL_CLEY
#define     cleybu   UINT8_CLEY
#define     cleybi    INT8_CLEY
#define     cleybc    CHAR_CLEY
#define     cleyhu  UINT16_CLEY
#define     cleyhi   INT16_CLEY
#define     cleyhf   FLT16_CLEY
#define     cleywu  UINT32_CLEY
#define     cleywi   INT32_CLEY
#define     cleywf     FLT_CLEY
#define     cleydu  UINT64_CLEY
#define     cleydi   INT64_CLEY
#define     cleydf     DBL_CLEY
#if DWRD_NLONG == 2
#   define  cleylu   ULONG_CLEY
#   define  cleyli    LONG_CLEY
#elif QUAD_NLLONG == 2
#   define  cleylu  ULLONG_CLEY
#   define  cleyli   LLONG_CLEY
#else
#   define  cleyqu  ULLONG_CLEY
#   define  cleyqi   LLONG_CLEY
#   define  cleyqf    LDBL_CLEY
#endif

#define     cleywbu   VWBU_CLEY
#define     cleywbi   VWBI_CLEY
#define     cleywbc   VWBC_CLEY
#define     cleywhu   VWHU_CLEY
#define     cleywhi   VWHI_CLEY
#define     cleywhf   VWHF_CLEY
#define     cleywwu   VWWU_CLEY
#define     cleywwi   VWWI_CLEY
#define     cleywwf   VWWF_CLEY

#define     cleydbu   VDBU_CLEY
#define     cleydbi   VDBI_CLEY
#define     cleydbc   VDBC_CLEY
#define     cleydhu   VDHU_CLEY
#define     cleydhi   VDHI_CLEY
#define     cleydhf   VDHF_CLEY
#define     cleydwu   VDWU_CLEY
#define     cleydwi   VDWI_CLEY
#define     cleydwf   VDWF_CLEY
#define     cleyddu   VDDU_CLEY
#define     cleyddi   VDDI_CLEY
#define     cleyddf   VDDF_CLEY

#define     cleyqbu   VQBU_CLEY
#define     cleyqbi   VQBI_CLEY
#define     cleyqbc   VQBC_CLEY
#define     cleyqhu   VQHU_CLEY
#define     cleyqhi   VQHI_CLEY
#define     cleyqhf   VQHF_CLEY
#define     cleyqwu   VQWU_CLEY
#define     cleyqwi   VQWI_CLEY
#define     cleyqwf   VQWF_CLEY
#define     cleyqdu   VQDU_CLEY
#define     cleyqdi   VQDI_CLEY
#define     cleyqdf   VQDF_CLEY
#if _LEAVE_CLEY
}
#endif

#if _ENTER_CGTS
{
#endif
/*  Elementwise compare 'A > B' (saturated) */

#define     cgts(...) (cgts_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cgts_funcof(A, ...)  \
FUNCOF(             \
    cgts, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cgtsbu   UINT8_CGTS
#define     cgtsbi    INT8_CGTS
#define     cgtsbc    CHAR_CGTS
#define     cgtshu  UINT16_CGTS
#define     cgtshi   INT16_CGTS
#define     cgtshf   FLT16_CGTS
#define     cgtswu  UINT32_CGTS
#define     cgtswi   INT32_CGTS
#define     cgtswf     FLT_CGTS
#define     cgtsdu  UINT64_CGTS
#define     cgtsdi   INT64_CGTS
#define     cgtsdf     DBL_CGTS
#if DWRD_NLONG == 2
#   define  cgtslu   ULONG_CGTS
#   define  cgtsli    LONG_CGTS
#elif QUAD_NLLONG == 2
#   define  cgtslu  ULLONG_CGTS
#   define  cgtsli   LLONG_CGTS
#else
#   define  cgtsqu  ULLONG_CGTS
#   define  cgtsqi   LLONG_CGTS
#   define  cgtsqf    LDBL_CGTS
#endif

#define     cgtswbu   VWBU_CGTS
#define     cgtswbi   VWBI_CGTS
#define     cgtswbc   VWBC_CGTS
#define     cgtswhu   VWHU_CGTS
#define     cgtswhi   VWHI_CGTS
#define     cgtswhf   VWHF_CGTS
#define     cgtswwu   VWWU_CGTS
#define     cgtswwi   VWWI_CGTS
#define     cgtswwf   VWWF_CGTS

#define     cgtsdbu   VDBU_CGTS
#define     cgtsdbi   VDBI_CGTS
#define     cgtsdbc   VDBC_CGTS
#define     cgtsdhu   VDHU_CGTS
#define     cgtsdhi   VDHI_CGTS
#define     cgtsdhf   VDHF_CGTS
#define     cgtsdwu   VDWU_CGTS
#define     cgtsdwi   VDWI_CGTS
#define     cgtsdwf   VDWF_CGTS
#define     cgtsddu   VDDU_CGTS
#define     cgtsddi   VDDI_CGTS
#define     cgtsddf   VDDF_CGTS

#define     cgtsqbu   VQBU_CGTS
#define     cgtsqbi   VQBI_CGTS
#define     cgtsqbc   VQBC_CGTS
#define     cgtsqhu   VQHU_CGTS
#define     cgtsqhi   VQHI_CGTS
#define     cgtsqhf   VQHF_CGTS
#define     cgtsqwu   VQWU_CGTS
#define     cgtsqwi   VQWI_CGTS
#define     cgtsqwf   VQWF_CGTS
#define     cgtsqdu   VQDU_CGTS
#define     cgtsqdi   VQDI_CGTS
#define     cgtsqdf   VQDF_CGTS
#if _LEAVE_CGTS
}
#endif

#if _ENTER_CGTY
{
#endif
/*  Elementwise compare 'A > B' (boolean) */

#define     cgty(...) (cgty_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cgty_funcof(A, ...)  \
FUNCOF(             \
    cgty, (   A   ),\
    YDR,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cgtyyu    BOOL_CGTY
#define     cgtybu   UINT8_CGTY
#define     cgtybi    INT8_CGTY
#define     cgtybc    CHAR_CGTY
#define     cgtyhu  UINT16_CGTY
#define     cgtyhi   INT16_CGTY
#define     cgtyhf   FLT16_CGTY
#define     cgtywu  UINT32_CGTY
#define     cgtywi   INT32_CGTY
#define     cgtywf     FLT_CGTY
#define     cgtydu  UINT64_CGTY
#define     cgtydi   INT64_CGTY
#define     cgtydf     DBL_CGTY
#if DWRD_NLONG == 2
#   define  cgtylu   ULONG_CGTY
#   define  cgtyli    LONG_CGTY
#elif QUAD_NLLONG == 2
#   define  cgtylu  ULLONG_CGTY
#   define  cgtyli   LLONG_CGTY
#else
#   define  cgtyqu  ULLONG_CGTY
#   define  cgtyqi   LLONG_CGTY
#   define  cgtyqf    LDBL_CGTY
#endif

#define     cgtywbu   VWBU_CGTY
#define     cgtywbi   VWBI_CGTY
#define     cgtywbc   VWBC_CGTY
#define     cgtywhu   VWHU_CGTY
#define     cgtywhi   VWHI_CGTY
#define     cgtywhf   VWHF_CGTY
#define     cgtywwu   VWWU_CGTY
#define     cgtywwi   VWWI_CGTY
#define     cgtywwf   VWWF_CGTY

#define     cgtydbu   VDBU_CGTY
#define     cgtydbi   VDBI_CGTY
#define     cgtydbc   VDBC_CGTY
#define     cgtydhu   VDHU_CGTY
#define     cgtydhi   VDHI_CGTY
#define     cgtydhf   VDHF_CGTY
#define     cgtydwu   VDWU_CGTY
#define     cgtydwi   VDWI_CGTY
#define     cgtydwf   VDWF_CGTY
#define     cgtyddu   VDDU_CGTY
#define     cgtyddi   VDDI_CGTY
#define     cgtyddf   VDDF_CGTY

#define     cgtyqbu   VQBU_CGTY
#define     cgtyqbi   VQBI_CGTY
#define     cgtyqbc   VQBC_CGTY
#define     cgtyqhu   VQHU_CGTY
#define     cgtyqhi   VQHI_CGTY
#define     cgtyqhf   VQHF_CGTY
#define     cgtyqwu   VQWU_CGTY
#define     cgtyqwi   VQWI_CGTY
#define     cgtyqwf   VQWF_CGTY
#define     cgtyqdu   VQDU_CGTY
#define     cgtyqdi   VQDI_CGTY
#define     cgtyqdf   VQDF_CGTY
#if _LEAVE_CGTY
}
#endif

#if _ENTER_CGES
{
#endif
/*  Elementwise compare 'A ≥ B' (saturated) */

#define     cges(...) (cges_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cges_funcof(A, ...)  \
FUNCOF(             \
    cges, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cgesbu   UINT8_CGES
#define     cgesbi    INT8_CGES
#define     cgesbc    CHAR_CGES
#define     cgeshu  UINT16_CGES
#define     cgeshi   INT16_CGES
#define     cgeshf   FLT16_CGES
#define     cgeswu  UINT32_CGES
#define     cgeswi   INT32_CGES
#define     cgeswf     FLT_CGES
#define     cgesdu  UINT64_CGES
#define     cgesdi   INT64_CGES
#define     cgesdf     DBL_CGES
#if DWRD_NLONG == 2
#   define  cgeslu   ULONG_CGES
#   define  cgesli    LONG_CGES
#elif QUAD_NLLONG == 2
#   define  cgeslu  ULLONG_CGES
#   define  cgesli   LLONG_CGES
#else
#   define  cgesqu  ULLONG_CGES
#   define  cgesqi   LLONG_CGES
#   define  cgesqf    LDBL_CGES
#endif

#define     cgeswbu   VWBU_CGES
#define     cgeswbi   VWBI_CGES
#define     cgeswbc   VWBC_CGES
#define     cgeswhu   VWHU_CGES
#define     cgeswhi   VWHI_CGES
#define     cgeswhf   VWHF_CGES
#define     cgeswwu   VWWU_CGES
#define     cgeswwi   VWWI_CGES
#define     cgeswwf   VWWF_CGES

#define     cgesdbu   VDBU_CGES
#define     cgesdbi   VDBI_CGES
#define     cgesdbc   VDBC_CGES
#define     cgesdhu   VDHU_CGES
#define     cgesdhi   VDHI_CGES
#define     cgesdhf   VDHF_CGES
#define     cgesdwu   VDWU_CGES
#define     cgesdwi   VDWI_CGES
#define     cgesdwf   VDWF_CGES
#define     cgesddu   VDDU_CGES
#define     cgesddi   VDDI_CGES
#define     cgesddf   VDDF_CGES

#define     cgesqbu   VQBU_CGES
#define     cgesqbi   VQBI_CGES
#define     cgesqbc   VQBC_CGES
#define     cgesqhu   VQHU_CGES
#define     cgesqhi   VQHI_CGES
#define     cgesqhf   VQHF_CGES
#define     cgesqwu   VQWU_CGES
#define     cgesqwi   VQWI_CGES
#define     cgesqwf   VQWF_CGES
#define     cgesqdu   VQDU_CGES
#define     cgesqdi   VQDI_CGES
#define     cgesqdf   VQDF_CGES
#if _LEAVE_CGES
}
#endif

#if _ENTER_CGEY
{
#endif
/*  Elementwise compare 'A ≥ B' (boolean) */

#define     cgey(...) (cgey_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cgey_funcof(A, ...)  \
FUNCOF(             \
    cgey, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cgeyyu    BOOL_CGEY
#define     cgeybu   UINT8_CGEY
#define     cgeybi    INT8_CGEY
#define     cgeybc    CHAR_CGEY
#define     cgeyhu  UINT16_CGEY
#define     cgeyhi   INT16_CGEY
#define     cgeyhf   FLT16_CGEY
#define     cgeywu  UINT32_CGEY
#define     cgeywi   INT32_CGEY
#define     cgeywf     FLT_CGEY
#define     cgeydu  UINT64_CGEY
#define     cgeydi   INT64_CGEY
#define     cgeydf     DBL_CGEY

#if DWRD_NLONG == 2
#   define  cgeylu   ULONG_CGEY
#   define  cgeyli    LONG_CGEY
#elif QUAD_NLLONG == 2
#   define  cgeylu  ULLONG_CGEY
#   define  cgeyli   LLONG_CGEY
#else
#   define  cgeyqu  ULLONG_CGEY
#   define  cgeyqi   LLONG_CGEY
#   define  cgeyqf    LDBL_CGEY
#endif

#define     cgeywbu   VWBU_CGEY
#define     cgeywbi   VWBI_CGEY
#define     cgeywbc   VWBC_CGEY
#define     cgeywhu   VWHU_CGEY
#define     cgeywhi   VWHI_CGEY
#define     cgeywhf   VWHF_CGEY
#define     cgeywwu   VWWU_CGEY
#define     cgeywwi   VWWI_CGEY
#define     cgeywwf   VWWF_CGEY

#define     cgeydbu   VDBU_CGEY
#define     cgeydbi   VDBI_CGEY
#define     cgeydbc   VDBC_CGEY
#define     cgeydhu   VDHU_CGEY
#define     cgeydhi   VDHI_CGEY
#define     cgeydhf   VDHF_CGEY
#define     cgeydwu   VDWU_CGEY
#define     cgeydwi   VDWI_CGEY
#define     cgeydwf   VDWF_CGEY
#define     cgeyddu   VDDU_CGEY
#define     cgeyddi   VDDI_CGEY
#define     cgeyddf   VDDF_CGEY

#define     cgeyqbu   VQBU_CGEY
#define     cgeyqbi   VQBI_CGEY
#define     cgeyqbc   VQBC_CGEY
#define     cgeyqhu   VQHU_CGEY
#define     cgeyqhi   VQHI_CGEY
#define     cgeyqhf   VQHF_CGEY
#define     cgeyqwu   VQWU_CGEY
#define     cgeyqwi   VQWI_CGEY
#define     cgeyqwf   VQWF_CGEY
#define     cgeyqdu   VQDU_CGEY
#define     cgeyqdi   VQDI_CGEY
#define     cgeyqdf   VQDF_CGEY
#if _LEAVE_CGEY
}
#endif

#if _ENTER_CNES
{
#endif
/*  Elementwise compare 'A ≠ B' (saturated) */

#define     cnes(...) (cnes_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cnes_funcof(A, ...)  \
FUNCOF(             \
    cnes, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cnesbu   UINT8_CNES
#define     cnesbi    INT8_CNES
#define     cnesbc    CHAR_CNES
#define     cneshu  UINT16_CNES
#define     cneshi   INT16_CNES
#define     cneshf   FLT16_CNES
#define     cneswu  UINT32_CNES
#define     cneswi   INT32_CNES
#define     cneswf     FLT_CNES
#define     cnesdu  UINT64_CNES
#define     cnesdi   INT64_CNES
#define     cnesdf     DBL_CNES
#if DWRD_NLONG == 2
#   define  cneslu   ULONG_CNES
#   define  cnesli    LONG_CNES
#elif QUAD_NLLONG == 2
#   define  cneslu  ULLONG_CNES
#   define  cnesli   LLONG_CNES
#else
#   define  cnesqu  ULLONG_CNES
#   define  cnesqi   LLONG_CNES
#   define  cnesqf    LDBL_CNES
#endif

#define     cneswbu   VWBU_CNES
#define     cneswbi   VWBI_CNES
#define     cneswbc   VWBC_CNES
#define     cneswhu   VWHU_CNES
#define     cneswhi   VWHI_CNES
#define     cneswhf   VWHF_CNES
#define     cneswwu   VWWU_CNES
#define     cneswwi   VWWI_CNES
#define     cneswwf   VWWF_CNES

#define     cnesdbu   VDBU_CNES
#define     cnesdbi   VDBI_CNES
#define     cnesdbc   VDBC_CNES
#define     cnesdhu   VDHU_CNES
#define     cnesdhi   VDHI_CNES
#define     cnesdhf   VDHF_CNES
#define     cnesdwu   VDWU_CNES
#define     cnesdwi   VDWI_CNES
#define     cnesdwf   VDWF_CNES
#define     cnesddu   VDDU_CNES
#define     cnesddi   VDDI_CNES
#define     cnesddf   VDDF_CNES

#define     cnesqbu   VQBU_CNES
#define     cnesqbi   VQBI_CNES
#define     cnesqbc   VQBC_CNES
#define     cnesqhu   VQHU_CNES
#define     cnesqhi   VQHI_CNES
#define     cnesqhf   VQHF_CNES
#define     cnesqwu   VQWU_CNES
#define     cnesqwi   VQWI_CNES
#define     cnesqwf   VQWF_CNES
#define     cnesqdu   VQDU_CNES
#define     cnesqdi   VQDI_CNES
#define     cnesqdf   VQDF_CNES
#if _LEAVE_CNES
}
#endif

#if _ENTER_CNEY
{
#endif
/*  Elementwise compare 'A ≠ B' (boolean) */

#define     cney(...) (cney_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cney_funcof(A, ...)  \
FUNCOF(             \
    cney, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cneyyu    BOOL_CNEY
#define     cneybu   UINT8_CNEY
#define     cneybi    INT8_CNEY
#define     cneybc    CHAR_CNEY
#define     cneyhu  UINT16_CNEY
#define     cneyhi   INT16_CNEY
#define     cneyhf   FLT16_CNEY
#define     cneywu  UINT32_CNEY
#define     cneywi   INT32_CNEY
#define     cneywf     FLT_CNEY
#define     cneydu  UINT64_CNEY
#define     cneydi   INT64_CNEY
#define     cneydf     DBL_CNEY
#if DWRD_NLONG == 2
#   define  cneylu   ULONG_CNEY
#   define  cneyli    LONG_CNEY
#elif QUAD_NLLONG == 2
#   define  cneylu  ULLONG_CNEY
#   define  cneyli   LLONG_CNEY
#else
#   define  cneyqu  ULLONG_CNEY
#   define  cneyqi   LLONG_CNEY
#   define  cneyqf    LDBL_CNEY
#endif

#define     cneywbu   VWBU_CNEY
#define     cneywbi   VWBI_CNEY
#define     cneywbc   VWBC_CNEY
#define     cneywhu   VWHU_CNEY
#define     cneywhi   VWHI_CNEY
#define     cneywhf   VWHF_CNEY
#define     cneywwu   VWWU_CNEY
#define     cneywwi   VWWI_CNEY
#define     cneywwf   VWWF_CNEY

#define     cneydbu   VDBU_CNEY
#define     cneydbi   VDBI_CNEY
#define     cneydbc   VDBC_CNEY
#define     cneydhu   VDHU_CNEY
#define     cneydhi   VDHI_CNEY
#define     cneydhf   VDHF_CNEY
#define     cneydwu   VDWU_CNEY
#define     cneydwi   VDWI_CNEY
#define     cneydwf   VDWF_CNEY
#define     cneyddu   VDDU_CNEY
#define     cneyddi   VDDI_CNEY
#define     cneyddf   VDDF_CNEY

#define     cneyqbu   VQBU_CNEY
#define     cneyqbi   VQBI_CNEY
#define     cneyqbc   VQBC_CNEY
#define     cneyqhu   VQHU_CNEY
#define     cneyqhi   VQHI_CNEY
#define     cneyqhf   VQHF_CNEY
#define     cneyqwu   VQWU_CNEY
#define     cneyqwi   VQWI_CNEY
#define     cneyqwf   VQWF_CNEY
#define     cneyqdu   VQDU_CNEY
#define     cneyqdi   VQDI_CNEY
#define     cneyqdf   VQDF_CNEY
#if _LEAVE_CNEY
}
#endif

#if _ENTER_CNBS
{
#endif
/*  Compare Not Between (saturated)

Test each element in the first operand for membership within
the range specified by the second (min) and third (max)
operands. If an element is NOT in the exclusive range, all
bits in the corresponding result element are set to 1,
otherwise 0.

The result is undefined if any element of any operand is NaN.

*/

#define     cnbs(...) (cnbs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cnbs_funcof(A, ...)  \
FUNCOF(             \
    cnbs, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cnbsbu   UINT8_CNBS
#define     cnbsbi    INT8_CNBS
#define     cnbsbc    CHAR_CNBS
#define     cnbshu  UINT16_CNBS
#define     cnbshi   INT16_CNBS
#define     cnbshf   FLT16_CNBS
#define     cnbswu  UINT32_CNBS
#define     cnbswi   INT32_CNBS
#define     cnbswf     FLT_CNBS
#define     cnbsdu  UINT64_CNBS
#define     cnbsdi   INT64_CNBS
#define     cnbsdf     DBL_CNBS
#if DWRD_NLONG == 2
#   define  cnbslu   ULONG_CNBS
#   define  cnbsli    LONG_CNBS
#elif QUAD_NLLONG == 2
#   define  cnbslu  ULLONG_CNBS
#   define  cnbsli   LLONG_CNBS
#else
#   define  cnbsqu  ULLONG_CNBS
#   define  cnbsqi   LLONG_CNBS
#   define  cnbsqf    LDBL_CNBS
#endif

#define     cnbswbu   VWBU_CNBS
#define     cnbswbi   VWBI_CNBS
#define     cnbswbc   VWBC_CNBS
#define     cnbswhu   VWHU_CNBS
#define     cnbswhi   VWHI_CNBS
#define     cnbswhf   VWHF_CNBS
#define     cnbswwu   VWWU_CNBS
#define     cnbswwi   VWWI_CNBS
#define     cnbswwf   VWWF_CNBS

#define     cnbsdbu   VDBU_CNBS
#define     cnbsdbi   VDBI_CNBS
#define     cnbsdbc   VDBC_CNBS
#define     cnbsdhu   VDHU_CNBS
#define     cnbsdhi   VDHI_CNBS
#define     cnbsdhf   VDHF_CNBS
#define     cnbsdwu   VDWU_CNBS
#define     cnbsdwi   VDWI_CNBS
#define     cnbsdwf   VDWF_CNBS
#define     cnbsddu   VDDU_CNBS
#define     cnbsddi   VDDI_CNBS
#define     cnbsddf   VDDF_CNBS

#define     cnbsqbu   VQBU_CNBS
#define     cnbsqbi   VQBI_CNBS
#define     cnbsqbc   VQBC_CNBS
#define     cnbsqhu   VQHU_CNBS
#define     cnbsqhi   VQHI_CNBS
#define     cnbsqhf   VQHF_CNBS
#define     cnbsqwu   VQWU_CNBS
#define     cnbsqwi   VQWI_CNBS
#define     cnbsqwf   VQWF_CNBS
#define     cnbsqdu   VQDU_CNBS
#define     cnbsqdi   VQDI_CNBS
#define     cnbsqdf   VQDF_CNBS
#if _LEAVE_CNBS
}
#endif

#if _ENTER_CNBY
{
#endif
/*  Compare Not Between (boolean)

Test each element in the first operand for membership within
the range specified by the second (min) and third (max)
operands. If an element is NOT in the exclusive range, the
corresponding result element is 1, otherwise 0.

The result is undefined if any element of any operand is NaN.

*/

#define     cnby(...) (cnby_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cnby_funcof(A, ...)  \
FUNCOF(             \
    cnby, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cnbybu   UINT8_CNBY
#define     cnbybi    INT8_CNBY
#define     cnbybc    CHAR_CNBY
#define     cnbyhu  UINT16_CNBY
#define     cnbyhi   INT16_CNBY
#define     cnbyhf   FLT16_CNBY
#define     cnbywu  UINT32_CNBY
#define     cnbywi   INT32_CNBY
#define     cnbywf     FLT_CNBY
#define     cnbydu  UINT64_CNBY
#define     cnbydi   INT64_CNBY
#define     cnbydf     DBL_CNBY

#if DWRD_NLONG == 2
#   define  cnbylu   ULONG_CNBY
#   define  cnbyli    LONG_CNBY
#elif QUAD_NLLONG == 2
#   define  cnbylu  ULLONG_CNBY
#   define  cnbyli   LLONG_CNBY
#else
#   define  cnbyqu  ULLONG_CNBY
#   define  cnbyqi   LLONG_CNBY
#   define  cnbyqf    LDBL_CNBY
#endif

#define     cnbywbu   VWBU_CNBY
#define     cnbywbi   VWBI_CNBY
#define     cnbywbc   VWBC_CNBY
#define     cnbywhu   VWHU_CNBY
#define     cnbywhi   VWHI_CNBY
#define     cnbywhf   VWHF_CNBY
#define     cnbywwu   VWWU_CNBY
#define     cnbywwi   VWWI_CNBY
#define     cnbywwf   VWWF_CNBY

#define     cnbydbu   VDBU_CNBY
#define     cnbydbi   VDBI_CNBY
#define     cnbydbc   VDBC_CNBY
#define     cnbydhu   VDHU_CNBY
#define     cnbydhi   VDHI_CNBY
#define     cnbydhf   VDHF_CNBY
#define     cnbydwu   VDWU_CNBY
#define     cnbydwi   VDWI_CNBY
#define     cnbydwf   VDWF_CNBY
#define     cnbyddu   VDDU_CNBY
#define     cnbyddi   VDDI_CNBY
#define     cnbyddf   VDDF_CNBY

#define     cnbyqbu   VQBU_CNBY
#define     cnbyqbi   VQBI_CNBY
#define     cnbyqbc   VQBC_CNBY
#define     cnbyqhu   VQHU_CNBY
#define     cnbyqhi   VQHI_CNBY
#define     cnbyqhf   VQHF_CNBY
#define     cnbyqwu   VQWU_CNBY
#define     cnbyqwi   VQWI_CNBY
#define     cnbyqwf   VQWF_CNBY
#define     cnbyqdu   VQDU_CNBY
#define     cnbyqdi   VQDI_CNBY
#define     cnbyqdf   VQDF_CNBY
#if _LEAVE_CNBY
}
#endif


#if _ENTER_CNT1
{
#endif
/*  Count the number of '1' digits in a value's binary
    representation. Commonly called "population count" or
    Hamming weight.
*/

#define     cnt1(...) (cnt1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cnt1_funcof(X, ...)  \
FUNCOF(             \
    cnt1, (   X   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cnt1yu    BOOL_CNT1
#define     cnt1bu   UINT8_CNT1
#define     cnt1bi    INT8_CNT1
#define     cnt1bc    CHAR_CNT1
#define     cnt1hu  UINT16_CNT1
#define     cnt1hi   INT16_CNT1
#define     cnt1wu  UINT32_CNT1
#define     cnt1wi   INT32_CNT1
#define     cnt1du  UINT64_CNT1
#define     cnt1di   INT64_CNT1
#if   DWRD_NLONG == 2
#   define  cnt1lu   ULONG_CNT1
#   define  cnt1li    LONG_CNT1
#elif QUAD_NLLONG == 2
#   define  cnt1lu  ULLONG_CNT1
#   define  cnt1li   LLONG_CNT1
#else
#   define  cnt1qu  ULLONG_CNT1
#   define  cnt1qi   LLONG_CNT1
#endif

#define     cnt1wbu   VWBU_CNT1
#define     cnt1wbi   VWBI_CNT1
#define     cnt1wbc   VWBC_CNT1
#define     cnt1whu   VWHU_CNT1
#define     cnt1whi   VWHI_CNT1
#define     cnt1wwu   VWWU_CNT1
#define     cnt1wwi   VWWI_CNT1

#define     cnt1dbu   VDBU_CNT1
#define     cnt1dbi   VDBI_CNT1
#define     cnt1dbc   VDBC_CNT1
#define     cnt1dhu   VDHU_CNT1
#define     cnt1dhi   VDHI_CNT1
#define     cnt1dwu   VDWU_CNT1
#define     cnt1dwi   VDWI_CNT1
#define     cnt1ddu   VDDU_CNT1
#define     cnt1ddi   VDDI_CNT1

#define     cnt1qbu   VQBU_CNT1
#define     cnt1qbi   VQBI_CNT1
#define     cnt1qbc   VQBC_CNT1
#define     cnt1qhu   VQHU_CNT1
#define     cnt1qhi   VQHI_CNT1
#define     cnt1qwu   VQWU_CNT1
#define     cnt1qwi   VQWI_CNT1
#define     cnt1qdu   VQDU_CNT1
#define     cnt1qdi   VQDI_CNT1
#if _LEAVE_CNT1
}
#endif

#if _ENTER_CNTS
{
#endif
/*  Count the number of times each element's MSB repeats.

Commonly called "count leading redundant sign bits"
*/

#define     cnts(...) (cnts_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cnts_funcof(X, ...)  \
FUNCOF(             \
    cnts, (   X   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cntsbu   UINT8_CNTS
#define     cntsbi    INT8_CNTS
#define     cntsbc    CHAR_CNTS
#define     cntshu  UINT16_CNTS
#define     cntshi   INT16_CNTS
#define     cntswu  UINT32_CNTS
#define     cntswi   INT32_CNTS
#define     cntsdu  UINT64_CNTS
#define     cntsdi   INT64_CNTS
#if   DWRD_NLONG == 2
#   define  cntslu   ULONG_CNTS
#   define  cntsli    LONG_CNTS
#elif QUAD_NLLONG == 2
#   define  cntslu  ULLONG_CNTS
#   define  cntsli   LLONG_CNTS
#else
#   define  cntsqu  ULLONG_CNTS
#   define  cntsqi   LLONG_CNTS
#endif

#define     cntswbu   VWBU_CNTS
#define     cntswbi   VWBI_CNTS
#define     cntswbc   VWBC_CNTS
#define     cntswhu   VWHU_CNTS
#define     cntswhi   VWHI_CNTS
#define     cntswwu   VWWU_CNTS
#define     cntswwi   VWWI_CNTS

#define     cntsdbu   VDBU_CNTS
#define     cntsdbi   VDBI_CNTS
#define     cntsdbc   VDBC_CNTS
#define     cntsdhu   VDHU_CNTS
#define     cntsdhi   VDHI_CNTS
#define     cntsdwu   VDWU_CNTS
#define     cntsdwi   VDWI_CNTS
#define     cntsddu   VDDU_CNTS
#define     cntsddi   VDDI_CNTS

#define     cntsqbu   VQBU_CNTS
#define     cntsqbi   VQBI_CNTS
#define     cntsqbc   VQBC_CNTS
#define     cntsqhu   VQHU_CNTS
#define     cntsqhi   VQHI_CNTS
#define     cntsqwu   VQWU_CNTS
#define     cntsqwi   VQWI_CNTS
#define     cntsqdu   VQDU_CNTS
#define     cntsqdi   VQDI_CNTS
#if _LEAVE_CNTS
}
#endif


#if _ENTER_CSZL
{
#endif
/*  Count Zequential Zeros (lo to hi) */

#define     cszl(...) (cszl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cszl_funcof(X, ...)  \
FUNCOF(             \
    cszl, (   X   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cszlyu    BOOL_CSZL
#define     cszlbu   UINT8_CSZL
#define     cszlbi    INT8_CSZL
#define     cszlbc    CHAR_CSZL
#define     cszlhu  UINT16_CSZL
#define     cszlhi   INT16_CSZL
#define     cszlwu  UINT32_CSZL
#define     cszlwi   INT32_CSZL
#define     cszldu  UINT64_CSZL
#define     cszldi   INT64_CSZL
#if   DWRD_NLONG == 2
#   define  cszllu   ULONG_CSZL
#   define  cszlli    LONG_CSZL
#elif QUAD_NLLONG == 2
#   define  cszllu  ULLONG_CSZL
#   define  cszlli   LLONG_CSZL
#else
#   define  cszlqu  ULLONG_CSZL
#   define  cszlqi   LLONG_CSZL
#endif

#define     cszlwbu   VWBU_CSZL
#define     cszlwbi   VWBI_CSZL
#define     cszlwbc   VWBC_CSZL
#define     cszlwhu   VWHU_CSZL
#define     cszlwhi   VWHI_CSZL
#define     cszlwwu   VWWU_CSZL
#define     cszlwwi   VWWI_CSZL

#define     cszldbu   VDBU_CSZL
#define     cszldbi   VDBI_CSZL
#define     cszldbc   VDBC_CSZL
#define     cszldhu   VDHU_CSZL
#define     cszldhi   VDHI_CSZL
#define     cszldwu   VDWU_CSZL
#define     cszldwi   VDWI_CSZL
#define     cszlddu   VDDU_CSZL
#define     cszlddi   VDDI_CSZL

#define     cszlqbu   VQBU_CSZL
#define     cszlqbi   VQBI_CSZL
#define     cszlqbc   VQBC_CSZL
#define     cszlqhu   VQHU_CSZL
#define     cszlqhi   VQHI_CSZL
#define     cszlqwu   VQWU_CSZL
#define     cszlqwi   VQWI_CSZL
#define     cszlqdu   VQDU_CSZL
#define     cszlqdi   VQDI_CSZL
#if _LEAVE_CSZL
}
#endif

#if _ENTER_CSZR
{
#endif
/*  Count Sequential Zeros (msb/hi to lsb/lo) */

#define     cszr(...) (cszr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cszr_funcof(X, ...)  \
FUNCOF(             \
    cszr, (   X   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cszryu    BOOL_CSZR
#define     cszrbu   UINT8_CSZR
#define     cszrbi    INT8_CSZR
#define     cszrbc    CHAR_CSZR
#define     cszrhu  UINT16_CSZR
#define     cszrhi   INT16_CSZR
#define     cszrwu  UINT32_CSZR
#define     cszrwi   INT32_CSZR
#define     cszrdu  UINT64_CSZR
#define     cszrdi   INT64_CSZR
#if   DWRD_NLONG == 2
#   define  cszrlu   ULONG_CSZR
#   define  cszrli    LONG_CSZR
#elif QUAD_NLLONG == 2
#   define  cszrlu  ULLONG_CSZR
#   define  cszrli   LLONG_CSZR
#else
#   define  cszrqu  ULLONG_CSZR
#   define  cszrqi   LLONG_CSZR
#endif

#define     cszrwbu   VWBU_CSZR
#define     cszrwbi   VWBI_CSZR
#define     cszrwbc   VWBC_CSZR
#define     cszrwhu   VWHU_CSZR
#define     cszrwhi   VWHI_CSZR
#define     cszrwwu   VWWU_CSZR
#define     cszrwwi   VWWI_CSZR

#define     cszrdbu   VDBU_CSZR
#define     cszrdbi   VDBI_CSZR
#define     cszrdbc   VDBC_CSZR
#define     cszrdhu   VDHU_CSZR
#define     cszrdhi   VDHI_CSZR
#define     cszrdwu   VDWU_CSZR
#define     cszrdwi   VDWI_CSZR
#define     cszrddu   VDDU_CSZR
#define     cszrddi   VDDI_CSZR

#define     cszrqbu   VQBU_CSZR
#define     cszrqbi   VQBI_CSZR
#define     cszrqbc   VQBC_CSZR
#define     cszrqhu   VQHU_CSZR
#define     cszrqhi   VQHI_CSZR
#define     cszrqwu   VQWU_CSZR
#define     cszrqwi   VQWI_CSZR
#define     cszrqdu   VQDU_CSZR
#define     cszrqdi   VQDI_CSZR
#if _LEAVE_CSZR
}
#endif


#if _ENTER_CVBU
{
#endif
/*  Convert a scalar to an unsigned 8 bit integer or a
    vector with at least four elements to a vector of
    unsigned 8 bit integers.
*/

#define     cvbu(...) (cvbu_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvbu_funcof(X, ...)  \
FUNCOF(             \
    cvbu, (   X   ),\
    YDR,  /* TGK */ \
    BR,   /* TGW */ \
    BHR,  /* TGD */ \
    BWR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvbuyu    BOOL_CVBU
#define     cvbubu   UINT8_CVBU
#define     cvbubi    INT8_CVBU
#define     cvbubc    CHAR_CVBU
#define     cvbuhu  UINT16_CVBU
#define     cvbuhi   INT16_CVBU
#define     cvbuhf   FLT16_CVBU
#define     cvbuwu  UINT32_CVBU
#define     cvbuwi   INT32_CVBU
#define     cvbuwf     FLT_CVBU
#define     cvbudu  UINT64_CVBU
#define     cvbudi   INT64_CVBU
#define     cvbudf     DBL_CVBU
#if   DWRD_NLONG == 2
#   define  cvbulu   ULONG_CVBU
#   define  cvbuli    LONG_CVBU
#elif QUAD_NLLONG == 2
#   define  cvbulu  ULLONG_CVBU
#   define  cvbuli   LLONG_CVBU
#else
#   define  cvbuqu  ULLONG_CVBU
#   define  cvbuqi   LLONG_CVBU
#   define  cvbuqf    LDBL_CVBU
#endif

#define     cvbuwbu   VWBU_CVBU
#define     cvbuwbi   VWBI_CVBU
#define     cvbuwbc   VWBC_CVBU

#define     cvbudbu   VDBU_CVBU
#define     cvbudbi   VDBI_CVBU
#define     cvbudbc   VDBC_CVBU
#define     cvbudhu   VDHU_CVBU
#define     cvbudhi   VDHI_CVBU
#define     cvbudhf   VDHF_CVBU

#define     cvbuqbu   VQBU_CVBU
#define     cvbuqbi   VQBI_CVBU
#define     cvbuqbc   VQBC_CVBU
#define     cvbuqhu   VQHU_CVBU
#define     cvbuqhi   VQHI_CVBU
#define     cvbuqhf   VQHF_CVBU
#define     cvbuqwu   VQWU_CVBU
#define     cvbuqwi   VQWI_CVBU
#define     cvbuqwf   VQWF_CVBU
#if _LEAVE_CVBU
}
#endif

#if _ENTER_CVBZ
{
#endif
/*  Convert a scalar to an unsigned 8 bit integer or a
    vector with at least four elements to a vector of
    unsigned 8 bit integers. The result is saturated.
*/

#define     cvbz(...) (cvbz_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvbz_funcof(X, ...)  \
FUNCOF(             \
    cvbz, (   X   ),\
    YDR,  /* TGK */ \
    BR,   /* TGW */ \
    BHR,  /* TGD */ \
    BWR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvbzyu    BOOL_CVBZ
#define     cvbzbu   UINT8_CVBZ
#define     cvbzbi    INT8_CVBZ
#define     cvbzbc    CHAR_CVBZ
#define     cvbzhu  UINT16_CVBZ
#define     cvbzhi   INT16_CVBZ
#define     cvbzhf   FLT16_CVBZ
#define     cvbzwu  UINT32_CVBZ
#define     cvbzwi   INT32_CVBZ
#define     cvbzwf     FLT_CVBZ
#define     cvbzdu  UINT64_CVBZ
#define     cvbzdi   INT64_CVBZ
#define     cvbzdf     DBL_CVBZ
#if   DWRD_NLONG == 2
#   define  cvbzlu   ULONG_CVBZ
#   define  cvbzli    LONG_CVBZ
#elif QUAD_NLLONG == 2
#   define  cvbzlu  ULLONG_CVBZ
#   define  cvbzli   LLONG_CVBZ
#else
#   define  cvbzqu  ULLONG_CVBZ
#   define  cvbzqi   LLONG_CVBZ
#   define  cvbzqf    LDBL_CVBZ
#endif

#define     cvbzwbu   VWBU_CVBZ
#define     cvbzwbi   VWBI_CVBZ
#define     cvbzwbc   VWBC_CVBZ

#define     cvbzdbu   VDBU_CVBZ
#define     cvbzdbi   VDBI_CVBZ
#define     cvbzdbc   VDBC_CVBZ
#define     cvbzdhu   VDHU_CVBZ
#define     cvbzdhi   VDHI_CVBZ
#define     cvbzdhf   VDHF_CVBZ

#define     cvbzqbu   VQBU_CVBZ
#define     cvbzqbi   VQBI_CVBZ
#define     cvbzqbc   VQBC_CVBZ
#define     cvbzqhu   VQHU_CVBZ
#define     cvbzqhi   VQHI_CVBZ
#define     cvbzqhf   VQHF_CVBZ
#define     cvbzqwu   VQWU_CVBZ
#define     cvbzqwi   VQWI_CVBZ
#define     cvbzqwf   VQWF_CVBZ
#if _LEAVE_CVBZ
}
#endif

#if _ENTER_CVBI
{
#endif
/*  Convert a scalar to an signed 8 bit integer or a
    vector with at least four elements to a vector of
    signed 8 bit integers.
*/

#define     cvbi(...) (cvbi_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvbi_funcof(X, ...)  \
FUNCOF(             \
    cvbi, (   X   ),\
    YDR,  /* TGK */ \
    BR,   /* TGW */ \
    BHR,  /* TGD */ \
    BWR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvbiyu    BOOL_CVBI
#define     cvbibu   UINT8_CVBI
#define     cvbibi    INT8_CVBI
#define     cvbibc    CHAR_CVBI
#define     cvbihu  UINT16_CVBI
#define     cvbihi   INT16_CVBI
#define     cvbihf   FLT16_CVBI
#define     cvbiwu  UINT32_CVBI
#define     cvbiwi   INT32_CVBI
#define     cvbiwf     FLT_CVBI
#define     cvbidu  UINT64_CVBI
#define     cvbidi   INT64_CVBI
#define     cvbidf     DBL_CVBI
#if   DWRD_NLONG == 2
#   define  cvbilu   ULONG_CVBI
#   define  cvbili    LONG_CVBI
#elif QUAD_NLLONG == 2
#   define  cvbilu  ULLONG_CVBI
#   define  cvbili   LLONG_CVBI
#else
#   define  cvbiqu  ULLONG_CVBI
#   define  cvbiqi   LLONG_CVBI
#   define  cvbiqf    LDBL_CVBI
#endif

#define     cvbiwbu   VWBU_CVBI
#define     cvbiwbi   VWBI_CVBI
#define     cvbiwbc   VWBC_CVBI

#define     cvbidbu   VDBU_CVBI
#define     cvbidbi   VDBI_CVBI
#define     cvbidbc   VDBC_CVBI
#define     cvbidhu   VDHU_CVBI
#define     cvbidhi   VDHI_CVBI
#define     cvbidhf   VDHF_CVBI

#define     cvbiqbu   VQBU_CVBI
#define     cvbiqbi   VQBI_CVBI
#define     cvbiqbc   VQBC_CVBI
#define     cvbiqhu   VQHU_CVBI
#define     cvbiqhi   VQHI_CVBI
#define     cvbiqhf   VQHF_CVBI
#define     cvbiqwu   VQWU_CVBI
#define     cvbiqwi   VQWI_CVBI
#define     cvbiqwf   VQWF_CVBI
#if _LEAVE_CVBI
}
#endif

#if _ENTER_CVBS
{
#endif
/*  Convert a scalar to an unsigned 8 bit integer or a
    vector with at least four elements to a vector of
    unsigned 8 bit integers. The result is saturated.
*/

#define     cvbs(...) (cvbs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvbs_funcof(X, ...)  \
FUNCOF(             \
    cvbs, (   X   ),\
    YDR,  /* TGK */ \
    BR,   /* TGW */ \
    BHR,  /* TGD */ \
    BWR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvbsyu    BOOL_CVBS
#define     cvbsbu   UINT8_CVBS
#define     cvbsbi    INT8_CVBS
#define     cvbsbc    CHAR_CVBS
#define     cvbshu  UINT16_CVBS
#define     cvbshi   INT16_CVBS
#define     cvbshf   FLT16_CVBS
#define     cvbswu  UINT32_CVBS
#define     cvbswi   INT32_CVBS
#define     cvbswf     FLT_CVBS
#define     cvbsdu  UINT64_CVBS
#define     cvbsdi   INT64_CVBS
#define     cvbsdf     DBL_CVBS
#if   DWRD_NLONG == 2
#   define  cvbslu   ULONG_CVBS
#   define  cvbsli    LONG_CVBS
#elif QUAD_NLLONG == 2
#   define  cvbslu  ULLONG_CVBS
#   define  cvbsli   LLONG_CVBS
#else
#   define  cvbsqu  ULLONG_CVBS
#   define  cvbsqi   LLONG_CVBS
#   define  cvbsqf    LDBL_CVBS
#endif

#define     cvbswbu   VWBU_CVBS
#define     cvbswbi   VWBI_CVBS
#define     cvbswbc   VWBC_CVBS

#define     cvbsdbu   VDBU_CVBS
#define     cvbsdbi   VDBI_CVBS
#define     cvbsdbc   VDBC_CVBS
#define     cvbsdhu   VDHU_CVBS
#define     cvbsdhi   VDHI_CVBS
#define     cvbsdhf   VDHF_CVBS

#define     cvbsqbu   VQBU_CVBS
#define     cvbsqbi   VQBI_CVBS
#define     cvbsqbc   VQBC_CVBS
#define     cvbsqhu   VQHU_CVBS
#define     cvbsqhi   VQHI_CVBS
#define     cvbsqhf   VQHF_CVBS
#define     cvbsqwu   VQWU_CVBS
#define     cvbsqwi   VQWI_CVBS
#define     cvbsqwf   VQWF_CVBS
#if _LEAVE_CVBS
}
#endif

#if _ENTER_CVBC
{
#endif
/*  Convert a scalar to an ASCII char or a vector with at
    least four elements to a vector of ASCII chars.
*/

#define     cvbc(...) (cvbc_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvbc_funcof(X, ...)  \
FUNCOF(             \
    cvbc, (   X   ),\
    YDR,  /* TGK */ \
    BR,   /* TGW */ \
    BHR,  /* TGD */ \
    BWR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvbcyu    BOOL_CVBC
#define     cvbcbu   UINT8_CVBC
#define     cvbcbi    INT8_CVBC
#define     cvbcbc    CHAR_CVBC
#define     cvbchu  UINT16_CVBC
#define     cvbchi   INT16_CVBC
#define     cvbchf   FLT16_CVBC
#define     cvbcwu  UINT32_CVBC
#define     cvbcwi   INT32_CVBC
#define     cvbcwf     FLT_CVBC
#define     cvbcdu  UINT64_CVBC
#define     cvbcdi   INT64_CVBC
#define     cvbcdf     DBL_CVBC
#if   DWRD_NLONG == 2
#   define  cvbclu   ULONG_CVBC
#   define  cvbcli    LONG_CVBC
#elif QUAD_NLLONG == 2
#   define  cvbclu  ULLONG_CVBC
#   define  cvbcli   LLONG_CVBC
#else
#   define  cvbcqu  ULLONG_CVBC
#   define  cvbcqi   LLONG_CVBC
#   define  cvbcqf    LDBL_CVBC
#endif

#define     cvbcwbu   VWBU_CVBC
#define     cvbcwbi   VWBI_CVBC
#define     cvbcwbc   VWBC_CVBC

#define     cvbcdbu   VDBU_CVBC
#define     cvbcdbi   VDBI_CVBC
#define     cvbcdbc   VDBC_CVBC
#define     cvbcdhu   VDHU_CVBC
#define     cvbcdhi   VDHI_CVBC
#define     cvbcdhf   VDHF_CVBC

#define     cvbcqbu   VQBU_CVBC
#define     cvbcqbi   VQBI_CVBC
#define     cvbcqbc   VQBC_CVBC
#define     cvbcqhu   VQHU_CVBC
#define     cvbcqhi   VQHI_CVBC
#define     cvbcqhf   VQHF_CVBC
#define     cvbcqwu   VQWU_CVBC
#define     cvbcqwi   VQWI_CVBC
#define     cvbcqwf   VQWF_CVBC
#if _LEAVE_CVBC
}
#endif



#if _ENTER_CVHU
{
#endif
/*  Convert a scalar to an unsigned 16 bit integer or a
    vector with at least two elements to a vector of
    unsigned 16 bit integers. The result is saturated.
*/

#define     cvhu(...) (cvhu_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvhu_funcof(X, ...)  \
FUNCOF(             \
    cvhu, (   X   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvhuyu    BOOL_CVHU
#define     cvhubu   UINT8_CVHU
#define     cvhubi    INT8_CVHU
#define     cvhubc    CHAR_CVHU
#define     cvhuhu  UINT16_CVHU
#define     cvhuhi   INT16_CVHU
#define     cvhuhf   FLT16_CVHU
#define     cvhuwu  UINT32_CVHU
#define     cvhuwi   INT32_CVHU
#define     cvhuwf     FLT_CVHU
#define     cvhudu  UINT64_CVHU
#define     cvhudi   INT64_CVHU
#define     cvhudf     DBL_CVHU
#if   DWRD_NLONG == 2
#   define  cvhulu   ULONG_CVHU
#   define  cvhuli    LONG_CVHU
#elif QUAD_NLLONG == 2
#   define  cvhulu  ULLONG_CVHU
#   define  cvhuli   LLONG_CVHU
#else
#   define  cvhuqu  ULLONG_CVHU
#   define  cvhuqi   LLONG_CVHU
#   define  cvhuqf    LDBL_CVHU
#endif

#define     cvhuwbu   VWBU_CVHU
#define     cvhuwbi   VWBI_CVHU
#define     cvhuwbc   VWBC_CVHU
#define     cvhuwhu   VWHU_CVHU
#define     cvhuwhi   VWHI_CVHU
#define     cvhuwhf   VWHF_CVHU

#define     cvhudbu   VDBU_CVHU
#define     cvhudbi   VDBI_CVHU
#define     cvhudbc   VDBC_CVHU
#define     cvhudhu   VDHU_CVHU
#define     cvhudhi   VDHI_CVHU
#define     cvhudhf   VDHF_CVHU
#define     cvhudwu   VDWU_CVHU
#define     cvhudwi   VDWI_CVHU
#define     cvhudwf   VDWF_CVHU

#define     cvhuqhu   VQHU_CVHU
#define     cvhuqhi   VQHI_CVHU
#define     cvhuqhf   VQHF_CVHU
#define     cvhuqwu   VQWU_CVHU
#define     cvhuqwi   VQWI_CVHU
#define     cvhuqwf   VQWF_CVHU
#define     cvhuqdu   VQDU_CVHU
#define     cvhuqdi   VQDI_CVHU
#define     cvhuqdf   VQDF_CVHU
#if _LEAVE_CVHU
}
#endif

#if _ENTER_CVHZ
{
#endif
/*  Convert a scalar to an unsigned 16 bit integer or a
    vector with at least four elements to a vector of
    unsigned 16 bit integers.
*/

#define     cvhz(...) (cvhz_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvhz_funcof(X, ...)  \
FUNCOF(             \
    cvhz, (   X   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvhzyu    BOOL_CVHZ
#define     cvhzbu   UINT8_CVHZ
#define     cvhzbi    INT8_CVHZ
#define     cvhzbc    CHAR_CVHZ
#define     cvhzhu  UINT16_CVHZ
#define     cvhzhi   INT16_CVHZ
#define     cvhzhf   FLT16_CVHZ
#define     cvhzwu  UINT32_CVHZ
#define     cvhzwi   INT32_CVHZ
#define     cvhzwf     FLT_CVHZ
#define     cvhzdu  UINT64_CVHZ
#define     cvhzdi   INT64_CVHZ
#define     cvhzdf     DBL_CVHZ
#if   DWRD_NLONG == 2
#   define  cvhzlu   ULONG_CVHZ
#   define  cvhzli    LONG_CVHZ
#elif QUAD_NLLONG == 2
#   define  cvhzlu  ULLONG_CVHZ
#   define  cvhzli   LLONG_CVHZ
#else
#   define  cvhzqu  ULLONG_CVHZ
#   define  cvhzqi   LLONG_CVHZ
#   define  cvhzqf    LDBL_CVHZ
#endif

#define     cvhzwbu   VWBU_CVHZ
#define     cvhzwbi   VWBI_CVHZ
#define     cvhzwbc   VWBC_CVHZ
#define     cvhzwhu   VWHU_CVHZ
#define     cvhzwhi   VWHI_CVHZ
#define     cvhzwhf   VWHF_CVHZ

#define     cvhzdbu   VDBU_CVHZ
#define     cvhzdbi   VDBI_CVHZ
#define     cvhzdbc   VDBC_CVHZ
#define     cvhzdhu   VDHU_CVHZ
#define     cvhzdhi   VDHI_CVHZ
#define     cvhzdhf   VDHF_CVHZ
#define     cvhzdwu   VDWU_CVHZ
#define     cvhzdwi   VDWI_CVHZ
#define     cvhzdwf   VDWF_CVHZ

#define     cvhzqhu   VQHU_CVHZ
#define     cvhzqhi   VQHI_CVHZ
#define     cvhzqhf   VQHF_CVHZ
#define     cvhzqwu   VQWU_CVHZ
#define     cvhzqwi   VQWI_CVHZ
#define     cvhzqwf   VQWF_CVHZ
#define     cvhzqdu   VQDU_CVHZ
#define     cvhzqdi   VQDI_CVHZ
#define     cvhzqdf   VQDF_CVHZ
#if _LEAVE_CVHZ
}
#endif

#if _ENTER_CVHI
{
#endif
/*  ConVert Halfword (truncated int16_t)
*/

#define     cvhi(...) (cvhi_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvhi_funcof(X, ...)  \
FUNCOF(             \
    cvhi, (   X   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvhiyu    BOOL_CVHI
#define     cvhibu   UINT8_CVHI
#define     cvhibi    INT8_CVHI
#define     cvhibc    CHAR_CVHI
#define     cvhihu  UINT16_CVHI
#define     cvhihi   INT16_CVHI
#define     cvhihf   FLT16_CVHI
#define     cvhiwu  UINT32_CVHI
#define     cvhiwi   INT32_CVHI
#define     cvhiwf     FLT_CVHI
#define     cvhidu  UINT64_CVHI
#define     cvhidi   INT64_CVHI
#define     cvhidf     DBL_CVHI
#if   DWRD_NLONG == 2
#   define  cvhilu   ULONG_CVHI
#   define  cvhili    LONG_CVHI
#elif QUAD_NLLONG == 2
#   define  cvhilu  ULLONG_CVHI
#   define  cvhili   LLONG_CVHI
#else
#   define  cvhiqu  ULLONG_CVHI
#   define  cvhiqi   LLONG_CVHI
#   define  cvhiqf    LDBL_CVHI
#endif

#define     cvhiwbu   VWBU_CVHI
#define     cvhiwbi   VWBI_CVHI
#define     cvhiwbc   VWBC_CVHI
#define     cvhiwhu   VWHU_CVHI
#define     cvhiwhi   VWHI_CVHI
#define     cvhiwhf   VWHF_CVHI

#define     cvhidbu   VDBU_CVHI
#define     cvhidbi   VDBI_CVHI
#define     cvhidbc   VDBC_CVHI
#define     cvhidhu   VDHU_CVHI
#define     cvhidhi   VDHI_CVHI
#define     cvhidhf   VDHF_CVHI
#define     cvhidwu   VDWU_CVHI
#define     cvhidwi   VDWI_CVHI
#define     cvhidwf   VDWF_CVHI

#define     cvhiqbu   VQBU_CVHI
#define     cvhiqbi   VQBU_CVHI
#define     cvhiqbc   VQBU_CVHI
#define     cvhiqhu   VQHU_CVHI
#define     cvhiqhi   VQHI_CVHI
#define     cvhiqhf   VQHF_CVHI
#define     cvhiqwu   VQWU_CVHI
#define     cvhiqwi   VQWI_CVHI
#define     cvhiqwf   VQWF_CVHI
#define     cvhiqdu   VQDU_CVHI
#define     cvhiqdi   VQDI_CVHI
#define     cvhiqdf   VQDF_CVHI
#if _LEAVE_CVHI
}
#endif

#if _ENTER_CVHS
{
#endif
/*  ConVert Halfword (saturated int16_t)
*/

#define     cvhs(...) (cvhs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvhs_funcof(X, ...)  \
FUNCOF(             \
    cvhs, (   X   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvhsyu    BOOL_CVHS
#define     cvhsbu   UINT8_CVHS
#define     cvhsbi    INT8_CVHS
#define     cvhsbc    CHAR_CVHS
#define     cvhshu  UINT16_CVHS
#define     cvhshi   INT16_CVHS
#define     cvhshf   FLT16_CVHS
#define     cvhswu  UINT32_CVHS
#define     cvhswi   INT32_CVHS
#define     cvhswf     FLT_CVHS
#define     cvhsdu  UINT64_CVHS
#define     cvhsdi   INT64_CVHS
#define     cvhsdf     DBL_CVHS
#if   DWRD_NLONG == 2
#   define  cvhslu   ULONG_CVHS
#   define  cvhsli    LONG_CVHS
#elif QUAD_NLLONG == 2
#   define  cvhslu  ULLONG_CVHS
#   define  cvhsli   LLONG_CVHS
#else
#   define  cvhsqu  ULLONG_CVHS
#   define  cvhsqi   LLONG_CVHS
#   define  cvhsqf    LDBL_CVHS
#endif

#define     cvhswbu   VWBU_CVHS
#define     cvhswbi   VWBI_CVHS
#define     cvhswbc   VWBC_CVHS
#define     cvhswhu   VWHU_CVHS
#define     cvhswhi   VWHI_CVHS
#define     cvhswhf   VWHF_CVHS

#define     cvhsdbu   VDBU_CVHS
#define     cvhsdbi   VDBI_CVHS
#define     cvhsdbc   VDBC_CVHS
#define     cvhsdhu   VDHU_CVHS
#define     cvhsdhi   VDHI_CVHS
#define     cvhsdhf   VDHF_CVHS
#define     cvhsdwu   VDWU_CVHS
#define     cvhsdwi   VDWI_CVHS
#define     cvhsdwf   VDWF_CVHS

#define     cvhsqhu   VQHU_CVHS
#define     cvhsqhi   VQHI_CVHS
#define     cvhsqhf   VQHF_CVHS
#define     cvhsqwu   VQWU_CVHS
#define     cvhsqwi   VQWI_CVHS
#define     cvhsqwf   VQWF_CVHS
#define     cvhsqdu   VQDU_CVHS
#define     cvhsqdi   VQDI_CVHS
#define     cvhsqdf   VQDF_CVHS
#if _LEAVE_CVHS
}
#endif

#if _ENTER_CVHF
{
#endif
/*  ConVert Halfword (flt16_t)
*/

#define     cvhf(...) (cvhf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvhf_funcof(X, ...)  \
FUNCOF(             \
    cvhf, (   X   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvhfyu    BOOL_CVHF
#define     cvhfbu   UINT8_CVHF
#define     cvhfbi    INT8_CVHF
#define     cvhfbc    CHAR_CVHF
#define     cvhfhu  UINT16_CVHF
#define     cvhfhi   INT16_CVHF
#define     cvhfhf   FLT16_CVHF
#define     cvhfwu  UINT32_CVHF
#define     cvhfwi   INT32_CVHF
#define     cvhfwf     FLT_CVHF
#define     cvhfdu  UINT64_CVHF
#define     cvhfdi   INT64_CVHF
#define     cvhfdf     DBL_CVHF
#if   DWRD_NLONG == 2
#   define  cvhflu   ULONG_CVHF
#   define  cvhfli    LONG_CVHF
#elif QUAD_NLLONG == 2
#   define  cvhflu  ULLONG_CVHF
#   define  cvhfli   LLONG_CVHF
#else
#   define  cvhfqu  ULLONG_CVHF
#   define  cvhfqi   LLONG_CVHF
#   define  cvhfqf    LDBL_CVHF
#endif

#define     cvhfwbu   VWBU_CVHF
#define     cvhfwbi   VWBI_CVHF
#define     cvhfwbc   VWBC_CVHF
#define     cvhfwhu   VWHU_CVHF
#define     cvhfwhi   VWHI_CVHF
#define     cvhfwhf   VWHF_CVHF

#define     cvhfdbu   VDBU_CVHF
#define     cvhfdbi   VDBI_CVHF
#define     cvhfdbc   VDBC_CVHF
#define     cvhfdhu   VDHU_CVHF
#define     cvhfdhi   VDHI_CVHF
#define     cvhfdhf   VDHF_CVHF
#define     cvhfdwu   VDWU_CVHF
#define     cvhfdwi   VDWI_CVHF
#define     cvhfdwf   VDWF_CVHF

#define     cvhfqbu   VQBU_CVHF
#define     cvhfqbi   VQBU_CVHF
#define     cvhfqbc   VQBU_CVHF
#define     cvhfqhu   VQHU_CVHF
#define     cvhfqhi   VQHI_CVHF
#define     cvhfqhf   VQHF_CVHF
#define     cvhfqwu   VQWU_CVHF
#define     cvhfqwi   VQWI_CVHF
#define     cvhfqwf   VQWF_CVHF
#define     cvhfqdu   VQDU_CVHF
#define     cvhfqdi   VQDI_CVHF
#define     cvhfqdf   VQDF_CVHF
#if _LEAVE_CVHF
}
#endif


#if _ENTER_CVWU
{
#endif
/*  ConVert Word (truncated uint32_t)
*/

#define     cvwu(...) (cvwu_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvwu_funcof(X, ...)  \
FUNCOF(             \
    cvwu, (   X   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvwuyu    BOOL_CVWU
#define     cvwubu   UINT8_CVWU
#define     cvwubi    INT8_CVWU
#define     cvwubc    CHAR_CVWU
#define     cvwuhu  UINT16_CVWU
#define     cvwuhi   INT16_CVWU
#define     cvwuhf   FLT16_CVWU
#define     cvwuwu  UINT32_CVWU
#define     cvwuwi   INT32_CVWU
#define     cvwuwf     FLT_CVWU
#define     cvwudu  UINT64_CVWU
#define     cvwudi   INT64_CVWU
#define     cvwudf     DBL_CVWU
#if   DWRD_NLONG == 2
#   define  cvwulu   ULONG_CVWU
#   define  cvwuli    LONG_CVWU
#elif QUAD_NLLONG == 2
#   define  cvwulu  ULLONG_CVWU
#   define  cvwuli   LLONG_CVWU
#else
#   define  cvwuqu  ULLONG_CVWU
#   define  cvwuqi   LLONG_CVWU
#   define  cvwuqf    LDBL_CVWU
#endif

#define     cvwuwbu   VWBU_CVWU
#define     cvwuwbi   VWBI_CVWU
#define     cvwuwbc   VWBC_CVWU
#define     cvwuwhu   VWHU_CVWU
#define     cvwuwhi   VWHI_CVWU
#define     cvwuwhf   VWHF_CVWU
#define     cvwuwwu   VWWU_CVWU
#define     cvwuwwi   VWWI_CVWU
#define     cvwuwwf   VWWF_CVWU

#define     cvwudhu   VDHU_CVWU
#define     cvwudhi   VDHI_CVWU
#define     cvwudhf   VDHF_CVWU
#define     cvwudwu   VDWU_CVWU
#define     cvwudwi   VDWI_CVWU
#define     cvwudwf   VDWF_CVWU
#define     cvwuddu   VDDU_CVWU
#define     cvwuddi   VDDI_CVWU
#define     cvwuddf   VDDF_CVWU

#define     cvwuqwu   VQWU_CVWU
#define     cvwuqwi   VQWI_CVWU
#define     cvwuqwf   VQWF_CVWU
#define     cvwuqdu   VQDU_CVWU
#define     cvwuqdi   VQDI_CVWU
#define     cvwuqdf   VQDF_CVWU
#if _LEAVE_CVWU
}
#endif

#if _ENTER_CVWZ
{
#endif
/*  ConVert Word (saturated uint32_t)
*/

#define     cvwz(...) (cvwz_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvwz_funcof(X, ...)  \
FUNCOF(             \
    cvwz, (   X   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvwzyu    BOOL_CVWZ
#define     cvwzbu   UINT8_CVWZ
#define     cvwzbi    INT8_CVWZ
#define     cvwzbc    CHAR_CVWZ
#define     cvwzhu  UINT16_CVWZ
#define     cvwzhi   INT16_CVWZ
#define     cvwzhf   FLT16_CVWZ
#define     cvwzwu  UINT32_CVWZ
#define     cvwzwi   INT32_CVWZ
#define     cvwzwf     FLT_CVWZ
#define     cvwzdu  UINT64_CVWZ
#define     cvwzdi   INT64_CVWZ
#define     cvwzdf     DBL_CVWZ
#if   DWRD_NLONG == 2
#   define  cvwzlu   ULONG_CVWZ
#   define  cvwzli    LONG_CVWZ
#elif QUAD_NLLONG == 2
#   define  cvwzlu  ULLONG_CVWZ
#   define  cvwzli   LLONG_CVWZ
#else
#   define  cvwzqu  ULLONG_CVWZ
#   define  cvwzqi   LLONG_CVWZ
#   define  cvwzqf    LDBL_CVWZ
#endif

#define     cvwzwbu   VWBU_CVWZ
#define     cvwzwbi   VWBI_CVWZ
#define     cvwzwbc   VWBC_CVWZ
#define     cvwzwhu   VWHU_CVWZ
#define     cvwzwhi   VWHI_CVWZ
#define     cvwzwhf   VWHF_CVWZ
#define     cvwzwwu   VWWU_CVWZ
#define     cvwzwwi   VWWI_CVWZ
#define     cvwzwwf   VWWF_CVWZ

#define     cvwzdhu   VDHU_CVWZ
#define     cvwzdhi   VDHI_CVWZ
#define     cvwzdhf   VDHF_CVWZ
#define     cvwzdwu   VDWU_CVWZ
#define     cvwzdwi   VDWI_CVWZ
#define     cvwzdwf   VDWF_CVWZ
#define     cvwzddu   VDDU_CVWZ
#define     cvwzddi   VDDI_CVWZ
#define     cvwzddf   VDDF_CVWZ

#define     cvwzqwu   VQWU_CVWZ
#define     cvwzqwi   VQWI_CVWZ
#define     cvwzqwf   VQWF_CVWZ
#define     cvwzqdu   VQDU_CVWZ
#define     cvwzqdi   VQDI_CVWZ
#define     cvwzqdf   VQDF_CVWZ
#if _LEAVE_CVWZ
}
#endif

#if _ENTER_CVWI
{
#endif
/*  Convert each element to an unsigned 32 bit integer.
The result is saturated.
*/

#define     cvwi(...) (cvwi_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvwi_funcof(X, ...)  \
FUNCOF(             \
    cvwi, (   X   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvwiyu    BOOL_CVWI
#define     cvwibu   UINT8_CVWI
#define     cvwibi    INT8_CVWI
#define     cvwibc    CHAR_CVWI
#define     cvwihu  UINT16_CVWI
#define     cvwihi   INT16_CVWI
#define     cvwihf   FLT16_CVWI
#define     cvwiwu  UINT32_CVWI
#define     cvwiwi   INT32_CVWI
#define     cvwiwf     FLT_CVWI
#define     cvwidu  UINT64_CVWI
#define     cvwidi   INT64_CVWI
#define     cvwidf     DBL_CVWI
#if   DWRD_NLONG == 2
#   define  cvwilu   ULONG_CVWI
#   define  cvwili    LONG_CVWI
#elif QUAD_NLLONG == 2
#   define  cvwilu  ULLONG_CVWI
#   define  cvwili   LLONG_CVWI
#else
#   define  cvwiqu  ULLONG_CVWI
#   define  cvwiqi   LLONG_CVWI
#   define  cvwiqf    LDBL_CVWI
#endif

#define     cvwiwbu   VWBU_CVWI
#define     cvwiwbi   VWBI_CVWI
#define     cvwiwbc   VWBC_CVWI
#define     cvwiwhu   VWHU_CVWI
#define     cvwiwhi   VWHI_CVWI
#define     cvwiwhf   VWHF_CVWI
#define     cvwiwwu   VWWU_CVWI
#define     cvwiwwi   VWWI_CVWI
#define     cvwiwwf   VWWF_CVWI

#define     cvwidhu   VDHU_CVWI
#define     cvwidhi   VDHI_CVWI
#define     cvwidhf   VDHF_CVWI
#define     cvwidwu   VDWU_CVWI
#define     cvwidwi   VDWI_CVWI
#define     cvwidwf   VDWF_CVWI
#define     cvwiddu   VDDU_CVWI
#define     cvwiddi   VDDI_CVWI
#define     cvwiddf   VDDF_CVWI

#define     cvwiqwu   VQWU_CVWI
#define     cvwiqwi   VQWI_CVWI
#define     cvwiqwf   VQWF_CVWI
#define     cvwiqdu   VQDU_CVWI
#define     cvwiqdi   VQDI_CVWI
#define     cvwiqdf   VQDF_CVWI
#if _LEAVE_CVWI
}
#endif

#if _ENTER_CVWS
{
#endif
/*  Convert each element to an signed 32 bit integer. The
    result is saturated.
*/

#define     cvws(...) (cvws_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvws_funcof(X, ...)  \
FUNCOF(             \
    cvws, (   X   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvwsyu    BOOL_CVWS
#define     cvwsbu   UINT8_CVWS
#define     cvwsbi    INT8_CVWS
#define     cvwsbc    CHAR_CVWS
#define     cvwshu  UINT16_CVWS
#define     cvwshi   INT16_CVWS
#define     cvwshf   FLT16_CVWS
#define     cvwswu  UINT32_CVWS
#define     cvwswi   INT32_CVWS
#define     cvwswf     FLT_CVWS
#define     cvwsdu  UINT64_CVWS
#define     cvwsdi   INT64_CVWS
#define     cvwsdf     DBL_CVWS
#if   DWRD_NLONG == 2
#   define  cvwslu   ULONG_CVWS
#   define  cvwsli    LONG_CVWS
#elif QUAD_NLLONG == 2
#   define  cvwslu  ULLONG_CVWS
#   define  cvwsli   LLONG_CVWS
#else
#   define  cvwsqu  ULLONG_CVWS
#   define  cvwsqi   LLONG_CVWS
#   define  cvwsqf    LDBL_CVWS
#endif

#define     cvwswbu   VWBU_CVWS
#define     cvwswbi   VWBI_CVWS
#define     cvwswbc   VWBC_CVWS
#define     cvwswhu   VWHU_CVWS
#define     cvwswhi   VWHI_CVWS
#define     cvwswhf   VWHF_CVWS
#define     cvwswwu   VWWU_CVWS
#define     cvwswwi   VWWI_CVWS
#define     cvwswwf   VWWF_CVWS

#define     cvwsdhu   VDHU_CVWS
#define     cvwsdhi   VDHI_CVWS
#define     cvwsdhf   VDHF_CVWS
#define     cvwsdwu   VDWU_CVWS
#define     cvwsdwi   VDWI_CVWS
#define     cvwsdwf   VDWF_CVWS
#define     cvwsddu   VDDU_CVWS
#define     cvwsddi   VDDI_CVWS
#define     cvwsddf   VDDF_CVWS

#define     cvwsqwu   VQWU_CVWS
#define     cvwsqwi   VQWI_CVWS
#define     cvwsqwf   VQWF_CVWS
#define     cvwsqdu   VQDU_CVWS
#define     cvwsqdi   VQDI_CVWS
#define     cvwsqdf   VQDF_CVWS
#if _LEAVE_CVWS
}
#endif

#if _ENTER_CVWF
{
#endif
/*  Elementwise convert to IEEE 764 32-bit float

    If an element cannot be converted exactly, the
    rounding direction is implementation defined and a
    floating point exception may be raised.

    If any element cannot be converted, the entire result
    is undefined and the implementation may raise a
    floating point exception.
*/

#define     cvwf(...) (cvwf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvwf_funcof(X, ...)  \
FUNCOF(             \
    cvwf, (   X   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvwfyu    BOOL_CVWF
#define     cvwfbu   UINT8_CVWF
#define     cvwfbi    INT8_CVWF
#define     cvwfbc    CHAR_CVWF
#define     cvwfhu  UINT16_CVWF
#define     cvwfhi   INT16_CVWF
#define     cvwfhf   FLT16_CVWF
#define     cvwfwu  UINT32_CVWF
#define     cvwfwi   INT32_CVWF
#define     cvwfwf     FLT_CVWF
#define     cvwfdu  UINT64_CVWF
#define     cvwfdi   INT64_CVWF
#define     cvwfdf     DBL_CVWF
#if   DWRD_NLONG == 2
#   define  cvwflu   ULONG_CVWF
#   define  cvwfli    LONG_CVWF
#elif QUAD_NLLONG == 2
#   define  cvwflu  ULLONG_CVWF
#   define  cvwfli   LLONG_CVWF
#else
#   define  cvwfqu  ULLONG_CVWF
#   define  cvwfqi   LLONG_CVWF
#   define  cvwfqf    LDBL_CVWF
#endif

#define     cvwfwbu   VWBU_CVWF
#define     cvwfwbi   VWBI_CVWF
#define     cvwfwbc   VWBC_CVWF
#define     cvwfwhu   VWHU_CVWF
#define     cvwfwhi   VWHI_CVWF
#define     cvwfwhf   VWHF_CVWF
#define     cvwfwwu   VWWU_CVWF
#define     cvwfwwi   VWWI_CVWF
#define     cvwfwwf   VWWF_CVWF

#define     cvwfdhu   VDHU_CVWF
#define     cvwfdhi   VDHI_CVWF
#define     cvwfdhf   VDHF_CVWF
#define     cvwfdwu   VDWU_CVWF
#define     cvwfdwi   VDWI_CVWF
#define     cvwfdwf   VDWF_CVWF
#define     cvwfddu   VDDU_CVWF
#define     cvwfddi   VDDI_CVWF
#define     cvwfddf   VDDF_CVWF

#define     cvwfqwu   VQWU_CVWF
#define     cvwfqwi   VQWI_CVWF
#define     cvwfqwf   VQWF_CVWF
#define     cvwfqdu   VQDU_CVWF
#define     cvwfqdi   VQDI_CVWF
#define     cvwfqdf   VQDF_CVWF
#if _LEAVE_CVWF
}
#endif


#if _ENTER_CVDU
{
#endif
/*  Elementwise convert to uint64_t */

#define     cvdu(...) (cvdu_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvdu_funcof(X, ...)  \
FUNCOF(             \
    cvdu, (   X   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvduyu    BOOL_CVDU
#define     cvdubu   UINT8_CVDU
#define     cvdubi    INT8_CVDU
#define     cvdubc    CHAR_CVDU
#define     cvduhu  UINT16_CVDU
#define     cvduhi   INT16_CVDU
#define     cvduhf   FLT16_CVDU
#define     cvduwu  UINT32_CVDU
#define     cvduwi   INT32_CVDU
#define     cvduwf     FLT_CVDU
#define     cvdudu  UINT64_CVDU
#define     cvdudi   INT64_CVDU
#define     cvdudf     DBL_CVDU
#if   DWRD_NLONG == 2
#   define  cvdulu   ULONG_CVDU
#   define  cvduli    LONG_CVDU
#elif QUAD_NLLONG == 2
#   define  cvdulu  ULLONG_CVDU
#   define  cvduli   LLONG_CVDU
#else
#   define  cvduqu  ULLONG_CVDU
#   define  cvduqi   LLONG_CVDU
#   define  cvduqf    LDBL_CVDU
#endif

#define     cvduwhu   VWHU_CVDU
#define     cvduwhi   VWHI_CVDU
#define     cvduwhf   VWHF_CVDU
#define     cvduwwu   VWWU_CVDU
#define     cvduwwi   VWWI_CVDU
#define     cvduwwf   VWWF_CVDU

#define     cvdudwu   VDWU_CVDU
#define     cvdudwi   VDWI_CVDU
#define     cvdudwf   VDWF_CVDU
#define     cvduddu   VDDU_CVDU
#define     cvduddi   VDDI_CVDU
#define     cvduddf   VDDF_CVDU

#define     cvduqdu   VQDU_CVDU
#define     cvduqdi   VQDI_CVDU
#define     cvduqdf   VQDF_CVDU
#if _LEAVE_CVDU
}
#endif

#if _ENTER_CVDZ
{
#endif
/*  Elementwise convert to saturated uint64_t */

#define     cvdz(...) (cvdz_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvdz_funcof(X, ...)  \
FUNCOF(             \
    cvdz, (   X   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvdzyu    BOOL_CVDZ
#define     cvdzbu   UINT8_CVDZ
#define     cvdzbi    INT8_CVDZ
#define     cvdzbc    CHAR_CVDZ
#define     cvdzhu  UINT16_CVDZ
#define     cvdzhi   INT16_CVDZ
#define     cvdzhf   FLT16_CVDZ
#define     cvdzwu  UINT32_CVDZ
#define     cvdzwi   INT32_CVDZ
#define     cvdzwf     FLT_CVDZ
#define     cvdzdu  UINT64_CVDZ
#define     cvdzdi   INT64_CVDZ
#define     cvdzdf     DBL_CVDZ
#if   DWRD_NLONG == 2
#   define  cvdzlu   ULONG_CVDZ
#   define  cvdzli    LONG_CVDZ
#elif QUAD_NLLONG == 2
#   define  cvdzlu  ULLONG_CVDZ
#   define  cvdzli   LLONG_CVDZ
#else
#   define  cvdzqu  ULLONG_CVDZ
#   define  cvdzqi   LLONG_CVDZ
#   define  cvdzqf    LDBL_CVDZ
#endif

#define     cvdzwhu   VWHU_CVDZ
#define     cvdzwhi   VWHI_CVDZ
#define     cvdzwhf   VWHF_CVDZ

#define     cvdzwwu   VWWU_CVDZ
#define     cvdzwwi   VWWI_CVDZ
#define     cvdzwwf   VWWF_CVDZ

#define     cvdzdwu   VDWU_CVDZ
#define     cvdzdwi   VDWI_CVDZ
#define     cvdzdwf   VDWF_CVDZ
#define     cvdzddu   VDDU_CVDZ
#define     cvdzddi   VDDI_CVDZ
#define     cvdzddf   VDDF_CVDZ

#define     cvdzqdu   VQDU_CVDZ
#define     cvdzqdi   VQDI_CVDZ
#define     cvdzqdf   VQDF_CVDZ
#if _LEAVE_CVDZ
}
#endif

#if _ENTER_CVDI
{
#endif
/*  Elementwise convert to int64_t */

#define     cvdi(...) (cvdi_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvdi_funcof(X, ...)  \
FUNCOF(             \
    cvdi, (   X   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvdiyu    BOOL_CVDI
#define     cvdibu   UINT8_CVDI
#define     cvdibi    INT8_CVDI
#define     cvdibc    CHAR_CVDI
#define     cvdihu  UINT16_CVDI
#define     cvdihi   INT16_CVDI
#define     cvdihf   FLT16_CVDI
#define     cvdiwu  UINT32_CVDI
#define     cvdiwi   INT32_CVDI
#define     cvdiwf     FLT_CVDI
#define     cvdidu  UINT64_CVDI
#define     cvdidi   INT64_CVDI
#define     cvdidf     DBL_CVDI
#if   DWRD_NLONG == 2
#   define  cvdilu   ULONG_CVDI
#   define  cvdili    LONG_CVDI
#elif QUAD_NLLONG == 2
#   define  cvdilu  ULLONG_CVDI
#   define  cvdili   LLONG_CVDI
#else
#   define  cvdiqu  ULLONG_CVDI
#   define  cvdiqi   LLONG_CVDI
#   define  cvdiqf    LDBL_CVDI
#endif

#define     cvdiwhu   VWHU_CVDI
#define     cvdiwhi   VWHI_CVDI
#define     cvdiwhf   VWHF_CVDI
#define     cvdiwwu   VWWU_CVDI
#define     cvdiwwi   VWWI_CVDI
#define     cvdiwwf   VWWF_CVDI

#define     cvdidwu   VDWU_CVDI
#define     cvdidwi   VDWI_CVDI
#define     cvdidwf   VDWF_CVDI
#define     cvdiddu   VDDU_CVDI
#define     cvdiddi   VDDI_CVDI
#define     cvdiddf   VDDF_CVDI

#define     cvdiqdu   VQDU_CVDI
#define     cvdiqdi   VQDI_CVDI
#define     cvdiqdf   VQDF_CVDI
#if _LEAVE_CVDI
}
#endif

#if _ENTER_CVDS
{
#endif
/*  Elementwise convert to saturated int64_t */

#define     cvds(...) (cvds_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvds_funcof(X, ...)  \
FUNCOF(             \
    cvds, (   X   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvdsyu    BOOL_CVDS
#define     cvdsbu   UINT8_CVDS
#define     cvdsbi    INT8_CVDS
#define     cvdsbc    CHAR_CVDS
#define     cvdshu  UINT16_CVDS
#define     cvdshi   INT16_CVDS
#define     cvdshf   FLT16_CVDS
#define     cvdswu  UINT32_CVDS
#define     cvdswi   INT32_CVDS
#define     cvdswf     FLT_CVDS
#define     cvdsdu  UINT64_CVDS
#define     cvdsdi   INT64_CVDS
#define     cvdsdf     DBL_CVDS
#if   DWRD_NLONG == 2
#   define  cvdslu   ULONG_CVDS
#   define  cvdsli    LONG_CVDS
#elif QUAD_NLLONG == 2
#   define  cvdslu  ULLONG_CVDS
#   define  cvdsli   LLONG_CVDS
#else
#   define  cvdsqu  ULLONG_CVDS
#   define  cvdsqi   LLONG_CVDS
#   define  cvdsqf    LDBL_CVDS
#endif

#define     cvdswbu   VWBU_CVDS
#define     cvdswbi   VWBI_CVDS
#define     cvdswbc   VWBC_CVDS
#define     cvdswhu   VWHU_CVDS
#define     cvdswhi   VWHI_CVDS
#define     cvdswhf   VWHF_CVDS
#define     cvdswwu   VWWU_CVDS
#define     cvdswwi   VWWI_CVDS
#define     cvdswwf   VWWF_CVDS

#define     cvdsdbu   VDBU_CVDS
#define     cvdsdbi   VDBI_CVDS
#define     cvdsdbc   VDBC_CVDS
#define     cvdsdhu   VDHU_CVDS
#define     cvdsdhi   VDHI_CVDS
#define     cvdsdhf   VDHF_CVDS
#define     cvdsdwu   VDWU_CVDS
#define     cvdsdwi   VDWI_CVDS
#define     cvdsdwf   VDWF_CVDS
#define     cvdsddu   VDDU_CVDS
#define     cvdsddi   VDDI_CVDS
#define     cvdsddf   VDDF_CVDS

#define     cvdsqdu   VQDU_CVDS
#define     cvdsqdi   VQDI_CVDS
#define     cvdsqdf   VQDF_CVDS
#define     cvdsqqu   VQQU_CVDS
#define     cvdsqqi   VQQI_CVDS
#define     cvdsqqf   VQQF_CVDS
#if _LEAVE_CVDS
}
#endif

#if _ENTER_CVDF
{
#endif
/*  Elementwise convert to IEEE 764 64-bit float (double)

    If an element cannot be converted exactly, the
    rounding direction is implementation defined and a
    floating point exception may be raised.

    If any element cannot be converted, the entire result
    is undefined and the implementation may raise a
    floating point exception.
*/

#define     cvdf(...) (cvdf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     cvdf_funcof(X, ...)  \
FUNCOF(             \
    cvdf, (   X   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     cvdfyu    BOOL_CVDF
#define     cvdfbu   UINT8_CVDF
#define     cvdfbi    INT8_CVDF
#define     cvdfbc    CHAR_CVDF
#define     cvdfhu  UINT16_CVDF
#define     cvdfhi   INT16_CVDF
#define     cvdfhf   FLT16_CVDF
#define     cvdfwu  UINT32_CVDF
#define     cvdfwi   INT32_CVDF
#define     cvdfwf     FLT_CVDF
#define     cvdfdu  UINT64_CVDF
#define     cvdfdi   INT64_CVDF
#define     cvdfdf     DBL_CVDF
#if   DWRD_NLONG == 2
#   define  cvdflu   ULONG_CVDF
#   define  cvdfli    LONG_CVDF
#elif QUAD_NLLONG == 2
#   define  cvdflu  ULLONG_CVDF
#   define  cvdfli   LLONG_CVDF
#else
#   define  cvdfqu  ULLONG_CVDF
#   define  cvdfqi   LLONG_CVDF
#   define  cvdfqf    LDBL_CVDF
#endif

#define     cvdfwhu   VWHU_CVDF
#define     cvdfwhi   VWHI_CVDF
#define     cvdfwhf   VWHF_CVDF
#define     cvdfwwu   VWWU_CVDF
#define     cvdfwwi   VWWI_CVDF
#define     cvdfwwf   VWWF_CVDF

#define     cvdfdwu   VDWU_CVDF
#define     cvdfdwi   VDWI_CVDF
#define     cvdfdwf   VDWF_CVDF
#define     cvdfddu   VDDU_CVDF
#define     cvdfddi   VDDI_CVDF
#define     cvdfddf   VDDF_CVDF

#define     cvdfqdu   VQDU_CVDF
#define     cvdfqdi   VQDI_CVDF
#define     cvdfqdf   VQDF_CVDF
#if _LEAVE_CVDF
}
#endif


#if _ENTER_DCRL
{
#endif
/*  DeCRement (truncated)

Subtract 1 from each element in the operand.
*/

#define     dcrl(...) (dcrl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dcrl_funcof(A, ...)  \
FUNCOF(             \
    dcrl, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     dcrlyu    BOOL_DCRL
#define     dcrlbu   UINT8_DCRL
#define     dcrlbi    INT8_DCRL
#define     dcrlbc    CHAR_DCRL
#define     dcrlhu  UINT16_DCRL
#define     dcrlhi   INT16_DCRL
#define     dcrlwu  UINT32_DCRL
#define     dcrlwi   INT32_DCRL
#define     dcrldu  UINT64_DCRL
#define     dcrldi   INT64_DCRL
#if   DWRD_NLONG == 2
#   define  dcrllu   ULONG_DCRL
#   define  dcrlli    LONG_DCRL
#elif QUAD_NLLONG == 2
#   define  dcrllu  ULLONG_DCRL
#   define  dcrlli   LLONG_DCRL
#else
#   define  dcrlqu  ULLONG_DCRL
#   define  dcrlqi   LLONG_DCRL
#endif

#define     dcrlwyu   VWYU_DCRL
#define     dcrlwbu   VWBU_DCRL
#define     dcrlwbi   VWBI_DCRL
#define     dcrlwbc   VWBC_DCRL
#define     dcrlwhu   VWHU_DCRL
#define     dcrlwhi   VWHI_DCRL
#define     dcrlwwu   VWWU_DCRL
#define     dcrlwwi   VWWI_DCRL

#define     dcrldyu   VDYU_DCRL
#define     dcrldbu   VDBU_DCRL
#define     dcrldbi   VDBI_DCRL
#define     dcrldbc   VDBC_DCRL
#define     dcrldhu   VDHU_DCRL
#define     dcrldhi   VDHI_DCRL
#define     dcrldwu   VDWU_DCRL
#define     dcrldwi   VDWI_DCRL
#define     dcrlddu   VDDU_DCRL
#define     dcrlddi   VDDI_DCRL

#define     dcrlqyu   VQYU_DCRL
#define     dcrlqbu   VQBU_DCRL
#define     dcrlqbi   VQBI_DCRL
#define     dcrlqbc   VQBC_DCRL
#define     dcrlqhu   VQHU_DCRL
#define     dcrlqhi   VQHI_DCRL
#define     dcrlqwu   VQWU_DCRL
#define     dcrlqwi   VQWI_DCRL
#define     dcrlqdu   VQDU_DCRL
#define     dcrlqdi   VQDI_DCRL
#if _LEAVE_DCRL
}
#endif

#if _ENTER_DCR1
{
#endif
/*  DeCRement (atomic subtract 1 w/ memory_order_relaxed)

Atomically exchange the contents of the variable pointed
to by the operand with its previous value minus 1.
*/

#define     dcr1(...)  (dcr1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dcr1_funcof(A, ...) \
FUNCOF_AK(          \
    dcr1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     dcr1ayu    BOOL_DCR1A
#define     dcr1abu   UINT8_DCR1A
#define     dcr1abi    INT8_DCR1A
#define     dcr1abc    CHAR_DCR1A
#define     dcr1ahu  UINT16_DCR1A
#define     dcr1ahi   INT16_DCR1A
#define     dcr1awu  UINT32_DCR1A
#define     dcr1awi   INT32_DCR1A
#define     dcr1adu  UINT64_DCR1A
#define     dcr1adi   INT64_DCR1A
#if DWRD_NLONG == 2
#   define  dcr1alu   ULONG_DCR1A
#   define  dcr1ali    LONG_DCR1A
#elif QUAD_NLLONG == 2
#   define  dcr1alu  ULLONG_DCR1A
#   define  dcr1ali   LLONG_DCR1A
#else
#   define  dcr1aqu  ULLONG_DCR1A
#   define  dcr1aqi   LLONG_DCR1A
#endif

#if _LEAVE_DCR1
}
#endif

#if _ENTER_DCRA
{
#endif
/*  DeCRement (atomic subtract 1 w/ memory_order_acquire)

Atomically exchange the contents of the variable pointed
to by the operand with its previous value minus 1.
*/

#define     dcra(...)  (dcra_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dcra_funcof(A, ...) \
FUNCOF_AK(          \
    dcra, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     dcraayu    BOOL_DCRAA
#define     dcraabu   UINT8_DCRAA
#define     dcraabi    INT8_DCRAA
#define     dcraabc    CHAR_DCRAA
#define     dcraahu  UINT16_DCRAA
#define     dcraahi   INT16_DCRAA
#define     dcraawu  UINT32_DCRAA
#define     dcraawi   INT32_DCRAA
#define     dcraadu  UINT64_DCRAA
#define     dcraadi   INT64_DCRAA
#if DWRD_NLONG == 2
#   define  dcraalu   ULONG_DCRAA
#   define  dcraali    LONG_DCRAA
#elif QUAD_NLLONG == 2
#   define  dcraalu  ULLONG_DCRAA
#   define  dcraali   LLONG_DCRAA
#else
#   define  dcraaqu  ULLONG_DCRAA
#   define  dcraaqi   LLONG_DCRAA
#endif

#if _LEAVE_DCRA
}
#endif

#if _ENTER_DCRE
{
#endif
/*  DeCRement (atomic subtract 1 w/ memory_order_release)

Atomically exchange the contents of the variable pointed
to by the operand with its previous value minus 1.
*/

#define     dcre(...)  (dcre_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dcre_funcof(A, ...) \
FUNCOF_AK(          \
    dcre, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     dcreayu    BOOL_DCREA
#define     dcreabu   UINT8_DCREA
#define     dcreabi    INT8_DCREA
#define     dcreabc    CHAR_DCREA
#define     dcreahu  UINT16_DCREA
#define     dcreahi   INT16_DCREA
#define     dcreawu  UINT32_DCREA
#define     dcreawi   INT32_DCREA
#define     dcreadu  UINT64_DCREA
#define     dcreadi   INT64_DCREA
#if DWRD_NLONG == 2
#   define  dcrealu   ULONG_DCREA
#   define  dcreali    LONG_DCREA
#elif QUAD_NLLONG == 2
#   define  dcrealu  ULLONG_DCREA
#   define  dcreali   LLONG_DCREA
#else
#   define  dcreaqu  ULLONG_DCREA
#   define  dcreaqi   LLONG_DCREA
#endif

#if _LEAVE_DCRE
}
#endif

#if _ENTER_DCRT
{
#endif
/*  DeCRement (atomic subtract 1 w/ memory_order_seq_cst)

Atomically exchange the contents of the variable pointed
to by the operand with its previous value minus 1.
*/

#define     dcrt(...)  (dcrt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dcrt_funcof(A, ...) \
FUNCOF_AK(          \
    dcrt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     dcrtayu    BOOL_DCRTA
#define     dcrtabu   UINT8_DCRTA
#define     dcrtabi    INT8_DCRTA
#define     dcrtabc    CHAR_DCRTA
#define     dcrtahu  UINT16_DCRTA
#define     dcrtahi   INT16_DCRTA
#define     dcrtawu  UINT32_DCRTA
#define     dcrtawi   INT32_DCRTA
#define     dcrtadu  UINT64_DCRTA
#define     dcrtadi   INT64_DCRTA
#if DWRD_NLONG == 2
#   define  dcrtalu   ULONG_DCRTA
#   define  dcrtali    LONG_DCRTA
#elif QUAD_NLLONG == 2
#   define  dcrtalu  ULLONG_DCRTA
#   define  dcrtali   LLONG_DCRTA
#else
#   define  dcrtaqu  ULLONG_DCRTA
#   define  dcrtaqi   LLONG_DCRTA
#endif

#if _LEAVE_DCRT
}
#endif


#if _ENTER_DIFU
{
#endif
/*  absolute DIFference (unsigned)

Compute as an unsigned integer the absolute difference of two
integers. Also known as the distance between two integers on
the number line.
*/

#define     difu(...) (difu_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     difu_funcof(A, ...)  \
FUNCOF(             \
    difu, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     difuyu    BOOL_DIFU
#define     difubu   UINT8_DIFU
#define     difubi    INT8_DIFU
#define     difubc    CHAR_DIFU
#define     difuhu  UINT16_DIFU
#define     difuhi   INT16_DIFU
#define     difuwu  UINT32_DIFU
#define     difuwi   INT32_DIFU
#define     difudu  UINT64_DIFU
#define     difudi   INT64_DIFU
#if   DWRD_NLONG == 2
#   define  difulu   ULONG_DIFU
#   define  difuli    LONG_DIFU
#elif QUAD_NLLONG == 2
#   define  difulu  ULLONG_DIFU
#   define  difuli   LLONG_DIFU
#else
#   define  difuqu  ULLONG_DIFU
#   define  difuqi   LLONG_DIFU
#endif

#define     difuwyu   VWYU_DIFU
#define     difuwbu   VWBU_DIFU
#define     difuwbi   VWBI_DIFU
#define     difuwbc   VWBC_DIFU
#define     difuwhu   VWHU_DIFU
#define     difuwhi   VWHI_DIFU
#define     difuwwu   VWWU_DIFU
#define     difuwwi   VWWI_DIFU

#define     difudyu   VDYU_DIFU
#define     difudbu   VDBU_DIFU
#define     difudbi   VDBI_DIFU
#define     difudbc   VDBC_DIFU
#define     difudhu   VDHU_DIFU
#define     difudhi   VDHI_DIFU
#define     difudwu   VDWU_DIFU
#define     difudwi   VDWI_DIFU
#define     difuddu   VDDU_DIFU
#define     difuddi   VDDI_DIFU

#define     difuqyu   VQYU_DIFU
#define     difuqbu   VQBU_DIFU
#define     difuqbi   VQBI_DIFU
#define     difuqbc   VQBC_DIFU
#define     difuqhu   VQHU_DIFU
#define     difuqhi   VQHI_DIFU
#define     difuqwu   VQWU_DIFU
#define     difuqwi   VQWI_DIFU
#define     difuqdu   VQDU_DIFU
#define     difuqdi   VQDI_DIFU
#if _LEAVE_DIFU
}
#endif


#if _ENTER_DIVL
{
#endif
/*  integer DIVision (truncated)

Divide each N bit integer in the first operand A by the
the corresponding N bit integer in the second operand,
producing a result with the same size as A.
*/

#define     divl(...) (divl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     divl_funcof(A, ...)  \
FUNCOF(             \
    divl, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     divlyu    BOOL_DIVL
#define     divlbu   UINT8_DIVL
#define     divlbi    INT8_DIVL
#define     divlbc    CHAR_DIVL
#define     divlhu  UINT16_DIVL
#define     divlhi   INT16_DIVL
#define     divlwu  UINT32_DIVL
#define     divlwi   INT32_DIVL
#define     divldu  UINT64_DIVL
#define     divldi   INT64_DIVL
#if   DWRD_NLONG == 2
#   define  divllu   ULONG_DIVL
#   define  divlli    LONG_DIVL
#elif QUAD_NLLONG == 2
#   define  divllu  ULLONG_DIVL
#   define  divlli   LLONG_DIVL
#else
#   define  divlqu  ULLONG_DIVL
#   define  divlqi   LLONG_DIVL
#endif

#define     divlwyu   VWYU_DIVL
#define     divlwbu   VWBU_DIVL
#define     divlwbi   VWBI_DIVL
#define     divlwbc   VWBC_DIVL
#define     divlwhu   VWHU_DIVL
#define     divlwhi   VWHI_DIVL
#define     divlwwu   VWWU_DIVL
#define     divlwwi   VWWI_DIVL

#define     divldyu   VDYU_DIVL
#define     divldbu   VDBU_DIVL
#define     divldbi   VDBI_DIVL
#define     divldbc   VDBC_DIVL
#define     divldhu   VDHU_DIVL
#define     divldhi   VDHI_DIVL
#define     divldwu   VDWU_DIVL
#define     divldwi   VDWI_DIVL
#define     divlddu   VDDU_DIVL
#define     divlddi   VDDI_DIVL

#define     divlqyu   VQYU_DIVL
#define     divlqbu   VQBU_DIVL
#define     divlqbi   VQBI_DIVL
#define     divlqbc   VQBC_DIVL
#define     divlqhu   VQHU_DIVL
#define     divlqhi   VQHI_DIVL
#define     divlqwu   VQWU_DIVL
#define     divlqwi   VQWI_DIVL
#define     divlqdu   VQDU_DIVL
#define     divlqdi   VQDI_DIVL
#if _LEAVE_DIVL
}
#endif

#if _ENTER_DIV2
{
#endif
/*  integer DIVision (wide divisor)

Divide each N bit integer in the first operand A by the
the corresponding N÷2 bit integer in the second operand,
producing a N÷2 bit quotient. I.e., the inverse of mul2.
*/

#define     div2(...) (div2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     div2_funcof(A, ...)  \
FUNCOF(             \
    div2, (   A   ),\
    HDZ,  /* TGK */ \
    NONE, /* TGW */ \
    HDZ,  /* TGD */ \
    HDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     div2hu  UINT16_DIV2
#define     div2hi   INT16_DIV2
#define     div2wu  UINT32_DIV2
#define     div2wi   INT32_DIV2
#define     div2du  UINT64_DIV2
#define     div2di   INT64_DIV2
#if   DWRD_NLONG == 2
#   define  div2lu   ULONG_DIV2
#   define  div2li    LONG_DIV2
#elif QUAD_NLLONG == 2
#   define  div2lu  ULLONG_DIV2
#   define  div2li   LLONG_DIV2
#else
#   define  div2qu  ULLONG_DIV2
#   define  div2qi   LLONG_DIV2
#endif

#define     div2dhu   VDHU_DIV2
#define     div2dhi   VDHI_DIV2
#define     div2dwu   VDWU_DIV2
#define     div2dwi   VDWI_DIV2
#define     div2ddu   VDDU_DIV2
#define     div2ddi   VDDI_DIV2

#define     div2qhu   VQHU_DIV2
#define     div2qhi   VQHI_DIV2
#define     div2qwu   VQWU_DIV2
#define     div2qwi   VQWI_DIV2
#define     div2qdu   VQDU_DIV2
#define     div2qdi   VQDI_DIV2
#if _LEAVE_DIV2
}
#endif

#if _ENTER_DIVH
{
#endif
/*  DIVide (flt16_t)

Divide each element in the first operand by the corresponding
16 bit float element in the second operand. The result's
element type is based on the effective type of a mixed type
C division expression.
*/

#define     divh(...) (divh_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     divh_funcof(A, ...)  \
FUNCOF(             \
    divh, (   A   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     divhyu    BOOL_DIVH
#define     divhbu   UINT8_DIVH
#define     divhbi    INT8_DIVH
#define     divhbc    CHAR_DIVH
#define     divhhu  UINT16_DIVH
#define     divhhi   INT16_DIVH
#define     divhhf   FLT16_DIVH
#define     divhwu  UINT32_DIVH
#define     divhwi   INT32_DIVH
#define     divhwf     FLT_DIVH
#define     divhdu  UINT64_DIVH
#define     divhdi   INT64_DIVH
#define     divhdf     DBL_DIVH
#if   DWRD_NLONG == 2
#   define  divhlu   ULONG_DIVH
#   define  divhli    LONG_DIVH
#elif QUAD_NLLONG == 2
#   define  divhlu  ULLONG_DIVH
#   define  divhli   LLONG_DIVH
#else
#   define  divhqu  ULLONG_DIVH
#   define  divhqi   LLONG_DIVH
#   define  divhqf    LDBL_DIVH
#endif

#define     divhwbu   VWBU_DIVH
#define     divhwbi   VWBI_DIVH
#define     divhwbc   VWBC_DIVH
#define     divhwhu   VWHU_DIVH
#define     divhwhi   VWHI_DIVH
#define     divhwhf   VWHF_DIVH

#define     divhdbu   VDBU_DIVH
#define     divhdbi   VDBI_DIVH
#define     divhdbc   VDBC_DIVH
#define     divhdhu   VDHU_DIVH
#define     divhdhi   VDHI_DIVH
#define     divhdhf   VDHF_DIVH
#define     divhdwu   VDWU_DIVH
#define     divhdwi   VDWI_DIVH
#define     divhdwf   VDWF_DIVH

#define     divhqhu   VQHU_DIVH
#define     divhqhi   VQHI_DIVH
#define     divhqhf   VQHF_DIVH
#define     divhqwu   VQWU_DIVH
#define     divhqwi   VQWI_DIVH
#define     divhqwf   VQWF_DIVH
#define     divhqdu   VQDU_DIVH
#define     divhqdi   VQDI_DIVH
#define     divhqdf   VQDF_DIVH
#if _LEAVE_DIVH
}
#endif

#if _ENTER_DIVW
{
#endif
/*  DIVide (float)

Divide each number in the first operand by the corresponding
32 bit float in the second operand.
*/

#define     divw(...) (divw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     divw_funcof(A, ...)  \
FUNCOF(             \
    divw, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     divwyu    BOOL_DIVW
#define     divwbu   UINT8_DIVW
#define     divwbi    INT8_DIVW
#define     divwbc    CHAR_DIVW
#define     divwhu  UINT16_DIVW
#define     divwhi   INT16_DIVW
#define     divwhf   FLT16_DIVW
#define     divwwu  UINT32_DIVW
#define     divwwi   INT32_DIVW
#define     divwwf     FLT_DIVW
#define     divwdu  UINT64_DIVW
#define     divwdi   INT64_DIVW
#define     divwdf     DBL_DIVW
#if   DWRD_NLONG == 2
#   define  divwlu   ULONG_DIVW
#   define  divwli    LONG_DIVW
#elif QUAD_NLLONG == 2
#   define  divwlu  ULLONG_DIVW
#   define  divwli   LLONG_DIVW
#else
#   define  divwqu  ULLONG_DIVW
#   define  divwqi   LLONG_DIVW
#   define  divwqf    LDBL_DIVW
#endif

#define     divwwbu   VWBU_DIVW
#define     divwwbi   VWBI_DIVW
#define     divwwbc   VWBC_DIVW
#define     divwwhu   VWHU_DIVW
#define     divwwhi   VWHI_DIVW
#define     divwwhf   VWHF_DIVW
#define     divwwwu   VWWU_DIVW
#define     divwwwi   VWWI_DIVW
#define     divwwwf   VWWF_DIVW

#define     divwdhu   VDHU_DIVW
#define     divwdhi   VDHI_DIVW
#define     divwdhf   VDHF_DIVW
#define     divwdwu   VDWU_DIVW
#define     divwdwi   VDWI_DIVW
#define     divwdwf   VDWF_DIVW
#define     divwddu   VDDU_DIVW
#define     divwddi   VDDI_DIVW
#define     divwddf   VDDF_DIVW

#define     divwqwu   VQWU_DIVW
#define     divwqwi   VQWI_DIVW
#define     divwqwf   VQWF_DIVW
#define     divwqdu   VQDU_DIVW
#define     divwqdi   VQDI_DIVW
#define     divwqdf   VQDF_DIVW
#if _LEAVE_DIVW
}
#endif

#if _ENTER_DIVD
{
#endif
/*  DIVide (double)

Divide each number in the first operand by the corresponding
64 bit float in the second operand.
*/

#define     divd(...) (divd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     divd_funcof(A, ...)  \
FUNCOF(             \
    divd, (   A   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     divdyu    BOOL_DIVD
#define     divdbu   UINT8_DIVD
#define     divdbi    INT8_DIVD
#define     divdbc    CHAR_DIVD
#define     divdhu  UINT16_DIVD
#define     divdhi   INT16_DIVD
#define     divdhf   FLT16_DIVD
#define     divdwu  UINT32_DIVD
#define     divdwi   INT32_DIVD
#define     divdwf     FLT_DIVD
#define     divddu  UINT64_DIVD
#define     divddi   INT64_DIVD
#define     divddf     DBL_DIVD
#if   DWRD_NLONG == 2
#   define  divdlu   ULONG_DIVD
#   define  divdli    LONG_DIVD
#elif QUAD_NLLONG == 2
#   define  divdlu  ULLONG_DIVD
#   define  divdli   LLONG_DIVD
#else
#   define  divdqu  ULLONG_DIVD
#   define  divdqi   LLONG_DIVD
#   define  divdqf    LDBL_DIVD
#endif

#define     divdwhu   VWHU_DIVD
#define     divdwhi   VWHI_DIVD
#define     divdwhf   VWHF_DIVD
#define     divdwwu   VWWU_DIVD
#define     divdwwi   VWWI_DIVD
#define     divdwwf   VWWF_DIVD

#define     divddwu   VDWU_DIVD
#define     divddwi   VDWI_DIVD
#define     divddwf   VDWF_DIVD
#define     divdddu   VDDU_DIVD
#define     divdddi   VDDI_DIVD
#define     divdddf   VDDF_DIVD

#define     divdqdu   VQDU_DIVD
#define     divdqdi   VQDI_DIVD
#define     divdqdf   VQDF_DIVD
#if _LEAVE_DIVD
}
#endif


#if _ENTER_DUPW
{
#endif
/*  Set each lane of a 32 bit vector to the same value

The source value can be a 1, 8, or 16 bit scalar, the
unaligned memory address of a scalar, or a vector plus
the lane number to duplicate.
*/

#define     dupw(...)    (dupw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dupw_funcof(X, ...) \
FUNCOF_AC(                      \
    dupw, (   X   ),\
    YHR,  /* TGK */ \
    YHR,  /* TGA */ \
    YHR,  /* TGW */ \
    YHR,  /* TGD */ \
    YHR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     dupwyu        BOOL_DUPW
#define     dupwacyu      BOOL_DUPWAC
#define     dupwbu       UINT8_DUPW
#define     dupwacbu     UINT8_DUPWAC
#define     dupwbi        INT8_DUPW
#define     dupwacbi      INT8_DUPWAC
#define     dupwacbc      CHAR_DUPWAC
#define     dupwbc        CHAR_DUPW
#define     dupwhu      UINT16_DUPW
#define     dupwachu    UINT16_DUPWAC
#define     dupwhi       INT16_DUPW
#define     dupwachi     INT16_DUPWAC
#define     dupwhf       FLT16_DUPW
#define     dupwachf     FLT16_DUPWAC
#define     dupwwu      UINT32_DUPW
#define     dupwacwu    UINT32_DUPWAC
#define     dupwwi       INT32_DUPW
#define     dupwacwi     INT32_DUPWAC
#define     dupwwf         FLT_DUPW
#define     dupwacwf       FLT_DUPWAC

#define     dupwwyu       VWYU_DUPW
#define     dupwwbu       VWBU_DUPW
#define     dupwwbi       VWBI_DUPW
#define     dupwwbc       VWBC_DUPW
#define     dupwwhu       VWHU_DUPW
#define     dupwwhi       VWHI_DUPW
#define     dupwwhf       VWHF_DUPW

#define     dupwdyu       VDYU_DUPW
#define     dupwdbu       VDBU_DUPW
#define     dupwdbi       VDBI_DUPW
#define     dupwdbc       VDBC_DUPW
#define     dupwdhu       VDHU_DUPW
#define     dupwdhi       VDHI_DUPW
#define     dupwdhf       VDHF_DUPW

#define     dupwqyu       VQYU_DUPW
#define     dupwqbu       VQBU_DUPW
#define     dupwqbi       VQBI_DUPW
#define     dupwqbc       VQBC_DUPW
#define     dupwqhu       VQHU_DUPW
#define     dupwqhi       VQHI_DUPW
#define     dupwqhf       VQHF_DUPW
#if _LEAVE_DUPW
}
#endif

#if _ENTER_DUPD
{
#endif
/*  Set each lane of a 64 bit vector to the same value */

#define     dupd(...)    (dupd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dupd_funcof(X, ...) \
FUNCOF_AC(                      \
    dupd, (   X   ),\
    YDR,  /* TGK */ \
    YDR,  /* TGA */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define      dupdyu     BOOL_DUPD
#define      dupdbu    UINT8_DUPD
#define      dupdbi     INT8_DUPD
#define      dupdbc     CHAR_DUPD
#define      dupdhu   UINT16_DUPD
#define      dupdhi    INT16_DUPD
#define      dupdhf    FLT16_DUPD
#define      dupdwu   UINT32_DUPD
#define      dupdwi    INT32_DUPD
#define      dupdwf      FLT_DUPD
#define      dupddu   UINT64_DUPD
#define      dupddi    INT64_DUPD
#define      dupddf      DBL_DUPD
#if DWRD_NLONG == 2
#   define  dupdlu       ULONG_DUPD
#   define  dupdaclu     ULONG_DUPDAC
#   define  dupdli        LONG_DUPD
#   define  dupdacli      LONG_DUPDAC
#elif QUAD_NLLONG == 2
#   define  dupdlu      ULLONG_DUPD
#   define  dupdli       LLONG_DUPD
#   define  dupdaclu    ULLONG_DUPDAC
#   define  dupdacli     LLONG_DUPDAC
#endif

#define      dupdacyu   BOOL_DUPDAC
#define      dupdacbu  UINT8_DUPDAC
#define      dupdacbi   INT8_DUPDAC
#define      dupdacbc   CHAR_DUPDAC
#define      dupdachu UINT16_DUPDAC
#define      dupdachi  INT16_DUPDAC
#define      dupdachf  FLT16_DUPDAC
#define      dupdacwu UINT32_DUPDAC
#define      dupdacwi  INT32_DUPDAC
#define      dupdacwf    FLT_DUPDAC
#define      dupdacdu UINT64_DUPDAC
#define      dupdacdi  INT64_DUPDAC
#define      dupdacdf    DBL_DUPDAC

#define      dupdwyu    VWYU_DUPD
#define      dupdwbu    VWBU_DUPD
#define      dupdwbi    VWBI_DUPD
#define      dupdwbc    VWBC_DUPD
#define      dupdwhu    VWHU_DUPD
#define      dupdwhi    VWHI_DUPD
#define      dupdwhf    VWHF_DUPD
#define      dupdwwu    VWWU_DUPD
#define      dupdwwi    VWWI_DUPD
#define      dupdwwf    VWWF_DUPD

#define      dupddyu    VDYU_DUPD
#define      dupddbu    VDBU_DUPD
#define      dupddbi    VDBI_DUPD
#define      dupddbc    VDBC_DUPD
#define      dupddhu    VDHU_DUPD
#define      dupddhi    VDHI_DUPD
#define      dupddhf    VDHF_DUPD
#define      dupddwu    VDWU_DUPD
#define      dupddwi    VDWI_DUPD
#define      dupddwf    VDWF_DUPD
#define      dupdddu    VDDU_DUPD
#define      dupdddi    VDDI_DUPD
#define      dupdddf    VDDF_DUPD

#define      dupdqyu    VQYU_DUPD
#define      dupdqbu    VQBU_DUPD
#define      dupdqbi    VQBI_DUPD
#define      dupdqbc    VQBC_DUPD
#define      dupdqhu    VQHU_DUPD
#define      dupdqhi    VQHI_DUPD
#define      dupdqhf    VQHF_DUPD
#define      dupdqwu    VQWU_DUPD
#define      dupdqwi    VQWI_DUPD
#define      dupdqwf    VQWF_DUPD
#define      dupdqdu    VQDU_DUPD
#define      dupdqdi    VQDI_DUPD
#define      dupdqdf    VQDF_DUPD
#if _LEAVE_DUPD
}
#endif

#if _ENTER_DUPQ
{
#endif
/*  Set each lane of a 128 bit vector to the same value */

#define     dupq(...)    (dupq_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     dupq_funcof(X, ...) \
FUNCOF_AC(          \
    dupq, (   X   ),\
    YDR,  /* TGK */ \
    YDR,  /* TGA */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#if DWRD_NLONG == 2
#   define  dupqlu       ULONG_DUPQ
#   define  dupqaclu     ULONG_DUPQAC
#   define  dupqli        LONG_DUPQ
#   define  dupqacli      LONG_DUPQAC
#elif QUAD_NLLONG == 2
#   define  dupqlu      ULLONG_DUPQ
#   define  dupqli       LLONG_DUPQ
#   define  dupqaclu    ULLONG_DUPQAC
#   define  dupqacli     LLONG_DUPQAC
#else
#   define  dupqqu      ULLONG_DUPQ
#   define  dupqqi       LLONG_DUPQ
#   define  dupqacqu    ULLONG_DUPQAC
#   define  dupqacqi     LLONG_DUPQAC
#endif

#define      dupqyu     BOOL_DUPQ
#define      dupqbu    UINT8_DUPQ
#define      dupqbi     INT8_DUPQ
#define      dupqbc     CHAR_DUPQ
#define      dupqhu   UINT16_DUPQ
#define      dupqhi    INT16_DUPQ
#define      dupqhf    FLT16_DUPQ
#define      dupqwu   UINT32_DUPQ
#define      dupqwi    INT32_DUPQ
#define      dupqwf      FLT_DUPQ
#define      dupqdu   UINT64_DUPQ
#define      dupqdi    INT64_DUPQ
#define      dupqdf      DBL_DUPQ

#define      dupqacyu   BOOL_DUPQAC
#define      dupqacbu  UINT8_DUPQAC
#define      dupqacbi   INT8_DUPQAC
#define      dupqacbc   CHAR_DUPQAC
#define      dupqachu UINT16_DUPQAC
#define      dupqachi  INT16_DUPQAC
#define      dupqachf  FLT16_DUPQAC
#define      dupqacwu UINT32_DUPQAC
#define      dupqacwi  INT32_DUPQAC
#define      dupqacwf    FLT_DUPQAC
#define      dupqacdu UINT64_DUPQAC
#define      dupqacdi  INT64_DUPQAC
#define      dupqacdf    DBL_DUPQAC

#define      dupqwyu    VWYU_DUPQ
#define      dupqwbu    VWBU_DUPQ
#define      dupqwbi    VWBI_DUPQ
#define      dupqwbc    VWBC_DUPQ
#define      dupqwhu    VWHU_DUPQ
#define      dupqwhi    VWHI_DUPQ
#define      dupqwhf    VWHF_DUPQ
#define      dupqwwu    VWWU_DUPQ
#define      dupqwwi    VWWI_DUPQ
#define      dupqwwf    VWWF_DUPQ

#define      dupqdyu    VDYU_DUPQ
#define      dupqdbu    VDBU_DUPQ
#define      dupqdbi    VDBI_DUPQ
#define      dupqdbc    VDBC_DUPQ
#define      dupqdhu    VDHU_DUPQ
#define      dupqdhi    VDHI_DUPQ
#define      dupqdhf    VDHF_DUPQ
#define      dupqdwu    VDWU_DUPQ
#define      dupqdwi    VDWI_DUPQ
#define      dupqdwf    VDWF_DUPQ
#define      dupqddu    VDDU_DUPQ
#define      dupqddi    VDDI_DUPQ
#define      dupqddf    VDDF_DUPQ

#define      dupqqyu    VQYU_DUPQ
#define      dupqqbu    VQBU_DUPQ
#define      dupqqbi    VQBI_DUPQ
#define      dupqqbc    VQBC_DUPQ
#define      dupqqhu    VQHU_DUPQ
#define      dupqqhi    VQHI_DUPQ
#define      dupqqhf    VQHF_DUPQ
#define      dupqqwu    VQWU_DUPQ
#define      dupqqwi    VQWI_DUPQ
#define      dupqqwf    VQWF_DUPQ
#define      dupqqdu    VQDU_DUPQ
#define      dupqqdi    VQDI_DUPQ
#define      dupqqdf    VQDF_DUPQ
#if _LEAVE_DUPQ
}
#endif

#if _ENTER_DUPL
{
#endif
/*  Copy the the first vector lane into all others

x86 calls this "broadcast" and ppc calls it "splat".
*/

#define     dupl(V)    (dupl_funcof(V)(V))
#define     dupl_funcof(V)  \
FUNCOF(             \
    dupl, (   V   ),\
    NONE, /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define      duplwyu    VWYU_DUPL
#define      duplwbu    VWBU_DUPL
#define      duplwbi    VWBI_DUPL
#define      duplwbc    VWBC_DUPL
#define      duplwhu    VWHU_DUPL
#define      duplwhi    VWHI_DUPL
#define      duplwhf    VWHF_DUPL
#define      duplwwu    VWWU_DUPL
#define      duplwwi    VWWI_DUPL
#define      duplwwf    VWWF_DUPL

#define      dupldyu    VDYU_DUPL
#define      dupldbu    VDBU_DUPL
#define      dupldbi    VDBI_DUPL
#define      dupldbc    VDBC_DUPL
#define      dupldhu    VDHU_DUPL
#define      dupldhi    VDHI_DUPL
#define      dupldhf    VDHF_DUPL
#define      dupldwu    VDWU_DUPL
#define      dupldwi    VDWI_DUPL
#define      dupldwf    VDWF_DUPL
#define      duplddu    VDDU_DUPL
#define      duplddi    VDDI_DUPL
#define      duplddf    VDDF_DUPL

#define      duplqyu    VQYU_DUPL
#define      duplqbu    VQBU_DUPL
#define      duplqbi    VQBI_DUPL
#define      duplqbc    VQBC_DUPL
#define      duplqhu    VQHU_DUPL
#define      duplqhi    VQHI_DUPL
#define      duplqhf    VQHF_DUPL
#define      duplqwu    VQWU_DUPL
#define      duplqwi    VQWI_DUPL
#define      duplqwf    VQWF_DUPL
#define      duplqdu    VQDU_DUPL
#define      duplqdi    VQDI_DUPL
#define      duplqdf    VQDF_DUPL
#if _LEAVE_DUPL
}
#endif


#if _ENTER_FAML
{
#endif
/*  Fused Add Multiply (truncated)

For integers A, B, and C in each operand, respectively,
compute the truncated result of A+B*C.
*/

#define     faml(...) (faml_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     faml_funcof(A, ...)  \
FUNCOF(             \
    faml, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     famlyu    BOOL_FAML
#define     famlbu   UINT8_FAML
#define     famlbi    INT8_FAML
#define     famlbc    CHAR_FAML
#define     famlhu  UINT16_FAML
#define     famlhi   INT16_FAML
#define     famlwu  UINT32_FAML
#define     famlwi   INT32_FAML
#define     famldu  UINT64_FAML
#define     famldi   INT64_FAML
#if   DWRD_NLONG == 2
#   define  famllu   ULONG_FAML
#   define  famlli    LONG_FAML
#elif QUAD_NLLONG == 2
#   define  famllu  ULLONG_FAML
#   define  famlli   LLONG_FAML
#else
#   define  famlqu  ULLONG_FAML
#   define  famlqi   LLONG_FAML
#   define  famlqf    LDBL_FAML
#endif

#define     famlwyu   VWYU_FAML
#define     famlwbu   VWBU_FAML
#define     famlwbi   VWBI_FAML
#define     famlwbc   VWBC_FAML
#define     famlwhu   VWHU_FAML
#define     famlwhi   VWHI_FAML
#define     famlwwu   VWWU_FAML
#define     famlwwi   VWWI_FAML

#define     famldyu   VDYU_FAML
#define     famldbu   VDBU_FAML
#define     famldbi   VDBI_FAML
#define     famldbc   VDBC_FAML
#define     famldhu   VDHU_FAML
#define     famldhi   VDHI_FAML
#define     famldwu   VDWU_FAML
#define     famldwi   VDWI_FAML
#define     famlddu   VDDU_FAML
#define     famlddi   VDDI_FAML

#define     famlqyu   VQYU_FAML
#define     famlqbu   VQBU_FAML
#define     famlqbi   VQBI_FAML
#define     famlqbc   VQBC_FAML
#define     famlqhu   VQHU_FAML
#define     famlqhi   VQHI_FAML
#define     famlqwu   VQWU_FAML
#define     famlqwi   VQWI_FAML
#define     famlqdu   VQDU_FAML
#define     famlqdi   VQDI_FAML
#if _LEAVE_FAML
}
#endif

#if _ENTER_FAM2
{
#endif
/*  Fused Add Multiply (widened accumulator)

For elements A, B, and C in the three operands, respectively,
compute the saturated result of A+B*C. A is twice as wide
as B or C.

If the element type of A is too small to store the result
of A+B*C, the result is implementation defined.
*/

#define     fam2(...) (fam2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     fam2_funcof(A, ...)  \
FUNCOF(             \
    fam2, (   A   ),\
    HDZ,  /* TGK */ \
    NONE, /* TGW */ \
    HDZ,  /* TGD */ \
    HDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     fam2hu  UINT16_FAM2 // u16+u8×u8
#define     fam2hi   INT16_FAM2 // i16+i8×i8
#define     fam2wu  UINT32_FAM2 // u32+u16×u16
#define     fam2wi   INT32_FAM2 // i32+i16×i16
#define     fam2du  UINT64_FAM2 // u64+u32×u32
#define     fam2di   INT64_FAM2 // i64+i32×i32
#if   DWRD_NLONG == 2
#   define  fam2lu   ULONG_FAM2 // u32+u16×u16
#   define  fam2li    LONG_FAM2 // i32+i16×i16
#elif QUAD_NLLONG == 2
#   define  fam2lu  ULLONG_FAM2 // u64+u32×u32
#   define  fam2li   LLONG_FAM2 // i64+i32×i32
#else
#   define  fam2qu  ULLONG_FAM2 // u128+u64×u64
#   define  fam2qi   LLONG_FAM2 // i128+i64×i64
#endif

#define     fam2dhu   VDHU_FAM2
#define     fam2dhi   VDHI_FAM2
#define     fam2dwu   VDWU_FAM2
#define     fam2dwi   VDWI_FAM2
#define     fam2ddu   VDDU_FAM2
#define     fam2ddi   VDDI_FAM2

#define     fam2qhu   VQHU_FAM2
#define     fam2qhi   VQHI_FAM2
#define     fam2qwu   VQWU_FAM2
#define     fam2qwi   VQWI_FAM2
#define     fam2qdu   VQDU_FAM2
#define     fam2qdi   VQDI_FAM2
#if _LEAVE_FAM2
}
#endif

#if _ENTER_FAMF
{
#endif
/*  Fused Add Multiply (floating)

For elements A, B, and C in the three respective operands, 
compute A+B*C.
*/

#define     famf(...) (famf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     famf_funcof(A, ...)  \
FUNCOF(             \
    famf, (   A   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     famfhf   FLT16_FAMF
#define     famfwf     FLT_FAMF
#define     famfdf     DBL_FAMF

#define     famfwhf   VWHF_FAMF
#define     famfwwf   VWWF_FAMF

#define     famfdhf   VDHF_FAMF
#define     famfdwf   VDWF_FAMF
#define     famfddf   VDDF_FAMF

#define     famfqhf   VQHF_FAMF
#define     famfqwf   VQWF_FAMF
#define     famfqdf   VQDF_FAMF
#if _LEAVE_FAML
}
#endif


#if _ENTER_GET1
{
#endif
/*  Extract a single vector element 

*/

#define     get1(...)  (get1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     get1_funcof(S, ...) \
FUNCOF(             \
    get1, (   S   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     get1wyu VWYU_GET1
#define     get1wbu VWBU_GET1
#define     get1wbi VWBI_GET1
#define     get1wbc VWBC_GET1
#define     get1whu VWHU_GET1
#define     get1whi VWHI_GET1
#define     get1whf VWHF_GET1

#define     get1dyu VDYU_GET1
#define     get1dbu VDBU_GET1
#define     get1dbi VDBI_GET1
#define     get1dbc VDBC_GET1
#define     get1dhu VDHU_GET1
#define     get1dhi VDHI_GET1
#define     get1dhf VDHF_GET1
#define     get1dwu VDWU_GET1
#define     get1dwi VDWI_GET1
#define     get1dwf VDWF_GET1

#define     get1qyu VQYU_GET1
#define     get1qbu VQBU_GET1
#define     get1qbi VQBI_GET1
#define     get1qbc VQBC_GET1
#define     get1qhu VQHU_GET1
#define     get1qhi VQHI_GET1
#define     get1qhf VQHF_GET1
#define     get1qwu VQWU_GET1
#define     get1qwi VQWI_GET1
#define     get1qwf VQWF_GET1
#define     get1qdu VQDU_GET1
#define     get1qdi VQDI_GET1
#define     get1qdf VQDF_GET1
#if _LEAVE_GET1
}
#endif

#if _ENTER_GETL
{
#endif
/*  Extract lower half
*/

#define     getl(...)  (getl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     getl_funcof(S, ...) \
FUNCOF(             \
    getl, (   S   ),\
    HDZ,  /* TGK */ \
    NONE, /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     getlhu  UINT16_GETL
#define     getlhi   INT16_GETL
#define     getlwu  UINT32_GETL
#define     getlwi   INT32_GETL
#define     getldu  UINT64_GETL
#define     getldi   INT64_GETL
#if DWRD_NLONG == 2
#   define  getllu   ULONG_GETL
#   define  getlli    LONG_GETL
#elif QUAD_NLLONG == 2
#   define  getllu  ULLONG_GETL
#   define  getlli   LLONG_GETL
#else
#   define  getlqu  ULLONG_GETL
#   define  getlqi   LLONG_GETL
#endif

#define     getldyu VDYU_GETL
#define     getldbu VDBU_GETL
#define     getldbi VDBI_GETL
#define     getldbc VDBC_GETL
#define     getldhu VDHU_GETL
#define     getldhi VDHI_GETL
#define     getldhf VDHF_GETL
#define     getldwu VDWU_GETL
#define     getldwi VDWI_GETL
#define     getldwf VDWF_GETL

#define     getlqyu VQYU_GETL
#define     getlqbu VQBU_GETL
#define     getlqbi VQBI_GETL
#define     getlqbc VQBC_GETL
#define     getlqhu VQHU_GETL
#define     getlqhi VQHI_GETL
#define     getlqhf VQHF_GETL
#define     getlqwu VQWU_GETL
#define     getlqwi VQWI_GETL
#define     getlqwf VQWF_GETL
#define     getlqdu VQDU_GETL
#define     getlqdi VQDI_GETL
#define     getlqdf VQDF_GETL
#if _LEAVE_GETL
}
#endif

#if _ENTER_GETR
{
#endif
/*  Extract upper half
*/

#define     getr(...)  (getr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     getr_funcof(S, ...) \
FUNCOF(             \
    getr, (   S   ),\
    HDZ,  /* TGK */ \
    NONE, /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     getrhu  UINT16_GETR
#define     getrhi   INT16_GETR
#define     getrwu  UINT32_GETR
#define     getrwi   INT32_GETR
#define     getrdu  UINT64_GETR
#define     getrdi   INT64_GETR
#if DWRD_NLONG == 2
#   define  getrlu   ULONG_GETR
#   define  getrli    LONG_GETR
#elif QUAD_NLLONG == 2
#   define  getrlu  ULLONG_GETR
#   define  getrli   LLONG_GETR
#else
#   define  getrqu  ULLONG_GETR
#   define  getrqi   LLONG_GETR
#endif

#define     getrdyu VDYU_GETR
#define     getrdbu VDBU_GETR
#define     getrdbi VDBI_GETR
#define     getrdbc VDBC_GETR
#define     getrdhu VDHU_GETR
#define     getrdhi VDHI_GETR
#define     getrdhf VDHF_GETR
#define     getrdwu VDWU_GETR
#define     getrdwi VDWI_GETR
#define     getrdwf VDWF_GETR

#define     getrqyu VQYU_GETR
#define     getrqbu VQBU_GETR
#define     getrqbi VQBI_GETR
#define     getrqbc VQBC_GETR
#define     getrqhu VQHU_GETR
#define     getrqhi VQHI_GETR
#define     getrqhf VQHF_GETR
#define     getrqwu VQWU_GETR
#define     getrqwi VQWI_GETR
#define     getrqwf VQWF_GETR
#define     getrqdu VQDU_GETR
#define     getrqdi VQDI_GETR
#define     getrqdf VQDF_GETR
#if _LEAVE_GETR
}
#endif


#if _ENTER_ICRL
{
#endif
/*  InCRement (truncated) */

#define     icrl(...) (icrl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     icrl_funcof(A, ...)  \
FUNCOF(             \
    icrl, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     icrlyu    BOOL_ICRL
#define     icrlbu   UINT8_ICRL
#define     icrlbi    INT8_ICRL
#define     icrlbc    CHAR_ICRL
#define     icrlhu  UINT16_ICRL
#define     icrlhi   INT16_ICRL
#define     icrlwu  UINT32_ICRL
#define     icrlwi   INT32_ICRL
#define     icrldu  UINT64_ICRL
#define     icrldi   INT64_ICRL
#if   DWRD_NLONG == 2
#   define  icrllu   ULONG_ICRL
#   define  icrlli    LONG_ICRL
#elif QUAD_NLLONG == 2
#   define  icrllu  ULLONG_ICRL
#   define  icrlli   LLONG_ICRL
#else
#   define  icrlqu  ULLONG_ICRL
#   define  icrlqi   LLONG_ICRL
#endif

#define     icrlwyu   VWYU_ICRL
#define     icrlwbu   VWBU_ICRL
#define     icrlwbi   VWBI_ICRL
#define     icrlwbc   VWBC_ICRL
#define     icrlwhu   VWHU_ICRL
#define     icrlwhi   VWHI_ICRL
#define     icrlwwu   VWWU_ICRL
#define     icrlwwi   VWWI_ICRL

#define     icrldyu   VDYU_ICRL
#define     icrldbu   VDBU_ICRL
#define     icrldbi   VDBI_ICRL
#define     icrldbc   VDBC_ICRL
#define     icrldhu   VDHU_ICRL
#define     icrldhi   VDHI_ICRL
#define     icrldwu   VDWU_ICRL
#define     icrldwi   VDWI_ICRL
#define     icrlddu   VDDU_ICRL
#define     icrlddi   VDDI_ICRL

#define     icrlqyu   VQYU_ICRL
#define     icrlqbu   VQBU_ICRL
#define     icrlqbi   VQBI_ICRL
#define     icrlqbc   VQBC_ICRL
#define     icrlqhu   VQHU_ICRL
#define     icrlqhi   VQHI_ICRL
#define     icrlqwu   VQWU_ICRL
#define     icrlqwi   VQWI_ICRL
#define     icrlqdu   VQDU_ICRL
#define     icrlqdi   VQDI_ICRL
#if _LEAVE_ICRL
}
#endif

#if _ENTER_ICR1
{
#endif
/*  InCRement (atomic add 1 w/ memory_order_relaxed)

Atomically exchange the contents of the variable pointed
to by the operand with the sum of it plus 1.

atomic_add_explicit(a, 1, memory_order_relaxed)
*/

#define     icr1(...)  (icr1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     icr1_funcof(A, ...) \
FUNCOF_AK(          \
    icr1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     icr1ayu    BOOL_ICR1A
#define     icr1abu   UINT8_ICR1A
#define     icr1abi    INT8_ICR1A
#define     icr1abc    CHAR_ICR1A
#define     icr1ahu  UINT16_ICR1A
#define     icr1ahi   INT16_ICR1A
#define     icr1awu  UINT32_ICR1A
#define     icr1awi   INT32_ICR1A
#define     icr1adu  UINT64_ICR1A
#define     icr1adi   INT64_ICR1A
#if DWRD_NLONG == 2
#   define  icr1alu   ULONG_ICR1A
#   define  icr1ali    LONG_ICR1A
#elif QUAD_NLLONG == 2
#   define  icr1alu  ULLONG_ICR1A
#   define  icr1ali   LLONG_ICR1A
#else
#   define  icr1aqu  ULLONG_ICR1A
#   define  icr1aqi   LLONG_ICR1A
#endif

#if _LEAVE_ICR1
}
#endif

#if _ENTER_ICRA
{
#endif
/*  atomic_add_explicit(a, 1, memory_order_acquire)

Atomic version of "icrl" with C11 memory_order_acquire
semantics.
*/

#define     icra(...)  (icra_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     icra_funcof(A, ...) \
FUNCOF_AK(          \
    icra, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     icraayu    BOOL_ICRAA
#define     icraabu   UINT8_ICRAA
#define     icraabi    INT8_ICRAA
#define     icraabc    CHAR_ICRAA
#define     icraahu  UINT16_ICRAA
#define     icraahi   INT16_ICRAA
#define     icraawu  UINT32_ICRAA
#define     icraawi   INT32_ICRAA
#define     icraadu  UINT64_ICRAA
#define     icraadi   INT64_ICRAA
#if DWRD_NLONG == 2
#   define  icraalu   ULONG_ICRAA
#   define  icraali    LONG_ICRAA
#elif QUAD_NLLONG == 2
#   define  icraalu  ULLONG_ICRAA
#   define  icraali   LLONG_ICRAA
#else
#   define  icraaqu  ULLONG_ICRAA
#   define  icraaqi   LLONG_ICRAA
#endif

#if _LEAVE_ICRA
}
#endif

#if _ENTER_ICRE
{
#endif
/*  atomic_add_explicit(a, 1, memory_order_release)

Atomic version of "icrl" with C11 memory_order_release
semantics.
*/

#define     icre(...)  (icre_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     icre_funcof(A, ...) \
FUNCOF_AK(          \
    icre, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     icreayu    BOOL_ICREA
#define     icreabu   UINT8_ICREA
#define     icreabi    INT8_ICREA
#define     icreabc    CHAR_ICREA
#define     icreahu  UINT16_ICREA
#define     icreahi   INT16_ICREA
#define     icreawu  UINT32_ICREA
#define     icreawi   INT32_ICREA
#define     icreadu  UINT64_ICREA
#define     icreadi   INT64_ICREA
#if DWRD_NLONG == 2
#   define  icrealu   ULONG_ICREA
#   define  icreali    LONG_ICREA
#elif QUAD_NLLONG == 2
#   define  icrealu  ULLONG_ICREA
#   define  icreali   LLONG_ICREA
#else
#   define  icreaqu  ULLONG_ICREA
#   define  icreaqi   LLONG_ICREA
#endif

#if _LEAVE_ICRE
}
#endif

#if _ENTER_ICRT
{
#endif
/*  atomic_add_explicit(a, 1, memory_order_seq_cst)

Atomic version of "icrl" with C11 memory_order_seq_cst
semantics.
*/

#define     icrt(...)  (icrt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     icrt_funcof(A, ...) \
FUNCOF_AK(          \
    icrt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     icrtayu    BOOL_ICRTA
#define     icrtabu   UINT8_ICRTA
#define     icrtabi    INT8_ICRTA
#define     icrtabc    CHAR_ICRTA
#define     icrtahu  UINT16_ICRTA
#define     icrtahi   INT16_ICRTA
#define     icrtawu  UINT32_ICRTA
#define     icrtawi   INT32_ICRTA
#define     icrtadu  UINT64_ICRTA
#define     icrtadi   INT64_ICRTA
#if DWRD_NLONG == 2
#   define  icrtalu   ULONG_ICRTA
#   define  icrtali    LONG_ICRTA
#elif QUAD_NLLONG == 2
#   define  icrtalu  ULLONG_ICRTA
#   define  icrtali   LLONG_ICRTA
#else
#   define  icrtaqu  ULLONG_ICRTA
#   define  icrtaqi   LLONG_ICRTA
#endif

#if _LEAVE_ICRT
}
#endif


#if _ENTER_INVS
{
#endif
/*  Bitwise NOT
*/

#define     invs(X) (invs_funcof(X)(X))
#define     invs_funcof(X)  \
FUNCOF(             \
    invs, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     invsyu   BOOL_INVS
#define     invsbu  UINT8_INVS
#define     invsbi   INT8_INVS
#define     invsbc   CHAR_INVS
#define     invshu UINT16_INVS
#define     invshi  INT16_INVS
#define     invswu UINT32_INVS
#define     invswi  INT32_INVS
#define     invsdu UINT64_INVS
#define     invsdi  INT64_INVS
#if DWRD_NLONG == 2
#   define  invslu  ULONG_INVS
#   define  invsli   LONG_INVS
#elif QUAD_NLLONG == 2
#   define  invslu ULLONG_INVS
#   define  invsli  LLONG_INVS
#else
#   define  invsqu ULLONG_INVS
#   define  invsqi  LLONG_INVS
#endif

#define     invswyu     VWYU_INVS
#define     invswbu     VWBU_INVS
#define     invswbi     VWBI_INVS
#define     invswbc     VWBC_INVS
#define     invswhu     VWHU_INVS
#define     invswhi     VWHI_INVS
#define     invswwu     VWWU_INVS
#define     invswwi     VWWI_INVS

#define     invsdyu     VDYU_INVS
#define     invsdbu     VDBU_INVS
#define     invsdbi     VDBI_INVS
#define     invsdbc     VDBC_INVS
#define     invsdhu     VDHU_INVS
#define     invsdhi     VDHI_INVS
#define     invsdwu     VDWU_INVS
#define     invsdwi     VDWI_INVS
#define     invsddu     VDDU_INVS
#define     invsddi     VDDI_INVS

#define     invsqyu     VQYU_INVS
#define     invsqbu     VQBU_INVS
#define     invsqbi     VQBI_INVS
#define     invsqbc     VQBC_INVS
#define     invsqhu     VQHU_INVS
#define     invsqhi     VQHI_INVS
#define     invsqwu     VQWU_INVS
#define     invsqwi     VQWI_INVS
#define     invsqdu     VQDU_INVS
#define     invsqdi     VQDI_INVS
#if _LEAVE_INVS
}
#endif

#if _ENTER_INV1
{
#endif
/*  atomic_xor_explicit(a, -1, memory_order_relaxed)

Atomic version of "invs" with C11 memory_order_relaxed
semantics.
*/

#define     inv1(...)  (inv1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     inv1_funcof(A, ...) \
FUNCOF_AK(          \
    inv1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     inv1ayu    BOOL_INV1A
#define     inv1abu   UINT8_INV1A
#define     inv1abi    INT8_INV1A
#define     inv1abc    CHAR_INV1A
#define     inv1ahu  UINT16_INV1A
#define     inv1ahi   INT16_INV1A
#define     inv1awu  UINT32_INV1A
#define     inv1awi   INT32_INV1A
#define     inv1adu  UINT64_INV1A
#define     inv1adi   INT64_INV1A
#if DWRD_NLONG == 2
#   define  inv1alu   ULONG_INV1A
#   define  inv1ali    LONG_INV1A
#elif QUAD_NLLONG == 2
#   define  inv1alu  ULLONG_INV1A
#   define  inv1ali   LLONG_INV1A
#else
#   define  inv1aqu  ULLONG_INV1A
#   define  inv1aqi   LLONG_INV1A
#endif

#if _LEAVE_INV1
}
#endif

#if _ENTER_INVA
{
#endif
/*  atomic_xor_explicit(a, -1, memory_order_acquire)

Atomic version of "invs" with C11 memory_order_acquire
semantics.
*/

#define     inva(...)  (inva_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     inva_funcof(A, ...) \
FUNCOF_AK(          \
    inva, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     invaayu    BOOL_INVAA
#define     invaabu   UINT8_INVAA
#define     invaabi    INT8_INVAA
#define     invaabc    CHAR_INVAA
#define     invaahu  UINT16_INVAA
#define     invaahi   INT16_INVAA
#define     invaawu  UINT32_INVAA
#define     invaawi   INT32_INVAA
#define     invaadu  UINT64_INVAA
#define     invaadi   INT64_INVAA
#if DWRD_NLONG == 2
#   define  invaalu   ULONG_INVAA
#   define  invaali    LONG_INVAA
#elif QUAD_NLLONG == 2
#   define  invaalu  ULLONG_INVAA
#   define  invaali   LLONG_INVAA
#else
#   define  invaaqu  ULLONG_INVAA
#   define  invaaqi   LLONG_INVAA
#endif

#if _LEAVE_INVA
}
#endif

#if _ENTER_INVE
{
#endif
/*  atomic_xor_explicit(a, -1, memory_order_release)

Atomic version of "invs" with C11 memory_order_release
semantics.
*/

#define     inve(...)  (inve_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     inve_funcof(A, ...) \
FUNCOF_AK(          \
    inve, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     inveayu    BOOL_INVEA
#define     inveabu   UINT8_INVEA
#define     inveabi    INT8_INVEA
#define     inveabc    CHAR_INVEA
#define     inveahu  UINT16_INVEA
#define     inveahi   INT16_INVEA
#define     inveawu  UINT32_INVEA
#define     inveawi   INT32_INVEA
#define     inveadu  UINT64_INVEA
#define     inveadi   INT64_INVEA
#if DWRD_NLONG == 2
#   define  invealu   ULONG_INVEA
#   define  inveali    LONG_INVEA
#elif QUAD_NLLONG == 2
#   define  invealu  ULLONG_INVEA
#   define  inveali   LLONG_INVEA
#else
#   define  inveaqu  ULLONG_INVEA
#   define  inveaqi   LLONG_INVEA
#endif

#if _LEAVE_INVE
}
#endif

#if _ENTER_INVT
{
#endif
/*  atomic_xor_explicit(a, -1, memory_order_seq_cst)

Atomic version of "invs" with C11 memory_order_seq_cst
semantics.
*/

#define     invt(...)  (invt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     invt_funcof(A, ...) \
FUNCOF_AK(          \
    invt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     invtayu    BOOL_INVTA
#define     invtabu   UINT8_INVTA
#define     invtabi    INT8_INVTA
#define     invtabc    CHAR_INVTA
#define     invtahu  UINT16_INVTA
#define     invtahi   INT16_INVTA
#define     invtawu  UINT32_INVTA
#define     invtawi   INT32_INVTA
#define     invtadu  UINT64_INVTA
#define     invtadi   INT64_INVTA
#if DWRD_NLONG == 2
#   define  invtalu   ULONG_INVTA
#   define  invtali    LONG_INVTA
#elif QUAD_NLLONG == 2
#   define  invtalu  ULLONG_INVTA
#   define  invtali   LLONG_INVTA
#else
#   define  invtaqu  ULLONG_INVTA
#   define  invtaqi   LLONG_INVTA
#endif

#if _LEAVE_INVT
}
#endif


#if _ENTER_LDR1
{
#endif
/*  atomic_load_explicit(src, memory_order_relaxed

Atomically load a 1, 8, 16, 32, or 64 bit integer from a
properly aligned memory address.
*/

#define     ldr1(...) (ldr1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ldr1_funcof(A, ...) \
FUNCOF_AC(          \
    ldr1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ldr1acyu      BOOL_LDR1AC
#define     ldr1acbu     UINT8_LDR1AC
#define     ldr1acbi      INT8_LDR1AC
#define     ldr1acbc      CHAR_LDR1AC
#define     ldr1achu    UINT16_LDR1AC
#define     ldr1achi     INT16_LDR1AC
#define     ldr1acwu    UINT32_LDR1AC
#define     ldr1acwi     INT32_LDR1AC
#define     ldr1acdu    UINT64_LDR1AC
#define     ldr1acdi     INT64_LDR1AC
#if DWRD_NLONG == 2
#   define  ldr1aclu     ULONG_LDR1AC
#   define  ldr1acli      LONG_LDR1AC
#elif QUAD_NLLONG == 2
#   define  ldr1aclu    ULLONG_LDR1AC
#   define  ldr1acli     LLONG_LDR1AC
#endif

#if _LEAVE_LDR1
}
#endif

#if _ENTER_LDRA
{
#endif
/*  atomic_load_explicit(src, memory_order_acquire

Atomically load a 1, 8, 16, 32, or 64 bit integer from a
properly aligned memory address.
*/

#define     ldra(...) (ldra_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ldra_funcof(A, ...) \
FUNCOF_AC(          \
    ldra, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ldraacyu      BOOL_LDRAAC
#define     ldraacbu     UINT8_LDRAAC
#define     ldraacbi      INT8_LDRAAC
#define     ldraacbc      CHAR_LDRAAC
#define     ldraachu    UINT16_LDRAAC
#define     ldraachi     INT16_LDRAAC
#define     ldraacwu    UINT32_LDRAAC
#define     ldraacwi     INT32_LDRAAC
#define     ldraacdu    UINT64_LDRAAC
#define     ldraacdi     INT64_LDRAAC
#if DWRD_NLONG == 2
#   define  ldraaclu     ULONG_LDRAAC
#   define  ldraacli      LONG_LDRAAC
#elif QUAD_NLLONG == 2
#   define  ldraaclu    ULLONG_LDRAAC
#   define  ldraacli     LLONG_LDRAAC
#endif

#if _LEAVE_LDRA
}
#endif

#if _ENTER_LDRT
{
#endif
/*  atomic_load_explicit(src, memory_order_seq_cst */

#define     ldrt(...) (ldrt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     ldrt_funcof(A, ...) \
FUNCOF_AC(                  \
    ldrt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ldrtacyu      BOOL_LDRTAC
#define     ldrtacbu     UINT8_LDRTAC
#define     ldrtacbi      INT8_LDRTAC
#define     ldrtacbc      CHAR_LDRTAC
#define     ldrtachu    UINT16_LDRTAC
#define     ldrtachi     INT16_LDRTAC
#define     ldrtacwu    UINT32_LDRTAC
#define     ldrtacwi     INT32_LDRTAC
#define     ldrtacdu    UINT64_LDRTAC
#define     ldrtacdi     INT64_LDRTAC
#if DWRD_NLONG == 2
#   define  ldrtaclu     ULONG_LDRTAC
#   define  ldrtacli      LONG_LDRTAC
#elif QUAD_NLLONG == 2
#   define  ldrtaclu    ULLONG_LDRTAC
#   define  ldrtacli     LLONG_LDRTAC
#endif

#if _LEAVE_LDRT
}
#endif

#if _ENTER_LDRW
{
#endif
/*  LoaD Word (32 bit vector, 4 byte aligned)
*/

#define     ldrw(SRC)  (ldrw_funcof(SRC)(SRC))
#define     ldrw_funcof(X)  \
FUNCOF_AC(                  \
    ldrw, (   X  ),\
    NONE, /* TGK */ \
    BWR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ldrwacbu     UINT8_LDRWAC
#define     ldrwacbi      INT8_LDRWAC
#define     ldrwacbc      CHAR_LDRWAC
#define     ldrwachu    UINT16_LDRWAC
#define     ldrwachi     INT16_LDRWAC
#define     ldrwachf     FLT16_LDRWAC
#define     ldrwacwu    UINT32_LDRWAC
#define     ldrwacwi     INT32_LDRWAC
#define     ldrwacwf       FLT_LDRWAC
#if (DWRD_NLONG == 2)
#define     ldrwaclu     ULONG_LDRWAC
#define     ldrwacli      LONG_LDRWAC
#endif

#if _LEAVE_LDRW
}
#endif

#if _ENTER_LDRD
{
#endif
/*  LoaD Doubleword (64 bit vector, from 8 byte aligned)
*/

#define     ldrd(SRC)  (ldrd_funcof(SRC)(SRC))
#define     ldrd_funcof(X)  \
FUNCOF_AC(                  \
    ldrd, (   X  ),\
    NONE, /* TGK */ \
    BDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ldrdacbu     UINT8_LDRDAC
#define     ldrdacbi      INT8_LDRDAC
#define     ldrdacbc      CHAR_LDRDAC
#define     ldrdachu    UINT16_LDRDAC
#define     ldrdachi     INT16_LDRDAC
#define     ldrdachf     FLT16_LDRDAC
#define     ldrdacwu    UINT32_LDRDAC
#define     ldrdacwi     INT32_LDRDAC
#define     ldrdacwf       FLT_LDRDAC
#define     ldrdacdu    UINT64_LDRDAC
#define     ldrdacdi     INT64_LDRDAC
#define     ldrdacdf       DBL_LDRDAC
#if (DWRD_NLONG == 2)
#define     ldrdaclu     ULONG_LDRDAC
#define     ldrdacli      LONG_LDRDAC
#elif (QUAD_NLLONG == 2)
#define     ldrdaclu    ULLONG_LDRDAC
#define     ldrdacli     LLONG_LDRDAC
#endif

#if _LEAVE_LDRD
}
#endif

#if _ENTER_LDRQ
{
#endif
/*  LoaD Quadword (128 bit vector, from 16 byte aligned)
*/

#define     ldrq(SRC)  (ldrq_funcof(SRC)(SRC))
#define     ldrq_funcof(X)  \
FUNCOF_AC(                  \
    ldrq, (   X  ),\
    NONE, /* TGK */ \
    BDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ldrqacbu     UINT8_LDRQAC
#define     ldrqacbi      INT8_LDRQAC
#define     ldrqacbc      CHAR_LDRQAC
#define     ldrqachu    UINT16_LDRQAC
#define     ldrqachi     INT16_LDRQAC
#define     ldrqachf     FLT16_LDRQAC
#define     ldrqacwu    UINT32_LDRQAC
#define     ldrqacwi     INT32_LDRQAC
#define     ldrqacwf       FLT_LDRQAC
#define     ldrqacdu    UINT64_LDRQAC
#define     ldrqacdi     INT64_LDRQAC
#define     ldrqacdf       DBL_LDRQAC
#if (DWRD_NLONG == 2)
#define     ldrqaclu     ULONG_LDRQAC
#define     ldrqacli      LONG_LDRQAC
#elif (QUAD_NLLONG == 2)
#define     ldrqaclu    ULLONG_LDRQAC
#define     ldrqacli     LLONG_LDRQAC
#endif

#if _LEAVE_LDRQ
}
#endif


#if _ENTER_LUN1
{
#endif
/*  Load UNaligned (into 1 multilane vector lane)

Given a vector V, lane K, and packed data S, set V[K]=*S.

*/

#define     lun1(...)  (lun1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lun1_funcof(S, ...) \
FUNCOF(             \
    lun1, (   S   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lun1wyu VWYU_LUN1
#define     lun1wbu VWBU_LUN1
#define     lun1wbi VWBI_LUN1
#define     lun1wbc VWBC_LUN1
#define     lun1whu VWHU_LUN1
#define     lun1whi VWHI_LUN1
#define     lun1whf VWHF_LUN1

#define     lun1dyu VDYU_LUN1
#define     lun1dbu VDBU_LUN1
#define     lun1dbi VDBI_LUN1
#define     lun1dbc VDBC_LUN1
#define     lun1dhu VDHU_LUN1
#define     lun1dhi VDHI_LUN1
#define     lun1dhf VDHF_LUN1
#define     lun1dwu VDWU_LUN1
#define     lun1dwi VDWI_LUN1
#define     lun1dwf VDWF_LUN1

#define     lun1qyu VQYU_LUN1
#define     lun1qbu VQBU_LUN1
#define     lun1qbi VQBI_LUN1
#define     lun1qbc VQBC_LUN1
#define     lun1qhu VQHU_LUN1
#define     lun1qhi VQHI_LUN1
#define     lun1qhf VQHF_LUN1
#define     lun1qwu VQWU_LUN1
#define     lun1qwi VQWI_LUN1
#define     lun1qwf VQWF_LUN1
#define     lun1qdu VQDU_LUN1
#define     lun1qdi VQDI_LUN1
#define     lun1qdf VQDF_LUN1
#if _LEAVE_LUN1
}
#endif

#if _ENTER_LUNN
{
#endif
/*  Load UNaligned (native endian)

Load a contiguous sequence of bytes then interpret that
string as a value of the result type.
*/

#define     lunn(...) (lunn_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lunn_funcof(A, ...) \
FUNCOF_AC(          \
    lunn, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lunnacyu   BOOL_LUNNAC
#define     lunnacbu  UINT8_LUNNAC
#define     lunnacbi   INT8_LUNNAC
#define     lunnacbc   CHAR_LUNNAC
#define     lunnachu UINT16_LUNNAC
#define     lunnachi  INT16_LUNNAC
#define     lunnachf  FLT16_LUNNAC
#define     lunnacwu UINT32_LUNNAC
#define     lunnacwi  INT32_LUNNAC
#define     lunnacwf    FLT_LUNNAC
#define     lunnacdu UINT64_LUNNAC
#define     lunnacdi  INT64_LUNNAC
#define     lunnacdf    DBL_LUNNAC
#define     lunnacap   ADDR_LUNNAC
#if   DWRD_NLONG == 2
#   define  lunnaclu  ULONG_LUNNAC
#   define  lunnacli   LONG_LUNNAC
#elif QUAD_NLLONG == 2
#   define  lunnaclu ULLONG_LUNNAC
#   define  lunnacli  LLONG_LUNNAC
#else
#   define  lunnacqu ULLONG_LUNNAC
#   define  lunnacqi  LLONG_LUNNAC
#endif

#if _LEAVE_LUNN
}
#endif

#if _ENTER_LUNL
{
#endif
/*  Load UNaligned (lil endian)

Load a contiguous sequence of bytes, interpreting it as a
lil endian represented value.
*/

#define     lunl(...) (lunl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lunl_funcof(A, ...) \
FUNCOF_AC(          \
    lunl, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lunlacyu   BOOL_LUNLAC
#define     lunlacbu  UINT8_LUNLAC
#define     lunlacbi   INT8_LUNLAC
#define     lunlacbc   CHAR_LUNLAC
#define     lunlachu UINT16_LUNLAC
#define     lunlachi  INT16_LUNLAC
#define     lunlachf  FLT16_LUNLAC
#define     lunlacwu UINT32_LUNLAC
#define     lunlacwi  INT32_LUNLAC
#define     lunlacwf    FLT_LUNLAC
#define     lunlacdu UINT64_LUNLAC
#define     lunlacdi  INT64_LUNLAC
#define     lunlacdf    DBL_LUNLAC
#define     lunlacap   ADDR_LUNLAC
#if   DWRD_NLONG == 2
#   define  lunlaclu  ULONG_LUNLAC
#   define  lunlacli   LONG_LUNLAC
#elif QUAD_NLLONG == 2
#   define  lunlaclu ULLONG_LUNLAC
#   define  lunlacli  LLONG_LUNLAC
#else
#   define  lunlacqu ULLONG_LUNLAC
#   define  lunlacqi  LLONG_LUNLAC
#endif

#if _LEAVE_LUNL
}
#endif

#if _ENTER_LUNR
{
#endif
/*  Load UNaligned (big endian)

Load a contiguous sequence of bytes, interpreting it as a
big endian represented value.
*/

#define     lunr(...) (lunr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lunr_funcof(A, ...) \
FUNCOF_AC(          \
    lunr, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lunracyu   BOOL_LUNRAC
#define     lunracbu  UINT8_LUNRAC
#define     lunracbi   INT8_LUNRAC
#define     lunracbc   CHAR_LUNRAC
#define     lunrachu UINT16_LUNRAC
#define     lunrachi  INT16_LUNRAC
#define     lunrachf  FLT16_LUNRAC
#define     lunracwu UINT32_LUNRAC
#define     lunracwi  INT32_LUNRAC
#define     lunracwf    FLT_LUNRAC
#define     lunracdu UINT64_LUNRAC
#define     lunracdi  INT64_LUNRAC
#define     lunracdf    DBL_LUNRAC
#define     lunracap   ADDR_LUNRAC
#if   DWRD_NLONG == 2
#   define  lunraclu  ULONG_LUNRAC
#   define  lunracli   LONG_LUNRAC
#elif QUAD_NLLONG == 2
#   define  lunraclu ULLONG_LUNRAC
#   define  lunracli  LLONG_LUNRAC
#else
#   define  lunracqu ULLONG_LUNRAC
#   define  lunracqi  LLONG_LUNRAC
#endif

#if _LEAVE_LUNR
}
#endif

#if _ENTER_LUNW
{
#endif
/*  Load UNaligned Word vector (native endian) 
*/

#define     lunw(...) (lunw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lunw_funcof(A, ...) \
FUNCOF_AC(          \
    lunw, (   A   ),\
    NONE, /* TGK */ \
    YWR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lunwacyu   BOOL_LUNWAC
#define     lunwacbu  UINT8_LUNWAC
#define     lunwacbi   INT8_LUNWAC
#define     lunwacbc   CHAR_LUNWAC
#define     lunwachu UINT16_LUNWAC
#define     lunwachi  INT16_LUNWAC
#define     lunwachf  FLT16_LUNWAC
#define     lunwacwu UINT32_LUNWAC
#define     lunwacwi  INT32_LUNWAC
#define     lunwacwf    FLT_LUNWAC
#if   DWRD_NLONG == 2
#   define  lunwaclu  ULONG_LUNWAC
#   define  lunwacli   LONG_LUNWAC
#endif

#if _LEAVE_LUNW
}
#endif

#if _ENTER_LUND
{
#endif
/*  Load UNaligned Doubleword vector (native endian)
*/

#define     lund(...) (lund_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lund_funcof(A, ...) \
FUNCOF_AC(          \
    lund, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lundacyu   BOOL_LUNDAC
#define     lundacbu  UINT8_LUNDAC
#define     lundacbi   INT8_LUNDAC
#define     lundacbc   CHAR_LUNDAC
#define     lundachu UINT16_LUNDAC
#define     lundachi  INT16_LUNDAC
#define     lundachf  FLT16_LUNDAC
#define     lundacwu UINT32_LUNDAC
#define     lundacwi  INT32_LUNDAC
#define     lundacwf    FLT_LUNDAC
#define     lundacdu UINT64_LUNDAC
#define     lundacdi  INT64_LUNDAC
#define     lundacdf    DBL_LUNDAC
#if   DWRD_NLONG == 2
#   define  lundaclu  ULONG_LUNDAC
#   define  lundacli   LONG_LUNDAC
#elif QUAD_NLLONG == 2
#   define  lundaclu ULLONG_LUNDAC
#   define  lundacli  LLONG_LUNDAC
#else
#   define  lundacqu ULLONG_LUNDAC
#   define  lundacqi  LLONG_LUNDAC
#endif

#if _LEAVE_LUND
}
#endif

#if _ENTER_LUNQ
{
#endif
/*  Load UNaligned (nat endian Quadword vector)
*/

#define     lunq(...) (lunq_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     lunq_funcof(A, ...) \
FUNCOF_AC(          \
    lunq, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     lunqacyu   BOOL_LUNQAC
#define     lunqacbu  UINT8_LUNQAC
#define     lunqacbi   INT8_LUNQAC
#define     lunqacbc   CHAR_LUNQAC
#define     lunqachu UINT16_LUNQAC
#define     lunqachi  INT16_LUNQAC
#define     lunqachf  FLT16_LUNQAC
#define     lunqacwu UINT32_LUNQAC
#define     lunqacwi  INT32_LUNQAC
#define     lunqacwf    FLT_LUNQAC
#define     lunqacdu UINT64_LUNQAC
#define     lunqacdi  INT64_LUNQAC
#define     lunqacdf    DBL_LUNQAC
#define     lunqacap   ADDR_LUNQAC
#if   DWRD_NLONG == 2
#   define  lunqaclu  ULONG_LUNQAC
#   define  lunqacli   LONG_LUNQAC
#elif QUAD_NLLONG == 2
#   define  lunqaclu ULLONG_LUNQAC
#   define  lunqacli  LLONG_LUNQAC
#else
#   define  lunqacqu ULLONG_LUNQAC
#   define  lunqacqi  LLONG_LUNQAC
#endif

#if _LEAVE_LUNQ
}
#endif


#if _ENTER_MAXL
{
#endif
/*  MAXimum (first operand likely)

For each pair of corresponding elements in both operands,
determine the numerical maximum. If the order of operands
affects performance, users should be able to benefit from
ensuring the first operand is most likely to be greater
than the second.
*/

#define     maxl(...) (maxl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     maxl_funcof(A, ...)  \
FUNCOF(             \
    maxl, (   A   ),\
    YDR,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     maxlyu    BOOL_MAXL
#define     maxlbu   UINT8_MAXL
#define     maxlbi    INT8_MAXL
#define     maxlbc    CHAR_MAXL
#define     maxlhu  UINT16_MAXL
#define     maxlhi   INT16_MAXL
#define     maxlhf   FLT16_MAXL
#define     maxlwu  UINT32_MAXL
#define     maxlwi   INT32_MAXL
#define     maxlwf     FLT_MAXL
#define     maxldu  UINT64_MAXL
#define     maxldi   INT64_MAXL
#define     maxldf     DBL_MAXL
#if   DWRD_NLONG == 2
#   define  maxllu   ULONG_MAXL
#   define  maxlli    LONG_MAXL
#elif QUAD_NLLONG == 2
#   define  maxllu  ULLONG_MAXL
#   define  maxlli   LLONG_MAXL
#else
#   define  maxlqu  ULLONG_MAXL
#   define  maxlqi   LLONG_MAXL
#endif

#define     maxlwyu   VWYU_MAXL
#define     maxlwbu   VWBU_MAXL
#define     maxlwbi   VWBI_MAXL
#define     maxlwbc   VWBC_MAXL
#define     maxlwhu   VWHU_MAXL
#define     maxlwhi   VWHI_MAXL
#define     maxlwhf   VWHF_MAXL
#define     maxlwwu   VWWU_MAXL
#define     maxlwwi   VWWI_MAXL
#define     maxlwwf   VWWF_MAXL

#define     maxldyu   VDYU_MAXL
#define     maxldbu   VDBU_MAXL
#define     maxldbi   VDBI_MAXL
#define     maxldbc   VDBC_MAXL
#define     maxldhu   VDHU_MAXL
#define     maxldhi   VDHI_MAXL
#define     maxldhf   VDHF_MAXL
#define     maxldwu   VDWU_MAXL
#define     maxldwi   VDWI_MAXL
#define     maxldwf   VDWF_MAXL
#define     maxlddu   VDDU_MAXL
#define     maxlddi   VDDI_MAXL
#define     maxlddf   VDDF_MAXL

#define     maxlqyu   VQYU_MAXL
#define     maxlqbu   VQBU_MAXL
#define     maxlqbi   VQBI_MAXL
#define     maxlqbc   VQBC_MAXL
#define     maxlqhu   VQHU_MAXL
#define     maxlqhi   VQHI_MAXL
#define     maxlqhf   VQHF_MAXL
#define     maxlqwu   VQWU_MAXL
#define     maxlqwi   VQWI_MAXL
#define     maxlqwf   VQWF_MAXL
#define     maxlqdu   VQDU_MAXL
#define     maxlqdi   VQDI_MAXL
#define     maxlqdf   VQDF_MAXL
#if _LEAVE_MAXL
}
#endif

#if _ENTER_MAXV
{
#endif
/*  MAXimum (across vector) */

#define     maxv(...) (maxv_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     maxv_funcof(A)  \
FUNCOF(             \
    maxv, (   A   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     maxvwyu   VWYU_MAXV
#define     maxvwbu   VWBU_MAXV
#define     maxvwbi   VWBI_MAXV
#define     maxvwbc   VWBC_MAXV
#define     maxvwhu   VWHU_MAXV
#define     maxvwhi   VWHI_MAXV
#define     maxvwhf   VWHF_MAXV

#define     maxvdyu   VDYU_MAXV
#define     maxvdbu   VDBU_MAXV
#define     maxvdbi   VDBI_MAXV
#define     maxvdbc   VDBC_MAXV
#define     maxvdhu   VDHU_MAXV
#define     maxvdhi   VDHI_MAXV
#define     maxvdhf   VDHF_MAXV
#define     maxvdwu   VDWU_MAXV
#define     maxvdwi   VDWI_MAXV
#define     maxvdwf   VDWF_MAXV

#define     maxvqyu   VQYU_MAXV
#define     maxvqbu   VQBU_MAXV
#define     maxvqbi   VQBI_MAXV
#define     maxvqbc   VQBC_MAXV
#define     maxvqhu   VQHU_MAXV
#define     maxvqhi   VQHI_MAXV
#define     maxvqhf   VQHF_MAXV
#define     maxvqwu   VQWU_MAXV
#define     maxvqwi   VQWI_MAXV
#define     maxvqwf   VQWF_MAXV
#define     maxvqdu   VQDU_MAXV
#define     maxvqdi   VQDI_MAXV
#define     maxvqdf   VQDF_MAXV
#if _LEAVE_MAXV
}
#endif


#if _ENTER_MINL
{
#endif
/*  MINimum (first operand likely)

For each pair of corresponding elements in both operands,
determine the numerical minimum. If the order of operands
affects performance, users should be able to benefit from
ensuring the first operand is most likely to be less than
the second.
*/

#define     minl(...) (minl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     minl_funcof(A, ...)  \
FUNCOF(             \
    minl, (   A   ),\
    YDR,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     minlyu    BOOL_MINL
#define     minlbu   UINT8_MINL
#define     minlbi    INT8_MINL
#define     minlbc    CHAR_MINL
#define     minlhu  UINT16_MINL
#define     minlhi   INT16_MINL
#define     minlhf   FLT16_MINL
#define     minlwu  UINT32_MINL
#define     minlwi   INT32_MINL
#define     minlwf     FLT_MINL
#define     minldu  UINT64_MINL
#define     minldi   INT64_MINL
#define     minldf     DBL_MINL
#if   DWRD_NLONG == 2
#   define  minllu   ULONG_MINL
#   define  minlli    LONG_MINL
#elif QUAD_NLLONG == 2
#   define  minllu  ULLONG_MINL
#   define  minlli   LLONG_MINL
#else
#   define  minlqu  ULLONG_MINL
#   define  minlqi   LLONG_MINL
#endif

#define     minlwyu   VWYU_MINL
#define     minlwbu   VWBU_MINL
#define     minlwbi   VWBI_MINL
#define     minlwbc   VWBC_MINL
#define     minlwhu   VWHU_MINL
#define     minlwhi   VWHI_MINL
#define     minlwhf   VWHF_MINL
#define     minlwwu   VWWU_MINL
#define     minlwwi   VWWI_MINL
#define     minlwwf   VWWF_MINL

#define     minldyu   VDYU_MINL
#define     minldbu   VDBU_MINL
#define     minldbi   VDBI_MINL
#define     minldbc   VDBC_MINL
#define     minldhu   VDHU_MINL
#define     minldhi   VDHI_MINL
#define     minldhf   VDHF_MINL
#define     minldwu   VDWU_MINL
#define     minldwi   VDWI_MINL
#define     minldwf   VDWF_MINL
#define     minlddu   VDDU_MINL
#define     minlddi   VDDI_MINL
#define     minlddf   VDDF_MINL

#define     minlqyu   VQYU_MINL
#define     minlqbu   VQBU_MINL
#define     minlqbi   VQBI_MINL
#define     minlqbc   VQBC_MINL
#define     minlqhu   VQHU_MINL
#define     minlqhi   VQHI_MINL
#define     minlqhf   VQHF_MINL
#define     minlqwu   VQWU_MINL
#define     minlqwi   VQWI_MINL
#define     minlqwf   VQWF_MINL
#define     minlqdu   VQDU_MINL
#define     minlqdi   VQDI_MINL
#define     minlqdf   VQDF_MINL
#if _LEAVE_MINL
}
#endif

#if _ENTER_MINV
{
#endif
/*  MINimum (across vector)

TODO: consider splitting minv/maxv into a separate op with
variants that return the first lane containing the min/max
and possibly one that returns an equivalent size vector
with the min/max in lane 0 and the index in lane 1.
*/

#define     minv(...) (minv_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     minv_funcof(A)  \
FUNCOF(             \
    minv, (   A   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     minvwyu   VWYU_MINV
#define     minvwbu   VWBU_MINV
#define     minvwbi   VWBI_MINV
#define     minvwbc   VWBC_MINV
#define     minvwhu   VWHU_MINV
#define     minvwhi   VWHI_MINV
#define     minvwhf   VWHF_MINV

#define     minvdyu   VDYU_MINV
#define     minvdbu   VDBU_MINV
#define     minvdbi   VDBI_MINV
#define     minvdbc   VDBC_MINV
#define     minvdhu   VDHU_MINV
#define     minvdhi   VDHI_MINV
#define     minvdhf   VDHF_MINV
#define     minvdwu   VDWU_MINV
#define     minvdwi   VDWI_MINV
#define     minvdwf   VDWF_MINV

#define     minvqyu   VQYU_MINV
#define     minvqbu   VQBU_MINV
#define     minvqbi   VQBI_MINV
#define     minvqbc   VQBC_MINV
#define     minvqhu   VQHU_MINV
#define     minvqhi   VQHI_MINV
#define     minvqhf   VQHF_MINV
#define     minvqwu   VQWU_MINV
#define     minvqwi   VQWI_MINV
#define     minvqwf   VQWF_MINV
#define     minvqdu   VQDU_MINV
#define     minvqdi   VQDI_MINV
#define     minvqdf   VQDF_MINV
#if _LEAVE_MINV
}
#endif


#if _ENTER_MODL
{
#endif

#define     modl(...) (modl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     modl_funcof(A, ...)  \
FUNCOF(             \
    modl, (   A   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     modlbu   UINT8_MODL
#define     modlbi    INT8_MODL
#define     modlbc    CHAR_MODL
#define     modlhu  UINT16_MODL
#define     modlhi   INT16_MODL
#define     modlwu  UINT32_MODL
#define     modlwi   INT32_MODL
#define     modldu  UINT64_MODL
#define     modldi   INT64_MODL
#if   DWRD_NLONG == 2
#   define  modllu   ULONG_MODL
#   define  modlli    LONG_MODL
#elif QUAD_NLLONG == 2
#   define  modllu  ULLONG_MODL
#   define  modlli   LLONG_MODL
#else
#   define  modlqu  ULLONG_MODL
#   define  modlqi   LLONG_MODL
#endif

#define     modlwbu   VWBU_MODL
#define     modlwbi   VWBI_MODL
#define     modlwbc   VWBC_MODL
#define     modlwhu   VWHU_MODL
#define     modlwhi   VWHI_MODL
#define     modlwwu   VWWU_MODL
#define     modlwwi   VWWI_MODL

#define     modldyu   VDYU_MODL
#define     modldbu   VDBU_MODL
#define     modldbi   VDBI_MODL
#define     modldbc   VDBC_MODL
#define     modldhu   VDHU_MODL
#define     modldhi   VDHI_MODL
#define     modldwu   VDWU_MODL
#define     modldwi   VDWI_MODL
#define     modlddu   VDDU_MODL
#define     modlddi   VDDI_MODL

#define     modlqyu   VQYU_MODL
#define     modlqbu   VQBU_MODL
#define     modlqbi   VQBI_MODL
#define     modlqbc   VQBC_MODL
#define     modlqhu   VQHU_MODL
#define     modlqhi   VQHI_MODL
#define     modlqwu   VQWU_MODL
#define     modlqwi   VQWI_MODL
#define     modlqdu   VQDU_MODL
#define     modlqdi   VQDI_MODL
#if _LEAVE_MODL
}
#endif

#if _ENTER_MOD2
{
#endif
/*  MODulus (wide divisor)
*/

#define     mod2(...) (mod2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     mod2_funcof(A, ...)  \
FUNCOF(             \
    mod2,   (   A   ),  \
    HDZ,  /* TGK */ \
    NONE, /* TGW */ \
    HDZ,  /* TGD */ \
    HDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     mod2hu  UINT16_MOD2
#define     mod2hi   INT16_MOD2
#define     mod2wu  UINT32_MOD2
#define     mod2wi   INT32_MOD2
#define     mod2du  UINT64_MOD2
#define     mod2di   INT64_MOD2
#if   DWRD_NLONG == 2
#   define  mod2lu   ULONG_MOD2
#   define  mod2li    LONG_MOD2
#elif QUAD_NLLONG == 2
#   define  mod2lu  ULLONG_MOD2
#   define  mod2li   LLONG_MOD2
#else
#   define  mod2qu  ULLONG_MOD2
#   define  mod2qi   LLONG_MOD2
#endif

#define     mod2dhu   VDHU_MOD2
#define     mod2dhi   VDHI_MOD2
#define     mod2dwu   VDWU_MOD2
#define     mod2dwi   VDWI_MOD2
#define     mod2ddu   VDDU_MOD2
#define     mod2ddi   VDDI_MOD2

#define     mod2qhu   VQHU_MOD2
#define     mod2qhi   VQHI_MOD2
#define     mod2qwu   VQWU_MOD2
#define     mod2qwi   VQWI_MOD2
#define     mod2qdu   VQDU_MOD2
#define     mod2qdi   VQDI_MOD2
#if _LEAVE_MOD2
}
#endif


#if _ENTER_MULL
{
#endif
/*  MULtiply (truncated)

Multiply each N bit integer in the first operand by the
corresponding N bit integer of the second operand, keeping
the least significant N bits of each product.
*/

#define     mull(...) (mull_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     mull_funcof(A, ...)  \
FUNCOF(             \
    mull, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     mullyu    BOOL_MULL
#define     mullbu   UINT8_MULL
#define     mullbi    INT8_MULL
#define     mullbc    CHAR_MULL
#define     mullhu  UINT16_MULL
#define     mullhi   INT16_MULL
#define     mullwu  UINT32_MULL
#define     mullwi   INT32_MULL
#define     mulldu  UINT64_MULL
#define     mulldi   INT64_MULL
#if   DWRD_NLONG == 2
#   define  mulllu   ULONG_MULL
#   define  mullli    LONG_MULL
#elif QUAD_NLLONG == 2
#   define  mulllu  ULLONG_MULL
#   define  mullli   LLONG_MULL
#else
#   define  mullqu  ULLONG_MULL
#   define  mullqi   LLONG_MULL
#endif

#define     mullwyu   VWYU_MULL
#define     mullwbu   VWBU_MULL
#define     mullwbi   VWBI_MULL
#define     mullwbc   VWBC_MULL
#define     mullwhu   VWHU_MULL
#define     mullwhi   VWHI_MULL
#define     mullwwu   VWWU_MULL
#define     mullwwi   VWWI_MULL

#define     mulldyu   VDYU_MULL
#define     mulldbu   VDBU_MULL
#define     mulldbi   VDBI_MULL
#define     mulldbc   VDBC_MULL
#define     mulldhu   VDHU_MULL
#define     mulldhi   VDHI_MULL
#define     mulldwu   VDWU_MULL
#define     mulldwi   VDWI_MULL
#define     mullddu   VDDU_MULL
#define     mullddi   VDDI_MULL

#define     mullqyu   VQYU_MULL
#define     mullqbu   VQBU_MULL
#define     mullqbi   VQBI_MULL
#define     mullqbc   VQBC_MULL
#define     mullqhu   VQHU_MULL
#define     mullqhi   VQHI_MULL
#define     mullqwu   VQWU_MULL
#define     mullqwi   VQWI_MULL
#define     mullqdu   VQDU_MULL
#define     mullqdi   VQDI_MULL
#if _LEAVE_MULL
}
#endif

#if _ENTER_MUL2
{
#endif
/*  MULtiply (widened×2)

Multiply each N bit integer in the first operand by the
corresponding N bit integer of the second operand. The
result's element width is 2N.
*/

#define     mul2(...) (mul2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     mul2_funcof(A, ...)  \
FUNCOF(             \
    mul2,   (   A   ),  \
    BWZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BWZ,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     mul2bu   UINT8_MUL2
#define     mul2bi    INT8_MUL2
#define     mul2bc    CHAR_MUL2
#define     mul2hu  UINT16_MUL2
#define     mul2hi   INT16_MUL2
#define     mul2wu  UINT32_MUL2
#define     mul2wi   INT32_MUL2
#define     mul2du  UINT64_MUL2
#define     mul2di   INT64_MUL2
#if   DWRD_NLONG == 2
#   define  mul2lu   ULONG_MUL2
#   define  mul2li    LONG_MUL2
#elif QUAD_NLLONG == 2
#   define  mul2lu  ULLONG_MUL2
#   define  mul2li   LLONG_MUL2
#else
#   define  mul2qu  ULLONG_MUL2
#   define  mul2qi   LLONG_MUL2
#endif

#define     mul2wyu   VWYU_MUL2
#define     mul2wbu   VWBU_MUL2
#define     mul2wbi   VWBI_MUL2
#define     mul2wbc   VWBC_MUL2
#define     mul2whu   VWHU_MUL2
#define     mul2whi   VWHI_MUL2
#define     mul2wwu   VWWU_MUL2
#define     mul2wwi   VWWI_MUL2

#define     mul2dbu   VDBU_MUL2
#define     mul2dbi   VDBI_MUL2
#define     mul2dbc   VDBC_MUL2
#define     mul2dhu   VDHU_MUL2
#define     mul2dhi   VDHI_MUL2
#define     mul2dwu   VDWU_MUL2
#define     mul2dwi   VDWI_MUL2
#define     mul2ddu   VDDU_MUL2
#define     mul2ddi   VDDI_MUL2

#if _LEAVE_MUL2
}
#endif

#if _ENTER_MULS
{
#endif
/*  MULtiply (saturated)

Multiply each N bit integer in the first operand by the
corresponding N bit integer of the second operand. The result
is clamped to the maximum or minimum representable by N bits.
*/

#define     muls(...) (muls_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     muls_funcof(A, ...)  \
FUNCOF(             \
    muls, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     mulsyu    BOOL_MULS
#define     mulsbu   UINT8_MULS
#define     mulsbi    INT8_MULS
#define     mulsbc    CHAR_MULS
#define     mulshu  UINT16_MULS
#define     mulshi   INT16_MULS
#define     mulswu  UINT32_MULS
#define     mulswi   INT32_MULS
#define     mulsdu  UINT64_MULS
#define     mulsdi   INT64_MULS
#if   DWRD_NLONG == 2
#   define  mulslu   ULONG_MULS
#   define  mulsli    LONG_MULS
#elif QUAD_NLLONG == 2
#   define  mulslu  ULLONG_MULS
#   define  mulsli   LLONG_MULS
#else
#   define  mulsqu  ULLONG_MULS
#   define  mulsqi   LLONG_MULS
#endif

#define     mulswyu   VWYU_MULS
#define     mulswbu   VWBU_MULS
#define     mulswbi   VWBI_MULS
#define     mulswbc   VWBC_MULS
#define     mulswhu   VWHU_MULS
#define     mulswhi   VWHI_MULS
#define     mulswwu   VWWU_MULS
#define     mulswwi   VWWI_MULS

#define     mulsdyu   VDYU_MULS
#define     mulsdbu   VDBU_MULS
#define     mulsdbi   VDBI_MULS
#define     mulsdbc   VDBC_MULS
#define     mulsdhu   VDHU_MULS
#define     mulsdhi   VDHI_MULS
#define     mulsdwu   VDWU_MULS
#define     mulsdwi   VDWI_MULS
#define     mulsddu   VDDU_MULS
#define     mulsddi   VDDI_MULS

#define     mulsqyu   VQYU_MULS
#define     mulsqbu   VQBU_MULS
#define     mulsqbi   VQBI_MULS
#define     mulsqbc   VQBC_MULS
#define     mulsqhu   VQHU_MULS
#define     mulsqhi   VQHI_MULS
#define     mulsqwu   VQWU_MULS
#define     mulsqwi   VQWI_MULS
#define     mulsqdu   VQDU_MULS
#define     mulsqdi   VQDI_MULS
#if _LEAVE_MULS
}
#endif

#if _ENTER_MULH
{
#endif
/*  MUL (flt16_t)

For each number N in the first operand and each flt16_t
element H in the second operand, compute N×H, with the same
element type as the effective type of the corresponding C
expression. E.g. for all integer types' operations, the
result's element type will be flt16_t. If the first operand's
element type has a higher rank, e.g. float or double, it is
the result's element type.
*/

#define     mulh(...) (mulh_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     mulh_funcof(A, ...)  \
FUNCOF(             \
    mulh, (   A   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     mulhyu    BOOL_MULH
#define     mulhbu   UINT8_MULH
#define     mulhbi    INT8_MULH
#define     mulhbc    CHAR_MULH
#define     mulhhu  UINT16_MULH
#define     mulhhi   INT16_MULH
#define     mulhhf   FLT16_MULH
#define     mulhwu  UINT32_MULH
#define     mulhwi   INT32_MULH
#define     mulhwf     FLT_MULH
#define     mulhdu  UINT64_MULH
#define     mulhdi   INT64_MULH
#define     mulhdf     DBL_MULH
#if   DWRD_NLONG == 2
#   define  mulhlu   ULONG_MULH
#   define  mulhli    LONG_MULH
#elif QUAD_NLLONG == 2
#   define  mulhlu  ULLONG_MULH
#   define  mulhli   LLONG_MULH
#else
#   define  mulhqu  ULLONG_MULH
#   define  mulhqi   LLONG_MULH
#   define  mulhqf    LDBL_MULH
#endif

#define     mulhwbu   VWBU_MULH
#define     mulhwbi   VWBI_MULH
#define     mulhwbc   VWBC_MULH
#define     mulhwhu   VWHU_MULH
#define     mulhwhi   VWHI_MULH
#define     mulhwhf   VWHF_MULH

#define     mulhdbu   VDBU_MULH
#define     mulhdbi   VDBI_MULH
#define     mulhdbc   VDBC_MULH
#define     mulhdhu   VDHU_MULH
#define     mulhdhi   VDHI_MULH
#define     mulhdhf   VDHF_MULH
#define     mulhdwu   VDWU_MULH
#define     mulhdwi   VDWI_MULH
#define     mulhdwf   VDWF_MULH

#define     mulhqhu   VQHU_MULH
#define     mulhqhi   VQHI_MULH
#define     mulhqhf   VQHF_MULH
#define     mulhqwu   VQWU_MULH
#define     mulhqwi   VQWI_MULH
#define     mulhqwf   VQWF_MULH
#define     mulhqdu   VQDU_MULH
#define     mulhqdi   VQDI_MULH
#define     mulhqdf   VQDF_MULH
#if _LEAVE_MULH
}
#endif

#if _ENTER_MULW
{
#endif
/*  MULtiply (float)

For each number N in the first operand and each float
element W in the second operand, compute N*W. The result's
element type is identical to the effective type of the
corresponding C expression 'N*W'.

If the result is too large for a float to represent, the
result is implementation defined.
*/

#define     mulw(...) (mulw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     mulw_funcof(A, ...)  \
FUNCOF(             \
    mulw, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     mulwyu    BOOL_MULW
#define     mulwbu   UINT8_MULW
#define     mulwbi    INT8_MULW
#define     mulwbc    CHAR_MULW
#define     mulwhu  UINT16_MULW
#define     mulwhi   INT16_MULW
#define     mulwhf   FLT16_MULW
#define     mulwwu  UINT32_MULW
#define     mulwwi   INT32_MULW
#define     mulwwf     FLT_MULW
#define     mulwdu  UINT64_MULW
#define     mulwdi   INT64_MULW
#define     mulwdf     DBL_MULW
#if   DWRD_NLONG == 2
#   define  mulwlu   ULONG_MULW
#   define  mulwli    LONG_MULW
#elif QUAD_NLLONG == 2
#   define  mulwlu  ULLONG_MULW
#   define  mulwli   LLONG_MULW
#else
#   define  mulwqu  ULLONG_MULW
#   define  mulwqi   LLONG_MULW
#   define  mulwqf    LDBL_MULW
#endif

#define     mulwwbu   VWBU_MULW
#define     mulwwbi   VWBI_MULW
#define     mulwwbc   VWBC_MULW
#define     mulwwhu   VWHU_MULW
#define     mulwwhi   VWHI_MULW
#define     mulwwhf   VWHF_MULW
#define     mulwwwu   VWWU_MULW
#define     mulwwwi   VWWI_MULW
#define     mulwwwf   VWWF_MULW

#define     mulwdhu   VDHU_MULW
#define     mulwdhi   VDHI_MULW
#define     mulwdhf   VDHF_MULW
#define     mulwdwu   VDWU_MULW
#define     mulwdwi   VDWI_MULW
#define     mulwdwf   VDWF_MULW
#define     mulwddu   VDDU_MULW
#define     mulwddi   VDDI_MULW
#define     mulwddf   VDDF_MULW

#define     mulwqwu   VQWU_MULW
#define     mulwqwi   VQWI_MULW
#define     mulwqwf   VQWF_MULW
#define     mulwqdu   VQDU_MULW
#define     mulwqdi   VQDI_MULW
#define     mulwqdf   VQDF_MULW
#if _LEAVE_MULW
}
#endif

#if _ENTER_MULD
{
#endif
/*  MULtiply (double)

For each number N in the first operand and each float
element D in the second operand, compute N*D. The result's
element type is identical to the effective type of the
corresponding C expression 'N*D'.

If the result is too large for a double to represent, the
result is implementation defined.
*/

#define     muld(...) (muld_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     muld_funcof(A, ...)  \
FUNCOF(             \
    muld, (   A   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     muldyu    BOOL_MULD
#define     muldbu   UINT8_MULD
#define     muldbi    INT8_MULD
#define     muldbc    CHAR_MULD
#define     muldhu  UINT16_MULD
#define     muldhi   INT16_MULD
#define     muldhf   FLT16_MULD
#define     muldwu  UINT32_MULD
#define     muldwi   INT32_MULD
#define     muldwf     FLT_MULD
#define     mulddu  UINT64_MULD
#define     mulddi   INT64_MULD
#define     mulddf     DBL_MULD
#if   DWRD_NLONG == 2
#   define  muldlu   ULONG_MULD
#   define  muldli    LONG_MULD
#elif QUAD_NLLONG == 2
#   define  muldlu  ULLONG_MULD
#   define  muldli   LLONG_MULD
#else
#   define  muldqu  ULLONG_MULD
#   define  muldqi   LLONG_MULD
#   define  muldqf    LDBL_MULD
#endif

#define     muldwhu   VWHU_MULD
#define     muldwhi   VWHI_MULD
#define     muldwhf   VWHF_MULD
#define     muldwwu   VWWU_MULD
#define     muldwwi   VWWI_MULD
#define     muldwwf   VWWF_MULD

#define     mulddwu   VDWU_MULD
#define     mulddwi   VDWI_MULD
#define     mulddwf   VDWF_MULD
#define     muldddu   VDDU_MULD
#define     muldddi   VDDI_MULD
#define     muldddf   VDDF_MULD

#define     muldqdu   VQDU_MULD
#define     muldqdi   VQDI_MULD
#define     muldqdf   VQDF_MULD
#if _LEAVE_MULD
}
#endif


#if _ENTER_NEGL
{
#endif
/*  NEGation (truncated)
*/

#define     negl(X) (negl_funcof(X)(X))
#define     negl_funcof(X)  \
FUNCOF(             \
    negl, (   X   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     neglbu   UINT8_NEGL
#define     neglbi    INT8_NEGL
#define     neglbc    CHAR_NEGL
#define     neglhu  UINT16_NEGL
#define     neglhi   INT16_NEGL
#define     neglhf   FLT16_NEGL
#define     neglwu  UINT32_NEGL
#define     neglwi   INT32_NEGL
#define     neglwf     FLT_NEGL
#define     negldu  UINT64_NEGL
#define     negldi   INT64_NEGL
#define     negldf     DBL_NEGL
#if DWRD_NLONG == 2
#   define  negllu   ULONG_NEGL
#   define  neglli    LONG_NEGL
#elif QUAD_NLLONG == 2
#   define  negllu  ULLONG_NEGL
#   define  neglli   LLONG_NEGL
#else
#   define  neglqu  ULLONG_NEGL
#   define  neglqi   LLONG_NEGL
#   define  neglqf    LDBL_NEGL
#endif

#define     neglwbu   VWBU_NEGL
#define     neglwbi   VWBI_NEGL
#define     neglwbc   VWBC_NEGL
#define     neglwhu   VWHU_NEGL
#define     neglwhi   VWHI_NEGL
#define     neglwhf   VWHF_NEGL
#define     neglwwu   VWWU_NEGL
#define     neglwwi   VWWI_NEGL
#define     neglwwf   VWWF_NEGL

#define     negldbu   VDBU_NEGL
#define     negldbi   VDBI_NEGL
#define     negldbc   VDBC_NEGL
#define     negldhu   VDHU_NEGL
#define     negldhi   VDHI_NEGL
#define     negldwu   VDWU_NEGL
#define     negldwi   VDWI_NEGL
#define     neglddu   VDDU_NEGL
#define     neglddi   VDDI_NEGL

#define     neglqbu   VQBU_NEGL
#define     neglqbi   VQBI_NEGL
#define     neglqbc   VQBC_NEGL
#define     neglqhu   VQHU_NEGL
#define     neglqhi   VQHI_NEGL
#define     neglqwu   VQWU_NEGL
#define     neglqwi   VQWI_NEGL
#define     neglqdu   VQDU_NEGL
#define     neglqdi   VQDI_NEGL
#if _LEAVE_NEGL
}
#endif

#if _ENTER_NEGS
{
#endif
/*  NEGation (saturated)
*/

#define     negs(X) (negs_funcof(X)(X))
#define     negs_funcof(X)  \
FUNCOF(             \
    negs, (   X   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     negsyu    BOOL_NEGS
#define     negsbu   UINT8_NEGS
#define     negsbi    INT8_NEGS
#define     negsbc    CHAR_NEGS
#define     negshu  UINT16_NEGS
#define     negshi   INT16_NEGS
#define     negswu  UINT32_NEGS
#define     negswi   INT32_NEGS
#define     negsdu  UINT64_NEGS
#define     negsdi   INT64_NEGS
#if DWRD_NLONG == 2
#   define  negslu  ULONG_NEGS
#   define  negsli   LONG_NEGS
#elif QUAD_NLLONG == 2
#   define  negslu ULLONG_NEGS
#   define  negsli  LLONG_NEGS
#else
#   define  negsqu ULLONG_NEGS
#   define  negsqi  LLONG_NEGS
#endif

#define     negswyu  VWYU_NEGS
#define     negswbu  VWBU_NEGS
#define     negswbi  VWBI_NEGS
#define     negswbc  VWBC_NEGS
#define     negswhu  VWHU_NEGS
#define     negswhi  VWHI_NEGS
#define     negswwu  VWWU_NEGS
#define     negswwi  VWWI_NEGS

#define     negsdyu  VDYU_NEGS
#define     negsdbu  VDBU_NEGS
#define     negsdbi  VDBI_NEGS
#define     negsdbc  VDBC_NEGS
#define     negsdhu  VDHU_NEGS
#define     negsdhi  VDHI_NEGS
#define     negsdwu  VDWU_NEGS
#define     negsdwi  VDWI_NEGS
#define     negsddu  VDDU_NEGS
#define     negsddi  VDDI_NEGS

#define     negsqyu  VQYU_NEGS
#define     negsqbu  VQBU_NEGS
#define     negsqbi  VQBI_NEGS
#define     negsqbc  VQBC_NEGS
#define     negsqhu  VQHU_NEGS
#define     negsqhi  VQHI_NEGS
#define     negsqwu  VQWU_NEGS
#define     negsqwi  VQWI_NEGS
#define     negsqdu  VQDU_NEGS
#define     negsqdi  VQDI_NEGS
#if _LEAVE_NEGS
}
#endif

#if _ENTER_NEGH
{
#endif
/*  NEGation (as flt16_t)
*/

#define     negh(X) (negh_funcof(X)(X))
#define     negh_funcof(X)  \
FUNCOF(             \
    negh, (   X   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     neghyu    BOOL_NEGH
#define     neghbu   UINT8_NEGH
#define     neghbi    INT8_NEGH
#define     neghbc    CHAR_NEGH
#define     neghhu  UINT16_NEGH
#define     neghhi   INT16_NEGH
#define     neghhf   FLT16_NEGH
#define     neghwu  UINT32_NEGH
#define     neghwi   INT32_NEGH
#define     neghwf     FLT_NEGH
#define     neghdu  UINT64_NEGH
#define     neghdi   INT64_NEGH
#define     neghdf     DBL_NEGH
#if DWRD_NLONG == 2
#   define  neghlu  ULONG_NEGH
#   define  neghli   LONG_NEGH
#elif QUAD_NLLONG == 2
#   define  neghlu ULLONG_NEGH
#   define  neghli  LLONG_NEGH
#else
#   define  neghqu ULLONG_NEGH
#   define  neghqi  LLONG_NEGH
#   define  neghqf   LDBL_NEGH
#endif

#define     neghwbu  VWBU_NEGH
#define     neghwbi  VWBI_NEGH
#define     neghwbc  VWBC_NEGH
#define     neghwhu  VWHU_NEGH
#define     neghwhi  VWHI_NEGH
#define     neghwhf  VWHF_NEGH

#define     neghdbu  VDBU_NEGH
#define     neghdbi  VDBI_NEGH
#define     neghdbc  VDBC_NEGH
#define     neghdhu  VDHU_NEGH
#define     neghdhi  VDHI_NEGH
#define     neghdhf  VDHF_NEGH
#define     neghdwu  VDWU_NEGH
#define     neghdwi  VDWI_NEGH
#define     neghdwf  VDWF_NEGH

#define     neghqhu  VQHU_NEGH
#define     neghqhi  VQHI_NEGH
#define     neghqhf  VQHF_NEGH
#define     neghqwu  VQWU_NEGH
#define     neghqwi  VQWI_NEGH
#define     neghqwf  VQWF_NEGH
#define     neghqdu  VQDU_NEGH
#define     neghqdi  VQDI_NEGH
#define     neghqdf  VQDF_NEGH
#if _LEAVE_NEGH
}
#endif

#if _ENTER_NEGW
{
#endif
/*  NEGation (as float)
*/

#define     negw(X) (negw_funcof(X)(X))
#define     negw_funcof(X)  \
FUNCOF(             \
    negw, (   X   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     negwyu    BOOL_NEGW
#define     negwbu   UINT8_NEGW
#define     negwbi    INT8_NEGW
#define     negwbc    CHAR_NEGW
#define     negwhu  UINT16_NEGW
#define     negwhi   INT16_NEGW
#define     negwhf   FLT16_NEGW
#define     negwwu  UINT32_NEGW
#define     negwwi   INT32_NEGW
#define     negwwf     FLT_NEGW
#define     negwdu  UINT64_NEGW
#define     negwdi   INT64_NEGW
#define     negwdf     DBL_NEGW
#if DWRD_NLONG == 2
#   define  negwlu  ULONG_NEGW
#   define  negwli   LONG_NEGW
#elif QUAD_NLLONG == 2
#   define  negwlu ULLONG_NEGW
#   define  negwli  LLONG_NEGW
#else
#   define  negwqu ULLONG_NEGW
#   define  negwqi  LLONG_NEGW
#   define  negwqf   LDBL_NEGW
#endif

#define     negwwbu  VWBU_NEGW
#define     negwwbi  VWBI_NEGW
#define     negwwbc  VWBC_NEGW
#define     negwwhu  VWHU_NEGW
#define     negwwhi  VWHI_NEGW
#define     negwwhf  VWHF_NEGW
#define     negwwwu  VWWU_NEGW
#define     negwwwi  VWWI_NEGW
#define     negwwwf  VWWF_NEGW

#define     negwdhu  VDHU_NEGW
#define     negwdhi  VDHI_NEGW
#define     negwdhf  VDHF_NEGW
#define     negwdwu  VDWU_NEGW
#define     negwdwi  VDWI_NEGW
#define     negwdwf  VDWF_NEGW
#define     negwddu  VDDU_NEGW
#define     negwddi  VDDI_NEGW
#define     negwddf  VDDF_NEGW

#define     negwqwu  VQWU_NEGW
#define     negwqwi  VQWI_NEGW
#define     negwqwf  VQWF_NEGW
#define     negwqdu  VQDU_NEGW
#define     negwqdi  VQDI_NEGW
#define     negwqdf  VQDF_NEGW
#if _LEAVE_NEGW
}
#endif

#if _ENTER_NEGD
{
#endif
/*  NEGation (as double)
*/

#define     negd(X) (negd_funcof(X)(X))
#define     negd_funcof(X)  \
FUNCOF(             \
    negd, (   X   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     negdyu    BOOL_NEGD
#define     negdbu   UINT8_NEGD
#define     negdbi    INT8_NEGD
#define     negdbc    CHAR_NEGD
#define     negdhu  UINT16_NEGD
#define     negdhi   INT16_NEGD
#define     negdhf   FLT16_NEGD
#define     negdwu  UINT32_NEGD
#define     negdwi   INT32_NEGD
#define     negdwf     FLT_NEGD
#define     negddu  UINT64_NEGD
#define     negddi   INT64_NEGD
#define     negddf     DBL_NEGD
#if DWRD_NLONG == 2
#   define  negdlu  ULONG_NEGD
#   define  negdli   LONG_NEGD
#elif QUAD_NLLONG == 2
#   define  negdlu ULLONG_NEGD
#   define  negdli  LLONG_NEGD
#else
#   define  negdqu ULLONG_NEGD
#   define  negdqi  LLONG_NEGD
#   define  negdqf   LDBL_NEGD
#endif

#define     negdwhu  VWHU_NEGD
#define     negdwhi  VWHI_NEGD
#define     negdwhf  VWHF_NEGD
#define     negdwwu  VWWU_NEGD
#define     negdwwi  VWWI_NEGD
#define     negdwwf  VWWF_NEGD

#define     negddwu  VDWU_NEGD
#define     negddwi  VDWI_NEGD
#define     negddwf  VDWF_NEGD
#define     negdddu  VDDU_NEGD
#define     negdddi  VDDI_NEGD
#define     negdddf  VDDF_NEGD
#define     negdqdu  VQDU_NEGD
#define     negdqdi  VQDI_NEGD
#define     negdqdf  VQDF_NEGD
#if _LEAVE_NEGD
}
#endif


#if _ENTER_NEWL
{
#endif
/*  vector constructor (left to right/lo to high)

Each operation takes the same number of operands as there
are elements in the resulting vector.
*/

#define     newl(T, ...) (newl_funcof(T)(__VA_ARGS__))
#define     newl_funcof(T, ...) \
FUNCOF(             \
    newl,   ((T){0}),           \
    NONE, /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     newlwbu VWBU_NEWL
#define     newlwbi VWBI_NEWL
#define     newlwbc VWBC_NEWL
#define     newlwhu VWHU_NEWL
#define     newlwhi VWHI_NEWL
#define     newlwhf VWHF_NEWL
#define     newlwwu VWWU_NEWL
#define     newlwwi VWWI_NEWL
#define     newlwwf VWWF_NEWL

#define     newldbu VDBU_NEWL
#define     newldbi VDBI_NEWL
#define     newldbc VDBC_NEWL
#define     newldhu VDHU_NEWL
#define     newldhi VDHI_NEWL
#define     newldhf VDHF_NEWL
#define     newldwu VDWU_NEWL
#define     newldwi VDWI_NEWL
#define     newldwf VDWF_NEWL
#define     newlddu VDDU_NEWL
#define     newlddi VDDI_NEWL
#define     newlddf VDDF_NEWL

#define     newlqbu VQBU_NEWL
#define     newlqbi VQBI_NEWL
#define     newlqbc VQBC_NEWL
#define     newlqhu VQHU_NEWL
#define     newlqhi VQHI_NEWL
#define     newlqhf VQHF_NEWL
#define     newlqwu VQWU_NEWL
#define     newlqwi VQWI_NEWL
#define     newlqwf VQWF_NEWL
#define     newlqdu VQDU_NEWL
#define     newlqdi VQDI_NEWL
#define     newlqdf VQDF_NEWL
#if _LEAVE_NEWL
}
#endif

#if _ENTER_NEWR
{
#endif
/*  vector constructor (right to left/hi to lo)

Each operation takes the same number of operands as there
are elements in the result vector. Operands are given in
"reversed" order, i.e. the first operand goes in the
result's highest lane and the last operand goes in lane 0.
*/

#define     newr(T, ...) (newr_funcof(T)(__VA_ARGS__))
#define     newr_funcof(T, ...) \
FUNCOF(             \
    newr,   ((T){0}),           \
    NONE, /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     newrwbu VWBU_NEWR
#define     newrwbi VWBI_NEWR
#define     newrwbc VWBC_NEWR
#define     newrwhu VWHU_NEWR
#define     newrwhi VWHI_NEWR
#define     newrwhf VWHF_NEWR
#define     newrwwu VWWU_NEWR
#define     newrwwi VWWI_NEWR
#define     newrwwf VWWF_NEWR

#define     newrdbu VDBU_NEWR
#define     newrdbi VDBI_NEWR
#define     newrdbc VDBC_NEWR
#define     newrdhu VDHU_NEWR
#define     newrdhi VDHI_NEWR
#define     newrdhf VDHF_NEWR
#define     newrdwu VDWU_NEWR
#define     newrdwi VDWI_NEWR
#define     newrdwf VDWF_NEWR
#define     newrddu VDDU_NEWR
#define     newrddi VDDI_NEWR
#define     newrddf VDDF_NEWR

#define     newrqbu VQBU_NEWR
#define     newrqbi VQBI_NEWR
#define     newrqbc VQBC_NEWR
#define     newrqhu VQHU_NEWR
#define     newrqhi VQHI_NEWR
#define     newrqhf VQHF_NEWR
#define     newrqwu VQWU_NEWR
#define     newrqwi VQWI_NEWR
#define     newrqwf VQWF_NEWR
#define     newrqdu VQDU_NEWR
#define     newrqdi VQDI_NEWR
#define     newrqdf VQDF_NEWR
#if _LEAVE_NEWR
}
#endif


#if _ENTER_ORRS
{
#endif
/*  Bitwise OR

For each bit A in the first operand A and each bit B in
the second operand, compute the bitwise OR of A and B.
*/

#define     orrs(...) (orrs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orrs_funcof(X, ...)  \
FUNCOF(             \
    orrs, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orrsyu    BOOL_ORRS
#define     orrsbu   UINT8_ORRS
#define     orrsbi    INT8_ORRS
#define     orrsbc    CHAR_ORRS
#define     orrshu  UINT16_ORRS
#define     orrshi   INT16_ORRS
#define     orrswu  UINT32_ORRS
#define     orrswi   INT32_ORRS
#define     orrsdu  UINT64_ORRS
#define     orrsdi   INT64_ORRS
#if   DWRD_NLONG == 2
#   define  orrslu   ULONG_ORRS
#   define  orrsli    LONG_ORRS
#elif QUAD_NLLONG == 2
#   define  orrslu  ULLONG_ORRS
#   define  orrsli   LLONG_ORRS
#else
#   define  orrsqu  ULLONG_ORRS
#   define  orrsqi   LLONG_ORRS
#endif

#define     orrswyu   VWYU_ORRS
#define     orrswbu   VWBU_ORRS
#define     orrswbi   VWBI_ORRS
#define     orrswbc   VWBC_ORRS
#define     orrswhu   VWHU_ORRS
#define     orrswhi   VWHI_ORRS
#define     orrswwu   VWWU_ORRS
#define     orrswwi   VWWI_ORRS

#define     orrsdyu   VDYU_ORRS
#define     orrsdbu   VDBU_ORRS
#define     orrsdbi   VDBI_ORRS
#define     orrsdbc   VDBC_ORRS
#define     orrsdhu   VDHU_ORRS
#define     orrsdhi   VDHI_ORRS
#define     orrsdwu   VDWU_ORRS
#define     orrsdwi   VDWI_ORRS
#define     orrsddu   VDDU_ORRS
#define     orrsddi   VDDI_ORRS

#define     orrsqyu   VQYU_ORRS
#define     orrsqbu   VQBU_ORRS
#define     orrsqbi   VQBI_ORRS
#define     orrsqbc   VQBC_ORRS
#define     orrsqhu   VQHU_ORRS
#define     orrsqhi   VQHI_ORRS
#define     orrsqwu   VQWU_ORRS
#define     orrsqwi   VQWI_ORRS
#define     orrsqdu   VQDU_ORRS
#define     orrsqdi   VQDI_ORRS
#if _LEAVE_ORRS
}
#endif

#if _ENTER_ORRN
{
#endif
/*  Bitwise OR NOT

For each bit A in the first operand A and each bit B in
the second operand, compute the bitwise OR of A and NOT B.
*/

#define     orrn(...) (orrn_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orrn_funcof(X, ...)  \
FUNCOF(             \
    orrn, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orrnyu    BOOL_ORRN
#define     orrnbu   UINT8_ORRN
#define     orrnbi    INT8_ORRN
#define     orrnbc    CHAR_ORRN
#define     orrnhu  UINT16_ORRN
#define     orrnhi   INT16_ORRN
#define     orrnwu  UINT32_ORRN
#define     orrnwi   INT32_ORRN
#define     orrndu  UINT64_ORRN
#define     orrndi   INT64_ORRN
#if   DWRD_NLONG == 2
#   define  orrnlu   ULONG_ORRN
#   define  orrnli    LONG_ORRN
#elif QUAD_NLLONG == 2
#   define  orrnlu  ULLONG_ORRN
#   define  orrnli   LLONG_ORRN
#else
#   define  orrnqu  ULLONG_ORRN
#   define  orrnqi   LLONG_ORRN
#endif

#define     orrnwyu   VWYU_ORRN
#define     orrnwbu   VWBU_ORRN
#define     orrnwbi   VWBI_ORRN
#define     orrnwbc   VWBC_ORRN
#define     orrnwhu   VWHU_ORRN
#define     orrnwhi   VWHI_ORRN
#define     orrnwwu   VWWU_ORRN
#define     orrnwwi   VWWI_ORRN

#define     orrndyu   VDYU_ORRN
#define     orrndbu   VDBU_ORRN
#define     orrndbi   VDBI_ORRN
#define     orrndbc   VDBC_ORRN
#define     orrndhu   VDHU_ORRN
#define     orrndhi   VDHI_ORRN
#define     orrndwu   VDWU_ORRN
#define     orrndwi   VDWI_ORRN
#define     orrnddu   VDDU_ORRN
#define     orrnddi   VDDI_ORRN

#define     orrnqyu   VQYU_ORRN
#define     orrnqbu   VQBU_ORRN
#define     orrnqbi   VQBI_ORRN
#define     orrnqbc   VQBC_ORRN
#define     orrnqhu   VQHU_ORRN
#define     orrnqhi   VQHI_ORRN
#define     orrnqwu   VQWU_ORRN
#define     orrnqwi   VQWI_ORRN
#define     orrnqdu   VQDU_ORRN
#define     orrnqdi   VQDI_ORRN
#if _LEAVE_ORRN
}
#endif

#if _ENTER_ORRV
{
#endif
/*  Bitwise OR (across vector)
*/

#define     orrv(...) (orrv_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orrv_funcof(X, ...)  \
FUNCOF(             \
    orrv, (   X   ),\
    NONE, /* TGK */ \
    YHZ,  /* TGW */ \
    YWZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orrvwyu   VWYU_ORRV
#define     orrvwbu   VWBU_ORRV
#define     orrvwbi   VWBI_ORRV
#define     orrvwbc   VWBC_ORRV
#define     orrvwhu   VWHU_ORRV
#define     orrvwhi   VWHI_ORRV

#define     orrvdyu   VDYU_ORRV
#define     orrvdbu   VDBU_ORRV
#define     orrvdbi   VDBI_ORRV
#define     orrvdbc   VDBC_ORRV
#define     orrvdhu   VDHU_ORRV
#define     orrvdhi   VDHI_ORRV
#define     orrvdwu   VDWU_ORRV
#define     orrvdwi   VDWI_ORRV

#define     orrvqyu   VQYU_ORRV
#define     orrvqbu   VQBU_ORRV
#define     orrvqbi   VQBI_ORRV
#define     orrvqbc   VQBC_ORRV
#define     orrvqhu   VQHU_ORRV
#define     orrvqhi   VQHI_ORRV
#define     orrvqwu   VQWU_ORRV
#define     orrvqwi   VQWI_ORRV
#define     orrvqdu   VQDU_ORRV
#define     orrvqdi   VQDI_ORRV
#if _LEAVE_ORRV
}
#endif

#if _ENTER_ORR1
{
#endif
/*  ORR (atomic fetch or w/ memory_order_relaxed)

Atomically exchange the contents of the scalar variable at
the address specified by the first oper A with the
bitwise OR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_or and memory_order_relaxed
*/

#define     orr1(...)  (orr1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orr1_funcof(A, ...) \
FUNCOF_AK(          \
    orr1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orr1ayu    BOOL_ORR1A
#define     orr1abu   UINT8_ORR1A
#define     orr1abi    INT8_ORR1A
#define     orr1abc    CHAR_ORR1A
#define     orr1ahu  UINT16_ORR1A
#define     orr1ahi   INT16_ORR1A
#define     orr1awu  UINT32_ORR1A
#define     orr1awi   INT32_ORR1A
#define     orr1adu  UINT64_ORR1A
#define     orr1adi   INT64_ORR1A
#if DWRD_NLONG == 2
#   define  orr1alu   ULONG_ORR1A
#   define  orr1ali    LONG_ORR1A
#elif QUAD_NLLONG == 2
#   define  orr1alu  ULLONG_ORR1A
#   define  orr1ali   LLONG_ORR1A
#else
#   define  orr1aqu  ULLONG_ORR1A
#   define  orr1aqi   LLONG_ORR1A
#endif

#if _LEAVE_ORR1
}
#endif

#if _ENTER_ORRA
{
#endif
/*  ORR (atomic fetch or w/ memory_order_acquire)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise OR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_or and memory_order_acquire
*/

#define     orra(...)  (orra_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orra_funcof(A, ...) \
FUNCOF_AK(          \
    orra, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orraayu    BOOL_ORRAA
#define     orraabu   UINT8_ORRAA
#define     orraabi    INT8_ORRAA
#define     orraabc    CHAR_ORRAA
#define     orraahu  UINT16_ORRAA
#define     orraahi   INT16_ORRAA
#define     orraawu  UINT32_ORRAA
#define     orraawi   INT32_ORRAA
#define     orraadu  UINT64_ORRAA
#define     orraadi   INT64_ORRAA
#if DWRD_NLONG == 2
#   define  orraalu   ULONG_ORRAA
#   define  orraali    LONG_ORRAA
#elif QUAD_NLLONG == 2
#   define  orraalu  ULLONG_ORRAA
#   define  orraali   LLONG_ORRAA
#else
#   define  orraaqu  ULLONG_ORRAA
#   define  orraaqi   LLONG_ORRAA
#endif

#if _LEAVE_ORRA
}
#endif

#if _ENTER_ORRE
{
#endif
/*  ORR (atomic fetch orr w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise OR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_or and memory_order_release
*/

#define     orre(...)  (orre_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orre_funcof(A, ...) \
FUNCOF_AK(          \
    orre, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orreayu    BOOL_ORREA
#define     orreabu   UINT8_ORREA
#define     orreabi    INT8_ORREA
#define     orreabc    CHAR_ORREA
#define     orreahu  UINT16_ORREA
#define     orreahi   INT16_ORREA
#define     orreawu  UINT32_ORREA
#define     orreawi   INT32_ORREA
#define     orreadu  UINT64_ORREA
#define     orreadi   INT64_ORREA
#if DWRD_NLONG == 2
#   define  orrealu   ULONG_ORREA
#   define  orreali    LONG_ORREA
#elif QUAD_NLLONG == 2
#   define  orrealu  ULLONG_ORREA
#   define  orreali   LLONG_ORREA
#else
#   define  orreaqu  ULLONG_ORREA
#   define  orreaqi   LLONG_ORREA
#endif

#if _LEAVE_ORRE
}
#endif

#if _ENTER_ORRT
{
#endif
/*  ORR (atomic fetch orr w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise OR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_or and memory_order_seq_cst
*/

#define     orrt(...)  (orrt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     orrt_funcof(A, ...) \
FUNCOF_AK(          \
    orrt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     orrtayu    BOOL_ORRTA
#define     orrtabu   UINT8_ORRTA
#define     orrtabi    INT8_ORRTA
#define     orrtabc    CHAR_ORRTA
#define     orrtahu  UINT16_ORRTA
#define     orrtahi   INT16_ORRTA
#define     orrtawu  UINT32_ORRTA
#define     orrtawi   INT32_ORRTA
#define     orrtadu  UINT64_ORRTA
#define     orrtadi   INT64_ORRTA
#if DWRD_NLONG == 2
#   define  orrtalu   ULONG_ORRTA
#   define  orrtali    LONG_ORRTA
#elif QUAD_NLLONG == 2
#   define  orrtalu  ULLONG_ORRTA
#   define  orrtali   LLONG_ORRTA
#else
#   define  orrtaqu  ULLONG_ORRTA
#   define  orrtaqi   LLONG_ORRTA
#endif

#if _LEAVE_ORRT
}
#endif



#if _ENTER_PERS
{
#endif
/*  PERmute vector (single)

Create a vector with elements selected from another
vector. Each operation takes an N element source vector A
plus N signed int constant parameters representing a lane
in A from which to copy the corresponding value. If the
list of lane numbers contains any values outside the
range [-1..N-1], the result is undefined.

Whenever a lane is specified as -1, the corresponding lane
of the result is set to zero.

The following shows a naive implementation of persdwf

    Vdwf
    persdwf(Vdwf a, Rc(-1, 1) k0, Rc(-1, 1) k1)
    {
        Vdwf c = {0};
        if (k0 > 0) c = set1(c, 0, get1(a, k0));
        if (k1 > 0) c = set1(c, 0, get1(a, k1));
        return c;
    }

TODO: debate permitting specification of some single value
other than zero
*/

#define     pers(...)    (pers_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     pers_funcof(X,...)  \
FUNCOF(             \
    pers, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     perswbu VWBU_PERS
#define     perswbi VWBI_PERS
#define     perswbc VWBC_PERS
#define     perswhu VWHU_PERS
#define     perswhi VWHI_PERS
#define     perswhf VWHF_PERS

#define     persdbu VDBU_PERS
#define     persdbi VDBI_PERS
#define     persdbc VDBC_PERS
#define     persdhu VDHU_PERS
#define     persdhi VDHI_PERS
#define     persdhf VDHF_PERS
#define     persdwu VDWU_PERS
#define     persdwi VDWI_PERS
#define     persdwf VDWF_PERS

#define     persqbu VQBU_PERS
#define     persqbi VQBI_PERS
#define     persqbc VQBC_PERS
#define     persqhu VQHU_PERS
#define     persqhi VQHI_PERS
#define     persqhf VQHF_PERS
#define     persqwu VQWU_PERS
#define     persqwi VQWI_PERS
#define     persqwf VQWF_PERS
#define     persqdu VQDU_PERS
#define     persqdi VQDI_PERS
#define     persqdf VQDF_PERS
#if _LEAVE_PERS
}
#endif

#if _ENTER_PERM
{
#endif
/*  PERMute vector pair

Create a vector with elements selected from another
vector. Each operation takes two N element source vectors
A and B plus N signed int constant parameters representing
a lane in A from which to copy the corresponding value. If
the list of lane numbers contains any values outside the
range [-1..N-1], the result is undefined.

Whenever a lane is specified as -1, the corresponding lane
of the second vector B is copied to the result, instead of
zero as with pers.

The following shows a naive implementation of permdwf

    Vdwf
    permdwf(Vdwf a, Vdwf b, Rc(-1, 1) k0, Rc(-1, 1) k1)
    {
        Vdwf c = b;
        if (k0 > 0) c = set1(c, 0, get1(a, k0));
        if (k1 > 0) c = set1(c, 0, get1(a, k1));
        return c;
    }

TODO: debate implementing perm*yu
*/

#define     perm(...)    (perm_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     perm_funcof(X,...)  \
FUNCOF(             \
    perm, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     permwbu VWBU_PERM
#define     permwbi VWBI_PERM
#define     permwbc VWBC_PERM
#define     permwhu VWHU_PERM
#define     permwhi VWHI_PERM
#define     permwhf VWHF_PERM

#define     permdbu VDBU_PERM
#define     permdbi VDBI_PERM
#define     permdbc VDBC_PERM
#define     permdhu VDHU_PERM
#define     permdhi VDHI_PERM
#define     permdhf VDHF_PERM
#define     permdwu VDWU_PERM
#define     permdwi VDWI_PERM
#define     permdwf VDWF_PERM

#define     permqbu VQBU_PERM
#define     permqbi VQBI_PERM
#define     permqbc VQBC_PERM
#define     permqhu VQHU_PERM
#define     permqhi VQHI_PERM
#define     permqhf VQHF_PERM
#define     permqwu VQWU_PERM
#define     permqwi VQWI_PERM
#define     permqwf VQWF_PERM
#define     permqdu VQDU_PERM
#define     permqdi VQDI_PERM
#define     permqdf VQDF_PERM
#if _LEAVE_PERM
}
#endif


#if _ENTER_REVS
{
#endif
/*  REVerse (vector)

Reverse the contents of a vector
*/

#define     revs(S)     (revs_funcof(S)(S))
#define     revs_funcof(S)  \
FUNCOF(             \
    revs, (   S   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     revswyu VWYU_REVS
#define     revswbu VWBU_REVS
#define     revswbi VWBI_REVS
#define     revswbc VWBI_REVS
#define     revswhu VWHU_REVS
#define     revswhi VWHI_REVS
#define     revswhf VWHF_REVS

#define     revsdyu VDYU_REVS
#define     revsdbu VDBU_REVS
#define     revsdbi VDBI_REVS
#define     revsdbc VDBC_REVS
#define     revsdhu VDHU_REVS
#define     revsdhi VDHI_REVS
#define     revsdhf VDHF_REVS
#define     revsdwu VDWU_REVS
#define     revsdwi VDWI_REVS
#define     revsdwf VDWF_REVS

#define     revsqyu VQYU_REVS
#define     revsqbu VQBU_REVS
#define     revsqbi VQBI_REVS
#define     revsqbc VQBC_REVS
#define     revsqhu VQHU_REVS
#define     revsqhi VQHI_REVS
#define     revsqhf VQHF_REVS
#define     revsqwu VQWU_REVS
#define     revsqwi VQWI_REVS
#define     revsqwf VQWF_REVS
#define     revsqdu VQDU_REVS
#define     revsqdi VQDI_REVS
#define     revsqdf VQDF_REVS
#if _LEAVE_REVS
}
#endif

#if _ENTER_REVY
{
#endif
/*  REVerse (binary repr)

Reverse the binary representation of each multibit element
in the operand. To reverse the binary representation of
an entire vector, see revs*yu
*/

#define     revy(S)     (revy_funcof(S)(S))
#define     revy_funcof(S)  \
FUNCOF(             \
    revy, (   S   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)
#define     revybu   UINT8_REVY
#define     revybi    INT8_REVY
#define     revybc    CHAR_REVY
#define     revyhu  UINT16_REVY
#define     revyhi   INT16_REVY
#define     revywu  UINT32_REVY
#define     revywi   INT32_REVY
#define     revydu  UINT64_REVY
#define     revydi   INT64_REVY
#if DWRD_NLONG == 2
#   define  revylu   ULONG_REVY
#   define  revyli    LONG_REVY
#elif QUAD_NLLONG == 2
#   define  revylu  ULLONG_REVY
#   define  revyli   LLONG_REVY
#endif

#define     revywbu   VWBU_REVY
#define     revywbi   VWBI_REVY
#define     revywbc   VWBI_REVY
#define     revywhu   VWHU_REVY
#define     revywhi   VWHI_REVY
#define     revywwu   VWWU_REVY
#define     revywwi   VWWI_REVY

#define     revydbu   VDBU_REVY
#define     revydbi   VDBI_REVY
#define     revydbc   VDBC_REVY
#define     revydhu   VDHU_REVY
#define     revydhi   VDHI_REVY
#define     revydwu   VDWU_REVY
#define     revydwi   VDWI_REVY
#define     revyddu   VDDU_REVY
#define     revyddi   VDDI_REVY

#define     revyqbu   VQBU_REVY
#define     revyqbi   VQBI_REVY
#define     revyqbc   VQBC_REVY
#define     revyqhu   VQHU_REVY
#define     revyqhi   VQHI_REVY
#define     revyqwu   VQWU_REVY
#define     revyqwi   VQWI_REVY
#define     revyqdu   VQDU_REVY
#define     revyqdi   VQDI_REVY
#if _LEAVE_REVY
}
#endif

#if _ENTER_REVB
{
#endif
/*  REVerse (byteorder)

Reverse the byteorder of each multibit element in the
operand.
*/

#define     revb(X)     (revb_funcof(X)(X))
#define     revb_funcof(X)  \
FUNCOF(             \
    revb, (   X   ),\
    HDR,  /* TGK */ \
    HWR,  /* TGW */ \
    HDR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     revbhu  UINT16_REVB
#define     revbhi   INT16_REVB
#define     revbhf   FLT16_REVB
#define     revbwu  UINT32_REVB
#define     revbwi   INT32_REVB
#define     revbwf     FLT_REVB
#define     revbdu  UINT64_REVB
#define     revbdi   INT64_REVB
#define     revbdf     DBL_REVB
#if DWRD_NLONG == 2
#   define  revblu   ULONG_REVB
#   define  revbli    LONG_REVB
#elif QUAD_NLLONG == 2
#   define  revblu  ULLONG_REVB
#   define  revbli   LLONG_REVB
#endif

#define     revbwhu   VWHU_REVB
#define     revbwhi   VWHI_REVB
#define     revbwhf   VWHF_REVB
#define     revbwwu   VWWU_REVB
#define     revbwwi   VWWI_REVB
#define     revbwwf   VWWF_REVB

#define     revbdhu   VDHU_REVB
#define     revbdhi   VDHI_REVB
#define     revbdhf   VDHF_REVB
#define     revbdwu   VDWU_REVB
#define     revbdwi   VDWI_REVB
#define     revbdwf   VDWF_REVB
#define     revbddu   VDDU_REVB
#define     revbddi   VDDI_REVB
#define     revbddf   VDDF_REVB

#define     revbqhu   VQHU_REVB
#define     revbqhi   VQHI_REVB
#define     revbqhf   VQHF_REVB
#define     revbqwu   VQWU_REVB
#define     revbqwi   VQWI_REVB
#define     revbqwf   VQWF_REVB
#define     revbqdu   VQDU_REVB
#define     revbqdi   VQDI_REVB
#define     revbqdf   VQDF_REVB
#if _LEAVE_REVB
}
#endif

#if _ENTER_REVH
{
#endif
/*  REVerse (halforder)

Reverse the halfwords in each 32 bit or wider element of
the operand.
*/

#define     revh(X)     (revh_funcof(X)(X))
#define     revh_funcof(X)  \
FUNCOF(             \
    revh, (   X   ),\
    WDR,  /* TGK */ \
    WR,   /* TGW */ \
    WDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     revhwu  UINT32_REVH
#define     revhwi   INT32_REVH
#define     revhwf     FLT_REVH
#define     revhdu  UINT64_REVH
#define     revhdi   INT64_REVH
#define     revhdf     DBL_REVH
#if DWRD_NLONG == 2
#   define  revhlu   ULONG_REVH
#   define  revhli    LONG_REVH
#elif QUAD_NLLONG == 2
#   define  revhlu  ULLONG_REVH
#   define  revhli   LLONG_REVH
#endif

#define     revhwwu   VWWU_REVH
#define     revhwwi   VWWI_REVH
#define     revhwwf   VWWF_REVH

#define     revhdwu   VDWU_REVH
#define     revhdwi   VDWI_REVH
#define     revhdwf   VDWF_REVH
#define     revhddu   VDDU_REVH
#define     revhddi   VDDI_REVH
#define     revhddf   VDDF_REVH

#define     revhqwu   VQWU_REVH
#define     revhqwi   VQWI_REVH
#define     revhqwf   VQWF_REVH
#define     revhqdu   VQDU_REVH
#define     revhqdi   VQDI_REVH
#define     revhqdf   VQDF_REVH
#if _LEAVE_REVH
}
#endif


#if _ENTER_RAZB
{
#endif
/*  Round Away from Zero (as 8 bit int)

Round each floating point element in the operand to
the nearest integer then convert the result to int8_t.
Ties round away from zero, i.e. towards ±∞.

If rounded values are greater than INT8_MAX or less
than INT8_MIN, the result is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     razb(...) (razb_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     razb_funcof(X, ...)  \
FUNCOF(             \
    razb, (   X   ),\
    BDF,  /* TGK */ \
    NONE, /* TGW */ \
    HF,   /* TGD */ \
    HWF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     razbhf   FLT16_RAZB
#define     razbwf     FLT_RAZB
#define     razbdf     DBL_RAZB
#if QUAD_NLLONG == 1
#   define  razbqf    LDBL_RAZB
#endif

#define     razbdhf   VDHF_RAZB
#define     razbqhf   VQHF_RAZB
#define     razbqwf   VQWF_RAZB
#if _LEAVE_RAZB
}
#endif

#if _ENTER_RAZH
{
#endif
/*  Round each floating point element in the operand to
    the nearest integer then convert the result to int16_t.
    Ties round away from zero, i.e. towards ±∞.

    If rounded values are greater than INT16_MAX or less
    than INT16_MIN, the result is implementation defined.

    If any element is NaN, the result is undefined.
*/

#define     razh(...) (razh_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     razh_funcof(X, ...)  \
FUNCOF(             \
    razh, (   X   ),\
    HDF,  /* TGK */ \
    HF,   /* TGW */ \
    HWF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     razhhf   FLT16_RAZH // hf => hi
#define     razhwf     FLT_RAZH // wf => hi
#define     razhdf     DBL_RAZH // df => hi

#if QUAD_NLLONG == 1
#   define  razhqf    LDBL_RAZH // qf => hi
#endif

// TGW=HF
#define     razhwhf   VWHF_RAZH // whf => whi

// TGD=HWF
#define     razhdhf   VDHF_RAZH // dhf => dhi
#define     razhdwf   VDWF_RAZH // dwf => whi

// TGQ=HDF
#define     razhqhf   VQHF_RAZH // qhf => qhi
#define     razhqwf   VQWF_RAZH // qwf => dhi
#define     razhqdf   VQDF_RAZH // qwf => whi

// TGO=HDF
#define     razhohf   VOHF_RAZH // ohf => ohi
#define     razhowf   VOWF_RAZH // owf => qhi
#define     razhodf   VODF_RAZH // odf => dhi
#define     razhoqf   VOQF_RAZH // oqf => whi

// TGS=HDF
#define     razhshf   VSHF_RAZH // shf => shi
#define     razhswf   VSWF_RAZH // swf => ohi
#define     razhsdf   VSDF_RAZH // sdf => qhi
#define     razhsqf   VSQF_RAZH // sqf => dhi

#if _LEAVE_RAZH
}
#endif

#if _ENTER_RAZW
{
#endif
/*  Round each floating point element in the operand to
    the nearest integer then convert the result to int32_t.
    Ties round away from zero, i.e. towards ±∞.

    If rounded values are greater than INT32_MAX or less
    than INT32_MIN, the result is implementation defined.

    If any element is NaN, the result is undefined.
*/

#define     razw(...) (razw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     razw_funcof(X, ...)  \
FUNCOF(             \
    razw, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    WDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     razwhf   FLT16_RAZW
#define     razwwf     FLT_RAZW
#define     razwdf     DBL_RAZW
#if QUAD_NLLONG == 1
#   define  razwqf    LDBL_RAZW
#endif

#define     razwwhf   VWHF_RAZW
#define     razwwwf   VWWF_RAZW

#define     razwdhf   VDHF_RAZW
#define     razwdwf   VDWF_RAZW
#define     razwddf   VDDF_RAZW

#define     razwqhf   VQHF_RAZW
#define     razwqwf   VQWF_RAZW
#define     razwqdf   VQDF_RAZW
#define     razwqqf   VQQF_RAZW
#if _LEAVE_RAZW
}
#endif

#if _ENTER_RAZD
{
#endif
/*  Round each floating point element in the operand to
    the nearest integer then convert the result to int64_t.
    Ties round away from zero, i.e. towards ±∞.

    If rounded values are greater than INT64_MAX or less
    than INT64_MIN, the result is implementation defined.

    If any element is NaN, the result is undefined.
*/

#define     razd(...) (razd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     razd_funcof(X, ...)  \
FUNCOF(             \
    razd, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    WDF,  /* TGD */ \
    DF,   /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     razdhf   FLT16_RAZD
#define     razdwf     FLT_RAZD
#define     razddf     DBL_RAZD
#if QUAD_NLLONG == 1
#   define  razdqf    LDBL_RAZD
#endif

#define     razdwhf   VWHF_RAZD
#define     razdwwf   VWWF_RAZD

#define     razddhf   VDHF_RAZD
#define     razddwf   VDWF_RAZD
#define     razdddf   VDDF_RAZD

#define     razdqhf   VQHF_RAZD
#define     razdqwf   VQWF_RAZD
#define     razdqdf   VQDF_RAZD
#define     razdqqf   VQQF_RAZD
#if _LEAVE_RAZD
}
#endif

#if _ENTER_RAZF
{
#endif
/*  Round Away from Zero

Round away from zero
*/

#define     razf(...) (razf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     razf_funcof(X, ...)  \
FUNCOF(             \
    razf, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     razfhf   FLT16_RAZF
#define     razfwf     FLT_RAZF
#define     razfdf     DBL_RAZF
#if QUAD_NLLONG == 1
#   define  razfqf    LDBL_RAZF
#endif

#define     razfwhf   VWHF_RAZF
#define     razfwwf   VWWF_RAZF

#define     razfdhf   VDHF_RAZF
#define     razfdwf   VDWF_RAZF
#define     razfddf   VDDF_RAZF

#define     razfqhf   VQHF_RAZF
#define     razfqwf   VQWF_RAZF
#define     razfqdf   VQDF_RAZF
#if _LEAVE_RAZF
}
#endif


#if _ENTER_ROTL
{
#endif
/*  ROTate binary representation (left)
*/

#define     rotl(...) (rotl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rotl_funcof(A, ...)  \
FUNCOF(             \
    rotl, (   A   ),\
    BDU,  /* TGK */ \
    BWU,  /* TGW */ \
    BDU,  /* TGD */ \
    BDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rotlbu   UINT8_ROTL
#define     rotlbc    CHAR_ROTL
#define     rotlhu  UINT16_ROTL
#define     rotlwu  UINT32_ROTL
#define     rotldu  UINT64_ROTL
#if   DWRD_NLONG == 2
#   define  rotllu   ULONG_ROTL
#elif QUAD_NLLONG == 2
#   define  rotllu  ULLONG_ROTL
#else
#   define  rotlqu  ULLONG_ROTL
#endif

#define     rotlwbu   VWBU_ROTL
#define     rotlwbc   VWBC_ROTL
#define     rotlwhu   VWHU_ROTL
#define     rotlwwu   VWWU_ROTL

#define     rotldbu   VDBU_ROTL
#define     rotldbc   VDBC_ROTL
#define     rotldhu   VDHU_ROTL
#define     rotldwu   VDWU_ROTL
#define     rotlddu   VDDU_ROTL

#define     rotlqbu   VQBU_ROTL
#define     rotlqbc   VQBC_ROTL
#define     rotlqhu   VQHU_ROTL
#define     rotlqwu   VQWU_ROTL
#define     rotlqdu   VQDU_ROTL
#if _LEAVE_ROTL
}
#endif

#if _ENTER_ROTR
{
#endif
/*  ROTate binary representation (right)
*/

#define     rotr(...) (rotr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rotr_funcof(A, ...)  \
FUNCOF(             \
    rotr, (   A   ),\
    BDU,  /* TGK */ \
    BWU,  /* TGW */ \
    BDU,  /* TGD */ \
    BDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rotrbu   UINT8_ROTR
#define     rotrbc    CHAR_ROTR
#define     rotrhu  UINT16_ROTR
#define     rotrwu  UINT32_ROTR
#define     rotrdu  UINT64_ROTR
#if   DWRD_NLONG == 2
#   define  rotrlu   ULONG_ROTR
#elif QUAD_NLLONG == 2
#   define  rotrlu  ULLONG_ROTR
#else
#   define  rotrqu  ULLONG_ROTR
#endif

#define     rotrwbu   VWBU_ROTR
#define     rotrwbc   VWBC_ROTR
#define     rotrwhu   VWHU_ROTR
#define     rotrwwu   VWWU_ROTR

#define     rotrdbu   VDBU_ROTR
#define     rotrdbc   VDBC_ROTR
#define     rotrdhu   VDHU_ROTR
#define     rotrdwu   VDWU_ROTR
#define     rotrddu   VDDU_ROTR

#define     rotrqbu   VQBU_ROTR
#define     rotrqbc   VQBC_ROTR
#define     rotrqhu   VQHU_ROTR
#define     rotrqwu   VQWU_ROTR
#define     rotrqdu   VQDU_ROTR
#if _LEAVE_ROTR
}
#endif


#if _ENTER_ROVL
{
#endif
/*  ROtate by Vector (right)

Rotated the binary representation of each N bit element in
the first operand right by the number of bits specified by
the corresponding N bit unsigned int element of the second
operand.

If the rotation amount of any element in the second
operand falls outside the range [0..N], the result is
implementation defined.
*/

#define     rovl(...) (rovl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rovl_funcof(A, ...)  \
FUNCOF(             \
    rovl, (   A   ),\
    NONE, /* TGK */ \
    BWU,  /* TGW */ \
    BDU,  /* TGD */ \
    BDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rovlwbu   VWBU_ROVL
#define     rovlwbc   VWBC_ROVL
#define     rovlwhu   VWHU_ROVL
#define     rovlwwu   VWWU_ROVL

#define     rovldbu   VDBU_ROVL
#define     rovldbc   VDBC_ROVL
#define     rovldhu   VDHU_ROVL
#define     rovldwu   VDWU_ROVL
#define     rovlddu   VDDU_ROVL

#define     rovlqbu   VQBU_ROVL
#define     rovlqbc   VQBC_ROVL
#define     rovlqhu   VQHU_ROVL
#define     rovlqwu   VQWU_ROVL
#define     rovlqdu   VQDU_ROVL
#if _LEAVE_ROVL
}
#endif

#if _ENTER_ROVR
{
#endif
/*  ROtate by Vector (right)

Rotated the binary representation of each N bit element in
the first operand left by the number of bits specified by
the corresponding N bit unsigned int element of the second
operand.

If the rotation amount of any element in the second
operand falls outside the range [0..N], the result is
implementation defined.
*/

#define     rovr(...) (rovr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rovr_funcof(A, ...)  \
FUNCOF(             \
    rovr, (   A   ),\
    NONE, /* TGK */ \
    BWU,  /* TGW */ \
    BDU,  /* TGD */ \
    BDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rovrwbu   VWBU_ROVR
#define     rovrwbc   VWBC_ROVR
#define     rovrwhu   VWHU_ROVR
#define     rovrwwu   VWWU_ROVR

#define     rovrdbu   VDBU_ROVR
#define     rovrdbc   VDBC_ROVR
#define     rovrdhu   VDHU_ROVR
#define     rovrdwu   VDWU_ROVR
#define     rovrddu   VDDU_ROVR

#define     rovrqbu   VQBU_ROVR
#define     rovrqbc   VQBC_ROVR
#define     rovrqhu   VQHU_ROVR
#define     rovrqwu   VQWU_ROVR
#define     rovrqdu   VQDU_ROVR
#if _LEAVE_ROVR
}
#endif


#if _ENTER_RTNB
{
#endif
/*  Round To Negative infinity (byte)

Round each floating point element in the operand "down", i.e.
toward negative infinity before converting the result to an
8 bit signed int.

The result of rounding elements that cannot be represented by
int8_t is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     rtnb(...) (rtnb_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtnb_funcof(X, ...)  \
FUNCOF(             \
    rtnb, (   X   ),\
    HDF,  /* TGK */ \
    NONE, /* TGW */ \
    HF,   /* TGD */ \
    HWF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtnbhf   FLT16_RTNB
#define     rtnbwf     FLT_RTNB
#define     rtnbdf     DBL_RTNB
#if QUAD_NLLONG == 1
#   define  rtnbqf    LDBL_RTNB
#endif

#define     rtnbdhf   VDHF_RTNB

#define     rtnbqhf   VQHF_RTNB
#define     rtnbqwf   VQWF_RTNB
#if _LEAVE_RTNB
}
#endif

#if _ENTER_RTNH
{
#endif
/*  Round To Negative infinity (halfword)

Round each floating point element in the operand "down", i.e.
toward negative infinity before converting the result to a
16 bit signed int.

The result of rounding elements that cannot be represented by
int16_t is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     rtnh(...) (rtnh_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtnh_funcof(X, ...)  \
FUNCOF(             \
    rtnh, (   X   ),\
    HDF,  /* TGK */ \
    HF, /* TGW */ \
    HWF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtnhhf   FLT16_RTNH
#define     rtnhwf     FLT_RTNH
#define     rtnhdf     DBL_RTNH
#if QUAD_NLLONG == 1
#   define  rtnhqf    LDBL_RTNH
#endif

#define     rtnhwhf   VWHF_RTNH
#define     rtnhdhf   VDHF_RTNH
#define     rtnhdwf   VDWF_RTNH

#define     rtnhqhf   VQHF_RTNH
#define     rtnhqwf   VQWF_RTNH
#define     rtnhqdf   VQDF_RTNH
#if _LEAVE_RTNH
}
#endif

#if _ENTER_RTNW
{
#endif
/*  Round To Negative infinity (word)

Round each floating point element in the operand "down", i.e.
toward negative infinity before converting the result to an
8 bit signed int.

The result of rounding elements that cannot be represented by
int8_t is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     rtnw(...) (rtnw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtnw_funcof(X, ...)  \
FUNCOF(             \
    rtnw, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    WDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtnwhf   FLT16_RTNW
#define     rtnwwf     FLT_RTNW
#define     rtnwdf     DBL_RTNW
#if QUAD_NLLONG == 1
#   define  rtnwqf    LDBL_RTNW
#endif

#define     rtnwwhf   VWHF_RTNW
#define     rtnwwwf   VWWF_RTNW

#define     rtnwdhf   VDHF_RTNW
#define     rtnwdwf   VDWF_RTNW
#define     rtnwddf   VDDF_RTNW

#define     rtnwqhf   VQHF_RTNW
#define     rtnwqwf   VQWF_RTNW
#define     rtnwqdf   VQDF_RTNW
#if _LEAVE_RTNW
}
#endif

#if _ENTER_RTND
{
#endif
/*  Round To Negative infinity (doubleword)

Round each floating point element in the operand "down", i.e.
toward negative infinity before converting the result to a
64 bit signed int.

The result of rounding elements that cannot be represented by
int64_t is implementation defined.

If any element is NaN, the entire result is undefined.
*/


#define     rtnd(...) (rtnd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtnd_funcof(X, ...)  \
FUNCOF(             \
    rtnd, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    WDF,  /* TGD */ \
    DF, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtndhf   FLT16_RTND
#define     rtndwf     FLT_RTND
#define     rtnddf     DBL_RTND
#if QUAD_NLLONG == 1
#   define  rtndqf    LDBL_RTND
#endif

#define     rtndwhf   VWHF_RTND
#define     rtndwwf   VWWF_RTND

#define     rtnddhf   VDHF_RTND
#define     rtnddwf   VDWF_RTND
#define     rtndddf   VDDF_RTND

#define     rtndqhf   VQHF_RTND
#define     rtndqwf   VQWF_RTND
#define     rtndqdf   VQDF_RTND
#if _LEAVE_RTND
}
#endif

#if _ENTER_RTNF
{
#endif
/*  Round To Negative infinity (float)

Round each floating point element in the operand "down", i.e.
toward negative infinity, without conversion to an integer
type.

If any element is NaN, the entire result is undefined.
*/

#define     rtnf(...) (rtnf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtnf_funcof(X, ...)  \
FUNCOF(             \
    rtnf, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtnfhf   FLT16_RTNF
#define     rtnfwf     FLT_RTNF
#define     rtnfdf     DBL_RTNF
#if QUAD_NLLONG == 1
#   define  rtnfqf    LDBL_RTNF
#endif

#define     rtnfwhf   VWHF_RTNF
#define     rtnfwwf   VWWF_RTNF

#define     rtnfdhf   VDHF_RTNF
#define     rtnfdwf   VDWF_RTNF
#define     rtnfddf   VDDF_RTNF

#define     rtnfqhf   VQHF_RTNF
#define     rtnfqwf   VQWF_RTNF
#define     rtnfqdf   VQDF_RTNF
#if _LEAVE_RTNF
}
#endif


#if _ENTER_RTPB
{
#endif
/*  Round To Positive infinity (byte)

Round each floating point element in the operand "up", i.e.
toward positive infinity before converting the result to an
8 bit signed int.

The result of rounding elements that cannot be represented by
int8_t is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     rtpb(...) (rtpb_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtpb_funcof(X, ...)  \
FUNCOF(             \
    rtpb, (   X   ),\
    HDF,  /* TGK */ \
    NONE, /* TGW */ \
    HF, /* TGD */ \
    HWF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtpbhf   FLT16_RTPB
#define     rtpbwf     FLT_RTPB
#define     rtpbdf     DBL_RTPB
#if QUAD_NLLONG == 1
#   define  rtpbqf    LDBL_RTPB
#endif

#define     rtpbdhf   VDHF_RTPB

#define     rtpbqhf   VQHF_RTPB
#define     rtpbqwf   VQWF_RTPB
#if _LEAVE_RTPB
}
#endif

#if _ENTER_RTPH
{
#endif
/*  Round To Positive infinity (halfword)

Round each floating point element in the operand "up", i.e.
toward positive infinity before converting the result to a
16 bit signed int.

The result of rounding elements that cannot be represented by
int16_t is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     rtph(...) (rtph_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtph_funcof(X, ...)  \
FUNCOF(             \
    rtph, (   X   ),\
    HDF,  /* TGK */ \
    HF, /* TGW */ \
    HWF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtphhf   FLT16_RTPH
#define     rtphwf     FLT_RTPH
#define     rtphdf     DBL_RTPH
#if QUAD_NLLONG == 1
#   define  rtphqf    LDBL_RTPH
#endif

#define     rtphwhf   VWHF_RTPH
#define     rtphdhf   VDHF_RTPH
#define     rtphdwf   VDWF_RTPH

#define     rtphqhf   VQHF_RTPH
#define     rtphqwf   VQWF_RTPH
#define     rtphqdf   VQDF_RTPH
#if _LEAVE_RTPH
}
#endif

#if _ENTER_RTPW
{
#endif
/*  Round To Positive infinity (word)

Round each floating point element in the operand "up", i.e.
toward positive infinity before converting the result to an
8 bit signed int.

The result of rounding elements that cannot be represented by
int8_t is implementation defined.

If any element is NaN, the result is undefined.
*/

#define     rtpw(...) (rtpw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtpw_funcof(X, ...)  \
FUNCOF(             \
    rtpw, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    WDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtpwhf   FLT16_RTPW
#define     rtpwwf     FLT_RTPW
#define     rtpwdf     DBL_RTPW
#if QUAD_NLLONG == 1
#   define  rtpwqf    LDBL_RTPW
#endif

#define     rtpwwhf   VWHF_RTPW
#define     rtpwwwf   VWWF_RTPW

#define     rtpwdhf   VDHF_RTPW
#define     rtpwdwf   VDWF_RTPW
#define     rtpwddf   VDDF_RTPW

#define     rtpwqhf   VQHF_RTPW
#define     rtpwqwf   VQWF_RTPW
#define     rtpwqdf   VQDF_RTPW
#if _LEAVE_RTPW
}
#endif

#if _ENTER_RTPD
{
#endif
/*  Round To Positive infinity (doubleword)

Round each floating point element in the operand "up", i.e.
toward positive infinity before converting the result to a
64 bit signed int.

The result of rounding elements that cannot be represented by
int64_t is implementation defined.

If any element is NaN, the entire result is undefined.
*/


#define     rtpd(...) (rtpd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtpd_funcof(X, ...)  \
FUNCOF(             \
    rtpd, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    WDF,  /* TGD */ \
    DF, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtpdhf   FLT16_RTPD
#define     rtpdwf     FLT_RTPD
#define     rtpddf     DBL_RTPD
#if QUAD_NLLONG == 1
#   define  rtpdqf    LDBL_RTPD
#endif

#define     rtpdwhf   VWHF_RTPD
#define     rtpdwwf   VWWF_RTPD

#define     rtpddhf   VDHF_RTPD
#define     rtpddwf   VDWF_RTPD
#define     rtpdddf   VDDF_RTPD

#define     rtpdqhf   VQHF_RTPD
#define     rtpdqwf   VQWF_RTPD
#define     rtpdqdf   VQDF_RTPD
#if _LEAVE_RTPD
}
#endif

#if _ENTER_RTPF
{
#endif
/*  Round To Positive infinity (float)

Round each floating point element in the operand "up", i.e.
toward positive infinity, without conversion to an integer
type.

If any element is NaN, the entire result is undefined.
*/

#define     rtpf(...) (rtpf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     rtpf_funcof(X, ...)  \
FUNCOF(             \
    rtpf, (   X   ),\
    HDF,  /* TGK */ \
    HWF,  /* TGW */ \
    HDF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     rtpfhf   FLT16_RTPF
#define     rtpfwf     FLT_RTPF
#define     rtpfdf     DBL_RTPF
#if QUAD_NLLONG == 1
#   define  rtpfqf    LDBL_RTPF
#endif

#define     rtpfwhf   VWHF_RTPF
#define     rtpfwwf   VWWF_RTPF

#define     rtpfdhf   VDHF_RTPF
#define     rtpfdwf   VDWF_RTPF
#define     rtpfddf   VDDF_RTPF

#define     rtpfqhf   VQHF_RTPF
#define     rtpfqwf   VQWF_RTPF
#define     rtpfqdf   VQDF_RTPF
#if _LEAVE_RTPF
}
#endif


#if _ENTER_SEQW
{
#endif
/*  linear word SEQuence

Construct a 32 bit vector that represents a linear range.
The first operand is the start and the second is the step.
The second operand is always signed, which facilitates
descending unsigned sequences.

If any element in the range cannot be represented by the
element type, the result is undefined.

TODO: consider adding floats
*/

#define     seqw(...) (seqw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     seqw_funcof(A, ...) \
FUNCOF(             \
    seqw,   A,          \
    BHZ,  /* TGK */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     seqwbu       UINT8_SEQW
#define     seqwbi        INT8_SEQW
#define     seqwbc        CHAR_SEQW
#define     seqwhu      UINT16_SEQW
#define     seqwhi       INT16_SEQW
#if _LEAVE_SEQW
}
#endif

#if _ENTER_SEQD
{
#endif
/*  linear doubleword SEQuence

Construct a 64 bit vector that represents a linear range.
The first operand is the start and the second is the step.
The second operand is always signed, which facilitates
descending unsigned sequences.

If any element in the range cannot be represented by the
element type, the result is undefined.

TODO: consider adding floats
*/

#define     seqd(...) (seqd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     seqd_funcof(A, ...) \
FUNCOF(             \
    seqd,   A,          \
    BWZ,  /* TGK */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     seqdbu       UINT8_SEQD
#define     seqdbi        INT8_SEQD
#define     seqdbc        CHAR_SEQD
#define     seqdhu      UINT16_SEQD
#define     seqdhi       INT16_SEQD
#define     seqdwu      UINT32_SEQD
#define     seqdwi       INT32_SEQD
#if DWRD_NLONG == 2
#   define  seqdlu       ULONG_SEQD
#   define  seqdli        LONG_SEQD
#endif

#if _LEAVE_SEQD
}
#endif

#if _ENTER_SEQQ
{
#endif
/*  linear quadword SEQuence

Construct a 128 bit vector that represents a linear range.
The first operand is the start and the second is the step.
The second operand is always signed, which facilitates
descending unsigned sequences.

If any element in the range cannot be represented by the
element type, the result is undefined.

TODO: consider adding floats
*/

#define     seqq(...) (seqq_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     seqq_funcof(A, ...) \
FUNCOF(             \
    seqq,   A,          \
    BDZ,  /* TGK */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     seqqbu       UINT8_SEQQ
#define     seqqbi        INT8_SEQQ
#define     seqqbc        CHAR_SEQQ
#define     seqqhu      UINT16_SEQQ
#define     seqqhi       INT16_SEQQ
#define     seqqwu      UINT32_SEQQ
#define     seqqwi       INT32_SEQQ
#define     seqqdu      UINT64_SEQQ
#define     seqqdi       INT64_SEQQ
#if DWRD_NLONG == 2
#   define  seqqlu       ULONG_SEQQ
#   define  seqqli        LONG_SEQQ
#elif QUAD_NLLONG == 2
#   define  seqqlu      ULLONG_SEQQ
#   define  seqqli       LLONG_SEQQ
#endif

#if _LEAVE_SEQQ
}
#endif


#if _ENTER_SET1
{
#endif
/*  Replace a single vector element 

*/

#define     set1(...)    (set1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     set1_funcof(D, ...) \
FUNCOF(             \
    set1, (   D   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     set1wyu     VWYU_SET1
#define     set1wbu     VWBU_SET1
#define     set1wbi     VWBI_SET1
#define     set1wbc     VWBC_SET1
#define     set1whu     VWHU_SET1
#define     set1whi     VWHI_SET1
#define     set1whf     VWHF_SET1

#define     set1dyu     VDYU_SET1
#define     set1dbu     VDBU_SET1
#define     set1dbi     VDBI_SET1
#define     set1dbc     VDBC_SET1
#define     set1dhu     VDHU_SET1
#define     set1dhi     VDHI_SET1
#define     set1dhf     VDHF_SET1
#define     set1dwu     VDWU_SET1
#define     set1dwi     VDWI_SET1
#define     set1dwf     VDWF_SET1

#define     set1qyu     VQYU_SET1
#define     set1qbu     VQBU_SET1
#define     set1qbi     VQBI_SET1
#define     set1qbc     VQBC_SET1
#define     set1qhu     VQHU_SET1
#define     set1qhi     VQHI_SET1
#define     set1qhf     VQHF_SET1
#define     set1qwu     VQWU_SET1
#define     set1qwi     VQWI_SET1
#define     set1qwf     VQWF_SET1
#define     set1qdu     VQDU_SET1
#define     set1qdi     VQDI_SET1
#define     set1qdf     VQDF_SET1
#if _LEAVE_SET1
}
#endif

#if _ENTER_SETL
{
#endif
/*  Replace lower half */

#define     setl(...)   ( (setl_funcof(__VA_ARGS__))(__VA_ARGS__) )
#define     setl_funcof(D, ...)  FUNCOF(\
    setl, (   D   ),\
    HDZ,       \
    NONE, /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     setlhu    UINT16_SETL
#define     setlhi     INT16_SETL
#define     setlwu    UINT32_SETL
#define     setlwi     INT32_SETL
#define     setldu    UINT64_SETL
#define     setldi     INT64_SETL
#if (DWRD_NLONG==2)
#   define  setllu     ULONG_SETL
#   define  setlli      LONG_SETL
#elif QUAD_NLLONG == 2
#   define  setllu    ULLONG_SETL
#   define  setlli     LLONG_SETL
#else
#   define  setlqu    ULLONG_SETL
#   define  setlqi     LLONG_SETL
#endif

#define     setldyu     VDYU_SETL
#define     setldbu     VDBU_SETL
#define     setldbi     VDBI_SETL
#define     setldbc     VDBC_SETL
#define     setldhu     VDHU_SETL
#define     setldhi     VDHI_SETL
#define     setldhf     VDHF_SETL
#define     setldwu     VDWU_SETL
#define     setldwi     VDWI_SETL
#define     setldwf     VDWF_SETL

#define     setlqyu     VQYU_SETL
#define     setlqbu     VQBU_SETL
#define     setlqbi     VQBI_SETL
#define     setlqbc     VQBC_SETL
#define     setlqhu     VQHU_SETL
#define     setlqhi     VQHI_SETL
#define     setlqhf     VQHF_SETL
#define     setlqwu     VQWU_SETL
#define     setlqwi     VQWI_SETL
#define     setlqwf     VQWF_SETL
#define     setlqdu     VQDU_SETL
#define     setlqdi     VQDI_SETL
#define     setlqdf     VQDF_SETL
#if _LEAVE_SETL
}
#endif

#if _ENTER_SETR
{
#endif
/* Replace vector upper half

TODO: make an op that sets the upper half of each element
*/

#define     setr(...)  ( (setr_funcof(__VA_ARGS__))(__VA_ARGS__) )
#define     setr_funcof(D, ...)  \
FUNCOF(             \
    setr, (   D   ),\
    HDZ,  /* TGK */ \
    NONE, /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     setrhu    UINT16_SETR
#define     setrhi     INT16_SETR
#define     setrwu    UINT32_SETR
#define     setrwi     INT32_SETR
#define     setrdu    UINT64_SETR
#define     setrdi     INT64_SETR
#if (DWRD_NLONG==2)
#   define  setrlu     ULONG_SETR
#   define  setrli      LONG_SETR
#elif QUAD_NLLONG == 2
#   define  setrlu    ULLONG_SETR
#   define  setrli     LLONG_SETR
#else
#   define  setrqu    ULLONG_SETR
#   define  setrqi     LLONG_SETR
#endif

#define     setrdyu     VDYU_SETR
#define     setrdbu     VDBU_SETR
#define     setrdbi     VDBI_SETR
#define     setrdbc     VDBC_SETR
#define     setrdhu     VDHU_SETR
#define     setrdhi     VDHI_SETR
#define     setrdhf     VDHF_SETR
#define     setrdwu     VDWU_SETR
#define     setrdwi     VDWI_SETR
#define     setrdwf     VDWF_SETR

#define     setrqyu     VQYU_SETR
#define     setrqbu     VQBU_SETR
#define     setrqbi     VQBI_SETR
#define     setrqbc     VQBC_SETR
#define     setrqhu     VQHU_SETR
#define     setrqhi     VQHI_SETR
#define     setrqhf     VQHF_SETR
#define     setrqwu     VQWU_SETR
#define     setrqwi     VQWI_SETR
#define     setrqwf     VQWF_SETR
#define     setrqdu     VQDU_SETR
#define     setrqdi     VQDI_SETR
#define     setrqdf     VQDF_SETR
#if _LEAVE_SETR
}
#endif


#if _ENTER_SHLL
{
#endif
/*  SHift Left (truncated)

Multiply each element in the first operand by the power of
two multiple given as the second number. For N bit ints,
only the least significant N bits of the result are kept.
If the shift amount falls outside the range [0..N], the
result is implementation defined.

For floats, which are generally implemented by adding the
shift amount to its exponent bitfield, the result is
undefined if it exceeds the maximum exponent possible for
a normal class float.

TODO: actually implement for floats 
*/

#define     shll(...) (shll_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     shll_funcof(A, ...)  \
FUNCOF(             \
    shll, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     shllyu    BOOL_SHLL
#define     shllbu   UINT8_SHLL
#define     shllbi    INT8_SHLL
#define     shllbc    CHAR_SHLL
#define     shllhu  UINT16_SHLL
#define     shllhi   INT16_SHLL
#define     shllwu  UINT32_SHLL
#define     shllwi   INT32_SHLL
#define     shlldu  UINT64_SHLL
#define     shlldi   INT64_SHLL
#if   DWRD_NLONG == 2
#   define  shlllu   ULONG_SHLL
#   define  shllli    LONG_SHLL
#elif QUAD_NLLONG == 2
#   define  shlllu  ULLONG_SHLL
#   define  shllli   LLONG_SHLL
#else
#   define  shllqu  ULLONG_SHLL
#   define  shllqi   LLONG_SHLL
#endif

#define     shllwyu   VWYU_SHLL
#define     shllwbu   VWBU_SHLL
#define     shllwbi   VWBI_SHLL
#define     shllwbc   VWBC_SHLL
#define     shllwhu   VWHU_SHLL
#define     shllwhi   VWHI_SHLL
#define     shllwwu   VWWU_SHLL
#define     shllwwi   VWWI_SHLL

#define     shlldyu   VDYU_SHLL
#define     shlldbu   VDBU_SHLL
#define     shlldbi   VDBI_SHLL
#define     shlldbc   VDBC_SHLL
#define     shlldhu   VDHU_SHLL
#define     shlldhi   VDHI_SHLL
#define     shlldwu   VDWU_SHLL
#define     shlldwi   VDWI_SHLL
#define     shllddu   VDDU_SHLL
#define     shllddi   VDDI_SHLL

#define     shllqyu   VQYU_SHLL
#define     shllqbu   VQBU_SHLL
#define     shllqbi   VQBI_SHLL
#define     shllqbc   VQBC_SHLL
#define     shllqhu   VQHU_SHLL
#define     shllqhi   VQHI_SHLL
#define     shllqwu   VQWU_SHLL
#define     shllqwi   VQWI_SHLL
#define     shllqdu   VQDU_SHLL
#define     shllqdi   VQDI_SHLL
#if _LEAVE_SHLL
}
#endif

#if _ENTER_SHLS
{
#endif
/*  SHift Left (saturated)

    Shift the binary representation of each element in
    the operand left by the specified number of bits. For
    each bit shifted out, one '0' is shifted in. If the
    result of shifting a positive value is greater than
    the maximum value the operand type can represent, the
    result is the maximum. If the result of shifting a
    negative value is less than the minimum value the
    operand type can represent, the result is the minimum.
*/

#define     shls(...) (shls_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     shls_funcof(A, ...)  \
FUNCOF(             \
    shls, (   A   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     shlsbu   UINT8_SHLS
#define     shlsbi    INT8_SHLS
#define     shlsbc    CHAR_SHLS
#define     shlshu  UINT16_SHLS
#define     shlshi   INT16_SHLS
#define     shlswu  UINT32_SHLS
#define     shlswi   INT32_SHLS
#define     shlsdu  UINT64_SHLS
#define     shlsdi   INT64_SHLS
#if   DWRD_NLONG == 2
#   define  shlslu   ULONG_SHLS
#   define  shlsli    LONG_SHLS
#elif QUAD_NLLONG == 2
#   define  shlslu  ULLONG_SHLS
#   define  shlsli   LLONG_SHLS
#else
#   define  shlsqu  ULLONG_SHLS
#   define  shlsqi   LLONG_SHLS
#endif

#define     shlswbu   VWBU_SHLS
#define     shlswbi   VWBI_SHLS
#define     shlswbc   VWBC_SHLS
#define     shlswhu   VWHU_SHLS
#define     shlswhi   VWHI_SHLS
#define     shlswwu   VWWU_SHLS
#define     shlswwi   VWWI_SHLS

#define     shlsdbu   VDBU_SHLS
#define     shlsdbi   VDBI_SHLS
#define     shlsdbc   VDBC_SHLS
#define     shlsdhu   VDHU_SHLS
#define     shlsdhi   VDHI_SHLS
#define     shlsdwu   VDWU_SHLS
#define     shlsdwi   VDWI_SHLS
#define     shlsddu   VDDU_SHLS
#define     shlsddi   VDDI_SHLS

#define     shlsqbu   VQBU_SHLS
#define     shlsqbi   VQBI_SHLS
#define     shlsqbc   VQBC_SHLS
#define     shlsqhu   VQHU_SHLS
#define     shlsqhi   VQHI_SHLS
#define     shlsqwu   VQWU_SHLS
#define     shlsqwi   VQWI_SHLS
#define     shlsqdu   VQDU_SHLS
#define     shlsqdi   VQDI_SHLS
#if _LEAVE_SHLS
}
#endif

#if _ENTER_SHLR
{
#endif
/*  SHift Left (carry upper)

For B bit integers: shift the operand left by the
specified number of bits, forming a 2B bit intermediate
result and keeping its upper B bits.

For vectors of B bit integers: shift each element by the
specified number of bits, forming an intermediate vector
vector consisting of the same number of 2B bit elements
before extracting each of its elements' upper B bits.
*/

#define     shlr(...) (shlr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     shlr_funcof(A, ...)  \
FUNCOF(             \
    shlr, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     shlryu    BOOL_SHLR
#define     shlrbu   UINT8_SHLR
#define     shlrbi    INT8_SHLR
#define     shlrbc    CHAR_SHLR
#define     shlrhu  UINT16_SHLR
#define     shlrhi   INT16_SHLR
#define     shlrwu  UINT32_SHLR
#define     shlrwi   INT32_SHLR
#define     shlrdu  UINT64_SHLR
#define     shlrdi   INT64_SHLR
#if   DWRD_NLONG == 2
#   define  shlrlu   ULONG_SHLR
#   define  shlrli    LONG_SHLR
#elif QUAD_NLLONG == 2
#   define  shlrlu  ULLONG_SHLR
#   define  shlrli   LLONG_SHLR
#else
#   define  shlrqu  ULLONG_SHLR
#   define  shlrqi   LLONG_SHLR
#endif

#define     shlrwyu   VWYU_SHLR
#define     shlrwbu   VWBU_SHLR
#define     shlrwbi   VWBI_SHLR
#define     shlrwbc   VWBC_SHLR
#define     shlrwhu   VWHU_SHLR
#define     shlrwhi   VWHI_SHLR
#define     shlrwwu   VWWU_SHLR
#define     shlrwwi   VWWI_SHLR

#define     shlrdyu   VDYU_SHLR
#define     shlrdbu   VDBU_SHLR
#define     shlrdbi   VDBI_SHLR
#define     shlrdbc   VDBC_SHLR
#define     shlrdhu   VDHU_SHLR
#define     shlrdhi   VDHI_SHLR
#define     shlrdwu   VDWU_SHLR
#define     shlrdwi   VDWI_SHLR
#define     shlrddu   VDDU_SHLR
#define     shlrddi   VDDI_SHLR

#define     shlrqyu   VQYU_SHLR
#define     shlrqbu   VQBU_SHLR
#define     shlrqbi   VQBI_SHLR
#define     shlrqbc   VQBC_SHLR
#define     shlrqhu   VQHU_SHLR
#define     shlrqhi   VQHI_SHLR
#define     shlrqwu   VQWU_SHLR
#define     shlrqwi   VQWI_SHLR
#define     shlrqdu   VQDU_SHLR
#define     shlrqdi   VQDI_SHLR
#if _LEAVE_SHLR
}
#endif

#if _ENTER_SHL2
{
#endif
/*  SHift Left (widened×2)

Arithmetically left shift each N bit integer in the
operand A by 1..N bits. The result has an element size
twice as wide as the element size of A.
*/

#define     shl2(...) (shl2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     shl2_funcof(A, ...)  \
FUNCOF(             \
    shl2, (   A   ),\
    BWZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BWZ,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     shl2bu   UINT8_SHL2
#define     shl2bi    INT8_SHL2
#define     shl2bc    CHAR_SHL2
#define     shl2hu  UINT16_SHL2
#define     shl2hi   INT16_SHL2
#define     shl2wu  UINT32_SHL2
#define     shl2wi   INT32_SHL2
#if   DWRD_NLONG == 2
#   define  shl2lu   ULONG_SHL2
#   define  shl2li    LONG_SHL2
#elif QUAD_NLLONG == 2
#   define  shl2lu  ULLONG_SHL2
#   define  shl2li   LLONG_SHL2
#endif

#define     shl2wbu   VWBU_SHL2
#define     shl2wbi   VWBI_SHL2
#define     shl2wbc   VWBC_SHL2
#define     shl2whu   VWHU_SHL2
#define     shl2whi   VWHI_SHL2
#define     shl2wwu   VWWU_SHL2
#define     shl2wwi   VWWI_SHL2

#define     shl2dbu   VDBU_SHL2
#define     shl2dbi   VDBI_SHL2
#define     shl2dbc   VDBC_SHL2
#define     shl2dhu   VDHU_SHL2
#define     shl2dhi   VDHI_SHL2
#define     shl2dwu   VDWU_SHL2
#define     shl2dwi   VDWI_SHL2

#define     shl2qbu   VQBU_SHL2
#define     shl2qbi   VQBI_SHL2
#define     shl2qbc   VQBC_SHL2
#define     shl2qhu   VQHU_SHL2
#define     shl2qhi   VQHI_SHL2
#define     shl2qwu   VQWU_SHL2
#define     shl2qwi   VQWI_SHL2
#if _LEAVE_SHL2
}
#endif


#if _ENTER_SHRS
{
#endif
/*  SHift Right (saturated)

Shift the integer operand's binary representation
right by the specified number of digits. For unsigned
operands, a zero bit is shifted in for each bit
shifted out. For signed operands, a copy of the sign
bit is shifted in.
*/

#define     shrs(...) (shrs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     shrs_funcof(A, ...)  \
FUNCOF(             \
    shrs, (   A   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     shrsbu   UINT8_SHRS
#define     shrsbi    INT8_SHRS
#define     shrsbc    CHAR_SHRS
#define     shrshu  UINT16_SHRS
#define     shrshi   INT16_SHRS
#define     shrswu  UINT32_SHRS
#define     shrswi   INT32_SHRS
#define     shrsdu  UINT64_SHRS
#define     shrsdi   INT64_SHRS
#if   DWRD_NLONG == 2
#   define  shrslu   ULONG_SHRS
#   define  shrsli    LONG_SHRS
#elif QUAD_NLLONG == 2
#   define  shrslu  ULLONG_SHRS
#   define  shrsli   LLONG_SHRS
#else
#   define  shrsqu  ULLONG_SHRS
#   define  shrsqi   LLONG_SHRS
#endif

#define     shrswbu   VWBU_SHRS
#define     shrswbi   VWBI_SHRS
#define     shrswbc   VWBC_SHRS
#define     shrswhu   VWHU_SHRS
#define     shrswhi   VWHI_SHRS
#define     shrswwu   VWWU_SHRS
#define     shrswwi   VWWI_SHRS

#define     shrsdbu   VDBU_SHRS
#define     shrsdbi   VDBI_SHRS
#define     shrsdbc   VDBC_SHRS
#define     shrsdhu   VDHU_SHRS
#define     shrsdhi   VDHI_SHRS
#define     shrsdwu   VDWU_SHRS
#define     shrsdwi   VDWI_SHRS
#define     shrsddu   VDDU_SHRS
#define     shrsddi   VDDI_SHRS

#define     shrsqbu   VQBU_SHRS
#define     shrsqbi   VQBI_SHRS
#define     shrsqbc   VQBC_SHRS
#define     shrsqhu   VQHU_SHRS
#define     shrsqhi   VQHI_SHRS
#define     shrsqwu   VQWU_SHRS
#define     shrsqwi   VQWI_SHRS
#define     shrsqdu   VQDU_SHRS
#define     shrsqdi   VQDI_SHRS
#if _LEAVE_SHRS
}
#endif


#if _ENTER_SILL
{
#endif
/*  Shift/Insert Left (from lo)

Shift the binary representation of each element in the
first operand A left by the number of bits specified by
the third operand C. The least significant C bits of the
corresponding element of the second operand B are shifted
in.

    sill(a,b,c) => (a<<c)|(b[:c])

*/

#define     sill(...) (sill_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sill_funcof(A, ...)  \
FUNCOF(             \
    sill, (   A   ),\
    YDU,  /* TGK */ \
    YWU,  /* TGW */ \
    YDU,  /* TGD */ \
    YDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sillyu    BOOL_SILL
#define     sillbu   UINT8_SILL
#define     sillbc    CHAR_SILL
#define     sillhu  UINT16_SILL
#define     sillwu  UINT32_SILL
#define     silldu  UINT64_SILL
#if   DWRD_NLONG == 2
#   define  silllu   ULONG_SILL
#   define  sillli    LONG_SILL
#elif QUAD_NLLONG == 2
#   define  silllu  ULLONG_SILL
#   define  sillli   LLONG_SILL
#else
#   define  sillqu  ULLONG_SILL
#   define  sillqi   LLONG_SILL
#endif

#define     sillwyu   VWYU_SILL
#define     sillwbu   VWBU_SILL
#define     sillwbc   VWBC_SILL
#define     sillwhu   VWHU_SILL
#define     sillwwu   VWWU_SILL

#define     silldyu   VDYU_SILL
#define     silldbu   VDBU_SILL
#define     silldbc   VDBC_SILL
#define     silldhu   VDHU_SILL
#define     silldwu   VDWU_SILL
#define     sillddu   VDDU_SILL

#define     sillqyu   VQYU_SILL
#define     sillqbu   VQBU_SILL
#define     sillqbc   VQBC_SILL
#define     sillqhu   VQHU_SILL
#define     sillqwu   VQWU_SILL
#define     sillqdu   VQDU_SILL
#if _LEAVE_SILL
}
#endif

#if _ENTER_SILR
{
#endif
/*  Shift/Insert Left (from hi)

Shift the binary representation of each element in the
first operand A left by the number of bits specified by
the third operand C. The most significant C bits of the
corresponding element of the second operand B are shifted
in.

    silr(a,b,c) => (a<<c)|(b[-c:])

*/

#define     silr(...) (silr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     silr_funcof(A, ...)  \
FUNCOF(             \
    silr, (   A   ),\
    YDU,  /* TGK */ \
    YWU,  /* TGW */ \
    YDU,  /* TGD */ \
    YDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     silryu    BOOL_SILR
#define     silrbu   UINT8_SILR
#define     silrbc    CHAR_SILR
#define     silrhu  UINT16_SILR
#define     silrwu  UINT32_SILR
#define     silrdu  UINT64_SILR
#if   DWRD_NLONG == 2
#   define  silrlu   ULONG_SILR
#   define  silrli    LONG_SILR
#elif QUAD_NLLONG == 2
#   define  silrlu  ULLONG_SILR
#   define  silrli   LLONG_SILR
#else
#   define  silrqu  ULLONG_SILR
#   define  silrqi   LLONG_SILR
#endif

#define     silrwyu   VWYU_SILR
#define     silrwbu   VWBU_SILR
#define     silrwbc   VWBC_SILR
#define     silrwhu   VWHU_SILR
#define     silrwwu   VWWU_SILR

#define     silrdyu   VDYU_SILR
#define     silrdbu   VDBU_SILR
#define     silrdbc   VDBC_SILR
#define     silrdhu   VDHU_SILR
#define     silrdwu   VDWU_SILR
#define     silrddu   VDDU_SILR

#define     silrqyu   VQYU_SILR
#define     silrqbu   VQBU_SILR
#define     silrqbc   VQBC_SILR
#define     silrqhu   VQHU_SILR
#define     silrqwu   VQWU_SILR
#define     silrqdu   VQDU_SILR
#if _LEAVE_SILR
}
#endif



#if _ENTER_SIRR
{
#endif
/*  Shift/Insert Right (from hi)

Shift the binary representation of each element in the
first operand A right by the number of bits specified by
the third operand C. The most significant C bits of the
corresponding element of the second operand B are shifted
in.

    sirr(a,b,c) => (a>>c)|(b[-c:])

If C is less than 0 or greater than the element width, the
result is undefined.

TODO: debate implementing ops for signed ints. If the answer
is "no", delete the reserved signed scalar op defines
*/

#define     sirr(...) (sirr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sirr_funcof(A, ...)  \
FUNCOF(             \
    sirr, (   A   ),\
    YDU,  /* TGK */ \
    YWU,  /* TGW */ \
    YDU,  /* TGD */ \
    YDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sirryu    BOOL_SIRR
#define     sirrbu   UINT8_SIRR
#define     sirrbc    CHAR_SIRR
#define     sirrhu  UINT16_SIRR
#define     sirrwu  UINT32_SIRR
#define     sirrdu  UINT64_SIRR
#if   DWRD_NLONG == 2
#   define  sirrlu   ULONG_SIRR
#   define  sirrli    LONG_SIRR
#elif QUAD_NLLONG == 2
#   define  sirrlu  ULLONG_SIRR
#   define  sirrli   LLONG_SIRR
#else
#   define  sirrqu  ULLONG_SIRR
#   define  sirrqi   LLONG_SIRR
#endif

#define     sirrwyu   VWYU_SIRR
#define     sirrwbu   VWBU_SIRR
#define     sirrwbc   VWBC_SIRR
#define     sirrwhu   VWHU_SIRR
#define     sirrwwu   VWWU_SIRR

#define     sirrdyu   VDYU_SIRR
#define     sirrdbu   VDBU_SIRR
#define     sirrdbc   VDBC_SIRR
#define     sirrdhu   VDHU_SIRR
#define     sirrdwu   VDWU_SIRR
#define     sirrddu   VDDU_SIRR

#define     sirrqyu   VQYU_SIRR
#define     sirrqbu   VQBU_SIRR
#define     sirrqbc   VQBC_SIRR
#define     sirrqhu   VQHU_SIRR
#define     sirrqwu   VQWU_SIRR
#define     sirrqdu   VQDU_SIRR
#if _LEAVE_SIRR
}
#endif


#if _ENTER_SIRL
{
#endif
/*  Shift/Insert Right (from hi)

Shift the binary representation of each element in the
first operand A right by the number of bits specified by
the third operand C. The most significant C bits of the
corresponding element of the second operand B are shifted
in.

    sirl(a,b,c) => (a>>c)|(b[-c:])

If C is less than 0 or greater than the element width, the
result is undefined.

TODO: debate implementing ops for signed ints. If the answer
is "no", delete the reserved signed scalar op defines
*/

#define     sirl(...) (sirl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sirl_funcof(A, ...)  \
FUNCOF(             \
    sirl, (   A   ),\
    YDU,  /* TGK */ \
    YWU,  /* TGW */ \
    YDU,  /* TGD */ \
    YDU,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sirlyu    BOOL_SIRL
#define     sirlbu   UINT8_SIRL
#define     sirlbc    CHAR_SIRL
#define     sirlhu  UINT16_SIRL
#define     sirlwu  UINT32_SIRL
#define     sirldu  UINT64_SIRL
#if   DWRD_NLONG == 2
#   define  sirllu   ULONG_SIRL
#   define  sirlli    LONG_SIRL
#elif QUAD_NLLONG == 2
#   define  sirllu  ULLONG_SIRL
#   define  sirlli   LLONG_SIRL
#else
#   define  sirlqu  ULLONG_SIRL
#   define  sirlqi   LLONG_SIRL
#endif

#define     sirlwyu   VWYU_SIRL
#define     sirlwbu   VWBU_SIRL
#define     sirlwbc   VWBC_SIRL
#define     sirlwhu   VWHU_SIRL
#define     sirlwwu   VWWU_SIRL

#define     sirldyu   VDYU_SIRL
#define     sirldbu   VDBU_SIRL
#define     sirldbc   VDBC_SIRL
#define     sirldhu   VDHU_SIRL
#define     sirldwu   VDWU_SIRL
#define     sirlddu   VDDU_SIRL

#define     sirlqyu   VQYU_SIRL
#define     sirlqbu   VQBU_SIRL
#define     sirlqbc   VQBC_SIRL
#define     sirlqhu   VQHU_SIRL
#define     sirlqwu   VQWU_SIRL
#define     sirlqdu   VQDU_SIRL
#if _LEAVE_SIRL
}
#endif

#if _ENTER_SPRL
{
#endif
/*  Shift Pair Right (left fill)

Concatenate two N bit multielement vectors then shift the
N×2 bit intermediate result right by a multiple of its 
element size. The lower N bits of the intermediate result
are kept.

    sprldhu(a, b, c) => (a>>(c*16))|b[:c*16]

*/

#define     sprl(...) (sprl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sprl_funcof(A, ...)  \
FUNCOF(             \
    sprl, (   A   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sprlwyu   VWYU_SPRL
#define     sprlwbu   VWBU_SPRL
#define     sprlwbi   VWBI_SPRL
#define     sprlwbc   VWBC_SPRL
#define     sprlwhu   VWHU_SPRL
#define     sprlwhi   VWHI_SPRL
#define     sprlwhf   VWHF_SPRL

#define     sprldyu   VDYU_SPRL
#define     sprldbu   VDBU_SPRL
#define     sprldbi   VDBI_SPRL
#define     sprldbc   VDBC_SPRL
#define     sprldhu   VDHU_SPRL
#define     sprldhi   VDHI_SPRL
#define     sprldhf   VDHF_SPRL
#define     sprldwu   VDWU_SPRL
#define     sprldwi   VDWI_SPRL
#define     sprldwf   VDWF_SPRL

#define     sprlqyu   VQYU_SPRL
#define     sprlqbu   VQBU_SPRL
#define     sprlqbi   VQBI_SPRL
#define     sprlqbc   VQBC_SPRL
#define     sprlqhu   VQHU_SPRL
#define     sprlqhi   VQHI_SPRL
#define     sprlqhf   VQHF_SPRL
#define     sprlqwu   VQWU_SPRL
#define     sprlqwi   VQWI_SPRL
#define     sprlqwf   VQWF_SPRL
#define     sprlqdu   VQDU_SPRL
#define     sprlqdi   VQDI_SPRL
#define     sprlqdf   VQDF_SPRL
#if _LEAVE_SPRL
}
#endif


#if _ENTER_STR1
{
#endif
/*  STR (atomic store w/ memory_order_relaxed)

Atomically store the value of the second operand SRC at 
the address specified by the first operand DST. 

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_str and memory_order_acquire
*/

#define     str1(...)  (str1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     str1_funcof(A, ...) \
FUNCOF_AK(          \
    str1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     str1ayu    BOOL_STR1A
#define     str1abu   UINT8_STR1A
#define     str1abi    INT8_STR1A
#define     str1abc    CHAR_STR1A
#define     str1ahu  UINT16_STR1A
#define     str1ahi   INT16_STR1A
#define     str1awu  UINT32_STR1A
#define     str1awi   INT32_STR1A
#define     str1adu  UINT64_STR1A
#define     str1adi   INT64_STR1A
#if DWRD_NLONG == 2
#   define  str1alu   ULONG_STR1A
#   define  str1ali    LONG_STR1A
#elif QUAD_NLLONG == 2
#   define  str1alu  ULLONG_STR1A
#   define  str1ali   LLONG_STR1A
#else
#   define  str1aqu  ULLONG_STR1A
#   define  str1aqi   LLONG_STR1A
#endif

#if _LEAVE_STRA
}
#endif

#if _ENTER_STRE
{
#endif
/*  STR (atomic fetch str w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand with the second
operand.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_str and memory_order_release
*/

#define     stre(...)  (stre_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     stre_funcof(A, ...) \
FUNCOF_AK(          \
    stre, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     streayu    BOOL_STREA
#define     streabu   UINT8_STREA
#define     streabi    INT8_STREA
#define     streabc    CHAR_STREA
#define     streahu  UINT16_STREA
#define     streahi   INT16_STREA
#define     streawu  UINT32_STREA
#define     streawi   INT32_STREA
#define     streadu  UINT64_STREA
#define     streadi   INT64_STREA
#if DWRD_NLONG == 2
#   define  strealu   ULONG_STREA
#   define  streali    LONG_STREA
#elif QUAD_NLLONG == 2
#   define  strealu  ULLONG_STREA
#   define  streali   LLONG_STREA
#else
#   define  streaqu  ULLONG_STREA
#   define  streaqi   LLONG_STREA
#endif

#if _LEAVE_STRE
}
#endif

#if _ENTER_STRT
{
#endif
/*  STR (atomic fetch str w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand with the second
operand.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_str and memory_order_seq_cst
*/

#define     strt(...)  (strt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     strt_funcof(A, ...) \
FUNCOF_AK(          \
    strt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     strtayu    BOOL_STRTA
#define     strtabu   UINT8_STRTA
#define     strtabi    INT8_STRTA
#define     strtabc    CHAR_STRTA
#define     strtahu  UINT16_STRTA
#define     strtahi   INT16_STRTA
#define     strtawu  UINT32_STRTA
#define     strtawi   INT32_STRTA
#define     strtadu  UINT64_STRTA
#define     strtadi   INT64_STRTA
#if DWRD_NLONG == 2
#   define  strtalu   ULONG_STRTA
#   define  strtali    LONG_STRTA
#elif QUAD_NLLONG == 2
#   define  strtalu  ULLONG_STRTA
#   define  strtali   LLONG_STRTA
#else
#   define  strtaqu  ULLONG_STRTA
#   define  strtaqi   LLONG_STRTA
#endif

#if _LEAVE_STRT
}
#endif



#if _ENTER_STRW
{
#endif
/*  SToRe (32 bit vector)

Write the contents of a 32 bit vector to memory. If the
address isn't 4 byte aligned, the result is undefined.
*/

#define     strw(...)  (strw_funcof(__VA_ARGS__)(__VA_ARGS__))

#define     strw_funcof(D, ...)  \
FUNCOF_AK(                  \
    strw, (   D   ),\
    NONE, /* TGK */ \
    YWR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     strwayu   BOOL_STRWA
#define     strwabu  UINT8_STRWA
#define     strwabi   INT8_STRWA
#define     strwabc   CHAR_STRWA
#define     strwahu UINT16_STRWA
#define     strwahi  INT16_STRWA
#define     strwahf  FLT16_STRWA
#define     strwawu UINT32_STRWA
#define     strwawi  INT32_STRWA
#define     strwawf    FLT_STRWA
#if   DWRD_NLONG == 2
#   define  strwalu  ULONG_STRWA
#   define  strwali   LONG_STRWA
#endif

#if _LEAVE_STRW
}
#endif

#if _ENTER_STRD
{
#endif
/*  SToRe aligned (64 bit vector)

Write the contents of a 64 bit vector to memory. If the
address isn't 8 byte aligned, the result is undefined.
*/

#define     strd(D, S)  (strd_funcof(D,S)(D,S))
#define     strd_funcof(D, ...)  \
FUNCOF_AK(                  \
    strd, (   D   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     strdayu   BOOL_STRDA
#define     strdabu  UINT8_STRDA
#define     strdabi   INT8_STRDA
#define     strdabc   CHAR_STRDA
#define     strdahu UINT16_STRDA
#define     strdahi  INT16_STRDA
#define     strdahf  FLT16_STRDA
#define     strdawu UINT32_STRDA
#define     strdawi  INT32_STRDA
#define     strdawf    FLT_STRDA
#define     strdadu UINT64_STRDA
#define     strdadi  INT64_STRDA
#define     strdadf    DBL_STRDA
#if   DWRD_NLONG == 2
#   define  strdalu  ULONG_STRDA
#   define  strdali   LONG_STRDA
#elif QUAD_NLLONG == 2
#   define  strdalu ULLONG_STRDA
#   define  strdali  LLONG_STRDA
#endif

#if _LEAVE_STRD
}
#endif

#if _ENTER_STRQ
{
#endif
/*  SToRe aligned (128 bit vector)

Write the contents of a 128 bit vector to memory. If the
address isn't 16 byte aligned, the result is undefined.
*/

#define     strq(...)  (strq_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     strq_funcof(D, ...)  \
FUNCOF_AK(                  \
    strq, (   D   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     strqayu   BOOL_STRQA
#define     strqabu  UINT8_STRQA
#define     strqabi   INT8_STRQA
#define     strqabc   CHAR_STRQA
#define     strqahu UINT16_STRQA
#define     strqahi  INT16_STRQA
#define     strqahf  FLT16_STRQA
#define     strqawu UINT32_STRQA
#define     strqawi  INT32_STRQA
#define     strqawf    FLT_STRQA
#define     strqadu UINT64_STRQA
#define     strqadi  INT64_STRQA
#define     strqadf    DBL_STRQA
#if   DWRD_NLONG == 2
#   define  strqalu  ULONG_STRQA
#   define  strqali   LONG_STRQA
#elif QUAD_NLLONG == 2
#   define  strqalu ULLONG_STRQA
#   define  strqali  LLONG_STRQA
#endif

#if _LEAVE_STRQ
}
#endif

#if _ENTER_SUBL
{
#endif
/*  Subtract (truncated)
*/

#define     subl(...) (subl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     subl_funcof(A, ...)  \
FUNCOF(             \
    subl, (   A   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sublyu    BOOL_SUBL
#define     sublbu   UINT8_SUBL
#define     sublbi    INT8_SUBL
#define     sublbc    CHAR_SUBL
#define     sublhu  UINT16_SUBL
#define     sublhi   INT16_SUBL
#define     sublwu  UINT32_SUBL
#define     sublwi   INT32_SUBL
#define     subldu  UINT64_SUBL
#define     subldi   INT64_SUBL
#if   DWRD_NLONG == 2
#   define  subllu   ULONG_SUBL
#   define  sublli    LONG_SUBL
#elif QUAD_NLLONG == 2
#   define  subllu  ULLONG_SUBL
#   define  sublli   LLONG_SUBL
#else
#   define  sublqu  ULLONG_SUBL
#   define  sublqi   LLONG_SUBL
#endif

#define     sublwyu   VWYU_SUBL
#define     sublwbu   VWBU_SUBL
#define     sublwbi   VWBI_SUBL
#define     sublwbc   VWBC_SUBL
#define     sublwhu   VWHU_SUBL
#define     sublwhi   VWHI_SUBL
#define     sublwwu   VWWU_SUBL
#define     sublwwi   VWWI_SUBL

#define     subldyu   VDYU_SUBL
#define     subldbu   VDBU_SUBL
#define     subldbi   VDBI_SUBL
#define     subldbc   VDBC_SUBL
#define     subldhu   VDHU_SUBL
#define     subldhi   VDHI_SUBL
#define     subldwu   VDWU_SUBL
#define     subldwi   VDWI_SUBL
#define     sublddu   VDDU_SUBL
#define     sublddi   VDDI_SUBL

#define     sublqyu   VQYU_SUBL
#define     sublqbu   VQBU_SUBL
#define     sublqbi   VQBI_SUBL
#define     sublqbc   VQBC_SUBL
#define     sublqhu   VQHU_SUBL
#define     sublqhi   VQHI_SUBL
#define     sublqwu   VQWU_SUBL
#define     sublqwi   VQWI_SUBL
#define     sublqdu   VQDU_SUBL
#define     sublqdi   VQDI_SUBL
#if _LEAVE_SUBL
}
#endif

#if _ENTER_SUB1
{
#endif
/*  SUB (atomic fetch sub w/ memory_order_relaxed)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
difference of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_sub and memory_order_relaxed
*/

#define     sub1(...)  (sub1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sub1_funcof(A, ...) \
FUNCOF_AK(          \
    sub1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sub1ayu    BOOL_SUB1A
#define     sub1abu   UINT8_SUB1A
#define     sub1abi    INT8_SUB1A
#define     sub1abc    CHAR_SUB1A
#define     sub1ahu  UINT16_SUB1A
#define     sub1ahi   INT16_SUB1A
#define     sub1awu  UINT32_SUB1A
#define     sub1awi   INT32_SUB1A
#define     sub1adu  UINT64_SUB1A
#define     sub1adi   INT64_SUB1A
#if DWRD_NLONG == 2
#   define  sub1alu   ULONG_SUB1A
#   define  sub1ali    LONG_SUB1A
#elif QUAD_NLLONG == 2
#   define  sub1alu  ULLONG_SUB1A
#   define  sub1ali   LLONG_SUB1A
#else
#   define  sub1aqu  ULLONG_SUB1A
#   define  sub1aqi   LLONG_SUB1A
#endif
#if _LEAVE_SUB1
}
#endif

#if _ENTER_SUBA
{
#endif
/*  SUB (atomic fetch sub w/ memory_order_acquire)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
difference of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_sub and memory_order_acquire
*/

#define     suba(...)  (suba_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     suba_funcof(A, ...) \
FUNCOF_AK(          \
    suba, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     subaayu    BOOL_SUBAA
#define     subaabu   UINT8_SUBAA
#define     subaabi    INT8_SUBAA
#define     subaabc    CHAR_SUBAA
#define     subaahu  UINT16_SUBAA
#define     subaahi   INT16_SUBAA
#define     subaawu  UINT32_SUBAA
#define     subaawi   INT32_SUBAA
#define     subaadu  UINT64_SUBAA
#define     subaadi   INT64_SUBAA
#if DWRD_NLONG == 2
#   define  subaalu   ULONG_SUBAA
#   define  subaali    LONG_SUBAA
#elif QUAD_NLLONG == 2
#   define  subaalu  ULLONG_SUBAA
#   define  subaali   LLONG_SUBAA
#else
#   define  subaaqu  ULLONG_SUBAA
#   define  subaaqi   LLONG_SUBAA
#endif

#if _LEAVE_SUBA
}
#endif

#if _ENTER_SUBE
{
#endif
/*  SUB (atomic fetch sub w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
difference of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_sub and memory_order_release
*/

#define     sube(...)  (sube_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sube_funcof(A, ...) \
FUNCOF_AK(          \
    sube, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     subeayu    BOOL_SUBEA
#define     subeabu   UINT8_SUBEA
#define     subeabi    INT8_SUBEA
#define     subeabc    CHAR_SUBEA
#define     subeahu  UINT16_SUBEA
#define     subeahi   INT16_SUBEA
#define     subeawu  UINT32_SUBEA
#define     subeawi   INT32_SUBEA
#define     subeadu  UINT64_SUBEA
#define     subeadi   INT64_SUBEA
#if DWRD_NLONG == 2
#   define  subealu   ULONG_SUBEA
#   define  subeali    LONG_SUBEA
#elif QUAD_NLLONG == 2
#   define  subealu  ULLONG_SUBEA
#   define  subeali   LLONG_SUBEA
#else
#   define  subeaqu  ULLONG_SUBEA
#   define  subeaqi   LLONG_SUBEA
#endif

#if _LEAVE_SUBE
}
#endif

#if _ENTER_SUBT
{
#endif
/*  SUB (atomic fetch sub w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
difference of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_sub and memory_order_seq_cst
*/

#define     subt(...)  (subt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     subt_funcof(A, ...) \
FUNCOF_AK(          \
    subt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     subtayu    BOOL_SUBTA
#define     subtabu   UINT8_SUBTA
#define     subtabi    INT8_SUBTA
#define     subtabc    CHAR_SUBTA
#define     subtahu  UINT16_SUBTA
#define     subtahi   INT16_SUBTA
#define     subtawu  UINT32_SUBTA
#define     subtawi   INT32_SUBTA
#define     subtadu  UINT64_SUBTA
#define     subtadi   INT64_SUBTA
#if DWRD_NLONG == 2
#   define  subtalu   ULONG_SUBTA
#   define  subtali    LONG_SUBTA
#elif QUAD_NLLONG == 2
#   define  subtalu  ULLONG_SUBTA
#   define  subtali   LLONG_SUBTA
#else
#   define  subtaqu  ULLONG_SUBTA
#   define  subtaqi   LLONG_SUBTA
#endif

#if _LEAVE_SUBT
}
#endif

#if _ENTER_SUBH
{
#endif
/*  SUB (flt16_t)

For each number N in the first operand and each flt16_t
element H in the second operand, compute N-H, with the same
element type as the effective type of the corresponding C
expression. E.g. for all integer types' operations, the
result's element type will be flt16_t. If the first operand's
element type has a higher rank, e.g. float or double, it is
the result's element type.
*/

#define     subh(...) (subh_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     subh_funcof(A, ...)  \
FUNCOF(             \
    subh, (   A   ),\
    YDR,  /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    HDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     subhyu    BOOL_SUBH
#define     subhbu   UINT8_SUBH
#define     subhbi    INT8_SUBH
#define     subhbc    CHAR_SUBH
#define     subhhu  UINT16_SUBH
#define     subhhi   INT16_SUBH
#define     subhhf   FLT16_SUBH
#define     subhwu  UINT32_SUBH
#define     subhwi   INT32_SUBH
#define     subhwf     FLT_SUBH
#define     subhdu  UINT64_SUBH
#define     subhdi   INT64_SUBH
#define     subhdf     DBL_SUBH
#if   DWRD_NLONG == 2
#   define  subhlu   ULONG_SUBH
#   define  subhli    LONG_SUBH
#elif QUAD_NLLONG == 2
#   define  subhlu  ULLONG_SUBH
#   define  subhli   LLONG_SUBH
#else
#   define  subhqu  ULLONG_SUBH
#   define  subhqi   LLONG_SUBH
#   define  subhqf    LDBL_SUBH
#endif

#define     subhwbu   VWBU_SUBH
#define     subhwbi   VWBI_SUBH
#define     subhwbc   VWBC_SUBH
#define     subhwhu   VWHU_SUBH
#define     subhwhi   VWHI_SUBH
#define     subhwhf   VWHF_SUBH

#define     subhdbu   VDBU_SUBH
#define     subhdbi   VDBI_SUBH
#define     subhdbc   VDBC_SUBH
#define     subhdhu   VDHU_SUBH
#define     subhdhi   VDHI_SUBH
#define     subhdhf   VDHF_SUBH
#define     subhdwu   VDWU_SUBH
#define     subhdwi   VDWI_SUBH
#define     subhdwf   VDWF_SUBH

#define     subhqhu   VQHU_SUBH
#define     subhqhi   VQHI_SUBH
#define     subhqhf   VQHF_SUBH
#define     subhqwu   VQWU_SUBH
#define     subhqwi   VQWI_SUBH
#define     subhqwf   VQWF_SUBH
#define     subhqdu   VQDU_SUBH
#define     subhqdi   VQDI_SUBH
#define     subhqdf   VQDF_SUBH
#if _LEAVE_SUBH
}
#endif

#if _ENTER_SUBW
{
#endif
/*  SUBtract (float)

For each number N in the first operand and each float
element W in the second operand, compute N-W. The result's
element type is identical to the effective type of the
corresponding C expression 'N-W'.

If the result is too large for a float to represent, the
result is implementation defined.
*/

#define     subw(...) (subw_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     subw_funcof(A, ...)  \
FUNCOF(             \
    subw, (   A   ),\
    YDR,  /* TGK */ \
    BWR,  /* TGW */ \
    HDR,  /* TGD */ \
    WDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     subwyu    BOOL_SUBW
#define     subwbu   UINT8_SUBW
#define     subwbi    INT8_SUBW
#define     subwbc    CHAR_SUBW
#define     subwhu  UINT16_SUBW
#define     subwhi   INT16_SUBW
#define     subwhf   FLT16_SUBW
#define     subwwu  UINT32_SUBW
#define     subwwi   INT32_SUBW
#define     subwwf     FLT_SUBW
#define     subwdu  UINT64_SUBW
#define     subwdi   INT64_SUBW
#define     subwdf     DBL_SUBW
#if   DWRD_NLONG == 2
#   define  subwlu   ULONG_SUBW
#   define  subwli    LONG_SUBW
#elif QUAD_NLLONG == 2
#   define  subwlu  ULLONG_SUBW
#   define  subwli   LLONG_SUBW
#else
#   define  subwqu  ULLONG_SUBW
#   define  subwqi   LLONG_SUBW
#   define  subwqf    LDBL_SUBW
#endif

#define     subwwbu   VWBU_SUBW
#define     subwwbi   VWBI_SUBW
#define     subwwbc   VWBC_SUBW
#define     subwwhu   VWHU_SUBW
#define     subwwhi   VWHI_SUBW
#define     subwwhf   VWHF_SUBW
#define     subwwwu   VWWU_SUBW
#define     subwwwi   VWWI_SUBW
#define     subwwwf   VWWF_SUBW

#define     subwdhu   VDHU_SUBW
#define     subwdhi   VDHI_SUBW
#define     subwdhf   VDHF_SUBW
#define     subwdwu   VDWU_SUBW
#define     subwdwi   VDWI_SUBW
#define     subwdwf   VDWF_SUBW
#define     subwddu   VDDU_SUBW
#define     subwddi   VDDI_SUBW
#define     subwddf   VDDF_SUBW

#define     subwqwu   VQWU_SUBW
#define     subwqwi   VQWI_SUBW
#define     subwqwf   VQWF_SUBW
#define     subwqdu   VQDU_SUBW
#define     subwqdi   VQDI_SUBW
#define     subwqdf   VQDF_SUBW
#if _LEAVE_SUBW
}
#endif

#if _ENTER_SUBD
{
#endif
/*  SUBtract (double)

For each number N in the first operand and each double
element D in the second operand, compute N-D. The result's
element type is identical to the effective type of the
corresponding C expression 'N-D'.

If the result is too large for a double to represent, the
result is implementation defined.
*/

#define     subd(...) (subd_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     subd_funcof(A, ...)  \
FUNCOF(             \
    subd, (   A   ),\
    YDR,  /* TGK */ \
    HWR,  /* TGW */ \
    WDR,  /* TGD */ \
    DR, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     subdyu    BOOL_SUBD
#define     subdbu   UINT8_SUBD
#define     subdbi    INT8_SUBD
#define     subdbc    CHAR_SUBD
#define     subdhu  UINT16_SUBD
#define     subdhi   INT16_SUBD
#define     subdhf   FLT16_SUBD
#define     subdwu  UINT32_SUBD
#define     subdwi   INT32_SUBD
#define     subdwf     FLT_SUBD
#define     subddu  UINT64_SUBD
#define     subddi   INT64_SUBD
#define     subddf     DBL_SUBD
#if   DWRD_NLONG == 2
#   define  subdlu   ULONG_SUBD
#   define  subdli    LONG_SUBD
#elif QUAD_NLLONG == 2
#   define  subdlu  ULLONG_SUBD
#   define  subdli   LLONG_SUBD
#else
#   define  subdqu  ULLONG_SUBD
#   define  subdqi   LLONG_SUBD
#   define  subdqf    LDBL_SUBD
#endif

#define     subdwhu   VWHU_SUBD
#define     subdwhi   VWHI_SUBD
#define     subdwhf   VWHF_SUBD
#define     subdwwu   VWWU_SUBD
#define     subdwwi   VWWI_SUBD
#define     subdwwf   VWWF_SUBD

#define     subddwu   VDWU_SUBD
#define     subddwi   VDWI_SUBD
#define     subddwf   VDWF_SUBD
#define     subdddu   VDDU_SUBD
#define     subdddi   VDDI_SUBD
#define     subdddf   VDDF_SUBD

#define     subdqdu   VQDU_SUBD
#define     subdqdi   VQDI_SUBD
#define     subdqdf   VQDF_SUBD
#if _LEAVE_SUBD
}
#endif


#if _ENTER_SUML
{
#endif
/*  SUM (truncated)
*/

#define     suml(...) (suml_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     suml_funcof(A, ...)  \
FUNCOF(             \
    suml, (   A   ),\
    NONE, /* TGK */ \
    YHZ,  /* TGW */ \
    YWZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sumlwyu   VWYU_SUML
#define     sumlwbu   VWBU_SUML
#define     sumlwbi   VWBI_SUML
#define     sumlwbc   VWBC_SUML
#define     sumlwhu   VWHU_SUML
#define     sumlwhi   VWHI_SUML

#define     sumldyu   VDYU_SUML
#define     sumldbu   VDBU_SUML
#define     sumldbi   VDBI_SUML
#define     sumldbc   VDBC_SUML
#define     sumldhu   VDHU_SUML
#define     sumldhi   VDHI_SUML
#define     sumldwu   VDWU_SUML
#define     sumldwi   VDWI_SUML

#define     sumlqyu   VQYU_SUML
#define     sumlqbu   VQBU_SUML
#define     sumlqbi   VQBI_SUML
#define     sumlqbc   VQBC_SUML
#define     sumlqhu   VQHU_SUML
#define     sumlqhi   VQHI_SUML
#define     sumlqwu   VQWU_SUML
#define     sumlqwi   VQWI_SUML
#define     sumlqdu   VQDU_SUML
#define     sumlqdi   VQDI_SUML
#if _LEAVE_SUML
}
#endif

#if _ENTER_SUM2
{
#endif
/*  SUM (widened×2)
*/

#define     sum2(...) (sum2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sum2_funcof(A, ...)  \
FUNCOF(             \
    sum2,   (   A   ),  \
    NONE, /* TGK */ \
    BHZ,  /* TGW */ \
    BWZ,  /* TGD */ \
    BWZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sum2wyu   VWYU_SUM2
#define     sum2wbu   VWBU_SUM2
#define     sum2wbi   VWBI_SUM2
#define     sum2wbc   VWBC_SUM2
#define     sum2whu   VWHU_SUM2
#define     sum2whi   VWHI_SUM2

#define     sum2dbu   VDBU_SUM2
#define     sum2dbi   VDBI_SUM2
#define     sum2dbc   VDBC_SUM2
#define     sum2dhu   VDHU_SUM2
#define     sum2dhi   VDHI_SUM2
#define     sum2dwu   VDWU_SUM2
#define     sum2dwi   VDWI_SUM2

#define     sum2qyu   VQYU_SUM2
#define     sum2qbu   VQBU_SUM2
#define     sum2qbi   VQBI_SUM2
#define     sum2qbc   VQBC_SUM2
#define     sum2qhu   VQHU_SUM2
#define     sum2qhi   VQHI_SUM2
#define     sum2qwu   VQWU_SUM2
#define     sum2qwi   VQWI_SUM2
#if _LEAVE_SUM2
}
#endif

#if _ENTER_SUMS
{
#endif
/*  SUM (saturated)

Compute the sum of a multielement integer vector. If the
result can't be represented by the operand's element type,
the result is saturated.
*/

#define     sums(...) (sums_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sums_funcof(A, ...)  \
FUNCOF(             \
    sums, (   A   ),\
    NONE, /* TGK */ \
    YHZ,  /* TGW */ \
    YWZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sumswyu   VWYU_SUMS
#define     sumswbu   VWBU_SUMS
#define     sumswbi   VWBI_SUMS
#define     sumswbc   VWBC_SUMS
#define     sumswhu   VWHU_SUMS
#define     sumswhi   VWHI_SUMS

#define     sumsdyu   VDYU_SUMS
#define     sumsdbu   VDBU_SUMS
#define     sumsdbi   VDBI_SUMS
#define     sumsdbc   VDBC_SUMS
#define     sumsdhu   VDHU_SUMS
#define     sumsdhi   VDHI_SUMS
#define     sumsdwu   VDWU_SUMS
#define     sumsdwi   VDWI_SUMS

#define     sumsqyu   VQYU_SUMS
#define     sumsqbu   VQBU_SUMS
#define     sumsqbi   VQBI_SUMS
#define     sumsqbc   VQBC_SUMS
#define     sumsqhu   VQHU_SUMS
#define     sumsqhi   VQHI_SUMS
#define     sumsqwu   VQWU_SUMS
#define     sumsqwi   VQWI_SUMS
#define     sumsqdu   VQDU_SUMS
#define     sumsqdi   VQDI_SUMS
#if _LEAVE_SUMS
}
#endif

#if _ENTER_SUMF
{
#endif
/*  SUM (floating)
*/

#define     sumf(...) (sumf_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sumf_funcof(A, ...)  \
FUNCOF(             \
    sumf, (   A   ),\
    NONE, /* TGK */ \
    HF,   /* TGW */ \
    HWF,  /* TGD */ \
    HDF,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sumfwhf   VWHF_SUMF

#define     sumfdhf   VDHF_SUMF
#define     sumfdwf   VDWF_SUMF

#define     sumfqhf   VQHF_SUMF
#define     sumfqwf   VQWF_SUMF
#define     sumfqdf   VQDF_SUMF
#if _LEAVE_SUMF
}
#endif

#if _ENTER_SUNN
{
#endif
/*  Store UNaligned (nat endian)

Store packed scalar value in native byteorder.

*/

#define     sunn(D, S)  (sunn_funcof(D,S)(D,S))
#define     sunn_funcof(D, S, ...)  \
FUNCOF_AK(                  \
    sunn, (   D   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sunnayu   BOOL_SUNNA
#define     sunnabu  UINT8_SUNNA
#define     sunnabi   INT8_SUNNA
#define     sunnabc   CHAR_SUNNA
#define     sunnahu UINT16_SUNNA
#define     sunnahi  INT16_SUNNA
#define     sunnahf  FLT16_SUNNA
#define     sunnawu UINT32_SUNNA
#define     sunnawi  INT32_SUNNA
#define     sunnawf    FLT_SUNNA
#define     sunnadu UINT64_SUNNA
#define     sunnadi  INT64_SUNNA
#define     sunnadf    DBL_SUNNA
#if   DWRD_NLONG == 2
#   define  sunnalu  ULONG_SUNNA
#   define  sunnali   LONG_SUNNA
#elif QUAD_NLLONG == 2
#   define  sunnalu ULLONG_SUNNA
#   define  sunnali  LLONG_SUNNA
#endif

#if _LEAVE_SUNN
}
#endif

#if _ENTER_SUNL
{
#endif
/*  Store UNaligned (lil endian)

Store packed scalar value in lil endian byteorder.
*/

#define     sunl(D, S)  (sunl_funcof(D,S)(D,S))
#define     sunl_funcof(D, S, ...)  \
FUNCOF_AK(                  \
    sunl, (   D   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sunlayu   BOOL_SUNLA
#define     sunlabu  UINT8_SUNLA
#define     sunlabi   INT8_SUNLA
#define     sunlabc   CHAR_SUNLA
#define     sunlahu UINT16_SUNLA
#define     sunlahi  INT16_SUNLA
#define     sunlahf  FLT16_SUNLA
#define     sunlawu UINT32_SUNLA
#define     sunlawi  INT32_SUNLA
#define     sunlawf    FLT_SUNLA
#define     sunladu UINT64_SUNLA
#define     sunladi  INT64_SUNLA
#define     sunladf    DBL_SUNLA
#if   DWRD_NLONG == 2
#   define  sunlalu  ULONG_SUNLA
#   define  sunlali   LONG_SUNLA
#elif QUAD_NLLONG == 2
#   define  sunlalu ULLONG_SUNLA
#   define  sunlali  LLONG_SUNLA
#endif

#if _LEAVE_SUNL
}
#endif

#if _ENTER_SUNR
{
#endif
/*  Store UNaligned (big endian)

Store packed scalar value in big endian byteorder.
*/

#define     sunr(D, S)  (sunr_funcof(D,S)(D,S))
#define     sunr_funcof(D,S,...)  \
FUNCOF_AK(                  \
    sunr, (   D   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sunrayu   BOOL_SUNRA
#define     sunrabi   INT8_SUNRA
#define     sunrabc   CHAR_SUNRA
#define     sunrahu UINT16_SUNRA
#define     sunrahi  INT16_SUNRA
#define     sunrahf  FLT16_SUNRA
#define     sunrawu UINT32_SUNRA
#define     sunrawi  INT32_SUNRA
#define     sunrawf    FLT_SUNRA
#define     sunradu UINT64_SUNRA
#define     sunradi  INT64_SUNRA
#define     sunradf    DBL_SUNRA
#if   DWRD_NLONG == 2
#   define  sunralu  ULONG_SUNRA
#   define  sunrali   LONG_SUNRA
#elif QUAD_NLLONG == 2
#   define  sunralu ULLONG_SUNRA
#   define  sunrali  LLONG_SUNRA
#endif

#if _LEAVE_SUNR
}
#endif

#if _ENTER_SUNW
{
#endif
/*  Store UNaligned Word

Store a 32 bit vector at an arbitrary address.
*/

#define     sunw(D, S)  (sunw_funcof(D,S)(D,S))
#define     sunw_funcof(A,...)  \
FUNCOF_AK(                  \
    sunw, (   D   ),\
    NONE, /* TGK */ \
    YWR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sunwabu  UINT8_SUNWA
#define     sunwabi   INT8_SUNWA
#define     sunwabc   CHAR_SUNWA
#define     sunwahu UINT16_SUNWA
#define     sunwahi  INT16_SUNWA
#define     sunwahf  FLT16_SUNWA
#define     sunwawu UINT32_SUNWA
#define     sunwawi  INT32_SUNWA
#define     sunwawf    FLT_SUNWA
#if   DWRD_NLONG == 2
#   define  sunwalu  ULONG_SUNWA
#   define  sunwali   LONG_SUNWA
#endif

#if _LEAVE_SUNW
}
#endif

#if _ENTER_SUND
{
#endif
/*  Store UNaligned Doubleword

Store a 64 bit vector at an arbitrary address.
*/

#define     sund(...)  (sund_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sund_funcof(A,...)  \
FUNCOF_AK(                  \
    sund, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sundabu  UINT8_SUNDA
#define     sundabi   INT8_SUNDA
#define     sundabc   CHAR_SUNDA
#define     sundahu UINT16_SUNDA
#define     sundahi  INT16_SUNDA
#define     sundahf  FLT16_SUNDA
#define     sundawu UINT32_SUNDA
#define     sundawi  INT32_SUNDA
#define     sundawf    FLT_SUNDA
#define     sundadu UINT64_SUNDA
#define     sundadi  INT64_SUNDA
#define     sundadf    DBL_SUNDA
#if   DWRD_NLONG == 2
#   define  sundalu  ULONG_SUNDA
#   define  sundali   LONG_SUNDA
#elif QUAD_NLLONG == 2
#   define  sundalu  ULLONG_SUNDA
#   define  sundali   LLONG_SUNDA
#endif

#if _LEAVE_SUND
}
#endif

#if _ENTER_SUNQ
{
#endif

#define     sunq(...)  (sunq_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     sunq_funcof(A,...)  \
FUNCOF_AK(                  \
    sunq, (   A   ),\
    NONE, /* TGK */ \
    YDR,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     sunqabu  UINT8_SUNQA
#define     sunqabi   INT8_SUNQA
#define     sunqabc   CHAR_SUNQA
#define     sunqahu UINT16_SUNQA
#define     sunqahi  INT16_SUNQA
#define     sunqahf  FLT16_SUNQA
#define     sunqawu UINT32_SUNQA
#define     sunqawi  INT32_SUNQA
#define     sunqawf    FLT_SUNQA
#define     sunqadu UINT64_SUNQA
#define     sunqadi  INT64_SUNQA
#define     sunqadf    DBL_SUNQA
#if   DWRD_NLONG == 2
#   define  sunqalu  ULONG_SUNQA
#   define  sunqali   LONG_SUNQA
#elif QUAD_NLLONG == 2
#   define  sunqalu  ULLONG_SUNQA
#   define  sunqali   LLONG_SUNQA

#endif

#if _LEAVE_SUNQ
}
#endif


#if _ENTER_SVLL
{
#endif
/*  Shift by Vector Left (truncated)

Shift each N bit element in the first vector left by the
number of bits specified by the corresponding N bit
unsigned int in the second vector.

As with shll, unsigned operands are logically shifted
while signed operands are arithmeticallt shifted.

If any element in the second operand falls outside the
range [0..N], the result is implementation defined.
*/

#define     svll(...) (svll_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     svll_funcof(A, ...)  \
FUNCOF(             \
    svll, (   A   ),\
    NONE, /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     svllwbu   VWBU_SVLL
#define     svllwbi   VWBI_SVLL
#define     svllwbc   VWBC_SVLL
#define     svllwhu   VWHU_SVLL
#define     svllwhi   VWHI_SVLL
#define     svllwwu   VWWU_SVLL
#define     svllwwi   VWWI_SVLL

#define     svlldbu   VDBU_SVLL
#define     svlldbi   VDBI_SVLL
#define     svlldbc   VDBC_SVLL
#define     svlldhu   VDHU_SVLL
#define     svlldhi   VDHI_SVLL
#define     svlldwu   VDWU_SVLL
#define     svlldwi   VDWI_SVLL
#define     svllddu   VDDU_SVLL
#define     svllddi   VDDI_SVLL

#define     svllqbu   VQBU_SVLL
#define     svllqbi   VQBI_SVLL
#define     svllqbc   VQBC_SVLL
#define     svllqhu   VQHU_SVLL
#define     svllqhi   VQHI_SVLL
#define     svllqwu   VQWU_SVLL
#define     svllqwi   VQWI_SVLL
#define     svllqdu   VQDU_SVLL
#define     svllqdi   VQDI_SVLL
#if _LEAVE_SVLL
}
#endif

#if _ENTER_SVLS
{
#endif
/*  Shift by Vector Left (saturated)

Shift each N bit element in the first vector left by the
number of bits specified by the corresponding N bit
unsigned int in the second vector.

As with shls, unsigned int operands are logical shifted
while signed int operands are arithmetically shifted.

If any element in the second operand falls outside the
range [0..N], the result is implementation defined.
*/

#define     svls(...) (svls_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     svls_funcof(A, ...)  \
FUNCOF(             \
    svls, (   A   ),\
    NONE, /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     svlswbu   VWBU_SVLS
#define     svlswbi   VWBI_SVLS
#define     svlswbc   VWBC_SVLS
#define     svlswhu   VWHU_SVLS
#define     svlswhi   VWHI_SVLS
#define     svlswwu   VWWU_SVLS
#define     svlswwi   VWWI_SVLS

#define     svlsdbu   VDBU_SVLS
#define     svlsdbi   VDBI_SVLS
#define     svlsdbc   VDBC_SVLS
#define     svlsdhu   VDHU_SVLS
#define     svlsdhi   VDHI_SVLS
#define     svlsdwu   VDWU_SVLS
#define     svlsdwi   VDWI_SVLS
#define     svlsddu   VDDU_SVLS
#define     svlsddi   VDDI_SVLS

#define     svlsqbu   VQBU_SVLS
#define     svlsqbi   VQBI_SVLS
#define     svlsqbc   VQBC_SVLS
#define     svlsqhu   VQHU_SVLS
#define     svlsqhi   VQHI_SVLS
#define     svlsqwu   VQWU_SVLS
#define     svlsqwi   VQWI_SVLS
#define     svlsqdu   VQDU_SVLS
#define     svlsqdi   VQDI_SVLS
#if _LEAVE_SVLS
}
#endif

#if _ENTER_SVL2
{
#endif
/*  Shift by Vector Left (widened×2)

Shift each N bit element in the first vector left by the
number of bits specified by the corresponding N bit
unsigned int in the second vector. The result has an
element size of 2N.

As with shl2, unsigned int operands are logical shifted
while signed int operands are arithmetically shifted.

If any element in the second operand falls outside the
range [0..N], the result is implementation defined.
*/

#define     svl2(...) (svl2_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     svl2_funcof(A, ...)  \
FUNCOF(             \
    svl2,   (   A   ),  \
    NONE, /* TGK */ \
    BWZ,  /* TGW */ \
    BWZ,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     svl2wbu   VWBU_SVL2
#define     svl2wbi   VWBI_SVL2
#define     svl2wbc   VWBC_SVL2
#define     svl2whu   VWHU_SVL2
#define     svl2whi   VWHI_SVL2
#define     svl2wwu   VWWU_SVL2
#define     svl2wwi   VWWI_SVL2

#define     svl2dbu   VDBU_SVL2
#define     svl2dbi   VDBI_SVL2
#define     svl2dbc   VDBC_SVL2
#define     svl2dhu   VDHU_SVL2
#define     svl2dhi   VDHI_SVL2
#define     svl2dwu   VDWU_SVL2
#define     svl2dwi   VDWI_SVL2

#define     svl2qbu   VQBU_SVL2
#define     svl2qbi   VQBI_SVL2
#define     svl2qbc   VQBC_SVL2
#define     svl2qhu   VQHU_SVL2
#define     svl2qhi   VQHI_SVL2
#define     svl2qwu   VQWU_SVL2
#define     svl2qwi   VQWI_SVL2
#if _LEAVE_SVL2
}
#endif


#if _ENTER_SVRS
{
#endif
/*  Shift by Vector Right (saturated)

Shifts the binary representation of each N bit element
in the first operand by the number of bits specified by
the corresponding element of the second operand. For each
bit of a signed int shifted out at the least significant
bit, a copy of  the sign bit is shifted in at the most
significant bit. For unsigned operands, an equivalent
number of zeros are shifted in at the most significant bit.

If any element in the second operand falls outside the
range [0..N], the result is implementation defined.
*/

#define     svrs(...) (svrs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     svrs_funcof(A, ...)  \
FUNCOF(             \
    svrs, (   A   ),\
    NONE, /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     svrswbu   VWBU_SVRS
#define     svrswbi   VWBI_SVRS
#define     svrswbc   VWBC_SVRS
#define     svrswhu   VWHU_SVRS
#define     svrswhi   VWHI_SVRS
#define     svrswwu   VWWU_SVRS
#define     svrswwi   VWWI_SVRS

#define     svrsdbu   VDBU_SVRS
#define     svrsdbi   VDBI_SVRS
#define     svrsdbc   VDBC_SVRS
#define     svrsdhu   VDHU_SVRS
#define     svrsdhi   VDHI_SVRS
#define     svrsdwu   VDWU_SVRS
#define     svrsdwi   VDWI_SVRS
#define     svrsddu   VDDU_SVRS
#define     svrsddi   VDDI_SVRS

#define     svrsqbu   VQBU_SVRS
#define     svrsqbi   VQBI_SVRS
#define     svrsqbc   VQBC_SVRS
#define     svrsqhu   VQHU_SVRS
#define     svrsqhi   VQHI_SVRS
#define     svrsqwu   VQWU_SVRS
#define     svrsqwi   VQWI_SVRS
#define     svrsqdu   VQDU_SVRS
#define     svrsqdi   VQDI_SVRS
#if _LEAVE_SVRS
}
#endif


#if _ENTER_SWP1
{
#endif
/*  atomic_exchange_explicit(..., memory_order_relaxed)
*/

#define     swp1(...)  (swp1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     swp1_funcof(A, ...) \
FUNCOF_AK(          \
    swp1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     swp1aac   ADDR_SWP1A
#define     swp1ayu   BOOL_SWP1A
#define     swp1abu  UINT8_SWP1A
#define     swp1abi   INT8_SWP1A
#define     swp1abc   CHAR_SWP1A
#define     swp1ahu UINT16_SWP1A
#define     swp1ahi  INT16_SWP1A
#define     swp1awu UINT32_SWP1A
#define     swp1awi  INT32_SWP1A
#define     swp1adu UINT64_SWP1A
#define     swp1adi  INT64_SWP1A
#if DWRD_NLONG == 2
#   define  swp1alu  ULONG_SWP1A
#   define  swp1ali   LONG_SWP1A
#elif QUAD_NLLONG == 2
#   define  swp1alu ULLONG_SWP1A
#   define  swp1ali  LLONG_SWP1A
#else
#   define  swp1aqu ULLONG_SWP1A
#   define  swp1aqi  LLONG_SWP1A
#endif

#if _LEAVE_SWP1
}
#endif

#if _ENTER_SWPA
{
#endif
/*  SWP (atomic exchange w/ memory_order_acquire)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand with the second
operand.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_swp and memory_order_acquire
*/

#define     swpa(...)  (swpa_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     swpa_funcof(A, ...) \
FUNCOF_AK(          \
    swpa, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     swpaayu    BOOL_SWPAA
#define     swpaabu   UINT8_SWPAA
#define     swpaabi    INT8_SWPAA
#define     swpaabc    CHAR_SWPAA
#define     swpaahu  UINT16_SWPAA
#define     swpaahi   INT16_SWPAA
#define     swpaawu  UINT32_SWPAA
#define     swpaawi   INT32_SWPAA
#define     swpaadu  UINT64_SWPAA
#define     swpaadi   INT64_SWPAA
#if DWRD_NLONG == 2
#   define  swpaalu   ULONG_SWPAA
#   define  swpaali    LONG_SWPAA
#elif QUAD_NLLONG == 2
#   define  swpaalu  ULLONG_SWPAA
#   define  swpaali   LLONG_SWPAA
#else
#   define  swpaaqu  ULLONG_SWPAA
#   define  swpaaqi   LLONG_SWPAA
#endif

#if _LEAVE_SWPA
}
#endif

#if _ENTER_SWPE
{
#endif
/*  SWP (atomic fetch swp w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand with the second
operand.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_swp and memory_order_release
*/

#define     swpe(...)  (swpe_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     swpe_funcof(A, ...) \
FUNCOF_AK(          \
    swpe, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     swpeayu    BOOL_SWPEA
#define     swpeabu   UINT8_SWPEA
#define     swpeabi    INT8_SWPEA
#define     swpeabc    CHAR_SWPEA
#define     swpeahu  UINT16_SWPEA
#define     swpeahi   INT16_SWPEA
#define     swpeawu  UINT32_SWPEA
#define     swpeawi   INT32_SWPEA
#define     swpeadu  UINT64_SWPEA
#define     swpeadi   INT64_SWPEA
#if DWRD_NLONG == 2
#   define  swpealu   ULONG_SWPEA
#   define  swpeali    LONG_SWPEA
#elif QUAD_NLLONG == 2
#   define  swpealu  ULLONG_SWPEA
#   define  swpeali   LLONG_SWPEA
#else
#   define  swpeaqu  ULLONG_SWPEA
#   define  swpeaqi   LLONG_SWPEA
#endif

#if _LEAVE_SWPE
}
#endif

#if _ENTER_SWPT
{
#endif
/*  SWP (atomic fetch swp w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand with the second
operand.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_swp and memory_order_seq_cst
*/

#define     swpt(...)  (swpt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     swpt_funcof(A, ...) \
FUNCOF_AK(          \
    swpt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     swptayu    BOOL_SWPTA
#define     swptabu   UINT8_SWPTA
#define     swptabi    INT8_SWPTA
#define     swptabc    CHAR_SWPTA
#define     swptahu  UINT16_SWPTA
#define     swptahi   INT16_SWPTA
#define     swptawu  UINT32_SWPTA
#define     swptawi   INT32_SWPTA
#define     swptadu  UINT64_SWPTA
#define     swptadi   INT64_SWPTA
#if DWRD_NLONG == 2
#   define  swptalu   ULONG_SWPTA
#   define  swptali    LONG_SWPTA
#elif QUAD_NLLONG == 2
#   define  swptalu  ULLONG_SWPTA
#   define  swptali   LLONG_SWPTA
#else
#   define  swptaqu  ULLONG_SWPTA
#   define  swptaqi   LLONG_SWPTA
#endif

#if _LEAVE_SWPT
}
#endif


#if _ENTER_TSTS
{
#endif
/*  TeST set bits (saturated)

Compute the bitwise AND of corresponding elements in the
two operand. If the intermediate result is nonzero, sets
the corresponding element of the result to all ones,
otherwise zero.

    tsts(0b1110, 0b0100) => -1 (0b1110&0b0100=0b0100)
*/

#define     tsts(...) (tsts_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     tsts_funcof(A, ...)  \
FUNCOF(             \
    tsts, (   A   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     tstsbu   UINT8_TSTS
#define     tstsbi    INT8_TSTS
#define     tstsbc    CHAR_TSTS
#define     tstshu  UINT16_TSTS
#define     tstshi   INT16_TSTS
#define     tstswu  UINT32_TSTS
#define     tstswi   INT32_TSTS
#define     tstsdu  UINT64_TSTS
#define     tstsdi   INT64_TSTS
#if DWRD_NLONG == 2
#   define  tstslu   ULONG_TSTS
#   define  tstsli    LONG_TSTS
#elif QUAD_NLLONG == 2
#   define  tstslu  ULLONG_TSTS
#   define  tstsli   LLONG_TSTS
#else
#   define  tstsqu  ULLONG_TSTS
#   define  tstsqi   LLONG_TSTS
#   define  tstsqf    LDBL_TSTS
#endif

#define     tstswbu   VWBU_TSTS
#define     tstswbi   VWBI_TSTS
#define     tstswbc   VWBC_TSTS
#define     tstswhu   VWHU_TSTS
#define     tstswhi   VWHI_TSTS
#define     tstswwu   VWWU_TSTS
#define     tstswwi   VWWI_TSTS

#define     tstsdbu   VDBU_TSTS
#define     tstsdbi   VDBI_TSTS
#define     tstsdbc   VDBC_TSTS
#define     tstsdhu   VDHU_TSTS
#define     tstsdhi   VDHI_TSTS
#define     tstsdwu   VDWU_TSTS
#define     tstsdwi   VDWI_TSTS
#define     tstsddu   VDDU_TSTS
#define     tstsddi   VDDI_TSTS

#define     tstsqbu   VQBU_TSTS
#define     tstsqbi   VQBI_TSTS
#define     tstsqbc   VQBC_TSTS
#define     tstsqhu   VQHU_TSTS
#define     tstsqhi   VQHI_TSTS
#define     tstsqwu   VQWU_TSTS
#define     tstsqwi   VQWI_TSTS
#define     tstsqdu   VQDU_TSTS
#define     tstsqdi   VQDI_TSTS
#if _LEAVE_TSTS
}
#endif

#if _ENTER_TSTY
{
#endif
/*  TeST set bits (boolean)

Identical to tsts except positive matches set the
corresponding result element to +1 rather than -1.
*/

#define     tsty(...) (tsty_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     tsty_funcof(A, ...)  \
FUNCOF(             \
    tsty, (   A   ),\
    BDZ,  /* TGK */ \
    BWZ,  /* TGW */ \
    BDZ,  /* TGD */ \
    BDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     tstybu   UINT8_TSTY
#define     tstybi    INT8_TSTY
#define     tstybc    CHAR_TSTY
#define     tstyhu  UINT16_TSTY
#define     tstyhi   INT16_TSTY
#define     tstywu  UINT32_TSTY
#define     tstywi   INT32_TSTY
#define     tstydu  UINT64_TSTY
#define     tstydi   INT64_TSTY
#if DWRD_NLONG == 2
#   define  tstylu   ULONG_TSTY
#   define  tstyli    LONG_TSTY
#elif QUAD_NLLONG == 2
#   define  tstylu  ULLONG_TSTY
#   define  tstyli   LLONG_TSTY
#else
#   define  tstyqu  ULLONG_TSTY
#   define  tstyqi   LLONG_TSTY
#   define  tstyqf    LDBL_TSTY
#endif

#define     tstywbu   VWBU_TSTY
#define     tstywbi   VWBI_TSTY
#define     tstywbc   VWBC_TSTY
#define     tstywhu   VWHU_TSTY
#define     tstywhi   VWHI_TSTY
#define     tstywwu   VWWU_TSTY
#define     tstywwi   VWWI_TSTY

#define     tstydbu   VDBU_TSTY
#define     tstydbi   VDBI_TSTY
#define     tstydbc   VDBC_TSTY
#define     tstydhu   VDHU_TSTY
#define     tstydhi   VDHI_TSTY
#define     tstydwu   VDWU_TSTY
#define     tstydwi   VDWI_TSTY
#define     tstyddu   VDDU_TSTY
#define     tstyddi   VDDI_TSTY

#define     tstyqbu   VQBU_TSTY
#define     tstyqbi   VQBI_TSTY
#define     tstyqbc   VQBC_TSTY
#define     tstyqhu   VQHU_TSTY
#define     tstyqhi   VQHI_TSTY
#define     tstyqwu   VQWU_TSTY
#define     tstyqwi   VQWI_TSTY
#define     tstyqdu   VQDU_TSTY
#define     tstyqdi   VQDI_TSTY
#if _LEAVE_TSTY
}
#endif


#if _ENTER_UNOS
{
#endif
/*  generate a consecutive sequence of '1' bits

Set each element of the result to a consecutive sequence
of 1 bits. E.g. unosdbu(3) is equivalent to dupdbu(0b111).
If the number of bits exceeds the width of the operation's
element type, the result is undefined.

TODO: debate splitting unos into unol and unor. Hopefully,
it is obvious what the difference between them would be.
*/

#define     unos(T, ...)    (unos_funcof(T)(__VA_ARGS__))
#define     unos_funcof(T, ...) \
FUNCOF(             \
    unos, ((T){0}), \
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     unosyu    BOOL_UNOS
#define     unosbu   UINT8_UNOS
#define     unosbi    INT8_UNOS
#define     unosbc    CHAR_UNOS
#define     unoshu  UINT16_UNOS
#define     unoshi   INT16_UNOS
#define     unoswu  UINT32_UNOS
#define     unoswi   INT32_UNOS
#define     unosdu  UINT64_UNOS
#define     unosdi   INT64_UNOS
#if DWRD_NLONG == 2
#   define  unoslu   ULONG_UNOS
#   define  unosli    LONG_UNOS
#elif QUAD_NLLONG == 2
#   define  unoslu  ULLONG_UNOS
#   define  unosli   LLONG_UNOS
#endif

#define     unoswyu     VWYU_UNOS
#define     unoswbu     VWBU_UNOS
#define     unoswbi     VWBI_UNOS
#define     unoswbc     VWBI_UNOS
#define     unoswhu     VWHU_UNOS
#define     unoswhi     VWHI_UNOS
#define     unoswwu     VWWU_UNOS
#define     unoswwi     VWWI_UNOS

#define     unosdyu     VDYU_UNOS
#define     unosdbu     VDBU_UNOS
#define     unosdbi     VDBI_UNOS
#define     unosdbc     VDBC_UNOS
#define     unosdhu     VDHU_UNOS
#define     unosdhi     VDHI_UNOS
#define     unosdwu     VDWU_UNOS
#define     unosdwi     VDWI_UNOS
#define     unosddu     VDDU_UNOS
#define     unosddi     VDDI_UNOS

#define     unosqyu     VQYU_UNOS
#define     unosqbu     VQBU_UNOS
#define     unosqbi     VQBI_UNOS
#define     unosqbc     VQBC_UNOS
#define     unosqhu     VQHU_UNOS
#define     unosqhi     VQHI_UNOS
#define     unosqwu     VQWU_UNOS
#define     unosqwi     VQWI_UNOS
#define     unosqdu     VQDU_UNOS
#define     unosqdi     VQDI_UNOS
#if _LEAVE_UNOS
}
#endif


#if _ENTER_UZPL
{
#endif
/*  UnZiP (extract evens)

TODO: implement uzp for integers
*/

#define     uzpl(...)    (uzpl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     uzpl_funcof(X,...)  \
FUNCOF(             \
    uzpl, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     uzplwyu VWYU_UZPL
#define     uzplwbu VWBU_UZPL
#define     uzplwbi VWBI_UZPL
#define     uzplwbc VWBC_UZPL
#define     uzplwhu VWHU_UZPL
#define     uzplwhi VWHI_UZPL
#define     uzplwhf VWHF_UZPL

#define     uzpldyu VDYU_UZPL
#define     uzpldbu VDBU_UZPL
#define     uzpldbi VDBI_UZPL
#define     uzpldbc VDBC_UZPL
#define     uzpldhu VDHU_UZPL
#define     uzpldhi VDHI_UZPL
#define     uzpldhf VDHF_UZPL
#define     uzpldwu VDWU_UZPL
#define     uzpldwi VDWI_UZPL
#define     uzpldwf VDWF_UZPL

#define     uzplqyu VQYU_UZPL
#define     uzplqbu VQBU_UZPL
#define     uzplqbi VQBI_UZPL
#define     uzplqbc VQBC_UZPL
#define     uzplqhu VQHU_UZPL
#define     uzplqhi VQHI_UZPL
#define     uzplqhf VQHF_UZPL
#define     uzplqwu VQWU_UZPL
#define     uzplqwi VQWI_UZPL
#define     uzplqwf VQWF_UZPL
#define     uzplqdu VQDU_UZPL
#define     uzplqdi VQDI_UZPL
#define     uzplqdf VQDF_UZPL
#if _LEAVE_UZPL
}
#endif

#if _ENTER_UZPR
{
#endif
/*  UnZiP (extract odds) */

#define     uzpr(...)    (uzpr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     uzpr_funcof(X,...)  \
FUNCOF(             \
    uzpr, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     uzprwbu VWBU_UZPR
#define     uzprwbi VWBI_UZPR
#define     uzprwbc VWBC_UZPR
#define     uzprwhu VWHU_UZPR
#define     uzprwhi VWHI_UZPR
#define     uzprwhf VWHF_UZPR

#define     uzprdbu VDBU_UZPR
#define     uzprdbi VDBI_UZPR
#define     uzprdbc VDBC_UZPR
#define     uzprdhu VDHU_UZPR
#define     uzprdhi VDHI_UZPR
#define     uzprdhf VDHF_UZPR
#define     uzprdwu VDWU_UZPR
#define     uzprdwi VDWI_UZPR
#define     uzprdwf VDWF_UZPR

#define     uzprqbu VQBU_UZPR
#define     uzprqbi VQBI_UZPR
#define     uzprqbc VQBC_UZPR
#define     uzprqhu VQHU_UZPR
#define     uzprqhi VQHI_UZPR
#define     uzprqhf VQHF_UZPR
#define     uzprqwu VQWU_UZPR
#define     uzprqwi VQWI_UZPR
#define     uzprqwf VQWF_UZPR
#define     uzprqdu VQDU_UZPR
#define     uzprqdi VQDI_UZPR
#define     uzprqdf VQDF_UZPR
#if _LEAVE_UZPR
}
#endif


#if _ENTER_VEQY
{
#endif
/*  Vector EQuality match (boolean)

Test if any element in the multielement first operand A is
equal to the second operand B.

Any NaN comparisons produce an undefined result.
*/

#define     veqy(...) (veqy_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     veqy_funcof(A, ...)  \
FUNCOF(             \
    veqy, (   A   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     veqywyu   VWYU_VEQY
#define     veqywbu   VWBU_VEQY
#define     veqywbi   VWBI_VEQY
#define     veqywbc   VWBC_VEQY
#define     veqywhu   VWHU_VEQY
#define     veqywhi   VWHI_VEQY
#define     veqywhf   VWHF_VEQY

#define     veqydyu   VDYU_VEQY
#define     veqydbu   VDBU_VEQY
#define     veqydbi   VDBI_VEQY
#define     veqydbc   VDBC_VEQY
#define     veqydhu   VDHU_VEQY
#define     veqydhi   VDHI_VEQY
#define     veqydhf   VDHF_VEQY
#define     veqydwu   VDWU_VEQY
#define     veqydwi   VDWI_VEQY
#define     veqydwf   VDWF_VEQY

#define     veqyqyu   VQYU_VEQY
#define     veqyqbu   VQBU_VEQY
#define     veqyqbi   VQBI_VEQY
#define     veqyqbc   VQBC_VEQY
#define     veqyqhu   VQHU_VEQY
#define     veqyqhi   VQHI_VEQY
#define     veqyqhf   VQHF_VEQY
#define     veqyqwu   VQWU_VEQY
#define     veqyqwi   VQWI_VEQY
#define     veqyqwf   VQWF_VEQY
#define     veqyqdu   VQDU_VEQY
#define     veqyqdi   VQDI_VEQY
#define     veqyqdf   VQDF_VEQY
#if _LEAVE_VEQY
}
#endif

#if _ENTER_VEQS
{
#endif
/*  Vector EQuality match (saturated)

In a new integer vector with equivalent dimensions to the
first operand, set all bits to 1 if any element in the
first operand equals the value specified by the second
operand.

Any comparison with NaN generates an undefined result.

TODO: debate renaming the current implementation of veqs
and making veqs return a saturated scalar
*/

#define     veqs(...) (veqs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     veqs_funcof(A, ...)  \
FUNCOF(             \
    veqs, (   A   ),\
    NONE, /* TGK */ \
    YHR,  /* TGW */ \
    YWR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     veqswyu   VWYU_VEQS
#define     veqswbu   VWBU_VEQS
#define     veqswbi   VWBI_VEQS
#define     veqswbc   VWBC_VEQS
#define     veqswhu   VWHU_VEQS
#define     veqswhi   VWHI_VEQS
#define     veqswhf   VWHF_VEQS

#define     veqsdyu   VDYU_VEQS
#define     veqsdbu   VDBU_VEQS
#define     veqsdbi   VDBI_VEQS
#define     veqsdbc   VDBC_VEQS
#define     veqsdhu   VDHU_VEQS
#define     veqsdhi   VDHI_VEQS
#define     veqsdhf   VDHF_VEQS
#define     veqsdwu   VDWU_VEQS
#define     veqsdwi   VDWI_VEQS
#define     veqsdwf   VDWF_VEQS

#define     veqsqyu   VQYU_VEQS
#define     veqsqbu   VQBU_VEQS
#define     veqsqbi   VQBI_VEQS
#define     veqsqbc   VQBC_VEQS
#define     veqsqhu   VQHU_VEQS
#define     veqsqhi   VQHI_VEQS
#define     veqsqhf   VQHF_VEQS
#define     veqsqwu   VQWU_VEQS
#define     veqsqwi   VQWI_VEQS
#define     veqsqwf   VQWF_VEQS
#define     veqsqdu   VQDU_VEQS
#define     veqsqdi   VQDI_VEQS
#define     veqsqdf   VQDF_VEQS
#if _LEAVE_VEQS
}
#endif


#if _ENTER_XEQ1
{
#endif
/*  atomic_compare_exchange_strong_explicit(
        ...,
        memory_order_relaxed,
        memory_order_relaxed
    )
*/
#define     xeq1(...)  (xeq1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xeq1_funcof(A, ...) \
FUNCOF_AK(          \
    xeq1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xeq1aac    ADDR_XEQ1A
#define     xeq1ayu    BOOL_XEQ1A
#define     xeq1abu   UINT8_XEQ1A
#define     xeq1abi    INT8_XEQ1A
#define     xeq1abc    CHAR_XEQ1A
#define     xeq1ahu  UINT16_XEQ1A
#define     xeq1ahi   INT16_XEQ1A
#define     xeq1awu  UINT32_XEQ1A
#define     xeq1awi   INT32_XEQ1A
#define     xeq1adu  UINT64_XEQ1A
#define     xeq1adi   INT64_XEQ1A
#if DWRD_NLONG == 2
#   define  xeq1alu   ULONG_XEQ1A
#   define  xeq1ali    LONG_XEQ1A
#elif QUAD_NLLONG == 2
#   define  xeq1alu  ULLONG_XEQ1A
#   define  xeq1ali   LLONG_XEQ1A
#else
#   define  xeq1aqu  ULLONG_XEQ1A
#   define  xeq1aqi   LLONG_XEQ1A
#endif

#if _LEAVE_XEQ1
}
#endif

#if _ENTER_XEQA
{
#endif
/*  atomic_compare_exchange_strong_explicit(
        ...,
        memory_order_acquire,
        memory_order_acquire
    )
*/

#define     xeqa(...)  (xeqa_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xeqa_funcof(A, ...) \
FUNCOF_AK(          \
    xeqa, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xeqaaac    ADDR_XEQAA
#define     xeqaayu    BOOL_XEQAA
#define     xeqaabu   UINT8_XEQAA
#define     xeqaabi    INT8_XEQAA
#define     xeqaabc    CHAR_XEQAA
#define     xeqaahu  UINT16_XEQAA
#define     xeqaahi   INT16_XEQAA
#define     xeqaawu  UINT32_XEQAA
#define     xeqaawi   INT32_XEQAA
#define     xeqaadu  UINT64_XEQAA
#define     xeqaadi   INT64_XEQAA
#if DWRD_NLONG == 2
#   define  xeqaalu   ULONG_XEQAA
#   define  xeqaali    LONG_XEQAA
#elif QUAD_NLLONG == 2
#   define  xeqaalu  ULLONG_XEQAA
#   define  xeqaali   LLONG_XEQAA
#else
#   define  xeqaaqu  ULLONG_XEQAA
#   define  xeqaaqi   LLONG_XEQAA
#endif

#if _LEAVE_XEQA
}
#endif

#if _ENTER_XEQE
{
#endif
/*  atomic_compare_exchange_strong_explicit(
        ...,
        memory_order_acq_rel,
        memory_order_acquire
    )
*/

#define     xeqe(...)  (xeqe_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xeqe_funcof(A, ...) \
FUNCOF_AK(          \
    xeqe, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xeqeaac    ADDR_XEQEA
#define     xeqeayu    BOOL_XEQEA
#define     xeqeabu   UINT8_XEQEA
#define     xeqeabi    INT8_XEQEA
#define     xeqeabc    CHAR_XEQEA
#define     xeqeahu  UINT16_XEQEA
#define     xeqeahi   INT16_XEQEA
#define     xeqeawu  UINT32_XEQEA
#define     xeqeawi   INT32_XEQEA
#define     xeqeadu  UINT64_XEQEA
#define     xeqeadi   INT64_XEQEA
#if DWRD_NLONG == 2
#   define  xeqealu   ULONG_XEQEA
#   define  xeqeali    LONG_XEQEA
#elif QUAD_NLLONG == 2
#   define  xeqealu  ULLONG_XEQEA
#   define  xeqeali   LLONG_XEQEA
#else
#   define  xeqeaqu  ULLONG_XEQEA
#   define  xeqeaqi   LLONG_XEQEA
#endif


#if _LEAVE_XEQE
}
#endif

#if _ENTER_XEQT
{
#endif
/*  atomic_compare_exchange_strong_explicit(
        ...,
        memory_order_seq_cst,
        memory_order_seq_cst
    )
*/

#define     xeqt(...)  (xeqt_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xeqt_funcof(A, ...) \
FUNCOF_AK(          \
    xeqt, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xeqtaac    ADDR_XEQTA
#define     xeqtayu    BOOL_XEQTA
#define     xeqtabu   UINT8_XEQTA
#define     xeqtabi    INT8_XEQTA
#define     xeqtabc    CHAR_XEQTA
#define     xeqtahu  UINT16_XEQTA
#define     xeqtahi   INT16_XEQTA
#define     xeqtawu  UINT32_XEQTA
#define     xeqtawi   INT32_XEQTA
#define     xeqtadu  UINT64_XEQTA
#define     xeqtadi   INT64_XEQTA
#if DWRD_NLONG == 2
#   define  xeqtalu   ULONG_XEQTA
#   define  xeqtali    LONG_XEQTA
#elif QUAD_NLLONG == 2
#   define  xeqtalu  ULLONG_XEQTA
#   define  xeqtali   LLONG_XEQTA
#else
#   define  xeqtaqu  ULLONG_XEQTA
#   define  xeqtaqi   LLONG_XEQTA
#endif

#if _LEAVE_XEQT
}
#endif


#if _ENTER_XORS
{
#endif
/*  Bitwise XOR

For each bit A in the first operand A and each bit B in
the second operand, compute the bitwise XOR of A and B.
*/

#define     xors(...) (xors_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xors_funcof(X, ...)  \
FUNCOF(             \
    xors, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xorsyu    BOOL_XORS
#define     xorsbu   UINT8_XORS
#define     xorsbi    INT8_XORS
#define     xorsbc    CHAR_XORS
#define     xorshu  UINT16_XORS
#define     xorshi   INT16_XORS
#define     xorswu  UINT32_XORS
#define     xorswi   INT32_XORS
#define     xorsdu  UINT64_XORS
#define     xorsdi   INT64_XORS
#if   DWRD_NLONG == 2
#   define  xorslu   ULONG_XORS
#   define  xorsli    LONG_XORS
#elif QUAD_NLLONG == 2
#   define  xorslu  ULLONG_XORS
#   define  xorsli   LLONG_XORS
#else
#   define  xorsqu  ULLONG_XORS
#   define  xorsqi   LLONG_XORS
#endif

#define     xorswyu   VWYU_XORS
#define     xorswbu   VWBU_XORS
#define     xorswbi   VWBI_XORS
#define     xorswbc   VWBC_XORS
#define     xorswhu   VWHU_XORS
#define     xorswhi   VWHI_XORS
#define     xorswwu   VWWU_XORS
#define     xorswwi   VWWI_XORS

#define     xorsdyu   VDYU_XORS
#define     xorsdbu   VDBU_XORS
#define     xorsdbi   VDBI_XORS
#define     xorsdbc   VDBC_XORS
#define     xorsdhu   VDHU_XORS
#define     xorsdhi   VDHI_XORS
#define     xorsdwu   VDWU_XORS
#define     xorsdwi   VDWI_XORS
#define     xorsddu   VDDU_XORS
#define     xorsddi   VDDI_XORS

#define     xorsqyu   VQYU_XORS
#define     xorsqbu   VQBU_XORS
#define     xorsqbi   VQBI_XORS
#define     xorsqbc   VQBC_XORS
#define     xorsqhu   VQHU_XORS
#define     xorsqhi   VQHI_XORS
#define     xorsqwu   VQWU_XORS
#define     xorsqwi   VQWI_XORS
#define     xorsqdu   VQDU_XORS
#define     xorsqdi   VQDI_XORS
#if _LEAVE_XORS
}
#endif

#if _ENTER_XORN
{
#endif
/*  Bitwise XOR NOT

For each bit A in the first operand A and each bit B in
the second operand, compute the bitwise XOR of A and NOT B.
*/

#define     xorn(...) (xorn_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xorn_funcof(X, ...)  \
FUNCOF(             \
    xorn, (   X   ),\
    YDZ,  /* TGK */ \
    YWZ,  /* TGW */ \
    YDZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xornyu    BOOL_XORN
#define     xornbu   UINT8_XORN
#define     xornbi    INT8_XORN
#define     xornbc    CHAR_XORN
#define     xornhu  UINT16_XORN
#define     xornhi   INT16_XORN
#define     xornwu  UINT32_XORN
#define     xornwi   INT32_XORN
#define     xorndu  UINT64_XORN
#define     xorndi   INT64_XORN
#if   DWRD_NLONG == 2
#   define  xornlu   ULONG_XORN
#   define  xornli    LONG_XORN
#elif QUAD_NLLONG == 2
#   define  xornlu  ULLONG_XORN
#   define  xornli   LLONG_XORN
#else
#   define  xornqu  ULLONG_XORN
#   define  xornqi   LLONG_XORN
#endif

#define     xornwyu   VWYU_XORN
#define     xornwbu   VWBU_XORN
#define     xornwbi   VWBI_XORN
#define     xornwbc   VWBC_XORN
#define     xornwhu   VWHU_XORN
#define     xornwhi   VWHI_XORN
#define     xornwwu   VWWU_XORN
#define     xornwwi   VWWI_XORN

#define     xorndyu   VDYU_XORN
#define     xorndbu   VDBU_XORN
#define     xorndbi   VDBI_XORN
#define     xorndbc   VDBC_XORN
#define     xorndhu   VDHU_XORN
#define     xorndhi   VDHI_XORN
#define     xorndwu   VDWU_XORN
#define     xorndwi   VDWI_XORN
#define     xornddu   VDDU_XORN
#define     xornddi   VDDI_XORN

#define     xornqyu   VQYU_XORN
#define     xornqbu   VQBU_XORN
#define     xornqbi   VQBI_XORN
#define     xornqbc   VQBC_XORN
#define     xornqhu   VQHU_XORN
#define     xornqhi   VQHI_XORN
#define     xornqwu   VQWU_XORN
#define     xornqwi   VQWI_XORN
#define     xornqdu   VQDU_XORN
#define     xornqdi   VQDI_XORN
#if _LEAVE_XORN
}
#endif

#if _ENTER_XORV
{
#endif
/*  Bitwise XOR (across vector)

TODO: implement ops for 32 bit vectors
*/

#define     xorv(...) (xorv_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xorv_funcof(X, ...)  \
FUNCOF(             \
    xorv, (   X   ),\
    NONE, /* TGK */ \
    NONE, /* TGW */ \
    YWZ,  /* TGD */ \
    YDZ,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xorvwyu   VWYU_XORV
#define     xorvwbu   VWBU_XORV
#define     xorvwbi   VWBI_XORV
#define     xorvwbc   VWBC_XORV
#define     xorvwhu   VWHU_XORV
#define     xorvwhi   VWHI_XORV

#define     xorvdyu   VDYU_XORV
#define     xorvdbu   VDBU_XORV
#define     xorvdbi   VDBI_XORV
#define     xorvdbc   VDBC_XORV
#define     xorvdhu   VDHU_XORV
#define     xorvdhi   VDHI_XORV
#define     xorvdwu   VDWU_XORV
#define     xorvdwi   VDWI_XORV

#define     xorvqyu   VQYU_XORV
#define     xorvqbu   VQBU_XORV
#define     xorvqbi   VQBI_XORV
#define     xorvqbc   VQBC_XORV
#define     xorvqhu   VQHU_XORV
#define     xorvqhi   VQHI_XORV
#define     xorvqwu   VQWU_XORV
#define     xorvqwi   VQWI_XORV
#define     xorvqdu   VQDU_XORV
#define     xorvqdi   VQDI_XORV
#if _LEAVE_XORV
}
#endif

#if _ENTER_XOR1
{
#endif
/*  XOR (atomic fetch xor w/ memory_order_relaxed)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise XOR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_xor and memory_order_relaxed
*/

#define     xor1(...)  (xor1_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xor1_funcof(A, ...) \
FUNCOF_AK(          \
    xor1, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xor1ayu    BOOL_XOR1A
#define     xor1abu   UINT8_XOR1A
#define     xor1abi    INT8_XOR1A
#define     xor1abc    CHAR_XOR1A
#define     xor1ahu  UINT16_XOR1A
#define     xor1ahi   INT16_XOR1A
#define     xor1awu  UINT32_XOR1A
#define     xor1awi   INT32_XOR1A
#define     xor1adu  UINT64_XOR1A
#define     xor1adi   INT64_XOR1A
#if DWRD_NLONG == 2
#   define  xor1alu   ULONG_XOR1A
#   define  xor1ali    LONG_XOR1A
#elif QUAD_NLLONG == 2
#   define  xor1alu  ULLONG_XOR1A
#   define  xor1ali   LLONG_XOR1A
#else
#   define  xor1aqu  ULLONG_XOR1A
#   define  xor1aqi   LLONG_XOR1A
#endif

#if _LEAVE_XOR1
}
#endif

#if _ENTER_XORA
{
#endif
/*  XOR (atomic fetch xor w/ memory_order_acquire)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise XOR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_xor and memory_order_acquire
*/

#define     xora(...)  (xora_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xora_funcof(A, ...) \
FUNCOF_AK(          \
    xora, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xoraayu    BOOL_XORAA
#define     xoraabu   UINT8_XORAA
#define     xoraabi    INT8_XORAA
#define     xoraabc    CHAR_XORAA
#define     xoraahu  UINT16_XORAA
#define     xoraahi   INT16_XORAA
#define     xoraawu  UINT32_XORAA
#define     xoraawi   INT32_XORAA
#define     xoraadu  UINT64_XORAA
#define     xoraadi   INT64_XORAA
#if DWRD_NLONG == 2
#   define  xoraalu   ULONG_XORAA
#   define  xoraali    LONG_XORAA
#elif QUAD_NLLONG == 2
#   define  xoraalu  ULLONG_XORAA
#   define  xoraali   LLONG_XORAA
#else
#   define  xoraaqu  ULLONG_XORAA
#   define  xoraaqi   LLONG_XORAA
#endif

#if _LEAVE_XORA
}
#endif

#if _ENTER_XORE
{
#endif
/*  XOR (atomic fetch xor w/ memory_order_release)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise XOR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_xor and memory_order_release
*/

#define     xore(...)  (xore_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xore_funcof(A, ...) \
FUNCOF_AK(          \
    xore, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xoreayu    BOOL_XOREA
#define     xoreabu   UINT8_XOREA
#define     xoreabi    INT8_XOREA
#define     xoreabc    CHAR_XOREA
#define     xoreahu  UINT16_XOREA
#define     xoreahi   INT16_XOREA
#define     xoreawu  UINT32_XOREA
#define     xoreawi   INT32_XOREA
#define     xoreadu  UINT64_XOREA
#define     xoreadi   INT64_XOREA
#if DWRD_NLONG == 2
#   define  xorealu   ULONG_XOREA
#   define  xoreali    LONG_XOREA
#elif QUAD_NLLONG == 2
#   define  xorealu  ULLONG_XOREA
#   define  xoreali   LLONG_XOREA
#else
#   define  xoreaqu  ULLONG_XOREA
#   define  xoreaqi   LLONG_XOREA
#endif

#if _LEAVE_XORE
}
#endif

#if _ENTER_XORT
{
#endif
/*  XOR (atomic fetch xor w/ memory_order_seq_cst)

Atomically exchange the contents of the scalar variable at
the address specified by the first operand A with the
bitwise XOR of it and the second operand B. Returns the
previous value stored in *A.

If the address is not properly aligned, the result is
undefined. For more info, consult the specification of
C11's atomic_fetch_xor and memory_order_seq_cst
*/

#define     xort(...)  (xort_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     xort_funcof(A, ...) \
FUNCOF_AK(          \
    xort, (   A   ),\
    NONE, /* TGK */ \
    YDZ,  /* TGA */ \
    NONE, /* TGW */ \
    NONE, /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     xortayu    BOOL_XORTA
#define     xortabu   UINT8_XORTA
#define     xortabi    INT8_XORTA
#define     xortabc    CHAR_XORTA
#define     xortahu  UINT16_XORTA
#define     xortahi   INT16_XORTA
#define     xortawu  UINT32_XORTA
#define     xortawi   INT32_XORTA
#define     xortadu  UINT64_XORTA
#define     xortadi   INT64_XORTA
#if DWRD_NLONG == 2
#   define  xortalu   ULONG_XORTA
#   define  xortali    LONG_XORTA
#elif QUAD_NLLONG == 2
#   define  xortalu  ULLONG_XORTA
#   define  xortali   LLONG_XORTA
#else
#   define  xortaqu  ULLONG_XORTA
#   define  xortaqi   LLONG_XORTA
#endif

#if _LEAVE_XORT
}
#endif


#if _ENTER_ZEQY
{
#endif
/*  Zero EQuals (boolean)

Compare each element in the operand to zero. If true, in
the corresponding result element store the integer 1 and
0 if false.

Comparisons of NaN are undefined.
*/

#define     zeqy(...) (zeqy_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zeqy_funcof(A, ...)  \
FUNCOF(             \
    zeqy, (   A   ),\
    YDR,  /* TGK */ \
    YWR,  /* TGW */ \
    YDR,  /* TGD */ \
    YDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zeqyyu    BOOL_ZEQY
#define     zeqybu   UINT8_ZEQY
#define     zeqybi    INT8_ZEQY
#define     zeqybc    CHAR_ZEQY
#define     zeqyhu  UINT16_ZEQY
#define     zeqyhi   INT16_ZEQY
#define     zeqyhf   FLT16_ZEQY
#define     zeqywu  UINT32_ZEQY
#define     zeqywi   INT32_ZEQY
#define     zeqywf     FLT_ZEQY
#define     zeqydu  UINT64_ZEQY
#define     zeqydi   INT64_ZEQY
#define     zeqydf     DBL_ZEQY
#if DWRD_NLONG == 2
#   define  zeqylu   ULONG_ZEQY
#   define  zeqyli    LONG_ZEQY
#elif QUAD_NLLONG == 2
#   define  zeqylu  ULLONG_ZEQY
#   define  zeqyli   LLONG_ZEQY
#else
#   define  zeqyqu  ULLONG_ZEQY
#   define  zeqyqi   LLONG_ZEQY
#   define  zeqyqf    LDBL_ZEQY
#endif

#define     zeqywyu   VWYU_ZEQY
#define     zeqywbu   VWBU_ZEQY
#define     zeqywbi   VWBI_ZEQY
#define     zeqywbc   VWBC_ZEQY
#define     zeqywhu   VWHU_ZEQY
#define     zeqywhi   VWHI_ZEQY
#define     zeqywhf   VWHF_ZEQY
#define     zeqywwu   VWWU_ZEQY
#define     zeqywwi   VWWI_ZEQY
#define     zeqywwf   VWWF_ZEQY

#define     zeqydyu   VDYU_ZEQY
#define     zeqydbu   VDBU_ZEQY
#define     zeqydbi   VDBI_ZEQY
#define     zeqydbc   VDBC_ZEQY
#define     zeqydhu   VDHU_ZEQY
#define     zeqydhi   VDHI_ZEQY
#define     zeqydhf   VDHF_ZEQY
#define     zeqydwu   VDWU_ZEQY
#define     zeqydwi   VDWI_ZEQY
#define     zeqydwf   VDWF_ZEQY
#define     zeqyddu   VDDU_ZEQY
#define     zeqyddi   VDDI_ZEQY
#define     zeqyddf   VDDF_ZEQY

#define     zeqyqyu   VQYU_ZEQY
#define     zeqyqbu   VQBU_ZEQY
#define     zeqyqbi   VQBI_ZEQY
#define     zeqyqbc   VQBC_ZEQY
#define     zeqyqhu   VQHU_ZEQY
#define     zeqyqhi   VQHI_ZEQY
#define     zeqyqhf   VQHF_ZEQY
#define     zeqyqwu   VQWU_ZEQY
#define     zeqyqwi   VQWI_ZEQY
#define     zeqyqwf   VQWF_ZEQY
#define     zeqyqdu   VQDU_ZEQY
#define     zeqyqdi   VQDI_ZEQY
#define     zeqyqdf   VQDF_ZEQY
#if _LEAVE_ZEQY
}
#endif

#if _ENTER_ZEQS
{
#endif
/*  Zero EQuals (saturated)

Compare each element in the operand to zero. If true, in
the corresponding result element store the integer 1 and
0 if false.

Comparisons of NaN are undefined.
*/

#define     zeqs(...) (zeqs_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zeqs_funcof(A, ...) \
FUNCOF(             \
    zeqs, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zeqsbu   UINT8_ZEQS
#define     zeqsbi    INT8_ZEQS
#define     zeqsbc    CHAR_ZEQS
#define     zeqshu  UINT16_ZEQS
#define     zeqshi   INT16_ZEQS
#define     zeqshf   FLT16_ZEQS
#define     zeqswu  UINT32_ZEQS
#define     zeqswi   INT32_ZEQS
#define     zeqswf     FLT_ZEQS
#define     zeqsdu  UINT64_ZEQS
#define     zeqsdi   INT64_ZEQS
#define     zeqsdf     DBL_ZEQS
#if DWRD_NLONG == 2
#   define  zeqslu   ULONG_ZEQS
#   define  zeqsli    LONG_ZEQS
#elif QUAD_NLLONG == 2
#   define  zeqslu  ULLONG_ZEQS
#   define  zeqsli   LLONG_ZEQS
#else
#   define  zeqsqu  ULLONG_ZEQS
#   define  zeqsqi   LLONG_ZEQS
#   define  zeqsqf    LDBL_ZEQS
#endif

#define     zeqswbu   VWBU_ZEQS
#define     zeqswbi   VWBI_ZEQS
#define     zeqswbc   VWBC_ZEQS
#define     zeqswhu   VWHU_ZEQS
#define     zeqswhi   VWHI_ZEQS
#define     zeqswhf   VWHF_ZEQS
#define     zeqswwu   VWWU_ZEQS
#define     zeqswwi   VWWI_ZEQS
#define     zeqswwf   VWWF_ZEQS

#define     zeqsdbu   VDBU_ZEQS
#define     zeqsdbi   VDBI_ZEQS
#define     zeqsdbc   VDBC_ZEQS
#define     zeqsdhu   VDHU_ZEQS
#define     zeqsdhi   VDHI_ZEQS
#define     zeqsdhf   VDHF_ZEQS
#define     zeqsdwu   VDWU_ZEQS
#define     zeqsdwi   VDWI_ZEQS
#define     zeqsdwf   VDWF_ZEQS
#define     zeqsddu   VDDU_ZEQS
#define     zeqsddi   VDDI_ZEQS
#define     zeqsddf   VDDF_ZEQS

#define     zeqsqbu   VQBU_ZEQS
#define     zeqsqbi   VQBI_ZEQS
#define     zeqsqbc   VQBC_ZEQS
#define     zeqsqhu   VQHU_ZEQS
#define     zeqsqhi   VQHI_ZEQS
#define     zeqsqhf   VQHF_ZEQS
#define     zeqsqwu   VQWU_ZEQS
#define     zeqsqwi   VQWI_ZEQS
#define     zeqsqwf   VQWF_ZEQS
#define     zeqsqdu   VQDU_ZEQS
#define     zeqsqdi   VQDI_ZEQS
#define     zeqsqdf   VQDF_ZEQS
#if _LEAVE_ZEQS
}
#endif


#if _ENTER_ZGEY
{
#endif
/*  Zero Greater or Equal (boolean)

For each element E in the operand, set the corresponding
result element to 0 >= E

Comparisons of NaN are undefined.
*/

#define     zgey(...) (zgey_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zgey_funcof(A, ...)  \
FUNCOF(             \
    zgey, (   A   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zgeybi    INT8_ZGEY
#define     zgeybc    CHAR_ZGEY
#define     zgeyhi   INT16_ZGEY
#define     zgeyhf   FLT16_ZGEY
#define     zgeywi   INT32_ZGEY
#define     zgeywf     FLT_ZGEY
#define     zgeydi   INT64_ZGEY
#define     zgeydf     DBL_ZGEY
#if DWRD_NLONG == 2
#   define  zgeylu   ULONG_ZGEY
#   define  zgeyli    LONG_ZGEY
#elif QUAD_NLLONG == 2
#   define  zgeylu  ULLONG_ZGEY
#   define  zgeyli   LLONG_ZGEY
#else
#   define  zgeyqu  ULLONG_ZGEY
#   define  zgeyqi   LLONG_ZGEY
#   define  zgeyqf    LDBL_ZGEY
#endif

#define     zgeywbi   VWBI_ZGEY
#define     zgeywbc   VWBC_ZGEY
#define     zgeywhi   VWHI_ZGEY
#define     zgeywhf   VWHF_ZGEY
#define     zgeywwi   VWWI_ZGEY
#define     zgeywwf   VWWF_ZGEY

#define     zgeydbi   VDBI_ZGEY
#define     zgeydbc   VDBC_ZGEY
#define     zgeydhi   VDHI_ZGEY
#define     zgeydhf   VDHF_ZGEY
#define     zgeydwi   VDWI_ZGEY
#define     zgeydwf   VDWF_ZGEY
#define     zgeyddi   VDDI_ZGEY
#define     zgeyddf   VDDF_ZGEY

#define     zgeyqbi   VQBI_ZGEY
#define     zgeyqbc   VQBC_ZGEY
#define     zgeyqhi   VQHI_ZGEY
#define     zgeyqhf   VQHF_ZGEY
#define     zgeyqwi   VQWI_ZGEY
#define     zgeyqwf   VQWF_ZGEY
#define     zgeyqdi   VQDI_ZGEY
#define     zgeyqdf   VQDF_ZGEY
#if _LEAVE_ZGEY
}
#endif

#if _ENTER_ZGES
{
#endif
/*  Zero Greater or Equal (saturated)

For each element E in the operand, set all bits of the
corresponding result element to the result of 0 >= E.

Comparisons of NaN are undefined.
*/

#define     zges(...) (zges_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zges_funcof(A, ...)  \
FUNCOF(             \
    zges, (   A   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zgesbi    INT8_ZGES
#define     zgesbc    CHAR_ZGES
#define     zgeshi   INT16_ZGES
#define     zgeshf   FLT16_ZGES
#define     zgeswi   INT32_ZGES
#define     zgeswf     FLT_ZGES
#define     zgesdi   INT64_ZGES
#define     zgesdf     DBL_ZGES
#if DWRD_NLONG == 2
#   define  zgeslu   ULONG_ZGES
#   define  zgesli    LONG_ZGES
#elif QUAD_NLLONG == 2
#   define  zgeslu  ULLONG_ZGES
#   define  zgesli   LLONG_ZGES
#else
#   define  zgesqu  ULLONG_ZGES
#   define  zgesqi   LLONG_ZGES
#   define  zgesqf    LDBL_ZGES
#endif

#define     zgeswbi   VWBI_ZGES
#define     zgeswbc   VWBC_ZGES
#define     zgeswhi   VWHI_ZGES
#define     zgeswhf   VWHF_ZGES
#define     zgeswwi   VWWI_ZGES
#define     zgeswwf   VWWF_ZGES

#define     zgesdbi   VDBI_ZGES
#define     zgesdbc   VDBC_ZGES
#define     zgesdhi   VDHI_ZGES
#define     zgesdhf   VDHF_ZGES
#define     zgesdwi   VDWI_ZGES
#define     zgesdwf   VDWF_ZGES
#define     zgesddi   VDDI_ZGES
#define     zgesddf   VDDF_ZGES

#define     zgesqbi   VQBI_ZGES
#define     zgesqbc   VQBC_ZGES
#define     zgesqhi   VQHI_ZGES
#define     zgesqhf   VQHF_ZGES
#define     zgesqwi   VQWI_ZGES
#define     zgesqwf   VQWF_ZGES
#define     zgesqdi   VQDI_ZGES
#define     zgesqdf   VQDF_ZGES
#if _LEAVE_ZGES
}
#endif


#if _ENTER_ZGTY
{
#endif
/*  Zero Greater Than (boolean)

For each element E in the operand, set the corresponding
result element to 0 > E

Comparisons of NaN are undefined.
*/

#define     zgty(...) (zgty_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zgty_funcof(A, ...)  \
FUNCOF(             \
    zgty, (   A   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zgtybi    INT8_ZGTY
#define     zgtybc    CHAR_ZGTY
#define     zgtyhi   INT16_ZGTY
#define     zgtyhf   FLT16_ZGTY
#define     zgtywi   INT32_ZGTY
#define     zgtywf     FLT_ZGTY
#define     zgtydi   INT64_ZGTY
#define     zgtydf     DBL_ZGTY
#if DWRD_NLONG == 2
#   define  zgtylu   ULONG_ZGTY
#   define  zgtyli    LONG_ZGTY
#elif QUAD_NLLONG == 2
#   define  zgtylu  ULLONG_ZGTY
#   define  zgtyli   LLONG_ZGTY
#else
#   define  zgtyqu  ULLONG_ZGTY
#   define  zgtyqi   LLONG_ZGTY
#   define  zgtyqf    LDBL_ZGTY
#endif

#define     zgtywbi   VWBI_ZGTY
#define     zgtywbc   VWBC_ZGTY
#define     zgtywhi   VWHI_ZGTY
#define     zgtywhf   VWHF_ZGTY
#define     zgtywwi   VWWI_ZGTY
#define     zgtywwf   VWWF_ZGTY

#define     zgtydbi   VDBI_ZGTY
#define     zgtydbc   VDBC_ZGTY
#define     zgtydhi   VDHI_ZGTY
#define     zgtydhf   VDHF_ZGTY
#define     zgtydwi   VDWI_ZGTY
#define     zgtydwf   VDWF_ZGTY
#define     zgtyddi   VDDI_ZGTY
#define     zgtyddf   VDDF_ZGTY

#define     zgtyqbi   VQBI_ZGTY
#define     zgtyqbc   VQBC_ZGTY
#define     zgtyqhi   VQHI_ZGTY
#define     zgtyqhf   VQHF_ZGTY
#define     zgtyqwi   VQWI_ZGTY
#define     zgtyqwf   VQWF_ZGTY
#define     zgtyqdi   VQDI_ZGTY
#define     zgtyqdf   VQDF_ZGTY
#if _LEAVE_ZGTY
}
#endif

#if _ENTER_ZGTS
{
#endif
/*  Zero Greater Than (saturated)

For each element E in the operand, set all bits of the
corresponding result element to the result of 0 > E.

Comparisons of NaN are undefined.
*/

#define     zgts(...) (zgts_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zgts_funcof(A, ...)  \
FUNCOF(             \
    zgts, (   A   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zgtsbi    INT8_ZGTS
#define     zgtsbc    CHAR_ZGTS
#define     zgtshi   INT16_ZGTS
#define     zgtshf   FLT16_ZGTS
#define     zgtswi   INT32_ZGTS
#define     zgtswf     FLT_ZGTS
#define     zgtsdi   INT64_ZGTS
#define     zgtsdf     DBL_ZGTS
#if DWRD_NLONG == 2
#   define  zgtslu   ULONG_ZGTS
#   define  zgtsli    LONG_ZGTS
#elif QUAD_NLLONG == 2
#   define  zgtslu  ULLONG_ZGTS
#   define  zgtsli   LLONG_ZGTS
#else
#   define  zgtsqu  ULLONG_ZGTS
#   define  zgtsqi   LLONG_ZGTS
#   define  zgtsqf    LDBL_ZGTS
#endif

#define     zgtswbi   VWBI_ZGTS
#define     zgtswbc   VWBC_ZGTS
#define     zgtswhi   VWHI_ZGTS
#define     zgtswhf   VWHF_ZGTS
#define     zgtswwi   VWWI_ZGTS
#define     zgtswwf   VWWF_ZGTS

#define     zgtsdbi   VDBI_ZGTS
#define     zgtsdbc   VDBC_ZGTS
#define     zgtsdhi   VDHI_ZGTS
#define     zgtsdhf   VDHF_ZGTS
#define     zgtsdwi   VDWI_ZGTS
#define     zgtsdwf   VDWF_ZGTS

#define     zgtsddi   VDDI_ZGTS
#define     zgtsddf   VDDF_ZGTS
#define     zgtsqbi   VQBI_ZGTS
#define     zgtsqbc   VQBC_ZGTS
#define     zgtsqhi   VQHI_ZGTS
#define     zgtsqhf   VQHF_ZGTS
#define     zgtsqwi   VQWI_ZGTS
#define     zgtsqwf   VQWF_ZGTS
#define     zgtsqdi   VQDI_ZGTS
#define     zgtsqdf   VQDF_ZGTS
#if _LEAVE_ZGTS
}
#endif


#if _ENTER_ZNEY
{
#endif
/*  Zero Not Equal (boolean)

For each element E in the operand, set the corresponding
result element to 0 != E

Comparisons of NaN are undefined.
*/

#define     zney(...) (zney_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zney_funcof(A, ...)  \
FUNCOF(             \
    zney, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zneyyu    BOOL_ZNEY
#define     zneybu   UINT8_ZNEY
#define     zneybi    INT8_ZNEY
#define     zneybc    CHAR_ZNEY
#define     zneyhu  UINT16_ZNEY
#define     zneyhi   INT16_ZNEY
#define     zneyhf   FLT16_ZNEY
#define     zneywu  UINT32_ZNEY
#define     zneywi   INT32_ZNEY
#define     zneywf     FLT_ZNEY
#define     zneydu  UINT64_ZNEY
#define     zneydi   INT64_ZNEY
#define     zneydf     DBL_ZNEY
#if DWRD_NLONG == 2
#   define  zneylu   ULONG_ZNEY
#   define  zneyli    LONG_ZNEY
#elif QUAD_NLLONG == 2
#   define  zneylu  ULLONG_ZNEY
#   define  zneyli   LLONG_ZNEY
#else
#   define  zneyqu  ULLONG_ZNEY
#   define  zneyqi   LLONG_ZNEY
#   define  zneyqf    LDBL_ZNEY
#endif

#define     zneywyu   VWYU_ZNEY
#define     zneywbu   VWBU_ZNEY
#define     zneywbi   VWBI_ZNEY
#define     zneywbc   VWBC_ZNEY
#define     zneywhu   VWHU_ZNEY
#define     zneywhi   VWHI_ZNEY
#define     zneywhf   VWHF_ZNEY
#define     zneywwu   VWWU_ZNEY
#define     zneywwi   VWWI_ZNEY
#define     zneywwf   VWWF_ZNEY

#define     zneydyu   VDYU_ZNEY
#define     zneydbu   VDBU_ZNEY
#define     zneydbi   VDBI_ZNEY
#define     zneydbc   VDBC_ZNEY
#define     zneydhu   VDHU_ZNEY
#define     zneydhi   VDHI_ZNEY
#define     zneydhf   VDHF_ZNEY
#define     zneydwu   VDWU_ZNEY
#define     zneydwi   VDWI_ZNEY
#define     zneydwf   VDWF_ZNEY
#define     zneyddu   VDDU_ZNEY
#define     zneyddi   VDDI_ZNEY
#define     zneyddf   VDDF_ZNEY

#define     zneyqyu   VQYU_ZNEY
#define     zneyqbu   VQBU_ZNEY
#define     zneyqbi   VQBI_ZNEY
#define     zneyqbc   VQBC_ZNEY
#define     zneyqhu   VQHU_ZNEY
#define     zneyqhi   VQHI_ZNEY
#define     zneyqhf   VQHF_ZNEY
#define     zneyqwu   VQWU_ZNEY
#define     zneyqwi   VQWI_ZNEY
#define     zneyqwf   VQWF_ZNEY
#define     zneyqdu   VQDU_ZNEY
#define     zneyqdi   VQDI_ZNEY
#define     zneyqdf   VQDF_ZNEY
#if _LEAVE_ZNEY
}
#endif

#if _ENTER_ZNES
{
#endif
/*  Zero Not Equal (saturated)

For each element E in the operand, set all bits of the
corresponding result element to the result of 0 != E.

Comparisons of NaN are undefined.
*/

#define     znes(...) (znes_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     znes_funcof(A, ...)  \
FUNCOF(             \
    znes, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     znesbu   UINT8_ZNES
#define     znesbi    INT8_ZNES
#define     znesbc    CHAR_ZNES
#define     zneshu  UINT16_ZNES
#define     zneshi   INT16_ZNES
#define     zneshf   FLT16_ZNES
#define     zneswu  UINT32_ZNES
#define     zneswi   INT32_ZNES
#define     zneswf     FLT_ZNES
#define     znesdu  UINT64_ZNES
#define     znesdi   INT64_ZNES
#define     znesdf     DBL_ZNES
#if DWRD_NLONG == 2
#   define  zneslu   ULONG_ZNES
#   define  znesli    LONG_ZNES
#elif QUAD_NLLONG == 2
#   define  zneslu  ULLONG_ZNES
#   define  znesli   LLONG_ZNES
#else
#   define  znesqu  ULLONG_ZNES
#   define  znesqi   LLONG_ZNES
#   define  znesqf    LDBL_ZNES
#endif

#define     zneswbu   VWBU_ZNES
#define     zneswbi   VWBI_ZNES
#define     zneswbc   VWBC_ZNES
#define     zneswhu   VWHU_ZNES
#define     zneswhi   VWHI_ZNES
#define     zneswhf   VWHF_ZNES
#define     zneswwu   VWWU_ZNES
#define     zneswwi   VWWI_ZNES
#define     zneswwf   VWWF_ZNES

#define     znesdbu   VDBU_ZNES
#define     znesdbi   VDBI_ZNES
#define     znesdbc   VDBC_ZNES
#define     znesdhu   VDHU_ZNES
#define     znesdhi   VDHI_ZNES
#define     znesdhf   VDHF_ZNES
#define     znesdwu   VDWU_ZNES
#define     znesdwi   VDWI_ZNES
#define     znesdwf   VDWF_ZNES
#define     znesddu   VDDU_ZNES
#define     znesddi   VDDI_ZNES
#define     znesddf   VDDF_ZNES

#define     znesqbu   VQBU_ZNES
#define     znesqbi   VQBI_ZNES
#define     znesqbc   VQBC_ZNES
#define     znesqhu   VQHU_ZNES
#define     znesqhi   VQHI_ZNES
#define     znesqhf   VQHF_ZNES
#define     znesqwu   VQWU_ZNES
#define     znesqwi   VQWI_ZNES
#define     znesqwf   VQWF_ZNES
#define     znesqdu   VQDU_ZNES
#define     znesqdi   VQDI_ZNES
#define     znesqdf   VQDF_ZNES
#if _LEAVE_ZNES
}
#endif


#if _ENTER_ZLTY
{
#endif
/*  Zero Less Than (boolean)

For each element E in the operand, set the corresponding
result element to 0 < E

Comparisons of NaN are undefined.
*/

#define     zlty(...) (zlty_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zlty_funcof(A, ...)  \
FUNCOF(             \
    zlty, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zltybu   UINT8_ZLTY
#define     zltybi    INT8_ZLTY
#define     zltybc    CHAR_ZLTY
#define     zltyhu  UINT16_ZLTY
#define     zltyhi   INT16_ZLTY
#define     zltyhf   FLT16_ZLTY
#define     zltywu  UINT32_ZLTY
#define     zltywi   INT32_ZLTY
#define     zltywf     FLT_ZLTY
#define     zltydu  UINT64_ZLTY
#define     zltydi   INT64_ZLTY
#define     zltydf     DBL_ZLTY
#if DWRD_NLONG == 2
#   define  zltylu   ULONG_ZLTY
#   define  zltyli    LONG_ZLTY
#elif QUAD_NLLONG == 2
#   define  zltylu  ULLONG_ZLTY
#   define  zltyli   LLONG_ZLTY
#else
#   define  zltyqu  ULLONG_ZLTY
#   define  zltyqi   LLONG_ZLTY
#   define  zltyqf    LDBL_ZLTY
#endif

#define     zltywbu   VWBU_ZLTY
#define     zltywbi   VWBI_ZLTY
#define     zltywbc   VWBC_ZLTY
#define     zltywhu   VWHU_ZLTY
#define     zltywhi   VWHI_ZLTY
#define     zltywhf   VWHF_ZLTY
#define     zltywwu   VWWU_ZLTY
#define     zltywwi   VWWI_ZLTY
#define     zltywwf   VWWF_ZLTY

#define     zltydbu   VDBU_ZLTY
#define     zltydbi   VDBI_ZLTY
#define     zltydbc   VDBC_ZLTY
#define     zltydhu   VDHU_ZLTY
#define     zltydhi   VDHI_ZLTY
#define     zltydhf   VDHF_ZLTY
#define     zltydwu   VDWU_ZLTY
#define     zltydwi   VDWI_ZLTY
#define     zltydwf   VDWF_ZLTY
#define     zltyddu   VDDU_ZLTY
#define     zltyddi   VDDI_ZLTY
#define     zltyddf   VDDF_ZLTY

#define     zltyqbu   VQBU_ZLTY
#define     zltyqbi   VQBI_ZLTY
#define     zltyqbc   VQBC_ZLTY
#define     zltyqhu   VQHU_ZLTY
#define     zltyqhi   VQHI_ZLTY
#define     zltyqhf   VQHF_ZLTY
#define     zltyqwu   VQWU_ZLTY
#define     zltyqwi   VQWI_ZLTY
#define     zltyqwf   VQWF_ZLTY
#define     zltyqdu   VQDU_ZLTY
#define     zltyqdi   VQDI_ZLTY
#define     zltyqdf   VQDF_ZLTY
#if _LEAVE_ZLTY
}
#endif

#if _ENTER_ZLTS
{
#endif
/*  Zero Less Than (saturated)

For each element E in the operand, set all bits of the
corresponding result element to the result of 0 < E.

Comparisons of NaN are undefined.
*/

#define     zlts(...) (zlts_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zlts_funcof(A, ...)  \
FUNCOF(             \
    zlts, (   A   ),\
    BDR,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zltsbu   UINT8_ZLTS
#define     zltsbi    INT8_ZLTS
#define     zltsbc    CHAR_ZLTS
#define     zltshu  UINT16_ZLTS
#define     zltshi   INT16_ZLTS
#define     zltshf   FLT16_ZLTS
#define     zltswu  UINT32_ZLTS
#define     zltswi   INT32_ZLTS
#define     zltswf     FLT_ZLTS
#define     zltsdu  UINT64_ZLTS
#define     zltsdi   INT64_ZLTS
#define     zltsdf     DBL_ZLTS
#if DWRD_NLONG == 2
#   define  zltslu   ULONG_ZLTS
#   define  zltsli    LONG_ZLTS
#elif QUAD_NLLONG == 2
#   define  zltslu  ULLONG_ZLTS
#   define  zltsli   LLONG_ZLTS
#else
#   define  zltsqu  ULLONG_ZLTS
#   define  zltsqi   LLONG_ZLTS
#   define  zltsqf    LDBL_ZLTS
#endif

#define     zltswbu   VWBU_ZLTS
#define     zltswbi   VWBI_ZLTS
#define     zltswbc   VWBC_ZLTS
#define     zltswhu   VWHU_ZLTS
#define     zltswhi   VWHI_ZLTS
#define     zltswhf   VWHF_ZLTS
#define     zltswwu   VWWU_ZLTS
#define     zltswwi   VWWI_ZLTS
#define     zltswwf   VWWF_ZLTS

#define     zltsdbu   VDBU_ZLTS
#define     zltsdbi   VDBI_ZLTS
#define     zltsdbc   VDBC_ZLTS
#define     zltsdhu   VDHU_ZLTS
#define     zltsdhi   VDHI_ZLTS
#define     zltsdhf   VDHF_ZLTS
#define     zltsdwu   VDWU_ZLTS
#define     zltsdwi   VDWI_ZLTS
#define     zltsdwf   VDWF_ZLTS
#define     zltsddu   VDDU_ZLTS
#define     zltsddi   VDDI_ZLTS
#define     zltsddf   VDDF_ZLTS

#define     zltsqbu   VQBU_ZLTS
#define     zltsqbi   VQBI_ZLTS
#define     zltsqbc   VQBC_ZLTS
#define     zltsqhu   VQHU_ZLTS
#define     zltsqhi   VQHI_ZLTS
#define     zltsqhf   VQHF_ZLTS
#define     zltsqwu   VQWU_ZLTS
#define     zltsqwi   VQWI_ZLTS
#define     zltsqwf   VQWF_ZLTS
#define     zltsqdu   VQDU_ZLTS
#define     zltsqdi   VQDI_ZLTS
#define     zltsqdf   VQDF_ZLTS
#if _LEAVE_ZLTS
}
#endif


#if _ENTER_ZLEY
{
#endif
/*  Zero Less or Equal (boolean)

For each element E in the operand, set the corresponding
result element to 0 <= E

Comparisons of NaN are undefined.
*/

#define     zley(...) (zley_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zley_funcof(A, ...)  \
FUNCOF(             \
    zley, (   A   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zleybi    INT8_ZLEY
#define     zleybc    CHAR_ZLEY
#define     zleyhi   INT16_ZLEY
#define     zleyhf   FLT16_ZLEY
#define     zleywi   INT32_ZLEY
#define     zleywf     FLT_ZLEY
#define     zleydi   INT64_ZLEY
#define     zleydf     DBL_ZLEY
#if DWRD_NLONG == 2
#   define  zleylu   ULONG_ZLEY
#   define  zleyli    LONG_ZLEY
#elif QUAD_NLLONG == 2
#   define  zleylu  ULLONG_ZLEY
#   define  zleyli   LLONG_ZLEY
#else
#   define  zleyqu  ULLONG_ZLEY
#   define  zleyqi   LLONG_ZLEY
#   define  zleyqf    LDBL_ZLEY
#endif

#define     zleywbi   VWBI_ZLEY
#define     zleywbc   VWBC_ZLEY
#define     zleywhi   VWHI_ZLEY
#define     zleywhf   VWHF_ZLEY
#define     zleywwi   VWWI_ZLEY
#define     zleywwf   VWWF_ZLEY

#define     zleydbi   VDBI_ZLEY
#define     zleydbc   VDBC_ZLEY
#define     zleydhi   VDHI_ZLEY
#define     zleydhf   VDHF_ZLEY
#define     zleydwi   VDWI_ZLEY
#define     zleydwf   VDWF_ZLEY
#define     zleyddi   VDDI_ZLEY
#define     zleyddf   VDDF_ZLEY

#define     zleyqbi   VQBI_ZLEY
#define     zleyqbc   VQBC_ZLEY
#define     zleyqhi   VQHI_ZLEY
#define     zleyqhf   VQHF_ZLEY
#define     zleyqwi   VQWI_ZLEY
#define     zleyqwf   VQWF_ZLEY
#define     zleyqdi   VQDI_ZLEY
#define     zleyqdf   VQDF_ZLEY
#if _LEAVE_ZLEY
}
#endif

#if _ENTER_ZLES
{
#endif
/*  Zero Less or Equal (saturated)

For each element E in the operand, set all bits of the
corresponding result element to the result of 0 <= E.

Comparisons of NaN are undefined.
*/

#define     zles(...) (zles_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zles_funcof(A, ...)  \
FUNCOF(             \
    zles, (   A   ),\
    BDS,  /* TGK */ \
    BWS,  /* TGW */ \
    BDS,  /* TGD */ \
    BDS,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zlesbi    INT8_ZLES
#define     zlesbc    CHAR_ZLES
#define     zleshi   INT16_ZLES
#define     zleshf   FLT16_ZLES
#define     zleswi   INT32_ZLES
#define     zleswf     FLT_ZLES
#define     zlesdi   INT64_ZLES
#define     zlesdf     DBL_ZLES
#if DWRD_NLONG == 2
#   define  zleslu   ULONG_ZLES
#   define  zlesli    LONG_ZLES
#elif QUAD_NLLONG == 2
#   define  zleslu  ULLONG_ZLES
#   define  zlesli   LLONG_ZLES
#else
#   define  zlesqu  ULLONG_ZLES
#   define  zlesqi   LLONG_ZLES
#   define  zlesqf    LDBL_ZLES
#endif

#define     zleswbi   VWBI_ZLES
#define     zleswbc   VWBC_ZLES
#define     zleswhi   VWHI_ZLES
#define     zleswhf   VWHF_ZLES
#define     zleswwi   VWWI_ZLES
#define     zleswwf   VWWF_ZLES

#define     zlesdbi   VDBI_ZLES
#define     zlesdbc   VDBC_ZLES
#define     zlesdhi   VDHI_ZLES
#define     zlesdhf   VDHF_ZLES
#define     zlesdwi   VDWI_ZLES
#define     zlesdwf   VDWF_ZLES
#define     zlesddi   VDDI_ZLES
#define     zlesddf   VDDF_ZLES

#define     zlesqbi   VQBI_ZLES
#define     zlesqbc   VQBC_ZLES
#define     zlesqhi   VQHI_ZLES
#define     zlesqhf   VQHF_ZLES
#define     zlesqwi   VQWI_ZLES
#define     zlesqwf   VQWF_ZLES
#define     zlesqdi   VQDI_ZLES
#define     zlesqdf   VQDF_ZLES
#if _LEAVE_ZLES
}
#endif


#if _ENTER_ZIPP
{
#endif
/*  Interleave pair

For N bit integers, interleave the individual bits in
their binary representation, forming a new 2N bit integer.

For vectors, interleave the elements of two vectors,
forming a new vector with twice as many elements.
*/

#define     zipp(...)    (zipp_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zipp_funcof(X,...)  \
FUNCOF(             \
    zipp, (   X   ),\
    BWU,  /* TGK */ \
    BWR,  /* TGW */ \
    BDR,  /* TGD */ \
    NONE, /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     zippbu UINT8_ZIPP
#define     zippbc CHAR_ZIPP
#define     zipphu UINT16_ZIPP
#define     zippwu UINT32_ZIPP

#define     zippwyu VWYU_ZIPP
#define     zippwbu VWBU_ZIPP
#define     zippwbi VWBI_ZIPP
#define     zippwbc VWBC_ZIPP
#define     zippwhu VWHU_ZIPP
#define     zippwhi VWHI_ZIPP
#define     zippwhf VWHF_ZIPP
#define     zippwwu VWWU_ZIPP
#define     zippwwi VWWI_ZIPP
#define     zippwwf VWWF_ZIPP

#define     zippdyu VDYU_ZIPP
#define     zippdbu VDBU_ZIPP
#define     zippdbi VDBI_ZIPP
#define     zippdbc VDBC_ZIPP
#define     zippdhu VDHU_ZIPP
#define     zippdhi VDHI_ZIPP
#define     zippdhf VDHF_ZIPP
#define     zippdwu VDWU_ZIPP
#define     zippdwi VDWI_ZIPP
#define     zippdwf VDWF_ZIPP
#define     zippddu VDDU_ZIPP
#define     zippddi VDDI_ZIPP
#define     zippddf VDDF_ZIPP

#define     zippqyu VQYU_ZIPP
#define     zippqbu VQBU_ZIPP
#define     zippqbi VQBI_ZIPP
#define     zippqbc VQBC_ZIPP
#define     zippqhu VQHU_ZIPP
#define     zippqhi VQHI_ZIPP
#define     zippqhf VQHF_ZIPP
#define     zippqwu VQWU_ZIPP
#define     zippqwi VQWI_ZIPP
#define     zippqwf VQWF_ZIPP
#define     zippqdu VQDU_ZIPP
#define     zippqdi VQDI_ZIPP
#define     zippqdf VQDF_ZIPP
#if _LEAVE_ZIPP
}
#endif

#if _ENTER_ZIPL
{
#endif
/*  Interleave the lower halves of two vectors */

#define     zipl(...)    (zipl_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zipl_funcof(X,...)  \
FUNCOF(             \
    zipl, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ziplwbu VWBU_ZIPL
#define     ziplwbi VWBI_ZIPL
#define     ziplwbc VWBC_ZIPL
#define     ziplwhu VWHU_ZIPL
#define     ziplwhi VWHI_ZIPL
#define     ziplwhf VWHF_ZIPL

#define     zipldbu VDBU_ZIPL
#define     zipldbi VDBI_ZIPL
#define     zipldbc VDBC_ZIPL
#define     zipldhu VDHU_ZIPL
#define     zipldhi VDHI_ZIPL
#define     zipldhf VDHF_ZIPL
#define     zipldwu VDWU_ZIPL
#define     zipldwi VDWI_ZIPL
#define     zipldwf VDWF_ZIPL

#define     ziplqbu VQBU_ZIPL
#define     ziplqbi VQBI_ZIPL
#define     ziplqbc VQBC_ZIPL
#define     ziplqhu VQHU_ZIPL
#define     ziplqhi VQHI_ZIPL
#define     ziplqhf VQHF_ZIPL
#define     ziplqwu VQWU_ZIPL
#define     ziplqwi VQWI_ZIPL
#define     ziplqwf VQWF_ZIPL
#define     ziplqdu VQDU_ZIPL
#define     ziplqdi VQDI_ZIPL
#define     ziplqdf VQDF_ZIPL
#if _LEAVE_ZIPL
}
#endif

#if _ENTER_ZIPR
{
#endif
/*  Interleave the upper halves of two vectors */

#define     zipr(...)    (zipr_funcof(__VA_ARGS__)(__VA_ARGS__))
#define     zipr_funcof(X,...)  \
FUNCOF(             \
    zipr, (   X   ),\
    NONE, /* TGK */ \
    BHR,  /* TGW */ \
    BWR,  /* TGD */ \
    BDR,  /* TGQ */ \
    NONE, /* TGO */ \
    NONE, /* TGS */ \
    default: NULL   \
)

#define     ziprwbu VWBU_ZIPR
#define     ziprwbi VWBI_ZIPR
#define     ziprwbc VWBC_ZIPR
#define     ziprwhu VWHU_ZIPR
#define     ziprwhi VWHI_ZIPR
#define     ziprwhf VWHF_ZIPR

#define     ziprdbu VDBU_ZIPR
#define     ziprdbi VDBI_ZIPR
#define     ziprdbc VDBC_ZIPR
#define     ziprdhu VDHU_ZIPR
#define     ziprdhi VDHI_ZIPR
#define     ziprdhf VDHF_ZIPR
#define     ziprdwu VDWU_ZIPR
#define     ziprdwi VDWI_ZIPR
#define     ziprdwf VDWF_ZIPR

#define     ziprqbu VQBU_ZIPR
#define     ziprqbi VQBI_ZIPR
#define     ziprqbc VQBC_ZIPR
#define     ziprqhu VQHU_ZIPR
#define     ziprqhi VQHI_ZIPR
#define     ziprqhf VQHF_ZIPR
#define     ziprqwu VQWU_ZIPR
#define     ziprqwi VQWI_ZIPR
#define     ziprqwf VQWF_ZIPR
#define     ziprqdu VQDU_ZIPR
#define     ziprqdi VQDI_ZIPR
#define     ziprqdf VQDF_ZIPR
#if _LEAVE_ZIPR
}
#endif


#if _ENTER_WTF_IS_THIS
{
#endif

#define     TGV_BDU(_) TGW_BDU(_) TGD_BDU(_) TGQ_BDU(_) TGO_BDU(_) TGS_BDU(_)
#define     TGV_BDI(_) TGW_BDI(_) TGD_BDI(_) TGQ_BDI(_) TGO_BDI(_) TGS_BDI(_)
#define     TGV_BDF(_) TGW_BDF(_) TGD_BDF(_) TGQ_BDF(_) TGO_BDF(_) TGS_BDF(_)
#define     TGV_BDZ(_) TGW_BDZ(_) TGD_BDZ(_) TGQ_BDZ(_) TGO_BDZ(_) TGS_BDZ(_)
#define     TGV_BDS(_) TGW_BDS(_) TGD_BDS(_) TGQ_BDS(_) TGO_BDS(_) TGS_BDS(_)
#define     TGV_BDR(_) TGW_BDR(_) TGD_BDR(_) TGQ_BDR(_) TGO_BDR(_) TGR_BDR(_)

#if _LEAVE_WTF_IS_THIS
}
#endif

#ifdef SPC_ARM_NEON

int TEST_ARM_GET1(FILE *f)
{
    if (f == NULL)
        f = stdout;
    int res;
    int sum = 0;
#define MY_TEST(...)                \
    res = fprintf(f, __VA_ARGS__);  \
    if (res < 0) goto FAIL;         \
    sum += res

    MY_TEST("TEST_ARM_GET1()\n");

    Vdhu dh = newl(Vdhu, '0','1','2','3');
    dh = VDHU_PERS(dh, 3,0,1, 2);
    MY_TEST(
        "%c%c%c%c\n",
        VDHU_GET1(dh, 0),
        VDHU_GET1(dh, 1),
        VDHU_GET1(dh, 2),
        VDHU_GET1(dh, 3)
    );

#undef MY_TEST
    SUCC: return sum;
    FAIL: return res;
}

void TEST_ARM_PERS(void)
{
    float32x2_t df = vreinterpret_f32_s32(vdup_n_s32(0));
    Vwbu w0123 = newl(Vwbu, '0', '1','2','3');
    Vwbu w3012 = VWBU_PERS(w0123, 3,0,1,2);
    uint8_t s16[17] = {0};
    df = vset_lane_f32(VWBU_ASTM(w3012), df, 0);
    vst1_u8(s16, VDWF_ASBU(df));
    (void) printf(
        "%.16s\n",
        s16
    );

}

#endif

int wtfclang(void) {return 0;}


int         outfwbu(Vwbu src, FILE *dst, char const *fmt)
{
    unsigned char seq[4];
    (void) UCHAR_STRWA(seq, src);
    return fprintf(
        dst, fmt,
        seq[0], seq[1], seq[2], seq[3]
    );
}

#define     outfwbi(src, ...) outfwbu(VWBI_ASTU(src), __VA_ARGS__)
#define     outfwbc(src, ...) outfwbu(VWBC_ASTU(src), __VA_ARGS__)
#if 0 // NO OUTS

int         outfwhu(Vwhu src, FILE *dst, char const *fmt)
{
    unsigned short seq[2];
    (void) USHRT_STRWA(seq, src);
    return fprintf(dst, fmt, seq[0], seq[1]);
}

#define     outfwhi(src, ...) outfwhu(VWHI_ASTU(src), __VA_ARGS__)


int         outfdbu(Vdbu src, FILE *dst, char const *fmt)
{
    unsigned char seq[8];
    (void) UINT8_STRDA(seq, src);
    return fprintf(
        dst, fmt,
        seq[0], seq[1], seq[2], seq[3],
        seq[4], seq[5], seq[6], seq[7]
    );
}
#define     outfdbi(src, ...) outfdbu(VDBI_ASTU(src), __VA_ARGS__)
#define     outfdbc(src, ...) outfdbu(VDBC_ASTU(src), __VA_ARGS__)

int         outfdhu(Vdhu src, FILE *dst, char const *fmt)
{
#define     outfdhi(src, ...) outfdhu(VDHI_ASTU(src), __VA_ARGS__)
    unsigned short seq[4];
    (void) UINT16_STRDA(seq, src);
    return fprintf(
        dst, fmt,
        seq[0], seq[1], seq[2], seq[3]
    );
}

int         outfdwu(Vdwu src, FILE *dst, char const *fmt)
{
#define     outfdwi(src, ...) outfdwu(VDWI_ASTU(src), __VA_ARGS__)
    unsigned seq[2];
    (void) UINT32_STRDA(seq, src);
    return fprintf(
        dst, fmt,
        seq[0], seq[1]
    );
}

int         outfddu(Vddu src, FILE *dst, char const *fmt)
{
#define     outfddi(src, ...) outfddu(VDDI_ASTU(src), __VA_ARGS__)
    uint64_t seq[1];
    (void) UINT64_STRDA(seq, src);
    return fprintf(dst, fmt, seq[0]);
}

int         outfqbu(Vqbu src, FILE *dst, char const *fmt)
{
    unsigned char seq[16];
    (void) UINT8_STRQA(seq, src);
    return fprintf(
        dst, fmt,
        seq[0x0], seq[0x1], seq[0x2], seq[0x3],
        seq[0x4], seq[0x5], seq[0x6], seq[0x7],
        seq[0x8], seq[0x9], seq[0xa], seq[0xb],
        seq[0xc], seq[0xd], seq[0xe], seq[0xf]
    );
}

int         outfqhu(Vqhu src, FILE *dst, char const *fmt)
{
    unsigned short seq[8];
    (void) UINT16_STRQA(seq, src);
    return fprintf(
        dst, fmt,
        seq[0], seq[1], seq[2], seq[3],
        seq[4], seq[5], seq[6], seq[7]
    );
}
#define     outfqhi(src, ...) outfqhu(VQHI_ASTU(src), __VA_ARGS__)

int         outfqwu(Vqwu src, FILE *dst, char const *fmt)
{
    uint32_t d[4];
    (void) UINT32_STRQA(d, src);
    return fprintf(dst, fmt, d[0], d[1], d[2], d[3]);
}
#define     outfqwi(src, ...) outfqwu(VQWI_ASTU(src), __VA_ARGS__)

int         outfqdu(Vqdu src, FILE *dst, char const *fmt)
{
    uint64_t d[2];
    (void) UINT64_STRQA(d, src);
    return fprintf(dst, fmt, d[0], d[1]);
}
#define     outfqdi(src, ...) outfqdu(VQDI_ASTU(src), __VA_ARGS__)

#endif

#if 1 // NO TOAY

void *toayyu(_Bool v, char s[1], size_t n[1])
{
    s[0] = '0'+v;
    n[0] = 1;
    return s;
}

INLINE(char *,MY_TOAYBU)
(
    unsigned    v,
    char        a[8],
    Rc(0, 7)    z
)
{
    switch (z)
    {
        case 0: {a[7] = '0'+(v&1); v >>= 1;}
        case 1: {a[6] = '0'+(v&1); v >>= 1;}
        case 2: {a[5] = '0'+(v&1); v >>= 1;}
        case 3: {a[4] = '0'+(v&1); v >>= 1;}
        case 4: {a[3] = '0'+(v&1); v >>= 1;}
        case 5: {a[2] = '0'+(v&1); v >>= 1;}
        case 6: {a[1] = '0'+(v&1); v >>= 1;}
        case 7: {a[0] = '0'+(v&1);}
    }
    return  a+(8-z);
}

INLINE(char *,MY_TOAYHU)
(
    unsigned    v,
    char        a[16],
    Rc(0, 15)   z
)
{
    switch (z)
    {
        case  0: {a[0xf] = '0'+(v&1); v >>= 1;}
        case  1: {a[0xe] = '0'+(v&1); v >>= 1;}
        case  2: {a[0xd] = '0'+(v&1); v >>= 1;}
        case  3: {a[0xc] = '0'+(v&1); v >>= 1;}
        case  4: {a[0xb] = '0'+(v&1); v >>= 1;}
        case  5: {a[0xa] = '0'+(v&1); v >>= 1;}
        case  6: {a[0x9] = '0'+(v&1); v >>= 1;}
        case  7: {a[0x8] = '0'+(v&1); v >>= 1;}
        case  8: {a[0x7] = '0'+(v&1); v >>= 1;}
        case  9: {a[0x6] = '0'+(v&1); v >>= 1;}
        case 10: {a[0x5] = '0'+(v&1); v >>= 1;}
        case 11: {a[0x4] = '0'+(v&1); v >>= 1;}
        case 12: {a[0x3] = '0'+(v&1); v >>= 1;}
        case 13: {a[0x2] = '0'+(v&1); v >>= 1;}
        case 14: {a[0x1] = '0'+(v&1); v >>= 1;}
        case 15: {a[0x0] = '0'+(v&1); v >>= 1;}
    }
    return  a+(16-z);
}

INLINE(char *,MY_TOAYWU) (uint32_t v, char a[32], Rc(0, 31) z)
{
    switch (z)
    {
        case  0: {a[0x1f] = '0'+(v&1); v >>= 1;}
        case  1: {a[0x1e] = '0'+(v&1); v >>= 1;}
        case  2: {a[0x1d] = '0'+(v&1); v >>= 1;}
        case  3: {a[0x1c] = '0'+(v&1); v >>= 1;}
        case  4: {a[0x1b] = '0'+(v&1); v >>= 1;}
        case  5: {a[0x1a] = '0'+(v&1); v >>= 1;}
        case  6: {a[0x19] = '0'+(v&1); v >>= 1;}
        case  7: {a[0x18] = '0'+(v&1); v >>= 1;}
        case  8: {a[0x17] = '0'+(v&1); v >>= 1;}
        case  9: {a[0x16] = '0'+(v&1); v >>= 1;}
        case 10: {a[0x15] = '0'+(v&1); v >>= 1;}
        case 11: {a[0x14] = '0'+(v&1); v >>= 1;}
        case 12: {a[0x13] = '0'+(v&1); v >>= 1;}
        case 13: {a[0x12] = '0'+(v&1); v >>= 1;}
        case 14: {a[0x11] = '0'+(v&1); v >>= 1;}
        case 15: {a[0x10] = '0'+(v&1); v >>= 1;}
        case 16: {a[0x0f] = '0'+(v&1); v >>= 1;}
        case 17: {a[0x0e] = '0'+(v&1); v >>= 1;}
        case 18: {a[0x0d] = '0'+(v&1); v >>= 1;}
        case 19: {a[0x0c] = '0'+(v&1); v >>= 1;}
        case 20: {a[0x0b] = '0'+(v&1); v >>= 1;}
        case 21: {a[0x0a] = '0'+(v&1); v >>= 1;}
        case 22: {a[0x09] = '0'+(v&1); v >>= 1;}
        case 23: {a[0x08] = '0'+(v&1); v >>= 1;}
        case 24: {a[0x07] = '0'+(v&1); v >>= 1;}
        case 25: {a[0x06] = '0'+(v&1); v >>= 1;}
        case 26: {a[0x05] = '0'+(v&1); v >>= 1;}
        case 27: {a[0x04] = '0'+(v&1); v >>= 1;}
        case 28: {a[0x03] = '0'+(v&1); v >>= 1;}
        case 29: {a[0x02] = '0'+(v&1); v >>= 1;}
        case 30: {a[0x01] = '0'+(v&1); v >>= 1;}
        case 31: {a[0x00] = '0'+(v&1); v >>= 1;}
    }
    return  a+(32-z);
}

INLINE(char *,MY_TOAYDU) (uint64_t v, char a[64],Rc(0, 63) z)
{
    if (z >= 32)
        return MY_TOAYWU(v, a, z-32);
    return MY_TOAYWU(v, MY_TOAYWU(v>>32, a, z), 0);
}

INLINE(char *,MY_TOAYQU) (QUAD_UTYPE v, char a[128],Rc(0, 127) z)
{
    if (z >= 64)
        return MY_TOAYDU(v, a, z-64);
    return MY_TOAYDU(v, MY_TOAYDU(v>>64, a, z), 0);
}


char *toaybu(uint8_t v, char s[8])
{
    unsigned const z = cszrbu(v);
    if (z==8)
    {
        *s++ = '0';
        return s;
    }
    return  MY_TOAYBU(v, s, z);
}

char *toayhu(uint16_t v, char s[16])
{
    unsigned const z = cszrhu(v);
    if (z==16)
    {
        *s++ = '0';
        return s;
    }
    return  MY_TOAYHU(v, s, z);
}

char *toaywu(uint32_t v, char s[32])
{
    unsigned const z = cszrwu(v);
    if (z==32)
    {
        *s++ = '0';
        return s;
    }
    return  MY_TOAYWU(v, s, z);
}

char *toaydu(uint64_t v, char s[64])
{
    unsigned const z = cszrdu(v);
    if (z==64)
    {
        *s++ = '0';
        return s;
    }
    return  MY_TOAYDU(v, s, z);
}

char *toayqu(QUAD_UTYPE v, char s[128])
{
    unsigned const z = cszrqu(v);
    if (z==128)
    {
        *s++ = '0';
        return s;
    }
    return  MY_TOAYQU(v, s, z);
}

char *toayqyu(Vqyu v, char s[128])
{
    union {
        Vqyu V;
        QUAD_UTYPE U;
    } t = {v};
    return toayqu(t.U, s);
}

void *toadbu(uint8_t v, char s[UINT8_DIG])
{
    return s;
}

#endif // NO TOAY
#if 0

#include <ctype.h>
#include <string.h>
#include <time.h>
char const *volatile testupr_src;
char const *volatile testupr_dst;


    size_t 
    my_strlen(char const str[])
    {
    
        size_t      off = 0x7&(uintptr_t) str;
        size_t      len = 0;
        Vdbc        vec = ldrd(str-off);
        uint64_t    bar;
        if (off)
        {
            str = str-off;
            vec = orrs(vec, asbc(unosddu((8*off))));
        }
        for (;;)
        {
            vec = zeqs(vec);
            bar = astv(asdu(vec));
            if (bar)
                break;
            len += 8;
            vec = ldrd(str+len);
        }
        return (len-off)+(cszl(bar)/8);
    }

    char * 
    av_strupr (char str[])
    {
        char *ret = str;
        for (;*str;str++) 
        {
            *str = toupper(*str);
        }
        return ret;
    }

    char * 
    my_strupr (char str[])
    {
        size_t      off = 0x7&(uintptr_t) str;
        char       *ret = str;
        Vdbc        vec;
        Vdbc        end;
        uint64_t    bar;
        int ctr = 0;
        if (off)
        {
            str -= off;
            for (; off < 8; off++)
            {
                if (!str[off]) 
                    return ret;
                str[off] -= (32&cbnsbc(str[off], 'a', 'z'));
            }
            str += 8;
        }
        for (;;str+=8)
        {
            vec = ldrdacbc(str);
            end = zeqsdbc(vec);
            bar = astvddu(asdudbc(end));
            if (ctr++ > 100)
            {
                printf("oops\n");
                return ret;
            }
            if (bar)
            {
                for (off=0; str[off] && (off < 8); off++)
                {
                    str[off] -= (32&cbnsbc(str[off], 'a', 'z'));
                }
                break;
            }
            vec = subldbc(
                vec, 
                andsdbc(
                    dupdbc(32),
                    cbnsdbc(vec, 'a', 'z')
                )
            );
            (void) strdabc(str, vec);
        }
        return  ret;
    }
    


void testupr(int t, long n)
{
    struct timespec bt, at;
    (void) clock_gettime(CLOCK_MONOTONIC, &bt);
    char str[257] = {0};

    if (t)
    {
        for (int i=0; i < n; i++)
        {
            testupr_dst = av_strupr(strcpy(str, testupr_src));
        }
    }
    else
    {
        for (int i=0; i < n; i++)
        {
            testupr_dst = my_strupr(strcpy(str, testupr_src));
        }
        
    }

    printf(
        "done with test on str[%zu] = \"%s\"\n",
        strlen(str),
        str
    );
    (void) clock_gettime(CLOCK_MONOTONIC, &at);
    printf(
        "tv_sec=%"  INT64_DFMT ", "
        "tv_nsec=%" INT64_DFMT "\n", 
        ((int64_t) (at.tv_sec -bt.tv_sec)),
        ((int64_t) (at.tv_nsec-bt.tv_nsec))
    );
    
}

#endif

Vdhu test_addldhu(Vdhu a, Vdhu b)
{
    return addl(a, b);
}

