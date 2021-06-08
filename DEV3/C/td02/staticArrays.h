#ifndef STATICARRAYS_H
#define STATICARRAYS_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void arrayIntPrint(const int data [], unsigned nbElem);
void arrayIntSort(int data [], unsigned nbElem, bool ascending);
void arrayIntSortGeneric(int data [], unsigned nbElem,
                         int (*comp)(const int *, const int *));

int compareAscending (void const * a, void const * b);
int compareDescending (void const * a, void const * b);
int compareAscMod3 (void const * a, void const * b);

int newCompareAsc (int const * a, int const * b);
int newCompareDesc (int const * a, int const * b);

#endif
