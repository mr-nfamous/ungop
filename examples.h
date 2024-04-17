
/*  Keep everything indented by 4 */


    /* "my_strlen"

    * ldrd(src) means load 64 bit vector. This is the
    generic form, which calls the type specific ldrdabc.
    NOTE: ldrdabc requires an 8 byte aligned address despite
    the C function signature. According to the style guide,
    array parameters have an alignment requirement equivalent
    to the total size of the array, not whatever pointer type
    the array "decays" to.

        // req = sizeof (char const[8])
        INLINE(Vdbc,ldrdabc) (char const src[8]);

    * unosddu means fill a Vddu (uint64x1) with sequential 1s
    NOTE: it's quite likely unos will be renamed unol and a
    unor added, which sets 1s beginning at the msb

    * astv(v) reinterprets single element vector v as scalar
    or scalar as single element vector. E.g. astvddu takes
    Vddu and returns uint64_t.

    * orrs(a, b) is equivalent to a|b. NOTE: bitwise ops are
    not defined for floats. If a and/or b have floating
    element types, use orrs(astu(a), astu(b))

    * zeqs here calls zeqsdbc, which tests each element for
    equality to zero. If true, the element is set to all 1,
    otherwise all zero.

    * cszl counts sequential zeros starting at the least
    significant bit. NOTE: arm doesn't have SIMD cszl for 64
    bit operands. I.e. cszlddu is implemented as a mov from
    vector to x-greg followed by ctz.

    ASM: (-O2)
        // -- Begin function my_strlen
            .globl my_strlen                     
            .p2align 2
            .type my_strlen,@function
        my_strlen:   // @my_strlen
            .cfi_startproc
        // %bb.0:
            and     x9, x0, #0xfffffffffffffff8
            and     x10, x0, #0x7
            neg     x8, x10
            ldr     d0, [x9]
            cbz     x10, .LBB22_2
        // %bb.1:
            lsl     x10, x10, #3
            mov     x11, #-1
            neg     x10, x10
            mov     x0, x9
            lsr     x10, x11, x10
            fmov    d1, x10
            orr     v0.8b, v0.8b, v1.8b
            .LBB22_2:
            cmeq    v0.8b, v0.8b, #0
            fmov    x9, d0
            cbnz    x9, .LBB22_6
        // %bb.3:
            add     x9, x0, #8
        // =>This Inner Loop Header: Depth=1
            .LBB22_4:                              
            ldr     d0, [x9], #8
            add     x8, x8, #8
            cmeq    v0.8b, v0.8b, #0
            fmov    x10, d0
            cbz     x10, .LBB22_4
        // %bb.5:
            fmov    x9, d0
            .LBB22_6:
            rbit    x9, x9
            clz     x9, x9
            add     x0, x8, x9, lsr #3
            ret
            .Lfunc_end22:
            .size my_strlen, .Lfunc_end22-my_strlen
            .cfi_endproc
        // -- End function
    */

    size_t
    my_strlen(char const str[])
    {

        size_t      len = 0;
        size_t      off = 0x7&(uintptr_t) str;
        Vdbc        vec = ldrd( (str-off) );
        uint64_t    bar;
        if (off)
        {
            str = str-off;
            vec = orrs(vec, asbc(unosddu( (8*off) )));
        }
        for (;;)
        {
            vec = zeqs(vec);
            bar = astv(asdu(vec));
            if (bar)
                break;
            len += 8;
            vec = ldrd( (str+len) );
        }
        return (len-off)+(cszl(bar)/8);
    }

    /*
    Inplace capitalize NUL terminated ASCII string. After
    handling a potentially unaligned pointer, simultaneously
    capitalize 8 lowercase letters per iteration. In this
    example, the type specific forms are always used.

    Newly introduced ops include:

    * subldbc: sub+l+dbc = (char×8 - char×8)
    * cbnsdbc: cbn+s+dbc = saturated ((a[0] < b) && (a[0] < c))
    * dupdbc:  dup+d+bc  = (char×8){k,k,k,k, k,k,k,k}
    * strdabc: str+d+abc = store char×8 to 8B aligned
    */

    char *
    my_strupr(char str[])
    {
        size_t      off = 0x7&(uintptr_t) str;
        char       *ret = str;
        Vdbc        vec;
        Vdbc        end;
        uint64_t    bar;
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
