#include <stdio.h>
#include <pthread.h>    //pour utiliser les threads et les mutex
#include <stdlib.h>		//pour utiliser le rand() => man 3 rand
#include <time.h>		//pour utiliser le time()
#include <unistd.h>		//usleep
#include <semaphore.h>	//pour utiliser les sémaphores

//renomme les opérations comme en algo
#define P(x) sem_wait(x)
#define V(x) sem_post(x)

pthread_mutex_t m1, m2;

sem_t sem1, sem2;

/*****************
 *  PROTOTYPES
 * ***************/
//pour insérer des temps d'attente aléatoire
int mon_rand(int a, int b);

//versions sans synchronisation
void main_sans_synchro(void);
void* thread_1();
void* thread_2();

//version avec des mutex
void main_mutex(void);
void* thread_1_mutex();
void* thread_2_mutex();

//versions avec des sémaphores
void main_sem(void);
void* thread_1_sem();
void* thread_2_sem();

/************************
 *  FONCTION PRINCIPALE
 * **********************/
int main(void)
{
	unsigned int choix = 0;
	
	srand(time(NULL));
	
	do
	{
		printf("*** Type d'execution : \n 1) sans synchro \n 2) avec mutex \n 3) avec semaphore\n 4)Autre pour quitter\n");
		printf("Votre choix : ");
		scanf(" %d", &choix);
		
		printf("----\n");
		switch(choix)
		{
			case 1 : 	main_sans_synchro();
						break;
			case 2 : 	main_mutex();
						break;
			case 3 : 	main_sem();
						break;
			
			default : printf("mauvais choix\n");
		}
		
		printf("----\n");
	}while(choix != 4);
	
	return 0;
}


int mon_rand(int a, int b)
{
	//on suppose que b>a !
	return ( rand()%(b-a) ) + a;
}

/**************************************
 *  FONCTIONS SANS SYNCHRONISATION 
 * ************************************/
void main_sans_synchro(void)
{
	pthread_t mes_threads[2];
	
	pthread_create(&mes_threads[0],NULL,thread_1,NULL);
	pthread_create(&mes_threads[1],NULL,thread_2,NULL);
	
	pthread_join(mes_threads[0],NULL);
	pthread_join(mes_threads[1],NULL);
	
	return;
}

void* thread_1()
{
	usleep(mon_rand(10000,1000000));
	printf("je\n");

	usleep(mon_rand(10000,1000000));
	printf("mes\n");
	
	return NULL;
}

void* thread_2()
{

	usleep(mon_rand(10000,1000000));
	printf("synchronise\n");

	usleep(mon_rand(10000,1000000));
	printf("threads\n");
	
	return NULL;
}
/**************************************
 *  FONCTIONS EN UTILISANT MUTEX 
 * ************************************/
void main_mutex(void)
{
	pthread_t mes_threads[2];
	
 	//il faut bloquer le premier thread dès le départ
	//les mutex sont unlock au démarrage !
	pthread_mutex_lock(&m1);
	pthread_mutex_lock(&m2);
	
	pthread_create(&mes_threads[0],NULL,thread_1_mutex,NULL);
	pthread_create(&mes_threads[1],NULL,thread_2_mutex,NULL);
	
	pthread_join(mes_threads[0],NULL);
	pthread_join(mes_threads[1],NULL);
	
	//A deverouiller pour les prochaines executions
	pthread_mutex_unlock(&m1);
	pthread_mutex_unlock(&m2);
	
	return;
}

void* thread_1_mutex()
{
	usleep(mon_rand(10000,1000000));
	printf("je\n");
	pthread_mutex_unlock(&m1);
	pthread_mutex_lock(&m2);
	usleep(mon_rand(10000,1000000));
	printf("mes\n");
	pthread_mutex_unlock(&m1);
	
	return NULL;
}

void* thread_2_mutex()
{
	pthread_mutex_lock(&m1);
	usleep(mon_rand(10000,1000000));
	printf("synchronise\n");
	pthread_mutex_unlock(&m2);
	pthread_mutex_lock(&m1);
	usleep(mon_rand(10000,1000000));
	printf("threads\n");
	
	return NULL;
}

/**************************************
 *  FONCTIONS EN UTILISANT SEMAPHORES 
 * ************************************/
void main_sem(void)
{
	pthread_t mes_threads[2];
	
	sem_init(&sem1,0,0); //on peut décider de la valeur initiale pour les sem
	sem_init(&sem2,0,0); //contrairement aux mutex
		
	pthread_create(&mes_threads[0],NULL,thread_1_sem,NULL);
	pthread_create(&mes_threads[1],NULL,thread_2_sem,NULL);
	
	pthread_join(mes_threads[0],NULL);
	pthread_join(mes_threads[1],NULL);
	
	return;
}

void* thread_1_sem()
{
	usleep(mon_rand(10000,1000000));
	printf("je\n");
	V(&sem1);
	P(&sem2);
	usleep(mon_rand(10000,1000000));
	printf("mes\n");
	V(&sem1);
	
	return NULL;
}

void* thread_2_sem()
{
	P(&sem1);
	usleep(mon_rand(10000,1000000));
	printf("synchronise\n");
	V(&sem2);
	P(&sem1);
	usleep(mon_rand(10000,1000000));
	printf("threads\n");
	
	return NULL;
}