# ungop
It's pronounced like "ungop"

ungop - pronounced "ungop" - is the specification of a set
of generic low level operations. It includes a C reference
implementation in which each operation is defined as a macro
that uses the C11 _Generic operator to select the function
designator representing the type specific operation, based on
the first operand.

The following set of types have, when applicable, their own
operation. The first column contains the type's operation
suffix:

    *yu     bool
    *bu     uint8_t
    *bi     int8_t
    *bc     char
    *hu     uint16_t
    *hi     int16_t
    *wu     uint32_t
    *wi     int32_t
    *du     uint64_t
    *di     int64_t
    *df     double
    *hf     flt16_t (binary16 float, i.e. "half precision")
    *wf     float  
    *df     double 
    *wyu    Vwyu (32×bool)
    *wbu    Vwbu (4×uint8_t)
    *wbi    Vwbi (4×int8_t)
    *wbc    Vwbc (4xchar)
    *whu    Vwhu (2×uint16_t)
    *whi    Vwhi (2×int16_t)
    *whf    Vwhf (2×flt16_t)
    *wwu    Vwwu (1×uint32_t)
    *wwi    Vwwi (1×int32_t)
    *wwf    Vwwf (1×float)
    *dyu    Vdyu (64×bool)
    *dbu    Vdbu (8×uint8_t)
    *dbi    Vdbi (8×int8_t)
    *dbc    Vdbc (8×char)
    *dhu    Vdhu (4×uint16_t)
    *dhi    Vdhi (4×int16_t)
    *dhf    Vdhf (4×flt16_t)
    *dwu    Vdwu (2×uint32_t)
    *dwi    Vdwi (2×int32_t)
    *dwf    Vdwf (2×float)
    *ddu    Vddu (1×uint64_t)
    *ddi    Vddi (1×int64_t)
    *ddf    Vddf (1×double)
    *qyu    Vqyu (128×bool)
    *qbu    Vqbu (16×uint8_t)
    *qbi    Vqbi (16×int8_t)
    *qbc    Vqbc (16×char)
    *qhu    Vqhu (8×uint16_t)
    *qhi    Vqhi (8×int16_t)
    *qhf    Vqhf (8×flt16_t)
    *qwu    Vqwu (4×uint32_t)
    *qwi    Vqwi (4 ×int32_t)
    *qwf    Vqwf (4×float)
    *qdu    Vqdu (2×uint64_t)
    *qdi    Vqdi (2×int64_t)
    *qdf    Vqdf (2×double)

Since ungop is essentially an expansive extension to the
C standard library, the most important consideration was 
how names were chosen. We wanted:

## Uniqueness
None of the names may conflict with any symbol defined or
reserved by the C23 standard or any of its standard annexes,
any version of POSIX/XSI, Microsoft's "Win32" and own C 
library (msvcrt), Google's "bionic", "glibc", or Apple's 
standard library. They also shouldn't be English words that
might conflict with commonly used variable or function names.
E.g. the name of "releasing atomic bitwise NOT" is "inve",
not "note".

## Readability

Compare:

    atomic_compare_exchange_strong_explicit(
        a, b, c,
        memory_order_seq_cst,
        memory_order_seq_cst
    )

from C11's <stdatomic.h> to our equivalent 

    xeqt(a, b, c)

or from C23's <stdbit.h>

    stdc_leading_zerosull

with 

    cszrlu

Ok, perhaps the latter isn't *too* difficult to recognize
or remember, but for such an important and common operation,
its bulkiness is not insignificant.
