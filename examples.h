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
        for (int loops = 0;;)
        {
            vec = zeqs(vec);
            bar = astv(asdu(vec));
            if (bar)
                break;
            len += 8;
            vec = ldrd(str+len);
            if (loops++ > 100)
            {
                printf("woops\n");
                return -1;
            }
        }
        return (len-off)+(cszl(bar)/8);
    }
    