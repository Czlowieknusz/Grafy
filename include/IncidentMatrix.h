#ifndef INCIDENTMATRIX_H
#define INCIDENTMATRIX_H


class IncidentMatrix
{
    public:
        IncidentMatrix();
        ~IncidentMatrix();
        int rozmiar, iloscKrawedzi;
        int** macierz;
        int* tablicaWag;

        void drukujMacierz();
};

#endif // INCIDENTMATRIX_H
