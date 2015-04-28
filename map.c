#include <stdlib.h>

#include "mem_util.h"
#include "map.h"

map *new_map( const size_t size ) {
    map *m = new_mem( sizeof( *m ) );
    m->arr = new_mem( size * sizeof( *m->arr ) );

    m->size = 0;
    m->cap = size;

    return m;
}

void free_map( map *m ) {
    free_mem( m->arr );
    free_mem( m );
}

bool put( map *m, const pair p ) {
    if ( invalid_mem( m ) ) {
        return false;
    }

    m->arr[ m->size++ ] = p;
    return true;
}

void sort_map( map *m ) {
    invalid_mem_exit( m, EX_ACCESS );
    qsort ( m->arr, m->size, sizeof( *m->arr ), compare_freq );
}
