#include <stdlib.h>
#include <stdio.h>
#include "wf.h"

/* allocation */
wf_item *word_frequency( const char *str ) {
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
    wf_item *wf_item_arr = malloc( ( unique + 1 ) * sizeof( *wf_item_arr ) );
    if ( wf_item_arr == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }

    // trim original array down to size and create wf_item array from data
    for ( size_t i = 0; i < unique; i++ ) {
        
        for ( size_t j = 0; j < arr_size; j++ ) {
            if ( arr[j] != 0 ) {
                wf_item_arr[i].c = ( char ) j;
                wf_item_arr[i].freq = arr[j];
                arr[j] = 0;
                break;
            }
        }
    }

    // null last element
    wf_item_arr[unique].c = '\0';
    wf_item_arr[unique].freq = -1;

    sort_wf_items( &wf_item_arr, unique );
    return wf_item_arr;
}

void free_wf_items( wf_item **wf_item_arr ) {
    if ( wf_item_arr == NULL ) {
        return;
    }

    free( *wf_item_arr );
    *wf_item_arr = NULL;
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

int compare_wf_item( const void *a, const void *b ) {
    const wf_item *ia = ( const wf_item * ) a;
    const wf_item *ib = ( const wf_item * ) b;
    return ib->freq - ia->freq;
}

void sort_wf_items( wf_item **wf_item_arr, const size_t size ) {
    if ( wf_item_arr == NULL || size <= 1 ) {
        return;
    }

    qsort ( *wf_item_arr, size, sizeof( *wf_item_arr ), compare_wf_item );
}

void print_wf_item( const wf_item item ) {
    printf( "%c: %d\n", item.c, item.freq );
}

void print_wf_items( const wf_item *wf_item_arr ) {
    if ( wf_item_arr == NULL ) {
        return;
    }

    while ( wf_item_arr->c != '\0' ) {
        print_wf_item( *wf_item_arr );
        wf_item_arr++;
    }
}
