#ifndef pemain_H
#define pemain_H

#include <stdio.h>
#include "../Point/point.h"

typedef struct
{
  char* nama;
  int uang;
  Koordinat posisiPemain;
} Pemain;

#define nama(p) (p).nama
#define uang(p) (p).uang
#define posisiPemain(p) (p).posisiPemain

Pemain makePemain(int uang, char* nama, Koordinat posisiPemain);
void setKoordinatPemain(Pemain *p);

#endif