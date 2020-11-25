
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bintree_Wahana.h"
// #include "../Mesin-Kata&Mesin-Karakter/mesinkar_file.h"

/* ADT Wahana */


Wahana MakeWahana(int ID, char Nama[], int Harga, char Deskripsi[], int Kapasitas, int Durasi_Menit, int Upgrade_Biaya, Material Upgrade_M[])
{
    
    Wahana W;
    ID_Wahana(W) = ID;
    strcpy(Nama_Wahana(W),Nama);
    Harga_Wahana(W) = Harga;
    strcpy(Deskripsi_Wahana(W),Deskripsi);
    Kapasitas_Wahana(W) = Kapasitas;
    Durasi_Wahana(W) = MenitToJAM(Durasi_Menit);
    Upgrade_Cost(W) = Upgrade_Biaya;
    
    Upgrade_Material(W,0) = Upgrade_M[0];
    Upgrade_Material(W,1) = Upgrade_M[1];
    return W;
}

// ID,Nama,Harga,Deskripsi,Kapasitas,Durasi

// Parameter input/output list of Wahana
void Read_File_Wahana(Wahana *List_W, char *nama_file, Material Database_Material[])
{
    /* INISIALISASI */
    int ID;
    char* Nama;
    int Harga;
    char* Deskripsi;
    int Kapasitas;
    int Durasi_Menit;
    int Upgrade_Biaya;
    Material Upgrade_Material[2];
    int level;

    /* PEMANGGILAN FILE */
    FILE *fp;
    char buff[256];

    fp = fopen(nama_file, "r");
    int j = 0;
    
    while (fgets(buff, sizeof(buff), fp))
    {                                    // fgets buat ngebaca buff
        char *token = strtok(buff, ","); // strtok buat ngesplit string dengan delimiter ','
        int i = 0;
        
        while (token != NULL && token != "\n")
        {
            
            switch (i)
            {
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
            case 6:
                Upgrade_Biaya = atoi(token);
                break;
            }
            i++;
            token = strtok(NULL, ",");
        }
        
        
        if (j<1) {
            level = 1;
            Upgrade_Material[0] = Database_Material[0];
            Upgrade_Material[1] = Database_Material[1];
        } else if (j<3) {
            level = 2;
            Upgrade_Material[0] = Database_Material[2];
            Upgrade_Material[1] = Database_Material[3];
        } else {
            level = 3;
            Upgrade_Material[0] = Database_Material[3];
            Upgrade_Material[1] = Database_Material[4];
        }
        

        Kuantitas_Material(Upgrade_Material[0]) = level*5;
        Kuantitas_Material(Upgrade_Material[1]) = level*5;
        
        
        // printf("%d\n",ID);
        
        List_W[j] = MakeWahana(ID, Nama, Harga, Deskripsi, Kapasitas, Durasi_Menit, Upgrade_Biaya, Upgrade_Material);
        // printf("%s\n",Nama_Wahana(List_W[j]));
        
        i = 0;
        j++;
    }
    // printf("%d\n",ID_Wahana(List_W[1]));
    fclose(fp);
    
}

void Make_Tree_Wahana(BinTree *Tree_Wahana, Wahana List_W[], Material Database_M[])
{
    
    MakeTree(List_W[0], Nil, Nil, Tree_Wahana);
    AddDaun(Tree_Wahana, ID_Wahana(List_W[0]), List_W[1], true);
    AddDaun(Tree_Wahana, ID_Wahana(List_W[0]), List_W[2], false);
    AddDaun(Tree_Wahana, ID_Wahana(List_W[1]), List_W[3], true);
    AddDaun(Tree_Wahana, ID_Wahana(List_W[1]), List_W[4], false);
    AddDaun(Tree_Wahana, ID_Wahana(List_W[2]), List_W[5], true);
    AddDaun(Tree_Wahana, ID_Wahana(List_W[2]), List_W[6], false);
}

void Print_Tree_Wahana(BinTree T)
{
    printf("(");
    if (!IsTreeEmpty(T))
    {
        printf("%d", ID_Wahana(Akar(T)));
        Print_Tree_Wahana(Left(T));
        Print_Tree_Wahana(Right(T));
    }
    printf(")");
}

/* Mengembalikan alamat Wahana ditemukan, NIL jika gagal ditemukan */
addrNode Search_Wahana(BinTree T, int ID) {
    /* KAMUS LOKAL */
    addrNode P;
    
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
        return Nil;
    } else {
        
        P = T;
        while (ID_Wahana(Akar(P))!=ID)
        {
            if (SearchTree(Left(T),ID)) {
                P = Left(P);
            } else {
                P = Right(P);
            } 
        }
        return P;  
    }
}


/* ADT MATERIAL */
/* Membuat ADT Material */
Material Make_Material(int ID, char Nama[], int Harga)
{
    Material M;
    
    ID_Material(M) = ID;
    strcpy(Nama_Material(M),Nama); 
    Harga_Material(M) = Harga;
    Kuantitas_Material(M) = 0;
    
    return M;
}

/* Baca File material */
void Read_File_Material(Material* List_M,char* nama_file)
{
    
    /* KAMUS LOKAL */
    int ID_Material;
    char* Nama_Material;
    int Harga_Material;
    
    /* BUKA FILE */
    FILE *fp;
    char buff[256];

    fp = fopen(nama_file, "r");
    int j = 0;

    while (fgets(buff, sizeof(buff), fp))
    {           
                                 // fgets buat ngebaca buff
        char *token = strtok(buff, ","); // strtok buat ngesplit string dengan delimiter ','
        int i = 0;

        while (token != NULL && token != "\n")
        {
            switch (i)
            {
            case 0:
                ID_Material = atoi(token);
                break;
            case 1:
                Nama_Material = token;
                break;
            case 2:
                Harga_Material = atoi(token);
                break;
            }
            i++;
            token = strtok(NULL, ",");
        }
        
        List_M[j] = Make_Material(ID_Material,Nama_Material,Harga_Material);
        // printf("%d",j);
        // printf("%d",ID_Material(List_M[j]));
        // printf("%s\n",Nama_Wahana(List_W[j]));
        i = 0;
        j++;
    }
    fclose(fp);
}


void init_wahana(BinTree* Bintree_Wahana,char* namaFileWahana, char* namaFileMaterial) {
    Wahana Database_W[30];
    Material Database_M[10];

    Read_File_Material(Database_M, namaFileMaterial);
    Read_File_Wahana(Database_W, namaFileWahana,Database_M);
    Make_Tree_Wahana(Bintree_Wahana,Database_W,Database_M);
}

void init_material(Material* Database_Material,char* namaFileMaterial) {
    Read_File_Material(Database_Material, namaFileMaterial);
}

void main() {
    BinTree Bintree_Wahana1;
    addrNode P;
    Material A;

    init_wahana(&Bintree_Wahana1,"wahana1.txt","material.txt");
    /*
    Wahana Database_W[30];
    Material Database_M[10];
    
    BinTree T_Wahana;
    
    
    Read_File_Material(Database_M, "material.txt");
    Read_File_Wahana(Database_W, "wahana1.txt",Database_M);
    Make_Tree_Wahana(&T_Wahana,Database_W,Database_M);
    */
    
    Print_Tree_Wahana(Bintree_Wahana1);
    P = Search_Wahana(Bintree_Wahana1,122);
    
    printf("\n%s\n",Nama_Wahana(Akar(P)));
    printf("%d\n",Upgrade_Cost(Akar(P)));
    A = Upgrade_Material(Akar(P),0);
    printf("%d\n",Kuantitas_Material(A));
    
    /* gcc bintree_wahana.c jam.c point.c wahana_material.c -o test */
}
