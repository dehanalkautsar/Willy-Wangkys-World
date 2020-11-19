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
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Tail(Q)==Nil && Head(Q)==Nil);
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q)==MaxEl(Q));
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)) {
        return 0;
    } else {
        return ((MaxEl(Q) + Tail(Q) - Head(Q)) % MaxEl(Q))+1;
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotypeQ*) malloc((Max)*sizeof(infotypeQ));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
    } else {
        MaxEl(*Q) = 0;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotypeQ X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    /* Kamus Lokal */
    address a,b;

    /* Algoritma */
    // Kasus Kosong
    if (IsEmpty(*Q)) {
        Head(*Q)++; 
        Tail(*Q)++;
        // Isi info tail
        InfoTail(*Q) = X;   
    } else { // Kasus Tidak Kosong
        a = Tail(*Q); // a berada di tail Q awal

        // Pindah tail Q
        if (Tail(*Q)==(MaxEl(*Q)-1)) {
            Tail(*Q) = 0;
        } else {
            Tail(*Q)++;
        }

        b = Tail(*Q); // b berada di tail Q yang sudah ditambah

        while (a != Head(*Q) && Elmt(*Q,a).kesabaran > X.kesabaran) {
            // Tukar urutan
            Elmt(*Q,b) = Elmt(*Q,a);
            // b sekarang maju ke a
            b = a;
            // a sekarang maju kedepan
            if (a==0) {
                a = MaxEl(*Q) - 1;
            } else {
                a--;
            }
        } // Kondisi keluar loop antara a berada di head atau sudah menemukan posisi

        if (Elmt(*Q,a).kesabaran <= X.kesabaran) {
            Elmt(*Q,b) = X;
        } else { // Elmt(*Q,a).prio > X.prio
            // Tukar posisi
            Elmt(*Q,b) = Elmt(*Q,a);
            // Isi elemen
            Elmt(*Q,a) = X;
        }
        
    } 
}

void Dequeue (PrioQueueChar * Q, infotypeQ * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (NBElmt(*Q)==1) { //Kondisi bersisa 1 elemen
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else { //Kondisi sisa elemen masih banyak
        if (Head(*Q)==(MaxEl(*Q)-1)) {
            Head(*Q) = 0;
        } else {
            Head(*Q)++;
        }
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    /* Kamus Lokal */
    address p;

    /* Algoritma */
    p = Head(Q);

    while (p != Tail(Q)) {
        printf("%d %c\n",Elmt(Q,p).kesabaran, Elmt(Q,p).info);

        if (p==(MaxEl(Q)-1)) {
            p = 0;
        } else {
            p++;
        }

    } // Berhenti ketika p sudah di tail atau p kosong
    if (p!=Nil) {
        printf("%d %c\n",Elmt(Q,p).kesabaran, Elmt(Q,p).info);
    }

    printf("#\n");

}

