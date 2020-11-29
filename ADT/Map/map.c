#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "map.h"
// #include "../Player/pemain.h"

void makeMap(Map *M, char *nama_file, int mapIndex)
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
    while (fgets(buff, sizeof(buff), fp))
    {
        while (buff[j] != '\0' && buff[j] != '\n')
        {
            if (i == 0)
            {
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
        infoOccupancy(*M, i) = 0;
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 0;
        infoTotalPenghasilan(*M, i) = 0;
        infoPenghasilan(*M, i) = 0;
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

            if (isKoordinatSama(current, posisiPemain(P)))
            {
                printf("P");
            }
            else if (searchKoordinat_IDListWahana(M, current) == 1)
            {
                printf("O");
            }
            else if (searchKoordinat_IDListWahana(M, current) == 2)
            {
                printf("A");
            }
            else if (searchKoordinat_IDListWahana(M, current) == 5)
            {
                printf("%c", Elmt(mapMatriks(M), i, j));
            }
            else if (searchKoordinatElmtListWahana(M, current) != -1)
            {
                printf("W");
            }
            else
            {
                printf("%c", Elmt(mapMatriks(M), i, j));
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

    while (!found && i < totalWahana(M))
    {
        if (absis(infoKoordinatWahanaMap(M, i)) == x && ordinat(infoKoordinatWahanaMap(M, i)) == (y + 1))
        {
            if ((infoIdWahana(M, i) != 1) && (infoIdWahana(M, i) != 2) && infoIdWahana(M, i) != 5)
            {
                //  printf("1id : %d\n", W.IdWahana);
                W.IdWahana = infoIdWahana(M, i);
                W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
                W.Occupancy = infoOccupancy(M, i);
                found = true;
            }
        }
        if (absis(infoKoordinatWahanaMap(M, i)) == (x + 1) && ordinat(infoKoordinatWahanaMap(M, i)) == y)
        {
            if ((infoIdWahana(M, i) != 1 && infoIdWahana(M, i) != 2) && infoIdWahana(M, i) != 5)
            {
                // printf("2id : %d\n", W.IdWahana);
                W.IdWahana = infoIdWahana(M, i);
                W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
                W.Occupancy = infoOccupancy(M, i);
                found = true;
            }
        }
        if (absis(infoKoordinatWahanaMap(M, i)) == x && ordinat(infoKoordinatWahanaMap(M, i)) == (y - 1))
        {
            if ((infoIdWahana(M, i) != 1 && infoIdWahana(M, i) != 2) && infoIdWahana(M, i) != 5)
            {
                // printf("3id : %d\n", W.IdWahana);
                W.IdWahana = infoIdWahana(M, i);
                W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
                W.Occupancy = infoOccupancy(M, i);
                found = true;
            }
        }
        if (absis(infoKoordinatWahanaMap(M, i)) == (x - 1) && ordinat(infoKoordinatWahanaMap(M, i)) == y)
        {
            if ((infoIdWahana(M, i) != 1 && infoIdWahana(M, i) != 2) && infoIdWahana(M, i) != 5)
            {
                // printf("4id : %d\n", W.IdWahana);
                W.IdWahana = infoIdWahana(M, i);
                W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
                W.Occupancy = infoOccupancy(M, i);
                found = true;
            }
        }
        i++;
    }

    // printf("id : %d\n", W.IdWahana);
    // found ? printf("found\n") : printf("not found\n");

    if (!found || W.IdWahana == 1 || W.IdWahana == 2 || W.IdWahana == 5)
    {
        Koordinat P;
        makeKoordinat(&P, 0, 0);

        // Apakah ini wahana?
        W.IdWahana = -1;
        W.KoordinatWahana = P;
        W.Occupancy = 0;
    }

    return W;
}

boolean isOfficeDekat(Pemain P)
{
    boolean found = false;
    if (P.Current_Map==1)
    {
        if (P.posisiPemain.X == 2 && P.posisiPemain.Y == (2 + 1))
        {
            found = true;
        }
        else if (P.posisiPemain.X == (2 + 1) && P.posisiPemain.Y == 2)
        {
            found = true;
        }
        else if (P.posisiPemain.X == (2) && P.posisiPemain.Y == (2-1))
        {
            found = true;
        }
        else if (P.posisiPemain.X == (2-1) && P.posisiPemain.Y == (2))
        {
            found = true;
        }
        return found;
    }
    else{
        return found;
    }
}

// void updateMap(Map *M, int x, int y, char input)
// {
//     Elmt(mapMatriks(*M), x, y) = input;
// }

boolean checkIsAvailablePoint(Map M, int x, int y)
{
    Koordinat current;
    makeKoordinat(&current, x, y);
    return searchKoordinatElmtListWahana(M, current) == -1;
}

int searchElmtListWahana(Map M, int idWahana)
{
    int i = 0;
    boolean status = false;

    while (i <= IdxMaxWahana && !status)
    {
        if (infoIdWahana(M, i) == idWahana)
        {
            status = true;
        }
        else
        {
            i++;
        }
    }

    if (status)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int searchKoordinatElmtListWahana(Map M, Koordinat Koordinat)
{ //mengembalikan indeks array listwahana dengan koordinat yang sesuai
    int total = totalWahana(M);
    int indeksTarget = -1;

    for (int i = 0; i < total; i++)
    {
        if (infoKoordinatWahanaMap(M, i).X == Koordinat.X && infoKoordinatWahanaMap(M, i).Y == Koordinat.Y)
        {
            indeksTarget = i;
        }
    }

    return indeksTarget;
}

int searchKoordinat_IDListWahana(Map M, Koordinat Koordinat)
{ //mengembalikan indeks array listwahana dengan koordinat yang sesuai
    int total = totalWahana(M);
    int idTarget = -1;

    for (int i = 0; i < total; i++)
    {
        if (infoKoordinatWahanaMap(M, i).X == Koordinat.X && infoKoordinatWahanaMap(M, i).Y == Koordinat.Y)
        {
            idTarget = infoIdWahana(M, i);
        }
    }

    return idTarget;
}

void initMap(Map *M)
{
    int i = totalWahana(*M);

    //pinjem
    MATRIKS Peta = mapMatriks(*M);
    int BorderKol = NBrsEff(Peta) - 1;
    int BorderBrs = NKolEff(Peta) - 1;
    Koordinat P1, P2;
    //bikin office
    Koordinat P;
    makeKoordinat(&P, 2, 2);
    infoKoordinatWahanaMap(*M, i) = P;
    infoIdWahana(*M, i) = 1;
    infoOccupancy(*M, i) = 0;
    infoStatusWahana(*M, i) = true;
    infoTotalOccupancy(*M, i) = 0;
    infoTotalPenghasilan(*M, i) = 0;
    infoPenghasilan(*M, i) = 0;

    i++;
    //bikin antrean
    makeKoordinat(&P, 10, 10);
    infoKoordinatWahanaMap(*M, i) = P;
    infoIdWahana(*M, i) = 2;
    infoOccupancy(*M, i) = 0;
    infoStatusWahana(*M, i) = true;
    infoTotalOccupancy(*M, i) = 0;
    infoTotalPenghasilan(*M, i) = 0;
    infoPenghasilan(*M, i) = 0;

}

void initGateMap(Map *M, int IDMap) {
    int i = totalWahana(*M);
    //bikin office
    MATRIKS Peta = mapMatriks(*M);
    // int BorderKol = NBrsEff(Peta) - 1;
    // int BorderBrs = NKolEff(Peta) - 1;
    Koordinat P1, P2;

    // Buat Gate
    if (IDMap == 1) {
        // Kanan
        makeKoordinat(&P1, 5, 17);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 2;           // ID Map pindah
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 5;      // Koordinat baru x
        infoTotalPenghasilan(*M, i) = 1;    // Koordinat baru y
        infoPenghasilan(*M, i) = 0;
        i++;
        // Bawah
        makeKoordinat(&P2, 11, 9);
        infoKoordinatWahanaMap(*M, i) = P2;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 4;           // ID Map pindah
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 1;      // Koordinat baru x
        infoTotalPenghasilan(*M, i) = 9;    // Koordinat baru y
        infoPenghasilan(*M, i) = 0;
    } else if (IDMap == 2) {
        // Kiri
        makeKoordinat(&P1, 5, 0);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 1;           
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 5;
        infoTotalPenghasilan(*M, i) = 16;
        infoPenghasilan(*M, i) = 0;
        i++;
        // Bawah
        makeKoordinat(&P1, 11, 9);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 3;
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 1;
        infoTotalPenghasilan(*M, i) = 9;
        infoPenghasilan(*M, i) = 0;

    } else if (IDMap == 3) {
        // Atas
        makeKoordinat(&P1, 0, 9);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 2;
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 10;
        infoTotalPenghasilan(*M, i) = 9;
        infoPenghasilan(*M, i) = 0;
        i++;
        // Kiri
        makeKoordinat(&P1, 5, 0);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 4;
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 5;
        infoTotalPenghasilan(*M, i) = 16;
        infoPenghasilan(*M, i) = 0;

    } else if (IDMap == 4) {
        // Atas
        makeKoordinat(&P1, 0, 9);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 1;
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 10;
        infoTotalPenghasilan(*M, i) = 9;
        infoPenghasilan(*M, i) = 0;
        i++;
        // Kanan
        makeKoordinat(&P1, 5, 17);
        infoKoordinatWahanaMap(*M, i) = P1;
        infoIdWahana(*M, i) = 5;
        infoOccupancy(*M, i) = 3;
        infoStatusWahana(*M, i) = true;
        infoTotalOccupancy(*M, i) = 5;
        infoTotalPenghasilan(*M, i) = 1;
        infoPenghasilan(*M, i) = 0;
    }   
}

boolean isAccessible(Map M, Koordinat PlayerPosition)
{
    boolean isAccess = true;
    int x = ordinat(PlayerPosition);
    int y = absis(PlayerPosition);

    if (y == 0)
    {
        isAccess = false;
    }
    else if (x == 0)
    {
        isAccess = false;
    }
    else if (y == NBrsEff(mapMatriks(M)) - 1)
    {
        isAccess = false;
    }
    else if (x == NKolEff(mapMatriks(M)) - 1)
    {
        isAccess = false;
    }
    else if (searchKoordinat_IDListWahana(M, PlayerPosition) != -1)
    {
        isAccess = false;
    }

    return isAccess;
}

boolean isGate(Map M, Koordinat PlayerPosition) {
    return searchKoordinat_IDListWahana(M, PlayerPosition) == 5;
}

WahanaMap GetGate(Map M, Koordinat PlayerPosition){
    /* Prioritas (1. Atas, 2.Kanan, 3.Bawah, 4.Kiri) */
    // Player Position udah di Gate
    int i, x, y;
    WahanaMap W;
    boolean found;

    i = 0;
    x = absis(PlayerPosition);
    y = ordinat(PlayerPosition);
    found = false;

    while (i < totalWahana(M) && !found)
    {
        // infoIdWahana(*M, i) = 5;
        // infoOccupancy(*M, i) = 2;           // ID Map pindah
        // infoTotalOccupancy(*M, i) = 5;      // Koordinat baru x
        // infoTotalPenghasilan(*M, i) = 1;    // Koordinat baru y
        if ((absis(infoKoordinatWahanaMap(M, i)) == x && ordinat(infoKoordinatWahanaMap(M, i)) == y)&& (infoIdWahana(M,i) == 5))
        {
            W.IdWahana = infoIdWahana(M, i);                    // Identitas Gate
            W.KoordinatWahana = infoKoordinatWahanaMap(M, i);
            W.Occupancy = infoOccupancy(M, i);                  // Pindah ke map mana
            W.totalOccupancy = infoTotalOccupancy(M,i);         // Koordinat x baru
            W.totalPenghasilan = infoTotalPenghasilan(M,i);     // Koordinat y baru
            found = true;
        }
        i++;
    }    
    return W;
    
}


void pindahMap(Map M, Pemain *P, Koordinat PlayerPosition){
    // Player Position udah di Gate
    Koordinat koordinatBaru;
    WahanaMap W;

    if (currentMap(*P) == 1){
        W = GetGate(M,PlayerPosition);
        if (W.Occupancy == 2){
            currentMap(*P) = 2;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }else if (W.Occupancy == 4){
            currentMap(*P) = 4;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }
    }else if(currentMap(*P) == 2) {
        W = GetGate(M,PlayerPosition);
        if (W.Occupancy == 1){
            currentMap(*P) = 1;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }else if (W.Occupancy == 3){
            currentMap(*P) = 3;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }
    }else if(currentMap(*P) == 3) {
        W = GetGate(M,PlayerPosition);
        if (W.Occupancy == 2){
            currentMap(*P) = 2;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }else if (W.Occupancy == 4){
            currentMap(*P) = 4;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }
    }else{
        W = GetGate(M,PlayerPosition);
        if (W.Occupancy == 1){
            currentMap(*P) = 1;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }else if (W.Occupancy == 3){
            currentMap(*P) = 3;
            makeKoordinat(&posisiPemain(*P), W.totalOccupancy, W.totalPenghasilan);
        }
    }
    
}

