#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "map.h"
#include "node.h"
#include "code.h"
#include "dictionary.h"

dictionary *new_dictionary( const size_t size ) {
    dictionary *d = new_mem( sizeof( *d ) );
    d->arr = new_mem( size * sizeof( *d->arr ) );

    d->size = 0;
    d->cap = size;

    return d;
}

dictionary *build_dictionary( const node *root, const size_t size ) {
    dictionary *d = new_dictionary( size );
    char buf[MAX_BUF_LEN] = { 0 };
    build( d, root, buf );
    return d;
}

void build( dictionary *d, const node *root, char *buf ) {
    if ( is_leaf( root ) ) {
        d->arr[ d->size++ ] = new_code( root->c, buf );
    } else {
        strncat( buf, "0", 1 );
        build( d, root->left, buf );
        buf[ strlen( buf ) - 1 ] = '\0';
        strncat( buf, "1", 1 );
        build( d, root->right, buf );
        buf[ strlen( buf ) - 1 ] = '\0';
    }
}

void free_dictionary( dictionary *d ) {
    free_mem( d->arr );
    free_mem( d );
}

char *get_code( const dictionary *d, const char c ) {
    for ( size_t i = 0; i < d->size; i++ ) {
        if ( d->arr[i].c == c ) {
            return d->arr[i].bin;
        }
    }
    return "";
}

char get_char( const dictionary *d, const char *bin ) {
    for ( size_t i = 0; i < d->size; i++ ) {
        if ( strcmp( d->arr[i].bin, bin ) == 0 ) {
            return d->arr[i].c;
        }
    }
    return '\0';
}

char *encode( const dictionary *d, const char *str ) {
    char buf[MAX_BUF_LEN] = { 0 };
    for ( size_t i = 0; i < strlen( str ); i++ ) {
        strcat( buf, get_code( d, str[i] ) );
    }
    char *enc = new_mem( ( 1 + strlen( buf ) ) * sizeof( *enc ) );
    strncpy( enc, buf, strlen( buf ) );
    enc[strlen( buf )] = '\0';
    return enc;
}

void print_dictionary( const dictionary d ) {
    printf( "dictionary[size = %zu, capacity = %zu]\n", d.size, d.cap );
    for ( size_t i = 0; i < d.size; i++ ) {
        print_code( d.arr[i] );
    }
}
