#include <vector>
#include <iostream>
#include "Dijkstra.h"
#include "IncidentMatrix.h"
#include <limits.h>

Dijkstra::Dijkstra()
{
    //IncidentMatrix iM;
    //findShortestWayMatrix(iM, 0);
}

Dijkstra::~Dijkstra()
{

}

void Dijkstra::findShortestWayMatrix(IncidentMatrix iM, int start)
{
    cout << "Tablica wag: " << endl;
    for(int i = 0; i<iM.iloscKrawedzi; i++)
        cout << "["<<i<<"] " << iM.tablicaWag[i] << endl;
    iM.drukujMacierz();
    vector<int> pred(iM.iloscWierzcholkow);
    vector<int> dist(iM.iloscWierzcholkow);
    vector<bool> checked(iM.iloscWierzcholkow);
    for(int i = 0; i < iM.iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
        checked[i] = false;
    }

    dist[start] = 0;

    for(int i = 0; i<iM.iloscWierzcholkow; i++)
    {
        int indeksWierzcholka;
        int mindist = INT_MAX;
        for (int j =0; j<iM.iloscWierzcholkow; j++)
        {
            if(!checked[j] &&dist[j] < mindist)
            {
                indeksWierzcholka = j;
                mindist = dist[indeksWierzcholka];
            }
        }
        if(mindist == INT_MAX)
            break;
        checked[indeksWierzcholka] = true;

        vector<int> sasiednieWierzcholki;
        vector<int> indeksyKrawedzi;
        for(int j =0; j<iM.iloscKrawedzi; j++)
        {
            if(iM.macierz[indeksWierzcholka][j] == 1)
            {
                for(int k = 0; k < iM.iloscWierzcholkow; k ++)
                {
                    if(iM.macierz[k][j] == -1 && !checked[k])
                    {
                        indeksyKrawedzi.push_back(j);
                        sasiednieWierzcholki.push_back(k);
                        break;
                    }
                }
            }
        }
        for(auto it = indeksyKrawedzi.begin(); it !=indeksyKrawedzi.end(); it++)
        {
            cout << "Indeks krawedzi = " << *it << endl;
        }

        for(auto it = sasiednieWierzcholki.begin(); it !=sasiednieWierzcholki.end(); it++)
        {
            if(dist[*it] > dist[indeksWierzcholka] + iM.tablicaWag[indeksyKrawedzi.front()])
            {
                dist[*it] = dist[indeksWierzcholka] + iM.tablicaWag[indeksyKrawedzi.front()];
                pred[*it] = indeksWierzcholka;
            }
            indeksyKrawedzi.erase(indeksyKrawedzi.begin());
        }
    }
        cout << endl << endl;
        for(auto it = dist.begin(); it != dist.end(); it++)
        {
            cout << *it << "; ";
        }
        cout<<endl;
        for(auto it = pred.begin(); it != pred.end(); it++)
        {
            cout << *it << "; ";
        }
}
