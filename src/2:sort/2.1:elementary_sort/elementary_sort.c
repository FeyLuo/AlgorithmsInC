#include "template.h"

void selection_sort(Template *T)
{
    int length = T->size;
    for(int i = 0; i < length; i++){
        int min = i;
        for(int j = i + 1; j < length; j++){
            if(less(T[j], T[min]))
                min = j;
        }
        exch(T, i, min);
    }
}

void insertion_sort(Template *T)
{
    int length = T->size;
    for(int i = 1; i < length; i++){
        for(int j = i; j > 0 && less(T[j], T[j-1]); j--)
            exch(T, j, j-1);
    }
}

void shell_sort(Template *T)
{
    int length = T->size;
    int h = 1;
    while(h < (T->size)/3) h = 3*h + 1;
    while(h >= 1){
        for(int i = h; i < T->size; i++){
            for(int j = i; j >= h && less(T[j], T[j-h]); j -= h){
                exch(T, j, j-h);
            }
        }
        h /= 3;
    }
}