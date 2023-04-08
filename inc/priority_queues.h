inline bool cmp_maxPQ(Template a, Template b)
{
    return less_abs(a, b);
}

inline bool cmp_minPQ(Template a, Template b)
{
    return less_abs(b, a);
}

void swim(Template* T, int k, bool cmp(Template , Template ));

void sink(Template* T, int k, bool cmp(Template , Template ));

void sink(Template* T, int k, int length, bool cmp(Template , Template ));

bool is_heaped(Template* T);