#ifndef NEWFUNCTIONS_H
#define NEWFUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
// for mainargs
#include <stdbool.h>
#include "mathesi.h"

size_t newStrlen(const char * str);
int newStrcmp( const char * lhs, const char * rhs );
char * newStrcpy( char * dest, const char * src );
char * newStrncpy( char * dest, const char * src, size_t count );
char * newStrcat( char * dest, const char * src );
char * newStrncat( char * dest, const char * src, size_t count );
char * newStrtok( char * str, const char * delim );

#endif
