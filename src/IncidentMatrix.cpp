#include "IncidentMatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <istream>

using namespace std;

/// Macierz incydencji skierowana
IncidentMatrix::IncidentMatrix()
{
    /// Odczytanie krawêdzi -> do dodania
    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        /// Odczytanie rozmiaru i ilosci krawedzi
        getline(myfile, line);
        rozmiar = atoi(line.c_str());

        getline(myfile, line);
        iloscKrawedzi = atoi(line.c_str());

        macierz = new int* [rozmiar];

        /// Tworzenie wierszy macierzy
        for(int i =0; i<rozmiar; i++)
            macierz[i] = new int[iloscKrawedzi];

        /// Wype³nienie macierzy zerami
        for(int i = 0; i<rozmiar; i++)
            for(int j = 0; j<iloscKrawedzi; j++)
                macierz[i][j] = 0;

        /// Odczytanie krawedzi i zapisanie do macierzy
        /// Poczatek - Koniec - Waga
        int buf[3], counter = 0, krawedz = 0;
        while(getline(myfile, line, ' '))
        {
            buf[counter] = atoi(line.c_str());
            counter ++;
            if(counter == 3)
            {
                macierz[buf[0]][krawedz] = buf[2];
                macierz[buf[1]][krawedz] = (-1)*buf[2];
                krawedz++;
                counter = 0;
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

IncidentMatrix::~IncidentMatrix()
{
    for(int i =0; i<rozmiar; i++)
        delete[] macierz[i];
    delete[] macierz;
}
