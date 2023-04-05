#include "template.h"
#include "sort.h"
#include "ADT.h"

int Kendall_tau(Template* a, Template* b)
{
    int size = len(a);
    Template* Ai = Template_array(a->type, size);
    Template* Ci = Template_array(a->type, size);
    for(int i = 0; i < size; i++)
        set_value(&Ai[a[i]], i);
    for(int i = 0; i < size; i++)
        set_value(&Ci[i], &Ai[b[i]]);
    show(Ai);
    show(Ci);
    return 0;
}

int inversions(template* T)
{
    Template* Ai = Template_array(a->type, len(T));
    for(int i = 0; i < len(T); i++)
        set_value(&Ai[T[i]], i);
    return 0;
}