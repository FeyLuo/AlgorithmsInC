#ifndef _ADT_H
#define _ADT_H

#include "template.h"

#define NULL ((void*) 0)

typedef struct node{
    Template*   value;
    node*      next;
}Node;  

typedef struct{
    Node* first;
    Node* last;
    int   n;
}Queue;

Queue* queue();

void enqueue(Queue* Q, Template* T);

Template* dequeue(Queue* Q);

inline bool is_empty_queue(Queue* Q)
{
    return Q->first == NULL;
}

inline int size_queue(Queue* Q)
{
    return Q->n;
}


#endif