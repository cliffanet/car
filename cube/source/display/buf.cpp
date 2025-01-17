#include "buf.h"

#include <stdlib.h>
#include <string.h>

DsplBufDbl::DsplBufDbl(uint16_t dsplwidth, uint16_t dsplheight, uint8_t xcnt, uint8_t ycnt, uint8_t *_buf1, uint8_t *_buf2) :
    _dsplw(dsplwidth),
    _dsplh(dsplheight),
    _frmw(xcnt > 0 ? dsplwidth / xcnt : 0),
    _frmh(ycnt > 0 ? dsplheight / ycnt : 0),
    _x(0),
    _y(0),
    _w(0),
    _h(0),
    _d1(_buf1),
    _d2(_buf2),
    _bn(0)
{ }

void DsplBufDbl::begin() {
    _x = 0;
    _y = 0;
    _w = _frmw;
    _h = _frmh;
    _bn = 0;
}

bool DsplBufDbl::nextfrm() {
    _x += _frmw;
    if (_x + _w <= _dsplw)
        // следующий горизонтальный фрейм,
        // полностью вмещается в экран, всё ок
        return true;
    if (_x < _dsplw) {
        // следующий горизонтальный фрейм,
        // в экран попадает, но частично, нужно обрезать справа
        _w = _dsplw - _x;
        return true;
    }

    // горизонтальная строка фреймов закончилась,
    // переходим к следующей
    _x = 0;
    _w = _frmw;
    _y += _frmh;
    // далее аналогичный алгоритм проверки, как и по горизонтали
    if (_y + _h <= _dsplh)
        // эта строчка полностью влазит по высоте, всё ок
        return true;
    if (_y < _dsplh) {
        // эта строка попадает в экран, но частично
        _h = _dsplh - _y;
        return true;
    }

    return false;
}

void DsplBufDbl::nextbuf() {
    _bn ++;
    _bn &= 0x1;
}
