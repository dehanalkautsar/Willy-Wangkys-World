/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type Wahana, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_WAHANA_H_
#define _BINTREE_WAHANA_H_

#define Nil NULL

/* Modul lain yang digunakan : */
#include "../Player/material.h"
// #include "../Player/pemain.h"
#include "boolean.h"
#include "../Jam/jam.h"

// typedef struct Material
// {
//   int ID;
//   char NamaMaterial[32];
//   int Harga;
//   int Kuantitas;
// } Material;

/* ADT Wahana */
typedef struct tElmt_Wahana
{
   int ID;
   char Nama[32];
   int Harga; // Harga tiket masuk bukan harga build
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

/* BAGIAN LISTREK */
/* Definisi Type */
typedef struct tElmtlist_Wahana *address_Wahana;

// typedef int Wahana;
typedef struct tElmtlist_Wahana
{
   Wahana info;
   address_Wahana next;
} ElmtList_Wahana;

/* Definisi list : */
/* List_Wahana kosong : L = Nil */

typedef address_Wahana List_Wahana;
/* Deklarasi  nama untuk variabel kerja */
/*  	L : List_Wahana */
/*  	P : address_Wahana 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next

/* BAGIAN TREE */
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
#define Status_Wahana(W) W.statusWahana
#define Upgrade_Material(W, i) W.Upgrade_Material[i]

/* ADT WAHANA */
/* Gunakan ini buat database material */
void init_material(Material *Database_Material, char *namaFileMaterial);
/* Inisialisasi database dengan Database_Material[10] */
/* Gunakan ini buat bikin wahana */
void init_wahana(BinTree *Bintree_Wahana, char *namaFileWahana, Material Database_Material[]);
/* Karena passing by reference, harus pake ini */
Wahana CopyWahana(Wahana W);
Material CopyMaterial(Material M);
/* Searching */
/* Ini buat semua database pohon */
addrNode Search_DatabaseWahana(BinTree Database_Wahana[], int ID);

/* Ini buat 1 pohon */
addrNode Search_Wahana(BinTree T, int ID);

/* Copy Material dan Wahana */
Material CopyMaterial(Material M);
Wahana CopyWahana(Wahana W);

/* Cek dulu apakah wahana bisa diupgrade */
Wahana Wahana_Pindah_Node(addrNode W, boolean kiri);

List_Wahana RiwayatUpgrade(int ID_Wahana, BinTree Database_W[]);

void Read_File_Material(Material *List_M, char *nama_file);
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

// #include "boolean.h"
// #include "bintree_wahana.h"
// #include "../Jam/jam.h"
// #include "../Player/pemain.h"

// #define Nil NULL

/* BAGIAN LISTREK */

/* *** Manajemen Memori *** */
List_Wahana Alokasi_Listrek(Wahana X);
/* Mengirimkan address_Wahana hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_Wahana tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi_Listrek(List_Wahana P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_Wahana P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List_Wahana */
int IsEmpty_Listrek(List_Wahana L);
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt_Listrek(List_Wahana L);
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
Wahana FirstElmt_Listrek(List_Wahana L);
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List_Wahana Tail(List_Wahana L);
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List_Wahana Konso(Wahana e, List_Wahana L);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List_Wahana KonsB(List_Wahana L, Wahana e);
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */

/* *** Operasi Lain *** */
List_Wahana Copy(List_Wahana L);
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
void MCopy(List_Wahana Lin, List_Wahana *Lout);
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
List_Wahana Concat(List_Wahana L1, List_Wahana L2);
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcat(List_Wahana L1, List_Wahana L2, List_Wahana *LHsl);
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList(List_Wahana L);
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList(List_Wahana L);
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search(List_Wahana L, Wahana X);
/* Mengirim true jika X adalah anggota list, false jika tidak */

/*** Operasi-Operasi Lain ***/
List_Wahana InverseList(List_Wahana L);
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

#endif
