#ifndef point_h
#define point_h

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"

typedef struct {
    //wahana *wahana;
    int X; /* absis   */
    int Y; /* ordinat */
} Koordinat;

/* *** Notasi Akses: Selektor POINT *** */
#define absis(P) (P).X
#define ordinat(P) (P).Y
//#define wahana(C) (P).wahana

void geserKanan(Koordinat *P);
void geserKiri(Koordinat *P);
void geserAtas(Koordinat *P);
void geserBawah(Koordinat *P);

// Make Wahana
//koordinatWahana *makeKoordinatWahana(wahana *wahana, int row, int kol);

//print Wahana
void printWahana(Koordinat P);



#endif /* point_h */