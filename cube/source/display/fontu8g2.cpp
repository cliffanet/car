#include "fontu8g2.h"

#include <strings.h>

/* size of the font data structure, there is no struct or class... */
/* this is the size for the new font format */
#define U8G2_FONT_DATA_STRUCT_SIZE 23

DsplFontU8g2::SymbInf::SymbInf(const DsplFontU8g2 &_f, uint16_t symb) :
    _f(_f),
    _d(_f._data(symb)),
    _bit(0)
{
    if (_d == NULL) {
        _w = 0;
        _h = 0;
        _padl = 0;
        _padt = 0;
        _dx = 0;
    }
    else {
        _w      = bitu(_f.bits_per_char_width);
        _h      = bitu(_f.bits_per_char_height);
        _padl   = bits(_f.bits_per_char_x);
        _padt   = bits(_f.bits_per_char_y);
        _dx     = bits(_f.bits_per_delta_x);
    }
}

uint8_t DsplFontU8g2::SymbInf::bitu(uint8_t sz) {
    uint8_t v = (*_d) >> _bit;
    uint8_t nxt = _bit+sz;
    if (nxt > 7) {
        _d ++;
        nxt &= 0x7;
        v |= (*_d) << (8-_bit);
    }
    v &= (1U<<sz)-1;
    _bit = nxt;

    return v;
}

int8_t DsplFontU8g2::SymbInf::bits(uint8_t sz) {
    return static_cast<int8_t>(bitu(sz)) - (1 << (sz-1));
}

void DsplFontU8g2::SymbInf::fill(uint8_t *_buf) {
    //bzero(_buf, bufsz());

    uint16_t sz = _w * _h;
    uint16_t bit = 0;
    while (sz > 0) {
        auto b0 = bitu(_f.bits_per_0);
        auto b1 = bitu(_f.bits_per_1);

        do {
            if (b0 > sz) b0 = sz;
            sz  -= b0;
            bit += b0;
            while (bit > 7) {
                bit -= 8;
                _buf++;
            }

            for (auto bb = b1; (bb > 0) && (sz > 0); bb--, sz--) {
                *_buf |= 1<<bit;
                bit++;
                if (bit > 7) {
                    bit = 0;
                    _buf++;
                }
            }
        } while (bitu(1) != 0);
    }
}


static inline uint8_t _vv(const uint8_t **r) {
    uint8_t v = **r;
    (*r)++;
    return v;
}
DsplFontU8g2::DsplFontU8g2(const uint8_t *font) :
    _d(font + U8G2_FONT_DATA_STRUCT_SIZE)
{
    /* offset 0 */
    glyph_cnt               = _vv(&font);
    bbx_mode                = _vv(&font);
    bits_per_0              = _vv(&font);
    bits_per_1              = _vv(&font);
    
    /* offset 4 */
    bits_per_char_width     = _vv(&font);
    bits_per_char_height    = _vv(&font);
    bits_per_char_x         = _vv(&font);
    bits_per_char_y         = _vv(&font);
    bits_per_delta_x        = _vv(&font);
    
    /* offset 9 */
    max_char_width          = _vv(&font);
    max_char_height         = _vv(&font);
    x_offset                = _vv(&font);
    y_offset                = _vv(&font);
    
    /* offset 13 */
    ascent_A                = _vv(&font);
    descent_g               = _vv(&font);
    ascent_para             = _vv(&font);
    descent_para            = _vv(&font);
    
    /* offset 17 */
    uint16_t h = _vv(&font);
    start_pos_upper_A       = (h << 8) | _vv(&font);
    h = _vv(&font);
    start_pos_lower_a       = (h << 8) | _vv(&font);
    
    /* offset 21 */
    h = _vv(&font);
    start_pos_unicode       = (h << 8) | _vv(&font);
}

uint16_t DsplFontU8g2::width(const char *_s) {
    DsplStr s(_s);
    uint16_t x = 0;
    
    while (1) {
        auto c = s.fetch();
        if (c == 0xffff)
            break;
        
        auto o = symbinf(c);
        if (!o)
            continue;
        
        x += o.padl() + o.dx();
    }

    return x;
}

const uint8_t *DsplFontU8g2::_data(uint16_t s) const {
    auto d = _d;

    if ( s <= 255 ) {
        if ( s >= 'a' )
            d += start_pos_lower_a;
        else
        if ( s >= 'A' )
            d += start_pos_upper_A;
        
        for(;;) {
            if ( *(d + 1) == 0 )
                break;
            if ( *d == s )
                return d+2;	/* skip encoding and glyph size */
            d += *(d + 1);
        }
    }
    
    return NULL;
}
