#ifndef __display_xpt2046_H
#define __display_xpt2046_H

#include <stdint.h>

#define TOUCH_PIN_CS    GPIOB, GPIO_PIN_1
#define TOUCH_PIN_IRQ   GPIOB, GPIO_PIN_10

#define TOUCH_WIDTH     480
#define TOUCH_HEIGHT    320

class TouchXPT2046 {
public:
    void init();
    typedef struct {
        uint16_t x, y, z;
    } val_t;
    val_t get();
};

#endif // __display_xpt2046_H
