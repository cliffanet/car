#ifndef __display_buf_H
#define __display_buf_H

#include <stddef.h>
#include <stdint.h>

class DsplBufDbl {
    const uint16_t _dsplw, _dsplh, _frmw, _frmh;
    uint16_t _x, _y;
    uint16_t _w, _h;
    uint8_t *_d1, *_d2;
    size_t _bsz;
    uint8_t _bn;
public:
    // Создаёт сам буферы
    DsplBufDbl(uint16_t dsplwidth, uint16_t dsplheight, uint8_t xcnt, uint8_t ycnt, uint8_t *_buf1, uint8_t *_buf2);

    inline uint16_t dsplw() const { return _dsplw; }
    inline uint16_t dsplh() const { return _dsplh; }

    template<class T>
    inline T frame() { return T(_x, _y, _w, _h, _bn ? _d2 : _d1); }

    void begin();
    bool nextfrm();
    void nextbuf();
};


#endif // __display_buf_H
