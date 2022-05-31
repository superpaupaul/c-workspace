#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <string.h>

#define TBUFFER 50

void lire (char str, void* buf){
    int file = open(str, O_RDONLY, 0);
    read(file,buf,50);
    printf("%s\n",buf);
    close(file);
}



void ecrire (char str){
    int file = open(str, O_CREAT | O_WRONLY , 0);
    write(file,"text",20);
    close(file);
}

int main(int argc, char * argv[] ){

    char buf[TBUFFER];
    char str = argv[1];
    ecrire(argv[1]);
    lire(argv[1],buf);
}