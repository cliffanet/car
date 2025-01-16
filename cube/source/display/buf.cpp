#include "buf.h"

#include <stdlib.h>
#include <string.h>

DsplBuf24::DsplBuf24(uint16_t w, uint16_t h, uint8_t xcnt, uint8_t ycnt) :
    DsplDraw(w, h),
    _xcnt(xcnt),
    _ycnt(ycnt),
    _x(0),
    _y(0),
    _w(0),
    _h(0),
    _d1(reinterpret_cast<uint8_t *>(malloc(dsz()))),
    _d2(reinterpret_cast<uint8_t *>(malloc(dsz()))),
    _d(_d2),
    _bn(1),
    _col1(0),
    _col2(0),
    _col3(0)
{ }

DsplBuf24::~DsplBuf24() {
    if (_d1 != NULL)
        free(_d1);
    if (_d2 != NULL)
        free(_d2);
}

uint8_t *DsplBuf24::_dnxt() {
    _bn ++;
    _bn &= 0x1;
    _d = _bn ? _d2 : _d1;
    if (_d != NULL)
        // надо полностью почистить буфер
        bzero(_d, dsz());
    return _d;
}

void DsplBuf24::begin() {
    _x = 0;
    _y = 0;
    _w = _xcnt > 0 ? width / _xcnt : 0;
    _h = _ycnt > 0 ? height / _ycnt : 0;
    _dnxt();
}

void DsplBuf24::color(uint16_t c) {
    _col1 = (c & 0xFF00) >> 8;
    _col2 = (c & 0x07E0) >> 3;
    _col3 = (c & 0x001F) << 3;
}

void DsplBuf24::pixel(int x, int y) {
    if ((_d == NULL) || !visibled(x, y))
        return;
    auto c = d(x, y);
    *c = _col1;
    c++;
    *c = _col2;
    c++;
    *c = _col3;
}

void DsplBuf24::fill(int x, int y, uint16_t w, uint16_t h) {
    if (_d == NULL)
        return;
    // сначала поправим координату x, должно выполняться: (x >= _x) && (x < _x+_w)
    if (x < _x) {
        if (x+w <= _x)
            return; // полный выход за пределы буфера слева
        w -= _x-x;
        x = _x;
    }
    else
    if (x >= _x+_w)
        return; // полный выход за пределы буфера справа
    // ширина
    if (x+w > _x+_w)
        w = _x+_w-x;
    
    // теперь проверяем аналогично y, должно выполняться: (y >= _y) && (y < _y+_h)
    if (y < _y) {
        if (y+h <= _y)
            return; // полный выход за пределы буфера сверху
        h -= _y-y;
        y = _y;
    }
    else
    if (y >= _y+_h)
        return; // полный выход за пределы буфера снизу
    // высота
    if (y+h > _y+_h)
        h = _y+_h-y;

    // можно закрашивать
    auto c = d(x, y);
    if (c == NULL)
        return;
    // отступы от буфера слева и справа,
    // которые нам надо будет проскочить после каждой строки
    // отступ слева: x-_x, справа: (_x+_w) - (x+w)
    // суммируем, раскрываем скобки, сокращаем - получаем только разницу: _w-w
    int pad = (_w-w) * 3;
    for (; h > 0; h--) {
        for (auto ww = w; ww > 0; ww--) {
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

bool DsplBuf24::next() {
    if ((_y > height) || (_xcnt == 0) || (_ycnt == 0) || (_d == NULL))
        return false;

    // чистим буфер к следующему приёму данных
    _dnxt();
    
    _x += width / _xcnt;
    if (_x + _w <= width)
        // следующий горизонтальный фрейм,
        // полностью вмещается в экран, всё ок
        return true;
    if (_x < width) {
        // следующий горизонтальный фрейм,
        // в экран попадает, но частично, нужно обрезать справа
        _w = width - _x;
        return true;
    }

    // горизонтальная строка фреймов закончилась,
    // переходим к следующей
    _x = 0;
    _w = width / _xcnt;
    _y += height / _ycnt;
    // далее аналогичный алгоритм проверки, как и по горизонтали
    if (_y + _h <= height)
        // эта строчка полностью влазит по высоте, всё ок
        return true;
    if (_y < height) {
        // эта строка попадает в экран, но частично
        _h = height - _y;
        return true;
    }

    // дисплей весь завершился

    return false;
}
