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
#include <stddef.h>
#include <algorithm>


using namespace std;
/*
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
*/

NeighbourList::NeighbourList(int wybor)
{
    tablicaKrawedzi = NULL;
    iloscWierzcholkow = iloscKrawedzi = 0;
    stworzListeSasiedztw(wybor);
}

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
        int skierowany;
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
        //drukujListe();
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

void NeighbourList::drukujListe()
{
    cout << "Lista sasiedztw..." << endl;
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        tablicaKrawedzi[i].wydrukujListe();
    }
}

void NeighbourList::menu()
{
    cout << endl;
    int liczba;
    short exit = 0;
    short choice;
    //int index = 0;
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
        cout << "7. Algorytm Forda Fulkersona. \n";
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
            //stworzLosowaMacierz();
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
            PrimMST(wierszStart);
            break;
        }
        case 4:
        {
            cout << endl;
            if (tablicaKrawedzi == NULL)
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
            if (tablicaKrawedzi == NULL)
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
            if (tablicaKrawedzi == NULL)
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
        default:
        {
            cout << "Wybrales zla opcje! \n";
            break;
        }
        }
    }
}

void NeighbourList::dijkstra(int start)
{
    int* pred = new int[iloscWierzcholkow];
    int* dist = new int[iloscWierzcholkow];
    bool* checked = new bool[iloscWierzcholkow];

    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
        checked[i] = false;
    }

    dist[start] = 0;

    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        int indeksWierzcholka;
        int mindist = INT_MAX;
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

        //ListaInt sasiednieWierzcholki;
        //ListaInt indeksyKrawedzi;

        for(int j = 0; j < tablicaKrawedzi[indeksWierzcholka].rozmiar; j++)
        {
            Krawedz* wsk = tablicaKrawedzi[indeksWierzcholka].zwrocElement(j);
            //cout << "Wsk = " << *wsk << "; tabKra = " << *tablicaKrawedzi[indeksWierzcholka].zwrocElement(j) << endl;
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
        cout << dist[i] << "; ";
    }
    cout << endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout << pred[i] << "; ";
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
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        pred[i] = -1;
        dist[i] = INT_MAX;
        wierzcholkiWychodzace[i] = false;
        wierzcholkiWychodzacePomoc[i] = false;
    }

    dist[start] = 0;
    wierzcholkiWychodzace[start] = true;

    for(int i = 1; i < iloscWierzcholkow; i++)
    {
        zmieniony = true;
        jestCykl = true;

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
        cout << dist[i] << "; ";
    }
    cout << endl;
    for(int i =0; i<iloscWierzcholkow; i++)
    {
        cout << pred[i] << "; ";
    }
    cout << endl;

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
    Lista drzewo, posortowane;
    Disjoint_Union disUnion(iloscWierzcholkow);

    /// Tworzenie posortowanej listy
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        for(int j = 0; j < tablicaKrawedzi[i].rozmiar; j++)
        {
            posortowane.dodajNaKoniec(tablicaKrawedzi[i].zwrocElement(j));
        }
    }
    /// Sortuje liste
    posortowane.quickSort();

    for(int i = 0; i < iloscWierzcholkow; i++)
        disUnion.makeSet(i);

    for(int i = 1; i <iloscWierzcholkow; i++)
    {
        Krawedz* k = new Krawedz;
        Krawedz* iter = posortowane.pierwsza;

        do
        {
            if(iter == NULL)
            {
                cout << "Nie da sie utworzyc MST" << endl;
                return false;
            }
            *k = *iter;
            iter = iter->nastepna;
            posortowane.usunPierwszy();
        }
        while(disUnion.findSet(k->wierzcholekPoczatkowy) == disUnion.findSet(k->wierzcholekkoncowy));
        drzewo.dodajNaKoniec(k);
        disUnion.unionSets(*k);
        for(int j = 0; j < iloscWierzcholkow; j++)
            cout << "DisUnion->up = " << disUnion.z[j].up << "; rank = " << disUnion.z[j].rank << endl;
    }
    cout << "Minimalne drzewo rozpinajace..." << endl;
    drzewo.wydrukujListe();
    return true;
}

bool NeighbourList::PrimMST(int start)
{
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

    while(licznikTrue!=iloscWierzcholkow)
    {
        Krawedz* k = nastepnaKrawedz(odwiedzone, wskDisUnion, drzewo);
        licznikTrue++;
        drzewo.dodajNaKoniec(k);
        wskDisUnion->unionSets(*k);
    }
    drzewo.wydrukujListe();
    delete wskDisUnion;
    delete[] odwiedzone;
    return false;
}

Krawedz* NeighbourList::nastepnaKrawedz(bool* odwiedzone, Disjoint_Union* disUnion, Lista& drzewo)
{
    Lista krawedzie;
    cout << "Szukamy krawedzi..." << endl;
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


/*
Krawedz* NeighbourList::nastepnaKrawedz(bool* odwiedzone, Disjoint_Union* disUnion, Lista& drzewo)
{
    cout << "Szukamy krawedzi..." << endl;
    Lista krawedzie;
    cout << "Wierzcholki poczatkowe..." <<endl;
    for(int i = 0; i < iloscWierzcholkow; i++)
    {
        if(odwiedzone[i])
            cout << " " << i;
    }
    cout << endl;
    for(int i = 0; i<iloscWierzcholkow; i++)
    {
        if(odwiedzone[i])
        {
            for(int j = 0; j < tablicaKrawedzi[i].rozmiar; j++)
            {
                Krawedz* wsk = tablicaKrawedzi[i].zwrocElement(j);
                Krawedz* k = new Krawedz(wsk->wierzcholekPoczatkowy, wsk->wierzcholekkoncowy, wsk->waga);
                krawedzie.dodajNaKoniec(k);
            }
        }
    }

    cout << "Krawedzie z cyklami" << endl;
    krawedzie.wydrukujListeSasiedztwa();

    /// Filtracja cykli
    for(int i = 0; i <krawedzie.rozmiar;)
    {
        Krawedz* k = krawedzie.zwrocElement(i);
        if(disUnion->findSet(k->wierzcholekPoczatkowy) == disUnion->findSet(k->wierzcholekkoncowy))
        {
            krawedzie.usunKtorykolwiek(i);
            continue;
        }
        i++;
    }
    Krawedz* zwracana;

    cout << "Krawedzie z powtorzeniami" << endl;
    krawedzie.wydrukujListeSasiedztwa();
/*
    /// Filtracja powtorzen
    for(int i = 0; i < krawedzie.rozmiar;)
    {
        if(drzewo.czyKrawedzObecna(krawedzie.zwrocElement(i))&&drzewo.rozmiar!=i)
        {
            krawedzie.usunKtorykolwiek(i);
            continue;
        }
        i++;
    }
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
}*/
