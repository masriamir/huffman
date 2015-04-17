#include <stdlib.h>
#include <stdio.h>

#include "map.h"

cf_pair *build_charmap( const char *str ) {
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

    size_t size = ELEMENTS( arr );
    size_t unique = get_num_unique_chars( arr, size );

    // allocate one extra to null-terminate array
    cf_pair *map = malloc( ( unique + 1 ) * sizeof( *map ) );
    if ( map == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }

    //TODO try to optimize loop
    for ( size_t i = 0; i < unique; i++ ) {
        for ( size_t j = 0; j < size; j++ ) {
            if ( arr[j] != 0 ) {
                map[i].c = ( char ) j;
                map[i].freq = arr[j];
                arr[j] = 0;
                break;
            }
        }
    }

    // use a null element to terminate the array
    map[unique].c = '\0';
    map[unique].freq = 0;

    sort_map( &map, unique );
    return map;
}

void free_map( cf_pair **map ) {
    if ( *map == NULL ) {
        return;
    }

    free( *map );
    *map = NULL;
}

unsigned int get_num_unique_chars( const int *arr, const size_t size ) {
    if ( arr == NULL || size < 1 ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    unsigned int unique = 0;
    for ( size_t i = 0; i < size; i++ ) {
        if ( arr[i] != 0 ) {
            unique++;
        }
    }
    return unique;
}

int compare_cf_pair( const void *a, const void *b ) {
    const cf_pair *ia = ( const cf_pair * ) a;
    const cf_pair *ib = ( const cf_pair * ) b;
    return ib->freq - ia->freq;
}

void sort_map( cf_pair **map, const size_t size ) {
    if ( map == NULL || size < 1 ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    qsort ( *map, size, sizeof( *map ), compare_cf_pair );
}

void print_entry( const cf_pair entry ) {
    printf( "%c: %d\n", entry.c, entry.freq );
}

void print_map( const cf_pair *map ) {
    if ( map == NULL ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    for ( size_t i = 0; map->c != '\0'; i++, map++ ) {
        print_entry( *map );
    }
}
