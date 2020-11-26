#ifndef map_h
#define map_h

#include <stdio.h>
#include "../Matriks/matriks.h"
#include "../Wahana/bintree_wahana.h"
#include "../Point/point.h"

#define IdxMaxWahana 49
#define IdxMinWahana 0
#define IdNil -1

typedef struct WahanaMap
{
  int IdWahana;
  Koordinat KoordinatWahana;
  int Occupancy;
} WahanaMap;

typedef struct Map
{
  MATRIKS mapMatriks;
  WahanaMap listWahana[IdxMaxWahana + 1]; //[<id, koordinat>, <id, koordinat>, ...]
} Map;



#define mapMatriks(M) (M).mapMatriks
#define listWahana(M, i) (M).listWahana[i]
#define infoIdWahana(M, i) (M).listWahana[i].IdWahana
#define infoKoordinatWahana(M, i) (M).listWahana[i].KoordinatWahana
#define infoOccupancy(M, i) (M).listWahana[i].Occupancy

void makeMap(Map *M, int row, int column, int mapIndex);
void printMap(Map M);
void updateMap(Map *M, int x, int y, char input);
WahanaMap wahanaTerdekat(Map M, Koordinat PlayerPosition);
int totalWahana(Map M);
boolean checkIsAvailablePoint(Map M, int x, int y);
int searchElmtListWahana(Map M, int idWahana);

#endif