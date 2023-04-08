#pragma once

#define INT  1
#define CHAR 2

#define GET_VALUE(T) ({       \
    if(T.type==INT)           \
        GET_INT_VALUE(T);     \
})
#define GET_INT_VALUE(T) (*((int *)&T))
#define GET_CHAR_VALUE(T) (*((char *)&T))

typedef struct{
    union{
        short   a;
        int     b;
        long    c;
        float   d;
        double  e;
        char    f;
    };
    int     type;
    int     size;
}Template;

inline int len(Template* T)
{
    return T->size;
}


inline int set_value(Template *T, int a)
{
    return (T->b = a);
}


inline char set_value(Template *T, char a)
{
    return (T->f = a);
}

inline void set_value(Template *a, Template *b)
{
    if(a->type == INT) a->b = b->b;
    else if(a->type == CHAR) a->f = b->f;
}

int cmp(Template a, Template b);

bool less(Template a, Template b);

bool less_abs(Template a, Template b);

void exch(Template* T, int i, int j);

void show(Template* T);

bool is_sorted(Template* T);

bool copy(Template* a, Template *b, int lo, int hi);

Template* Template_array(int type, int size);

Template* Template_array(int type, int size, int* ptr);

Template* Template_array(int type, int size, char* ptr);
