#ifndef map_h
#define map_h

#include <stdio.h>
#include "../Matriks/matriks.h"
#include "../Wahana/bintree_wahana.h"

typedef struct
{
  MATRIKS mapMatriks;
  ListWahana mapListWahana; 
} Map;

typedef struct ElementWahana *address;

typedef struct {
  address first;
} ListWahana;

typedef struct {
  InfoWahana infoWahana;
  address next;
} ElementWahana;

typedef struct {
  Elmt_Wahana ElementWahana;
  Koordinat KoordinatWahana;
} InfoWahana;

#define infoElementWahana(P) (P)->infoWahana.ElementWahana
#define infoKoordinatWahana(P) (P)->infoWahana.KoordinatWahana
#define next(P) (P)->next
#define first(L) ((L).First)

#endif