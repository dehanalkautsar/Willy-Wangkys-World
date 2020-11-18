#ifndef wahana_H
#define wahana_H

#include "../Point/point.h"
#include "../Jam/boolean.h"

typedef struct 
{
     char* Nama;
     char* Tipe;
     int Harga;
     koordinatWahana Lokasi;
     char* Deskripsi;
     int Kapasitas;
     // history upgrade wahana
     int Durasi;
     // Ukuran Wahana (Bonus)
     

} wahana;


#endif
