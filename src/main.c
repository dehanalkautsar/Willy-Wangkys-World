#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/Jam/boolean.h"
#include "../ADT/Jam/jam.h"
#include "../ADT/ListImplementasiArray/listimplementasiarray.h"
#include "../ADT/ListImplementasiListBerkait/listlinier.h"
#include "../ADT/Matriks/matriks.h"
#include "../ADT/Mesin-Kata&Mesin-Karakter/mesinkar.h"
#include "../ADT/Mesin-Kata&Mesin-Karakter/mesinkata.h"
#include "../ADT/Point/point.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Queue/prioqueuechar.h"
#include "../ADT/Queue/linkedlistQ.h"
#include "../ADT/Stack/stackt.h"
#include "../ADT/Player/pemain.h"
#include "../ADT/Tree/bintree.h"
#include "../ADT/Wahana/bintree_wahana.h"
#include "../ADT/Map/map.h"

int main()
{
    // char* choice;
    Kata New, Load, Exit;

    New.Length = 3;
    New.TabKata[0] = 'n';
    New.TabKata[1] = 'e';
    New.TabKata[2] = 'w';

    Load.Length = 4;
    Load.TabKata[0] = 'l';
    Load.TabKata[1] = 'o';
    Load.TabKata[2] = 'a';
    Load.TabKata[3] = 'd';

    Exit.Length = 4;
    Exit.TabKata[0] = 'e';
    Exit.TabKata[1] = 'x';
    Exit.TabKata[2] = 'i';
    Exit.TabKata[3] = 't';

    printf("// Welcome to Willy wangky's fun factory!!//\n New game / load game / exit? //\n");

    /* ALGORITMA */
    STARTKATA();
    while (!EndKata)
    {
        if (IsKataSama(New, CKata))
        {
            // New Game
        }
        else if (IsKataSama(Load, CKata))
        {
            // Load Game
        }
        else if (IsKataSama(Exit, CKata))
        {
            // Exit
            printf("// Thanks for playing!!! //");
        }
        else
        {
            printf("Input tidak valid\n");
        }

        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya
    }

    return 0;
}

/* STATUS PERMAINAN */
void game_on(int *day)
{ // Masih perlu tambah parameter (Player)
    /* KAMUS */
    boolean isGoing;
    /* ALGORITMA */
    isGoing = true;
    while (isGoing)
    {
        preparation_phase(*day);
        main_phase(day, isGoing);
    }
    // Terminasi program
}

void enter_office(int day, boolean isGoing)
{ //parameternya belum dimasukin
    /* KAMUS */
    boolean stillInOffice;
    /* ALGORITMA */
    stillInOffice = true;

    while (stillInOffice)
    {
        office(&stillInOffice);
    }
    main_phase(&day, isGoing);
}

/* NEW GAME */
void new_game()
{
    /* KAMUS */
    char *nama;
    int start_day;
    int start_money;

    /* ALGORITMA */
    printf("Memulai permainan baru..");
    printf("Masukkan nama:");
    scanf("%s", &nama);

    /* Inisialisasi Permainan */
    start_day = 1;
    start_money = 500;

    // MakePlayer

    /* Jalankan permainan */
    game_on(&start_day); //tambah parameter player dll
}

/* LOAD GAME */
/* TBA */

/* GENERAL PROCEDURE FOR PREPARATION AND MAIN */

// Bikin fungsi buat ambil wahana dari txt

/* END OF RESERVE */

/* RESERVED FOR PREPRATATON PHASE */
void preparation_phase(int day)
{ // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;
    JAM CJam;
    JAM OPJam;
    JAM SisaJam;
    int Need_Money;
    JAM Need_Time;

    /* ALGORITMA */
    /* Inisialisasi */
    CJam = MakeJAM(21, 0);
    OPJam = MakeJAM(9, 0);
    Need_Money = 0;
    Need_Time = MakeJAM(0, 0);

    status = true;

    /* Looping preparation phase */
    while (status)
    {
        printf("Preparation phase day %d\n", day);
        // Panggil fungsi gambar peta

        // Panggil legend peta
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");

        // Panggil status player
        // Need ADT Player

        // Panggil current waktu dan limit waktu
        printf("Current Time: ");
        TulisJAM(CJam);
        printf("\n");
        printf("Opening Time: ");
        TulisJAM(OPJam);
        printf("\n");

        SisaJam = Durasi(CJam, OPJam);
        if (JAMToMenit(SisaJam) != 0)
        {
            if (Minute(SisaJam) == 0)
            {
                print("Time Remaining: %d hour(s)\n", Hour(SisaJam));
            }
            else
            {
                print("Time Remaining: %d hour(s) %d minute(s)\n", Hour(SisaJam), Minute(SisaJam));
            }
        }
        else
        {
            print("Time Remaining: 0");
        }

        // Panggil status jumlah aksi, waktu dan uang yang dibutuhkan
        // Menampilkan Count_isi stack aski : TBA

        // Menampilkan total waktu yang dibutuhkan
        if (JAMToMenit(Need_Time) != 0)
        {
            if (Minute(Need_Time) == 0)
            {
                print("Total waktu yang dibutuhkan: %d hour(s)\n", Hour(Need_Time));
            }
            else
            {
                print("Total waktu yang dibutuhkan: %d hour(s) %d minute(s)\n", Hour(Need_Time), Minute(Need_Time));
            }
        }
        else
        {
            print("Total waktu yang dibutuhkan: 0");
        }
        // Menampilkan total uang yang dibutuhkan:
        print("Total uang yang dibutuhkan: %d", Need_Money);

        // Panggil input dan jalankan
        input_preparation_phase(&status); // Not finished, tambah parameter yang kurang
    }
}

// Not finished, tambah parameter yang kurang
void input_preparation_phase(boolean *status)
{
    /* KAMUS */
    Kata W, A, S, D, Build, Upgrade, Buy, Undo, Execute, Main, Quit;

    W = StringToKata("w");
    A = StringToKata("a");
    S = StringToKata("s");
    D = StringToKata("d");
    Build = StringToKata("build");
    Upgrade = StringToKata("upgrade");
    Buy = StringToKata("buy");
    Undo = StringToKata("undo");
    Execute = StringToKata("execute");
    Main = StringToKata("main");

    /* ALGORITMA */
    STARTKATA();
    while (!EndKata)
    {
        if ((IsKataSama(W, CKata)) || (IsKataSama(A, CKata)) || (IsKataSama(S, CKata)) || (IsKataSama(D, CKata)))
        {
            // Update peta
        }
        else if (IsKataSama(Build, CKata))
        {
            // Lakukan build
        }
        else if (IsKataSama(Upgrade, CKata))
        {
            // Lakukan upgrade
        }
        else if (IsKataSama(Buy, CKata))
        {
            // Lakukan buy
        }
        else if (IsKataSama(Undo, CKata))
        {
            // Lakukan undo
        }
        else if (IsKataSama(Execute, CKata))
        {
            // Lakukan execute
        }
        else if (IsKataSama(Main, CKata))
        {
            // Lakukan main
        }
        else
        {
            printf("Input tidak valid\n");
        }

        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya
    }
}

void build(Pemain P, Elmt_Wahana W, int *Need_Money, JAM *Need_Jam)
{
    JAM WaktuBuild = MakeJAM(1, 0);
    JAM TempJam = MakeJAM(0, 0);
    long TempMenit = 0;
    // 1st Step menampilakan wahana dasar yang mungkin dibuat (hasil file load eksternal)
    // pending menunggu file eksternal

    //2nd step
    //pilih wahana

    //3rd step cek resource player dengan requirement wahana
    if ((Need_Money <= P.uang) && (JLT(WaktuBuild, P.jamPemain)))
    {                                                               //JLT sudah diubah jump least than equal
        *Need_Money = *Need_Money + W.Harga;                        // Tambah need_money
        TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
        *Need_Jam = MenitToJAM(TempMenit);
    }
    else
    {
        if (Need_Money > P.uang)
        {
            printf("Uang player tidak cukup");
        }
        else if (JGT(WaktuBuild, P.jamPemain))
        {
            printf("Waktu tersisa tidak cukup");
        }
    }
    //4th step masukan perintah eksekusi ke dalam stack
}

void upgrade(Pemain P, Map M, int *Need_Money, JAM *Need_Jam)
{
    /* KAMUS LOKAL */
    JAM WaktuBuild = MakeJAM(1, 30);
    wahana W;
    Upgrade_Wahana U1, U2;
    Kata K1, K2;
    int choice;
    boolean valid;

    /* ALGORITMA */
    /* 1. Cek Wahana disekitar kita */
    // TBA

    /* 2. Tampilkan daftar upgrade */
    // Udah ada wahana di sekitar kita
    U1 = Left_Upgrade(W);
    U2 = Right_Upgrade(W);
    printf("- %s\n", Nama_Upgrade(U1));
    printf("- %s\n", Nama_Upgrade(U2));

    K1 = StringToKata(Nama_Upgrade(U1));
    K2 = StringToKata(Nama_Upgrade(U2));

    /* 3. Input User */
    choice = 0;
    valid = false;
    STARTKATA();
    while (!EndKata)
    {
        if (IsKataSama(K1, CKata))
        {
            choice = 1;
        }
        else if (IsKataSama(K2, CKata))
        {
            choice = 2;
        }
        else
        {
            printf("Input tidak valid\n");
        }

        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya
    }

    if (choice == 1)
    {
        /* 4. Check apakah uang dan resource memenuhi */
        if (true)
        {
        }
        else
        {
            printf("Error: Resource atau Uang tidak memenuhi");
        }
    }
    else if (choice == 2)
    {
        /* 4. Check apakah uang dan resource memenuhi */
        if (true)
        {
        }
        else
        {
            printf("Error: Resource atau Uang tidak memenuhi");
        }
    }

    /* 5. Kalau berhasil push ke stack aksi, kalau gagal tampilkan error */
    if ((choice == 1 || choice == 2) && valid)
    {
    }
}

/* END OF RESERVED */

/* RESERVE FROM MAIN PHASE */

void main_phase(int *day, boolean isGoing)
{ // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;
    JAM CurrentJam;
    JAM CloseJam;
    JAM SisaJam;
    PrioQueue antrean;

    /* ALGORITMA */
    /* Inisialisasi */
    CurrentJam = MakeJAM(9, 0);
    CloseJam = MakeJAM(21, 0);

    status = true;

    makeQueue(&antrean);

    /* Looping preparation phase */
    while (status)
    {
        printf("Main phase day %d\n", *day);
        // Panggil fungsi gambar peta

        // Panggil legend peta
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");

        // Panggil status player
        // Need ADT Player

        // Panggil current waktu dan limit waktu
        printf("Current Time: ");
        TulisJAM(CurrentJam);
        printf("\n");
        printf("Opening Time: ");
        TulisJAM(CloseJam);
        printf("\n");

        SisaJam = Durasi(CurrentJam, CloseJam);
        if (JAMToMenit(SisaJam) != 0)
        {
            if (Minute(SisaJam) == 0)
            {
                print("Time Remaining: %d hour(s)\n", Hour(SisaJam));
            }
            else
            {
                print("Time Remaining: %d hour(s) %d minute(s)\n", Hour(SisaJam), Minute(SisaJam));
            }
        }
        else
        {
            print("Time Remaining: 0\n");
        }

        // Panggil Priority Queue buat tampilan antrian
        printAntrean(antrean);
        // Panggil wahana apa yang rusak.

        input_main_phase(&status, day, isGoing); //panggil input dan jalankan

        *day++;
    }
}

/* RESERVED FOR FUNCTION IN MAIN PHASE */

// Not finished, tambah parameter yang kurang
void input_main_phase(boolean *status, int day, boolean isGoing)
{
    /* KAMUS */
    Kata W, A, S, D, Serve, Repair, Detail, Office, Prepare, Quit;

    W.Length = 1;
    W.TabKata[0] = 'w';
    A.Length = 1;
    A.TabKata[0] = 'a';
    S.Length = 1;
    S.TabKata[0] = 's';
    D.Length = 1;
    D.TabKata[0] = 'd';

    Serve.Length = 5;
    Serve.TabKata[0] = 's';
    Serve.TabKata[1] = 'e';
    Serve.TabKata[2] = 'r';
    Serve.TabKata[3] = 'v';
    Serve.TabKata[4] = 'e';

    Repair.Length = 6;
    Repair.TabKata[0] = 'r';
    Repair.TabKata[1] = 'e';
    Repair.TabKata[2] = 'p';
    Repair.TabKata[3] = 'a';
    Repair.TabKata[4] = 'i';
    Repair.TabKata[5] = 'r';

    Detail.Length = 6;
    Detail.TabKata[0] = 'd';
    Detail.TabKata[1] = 'e';
    Detail.TabKata[2] = 't';
    Detail.TabKata[3] = 'a';
    Detail.TabKata[4] = 'i';
    Detail.TabKata[5] = 'l';

    Office.Length = 6;
    Office.TabKata[0] = 'o';
    Office.TabKata[1] = 'f';
    Office.TabKata[2] = 'f';
    Office.TabKata[3] = 'i';
    Office.TabKata[4] = 'c';
    Office.TabKata[5] = 'e';

    Prepare.Length = 7;
    Prepare.TabKata[0] = 'p';
    Prepare.TabKata[1] = 'r';
    Prepare.TabKata[2] = 'e';
    Prepare.TabKata[3] = 'p';
    Prepare.TabKata[4] = 'a';
    Prepare.TabKata[5] = 'r';
    Prepare.TabKata[6] = 'e';

    Quit.Length = 4;
    Quit.TabKata[0] = 'm';
    Quit.TabKata[1] = 'a';
    Quit.TabKata[2] = 'i';
    Quit.TabKata[3] = 'n';

    /* ALGORITMA */
    STARTKATA();
    while (!EndKata)
    {
        if ((IsKataSama(W, CKata)) || (IsKataSama(A, CKata)) || (IsKataSama(S, CKata)) || (IsKataSama(D, CKata)))
        {
            // Update peta
        }
        else if (IsKataSama(Serve, CKata))
        {
            // Lakukan serve
        }
        else if (IsKataSama(Repair, CKata))
        {
            // Lakukan repair
        }
        else if (IsKataSama(Detail, CKata))
        {
            // Lakukan detail
        }
        else if (IsKataSama(Office, CKata))
        {
            enter_office(day, isGoing);
        }
        else if (IsKataSama(Prepare, CKata))
        {
            // Lakukan prepare
        }
        else if (IsKataSama(Quit, CKata))
        {
            // Lakukan quit
        }
        else
        {
            printf("Input tidak valid\n");
        }

        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya
    }
}

void serve(Elmt_Wahana W, Pemain *P, PrioQueue Q, char *wahana)
{ // parameternya harusnya wahana, sama player
    // check wahana error atau engga
    int kepala = Head(Q);
    infotypeQ R = Q.T[kepala];
    int astaghfirullah;
    WahanaAntrean cekanjing;
    
    if (W.statusWahana)
    {
        //proses serve
        uang(*P) += Harga_Wahana(W);
        // ngecek customer queue pertama, apakah dia ngantri di wahana ybs atau engga
        //kalo iya dilayani terus wahana itu dihapus dari list antrian customer tsb
        //kalo wishlist wahana udah kosong, pengunjung dequeue
        //kalo wishlist masih ada, prioritas (kesabaran) makin ke depan
        //kalo engga, cek customer berikutnya
    }
    else
    {
        printf("Oops! Wahana tidak tersedia..");
    }
}

void repair()
{
    //belum dicoding
}

void detail()
{ //parameternya belum dimasukin, harusnya ADT wahana, point, tree
    /* KAMUS */

    /* ALGORITMA */
    printf("// Melihat detail wahana //\n");
    printf("// Nama : \n");       //print nama wahana yang ingin dilihat detail nya
    printf("// Lokasi : \n");     //print dimana letak lokasi wahana
    printf("// Upgrade(s) : \n"); //print upgrade(s)
    printf("// History : \n");    //print history upgrade wahana
    printf("// Status : \n");     //print status wahana berfungsi atau tidak
}

void office(boolean *stillInOffice)
{ //parameter belom dimasukin, belum pernah ditest juga
    /* KAMUS */
    Kata Details, Report, Exit;

    Details.Length = 7;
    Details.TabKata[0] = 'D';
    Details.TabKata[1] = 'e';
    Details.TabKata[2] = 't';
    Details.TabKata[3] = 'a';
    Details.TabKata[4] = 'i';
    Details.TabKata[5] = 'l';
    Details.TabKata[6] = 's';

    Report.Length = 6;
    Report.TabKata[0] = 'R';
    Report.TabKata[1] = 'e';
    Report.TabKata[2] = 'p';
    Report.TabKata[3] = 'o';
    Report.TabKata[4] = 'r';
    Report.TabKata[5] = 't';

    Exit.Length = 4;
    Exit.TabKata[0] = 'E';
    Exit.TabKata[1] = 'x';
    Exit.TabKata[2] = 'i';
    Exit.TabKata[3] = 't';

    /* ALGORITMA */
    if (stillInOffice)
    {
        printf("Masukkan perintah (Details / Report / Exit) :\n");
        STARTKATA();
        while (!EndKata)
        {
            if (IsKataSama(Details, CKata))
            {
                // lakukan details, akses list wahana dan detail
            }
            else if (IsKataSama(Report, CKata))
            {
                // lakukan report, akses list wahana dan report
            }
            else if (IsKataSama(Exit, CKata))
            {
                stillInOffice = false;
            }
            else
            {
                printf("Input tidak valid\n");
            }

            IgnoreBlank();
            ADVKATA();
        }
    }
}
/* END OF RESERVED OF MAIN PHASE FUNCTION/PROCEDURE */
