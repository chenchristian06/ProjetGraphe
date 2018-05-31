#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>

//DEBUT_DEF_STRUCT


// description/valeur d'un voisin
typedef struct{
    long arrivee;
    double cout;
} T_ARC;


// structure d'un voisin
typedef struct lsucc{
    T_ARC val;
    struct lsucc* suiv;
}* L_ARC;


//Structure d'un sommet
typedef struct{
    char* nom;
    char* ligne;
    long position_tas;
    long position_graphe;
    double x,y;
    L_ARC voisins;
} T_SOMMET;

typedef struct cellule{
    long val;
    struct cellule* suiv;
}* Liste;


//Liste fonctions
T_SOMMET* creer_graphe(void);
T_SOMMET* creation_graphe(T_SOMMET* g,char* nom_fichier,long* pnb_sommets,long* pnb_arcs);
L_ARC ajout_teteG(T_ARC k,L_ARC l);
L_ARC creer_L_ARC(void);
void visualiser_graphe(T_SOMMET* g,long* pnb_sommets,long* pnb_arcs);
void supprime_retour(char* s);
void reset_arc(T_SOMMET* g,long* H);
void resultat(T_SOMMET* g,long* pere,long depart,long arrivee,long nb_sommets,int num);
Liste ajout_tete(long k,Liste l);

#endif /* graph_h */
