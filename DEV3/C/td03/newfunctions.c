#include "newfunctions.h"

size_t newStrlen(const char * str) {
    size_t count = 0;
    /*
     * Exemple 1
     while (str[count] != '\0') {
        count++;
    }
    */

    /*
     * Exemple 2
    for (count; str[count] != '\0'; count++);
    */

    /*
     * Exemple 3
    while (*str != '\0') {
        ++count;
        ++str; // on incrémente qu'une valeur, pas le char qui est const
    }
    */

    /*
     * Exemple 4
    const char * tmp = str;
    while (*tmp != '\0') {
        tmp++;
    }
    return tmp - str;
    */

    for (; *str != '\0'; str++, count++);
    return count;
}

int newStrcmp( const char * lhs, const char * rhs ) {
    /*
     * Exemple 1
    while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0') {
        rhs++;
        lhs++;
    }
    */
    for (; *lhs == *rhs && *lhs != '\0' && *rhs != '\0'; rhs++, lhs++);
    return *lhs - *rhs;
}

char * newStrcpy( char * dest, const char * src ) {
    for (; *src != '\0'; src++, dest++) {
        *dest = *src;
    }
    *dest = '\0';
    return dest;
}

char * newStrncpy( char * dest, const char * src, size_t count ) {
    for (size_t i = 0; i < count; ++i, ++src, ++dest) {
        *dest = *src;
    }
    *dest = '\0';
    return dest;
}

char * newStrcat( char * dest, const char * src ) {
    size_t count = 0;
    for (; dest[count] != '\0'; count++);
    for (size_t i = 0; src[i] != '\0'; count++, i++) {
        dest[count] = src[i];
    }
    dest[count] = '\0';

    return dest;
}

char * newStrncat( char * dest, const char * src, size_t count ) {
    size_t index = 0;
    for (; dest[index] != '\0'; index++);
    for (size_t i = 0; i < count && src[i] != '\0'; index++, i++) {
        dest[index] = src[i];
    }
    dest[index] = '\0';
    return dest;
}

char * newStrtok( char * str, const char * delim ) {
    static char * toSplit;
    static size_t count = -1;

    if (str != NULL) {
        toSplit = str;
    }
    count += 1;
    size_t saveCount = count;
    for (; toSplit[count] != *delim && toSplit[count] != '\0'; count++);
    toSplit[count] = '\0';

    return saveCount == count ? NULL : &toSplit[saveCount];
}
