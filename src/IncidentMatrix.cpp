#include "IncidentMatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iomanip>
#include <time.h>
#include <limits.h>
#include "Disjoint_Union.h"
#include "lista.h"
#include "listaInt.h"

using namespace std;

/// Macierz incydencji skierowana
IncidentMatrix::IncidentMatrix()
{
    macierz = NULL;
    iloscWierzcholkow = 0;
    iloscKrawedzi = 0;
}

IncidentMatrix::~IncidentMatrix()
{
    for(int i =0; i<iloscWierzcholkow; i++)
        delete[] macierz[i];
    delete[] macierz;
    delete[] tablicaWag;
}

void IncidentMatrix::drukujMacierz()
{
    cout << "Wagi:";
    for(int j = 0; j < iloscKrawedzi; j++)
        cout << setw(3) << tablicaWag[j];
    cout << endl;
    cout << setw(5) << " ";
    for(int j = 0; j< iloscKrawedzi; j++)
    {
        cout << setw(3) <<j;
    }
    cout << endl;
    for(int i = 0; i<iloscWierzcholkow; i++)
    {
        cout << setw(3) << "[" << i << "] ";
        for(int j = 0; j < iloscKrawedzi; j++)
        {
            cout << setw(2) << macierz[i][j] << " ";
        }
        cout << endl;
    }
}

void IncidentMatrix::stworzMacierz()
{
    /// Odczytanie krawêdzi
    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        /// Odczytanie rozmiaru i ilosci krawedzi
        getline(myfile, line);
        iloscWierzcholkow = atoi(line.c_str());

        getline(myfile, line);
        iloscKrawedzi = atoi(line.c_str());

        macierz = new int*[iloscWierzcholkow];
        tablicaWag = new int[iloscKrawedzi];

        /// Tworzenie wierszy macierzy
        for(int i =0; i<iloscWierzcholkow; i++)
            macierz[i] = new int[iloscKrawedzi];

        /// Wype³nienie macierzy zerami
        for(int i = 0; i<iloscWierzcholkow; i++)
            for(int j = 0; j<iloscKrawedzi; j++)
                macierz[i][j] = 0;

        /// Odczytanie krawedzi i zapisanie do macierzy
        /// Poczatek - Koniec - Waga
        int buf[3], counter = 0, krawedz = 0;
        macierzPomocnicza = new int*[iloscKrawedzi];
        for(int i = 0; i < iloscKrawedzi; i++)
        {
            macierzPomocnicza[i] = new int[3];
        }
        while(getline(myfile, line, ' '))
        {
            buf[counter] = atoi(line.c_str());
            counter ++;
            if(counter == 3)
            {
                macierz[buf[0]][krawedz] = 1;
                macierz[buf[1]][krawedz] = -1;
                tablicaWag[krawedz] = buf[2];
                macierzPomocnicza[krawedz][0] = buf[0];
                macierzPomocnicza[krawedz][1] = buf[1];
                macierzPomocnicza[krawedz][2] = buf[2];
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

void IncidentMatrix::menu()
{
    cout << endl;
    int liczba;
    short exit = 0;
    short choice;
    while (exit == 0)
    {
        if (exit == 1)
            break;
        cout << "Co chcesz zrobic?\n";
        cout << "1. Wczytaj dane z pliku. \n";
        cout << "2. Wygeneruj dane losowo. \n";
        cout << "3. Algorytm Prima. \n";
        cout << "4. Algorytm Kruskala. \n";
        cout << "5. Algorytm Dijkstry. \n";
        cout << "6. Algorytm Forda-Bellmana. \n";
        cout << "8. Wypisz macierz. \n";
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
            stworzMacierz();
            cout << endl;
            break;
        }

        case 2:
        {
            int ilW, ilK;
            cout << "podaj ilosc wierzcholkow: ";
            cin >>ilW;
            cout << endl;
            cout << "podaj ilosc krawedzi: ";
            cin >>ilK;
            cout << endl;
            stworzLosowaMacierz(ilW,ilK);
            break;
        }
        case 3:
        {
            cout << endl;
            if (macierz == NULL)
            {
                cout << "Macierz jest pusta! \n";
                cout << "Wczytaj dane do amcierzy!\n";
                break;
            }
            int wierzStart = 0;
            cout << "Podaj wierzcholek startowy: ";
            cin >> wierzStart;
            cout << endl;
            primMST(wierzStart);
            break;
        }
        case 4:
        {
            cout << endl;
            if (macierz == NULL)
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
            if (macierz == NULL)
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
            if (macierz == NULL)
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
            drukujMacierz();
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

/// Algorytm Dijkstry:
/// Wyszukuje najtansze drogi dojscia od wierzcholka startowego
void IncidentMatrix::dijkstra(int start)
{
    /// Tablice poprzednikow, dystansow dojsc i flag odwiedzen
    int* pred = new int[iloscWierzcholkow];
    int* dist = new int[iloscWierzcholkow];
    bool* checked = new bool[iloscWierzcholkow];

    /// wartosc poprzednikow to nieistniejacy wierzcholek -1
    /// dystansem jest symboliczna nieskonczonosc, w tym przypadku najwieksza wartosc inta
    /// odwiedzenia ustawione na false - poczatek dzialania algorytmu
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
        checked[i] = false;
    }

    /// koszt dojscia do wierzcholka startowego to oczywiscie 0, poniewaz juz w nim jestesmy
    dist[start] = 0;

    /// Petla algorytmu
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        int indeksWierzcholka;
        int mindist = INT_MAX;

        /// Wyszukuje wierzcholek o najmniejszym dystansie, z ktorego jeszcze nie startowano
        /// Dla pierwszego wywolania to zawsze bedzie nasz wierzcholek startowy
        for(int j =0; j<iloscWierzcholkow; j++)
        {
            if(!checked[j] &&dist[j] < mindist)
            {
                indeksWierzcholka = j;
                mindist = dist[indeksWierzcholka];
            }
        }

        /// Jesli mindist maksymalne => nie ma nieodwiedzonego w jednym grafie ze startowym
        if(mindist == INT_MAX)
            break;

        checked[indeksWierzcholka] = true;

        ListaInt sasiednieWierzcholki;
        ListaInt indeksyKrawedzi;
        for(int j =0; j<iloscKrawedzi; j++)
        {
            if(macierz[indeksWierzcholka][j] == 1)
            {
                for(int k = 0; k < iloscWierzcholkow; k ++)
                {
                    if(macierz[k][j] == -1 && !checked[k])
                    {
                        indeksyKrawedzi.dodajNaKoniec(j);
                        sasiednieWierzcholki.dodajNaKoniec(k);
                        break;
                    }
                }
            }
        }

        /// Zmiana wartosci dojscia do wierzcholkow dla polaczonych z wybranym wierzcholkiem
        for(int i = 0; i <sasiednieWierzcholki.rozmiar; i++)
        {
            if(dist[sasiednieWierzcholki.zwrocElement(i)] > dist[indeksWierzcholka] + tablicaWag[indeksyKrawedzi.zwrocElement(0)])
            {
                dist[sasiednieWierzcholki.zwrocElement(i)] = dist[indeksWierzcholka] + tablicaWag[indeksyKrawedzi.zwrocElement(0)];
                pred[sasiednieWierzcholki.zwrocElement(i)] = indeksWierzcholka;
            }
            indeksyKrawedzi.usunPierwszy();
        }
    }

    /// Drukowanie wynikow
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

    delete[] pred;
    delete[] dist;
    delete[] checked;
}

/// Algorytm Ford-Bellmana
/// Rozwiazuje problem najkrotszej sciezki
void IncidentMatrix::fordBellman(int start)
{
    int maxint = INT_MAX;
    bool zmieniony;
    bool jestCykl = false;
    int* pred = new int[iloscWierzcholkow];
    int* dist = new int[iloscWierzcholkow];

    /// Ustawienie wartosci poczatkowych
    for(int i = 0; i< iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
    }

    /// dystans do wierzcholka startowego = 0 => jestesmy w nim
    dist[start] = 0;

    /// Petla wyszukujaca wierzcholki
    for(int i = 1; i < iloscWierzcholkow; i++)  // n-1 przejsc
    {
        zmieniony = true;
        jestCykl = true;

        for(int j = start; j<iloscWierzcholkow; j++)
        {
            for(int x = 0; x < iloscKrawedzi; x++)
                if((macierzPomocnicza[x][0] == j) && (dist[macierzPomocnicza[x][1]] > (dist[j] + macierzPomocnicza[x][2])))
                {
                    if(dist[j] != INT_MAX)
                    {
                        /// zmiana w tablicy
                        zmieniony = false;
                        /// wpisujemy koszt przejscia
                        dist[macierzPomocnicza[x][1]] = dist[j] + macierzPomocnicza[x][2];
                        /// poprzednikiem sasiada bedzie wierzcholek j
                        pred[macierzPomocnicza[x][1]] = j;
                    }
                }
            if(jestCykl && (j == iloscWierzcholkow - 1))
            {
                j = -1;
                jestCykl = false;
            }
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

    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        for(int x = 0; x < iloscKrawedzi; x++)
        {
            if((macierzPomocnicza[x][0] == i) && (dist[macierzPomocnicza[x][1]] > (dist[macierzPomocnicza[x][0]] + macierzPomocnicza[x][2])))
                jestCykl = true;
        }
    }
    if(jestCykl)
    {
        cout << endl << "Cykl ujemny lub niedostepny wierzcholek" << endl;
        return;
    }
    delete[] pred;
    delete[] dist;
}

/// Algorytm Kruskala
/// Rozwiazuje problem minimalnego drzewa
bool IncidentMatrix::KruskalMST()
{
    int p = 0;
    int k = 0;
    int w = 0;

    /// Sortowanie
    for(int j = 0; j<iloscKrawedzi; j++)
    {
        for(int i = j; i < iloscKrawedzi; i++)
        {
            if(macierzPomocnicza[i][2] < macierzPomocnicza[j][2])
            {
                p = macierzPomocnicza[i][0];
                k = macierzPomocnicza[i][1];
                w = macierzPomocnicza[i][2];
                macierzPomocnicza[i][0] = macierzPomocnicza[j][0];
                macierzPomocnicza[i][1] = macierzPomocnicza[j][1];
                macierzPomocnicza[i][2] = macierzPomocnicza[j][2];
                macierzPomocnicza[j][0] = p;
                macierzPomocnicza[j][1] = k;
                macierzPomocnicza[j][2] = w;
            }
        }
    }

    /// Lista przechowujaca krawedzie grafu
    Lista test;
    for(int i = 0; i < iloscKrawedzi; i++)
    {
        Krawedz* k = new Krawedz(macierzPomocnicza[i][0],macierzPomocnicza[i][1],macierzPomocnicza[i][2]);
        test.dodajNaKoniec(k);
    }

    /// Pomocny zestaw zbiorow rozlacznych
    /// Zaimplementowany w celu sprawdzania, czy nie wystapily gdzies cykle
    Disjoint_Union disUnion(iloscWierzcholkow);

    Lista drzewo;

    for(int i = 0; i < iloscWierzcholkow; i++)
        disUnion.makeSet(i);

    /// Petla algorytmu
    /// Jedno wykoanie petli, to jedna dodana krawedz
    /// Przechodzi po wszyskich krawedziach od najmnniejszego do najwiekszego kosztu
    /// Jesli krawedz nie utworzy cyklu jest dodawana do drzewa
    for(int i = 1; i < iloscWierzcholkow; i++)
    {
        Krawedz* k = new Krawedz;
        Krawedz* iter = test.pierwsza;

        do
        {
            if(iter == NULL)
            {
                return false;
            }
            *k = *iter;
            iter = iter->nastepna;
            test.usunPierwszy();
        }
        while(disUnion.findSet(k->wierzcholekPoczatkowy) == disUnion.findSet(k->wierzcholekkoncowy));
        drzewo.dodajNaKoniec(k);
        disUnion.unionSets(*k);
    }
    cout << "Minimalne drzewo rozpinające:"<<endl;
    drzewo.wydrukujListe();
    return true;
}

/// Algorytm Prima
/// Problem minimalnego drzewa rozpinajacego
bool IncidentMatrix::primMST(int start)
{
    /// Tablica wierzcholkow odwiedzonych przez algorytm
    bool* odwiedzone = new bool[iloscWierzcholkow] ;
    int licznikTrue = 1;

    /// Pomocny zestaw zbiorow rozlacznych
    /// Zaimplementowany w celu sprawdzania, czy nie wystapily gdzies cykle
    Disjoint_Union disUnion(iloscWierzcholkow);

    /// Wskaznik na zbior do przekazywania do funkcji
    Disjoint_Union* wskDisUnion = &disUnion;
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        odwiedzone[i] = false;
    }

    for(int i = 0; i < iloscWierzcholkow; i++)
        disUnion.makeSet(i);

    odwiedzone[start] = true;
    Lista drzewo;

    /// Petla algorytmu
    /// Wywoluje funkcje zwracajaca nastepna krawedz i dodaje ja do drzewa
    /// Jesli zwrocona krawedz ma granice maksymalna najpewniej graf rozlaczny
    /// Nalezy przerwac wykonywanie algorytmu
    while(licznikTrue!=iloscWierzcholkow)
    {
        Krawedz* k = nastepnaKrawedz(odwiedzone, wskDisUnion);
        if(k->waga == INT_MAX)
            return false;
        licznikTrue++;
        drzewo.dodajNaKoniec(k);
        wskDisUnion->unionSets(*k);
    }

    drzewo.wydrukujListe();

    if(drzewo.rozmiar<iloscWierzcholkow-1)
        cout << "Nie da sie utworzyc MST."<<endl;

    delete wskDisUnion;
    delete[] odwiedzone;
    return true;
}

Krawedz* IncidentMatrix::nastepnaKrawedz(bool* odwiedzone, Disjoint_Union* disUnion)
{
    Lista krawedzie;

    /// Wyselekcjonowanie krawedzi do ktorych naleza wierzcholki drzewa
    for(int i = 0; i<iloscWierzcholkow; i++)
    {
        /// Sprawdzenie, ktora krawedz nalezy do drzewa
        if(odwiedzone[i] == true)
        {
            /// Znalezienie indeksow krawedzi wierzcholka
            for(int j = 0; j < iloscKrawedzi; j++)
            {
                if(macierz[i][j] == 1)
                {
                    /// Znalezienie indeksu wierzcholka sasiadujacego
                    for(int z = 0; z < iloscWierzcholkow; z++)
                    {
                        if(macierz[z][j]==-1)
                        {
                            Krawedz* k = new Krawedz(i,z,tablicaWag[j]);
                            krawedzie.dodajNaKoniec(k);
                        }
                    }
                }
                if(macierz[i][j] == -1)
                {
                    /// Znalezienie indeksu wierzcholka sasiadujacego
                    for(int z = 0; z < iloscWierzcholkow; z++)
                    {
                        if(macierz[z][j]==1)
                        {
                            Krawedz* k = new Krawedz(i,z,tablicaWag[j]);
                            krawedzie.dodajNaKoniec(k);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i<krawedzie.rozmiar;)
    {
        Krawedz* k = krawedzie.zwrocElement(i);
        if(disUnion->findSet(k->wierzcholekPoczatkowy) == disUnion->findSet(k->wierzcholekkoncowy))
        {
            krawedzie.usunKtorykolwiek(i);
            continue;
        }
        i++;
    }

    Krawedz* zwracana = new Krawedz(-1,-1,INT_MAX);

    for(int i = 0; i < krawedzie.rozmiar; i++)
        if(zwracana->waga > krawedzie.zwrocElement(i)->waga)
        {
            zwracana = krawedzie.zwrocElement(i);
        }
    if(zwracana->waga == INT_MAX)
        return zwracana;
    odwiedzone[zwracana->wierzcholekkoncowy] = true;
    odwiedzone[zwracana->wierzcholekPoczatkowy] = true;
    Krawedz* k = new Krawedz;
    k->waga = zwracana->waga;
    k->wierzcholekkoncowy = zwracana->wierzcholekkoncowy;
    k->wierzcholekPoczatkowy = zwracana->wierzcholekPoczatkowy;
    return k;
}

void IncidentMatrix::stworzLosowaMacierz(int ilW, int ilK)
{
    if(ilW == 0)
        return;
    srand(time(NULL));
    /// Usuwam poprzednie macierze
    if(macierz!=NULL)
        delete[] macierz;
    if(macierzPomocnicza!=NULL)
        delete[] macierzPomocnicza;

    iloscKrawedzi = ilK;
    iloscWierzcholkow = ilW;

    // Wypelnienie losowymi wartosciami macierz
    macierz = new int*[iloscWierzcholkow];
    tablicaWag = new int[iloscKrawedzi];

    /// Tworzenie wierszy macierzy
    for(int i =0; i<iloscWierzcholkow; i++)
        macierz[i] = new int[iloscKrawedzi];

    /// Wype³nienie macierzy zerami
    for(int i = 0; i<iloscWierzcholkow; i++)
        for(int j = 0; j<iloscKrawedzi; j++)
            macierz[i][j] = 0;

    /// Odczytanie krawedzi i zapisanie do macierzy
    /// Poczatek - Koniec - Waga
    macierzPomocnicza = new int*[iloscKrawedzi];
    for(int i = 0; i < iloscKrawedzi; i++)
    {
        macierzPomocnicza[i] = new int[3];
    }
    for(int i = 0; i < iloscKrawedzi; i++)
    {
        int wPocz = rand()%iloscWierzcholkow;
        int wKon = rand()%iloscWierzcholkow;
        int wagaK = rand()%10;
        macierz[wPocz][i] = 1;
        macierz[wKon][i] = -1;
        tablicaWag[i] = wagaK;
        macierzPomocnicza[i][0] = wPocz;
        macierzPomocnicza[i][1] = wKon;
        macierzPomocnicza[i][2] = wagaK;
    }
}
