#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <list>
#include "IncidentMatrix.h"

using namespace std;

class Dijkstra
{
public:
    Dijkstra();
    ~Dijkstra();
    void findShortestWayMatrix(IncidentMatrix, int);
};

#endif // DIJKSTRA_H
