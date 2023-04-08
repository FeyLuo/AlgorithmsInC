#include "template.h"
#include "sort.h"
#include "applications.h"
#include "priority_queues.h"
#include <stdlib.h>

int sum;
Template* aux;

static void merge_and_count(Template *array, int lo, int mid, int hi)
{
    //printf("%s(%d, %d, %d)\n", __func__, lo, mid, hi);
    int i = lo, j = mid + 1;
    copy(array, aux, lo, hi);
    for(int k = lo; k <= hi; k++){
        if(i > mid)                     set_value(&array[k], &aux[j++]);
        else if(j > hi)                 set_value(&array[k], &aux[i++]);
        else if(less(aux[i], aux[j]))   set_value(&array[k], &aux[i++]);
        else                            set_value(&array[k], &aux[j++]), sum += (mid - i + 1);
    }
}

int inversions(int* array, int size)
{
    sum = 0;
    Template* T = Template_array(INT, size, array);
    aux = Template_array(T->type, T->size);
    int length = T->size - 1;
    for(int ssize = 1; ssize <= length; ssize *= 2)
        for(int lo = 0; lo < length; lo += 2 * ssize)
            merge_and_count(T, lo, lo + ssize - 1, (lo + 2*ssize - 1) >= length? length: (lo + 2*ssize - 1));
    return sum;
}

int Kendall_tau(int *a, int *b, int size)
{
    int* Ai = (int*)calloc(size, sizeof(int));
    int* Ci = (int*)calloc(size, sizeof(int));
    for(int i = 0; i < size; i++)
        Ai[a[i]] = i;
    for(int i = 0; i < size; i++)
        Ci[i] = Ai[b[i]];
    return inversions(Ci, size);
}

double meadian(Template* T)
{
    Meadian_Finder* M = (Meadian_Finder*)calloc(1, sizeof(Meadian_Finder));
    M->maxPQ = Template_array(T->type, len(T)/2 + 2);
    M->minPQ = Template_array(T->type, len(T)/2 + 2);
    M->max_len = 0;
    M->min_len = 0;
    for(int i = 0; i < len(T); i++){
        if(M->max_len == 0){
            set_value(&M->maxPQ[M->max_len++], &T[i]);
            continue;
        }
        if(!less(T[i], M->maxPQ[0])){
            set_value(&M->minPQ[M->min_len++], &T[i]);
            swim(M->minPQ, M->min_len, cmp_minPQ);
        }
        else{
            set_value(&M->maxPQ[M->max_len++], &T[i]);
            swim(M->maxPQ, M->max_len, cmp_maxPQ);
        }
        if(M->max_len - M->min_len > 1 || M->min_len - M->max_len > 1){
            if(M->max_len > M->min_len){
                set_value(&M->minPQ[M->min_len++], &M->maxPQ[0]);
                swim(M->minPQ, M->min_len, cmp_minPQ);
                exch(M->maxPQ, 0, M->max_len - 1);
                sink(M->maxPQ, 1, --M->max_len, cmp_maxPQ);
            }
            else{
                set_value(&M->maxPQ[M->max_len++], &M->minPQ[0]);
                swim(M->maxPQ, M->max_len, cmp_maxPQ);
                exch(M->minPQ, 0, M->min_len - 1);
                sink(M->minPQ, 1, --M->min_len, cmp_minPQ);
            }
        }
    }
    if(M->min_len == M->max_len)
        return (double) (GET_INT_VALUE(M->maxPQ[0]) + GET_INT_VALUE(M->minPQ[0]))/2.0;
    if(M->max_len > M->min_len)
        return (double)GET_INT_VALUE(M->maxPQ[0]);
    return (double)GET_INT_VALUE(M->minPQ[0]);
}