/*
    Ultrasonic HC-SR04
*/

#ifndef _chassis_sr04_H
#define _chassis_sr04_H

#include "../def.h"
#include <stdint.h>
#include <stddef.h>

namespace sr04 {
    void start();
    void stop();
    uint16_t distmm();
    bool isback();
}; // namespace sr04

#endif // _chassis_sr04_H
