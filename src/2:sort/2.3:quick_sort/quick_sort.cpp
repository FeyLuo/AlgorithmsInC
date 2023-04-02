#include "template.h"

static int partition(Template *T, int lo, int hi)
{
    int i = lo, j = hi + 1;
    while(true){
        while(less_abs(T[++i], T[lo])) 
            if(i == hi) 
                break;
        while(less_abs(T[lo], T[--j])) 
            if(j == lo)
                break;
        if(i >= j)
            break;
        exch(T, i, j);
    }
    exch(T, lo, j);
    return j;
}

static void quick_sort_r(Template *T, int lo, int hi)
{
    if(hi <= lo)    return;
    int pos = partition(T, lo, hi);
    quick_sort_r(T, lo, pos - 1);
    quick_sort_r(T, pos + 1, hi);
}

void quick_sort(Template *T)
{
    quick_sort_r(T, 0, T->size - 1);
}

static void quick_3way_sort_r(Template *T, int lo, int hi)
{
    if(hi <= lo)    return;
    int lt = lo, gt = hi, i = lo + 1;
    Template v = T[lo];
    while(i <= gt){
        switch (cmp(T[i], v))
        {
        case 1:     //T[i] > v
            exch(T, i, gt--);
            break;
        case 0:     //T[i] = v
            i++;
            break;
        case -1:    //T[i] < v
            exch(T, i++, lt++);
            break;
        }
    }
    quick_3way_sort_r(T, lo, lt - 1);
    quick_3way_sort_r(T, gt + 1, hi);
}

void quick_3way_sort(Template *T)
{
    quick_3way_sort_r(T, 0, T->size - 1);
}