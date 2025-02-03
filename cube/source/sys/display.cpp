#include "display.h"
#include "proc.h"
#include "stm32drv.h"
#include "../display/ili9488.h"

#include <list>

static DsplILI9488 _dspl;

static std::list<dspl::el_t> _draw;

static void _proc() {
    auto gfx = _dspl.draw();
    do {
        gfx.zero();
        for (auto p: _draw)
            p(gfx);
    } while (_dspl.next());
}

void init_display() {
    _dspl.init();
    proc::add(_proc);
}

namespace dspl {
    void add(el_t p) {
        if (_draw.empty())
            proc::add(_proc);
        else
            for (const auto e: _draw)
                if (p == e)
                    return;
        _draw.push_back(p);
    }

    void del(el_t p) {
        for (auto i = _draw.cbegin(); i != _draw.cend(); i++)
            if (*i == p) {
                _draw.erase(i);
                break;
            }
        if (_draw.empty())
            proc::del(_proc);
    }

    void sleep() {
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    }

    void resume() {
        HAL_GPIO_WritePin(DSPL_PIN_CS, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DSPL_PIN_DC, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DSPL_PIN_RST, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DSPL_PIN_BL, GPIO_PIN_RESET);

        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
        _dspl.init();
    }
}
