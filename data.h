#ifndef _data_h
#define _data_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Data
{
    int verification;           /* verification of the key */
    char *key;          /* string representing the key value of the node */
}  Data;

void freeData( Data* d );
int compareData( Data* d1, Data* d2 );

#endif
