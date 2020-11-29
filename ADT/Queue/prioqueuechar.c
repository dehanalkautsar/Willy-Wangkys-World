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
    idx a, b;
    //temp infotypeQ;

    /* Algoritma */
    // Kasus Kosong
    if (isEmptyPQ(*Q))
    {
        Head(*Q)++;
        Tail(*Q)++;
        // Isi info tail
        InfoTail(*Q).kesabaran = X.kesabaran;
        InfoTail(*Q).WahanaString = X.WahanaString;
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

        while (a != Head(*Q) && ElmtQ(*Q, a).kesabaran > X.kesabaran)
        {
            // Tukar urutan
            //temp = 
            ElmtQ(*Q, b) = ElmtQ(*Q, a);
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

        if (ElmtQ(*Q, a).kesabaran <= X.kesabaran)
        {
            ElmtQ(*Q, b) = X;
        }
        else
        { // ElmtQ(*Q,a).prio > X.prio
            // Tukar posisi
            ElmtQ(*Q, b) = ElmtQ(*Q, a);
            // Isi elemen
            ElmtQ(*Q, a) = X;
        }
    }
}

void Dequeue(PrioQueue *Q, infotypeQ *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    // infotypeQ temp;
    // temp.kesabaran = InfoHead(*Q).kesabaran;
    // *X = temp;
    // temp.WahanaString = ;
    (*X).kesabaran = InfoHead(*Q).kesabaran;
    (*X).WahanaString = InfoHead(*Q).WahanaString;
    // Kesabaran(*X) = InfoHead(*Q).Kesabaran;
    // QWahana(*X) = InfoHead(*Q).WahanaAntrean;
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

void kurangSabar(PrioQueue *Q)
{

    idx P;
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
}

void tendangAntrean(PrioQueue *Q)
{

    idx P;
    P = Head(*Q);

    while (P != Tail(*Q) && ((*Q).T[P].kesabaran == 0))
    {
        infotypeQ X;
        Dequeue(Q, &X);
    }

    // 5 5 5 5 5 5
    // 4 4 4 4 4 4

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
//     idx info = info;
//     PrintInfo(Wahana);
//     printf(", kesabaran: %d\n", kesabaran);
// }

void printAntrean(PrioQueue Q, BinTree T[])
{
    // Seg Fault gatau kenapa


    infotypeQ CurrElmt;

    while (!isEmptyPQ(Q))
    {
        printf("cek print\n");
        Dequeue(&Q,&CurrElmt);
        int kesabaran = CurrElmt.kesabaran;
        printf("cek print 2 \n");
        WahanaAntrean LWahana = CurrElmt.WahanaString;

        PrintInfoLQ(LWahana,T);
        printf(", kesabaran : %d\n", kesabaran);
    }

    // int P;
    // P = Head(Q);
    
    // printf("P : %d\n",P);
    // // dari kepala
    // while (P != Tail(Q))
    // {
    //     printf("ini P %d\n", P);
    //     infotypeQ R = Q.T[P]; //kesabaran sama list wahana
    //     int kesabaran = R.kesabaran;
    //     WahanaAntrean Wahana = R.WahanaString;

    //     PrintInfoLQ(Wahana, T);
    //     printf(", kesabaran: %d\n", kesabaran);

    //     if (P == (MaxEl(Q) - 1))
    //     {
    //         P = 0;
    //     }
    //     else
    //     {
    //         P++;
    //     }
    // }

    // if (P != NilQ)
    // {
    //     infotypeQ R = Q.T[P]; //kesabaran sama list wahana
    //     int kesabaran = R.kesabaran;
    //     WahanaAntrean Wahana = R.Wahana;
    //     idx info = info;
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


//sebelum panggil, makeEmpty dulu
void makeQueue(PrioQueue *Q, Map WahanaMap)
/* Prosedur ini buat bikin antriannya */
{
    //char *wahana[] = {"Wangky's World", "Subway rush", "Fear Factor"};
    int Rand = totalWahana(WahanaMap);

    //MakeEmpty(Q, nMax);
    infotypeQ X;

    if (isEmptyPQ(*Q)){
        for (int i = 0; i < 5; i++)
        {
            //printf("cek2\n");
            int r = (rand() % (Rand));
            // ini bikin list wahana yang di antre
            CreateEmpty(&X.WahanaString);
            for (int j = 0; j < r; j++)
            {
                // ini insert list wahana yang di random
                int k = (rand() % (Rand-2)+2);
                //printf("%d\n", infoIdWahana(WahanaMap,k));
                if ((infoIdWahana(WahanaMap,k) != 1) && (infoIdWahana(WahanaMap,k) != 2) && (infoIdWahana(WahanaMap,k) != 5)){
                    InsVLast(&X.WahanaString, infoIdWahana(WahanaMap, k));
                    // printf();
                }
            }
            
            if (!IsEmptyW(X.WahanaString)){
                //X.Wahana = random dari array wahana customer
                X.kesabaran = 5;
                //X.kesabaran = (rand() % (10 - 2 + 1)+2);
                Enqueue(Q, X);
            }
            
        }
    }else{ 
        //printf("cek4\n");
        int k = Tail(*Q);
        for (int i = k; i < Tail(*Q)+5; i++)
        {
            int r = (rand() % Rand);
            // ini bikin list wahana yang di antre
            CreateEmpty(&X.WahanaString);
            for (int j = 0; j < r; j++)
            {
                // ini insert list wahana yang di random
                int nameWahana = (rand() % Rand);
                if ((infoIdWahana(WahanaMap,nameWahana) != 1) && (infoIdWahana(WahanaMap,nameWahana) != 2) && (infoIdWahana(WahanaMap,nameWahana) != 5)){
                    InsVLast(&X.WahanaString, infoIdWahana(WahanaMap, k));
                }
            }
            if (!IsEmptyW(X.WahanaString)){
                //X.Wahana = random dari array wahana customer
                X.kesabaran = 5;
                //X.kesabaran = (rand() % (10 - 2 + 1)+2);
                Enqueue(Q, X);
            }
        }
    }
}

void bikinQueue(PrioQueue *Q){

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
//     idx p;

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
