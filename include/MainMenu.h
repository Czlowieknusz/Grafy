#ifndef MAINMENU_H
#define MAINMENU_H

#include "IncidentMatrix.h"
#include "NeighbourList.h"

class MainMenu
{
    public:
        int opcja;

        NeighbourList nLSkier;
        NeighbourList nLNieSkier;
        IncidentMatrix iM;
        MainMenu();
        virtual ~MainMenu();
        void AskForOption();

    protected:

    private:
};

#endif // MAINMENU_H
