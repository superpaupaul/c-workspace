#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int n = 3;
sem_t sem;

void *fct_thread(void *vargp)
{
    sleep(1);
    printf("[thread %d] Point atteint\n",*(int*)vargp);
    sem_post(&sem);
    return 0;
}

void *barrier_thread(void *vargp)
{
    printf("[b_thread] Barrière atteinte, en attente...\n");
    for(int i = 0; i < n; i++)
    {
        sem_wait(&sem);
    }
    sem_wait(&sem);
    
    printf("[b_thread] Je peux continuer !\n");
    return 0;
}

int main()
{
    sem_init(&sem,0,1); // 0 car on a un seul processus, 1 car on l'instancie à 1
    pthread_t tids;
    pthread_t tidBarrier;

    for(int i = 0; i < n; i++)
    {
        pthread_create(&tids,NULL,fct_thread,(void*)&tids);
    }
    pthread_create(&tidBarrier,NULL,barrier_thread,(void*)&tids);
    sem_destroy(&sem);
    pthread_exit(NULL);
    return 0;
}