/*   Nama        : Muhammad Dehan Al Kautsar
     NIM         : 13519200
     Topik       : Pra Praktikum Minggu 3 - ADT List (Implementasi Array)
     Judul       : arraypos.c
     Tanggal     : 8 September 2020 */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listimplementasiarray.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabACTBAHAN * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
     int i;
     for (i=IdxMin;i <= IdxMax; i++) {
          ActOrBarang(*T,i) = "";
          DurasiOrHarga(*T,i) = ValUndef;
     }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabACTBAHAN T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
     int count = 0;
     int i = IdxMin;
     while (((DurasiOrHarga(T,i) != ValUndef)) && i<=IdxMax)
     {
          count = count + 1;
          i++;
     }
     return count;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabACTBAHAN T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
     return IdxMax+1-IdxMin;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabACTBAHAN T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
     return IdxMin;
}
IdxType GetLastIdx (TabACTBAHAN T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
     return NbElmt(T)+IdxMin-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabACTBAHAN T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
     return (i>=IdxMin && i<=IdxMax);
}
boolean IsIdxEff (TabACTBAHAN T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
     return(i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabACTBAHAN T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
     return (NbElmt(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabACTBAHAN T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
     return (NbElmt(T) == IdxMax+1);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabACTBAHAN * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
     int N;
     char* nilaiIdx1;
     int nilaiIdx2;
     int i;
     scanf("%d\n", &N);
     while ((N>=0 && N<=MaxNbEl(*T)) == false) {
          scanf("%d\n", &N);
     }
     if (N==0) {
          MakeEmpty(T);
     }
     else {
          MakeEmpty(T);
          for ( i = IdxMin; i < N; i++)
          {
               scanf("%c\n", &nilaiIdx1);
               ActOrBarang(*T,i) = nilaiIdx1;
               scanf("%d\n", &nilaiIdx2);
               DurasiOrHarga(*T,i) = nilaiIdx2;
          }
     }
}
void TulisIsiTab (TabACTBAHAN T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong:
     - NAMA 1
     - NAMA 2
     - NAMA 3
     - dst

 */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
     int i;
     if (IsEmpty(T)) {
          printf("[]");
     }
     else {
          for ( i = 0; i < NbElmt(T); i++)
          {
               printf("     - %c\n", ActOrBarang(T,i));
          }
     }
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabACTBAHAN T, char* X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
     int i=IdxMin;
     if (IsEmpty(T)) {
          return IdxUndef;
     }
     else {
          while ((ActOrBarang(T,i)!=X) && i<=GetLastIdx(T))
          {
               i++;
          }
          if (i<=GetLastIdx(T)) {
               return i;
          }
          else {
               return IdxUndef;
          }
     }
}
boolean SearchB (TabACTBAHAN T, char* X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
     int i = GetFirstIdx(T);
     boolean found = false;
     while (i<=GetLastIdx(T) && found==false)
     {
          if (ActOrBarang(T,i)==X)
          {
          found = true;
     }
     i++;
     }
     return found;
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabACTBAHAN * T, char* X, int Y)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
     int i=IdxMin;
     if (IsEmpty(*T)) {
          ActOrBarang(*T,i) = X;
          DurasiOrHarga(*T,i) = Y;
     }
     else {
          while (DurasiOrHarga(*T,i) != ValUndef) {
               i++;
          }
          ActOrBarang(*T,i) = X;
          DurasiOrHarga(*T,i) = Y;
     }
}
void DelLastEl (TabACTBAHAN * T, char* * X, int * Y)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
     int i;
     i = GetLastIdx(*T);
     *X = ActOrBarang(*T,i);
     *Y = DurasiOrHarga(*T,i);
     DurasiOrHarga(*T,i) = ValUndef;
     ActOrBarang(*T,i) = "";
}