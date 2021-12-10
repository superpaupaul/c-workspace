#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#define nbIt 5

int v_globale = 42;

int main(){
    pid_t ret;
    ret = fork();
    printf("\n");
    if(ret == 0) // je suis fils
    {
        printf("[fils] PID=%d,PPID=%d,v_globale=%d\n",(int)getpid(),(int)getppid(),v_globale);
        for(int i=0; i<nbIt;i++)
        {
            srand(time(NULL) + getpid());
            sleep(rand());
            v_globale += 10;
            printf("[fils] <%d> : i=%d, v_globale=%d\n",(int)getpid(),i,v_globale);
        }

    }
    else // je suis pere
    {
        printf("[pere] PID=%d,PPID=%d,v_globale=%d\n",(int)getpid(),(int)getppid(),v_globale);
        for(int i=0; i<nbIt;i++)
        {
            srand(time(NULL) + getpid());
            sleep(rand());
            v_globale *= 2;
            printf("[pere] <%d> : i=%d, v_globale=%d\n",(int)getpid(),i,v_globale);
        }
    }

    printf("** Fin du retessus <%d>, v_globale=%d **\n",(int)getpid(),v_globale);
    // Q1 On constate que la variable globale est propre à chaque retessus, elle n'est pas partagée
    // Q2 Si on oublie les '\n', les affichages vont s'entremêler dans le buffer, déja qu'ils s'entremêlent entre fils et père là c'est le bordel.
    // Q3 fork() renvoie le pid du retessus. Le ppid du père correspond au pid du programme ayant executé mon programme.
    // Q4 ajouter un sleep(1) dans chaque boucle permet d'attendre une seconde à chaque itération et donc les retessus fils et père affichent en même temps en alternance. La variable globale reste dans les deux cas inchangée car elle n'est pas partagée.

    return 0;
}
