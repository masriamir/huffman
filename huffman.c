#include <stdlib.h>
#include <stdio.h>

#include "node.h"
#include "tree.h"

char *huffman_encode( const char *str ) {
    node *root = build_tree( str );
    char *enc = encode( root, str );
    free_tree( root );
    return enc;
}
