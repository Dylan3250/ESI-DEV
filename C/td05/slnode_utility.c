#include "slnode_utility.h"

struct SLNode * forwardSLN(struct SLNode * pSLN, size_t distance) {
    for (size_t i = 0; i < distance; i++) {
        pSLN = pSLN->next;
    }
    return pSLN;
}
