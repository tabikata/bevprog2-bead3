#include "widgets.hpp"
#include "application.hpp"
#include "szambeallito.hpp"

#include <array>
#include <functional>
#include <iostream>

using namespace std;
using namespace genv;

class SudokuMezo: public SzamBeallito
{
protected:
    function<void(int, int, int)> frissit;
    int ind_x, ind_y;
    bool hibas_sor, hibas_oszlop, hibas_cella;

public:
    SudokuMezo(Application *parent_, int x_, int y_, function<void(int, int, int)> &frissit_, int ind_x_, int ind_y_)
            : SzamBeallito(parent_, x_, y_, 60, 40, 0, 0, 9), frissit(frissit_), ind_x(ind_x_), ind_y(ind_y_)
    {}

    void handle(event ev) override
    {
        int t = szam;
        SzamBeallito::handle(ev);
        if (t != szam)
        {
            frissit(ind_x, ind_y, szam);
        }
    }

    void set_hibas_sor(bool uj_ertek)
    {
        hibas_sor = uj_ertek;
        hatterszin_frissites();
    }
    void set_hibas_oszlop(bool uj_ertek)
    {
        hibas_oszlop = uj_ertek;
        hatterszin_frissites();
    }
    void set_hibas_cella(bool uj_ertek)
    {
        hibas_cella = uj_ertek;
        hatterszin_frissites();
    }

    void hatterszin_frissites()
    {
        if (hibas_sor or hibas_oszlop or hibas_cella)
        {
            hatterszinezo(255, 0, 0);
        }
        else
        {
            hatterszinezo(255, 255, 255);
        }
    }

};

class MyApplication: public Application
{
private:
    array<SudokuMezo *, 9*9> sudoku;
    array<int, 9*9> szamok;

public:
    MyApplication(int width, int height): Application(width, height)
    {
        function<void(int, int, int)> frissit = [&](int ind_x, int ind_y, int szam)
        {
            frissit_(ind_x, ind_y, szam);
        };

        for (int j=0; j<9; j++)
        {
            for (int i=0; i<9; i++)
            {
                sudoku[j*9 + i] = new SudokuMezo(this, (i+1)*60+i/3*3, (j+1)*40+j/3*3, frissit, i, j);
            }
        }
    }

    array<int, 9> sorindexek(int sorszam)
    {
        array<int, 9> indexek;
        for (int i=0; i<indexek.size(); i++)
        {
            indexek[i] = sorszam*9 + i;
        }
        return indexek;
    }

    array<int, 9> oszlopindexek(int oszlopszam)
    {
        array<int, 9> indexek;
        for (int i=0; i<indexek.size(); i++)
        {
            indexek[i] = oszlopszam + i*9;
        }
        return indexek;
    }

    array<int, 9> cellaindexek(int ind_x, int ind_y)
    {
        array<int, 9> indexek;
        int i = 0;
        int kezdo_index = ind_x/3*3 + ind_y/3*3*9;
        for (int y=0; y<3; y++)
        {
            for (int x=0; x<3; x++)
            {
                indexek[i++] = kezdo_index + y*9 + x;
            }
        }
        return indexek;
    }

    bool ellenoriz(array<int, 9> indexek)
    {
        int ertekek[9] = {0};
        for (int ind: indexek)
        {
            int mezo_ertek = szamok[ind];
            if (mezo_ertek > 0 and mezo_ertek < 10)
            {
                ertekek[mezo_ertek - 1] += 1;
                if (ertekek[mezo_ertek - 1] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void frissit_(int ind_x, int ind_y, int szam)
    {
        szamok[ind_y*9 + ind_x] = szam;

        array<int, 9> sor = sorindexek(ind_y);
        array<int, 9> oszlop = oszlopindexek(ind_x);
        array<int, 9> cella = cellaindexek(ind_x, ind_y);
        bool hibas = !ellenoriz(sor);
        for (int ind: sor)
        {
            sudoku[ind]->set_hibas_sor(hibas);
        }
        hibas = !ellenoriz(oszlop);
        for (int ind: oszlop)
        {
            sudoku[ind]->set_hibas_oszlop(hibas);
        }
        hibas = !ellenoriz(cella);
        for (int ind: cella)
        {
            sudoku[ind]->set_hibas_cella(hibas);
        }
    }



};


int main()
{
    MyApplication app(700, 600);
    app.event_loop();
    return 0;
}
