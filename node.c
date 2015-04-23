#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "node.h"

node *new_node( const char c, const int freq, node *left, node *right ) {
    node *n = new_mem( sizeof( *n ) );

    n->c = c;
    n->freq = freq;
    n->left = left;
    n->right = right;

    return n;
}

void free_node( node *n ) {
    free_mem( n );
}

int compare_node( const void *a, const void *b ) {
    const node *ia = *( const node ** ) a;
    const node *ib = *( const node ** ) b;
    return ia->freq - ib->freq;
}

bool is_leaf( const node *n ) {
    invalid_mem_exit( n, EX_ACCESS );
    return ( n->left == NULL && n->right == NULL );
}

void print_node( const node *n ) {
    invalid_mem_exit( n, EX_ACCESS );
    printf( "node(%p) [c = %c, freq = %d, left = %p, right = %p]\n",
            ( void * )n, n->c, n->freq, ( void * )n->left, ( void * )n->right );
}
