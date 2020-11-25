#include <stdio.h>
#include "pemain.h"
#include "point.h"
#include "matriks.h"
#include "map.h"

void makePemain(Pemain *P, int uang, char* nama, Koordinat posisiPemain, JAM jamPemain){
  nama(*P) = nama;
  uang(*P) = uang;
  posisiPemain(*P) = posisiPemain;
  jamPemain(*P) = jamPemain;
}

void setKoordinatPemain(Pemain *P, char input, MATRIKS M){
  switch (input)
  {
  case 'w':
    if(strcmp(Elmt(M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1 ), '-') == 0){
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserAtas(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  case 'a':
    if(strcmp(Elmt(M, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P))), '-') == 0){
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserKiri(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  case 's':
    if(strcmp(Elmt(M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1 ), '-') == 0){
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserBawah(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  case 'd':
    if(strcmp(Elmt(M, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P))), '-') == 0){
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserKanan(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  default:
    break;
  }  
}