//
//  main.c
//  Projet1A
//
//  Created by Chen Christian on 01/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include "graphe.h"
#include "dijkstra.h"
#include "liste.h"
main(){
    T_SOMMET* g;
    char* nom_fichier;
    printf("Veuillez spécifier le nom de fichier où extraire le graphe \n ");
    //scanf("%s",nom_fichier);
    nom_fichier="/Users/chenchristian/Desktop/Projet1A/Projet1A/graphe1.txt";
    g = creer_graphe();
    int nb_sommets;
    int nb_arcs;
    g=creation_graphe(g, nom_fichier,&nb_sommets,&nb_arcs);
    visualiser_graphe(g,&nb_sommets,&nb_arcs);
    printf("le graphe crée");
    
    //Dijkstra
    int depart;
    int arrivee;
    int i;
    int j;
    int* pere;
    int* pcc;
    printf("Donner depart\n");
    scanf("%d",&depart);
    printf("Donner arrivee\n");
    scanf("%d",&arrivee);
    Liste deja_visite;
    Liste pas_visite;
    pere = creer_pere(nb_sommets);
    pcc = creer_poids(nb_sommets);
    depart_poids(depart, pcc);
    deja_visite = creation_deja_visite();
    pas_visite = creation_pas_visite(nb_sommets);
    do{
        j = recherche_min(pcc, nb_sommets);
        pas_visite = supprime_liste(pas_visite, j);
        ajout_tete(j, deja_visite);
        L_ARC l = g[j].voisins;
        while(l!=NULL){
            int k = ((g[i].voisins)->val).arrivee;
            double cjk = ((g[i].voisins)->val).cout;
            if(pcc[k]>pcc[j] + cjk ){
                pcc[k] = pcc[j] + cjk;
                pere[k] = j;
            }
            l = l->suiv;
        }
    }while((test_presence(deja_visite,arrivee))&&(pcc[j]!=-1));
}
