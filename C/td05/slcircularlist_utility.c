#include "slcircularlist_utility.h"
#include <stdio.h>

size_t sizeSLCL(const struct SLCircularList * pSLCL) {
    if (emptySLCL(pSLCL)) {
        return 0;
    }
    struct SLNode * firstNode = pSLCL->entry->next;
    size_t i = 1;
    for (; firstNode != pSLCL->entry; ++i) {
        firstNode = firstNode->next;
    }
    return i;
}

struct SLNode * previousSLCL( const struct SLCircularList * pSLCL,
                              const struct SLNode * pSLN) {
    if (emptySLCL(pSLCL)) {
        return NULL;
    }
    struct SLNode * before = pSLCL->entry;

    while (pSLN != before->next) {
        before = before->next;
    }

    return before;
}
