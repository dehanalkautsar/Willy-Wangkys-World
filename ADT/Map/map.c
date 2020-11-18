#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "map.h"
#include "../Matriks/matriks.h"

void makeMap(MATRIKS *M, int row, int column, int mapIndex)
{
    NBrsEff(*M) = row;
    NKolEff(*M) = column;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == 0 || i == (row - 1) || j == 0 || j == (column - 1))
            {
                Elmt(*M, i, j) = '*';
            }
            else
            {
                Elmt(*M, i, j) = '-';
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
}

void printMap(MATRIKS M)
{
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            printf("%c", Elmt(M, i, j));
        }
        printf("\n");
    }
}

void updateMap(MATRIKS *M, int x, int y, char input)
{
    Elmt(*M, x, y) = input;
}
