#ifndef KIVALASZTO_HPP
#define KIVALASZTO_HPP

#include "widgets.hpp"
#include <vector>

class Kivalaszto: public Widget
{
protected:
    int meret;
    std::vector<std::string> lehetosegek;
    int aktualis;
    bool levanegordulve;

public:
    Kivalaszto(Application *, int, int, int, int, int, std::vector<std::string>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual bool lenyit(int, int);
    virtual bool valasztas(int, int);
    virtual void valaszt(int, int);
    virtual std::string value();
};

#endif // KIVALASZTO_HPP
