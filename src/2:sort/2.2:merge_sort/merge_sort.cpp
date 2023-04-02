#include "template.h"
#include <stdlib.h>
#include <stdio.h>

Template *aux;

static void merge(Template *array, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;
    copy(array, aux, lo, hi);
    for(int k = lo; k <= hi; k++){
        if(i > mid)                     set_value(&array[k], &aux[j++]);
        else if(j > hi)                 set_value(&array[k], &aux[i++]);
        else if(less(aux[i], aux[j]))   set_value(&array[k], &aux[i++]);
        else                            set_value(&array[k], &aux[j++]);
    }
}

static void topdown_merge_sort_r(Template *T, int lo, int hi)
{
    if(hi <= lo) return;
    int mid = (lo + hi)/2;
    topdown_merge_sort_r(T, lo, mid);
    topdown_merge_sort_r(T, mid + 1, hi);
    merge(T, lo, mid, hi);
}

void topdown_merge_sort(Template *T)
{
    aux = Template_array(T->type, T->size);
    topdown_merge_sort_r(T, 0, T->size - 1);
    free(aux);
}

void bottomup_merge_sort(Template *T)
{
    aux = Template_array(T->type, T->size);
    int length = T->size;
    for(int ssize = 1; ssize < length; ssize *= 2)
        for(int lo = 0; lo < length; lo += 2 * ssize)
            merge(T, lo, lo + ssize - 1, (lo + 2*ssize - 1)>length? length: (lo + 2*ssize - 1));
    free(aux);
}