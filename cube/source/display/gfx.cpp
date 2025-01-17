#include "gfx.h"

// исправление значений диапазона _beg~_len до допустимого-видимого rngbeg~rnglen
inline bool _rngfix(int &_beg, uint16_t &_len, int rngbeg, int rnglen) {
    if (_beg < rngbeg) {
        if (_beg+_len <= rngbeg)
            return false; // полный выход за пределы буфера слева
        _len -= rngbeg-_beg;
        _beg = rngbeg;
    }
    else
    if (_beg >= rngbeg+rnglen)
        return false; // полный выход за пределы буфера справа
    // ширина
    if (_beg+_len > rngbeg+rnglen)
        _len = rngbeg+rnglen - _beg;
    
    return true;
}

inline bool _rngok(int _v, int rngbeg, int rnglen) {
    return (_v >= rngbeg) && (_v < rngbeg+rnglen);
}

inline void _hline(DsplFrame &f, int x, int y, uint16_t w) {
    if (!_rngok(y, f.y, f.h))
        return;
    if (!_rngfix(x, w, f.x, f.w))
        return;
    f.fill(x-f.x, y-f.y, w, 1);
}
inline void _vline(DsplFrame &f, int x, int y, uint16_t h) {
    if (!_rngok(x, f.x, f.w))
        return;
    if (!_rngfix(y, h, f.y, f.h))
        return;
    f.fill(x-f.x, y-f.y, 1, h);
}


void DsplGfx::fill(int x, int y, uint16_t w, uint16_t h) {
    // сначала поправим координату x, должно выполняться: (x >= _x) && (x < _x+_w)
    if (!_rngfix(x, w, _frm.x, _frm.w))
        return;
    
    // теперь проверяем аналогично y, должно выполняться: (y >= _y) && (y < _y+_h)
    if (!_rngfix(y, h, _frm.y, _frm.h))
        return;
    
    _frm.fill(x-_frm.x, y-_frm.y, w, h);
}

void DsplGfx::rect(int x, int y, uint16_t w, uint16_t h) {
    if ((w == 0) || (h == 0))
        return;
    _hline(_frm,    x,      y,      w);
    _hline(_frm,    x,      y+h-1,  w);
    _vline(_frm,    x,      y,      h);
    _vline(_frm,    x+w-1,  y,      h);
}
