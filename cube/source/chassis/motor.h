/*
    Motor
*/

#ifndef _chassis_motor_H
#define _chassis_motor_H

#include "../def.h"
#include <stdint.h>
#include <stddef.h>

namespace motor {

    // Коды моторов
    typedef enum {
        L_A = 0,
        L_B,
        R_A,
        R_B
    } code_t;

    // Направление вращения
    typedef enum {
        OFF = 0,
        FWD,
        BAC,
        BRK
    } dir_t;

    dir_t isrun(code_t m);
    void run(code_t m, dir_t dir);

    void straight(bool rev = false);
    void fstturnl();
    void fstturnr();
    void stop(bool brk = true);

    void sleep();
    void resume();
}; // namespace motor

#endif // _chassis_motor_H
