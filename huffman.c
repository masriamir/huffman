#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "wfreq.h"
#include "node.h"
#include "tree.h"
#include "dictionary.h"
#include "print.h"

int main ( int argc, char *argv[] ) {
    if ( argc != 2 ) {
        fprintf( stderr, "Usage: out text\n" );
        return 0;
    }

    char *str = argv[1];

    map *charmap = build_charmap( str );
    print_map( *charmap );

    node *root = build_tree( charmap );
    print_tree( root );

    dictionary *d = build_dictionary( root, charmap->size );
    print_dictionary( *d );

    char *enc = encode( d, str );
    printf( "encoded: %s\n", enc );
    free( enc );

    free_map( charmap );
    free_tree( root );
    free_dictionary( d );

    return 0;
}
