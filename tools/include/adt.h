#ifndef _ADT_H
#define _ADT_H

#define INT  1
#define CHAR 2

#define GET_VALUE(adt) ({       \
    if(adt.type==INT)           \
        GET_INT_VALUE(adt);     \
})
#define GET_INT_VALUE(adt) (*((int *)&adt))
#define GET_CHAR_VALUE(adt) (*((char *)&adt))



struct adt{
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
};

inline int len(struct adt* adt)
{
    return adt->size;
}


inline int set_value(struct adt *adt, int a)
{
    return (adt->b = a);
}


inline char set_value(struct adt *adt, char a)
{
    return (adt->f = a);
}

bool less(struct adt* a, struct adt* b);

void exch(struct adt* adt, int i, int j);

struct adt* adt_array(int type, int size);

#endif