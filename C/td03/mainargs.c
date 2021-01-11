#include "newfunctions.h"

int main2(int argc, char * argv[]) {
    const char * errorMsg =
        "Erreur ! Merci de lancer le programme : ./a.out <unsigned > 0> [-v]\n";

    if (argc > 3 || argc <= 1
            || (argc == 3 && newStrcmp(argv[1], argv[2]) == 0)) {
        printf("%s", errorMsg);
        return 1;
    }

    bool isV = false;
    char * endPtr;
    long value = 0;

    if (argc == 2) {
        value = strtol(argv[1], &endPtr, 10);
    } else if (argc == 3) {
        if (newStrcmp(argv[1], "-v") == 0 ) {
            isV = true;
            value = strtol(argv[2], &endPtr, 10);
        } else if (newStrcmp(argv[2], "-v") == 0) {
            isV = true;
            value = strtol(argv[1], &endPtr, 10);
        }
    }

    if (value != 0 ) {
        printPrimeFactor(value, isV ? false : true);
    } else {
        printf("%s", errorMsg);
        return 2;
    }
    return 0;
}
