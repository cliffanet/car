#ifndef __display_fontu8g2_H
#define __display_fontu8g2_H

#include <stdint.h>
#include <stdlib.h>

class DsplStr {
    const char *_s;
public:
    DsplStr(const char *_s) : _s(_s) {}
    virtual uint16_t fetch() {
        uint16_t c = *_s;
        if (c == 0)
            c = 0x0ffff;
        else
            _s++;
        return c;
    }
};

class DsplFontU8g2 {
    /* offset 0 */
    uint8_t glyph_cnt;
    uint8_t bbx_mode;
    uint8_t bits_per_0;
    uint8_t bits_per_1;
    
    /* offset 4 */
    uint8_t bits_per_char_width;
    uint8_t bits_per_char_height;		
    uint8_t bits_per_char_x;
    uint8_t bits_per_char_y;
    uint8_t bits_per_delta_x;
    
    /* offset 9 */
    int8_t max_char_width;
    int8_t max_char_height; /* overall height, NOT ascent. Instead ascent = max_char_height + y_offset */
    int8_t x_offset;
    int8_t y_offset;
    
    /* offset 13 */
    int8_t  ascent_A;
    int8_t  descent_g;	/* usually a negative value */
    int8_t  ascent_para;
    int8_t  descent_para;
        
    /* offset 17 */
    uint16_t start_pos_upper_A;
    uint16_t start_pos_lower_a; 
    
    /* offset 21 */
    uint16_t start_pos_unicode;

    const uint8_t *_d;

    const uint8_t *_data(uint16_t s) const;

    class SymbInf {
        const DsplFontU8g2 &_f;
        const uint8_t *_d;
        uint8_t _bit;
        uint8_t _w, _h;
        uint8_t _padl, _padt, _dx;
        uint8_t bitu(uint8_t sz);
        int8_t bits(uint8_t sz);
    public:
        SymbInf(const DsplFontU8g2 &_f, uint16_t symb);
        operator    bool()  const { return _d != NULL; }
        uint8_t     w()     const { return _w; }
        uint8_t     h()     const { return _h; }
        uint8_t     padl()  const { return _padl; }
        uint8_t     padt()  const { return _padt; }
        uint8_t     dx()    const { return _dx; }
        uint16_t    bufsz() const { return (_w*_h + 7) / 8; }
        void fill(uint8_t *_buf);
    };
public:
    DsplFontU8g2(const uint8_t *font);
    int8_t  ascent()    const { return ascent_A; }
    int8_t  descent()   const { return descent_g; }
    uint16_t width(const char *s);

    SymbInf symbinf(uint16_t symb) const { return SymbInf(*this, symb); };
};


#endif // __display_fontu8g2_H
