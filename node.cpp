#include "node.h"
namespace path
{
    node::node() : parent(nullptr),
                   g(0),
                   h(0),
                   f(0),
                   need_to_calculate_f(false),
                   need_to_calculate_h(true)
    {

    }

    node::~node()
    {

    }

    const fu32& node::get_f()
    {
        if (need_to_calculate_f)
        {
            f = g + get_h();
            need_to_calculate_f = false;
        }
        return f;
    }

    void node::set_g(fu32 _g)
    {
        g = _g;
        need_to_calculate_f = true;
    }

    const fu32& node::get_g()
    {
        return g;
    }

    const fu32& node::get_h()
    {
        if (need_to_calculate_h)
        {
            need_to_calculate_h = false;
            need_to_calculate_f = true;
            ///@todo actually calculate h
            h = 0;
        }
        return h;
    }
}
