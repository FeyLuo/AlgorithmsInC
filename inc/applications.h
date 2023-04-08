#pragma once

typedef struct{
    Template* minPQ;
    Template* maxPQ;
    int min_len;
    int max_len;
}Meadian_Finder;

int Kendall_tau(int *a, int *b, int size);

int inversions(int* array, int size);

double meadian(Template* T);