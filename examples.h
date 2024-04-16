
/*  Keep everything indented by 4 */


    /*

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
    
    