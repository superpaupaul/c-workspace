#include "grafik.h"

void allumerLettre(posDamier d, char dam[4][4])
    {
    Point p = posDamier2Screen(d);
    char str[2];

    str[0] = dam[d.l][d.c];
    str[1] = '\0';
    dessiner_rectangle(p,STEP,STEP,rouge);
    p.x += OFFSETXT;
    afficher_texte(str,40,p,blanc);
    }

void eteindreLettre(posDamier d, char dam[4][4])
    {
    Point p = posDamier2Screen(d);
    char str[2];

    str[0] = dam[d.l][d.c];
    str[1] = '\0';
    dessiner_rectangle(p,STEP,STEP,bleu);
    p.x += OFFSETXT;
    afficher_texte(str,40,p,blanc);
    }

posDamier screen2posDamier(Point p)
    {
    posDamier d;

    if(p.y-OFFSETY<0)
        d.l = -1;
    else
        d.l = (p.y-OFFSETY)/STEP;

    if(p.x-OFFSETX<0)
        d.c = -1;
        else
    d.c = (p.x-OFFSETX)/STEP;

    return d;
    }

Point posDamier2Screen(posDamier d)
    {
    Point p;

    p.x = d.c*STEP + OFFSETX;
    p.y = d.l*STEP + OFFSETY;

    return p;
    }

int estDansDamier(posDamier d)
    {
    if(d.c<0 || d.c>3 || d.l<0 || d.l>3)
        return 0;
    return 1;
    }

int sontVoisins(posDamier d, posDamier e)
    {
    int dl = d.l-e.l, dc=d.c-e.c;

    if(dl==0 && dc==0)
        return 0;

    if(dl<-1 || dl>1 || dc<-1 || dc>1)
        return 0;

    return 1;
    }

void initDam(char dam[4][4])
    {
    int l,c;

    for(l=0;l<=3;l++)
        for(c=0;c<=3;c++)
            dam[l][c] = 0;
    }

void dessinerDam(char dam[4][4])
    { 
    posDamier d;
    char str[2];
    Point p;

    effacerDam();

    str[1]='\0';
    for(d.l=0;d.l<=3;d.l++)
        for(d.c=0;d.c<=3;d.c++)
            {
            p = posDamier2Screen(d);
            p.x += OFFSETXT;
            str[0] = dam[d.l][d.c];
            afficher_texte(str,40,p,blanc);
            }
    }

void effacerDam()
    {
    Point p={OFFSETX,OFFSETY};
    dessiner_rectangle(p,4*STEP,4*STEP,bleu);
    }

void dessiner_ligne_epaisse(Point p, Point q, int e)
    {
    Point r,s;

    r = p; s=q;
    for(r.x=p.x-e+1, s.x=q.x-e+1; r.x<=p.x+e-1; r.x++, s.x++)
        dessiner_ligne(r, s, jaune);

    r = p; s=q;
    for(r.y=p.y-e+1, s.y=q.y-e+1; r.y<=p.y+e-1; r.y++, s.y++)
        dessiner_ligne(r, s, jaune);
    }

