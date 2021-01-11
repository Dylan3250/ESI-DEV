#include "imo.h"
#include <stdio.h>

void printTab(const char * title, struct MbonguosseEvent const * elt, unsigned nbElement) {
    printf("%s\n", title);
    for(unsigned i = 0; i < nbElement; i++) {
        printf("Le %d/%d/%d ", elt[i].dateEvent.day, elt[i].dateEvent.month, elt[i].dateEvent.year);
        printf("à %d:%d:%d ", elt[i].momentEvent.hours, elt[i].momentEvent.minutes, elt[i].momentEvent.seconds);
        printf("%s\n", elt[i].nameEvent);
    }
    printf("\n");
}

int major (void const * a, void const * b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ia - ib;
}

int minor (void const * a, void const * b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ib - ia;
}
