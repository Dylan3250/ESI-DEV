#include "staticArrays.h"

int main() {
    int array[] = {5, 9, 2, 4, 7, 2, 7, 3, 4, 1, -1, 23, 12, 43, 2, -4, 5 };
    printf("Affiche les 3 premiers éléments du tableau : ");
    arrayIntPrint(array, 3);

    printf("Tri du tableau avec arrayIntSort : ");
    int sizeArray = sizeof(array) / sizeof(*array);
    arrayIntSort(array, sizeArray, true);
    arrayIntPrint(array, sizeArray);

    printf("Tri du tableau avec qsort (comparingDescending) : ");
    qsort(array, sizeArray, sizeof(int), compareDescending);
    arrayIntPrint(array, sizeArray);

    printf("Tri du tableau avec qsort (compareAscending) : ");
    qsort(array, sizeArray, sizeof(int), compareAscending);
    arrayIntPrint(array, sizeArray);

    printf("Tri du tableau avec qsort (compareAscMod3) : ");
    qsort(array, sizeArray, sizeof(int), compareAscMod3);
    arrayIntPrint(array, sizeArray);

    printf("Tri du tableau avec arrayIntSortGeneric (newCompareAsc) : ");
    arrayIntSortGeneric(array, sizeArray, newCompareAsc);
    arrayIntPrint(array, sizeArray);

    printf("Tri du tableau avec arrayIntSortGeneric (newCompareDesc) : ");
    arrayIntSortGeneric(array, sizeArray, newCompareDesc);
    arrayIntPrint(array, sizeArray);

    return 0;
}
