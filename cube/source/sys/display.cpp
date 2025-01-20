#include "display.h"
#include "proc.h"
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
}
