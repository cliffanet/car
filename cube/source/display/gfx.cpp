#include "gfx.h"

DsplGfx::DsplGfx(DsplDraw &draw) :
    _draw(&draw)
{
    _draw->begin();
}

void DsplGfx::rect(int x, int y, uint16_t w, uint16_t h) {
    if ((w == 0) || (h == 0))
        return;
    _draw->fill(x, y, w, 1);
    _draw->fill(x, y+h-1, w, 1);
    _draw->fill(x, y, 1, h);
    _draw->fill(x+w-1, y, 1, h);
}
