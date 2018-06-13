#include "Disjoint_Union.h"

Disjoint_Union::Disjoint_Union(int n)
{
    z = new Wierzcholek[n];
}

Disjoint_Union::~Disjoint_Union()
{
    delete[] z;
}

void Disjoint_Union::makeSet(int n)
{
    z[n].up = n;
    z[n].wRank = 0;
}

int Disjoint_Union::findSet(int v)
{
    if(z[v].up != v)
        z[v].up = findSet(z[v].up);
    return z[v].up;
}

void Disjoint_Union::unionSets(Krawedz k)
{
    int ru, rv;

    ru = findSet(k.wierzcholekPoczatkowy);
    rv = findSet(k.wierzcholekkoncowy);

    if(ru != rv)
    {
        if(z[ru].wRank > z[rv].wRank)
            z[rv].up = ru;
        else
        {
            z[ru].up = rv;
            if(z[ru].wRank == z[rv].wRank)
                z[rv].wRank += 1;
        }
    }
}
