//
//  main.c
//  Projet1A
//
//  Created by Chen Christian on 01/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include "graphe.h"
#include "dijkstra.h"
main(){
    T_SOMMET* g;
    //char nom_fichier[512];
    //printf("Veuillez spécifier le nom de fichier où extraire le graphe \n ");
    //scanf("%s",nom_fichier);
    char* nom_fichier="graphe1.txt";
    g = creer_graphe();
    int nb_sommets;
    int nb_arcs;
    g=creation_graphe(g, nom_fichier,&nb_sommets,&nb_arcs);
    //visualiser_graphe(g,&nb_sommets,&nb_arcs);
    //printf("le graphe crée\n");
  
    //Dijkstra:
    int depart;
    int arrivee;
    int i;
    int j;
    int* pere;
    double* pcc;
    printf("Donner depart\n");
    scanf("%d",&depart);
    printf("Donner arrivee\n");
    scanf("%d",&arrivee);
    Liste deja_visite;
    Liste pas_visite;
    pere = creer_pere(nb_sommets);
    pcc = creer_poids(nb_sommets);
    pcc=depart_poids(depart, pcc);
    deja_visite = creation_deja_visite();
    pas_visite = creation_pas_visite(nb_sommets);
    do{
        j = recherche_min(pcc, nb_sommets,deja_visite);
        pas_visite = supprime_liste(pas_visite, j);
        ajout_tete(j, deja_visite);
        L_ARC l = g[j].voisins;
        while(l!=NULL){
            int k = (l->val).arrivee;
            double cjk = (l->val).cout;
            printf("%lf %lf %lf \n",pcc[k],pcc[j],cjk);
            if(pcc[k]>pcc[j] + cjk ){
                printf("%d\n",k);
                pcc[k] = pcc[j] + cjk;
                pere[k] = j;
            }
            l = l->suiv;
        }
   }while((test_presence(deja_visite,arrivee))&&(pcc[j]!=0xffffffff));
   /*printf("%d",arrivee);
	int x=arrivee;
	while(x!=depart){
   	printf("%d",pere[x]);
		x=pere[x];
	}*/
	for(i=0;i<nb_sommets;i++){
   	printf("%d ",pere[i]);
	}
}


