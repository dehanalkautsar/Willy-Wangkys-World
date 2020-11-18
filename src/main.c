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
#include "../ADT/Stack/stackt.h"
#include "../ADT/Player/pemain.h"

int main(){
    char* choice;
    
    printf("// Welcome to Willy wangky's fum factory!!////\n New game / load game / exit? //\n");
    
    do{
        scanf("%s", &choice);
    }while (choice=="new" || choice=="load" || choice =="exit");
    
    if (choice=="new"){   
        //new game
    }else if(choice=="load"){
        //continue game
    }else{
            printf("// Thanks for playing!!! //");
            return 0;
        }
    
    return 0;
}

/* STATUS PERMAINAN */
void game_on(int* day) { // Masih perlu tambah parameter (Player)
    /* KAMUS */
    boolean isGoing;
    /* ALGORITMA */
    isGoing = true;
    while (isGoing) {
        preparation_phase(*day);
        main_phase(day,&isGoing);
    }
    // Terminasi program
}

/* NEW GAME */
void new_game() {
    /* KAMUS */
    char* nama;
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


/* END OF RESERVE */


/* RESERVED FOR PREPRATATON PHASE */
void preparation_phase(int day) { // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;
    JAM CJam;
    JAM OPJam;
    JAM SisaJam;
    int Need_Money;
    JAM Need_Time;

    /* ALGORITMA */
    /* Inisialisasi */
    CJam = MakeJAM(21,0);
    OPJam = MakeJAM(9,0);
    Need_Money = 0;
    Need_Time = MakeJAM(0,0);

    status = true;

    /* Looping preparation phase */
    while (status) {
        printf("Preparation phase day %d\n",day);
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

        SisaJam = Durasi(CJam,OPJam)
        if (JAMToMenit(SisaJam) != 0) {
            if (Minute(SisaJam) == 0) {
                print("Time Remaining: %d hour(s)\n",Hour(SisaJam));
            } else {
                print("Time Remaining: %d hour(s) %d minute(s)\n",Hour(SisaJam),Minute(SisaJam));
            }
        } else {
            print("Time Remaining: 0");
        }
        
        // Panggil status jumlah aksi, waktu dan uang yang dibutuhkan
        // Menampilkan Count_isi stack aski : TBA

        // Menampilkan total waktu yang dibutuhkan
        if (JAMToMenit(Need_Time) != 0) {
            if (Minute(Need_Time) == 0) {
                print("Total waktu yang dibutuhkan: %d hour(s)\n",Hour(Need_Time));
            } else {
                print("Total waktu yang dibutuhkan: %d hour(s) %d minute(s)\n",Hour(Need_Time),Minute(Need_Time));
            }
        } else {
            print("Total waktu yang dibutuhkan: 0");
        }
        // Menampilkan total uang yang dibutuhkan:
        print("Total uang yang dibutuhkan: %d", Need_Money);
        
        // Panggil input dan jalankan
        input_prepration_phase(&status);   // Not finished, tambah parameter yang kurang
        
    }
}

// Not finished, tambah parameter yang kurang
void input_prepration_phase(boolean* status) {
    /* KAMUS */
    Kata W, A, S, D, Build, Upgrade, Buy, Undo, Execute, Main;
    
    W.Length = 1;
    W.TabKata[0] = 'w';
    A.Length = 1;
    A.TabKata[0] = 'a';
    S.Length = 1;
    S.TabKata[0] = 's';
    D.Length = 1;
    D.TabKata[0] = 'd';

    Build.Length = 5;
    Build.TabKata[0] = 'b';
    Build.TabKata[1] = 'u';
    Build.TabKata[2] = 'i';
    Build.TabKata[3] = 'l';
    Build.TabKata[4] = 'd';

    Upgrade.Length = 7;
    Upgrade.TabKata[0] = 'u';
    Upgrade.TabKata[1] = 'p';
    Upgrade.TabKata[2] = 'g';
    Upgrade.TabKata[3] = 'r';
    Upgrade.TabKata[4] = 'a';
    Upgrade.TabKata[5] = 'd';
    Upgrade.TabKata[6] = 'e';

    Buy.Length = 3;
    Buy.TabKata[0] = 'b';
    Buy.TabKata[1] = 'u';
    Buy.TabKata[2] = 'y';

    Undo.Length = 4;
    Undo.TabKata[0] = 'u';
    Undo.TabKata[1] = 'n';
    Undo.TabKata[2] = 'd';
    Undo.TabKata[3] = 'o';

    Execute.Length = 7;
    Execute.TabKata[0] = 'e';
    Execute.TabKata[1] = 'x';
    Execute.TabKata[2] = 'e';
    Execute.TabKata[3] = 'c';
    Execute.TabKata[4] = 'u';
    Execute.TabKata[5] = 't';
    Execute.TabKata[6] = 'e';

    Main.Length = 4;
    Main.TabKata[0] = 'm';
    Main.TabKata[1] = 'a';
    Main.TabKata[2] = 'i';
    Main.TabKata[3] = 'n';
    
    /* ALGORITMA */
    STARTKATA();
    while(!EndKata) {
        if ((IsKataSama(W,CKata)) || (IsKataSama(A,CKata)) || (IsKataSama(S,CKata)) || (IsKataSama(D,CKata))) {
            // Update peta
        } else if (IsKataSama(Build,CKata)) {
            // Lakukan build
        } else if (IsKataSama(Upgrade,CKata)) {
            // Lakukan upgrade
        } else if (IsKataSama(Buy,CKata)) {
            // Lakukan buy
        } else if (IsKataSama(Undo,CKata)) {
            // Lakukan undo
        } else if (IsKataSama(Execute,CKata)) {
            // Lakukan execute
        } else if (IsKataSama(Main,CKata)) {
            // Lakukan main
        } else {
            printf("Input tidak valid\n");
        }

        IgnoreBlank();
        ADVKATA(); //Cek kata selanjutnya
    }

}


/* END OF RESERVED */


int main_phase(int* day, boolean* isGoing) { //parameternya masih kurang ditambah lagi sama ADT ADT yg belom
    /* KAMUS */
    boolean status;
    char* input;
    /* ALGORITMA */
    status = true;
    //disini masukin fungsi random buat antrian
    //spawn antrian
    Queue antrian;
    MakeQueue(&antrian,5);
    for (int i = 0; i<5; i++){
        //proses isi antrian
    }

    while (status) {
        printf("//Mengeksekusi perintah dari stack //\n");
        printf("Main phase day %d\n", day);
        // PANGGIL FUNGSI GAMBAR PETA

        // PANGGIL LEGEND DATA
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");

        // PANGGIL STATUS PLAYER

        // PANGGIL CURENT, CLOSING, DAN TIME REMAINING

        // PANGGIL FUNGSI ANTRIAN

        // PANGGIL FUNGSI INPUT
        input = input_main_phase();

        // JALANKAN FUNGSI INPUT
    }
    *day++;

    return 0;
}

/* RESERVED FOR FUNCTION IN MAIN PHASE */
char* input_main_phase() {
    /* KAMUS */
    char* input_user;
    char* valid_input[9] = {"w","a","s","d","serve","repair","detail","office","prepare"};
    boolean valid = false;

    int i = 0;

    /* ALGORITHM */
    do {
        printf("Masukkan Perintah :\n");
        scanf("%s",&input_user); /* JANGAN LUPA NANTI MASUKINNYA KE ADT MESIN KATA / MESIN KARAKTER */

        while (!valid && i<9) {
            if (!strcmp(input_user,valid_input[i])) {   // Note, strcmp kalau sama malah 0
                valid = true;
            } else {
                i++;
            }
        }
        
        if (!valid) {
           printf("Perintah salah, coba lagi\n"); 
        }
        
    } while (!valid);

    return input_user;
}


void action_input_main(char* input,boolean status) { // Tambah parameter player sama map buat diupdate, 
/* Menjalankan perintah input */

/* KAMUS*/

/* ALGORITMA */
    if ((!strcmp("w",input)) || (!strcmp("a",input)) || (!strcmp("s",input)) || (!strcmp("d",input))) {
        // Update peta
    } else if (!strcmp("serve",input)) {
        // Lakukan serve
    } else if (!strcmp("repair",input)) {
        // Lakukan repair
    } else if (!strcmp("detail",input)) {
        // Lakukan detail
    } else if (!strcmp("office",input)) {
        // Lakukan office
    } else if (!strcmp("prepare",input)) {
        // Lakukan prepare
    } else {
        printf("Something wrong happened\n");
    }
}





/* END OF RESERVED OF MAIN PHASE FUNCTION/PROCEDURE */
