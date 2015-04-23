#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "wfreq.h"
#include "node.h"
#include "tree.h"
#include "dictionary.h"

int main ( int argc, char *argv[] ) {
    if ( argc != 2 ) {
        fprintf( stderr, "Usage: out text\n" );
        return 0;
    }

    char *str = argv[1];

    map *charmap = build_charmap( str );
    size_t size = charmap->size;
    print_map( *charmap );

    node *root = build_tree( charmap, size );
    free_map( charmap );
    print_tree( root );

    dictionary *d = build_dictionary( root, size );
    // print_dictionary( d );

    free_tree( root );
    free_dictionary( &d );

    return 0;
}
