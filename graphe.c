#include <stdlib.h>
#include "graphe.h"
#include <string.h>

T_SOMMET* creer_graphe(void){
    return NULL;
}

void visualiser(L_ARC l){
    L_ARC p=l;
    while(p!=NULL){
        printf("%d %lf \n", (p->val).arrivee, (p->val).cout);
        p=p->suiv;
    }
puts("\n");
}

void visualiser_graphe(T_SOMMET* g,int* pnb_sommets,int* pnb_arcs){
    int i = 0;
    for(;i<*pnb_sommets;i++){
        printf("le nom du sommet est : %s \n en x = %lf y= %lf \n",g[i].nom,g[i].x,g[i].y);
        L_ARC l=creer_liste();
        l=g[i].voisins;
        printf("Listes des voisins et cout associe \n");
        while(l!=NULL){
            printf("voisin:%d,cout:%lf \n",(l->val).arrivee,(l->val).cout);
            l=l->suiv;
        }

    }

}
L_ARC ajout_teteG(T_ARC k,L_ARC l){
    L_ARC nv_liste = calloc(1,sizeof(*nv_liste));
    nv_liste->val = k;
    nv_liste->suiv = l;
    return nv_liste;
}

L_ARC creer_liste(){
    return NULL;
}



T_SOMMET* creation_graphe(T_SOMMET* g,char* nom_fichier,int* pnb_sommets,int* pnb_arcs){
   FILE * f;
   f=fopen(nom_fichier,"r");
    if(f == 0) {
        perror("fopen");
        exit(1);
    }
    int nb_sommets,nb_arcs,i,numero,depart;
    T_ARC T;
    char line[128];
    char mot[512];
    fscanf(f,"%d %d ",&nb_sommets,&nb_arcs); // Lecture de la première ligne
    *pnb_sommets= nb_sommets;
    *pnb_arcs= nb_arcs;
    fgets(mot,511,f); // On saute la deuxième ligne
    g=calloc(nb_sommets,sizeof(T_SOMMET)); // Création du graphe
    for(i=0;i<nb_sommets;i++){ // On rentre la lat,long et nom de chaque sommet
        fscanf(f,"%d %lf %lf %s",&numero, &(g[i].x), &(g[i].y), line);
        fgets(mot,511,f);
        g[i].nom=calloc(512,sizeof(char));
        strcpy(g[i].nom,mot);
        g[i].voisins=creer_liste();
    }
    fgets(mot,511,f); // On passe aux arcs
    for(i=0;i<nb_arcs;i++){// On rentre tous les arcs partant du sommet i
        fscanf(f,"%d %d %lf ",&depart, &(T.arrivee), &(T.cout));
        g[depart].voisins=ajout_teteG(T,g[depart].voisins);
    }

   fclose(f);
    return g;
}



