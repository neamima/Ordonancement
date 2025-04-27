#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    
    int l = taille(root);
    matrice *graph = rr(root,1);
    //printmatrice(graph);
    printtable(graph,root);
    stepprintinggraph(graph,root,graph->column);*/
    /*char *path=(char *)argv[argc-1];
    node *root=filetoliste(path);
    int l = taille(root);
    matrice *graph = rr(root,1);
    //printmatrice(graph);
    printtable(graph,root);
    stepprintinggraph(graph,root,graph->column);*/

    char *path=(char *)argv[argc-1];
    node *liste=filetoliste(path);
    matrice *graph;
    int choice;
    printf("choisir l'algorithme d'ordonancement :\n1.FIFO\n2.SJF\n3.RR\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            graph=fifo(liste);
            break;
        case 2:
            graph=sjf(liste);
            break;
        case 3:
            int r;
            printf("donner r :");
            scanf("%d",&r);
            graph = rr(liste,r);
            break;
        default:
            printf("choix invalide\n");
    }
    printf("graph");
    printtable(graph,liste);
    int i=0;
    char t;
    do{
        stepprintinggraph(graph,liste,i);
        if(i==0){
            printf("\ns : suivant , f : fin , q : quitter");
            scanf("%s",&t);
            if(t != 's' && t != 'f' && t != 'q'){
                printf("choix invalid");
                return EXIT_FAILURE;
            }
        }else if (i>0 && i< graph->column){
            printf("\ns : suivant , p : precedant , d : debut , f : fin , q : quitter");
            scanf("%s",&t);
            if(t != 's' && t != 'p' && t != 'd' && t != 'f' && t != 'q'){
                printf("choix invalid");
                return EXIT_FAILURE;
            }
        } else if (i == graph->column){
            printf("\np : precedant , d : debut , q : quitter");
            scanf("%s",&t);
            if(t != 'p' && t != 'd' && t != 'q'){
                printf("choix invalid");
                return EXIT_FAILURE;
            }
        }
        
        

        if(t == 's'){
            i++;
        } else if (t == 'p'){
            i--;
        } else if (t == 'f') {
            i=graph->column;
        } else if (t == 'd') {
            i=0;
        } else if (t == 'q') {
            break;
        } else {
            printf("Errer");
            return EXIT_FAILURE;
        }
    }
    while(1);
    
}