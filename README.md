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
    *du     uint32_t
    *di     int32_t
    *hf     flt16_t (binary16 float, i.e. "half precision")
    *wf     float  
    *df     double 
    *wyu    (32×bool)
    *wbu    (4×uint8_t)
    *wbi    (4×int8_t)
    *whu    (2×uint16_t)
    *whi    (2×int16_t)
    *whf    (2×flt16_t)
    *wwu    (1×uint32_t)
    *wwi    (1×int32_t)
    *dyu    (64×bool)
    *dbu    (8×uint8_t)
    *dbi    (8×int8_t)
    *dbc    (8×char)
    *dhu    (4×uint16_t)
    *dhi    (4×int16_t)
    *dhf    (4×flt16_t)
    *dwu    (2×uint32_t)
    *dwi    (2×int32_t)
    *dwf    (2×float)
    *ddu    (1×uint64_t)
    *ddi    (1×int64_t)
    *ddf    (1×double)
    *qyu    (128×bool)
    *qbu    (16×uint8_t)
    *qbi    (16×int8_t)
    *qbc    (16×char)
    *qhu    (8×uint16_t)
    *qhi    (8×int16_t)
    *qhf    (8×flt16_t)
    *qwu    (4×uint32_t)
    *qwi    (4 ×int32_t)
    *qwf    (4×float)
    *qdu    (2×uint64_t)
    *qdi    (2×int64_t)
    *qdf    (2×double)
