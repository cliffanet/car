#include "path.h"
#include "sys/proc.h"
#include "sys/display.h"
#include "sys/touch.h"
#include "sys/power.h"
#include "sys/stm32drv.h"
#include "chassis/motor.h"
#include "chassis/sr04.h"

#include <list>
#include <math.h>

// время полного оборота на 360
#define TURN_TIME   2726
// время преодоления 1 пикселя на карте
#define PIXL_TIME   35

typedef struct { uint16_t x,y; } pnt_t;
static std::list<pnt_t> _path;
static bool _isrun = false;
static uint8_t _blink = 0;

#include <stdio.h>
#include "display/u8g2_fonts.h"
static uint32_t _cc = 0;
static double _fifi = 0;

// --------------------------------------------------
static double _fi(pnt_t p1, pnt_t p2) {
    int a = static_cast<int>(p2.x) - static_cast<int>(p1.x);
    int b = static_cast<int>(p2.y) - static_cast<int>(p1.y);
    double f = atan(static_cast<double>(b) / abs(a)) + M_PI/2;
    if (a < 0)
        f *= -1;
    return f;
}

static double _fi(pnt_t p1, pnt_t p2, pnt_t p3) {
    auto f = _fi(p2, p3) - _fi(p1, p2);
    while (f <= -M_PI)
        f += M_PI*2;
    while (f > M_PI)
        f -= M_PI*2;
    return f;
}

// --------------------------------------------------

static void _proc() {
    auto t = ts::inf();
    if (t.touch && (_path.size() < 100)) {
        if (_path.empty())
            _path.push_back({ t.x, t.y });
        else {
            const auto &p = _path.back();
            int32_t dx = static_cast<int32_t>(p.x)-t.x;
            int32_t dy = static_cast<int32_t>(p.y)-t.y;
            if (sqrt(dx*dx+dy*dy) >= 5)
                _path.push_back({ t.x, t.y });
        }
    }

    if (_isrun) {
        _blink++;
        pwr::active();
    }
}

static void _draw(DsplGfx &gfx) {
    gfx.color(COLOR_BLUE);
    for (const auto &p : _path)
        gfx.disc(p.x, p.y, 10);

    if (_isrun && !_path.empty()) {
        gfx.color(COLOR_RED);
        const auto &p = _path.front();
        gfx.disc(p.x, p.y, 10);

    }
    if (_isrun && (_path.size() > 1) && ((_blink % 4) < 2)) {
        gfx.color(COLOR_GREEN);
        auto i = _path.begin();
        i++;
        const auto &p = *i;
        gfx.disc(p.x, p.y, 10);
    }
    if (_isrun && (_cc > 0)) {
        char s[32];
        snprintf(s, sizeof(s), "%.1f", static_cast<double>(_cc) / 1000);

        gfx.color(COLOR_RED);
        DsplFontU8g2 f(u8g2_font_fub20_tr);
        gfx.text(0, 100, f, s);
    }
}

static void _run();
static void _touch(uint16_t tx, uint16_t ty, bool tch) {
    if (tch) {
        _path.clear();
        path::stop();
    }
    else
        _run();
}

// --------------------------------------------------

void init_path() {
    proc::add(_proc);
    dspl::add(_draw);
    ts::hndadd(_touch);
}

// --------------------------------------------------

static void (*_next)() = NULL;

extern TIM_HandleTypeDef htim1;
extern "C"
void path_timer() {
    if (sr04::isback())
        // не двигаемся дальше по path, пока работает
        // самоотворот по дальномеру.
        return;
    
    if (_cc > 0)
        _cc --;
    else
    if (_next != NULL)
        _next();
    else
        sr04::stop();
}

static void _run_turn();
static void _run_str() {
    if (_path.size() < 2)
        return;
    motor::straight();
    _next = _run_turn;
    
    const auto &p1 = _path.front();
    const auto &p2 = *(++_path.begin());
    double a = abs(static_cast<int>(p2.x) - static_cast<int>(p1.x));
    double b = abs(static_cast<int>(p2.y) - static_cast<int>(p1.y));
    _cc = round(sqrt(a*a + b*b) * PIXL_TIME);
}

static void _turn(double f) {
    if (f < 0)
        motor::fstturnl();
    else
        motor::fstturnr();
    _next = _run_str;
    _cc = round(abs(f) / (2*M_PI) * TURN_TIME);
    _fifi = f;
}

static void _run_turn() {
    const auto p1 = _path.front();
    _path.erase(_path.begin());
    if (_path.size() < 2) {
        path::stop();
        sr04::stop();
        return;
    }
    _turn(_fi(p1, _path.front(), *(++_path.begin())));
}

static void _run_start() {
    _turn(_fi(_path.front(), *(++_path.begin())));
}

static void _run() {
    if (_path.size() < 2) {
        path::stop();
        return;
    }

    _isrun = true;
    HAL_TIM_Base_Start_IT(&htim1);
    
    _cc = 5000;
    _next = _run_start;

    sr04::start();
}

// --------------------------------------------------

namespace path {
    void stop() {
        motor::stop();
        _path.clear();
        _isrun = false;
        _next = NULL;
        HAL_TIM_Base_Stop_IT(&htim1);
    }
}; // namespace path
