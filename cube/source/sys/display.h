/*
    Display
*/

#ifndef _sys_display_H
#define _sys_display_H

#include "../def.h"
#include "../display/gfx.h"

namespace dspl {
    typedef void (*el_t)(DsplGfx &_gfx);

    void add(el_t p);
    void del(el_t p);

    void sleep();
    void resume();
};

#endif // _sys_display_H
