#ifndef DISJOINT_UNION_H
#define DISJOINT_UNION_H

#include <cstring>
#include "Krawedz.h"

class Wierzcholek
{
public:
    int up, wRank;
};

class Disjoint_Union
{
    public:
        Wierzcholek* z;

        Disjoint_Union(int n);
        ~Disjoint_Union();
        void makeSet(int n);
        int findSet(int v);
        void unionSets(Krawedz k);
};

#endif // DISJOINT_UNION_H
