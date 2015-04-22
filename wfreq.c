#include <stdlib.h>
#include <stdio.h>

#include "wfreq.h"

map *build_charmap( const char *str ) {
    if ( str == NULL ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    int arr[ASCII_LENGTH] = { 0 };
    for ( size_t i = 0; str[i] != '\0'; i++ ) {
        // arr index is ascii value of char
        int ascii = ( int ) str[i];
        arr[ascii]++;
    }

    size_t unique = get_num_unique_chars( arr );
    map *m = new_map( unique );

    //TODO try to optimize loop
    for ( size_t i = 0; i < m->cap; i++ ) {
        for ( size_t j = 0; j < ASCII_LENGTH; j++ ) {
            if ( arr[j] != 0 ) {
                put( m, new_pair( ( char ) j, arr[j] ) );
                arr[j] = 0;
                break;
            }
        }
    }

    sort_map( &m );
    return m;
}

unsigned int get_num_unique_chars( const int *arr ) {
    if ( arr == NULL ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    unsigned int unique = 0;
    for ( size_t i = 0; i < ASCII_LENGTH; i++ ) {
        if ( arr[i] != 0 ) {
            unique++;
        }
    }
    return unique;
}
