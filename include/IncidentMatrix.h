#ifndef INCIDENTMATRIX_H
#define INCIDENTMATRIX_H

#include <fstream>
#include "Disjoint_Union.h"
#include "Krawedz.h"
#include "lista.h"

using namespace std;

class IncidentMatrix
{
    public:
        IncidentMatrix();
        ~IncidentMatrix();
        int iloscWierzcholkow, iloscKrawedzi;
        int** macierz;
        int** macierzPomocnicza;
        int* tablicaWag;
        short* wpisane;


        void drukujMacierz();
        void menu();
        void stworzMacierz();       // dane z pliku
        bool KruskalMST();
        bool primMST(int);      // alg. Prima
        Krawedz* nastepnaKrawedz(bool*, Disjoint_Union*); // metoda pomocnicza do alg. Prima
        void dijkstra(int);     // alg Dijkstry
        void fordBellman(int);  // alg. Forda-Bellmana
        void stworzLosowaMacierz();        // Tworzy losowy graf
        void stworzLosowaMacierz(int, int);    // tworzy losowy graf
        void drukujKrawedzie(Lista& krawedzie);
};

#endif // INCIDENTMATRIX_H
