#include "Krawedz.h"
#include <iostream>

using namespace std;

Krawedz::Krawedz(){}

Krawedz::Krawedz(const Krawedz& kra)
{
    wierzcholekPoczatkowy = kra.wierzcholekPoczatkowy;
    wierzcholekkoncowy = kra.wierzcholekkoncowy;
    waga = kra.waga;
}

Krawedz::~Krawedz()
{
    //dtor
}

Krawedz::Krawedz(short pocz, short kon, int w, bool d)
{
    this->wierzcholekPoczatkowy = pocz;
    this->wierzcholekkoncowy = kon;
    this->waga = w;
}

bool Krawedz::operator==(Krawedz k) const
{
    if(this->waga == k.waga)
        return true;
    return false;
}

bool Krawedz::operator!=(Krawedz k) const
{
    if(this->waga != k.waga)
        return true;
    return false;
}

bool Krawedz::operator < (const Krawedz& k)
{
    if(this->waga < k.waga)
        return true;
    return false;
}

bool Krawedz::operator>(const Krawedz& k)
{
    if(this->waga > k.waga)
        return true;
    return false;
}

Krawedz& Krawedz::operator=(const Krawedz k)
{
    this->wierzcholekPoczatkowy = k.wierzcholekPoczatkowy;
    this->wierzcholekkoncowy = k.wierzcholekkoncowy;
    this->waga = k.waga;

    return* this;
}

ostream& operator << (ostream& str, Krawedz k)
{
    str << k.wierzcholekPoczatkowy << "->";
    str << k.wierzcholekkoncowy << ": ";
    str << k.waga;
    return str;
}
