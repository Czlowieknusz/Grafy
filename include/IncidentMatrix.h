#ifndef INCIDENTMATRIX_H
#define INCIDENTMATRIX_H

#include <fstream>
#include <list>

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
        void KruskalMST();
        int resize(list<int>);    // pomocnicza metoda do Kruskala
        void primMST(int);      // alg. Prima
        void nastepnaKrawedz(list<int>&, bool*, bool&); // metoda pomocnicza do alg. Prima
        void dijkstra(int);     // alg Dijkstry
        void fordBellman(int);  // alg. Forda-Bellmana
        void stworzLosowaMacierz();        // Tworzy losowy graf
        void stworzLosowaMacierz(int, int);    // tworzy losowy graf
};

#endif // INCIDENTMATRIX_H
