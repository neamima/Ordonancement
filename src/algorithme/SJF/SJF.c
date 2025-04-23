#include <stdio.h>
#include "SJF.h"
#include "../../../include/ord.h"

node *sjfaddqueue(node *root,process *p){
    if(!root){
        return createnode(p);
    }
    if(p->date_entree<=root->p->date_entree && p->duree < root->p->duree){
        node *temp = createnode(p);
        temp->nxt=root;
        return temp;
    }
    node *temp = root;
    while(temp->nxt && temp->nxt->p->duree <= p->duree){
        temp = temp->nxt;
    }
    if(!temp->nxt){
        temp->nxt = createnode(p);
        return root;
    }
    node *temp2=createnode(p);
    temp2->nxt=temp->nxt;
    temp->nxt=temp2;
    return root;
}

matrice *sjf(node *liste){
    node *cpyliste=cpynode(liste);
    int l = taille(liste);
    matrice *graph = creatematrice(l);
    node *queue=NULL;
    int i=0;
    while(cpyliste || queue){
        node *temp=cpyliste;
        while(temp){
            if(temp->p->date_entree==i){
                queue=sjfaddqueue(queue,temp->p);
                cpyliste=delnode(cpyliste,temp->p);
            }
            temp=temp->nxt;
        }
        graph = addcolumn(graph);
        if(queue){
            graph->matrice[queue->p->nb][graph->column-1]=1;
            queue->p->temp_restant--;
            if(queue->p->temp_restant==0){
                queue->p->fin=i+1;
                queue=delfqueue(queue);
            }
        }
        i++;
    }
    return graph;
}