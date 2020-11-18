#include <stdio.h>
#include <stdlib.h>
#include "point.h"

void geserKanan(Koordinat *P){
  absis(*P) += 1;
}
void geserKiri(Koordinat *P) {
  absis(*P) -= 1;
}
void geserAtas(Koordinat *P) {
    ordinat(*P) -= 1;
}
void geserBawah(Koordinat *P) {
    ordinat(*P) += 1;
}

//print Wahana
void printWahana(Koordinat P);