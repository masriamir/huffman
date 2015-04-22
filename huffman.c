#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "wfreq.h"
#include "node.h"
#include "tree.h"

int main ( int argc, char *argv[] ) {
    if ( argc != 2 ) {
        fprintf( stderr, "Usage: out text\n" );
        return 0;
    }

    char *str = argv[1];
    map *charmap = build_charmap( str );
    print_map( charmap );
    node *root = build_tree( charmap, charmap->size );
    print_tree( root );
    free_tree( &root );
    free_map( &charmap );
    return 0;
}
