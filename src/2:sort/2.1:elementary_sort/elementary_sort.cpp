#include "adt.h"

void selection_sort(struct adt *adt)
{
    int length = adt->size;
    for(int i = 0; i < length; i++){
        int min = i;
        for(int j = i + 1; j < length; j++){
            if(less(&adt[j], &adt[min]))
                min = j;
        }
        exch(adt, i, min);
    }
}

void insertion_sort(struct adt *adt)
{
    int length = adt->size;
    for(int i = 1; i < length; i++){
        for(int j = i; j > 0 && less(&adt[j], &adt[j-1]); j--)
            exch(adt, j, j-1);
    }
}

void shell_sort(struct adt *adt)
{
    int length = adt->size;
    int h = 1;
    while(h < (adt->size)/3) h = 3*h + 1;
    while(h >= 1){
        for(int i = h; i < adt->size; i++){
            for(int j = i; j >= h && less(&adt[j], &adt[j-h]); j -= h){
                exch(adt, j, j-h);
            }
        }
        h /= 3;
    }
}