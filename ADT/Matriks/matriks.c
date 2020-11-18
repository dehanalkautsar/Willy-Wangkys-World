#include "matriks.h"
#include <stdio.h>

void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    for(int i = 0; i < NB; i++) {
      for(int j = 0; j < NK; j++) {
        Elmt(*M, i, j) = "-";
      }
    }
}

indeks GetFirstIdxBrs (MATRIKS M)
{
    return  BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
{
    return (NBrsEff(M)-1);
}
indeks GetLastIdxKol (MATRIKS M)
{
    return (NKolEff(M)-1);
}

void UpdateMATRIKS (MATRIKS *M, int x, int y, char input) {
  Elmt(*M, x, y) = input;
}

int NBElmt (MATRIKS M)
{
    return (NBrsEff(M)*NKolEff(M));
}
