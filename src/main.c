#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/Jam/boolean.h"
#include "../ADT/Jam/jam.h"
// #include "../ADT/ListImplementasiArray/listimplementasiarray.h"
// #include "../ADT/ListImplementasiListBerkait/listlinier.h"
#include "../ADT/Matriks/matriks.h"
#include "../ADT/Mesin/mesinkar.h"
#include "../ADT/Mesin/mesinkata.h"
#include "../ADT/Point/point.h"
//#include "../ADT/Queue/queue.h"
#include "../ADT/Queue/prioqueuechar.h"
#include "../ADT/Queue/linkedlistQ.h"
#include "../ADT/Stack/stackt.h"
#include "../ADT/Player/pemain.h"
// #include "../ADT/Tree/bintree.h"
#include "../ADT/Wahana/bintree_wahana.h"
//#include "../ADT/Wahana/listrek_wahana.h"
//#include "../ADT/Map/map.h"

/* Global Variabel */
BinTree Database_Wahana[3];
Material Database_Material[5];
Stack StackPreparationPhase; //Insialisasi Empty Stack
Map M1, M2, M3, M4;          // Inisialisasi Map
Pemain P1;
boolean isGoing;
PrioQueue antrean;

/* PROTOTIPE */
void preparation_phase(int *day, Pemain *P);
void input_preparation_phase(boolean *status, Pemain *P, int *Need_Money, int *Need_Menit, JAM *Need_Time, Material Need_Material[], int *day);
void build(Pemain P, int *Need_Money, int *Need_Menit, JAM *Need_Jam, Map Map_Current);
void upgrade(Pemain P, Map M, int *Need_Money, int *Need_Menit, Material Need_Material[5]);
void buy(int *Need_Money, int *Need_Menit);
void undo(Stack *StackPreparation, int *Need_Money, int *Need_Menit, Material Need_Material[5]);
void execute(Stack *StackPreparation, Pemain *P, int *Need_Money, int *Need_Menit, Material Need_Material[5]);
void Ignore_Stack(Stack *StackPreparation, int *Need_Money, int *Need_Menit, Material Need_Material[5]);
void main_phase(int *day, boolean *isGoing, Pemain *P);
void input_main_phase(boolean *status, int *day, boolean *isGoing, PrioQueue *Q, Pemain *P, JAM *currentTime);
int searchIdWahana(char *namaWahana, Map M);
void serve(Pemain *P, int idWahana, JAM *currentTime);
void repair(Pemain *P, Map *currentMap, JAM *currentTime);
void detail(Map currentMap, Koordinat Pemain);
void detailOffice(Map currentMap);
void reportOffice(Map currentMap);
void office(boolean *stillInOffice);
void enter_office(int day, boolean isGoing, Pemain P);
void game_on(int *day, Pemain *P);
void new_game();
Map idMapToMap(int idMap);

/* GENERAL PROCEDURE FOR PREPARATION AND MAIN */
/* STATUS PERMAINAN */
void game_on(int *day, Pemain *P)
{ // Masih perlu tambah parameter (Player)
    /* KAMUS */
    boolean isGoing;
    int idMap;
    Map Map_Current;
    /* ALGORITMA */
    isGoing = true;
    while (isGoing)
    {
        jamPemain(*P) = MakeJAM(21, 0);
        preparation_phase(day, P);
        MakeEmpty(&antrean, 20);
        makeQueue(&antrean, M1);
        // makeQueue(&antrean, M2);
        // makeQueue(&antrean, M3);
        // makeQueue(&antrean, M4);
        // idMap = currentMap(*P);
        // Map_Current = idMapToMap(idMap);
        jamPemain(*P) = MakeJAM(9, 0);
        main_phase(day, &isGoing, P);

    }
    // Terminasi program
}

/* RESERVED FOR PREPRATATON PHASE */
void preparation_phase(int *day, Pemain *P)
{ // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;
    JAM CJam;
    JAM OPJam;
    JAM SisaJam;
    int Need_Money;
    JAM Need_Time;
    int Need_Menit;
    Material Need_Material[5];
    Map C_Map;

    for (int i = 0; i < 5; i++)
    {
        Need_Material[i] = CopyMaterial(Database_Material[i]);
        Kuantitas_Material(Need_Material[i]) = 0;
    }

    /* ALGORITMA */
    /* Inisialisasi */
    //CJam = MakeJAM(21, 0);;
    OPJam = MakeJAM(9, 0);
    Need_Money = 0;
    Need_Time = MakeJAM(0, 0);

    status = true;

    /* Looping preparation phase */
    while (status)
    {
        printf("========= PREPARATION PHASE DAY(s) %d =======\n", *day);
        // Panggil fungsi gambar peta
        C_Map = idMapToMap(currentMap(*P));
        printMap(C_Map, *P);
        // Panggil legend peta
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");

        // Panggil status player
        // Need ADT Player
        printf("================== STATUS ==================\n");
        printf(" Nama     : %s\n",nama(*P));
        printf(" Money    : %d\n", uang(*P));
        //ngeprint material
        printf(" Material : \n");
        for(int i = 0; i < 5; i++) {
            printf("   - %s ", Nama_Material(materialPemain(*P, i)));  
            printf("%d\n", Kuantitas_Material(materialPemain(*P, i)));
        }
        // Panggil current waktu dan limit waktu
        printf(" Current Time : ");
        CJam = jamPemain(*P);
        TulisJAM(CJam);
        printf("\n");
        printf(" Opening Time : ");
        TulisJAM(OPJam);
        printf("\n");
        printf("================ TIME LIMIT ================\n");
        SisaJam = Durasi(CJam, OPJam);
        if (JAMToMenit(SisaJam) != 0)
        {
            if (Minute(SisaJam) == 0)
            {
                printf("Time Remaining: %d hour(s)\n", Hour(SisaJam));
            }
            else
            {
                printf("Time Remaining: %d hour(s) %d minute(s)\n", Hour(SisaJam), Minute(SisaJam));
            }
        }
        else
        {
            printf("Time Remaining: 0\n");
        }

        
        printf("=========== OPERATIONAL NEEDED =============\n");
        // Menampilkan total waktu yang dibutuhkan
        if (JAMToMenit(Need_Time) != 0)
        {
            if (Minute(Need_Time) == 0)
            {
                printf("Total waktu yang dibutuhkan: %d hour(s)\n", Hour(Need_Time));
            }
            else
            {
                printf("Total waktu yang dibutuhkan: %d hour(s) %d minute(s)\n", Hour(Need_Time), Minute(Need_Time));
            }
        }
        else
        {
            printf("Total waktu yang dibutuhkan: 0\n");
        }
        // Menampilkan total uang yang dibutuhkan:
        printf("Total uang yang dibutuhkan: %d\n", Need_Money);
        printf("===========================================\n\n");
        // Panggil input dan jalankan
        input_preparation_phase(&status, P, &Need_Money, &Need_Menit, &Need_Time, Need_Material, day);
    }
}

// Not finished, tambah parameter yang kurang
void input_preparation_phase(boolean *status, Pemain *P, int *Need_Money, int *Need_Menit, JAM *Need_Time, Material Need_Material[], int *day)
{
    /* KAMUS */
    Kata W, A, S, D, Build, Upgrade, Buy, Undo, Execute, Main, Quit;
    int temp;

    StringToKata(&W ,"w");
    StringToKata(&A,"a");
    StringToKata(&S,"s");
    StringToKata(&D,"d");
    StringToKata(&Build,"build");
    StringToKata(&Upgrade, "upgrade");
    StringToKata(&Buy, "buy");
    StringToKata(&Undo, "undo");
    StringToKata(&Execute,"execute");
    StringToKata(&Main,"main");
    StringToKata(&Quit,"quit");

    EndKata = false;
    // printf("Yoyoyoyyy\n");
    /* ALGORITMA */
    ReadInput();
    // while (!EndKata)
    // {
    //     EndKata = true;
    // ReadInput();
    // printf("Yoyoyoyyy\n");
    if ((IsKataSama(W, CKata)) || (IsKataSama(A, CKata)) || (IsKataSama(S, CKata)) || (IsKataSama(D, CKata)))
    {
        
        // Update peta  (Done)
        // parameter kurang : *Map, *Pemain
        // EndKata = true;
        boolean move = false;
        int idMap = currentMap(*P);
        if (idMap == 1)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
                else if (isGate(M1, movedPosition))
                {
                    pindahMap(M1, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
                else if (isGate(M1, movedPosition))
                {
                    pindahMap(M1, P, movedPosition);
                    move = true;
                }
            }
        }
        else if (idMap == 2)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
                else if (isGate(M2, movedPosition))
                {
                    pindahMap(M2, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
                else if (isGate(M2, movedPosition))
                {
                    pindahMap(M2, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
            }
        }
        else if (idMap == 3)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
                else if (isGate(M3, movedPosition))
                {
                    pindahMap(M3, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
                else if (isGate(M3, movedPosition))
                {
                    pindahMap(M3, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
            }
        }
        else if (idMap == 4)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
                else if (isGate(M4, movedPosition))
                {
                    pindahMap(M4, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
                else if (isGate(M4, movedPosition))
                {
                    pindahMap(M4, P, movedPosition);
                    move = true;
                }
            }
        }
        if (move)
        {
            jamPemain(*P) = NextNMenit(jamPemain(*P), 2);
        }
    }
    
    else if (IsKataSama(Build, CKata))
    {
        // EndKata = true;
        // Lakukan build (Done)
        int idMap = currentMap(*P);
        if (idMap == 1)
        {
            build(*P, Need_Money, Need_Menit, Need_Time, M1);
        }
        else if (idMap == 2)
        {
            build(*P, Need_Money, Need_Menit, Need_Time, M2);
        }
        else if (idMap == 3)
        {
            build(*P, Need_Money, Need_Menit, Need_Time, M3);
        }
        else if (idMap == 4)
        {
            build(*P, Need_Money, Need_Menit, Need_Time, M4);
        }
    }
    else if (IsKataSama(Upgrade, CKata))
    {
        // EndKata = true;
        // Lakukan upgrade (Done)
        int idMap = currentMap(*P);
        if (idMap == 1)
        {
            upgrade(*P, M1, Need_Money, Need_Menit, Need_Material);
        }
        else if (idMap == 2)
        {
            upgrade(*P, M2, Need_Money, Need_Menit, Need_Material);
        }
        else if (idMap == 3)
        {
            upgrade(*P, M3, Need_Money, Need_Menit, Need_Material);
        }
        else if (idMap == 4)
        {
            upgrade(*P, M4, Need_Money, Need_Menit, Need_Material);
        }
        // temp = JAMToMenit(*Need_Time);
        *Need_Time = MenitToJAM(*Need_Menit);
    }
    else if (IsKataSama(Buy, CKata))
    {
        // EndKata = true;
        // Lakukan buy
        buy(Need_Money, Need_Menit);

        // temp = JAMToMenit(*Need_Time);
        *Need_Time = MenitToJAM(*Need_Menit);
    }
    else if (IsKataSama(Undo, CKata))
    {
        // EndKata = true;
        // Lakukan undo
        undo(&StackPreparationPhase, Need_Money, Need_Menit, Need_Material);
        *Need_Time = MenitToJAM(*Need_Menit);
    }
    else if (IsKataSama(Execute, CKata))
    {
        // EndKata = true;
        // Lakukan execute
        execute(&StackPreparationPhase, P, Need_Money, Need_Menit, Need_Material);
        // temp = JAMToMenit(*Need_Time);
        *Need_Time = MenitToJAM(0);
        *status = false;
        // printf("%d\n", *status);
    }
    else if (IsKataSama(Main, CKata))
    {
        // EndKata = true;
        // Lakukan main (Done)
        Ignore_Stack(&StackPreparationPhase, Need_Money, Need_Menit, Need_Material);
        boolean isGoing = true;
        //sementara
        *Need_Time = MenitToJAM(0);
        *status = false;
        // printf("%d\n", *status);
    }
    else if (IsKataSama(Quit, CKata))
    {
        // EndKata = true;
        *status = false;
        isGoing = false;
        // isgoing
    }
    else
    {
        EndKata = true;
        printf("Input tidak valid\n");
    }

    //     IgnoreBlank();
    //     ADVKATA(); //Cek kata selanjutnya
    // }
}

void build(Pemain P, int *Need_Money, int *Need_Menit, JAM *Need_Jam, Map Map_Current)
{
    JAM WaktuBuild = MakeJAM(1, 0);
    JAM TempJam = MakeJAM(0, 0);
    long TempMenit = 0;
    int UangBuild = 100;
    Koordinat KoordinatBuild;
    makeKoordinat(&KoordinatBuild, 0, 0);

    Material Need_Material_Build[5];

    for (int i = 0; i < 5; i++)
    {
        Need_Material_Build[i] = CopyMaterial(Database_Material[i]);
        Kuantitas_Material(Need_Material_Build[i]) = 0;
    }

    IsiStack StackWahanaBuild;
    // 1st Step menampilakan wahana dasar yang mungkin dibuat (hasil file load eksternal)
    printf("Berikut adalah wahana standar yang tersedia:\n");
    printf("\n");
    printf("1. %s\n", Database_Wahana[0]->info.Nama);
    printf("2. %s\n", Database_Wahana[1]->info.Nama);
    printf("3. %s\n", Database_Wahana[2]->info.Nama);

    //2nd step
    //pilih wahana
    printf("Masukan pilihan wahana yang ingin anda build: (1/2/3)\n");
    // int InputPilihanWahana;
    // scanf("%d",&InputPilihanWahana);
    ReadInput();

    int InputPilihanWahana = KataToInt(CKata);

    //3rd step cek resource player dengan requirement wahana
    if (InputPilihanWahana == 1)
    {

        if (((*Need_Money + UangBuild) <= P.uang) && (JLT(WaktuBuild, P.jamPemain)))
        {                                                               //JLT sudah diubah jump least than equal
            *Need_Money = *Need_Money + UangBuild;                      // Tambah need_money
            TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
            *Need_Jam = MenitToJAM(TempMenit);
            *Need_Menit = JAMToMenit(*Need_Jam);

            KoordinatBuild.X = P.posisiPemain.X;
            KoordinatBuild.Y = P.posisiPemain.Y;

            // Masukan ke Stack
            AddElementIsiStack(&StackWahanaBuild, "build", KoordinatBuild, Database_Wahana[0]->info.Nama, Database_Wahana[0]->info.ID, 0, Need_Material_Build, UangBuild, JAMToMenit(WaktuBuild), currentMap(P));
            Push(&StackPreparationPhase, StackWahanaBuild);
            printf("// Memasukkan perintah build ke dalam stack. //\n");
            printf("\n");
        }
        else
        {
            if (*Need_Money + UangBuild > P.uang)
            {
                printf("Uang player tidak cukup\n");
            }
            else if (JGT(WaktuBuild, P.jamPemain))
            { //Jump greater than
                printf("Waktu tersisa tidak cukup\n");
            }
        }
    }
    else if (InputPilihanWahana == 2)
    {
        if ((*Need_Money + UangBuild <= P.uang) && (JLT(WaktuBuild, P.jamPemain)))
        {                                                               //JLT sudah diubah jump least than equal
            *Need_Money = *Need_Money + UangBuild;                      // Tambah need_money
            TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
            *Need_Jam = MenitToJAM(TempMenit);
            *Need_Menit = JAMToMenit(*Need_Jam);

            KoordinatBuild.X = P.posisiPemain.X;
            KoordinatBuild.Y = P.posisiPemain.Y;

            // Masukan ke Stack
            AddElementIsiStack(&StackWahanaBuild, "build", KoordinatBuild, Database_Wahana[0]->info.Nama, Database_Wahana[1]->info.ID, 0, Need_Material_Build, UangBuild, JAMToMenit(WaktuBuild), currentMap(P));
            Push(&StackPreparationPhase, StackWahanaBuild);
            printf("// Memasukkan perintah build ke dalam stack. //\n");
            printf("\n");
        }
        else
        {
            if (*Need_Money > P.uang)
            {
                printf("Uang player tidak cukup");
            }
            else if (JGT(WaktuBuild, P.jamPemain))
            { //Jump greater than
                printf("Waktu tersisa tidak cukup");
            }
        }
    }
    else if (InputPilihanWahana == 3)
    {
        if ((*Need_Money + UangBuild <= P.uang) && (JLT(WaktuBuild, P.jamPemain)))
        {                                                               //JLT sudah diubah jump least than equal
            *Need_Money = *Need_Money + UangBuild;                      // Tambah need_money
            TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
            *Need_Jam = MenitToJAM(TempMenit);
            *Need_Menit = JAMToMenit(*Need_Jam);

            KoordinatBuild.X = P.posisiPemain.X;
            KoordinatBuild.Y = P.posisiPemain.Y;

            // Masukan ke Stack
            AddElementIsiStack(&StackWahanaBuild, "build", KoordinatBuild, Database_Wahana[0]->info.Nama, Database_Wahana[2]->info.ID, 0, Need_Material_Build, UangBuild, JAMToMenit(WaktuBuild), currentMap(P));
            Push(&StackPreparationPhase, StackWahanaBuild);
            printf("// Memasukkan perintah build ke dalam stack. //\n");
            printf("\n");
        }
        else
        {
            if (*Need_Money > P.uang)
            {
                printf("Uang player tidak cukup");
            }
            else if (JGT(WaktuBuild, P.jamPemain))
            { //Jump greater than
                printf("Waktu tersisa tidak cukup");
            }
        }
    }

    //4th step masukan perintah eksekusi ke dalam stack
}

void upgrade(Pemain P, Map M, int *Need_Money, int *Need_Menit, Material Need_Material[5])
{
    /* KAMUS LOKAL */
    JAM WaktuUpgrade = MakeJAM(1, 30);
    addrNode Node_Wahana;
    WahanaMap Wahana_Terdekat;
    Wahana Curr_Wahana, Left_Wahana, Right_Wahana;
    int ID_Wahana;
    Koordinat Koordinat_Wahana;
    Material M1, M2;
    Material PM[5];

    Kata K1, K2;
    int choice;
    boolean valid, v1, v2;

    int temp;

    /* ALGORITMA */
    /* 1. Cek Wahana disekitar kita */
    Wahana_Terdekat = wahanaTerdekat(M, posisiPemain(P));
    

    if (Wahana_Terdekat.IdWahana != -1)
    {
        /* 2. Tampilkan daftar upgrade */
        ID_Wahana = Wahana_Terdekat.IdWahana;
        Koordinat_Wahana = Wahana_Terdekat.KoordinatWahana;

        Node_Wahana = Search_DatabaseWahana(Database_Wahana, ID_Wahana);
        Curr_Wahana = Akar(Node_Wahana);
        
        if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil)
        {
            Left_Wahana = Akar(Left(Node_Wahana));
            Right_Wahana = Akar(Right(Node_Wahana));

            printf("- %s\n", Nama_Wahana(Left_Wahana));
            printf("- %s\n", Nama_Wahana(Right_Wahana));

            StringToKata(&K1,Nama_Wahana(Left_Wahana));
            StringToKata(&K2,Nama_Wahana(Right_Wahana));

            /* 3. Input User */
            choice = 0;
            printf("Wahana yang ingin diupgrade:\n");
            ReadInput();
            // while (!EndKata)
            // {
            if (IsKataSama(K1, CKata))
            {
                choice = 1;
                // EndKata = true;
            }
            else if (IsKataSama(K2, CKata))
            {
                choice = 2;
                // EndKata = true;
            }
            else
            {
                printf("Error : Input tidak valid\n");
            }

            //     IgnoreBlank();
            //     ADVKATA(); //Cek apakah EndKata
            // }
            M1 = Upgrade_Material(Curr_Wahana, 0);
            M2 = Upgrade_Material(Curr_Wahana, 1);
            printf("Biaya upgrade : %d\n",Upgrade_Cost(Curr_Wahana));
            printf("Membutuhkan %s : %d buah dan %s : %d buah\n",M1.NamaMaterial,M1.Kuantitas,M2.NamaMaterial,M2.Kuantitas);

            valid = false;
            if (choice == 1 || choice == 2)
            {
                // Cek apakah uang "kemungkinan" cukup
                if (uang(P) >= Upgrade_Cost(Curr_Wahana)) //&& (JLT(WaktuUpgrade, jamPemain(P)))
                {

                    v1 = false;
                    v2 = false;

                    // Cek apakah material "kemungkinan" cukup
                    for (int i = 0; i < 5; i++)
                    {
                        if (ID_Material(M1) == ID_Material(P.ArrMaterial[i]))
                        {
                            if (Kuantitas_Material(M1) <= (Kuantitas_Material(P.ArrMaterial[i]))) // - Kuantitas_Material(Need_Material[i])
                            {
                                v1 = true;
                            }
                        }
                        if (ID_Material(M2) == ID_Material(P.ArrMaterial[i]))
                        {
                            if (Kuantitas_Material(M2) <= (Kuantitas_Material(P.ArrMaterial[i])))
                            {
                                v2 = true;
                            }
                        }
                    }

                    // Syarat terpenuhi
                    if (v1 && v2)
                    {
                        // Tambah need money dan need material
                        *Need_Money = *Need_Money + Upgrade_Cost(Curr_Wahana);
                        *Need_Menit = *Need_Menit + JAMToMenit(WaktuUpgrade);

                        for (int i = 0; i < 5; i++)
                        {
                            if (ID_Material(M1) == ID_Material(Need_Material[i]))
                            {
                                Kuantitas_Material(Need_Material[i]) += Kuantitas_Material(M1);
                            }
                            if (ID_Material(M2) == ID_Material(Need_Material[i]))
                            {
                                Kuantitas_Material(Need_Material[i]) += Kuantitas_Material(M2);
                            }
                        }

                        // Ini buat masukin ke stack
                        for (int i = 0; i < 5; i++)
                        {
                            PM[i] = CopyMaterial(Database_Material[i]);
                            Kuantitas_Material(PM[i]) = 0;

                            if (ID_Material(M1) == ID_Material(PM[i]))
                            {
                                Kuantitas_Material(PM[i]) += Kuantitas_Material(M1);
                            }
                            else if (ID_Material(M2) == ID_Material(PM[i]))
                            {
                                Kuantitas_Material(PM[i]) += Kuantitas_Material(M2);
                            }
                        }
                        valid = true;
                    }
                }
            }

            /* 5. Kalau berhasil push ke stack aksi, kalau gagal tampilkan error */
            if ((choice == 1 || choice == 2) && valid)
            {
                IsiStack Stack_Upgrade;

                if (choice == 1)
                {
                    AddElementIsiStack(&Stack_Upgrade, "upgrade", Koordinat_Wahana, Nama_Wahana(Curr_Wahana), ID_Wahana(Left_Wahana), 0, PM, Upgrade_Cost(Curr_Wahana), JAMToMenit(WaktuUpgrade), currentMap(P));
                }
                else
                {
                    AddElementIsiStack(&Stack_Upgrade, "upgrade", Koordinat_Wahana, Nama_Wahana(Curr_Wahana), ID_Wahana(Right_Wahana), 0, PM, Upgrade_Cost(Curr_Wahana), JAMToMenit(WaktuUpgrade), currentMap(P));
                }

                Push(&StackPreparationPhase, Stack_Upgrade);
            }
            else if (!valid)
            {
                printf("Error: Resource/Uang/Waktu tidak memenuhi\n");
            }
        }
        else
        {
            printf("Error: Wahana tidak dapat diupgrade! \n");
        }
    }
    else
    {
        printf("Error: Tidak ada wahana didekat kamu! \n");
    }
}

void buy(int *Need_Money, int *Need_Menit)
{
    /* KAMUS LOKAL */
    Kata B0, B1, B2, B3, B4;
    int jumlahMaterial;
    int choice;
    char string[256];
    IsiStack isi;

    StringToKata(&B0,Nama_Material(Database_Material[0]));
    StringToKata(&B1,Nama_Material(Database_Material[1]));
    StringToKata(&B2,Nama_Material(Database_Material[2]));
    StringToKata(&B3,Nama_Material(Database_Material[3]));
    StringToKata(&B4,Nama_Material(Database_Material[4]));

    /* ALGORITMA */
    printf("Ingin membeli apa?\n");
    printf("List: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("     -  %s\n", Nama_Material(Database_Material[i]));
    }

    choice = -1;

    // STARTKATA();
    // while (!EndKata && choice == -1)
    // {
    printf("Masukkan jumlah barang :\n");
    ReadInput();
    jumlahMaterial = KataToInt(CKata);

    // ADVKATA();
    printf("Masukkan nama barang :\n");
    ReadInput();
    KataToString(CKata, string);
    // Bagian cari material
    if (IsKataSama(CKata, B0))
    {
        EndKata = true;
        choice = 0;
    }
    else if (IsKataSama(CKata, B1))
    {
        EndKata = true;
        choice = 1;
    }
    else if (IsKataSama(CKata, B2))
    {
        EndKata = true;
        choice = 2;
    }
    else if (IsKataSama(CKata, B3))
    {
        EndKata = true;
        choice = 3;
    }
    else if (IsKataSama(CKata, B4))
    {
        EndKata = true;
        choice = 4;
    }
    else
    {
        printf("Nama material salah!\n");
    }

    //     IgnoreBlank();
    //     ADVKATA(); //Cek kata selanjutnya
    // }

    if (choice != -1)
    {
        int total = jumlahMaterial * Harga_Material(Database_Material[choice]);
        *Need_Money += total;

        // Masukkan ke stack
        Material Dummy[5];
        Koordinat DumKoor;
        for (int i = 0; i < 5; i++)
        {
            Dummy[i] = CopyMaterial(Database_Material[i]);
            Kuantitas_Material(Dummy[i]) = 0;
        }
        makeKoordinat(&DumKoor, 0, 0);
        *Need_Menit = *Need_Menit + 10; //ini durasi buy

        AddElementIsiStack(&isi, "buy", DumKoor, " ", choice + 1, jumlahMaterial, Dummy, total, 10, 0);
        Push(&StackPreparationPhase, isi);

        printf("// Memasukkan perintah membeli %s sebanyak %d pada stack //\n", string, jumlahMaterial);
    }
}

void undo(Stack *StackPreparation, int *Need_Money, int *Need_Menit, Material Need_Material[5])
{
    IsiStack isi;
    Pop(StackPreparation, &isi);
    if (!strcmp(infoCommand(isi), "build"))
    {
        printf("// Menghapus perintah membangun wahana %s dari stack. //\n", infoNamaWahanaOrMaterial(isi));
    }
    else if (!strcmp(infoCommand(isi), "upgrade"))
    {
        addrNode node_wahana = Search_DatabaseWahana(Database_Wahana, infoIDUpgrade(isi));
        Wahana c_wahana = Akar(node_wahana);
        printf("// Menghapus perintah mengupgrade wahana %s menjadi wahana %s dari stack. //\n", infoNamaWahanaOrMaterial(isi), Nama_Wahana(c_wahana));
    }
    else if (!strcmp(infoCommand(isi), "buy"))
    {
        printf("// Menghapus perintah membeli %s sebanyak %d dari stack. //\n", infoNamaWahanaOrMaterial(isi), infoJumlahMaterial(isi));
    }
    /* PROSES PENGHAPUSAN KOMPONEN EKSEKUSI TERAKHIR*/
    *Need_Money = *Need_Money - infoNeedMoney(isi);
    // printf("%d\n",infoNeedMoney(isi));
    *Need_Menit = *Need_Menit - infoNeedMenit(isi);
    for (int i = 0; i < 5; i++)
    {
        Kuantitas_Material(Need_Material[i]) = Kuantitas_Material(Need_Material[i]) - Kuantitas_Material(infoNeedMaterial(isi, i));
    }
}

void execute(Stack *StackPreparation, Pemain *P, int *Need_Money, int *Need_Menit, Material Need_Material[5])
{
    /* KAMUS LOKAL */
    IsiStack isi;
    int Sisa_Menit;
    boolean valid;
    int tempIDMaterial;
    // printf("Cek1\n");
    /* ALGORITMA */
    Sisa_Menit = JAMToMenit(Durasi(jamPemain(*P), MakeJAM(9, 0)));

    // Cek apakah bisa diexecute
    valid = false;
    if (uang(*P) >= *Need_Money && Sisa_Menit >= *Need_Menit)
    {
        // printf("Cek2\n");
        valid = true;
        for (int i = 0; i < 5 && valid; i++)
        {
            if (ID_Material(Need_Material[i]) == ID_Material((*P).ArrMaterial[i]))
            {
                if (Kuantitas_Material(Need_Material[i]) > Kuantitas_Material((*P).ArrMaterial[i]))
                {
                    valid = false;
                    printf("Error : Material %s tidak cukup!\n", Nama_Material(Need_Material[i]));
                }
            }
        }
    }
    else
    {
        printf("Error : Uang/Waktu tidak cukup\n");
    }
    // printf("Cek3\n");
    if (valid)
    {
        // Pop(StackPreparation, &isi);
        while (!IsStackEmpty(*StackPreparation))
        {
            // printf("Cek5\n");
            Pop(StackPreparation, &isi);
            //melakukan aksi tergantung dengan command yang ada di dalam IsiStack
            if (!strcmp(infoCommand(isi), "build"))
            {
                // printf("Cek6\n");
                //lakukan build
                // AddElementIsiStack(&StackWahanaBuild,"build",KoordinatBuild,Database_Wahana[2]->info.Nama,-1,0,Need_Material_Build,*Need_Money,*Need_Menit,currentMap(P));
                int i;
                WahanaMap Wahana_Baru;
                if (isi.ID_Map == 1)
                {
                    boolean statusPosisiBuild = checkIsAvailablePoint(M1, infoKoordinatWahana(isi).X, infoKoordinatWahana(isi).Y);
                    if (statusPosisiBuild)
                    {
                        i = totalWahana(M1);
                        Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                        Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                        Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                        Wahana_Baru.Occupancy = 0;
                        Wahana_Baru.statusWahana = true;
                        Wahana_Baru.penghasilan = 0;
                        Wahana_Baru.totalPenghasilan = 0;
                        Wahana_Baru.totalOccupancy = 0;

                        listWahana(M1, i) = Wahana_Baru;
                    }
                    else
                    {
                        printf("Build gagal lokasi sudah penuh");
                    }
                }
                else if (isi.ID_Map == 2)
                {
                    i = totalWahana(M2);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    Wahana_Baru.penghasilan = 0;
                    Wahana_Baru.totalPenghasilan = 0;
                    Wahana_Baru.totalOccupancy = 0;

                    listWahana(M2, i) = Wahana_Baru;
                }
                else if (isi.ID_Map == 3)
                {
                    i = totalWahana(M3);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    Wahana_Baru.penghasilan = 0;
                    Wahana_Baru.totalPenghasilan = 0;
                    Wahana_Baru.totalOccupancy = 0;

                    listWahana(M3, i) = Wahana_Baru;
                }
                else if (isi.ID_Map == 4)
                {
                    i = totalWahana(M4);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    Wahana_Baru.penghasilan = 0;
                    Wahana_Baru.totalPenghasilan = 0;
                    Wahana_Baru.totalOccupancy = 0;

                    listWahana(M4, i) = Wahana_Baru;
                }
            }
            else if (!strcmp(infoCommand(isi), "upgrade"))
            {
                //lakukan upgrade
                int total;
                if (isi.ID_Map == 1)
                {
                    total = totalWahana(M1);
                    for (int i = 0; i < total; i++)
                    {
                        if (infoKoordinatWahanaMap(M1, i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M1, i).Y == infoKoordinatWahana(isi).Y)
                        {
                            infoIdWahana(M1, i) = infoIDUpgrade(isi);
                        }
                    }
                }
                else if (isi.ID_Map == 2)
                {
                    total = totalWahana(M2);
                    for (int i = 0; i < total; i++)
                    {
                        if (infoKoordinatWahanaMap(M2, i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M2, i).Y == infoKoordinatWahana(isi).Y)
                        {
                            infoIdWahana(M2, i) = infoIDUpgrade(isi);
                        }
                    }
                }
                else if (isi.ID_Map == 3)
                {
                    total = totalWahana(M3);
                    for (int i = 0; i < total; i++)
                    {
                        if (infoKoordinatWahanaMap(M3, i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M3, i).Y == infoKoordinatWahana(isi).Y)
                        {
                            infoIdWahana(M3, i) = infoIDUpgrade(isi);
                        }
                    }
                }
                else if (isi.ID_Map == 4)
                {
                    total = totalWahana(M4);
                    for (int i = 0; i < total; i++)
                    {
                        if (infoKoordinatWahanaMap(M4, i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M4, i).Y == infoKoordinatWahana(isi).Y)
                        {
                            infoIdWahana(M4, i) = infoIDUpgrade(isi);
                        }
                    }
                }
            }

            else if (!strcmp(infoCommand(isi), "buy"))
            {
                //lakukan buy
                boolean materialsesuai = false;
                int curr_jumlahmaterial;
                int idx;
                for (int i = 0; i < 5 && !materialsesuai; i++)
                {
                    //if (!strcmp(infoNamaWahanaOrMaterial(isi), Nama_Material((*P).ArrMaterial[i])))
                    if (isi.idUpgrade == ID_Material(materialPemain(*P,i)))
                    {
                        materialsesuai = true;
                        idx = i;
                    }
                    // tempIDMaterial = i;
                }
                if (materialsesuai){
                    curr_jumlahmaterial = Kuantitas_Material((*P).ArrMaterial[idx]);
                    Kuantitas_Material((*P).ArrMaterial[idx]) = curr_jumlahmaterial + infoJumlahMaterial(isi);    
                    // int curr_jumlahmaterial = Kuantitas_Material((*P).ArrMaterial[tempIDMaterial]);
                    // Kuantitas_Material((*P).ArrMaterial[tempIDMaterial]) = curr_jumlahmaterial + infoJumlahMaterial(isi);
                }
            }

            // Pop(StackPreparation, &isi);
        }
        uang(*P) -= *Need_Money;
        for (int i = 0; i < 5; i++)
        {
            if (ID_Material((*P).ArrMaterial[i]) == ID_Material(Need_Material[i]))
            {
                Kuantitas_Material((*P).ArrMaterial[i]) -= Kuantitas_Material(Need_Material[i]);
            }
        }
    }
    /* PROSES PE-RESET-AN NEED NEED AN*/
    *Need_Money = 0;
    *Need_Menit = 0;
    // reset need time ada di preparation phase
    //*Need_Time = 0;
    for (int i = 0; i < 5; i++)
    {
        Kuantitas_Material(Need_Material[i]) = 0;
    }
    // printf("Cek4\n");
}

// langsung main
void Ignore_Stack(Stack *StackPreparation, int *Need_Money, int *Need_Menit, Material Need_Material[5])
{ //ini fungsi Main buat ignore stack langsung ke main phase ya gess
    IsiStack isi;
    while (!IsStackEmpty(*StackPreparation))
    {
        Pop(StackPreparation, &isi);
    }
    /* PROSES PE-RESET-AN NEED NEED AN*/
    *Need_Money = 0;
    *Need_Menit = 0;
    for (int i = 0; i < 5; i++)
    {
        Kuantitas_Material(Need_Material[i]) = 0;
    }
}

/* END OF RESERVED */

/* RESERVE FROM MAIN PHASE */

void main_phase(int *day, boolean *isGoing, Pemain *P)
{ // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;
    JAM CJam;
    JAM CloseJam;
    JAM SisaJam;
    PrioQueue antrean;
    Map C_Map;

    /* ALGORITMA */
    /* Inisialisasi */
    // CJam = jamPemain(*P);
    CloseJam = MakeJAM(21, 0);

    status = true;

    /* Looping main phase */
    while (status)
    {
        printf("============ MAIN PHASE DAY(s) %d ===========\n", *day);
        // Panggil fungsi gambar peta
        C_Map = idMapToMap(currentMap(*P));
        printMap(C_Map, *P);
        // Panggil legend peta
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");

        // Panggil status player
        // Need ADT Player
        printf("================== STATUS ==================\n");
        printf(" Nama     : %s\n",nama(*P));
        printf(" Money    : %d\n", uang(*P));
        //ngeprint material
        printf(" Material : \n");
        for(int i = 0; i < 5; i++) {
            printf("   - %s ", Nama_Material(materialPemain(*P, i)));  
            printf("%d\n", Kuantitas_Material(materialPemain(*P, i)));
        }
        // Panggil current waktu dan limit waktu
        printf(" Current Time : ");
        CJam = jamPemain(*P);
        TulisJAM(CJam);
        printf("\n");
        printf(" Opening Time : ");
        TulisJAM(CloseJam);
        printf("\n");
        printf("================ TIME LIMIT ================\n");
        SisaJam = Durasi(CJam, CloseJam);
        if (JAMToMenit(SisaJam) != 0)
        {
            if (Minute(SisaJam) == 0)
            {
                printf("Time Remaining: %d hour(s)\n", Hour(SisaJam));
            }
            else
            {
                printf("Time Remaining: %d hour(s) %d minute(s)\n", Hour(SisaJam), Minute(SisaJam));
            }
        }
        else
        {
            printf("Time Remaining: 0\n");
        }
        printf("================= ANTREAN =================\n");
        // Panggil Priority Queue buat tampilan antrian
        //printf("Assalamualaikum antrean\n");
        //printAntrean(antrean, Database_Wahana);
        // Panggil wahana apa yang rusak.
        printf("===========================================\n\n");
        // printf("cek\n");
        // input_main_phase(&status, day, isGoing)
        input_main_phase(&status, day, isGoing, &antrean, P, &CJam); //panggil input dan jalankan
    }
    // printMap(M1, *P);
    *day++;
}

/* RESERVED FOR FUNCTION IN MAIN PHASE */

// Not finished, tambah parameter yang kurang
void input_main_phase(boolean *status, int *day, boolean *isGoing, PrioQueue *Q, Pemain *P, JAM *currentTime)
//void serve(BinTree *W, Pemain *P, PrioQueue *Q, Map *Wahana, int idWahana, JAM *currentTime

// tambah parameter database tree dong
{
    /* KAMUS */
    Kata W, A, S, D, Serve, Repair, Detail, Office, Prepare, Quit;

    StringToKata(&W,"w");
    StringToKata(&A,"a");
    StringToKata(&S,"s");
    StringToKata(&D,"d");
    StringToKata(&Serve, "serve");
    StringToKata(&Repair, "repair");
    StringToKata(&Detail,"detail");
    StringToKata(&Office,"office");
    StringToKata(&Prepare,"prepare");
    StringToKata(&Quit,"quit");

    /* ALGORITMA */
    ReadInput();
    // STARTKATA();
    // while (!EndKata)
    // {
    if ((IsKataSama(W, CKata)) || (IsKataSama(A, CKata)) || (IsKataSama(S, CKata)) || (IsKataSama(D, CKata)))
    {
        // Update peta  (Done)
        // parameter kurang : *Map, *Pemain
        // EndKata = true;
        boolean move = false;
        int idMap = currentMap(*P);
        if (idMap == 1)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
                else if (isGate(M1, movedPosition))
                {
                    pindahMap(M1, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M1, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
                else if (isGate(M1, movedPosition))
                {
                    pindahMap(M1, P, movedPosition);
                    move = true;
                }
            }
        }
        else if (idMap == 2)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
                else if (isGate(M2, movedPosition))
                {
                    pindahMap(M2, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
                else if (isGate(M2, movedPosition))
                {
                    pindahMap(M2, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M2, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
            }
        }
        else if (idMap == 3)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
                else if (isGate(M3, movedPosition))
                {
                    pindahMap(M3, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
                else if (isGate(M3, movedPosition))
                {
                    pindahMap(M3, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M3, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
            }
        }
        else if (idMap == 4)
        {
            if (IsKataSama(W, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) - 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 'w');
                    move = true;
                }
                else if (isGate(M4, movedPosition))
                {
                    pindahMap(M4, P, movedPosition);
                    move = true;
                }
            }
            else if (IsKataSama(A, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) - 1);
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 'a');
                    move = true;
                }
            }
            else if (IsKataSama(S, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)) + 1, ordinat(posisiPemain(*P)));
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 's');
                    move = true;
                }
            }
            else if (IsKataSama(D, CKata))
            {
                Koordinat movedPosition;
                makeKoordinat(&movedPosition, absis(posisiPemain(*P)), ordinat(posisiPemain(*P)) + 1);
                if (isAccessible(M4, movedPosition))
                {
                    setKoordinatPemain(P, 'd');
                    move = true;
                }
                else if (isGate(M4, movedPosition))
                {
                    pindahMap(M4, P, movedPosition);
                    move = true;
                }
            }
        }
        if (move)
        {
            jamPemain(*P) = NextNMenit(jamPemain(*P), 2);
        }
    }
    else if (IsKataSama(Serve, CKata))
    {
        // ADVKATA();
        printf("Masukkan nama wahana:");
        ReadInput();
        
        char namaWahana[256];
        KataToString(CKata, namaWahana);
        int idMap = currentMap(*P);
        int idWahana;
        if (idMap == 1)
        {
            idWahana = searchIdWahana(namaWahana, M1);
            // Lakukan serve
            serve(P, idWahana, currentTime);
            // ini harusnya cek nama wahana juga
        }
        else if (idMap == 2)
        {
            idWahana = searchIdWahana(namaWahana, M2);
            // Lakukan serve
            serve(P, idWahana, currentTime);
            // ini harusnya cek nama wahana juga
        }
        else if (idMap == 3)
        {
            idWahana = searchIdWahana(namaWahana, M3);
            // Lakukan serve
            serve(P, idWahana, currentTime);
            // ini harusnya cek nama wahana juga
        }
        else if (idMap == 4)
        {
            idWahana = searchIdWahana(namaWahana, M4);
            // Lakukan serve
            serve(P, idWahana, currentTime);
            // ini harusnya cek nama wahana juga
        }
    }
    else if (IsKataSama(Repair, CKata))
    {
        // Lakukan repair
        int idMap = currentMap(*P);
        if (idMap == 1)
        {
            repair(P, &M1, currentTime);
        }
        else if (idMap == 2)
        {
            repair(P, &M2, currentTime);
        }
        else if (idMap == 3)
        {
            repair(P, &M3, currentTime);
        }
        else if (idMap == 4)
        {
            repair(P, &M4, currentTime);
        }
    }
    else if (IsKataSama(Detail, CKata))
    {
        // Lakukan detail
        int idMap = currentMap(*P);
        if (idMap == 1)
        {
            detail(M1, posisiPemain(*P));
        }
        else if (idMap == 2)
        {
            detail(M2, posisiPemain(*P));
        }
        else if (idMap == 3)
        {
            detail(M3, posisiPemain(*P));
        }
        else if (idMap == 4)
        {
            detail(M4, posisiPemain(*P));
        }
    }
    else if (IsKataSama(Office, CKata))
    {
        enter_office(*day, *isGoing, *P);
    }
    else if (IsKataSama(Prepare, CKata))
    {
        int idx;
        // Lakukan prepare
        idx = totalWahana(M1);
        for (int i = 0; i < idx; i++)
        {
            infoPenghasilan(M1, i) = 0;
        }
        for (int i = 0; i < idx; i++)
        {
            if (infoIdWahana(M1,i)!=5){
                infoOccupancy(M1, i) = 0;
            }
                
        }

        idx = totalWahana(M2);
        for (int i = 0; i < idx; i++)
        {
            infoPenghasilan(M2, i) = 0;
        }
        for (int i = 0; i < idx; i++)
        {
            if (infoIdWahana(M2,i)!=5){
                infoOccupancy(M2, i) = 0;
            }
        }

        idx = totalWahana(M3);
        for (int i = 0; i < idx; i++)
        {
            infoPenghasilan(M3, i) = 0;
        }
        for (int i = 0; i < idx; i++)
        {
            if (infoIdWahana(M3,i)!=5){
                infoOccupancy(M3, i) = 0;
            }
        }

        idx = totalWahana(M4);
        for (int i = 0; i < idx; i++)
        {
            infoPenghasilan(M4, i) = 0;
        }
        for (int i = 0; i < idx; i++)
        {
            if (infoIdWahana(M4,i)!=5){
                infoOccupancy(M4, i) = 0;
            }
        }

        *day += 1;
        *status = false;
        // preparation_phase(day, P);
    }
    else if (IsKataSama(Quit, CKata))
    {
        *status = false;
        *isGoing = false;
    }
    else
    {
        printf("Input tidak valid\n");
    }

    //     IgnoreBlank();
    //     ADVKATA(); //Cek kata selanjutnya
    // }
}

int searchIdWahana(char *namaWahana, Map M)
{
    int i = 0;
    while (i <= IdxMaxWahana)
    {
        addrNode N = Search_DatabaseWahana(Database_Wahana, infoIdWahana(M, i));
        if (N != Nil && !strcmp(namaWahana, Nama_Wahana(Akar(N))))
        {
            return (ID_Wahana(Akar(N)));
        }
        else
        {
            i++;
        }
    }
}

void gabungListWahana(WahanaMap listGabung[],int* nWahana){
    
    int i = 0;
    int k = 0;
    while (i < totalWahana(M1)) {
        if ((infoIdWahana(M1, i) != 1) && (infoIdWahana(M1, i) != 2) && (infoIdWahana(M1, i) != 5)) {
            listGabung[k].IdWahana = infoIdWahana(M1,i);
            listGabung[k].KoordinatWahana = infoKoordinatWahanaMap(M1,i);
            listGabung[k].Occupancy = infoOccupancy(M1,i);
            listGabung[k].penghasilan = infoPenghasilan(M1,i);
            listGabung[k].statusWahana = infoStatusWahana(M1,i);
            listGabung[k].totalOccupancy = infoTotalOccupancy(M1,i);
            listGabung[k].totalPenghasilan = infoTotalPenghasilan(M1,i);
            k++; 
        }
        i++;
    }
    i = 0;
    while (i < totalWahana(M2)) {
        if ((infoIdWahana(M2, i) != 1) && (infoIdWahana(M2, i) != 2) && (infoIdWahana(M2, i) != 5)) {
            listGabung[k].IdWahana = infoIdWahana(M2,i);
            listGabung[k].KoordinatWahana = infoKoordinatWahanaMap(M2,i);
            listGabung[k].Occupancy = infoOccupancy(M2,i);
            listGabung[k].penghasilan = infoPenghasilan(M2,i);
            listGabung[k].statusWahana = infoStatusWahana(M2,i);
            listGabung[k].totalOccupancy = infoTotalOccupancy(M2,i);
            listGabung[k].totalPenghasilan = infoTotalPenghasilan(M2,i);
            k++; 
        }
        i++;
    }
    i = 0;
    while (i < totalWahana(M3)) {
        if ((infoIdWahana(M3, i) != 1) && (infoIdWahana(M3, i) != 2) && (infoIdWahana(M3, i) != 5)) {
            listGabung[k].IdWahana = infoIdWahana(M3,i);
            listGabung[k].KoordinatWahana = infoKoordinatWahanaMap(M3,i);
            listGabung[k].Occupancy = infoOccupancy(M3,i);
            listGabung[k].penghasilan = infoPenghasilan(M3,i);
            listGabung[k].statusWahana = infoStatusWahana(M3,i);
            listGabung[k].totalOccupancy = infoTotalOccupancy(M3,i);
            listGabung[k].totalPenghasilan = infoTotalPenghasilan(M3,i);
            k++; 
        }
        i++;
    }
    i = 0;
    while (i < totalWahana(M4)) {
        if ((infoIdWahana(M4, i) != 1) && (infoIdWahana(M4, i) != 2) && (infoIdWahana(M4, i) != 5)) {
            listGabung[k].IdWahana = infoIdWahana(M4,i);
            listGabung[k].KoordinatWahana = infoKoordinatWahanaMap(M4,i);
            listGabung[k].Occupancy = infoOccupancy(M4,i);
            listGabung[k].penghasilan = infoPenghasilan(M4,i);
            listGabung[k].statusWahana = infoStatusWahana(M4,i);
            listGabung[k].totalOccupancy = infoTotalOccupancy(M4,i);
            listGabung[k].totalPenghasilan = infoTotalPenghasilan(M4,i);
            k++; 
        }
        i++;
    }
    *nWahana = k;
}

void serve(Pemain *P, int idWahana, JAM *currentTime)
{ // parameternya harusnya wahana, sama player
    // check wahana error atau engga
    int kepala = Head(antrean);
    infotypeQ X;
    // Map C_Map;
    WahanaMap listGabung[256];
    int nWahana;
    int idx;
    boolean valid;

    // Search_DatabaseWahana(BinTree Database_Wahana[], int ID);
    addrNode N = Search_DatabaseWahana(Database_Wahana, idWahana);

    if (N != Nil){
        gabungListWahana(listGabung,&nWahana);
        // C_Map = idMapToMap(currentMap(*P));

        valid = false;
        
        for (int i = 0; i < nWahana && !valid; i++){
            if (listGabung[i].IdWahana == ID_Wahana(Akar(N)) && listGabung[i].Occupancy < Kapasitas_Wahana(Akar(N)) && listGabung[i].statusWahana){
                valid = true;
                idx = i;
            }
        }

        // currentTime + DurasiWahana <= closeTime --> OK
        JAM durasi = Durasi_Wahana(Akar(N));
        long menitDurasi = JAMToMenit(durasi);
        long menitCurrent = JAMToMenit(*currentTime);
        JAM total = MenitToJAM(menitDurasi + menitCurrent);

        // bikin jam tutup
        JAM tutup = MakeJAM(21, 0);

        boolean isOk = JLT(total, tutup);

        if (isOk){
            //proses serve
            uang(*P) += Harga_Wahana(Akar(N));
            // ngecek customer queue pertama, apakah dia ngantri di wahana ybs atau engga
            if (SearchLQ((antrean).T[kepala].WahanaString, idWahana) != Nil)
            {
                //kalo ternyata ada wahana ybs di head, maka diapus dr list
                DelP(&(antrean).T[kepala].WahanaString, idWahana);
                //mengurangi semua kesabaran
                kurangSabar(&antrean);
                //kalo list wahana udah kosong dequeue headnya
                if (IsEmptyW((antrean).T[kepala].WahanaString))
                {
                    Dequeue(&antrean, &X);
                }
                else
                {
                    Dequeue(&antrean, &X);
                    Enqueue(&antrean, X);
                }
            }
            *currentTime = total;
            jamPemain(*P) = total;
            // C_Map = idMapToMap(currentMap(*P));
            
            valid = false;
            for (int i = 0; i < totalWahana(M1) && !valid; i++){
                if (listGabung[idx].IdWahana == infoIdWahana(M1,i) && listGabung[idx].Occupancy < infoOccupancy(M1,i)){
                    infoOccupancy(M1, i) += 1;
                    infoTotalOccupancy(M1, i) += 1;
                    infoPenghasilan(M1, i) += Harga_Wahana(Akar(N));
                    infoTotalPenghasilan(M1, i) += Harga_Wahana(Akar(N));
                    //random kerusakan wahana
                    int constRandom;
                    constRandom = (rand() % (5));
                    if (constRandom == 0)
                    {
                        infoStatusWahana(M1, i) = false;
                    }
                    valid = true;
                }
            }
            for (int i = 0; i < totalWahana(M2) && !valid; i++){
                if (listGabung[idx].IdWahana == infoIdWahana(M2,i) && listGabung[idx].Occupancy < infoOccupancy(M2,i)){
                    infoOccupancy(M2, i) += 1;
                    infoTotalOccupancy(M2, i) += 1;
                    infoPenghasilan(M2, i) += Harga_Wahana(Akar(N));
                    infoTotalPenghasilan(M2, i) += Harga_Wahana(Akar(N));
                    //random kerusakan wahana
                    int constRandom;
                    constRandom = (rand() % (5));
                    if (constRandom == 0)
                    {
                        infoStatusWahana(M2, i) = false;
                    }
                    valid = true;
                }
            }
            for (int i = 0; i < totalWahana(M3) && !valid; i++){
                if (listGabung[idx].IdWahana == infoIdWahana(M3,i) && listGabung[idx].Occupancy < infoOccupancy(M3, i)){
                    infoOccupancy(M3, i) += 1;
                    infoTotalOccupancy(M3, i) += 1;
                    infoPenghasilan(M3, i) += Harga_Wahana(Akar(N));
                    infoTotalPenghasilan(M3, i) += Harga_Wahana(Akar(N));
                    //random kerusakan wahana
                    int constRandom;
                    constRandom = (rand() % (5));
                    if (constRandom == 0)
                    {
                        infoStatusWahana(M3, i) = false;
                    }
                    valid = true;
                }
            }
            for (int i = 0; i < totalWahana(M4) && !valid; i++){
                if (listGabung[idx].IdWahana == infoIdWahana(M4,i) && listGabung[idx].Occupancy < infoOccupancy(M4,i)){
                    infoOccupancy(M4, i) += 1;
                    infoTotalOccupancy(M4, i) += 1;
                    infoPenghasilan(M4, i) += Harga_Wahana(Akar(N));
                    infoTotalPenghasilan(M4, i) += Harga_Wahana(Akar(N));
                    //random kerusakan wahana
                    int constRandom;
                    constRandom = (rand() % (5));
                    if (constRandom == 0)
                    {
                        infoStatusWahana(M4, i) = false;
                    }
                    valid = true;
                }
            }


        }else{
            printf("Waktu tidak cukup!");
        }
            
    }else{
        printf("Oops! Wahana tidak tersedia..");
    }
}

void repair(Pemain *P, Map *currentMap, JAM *currentTime)
{
    // currentTime + DurasiWahana <= closeTime --> OK
    JAM durasi = MakeJAM(1, 0);
    long menitDurasi = JAMToMenit(durasi);
    long menitCurrent = JAMToMenit(*currentTime);
    JAM total = MenitToJAM(menitDurasi + menitCurrent);

    // bikin jam tutup
    JAM tutup = MakeJAM(21, 0);

    boolean isOk = JLT(total, tutup);

    WahanaMap container = wahanaTerdekat(*currentMap, posisiPemain(*P));
    int CostRepair = 50;
    int idx;

    if ((container.IdWahana != -1) && (container.statusWahana == false))
    {
        if (((uang(*P) - CostRepair) >= 0) && (isOk))
        {

            idx = searchKoordinatElmtListWahana(*currentMap, container.KoordinatWahana);

            uang(*P) = uang(*P) - CostRepair;
            *currentTime = total; // current time dan jam pemain fungsinya beririsan
            P->jamPemain = total;

            infoStatusWahana(*currentMap, idx) = true;
            printf("Repair Anda Berhasil");
        }
        else if ((uang(*P) - CostRepair) < 0)
        {
            printf("duit lau gacukup!");
        }
        else if (!isOk)
        {
            printf("waktumu sudah habis!");
        }
    }
    else
    {
        printf("Tidak ada wahana yang rusak disekitarmu!");
    }
}

void detail(Map currentMap, Koordinat Pemain)
{
    /* KAMUS */

    /* ALGORITMA */
    WahanaMap container = wahanaTerdekat(currentMap, Pemain);
    addrNode Node_Wahana;

    if (container.IdWahana != -1)
    {
        Node_Wahana = Search_DatabaseWahana(Database_Wahana, container.IdWahana);
        if (Node_Wahana!= Nil)
        {
            printf("// Melihat detail wahana //\n");
            printf("// Nama : %s \n", Nama_Wahana(Akar(Node_Wahana)));                                  //print nama wahana yang ingin dilihat detail nya
            printf("// Lokasi : (%d,%d) \n", container.KoordinatWahana.X, container.KoordinatWahana.Y); //print dimana letak lokasi wahana
            printf("// Upgrade(s) : \n");                                                               //print upgrade(s)
            if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil)
            {
                printf("- %s\n", Nama_Wahana(Akar(Left(Node_Wahana))));
                printf("- %s\n", Nama_Wahana(Akar(Right(Node_Wahana))));
            } else {
                printf("- Wahana tidak dapat diupgrade\n");
            }
            printf("// History : \n");
            PrintList(RiwayatUpgrade(container.IdWahana, Database_Wahana)); //print history upgrade wahana

            // printf("%d\n",container.statusWahana);
            if (!container.statusWahana)
            {
                printf("// Status : Berfungsi \n"); //print status wahana berfungsi atau tidak
            }
            else
            {
                printf("// Status : Rusak \n"); //print status wahana berfungsi atau tidak
            }
        }
    }
    else
    {
        printf("Tidak ada wahana di dekat anda!\n");
    }
}

void detailOffice(Map currentMap)
{
    // printf("Hello\n");
    int i = 0;
    int idx = -1;
    int count = 0;
    Koordinat xy;
    printf("%d\n", totalWahana(currentMap));
    while (i < totalWahana(currentMap))
    {
        addrNode N = Search_DatabaseWahana(Database_Wahana, infoIdWahana(currentMap, i));
        if (N != Nil) {
            printf(" -> Nama Wahana (%d,%d) : %s \n", infoKoordinatWahanaMap(currentMap, i).X, infoKoordinatWahanaMap(currentMap, i).Y, Nama_Wahana(Akar(N)));
            count++;
        }
        i++;
        
    }
    if (count!=0){
        int x, y;
        printf("Masukan Koordinat wahana yang ingin anda tampilkan: \n");
        printf("X: ");
        ReadInput();
        x = KataToInt(CKata);
        printf("Y: ");
        ReadInput();
        y = KataToInt(CKata);

        makeKoordinat(&xy, x, y);
        idx = searchKoordinatElmtListWahana(currentMap, xy);
    }
    if (idx!=-1){
        int idWahana = infoIdWahana(currentMap, idx);
        addrNode Node_Wahana = Search_DatabaseWahana(Database_Wahana, idWahana);
        
        if (Node_Wahana != Nil) {
            printf("// Melihat detail wahana //\n");
            printf("// Nama : %s \n", Nama_Wahana(Akar(Node_Wahana))); //print nama wahana yang ingin dilihat detail nya
            printf("// Lokasi : (%d,%d) \n", xy.X, xy.Y);              //print dimana letak lokasi wahana
            printf("// Upgrade(s) : \n");                              //print upgrade(s)
            if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil)
            {
                printf("- %s\n", Nama_Wahana(Akar(Left(Node_Wahana))));
                printf("- %s\n", Nama_Wahana(Akar(Right(Node_Wahana))));
            }
            printf("// History : \n");
            PrintList(RiwayatUpgrade(idWahana, Database_Wahana)); //print history upgrade wahana

            if (infoStatusWahana(currentMap, idx))
            {
                printf("// Status : Berfungsi \n"); //print status wahana berfungsi atau tidak
            }
            else
            {
                printf("// Status : Rusak \n"); //print status wahana berfungsi atau tidak
            }
        } 
        else{
            printf("Wahana tidak ditemukan\n");
        }
    }
    else{
        printf("Wahana tidak ditemukan\n");
    }
    // 
}
void reportOffice(Map currentMap)
{
    /* KAMUS */

    /* ALGORITMA */
    int i = 0;
    int idx = -1;
    Koordinat xy;
    int count = 0;
    while (i < totalWahana(currentMap))
    {
        addrNode N = Search_DatabaseWahana(Database_Wahana, infoIdWahana(currentMap, i));
        if (N != Nil){
            printf(" -> Nama Wahana (%d,%d) : %s \n", infoKoordinatWahanaMap(currentMap, i).X, infoKoordinatWahanaMap(currentMap, i).Y, Nama_Wahana(Akar(N)));
            count++;
        }
        i++;
    }
    if (count!=0){
        int x, y;
        printf("Masukan Koordinat wahana yang ingin anda tampilkan: \n");
        printf("X: ");
        ReadInput();
        x = KataToInt(CKata);
        printf("Y: ");
        ReadInput();
        y = KataToInt(CKata);

        makeKoordinat(&xy, x, y);
        idx = searchKoordinatElmtListWahana(currentMap, xy);
    }
    if (idx!=-1){
        int idWahana = infoIdWahana(currentMap, idx);
        addrNode Node_Wahana = Search_DatabaseWahana(Database_Wahana, idWahana);
        
        if (Node_Wahana!=Nil){
            printf("// Melihat detail wahana //\n");
            printf("// Nama : %s \n", Nama_Wahana(Akar(Node_Wahana))); //print nama wahana yang ingin dilihat detail nya
            printf("// Lokasi : (%d,%d) \n", xy.X, xy.Y);              //print dimana letak lokasi wahana
            printf("TOTAL : \n");
            printf("// Wahana ini telah dinaiki secara total sebanyak   : %d kali\n", infoTotalOccupancy(currentMap, idx));
            printf("// Total penghasilan wahana ini adalah : %d\n", infoTotalPenghasilan(currentMap, idx));
            printf("DAILY: \n");
            printf("// Wahana ini telah dinaiki sebanyak  : %d kali\n", infoOccupancy(currentMap, idx));
            printf("// Penghasilan wahana ini untuk hari ini adalah : %d\n", infoPenghasilan(currentMap, idx));
        } else {
            printf("Wahana tidak ditemukan\n");
        }
    } else {
        printf("Wahana tidak ditemukan\n");
    }
    // Belum yakin gan -> Apus Gan
    
    /**
    1. Berapa kali wahana dinaiki.
    2. Total penghasilan dari wahana.
    3. Berapa kali wahana dinaiki dalam hari ini.
    4. Total penghasilan dari wahana dalam hari ini.**/



    // printf("// Upgrade(s) : \n"); //print upgrade(s)
    // if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil) {
    //     printf("- %s\n", Nama_Wahana(Akar(Left(Node_Wahana))));
    //     printf("- %s\n", Nama_Wahana(Akar(Right(Node_Wahana))));
    // }
    // printf("// History : \n");
    // PrintList(RiwayatUpgrade(idWahana, Database_Wahana));    //print history upgrade wahana

    // if (infoStatusWahana(currentMap,idx)){
    //     printf("// Status : Berfungsi \n");     //print status wahana berfungsi atau tidak
    // }
    // else{
    //     printf("// Status : Rusak \n");     //print status wahana berfungsi atau tidak
    // }
}

void office(boolean *stillInOffice)
{ //parameter belom dimasukin, belum pernah ditest juga
    /* KAMUS */
    Kata Details, Report, Exit;
    StringToKata(&Details, "details");
    StringToKata(&Report, "report");
    StringToKata(&Exit, "exit");

    /* ALGORITMA */
    if (*stillInOffice)
    {
        printf("Masukkan perintah (Details / Report / Exit) :\n");
        // STARTKATA();
        ReadInput();
        int choice = 0;
        
        // while (!EndKata)
        // {
        if (IsKataSama(Details, CKata))
        {
            choice = 1;
            EndKata = true;
            //detail(*currentMap, posisiPemain(*P));
        }
        else if (IsKataSama(Report, CKata))
        {
            // lakukan report
            choice = 2;
            EndKata = true;
        }
        else if (IsKataSama(Exit, CKata))
        {
            // EndKata = true;
            *stillInOffice = false;
        }
        // ADVKATA();
        // }

        Kata C1, C2, C3, C4;
        // int C1;
        if (choice == 1)
        {
            // Lakukan details.
            StringToKata(&C1,"1");
            StringToKata(&C2,"2");
            StringToKata(&C3,"3");
            StringToKata(&C4,"4");

            printf("Map yang Tersedia :\n");
            printf(" 1. Map 1\n");
            printf(" 2. Map 2\n");
            printf(" 3. Map 3\n");
            printf(" 4. Map 4\n");
            printf("Pilih Peta (1/2/3/4) : \n");
            ReadInput();

            
            // {
            if (IsKataSama(C1, CKata))
            {
                // printf("gnu prolog");
                detailOffice(M1);
            }
            else if (IsKataSama(C2, CKata))
            {
                detailOffice(M2);
            }
            else if (IsKataSama(C3, CKata))
            {
                detailOffice(M3);
            }
            else if (IsKataSama(C4, CKata))
            {
                detailOffice(M4);
            }
            //     ADVKATA();
            // }
        }
        else if (choice == 2)
        {
            //lakukan report, akses reporttttt
            StringToKata(&C1,"1");
            StringToKata(&C2,"2");
            StringToKata(&C3,"3");
            StringToKata(&C4,"4");

            printf("Map yang Tersedia :\n");
            printf(" 1. Map 1\n");
            printf(" 2. Map 2\n");
            printf(" 3. Map 3\n");
            printf(" 4. Map 4\n");
            printf("Pilih Peta (1/2/3/4) : \n");

            ReadInput();
            // STARTKATA();
            // while (!EndKata)
            // {
            if (IsKataSama(C1, CKata))
            {
                reportOffice(M1);
            }
            else if (IsKataSama(C2, CKata))
            {
                reportOffice(M2);
            }
            else if (IsKataSama(C3, CKata))
            {
                reportOffice(M3);
            }
            else if (IsKataSama(C4, CKata))
            {
                reportOffice(M4);
            }
            // ADVKATA();
            // }
        }
    }
}

void enter_office(int day, boolean isGoing, Pemain P)
{ //parameternya belum dimasukin
    /* KAMUS */
    boolean stillInOffice;
    /* ALGORITMA */
    if (isOfficeDekat(P))
    {
        stillInOffice = true;

        while (stillInOffice)
        {
            office(&stillInOffice);
        }
        main_phase(&day, &isGoing, &P);
    }
}
// BATAS MAIN PHASE //

// FUNGSI TAMBAHAN //
Map idMapToMap(int idMap)
{
    if (idMap == 1)
    {
        return M1;
    }
    else if (idMap == 2)
    {
        return M2;
    }
    else if (idMap == 3)
    {
        return M3;
    }
    else if (idMap == 4)
    {
        return M4;
    }
    else
    {
        printf("ID Map tidak valid");
    }
}

/* NEW GAME */
void new_game()
{
    /* KAMUS */
    int start_day;
    int start_money;
    char nama[256];

    /* ALGORITMA */
    printf("Memulai permainan baru..\n");
    printf("Masukkan nama: ");
    ReadInput();
    // scanf("%s", &nama);
    KataToString(CKata,nama);
    /* Inisialisasi Permainan */
    start_day = 1;
    start_money = 500;

    // MakePlayer
    // Inisialisasi Pemain
    Pemain P;
    makePemain(&P, 20000, nama, Database_Material);
    /* Jalankan permainan */
    game_on(&start_day, &P); //tambah parameter player dll
}

int main()
{
    // Inisialisasi
    CreateEmptyStack(&StackPreparationPhase);
    BinTree Database_Wahana1;
    BinTree Database_Wahana2;
    BinTree Database_Wahana3;
    init_material(Database_Material, "material.txt");
    init_wahana(&Database_Wahana1, "wahana1.txt", Database_Material);
    init_wahana(&Database_Wahana2, "wahana2.txt", Database_Material);
    init_wahana(&Database_Wahana3, "wahana3.txt", Database_Material);
    Database_Wahana[0] = Database_Wahana1;
    Database_Wahana[1] = Database_Wahana2;
    Database_Wahana[2] = Database_Wahana3;

    /* Make Map */
    makeMap(&M1, "map1.txt", 1);
    makeMap(&M2, "map2.txt", 2);
    makeMap(&M3, "map3.txt", 3);
    makeMap(&M4, "map4.txt", 4);

    initMap(&M1);

    initGateMap(&M1, 1);
    initGateMap(&M2, 2);
    initGateMap(&M3, 3);
    initGateMap(&M4, 4);

    Kata New, Load, Exit;

    StringToKata(&New,"new");
    StringToKata(&Load,"load");
    StringToKata(&Exit,"exit");

    printf("// Welcome to Willy wangky's fun factory!!//\n New game / load game / exit? //\n");

    /* ALGORITMA */
    ReadInput();
    // while (!EndKata)
    // {
    if (IsKataSama(New, CKata))
    {
        new_game();
        printf("Terimakasih Sudah Bermain!\n");
    }
    else if (IsKataSama(Load, CKata))
    {
        // Load Game
    }
    else if (IsKataSama(Exit, CKata))
    {
        // EndKata = true;
        printf("// Thanks for playing!!! //");
    }
    else
    {
        printf("Input tidak valid\n");
    }

    //     IgnoreBlank();
    //     ADVKATA(); //Cek kata selanjutnya
    // }

    return 0;
}
// void status