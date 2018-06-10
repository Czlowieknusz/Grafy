#ifndef LISTA_H
#define LISTA_H

#include "Krawedz.h"

class Lista
{
public:
	   	int rozmiar;

	   	Lista();

	   	~Lista();

	   	Krawedz* pierwsza;
	   	Krawedz* ostatnia;
	   	Krawedz* aktualna;

	   	void dodajNaPoczatek(Krawedz*);

	   	void dodajGdziekolwiek(Krawedz*, int);

	   	void dodajNaKoniec(Krawedz*);

	   	void wydrukujListe();

	   	void wydrukujListeSasiedztwa();

	   	void usunPierwszy();

	   	void usunOstatni();

	   	void usunKtorykolwiek(int);

	   	/// Quicksort
	   	void quickSort();

	   	/// Metoda pomocnicza do quicksorta
	   	void podzial(Krawedz*, Krawedz*);

	   	Krawedz* zwrocElement(int);

        Lista& operator = (Lista l);

	   	//bool sprawdzCzyIstnieje(Krawedz*);
};

#endif // LISTA_H
