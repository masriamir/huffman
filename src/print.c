#include <stdio.h>

#include "mem_util.h"
#include "print.h"

void print_node( const node *n ) {
    invalid_mem_exit( n, EX_ACCESS );
    printf( "node(%p) [c = %c, freq = %d, bits = %s, left = %p, right = %p]\n",
            ( void * )n, n->c, n->freq, n->bits,
                ( void * )n->left, ( void * )n->right );
}

void print_queue( const queue q ) {
    printf( "queue[size = %zu, capacity = %zu]\n", q.size, q.cap );
    for ( size_t i = 0; i < q.size; i++ ) {
        print_node( q.arr[i] );
    }
}

void print_tree( const node *n ) {
    invalid_mem_exit( n, EX_ACCESS );

    if ( is_leaf( n ) ) {
        print_node( n );
    } else {
        print_node( n );
        print_tree( n->left );
        print_tree( n->right );
    }
}
