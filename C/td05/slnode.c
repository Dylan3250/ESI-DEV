#include "slnode.h"
#include <stdlib.h>
#include <errno.h>

struct SLNode * newSLN(value_t value) {
    struct SLNode * nsln = malloc(sizeof(struct SLNode));
    if (nsln == NULL) {
        errno = ESLNMEMORYFAIL;
        return NULL;
    }
    nsln->value = value;
    nsln->next = NULL;
    return nsln;
}

void deleteSLN(struct SLNode * * adpSLN) {
    free(*adpSLN);
    *adpSLN = NULL;
}

struct SLNode * nextSLN(const struct SLNode * pSLN) {
    return pSLN->next;
}

void setNextSLN(struct SLNode * pSLN, struct SLNode * pNewNext) {
    pSLN->next = pNewNext;
}

value_t valueSLN(const struct SLNode * pSLN) {
    return pSLN->value;
}

void setValueSLN(struct SLNode * pSLN, value_t newValue) {
    pSLN->value = newValue;
}
