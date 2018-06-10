#include "grafGenerator.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

grafGenerator::grafGenerator()
{
}

grafGenerator::~grafGenerator()
{
}

void grafGenerator::generujDane(double stosunek)
{
    srand(time(NULL));
    int iloscWierzcholkow = rand()%80 + 20;
    cout << "ilWIerz = " << iloscWierzcholkow<< "; stosunek = " << stosunek <<endl;
    int iloscKrawedzi = iloscWierzcholkow*stosunek;
    cout << "iloscKraw = " << iloscKrawedzi << endl;

    return( 0 );


}
