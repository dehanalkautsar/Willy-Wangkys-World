/* File : prioqueuechar.c */
/* 
- NIM       : 13519020
- Nama      : Muhammad Azhar Faturahman
- Tanggal   : 08 Oktober 2020
- Topik     : ADT Queue
- Deskripsi : Membuat Prototipe prioqueuechar.h */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "prioqueuechar.h"

/* INDEKS YANG DIPAKAI [0..MaxEl(Q)-1] (ini berisi sejumlah MaxEl) */

/* ********* Prototype ********* */
boolean isEmptyPQ(PrioQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Tail(Q) == NilQ && Head(Q) == NilQ);
}

boolean IsFullPQ(PrioQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt(PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (isEmptyPQ(Q))
    {
        return 0;
    }
    else
    {
        return ((MaxEl(Q) + Tail(Q) - Head(Q)) % MaxEl(Q)) + 1;
    }
}

/* *** Kreator *** */
void MakeEmpty(PrioQueue *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotypeQ *)malloc((Max) * sizeof(infotypeQ));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
    }
    else
    {
        MaxEl(*Q) = 0;
    }
    Head(*Q) = NilQ;
    Tail(*Q) = NilQ;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueue *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    Head(*Q) = NilQ;
    Tail(*Q) = NilQ;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueue *Q, infotypeQ X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    /* Kamus Lokal */
    index a, b;

    /* Algoritma */
    // Kasus Kosong
    if (isEmptyPQ(*Q))
    {
        Head(*Q)++;
        Tail(*Q)++;
        // Isi info tail
        InfoTail(*Q).kesabaran = X.kesabaran;
        InfoTail(*Q).Wahana = X.Wahana;
    }
    else
    {                 // Kasus Tidak Kosong
        a = Tail(*Q); // a berada di tail Q awal

        // Pindah tail Q
        if (Tail(*Q) == (MaxEl(*Q) - 1))
        {
            Tail(*Q) = 0;
        }
        else
        {
            Tail(*Q)++;
        }

        b = Tail(*Q); // b berada di tail Q yang sudah ditambah

        while (a != Head(*Q) && Elmt(*Q, a).kesabaran > X.kesabaran)
        {
            // Tukar urutan
            Elmt(*Q, b) = Elmt(*Q, a);
            // b sekarang maju ke a
            b = a;
            // a sekarang maju kedepan
            if (a == 0)
            {
                a = MaxEl(*Q) - 1;
            }
            else
            {
                a--;
            }
        } // Kondisi keluar loop antara a berada di head atau sudah menemukan posisi

        if (Elmt(*Q, a).kesabaran <= X.kesabaran)
        {
            Elmt(*Q, b) = X;
        }
        else
        { // Elmt(*Q,a).prio > X.prio
            // Tukar posisi
            Elmt(*Q, b) = Elmt(*Q, a);
            // Isi elemen
            Elmt(*Q, a) = X;
        }
    }
}

void Dequeue(PrioQueue *Q, infotypeQ *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1)
    { //Kondisi bersisa 1 elemen
        Head(*Q) = NilQ;
        Tail(*Q) = NilQ;
    }
    else
    { //Kondisi sisa elemen masih banyak
        if (Head(*Q) == (MaxEl(*Q) - 1))
        {
            Head(*Q) = 0;
        }
        else
        {
            Head(*Q)++;
        }
    }
}

void kurangSabar(PrioQueue *Q){
    
    index P;
    P = Head(*Q);

    while (P != Tail(*Q))
    {
        (*Q).T[P].kesabaran -= 1;

        if (P == (MaxEl(*Q) - 1))
        {
            P = 0;
        }
        else
        {
            P++;
        }

    }
    


    // if (P != NilQ)
    // {
    //     infotypeQ R = (*Q).T[P]; //kesabaran sama list wahana
    //     int kesabaran = R.kesabaran;
    //     WahanaAntrean Wahana = R.Wahana;
    //     index info = info;
    //     PrintInfo(Wahana);
    //     printf(", kesabaran: %d\n", kesabaran);
    // }
}

void printAntrean(PrioQueue Q, BinTree T)
{
    index P;
    P = Head(Q);

    while (P != Tail(Q))
    {
        infotypeQ R = Q.T[P]; //kesabaran sama list wahana
        int kesabaran = R.kesabaran;
        WahanaAntrean Wahana = R.Wahana;

        PrintInfo(Wahana);
        printf(", kesabaran: %d\n", kesabaran);

        if (P == (MaxEl(Q) - 1))
        {
            P = 0;
        }
        else
        {
            P++;
        }

    }
    
    // if (P != NilQ)
    // {
    //     infotypeQ R = Q.T[P]; //kesabaran sama list wahana
    //     int kesabaran = R.kesabaran;
    //     WahanaAntrean Wahana = R.Wahana;
    //     index info = info;
    //     PrintInfo(Wahana);
    //     printf(", kesabaran: %d\n", kesabaran);
    // }
    //         printf("%d %c\n",Elmt(Q,p).kesabaran, Elmt(Q,p).info);

    //         if (p==(MaxEl(Q)-1)) {
    //             p = 0;
    //         } else {
    //             p++;
    //         }

    //     } // Berhenti ketika p sudah di tail atau p kosong
    //     if (p!=NilQ) {
    //         printf("%d %c\n",Elmt(Q,p).kesabaran, Elmt(Q,p).info);
    //     }
}



void makeQueue(PrioQueue *Q, Map WahanaMap)
/* Prosedur ini buat bikin antriannya */
{
    //char *wahana[] = {"Wangky's World", "Subway rush", "Fear Factor"};
    int Rand = totalWahana(WahanaMap);

    
    MakeEmpty(Q, 5);
    infotypeQ X;

    for (int i = 0; i < 5; i++)
    {
        int r = (rand() % Rand);
        CreateEmpty(&X.Wahana);
        for (int j = 0; j < r; j++)
        {
            InsVLast(&X.Wahana, infoIdWahana(WahanaMap, r));
        }
        //X.Wahana = random dari array wahana customer
        X.kesabaran = 5;
        //X.kesabaran = (rand() % (10 - 2 + 1)+2);
        Enqueue(Q, X);
    }
}

// /* Operasi Tambahan */
// void PrintPrioQueueChar (PrioQueue Q)
// /* Mencetak isi queue Q ke layar */
// /* I.S. Q terdefinisi, mungkin kosong */
// /* F.S. Q tercetak ke layar dengan format:
// <prio-1> <elemen-1>
// ...
// <prio-n> <elemen-n>
// #
// */
// {
//     /* Kamus Lokal */
//     index p;

//     /* Algoritma */
//     p = Head(Q);

//     while (p != Tail(Q)) {
//         printf("%d %c\n",Elmt(Q,p).kesabaran, Elmt(Q,p).info);

//         if (p==(MaxEl(Q)-1)) {
//             p = 0;
//         } else {
//             p++;
//         }

//     } // Berhenti ketika p sudah di tail atau p kosong
//     if (p!=NilQ) {
//         printf("%d %c\n",Elmt(Q,p).kesabaran, Elmt(Q,p).info);
//     }

//     printf("#\n");

// }
