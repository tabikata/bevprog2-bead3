#include "szambeallito.hpp"
#include <sstream>

using namespace genv;

SzamBeallito::SzamBeallito(Application * parent_, int x_, int y_, int sx_, int sy_, int szam_, int imin_, int imax_)
                : Widget(parent_, x_, y_, sx_, sy_), szam(szam_), imin(imin_), imax(imax_), hatter(255, 255, 255)
{}

void SzamBeallito::draw()
{
    std::stringstream num;
    num << szam;
    gout << hatter << move_to(x, y) << box(sx, sy)
        << color(0, 0, 0) << move_to(x + (sx - sy/2)/2 - 2, y + sy*2/3);
        if (szam == 0)
        {
            gout << text(' ');
        }
        else
        {
            gout << text(num.str());
        }
        gout << move_to(x+sx-sy/2, y) << line(0, sy) << move_to(x+sx-sy/2, y+sy/2) << line(sy/2, 0) << move_to(x+sx-1, y) << line(0, sy) << move_to(x, y+sy-1) << line(sx, 0)
        << move_to(x+sx-sy/2+5, y+sy/2-5) << line(sy/2-2*5, 0) << line_to(x+sx-sy/4, y+5) << line_to(x+sx-sy/2+5, y+sy/2-5)
        << move_to(x+sx-sy/2+5, y+sy/2+5) << line(sy/2-2*5, 0) << line_to(x+sx-sy/4, y+sy-5) << line_to(x+sx-sy/2+5, y+sy/2+5);
}

void SzamBeallito::handle(event ev)
{
    if (ev.type == ev_key)
    {
        if (ev.keycode == key_up and szam+1 <= imax)
        {
            szam++;
        }
        else if (ev.keycode == key_down and szam-1 >= imin)
        {
            szam--;
        }
        else if (ev.keycode == key_pgup and szam+10 <= imax)
        {
            szam+=10;
        }
        else if (ev.keycode == key_pgdn and szam-10 >= imin)
        {
            szam-=10;
        }
    }
    else if (ev.type == ev_mouse and ev.button == btn_left)
    {
        if (novel(ev.pos_x, ev.pos_y) and szam+1 <= imax)
        {
            szam++;
        }
        else if (csokkent(ev.pos_x, ev.pos_y) and szam-1 >= imin)
        {
            szam--;
        }
    }
}

bool SzamBeallito::novel(int mouse_x, int mouse_y)
{
    return mouse_x > x+sx-sy/2 and mouse_x < x+sx
        and mouse_y > y and mouse_y < y+sy/2;
}

bool SzamBeallito::csokkent(int mouse_x, int mouse_y)
{
    return mouse_x > x+sx-sy/2 and mouse_x < x+sx
        and mouse_y > y+sy/2 and mouse_y < y+sy;
}

int SzamBeallito::value()
{
    return szam;
}

void SzamBeallito::hatterszinezo(int r, int g, int b)
{
    hatter = color(r, g, b);
    draw();
}


