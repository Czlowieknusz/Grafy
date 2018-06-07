#include "Menu.h"
#include "IncidentMatrix.h"
#include "NeighbourList.h"
#include <iostream>
#include <cstdlib>
#include "Dane.h"

using namespace std;

Menu::Menu()
{
    opcja = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu::AskForOption() {
		while (true) {//Nasze glowne menu
			cout << "Witaj w programie.\n";
			cout << "Wpisz numer polecenia: \n";
			cout << "Opcje reprezentacji grafu: \n";
			cout << "1. Macierz indykacji.\n";
			cout << "2. Lista nastepnikow.\n";
			cout << "5. Wygeneruj nowe dane. \n";
			//cout << "9. Rozpocznij testy.\n";
			cout << "Aby wyjsc wpisz cokolwiek innego. \n";
			cin >> opcja;
			if (!cin) {
				cin.clear();
				cin.ignore();
			}
			switch (opcja) {
			case 1://Macierz
			{
				IncidentMatrix matrix;
				matrix.menu();
				break;
			}
			case 2://Lista
			{
				NeighbourList lis;
				//lis.menu();
				break;
			}

			case 5://Stworzmy inne dane
			{
				Dane data;
				cout << "Ile wierzcholkow ma byc w grafie?\n";
				cin >> data.iloscWierzcholkow;
				cin.ignore();
				cout << "Ile krawedzi ma byc w grafie?\n";
				cin >> data.iloscKrawedzi;
				data.stworzDane();
				break;
			}

			default:
				cout << "Zla opcja.";
				exit(1000);
				break;
			}
		}
	}

