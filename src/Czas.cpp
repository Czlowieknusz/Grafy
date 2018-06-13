#include "Czas.h"
#include <chrono>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace std::chrono;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void Czas::StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency Failed!" << endl;

    PCFreq = double(li.QuadPart)/1.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double Czas::GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart)/PCFreq;
}
// Funkcja zapisuje do zmiennej czasPoczatek bie¿¹cy czas
void Czas::czasStart()
{
	czasPoczatek = high_resolution_clock::now();
}

// Funkcja zapisuje do zmiennej czasKoniec bie¿¹cy czas
void Czas::czasStop()
{
	czasKoniec = high_resolution_clock::now();
}

// Funkcja zwraca ró¿nicê miêdzy czasKoniec i czasPocz¹tek
long Czas::czasOperacji()
{
	return duration_cast<nanoseconds>(Czas::czasKoniec - Czas::czasPoczatek).count()/1000000;
}
