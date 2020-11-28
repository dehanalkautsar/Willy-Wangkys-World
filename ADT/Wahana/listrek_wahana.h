// /* File: listrek.h */
// /* ADT list linier dengan representasi pointer */
// /* Implementasi list linier secara rekursif */

// #ifndef _LISTREK_Wahana_H_
// #define _LISTREK_Wahana_H_

// #include "boolean.h"
// #include "bintree_wahana.h"
// #include "../Jam/jam.h"
// #include "../Player/pemain.h"

// #define Nil NULL

// /* Definisi Type */
// typedef struct tElmtlist_Wahana* address_Wahana;
// typedef address_Wahana List_Wahana;
// // typedef int Wahana;
// typedef struct tElmtlist_Wahana { 
// 	Wahana info;
// 	address_Wahana next;
// } ElmtList_Wahana;

// /* Definisi list : */
// /* List_Wahana kosong : L = Nil */


// /* Deklarasi  nama untuk variabel kerja */ 
// /*  	L : List_Wahana */
// /*  	P : address_Wahana 	*/
// /* Maka penulisan First(L) menjadi L */
// /*                P.info menjadi Info(P); P.next menjadi Next(P) */

// /* Selektor */
// #define Info(P) (P)->info
// #define Next(P) (P)->next

// /* *** Manajemen Memori *** */
// address_Wahana Alokasi_Listrek (Wahana X);
// /* Mengirimkan address_Wahana hasil alokasi sebuah elemen */
// /* Jika alokasi berhasil, maka address_Wahana tidak Nil, dan misalnya menghasilkan P, 
//   maka Info(P) = X, Next(P) = Nil */
// /* Jika alokasi gagal, mengirimkan Nil */
// void Dealokasi_Listrek (address_Wahana P);
// /* I.S. P terdefinisi */
// /* F.S. P dikembalikan ke sistem */
// /* Melakukan dealokasi/pengembalian address_Wahana P */

// /* *** Primitif-primitif yang harus direalisasikan *** */

// /* Pemeriksaan Kondisi List_Wahana */
// int IsEmpty_Listrek(address_Wahana L);
// /* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
// int IsOneElmt_Listrek(address_Wahana L);
// /* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

// /* *** Selektor *** */
// Wahana FirstElmt_Listrek (List_Wahana L);
// /* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
// List_Wahana Tail(List_Wahana L);
// /* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

// /* *** Konstruktor *** */
// List_Wahana Konso(Wahana e, List_Wahana L);
// /* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
// e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
// List_Wahana KonsB(List_Wahana L, Wahana e);
// /* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
// /* e harus dialokasi terlebih dahulu */
// /* Jika alokasi e gagal, mengirimkan L */ 

// /* *** Operasi Lain *** */
// List_Wahana Copy (List_Wahana L);
// /* Mengirimkan salinan list L (menjadi list baru) */
// /* Jika ada alokasi gagal, mengirimkan L */ 
// void MCopy (List_Wahana Lin, List_Wahana *Lout);
// /* I.S. Lin terdefinisi */
// /* F.S. Lout berisi salinan dari Lin */
// /* Proses : menyalin Lin ke Lout */
// List_Wahana Concat (List_Wahana L1, List_Wahana L2);
// /* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
// /* Jika ada alokasi gagal, menghasilkan Nil */
// void MConcat (List_Wahana L1, List_Wahana L2, List_Wahana *LHsl);
// /* I.S. L1, L2 terdefinisi */
// /* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
// /* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
// void PrintList (List_Wahana L);
// /* I.S. L terdefinisi. */
// /* F.S. Setiap elemen list dicetak. */
// int NbElmtList (List_Wahana L);
// /* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
// boolean Search (List_Wahana L, Wahana X);
// /* Mengirim true jika X adalah anggota list, false jika tidak */

// /*** Operasi-Operasi Lain ***/
// List_Wahana InverseList (List_Wahana L);
// /* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
// Semua elemen list baru harus dialokasi */
// /* Jika alokasi gagal, hasilnya list kosong */


// #endif