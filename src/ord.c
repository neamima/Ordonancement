#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ord.h"

process *createprocess(char *name,int entre,int duree,int nb){
    process *p = (process*)malloc(sizeof(process));
    strcpy(p->name , name);
    p->date_entree = entre;
    p->duree = duree;
    p->temp_restant = duree;
    p->fin=0;
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

int getmaxlenght(node *liste){
    int lenght=0;
    if(!liste){
        return lenght;
    }
    while(liste){
        int temp = strlen(liste->p->name);
        if(temp>lenght){
            lenght = temp;
        }
        liste = liste->nxt;
    }
    return lenght;
}

void stepprintinggraph(matrice *m,node *liste,int step){
    int l = getmaxlenght(liste),i,j;
    for(i=0;i<l;i++){
        printf(" ");
    }
    printf("^\n");
    for(i=0;i<m->row;i++){
        for(j=0;j<l-strlen(liste->p->name);j++){
            printf(" ");
        }
        printf("%s|",liste->p->name);
        for(j=0;j<step;j++){
            if(m->matrice[i][j]==1){
                printf("====");
            } else {
                printf("    ");
            }
        }

        printf("\n");
        liste=liste->nxt;
    }
    for(i=0;i<l;i++){
        printf(" ");
    }
    printf("+");
    for(i=0;i<m->column;i++){
        printf("----");
    }
    printf("-->\n");
    for(i=0;i<l;i++){
        printf(" ");
    }
    for(i=0;i<m->column+1;i++){
        if(i<10){
            printf("%d   ",i);
        }else if(i<100){
            printf("%d  ",i);
        }else {
            printf("%d ",i);
        }
        
    }
}

void printlignetable(int l){
    int i;
    printf("+");
    for(i=0;i<l;i++){
        printf("-");
    }
    printf("+");
    for(i=0;i<15;i++){
        printf("-");
    }
    printf("+");
    for(i=0;i<7;i++){
        printf("-");
    }
    printf("+");
    for(i=0;i<19;i++){
        printf("-");
    }
    printf("+");
    for(i=0;i<17;i++){
        printf("-");
    }
    printf("+\n");
}
void printcase(int n,int space){
    int i,k,j;
    if(n<10){
        k=(space - 1)/2;
        j=space-(k+1);
    }else if (n<100){
        k=(space - 2)/2;
        j=space-(k+2);
    }else {
        k=(space - 3)/2;
        j=space-(k+3);
    }
    for(i=0;i<k;i++){
        printf(" ");
    }
    printf("%d",n);
    for(i=0;i<j;i++){
        printf(" ");
    }
    printf("|");
}

void printtable(matrice *m,node *liste){
    int l = getmaxlenght(liste),i,j;
    char *p ="Processus";
    int temp=strlen(p);
    if(temp > l){
        l=temp;
    }
    printlignetable(l);
    int k=(l-strlen(p))/2;
    printf("|");
    for(j=0;j<k;j++){
        printf(" ");
    }
    
    printf("%s",p);
    k=l-(k+strlen(p));
    for(j=0;j<k;j++){
        printf(" ");
    }
    printf("| Date d'entree | Duree | Temps de rotation | Temps d'attente |\n",p);
    printlignetable(l);
    for(i = 0;i<m->row;i++){
        printf("|");
        k=(l-strlen(liste->p->name))/2;
        for(j=0;j<k;j++){
            printf(" ");
        }
        printf("%s",liste->p->name);
        k=l-(k+strlen(liste->p->name));
        for(j=0;j<k;j++){
            printf(" ");
        }
        printf("|");
        printcase(liste->p->date_entree,15);
        printcase(liste->p->duree,7);
        printcase(liste->p->fin-liste->p->date_entree,19);
        printcase(liste->p->fin-liste->p->date_entree-liste->p->duree,17);
        printf("\n");
        printlignetable(l);
        liste=liste->nxt;
    }

}

char *rmfirstspace(char* line){
    while(*line==' ' || *line=='\t'){
        *line++;
    }
    return line;
}

node *filetoliste(char *path){
    FILE *file = fopen(path,"r");
    node *liste=NULL;
    char line[100];
    int i=0;
    while(fgets(line,sizeof(line),file)){
        strcpy(line,rmfirstspace(line));
        char *com =strstr(line,"//");
        if (com != NULL) {
            if(com==line){
                continue;
            }else{
                *com = '\0';
            }
        }else {
            int l=strcspn(line,"\n");
            if(l==0){
                continue;
            }
            line[l]='\0';
        }
        
        
        char *name = strtok(line,",");
        char *entre =strtok(NULL,",");
        char *dure = strtok(NULL,",");
        liste = addnode(liste,createprocess(name,atoi(entre),atoi(dure),i));
        i++;
    }
    fclose(file);
    return liste;
}