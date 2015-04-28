#include <stdlib.h>
#include <stdbool.h>

#include "huffman.h"
#include "queue.h"

queue new_queue( const size_t size ) {
    queue q;

    q.arr = new_mem( size * sizeof( *q.arr ) );
    q.size = 0;
    q.cap = size;

    return q;
}

void free_queue( queue *q ) {
    for ( size_t i = 0; i < q->size; i++ ) {
        free_mem( q->arr[i] );
    }

    free_mem( q->arr );
}

bool offer( queue *q, node *el ) {
    if ( invalid_mem( q ) || invalid_mem( el ) ) {
        return false;
    }

    q->arr[ q->size++ ] = el;
    sort_queue( q );
    return true;
}

node *poll( queue *q ) {
    invalid_mem_exit( q, EX_ACCESS );
    if ( q->size <= 0 ) {
        error_exit( EX_ACCESS );
    }

    node *el = q->arr[0];
    for ( size_t i = 0; i < q->size - 1; i++ ) {
        q->arr[i] = q->arr[i + 1];
    }

    q->size--;
    return el;
}

node *peek( const queue *q ) {
    invalid_mem_exit( q, EX_ACCESS );
    if ( q->size <= 0 ) {
        error_exit( EX_ACCESS );
    }

    return q->arr[0];
}

void sort_queue( queue *q ) {
    invalid_mem_exit( q, EX_ACCESS );
    qsort ( q->arr, q->size, sizeof( *q->arr ), compare_node );
}
