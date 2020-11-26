#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "map.h"
#include "boolean.h"
#include "../Matriks/matriks.h"
#include "../Point/point.h"

void makeMap(Map *M, int row, int column, int mapIndex)
{
    NBrsEff(mapMatriks(*M)) = row;
    NKolEff(mapMatriks(*M)) = column;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == 0 || i == (row - 1) || j == 0 || j == (column - 1))
            {
                Elmt(mapMatriks(*M), i, j) = '*';
            }
            else
            {
                Elmt(mapMatriks(*M), i, j) = '-';
            }
        }
    }

    int randomPosition1 = rand() % (row - 2) + 1;
    int randomPosition2 = rand() % (column - 2) + 1;

    switch (mapIndex)
    {
    case 1:
        updateMap(M, randomPosition1, column - 1, '>');
        updateMap(M, row - 1, randomPosition2, 'v');
        break;
    case 2:
        updateMap(M, randomPosition1, 0, '<');
        updateMap(M, row - 1, randomPosition2, 'v');
        break;
    case 3:
        updateMap(M, randomPosition1, 0, '<');
        updateMap(M, 0, randomPosition2, '^');
        break;
    case 4:
        updateMap(M, randomPosition1, column - 1, '>');
        updateMap(M, 0, randomPosition2, '^');
        break;
    default:
        break;
    }

    // Inisialisasi list
    for (int i = 0; i <= IdxMaxWahana; i++)
    {
        Koordinat P;
        makeKoordinat(&P, 0, 0);
        infoKoordinatWahana(*M, i) = P;
        infoIdWahana(*M, i) = -1;
        infoOccupancy(*M,i) = 0;
    }
}

void printMap(Map M)
{
    for (int i = GetFirstIdxBrs(mapMatriks(M)); i <= GetLastIdxBrs(mapMatriks(M)); i++)
    {
        for (int j = GetFirstIdxKol(mapMatriks(M)); j <= GetLastIdxKol(mapMatriks(M)); j++)
        {
            printf("%c", Elmt(mapMatriks(M), i, j));
        }
        printf("\n");
    }
}

int totalWahana(Map M)
{
    int i = 0;
    while (infoIdWahana(M, i) != -1)
    {
        i++;
    }
    return i;
}

WahanaMap wahanaTerdekat(Map M, Koordinat PlayerPosition)
{
    /* Prioritas (1. Atas, 2.Kanan, 3.Bawah, 4.Kiri) */

    int i, x, y;
    WahanaMap W;
    boolean found;

    i = 0;
    x = absis(PlayerPosition);
    y = ordinat(PlayerPosition);
    found = false;


    while (i < totalWahana(M) && !found)
    {
        if (absis(infoKoordinatWahana(M, i)) == x && ordinat(infoKoordinatWahana(M, i)) == (y + 1))
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahana(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        else if (absis(infoKoordinatWahana(M, i)) == (x + 1) && ordinat(infoKoordinatWahana(M, i)) == y)
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahana(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        else if (absis(infoKoordinatWahana(M, i)) == x && ordinat(infoKoordinatWahana(M, i)) == (y - 1))
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahana(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        else if (absis(infoKoordinatWahana(M, i)) == (x - 1) && ordinat(infoKoordinatWahana(M, i)) == y)
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahana(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        i++;
    }

    if(!found) {
        Koordinat P;
        makeKoordinat(&P, 0, 0);

        W.IdWahana = -1;
        W.KoordinatWahana = P;
        W.Occupancy = 0;
    }

    return W;
}

void updateMap(Map *M, int x, int y, char input)
{
    Elmt(mapMatriks(*M), x, y) = input;
}

boolean checkIsAvailablePoint(Map M, int x, int y) {
  return Elmt(mapMatriks(M), x, y) == '-';
}