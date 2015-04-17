#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "node.h"
#include "tree.h"

int main ( void ) {
    char *str = "abracadabra!";
    cf_pair *charmap = word_frequency( str );
    print_cf_pairs( charmap );
    node *root = build_tree( charmap, 6 );
    print_tree( root );
    free_tree( &root );
    free_cf_pairs( &charmap );
    return 0;
}
