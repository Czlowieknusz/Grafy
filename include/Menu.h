#ifndef MENU_H
#define MENU_H

#include "IncidentMatrix.h"
#include "NeighbourList.h"

class Menu
{
    public:
        Menu();
        ~Menu();
        int opcja;

        void AskForOption(IncidentMatrix&, NeighbourList&, NeighbourList&);
};

#endif // MENU_H
