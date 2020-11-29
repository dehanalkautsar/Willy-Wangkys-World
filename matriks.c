#include "matriks.h"
#include <stdio.h>

indeks GetFirstIdxBrs(MATRIKS M)
{
    return BrsMin;
}
indeks GetFirstIdxKol(MATRIKS M)
{
    return KolMin;
}
indeks GetLastIdxBrs(MATRIKS M)
{
    return (NBrsEff(M) - 1);
}
indeks GetLastIdxKol(MATRIKS M)
{
    return (NKolEff(M) - 1);
}
