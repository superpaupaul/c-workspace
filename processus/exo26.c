#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
#define temps 2


int main(){
    
    int nbProc;
    printf("Entrez le nombre de processus à créer\n");
    scanf("%d",&nbProc);
    pid_t pids[nbProc];
    char echo[] = "./prog_fils ";
    char prenom[256];

    // Lancer les enfants.
    for(int i = 0; i < nbProc; i++)
    {
        if(pids[i] = fork() < 0)
        {
            perror("fork");
            abort();
        }
        else if (pids[i] == 0)
        {
            /*
            printf("Entrer un prénom \n");
            scanf("%s",prenom);
            strcat(echo,prenom);
            system(echo);
            */
           printf("%d\n",i);
        }
    }

    // Attendre les enfants
    int status;
    pid_t pid;
    while(nbProc > 0)
    {
        pid = wait(&status);
        printf("Fin du processus enfant %d\n",(long)pid);
        --nbProc;
    }
    

    printf("** Fin du process <%d> **\n",(int)getpid());
    return 0;
}
