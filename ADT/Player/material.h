#ifndef _MATERIAL_H
#define _MATERIAL_H


typedef struct Material
{
  int ID;
  char NamaMaterial[32];
  int Harga;
  int Kuantitas;
} Material;


/* MAKRO ADT MATERIAL */
#define ID_Material(M) (M).ID
#define Nama_Material(M) (M).NamaMaterial
#define Harga_Material(M) (M).Harga
#define Kuantitas_Material(M) (M).Kuantitas


#endif