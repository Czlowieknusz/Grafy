#include "MainMenu.h"
#include "Menu.h"
#include "IncidentMatrix.h"
#include "NeighbourList.h"
#include <iostream>
#include <cstdlib>
#include "Testy.h"

using namespace std;

MainMenu::MainMenu()
{
    cout << "========== MENU PROGRAMU ==========" <<endl;
    opcja = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::AskForOption() {
		while (true) {//Nasze glowne menu
			cout << "Witaj w programie.\n";
			cout << "Wpisz numer polecenia: \n";
			cout << "1. Wczytaj dane z pliku.\n";
			cout << "2. Wygeneruj losowe dane.\n";
			cout << "3. Przejdz do wyboru struktury.\n";
			cout << "0. Wrc do poprzedniego menu.\n";
			cout << "Aby wyjsc wpisz cokolwiek innego. \n";
			cin >> opcja;
			if (!cin)
            {
				cin.clear();
				cin.ignore();
			}
			switch (opcja) {
			case 1://Macierz
			{
			    iM.stworzMacierz();
			    nLSkier.stworzListeSasiedztw(0);
			    nLNieSkier.stworzListeSasiedztw(1);
			    iM.drukujMacierz();
			    nLSkier.drukujListe();
			    nLNieSkier.drukujListe();
				break;
			}
			case 2://Lista
			{
			    int ilW, ilK, skier;
			    cout << "ile wierzcholkow?" << endl;
			    cin >> ilW;
			    cout << "ile Krawedzi?" << endl;
			    cin >> ilK;
			    cout << "skirowana? [0 tak] [1 nie]" << endl;
			    cin >> skier;
			    iM.stworzLosowaMacierz(ilW,ilK);
			    nLSkier.losowaListaSasiedztw(ilW,ilK,skier);
			    nLNieSkier.losowaListaSasiedztw(ilW,ilK,skier);
			    iM.drukujMacierz();
			    nLSkier.drukujListe();
			    nLNieSkier.drukujListe();
				break;
			}
            case 3:
            {
                cout << "przechodze do menu zarzadzania..." << endl;
                Menu menu;
                if(nLNieSkier.tablicaKrawedzi == NULL)
                    cout << "Najpierw wczytaj dane!" << endl;
                else
                    menu.AskForOption(iM, nLSkier, nLNieSkier);
                break;
            }
            case 4:
                return;
                break;
			default:
				cout << "Czy na pewno chcesz wyjsc? [1 - tak] [cokolwiek innego - nie]" << endl;
				int pytanie;
				cin >> pytanie;
				if(pytanie == 1)
                    exit(1000);
				break;
			}
		}
	}

