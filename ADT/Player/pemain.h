#ifndef pemain_H
#define pemain_H

#include <stdio.h>
#include "../Point/point.h"
#include "../Jam/jam.h"
#include "../Matriks/matriks.h"

typedef struct
{
  char* nama;
  int uang;
  JAM jamPemain;
  Koordinat posisiPemain;
} Pemain;

#define nama(P) (P).nama
#define uang(P) (P).uang
#define posisiPemain(P) (P).posisiPemain
#define jamPemain(P) (P).jamPemain

void makePemain(Pemain *P, int uang, char* nama, Koordinat posisiPemain, JAM jamPemain);
void setKoordinatPemain(Pemain *P, char input, MATRIKS M);

#endif