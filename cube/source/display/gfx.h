#ifndef __display_gfx_H
#define __display_gfx_H

#include "io.h"

#define COLOR_BLACK         0x0000
#define COLOR_GRAY          0xF7DE
#define COLOR_BLUE          0x001F
#define COLOR_RED           0xF800
#define COLOR_GREEN         0x07E0
#define COLOR_CYAN          0x07FF
#define COLOR_MAGENTA       0xF81F
#define COLOR_YELLOW        0xFFE0
#define COLOR_WHITE         0xFFFF

class DsplGfx {
    DsplDraw *_draw;
public:
    DsplGfx(DsplDraw &draw);

    inline uint16_t width() const { return _draw->width; }
    inline uint16_t w()     const { return _draw->width; }
    inline uint16_t height()const { return _draw->height; }
    inline uint16_t h()     const { return _draw->height; }

    inline bool next() { return _draw->next(); }

    inline void color(uint16_t c) { _draw->color(c); };
    inline void clearScreen() {
        _draw->fill(0, 0, _draw->width, _draw->height);
        //for (int x = 0; x < _draw->width; x++)
        //    for (int y = 0; y < _draw->height; y++)
        //        _draw->pixel(x, y);
    }
    inline void fill(int x, int y, uint16_t w, uint16_t h) {
        _draw->fill(x, y, w, h);
    }
    void rect(int x, int y, uint16_t w, uint16_t h);
};


#endif // __display_gfx_H
