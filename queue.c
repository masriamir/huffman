#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "queue.h"

queue *new_queue( void ) {
    queue *q = new_mem( sizeof( *q ) );
    q->arr = new_mem( DEF_SZ * sizeof( *q->arr ) );
    q->size = 0;
    q->cap = DEF_SZ;
    return q;
}

void free_queue( queue **q ) {
    if ( *q == NULL ) {
        return;
    }

    for ( size_t i = 0; i < ( *q )->size; i++ ) {
        free( ( *q )->arr[i] );
        ( *q )->arr[i] = NULL;
    }

    free( ( *q )->arr );
    ( *q )->arr = NULL;

    free( *q );
    *q = NULL;
}

size_t resize_queue( queue **q ) {
    size_t new_cap = ( *q )->cap * 2;
    ( *q )->arr = realloc( ( *q )->arr, new_cap * sizeof( *( *q )->arr ) );
    check_mem_exit( ( *q )->arr, EX_MEM );
    return new_cap;
}

bool offer( queue *q, node *el ) {
    if ( q == NULL || el == NULL ) {
        return false;
    }

    if ( q->size + 1 == q->cap ) {
        q->cap = resize_queue( &q );
    }

    q->arr[ q->size++ ] = el;
    return true;
}

node *poll( queue *q ) {
    if ( q == NULL || q->size == 0 ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    node *el = q->arr[0];
    for ( size_t i = 0; i < q->size; i++ ) {
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

void print_queue( const queue *q ) {
    check_mem_exit( q, EX_ACCESS );
    printf( "queue[size = %zu, capacity = %zu]\n", q->size, q->cap );
    for ( size_t i = 0; i < q->size; i++ ) {
        print_node( q->arr[i] );
    }
}
