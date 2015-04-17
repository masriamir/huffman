#include <stdlib.h>
#include <stdio.h>

#include "map.h"

/* allocation */
cf_pair *word_frequency( const char *str ) {
    if ( str == NULL ) {
        return NULL;
    }

    int arr[ASCII_LENGTH] = { 0 };
    for ( size_t i = 0; str[i] != '\0'; i++ ) {
        // arr index is ascii value of char
        int ascii = ( int ) str[i];
        arr[ascii]++;
    }

    size_t arr_size = ELEMENTS( arr );
    size_t unique = get_num_unique_chars( arr, arr_size );

    // allocate one extra to null-terminate array
    cf_pair *cf_pair_arr = malloc( ( unique + 1 ) * sizeof( *cf_pair_arr ) );
    if ( cf_pair_arr == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }

    // trim original array down to size and create cf_pair array from data
    for ( size_t i = 0; i < unique; i++ ) {
        
        for ( size_t j = 0; j < arr_size; j++ ) {
            if ( arr[j] != 0 ) {
                cf_pair_arr[i].c = ( char ) j;
                cf_pair_arr[i].freq = arr[j];
                arr[j] = 0;
                break;
            }
        }
    }

    // null last element
    cf_pair_arr[unique].c = '\0';
    cf_pair_arr[unique].freq = -1;

    sort_cf_pairs( &cf_pair_arr, unique );
    return cf_pair_arr;
}

void free_cf_pairs( cf_pair **cf_pair_arr ) {
    if ( cf_pair_arr == NULL ) {
        return;
    }

    free( *cf_pair_arr );
    *cf_pair_arr = NULL;
}

/* util */
unsigned int get_num_unique_chars( const int *arr, const size_t size ) {
    if ( arr == NULL || size <= 0 ) {
        return 0;
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

void sort_cf_pairs( cf_pair **cf_pair_arr, const size_t size ) {
    if ( cf_pair_arr == NULL || size <= 1 ) {
        return;
    }

    qsort ( *cf_pair_arr, size, sizeof( *cf_pair_arr ), compare_cf_pair );
}

void print_cf_pair( const cf_pair item ) {
    printf( "%c: %d\n", item.c, item.freq );
}

void print_cf_pairs( const cf_pair *cf_pair_arr ) {
    if ( cf_pair_arr == NULL ) {
        return;
    }

    while ( cf_pair_arr->c != '\0' ) {
        print_cf_pair( *cf_pair_arr );
        cf_pair_arr++;
    }
}
