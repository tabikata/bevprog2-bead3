#ifndef SZAMBEALLITO_HPP
#define SZAMBEALLITO_HPP

#include "widgets.hpp"

class SzamBeallito: public Widget
{
protected:
    int szam, imin, imax;
    genv::color hatter;

public:
    SzamBeallito(Application *, int, int, int, int, int, int, int);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual bool novel(int, int);
    virtual bool csokkent(int, int);
    virtual int value();
    void hatterszinezo(int, int, int);
};

#endif // SZAMBEALLITO_HPP
