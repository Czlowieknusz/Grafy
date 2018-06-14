#include "lista.h"
#include "NeighbourList.h"
#include "Krawedz.h"
#include "listaInt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iomanip>
#include <limits.h>
#include <time.h>
#include <stddef.h>
#include <algorithm>


using namespace std;

NeighbourList::NeighbourList()
{
    tablicaKrawedzi = NULL;
    iloscWierzcholkow = iloscKrawedzi = 0;
}

NeighbourList::NeighbourList(int wybor)
{
    tablicaKrawedzi = NULL;
    iloscWierzcholkow = iloscKrawedzi = 0;
    //stworzListeSasiedztw(wybor);
}

/// Odczytuje z pliku 'test.txt' krawedzie grafu
void NeighbourList::stworzListeSasiedztw(int wybor)
{
    /// Odczytanie krawêdzi -> do dodania
    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        /// Odczytanie rozmiaru i ilosci krawedzi
        getline(myfile, line);
        iloscWierzcholkow = atoi(line.c_str());

        getline(myfile, line);
        iloscKrawedzi = atoi(line.c_str());

        tablicaKrawedzi = new Lista[iloscWierzcholkow];

        /// Tworzenie wierszy tablicy list
        for(int i =0; i<iloscWierzcholkow; i++)
        {
            Lista l;
            tablicaKrawedzi[i] = l;
        }
        //drukujListe();

        /// Odczytanie krawedzi i zapisanie do macierzy
        /// Poczatek - Koniec - Waga
        int buf[3], counter = 0;
        //int skierowany
        // cout << "Graf skierowany [0] czy nieskierowany [inna]? ";
        //cin >> skierowany;
        while(getline(myfile, line, ' '))
        {
            buf[counter] = atoi(line.c_str());
            counter ++;
            if(counter == 3)
            {
                if(wybor == 0)
                {
                    Krawedz* k = new Krawedz(buf[0], buf[1], buf[2]);
                    tablicaKrawedzi[buf[0]].dodajNaKoniec(k);
                    counter = 0;
                }
                else
                {
                    Krawedz* k = new Krawedz(buf[0], buf[1], buf[2]);
                    Krawedz* k2 = new Krawedz(buf[1], buf[0], buf[2]);
                    tablicaKrawedzi[buf[0]].dodajNaKoniec(k);
                    tablicaKrawedzi[buf[1]].dodajNaKoniec(k2);
                    counter = 0;
                }
            }
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
    delete[] tablicaKrawedzi;
}

/// Drukuje liste
void NeighbourList::drukujListe()
{
    cout << "Lista sasiedztw..." << endl;
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        cout << "[" << i << "]. ";
        tablicaKrawedzi[i].wydrukujListe();
        cout << endl;
    }
}

/// Menu uzytkownika
void NeighbourList::menu()
{
    cout << endl;
    int liczba;
    short exit = 0;
    short choice;
    while (exit == 0)
    {
        if (exit == 1)
            break;
        cout << "\nCo chcesz zrobic?\n";
        cout << "1. Wczytaj dane z pliku. \n";
        cout << "2. Wygeneruj dane losowo. \n";
        cout << "3. Algorytm Prima. \n";
        cout << "4. Algorytm Kruskala. \n";
        cout << "5. Algorytm Dijkstry. \n";
        cout << "6. Algorytm Forda-Bellmana. \n";
        cout << "8. Wypisz liste. \n";
        cout << "9. Wroc do poprzedniego menu. \n";
        cout << "10. Testy. \n";
        cin >> choice;
        if (!cin)
        {
            cin.clear();
            cin.ignore();
        }
        switch (choice)
        {

        case 1:
        {
            cout << "Wczytuje dane z pliku: 'dane.txt'" << endl;
            stworzListeSasiedztw(0);
            cout << endl;
            break;
        }

        case 2:
        {
            int ilW, ilK;
            bool skier;
            cout << "ile wiezcholkow?" <<endl;
            cin >> ilW;
            cout << "ile kraedzi?" <<endl;
            cin >> ilK;
            cout << "skierowany? [0 - tak; 1 - nie]" <<endl;
            cin >> skier;
            losowaListaSasiedztw(ilW,ilK, skier);
            break;
        }
        case 3:
        {
            cout << endl;
            if (tablicaKrawedzi == NULL)
            {
                cout << "Macierz jest pusta! \n";
                cout << "Wczytaj dane do amcierzy!\n";
                break;
            }
            int wierszStart = 0;
            cout << "Podaj wierzcholek startowy: ";
            cin >> wierszStart;
            cout << endl;
            if (wierszStart < 0 || wierszStart >= iloscWierzcholkow)
            {
                cout << "Niepoprawny wierzcholek!\n";
            }
            else
            {
                PrimMST(wierszStart);
            }
            break;
        }
        case 4:
        {
            cout << endl;
            if (tablicaKrawedzi == NULL || tablicaKrawedzi->rozmiar == 0)
            {
                cout << "Macierz jest pusta! \n";
                cout << "Wczytaj dane do amcierzy!\n";
                break;
            }
            cout << "Kurskal...\n\n";
            KruskalMST();
            break;
        }
        case 5:
        {
            cout << endl;
            if (tablicaKrawedzi == NULL || tablicaKrawedzi->rozmiar == 0)
            {
                cout << "Macierz jest pusta! \n";
                cout << "Wczytaj dane do macierzy!\n";
                break;
            }
            cout << endl;
            cout << "Z jakiego wierzcholka chcesz rozpoczac?\n";
            cin >> liczba;
            if (liczba < 0 || liczba >= iloscWierzcholkow)
            {
                cout << "Niepoprawny wierzcholek!\n";
            }
            else
            {
                dijkstra(liczba);
            }
            break;
        }
        case 6:
        {
            cout << endl;
            if (tablicaKrawedzi == NULL || tablicaKrawedzi->rozmiar == 0)
            {
                cout << "Macierz jest pusta! \n";
                cout << "Wczytaj dane do amcierzy!\n";
                break;
            }
            cout << endl;
            cout << "Z jakiego wierzcholka rozpoczac?\n";
            cin >> liczba;
            if (liczba < 0 || liczba >= iloscWierzcholkow)
            {
                cout << "Niepoprawny wierzcholek!\n";
            }
            else
            {
                cout << endl<<"startuje" << endl;
                fordBellman(liczba);
            }
            break;
        }
        case 8:
            drukujListe();
            break;
        case 9:
            return;
        default:
        {
            cout << "Wybrales zla opcje! \n";
            break;
        }
        }
    }
}

/// Algorytm dijkstry
void NeighbourList::dijkstra(int start)
{
    /// Tablice: poprzednikow, dystansu i flag odwiedzen
    int* pred = new int[iloscWierzcholkow];
    int* dist = new int[iloscWierzcholkow];
    bool* checked = new bool[iloscWierzcholkow];

    /// Ustawienie poprzednikow na -1
    /// dystasu na najwieksza wartosc inta
    /// flage odwiedzenia na false
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
        checked[i] = false;
    }

    /// Dystans wierzcholka poczatkowego to 0
    dist[start] = 0;

    /// Petla funkcji
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        int indeksWierzcholka;
        int mindist = INT_MAX;

        /// Sprawdzenie, czy do wierzcholka da sie dojsc szybciej
        for(int j = 0; j < iloscWierzcholkow; j++)
        {
            if(!checked[j] && dist[j] < mindist)
            {
                indeksWierzcholka = j;
                mindist = dist[indeksWierzcholka];
            }
        }
        if(mindist == INT_MAX)
            break;
        checked[indeksWierzcholka] = true;

        /// Zmiana najlepszego wierzcholka dojscia dla kazdego wierzcholka
        for(int j = 0; j < tablicaKrawedzi[indeksWierzcholka].rozmiar; j++)
        {
            Krawedz* wsk = tablicaKrawedzi[indeksWierzcholka].zwrocElement(j);
            if(dist[wsk->wierzcholekkoncowy] > dist[wsk->wierzcholekPoczatkowy] + wsk->waga)
            {
                dist[wsk->wierzcholekkoncowy] = dist[wsk->wierzcholekPoczatkowy] + wsk->waga;
                pred[wsk->wierzcholekkoncowy] = indeksWierzcholka;
            }
        }
    }

    cout << "Wierzcholki ich poprzednicy i koszt dojscia..." <<endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout <<" [" << i << "] ";
    }
    cout << endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout <<setw(3) << dist[i] << "; ";
    }
    cout << endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout <<setw(3) << pred[i] << "; ";
    }
    cout << endl;

    delete[] dist;
    delete[] checked;
    delete[] pred;
}

void NeighbourList::fordBellman(int start)
{
    int maxint = INT_MAX;
    bool zmieniony;
    bool jestCykl = false;
    int* pred = new int[iloscWierzcholkow];
    int* dist = new int[iloscWierzcholkow];
    bool* wierzcholkiWychodzace = new bool[iloscWierzcholkow];
    bool* wierzcholkiWychodzacePomoc = new bool[iloscWierzcholkow];

    /// Ustawienie wartosci poczatkowych
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
        wierzcholkiWychodzace[i] = false;
        wierzcholkiWychodzacePomoc[i] = false;
    }

    /// Ustawienie wierzcholka poczatkowego
    dist[start] = 0;
    wierzcholkiWychodzace[start] = true;

    /// Petla dla n-1 powtorzen
    for(int i = 1; i < iloscWierzcholkow; i++)
    {
        zmieniony = true;
        jestCykl = true;

        /// Sprawdzenie warunku dla kazdej krawedzi wychodzacej z ostatnio odwiezdonych wierzcholkow
        for(int j = 0; j<iloscWierzcholkow; j++)
        {
            if(wierzcholkiWychodzace[j])
            {
                for(int x = 0; x < tablicaKrawedzi[j].rozmiar; x++)
                {
                    Krawedz* wsk = tablicaKrawedzi[j].zwrocElement(x);
                    if(dist[wsk->wierzcholekkoncowy] > dist[wsk->wierzcholekPoczatkowy] + wsk->waga)
                    {
                        zmieniony = false;
                        dist[wsk->wierzcholekkoncowy] = dist[wsk->wierzcholekPoczatkowy] + wsk->waga;
                        pred[wsk->wierzcholekkoncowy] = j;
                        wierzcholkiWychodzacePomoc[wsk->wierzcholekkoncowy] = true;
                    }

                }
            }
            if(jestCykl && (j == iloscWierzcholkow - 1))
            {
                j = -1;
                jestCykl = false;
            }
        }

        /// Wyznaczenie przyszlych wierzcholkow poczatkowych
        for(int x = 0; x < iloscWierzcholkow; x++)
        {
            if(wierzcholkiWychodzacePomoc[x])
                wierzcholkiWychodzace[x] = true;
            else
                wierzcholkiWychodzace[x] = false;
            wierzcholkiWychodzacePomoc[x] = false;
        }
        if(zmieniony)
            maxint = 0;
        if(maxint == 0)
            break;
    }

    cout << "Wierzcholki ich poprzednicy i koszt dojscia..." <<endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout <<" [" << i << "] ";
    }
    cout << endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout <<setw(3) << dist[i] << "; ";
    }
    cout << endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout <<setw(3) << pred[i] << "; ";
    }
    cout << endl;

    /// Wykrycie cylku ujemnego
    for(int i = 0; i < iloscWierzcholkow; i++)
        for(int j = 0; j < tablicaKrawedzi[i].rozmiar; j++)
        {
            Krawedz* wsk = tablicaKrawedzi[i].zwrocElement(j);
            if((wsk->wierzcholekPoczatkowy == i) && (dist[wsk->wierzcholekkoncowy] > dist[wsk->wierzcholekPoczatkowy] + wsk->waga))
                jestCykl = true;
        }
    if(jestCykl)
    {
        cout << endl << "Cykl ujemny lub niedostepny wierzcholek" << endl;
        return;
    }
    delete[] pred;
    delete[] dist;
    delete[] wierzcholkiWychodzace;
    delete[] wierzcholkiWychodzacePomoc;
}

bool NeighbourList::KruskalMST()
{
    int sumaWag = 0;
    Lista drzewo, posortowane;
    Disjoint_Union disUnion(iloscWierzcholkow);

    /// Tworzenie posortowanej listy
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        for(int j = 0; j < tablicaKrawedzi[i].rozmiar; j++)
        {
            Krawedz* k = new Krawedz(*tablicaKrawedzi[i].zwrocElement(j));
            posortowane.dodajNaKoniec(k);
        }
    }

    /// Sortuje liste
    posortowane.quickSort();

    for(int i = 0; i < iloscWierzcholkow; i++)
        disUnion.makeSet(i);

    /// Petla pobierajaca kolejne krawezdie z posortowanego zbioru
    /// i sprawdzajaca czy nie tworza cykli
    /// na jedna iteracje przypadajedna krawedz
    for(int i = 1; i <iloscWierzcholkow; i++)
    {
        Krawedz* k = new Krawedz;
        Krawedz* iter = posortowane.pierwsza;

        do
        {
            if(iter == NULL)
            {
                return false;
            }
            *k = *iter;
            iter = iter->nastepna;
            posortowane.usunPierwszy();
        }
        while(disUnion.findSet(k->wierzcholekPoczatkowy) == disUnion.findSet(k->wierzcholekkoncowy));
        drzewo.dodajNaKoniec(k);
        disUnion.unionSets(*k);
        sumaWag += k->waga;
    }
    cout << "Minimalne drzewo rozpinajace..." << endl;
    drukujKrawedzie(drzewo);
    cout << endl << "Suma wag krawedzi = " << sumaWag << endl;
    //drzewo.wydrukujListe();
    return true;
}

bool NeighbourList::PrimMST(int start)
{
    int sumaWag = 0;
    Lista drzewo;
    bool* odwiedzone = new bool[iloscWierzcholkow];
    int licznikTrue = 1;

    Disjoint_Union disUnion(iloscWierzcholkow);

    Disjoint_Union* wskDisUnion = &disUnion;
    for(int i = 0; i < iloscWierzcholkow; i++)
        odwiedzone[i] = false;

    for(int i = 0; i < iloscWierzcholkow; i++)
        disUnion.makeSet(i);

    odwiedzone[start] = true;

    /// Petla wyznaczajaca krawedzie drzewa
    /// iteruje poki ilosc krawedzi w drzewie nie jest rowna ilosci wierzcholkow
    ///
    while(licznikTrue!=iloscWierzcholkow)
    {
        Krawedz* k = nastepnaKrawedz(odwiedzone, wskDisUnion, drzewo);
        if(k->waga == INT_MAX)
            return false;
        licznikTrue++;
        drzewo.dodajNaKoniec(k);
        wskDisUnion->unionSets(*k);
        sumaWag += k->waga;
    }
    cout << "Minimalne drzewo rozpinajace" << endl;
    drukujKrawedzie(drzewo);
    cout << "Suma wag krawedzi = " << sumaWag << endl;
        //drzewo.wydrukujListe();
    delete wskDisUnion;
    delete[] odwiedzone;
    return false;
}

/// Funkcja wyznaczajaca nastepna krawedz do dodania
/// Dodaje do zbioru z ktorego w przyszlosci wybierze wszystkie krawedzie wychodzace z wybranych juz wierzcholkow
/// nasteone sortuje je pod wzgledem wystepowania cykli
/// nastepnie sposrod pozostalych wybiera ten o najmniejszym koszcie
Krawedz* NeighbourList::nastepnaKrawedz(bool* odwiedzone, Disjoint_Union* disUnion, Lista& drzewo)
{
    Lista krawedzie;
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        if(odwiedzone[i])
        {
            for(int j =0; j < tablicaKrawedzi[i].rozmiar; j++)
            {
                Krawedz* wsk = tablicaKrawedzi[i].zwrocElement(j);
                Krawedz* k = new Krawedz(wsk->wierzcholekPoczatkowy, wsk->wierzcholekkoncowy, wsk->waga);
                krawedzie.dodajNaKoniec(k);
            }
        }
    }

    for(int i = 0; i < krawedzie.rozmiar;)
    {
        Krawedz* k = krawedzie.zwrocElement(i);
        if(disUnion->findSet(k->wierzcholekPoczatkowy) == disUnion->findSet(k->wierzcholekkoncowy))
        {
            krawedzie.usunKtorykolwiek(i);
            continue;
        }
        /// Dla kazdego
        i++;
    }

    Krawedz* zwracana = new Krawedz(-1,-1,INT_MAX);

    for(int i = 0; i < krawedzie.rozmiar; i++)
    {
        if(zwracana->waga > krawedzie.zwrocElement(i)->waga)
            zwracana = krawedzie.zwrocElement(i);
    }

    odwiedzone[zwracana->wierzcholekkoncowy] = true;
    odwiedzone[zwracana->wierzcholekPoczatkowy] = true;
    Krawedz* k = new Krawedz;
    k->waga = zwracana->waga;
    k->wierzcholekkoncowy = zwracana->wierzcholekkoncowy;
    k->wierzcholekPoczatkowy = zwracana->wierzcholekPoczatkowy;
    return k;
}

void NeighbourList::losowaListaSasiedztw(int ilW, int ilK, int skier)
{
    if(ilW == 0)
        return;
    delete[] tablicaKrawedzi;
    iloscWierzcholkow = ilW;
    iloscKrawedzi = ilK;
    tablicaKrawedzi = new Lista[ilW];

    /// Tworzenie wierszy tablicy list
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        Lista l;
        tablicaKrawedzi[i] = l;
    }
    //drukujListe();

    /// Odczytanie krawedzi i zapisanie do macierzy
    /// Poczatek - Koniec - Waga
    int skierowany = skier;
    // cout << "Graf skierowany [0] czy nieskierowany [inna]? ";
    //cin >> skierowany;
    srand(time(NULL));
    for(int i = 0; i < ilK; i++)
    {
        int wPocz = rand()%iloscWierzcholkow;
        int wKon = rand()%iloscWierzcholkow;
        int wagaK = rand()%10;
        if(skierowany == 0)
        {
            Krawedz* k = new Krawedz(wPocz, wKon, wagaK);
            tablicaKrawedzi[wPocz].dodajNaKoniec(k);
        }
        else
        {
            Krawedz* k = new Krawedz(wPocz, wKon, wagaK);
            Krawedz* k2 = new Krawedz(wKon, wPocz, wagaK);
            tablicaKrawedzi[wPocz].dodajNaKoniec(k);
            tablicaKrawedzi[wKon].dodajNaKoniec(k2);
        }
    }
}

void NeighbourList::drukujKrawedzie(Lista& krawedzie)
{
    for(int i = 0; i < krawedzie.rozmiar; i++)
        cout << "[" << i << "]" << *krawedzie.zwrocElement(i) << endl;
}
