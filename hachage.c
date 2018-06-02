#include"hachage.h"
#include"graphe.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


H_Liste ajout_tete_H(T_SOMMET k,H_Liste l){
    H_Liste nv_liste = calloc(1,sizeof(*nv_liste));
    nv_liste->sommet=k;
    nv_liste->suiv=l;
    return nv_liste;
}

unsigned long puissance(unsigned long a,unsigned long b){
    int i;
    long p=1;
    if(b==0) return 1;
    for(i=0;i<b;i++){
        p*=a;
    }
    return p;
}

long hachage(char* nom_sommet,long N){
    int l=strlen(nom_sommet);
    long h=nom_sommet[0]; unsigned long a=31415; unsigned long b=27183;
    long i;
    if(nom_sommet[1]=='\0') return h%N;
    for(i=1;i<l;i++){
        h+=nom_sommet[i]*(((a*puissance(b,i)%(N-1))));//hachage universel
    }
    return h%N;
}

H_Liste* remplissage_table(H_Liste* tab,T_SOMMET* g,long n){
    tab=calloc(n,sizeof(*tab));
    long i,h;
    for(i=0;i<n;i++){
        h=hachage(g[i].nom,n);
        tab[h]=ajout_tete_H(g[i],tab[h]);
    }
    return tab;
}

void visualiser_table(H_Liste* tab,long n){
    long i;
    printf("[");
    for(i=0;i<n;i++){
        affichage_H(tab[i]);
    }
    printf("]\n");
}


void affichage_H(H_Liste l){
    if(!l){
        printf("la liste est vide\n");

    }
    else{
        H_Liste t = l;
        while(t!=NULL){
            printf("%s, ",(t->sommet).nom);
            t = t->suiv;
        }
        printf("\n");
    }
}

void rechercher(char* nom,H_Liste* tab,long* H,long N){
    long h=hachage(nom,N);
    int i=0;
    H_Liste p=tab[h];
    while(p!=NULL){
        if(strcasecmp((p->sommet).nom,nom)==0){
                H[i]=(p->sommet).position_graphe;
                i++;
        }
        p=p->suiv;
    }
    H[i]=-1;
    if(H[0]!=-1) return;
    printf("Erreur: le sommet %s n'existe pas",nom);
    exit(1);
}
