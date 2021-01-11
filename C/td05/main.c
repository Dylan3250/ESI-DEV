#include "slcircularlist_utility.h"
#include "slcircularlist.h"
#include "slnode_utility.h"
#include "slnode.h"
#include <errno.h>
#include "value_t.h"
#include <stdio.h>

int main() {
    // EXERCICE 1
    struct SLNode * sln = newSLN(2);
    if (sln == NULL) {
        fprintf(stderr, errno == ESLLMEMORYFAIL ?
                "Error with allocate memory for SLNode.\n" :  "Unknown error.\n");
        return 1;
    }
    printf("Sln : %f\n", sln->value);
    struct SLNode * next = newSLN(10);
    setNextSLN(sln, next);
    sln = nextSLN(sln);
    if (sln == NULL) {
        fprintf(stderr, errno == ESLLMEMORYFAIL ?
                "Error with allocate memory for SLNode.\n" :  "Unknown error.\n");
        return 1;
    }
    printf("Sln : %f\n", sln->value);
    deleteSLN(&sln);

    // EXERCICE 2 (without error checking)
    struct SLNode * slnEx2 = newSLN(2);
    struct SLNode * slnNextEx2 = newSLN(4);
    setNextSLN(slnEx2, slnNextEx2);
    struct SLNode * slnNext2Ex2 = newSLN(6);
    setNextSLN(slnNextEx2, slnNext2Ex2);
    struct SLNode * slnNext3Ex2 = newSLN(8);
    setNextSLN(slnNext2Ex2, slnNext3Ex2);
    struct SLNode * forwardedSLN = forwardSLN(slnEx2, 3);
    printf("ForwardedSLN : %f\n", forwardedSLN->value);

    // EXERCICE 3
    struct SLCircularList * circularList = newSLCL();
    pushSLCL(circularList, 2);
    printf("Circularlist 1 : %f\n", entrySLCL(circularList)->value);
    insertSLCL(circularList, entrySLCL(circularList), 5);
    printf("Circularlist 2 : %f\n",
           entrySLCL(circularList)->next->value);
    printf("Circularlist 3 : %f\n",
           entrySLCL(circularList)->next->next->value);
    printf("Circularlist 3 : %f\n\n",
           entrySLCL(circularList)->next->next->next->value);

    popSLCL(circularList);
    printf("Circularlist pop 1 : %f\n", entrySLCL(circularList)->value);
    printf("Circularlist pop 1 value 2 : %f\n",
           entrySLCL(circularList)->next->value);
    printf("Circularlist empty ? %s \n",
           emptySLCL(circularList) ? "true" : "false" );
    popSLCL(circularList);
    printf("Circularlist empty ? %s \n",
           emptySLCL(circularList) ? "true" : "false" );

    pushSLCL(circularList, 10);
    struct SLNode * returnedNode1 = insertSLCL(circularList,
                                    entrySLCL(circularList), 15);
    struct SLNode * returnedNode2 = insertSLCL(circularList,
                                    entrySLCL(circularList), 20);
    struct SLNode * returnedNode3 = insertSLCL(circularList,
                                    entrySLCL(circularList), 25);

    printf("Circularlist insert after pop 1 : %f\n",
           entrySLCL(circularList)->value);
    printf("Circularlist insert after pop 2 : %f\n",
           entrySLCL(circularList)->next->value);
    printf("Circularlist insert after pop 3 : %f\n",
           entrySLCL(circularList)->next->next->value);
    printf("Circularlist insert after pop 4 : %f\n",
           entrySLCL(circularList)->next->next->next->value);

    printf("\nPrevious of 20 is %f\n", previousSLCL(circularList,
            returnedNode2)->value);

    printf("\nSize of list : %lld", sizeSLCL(circularList));
    eraseSLCL(circularList, returnedNode1);
    eraseSLCL(circularList, returnedNode2);
    eraseSLCL(circularList, returnedNode3);
    printf("\nSize of list : %lld\n", sizeSLCL(circularList));
    printf("\nPrevious of 10 (first node) is %f\n",
           previousSLCL(circularList, entrySLCL(circularList))->value);

    printf("\nCircularlist erase 1,2,3 : %f\n",
           entrySLCL(circularList)->value);
    printf("Circularlist erase 1,2,3 next : %f\n",
           entrySLCL(circularList)->next->value);

    deleteSLCL(&circularList);
    printf("\nSize of list : %lld\n", sizeSLCL(circularList));

    return 0;
}
