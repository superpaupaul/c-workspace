/******************************************************************************/
/*                                                                            */
/******************************************************************************/

#ifndef GRAFIK_H
#define GRAFIK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/libgraphique.h"
#include<math.h>

#define OFFSETX 70
#define OFFSETY 70
#define OFFSETXT 10
#define STEP 50



/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/

typedef struct {
    int l;
    int c;
} posDamier;







/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/

/* Transforme une position écran en position du damier                        */
posDamier screen2posDamier(Point p);
/* Transforme une position du damier en position écran                        */
Point posDamier2Screen(posDamier d);
/* Indique si une position est dans le damier ou non                          */
int estDansDamier(posDamier d);
/* Indique si deux positions sont voisines                                    */
int sontVoisins(posDamier d, posDamier e);
/* Vide le tableau de jeu                                                     */
void initDam(char dam[4][4]);
/* Dessine le tableau de jeu à l'écran                                        */
void dessinerDam(char dam[4][4]);
/* Efface le tableau de jeu à l'écran                                         */
void effacerDam();
/* Dessine une ligne épaisse entre 2 points                                   */
void dessiner_ligne_epaisse(Point p, Point q, int e);
/* Allume en rouge une position du damier                                     */
void allumerLettre(posDamier d, char dam[4][4]);
/* Eteint - en bleu - une position du damier                                  */
void eteindreLettre(posDamier d, char dam[4][4]);
















#endif

