#include <stdlib.h>
#include <stdio.h>
#include "node.h"

/* allocation */
node new_node( const char c, const int freq, node *left, node *right ) {
    /*node *n = malloc( sizeof( *n ) );
    if ( n == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }*/

    node n;
    n.c = c;
    n.freq = freq;
    n.left = left;
    n.right = right;

    return n;
}

/*void free_node( node **n ) {
    free( *n );
    *n = NULL;
}*/

/* util */
void print_node( node n ) {
    printf( "node[c = %c, freq = %d, left = %p, right = %p]\n",
            n.c, n.freq, ( void * )n.left, ( void * )n.right );
}
