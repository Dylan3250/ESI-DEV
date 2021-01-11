#include "slcircularlist.h"
#include <stdlib.h>
#include <errno.h>

struct SLCircularList * newSLCL(void) {
    struct SLCircularList * SLCircular = malloc(sizeof(
            struct SLCircularList));
    if (SLCircular == NULL) {
        errno = ESLNMEMORYFAIL;
        return NULL;
    }
    SLCircular->entry = NULL;
    return SLCircular;
}

void deleteSLCL(struct SLCircularList * * adpSLCL) {
    clearSLCL(*adpSLCL);
}

void clearSLCL(struct SLCircularList * pSLCL) {
    struct SLNode * currentNode = pSLCL->entry->next;

    while (currentNode != pSLCL->entry) {
        struct SLNode * saveNode = currentNode->next;
        deleteSLN(&currentNode);
        currentNode = saveNode;
    }
    deleteSLN( &pSLCL->entry);
}

struct SLNode * entrySLCL(const struct SLCircularList * pSLCL) {
    return emptySLCL(pSLCL) ? NULL : pSLCL->entry;
}

bool emptySLCL(const struct SLCircularList * pSLCL) {
    return pSLCL->entry == NULL ? true : false;
}

struct SLNode * pushSLCL(struct SLCircularList * pSLCL,
                         value_t value) {
    if (entrySLCL(pSLCL) != NULL) {
        return pSLCL->entry;
    }
    struct SLNode * entry = malloc(sizeof(struct SLNode));
    if (entry == NULL) {
        errno = ESLLMEMORYFAIL;
        return NULL;
    }
    entry->value = value;
    entry->next = entry;
    pSLCL->entry = entry;
    return entry;
}

struct SLNode * insertSLCL(struct SLCircularList * pSLCL,
                           struct SLNode * pSLN, value_t value) {
    if (pSLCL == NULL || (pSLN == NULL && !emptySLCL(pSLCL))) {
        return pSLN;
    }
    if (pSLN == NULL) {
        return pushSLCL(pSLCL, value);
    }
    struct SLNode * newSLN = malloc(sizeof(struct SLNode));
    if (newSLN == NULL) {
        errno = ESLLMEMORYFAIL;
        return NULL;
    }
    newSLN->next = pSLN->next;
    newSLN->value = value;
    pSLN->next = newSLN;

    return newSLN;
}

struct SLNode * popSLCL(struct SLCircularList * pSLCL) {
    if (emptySLCL(pSLCL)) {
        errno = ESLLEMPTY;
        return NULL;
    }
    struct SLNode * saveOldEntry = pSLCL->entry;
    pSLCL->entry = saveOldEntry->next;
    if (saveOldEntry->next == saveOldEntry) {
        pSLCL->entry = NULL;
    } else if (pSLCL->entry->next == saveOldEntry) {
        pSLCL->entry->next = pSLCL->entry;
    }

    deleteSLN(&saveOldEntry);
    return pSLCL->entry;
}

struct SLNode * eraseSLCL(struct SLCircularList * pSLCL,
                          struct SLNode * pSLN) {
    if (pSLCL->entry == pSLN) {
        return popSLCL(pSLCL);
    }
    struct SLNode * beforeDeleted = pSLN;

    while (pSLN != beforeDeleted->next) {
        beforeDeleted = beforeDeleted->next;
    }
    beforeDeleted->next = pSLN->next;
    return pSLN;
}
