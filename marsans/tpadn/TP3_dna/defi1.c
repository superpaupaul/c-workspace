#include<stdio.h>
#include"WT.c"
#include "WT.h"
#include"LC.h"



int main()
{

    char seq[] = "TCGACCAAGCTGGTTTTTCCGTCCTGCCTTTTCCGATAGAGCGATCCTTTGACTGACTAAGGAGCCGGTAGCGATATACCTAGTATTGCGCGCGTCTCGGAGGGCGAGGCTAGATTTAAACGGGTCCGATTTCGGCCAGCTAAGGATTTGATTAAAAAATGTTTCCCGATCCCAACCATAGGGACTTGGTCTTCCAAAACTAATGACACATGTGAATACAAGATGGATGGAGTGATCCCCATTCGAGCGACGCTGATAGCCTAAGCTGCTCCTGATGCGCCGTTTACTTTGAACTAAGGT";    
    // trad["C" - 'A'] // indice
    char model[] = "ACTAA";
    Noeud * arbre = nouveauNoeud();

    for(int i = 0; i < 295; i++) // gestion de la fin du tab
    {
        ajouteMotArbre(arbre,seq+i,0); // seq et seq + i
    }
    return 0;
}