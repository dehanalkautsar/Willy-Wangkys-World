#ifndef _WAHANA_MAP_h
#define _WAHANA_MAP_h

// #include <stdio.h>
#include <stdio.h>
// #include "../Matriks/matriks.h"
// #include "../Wahana/bintree_wahana.h"
#include "../Point/point.h"

#define IdxMaxWahana 49
#define IdxMinWahana 0
#define IdNil -1


typedef struct tWahanaMap
{
  //report
  int IdWahana;
  Koordinat KoordinatWahana;
  int Occupancy;
  boolean statusWahana;
  // details office
  int penghasilan;  // daily
  int totalPenghasilan; // all time
  int totalOccupancy; //all time

} WahanaMap;




#endif