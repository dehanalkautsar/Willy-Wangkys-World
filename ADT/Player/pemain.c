#include <stdio.h>
#include <string.h>
#include "pemain.h"
#include "../Wahana/bintree_wahana.h"


//(Pemain *P, int uang, char *nama, Koordinat posisiPemain, JAM jamPemain);
void makePemain(Pemain *P, int uang, char *nama, Material Database_Material[])
{
  strcpy(nama(*P),nama);
  uang(*P) = uang;
  makeKoordinat(&posisiPemain(*P),1,1);
  jamPemain(*P) = MakeJAM(21,0);
  for (int i = 0; i < 5; i++) {
    materialPemain(*P,i) = CopyMaterial(Database_Material[i]);
    Kuantitas_Material(materialPemain(*P,i)) = 0;
  }
  currentMap(*P) = 1;
}

void setKoordinatPemain(Pemain *P, char input, Map M)
{
  switch (input)
  {
  case 'w':
    if (Elmt(mapMatriks(M), absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1) == '-')
    {
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserAtas(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  case 'a':
    if (Elmt(mapMatriks(M), absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P))) == '-')
    {
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserKiri(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  case 's':
    if (Elmt(mapMatriks(M), absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1) == '-')
    {
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserBawah(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  case 'd':
    if (Elmt(mapMatriks(M), absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P))) == '-')
    {
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), '-');
      geserKanan(&posisiPemain(*P));
      updateMap(&M, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)), 'P');
    }
    break;
  default:
    break;
  }
}