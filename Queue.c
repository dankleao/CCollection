//
// Created by Daniel Cardoso on 22/05/17.
//

#include "Queue.h"

PRIVATE inline Bool isEmpty( Queue*q )
{
    return ( q->pFirst == q->pLast ? TRUE : FALSE );
}

PUBLIC Queue* Qcreate(){

    static Queue* tempQueue;
    tempQueue = new_queue;
    tempQueue->pFirst = NULL;
    tempQueue->pLast = NULL;
    tempQueue->size = 0;
    return tempQueue;
}

PUBLIC void Qadd( Queue* q, void* data )
{
    static Node* tempNode = NULL;
    tempNode = new_node;
    tempNode->info = data;

    if( q->pFirst == NULL )
    {
        q->pFirst = q->pLast = new_node;
        q->pFirst->info = q->pFirst->next = q->pFirst->prev = NULL;
    }

    tempNode->prev = q->pLast;
    q->pLast = q->pLast->next = tempNode;
    q->pLast->next = NULL;
    q->size++;
}

PUBLIC generic Qget(Queue* q, int index)
{
    if( index >= q->size )
        return NULL;

    register Node* p = q->pFirst->next;
    register int i;
    for( i = 0 ; i < index ; ++i, p = p->next );
    return p->info;
}

PUBLIC generic Qremove(Queue* q)
{
    if( isEmpty(q) )
        return NULL;

    Node* p = q->pFirst->next;
    q->pFirst->next = p->next;
    if( p->next == NULL )
        q->pLast = p->prev;
    else
        p->next->prev = p->prev;
    free(p);
    q->size--;
    return p->info;
}

PUBLIC int Qsearch(Queue* q, generic objAddr )
{
    register Node* p = q->pFirst->next;
    register int i;
    for ( i = 0; i < q->size ; ++i, p = p->next )
        if( p->info == objAddr ) goto Find;

    NotFind:
        return -1;

    Find:
        return i;
}
