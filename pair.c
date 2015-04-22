#include <stdlib.h>
#include <stdio.h>

#include "pair.h"

pair *new_pair( const char c, const int freq ) {
    pair *p = new_mem( sizeof( *p ) );

    p->c = c;
    p->freq = freq;

    return p;
}

void free_pair( pair **p ) {
    free_mem( *p );
}

int compare_freq( const void *a, const void *b ) {
    const pair *ia = *( const pair ** ) a;
    const pair *ib = *( const pair ** ) b;
    return ib->freq - ia->freq;
}

void print_pair( const pair *p ) {
    check_mem_err( p, EX_ACCESS );
    printf( "%c: %d\n", p->c, p->freq );
}
