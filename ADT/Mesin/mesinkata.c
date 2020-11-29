#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

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
    if (CC == MARK)
    {
        EndKata = true;
        EOP = true;
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

void ReadInput()
{
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = 0;
    printf("$ ");
    do
    {
        ADV_Input();
        CKata.TabKata[i] = CC;
        i++;
    } while ((CC != EOI) && (i <= NMax));
    CKata.Length = i - 1;
}
/* Nani? */

boolean IsKataSama(Kata K1, Kata K2)
{
    /* KAMUS LOKAL */
    int i = 0;
    boolean sama = true;

    /* ALGORITMA */
    if (K1.Length == K2.Length)
    {
        while (sama && i < K1.Length)
        {
            if (K1.TabKata[i] != K2.TabKata[i])
            {
                sama = false;
            }
            i++;
        }
    }
    else
    {
        sama = false;
    }

    return sama;
}

int PanjangString(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

void StringToKata(Kata* Pass ,char *string)
{
    /* KAMUS LOKAL */
    // Kata Pass;
    int n;

    /* ALGORITMA */
    n = PanjangString(string);
    (*Pass).Length = n;

    for (int i = 0; i < n; i++)
    {
        (*Pass).TabKata[i] = string[i];
    }

    // return Pass;
}

void KataToString(Kata Kata, char buff[256])
{
    /* KAMUS LOKAL */
    int n;
    int i;

    /* ALGORITMA */
    n = Kata.Length;
    for (i = 0; i < n; i++)
    {
        buff[i] = Kata.TabKata[i];
    }
    buff[i + 1] = '\0'; // End of string
}

int KataToInt(Kata Current_Kata)
{
    int num = 0;
    int panjang = Current_Kata.Length;

    for (int i = 0; i < panjang; i++)
    {
        num *= 10;
        num += Current_Kata.TabKata[i] - '0';
    }

    return num;
}