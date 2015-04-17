#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "node.h"
#include "tree.h"

int main ( void ) {
    char *str = "abracadabra!";
    cf_pair *charmap = build_charmap( str );
    print_map( charmap );
    node *root = build_tree( charmap, 6 );
    print_tree( root );
    free_tree( &root );
    free_map( &charmap );
    return 0;
}
