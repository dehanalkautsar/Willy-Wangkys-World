
#include <stdio.h>
#include <string.h> 
#include "bintree_wahana.h"
#include "../ADT/Mesin-Kata&Mesin-Karakter/mesinkata.h"

/* ADT WAHANA */
/* BELUM ADA UPGRADE */
wahana MakeWahana(int ID, char* Nama, int Harga, char* Deskripsi, int Kapasitas, int Durasi_Menit) {
    wahana W;
    ID_Wahana(W) = ID;
    Nama_Wahana(W) = Nama;
    Harga_Wahana(W) = Harga;
    Deskripsi_Wahana(W) = Deskripsi;
    Kapasitas_Wahana(W) = Kapasitas;
    Durasi_Wahana(W) = MenitToJAM(Durasi_Menit);
    return W;
}

// ID,Nama,Harga,Deskripsi,Kapasitas,Durasi

// Parameter input/output list of wahana
void Read_File_Wahana(wahana* W[30], char* nama_file) {
    int ID, char* Nama; int Harga; char* Deskripsi; int Kapasitas; int Durasi_Menit;
    FILE *fp;
    char buff[255];

    fp = fopen(nama_file, "r");
    int j = 0;

    while (fgets(buff, sizeof(buff), fp)) {                 // fgets buat ngebaca buff
        char *token = strtok(buff, ",");                    // strtok buat ngesplit string dengan delimiter ','
        int i = 0;

        while (token != NULL && token != "\n") 
        {
            switch (i) {
                case 0:
                    ID = atoi(token);
                    break;
                case 1:
                    Nama = token;
                    break;
                case 2:
                    Harga = atoi(token); // Atoi buat mengubah dari string jadi integer ("2000" -> 2000)
                    break;
                case 3:
                    Deskripsi = token;
                    break;
                case 4:
                    Kapasitas = atoi(token);
                    break;
                case 5:
                    Durasi_Menit = atoi(token);
                    break;
            }
            i++;
            token = strtok(NULL, ",");   
        }

        W[j] = MakeWahana(ID,Nama,Harga,Deskripsi,Kapasitas,Durasi_Menit);
        i = 0;
        j++; 
    }
    
    fclose(fp);
    // printf("%s\n",Nama);
    // printf("%d\n",Harga);
    // printf("%s\n",Deskripsi);
    // printf("%d\n",Kapasitas);
    // printf("%d\n",Durasi_Menit);
}

void Make_Tree_Wahana(BinTree *Tree_Wahana,char* nama_file) {
    wahana W[30];
    Read_File_Wahana(&W[30], nama_file);

    MakeTree(W[0], Nil, Nil, Tree_Wahana);
    AddDaun(Tree_Wahana,W[0],W[1],true);
    AddDaun(Tree_Wahana,W[0],W[2],false);
    AddDaun(Tree_Wahana,W[1],W[3],true);
    AddDaun(Tree_Wahana,W[1],W[4],false);
    AddDaun(Tree_Wahana,W[2],W[5],true);
    AddDaun(Tree_Wahana,W[2],W[6],false);
    
        
    }
    
}


