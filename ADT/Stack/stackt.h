//
//  NIM             : 13519080
//  Nama            : Daru Bagus Dananjaya
//  Tanggal         : 20 Oktober 2020
//  Topik Praktikum :   Stack
//  Deskripsi       :
//

/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
//
//  Created by Daru Bagus Dananjaya on 20/10/20.
//

#ifndef stackt_h
#define stackt_h

#include <stdio.h>
#include "boolean.h"
#include "../Point/point.h"


#define Nil -1
#define MaxEl 10
/* Nil adalah stack dengan elemen kosong . */

typedef int infotype;
typedef int address;   /* indeks tabel */

typedef struct {
  char* command;
  Koordinat koordinatWahana; //untuk build dan upgrade
  char* namaWahanaOrMaterial; //untuk build, upgrade, dan buy
  int idUpgrade; //untuk upgrade
  int jumlahMaterial; //untuk buy
} IsiStack;

#define infoCommand(iS) (iS).command
#define infoKoordinatWahana(iS) (iS).koordinatWahana
#define infoNamaWahanaOrMaterial(iS) (iS).namaWahanaOrMaterial
#define infoIDUpgrade(iS) (iS).idUpgrade
#define infoJumlahMaterial(iS) (iS).jumlahMaterial

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  IsiStack T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

void AddElementIsiStack( IsiStack *isi, char* command, Koordinat koordinat, char* namaWahana, int IDUpgradeWahana, int jumlah);
/* I.S = 'isi' terdefinisi
   F.S = 'isi' telah dimasukkan elemen elemen didalam parameter*/
void InversStack(Stack *S);
/*
Buat balik stack biar ntar execute nya urut
*/

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, IsiStack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, IsiStack* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif /* stackt_h */
