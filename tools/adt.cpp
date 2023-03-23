#include "include/adt.h"
#include <stdlib.h>

bool less(struct adt* a, struct adt* b)
{
    switch (a->type)
    {
    case INT:
        return (a->b)<(b->b);
    case CHAR:
        return (a->f)<(b->f);
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
        adt[i].b= adt[i].b ^ adt[j].b;
        adt[j].b= adt[i].b ^ adt[j].b;
        adt[i].b= adt[i].b ^ adt[j].b;
        return;
    }
    case CHAR:
    {
        adt[i].f= adt[i].f ^ adt[j].f;
        adt[j].f= adt[i].f ^ adt[j].f;
        adt[i].f= adt[i].f ^ adt[j].f;
        return;
    }
    default:
        return;
    }
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