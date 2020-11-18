#ifndef point_h
#define point_h

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"

typedef struct {
    //wahana *wahana;
    int X; /* absis   */
    int Y; /* ordinat */
} koordinatWahana;

/* *** Notasi Akses: Selektor POINT *** */
#define Kol(P) (P).X
#define Brs(P) (P).Y
//#define wahana(C) (P).wahana

// Make Wahana
//koordinatWahana *makeKoordinatWahana(wahana *wahana, int row, int kol);

//print Wahana
void printWahana(koordinatWahana P);



#endif /* point_h */