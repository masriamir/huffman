#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "map.h"

map *new_map( const size_t size ) {
    map *m = new_mem( sizeof( *m ) );
    m->arr = new_mem( size * sizeof( *m->arr ) );

    m->size = 0;
    m->cap = size;

    return m;
}

void free_map( map *m ) {
    if ( !check_mem( m ) ) {
        return;
    }

    free_mem( m->arr );
    free_mem( m );
}

bool put( map *m, const pair p ) {
    if ( !check_mem( m ) ) {
        return false;
    }

    m->arr[ m->size++ ] = p;
    return true;
}

void sort_map( map *m ) {
    check_mem_err( m, EX_ACCESS );
    qsort ( m->arr, m->size, sizeof( *m->arr ), compare_freq );
}

void print_map( const map m ) {
    printf( "map[size = %zu, capacity = %zu]\n", m.size, m.cap );
    for ( size_t i = 0; i < m.size; i++ ) {
        print_pair( m.arr[i] );
    }
}
