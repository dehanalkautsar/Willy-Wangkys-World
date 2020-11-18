//
//  Nama            : Daru Bagus Dananjaya
//  NIM             : 13519080
//  Tanggal         : 24 September 2020
//  Topik Praktikum : ADT Matriks
//  Deskripsi       :

//
//  Created by Daru Bagus Dananjaya on 22/09/20.
//

#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return (i>=BrsMin && i <=BrsMax) && (j>=KolMin && j<=KolMax);
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return  BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return (NBrsEff(M)-1);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return (NKolEff(M)-1);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return (i>=GetFirstIdxBrs(M) && i <=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    
    for (indeks i= GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
        for (indeks j= GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    indeks i=GetFirstIdxBrs(*M);
    indeks j = GetFirstIdxKol(*M);
    ElType x;
    
    MakeMATRIKS(NB, NK, M);
    
    for (i= GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
            scanf("%d", &x);
            Elmt(*M, i, j) = x;
        }
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M);i++){
        for (indeks j = GetFirstIdxKol(M); j<= GetLastIdxKol(M);j++){
            printf("%d", Elmt(M, i,j));
            //jika M[i,j] bukan elemen kolom terakhir, maka dicetak spasi
            if (j != GetLastIdxKol(M)){
                printf(" ");
            }
        }
        if (i != GetLastIdxBrs(M)){
            printf("\n");
        }
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    MATRIKS MRes;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MRes);
    
    for (indeks i= GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1); i++){
        for (indeks j= GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++){
            Elmt(MRes, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }
    
    return MRes;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS MRes;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MRes);
    
    for (indeks i= GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1); i++){
        for (indeks j= GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++){
            Elmt(MRes, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }
    
    return MRes;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    MATRIKS MRes;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MRes);
    ElType result;
    
    //iterasi baris
    for (indeks i= GetFirstIdxBrs(MRes); i<=GetLastIdxBrs(MRes); i++){
        //iterasi kolom
        for (indeks j= GetFirstIdxKol(MRes); j<=GetLastIdxKol(MRes); j++){
            result = 0; //inisialisasi hasil perkalian dengan 0
            for (indeks k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++){
                //misal matriks 3x3, untuk menghasilkan Res[0,0] = M1[0,0]*M2[0,0]+ M1[0,1]*M2[1,0] + M1[0,2]*M2[2,0]
                //bisa diliat kalo yg dioperasikan itu barisM1=kolomM2
                result += Elmt(M1, i, k) * Elmt(M2, k, j);
            }
            Elmt(MRes, i, j) = result;
        }
    }
    
    return MRes;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    
    for (indeks i= GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        for (indeks j= GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
            Elmt(M, i, j) *= X;
        }
    }
    
    return M;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    for (indeks i= GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
        for (indeks j= GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
            Elmt(*M, i, j) *= K;
        }
    }
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    boolean status = true;
    
    if (NBElmt(M1) != NBElmt(M2)){
        status = false;
    } else {
        for (indeks i= GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1); i++){
            for (indeks j= GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++){
                if (Elmt(M1, i, j) != Elmt(M2, i, j)){
                    status = false;
                }
            }
        }
    }
    
    return status;
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return (!EQ(M1, M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (GetLastIdxBrs(M)==GetLastIdxKol(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    boolean status = true;
    indeks i = GetFirstIdxBrs(M);
    indeks j = GetFirstIdxKol(M);
    
    if (!IsBujurSangkar(M)){
        status = false;
    } else {
        while (status && (i<=GetLastIdxBrs(M))){
            j = GetFirstIdxKol(M);
            while (status && (j<=GetLastIdxKol(M))){
                if (Elmt(M, i, j)!=Elmt(M, j, i)){
                    status = false;
                }
                j++;
            }
            i++;
        }
    }
    
    return status;
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    boolean status = true;
    indeks i = GetFirstIdxBrs(M);
    indeks j = GetFirstIdxKol(M);
    
    if (!IsBujurSangkar(M)){
        status = false;
    } else {
        while (status && i<=GetLastIdxBrs(M)){
            j = GetFirstIdxKol(M);
            while (status && j<=GetLastIdxKol(M)){
                if (i==j){
                    if (Elmt(M, i, j) != 1){
                        status = false;
                    }
                } else {
                    if (Elmt(M, i, j) != 0){
                        status = false;
                    }
                }
                j++;
            }
            i++;
        }
    }
    
    return status;
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int count = 0;
    float limit = NBrsEff(M)*NKolEff(M)*0.05;
    
    for (indeks i= GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        for (indeks j= GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
            if (Elmt(M, i, j)!=0){
                count+=1;
            }
        }
    }
    
    return (count <= limit);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    MATRIKS MRes;
    CopyMATRIKS(M, &MRes);
    
    for (indeks i= GetFirstIdxBrs(MRes); i<=GetLastIdxBrs(MRes); i++){
        for (indeks j= GetFirstIdxKol(MRes); j<=GetLastIdxKol(MRes); j++){
            Elmt(MRes, i, j) *= (-1);
        }
    }

    return MRes;
}


float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
/*
 0 4
 2 -3
 */
{
    float det;
    if (NBrsEff(M) == 1){
        det = Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));
    }
    else{
        det = 0;
        for (indeks baris = GetFirstIdxKol(M); baris <= GetLastIdxKol(M); baris++){
            MATRIKS Kofaktor;
            MakeMATRIKS((NBrsEff(M) - 1), (NKolEff(M) - 1), &Kofaktor);
            indeks iM, jM, iKofaktor, jKofaktor;
            iKofaktor = GetFirstIdxBrs(Kofaktor);
            for (iM = GetFirstIdxBrs(M); iM <= GetLastIdxBrs(M); iM++){
                if (iM != baris){
                    jKofaktor = GetFirstIdxKol(Kofaktor);
                    for (jM = GetFirstIdxKol(M); jM <= GetLastIdxKol(M); jM++){
                        if (jM != GetFirstIdxKol(M)){
                            Elmt(Kofaktor, iKofaktor, jKofaktor) = Elmt(M, iM, jM);
                            jKofaktor++;
                        }
                    }
                    iKofaktor++;
                }
            }
            //kalo baris genap, maka determinan dikali 1, kalo baris ganjil, determinan dikali -1
            det += (baris % 2 == 0 ? 1 : -1) * Elmt(M, baris, GetFirstIdxKol(M)) * Determinan(Kofaktor);
        }
    }
    return det;
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    for (indeks i= GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (indeks j= GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            Elmt(*M, i, j) *= (-1);
        }
    }
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    MATRIKS Mtemp;
    CopyMATRIKS(*M, &Mtemp);
    
    //1 0 9         1 3 5
    //3 1 5         0 1 7
    //5 7 6         9 5 6
    
    for (indeks i= GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
        for (indeks j= GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
            Elmt(Mtemp, i, j) = Elmt(*M, j, i);
        }
    }
    
    *M = Mtemp;
}

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    float sum = 0;
    
    for (indeks j = GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
        sum += Elmt(M, i, j);
    }
    
    return (sum/NKolEff(M));
}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    float sum = 0;
    
    for (indeks i = GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        sum += Elmt(M, i, j);
    }
    
    return (sum/NBrsEff(M));
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    ElType maxTemp = Elmt(M, i, GetFirstIdxKol(M));
    ElType minTemp = Elmt(M, i, GetFirstIdxKol(M));
    
    for (indeks j = GetFirstIdxKol(M)+1; j<=GetLastIdxKol(M); j++){
        if (Elmt(M, i, j) > maxTemp){
            maxTemp = Elmt(M, i, j);
        }
        else if (Elmt(M, i, j) < minTemp){
            minTemp = Elmt(M, i, j);
        }
    }
    
    *max = maxTemp;
    *min = minTemp;
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    ElType maxTemp = Elmt(M, GetFirstIdxBrs(M), j);
    ElType minTemp = Elmt(M, GetFirstIdxBrs(M), j);
    
    for (indeks i = GetFirstIdxBrs(M)+1; i<=GetLastIdxBrs(M); i++){
        if (Elmt(M, i, j)>= maxTemp){
            maxTemp = Elmt(M, i, j);
        }
        else if (Elmt(M, i, j) < minTemp){
            minTemp = Elmt(M, i, j);
        }
    }
    
    *max = maxTemp;
    *min = minTemp;
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    int count = 0;
    for (indeks j = GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
        if (Elmt(M, i, j)==X){
            count++;
        }
    }
    
    return count;
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    int count = 0;
    for (indeks i = GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        if (Elmt(M, i, j)==X){
            count++;
        }
    }
    
    return count;
}
