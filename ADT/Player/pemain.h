#ifndef pemain_H
#define pemain_H

#include <stdio.h>
#include "../Point/point.h"
#include "../Jam/jam.h"
#include "../Map/map.h"

/*  Kamus Umum */
#define IdxMax 4
/* Indeks maksimum array */
#define IdxMin 0

typedef struct Material
{
  int ID;
  char NamaMaterial[32];
  int Harga;
  int Kuantitas;
} Material;

typedef struct
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
#define ID_Material(P) (P).ID
#define Nama_Material(P) (P).NamaMaterial
#define Harga_Material(P) (P).Harga
#define Kuantitas_Material(P) (P).Kuantitas

void makePemain(Pemain *P, int uang, char *nama, Koordinat posisiPemain, JAM jamPemain);
void setKoordinatPemain(Pemain *P, char input, Map M);

#endif