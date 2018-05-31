#include <stdlib.h>
#include "graphe.h"
#include <string.h>

T_SOMMET* creer_graphe(void){
    return NULL;
}

void visualiser(L_ARC l){
    L_ARC p=l;
    while(p!=NULL){
        printf("%ld %lf \n", (p->val).arrivee, (p->val).cout);
        p=p->suiv;
    }
puts("\n");
}

void visualiser_graphe(T_SOMMET* g,long* pnb_sommets,long* pnb_arcs){
    long i = 0;
    for(;i<*pnb_sommets;i++){
        printf("le nom du sommet est : %s \n en x = %lf y= %lf \n",g[i].nom,g[i].x,g[i].y);
        L_ARC l=creer_L_ARC();
        l=g[i].voisins;
        printf("Listes des voisins et cout associe \n");
        while(l!=NULL){
            printf("voisin:%ld,cout:%lf \n",(l->val).arrivee,(l->val).cout);
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

L_ARC creer_L_ARC(){
    return NULL;
}

void supprime_retour(char* s){
    int l=strlen(s);
    char* p= strchr(s,'\n');
    if(p) *p=0;
    int i;
    //printf("%d ",s[0]);
    while(*s==32 || *s==9){
        for (i=0;i<l-1;i++){
           //printf("%c ",s[i+1]);
           s[i]=s[i+1];
        }
        l--;
    }
}

void reset_arc(T_SOMMET* g,long* H){
    int i,j;
    L_ARC p;
    for(i=0;H[i]!=-1;i++){
        p=g[i].voisins;
        while(p!=NULL){
            for(j=0;j!=i && H[j]!=-1;j++){
                if((p->val).arrivee==j) (p->val).cout=0;
            }
            p=p->suiv;
        }
    }
}

void resultat(T_SOMMET* g,long* pere,long depart,long arrivee,long nb_sommets,int num){
    long x=arrivee;
    Liste chemin=calloc(nb_sommets,sizeof(*chemin));
    chemin=ajout_tete(x,chemin);
    do{
       chemin=ajout_tete(pere[x],chemin);
        x=pere[x];
    }while(x!=depart);
    Liste p=chemin->suiv;
    if(num==9) printf("Depart: %s\n",g[chemin->val].nom);
    else printf("Depart: %s ->",g[chemin->val].nom);
    while((p->suiv)->suiv!=NULL){
        if(num==9) printf("Ligne: %s, Station: %s\n",g[p->val].ligne,g[p->val].nom);
        else printf(" %s->",g[p->val].nom);
        p=p->suiv;
    }
    printf("Arrive: %s\n",g[p->val].nom);
}

Liste ajout_tete(long k,Liste l){
    Liste nv_liste = malloc(sizeof(*nv_liste));
    nv_liste->val = k;
    nv_liste->suiv = l;
    return nv_liste;
}

T_SOMMET* creation_graphe(T_SOMMET* g,char* nom_fichier,long* pnb_sommets,long* pnb_arcs){
   FILE * f;
   f=fopen(nom_fichier,"r");
    if(f == 0) {
        perror("fopen");
        exit(1);
    }
    long nb_sommets,nb_arcs,i,numero,depart;
    T_ARC T;
    char ligne[128];
    char mot[512];
    fscanf(f,"%ld %ld ",&nb_sommets,&nb_arcs); // Lecture de la première ligne
    *pnb_sommets= nb_sommets;
    *pnb_arcs= nb_arcs;
    fgets(mot,511,f); // On saute la deuxième ligne
    g=calloc(nb_sommets,sizeof(T_SOMMET)); // Création du graphe
    for(i=0;i<nb_sommets;i++){ // On rentre la lat,long et nom de chaque sommet
        fscanf(f,"%ld %lf %lf %s",&numero, &(g[i].x), &(g[i].y),ligne);
        g[i].ligne=calloc(128,sizeof(char));
        strcpy(g[i].ligne,ligne);
        g[i].position_tas=-1;
        g[i].position_graphe=i;
        fgets(mot,511,f);
        supprime_retour(mot);
        //printf("%s\n",mot);
        g[i].nom=calloc(512,sizeof(char));
        strcpy(g[i].nom,mot);
        g[i].voisins=creer_L_ARC();
    }
    fgets(mot,511,f);
    fgets(mot,511,f);  // On passe aux arcs
    for(i=0;i<nb_arcs;i++){// On rentre tous les arcs partant du sommet i
        fscanf(f,"%ld %ld %lf ",&depart, &(T.arrivee), &(T.cout));
        g[depart].voisins=ajout_teteG(T,g[depart].voisins);
    }

   fclose(f);
    return g;
}



