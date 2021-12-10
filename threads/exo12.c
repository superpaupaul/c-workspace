#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t m1;
sem_t m2;

void *fct_thread1(void *vargp)
{
    printf("Je ");
    sem_post(&m2);
    sem_wait(&m1);
    printf("mes ");
    sem_post(&m2);
    return 0;
}

void *fct_thread2(void *vargp)
{
    sem_wait(&m2);
    printf("synchronise ");
    sem_post(&m1);
    sem_wait(&m2);
    printf("threads\n");
    return 0;
}

int main()
{
    
    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1,NULL,fct_thread1,(void*)&tid1);
    pthread_create(&tid2,NULL,fct_thread2,(void*)&tid2);
    
    pthread_exit(NULL);
    return 0;
}