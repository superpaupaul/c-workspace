#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TAMPON 1024

#define F_A_LIRE "f_lire.txt"
#define F_A_ECRIRE "f_ecrire.txt"

void verifier_entrees(char** fichier_s,char** fichier_e, int nbarg, char** argv);
void ecrire_fichier(char* fichier, char* message);
char* lire_fichier(char* fichier);
void copier_fichier(char* src, char* dest);

int main(int nbarg, char* argv[])
{
	char* fichier_s=NULL, *fichier_e=NULL;
	//char* texte = NULL;
	
	verifier_entrees(&fichier_s,&fichier_e,nbarg, argv);
	
	copier_fichier(fichier_e, fichier_s);
	
	return 0;
}

void verifier_entrees(char** fichier_s,char** fichier_e, int nbarg, char** argv)
{
	switch(nbarg)
	{
		case 2:		if( strcmp(argv[1],"-help") == 0 )
					{
						printf("Utilisation : %s [fichier sortie] [fichier entree] \n",argv[0]);
						exit(0);
					}
				break;
	
		case 3:		*fichier_s = (char*)malloc((strlen(argv[1])+1)*sizeof(char));
					strcpy(*fichier_s,argv[1]);
					*fichier_e = (char*)malloc((strlen(argv[2])+1)*sizeof(char));
					strcpy(*fichier_e,argv[2]);
					
				break;
			
		default:	printf("Utiliser le flag \"-help\" pour consulter l'aide\n");
					exit(0);
	}

	return;
}

void ecrire_fichier(char* fichier, char* message)
{
	FILE* fichier_ecrit = NULL;
	
	fichier_ecrit = fopen(fichier, "w");
	
	if(fichier_ecrit != NULL)
	{
		printf("ecriture dans le fichier %s...\n",fichier);
		fputs(message, fichier_ecrit);
		fclose(fichier_ecrit);
	}
	else
	{
		printf("Echec de l'ouverture du fichier à ecrire \"%s\".\n",fichier);
	}
	
	return;
}

char* lire_fichier(char* fichier)
{
	FILE* fichier_lu = NULL;
	char* phrase = NULL;
	char tmp[TAILLE_TAMPON]=""; //chaine dynamique ?
	
	fichier_lu = fopen(fichier,"r");
	
	if(fichier_lu == NULL)
	{
		printf("Echec de l'ouverture  du fichier a lire \"%s\".\n",fichier);
	}

	printf("Lecture dans le fichier %s...\n",fichier);
	while( fgets(tmp,TAILLE_TAMPON,fichier_lu) )
	{
		phrase = (char*)realloc(phrase,(strlen(phrase)+strlen(tmp)+1)*sizeof(char)); //pas besoin du +1 dans ce cas
		strcpy(phrase+strlen(phrase),tmp);
		//printf("%s",tmp);
	}
	
	fclose(fichier_lu);
	
	//phrase = (char*)malloc((strlen(tmp)+1)*sizeof(char));
	//strcpy(phrase,tmp);

	return phrase;
}

void copier_fichier(char* src, char* dest)
{
	if( src!=NULL && dest!=NULL )
		ecrire_fichier(dest,lire_fichier(src));
	
	return;
}