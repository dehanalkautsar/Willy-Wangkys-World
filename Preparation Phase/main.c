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
    
    repeat{
        scanf("%s", &choice);
    }until(choice=="new" || choice=="load" || choice =="exit")
    
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

int preparation_phase(int day) { // Parameternya masih harus ditambah ADT Player, Peta
    /* KAMUS */
    boolean status;

    /* ALGORITMA */
    
    /* Inisialisasi */

    
    status = true;
    while (status) {
        printf("Preparation phase day %d\n",day);
        // Panggil fungsi gambar peta
        
        // Panggil legend peta

        // Panggil status player

        // Panggil current waktu dan limit waktu

        // Panggil status aksi, waktu dan uang yang dibutuhkan

        // Panggil input
        
        // Jalankan aksi input
    }
    
}

/* RESERVED FOR FUNCTION IN PREPRATATON PHASE */
char* input_prepration_phase() {
    /* KAMUS */
    char* input_user;
    char* valid_input[10] = {"w","a","s","d","build","upgrade","buy","undo","execute","main"};
    boolean isValid = fa

    do {
        printf("Masukkan perintah :\n");
        scanf("%s",&input_user);
    } while ();
    

    return input_user;
}







/* END OF RESERVED */

int main_phase(int day) {
    /* KAMUS */
    boolean status;
    /* ALGORITMA */
    status = true;
    while (status) {
        printf("//Mengeksekusi perintah dari stack //\n")
        printf("Main phase day %d\n", day);
        // PANGGIL FUNGSI GAMBAR PETA

        // PANGGIL LEGEND DATA

        // PANGGIL STATUS PLAYER

        // PANGGIL CURENT, CLOSING, DAN TIME REMAINING

        // PANGGIL FUNGSI ANTRIAN

        // PANGGIL FUNGSI INPUT

        // JALANKAN FUNGSI INPUT
    }

    return 0;
}

/* RESERVED FOR FUNCTION IN MAIN PHASE */
char* input_main_phase() {
    /* KAMUS */
    char* input_user;
    char* valid_input[5] =
    /* ALGORITHM */
    printf("Masukkan Perintah :\n");
    scanf("%s",&input_user);

    return input_user;
}






/* END OF RESERVED 
