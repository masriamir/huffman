#include <stdlib.h>
#include <stdio.h>

#include "map.h"

map *new_map( const size_t size ) {
    map *m = new_mem( sizeof( *m ) );
    m->arr = new_mem( size * sizeof( *m->arr ) );

    m->size = 0;
    m->cap = size;

    return m;
}

void free_map( map **m ) {
    if ( *m == NULL ) {
        return;
    }

    for ( size_t i = 0; i < ( *m )->size; i++ ) {
        free( ( *m )->arr[i] );
        ( *m )->arr[i] = NULL;
    }

    free( ( *m )->arr );
    ( *m )->arr = NULL;

    free( *m );
    *m = NULL;
}

bool put( map *m, pair *p ) {
    if ( m == NULL || p == NULL ||  m->size == m->cap ) {
        return false;
    }

    m->arr[ m->size++ ] = p;
    return true;
}

void sort_map( map **m ) {
    if ( *m == NULL || ( *m )->size < 1 ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    qsort ( ( *m )->arr, ( *m )->size, sizeof( *( *m )->arr ), compare_freq );
}

void print_map( const map *m ) {
    check_mem_exit( m, EX_ACCESS );

    printf( "map[size = %zu, capacity = %zu]\n", m->size, m->cap );
    for ( size_t i = 0; i < m->size; i++ ) {
        print_pair( m->arr[i] );
    }
}
