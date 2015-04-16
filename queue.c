#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "queue.h"

queue *new_queue( void ) {
    queue *q = malloc( sizeof( *q ) );
    if ( q == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }

    q->arr = malloc( DEF_SZ * sizeof( *q->arr ) );
    if ( q->arr == NULL ) {
        fprintf( stderr, "mem error\n" );
        free( q );
        exit( 1 );
    }

    q->size = 0;
    q->cap = DEF_SZ;
    return q;
}

void free_queue( queue **q ) {
    if ( *q == NULL ) {
        return;
    }

    free( ( *q )->arr );
    ( *q )->arr = NULL;

    free( *q );
    *q = NULL;
}

size_t resize_queue( queue **q ) {
    size_t new_cap = ( *q )->cap * 2;
    ( *q )->arr = realloc( ( *q )->arr, new_cap * sizeof( *( *q )->arr ) );
    if ( ( *q )->arr == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }
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
    if ( q == NULL ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    printf( "queue[size = %zu, capacity = %zu]\n", q->size, q->cap );
    for ( size_t i = 0; i < q->size; i++ ) {
        print_node( q->arr[i] );
    }
}
