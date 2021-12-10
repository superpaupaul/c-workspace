#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

int v_globale = 10;

void *fct_thread(void *vargp)
{
    int* myId = (int*)vargp;
    int s = 0;

    ++s; ++v_globale;
    printf("Thread ID : %d, Variable locale : %d, Variable globale : %d\n",*myId,s,v_globale);
    return 0;
}

int main()
{
    
    pthread_t tid;

    for(int i = 0; i < 3; i++)
    {
        pthread_create(&tid,NULL,fct_thread,(void*)&tid);
    }

    pthread_exit(NULL);
    return 0;
}