#ifndef map_h
#define map_h

#include <stdio.h>
#include "../Matriks/matriks.h"
#include "../Wahana/bintree_wahana.h"

typedef struct{
  Elmt_Wahana Wahana;
  Koordinat KoordinatWahana;
  address Next;
} Elmt_List_Wahana;


typedef struct {
    address First;

} List_Wahana

typedef struct
{
  MATRIKS Peta;
  List_Wahana L_Wahana;
} Map;




Peta.Wahana[0].Elmt_Wahana
Peta.Wahana[1].KoordinatWahana



void printMap(Peta M);
