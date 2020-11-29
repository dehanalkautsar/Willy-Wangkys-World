#ifndef matriks_h
#define matriks_h

#include <stdio.h>
#include "boolean.h"

#define BrsMin 0
#define BrsMax 50
#define KolMin 0
#define KolMax 50

typedef int indeks;
typedef char ElType;
typedef struct
{
    ElType Mem[BrsMax + 1][KolMax + 1];
    int NBrsEff;
    int NKolEff;
} MATRIKS;

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M, i, j) (M).Mem[(i)][(j)]

indeks GetFirstIdxBrs(MATRIKS M);

indeks GetFirstIdxKol(MATRIKS M);

indeks GetLastIdxBrs(MATRIKS M);

indeks GetLastIdxKol(MATRIKS M);

#endif
