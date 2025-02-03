/*
    TouchScreen
*/

#ifndef _sys_touch_H
#define _sys_touch_H

#include "../def.h"
#include <stdint.h>

namespace ts {
    typedef struct {
        uint16_t x,y,z;
        bool touch;
    } inf_t;

    const inf_t &inf();

    typedef void (*hnd_t)(uint16_t x, uint16_t y, bool tch);
    void hndadd(hnd_t hnd);
    void hnddel(hnd_t hnd);

    void sleep();
    void resume();
}

#endif // _sys_touch_H
