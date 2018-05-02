//
//  dijkstra.c
//  Projet1A
//
//  Created by Chen Christian on 13/04/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//
#include "liste.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
//Dijkstra
int* creer_pere(int nb_sommets){
/*on créer un tableau de pere ou l'indice est le pere et le contenu est l'antécédent*/
    int* tab_pere;
    tab_pere = calloc(nb_sommets,sizeof(int));
    int i = 0;
    for(;i<nb_sommets;i++){
        *(tab_pere+i) = -1;
    }
    return tab_pere;
}

int* creer_poids(int nb_sommets){
    /*on crée le tableau des poids où l'indice représente le numéro du sommet le la valeur le poids */
    int* tab_poids;
    tab_poids = calloc(nb_sommets,sizeof(*tab_poids));
    int i;
    for(i=0;i<nb_sommets;i++){
        tab_poids[i]=-1;
    }
    return tab_poids;
}

void depart_poids(int i, int* tab_poids){
    /*Ici on choisit le point de départ */
    tab_poids[i]=0;
}

Liste creation_pas_visite(int nb_sommets){
    /* on crée la liste des sommets pas encore visité */
    int i;
    Liste l = creer_liste();
    for(i=0;i<nb_sommets;i++){
        ajout_tete(i,l);
    }
    return l;
}

Liste creation_deja_visite(void){
    /* ici on a la liste des sommets déjà visité */
    return creer_liste();
}

Liste supprime_liste(Liste l,int x){
    /* on recherche et on élimine l'élément x dans la lsite l*/
    if(!l){
        return NULL;
    }
    Liste l_temp = l;
    if(l_temp->val == x){
        return l_temp->suiv;
    }
    else{
        while((l_temp->suiv)!=NULL){
            if((l_temp->suiv)->val==x){
                l_temp->suiv = (l_temp->suiv)->suiv;
            }
            else{
                l_temp = l_temp->suiv;
            }
        }
        return l;
    }
}

int recherche_min(int* l,int nb_sommets){
    int imin = 0;
    int i;
    for(i=1;i<nb_sommets;i++){
        if(l[i]<l[imin]){
            imin = i;
        }
    }
    return imin;
}

int test_presence(Liste l, int x){
    /* test si x est présent dans l */
    if(!l){
        return 0;
    }
    Liste l_temp = l;
    if(l_temp->val == x){
        return 1;
    }
    else{
        while(l_temp!=NULL){
            if(l_temp->val==x){
                return 1;
            }
            else{
                l_temp = l_temp->suiv;
            }
        }
        return 0;
    }
}




    




