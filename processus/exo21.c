#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
#define temps 2


int main(){
    pid_t ret,wpid;
    ret = fork();
    printf("\n");
    int status ;
    if(ret == 0) // je suis fils
    {
        printf("[fils] Je m'endors pour %ds...\n",temps);
        sleep(temps);
        printf("Je me suis réveillé !\n");
    }
    else // je suis pere
    {
        printf("[pere] En attente de mon fils...\n");
        wait(&status);
    }

    printf("** Fin du process <%d> **\n",(int)getpid());
    return 0;
}
