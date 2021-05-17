#include "widgets.hpp"
#include "application.hpp"

using namespace genv;

Widget::Widget(Application* parent_, int x_, int y_, int sx_, int sy_)
        : parent(parent_), x(x_), y(y_), sx(sx_), sy(sy_)
{
    parent->registerWidget(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x > x and mouse_x < x+sx
        and mouse_y > y and mouse_y < y+sy;
}






