#include "Dane.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Dane::Dane()
{
    //ctor
}

Dane::~Dane()
{
    //dtor
}

void Dane::stworzDane()
{
    short znak;
    short waga;;
    short liczbaWierzcholkaP;
    short liczbaWierzcholkaK;
    ofstream plik("dane.txt");
    if (plik)
    {
        plik << iloscKrawedzi << " " << iloscWierzcholkow << endl;;
        srand(time(NULL));
        for (int i = 0; i < iloscKrawedzi; i++)
        {

            liczbaWierzcholkaP = (rand() % iloscWierzcholkow) + 0;
            waga = (rand() % 10) + 0;
            znak = (rand() % 1);
            if (znak == 1)
            {
                waga = 0 + waga;
            }
            else
            {
                waga = 0 - waga;
            }
            liczbaWierzcholkaK = (rand() % iloscWierzcholkow) + 0;
            if (liczbaWierzcholkaK == liczbaWierzcholkaP)
            {
                if (znak == 1)
                {
                    liczbaWierzcholkaK = liczbaWierzcholkaK-1;
                }
                else
                {
                    liczbaWierzcholkaK = liczbaWierzcholkaK+1;
                }
            }
            if ((liczbaWierzcholkaK >= iloscWierzcholkow) || (liczbaWierzcholkaP >= iloscWierzcholkow) || (liczbaWierzcholkaK < 0) || (liczbaWierzcholkaP < 0))
            {
                iloscKrawedzi--;
            }
            else
            {
                plik << liczbaWierzcholkaP << " " << liczbaWierzcholkaK << " " << waga << endl;
            }

        }

    }
    else
    {
        cout << "Blad nie mozna otworzyc." << endl;
    }
    plik.close();
}
