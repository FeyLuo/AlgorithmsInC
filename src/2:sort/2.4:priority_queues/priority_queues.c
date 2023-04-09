#include <stdbool.h>
#include "template.h"
#include "priority_queues.h"

void swim(Template* T, int k, bool cmp(Template , Template ))
{
    while(k > 1 && (cmp(T[k/2 -1], T[k-1])) ){
        exch(T, k/2 -1, k - 1);
        k = k/2;
    }
}

void sink(Template* T, int k, bool cmp(Template , Template ))
{
    while(k * 2 <= T->size){
        int j = k * 2;
        if(j < T->size && cmp(T[j-1], T[j])) j++;
        if(!cmp(T[k-1], T[j-1]))   break;
        exch(T, k - 1, j - 1);
        k = j;
    }
}

void sink(Template* T, int k, int length, bool cmp(Template , Template ))
{
    while(k * 2 <= length){
        int j = k * 2;
        if(j < length && cmp(T[j-1], T[j])) j++;
        if(!cmp(T[k-1], T[j-1]))   break;
        exch(T, k - 1, j - 1);
        k = j;
    }
}

bool is_heaped(Template* T)
{
    for(int i = 2; i < T->size; i++){
        if(less_abs(T[i/2 - 1], T[i - 1]))
            return false;
    }
    return true;
}

void heap_sort_swim(Template *T)
{
    for(int i = T->size; i > T->size/2; i--)
        swim(T, i, cmp_maxPQ);
    int N = T->size - 1;
    while(N > 0){
        exch(T, 0, N);
        sink(T, 1, N--, cmp_maxPQ);
    }
}

void heap_sort_sink(Template *T)
{
    for(int i = T->size/2; i > 0; i--)
        sink(T, i, cmp_maxPQ);
    int N = T->size - 1;
    while(N > 0){
        exch(T, 0, N);
        sink(T, 1, N--, cmp_maxPQ);
    }
}