#ifndef _priorityQueue_h
#define _priorityQueue_h
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

typedef TNode* pqType; /* priority queue stores nodes from our Huffman tree */

typedef struct PriorityQueue
{
    pqType *data;          /* pqType data stored in the stack */
    int last;              /* index of the last element in the array */
    int capacity;          /* current capacity of stack */
} PriorityQueue;

PriorityQueue *createPQ( );
void freePQ( PriorityQueue *ppq );

pqType removePQ( PriorityQueue *ppq );
void insertPQ( PriorityQueue *ppq, pqType pt );
pqType getNextPQ( PriorityQueue *ppq );

bool isEmptyPQ( PriorityQueue *ppq );
bool isFullPQ( PriorityQueue *ppq );

#endif
