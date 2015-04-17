#include <stdlib.h>
#include <stdio.h>

#include "wf.h"
#include "node.h"
#include "tree.h"

int main ( void ) {
    char *str = "abracadabra!";
    wf_item *charmap = word_frequency( str );
    print_wf_items( charmap );
    node *root = build_tree( charmap, 6 );
    print_node( root );
    free_tree( &root );
    free_wf_items( &charmap );
    return 0;
}
