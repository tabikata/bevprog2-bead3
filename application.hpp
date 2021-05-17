#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widgets.hpp"
#include <vector>

class Application
{
protected:
    std::vector<Widget *> widgets;

public:
    Application(int, int);
    virtual ~Application(){}
    void event_loop();
    void registerWidget(Widget *);
    //virtual void action(std::string) = 0;
};

#endif // APPLICATION_HPP
