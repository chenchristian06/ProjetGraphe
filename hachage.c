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

long puissance(long a,long b){
    int i;
    long p=1;
    if(b==0) return p;
    for(i=0;i<b;i++){
        p*=a;
    }
    return p;
}

long hachage(char* nom_sommet,long N){
    int l=strlen(nom_sommet);
    long h=nom_sommet[0]; long a=31415; long b=27183;
    long i;
    if(nom_sommet[1]=='\0') return h%N;
    for(i=1;i<l;i++){
        h+=nom_sommet[i]*(((a*puissance(b,i))%(N-1)));
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
    for(i=0;i<n;i++){
        affichage_H(tab[i]);
    }
}


void affichage_H(H_Liste l){
    if(!l){
        printf("la liste est vide\n");

    }
    else{
        H_Liste t = l;
        while(t!=NULL){
            printf("%s ",(t->sommet).nom);
            t = t->suiv;
        }
    }
}

T_SOMMET rechercher(char* nom,H_Liste* tab,long N){
    long h=hachage(nom,N);
    return tab[h]->sommet;
}
