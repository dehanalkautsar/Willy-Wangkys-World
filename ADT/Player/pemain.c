#include <stdio.h>
#include <string.h>
#include "pemain.h"
#include "../Wahana/bintree_wahana.h"


//(Pemain *P, int uang, char *nama, Koordinat posisiPemain, JAM jamPemain);
void makePemain(Pemain *P, int uang, char *nama, Material Database_Material[])
{
  strcpy(nama(*P),nama);
  uang(*P) = uang;
  makeKoordinat(&posisiPemain(*P), 1, 1);
  jamPemain(*P) = MakeJAM(21,0);
  for (int i = 0; i < 5; i++) {
    materialPemain(*P,i) = CopyMaterial(Database_Material[i]);
    Kuantitas_Material(materialPemain(*P,i)) = 0;
  }
  currentMap(*P) = 1;
}

void setKoordinatPemain(Pemain *P, char input)
{
  switch (input)
  {
  case 'w':
      geserAtas(&posisiPemain(*P));
    break;
  case 'a':
      geserKiri(&posisiPemain(*P));
    break;
  case 's':
      geserBawah(&posisiPemain(*P));
    break;
  case 'd':
      geserKanan(&posisiPemain(*P));
    break;
  default:
    break;
  }
}