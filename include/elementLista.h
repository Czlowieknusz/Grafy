#ifndef ELEMENTLISTA_H
#define ELEMENTLISTA_H


class ElementListy
{
	public:
		ElementListy* nastepny;
		ElementListy* poprzedni;
		int wartosc;

		ElementListy(int, ElementListy*, ElementListy*);
};

#endif // ELEMENTLISTA_H
