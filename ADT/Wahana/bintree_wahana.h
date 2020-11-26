/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type Wahana, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_Wahana_H_
#define _BINTREE_Wahana_H_

#define Nil NULL
/* Modul lain yang digunakan : */
#include "boolean.h"
// #include "point.h"
#include "jam.h"
#include "pemain.h"


/* ADT Wahana */
typedef struct tElmt_Wahana
{
   int ID;
   char Nama[32];
   int Harga;
   // Koordinat Lokasi;
   char Deskripsi[256];
   int Kapasitas;
   // history upgrade Wahana
   JAM Durasi;
   // Ukuran Wahana (Bonus)
   // Buat Upgrade Wahana
   int Upgrade_Cost;
   Material Upgrade_Material[2];
   // Status Wahana
   boolean statusWahana;
} Elmt_Wahana;

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */
/* Makro Wahana */
typedef Elmt_Wahana Wahana;

/* *** Definisi Type Pohon Biner *** */
typedef struct tNode *addrNode;
typedef struct tNode
{
   Wahana info;
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
#define Harga_Wahana(W) W.Harga
#define Deskripsi_Wahana(W) W.Deskripsi
#define Kapasitas_Wahana(W) W.Kapasitas
#define Durasi_Wahana(W) W.Durasi
#define Upgrade_Cost(W) W.Upgrade_Cost
#define Upgrade_Material(W,i) W.Upgrade_Material[i]


/* ADT WAHANA */
/* Gunakan ini buat database material */
void init_material(Material* Database_Material,char* namaFileMaterial);
/* Inisialisasi database dengan Database_Material[10] */
/* Gunakan ini buat bikin wahana */
void init_wahana(BinTree* Bintree_Wahana,char* namaFileWahana, Material Database_Material[]);
/* Karena passing by reference, harus pake ini */
Wahana CopyWahana(Wahana W);
Material CopyMaterial(Material M);
/* Searching */
addrNode Search_DatabaseWahana(BinTree T1, BinTree T2, BinTree T3, int ID);
addrNode Search_Wahana(BinTree T, int ID);

/* Buat Upgrade */
/* Cek dulu apakah wahana bisa diupgrade */
Wahana Wahana_Pindah_Node(addrNode W, boolean kiri);

void Read_File_Material(Material* List_M,char* nama_file);
void Read_File_Wahana(Wahana *List_W, char *nama_file, Material Database_Material[]);
void Print_Tree_Wahana(BinTree T);
void Make_Tree_Wahana(BinTree *Tree_Wahana, Wahana List_W[], Material Database_M[]);
Material Make_Material(int ID, char Nama[], int Harga);
Wahana MakeWahana(int ID, char Nama[], int Harga, char Deskripsi[], int Kapasitas, int Durasi_Menit, int Upgrade_Biaya, Material Upgrade_M[]);
/* KONSTRUKTOR Wahana */

/* *** Konstruktor *** */
BinTree Tree(Wahana Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(Wahana Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */

/* Manajemen Memory */
addrNode AlokNode(Wahana X);
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

/* *** Searching *** */
boolean SearchTree(BinTree P, int ID);
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
int Level(BinTree P, int ID);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
int Tinggi(BinTree P);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, Wahana X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, int ID, Wahana Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, Wahana *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, Wahana X);
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
// List MakeListDaun (BinTree P);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,

#endif
