//
//  NIM             : 13519080
//  Nama            : Daru Bagus Dananjaya
//  Tanggal         : 20 Oktober 2020
//  Topik Praktikum : Stack
//  Deskripsi       :
//
//  Created by Daru Bagus Dananjaya on 20/10/20.
//

#include "stackt.h"
#include "../Point/point.h"


void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElS */
/* jadi indeksnya antara 0.. MaxElS */
/* Ciri stack kosong : TOP berNilSai NilS */
{
    Top(*S)=NilS;
}


void AddElementIsiStack(IsiStack *isi, char* command, Koordinat koordinat, char* namaWahana, int IDUpgradeWahanaOrIDMaterial, int jumlahMaterial, Material need_material[], int need_money, int need_menit, int ID_Map)
/* I.S = 'isi' terdefinisi
   F.S = 'isi' telah dimasukkan elemen elemen didalam parameter*/
{
    strcpy(infoCommand(*isi) , command);
    infoKoordinatWahana(*isi) = koordinat;
    strcpy(infoNamaWahanaOrMaterial(*isi),namaWahana);
    infoIDUpgrade(*isi) = IDUpgradeWahanaOrIDMaterial; // Dipake juga buat ID material
    infoJumlahMaterial(*isi) = jumlahMaterial;
    for (int i = 0; i < 5; i++) {
        infoNeedMaterial(*isi,i) = CopyMaterial(need_material[i]);
    }
    infoNeedMoney(*isi) = need_money;
    infoNeedMenit(*isi) = need_menit;
    isi->ID_Map = ID_Map; 
}
void InversStack(Stack *S) {
    Stack TempS;
    TempS = *S;

    if (!IsStackEmpty(*S)){
        IsiStack X;
        Pop(S, &X);
    }

    if (!IsStackEmpty(TempS)){
        IsiStack X;
        Pop(&TempS, &X);
        Push(S, X);
    }
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==NilS);
}
boolean IsStackFull (Stack S)
/* Mengirim true jika tabel penampung NilSai elemen stack penuh */
{
    return (Top(S)==(MaxElS-1));
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, IsiStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmpty(*S)){
        Top(*S) = 0;
    }
    else{
        Top(*S)++;
    }
    InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, IsiStack* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilSai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    
    if (Top(*S)==0){
        Top(*S)= NilS;
    }
    else{
        Top(*S)--;
    }
}
