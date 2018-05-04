//
//  main.c
//  Projet1A
//
//  Created by Chen Christian on 01/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include "graphe.h"
#include "dijkstra.h"
int main(){
/*---DEBUT CREATION GRAPHE---*/
    T_SOMMET* g;
    //char nom_fichier[512];
    //printf("Veuillez spécifier le nom de fichier où extraire le graphe \n ");
    //scanf("%s",nom_fichier);
    char* nom_fichier="/Users/chenchristian/Desktop/Projet1A/Projet1A/grapheNewYork.csv";
    g = creer_graphe();
    long nb_sommets;
    long nb_arcs;
    g=creation_graphe(g, nom_fichier,&nb_sommets,&nb_arcs);
    //visualiser_graphe(g,&nb_sommets,&nb_arcs);
    //printf("le graphe crée\n");
/*---FIN---*/
    
/*---DEBUT DIJKSTRA---*/
    long depart;
    long arrivee;
    long i;
    long j;
    long* pere;
    double* pcc;
    printf("Donner depart\n");
    scanf("%ld",&depart);
    printf("Donner arrivee\n");
    scanf("%ld",&arrivee);
    Liste deja_visite;
    Liste pas_visite;
    pere = creer_pere(nb_sommets);
    pcc = creer_poids(nb_sommets);
    pcc = depart_poids(depart, pcc);
    deja_visite = creation_deja_visite();
    pas_visite = creation_pas_visite(nb_sommets);
    do{
        j = recherche_min(pcc, nb_sommets,deja_visite);
        pas_visite = supprime_liste(pas_visite, j);
        deja_visite = ajout_tete(j, deja_visite);
        L_ARC l = g[j].voisins;
        while(l!=NULL){
            long k = (l->val).arrivee;
            double cjk = (l->val).cout;
            if(pcc[k]>pcc[j] + cjk ){
                pcc[k] = pcc[j] + cjk;
                pere[k] = j;
            }
            l = l->suiv;
        }
   }while((!test_presence(deja_visite,arrivee))&&(pcc[j]!=0xffffffff));
    printf("%ld <- ",arrivee);
    long x=arrivee;
    do{
        printf("%ld <- ",pere[x]);
		x=pere[x];
	}while(x!=depart);
    //Affichage tableau
    /* printf(" voici le tableau père: [");
	for(i=0;i<nb_sommets;i++){
   	printf("%ld ",pere[i]);
    }
    printf("]"); */
    
    //fin
}
/*---FIN---*/


