#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "node.h"

node *new_node( const char c, const int freq, node *left, node *right ) {
    node *n = malloc( sizeof( *n ) );
    if ( n == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }

    n->c = c;
    n->freq = freq;
    n->left = left;
    n->right = right;

    return n;
}

void free_node( node **n ) {
    if ( *n == NULL ) {
        return;
    }

    free( *n );
    *n = NULL;
}

bool is_leaf( const node *n ) {
    if ( n == NULL ) {
        return false;
    }

    return ( n->left == NULL && n->right == NULL );
}

void print_node( const node *n ) {
    if ( n == NULL ) {
        fprintf( stderr, "illegal access\n" );
        return;
    }

    printf( "node[c = %c, freq = %d, left = %p, right = %p]\n",
            n->c, n->freq, ( void * )n->left, ( void * )n->right );
}
