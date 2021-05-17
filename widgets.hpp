#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Application;

class Widget
{
protected:
    Application * parent;
    int x, y, sx, sy;

public:
    Widget(Application *, int, int, int, int);
    virtual bool is_selected(int, int);
    virtual void draw() = 0;
    virtual void handle(genv::event) = 0;
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
