#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
{
    while (CC == BLANK)
    {
        ADV();
    }
}

void STARTKATA()
{
    START();
  k();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
{
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
    }
}

void SalinKata()
{
    int i = 0;
    while (CC != MARK && CC != BLANK)
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

boolean IsKataSama (Kata K1,Kata K2)
{
    /* KAMUS LOKAL */
    int i = 0;
    boolean sama = true;

    /* ALGORITMA */
    if (K1.Length==K2.Length) {
        while (sama && i < K1.Length)
        {
            if (K1.TabKata[i]!=K2.TabKata[i])
            {
                sama = false;
            } 
            i++;
        }
    } else {
        sama = false;
    }

    return sama; 
}


int PanjangString(char* string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

Kata StringToKata(char* string) {
    /* KAMUS LOKAL */
    Kata Pass;
    int n;

    /* ALGORITMA */
    n = PanjangString(string);
    Pass.Length = n;
    
    for (int i = 0; i < n; i++)
    {
        Pass.TabKata[i] = string[i];
    }
    
    return Pass;
}