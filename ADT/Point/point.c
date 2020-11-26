#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "boolean.h"

void makeKoordinat(Koordinat *P, int x, int y)
{
  absis(*P) = x;
  ordinat(*P) = y;
}

void geserKanan(Koordinat *P)
{
  absis(*P) += 1;
}
void geserKiri(Koordinat *P)
{
  absis(*P) -= 1;
}
void geserAtas(Koordinat *P)
{
  ordinat(*P) -= 1;
}
void geserBawah(Koordinat *P)
{
  ordinat(*P) += 1;
}
boolean isKoordinatSama(Koordinat P1, Koordinat P2){
  return (absis(P1) == absis(P2)) && (ordinat(P1) == ordinat(P2));
}

//print Wahana
void printWahana(Koordinat P);