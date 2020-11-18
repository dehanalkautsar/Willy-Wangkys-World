#include <stdio.h>
#include "../Matriks/matriks.h";

void printMap(MATRIKS M) {
    for(int i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) + 2; i++){
        for(int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M) + 2; j++){
            if(i == GetFirstIdxBrs(M) || i == GetLastIdxBrs(M) + 2) {
              printf("*");
            }else{
              printf("-");
            }
        }
        printf("\n");
    }
}