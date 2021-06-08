#include "staticArrays.h"

void arrayIntPrint(const int data[], unsigned nbElem) {
    for (unsigned i = 0; i < nbElem; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void arrayIntSort(int data [], unsigned nbElem, bool ascending) {
    for (unsigned i = 1; i < nbElem; i++) {
        int x = data[i];
        int j = (ascending ? i : i - 1);

        while ((ascending && j > 0 && data[j - 1] > x)
                || (!ascending && j >= 0 && x > data[j])) {
            data[j] = (ascending ? data[j - 1] : data[j + 1]);
            j = j - 1;
        }
        if (ascending) {
            data[j] = x;
        } else {
            data[j + 1] = x;
        }
    }
}

int compareAscending (void const * a, void const * b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ia  - ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}

int compareDescending (void const * a, void const * b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ib - ia;
}

int compareAscMod3 (void const * a, void const * b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ia % 3 - ib % 3;
}

int newCompareAsc (int const * a, int const * b) {
    return compareAscending((const void *)a, (const void *)b);
}

int newCompareDesc (int const * a, int const * b) {
    return compareDescending((const void *)a, (const void *)b);
}

void arrayIntSortGeneric(int data [], unsigned nbElem,
                         int (*comp)(const int *, const int *)) {
    for (unsigned i = 0; i < nbElem; i++) {
        unsigned count = i;
        for (unsigned j = i; j < nbElem; j++) {
            if (comp(&data[count], &data[j]) > 0) {
                count = j;
            }
        }
        int save = data[i];
        data[i] = data[count];
        data[count] = save;
    }
}
