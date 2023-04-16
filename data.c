#include "data.h"

/* compare
 * input: two Data* variables
 * output: int
 *
 * Uses strcmp to compare the key values of the the Data* variables
 */
int compareData( Data* d1, Data* d2 ){
    return strcmp( d1->key, d2->key );
}

/* freeData
 * input: a Data* variable
 * output: int
 *
 * Frees the Data* type variable
 */
void freeData( Data* d ){
    free( d->key );
    free( d );
}
