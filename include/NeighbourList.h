#ifndef NEIGHBOURLIST_H
#define NEIGHBOURLIST_H
#include <list>
#include <vector>

using namespace std;

class krawedz
{
    public:
    int poczatek, koniec, waga;

    krawedz(int, int, int);
};

class wierzcholek
{
    public:
    int indeks;
    list<krawedz> sasiedzi;

    wierzcholek(int, list<krawedz>);
    wierzcholek(int);
};

class NeighbourList
{
    public:
        int ilWierzch, ilKraw;
        vector<wierzcholek> sasiedztwo;
        krawedz* p,* r;
        NeighbourList();
        ~NeighbourList();
};

#endif // NEIGHBOURLIST_H
