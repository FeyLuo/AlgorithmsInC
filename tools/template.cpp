#include <stdlib.h>
#include <stdio.h>
#include "template.h"

int cmp(Template a, Template b)
{
    switch (a.type)
    {
    case INT:
        return (a.b)==(b.b) ? 0 : ((a.b)>(b.b) ? 1 : -1);
    case CHAR:
        return (a.f)==(b.f) ? 0 : ((a.f)>(b.f) ? 1 : -1);
    default:
        return false;
    }
}

// less-or-equal function.
bool less(Template a, Template b)
{
    switch (a.type)
    {
    case INT:
        return (a.b)<=(b.b);
    case CHAR:
        return (a.f)<=(b.f);
    default:
        return false;
    }
}

// absolutely less-than function.
bool less_abs(Template a, Template b)
{
    switch (a.type)
    {
    case INT:
        return (a.b)<(b.b);
    case CHAR:
        return (a.f)<(b.f);
    default:
        return false;
    }
}

void exch(Template* Template, int i, int j)
{
    switch (Template->type)
    {
    case INT:
    {
        int tmp;
        tmp      = Template[i].b;
        Template[i].b = Template[j].b;
        Template[j].b = tmp;
        return;
    }
    case CHAR:
    {
        char tmp;
        tmp      = Template[i].f;
        Template[i].f = Template[j].f;
        Template[j].f = tmp;
        return;
    }
    default:
        return;
    }
}

void show(Template* Template)
{
    int i = 0;
    switch (Template->type)
    {
    case INT:{
        for(i; i < Template->size; i++)
            printf("%d ", Template[i].b);
        break;
    }
    case CHAR:
        for(i; i < Template->size; i++)
            printf("%c ", Template[i].f);
        break;
    default:
        break;
    }
    printf("\n");
}

bool is_sorted(Template* Template)
{
    if(Template->size == 1)  
        return true;
    for(int i = 0; i < Template->size - 1; i++)
        if(!less(Template[i], Template[i+1]))
            return false;
    return true;
}


//
// @param a: the array to copy value to b.
// @param b: the array to be copied.
// @param lo,hi: range [lo, hi]
//
bool copy(Template* a, Template *b, int lo, int hi)
{
    int i = lo;
    if(a->type != b->type)
        return false;
    switch (a->type)
    {
    case INT:{
        for(i; i <= hi; i++)
            set_value(&b[i], a[i].b);
        break;
    }
    case CHAR:
        for(i; i <= hi; i++)
            set_value(&b[i], a[i].f);
        break;
    default:
        return false;
    }
    return true;
}

Template* Template_array(int type, int size)
{
    Template* array = (Template*)calloc(size,sizeof(Template));
    for(int i = 0;i < size; i++){
        array[i].type = type;
        array[i].size = size - i;
    }
    return array;
}

Template* Template_array(int type, int size, int* ptr)
{
    Template* array = (Template*)calloc(size,sizeof(Template));
    for(int i = 0;i < size; i++){
        array[i].type = type;
        array[i].size = size - i;
        array[i].b    = ptr[i];
    }
    return array;
}

Template* Template_array(int type, int size, char* ptr)
{
    size--;
    Template* array = (Template*)calloc(size,sizeof(Template));
    for(int i = 0;i < size; i++){
        array[i].type = type;
        array[i].size = size - i;
        array[i].f    = ptr[i];
    }
    return array;
}