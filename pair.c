#include <stdlib.h>
#include <stdio.h>

#include "pair.h"

pair *new_pair( const char c, const int freq ) {
    pair *p = malloc( sizeof( *p ) );
    if ( p == NULL ) {
        fprintf( stderr, "mem error\n" );
        exit( 1 );
    }

    p->c = c;
    p->freq = freq;

    return p;
}

void free_pair( pair **p ) {
    if ( *p == NULL ) {
        return;
    }

    free( *p );
    *p = NULL;
}

int compare_freq( const void *a, const void *b ) {
    const pair *ia = *( const pair ** ) a;
    const pair *ib = *( const pair ** ) b;
    return ib->freq - ia->freq;
}

void print_pair( const pair *p ) {
    if ( p == NULL ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    printf( "%c: %d\n", p->c, p->freq );
}
