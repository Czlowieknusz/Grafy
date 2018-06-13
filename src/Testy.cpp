#include "Testy.h"
#include "Czas.h"

using namespace std;

Testy::Testy()
{
    //ctor
}

Testy::~Testy()
{
    //dtor
}

void Testy::testyMatrix()
{
    cout << "========== Dijkstra ==============" << endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    dijkstraMatrix(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    dijkstraMatrix(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    dijkstraMatrix(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    dijkstraMatrix(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    dijkstraMatrix(100);


    cout << "========== Ford-Bellman =============="<<endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    fordBellmanMatrix(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    fordBellmanMatrix(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    fordBellmanMatrix(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    fordBellmanMatrix(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    fordBellmanMatrix(100);

    cout << "========== Prim MST =============="<<endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    primMatrix(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    primMatrix(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    primMatrix(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    primMatrix(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    primMatrix(100);

    cout << "=========== LISTA  ==============="    << endl;
    cout << "========== Dijkstra ==============" << endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    dijkstraLista(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    dijkstraLista(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    dijkstraLista(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    dijkstraLista(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    dijkstraLista(100);


    cout << "========== Ford-Bellman =============="<<endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    fordBellmanLista(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    fordBellmanLista(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    fordBellmanLista(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    fordBellmanLista(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    fordBellmanLista(100);

    cout << "========== Prim MST LISTA =============="<<endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    primLista(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    primLista(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    primLista(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    primLista(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    primLista(100);

    cout << "========== Kruskal MST =============="<<endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    kruskalLista(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    kruskalLista(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    kruskalLista(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    kruskalLista(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    kruskalLista(100);


    // Macierz
    cout << "==========Matrix Kruskal MST =============="<<endl << endl;
    cout << "====== Test 20 wierzcholkow ======" << endl <<endl;
    kruskalMatrix(20);
    cout << "====== Test 40 wierzcholkow ======" << endl <<endl;
    kruskalMatrix(40);
    cout << "====== Test 60 wierzcholkow ======" << endl <<endl;
    kruskalMatrix(60);
    cout << "====== Test 80 wierzcholkow ======" << endl <<endl;
    kruskalMatrix(80);
    cout << "====== Test 100 wierzcholkow ======" << endl <<endl;
    kruskalMatrix(100);
}

void Testy::dijkstraMatrix(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::fordBellmanMatrix(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::primMatrix(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.primMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.primMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.primMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.primMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::kruskalMatrix(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        IncidentMatrix iM;
        iM.stworzLosowaMacierz(iloscWierzcholkow, maxKrawedzi*stosunek);
        licznikCzasu.StartCounter();
        iM.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::dijkstraLista(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.dijkstra(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::fordBellmanLista(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 0);
        licznikCzasu.StartCounter();
        nL.fordBellman(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::primLista(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.PrimMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.PrimMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.PrimMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.PrimMST(0);
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}

void Testy::kruskalLista(int iloscWierzcholkow)
{
    /// 10 wierzcholkow
    Czas licznikCzasu;
    double sredniCzas = 0;
    int n = 100;
    double stosunek = 0.25;
    int maxKrawedzi = iloscWierzcholkow*(iloscWierzcholkow - 1)/2;

    for(int i = 0; i < n;  i++)
    {
        //cout << "inicjalizacja" << endl;
        NeighbourList* nL = new NeighbourList();
        //cout << "generacja danych" << endl;
        nL->losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        //cout << "czas start" << endl;
        licznikCzasu.StartCounter();
        //cout << "wywolanie funkcji" << endl;
        nL->KruskalMST();
        //cout << "przed czasm" << endl;
        sredniCzas += licznikCzasu.GetCounter();
        //cout << "po czasie" << endl;
        delete nL;
    }
    //cout << "po petli tej duzej?" << endl;
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.5;

    //cout << "Nastepna petla" << endl;
    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.75;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
    sredniCzas = 0;
    stosunek = 0.99;

    for(int i = 0; i < n;  i++)
    {
        NeighbourList nL;
        nL.losowaListaSasiedztw(iloscWierzcholkow, maxKrawedzi*stosunek, 1);
        licznikCzasu.StartCounter();
        nL.KruskalMST();
        sredniCzas += licznikCzasu.GetCounter();
    }
    sredniCzas/=n;
    cout << stosunek  << " - stosunek; wynik = " << sredniCzas<<endl;
}
