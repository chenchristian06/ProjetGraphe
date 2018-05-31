//
//  test.c
//  tritas
//
//  Created by Chen Christian on 14/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include <stdio.h>
#include "graphe.h"
#include "dijkstra.h"
#include "hachage.h"
#include "tas.h"
int main(){
    /*---DEBUT CREATION GRAPHE---*/
    T_SOMMET* g;
    int num;
    char* nom_fichier;
    printf("Veuillez sélectionner le numero du fichier: 1.graphe1 2.graphe2 3.NewYork 4.Colorado 5.Floride 6.GrandLacs 7.USACentral 8.USAOuest 9.Metro\n");
    scanf("%d",&num);
    getchar();
    switch(num){
    case 1: nom_fichier="C:/Users/Tanguy/Downloads/graphe1.txt";
    break;
    case 2: nom_fichier="C:/Users/Tanguy/Downloads/graphe2.txt";
    break;
    case 3: nom_fichier="C:/Users/Tanguy/Downloads/grapheNewYork.csv";
    break;
    case 4: nom_fichier="C:/Users/Tanguy/Downloads/grapheColorado.csv";
    break;
    case 5: nom_fichier="C:/Users/Tanguy/Downloads/grapheFloride.csv";
    break;
    case 6: nom_fichier="C:/Users/Tanguy/Downloads/grapheGrandLacs.csv";
    break;
    case 7: nom_fichier="C:/Users/Tanguy/Downloads/grapheUSACentral.csv";
    break;
    case 8: nom_fichier="C:/Users/Tanguy/Downloads/grapheUSAOuest.csv";
    break;
    case 9: nom_fichier="C:/Users/Tanguy/Downloads/metroetu.csv";
    break;
    default: printf("Le fichier n'existe pas");
    exit(-1);
    }
    g = creer_graphe();
    long nb_sommets;
    long nb_arcs;
    g=creation_graphe(g, nom_fichier,&nb_sommets,&nb_arcs);
    printf("ce graphe contient %ld sommets \n",nb_sommets);
    //visualiser_graphe(g,&nb_sommets,&nb_arcs);
    //printf("le graphe crée\n");
    /*---FIN---*/
    /*---DEBUT DIJKSTRA---*/
    H_Liste* tabh=NULL;
    tabh=remplissage_table(tabh,g,nb_sommets);
    long H[10];
    char D[512];
    char A[512];
    long depart;
    long arrivee;
    long* pere;
    TAS* pcc;
    if(num!=9) printf("Donner le nom du sommet de depart:\n");
    else printf("Donner le nom de la staion de depart:\n");
    fgets(D,512,stdin);
    supprime_retour(D);
    rechercher(D,tabh,H,nb_sommets);
    depart=H[0];
    if(num==9) reset_arc(g,H);
    if(num!=9) printf("Donner le nom du sommet d'arrivee:\n");
    else printf("Donner le nom de la station d'arrivee:\n");
    fgets(A,512,stdin);
    supprime_retour(A);
    rechercher(A,tabh,H,nb_sommets);
    arrivee=H[0];
    if(num==9) reset_arc(g,H);
    long j;
    long taille_tas = nb_sommets;
    double poids;
    pere = creer_pere(nb_sommets);
    pcc = creer_poids(nb_sommets,depart,g);
    do{
        j = pcc[0].sommet;
        poids = pcc[0].poids;
        supprime_tete_tas(pcc, taille_tas , g);
        //printf("tête supprimé: %ld \n",j);
        /*long i;
        for(i=0;i<nb_sommets;i++){
            printf("%ld , sommet : %ld de poids %lf \n",i,pcc[i].sommet,pcc[i].poids);
        }*/
        taille_tas -= 1;
        L_ARC l = g[j].voisins;
        while(l!=NULL){
            long k = (l->val).arrivee;
            //printf("voisin : %ld \n",k);
            double cjk = (l->val).cout;
            if(pcc[g[k].position_tas].poids > poids + cjk ){
                pcc[g[k].position_tas].poids = poids + cjk;
                pere[k] = j;
                //long i;
                pcc = augmentetas(pcc,g[k].position_tas, g);
                /*for(i=0;i<nb_sommets;i++){
                    printf("%ld , sommet : %ld de poids %lf \n",i,pcc[i].sommet,pcc[i].poids);
                }*/
            }

            l = l->suiv;
        }
    }while((j!=arrivee)&&(pcc[g[j].position_tas].poids!=0xffffffff));
if(j!=arrivee){
    puts("Pas de chemin possible \n");
}
else{
    resultat(g,pere,depart,arrivee,nb_sommets,num);
}
}
