#include "adt.h"
#include <stdlib.h>
#include <stdio.h>

struct adt *aux;

static void merge(struct adt *array, int lo, int mid, int hi)
{
    printf("%s(%d, %d, %d)\n", __func__, lo, mid, hi);
    int i = lo, j = mid + 1;
    copy(array, aux, lo, hi);
    for(int k = lo; k <= hi; k++){
        if(i > mid)                     set_value(&array[k], &aux[j++]);
        else if(j > hi)                 set_value(&array[k], &aux[i++]);
        else if(less(&aux[i], &aux[j])) set_value(&array[k], &aux[i++]);
        else                            set_value(&array[k], &aux[j++]);
    }
}

static void topdown_merge_sort_r(struct adt *adt, int lo, int hi)
{
    if(hi <= lo) return;
    int mid = (lo + hi)/2;
    topdown_merge_sort_r(adt, lo, mid);
    topdown_merge_sort_r(adt, mid + 1, hi);
    merge(adt, lo, mid, hi);
}

void topdown_merge_sort(struct adt *adt)
{
    aux = adt_array(adt->type, adt->size);
    topdown_merge_sort_r(adt, 0, adt->size - 1);
    free(aux);
}

void bottomup_merge_sort(struct adt *adt)
{
    aux = adt_array(adt->type, adt->size);
    int length = adt->size;
    for(int ssize = 1; ssize < length; ssize *= 2)
        for(int lo = 0; lo < length; lo += 2 * ssize)
            merge(adt, lo, lo + ssize - 1, (lo + 2*ssize - 1)>length? length: (lo + 2*ssize - 1));
    free(aux);
}