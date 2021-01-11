#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

enum
{
    h_min = 0, h_max = 24,
    mi_min = 0, mi_max = 60,
    s_min = 0, s_max = 60,
    nbElem_min = 33, nbElem_max = 70,
    y_min = 2001, y_max = 2020,
    mo_min = 1, mo_max = 12,
    j_min = 1, j_max = 29,
    delim_max = 6, delim_min = 2,
};

const char * const event[] = {"Emol", "Pekassal", "Embake", "Nifounou", "Pehosse", "Nehasse", "Emalamande"};

// tirer un pseudo-réel au hasard entre le_min et le_max; le_max exclus
static double aleat_double(double le_min, double le_max)
{
    if (le_max < le_min)
    {
        double temp = le_min;
        le_min = le_max;
        le_max = temp;
    }
    return le_min + (le_max - le_min) * rand() / (1. + RAND_MAX);
}

// tirer un entier au hasard entre le_min et le_max; le_max exclus
static int aleat_int(int le_min, int le_max)
{
    if (le_max < le_min)
    {
        int temp = le_min;
        le_min = le_max;
        le_max = temp;
    }
    return le_min + rand() % (le_max - le_min);
}

// gestion des délimiteurs
static const char * delimiteurs(size_t * delim_taille)
{
    aleat_double(1, 4); // ne sert à rien - juste un bluff
    static char delim[delim_max] = {[delim_max - 1] = '\0'};
    *delim_taille = (size_t) aleat_int(delim_min, delim_max);
    delim[*delim_taille] = '\0';
    for (size_t i = 0; i < *delim_taille; ++i)
    {
        delim[i] = (char) aleat_int('a', 'z' + 1);
    }
    return delim;
}


// Génération des données via la fonction data()
const char * * data(void)
{
    static bool first_time = true;
    static char * * result = NULL;
    if (first_time)
    {
        first_time = false;
        srand((unsigned) time(NULL));
        int chaine_cpt = aleat_int(nbElem_min, nbElem_max);
        result = malloc((size_t) chaine_cpt * sizeof (const char *));
        result[chaine_cpt - 1] = NULL;
        for (int i = 0; i < chaine_cpt - 1; ++i)
        {
            size_t taille_ch = 1;
            char * str = malloc(taille_ch);
            str[taille_ch - 1] = '\0';
            size_t cpt_delim;
            const char * delim = NULL;

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value1[20];
            int value = aleat_int(y_min, y_max);
            sprintf(str_value1, "%d", value);
            taille_ch += strlen(str_value1);
            str = realloc(str, taille_ch);
            strcat(str, str_value1);

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value2[20];
            value = aleat_int(mo_min, mo_max);
            sprintf(str_value2, "%d", value);
            taille_ch += strlen(str_value2);
            str = realloc(str, taille_ch);
            strcat(str, str_value2);

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value3[20];
            value = aleat_int(j_min, j_max);
            sprintf(str_value3, "%d", value);
            taille_ch += strlen(str_value3);
            str = realloc(str, taille_ch);
            strcat(str, str_value3);

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value4[20];
            value = aleat_int(h_min, h_max);
            sprintf(str_value4, "%d", value);
            taille_ch += strlen(str_value4);
            str = realloc(str, taille_ch);
            strcat(str, str_value4);

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value5[20];
            value = aleat_int(mi_min, mi_max);
            sprintf(str_value5, "%d", value);
            taille_ch += strlen(str_value5);
            str = realloc(str, taille_ch);
            strcat(str, str_value5);

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value6[20];
            value = aleat_int(s_min, s_max);
            sprintf(str_value6, "%d", value);
            taille_ch += strlen(str_value6);
            str = realloc(str, taille_ch);
            strcat(str, str_value6);

            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            char str_value7[20];
            value = aleat_int(0, 6);// position sur le tableau event[]
            sprintf(str_value7, "%d", value);
            taille_ch += strlen(str_value7);
            str = realloc(str, taille_ch);
            strcat(str, str_value7);
            // ajout nom évent
            delim = delimiteurs(&cpt_delim);
            taille_ch += cpt_delim;
            str = realloc(str, taille_ch);
            strcat(str, delim);

            result[i] = str;
        }
    }
    else
    {
        if (result != NULL)
        {
            size_t index = 0;
            while (result[index] != NULL)
            {
                free(result[index++]);
            }
            free(result);
            result = NULL;
        }
    }

    return (const char * *) result;;
}
