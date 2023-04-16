#ifndef _tree_h
#define _tree_h
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"

typedef struct Data Data;

typedef enum treeType{ HUFFMAN, AVL, SEGMENT } treeType;

typedef struct TNode
{
    /* Data for every TNode */
    struct TNode* pLeft;    /* left child (NULL for leaf) */
    struct TNode* pRight;   /* right child (NULL for leaf) */
    struct TNode* pParent;  /* parent TNode (NULL for root) */

    /* AVL data */
    int height;             /* max number of nodes on path from this node down to a leaf of the tree */
    Data* data;             /* pointer to the data stored in the node, leaves contain no valid data */

    /* Huffman data */
    int priority;           /* total number of occurrences of the chars in str */
    char *str;              /* the chars in str are ones whose Huffman encoding is given by the subtree rooted at this TNode */

    /* Segment tree data */
    double low, high;       /* the line segment specified by this TNode is from low to high */
    int cnt;                /* the number of inserted line segments that FULLY cover the range (low,high) but not the range of an ancestor of this TNode */
}  TNode;

typedef struct Tree
{
    TNode* root;            /* the root of this tree (it will be a NULL if the tree is empty) */
    treeType type;          /* the type of data that the TNodes stored in this tree will have (e.g. HUFFMAN, AVL, SEGMENT) */
}  Tree;

void printName( );

/**********  Functions for creating/freeing a tree **********/
Tree *createTree( );
Tree *createTreeFromTNode( TNode* root );
void freeTree( Tree* t );
void freeTreeContents( TNode *root, treeType type );

/**********  Functions for creating/linking TNodes tree **********/
TNode* createTNode( );
void attachChildNodes( TNode* root, TNode* left, TNode* right );

/**********  Functions for searching an AVL tree **********/
TNode* searchTree( Tree *t, Data* tData );
TNode* searchTreeRec( TNode *root, Data* tData );

/**********  Functions for inserting/removing from an AVL tree **********/
TNode* insertNode( TNode *root, TNode* newNode );
void insertTree( Tree* t, Data* tData );
void insertTreeBalanced( Tree* t, Data* tData );
Data* removeTree( Tree* t, char* key );

/**********  Functions for getting Huffman Encoding **********/
void printHuffmanEncoding( TNode* root, char c );

/**********  Functions for Segment Tree **********/
TNode* constructSegmentTree( double* points, int low, int high);
void insertSegment( TNode* root, double segmentStart, double segmentEnd );
int lineStabQuery( TNode* root, double queryPoint );

/**********  Functions for debugging an AVL tree **********/
void printTree( TNode* root );
void checkAVLTree( TNode* root );
int getBalance(TNode* x);

/**********  Functions for printing an tree **********/
void printTreeByType( Tree* t, TNode* root, int depth );

#endif
