#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "queue.h"

queue new_queue( const size_t size ) {
    queue q;
    q.arr = new_mem( size * sizeof( *q.arr ) );
    q.size = 0;
    q.cap = size;
    return q;
}

void free_queue( queue *q ) {
    if ( q == NULL ) {
        return;
    }

    for ( size_t i = 0; i < q->size; i++ ) {
        free_mem( q->arr[i] );
    }

    free_mem( q->arr );
}

bool offer( queue *q, node *el ) {
    if ( q == NULL || el == NULL ) {
        return false;
    }

    q->arr[ q->size++ ] = el;
    sort_queue( q );
    return true;
}

node *poll( queue *q ) {
    if ( q == NULL || q->size == 0 ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    node *el = q->arr[0];
    for ( size_t i = 0; i < q->size - 1; i++ ) {
        q->arr[i] = q->arr[i + 1];
    }

    q->size--;
    return el;
}

node *peek( const queue *q ) {
    if ( q == NULL || q->size == 0 ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    return q->arr[0];
}

void sort_queue( queue *q ) {
    check_mem_err( q, EX_ACCESS );
    qsort ( q->arr, q->size, sizeof( *q->arr ), compare_node );
}

void print_queue( const queue q ) {
    printf( "queue[size = %zu, capacity = %zu]\n", q.size, q.cap );
    for ( size_t i = 0; i < q.size; i++ ) {
        print_node( q.arr[i] );
    }
}
