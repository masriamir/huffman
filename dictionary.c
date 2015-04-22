#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "map.h"
#include "node.h"
#include "dictionary.h"

code *new_code( const char c, char *bin ) {
    code *cd = malloc( sizeof( *cd ) );
    cd->c = c;
    size_t bin_len = strlen( bin );
    //TODO fix read error
    cd->bin = malloc( bin_len * sizeof( char ) );
    strncpy( cd->bin, bin, bin_len );
    return cd;
}

void free_code( code **c ) {
    if ( *c == NULL ) {
        return;
    }

    free( ( *c )->bin );
    ( *c )->bin = NULL;

    free( *c );
    *c = NULL;
}

void print_code( const code *c ) {
    printf( "code[c = %c, bin = %s]\n", c->c, c->bin );
}

dictionary *new_dictionary( const size_t size ) {
    dictionary *d = malloc( sizeof( *d ) );
    d->arr = malloc( size * sizeof( *d->arr ) );
    d->size = 0;
    d->cap = size;
    return d;
}

dictionary *build_dictionary( const node *root, const size_t size ) {
    dictionary *d = new_dictionary( size );
    char buf[256] = { 0 };
    if ( buf == NULL ) {
        fprintf( stderr, "mem error\n" );
        free_dictionary( &d );
        exit( 1 );
    }
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

void free_dictionary( dictionary **d ) {
    for ( size_t i = 0; i < ( *d )->size; i++ ) {
        free_code( &( *d )->arr[i] );
    }

    free( ( *d )->arr );
    ( *d )->arr = NULL;

    free( *d );
    *d = NULL;
}

void print_dictionary( const dictionary *d ) {
    printf( "dictionary[size = %zu, capacity = %zu]\n", d->size, d->cap );
    for ( size_t i = 0; i < d->size; i++ ) {
        print_code( d->arr[i] );
    }
}
