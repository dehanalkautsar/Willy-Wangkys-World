#ifndef map_h
#define map_h

#include <stdio.h>
#include "../Matriks/matriks.h"
#include "../Wahana/bintree_wahana.h"

#define IdxMax 49
#define IdxMin 0
#define Nil NULL


typedef struct
{
  MATRIKS mapMatriks;
  Wahana listWahana[IdxMax + 1]; 
} Map;

typedef struct {
  Elmt_Wahana ElementWahana;
  Koordinat KoordinatWahana;
} Wahana;

#define mapMatriks(M) (M).mapMatriks
#define listWahana(M, i) (M).listWahana[i]
#define infoElementWahana(M, i) (M).listWahana[i].ElementWahana
#define infoKoordinatWahana(M, i) (M).listWahana[i].KoordinatWahana

void makeMap(Map *M, int row, int column, int mapIndex);
void printMap(Map M);
void updateMap(Map *M, int x, int y, char input);
void wahanaTerdekat(Map M, int x, int y, char* namaWahana[4]);
int totalWahana(Map M);

#endif