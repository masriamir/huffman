#include <stdio.h>

#include "print.h"

void print_code( const code cd ) {
    printf( "code[c = %c, bin = %s]\n", cd.c, cd.bin );
}

void print_dictionary( const dictionary d ) {
    printf( "dictionary[size = %zu, capacity = %zu]\n", d.size, d.cap );
    for ( size_t i = 0; i < d.size; i++ ) {
        print_code( d.arr[i] );
    }
}

void print_node( const node *n ) {
    invalid_mem_exit( n, EX_ACCESS );
    printf( "node(%p) [c = %c, freq = %d, left = %p, right = %p]\n",
            ( void * )n, n->c, n->freq, ( void * )n->left, ( void * )n->right );
}

void print_map( const map m ) {
    printf( "map[size = %zu, capacity = %zu]\n", m.size, m.cap );
    for ( size_t i = 0; i < m.size; i++ ) {
        print_pair( m.arr[i] );
    }
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
