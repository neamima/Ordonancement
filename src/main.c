#include <stdio.h>
#include <stdlib.h>
#include "../include/ord.h"
#include "./algorithme/FIFO/FIFO.h"
#include "./algorithme/SJF/SJF.h"
#include "./algorithme/RR/RR.h"





int main(int argc,int *argv[]){
    node *root=createnode(createprocess("p1",1,3,0));
    addnode(root,createprocess("p2",0,5,1));
    addnode(root,createprocess("p3",0,8,2));
    
    int duree = duree_totale(root);
    int l = taille(root);
    matrice *graph = rr(root,2);
    printmatrice(graph);

}