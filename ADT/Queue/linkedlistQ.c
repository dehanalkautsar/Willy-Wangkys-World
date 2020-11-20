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

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
     address P = First(L);
     printf("[");
     if (!IsEmpty(L)) {
          while (Next(P) != Nil) {
               printf("%d,", Info(P));
               P = Next(P);
          }
          //Next(P) = Nil
          printf("%d", Info(P));
     }
     printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
     int count = 0;
     address P = First(L);

     if (!IsEmpty(L)) {
          while (P != Nil) {
               count++;
               P = Next(P);
          }
     }

     return count;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
     address P = First(L);
     infotype Nmin = Info(P);

     while(P != Nil) {
          if (Info(P) < Nmin) {
               Nmin = Info(P);
          }
          P = Next(P);
     }
     return Nmin;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
     address P = First(L);
     infotype Nmin = Info(P);

     while(P != Nil) {
          if (Info(P) < Nmin) {
               Nmin = Info(P);
          }
          P = Next(P);
     }
     return Search(L,Nmin);
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
     address P = First(L);
     infotype Nmax = Info(P);

     while(P != Nil) {
          if (Info(P) > Nmax) {
               Nmax = Info(P);
          }
          P = Next(P);
     }
     return Nmax;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
     address P = First(L);
     infotype Nmax = Info(P);

     while(P != Nil) {
          if (Info(P) > Nmax) {
               Nmax = Info(P);
          }
          P = Next(P);
     }
     return Search(L,Nmax);
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
     address P = First(L);
     infotype total = 0;
     float avrg;
     int NBelmt = NbElmt(L);

     while (P != Nil) {
          total = total + Info(P);
          P = Next(P);
     }
     avrg = (float) total / (float) NBelmt;

     return avrg;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
     address P;

     if (IsEmpty(*L1)) {
          First(*L3) = First(*L2);
          First(*L2) = Nil;
     } 
     else if (IsEmpty(*L2)) {
          First(*L3) = First(*L1);
          First(*L1) = Nil;
     }
     else {
          P = First(*L1);
          while (Next(P) != Nil) {
               P = Next(P);
          }
          Next(P) = First(*L2);
          First(*L3) = First(*L1);
          First(*L1) = Nil;
          First(*L2) = Nil;
     }
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
     infotype X;
     while (!IsEmpty(*L)) {
          DelVFirst(L,&X);
     }
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
     address CurrNode = First(*L);
     address PrevNode = Nil;
     address tempNode; //menyimpan node temporary untuk iterasi node

     while (CurrNode != Nil) {
          tempNode = Next(CurrNode);
          Next(CurrNode) = PrevNode;
          PrevNode = CurrNode;
          CurrNode = tempNode;
     }

     First(*L) = PrevNode; //resolving elemen pertama
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
     List Newlist;
     address P = First(L);
     address TempAdd;
     boolean sign = true;

     CreateEmpty(&Newlist);

     while (P != Nil && sign) {
          TempAdd = Alokasi(Info(P));
          if (TempAdd == Nil) {
               DelAll(&Newlist);
               sign = false;
          }
          else {
               InsertFirst(&Newlist,TempAdd);
          }
          P = Next(P);
     }
     return Newlist;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
     First(*L1) = First(*L2);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
     List Newlist;
     address P = First(L);
     address TempAdd;
     boolean sign = true;

     CreateEmpty(&Newlist);

     while (P != Nil && sign) {
          TempAdd = Alokasi(Info(P));
          if (TempAdd == Nil) {
               DelAll(&Newlist);
               sign = false;
          }
          else {
               InsertLast(&Newlist,TempAdd);
          }
          P = Next(P);
     }
     return Newlist;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{

     *Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
     address P;

     CreateEmpty(L3);
     CpAlokList(L1,L3);

     P = First(*L3);
     while (Next(P) != Nil) {
          P = Next(P);
     }
     Next(P) = First(L2);
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
     CreateEmpty(L1);
     CreateEmpty(L2);
     int NumberElmt = NbElmt(L);
     address P = First(L);
     address tempadd;

     if (NumberElmt % 2 == 1) {
          while ( NbElmt(*L1)+1 <= NumberElmt/2) {
               tempadd = Alokasi(Info(P));
               if (tempadd != Nil) {
                    InsertLast(L1,tempadd);
               }
               P = Next(P);
          }
          while ( P != Nil) {
               tempadd = Alokasi(Info(P));
               if (tempadd != Nil) {
                    InsertLast(L2,tempadd);
               }
               P = Next(P);
          }
     }

     else {
          while ( NbElmt(*L1)+1 <= NumberElmt/2) {
               tempadd = Alokasi(Info(P));
               if (tempadd != Nil) {
                    InsertLast(L1,tempadd);
               }
               P = Next(P);
          }
          while ( P != Nil) {
               tempadd = Alokasi(Info(P));
               if (tempadd != Nil) {
                    InsertLast(L2,tempadd);
               }
               P = Next(P);
          }
     }
}
