#include "kivalaszto.hpp"

using namespace genv;

Kivalaszto::Kivalaszto(Application * parent_, int x_, int y_, int sx_, int sy_, int meret_, std::vector<std::string> lehetosegek_)
            : Widget(parent_, x_, y_, sx_, sy_), meret(meret_), lehetosegek(lehetosegek_), aktualis(0), levanegordulve(false)
{
}

void Kivalaszto::draw()
{
    gout << color(255, 255, 255) << move_to(x, y) << box(sx, sy)
        << color(0, 0, 0) << move_to(x + 10, y + sy*2/3) << text(lehetosegek[aktualis])
        << move_to(x+sx-sy, y) << line(0, sy)
        << move_to(x+sx-sy*2/3, y+sy/3) << line(sy/3, 0) << line_to(x+sx-sy/2, y+sy*2/3) << line_to(x+sx-sy*2/3, y+sy/3);
    if (levanegordulve)
    {
        gout << color(255, 255, 255) << move_to(x, y+sy) << box(sx, meret*sy)
            << color(0, 0, 0)
            << move_to(x+sx-10, y+sy+2) << box(8, (meret*sy)/(lehetosegek.size()-meret+1)-4);
        for (int i=0; i<meret; i++)
        {
            gout << move_to(x, y+(i+1)*sy) << line(sx, 0)
                << move_to(x+10, y+(i+1)*sy+sy*2/3) << text(lehetosegek[i]);
        }
    }
    else if(!levanegordulve)
    {
        gout << color(0, 0, 0) << move_to(x, y+sy) << box(sx, meret*sy);
    }
}

void Kivalaszto::handle(event ev)
{
    if (ev.type == ev_mouse and ev.button == btn_left)
    {
        if (lenyit(ev.pos_x, ev.pos_y))
        {
            levanegordulve = true;
        }
        else if (levanegordulve and valasztas(ev.pos_x, ev.pos_y))
        {
            levanegordulve = false;
        }
        valaszt(ev.pos_x, ev.pos_y);
    }
}

bool Kivalaszto::lenyit(int mouse_x, int mouse_y)
{
    return mouse_x > x+sx-sy and mouse_x < x+sx
        and mouse_y > y and mouse_y < y+sy;
}

bool Kivalaszto::valasztas(int mouse_x, int mouse_y)
{
    return mouse_x > x and mouse_x < x+sx-10
        and mouse_y > y+sy and mouse_y < y+(meret+1)*sy;
}

void Kivalaszto::valaszt(int mouse_x, int mouse_y)
{
    for (int i=0; i<lehetosegek.size(); i++)
    {
        if (mouse_x > x and mouse_x < x+sx-10 and mouse_y > y+(i+1)*sy and mouse_y < y+(i+2)*sy)
        {
            aktualis = i;
        }
    }
}

std::string Kivalaszto::value()
{
    return lehetosegek[aktualis];
}
