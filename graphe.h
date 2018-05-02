#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>

//DEBUT_DEF_STRUCT
typedef struct{
    int arrivee;
    double cout;
} T_ARC;
//description des éléments dans le tableau 
//liste des successeurs et T_ARC est le nom de l'arc
typedef struct lsucc{
    T_ARC val;
    struct lsucc* suiv;
}* L_ARC;
//structure un arc T_ARC
typedef struct{
    char* nom;
    double x,y;
    L_ARC voisins;
} T_SOMMET;
// structure des sommets T_SOMMET

typedef struct{
    int poids;
    int deja_visite; // 0 pour non et 1 pour oui
} TPOIDS;
//FIN_DEF_STRUCTURE

//Liste fonctions
T_SOMMET* creer_graphe(void);
T_SOMMET* creation_graphe(T_SOMMET* g,char* nom_fichier,int* pnb_sommets,int* pnb_arcs);
L_ARC ajout_teteG(T_ARC k,L_ARC l);
L_ARC creer_L_ARC(void);
void visualiser_graphe(T_SOMMET* g,int* pnb_sommets,int* pnb_arcs);

#endif /* graph_h */
