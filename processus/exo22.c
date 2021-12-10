#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
#define temps 2


int main(){
    pid_t ret;
    ret = fork();
    printf("\n");
    int status ;
    char echo[] = "./prog_fils ";
    char prenom[256];
    if(ret == 0) // je suis fils
    {
        printf("Entrer un prénom \n");
        scanf("%s",prenom);
        strcat(echo,prenom);
        execlp("sh", "sh", "-c", echo, (char *)0); // on peut mettre NULL à la place de (char*)0
        // execlp permet de spécifier les commandes du $PATH donc pas à spécifier /bin/sh
        fprintf(stdout,"execlp() failed!\n");
    }
    else // je suis pere
    {
        printf("[pere] En attente de mon fils...\n");
        wait(&status);
    }

    printf("** Fin du process <%d> **\n",(int)getpid());
    return 0;
}
