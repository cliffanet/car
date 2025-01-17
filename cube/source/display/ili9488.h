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
#define DSLP_FRMCNT_X   8
#define DSLP_FRMCNT_Y   8

#define DSLP_FRM_WIDTH  (DSPL_WIDTH/DSLP_FRMCNT_X)
#define DSLP_FRM_HEIGHT (DSPL_HEIGHT/DSLP_FRMCNT_Y)
#define DSPL_BUFSZ      (DSLP_FRM_WIDTH*DSLP_FRM_HEIGHT*3)

class DsplILI9488 {
    uint8_t _d1[DSPL_BUFSZ], _d2[DSPL_BUFSZ]; 
    DsplBufDbl _buf;
    DsplFrame24 _frm;

    void write();
    void end();
public:
    DsplILI9488() :
        _buf(DSPL_WIDTH, DSPL_HEIGHT, DSLP_FRMCNT_X, DSLP_FRMCNT_Y, _d1, _d2),
        _frm(0, 0, 0, 0, NULL)
        {}

    inline uint16_t width() const { return _buf.dsplw(); }
    inline uint16_t height()const { return _buf.dsplh(); }

    void init();

    DsplGfx draw();
    bool next();
    
    typedef void draw_t(DsplGfx &);
    void draw(draw_t *d);
};

#endif // __display_ioili9488_H
