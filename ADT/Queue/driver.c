#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    PrioQueue Q1;
    infotypeQ X;
    makeQueue(&Q1);
    printAntrean(Q1);
    kurangSabar(&Q1);
    //Dequeue(&Q1, &X);
    printf("---------\n");
    printAntrean(Q1);
    return 0;
}