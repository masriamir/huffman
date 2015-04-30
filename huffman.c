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
    free_map( charmap );
    char *enc = encode( root, str );
    free_tree( root );
    return enc;
}
