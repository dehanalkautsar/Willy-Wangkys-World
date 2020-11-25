/* File: bintree.c */
/* 
- NIM       : 13519020
- Nama      : Muhammad Azhar Faturahman
- Tanggal   : 26 November 2020
- Topik     : ADT list Linier
- Deskripsi : Membuat prototipe bintree.h
*/
/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

/* Modul lain yang digunakan : */
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "listrek.h"
#include "boolean.h"


/* Global Variabel */

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    /* KAMUS LOKAL */
    addrNode P;
    /* ALGORITMA */
    P = AlokNode(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *P = Tree(Akar,L,R);
}

BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
{
    /* KAMUS LOKAL */
    infotype X;
    addrNode P;
    BinTree L,R;
    int nL, nR;
    /* ALGORITMA */
    if (n==0) {     // Basis
        return Nil;
    } else {        // Rekursif
        /* Buat akar */
        scanf("%d",&X);
        P = AlokNode(X);
        if (P != Nil) {     // Cek apakah alokasi berhasil
            /* Partisi sisa node sebagai anak kiri dan anak kanan */
            nL = n / 2;
            nR = n - nL - 1;    // Kalau n genap, maka pohon berat ke kiri
            L = BuildBalanceTree(nL);
            R = BuildBalanceTree(nR);
            Left(P) = L;
            Right(P) = R;
        }
        return P;
    }
}

/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* KAMUS LOKAL */
    addrNode P;
    /* ALGORITMA */
    P = (addrNode) malloc(sizeof(Node));
    if (P != Nil) {
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (P == Nil);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        return (Left(P) == Nil && Right(P)==Nil);
    }
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Left(P) != Nil && Right(P) == Nil);
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Left(P) == Nil && Right(P) != Nil);
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Left(P) != Nil && Right(P) != Nil);
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("(");
    if (!IsTreeEmpty(P))    // Basis 0
    {
        printf("%d",Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }
    printf(")"); 
}

void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("(");
    if (!IsTreeEmpty(P))    // Basis 0
    {
        PrintInorder(Left(P));
        printf("%d",Akar(P));
        PrintInorder(Right(P));
    }
    printf(")");
}

void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("(");
    if (!IsTreeEmpty(P))    // Basis 0
    {
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d",Akar(P));
    }
    printf(")");  
}

void PrintTreeLevel(BinTree P, int h, int level) {
    /* KAMUS */
    int i;
    /* ALGORITMA */
    if (!IsTreeEmpty(P))
    {
        for (i = 0; i < h*level; i++) {
            printf(" ");
        }
        printf("%d\n",Akar(P));
        PrintTreeLevel(Left(P),h,level+1);
        PrintTreeLevel(Right(P),h,level+1);
    }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    PrintTreeLevel(P,h,0);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{   
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {           // Basis 0
        return false;
    } else {                        // Rekurens
        if (Akar(P)==X) {        
            return true;
        } else {                        
            return SearchTree(Left(P), X) || SearchTree(Right(P), X);
        }
    } 
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {   // Basis 0
        return 0;
    } else {            // Rekurens
        return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
    }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {            // Basis 0
        return 0;
    } else if (IsTreeOneElmt(P)) {   // Basis 1
        return 1;
    } else {                         // Rekurens
        return NbDaun(Left(P)) + NbDaun(Right(P));
    }
}

boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {   // Basis 0
        return true;
    } else {                // Rekurens
        if (Right(P) != Nil) {
            return false;
        } else {
            return IsSkewLeft(Left(P));
        }
    }
}

boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {   // Basis 0
        return true;
    } else {                // Rekurens
        if (Left(P) != Nil) {
            return false;
        } else {
            return IsSkewRight(Right(P));
        }
    }
}

int Level(BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    // Asumsi X pasti ada di pohon
    if (SearchTree(P,X)) {
        if (Akar(P) == X) {     // Basis
            return 1;
        } else {                // Rekurens
            if (SearchTree(Left(P),X)) {
                return 1 + Level(Left(P),X);
            } else {
                return 1 + Level(Right(P),X);
            }
        }
    }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    /* KAMUS LOKAL */
    int Tinggi_L, Tinggi_R;
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {               // Basis 0
        return 0;
    } else {                            // Rekurens
        Tinggi_L = Tinggi(Left(P));
        Tinggi_R = Tinggi(Right(P));
        if (Tinggi_L >= Tinggi_R) {
            return 1 + Tinggi_L;
        } else {
            return 1 + Tinggi_R;
        }
    }
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(*P)) {          // Basis 0
        *P = Tree(X,Nil,Nil);
    } else {                        // Rekurens
        AddDaunTerkiri(&Left(*P),X);
    }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    // Asumsi X pasti ada di pohon
    if (!IsTreeEmpty(*P)) {
        if (Akar(*P)==X && IsTreeOneElmt(*P)) {   // Basis 1
            if (Kiri) {
                Left(*P) = Tree(Y,Nil,Nil);
            } else {
                Right(*P) = Tree(Y,Nil,Nil);
            }
        } else {                              // Rekurens
            if (SearchTree(Left(*P),X)) {
                AddDaun(&Left(*P), X, Y, Kiri);
            } else {
                AddDaun(&Right(*P), X, Y, Kiri);
            }
        }
    }
}   

void DelDaunTerkiri(BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
{
    /* KAMUS LOKAL */
    addrNode N;
    /* ALGORITMA */
    if (IsTreeOneElmt(*P)) {    // Basis 1
        *X = Akar(*P);
        N = *P;
        *P = Nil;
        DealokNode(N);
    } else if (!IsTreeEmpty(*P)) {
        if (IsUnerRight(*P)) {
            DelDaunTerkiri(&Right(*P),X);
        } else {
            DelDaunTerkiri(&Left(*P), X);
        }
    }
}

void DelDaun(BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
    /* KAMUS LOKAL */
    addrNode N;
    /* ALGORITMA */
    if (!IsTreeEmpty(*P)) {
        if (Akar(*P)==X && IsTreeOneElmt(*P)) {    // Basis 1
            N = *P;
            *P = Nil;
            DealokNode(N);
        } else {                                // Rekurens
            if (IsUnerRight(*P)) {
                DelDaun(&Right(*P),X);
            } else if (IsUnerLeft(*P)) {
                DelDaun(&Left(*P),X);
            } else {
                DelDaun(&Left(*P),X);
                DelDaun(&Right(*P),X);
            }
        }    
    }

}

List MakeListDaun(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    /* KAMUS LOKAL */
    /*
    address E;
    List L;
    */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {               // Basis 0
        return Nil;
    } else {
        if (IsTreeOneElmt(P)) {         // Basis 1
            /*
            E = Alokasi(Akar(P));
            if (E != Nil) {
                L = E; 
            } else {
                L = Nil;
            }
            return L;
            */
            return Alokasi(Akar(P));    
        } else {                        // Rekurens
            /*
            if (IsUnerLeft(P)) {
                L = MakeListDaun(Left(P));
            } else if (IsUnerRight(P)) {
                L = MakeListDaun(Right(P));
            } else {
                L = Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
            }
            return L; 
            */
            return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
        }
    }
}

List MakeListPreorder(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    /* KAMUS LOKAL */
    address E;
    List L;
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {           // Basis 0
        return Nil;
    } else {                        // Rekurens
        E = Alokasi(Akar(P)); 
        if (E != Nil) {
            Next(E) = MakeListPreorder(Left(P));
            L = Concat(E, MakeListPreorder(Right(P)));
        } else {
            L = Nil;
        }
        return L;
    }
}

List MakeListLevel(BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {   // Kasus kosong
        return Nil;
    } else {
        if (N==1) {                     // Basis 1
            return Alokasi(Akar(P));   
        } else {                        // Rekurens
            return Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1));
        }
    }
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P)) {   // Basis 0
        return false;
    } else {                // Rekurens
        if (Akar(P)==X) {
            return true;
        } else {
            if (X<Akar(P)) {
                return BSearch(Left(P), X);
            } else {
                return BSearch(Right(P), X);
            }
        }
    }
}

void InsSearch(BinTree *P, infotype X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(*P)) {      // Basis kosong
        MakeTree(X,Nil,Nil,P);
    } else {                    // Rekurens
        if (X < Akar(*P)) {
            return InsSearch(&Left(*P), X);
        } else if (X > Akar(*P)) {
            return InsSearch(&Right(*P), X);
        }
    }
}

void DelNode(BinTree *P, addrNode *q)
/* I.S. P adalah pohon biner tidak kosong */
/* F.S. q berisi salinan nilai daun terkanan */
/* Proses: */
/* Memakai nilai q yang global*/
/* Traversal sampai NODE terkanan, copy nilai NODE terkanan P, salin nilai ke q semula */
/* q adalah NODE TERKANAN yang akan dihapus */
{
    /* KAMUS LOKAL */
    //extern addrNode q;
    /* ALGORITMA */
    if (Right(*P) != Nil) {
        DelNode(&Right(*P),q);
    } else {
        Akar(*q) = Akar(*P);
        *q = *P;
        *P = Left(*P);
    }
}

void DelBtree(BinTree *P, infotype X)
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
{
    /* KAMUS LOKAL */
    addrNode q;
    /* ALGORITMA */
    if (X < Akar(*P)) {
        DelBtree(&Left(*P), X);
    } else if (X > Akar(*P)) {
        DelBtree(&Right(*P), X);
    } else {        // Hapus node ini
        q = *P;
        if (IsTreeOneElmt(*P)) {
            *P = Nil;
        } else if (IsUnerLeft(*P)) {
            *P = Left(q);
        } else if (IsUnerRight(*P)) {
            *P = Right(q);
        } else {
            DelNode(&Left(q),&q);
        }
        DealokNode(q);
    }

}

