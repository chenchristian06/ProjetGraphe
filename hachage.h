#ifndef hachage_h
#define hachage_h

#include"graphe.h"
struct cellules {
    T_SOMMET sommet;
    struct cellules * suiv;};
    typedef struct cellules* H_Liste;


long hachage(char* nom_sommet,long N);
unsigned long puissance(unsigned long a,unsigned long b);
H_Liste ajout_tete_H(T_SOMMET k,H_Liste l);
H_Liste* remplissage_table(H_Liste* tab,T_SOMMET* g,long n);
void visualiser_table(H_Liste* tab,long n);
void affichage_H(H_Liste l);
void rechercher(char* nom,H_Liste* tab,long* H,long N);

#endif
