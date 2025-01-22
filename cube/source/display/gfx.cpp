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
    
    _beg -= rngbeg;
    
    return true;
}

inline bool _rngok(int &_v, int rngbeg, int rnglen) {
    if ((_v >= rngbeg) && (_v < rngbeg+rnglen)) {
        _v -= rngbeg;
        return true;
    }

    return false;
}

inline void _pix(DsplFrame &f, int x, int y) {
    if (_rngok(x, f.x, f.w) && _rngok(y, f.y, f.h))
        f.pixel(x, y);
}

inline void _hline(DsplFrame &f, int x, int y, uint16_t w) {
    if (_rngok(y, f.y, f.h) && _rngfix(x, w, f.x, f.w))
        f.fill(x, y, w, 1);
}
inline void _vline(DsplFrame &f, int x, int y, uint16_t h) {
    if (_rngok(x, f.x, f.w) && _rngfix(y, h, f.y, f.h))
        f.fill(x, y, 1, h);
}

class _Circle {
    int f, ddx, ddy;
public:
    uint16_t x, y;
    _Circle(int r) { reset(r); }
    bool next() {
        if (x >= y)
            return false;
        if (f >= 0) {
            y--;
            ddy += 2;
            f += ddy;
        }
        x++;
        ddx += 2;
        f += ddx;
        return true;
    }
    void reset(int r) {
        f   = 1 - r;
        ddx = 1;
        ddy = (-r)*2;
        x   = 0;
        y   = r;
    }
};

void DsplGfx::fill(int x, int y, uint16_t w, uint16_t h) {
    // сначала поправим координату x, должно выполняться: (x >= _x) && (x < _x+_w)
    if (!_rngfix(x, w, _frm.x, _frm.w))
        return;
    
    // теперь проверяем аналогично y, должно выполняться: (y >= _y) && (y < _y+_h)
    if (!_rngfix(y, h, _frm.y, _frm.h))
        return;
    
    _frm.fill(x, y, w, h);
}

void DsplGfx::rect(int x, int y, uint16_t w, uint16_t h) {
    if ((w == 0) || (h == 0))
        return;
    _hline(_frm,    x,      y,      w);
    _hline(_frm,    x,      y+h-1,  w);
    _vline(_frm,    x,      y,      h);
    _vline(_frm,    x+w-1,  y,      h);
}

void DsplGfx::rfill(int x, int y, uint16_t w, uint16_t h, uint16_t r) {
    if (r == 0) {
        fill(x, y, w, h);
        return;
    }

    int xl = x+r, xr = x+w-r-1, wc = xr-xl+1, yt = y+r, yb = y+h-r-1;
    if (yb >= yt)
        fill(x, yt, w, yb-yt+1);
        
    _Circle p(r);
    _hline(_frm, xl, y,     wc);
    _hline(_frm, xl, y+h-1, wc);
    while (p.next()) {
        _hline(_frm,    xl - p.x,   yt - p.y,   p.x + wc + p.x);
        _hline(_frm,    xl - p.y,   yt - p.x,   p.y + wc + p.y);
        _hline(_frm,    xl - p.x,   yb + p.y,   p.x + wc + p.x);
        _hline(_frm,    xl - p.y,   yb + p.x,   p.y + wc + p.y);
    }
}

void DsplGfx::rrect(int x, int y, uint16_t w, uint16_t h, uint16_t r) {
    if (r == 0) {
        rect(x, y, w, h);
        return;
    }

    int xl = x+r, xr = x+w-r-1, wc = xr-xl+1, yt = y+r, yb = y+h-r-1, hc = yb-yt+1;
    if (hc > 0) {
        _vline(_frm, x, yt, hc);
        _vline(_frm, x+w-1, yt, hc);
    }
    if (wc > 0) {
        _hline(_frm, xl, y,     wc);
        _hline(_frm, xl, y+h-1, wc);
    }
        
    _Circle p(r);
    while (p.next()) {
        _pix(_frm,  xl - p.x,   yt - p.y);
        _pix(_frm,  xr + p.x,   yt - p.y);
        _pix(_frm,  xl - p.y,   yt - p.x);
        _pix(_frm,  xr + p.y,   yt - p.x);
        _pix(_frm,  xl - p.x,   yb + p.y);
        _pix(_frm,  xr + p.x,   yb + p.y);
        _pix(_frm,  xl - p.y,   yb + p.x);
        _pix(_frm,  xr + p.y,   yb + p.x);
    }
}

void DsplGfx::circle(int x, int y, uint16_t r) {
    _Circle p(r);
    do {
        _pix(_frm,  x - p.x,    y - p.y);
        _pix(_frm,  x - p.y,    y - p.x);
        _pix(_frm,  x + p.x,    y - p.y);
        _pix(_frm,  x + p.y,    y - p.x);
        _pix(_frm,  x - p.x,    y + p.y);
        _pix(_frm,  x - p.y,    y + p.x);
        _pix(_frm,  x + p.x,    y + p.y);
        _pix(_frm,  x + p.y,    y + p.x);
    } while (p.next());
}

void DsplGfx::disc(int x, int y, uint16_t r) {
    _Circle p(r);
    do {
        _hline(_frm,    x - p.x,    y - p.y,    p.x * 2 + 1);
        _hline(_frm,    x - p.y,    y - p.x,    p.y * 2 + 1);
        _hline(_frm,    x - p.x,    y + p.y,    p.x * 2 + 1);
        _hline(_frm,    x - p.y,    y + p.x,    p.y * 2 + 1);
    } while (p.next());
}

void DsplGfx::fmap(int x, int y, uint16_t w, uint16_t h, const uint8_t *data) {
    int ox=x, oy=y, ow=w;

    if (!_rngfix(x, w, _frm.x, _frm.w) || !_rngfix(y, h, _frm.y, _frm.h))
        return;

    // количество пропущенных точек в самом начале
    uint32_t bit = (y+_frm.y - oy) * ow + (x+_frm.x - ox);
    // пропускаем целые байты
    data += bit >> 3;
    // а bit - останется текущим битом в байте
    bit = 1 << (bit & 0x7);

    // разница между оригинальной шириной и пересчитанной
    // кол-во пикселей, пропускаемых после каждой строчки
    ow -= w;
    // разбиваем их на целое число байт
    uint16_t pad_b  = ow >> 3;
    // и на число бит в байте
    uint8_t pad_p   = ow & 0x7;

    for (; h > 0; h --, y++) {
        auto xx = x;
        for (auto ww = w; ww > 0; ww--, xx++) {
            while (bit > 0xff) {
                bit >>= 8;
                data++;
            }
            if (*data & bit)
                _frm.pixel(xx, y);
            bit <<= 1;
        }
        
        data += pad_b;
        bit  <<= pad_p;
    }
}

void DsplGfx::text(int x, int y, const DsplFontU8g2 &fnt, const char *_s) {
    DsplStr s(_s);
    
    while (1) {
        auto c = s.fetch();
        if (c == 0xffff)
            return;
        
        auto o = fnt.symbinf(c);
        if (!o)
            continue;
        
        x += o.padl();
        int y1 = y - (o.padt()+o.h());

        if (_frm.visible(x, y1, o.w(), o.h())) {
            uint8_t d[o.bufsz()] = { 0 };
            o.fill(d);
            fmap(x, y1, o.w(), o.h(), d);
        }

        x += o.dx();
    }
}
