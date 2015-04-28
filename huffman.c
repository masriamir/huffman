#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "wfreq.h"
#include "node.h"
#include "tree.h"
#include "dictionary.h"

char *huffman_encode( const char *str ) {
    map *charmap = build_charmap( str );
    node *root = build_tree( charmap );
    dictionary *d = build_dictionary( root, charmap->size );
    free_map( charmap );
    free_tree( root );
    char *enc = encode( d, str );
    free_dictionary( d );
    return enc;
}
