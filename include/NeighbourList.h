#ifndef NEIGHBOURLIST_H
#define NEIGHBOURLIST_H
#include <list>
#include <vector>

using namespace std;

struct krawedz
{
    int poczatek, koniec, waga;
};

class wierzcholek
{
    public:
    int indeks;
    list<krawedz> sasiedzi;

    wierzcholek(int, list<krawedz>);
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
