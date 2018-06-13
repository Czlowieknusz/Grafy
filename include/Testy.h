#ifndef TESTY_H
#define TESTY_H

#include <iostream>
#include "Krawedz.h"
#include "IncidentMatrix.h"
#include "NeighbourList.h"

class Testy
{
    public:
        Testy();
        virtual ~Testy();
        void testyMatrix();
        void dijkstraMatrix(int);
        void fordBellmanMatrix(int);
        void primMatrix(int);
        void kruskalMatrix(int);
        void dijkstraLista(int);
        void fordBellmanLista(int);
        void primLista(int);
        void kruskalLista(int);


    protected:

    private:
};

#endif // TESTY_H
