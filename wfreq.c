#include <stdlib.h>

#include "mem_util.h"
#include "wfreq.h"

map *build_charmap( const char *str ) {
    invalid_mem_exit( str, EX_ACCESS );

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
                if ( !put( m, new_pair( ( char ) j, arr[j] ) ) ) {
                    error_exit( EX_ACCESS );
                }
                arr[j] = 0;
                break;
            }
        }
    }
    return m;
}

unsigned int get_num_unique_chars( const int *arr ) {
    invalid_mem_exit( arr, EX_ACCESS );

    unsigned int unique = 0;
    for ( size_t i = 0; i < ASCII_LENGTH; i++ ) {
        if ( arr[i] != 0 ) {
            unique++;
        }
    }
    return unique;
}
