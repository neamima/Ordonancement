#include <stdio.h>
#include <stdlib.h>
#include "../include/ord.h"
#include "./algorithme/FIFO/FIFO.h"
#include "./algorithme/SJF/SJF.h"
#include "./algorithme/RR/RR.h"





int main(int argc,int *argv[]){
    /*node *root=createnode(createprocess("p1",0,3,0));
    addnode(root,createprocess("p2",2,6,1));
    addnode(root,createprocess("p3",4,4,2));
    addnode(root,createprocess("p4",6,5,3));
    addnode(root,createprocess("p5",8,2,4));
    
    int duree = duree_totale(root);
    int l = taille(root);
    matrice *graph = rr(root,1);
    //printmatrice(graph);
    printtable(graph,root);
    stepprintinggraph(graph,root,graph->column);*/
    char *path=(char *)argv[argc-1];
    node *root=filetoliste(path);
    int duree = duree_totale(root);
    int l = taille(root);
    matrice *graph = rr(root,1);
    //printmatrice(graph);
    printtable(graph,root);
    stepprintinggraph(graph,root,graph->column);
}