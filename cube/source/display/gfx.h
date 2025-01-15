#ifndef __display_gfx_H
#define __display_gfx_H

#include "io.h"

class DsplGfx {
    DsplDraw *_draw;
public:
    DsplGfx(DsplDraw &draw);

    inline uint16_t width() const { return _draw->width; }
    inline uint16_t w()     const { return _draw->width; }
    inline uint16_t height()const { return _draw->height; }
    inline uint16_t h()     const { return _draw->height; }

    inline bool next() { return _draw->next(); }

    void clearScreen(uint16_t color);
};


#endif // __display_gfx_H
