#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RR.h"
#include "../../../include/ord.h"

node *rraddqueue(node *root,process *p){
    if(!root){
        return createnode(p);
    }
    node *temp=root;
    while(temp->nxt){
        temp=temp->nxt;
    }
    temp->nxt = createnode(p);
    return root;
}

node *rrmovetoendqueue(node *root){
    if(!root || !root->nxt){
        return root;
    }
    node *temp1=root, *temp2=root;
    while(temp1->nxt){
        temp1=temp1->nxt;
    }
    temp1->nxt=temp2;
    temp2=temp2->nxt;
    temp1->nxt->nxt=NULL;
    return temp2;
}

matrice *rr(node *liste,int r){
    node *cpyliste=cpynode(liste);
    int l = taille(liste);
    matrice *graph = creatematrice(l);
    node *queue=NULL;
    int i=0,j=0;

    while(cpyliste || queue){
        node *temp=cpyliste;
        while(temp){
            if(temp->p->date_entree==i){
                queue=rraddqueue(queue,temp->p);
                cpyliste=delnode(cpyliste,temp->p);
            }
            temp=temp->nxt;
        }
        graph = addcolumn(graph);
        if(queue){
            graph->matrice[queue->p->nb][graph->column-1]=1;
            queue->p->duree--;
            j++;
            if(queue->p->duree==0){
                queue=delfqueue(queue);
                j=0;
            } else if(j==r){
                queue = rrmovetoendqueue(queue);
                j=0;
            }
        }
        i++;
    }
    return graph;
}