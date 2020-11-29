/* File: listrek.c */
/* 
- NIM       : 13519020
- Nama      : Muhammad Azhar Faturahman
- Tanggal   : 18 November 2020
- Topik     : ADT list Linier
- Deskripsi : Membuat prototipe listrek.h
*/
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "bintree_wahana.h"

/* *** Manajemen Memori *** */
List_Wahana Alokasi_Listrek (Wahana X)
/* Mengirimkan address_Wahana hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_Wahana tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* KAMUS LOKAL */
    address_Wahana P;
    /* ALGORITMA */
    P = (address_Wahana) malloc(sizeof(ElmtList_Wahana));
    if (P!=Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi_Listrek (List_Wahana P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_Wahana P */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */
/* Pemeriksaan Kondisi List_Wahana */
int IsEmpty_Listrek(List_Wahana L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (L == Nil);
}

int IsOneElmt_Listrek(List_Wahana L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmpty_Listrek(L)) {
        return 0;
    } else {
        return (Next(L)==Nil);
    }
}

/* *** Selektor *** */
Wahana FirstElmt_Listrek (List_Wahana L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return Info(L);
}

List_Wahana Tail(List_Wahana L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return Next(L);
}

/* *** Konstruktor *** */
List_Wahana Konso(Wahana e, List_Wahana L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
    /* KAMUS LOKAL */
    address_Wahana P;
    /* ALGORITMA */
    P = Alokasi_Listrek(e);
    if (P != Nil) {
        Next(P) = L;
        return P;
    } else {
        return L;
    }
    
}

List_Wahana KonsB(List_Wahana L, Wahana e)
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
    /* KAMUS LOKAL */
    address_Wahana P;
    /* ALGORITMA */
    P = Alokasi_Listrek(e);
    if (P!=Nil) {
        if (IsEmpty_Listrek(L)) {
            return Alokasi_Listrek(e);
        } else {
            Next(L) = KonsB(Tail(L),e);
            return L;
        }
    } else {
        return L;
    }
    
}

/* *** Operasi Lain *** */
List_Wahana Copy (List_Wahana L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmpty_Listrek(L)) {
        return Nil;
    } else {
        return Konso(FirstElmt_Listrek(L),Copy(Tail(L)));
    }
    
}

void MCopy (List_Wahana Lin, List_Wahana *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
    /* KAMUS LOKAL */
    List_Wahana LTemp;
    /* ALGORITMA */
    if (IsEmpty_Listrek(Lin)) { // Basis
        *Lout = Nil;
    } else {            // rekurens
        MCopy(Tail(Lin),&LTemp);
        *Lout = Konso(FirstElmt_Listrek(Lin),LTemp);
    }
}

List_Wahana Concat (List_Wahana L1, List_Wahana L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmpty_Listrek(L1)) {  // Basis
        return Copy(L2);
    } else {            // Rekurens
        return (Konso(FirstElmt_Listrek(L1), Concat(Tail(L1), L2)));
    }
}

void MConcat (List_Wahana L1, List_Wahana L2, List_Wahana *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
    /* KAMUS LOKAL */
    List_Wahana LTemp;
    /* ALGORITMA */
    if (IsEmpty_Listrek(L1)) {  // Basis
        *LHsl = Copy(L2);
    } else {            // Rekurens
        MConcat(Tail(L1),L2,&LTemp);
        *LHsl = Konso(FirstElmt_Listrek(L1),LTemp);
    }
}

void PrintList (List_Wahana L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (!IsEmpty_Listrek(L)) {
        if (Tail(L) != Nil) {
            printf("%s -> ",Nama_Wahana(FirstElmt_Listrek(L)));
        } else {
            printf("%s\n",Nama_Wahana(FirstElmt_Listrek(L)));
        }
        PrintList(Next(L));
        
    }
}

int NbElmtList (List_Wahana L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmpty_Listrek(L)) {   // Basis
        return 0;
    } else {            // Rekurens
        return 1 + NbElmtList(Tail(L));
    }
}

boolean Search (List_Wahana L, Wahana X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmpty_Listrek(L)) {
        return false;
    } else {
        if (ID_Wahana(FirstElmt_Listrek(L)) == ID_Wahana(X)) {
            return true;
        } else {
            return Search(Tail(L),X);
        }
    }
}

/*** Operasi-Operasi Lain ***/
List_Wahana InverseList (List_Wahana L)
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmpty_Listrek(L)) {   // Basis
        return Nil;
    } else {            // Rekurens
        return KonsB(InverseList(Tail(L)),FirstElmt_Listrek(L));
    }
}