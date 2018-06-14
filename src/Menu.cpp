#include "Menu.h"
#include "IncidentMatrix.h"
#include "NeighbourList.h"
#include <iostream>
#include <cstdlib>
#include "Testy.h"

using namespace std;

Menu::Menu()
{
    cout << "\n========== MENU STRUKTUR ==========" <<endl;
    opcja = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu::AskForOption(IncidentMatrix& iM, NeighbourList& nLSkier, NeighbourList& nLNieSkier) {
		while (true) {//Nasze glowne menu
			cout << "\nWitaj w programie.\n";
			cout << "Wpisz numer polecenia: \n";
			cout << "Opcje reprezentacji grafu: \n";
			cout << "1. Macierz indykacji.\n";
			cout << "2. Lista nastepnikow skierowana.\n";
			cout << "3. Lista nastepnikow nie skierowana.\n";
			cout << "9. Rozpocznij testy.\n";
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
                iM.menu();
                break;
			}
			case 2://Lista
			{
				nLSkier.menu();
				break;
			}
			case 3:
			    nLNieSkier.menu();
                break;
            case 9:
            {
                Testy test;
                cout << "Rozpoczynam testy..."<<endl;
                test.testyMatrix();
                break;
            }
			default:
				cout << "Zla opcja.";
				exit(1000);
				break;
			}
		}
	}

