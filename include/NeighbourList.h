#ifndef NEIGHBOURLIST_H
#define NEIGHBOURLIST_H
#include "Krawedz.h"
#include "lista.h"
#include "Disjoint_Union.h"

using namespace std;

class NeighbourList
{
    public:
        int iloscWierzcholkow, iloscKrawedzi;
        Lista* tablicaKrawedzi;
        NeighbourList(int);
        NeighbourList();
        ~NeighbourList();
        void stworzListeSasiedztw(int);
        void losowaListaSasiedztw(int, int, int);
        void drukujListe();
        void menu();
        bool PrimMST(int);
        bool KruskalMST();
        void fordBellman(int);
        void dijkstra(int);
        Krawedz* nastepnaKrawedz(bool*, Disjoint_Union*, Lista&);
        void drukujKrawedzie(Lista& krawedzie);
};

#endif // NEIGHBOURLIST_H
