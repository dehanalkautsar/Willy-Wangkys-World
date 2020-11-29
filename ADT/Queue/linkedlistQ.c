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
boolean IsEmptyW(WahanaAntrean L)
/* Mengirim true jika list kosong */
{
     return First(L) == Nill;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(WahanaAntrean *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
     First(*L) = Nill;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotypeLQ X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nill, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nill */
/* Jika alokasi gagal, mengirimkan Nill */
{
     ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));

     if (P == Nill)
     {
          return Nill;
     }
     else
     {
          (P)->info = X;
          (P)->next = Nill;
          return P;
     }
}
void Dealokasi(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
     free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchLQ(WahanaAntrean L, infotypeLQ X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nill */
{
     address P;
     if (First(L) == Nill)
     {
          return Nill;
     }
     else
     {
          P = First(L);
          while (P != Nill)
          {
               if (Info(P) == X)
               {
                    return P;
               }
               else
               {
                    P = Next(P);
               }
          }
          return Nill;
     }
}

boolean FSearch(WahanaAntrean L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
     address Node = First(L);
     boolean found = false;

     if (!IsEmptyW(L))
     {
          while (!found && Node != Nill)
          {
               if (Node == P)
               {
                    found = true;
               }
               else
               {
                    Node = Next(Node);
               }
          }
     }
     //keluar looping

     return found;
}
address SearchPrec(WahanaAntrean L, infotypeLQ X)
/* Mengirimkan address elemen sebelum elemen yang Nillainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nill */
/* Jika P adalah elemen pertama, maka Prec=Nill */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
     address Prec = Nill;
     address P = First(L);
     boolean found = false;

     while (!found && P != Nill)
     {
          if (Info(P) == X)
          {
               found = true;
          }
          else
          {
               Prec = P;
               P = Next(P);
          }
     }
     if (found)
     {
          return Prec;
     }
     else
     {
          return Nill;
     }
}

/****************** PRIMITIF BERDASARKAN NillAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(WahanaAntrean *L, infotypeLQ X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nillai X jika alokasi berhasil */
{
     address P = Alokasi(X);

     if (P != Nill)
     {
          if (IsEmptyW(*L))
          {
               First(*L) = P;
          }
          else
          {
               Next(P) = First(*L);
               First(*L) = P;
          }
     }
}
void InsVLast(WahanaAntrean *L, infotypeLQ X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNillai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
     address P = Alokasi(X);
     address Node = First(*L);

     if (P != Nill)
     {
          if (IsEmptyW(*L))
          {
               First(*L) = P;
          }
          else
          {
               while (Next(Node) != Nill)
               {
                    Node = Next(Node);
               }
               //Next(Node) = Nill
               Next(Node) = P;
          }
     }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(WahanaAntrean *L, infotypeLQ *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nillai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
     address P = First(*L);
     address NextNode;

     *X = Info(P);
     NextNode = Next(P);
     First(*L) = NextNode;
     Dealokasi(&P);
}
void DelVLast(WahanaAntrean *L, infotypeLQ *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nillai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
     address CurrentNode;

     DelLast(L, &CurrentNode);
     *X = Info(CurrentNode);
     Dealokasi(&CurrentNode);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(WahanaAntrean *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
     Next(P) = First(*L);
     First(*L) = P;
}
void InsertAfter(WahanaAntrean *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
     address Node = First(*L);
     address AfterNode = Next(Node);
     if (IsEmptyW(*L))
     {
          InsertFirst(L, P);
     }
     else
     {
          while (Node != Prec)
          {
               Node = Next(Node);
               AfterNode = Next(Node);
          }
          //Node = Prec
          Next(P) = AfterNode;
          Next(Node) = P;
     }
}
void InsertLast(WahanaAntrean *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
     address Node = First(*L);
     if (IsEmptyW(*L))
     {
          InsertFirst(L, P);
     }
     else
     {
          while (Next(Node) != Nill)
          {
               Node = Next(Node);
          }
          Next(Node) = P;
     }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(WahanaAntrean *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
     *P = First(*L);
     address Suksesor = Next(*P);

     First(*L) = Suksesor;
}
void DelP(WahanaAntrean *L, infotypeLQ X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNillai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
     address P = First(*L);
     address PrevNode = Nill;
     boolean found = false;

     while (P != Nill && !found)
     {
          if (Info(P) == X)
          {
               found = true;
          }
          else
          {
               PrevNode = P;
               P = Next(P);
          }
     }

     if (found)
     {
          if (PrevNode == Nill)
          { //list satu elemen atau elemen pertama
               DelFirst(L, &P);
          }
          else
          { //elemen di tengah atau akhir
               Next(PrevNode) = Next(P);
          }
          Dealokasi(&P);
     }
}
void DelLast(WahanaAntrean *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
     address PrevNode = Nill;
     *P = First(*L);

     while (Next(*P) != Nill)
     {
          PrevNode = *P;
          *P = Next(*P);
     }
     if (PrevNode == Nill)
     { //1 elemen atau elemen pertama
          DelFirst(L, P);
     }
     else
     {
          Next(PrevNode) = Nill;
     }
}
void DelAfter(WahanaAntrean *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
     address NextP;

     *Pdel = First(*L);
     while (*Pdel != Prec)
     {
          *Pdel = Next(*Pdel);
     }
     *Pdel = Next(*Pdel);
     NextP = Next(*Pdel);
     Next(Prec) = NextP;
}

void PrintInfoLQ(WahanaAntrean L, BinTree T[])
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNillai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
     address P = First(L);
     printf("(");
     if (!IsEmptyW(L))
     {
          while (Next(P) != Nill)
          {
               addrNode N = Search_DatabaseWahana(T, Info(P));

               printf("%s, ", Nama_Wahana(Akar(N)));
               P = Next(P);
          }
          //Next(P) = Nill
          addrNode N = Search_DatabaseWahana(T, Info(P));
          printf("%s", Nama_Wahana(Akar(N)));
     }
     printf(")");
}
