#include "elementLista.h"

class ListaInt
{
public:
	   	int rozmiar;

	   	ListaInt();

	   	~ListaInt();

	   	ElementListy* pierwszyElement;
	   	ElementListy* ostatniElement;
	   	ElementListy* aktualnyElement;

	   	void dodajNaPoczatek(int wartosc);

	   	void dodajGdziekolwiek(int wartosc, int pozycja);

	   	void dodajNaKoniec(int watosc);

	   	int zwrocElement(int pozycja);

	   	void wydrukujListe();

	   	void usunPierwszy();

	   	void usunOstatni();

	   	void usunKtorykolwiek(int);

	   	bool sprawdzCzyIstnieje(int wartosc);
};
