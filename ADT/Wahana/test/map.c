#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "map.h"
#include "matriks.h"
#include "point.h"

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
    for (int i = 0; i <= IdxMax; i++)
    {
        listWahana(*M, i) = Nil;
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
    while (listWahana(M, i) != Nil)
    {
        i++;
    }
    return i;
}

void wahanaTerdekat(Map M, int x, int y, char *namaWahana[4])
{
    int totalNamaWahana = 0;
    int i = 0;
    while (totalNamaWahana < 4 && i < totalWahana(M))
    {
        if (absis(infoKoordinatWahana(M, i)) == (x + 1) && ordinat(infoKoordinatWahana(M, i)) == y)
        {
            namaWahana[totalNamaWahana] = Nama_Wahana(infoElementWahana(M, i));
            totalNamaWahana++;
        }
        else if (absis(infoKoordinatWahana(M, i)) == (x - 1) && ordinat(infoKoordinatWahana(M, i)) == y)
        {
            namaWahana[totalNamaWahana] = Nama_Wahana(infoElementWahana(M, i));
            totalNamaWahana++;
        }
        else if (absis(infoKoordinatWahana(M, i)) == (x) && ordinat(infoKoordinatWahana(M, i)) == (y + 1))
        {
            namaWahana[totalNamaWahana] = Nama_Wahana(infoElementWahana(M, i));
            totalNamaWahana++;
        }
        else if (absis(infoKoordinatWahana(M, i)) == (x) && ordinat(infoKoordinatWahana(M, i)) == (y - 1))
        {
            namaWahana[totalNamaWahana] = Nama_Wahana(infoElementWahana(M, i));
            totalNamaWahana++;
        }
        i++;
    }
}

void updateMap(Map *M, int x, int y, char input)
{
    Elmt(mapMatriks(*M), x, y) = input;
}
