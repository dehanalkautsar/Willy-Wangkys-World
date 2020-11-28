/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef prioqueuechar_H
#define prioqueuechar_H

#include "boolean.h"
#include "linkedlistQ.h"
#include "../Map/map.h"
#include "../Wahana/bintree_wahana.h"

#define NilQ -1
/* Konstanta untuk mendefinisikan index tak terdefinisi */

/* Definisi elemen dan index */

typedef struct
{
    int kesabaran; /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
    WahanaAntrean WahanaString;   /* elemen Wahana */
} infotypeQ;
typedef int index; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    infotypeQ *T; /* tabel penyimpan elemen */
    index HEAD; /* alamat penghapusan */
    index TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueChar, maka akses elemen : */
#define Kesabaran(e) (e).kesabaran
#define QWahana(e) (e).Wahana
#define InfoQ(e) (e).info
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define ElmtQ(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyPQ(PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullPQ(PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty(PrioQueue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueue *Q, infotypeQ X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue(PrioQueue *Q, infotypeQ *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueue(PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
void kurangSabar(PrioQueue *Q);
void printAntrean(PrioQueue Q);
void makeQueue(PrioQueue *Q, Map WahanaMap);
void tendangAntrean(PrioQueue *Q);

#endif
