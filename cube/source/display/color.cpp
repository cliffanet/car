#include "color.h"
    #include <math.h>

namespace color {
    hsv_t rgb2hsv(uint8_t r, uint8_t g, uint8_t b) {
        uint16_t max = (r >= g) && (r >= b) ? r : g >= b ? g : b;
        uint16_t min = (r <= g) && (r <= b) ? r : g <= b ? g : b;
        uint16_t d = max - min;
        uint16_t d6 = d*6;

        uint8_t
            h =
                d == 0      ? 0 :
                max == r    ? ((    g-b) << 8) / d6 :
                max == g    ? ((d*2+b-r) << 8) / d6 :
                              ((d*4+r-g) << 8) / d6,
            
            s = max == 0 ? 0 : ((d << 8)-d) / max;
        
        return { h, s, static_cast<uint8_t>(max)};
    }

    rgb_t hsv2rgb(const hsv_t &c) {
        uint16_t f = static_cast<uint16_t>(c.h)*6;
        uint8_t h = f >> 8;
        f &= 0xff;

        uint8_t m = static_cast<uint16_t>(c.v) * (255 - c.s) / 255;
        uint8_t q = static_cast<uint16_t>(c.v) * (255 - f * c.s / 255) / 255;
        uint8_t t = static_cast<uint16_t>(c.v) * (255 - (255-f) * c.s / 255) / 255;

        switch (h) {
            case 0:
                return {    c.v,    t,      m   };
            case 1:
                return {    q,      c.v,    m   };
            case 2:
                return {    m,      c.v,    t   };
            case 3:
                return {    m,      q,      c.v };
            case 4:
                return {    t,      m,      c.v };
            case 5:
                return {    c.v,    m,      q   };
        }
        return { 0, 0, 0 };
    }


    hsl_t rgb2hsl(uint8_t r, uint8_t g, uint8_t b) {
        uint16_t max = (r >= g) && (r >= b) ? r : g >= b ? g : b;
        uint16_t min = (r <= g) && (r <= b) ? r : g <= b ? g : b;
        uint16_t d = max - min;
        uint16_t d6 = d*6;

        uint8_t
            h =
                d == 0      ? 0 :
                max == r    ? ((    g-b) << 8) / d6 :
                max == g    ? ((d*2+b-r) << 8) / d6 :
                              ((d*4+r-g) << 8) / d6,
            
            l = (max + min) / 2,
            
            s = d == 0 ? 0 : ((d << 8)-d) / 255 - abs(max+min-255);
        
        return { h, s, l};
    }
    rgb_t hsl2rgb(const hsl_t &i) {
        int16_t f = static_cast<int16_t>(i.h)*6;
        uint8_t h = f >> 8;
        f &= 0x1ff;
        int16_t l2 = static_cast<int16_t>(i.l) << 1;

        uint16_t c = (255 - abs(l2 - 255)) * i.s / 255;
        uint16_t x = c * (255 - abs(f-255)) / 255;
        uint16_t m = (l2 - c) >> 1;
        c += m;
        x += m;

        switch (h) {
            case 0:
                return {    static_cast<uint8_t>(c),      static_cast<uint8_t>(x),      static_cast<uint8_t>(m)   };
            case 1:
                return {    static_cast<uint8_t>(x),      static_cast<uint8_t>(c),      static_cast<uint8_t>(m)   };
            case 2:
                return {    static_cast<uint8_t>(m),      static_cast<uint8_t>(c),      static_cast<uint8_t>(x)   };
            case 3:
                return {    static_cast<uint8_t>(m),      static_cast<uint8_t>(x),      static_cast<uint8_t>(c)   };
            case 4:
                return {    static_cast<uint8_t>(x),      static_cast<uint8_t>(m),      static_cast<uint8_t>(c)   };
            case 5:
                return {    static_cast<uint8_t>(c),      static_cast<uint8_t>(m),      static_cast<uint8_t>(x)   };
        }
        return { 0, 0, 0 };
    }
};
