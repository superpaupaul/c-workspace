#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define P(sem)  (sem_wait(&sem))
#define V(sem)  (sem_post(&sem))
#define TBUFFER 10


int tampon[TBUFFER];

sem_t lib;
sem_t occ;

void *lecture_tampon(void *vargp)
{
    int j = 0;
    while(1)
    {
        P(occ);
        tampon[j%TBUFFER] = j;
        j++;
        printf("[Lecture] - j%%TBUFFER = %d - j = %d\n",j%TBUFFER,j);
        V(lib);
        sleep(2);
    }
    return 0;
}

void *ecrire_tampon(void *vargp)
{
    int i = 0;
    while(1)
    {
        P(lib);
        usleep(mon_rand(10000,1000000));
        tampon[i%TBUFFER] = i;
        i++;
        printf("[Ecriture] - i%%TBUFFER = %d - i = %d\n",i%TBUFFER,i);
        V(occ);
        sleep(2);
    }
    return 0;
}

int main()
{
    sem_init(&lib,0,TBUFFER); // 0 car on a un seul processus, 1 car on l'instancie à 1
    sem_init(&occ,0,0);
    
    pthread_t tidLecture;
    pthread_t tidEcriture;

    pthread_create(&tidLecture,NULL,lecture_tampon,(void*)&tidLecture);
    pthread_create(&tidEcriture,NULL,ecrire_tampon,(void*)&tidEcriture);



    sem_destroy(&lib);
    sem_destroy(&occ);
    pthread_exit(NULL);
    return 0;
}