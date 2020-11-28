#ifndef _MAP_h
#define _MAP_h

#include <stdio.h>
#include "wahana_map.h"
#include "../Matriks/matriks.h"
// #include "../Wahana/bintree_wahana.h"
#include "../Point/point.h"
#include "../Player/pemain.h"

#define IdxMaxWahana 49
#define IdxMinWahana 0
#define IdNil -1

typedef struct tMap
{
  MATRIKS mapMatriks;
  WahanaMap listWahana[IdxMaxWahana + 1]; 
} Map;

#define mapMatriks(M) (M).mapMatriks
#define listWahana(M, i) (M).listWahana[i]
#define infoIdWahana(M, i) (M).listWahana[i].IdWahana
#define infoKoordinatWahanaMap(M, i) (M).listWahana[i].KoordinatWahana
#define infoOccupancy(M, i) (M).listWahana[i].Occupancy
#define infoStatusWahana(M, i) (M).listWahana[i].statusWahana
#define infoTotalOccupancy(M, i) (M).listWahana[i].totalOccupancy
#define infoPenghasilan(M, i) (M).listWahana[i].penghasilan
#define infoTotalPenghasilan(M, i) (M).listWahana[i].totalPenghasilan

void makeMap(Map *M, char* nama_file, int mapIndex);
void printMap(Map M, Pemain P);
void updateMap(Map *M, int x, int y, char input);
WahanaMap wahanaTerdekat(Map M, Koordinat PlayerPosition);
int totalWahana(Map M);
boolean checkIsAvailablePoint(Map M, int x, int y);
int searchElmtListWahana(Map M, int idWahana);
int searchKoordinatElmtListWahana(Map M, Koordinat Koordinat);  //mengembalikan indeks array listwahana dengan koordinat yang sesuai


#endif