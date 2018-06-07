#ifndef FORD-BELLMAN_H
#define FORD-BELLMAN_H

#include "IncidentMatrix.h"

class FordBellman
{
    public:
        FordBellman();
        ~FordBellman();
        void findShortestWayMatrix(IncidentMatrix, int);
};

#endif // FORD-BELLMAN_H
