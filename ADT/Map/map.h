#ifndef map_h
#define map_h

#include <stdio.h>
#include "../Matriks/matriks.h"

void printMap(MATRIKS M);
void updateMap(MATRIKS *M, int x, int y, char input);
void makeMap(MATRIKS *M, int row, int column, int mapIndex);

#endif