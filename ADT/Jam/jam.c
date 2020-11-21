#include "jam.h"

boolean IsJAMValid (int H, int M)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return ((H >=0 && H <= 23) && (M >=0 && M <= 59));
}
/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM J1;
    Hour(J1) = HH;
    Minute(J1) = MM;
    return J1;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    int HH, MM;
    
    scanf("%d %d", &HH, &MM);
    
    while (!IsJAMValid(HH, MM)){
        printf("Jam tidak valid\n");
        scanf("%d %d", &HH, &MM);
    }
    
    *J = MakeJAM(HH, MM);
        
    
}


void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
    printf("%d.%d", Hour(J),Minute(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToMenit (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return((60*Hour(J))+Minute(J));
}

JAM MenitToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    int sisa;
    JAM JOutput;
    
    if (N<0){
        N+=1440;
    }
    
    N = N % 1440;
    
    Hour(JOutput) = N/60;
    return JOutput;
    
}
/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
     return (JAMToMenit(J1) == JAMToMenit(J2));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return (!(JEQ(J1, J2)));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<=J2, false jika tidak */
{
    return (JAMToMenit(J1) <= JAMToMenit(J2));
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{
    return (JAMToMenit(J1) > JAMToMenit(J2));
}
JAM NextMenit (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    long now = JAMToMenit(J);
    
    return MenitToJAM(now + 1);
}

JAM NextNMenit (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    long now = JAMToMenit(J);
    
    return MenitToJAM(now + N);
}
JAM NextNJam (JAM J, int N)
{
    long now = JAMToMenit(J);
    JAM add = MakeJAM(N,0);
    long add1 = JAMToMenit(add);

    long hasil = now+add1;

    if (hasil >= 1440){
        hasil -= 1440;
    }

    return MenitToJAM(hasil);
}
// JAM PrevDetik (JAM J)
// /* Mengirim 1 detik sebelum J dalam bentuk JAM */
// {
//     long now = JAMToDetik(J);
    
//     return DetikToJAM(now - 1);
// }
// JAM PrevNDetik (JAM J, int N)
// /* Mengirim N detik sebelum J dalam bentuk JAM */
// /* *** Kelompok Operator Aritmetika *** */
// {
//         long now = JAMToDetik(J);
    
//         return DetikToJAM(now - N);
//}
JAM Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    long selisih = JAMToMenit(JAkh) - JAMToMenit(JAw);
    if (selisih < 0){
        selisih += 1440;
    }
    JAM hasil = MenitToJAM(selisih);
    
    return hasil;
}

