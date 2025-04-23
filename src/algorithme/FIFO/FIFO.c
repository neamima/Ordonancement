#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FIFO.h"
#include "../../../include/ord.h"

node *fifoaddqueue(node *root,process *p){
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

matrice *fifo(node *liste){
    node *cpyliste=cpynode(liste);
    int l = taille(liste);
    matrice *graph = creatematrice(l);
    node *queue=NULL;
    int i=0;

    while(cpyliste || queue){
        node *temp=cpyliste;
        while(temp){
            if(temp->p->date_entree==i){
                queue=fifoaddqueue(queue,temp->p);
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

