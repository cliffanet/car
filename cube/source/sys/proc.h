/*
    process management
*/

#ifndef _sys_proc_H
#define _sys_proc_H

#include "../def.h"

#ifdef __cplusplus
extern "C"
#endif
void init();

#ifdef __cplusplus

namespace proc {
    typedef void (*el_t)();

    void add(el_t p);
    void del(el_t p);
};

#endif

#endif // _sys_proc_H
