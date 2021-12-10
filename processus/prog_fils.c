#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
#define temps 2


int main(int argc, char** argv){
    pid_t ret;
    ret = fork();
    if(ret == 0) // je suis fils
    {
        printf("[fils] pid=<%d>, ppid=<%d>\n",(int)getpid(),(int)getppid());
        printf("[fils] commande de lancement : %s\n",argv[0]);
        printf("[fils] Bonjour %s\n",argv[1]);
    }
    else // je suis pere
    {
    }

    printf("** Fin du process <%d> **\n",(int)getpid());
    return 0;

    // execlp utilise le $PATH à la différence de execl
}
