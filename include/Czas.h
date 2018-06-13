#ifndef CZAS_H
#define CZAS_H

#include <chrono>
#include <windows.h>
#include <iostream>
#include <inttypes.h>

using namespace std::chrono;

class Czas
{
    public:
	high_resolution_clock::time_point czasPoczatek;
	high_resolution_clock::time_point czasKoniec;

    void StartCounter();

    double GetCounter();

	long czasOperacji();

	void dzialaCzyNieDziala();

	void czasStart();

	void czasStop();
};

#endif // CZAS_H
