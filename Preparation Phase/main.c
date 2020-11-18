#include <stdio.h>
#include <stdlib.h>


int main(){
    char* choice;

    printf("// Welcome to Willy wangky's fum factory!!////\n New game / load game / exit? //\n");
    scanf("%s", &choice);
    if (choice=="new"){
        char* nama;
        printf("Memulai permainan baru..");
        printf("Masukkan nama:");
        scanf("%s", &nama);
        
        //new game
    }else if(choice=="load"){
        //continue game
    }else{
        return 0;
    }
}


