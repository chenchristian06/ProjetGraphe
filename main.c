//
//  main.c
//  Projet1A
//
//  Created by Chen Christian on 01/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include "graphe.h"
#include "dijkstra.h"
#include "hachage.h"
int main(){
/*---DEBUT CREATION GRAPHE---*/
    T_SOMMET* g;
    //char nom_fichier[512];
    //printf("Veuillez spécifier le nom de fichier où extraire le graphe \n ");
    //scanf("%s",nom_fichier);
    char* nom_fichier="C:/Users/Tanguy/Downloads/graphe1.txt";
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
        if(j!=-1){
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
        }
   }while((j!=arrivee)&&j!=-1); // Si j=-1, le sommet n'a plus de voisin => pas de chemin possible
	if(j!=arrivee){
		puts("Pas de chemin possible \n");
   }
   else{
    printf("fin <-%ld <- ",arrivee);
    long x=arrivee;
    do{
        printf("%ld <- ",pere[x]);
		x=pere[x];
	}while(x!=depart);
   puts("début\n");
   }
    //Affichage tableau
    /* printf(" voici le tableau père: [");
	for(i=0;i<nb_sommets;i++){
   	printf("%ld ",pere[i]);
    }
    printf("]"); */
   H_Liste* table=NULL;
   table=remplissage_table(table,g,nb_sommets);
   visualiser_table(table,nb_sommets);
   char nom[3]="Aaa";
   T_SOMMET* S;
   S=calloc(1,sizeof(*S));
   S->nom=calloc(512,sizeof(char));
   *S=rechercher(nom,table,nb_sommets);
   printf("%s %lf %lf\n",S->nom,S->x,S->y);
   L_ARC l=creer_L_ARC();
        l=S->voisins;
        printf("Listes des voisins et cout associe \n");
        while(l!=NULL){
            printf("voisin:%ld,cout:%lf \n",(l->val).arrivee,(l->val).cout);
            l=l->suiv;
        }

    //fin
}
/*---FIN---*/


