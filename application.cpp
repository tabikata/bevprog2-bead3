#include "application.hpp"

using namespace genv;

Application::Application(int width, int height)
{
    gout.open(width, height);
    //gout.load_font("LiberationSans-Regular.ttf", 10);
}

void Application::event_loop()
{
    event ev;
    int focus = -1;
    while (gin >> ev)
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                        focus = i;
                }
            }
        }
        if (focus != -1)
        {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets)
        {
            w->draw();
        }
        gout << refresh;
    }
}

void Application::registerWidget(Widget * widget)
{
    widgets.push_back(widget);
}


