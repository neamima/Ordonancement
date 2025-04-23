#include <stdio.h>
#include <stdlib.h>
#include "../include/ord.h"

process *createprocess(char *name,int entre,int duree,int nb){
    process *p = (process*)malloc(sizeof(process));
    p->name = name;
    p->date_entree = entre;
    p->duree = duree;
    p->nb=nb;
    return p;
}

node *createnode(process *p){
    node *root =(node*)malloc(sizeof(node));
    root->p=p;
    root->nxt=NULL;
    return root;
}

node *addnode(node *root,process *p){
    node *temp1 = createnode(p);
    if(!root){
        return temp1;
    }
    node *temp2=root;
    while(temp2->nxt){
        temp2 = temp2->nxt;
    }
    temp2->nxt = temp1;
    return root;
}


node *cpynode(node *root){
    node *cpy = createnode(root->p);
    node *temp = cpy;
    while(root->nxt){
        temp->nxt = createnode(root->nxt->p);
        temp=temp->nxt;
        root=root->nxt;
    }
    return cpy;
}

node *delnode(node *root,process *p){
    if(!root){
        return root;
    }
    node *temp = root;
    if(root->p->nb == p->nb){
        root = root->nxt;
        free(temp);
        return root;
    }
    while(temp->nxt && temp->nxt->p->nb != p->nb){
        temp=temp->nxt;
    }
    if(!temp->nxt){
        return root;
    }
    node *temp2 = temp->nxt;
    temp->nxt = temp2->nxt;
    free(temp2);
    return root;

}



node *delfqueue(node *queue){
    node *temp=queue;
    queue = queue->nxt;
    free(temp);
    return queue;
}


void printnode(node *root){
    while(root){
        printf("%s -> ",root->p->name);
        root = root->nxt;
    }
}

int taille(node *root){
    int taille=0;
    while(root){
        taille++;
        root=root->nxt;
    }
    return taille;
}

int duree_totale(node *root){
    int duree = 0;
    while(root){
        duree += root->p->duree;
        root=root->nxt;
    }
    return duree;
}

matrice *creatematrice(int taille){
    matrice *m = (matrice*)malloc(sizeof(matrice));
    m->row=taille;
    m->column=0;
    m->matrice = calloc(taille,sizeof(int*));
    return m;
}

matrice *addcolumn(matrice *m){
    for(int i=0;i<m->row;i++){
        m->matrice[i]=realloc(m->matrice[i],(m->column+1)*sizeof(int));
        m->matrice[i][m->column]=0;
    }
    m->column++;
    return m;
}

void printmatrice(matrice *m){
    for(int i=0;i<m->row;i++){
        for(int j=0;j<m->column;j++){
            printf("%d\t",m->matrice[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
}