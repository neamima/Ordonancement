#ifndef ORD_H
#define ORD_H

typedef struct process {
    char *name;
    int date_entree;
    int duree;
    int nb;
} process;

typedef struct node{
    process *p;
    struct node *nxt;
} node;

typedef struct matrice{
    int row;
    int column;
    int **matrice;
} matrice;

process *createprocess(char *name,int entre,int duree,int nb);
node *createnode(process *p);
node *addnode(node *root,process *p);
node *cpynode(node *root);
node *delnode(node *root,process *p);


node *delfqueue(node *queue);
void printnode(node *root);


int taille(node *root);
int duree_totale(node *root);

matrice *creatematrice(int taille);
matrice *addcolumn(matrice *m);
void printmatrice(matrice *m);

#endif // ORD_H