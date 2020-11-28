#ifndef _PEMAIN_H
#define _PEMAIN_H

#include <stdio.h>
#include "material.h"
#include "../Point/point.h"
#include "../Jam/jam.h"
#include "../Map/wahana_map.h"
#include "../Map/map.h"
// #include "../Wahana/bintree_wahana.h"


/*  Kamus Umum */
#define IdxMax 4
/* Indeks maksimum array */
#define IdxMin 0

// typedef struct Material
// {
//   int ID;
//   char NamaMaterial[32];
//   int Harga;
//   int Kuantitas;
// } Material;

typedef struct Pemain
{
  char nama[32];
  int uang;
  JAM jamPemain;
  Koordinat posisiPemain;
  Material ArrMaterial[5];
  int Current_Map;
} Pemain;

#define nama(P) (P).nama
#define uang(P) (P).uang
#define posisiPemain(P) (P).posisiPemain
#define jamPemain(P) (P).jamPemain
#define materialPemain(P,i) (P).ArrMaterial[i]
#define currentMap(P) (P).Current_Map

/* MAKRO ADT MATERIAL */
// #define ID_Material(M) (M).ID
// #define Nama_Material(M) (M).NamaMaterial
// #define Harga_Material(M) (M).Harga
// #define Kuantitas_Material(M) (M).Kuantitas

void makePemain(Pemain *P, int uang, char *nama,  Material Database_Material[]);
void setKoordinatPemain(Pemain *P, char input, Map M);

#endif