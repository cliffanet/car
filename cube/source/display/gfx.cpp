#include "gfx.h"

DsplGfx::DsplGfx(DsplDraw &draw) :
    _draw(&draw)
{
    _draw->begin();
}

void DsplGfx::clearScreen(uint16_t color) {
    _draw->fill(0, 0, _draw->width, _draw->height, color);
    //for (int x = 0; x < _draw->width; x++)
    //    for (int y = 0; y < _draw->height; y++)
    //        _draw->pixel(x, y, color);
}
