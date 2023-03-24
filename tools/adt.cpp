#include "include/adt.h"
#include <stdlib.h>
#include <stdio.h>

bool less(struct adt* a, struct adt* b)
{
    switch (a->type)
    {
    case INT:
        return (a->b)<=(b->b);
    case CHAR:
        return (a->f)<=(b->f);
    default:
        return false;
    }
}

void exch(struct adt* adt, int i, int j)
{
    switch (adt->type)
    {
    case INT:
    {
        int tmp;
        tmp      = adt[i].b;
        adt[i].b = adt[j].b;
        adt[j].b = tmp;
        return;
    }
    case CHAR:
    {
        char tmp;
        tmp      = adt[i].f;
        adt[i].f = adt[j].f;
        adt[j].f = tmp;
        return;
    }
    default:
        return;
    }
}

void show(struct adt* adt)
{
    int i = 0;
    switch (adt->type)
    {
    case INT:{
        for(i; i < adt->size; i++)
            printf("%d ", adt[i].b);
        break;
    }
    case CHAR:
        for(i; i < adt->size; i++)
            printf("%c ", adt[i].f);
        break;
    default:
        break;
    }
    printf("\n");
}

bool is_sorted(struct adt* adt)
{
    if(adt->size == 1)  
        return true;
    for(int i = 0; i < adt->size - 1; i++)
        if(!less(&adt[i], &adt[i+1]))
            return false;
    return true;
}

struct adt* adt_array(int type, int size)
{
    struct adt* array = (struct adt*)calloc(size,sizeof(struct adt));
    for(int i = 0;i < size; i++){
        array[i].type = type;
        array[i].size = size - i;
    }
    return array;
}

struct adt* adt_array(int type, int size, int* ptr)
{
    struct adt* array = (struct adt*)calloc(size,sizeof(struct adt));
    for(int i = 0;i < size; i++){
        array[i].type = type;
        array[i].size = size - i;
        array[i].b    = ptr[i];
    }
    return array;
}

struct adt* adt_array(int type, int size, char* ptr)
{
    size--;
    struct adt* array = (struct adt*)calloc(size,sizeof(struct adt));
    for(int i = 0;i < size; i++){
        array[i].type = type;
        array[i].size = size - i;
        array[i].f    = ptr[i];
    }
    return array;
}