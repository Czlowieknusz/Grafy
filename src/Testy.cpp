#include "Testy.h"
#include "grafGenerator.h"

using namespace std;

Testy::Testy()
{
    //ctor
}

Testy::~Testy()
{
    //dtor
}

void Testy::dijkstraMatrix()
{
    grafGenerator gG;
    gG.generujDane(0.25);
    /*
    for(int i = 0; i < 100;  i++)
    {
        IncidentMatrix iM;
        iM.dijkstra(0);
    }
    for(int i = 0; i < 100;  i++)
    {
        IncidentMatrix iM;
        iM.primMST(0);
    }
    for(int i = 0; i < 100;  i++)
    {
        IncidentMatrix iM;
        iM.KruskalMST();
    }
    for(int i = 0; i < 100;  i++)
    {
        IncidentMatrix iM;
        iM.fordBellman(0);
    }
    for(int i = 0; i < 100;  i++)
    {
        NeighbourList nL(0);
        nL.dijkstra(0);
    }
    for(int i = 0; i < 100;  i++)
    {
        NeighbourList nL(1);
        nL.KruskalMST();
    }
    for(int i = 0; i < 100;  i++)
    {
        NeighbourList nL(1);
        nL.PrimMST(0);
    }
    for(int i = 0; i < 100;  i++)
    {
        NeighbourList nL(0);
        nL.fordBellman(0);
    }*/
    cout << "Jestem" << endl;
}
