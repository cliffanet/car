#ifndef __display_buf_H
#define __display_buf_H

#include <stddef.h>
#include "io.h"

class DsplBuf24 : public DsplDraw {
    const uint16_t _xcnt, _ycnt;
    int _x, _y;
    uint16_t _w, _h;
    uint8_t *_d;
    inline size_t dsz() const { return (static_cast<size_t>(width) / _xcnt) * (static_cast<size_t>(height) / _ycnt) * 3; }
    inline uint8_t *d(int x, int y) {
        if (_d == NULL)
            return NULL;
        if ((x < _x) || (x >= _x+_w) || (y < _y) || (y >= _y+_h))
            return NULL;
        return _d + ((y-_y)*_w + (x-_x))*3;
    }

protected:
    const uint8_t *data() const { return _d; }
    const size_t sz() const { return _w*_h*3; }

    typedef struct {
        uint16_t x;
        uint16_t y;
        uint16_t w;
        uint16_t h;
    } area_t;
    const area_t area() const { return { static_cast<uint16_t>(_x), static_cast<uint16_t>(_y), _w, _h }; }

public:
    DsplBuf24(uint16_t w, uint16_t h, uint8_t xcnt, uint8_t ycnt);
    ~DsplBuf24();

    virtual void begin();
    void pixel(int x, int y, uint16_t color);
    void fill(int x, int y, uint16_t w, uint16_t h, uint16_t color);
    virtual bool next();
};


#endif // __display_buf_H
