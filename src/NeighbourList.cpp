#include "NeighbourList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

krawedz::krawedz(int pocz, int kon, int wag)
{
    poczatek = pocz;
    koniec = kon;
    waga = wag;
}

wierzcholek::wierzcholek(int nr, list<krawedz> lista)
{
    indeks = nr;
    sasiedzi = lista;
}

wierzcholek::wierzcholek(int nr)
{
    indeks = nr;
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
            list<krawedz> lista;
            //krawedz k(1,2,i);
            //lista.push_back(k);
            wierzcholek w(i, lista);
            sasiedztwo.push_back(w);
        }

        vector<wierzcholek>::iterator wit;
        list<krawedz>::iterator kit;

        /// Odczytanie krawedzi i zapisanie do macierzy
        /// Poczatek - Koniec - Waga
        int buf[3], counter = 0;
        while(getline(myfile, line, ' '))
        {
            buf[counter] = atoi(line.c_str());
            counter ++;
            if(counter == 3)
            {
                wit = sasiedztwo.begin();
                while(wit->indeks!=buf[0])
                {
                    wit++;
                }
                krawedz k(buf[0], buf[1], buf[2]);
                wit->sasiedzi.push_back(k);
                counter = 0;
            }
        }

        for(wit = sasiedztwo.begin(); wit!= sasiedztwo.end(); ++wit)
        {
            for(kit = (*wit).sasiedzi.begin(); kit != (*wit).sasiedzi.end(); ++kit)
            {
                cout << "[" << kit->poczatek << "]. Waga = " << kit->waga << ", koniec = " << kit->koniec;
            }
            cout << endl;
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
