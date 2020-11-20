/*   Nama        : Muhammad Dehan Al Kautsar
     NIM         : 13519200
     Topik       : Pra Praktikum Minggu 9 - List Linier Berkait
     Judul       : listlinier.c
     Tanggal     : 4 November 2020 */

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "linkedlistQ.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
     return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
     First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
     ElmtList *P = (ElmtList *) malloc(sizeof (ElmtList));

     if (P == Nil) {
          return Nil;
     }
     else {
          (P)->info = X;
          (P)->next = Nil;
          return P;
     }
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
     free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
     address P;
     if (First(L) == Nil) {
          return Nil;
     }
     else {
          P = First(L);
          while (P != Nil) {
               if (Info(P) == X) {
                    return P;
               }
               else {
                    P = Next(P);
               }
          }
          return Nil;
     }
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
     address Node = First(L);
     boolean found = false;

     if (!IsEmpty(L)) {
          while (!found && Node != Nil) {
               if (Node == P) {
                    found = true;
               }
               else {
                    Node = Next(Node);
               }
          }
     }
     //keluar looping

     return found;
}
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
     address Prec = Nil;
     address P = First(L);
     boolean found = false;

     while (!found && P != Nil) {
          if (Info(P) == X) {
               found = true;
          }
          else {
               Prec = P;
               P = Next(P);
          }
     }
     if (found) {
          return Prec;
     }
     else {
          return Nil;
     }
     
     
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
     address P = Alokasi(X);

     if (P != Nil) {
          if (IsEmpty(*L)) {
               First(*L) = P;
          }
          else {
               Next(P) = First(*L);
               First(*L) = P;
          }
     }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
     address P = Alokasi(X);
     address Node = First(*L);

     if (P != Nil) {
          if (IsEmpty(*L)) {
               First(*L) = P;
          }
          else {
               while (Next(Node) != Nil) {
                    Node = Next(Node);
               }
               //Next(Node) = Nil
               Next(Node) = P;
          }
     }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
     address P = First(*L);
     address NextNode;

     *X = Info(P);
     NextNode = Next(P);
     First(*L) = NextNode;
     Dealokasi(&P);

}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
     address CurrentNode;

     DelLast(L,&CurrentNode);
     *X = Info(CurrentNode);
     Dealokasi(&CurrentNode);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
     Next(P) = First(*L);
     First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
     address Node = First(*L);
     address AfterNode = Next(Node);
     if (IsEmpty(*L)) {
          InsertFirst(L,P);
     }
     else {
          while (Node != Prec) {
               Node = Next(Node);
               AfterNode = Next(Node);
          }
          //Node = Prec
          Next(P) = AfterNode;
          Next(Node) = P;
     }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
     address Node = First(*L);
     if (IsEmpty(*L)) {
          InsertFirst(L,P);
     }
     else {
          while (Next(Node) != Nil) {
               Node = Next(Node);
          }
          Next(Node) = P;
     }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
     *P = First(*L);
     address Suksesor = Next(*P);

     First(*L) = Suksesor;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
     address P = First(*L);
     address PrevNode = Nil;
     boolean found = false;

     while(P != Nil && !found) {
          if (Info(P) == X) {
               found = true;
          }
          else {
               PrevNode = P;
               P = Next(P);
          }
     }

     if (found) {
          if (PrevNode == Nil) { //list satu elemen atau elemen pertama
               DelFirst(L,&P);
          }
          else { //elemen di tengah atau akhir
               Next(PrevNode) = Next(P);
          }
          Dealokasi(&P);
     }
     
     
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
     address PrevNode = Nil;
     *P = First(*L);

     while(Next(*P) != Nil) {
          PrevNode = *P;
          *P = Next(*P);
     }
     if (PrevNode == Nil) { //1 elemen atau elemen pertama
          DelFirst(L,P);
     }
     else {
          Next(PrevNode) = Nil;
     }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
     address NextP;

     *Pdel = First(*L);
     while (*Pdel != Prec) {
          *Pdel = Next(*Pdel);
     }
     *Pdel = Next(*Pdel);
     NextP = Next(*Pdel);
     Next(Prec) = NextP;
}
