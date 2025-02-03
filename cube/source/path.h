/*
    Path
*/

#ifndef _path_H
#define _path_H

#include "def.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
#endif
void path_timer();

#ifdef __cplusplus

namespace path {
    void stop();
}; // namespace path

#endif

#endif // _path_H
