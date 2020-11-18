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
#include "../ADT/Player/player.h"

int main(){
    char* choice;
    
    printf("// Welcome to Willy wangky's fum factory!!////\n New game / load game / exit? //\n");
    
    do{
        scanf("%s", &choice);
    }while (choice=="new" || choice=="load" || choice =="exit");
    
    if (choice=="new"){
        char* nama;
        printf("Memulai permainan baru..");
        printf("Masukkan nama:");
        scanf("%s", &nama);   
        //new game
    }else if(choice=="load"){
        //continue game
    }else{
            printf("// Thanks for playing!!! //");
            return 0;
        }
    
    return 0;
}

/* RESERVED FOR PREPRATATON PHASE */

void preparation_phase(int* day) { // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;
    char* input;
    /* ALGORITMA */
    
    /* Inisialisasi */
    status = true;
    while (status) {
        printf("Preparation phase day %d\n",*day);
        // Panggil fungsi gambar peta
        
        // Panggil legend peta

        // Panggil status player

        // Panggil current waktu dan limit waktu

        // Panggil status aksi, waktu dan uang yang dibutuhkan

        // Panggil input
        input = input_prepration_phase();   // Sudah divalidasi
        // Jalankan aksi input
        action_prepration_phase(input,status); // Not finished
    }
    *day++;
}


char* input_prepration_phase() {
    /* KAMUS */
    char input_user[10];
    char* valid_input[10] = {"w","a","s","d","build","upgrade","buy","undo","execute","main"};
    boolean valid = false;

    /* ALGORITMA */
    do {
        printf("Masukkan perintah :\n");
        scanf("%s",input_user);

        int i = 0;
        while (!valid && i<10) {
            if (!strcmp(input_user,valid_input[i])) {   // Note, strcmp kalau sama malah return 0
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

void action_prepration_phase(char* input,boolean status) { // Tambah parameter player sama map buat diupdate, 
/* Menjalankan perintah input */

/* KAMUS*/

/* ALGORITMA */
    if ((!strcmp("w",input)) || (!strcmp("a",input)) || (!strcmp("s",input)) || (!strcmp("d",input))) {
        // Update peta
    } else if (!strcmp("build",input)) {
        // Lakukan build
    } else if (!strcmp("upgrade",input)) {
        // Lakukan upgrade
    } else if (!strcmp("buy",input)) {
        // Lakukan buy
    } else if (!strcmp("undo",input)) {
        // Lakukan undo
    } else if (!strcmp("execute",input)) {
        // Lakukan execute
    } else if (!strcmp("main",input)) {
        // Lakukan main
    } else {
        printf("Something wrong happened");
    }
}

/* END OF RESERVED */

int main_phase(int day) {
    /* KAMUS */
    boolean status;
    char* input;
    /* ALGORITMA */
    status = true;
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
        scanf("%s",&input_user);

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
    } else if (!strcmp("build",input)) {
        // Lakukan build
    } else if (!strcmp("upgrade",input)) {
        // Lakukan upgrade
    } else if (!strcmp("buy",input)) {
        // Lakukan buy
    } else if (!strcmp("undo",input)) {
        // Lakukan undo
    } else if (!strcmp("execute",input)) {
        // Lakukan execute
    } else if (!strcmp("main",input)) {
        // Lakukan main
    } else {
        printf("Something wrong happened");
    }
}




/* END OF RESERVED */
