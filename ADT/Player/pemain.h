#ifndef pemain_H
#define pemain_H

#include <stdio.h>
#include "../Point/point.h"
#include "../Jam/jam.h"
#include "../Matriks/matriks.h"

/*  Kamus Umum */
#define IdxMax 4
/* Indeks maksimum array */
#define IdxMin 0

typedef struct Material
{
  char* NamaMaterial;
  int Kuantitas;
}Material;

typedef struct
{
  char* nama;
  int uang;
  JAM jamPemain;
  Koordinat posisiPemain;
  Material ArrMaterial[IdxMax+1];
} Pemain;

#define nama(P) (P).nama
#define uang(P) (P).uang
#define posisiPemain(P) (P).posisiPemain
#define jamPemain(P) (P).jamPemain


void makePemain(Pemain *P, int uang, char* nama, Koordinat posisiPemain, JAM jamPemain);
void setKoordinatPemain(Pemain *P, char input, MATRIKS M);

#endif