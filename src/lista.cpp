#include "lista.h"
#include <limits.h>

using namespace std;

Lista::Lista()
{
    Lista::pierwsza = NULL;
	Lista::aktualna = NULL;
	Lista::ostatnia = NULL;
	Lista::rozmiar = 0;
}

Lista::~Lista()
{
	for(int i = 0; i<Lista::rozmiar; i++)
	{
		// Przypisuje kolejny element do aktualna
		aktualna = pierwsza->nastepna;

		// Usuñ pierwszy element
		delete pierwsza;

		// Przypisz aktualna do pierwsza
		pierwsza = aktualna;
	}
}

void Lista::dodajNaPoczatek(Krawedz* k)
{
	// Sprawdzenie, czy lista nie jest pusta
	if(pierwsza == NULL)
	{
		// Uwórz element, nastêpnie ustaw go jako element pocz¹tkowy i koñcowy
		pierwsza = k;
		ostatnia = pierwsza;
	}
	else
	{
		// Ustaw element pierwszy jako aktualny
		aktualna = pierwsza;

		// utworzenie nowego elementu i przypisanie go jako pierwsza
		pierwsza = k;
		pierwsza->nastepna = aktualna;
		aktualna->poprzednia = pierwsza;
		//pierwsza->poprzednia = NULL;
	}

	// Inkrementacja rozmiaru listy
	rozmiar++;
}

void Lista::dodajNaKoniec(Krawedz* k)
{
	//Sprawdzenie czy lista nie jest pusta
	if(pierwsza == NULL)
	{
		// Uwórz element, nastêpnie ustaw go jako element pocz¹tkowy i koñcowy
		pierwsza = k;
		ostatnia = pierwsza;
	}
	else
	{
		// Ustaw ostatni element jako aktualny
		aktualna = ostatnia;

		// utworzenie nowego elementu i przypisanie go jako ostatnia
		ostatnia = k;
		ostatnia->poprzednia = aktualna;
		aktualna->nastepna = ostatnia;
	}

	// Inkrementacja rozmiaru
	rozmiar++;
}

void Lista::dodajGdziekolwiek(Krawedz* k, int pozycja)
{
    // Sprawdz czy lista posiada dan¹ pozycjê
	if(pozycja < 0 || pozycja > rozmiar)
	{
		//cout << "Lista nie posiada pozycji [" << pozycja << "]" << endl;
		return;
	}

	// Sprawdz czy dana pozycja jest pierwsz¹
	if(pozycja == 0)
	{
		Lista::dodajNaPoczatek(k);
		return;
	}

	// Sprawdz czy dana pozycja jest ostatni¹
	if(pozycja == rozmiar)
	{
		Lista::dodajNaKoniec(k);
		return;
	}

	// Sprawdzenie w której po³owie listy znajduje siê wybrany element
	// w celu przyspieszenia obliczeñ
	if(pozycja < rozmiar / 2)
	{
		// Przypisz pierwszy element za aktualny
		aktualna = pierwsza;

		// Przesuñ aktualna do danej pozycji
		for(int i = 1; i < pozycja; ++i)
		{
			aktualna = aktualna->nastepna;
		}
	}
	else
	{
		//Przypisz element ostatni za aktualny
		aktualna = ostatnia;

		// Przesuñ wszystkie elementy o jedn¹ pozycjê wstecz
		for(int i = 0; i < rozmiar - pozycja; ++i)
		{
			aktualna = aktualna->poprzednia;
		}
	}
	cout << "Dodawany element = " << *k << " poprzedniczka: "<<*aktualna << "; pozycja: " << pozycja <<endl;
	// Stwórz nowy element listy z podanymi parametrami
    k->nastepna = aktualna->nastepna;
    k->poprzednia = aktualna;
	// Przypisz nowy element na danej pozycji listy
	aktualna->nastepna->poprzednia = k;
	aktualna->nastepna = k;

	// Inkrementacja rozmiaru
	rozmiar++;
}

void Lista::usunPierwszy()
{
    if(pierwsza==NULL)
    {
        cout << "Lista jest pusta."<<endl;
        return;
    }
	// Przypisz drugi element jako aktualny
	aktualna = pierwsza->nastepna;

	// Usuñ pierwszy element
	delete pierwsza;

	// Sprawdzenie czy w liœcie s¹ inne elementy
	// Je¿eli tak, przypisz aktualny element jako pierwsze
	// Je¿eli nie, nullujemy elementy listy
	if(rozmiar > 1)
	{
		aktualna->poprzednia = NULL;
		pierwsza = aktualna;
	}
	else
	{
		aktualna = NULL;
		pierwsza = NULL;
		ostatnia = NULL;
	}

	// Dekrementuj rozmiar
	rozmiar--;
}

void Lista::usunOstatni()
{
    if(pierwsza==NULL)
    {
        cout << "Lista jest pusta."<<endl;
        return;
    }
	// Przypisz przedostatni element jako aktualny
	aktualna = ostatnia->poprzednia;

	// Usuñ ostatni element
	delete ostatnia;

	// Sprawdzenie czy w liœcie s¹ inne elementy
	// Je¿eli tak, przypisz aktualny element jako pierwsze
	// Je¿eli nie, nullujemy elementy listy
	if(rozmiar > 1)
	{
		aktualna->nastepna = NULL;
		ostatnia = aktualna;
	}
	else
	{
		aktualna = NULL;
		pierwsza = NULL;
		ostatnia = NULL;
	}

	// Dekrementuj rozmiar
	rozmiar--;
}

void Lista::usunKtorykolwiek(int pozycja)
{
	//Sprawdzenie czy na liœcie istnieje dana pozycja
	if(pozycja < 0 || pozycja >= rozmiar)
	{
		//cout << "Lista nie posiada danej pozycji [" << pozycja << "]" << endl;
		return;
	}

	//Sprawdzenie czy dana pozycja jest pierwsza
	if(pozycja == 0)
	{
		usunPierwszy();
		return;
	}

	// Sprawdzenie czy dana pozycja jest ostatnia
	if(pozycja == rozmiar - 1)
	{
		usunOstatni();
		return;
	}

	// Sprawdzenie w której po³owie listy znajduje siê wybrany element
	if(pozycja < rozmiar / 2)
	{
		//Przypisz za aktualny element pierwszy
		aktualna = pierwsza;

		//Przesuñ aktualna do danej pozycji
		for(int i = 1; i < pozycja; ++i)
		{
			aktualna = aktualna->nastepna;
		}
	}
	else
	{
		// Przypisz za aktualny element ostatni
		aktualna = ostatnia;

		// Przesuñ aktualna do danej pozycji
		for (int i = 0; i < rozmiar - pozycja; ++i)
		{
			aktualna = aktualna->poprzednia;
		}
	}

	// Stwórz nowy wskaźnik na element do usunięcia
	Krawedz* k = aktualna->nastepna;
	aktualna->nastepna=k->nastepna;
	aktualna->nastepna->poprzednia=aktualna;

	delete k;

	// Dekrementuj rozmiar
	rozmiar--;
}

/*
bool Lista::sprawdzCzyIstnieje(Krawedz* k)
{
	// Je¿eli lista jest pusta, zwróæ false z automatu
	if(rozmiar == 0)
	{
		return false;
	}

	// Przypisz pierwszy element do aktualnego
	aktualna = pierwsza;

	// Przeszukaj listê pod k¹tem wartoœci
	for(int i = 0; i < rozmiar; i++)
	{
		if(aktualna->wartosc == wartosc)
		{
			//cout << "Wartoœæ znaleziona na pozycji [" << i << "]" << endl;
			return true;
		}

		aktualna = aktualna->nastepna;
	}

	// Zwróæ false je¿eli wartoœæ nie znalaz³a siê na liœcie
	//cout << "Nie znaleziono wartoœci w liœcie" << endl;
	return false;
}
*/
void Lista::wydrukujListe()
{
    cout << endl<< "Lista..."<<endl;
	// Przypisz do aktualna pierwsza
	aktualna = pierwsza;

	for(int i = 0; i < rozmiar; i++)
	{
		cout << *aktualna;

		// Przypisz kolejny element listy jako aktualn
		aktualna = aktualna->nastepna;
	}
}

void Lista::wydrukujListeSasiedztwa()
{
	// Przypisz do aktualna pierwsza
	aktualna = pierwsza;

	for(int i = 0; i < rozmiar; i++)
	{
		cout << *aktualna;

		// Przypisz kolejny element listy jako aktualn
		aktualna = aktualna->nastepna;
	}
	cout << endl;
}

/*
void Lista::sortList()
{
    for(int i = 0; i < rozmiar; i++)
    {
        for(int j = 1; j < n - 1; j++)
            if(tab[j-1] > tab[j])
            {
                Krawe
            }
    }
}
*/

Krawedz* Lista::zwrocElement(int pozycja)
{
    aktualna = pierwsza;
    for(int i = 0; i < pozycja; i++)
        aktualna= aktualna->nastepna;
    return aktualna;
}

Lista& Lista::operator=(const Lista l)
{
    this->pierwsza = l.pierwsza;
    this->aktualna = l.aktualna;
    this->ostatnia = l.ostatnia;
    this->rozmiar = l.rozmiar;

    return* this;
}

void Lista::quickSort()
{
    Krawedz* wartownikPrzod = new Krawedz(-1,-1,0);
    Krawedz* wartownikTyl = new Krawedz(-1,-1,0);
    dodajNaPoczatek(wartownikPrzod);
    dodajNaKoniec(wartownikTyl);
    podzial(pierwsza,ostatnia);
    usunPierwszy();
    usunOstatni();
}

void Lista::podzial(Krawedz* lw, Krawedz* pw)
{
    Krawedz* p,* i,* j;

    p = lw->nastepna;
    i = p->nastepna;
    if(i != pw)
    {
        do
        {
            j = i;
            i = i->nastepna;
            if(j->waga < p->waga)
            {
                j->poprzednia->nastepna = j->nastepna;
                j->nastepna->poprzednia = j->poprzednia;
                j->nastepna = p;
                j->poprzednia = p->poprzednia;
                p->poprzednia = j;
                j->poprzednia->nastepna = j;
            }
        } while(i != pw);

        if(lw->nastepna != p)
            podzial(lw, p);
        if(p->nastepna != pw)
            podzial(p, pw);
    }
}
