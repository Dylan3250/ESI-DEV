#include "mathesi.h"

void printPrimeFactor(unsigned number, bool showPower) {
    unsigned int count = number - 1;
    unsigned int actualFactor = 0;
    unsigned int countFactor = 1;
    unsigned int oldFactor = 0;

    printf("%d = ", number);
    while (number != 1) {
        while (number % count != 0 ) {
            count--;
        }

        actualFactor = number / count;
        number = count;
        count = number - 1;
        if (showPower) {
            if (actualFactor == oldFactor) {
                countFactor += 1;
                if (number == 1) {
                    printf(" ^ %d", countFactor);
                }
            } else {
                if (countFactor > 1) {
                    printf(" ^ %d", countFactor);
                    countFactor = 1;
                }
                printf(!oldFactor ? "%d" : " x %d", actualFactor);
                oldFactor = actualFactor;
            }
        } else {
            printf(number != 1 ? "%d x " : "%d", actualFactor);
        }
    }
    printf("\n");
}
