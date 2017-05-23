//
// Created by Daniel Cardoso on 22/05/17.
//

#include <stdlib.h>
#include "def.h"

#ifndef CCOLLECTION_QUEUE_H
#define CCOLLECTION_QUEUE_H

#define new_queue (Queue*) malloc(sizeof(Queue))
#define new_node (Node*) malloc(sizeof(Node))

typedef struct queue {
    struct node * pFirst;
    struct node * pLast;
    unsigned int size;
}Queue;

typedef struct node{
    generic info;
    struct node * next;
    struct node * prev;
}Node;

PRIVATE Bool isEmpty(Queue*);
PUBLIC void Qadd(Queue*, generic );
PUBLIC generic Qremove(Queue*);
PUBLIC generic Qget(Queue*,int);
PUBLIC Queue* Qcreate();
PUBLIC int Qsearch(Queue*, generic);

#endif //CCOLLECTION_QUEUE_H
