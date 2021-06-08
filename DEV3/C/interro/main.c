#include <stdio.h>
#include "imo.h"
#include "forstudent/util.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char * * datas = data();
    struct MbonguosseEvent * tab = malloc(strlen(*datas) * sizeof (
            struct MbonguosseEvent));
    unsigned totalElmt = 0;

    for (unsigned i = 0; i < strlen(*datas); i++) {
        int values[6];
        int index = 0;

        for (unsigned j = 0; j < strlen(datas[i]); j++) {
            if (atoi(&datas[i][j]) != 0) {
                values[index] = atoi(&datas[i][j]);
                index++;

                char number_str[10];
                sprintf(number_str, "%d", atoi(&datas[i][j]));
                j += strlen(number_str);
            }
        }

        struct Date * date = malloc(sizeof (struct Date));
        struct Moment * moment = malloc(sizeof (struct Moment));

        date->year = values[0];
        date->month = values[1];
        date->day = values[2];
        moment->hours = values[3];
        moment->minutes = values[4];
        moment->seconds = values[5];

        tab[i].dateEvent = *date;
        tab[i].momentEvent = *moment;

        free(date);
        free(moment);
        totalElmt++;
    }

    data();
    printTab("Tableau des événement mystiques – avant le tri", tab,
             totalElmt);
    qsort(tab, totalElmt, sizeof (struct MbonguosseEvent), major);
    qsort(tab, totalElmt, sizeof (struct MbonguosseEvent), minor);
    printTab("Tableau des évènements mystiques – après le tri", tab,
             totalElmt);
    free(tab);
    return 0;
}

