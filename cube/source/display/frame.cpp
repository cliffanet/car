#include "frame.h"

#include <stdlib.h>
#include <string.h>


DsplFrame24::DsplFrame24(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t *data) :
    DsplFrame(x, y, w, h),
    _d(data)
{ }

void DsplFrame24::zero() {
    _col1 = 0;
    _col2 = 0;
    _col3 = 0;
    bzero(_d, sz());
}

void DsplFrame24::color(uint16_t _c) {
    _col1 = (_c & 0xFF00) >> 8;
    _col2 = (_c & 0x07E0) >> 3;
    _col3 = (_c & 0x001F) << 3;
}

void DsplFrame24::color(uint8_t r, uint8_t g, uint8_t b) {
    _col1 = r & 0xfc;
    _col2 = g & 0xfc;
    _col3 = b & 0xfc;
}

void DsplFrame24::pixel(uint16_t _x, uint16_t _y) {
    auto c = d(_x, _y);
    *c = _col1;
    c++;
    *c = _col2;
    c++;
    *c = _col3;
}

void DsplFrame24::fill(uint16_t _x, uint16_t _y, uint16_t _w, uint16_t _h) {
    auto c = d(_x, _y);
    // отступы от буфера слева и справа,
    // которые нам надо будет проскочить после каждой строки
    // отступ слева: x-_x, справа: (_x+_w) - (x+w)
    // суммируем, раскрываем скобки, сокращаем - получаем только разницу: _w-w
    int pad = (w-_w) * 3;
    for (; _h > 0; _h--) {
        for (auto w1 = _w; w1 > 0; w1--) {
            *c = _col1;
            c++;
            *c = _col2;
            c++;
            *c = _col3;
            c++;
        }
        c += pad;
    }
}
