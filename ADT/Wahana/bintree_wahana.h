/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type wahana, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_WAHANA_H_
#define _BINTREE_WAHANA_H_

#define Nil NULL
/* Modul lain yang digunakan : */
#include "boolean.h"
// #include "point.h"
#include "jam.h"
// #include "pemain.h"

/* ADT UPGRADE WAHANA */
typedef struct tUpgrade_Wahana
{
   char *Nama_Upgrade;
   int Cost_Upgrade;
   // Material yang dibutuhkan
   // Material Bahan_Upgrade;

} Upgrade_Wahana;

/* ADT WAHANA */
typedef struct tElmt_Wahana
{
   int ID;
   char *Nama;
   int Harga;
   // Koordinat Lokasi;
   char *Deskripsi;
   int Kapasitas;
   // history upgrade wahana
   JAM Durasi;
   // Ukuran Wahana (Bonus)
   Upgrade_Wahana Left_Upgrade;
   Upgrade_Wahana Right_Upgrade;
   boolean statusWahana;
} Elmt_Wahana;

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */
/* Makro Wahana */
typedef Elmt_Wahana wahana;

/* *** Definisi Type Pohon Biner *** */
typedef struct tNode *addrNode;
typedef struct tNode
{
   wahana info;
   addrNode left;
   addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

#define ID_Wahana(W) W.ID
#define Nama_Wahana(W) W.Nama
#define Tipe_Wahana(W) W.Tipe
#define Harga_Wahana(W) W.Harga
// #define Lokasi_Wahana(W) W.Lokasi
#define Deskripsi_Wahana(W) W.Deskripsi
#define Kapasitas_Wahana(W) W.Kapasitas
#define Durasi_Wahana(W) W.Durasi
#define Left_Upgrade(W) W.Left_Upgrade
#define Right_Upgrade(W) W.Right_Upgrade

#define Nama_Upgrade(U) U.Nama_Upgrade
#define Cost_Upgrade(U) U.Cost_Upgrade
#define Bahan_Upgrade(U) U.Bahan_Upgrade

/* KONSTRUKTOR WAHANA */

/* *** Konstruktor *** */
BinTree Tree(wahana Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(wahana Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */

/* Manajemen Memory */
addrNode AlokNode(wahana X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

// /* *** Traversal *** */
// void PrintPreorder (BinTree P);
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh:
//    (A()()) adalah pohon dengan 1 elemen dengan akar A
//    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
// void PrintInorder (BinTree P);
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh:
//    (()A()) adalah pohon dengan 1 elemen dengan akar A
//    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
// void PrintPostorder (BinTree P);
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh:
//    (()()A) adalah pohon dengan 1 elemen dengan akar A
//    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
// void PrintTree (BinTree P, int h);
// /* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
// /* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
// /* Penulisan akar selalu pada baris baru (diakhiri newline) */
// /* Contoh, jika h = 2:
// 1) Pohon preorder: (A()()) akan ditulis sbb:
// A
// 2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
// A
//   B
//   C
// 3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
// A
//   B
//     D
//   C
//     E
// */

/* *** Searching *** */
boolean SearchTree(BinTree P, wahana X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt_Tree(BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, wahana X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
int Tinggi(BinTree P);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, wahana X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, wahana X, wahana Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, wahana *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, wahana X);
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
// List MakeListDaun (BinTree P);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
//    jika semua alokasi list berhasil.
//    Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListPreorder (BinTree P);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
//    dengan urutan preorder, jika semua alokasi berhasil.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListLevel (BinTree P, int N);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
//    yang levelnya=N, jika semua alokasi berhasil.
//    Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */

#endif
