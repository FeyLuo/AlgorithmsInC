#include <stdlib.h>
#include "ADT.h"

Queue* queue()
{
    Queue* Q = (Queue*)calloc(1, sizeof(Queue));
    Q->first = NULL;
    Q->last  = NULL;
    Q->n     = 0;
    return Q;
}

void enqueue(Queue* Q, Template* T)
{
    Node* old_last = Q->last;
    Q->last = (Node*)calloc(1, sizeof(Node));
    Q->last->value = T;
    Q->last->next  = NULL;
    if(Q->first == NULL)          Q->first = Q->last;
    else                    old_last->next = Q->last;
    Q->n++;
}

Template* dequeue(Queue* Q)
{
    if(is_empty_queue(Q))   abort();
    Template* T = Q->first->value;
    Q->first = Q->first->next;
    Q->n--;
    return T;
}