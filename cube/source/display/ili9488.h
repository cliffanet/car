#ifndef __display_ioili9488_H
#define __display_ioili9488_H

#include "gfx.h"
#include "buf.h"

#define DSPL_PIN_CS     GPIOA, GPIO_PIN_4
#define DSPL_PIN_DC     GPIOB, GPIO_PIN_0
#define DSPL_PIN_RST    GPIOA, GPIO_PIN_3
#define DSPL_PIN_BL     GPIOA, GPIO_PIN_2

#define DSPL_WIDTH      480
#define DSPL_HEIGHT     320

class DsplBufILI9488DMA : public DsplBuf24 {
    void write();
public:
    using DsplBuf24::DsplBuf24;
    virtual void begin();
    virtual bool next();
};

class DsplILI9488 : public DsplIO {
    DsplBufILI9488DMA _buf;
public:
    DsplILI9488() : _buf(DSPL_WIDTH, DSPL_HEIGHT, 4, 4) {}
    void init();
    inline DsplGfx draw() { return DsplGfx(_buf); }
};

#endif // __display_ioili9488_H
