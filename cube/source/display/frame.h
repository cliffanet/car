#ifndef __display_frame_H
#define __display_frame_H

#include <stddef.h>
#include <stdint.h>

class DsplFrame {
public:
    // координаты этого фрейма, в котором мы будем рисовать
    const uint16_t x, y, w, h;

    DsplFrame(uint16_t x, uint16_t y, uint16_t w, uint16_t h) : x(x), y(y), w(w), h(h) {}
    DsplFrame(const DsplFrame &d) : DsplFrame(d.x, d.y, d.w, d.h) {};
    virtual ~DsplFrame() = default;

    DsplFrame& operator=(DsplFrame &&o) {
        if (this == &o)
            return *this;
        *const_cast<uint16_t *>(&x) = o.x;
        *const_cast<uint16_t *>(&y) = o.y;
        *const_cast<uint16_t *>(&w) = o.w;
        *const_cast<uint16_t *>(&h) = o.h;
        return *this;
    }

    virtual void zero() = 0;
    virtual void color(uint16_t c) = 0;
    virtual void pixel(uint16_t x, uint16_t y) = 0;
    virtual void fill(uint16_t x, uint16_t y, uint16_t w, uint16_t h) = 0;
};


class DsplFrame24 : public DsplFrame {
    uint8_t *_d;
    uint8_t _col1, _col2, _col3;
    inline uint8_t *d(uint16_t _x, uint16_t _y) {
        return _d + (_y*w + _x)*3;
    }
public:
    DsplFrame24(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t *data);
    inline const uint8_t *d() const { return _d; }
    inline size_t sz() const { return w*h*3; }
    void zero();
    void color(uint16_t _c);
    void pixel(uint16_t _x, uint16_t _y);
    void fill(uint16_t _x, uint16_t _y, uint16_t _w, uint16_t _h);
};

#endif // __display_frame_H
