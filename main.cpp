#include "graphics.hpp"
using namespace genv;


int main()
{
    gout.open(400,400);
    gout <<text("hello world")<< refresh;
    event ev;
    while(gin >> ev) {
    }
    return 0;
}
