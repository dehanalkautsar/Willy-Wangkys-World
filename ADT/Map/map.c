#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "map.h"
// #include "../Player/pemain.h"



void makeMap(Map *M, char* nama_file, int mapIndex)
{
    // Find row and column
    FILE *fp;
    char buff[256];
    int row, column, i, j;

    fp = fopen(nama_file, "r");


    // while (fgets(buff, sizeof(buff), fp))
    // {
    //     while (row == 0 && (buff[column] != '\0' && buff[column] != '\n'))
    //     {
    //         column++;
    //     }
    //     row++;
    // }

    // input buff to matrix
    i = 0;
    j = 0;
    row = 0;
    column = 0;
    while(fgets(buff, sizeof(buff), fp)){
        while(buff[j] != '\0' && buff[j] != '\n'){
            if(i == 0) {
                column++;
            }
            Elmt(mapMatriks(*M), i, j) = buff[j];
            j++;
        }
        i++;
        j = 0;
    }
    row = i;

    NBrsEff(mapMatriks(*M)) = row;
    NKolEff(mapMatriks(*M)) = column;
    

    // Inisialisasi list
    for (int i = 0; i <= IdxMaxWahana; i++)
    {
        Koordinat P;
        makeKoordinat(&P, 0, 0);
        infoKoordinatWahanaMap(*M, i) = P;
        infoIdWahana(*M, i) = -1;
        infoOccupancy(*M,i) = 0;
        infoStatusWahana(*M,i) = true;
        infoTotalOccupancy(*M,i) = 0;
        infoTotalPenghasilan(*M,i) = 0;
        infoPenghasilan(*M,i) = 0;
    }
}

void printMap(Map M, Pemain P)
{
    for (int i = GetFirstIdxBrs(mapMatriks(M)); i <= GetLastIdxBrs(mapMatriks(M)); i++)
    {
        for (int j = GetFirstIdxKol(mapMatriks(M)); j <= GetLastIdxKol(mapMatriks(M)); j++)
        {
            Koordinat current;
            makeKoordinat(&current, i, j);
            
            if(isKoordinatSama(current, posisiPemain(P))){
                printf("P");
            }else if(searchKoordinatElmtListWahana(M, current) != -1) {
                printf("W");
            }else{
                printf("%c", Elmt(mapMatriks(M),i,j));
            }
            
        }
        printf("\n");
    }
}

int totalWahana(Map M)
{
    int i = 0;
    while (infoIdWahana(M, i) != -1)
    {
        i++;
    }
    return i;
}

WahanaMap wahanaTerdekat(Map M, Koordinat PlayerPosition)
{
    /* Prioritas (1. Atas, 2.Kanan, 3.Bawah, 4.Kiri) */

    int i, x, y;
    WahanaMap W;
    boolean found;

    i = 0;
    x = absis(PlayerPosition);
    y = ordinat(PlayerPosition);
    found = false;


    while (i < totalWahana(M) && !found)
    {
        if (absis(infoKoordinatWahanaMap(M, i)) == x && ordinat(infoKoordinatWahanaMap(M, i)) == (y + 1))
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        else if (absis(infoKoordinatWahanaMap(M, i)) == (x + 1) && ordinat(infoKoordinatWahanaMap(M, i)) == y)
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        else if (absis(infoKoordinatWahanaMap(M, i)) == x && ordinat(infoKoordinatWahanaMap(M, i)) == (y - 1))
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        else if (absis(infoKoordinatWahanaMap(M, i)) == (x - 1) && ordinat(infoKoordinatWahanaMap(M, i)) == y)
        {
            W.IdWahana = infoIdWahana(M, i);
            W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
            W.Occupancy = infoOccupancy(M, i);
            found = true;
        }
        i++;
    }

    if(!found) {
        Koordinat P;
        makeKoordinat(&P, 0, 0);

        W.IdWahana = -1;
        W.KoordinatWahana = P;
        W.Occupancy = 0;
    }

    return W;
}

void updateMap(Map *M, int x, int y, char input)
{
    Elmt(mapMatriks(*M), x, y) = input;
}

boolean checkIsAvailablePoint(Map M, int x, int y) {
    return Elmt(mapMatriks(M), x, y) == '-';
}

int searchElmtListWahana(Map M, int idWahana){
    int i = 0;
    boolean status = false;

    while (i<=IdxMaxWahana && !status){
        if (infoIdWahana(M,i) == idWahana){
            status = true;
        }else{
            i++;
        }
    }

    if (status){
        return i;
    }else{
        return -1;
    }
}
int searchKoordinatElmtListWahana(Map M, Koordinat Koordinat){  //mengembalikan indeks array listwahana dengan koordinat yang sesuai
    int total = totalWahana(M);
    int indeksTarget = -1;

    for (int i = 0; i < total; i++) {
        if (infoKoordinatWahanaMap(M,i).X == Koordinat.X && infoKoordinatWahanaMap(M,i).Y == Koordinat.Y) {
            indeksTarget = i;
        }
    }

    return indeksTarget;
}