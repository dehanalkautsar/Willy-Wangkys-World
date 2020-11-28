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
// #include "../ADT/Tree/bintree.h"
#include "../ADT/Wahana/bintree_wahana.h"
#include "../ADT/Map/map.h"

/* Global Variabel */
BinTree Database_Wahana[3];
Material Database_Material[5];
Stack StackPreparationPhase;    //Insialisasi Empty Stack
Map M1, M2, M3, M4; // Inisialisasi Map

int main()
{
    // Inisialisasi
    CreateEmptyStack(&StackPreparationPhase);
    BinTree Database_Wahana1;
    BinTree Database_Wahana2;
    BinTree Database_Wahana3;
    init_material(Database_Material,"material.txt");
    init_wahana(&Database_Wahana1,"wahana1.txt", Database_Material);
    init_wahana(&Database_Wahana2,"wahana2.txt", Database_Material);
    init_wahana(&Database_Wahana3,"wahana3.txt", Database_Material);
    Database_Wahana[0] = Database_Wahana1;
    Database_Wahana[1] = Database_Wahana2;
    Database_Wahana[2] = Database_Wahana3;

    // Inisialisasi Pemain
    Pemain P;
    makePemain(&P,  2000, "Yayan Kanebo", Database_Material);
    
    /* Make Map */
    makeMap(&M1, "map1.txt", 1);
    makeMap(&M2, "map2.txt", 2);
    makeMap(&M3, "map3.txt", 3);
    makeMap(&M4, "map4.txt", 4);   

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
        //main_phase(day, isGoing);
    }
    // Terminasi program
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
    int Need_Menit;
    Material Need_Material[5];

    for (int i = 0; i < 5; i++) {
        Need_Material[i] = CopyMaterial(Database_Material[i]);
        Kuantitas_Material(Need_Material[i]) = 0;
    }
    

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
            // Update peta  (Done)
        }
        else if (IsKataSama(Build, CKata))
        {
            // Lakukan build (Done)
        }
        else if (IsKataSama(Upgrade, CKata))
        {
            // Lakukan upgrade (Done)
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
            // Lakukan main (Done)
        }
        else
        {
            printf("Input tidak valid\n");
        }

        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya
    }
}

void build(Pemain P, int *Need_Money, int *Need_Menit ,JAM *Need_Jam)
{
    JAM WaktuBuild = MakeJAM(1, 0);
    JAM TempJam = MakeJAM(0, 0);
    long TempMenit = 0;
    int UangBuild = 10000;
    Koordinat KoordinatBuild;
    makeKoordinat(&KoordinatBuild,0,0);

    Material Need_Material_Build[5];

    for (int i = 0; i < 5; i++) {
        Need_Material_Build[i] = CopyMaterial(Database_Material[i]);
        Kuantitas_Material(Need_Material_Build[i]) = 0;
    }

    IsiStack StackWahanaBuild;
    // 1st Step menampilakan wahana dasar yang mungkin dibuat (hasil file load eksternal)
    printf("Berikut adalah wahana standar yang tersedia:\n");
    printf("\n");
    printf("1. %s\n",Database_Wahana[0]->info.Nama);
    printf("2. %s\n",Database_Wahana[1]->info.Nama);
    printf("3. %s\n",Database_Wahana[2]->info.Nama);

    //2nd step
    //pilih wahana
    printf("Masukan pilihan wahana yang ingin anda build:\n");
    int InputPilihanWahana;
    scanf("%d",&InputPilihanWahana);
    
    //3rd step cek resource player dengan requirement wahana
    if (InputPilihanWahana = 1){
        if ((Need_Money+UangBuild <= P.uang) && (JLT(WaktuBuild, P.jamPemain))){                  //JLT sudah diubah jump least than equal
            *Need_Money = *Need_Money + UangBuild;                        // Tambah need_money
            TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
            *Need_Jam = MenitToJAM(TempMenit);
            *Need_Menit = JAMToMenit(*Need_Jam);

            
            
            KoordinatBuild.X = P.posisiPemain.X;
            KoordinatBuild.Y = P.posisiPemain.Y;

            // Masukan ke Stack
            AddElementIsiStack(&StackWahanaBuild,"build",KoordinatBuild,Database_Wahana[0]->info.Nama,Database_Wahana[0]->info.ID,0,Need_Material_Build,*Need_Money,*Need_Menit,currentMap(P));
            Push(&StackPreparationPhase,StackWahanaBuild);
        }
        else{
            if (Need_Money > P.uang){
                printf("Uang player tidak cukup");
            }
            else if (JGT(WaktuBuild, P.jamPemain)){ //Jump greater than
                printf("Waktu tersisa tidak cukup");
            }
        }
    }
    else if(InputPilihanWahana = 2){
        if ((Need_Money+UangBuild <= P.uang) && (JLT(WaktuBuild, P.jamPemain))){                  //JLT sudah diubah jump least than equal
            *Need_Money = *Need_Money + UangBuild;                       // Tambah need_money
            TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
            *Need_Jam = MenitToJAM(TempMenit);
            *Need_Menit = JAMToMenit(*Need_Jam);

            KoordinatBuild.X = P.posisiPemain.X;
            KoordinatBuild.Y = P.posisiPemain.Y;

            // Masukan ke Stack
            AddElementIsiStack(&StackWahanaBuild,"build",KoordinatBuild,Database_Wahana[0]->info.Nama,Database_Wahana[1]->info.ID,0,Need_Material_Build,*Need_Money,*Need_Menit,currentMap(P));
            Push(&StackPreparationPhase,StackWahanaBuild);
        }
        else{
            if (Need_Money > P.uang){
                printf("Uang player tidak cukup");
            }
            else if (JGT(WaktuBuild, P.jamPemain)){ //Jump greater than
                printf("Waktu tersisa tidak cukup");
            }
        }
    }
    else if(InputPilihanWahana = 3){
        if ((Need_Money+UangBuild <= P.uang) && (JLT(WaktuBuild, P.jamPemain))){                  //JLT sudah diubah jump least than equal
            *Need_Money = *Need_Money + UangBuild;                        // Tambah need_money
            TempMenit = JAMToMenit(WaktuBuild) + JAMToMenit(*Need_Jam); //Konvert jam lalu ditambah ke need_jam
            *Need_Jam = MenitToJAM(TempMenit);
            *Need_Menit = JAMToMenit(*Need_Jam);

            KoordinatBuild.X = P.posisiPemain.X;
            KoordinatBuild.Y = P.posisiPemain.Y;

            // Masukan ke Stack
            AddElementIsiStack(&StackWahanaBuild,"build",KoordinatBuild,Database_Wahana[0]->info.Nama,Database_Wahana[2]->info.ID,0,Need_Material_Build,*Need_Money,*Need_Menit,currentMap(P));
            Push(&StackPreparationPhase,StackWahanaBuild);
        }
        else{
            if (Need_Money > P.uang){
                printf("Uang player tidak cukup");
            }
            else if (JGT(WaktuBuild, P.jamPemain)){ //Jump greater than
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
    Wahana Curr_Wahana,Left_Wahana,Right_Wahana;
    int ID_Wahana;
    Koordinat Koordinat_Wahana;
    Material M1, M2;
    Material PM[5];

    Kata K1, K2;
    int choice;
    boolean valid, v1,v2;

    int temp;

    /* ALGORITMA */
    /* 1. Cek Wahana disekitar kita */
    Wahana_Terdekat = wahanaTerdekat(M, posisiPemain(P));

    if (Wahana_Terdekat.IdWahana != -1)
    {
        /* 2. Tampilkan daftar upgrade */
        ID_Wahana = Wahana_Terdekat.IdWahana;
        Koordinat_Wahana = Wahana_Terdekat.KoordinatWahana;

        Node_Wahana = Search_DatabaseWahana(Database_Wahana,ID_Wahana);
        Curr_Wahana = Akar(Node_Wahana);

        if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil) {
            Left_Wahana = Akar(Left(Node_Wahana));
            Right_Wahana = Akar(Right(Node_Wahana));

            printf("- %s\n", Nama_Wahana(Left_Wahana));
            printf("- %s\n", Nama_Wahana(Right_Wahana));

            K1 = StringToKata(Nama_Wahana(Left_Wahana));
            K2 = StringToKata(Nama_Wahana(Right_Wahana));

            /* 3. Input User */
            choice = 0;
            
            STARTKATA();
            while (!EndKata)
            {
                if (IsKataSama(K1, CKata)) {
                    choice = 1;
                }
                else if (IsKataSama(K2, CKata)) {
                    choice = 2;
                } else {
                    printf("Error : Input tidak valid\n");
                }

                IgnoreBlank();
                ADVKATA(); //Cek apakah EndKata
            }

            valid = false;
            if (choice == 1 || choice == 2)
            {
                if (uang(P) >= Upgrade_Cost(Curr_Wahana)) //&& (JLT(WaktuUpgrade, jamPemain(P))) 
                {
                    
                    M1 = Upgrade_Material(Curr_Wahana,0);
                    M2 = Upgrade_Material(Curr_Wahana,1);

                    v1 = false;
                    v2 = false;

            
                    for (int i = 0; i < 5; i++)
                    {
                        if (ID_Material(M1) == ID_Material(P.ArrMaterial[i])) {
                            if (Kuantitas_Material(M1) <= (Kuantitas_Material(P.ArrMaterial[i]) - Kuantitas_Material(Need_Material[i]))) {
                                v1 = true;
                            }
                        } else if (ID_Material(M2) == ID_Material(P.ArrMaterial[i])) {
                            if (Kuantitas_Material(M2) <= (Kuantitas_Material(P.ArrMaterial[i]) - Kuantitas_Material(Need_Material[i]))) {
                                v2 = true;
                            }
                        }
                        
                    }
                    
                    if (v1 && v2) {
                        *Need_Money = *Need_Money + Upgrade_Cost(Curr_Wahana);  
                        *Need_Menit = *Need_Menit + JAMToMenit(WaktuUpgrade);
                        
        
                        
                        for (int i = 0; i < 5; i++) {
                            if (ID_Material(M1) == ID_Material(Need_Material[i])) {
                                Kuantitas_Material(Need_Material[i]) += Kuantitas_Material(M1);
                            } else if (ID_Material(M2) == ID_Material(Need_Material[i])) {
                                Kuantitas_Material(Need_Material[i]) += Kuantitas_Material(M2);
                            }

                            if (ID_Material(M1) == ID_Material(PM[i])) {
                                Kuantitas_Material(PM[i]) += Kuantitas_Material(M1);
                            } else if (ID_Material(M2) == ID_Material(PM[i])) {
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
                
                if (choice==1) {
                    AddElementIsiStack(&Stack_Upgrade,"upgrade",Koordinat_Wahana,Nama_Wahana(Curr_Wahana),ID_Wahana(Left_Wahana),0,Need_Material,Upgrade_Cost(Curr_Wahana),JAMToMenit(WaktuUpgrade),currentMap(P));
                } else {
                    AddElementIsiStack(&Stack_Upgrade,"upgrade",Koordinat_Wahana,Nama_Wahana(Curr_Wahana),ID_Wahana(Right_Wahana),0,Need_Material,Upgrade_Cost(Curr_Wahana),JAMToMenit(WaktuUpgrade),currentMap(P));
                }

                Push(&StackPreparationPhase,Stack_Upgrade);

            } else if (!valid) {
                printf("Error: Resource/Uang/Waktu tidak memenuhi");
            }
        } else {
            printf("Error: Wahana tidak dapat diupgrade! ");
        }
    } else {
        printf("Error: Tidak ada wahana didekat kamu! ");
    } 
}

void buy(int* Need_Money, int* Need_Menit){
    /* KAMUS LOKAL */
    Kata B0, B1, B2, B3, B4;
    int jumlahMaterial;
    int choice;
    char* string;
    IsiStack isi;

    B0 = StringToKata(Nama_Material(Database_Material[0]));
    B1 = StringToKata(Nama_Material(Database_Material[1]));
    B2 = StringToKata(Nama_Material(Database_Material[2]));
    B3 = StringToKata(Nama_Material(Database_Material[3]));
    B4 = StringToKata(Nama_Material(Database_Material[4]));

    /* ALGORITMA */
    printf("Ingin membeli apa?\n");
    printf("List: \n");
    for (int i=0; i<5;i++){
        printf("     -  %s\n",Nama_Material(Database_Material[i]));
    }

    choice = -1;
    STARTKATA();
    while (!EndKata && choice == -1)
    {
        // Belum ada konversi kata ke string;
        string = KataToString(CKata);
        jumlahMaterial = atoi(string);
        ADVKATA();
        // Bagian cari material
        if (IsKataSama(CKata,B0)) {
            choice = 0; 
        } else if (IsKataSama(CKata,B1)) {
            choice = 1;
        } else if (IsKataSama(CKata,B2)) {
            choice = 2;
        } else if (IsKataSama(CKata,B3)) {
            choice = 3;
        } else if (IsKataSama(CKata,B4)) {
            choice = 4;
        } else {
            printf("Nama material salah!\n");
        }
        
        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya       
    }
    
    if (choice != -1) {
        int total = jumlahMaterial*Harga_Material(Database_Material[choice]);
        *Need_Money += total;
        
        // Masukkan ke stack
        Material Dummy[5];
        Koordinat DumKoor;
        for (int i = 0; i < 5; i++) {
            Dummy[i] = CopyMaterial(Database_Material[i]);
            Kuantitas_Material(Dummy[i]) = 0;
        }
        makeKoordinat(&DumKoor,0,0);

        AddElementIsiStack(&isi,'buy',DumKoor," ",choice+1,jumlahMaterial,Dummy,total,0,0);
        Push(&StackPreparationPhase,isi);

        printf("// Memasukkan perintah membeli %s sebanyak %d pada stack //",string,jumlahMaterial);
        *Need_Menit = *Need_Menit + 10; //ini durasi buy
    }

    
}

void undo(Stack *StackPreparationPhase, int *Need_Money, int *Need_Menit, Material Need_Material[5]) {
    IsiStack isi;
    Pop(StackPreparationPhase,&isi);
    if (!strcmp(infoCommand(isi),'build')) {
        printf("// Menghapus perintah membangun wahana %s dari stack. //", infoNamaWahanaOrMaterial(isi));
    }
    else if (!strcmp(infoCommand(isi),'upgrade')) {
        addrNode node_wahana = Search_DatabaseWahana(Database_Wahana, infoIDUpgrade(isi));
        Wahana c_wahana = Akar(node_wahana);
        printf("// Menghapus perintah mengupgrade wahana %s menjadi wahana %s dari stack. //", infoNamaWahanaOrMaterial(isi), Nama_Wahana(c_wahana) );
    }
    else if (!strcmp(infoCommand(isi),'buy')) {
        printf("// Menghapus perintah membeli %s sebanyak %d dari stack. //", infoNamaWahanaOrMaterial(isi), infoJumlahMaterial(isi));
    }
    /* PROSES PENGHAPUSAN KOMPONEN EKSEKUSI TERAKHIR*/
    *Need_Money = *Need_Money - infoNeedMoney(isi);
    *Need_Menit = *Need_Menit - infoNeedMenit(isi);
    for (int i=0; i < 5 ; i++) {
        Kuantitas_Material(Need_Material[i]) = Kuantitas_Material(Need_Material[i]) - Kuantitas_Material(infoNeedMaterial(isi,i));
    }
}


void execute(Stack* StackPreparationPhase,Pemain *P, int* Need_Money, int* Need_Menit, Material Need_Material[5]) {
    /* KAMUS LOKAL */
    IsiStack isi;
    int Sisa_Menit;
    boolean valid;
    int tempIDMaterial;
    

    /* ALGORITMA */
    Sisa_Menit = JAMToMenit(Durasi(jamPemain(*P), MakeJAM(9,0)));
    
    // Cek apakah bisa diexecute
    valid = false;
    if (uang(*P) >= *Need_Money && Sisa_Menit >= *Need_Menit) {
        valid = true;
        for (int i = 0; i < 5 && valid; i++) {
            if (ID_Material(Need_Material[i]) == ID_Material((*P).ArrMaterial[i])) {
                if (Kuantitas_Material(Need_Material[i]) >= Kuantitas_Material((*P).ArrMaterial[i])) {
                    valid = false;
                    printf("Error : Material %s tidak cukup!\n",Nama_Material(Need_Material[i])); 
                }
            }  
        } 
    } else {
        printf("Error : Uang/Waktu tidak cukup\n");
    }
    
    if (valid) {
        while (!IsStackEmpty(*StackPreparationPhase)) {
            Pop(StackPreparationPhase,&isi);
            //melakukan aksi tergantung dengan command yang ada di dalam IsiStack
            if (!strcmp(infoCommand(isi),'build')) {
                //lakukan build
                // AddElementIsiStack(&StackWahanaBuild,"build",KoordinatBuild,Database_Wahana[2]->info.Nama,-1,0,Need_Material_Build,*Need_Money,*Need_Menit,currentMap(P));   
                int i;
                WahanaMap Wahana_Baru;
                if (isi.ID_Map == 1) {
                    i = totalWahana(M1);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    listWahana(M1, i+1) = Wahana_Baru;
                } else if (isi.ID_Map == 2) {
                    i = totalWahana(M2);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    listWahana(M2, i+1) = Wahana_Baru;
                    
                } else if (isi.ID_Map == 3) {
                    i = totalWahana(M3);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    listWahana(M3, i+1) = Wahana_Baru;
                } else if (isi.ID_Map == 4) {
                    i = totalWahana(M4);
                    Wahana_Baru.IdWahana = infoIDUpgrade(isi);
                    Wahana_Baru.KoordinatWahana.X = infoKoordinatWahana(isi).X;
                    Wahana_Baru.KoordinatWahana.Y = infoKoordinatWahana(isi).Y;
                    Wahana_Baru.Occupancy = 0;
                    Wahana_Baru.statusWahana = true;
                    listWahana(M4, i+1) = Wahana_Baru;
                }
                
            }
            else if (!strcmp(infoCommand(isi),'upgrade')) {
                //lakukan upgrade
                int total;
                if (isi.ID_Map == 1) {
                    total = totalWahana(M1);
                    for (int i = 0; i < total; i++) {
                        if (infoKoordinatWahanaMap(M1,i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M1,i).Y == infoKoordinatWahana(isi).Y) {
                            infoIdWahana(M1,i) = infoIDUpgrade(isi);
                        }
                    }
                    
                } else if (isi.ID_Map == 2) {
                    total = totalWahana(M2);
                    for (int i = 0; i < total; i++) {
                        if (infoKoordinatWahanaMap(M2,i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M2,i).Y == infoKoordinatWahana(isi).Y) {
                            infoIdWahana(M2,i) = infoIDUpgrade(isi);
                        }
                    }
                    
                } else if (isi.ID_Map == 3) {
                    total = totalWahana(M3);
                    for (int i = 0; i < total; i++) {
                        if (infoKoordinatWahanaMap(M3,i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M3,i).Y == infoKoordinatWahana(isi).Y) {
                            infoIdWahana(M3,i) = infoIDUpgrade(isi);
                        }
                    }

                } else if (isi.ID_Map == 4) {
                    total = totalWahana(M4);
                    for (int i = 0; i < total; i++) {
                        if (infoKoordinatWahanaMap(M4,i).X == infoKoordinatWahana(isi).X && infoKoordinatWahanaMap(M4,i).Y == infoKoordinatWahana(isi).Y) {
                            infoIdWahana(M4,i) = infoIDUpgrade(isi);
                        }
                    }
                }
            }
            
            else if (!strcmp(infoCommand(isi),'buy')) {
                //lakukan buy
                boolean materialsesuai = false;
                for (int i=0; i<5 && !materialsesuai ; i++) {
                    if (!strcmp(infoNamaWahanaOrMaterial(isi),Nama_Material((*P).ArrMaterial[i]))) {
                        materialsesuai = true;
                    }
                    tempIDMaterial = i;
                }
                int curr_jumlahmaterial = Kuantitas_Material((*P).ArrMaterial[tempIDMaterial]);
                Kuantitas_Material((*P).ArrMaterial[tempIDMaterial]) = curr_jumlahmaterial + infoJumlahMaterial(isi);
            }
            Pop(StackPreparationPhase,&isi);
        }
        uang(*P) -= *Need_Money;
        for (int i=0; i < 5 ; i++) {
            if (ID_Material((*P).ArrMaterial[i]) == ID_Material(Need_Material[i])) {
                Kuantitas_Material((*P).ArrMaterial[i]) -= Kuantitas_Material(Need_Material[i]);
            }
        }
    }
    /* PROSES PE-RESET-AN NEED NEED AN*/
    *Need_Money = 0;
    *Need_Menit = 0;
    for (int i=0; i < 5 ; i++) {
        Kuantitas_Material(Need_Material[i]) = 0;
    }
}

// langsung main
void Ignore_Stack(Stack* StackPreparationPhase, int* Need_Money, int* Need_Menit, Material Need_Material[5]) {           //ini fungsi Main buat ignore stack langsung ke main phase ya gess
    IsiStack isi;
    while (!IsStackEmpty(*StackPreparationPhase)) {
        Pop(StackPreparationPhase,&isi);
    }
    /* PROSES PE-RESET-AN NEED NEED AN*/
    *Need_Money = 0;
    *Need_Menit = 0;
    for (int i=0; i < 5 ; i++) {
        Kuantitas_Material(Need_Material[i]) = 0;
    }
        
}

/* END OF RESERVED */

/* RESERVE FROM MAIN PHASE */

void main_phase(int *day, boolean isGoing, Map Wahana)
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

    makeQueue(&antrean, Wahana);

    /* Looping main phase */
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


        // input_main_phase(&status, day, isGoing)
        input_main_phase(&status, day, isGoing, &M, &Q, &P, J, &CurrentJam); //panggil input dan jalankan
        
        *day++;
    }
}

/* RESERVED FOR FUNCTION IN MAIN PHASE */

// Not finished, tambah parameter yang kurang
void input_main_phase(boolean *status, int day, boolean isGoing, Map *currentMap, PrioQueue *Q, Pemain *P, JAM J, JAM *currentTime)
//void serve(BinTree *W, Pemain *P, PrioQueue *Q, Map *Wahana, int idWahana, JAM *currentTime

// tambah parameter database tree dong
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
            ADVKATA();
            char* namaWahana = KataToString(CKata);
            int idWahana = searchIdWahana(namaWahana,*currentMap);
            // Lakukan serve
            serve(P,Q,currentMap,idWahana,currentTime);
            // ini harusnya cek nama wahana juga
        }
        else if (IsKataSama(Repair, CKata))
        {
            // Lakukan repair
            repair(P, currentMap, currentTime);
        }
        else if (IsKataSama(Detail, CKata))
        {
            // Lakukan detail
            detail(*currentMap, posisiPemain(*P));
        }
        else if (IsKataSama(Office, CKata))
        {
            enter_office(day, isGoing);
        }
        else if (IsKataSama(Prepare, CKata))
        {
            // Lakukan prepare
            int idx = totalWahana(*currentMap);
            for (int i = 0; i < idx; i++){
                infoPenghasilan(*currentMap,i) = 0;
            }
            for (int i = 0; i < idx; i++){
                infoOccupancy(*currentMap,i) = 0;
            }
            preparation_phase(day);
            
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

int searchIdWahana(char* namaWahana, Map M){
    int i = 0;
    while(i<=IdxMaxWahana){
        addrNode N = Search_DatabaseWahana(Database_Wahana,infoIdWahana(M,i));
        if (N != Nil && !strcmp(namaWahana,Nama_Wahana(Akar(N)))){
            return (ID_Wahana(Akar(N)));
        }else{
            i++;
        }
    }
}

void serve(Pemain *P, PrioQueue *Q, Map *currentMap, int idWahana, JAM *currentTime)
{ // parameternya harusnya wahana, sama player
    // check wahana error atau engga
    int kepala = Head(*Q);
    infotypeQ X;
    int P = Head(*Q);

    // Search_DatabaseWahana(BinTree Database_Wahana[], int ID);
    addrNode N = Search_DatabaseWahana(Database_Wahana,idWahana);

    WahanaMap container = wahanaTerdekat(*currentMap, posisiPemain(*P));

    int idx = searchKoordinatElmtListWahana(*currentMap,container.KoordinatWahana);

    // currentTime + DurasiWahana <= closeTime --> OK
    JAM durasi = Durasi_Wahana(Akar(N));
    long menitDurasi = JAMToMenit(durasi);
    long menitCurrent = JAMToMenit(*currentTime);
    JAM total = MenitToJAM(menitDurasi+menitCurrent);

    // bikin jam tutup
    JAM tutup = MakeJAM(21,0);

    boolean isOk = JLT(total, tutup);
    

    if ((Status_Wahana(Akar(N)) && (infoOccupancy(*currentMap,idx) < Kapasitas_Wahana(Akar(N)))) && isOk) //cekWahananya rusak ato engga, durasi offisde atau engga, sm penuh atau engga
    {
        //proses serve
        uang(*P) += Harga_Wahana(Akar(N));
        // ngecek customer queue pertama, apakah dia ngantri di wahana ybs atau engga
        if (Search((*Q).T[kepala].Wahana, idWahana) != Nil)
        {
            //kalo ternyata ada wahana ybs di head, maka diapus dr list
            DelP(&(*Q).T[kepala].Wahana, idWahana);
            //mengurangi semua kesabaran
            kurangSabar(Q);
            //kalo list wahana udah kosong dequeue headnya
            if (IsEmptyW((*Q).T[kepala].Wahana)){
                Dequeue(&(*Q).T[kepala],&X);
            }else{
                Dequeue(&(*Q).T[kepala],&X);
                Enqueue(&(*Q),X);
            }
            //random kerusakan wahana
            int constRandom;
            constRandom = (rand() % (5));
            if (constRandom == 0){
                infoStatusWahana(*currentMap,idx) = false;
            }
        }
        *currentTime = total;
        jamPemain(*P)= total;

        infoOccupancy(*currentMap, idx) += 1;
        infoTotalOccupancy(*currentMap, idx) += 1;
        infoPenghasilan(*currentMap, idx) += Harga_Wahana(Akar(N));
        infoTotalPenghasilan(*currentMap, idx) += Harga_Wahana(Akar(N));
    }
    else
    {
        printf("Oops! Wahana tidak tersedia..");
    }
}

void repair(Pemain *P, Map *currentMap, JAM *currentTime)
{
    
    // currentTime + DurasiWahana <= closeTime --> OK
    JAM durasi = MakeJAM(1,0);
    long menitDurasi = JAMToMenit(durasi);
    long menitCurrent = JAMToMenit(*currentTime);
    JAM total = MenitToJAM(menitDurasi+menitCurrent);

    // bikin jam tutup
    JAM tutup = MakeJAM(21,0);

    boolean isOk = JLT(total, tutup);

    WahanaMap container = wahanaTerdekat(*currentMap,posisiPemain(*P));
    int CostRepair = 50;
    int idx;
    
    if ((container.IdWahana != -1) && (container.statusWahana == false)){
        if ( ((uang(*P) - CostRepair) >= 0) && (isOk) ) {
        
            idx = searchKoordinatElmtListWahana(*currentMap, container.KoordinatWahana);

            uang(*P) = uang(*P) - CostRepair;
            *currentTime = total;   // current time dan jam pemain fungsinya beririsan
            P->jamPemain = total; 

            infoStatusWahana(*currentMap,idx) = true;
            
        }else if ((uang(*P) - CostRepair) < 0){
            printf("duit lau gacukup!");
        }
        else if(!isOk){
            printf("waktumu sudah habis!");
        }
    }else{
        printf("Tidak ada wahana yang rusak disekitarmu!");
    }
    

}

void detail(Map currentMap, Koordinat Pemain)
{ 
    /* KAMUS */

    /* ALGORITMA */
    WahanaMap container = wahanaTerdekat(currentMap,Pemain);
    addrNode Node_Wahana;

    if (container.IdWahana != -1){
        Node_Wahana = Search_DatabaseWahana(Database_Wahana,container.IdWahana);

        printf("// Melihat detail wahana //\n");
        printf("// Nama : %s \n", Nama_Wahana(Akar(Node_Wahana)));       //print nama wahana yang ingin dilihat detail nya
        printf("// Lokasi : (%d,%d) \n", container.KoordinatWahana.X, container.KoordinatWahana.Y);     //print dimana letak lokasi wahana
        printf("// Upgrade(s) : \n"); //print upgrade(s)
        if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil) {
            printf("- %s\n", Nama_Wahana(Akar(Left(Node_Wahana))));
            printf("- %s\n", Nama_Wahana(Akar(Right(Node_Wahana))));
        }
        printf("// History : \n");
        PrintList(RiwayatUpgrade(container.IdWahana, Database_Wahana));    //print history upgrade wahana
        
        if (container.statusWahana){
            printf("// Status : Berfungsi \n");     //print status wahana berfungsi atau tidak
        }
        else{
            printf("// Status : Rusak \n");     //print status wahana berfungsi atau tidak
        }
        
    }else{
        printf("Tidak ada wahana di dekat anda!");
    }
}

void detailOffice(Map currentMap){

    int i=0;
    int idx;
    Koordinat xy;
    while (i<totalWahana(currentMap))
    {
        addrNode N = Search_DatabaseWahana(Database_Wahana,infoIdWahana(currentMap,i));
        printf(" -> Nama Wahana (%d,%d) : %s \n", infoKoordinatWahanaMap(currentMap,i).X, infoKoordinatWahanaMap(currentMap,i).Y, Nama_Wahana(Akar(N)));
        i++;
    }
    int x,y;
    printf("Masukan Koordinat wahana yang ingin anda tampilkan: \n");
    printf("X: ");
    scanf("%d\n",&x);
    printf("Y: ");
    scanf("%d\n",&y);

    makeKoordinat(&xy, x, y);
    idx = searchKoordinatElmtListWahana(currentMap, xy);

    // Belum yakin gan
    int idWahana = infoIdWahana(currentMap,idx);
    addrNode Node_Wahana = Search_DatabaseWahana(Database_Wahana,idWahana);

    printf("// Melihat detail wahana //\n");
    printf("// Nama : %s \n", Nama_Wahana(Akar(Node_Wahana)));       //print nama wahana yang ingin dilihat detail nya
    printf("// Lokasi : (%d,%d) \n", xy.X, xy.Y);     //print dimana letak lokasi wahana
    printf("// Upgrade(s) : \n"); //print upgrade(s)
    if (Left(Node_Wahana) != Nil && Right(Node_Wahana) != Nil) {
        printf("- %s\n", Nama_Wahana(Akar(Left(Node_Wahana))));
        printf("- %s\n", Nama_Wahana(Akar(Right(Node_Wahana))));
    }
    printf("// History : \n");
    PrintList(RiwayatUpgrade(idWahana, Database_Wahana));    //print history upgrade wahana
    
    if (infoStatusWahana(currentMap,idx)){
        printf("// Status : Berfungsi \n");     //print status wahana berfungsi atau tidak
    }
    else{
        printf("// Status : Rusak \n");     //print status wahana berfungsi atau tidak
    }

    
}


void office(boolean *stillInOffice, Pemain *P, Map *currentMap)
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
    if (*stillInOffice)
    {
        printf("Masukkan perintah (Details / Report / Exit) :\n");
        STARTKATA();
        while (!EndKata)
        {
            if (IsKataSama(Details, CKata))
            {
                detail(*currentMap, posisiPemain(*P));
            }
            else if (IsKataSama(Report, CKata))
            {
                // lakukan report, akses list wahana dan report
            }
            else if (IsKataSama(Exit, CKata))
            {
                *stillInOffice = false;
            }
        }
    }
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