#include "adt.h"

static int partition(struct adt *adt, int lo, int hi)
{
    int i = lo, j = hi + 1;
    while(true){
        while(less_abs(adt[++i], adt[lo])) 
            if(i == hi) 
                break;
        while(less_abs(adt[lo], adt[--j])) 
            if(j == lo)
                break;
        if(i >= j)
            break;
        exch(adt, i, j);
    }
    exch(adt, lo, j);
    return j;
}

static void quick_sort_r(struct adt *adt, int lo, int hi)
{
    if(hi <= lo)    return;
    int pos = partition(adt, lo, hi);
    quick_sort_r(adt, lo, pos - 1);
    quick_sort_r(adt, pos + 1, hi);
}

void quick_sort(struct adt *adt)
{
    quick_sort_r(adt, 0, adt->size - 1);
}

static void quick_3way_sort_r(struct adt *adt, int lo, int hi)
{
    if(hi <= lo)    return;
    int lt = lo, gt = hi, i = lo + 1;
    struct adt v = adt[lo];
    while(i <= gt){
        switch (cmp(adt[i], v))
        {
        case 1:     //adt[i] > v
            exch(adt, i, gt--);
            break;
        case 0:     //adt[i] = v
            i++;
            break;
        case -1:    //adt[i] < v
            exch(adt, i++, lt++);
            break;
        }
    }
    quick_sort_r(adt, lo, lt - 1);
    quick_sort_r(adt, gt + 1, hi);
}

void quick_3way_sort(struct adt *adt)
{
    quick_3way_sort_r(adt, 0, adt->size - 1);
}