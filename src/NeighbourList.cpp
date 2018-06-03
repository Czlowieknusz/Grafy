#include "NeighbourList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

wierzcholek::wierzcholek(int nr, list<krawedz> lista)
{
    indeks = nr;
    sasiedzi = lista;
}

NeighbourList::NeighbourList()
{
    /// Odczytanie krawêdzi -> do dodania
    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        /// Odczytanie rozmiaru i ilosci krawedzi
        getline(myfile, line);
        ilWierzch = atoi(line.c_str());

        getline(myfile, line);
        ilKraw = atoi(line.c_str());

        /// Tworzenie wierszy macierzy
        for(int i =0; i<ilWierzch; i++)
        {
            sasiedztwo.push_back(new wierzcholek(i, new list<krawedz>));
        }
        /// Odczytanie kolejnych wierzcholkow
        for(int i =0; i<ilWierzch; i++)
        {
            krawedz k;
            k.waga = i;
            sasiedztwo[i].push_back(k);
            cout << sasiedztwo[i][0]<<endl;
        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

NeighbourList::~NeighbourList()
{

}
