#ifndef __display_color_H
#define __display_color_H

#include "stdint.h"

namespace color {

    typedef struct {
        uint8_t r, g, b;
    } rgb_t;

    typedef struct {
        uint8_t h, s, v;
    } hsv_t;
    hsv_t rgb2hsv(uint8_t r, uint8_t g, uint8_t b);
    inline
    hsv_t rgb2hsv(const rgb_t &c) {
        return rgb2hsv(c.r, c.g, c.b);
    }
    rgb_t hsv2rgb(const hsv_t &c);

    typedef struct {
        uint8_t h, s, l;
    } hsl_t;
    hsl_t rgb2hsl(uint8_t r, uint8_t g, uint8_t b);
    inline
    hsl_t rgb2hsl(const rgb_t &c) {
        return rgb2hsl(c.r, c.g, c.b);
    }
    rgb_t hsl2rgb(const hsl_t &i);
};


#endif // __display_gfx_H
