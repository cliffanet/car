#include "touch.h"
#include "proc.h"
#include "../display/xpt2046.h"

#include <list>

static TouchXPT2046 _touch;

static ts::inf_t _inf = { 0 };

static std::list<ts::hnd_t> _hndall;

static void _proc() {
    auto t = _touch.get();
    _inf.x = t.x;
    _inf.y = t.y;
    _inf.z = t.z;

    bool _tch = t.z > 100;
    if (_inf.touch != _tch) {
        _inf.touch = _tch;
        for (auto p: _hndall)
            p(_inf.x, _inf.y, _inf.touch);
    }
}

namespace ts {

    const inf_t &inf() {
        return _inf;
    }

    void hndadd(hnd_t hnd) {
        for (const auto e: _hndall)
            if (hnd == e)
                return;
        _hndall.push_back(hnd);
    }
    void hnddel(hnd_t hnd){
        for (auto i = _hndall.cbegin(); i != _hndall.cend(); i++)
            if (*i == hnd) {
                _hndall.erase(i);
                return;
            }
    }
}

void init_touch() {
    _touch.init();
    proc::add(_proc);
}
