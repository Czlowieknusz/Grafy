#ifndef KRAWEDZ_H
#define KRAWEDZ_H

#include <iostream>

using namespace std;

class Krawedz
{
    public:
        int waga;
        short wierzcholekPoczatkowy;
        short wierzcholekkoncowy;
        bool skierowany;
        Krawedz* nastepna,* poprzednia;

        Krawedz();
        Krawedz(const Krawedz&);
        Krawedz(short pocz, short kon, int w, bool d = 0);
        ~Krawedz();

        friend ostream& operator << (ostream& str, Krawedz k);
        bool operator == (Krawedz k) const;
        bool operator < (const Krawedz& k);
        bool operator > (const Krawedz& k);
        bool operator != (Krawedz k) const;
        Krawedz& operator = (Krawedz k);
};

ostream& operator << (ostream& str, Krawedz k);

#endif // KRAWEDZ_H
