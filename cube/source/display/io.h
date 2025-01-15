#ifndef __display_io_H
#define __display_io_H

#include <stdint.h>

class DsplDraw {
public:
    const uint16_t width, height;
    DsplDraw(uint16_t w, uint16_t h) : width(w), height(h) {}
    virtual ~DsplDraw() = default;

    virtual void begin() = 0;
    virtual void pixel(int x, int y, uint16_t color) = 0;
    virtual void fill(int x, int y, uint16_t w, uint16_t h, uint16_t color) = 0;
    virtual bool next() = 0;
};

class DsplGfx;
class DsplIO {

public:
    virtual void init() = 0;
    virtual DsplGfx draw() = 0;
};


#endif // __display_io_H
