#include "bintree_wahana.h"
#include "boolean.h"
#include "string.h"

#include <stdlib.h>
#include <stdio.h>

/* *** Konstruktor *** */
BinTree Tree (wahana Akar, BinTree L, BinTree R) {
	addrNode X = AlokNode(Akar);
	if (X != Nil) {
		Left(X) = L;
		Right(X) = R;
	}
	return X;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (wahana Akar, BinTree L, BinTree R, BinTree *P) {
	*P = Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */

/* Manajemen Memory */
addrNode AlokNode (wahana X) {
	addrNode P = (addrNode) malloc(sizeof(wahana));
	if (P!=Nil){
		Akar(P) = X;
		Left(P) = Right(P) = Nil;
	}
	
	return P;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode (addrNode P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P) {
/* Mengirimkan true jika P adalah pohon biner kosong */
	return P == Nil;
}

boolean IsTreeOneElmt (BinTree P) {
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
	if (!IsTreeEmpty(P))
		return Left(P) == Nil && Right(P) == Nil;
	else
		return false;
}

boolean IsUnerLeft (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
	if (!IsTreeEmpty(P))
		return Left(P) != Nil && Right(P) == Nil;
	else
		return false;
}

boolean IsUnerRight (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
	if (!IsTreeEmpty(P))
		return Left(P) == Nil && Right(P) != Nil;
	else
		return false;
}

boolean IsBiner (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
	if (!IsTreeEmpty(P))
		return Left(P) != Nil && Right(P) != Nil;
	else
		return false;
}


/* *** Traversal *** */
void PrintPreorder (BinTree P) {
	printf("(");
	if (!IsTreeEmpty(P)) {
		printf("%d", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder (BinTree P) {
	printf("(");
	if (!IsTreeEmpty(P)) {
		PrintInorder(Left(P));
		printf("%d", Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder (BinTree P) {
	printf("(");
	if (!IsTreeEmpty(P)) {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d", Akar(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTreeRec (BinTree P, int level, int h) {
	if (!IsTreeEmpty(P)) {
		int i;
		for (i = 0; i < level * h; i++)
			printf(" ");
		printf("%d\n", Akar(P));
		PrintTreeRec(Left(P), level+1, h);
		PrintTreeRec(Right(P), level+1, h);
	}
}
void PrintTree (BinTree P, int h) {
	PrintTreeRec(P, 0, h);
}
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

/* *** Searching *** */
boolean SearchTree (BinTree P, wahana X) {
	if (P == Nil)
		return false;
	else if (ID_Wahana(Akar(P))==ID_Wahana(X))
		return true;
	else
		return SearchTree(Left(P), X) || SearchTree(Right(P), X);
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt_Tree (BinTree P) {
	if (P == Nil)
		return 0;
	else
		return 1 + NbElmt_Tree(Left(P)) + NbElmt_Tree(Right(P));
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun (BinTree P) {
	if (IsTreeEmpty(P))
		return 0;
	else if (IsTreeOneElmt(P))
		return 1;
	else
		return NbDaun(Left(P)) + NbDaun(Right(P));
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft (BinTree P) {
	if (IsTreeEmpty(P))
		return true;
	else
		return Right(P) == Nil && IsSkewLeft(Left(P));
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight (BinTree P) {
	if (IsTreeEmpty(P))
		return true;
	else
		return Left(P) == Nil && IsSkewRight(Right(P));
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level (BinTree P, wahana X) {
	if (ID_Wahana(Akar(P))==ID_Wahana(X))
		return 1;
	else if (SearchTree(Left(P),X))
		return 1 + Level(Left(P), X);
	else
		return 1 + Level(Right(P), X);
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
int Tinggi (BinTree P) {
	if (IsTreeEmpty(P))
		return 0;
	else {
		int a = Tinggi(Left(P));
		int b = Tinggi(Right(P));
		if (a > b)
			return 1 + a;
		else
			return 1 + b;
	}
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, wahana X) {
	if (IsTreeEmpty(*P))
		*P = Tree(X, Nil, Nil);
	else if (IsUnerRight(*P))
		Left(*P) = Tree(X,Nil,Nil);
	else
		AddDaunTerkiri(P, X);
}
// /* I.S. P boleh kosong */
// /* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun (BinTree *P, wahana X, wahana Y, boolean Kiri) {
	if (!IsTreeEmpty(*P)) {
		if (IsTreeOneElmt(*P) && ID_Wahana(Akar(*P))==ID_Wahana(X)) {
			if (Kiri)
				Left(*P) = Tree(Y, Nil, Nil);
			else
				Right(*P) = Tree(Y, Nil, Nil);
		} else {
			if (SearchTree(Left(*P), X))
				AddDaun(&Left(*P), X, Y, Kiri);
			else
				AddDaun(&Right(*P), X, Y, Kiri);
		}
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri (BinTree *P, wahana *X) {
	if (IsTreeOneElmt(*P))
		*X = Akar(*P), *P = Nil;
	else if (IsUnerRight(*P)) {
		if (IsTreeOneElmt(Right(*P))) {
			*X = Akar(Right(*P));
			DealokNode(Right(*P));
			Right(*P) = Nil;
		} else
			DelDaunTerkiri(&Right(*P), X);
	} else if (IsTreeOneElmt(Left(*P))) {
		*X = Akar(Left(*P));
		DealokNode(Left(*P));
		Left(*P) = Nil;
	} else
		DelDaunTerkiri(&Left(*P), X);
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun (BinTree *P, wahana X) {
	if (!IsTreeEmpty(*P)) {
		if (IsTreeOneElmt(*P)) {
			if (ID_Wahana(Akar(*P))==ID_Wahana(X))
				DealokNode(*P), *P = Nil;
		} else if (Left(*P) != Nil && ID_Wahana(Akar(Left(*P)))==ID_Wahana(X) && IsTreeOneElmt(Left(*P))) {
			DealokNode(Left(*P));
			Left(*P) = Nil;
		} else if (Right(*P) != Nil && ID_Wahana(Akar(Right(*P)))==ID_Wahana(X) && IsTreeOneElmt(Right(*P))) {
			DealokNode(Right(*P));
			Right(*P) = Nil;
		}
		if (!IsTreeEmpty(*P))
			DelDaun(&Left(*P), X), DelDaun(&Right(*P), X);
	}
}
// /* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
// /* F.S. Semua daun bernilai X dihapus dari P. */
// List MakeListDaun (BinTree P) {
// 	if (IsTreeEmpty(P))
// 		return Nil;
// 	if (IsTreeOneElmt(P))
// 		return Alokasi(ID_Wahana(Akar(P)));
// 	else
// 		return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
// }
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
//    jika semua alokasi list berhasil.
//    Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListPreorder (BinTree P) {
// 	if (IsTreeEmpty(P))
// 		return Nil;
// 	if (IsTreeOneElmt(P))
// 		return Alokasi(Akar(P));
// 	else
// 		return Konso(Akar(P), Concat(MakeListPreorder(Left(P)), MakeListPreorder(Right(P))));
// }
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
//    dengan urutan preorder, jika semua alokasi berhasil.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListLevel (BinTree P, int N) {
// 	if (!IsTreeEmpty(P) && N == 1)
// 		return Alokasi(Akar(P));
// 	else if (!IsTreeEmpty(P))
// 		return Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1));
// 	else
// 		return Nil;
// }
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
//    yang levelnya=N, jika semua alokasi berhasil.
//    Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
