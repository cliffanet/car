#ifndef __display_gfx_H
#define __display_gfx_H

#include "frame.h"
#include "fontu8g2.h"

#define COLOR_BLACK         0x0000
#define COLOR_GRAY          0xF7DE
#define COLOR_BLUE          0x001F
#define COLOR_RED           0xF800
#define COLOR_GREEN         0x07E0
#define COLOR_CYAN          0x07FF
#define COLOR_MAGENTA       0xF81F
#define COLOR_YELLOW        0xFFE0
#define COLOR_WHITE         0xFFFF

// Перекладываем все проверки на видимость пикселя (внутри фрейма) на DsplGfx
// Работу сводим к наличию класса DsplFrame, который определяет
// координаты видимости: x, y, w, h.
// Внутри него DsplGfx будет пытаться рисовать всё, что требуется.
// Для уменьшения времени выполнения на разные перепроверки разделим
// зоны ответственности:
//
//      DsplGfx сам проверяет видимость внутри фрейма и гарантирует,
//      что во всех вызовах _frm->pixel(), _frm->fill() и т.п.
//      переданные координаты находятся внутри допустимого диапазона у DsplFrame.
//
//      DsplFrame может уже не перепроверять входные координаты
//      и сразу использовать их в адресации пикселя.
class DsplGfx {
    DsplFrame &_frm;
public:
    DsplGfx(DsplFrame &frame) : _frm(frame) {};

    inline DsplFrame::rgb_t color() const {
        return _frm.color();
    };
    inline void color(uint16_t c) {
        _frm.color(c);
    };
    inline void color(uint8_t r, uint8_t g, uint8_t b) {
        _frm.color(r, g, b);
    }
    inline void zero() {
        _frm.zero();
    }
    inline void clear() {
        _frm.fill(0, 0, _frm.w, _frm.h);
    }
    void fill(int x, int y, uint16_t w, uint16_t h);
    void rect(int x, int y, uint16_t w, uint16_t h);
    void rfill(int x, int y, uint16_t w, uint16_t h, uint16_t r);
    void rrect(int x, int y, uint16_t w, uint16_t h, uint16_t r);
    void circle(int x, int y, uint16_t r);
    void disc(int x, int y, uint16_t r);
    
    void fmap(int x, int y, uint16_t w, uint16_t h, const uint8_t *data);

    void text(int x, int y, const DsplFontU8g2 &fnt, const char *s);
};


#endif // __display_gfx_H
