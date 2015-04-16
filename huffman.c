#include <stdlib.h>
#include <stdio.h>
#include "wf.h"
#include "node.h"
#include "tree.h"
#include "queue.h"

int main ( void ) {
    char *str = "abracadabra!";
    wf_item *charmap = word_frequency( str );
    print_wf_items( charmap );
    /*for ( size_t i = 0; i < 6; i++ ) {
        node *n = new_node( charmap[i].c, charmap[i].freq, NULL, NULL );
        print_node( n );
        free( n );
    }*/
    queue *q = new_queue();
    for ( size_t i = 0; i < 6; i++ ) {
        node *n = new_node( charmap[i].c, charmap[i].freq, NULL, NULL );
        print_node( n );
        offer( q, n );
        free_node( &n );
    }
    print_queue( q );
    free_queue( &q );
    //node *root = build_tree( charmap, 6 );
    //free_node( &root );
    //print_node( root );
    free_wf_items( &charmap );
    return 0;
}
