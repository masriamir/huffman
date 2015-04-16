#include <stdlib.h>
#include <stdio.h>
#include "wf.h"
#include "node.h"
#include "queue.h"

node build_tree( const wf_item *wf_arr, const size_t size ) {
    //TODO create queue, add items, combine, return root
    queue *q = new_queue();
    //node *nodes = malloc( size * sizeof( *node ) );
    for ( size_t i = 0; i < size; i++ ) {
        offer( q, new_node( wf_arr[i].c, wf_arr[i].freq, NULL, NULL ) );
    }
    node root;
    while ( q->size > 1 ) {
        node left = poll( q );
        node right = poll( q );
        root = new_node( '\0', left.freq + right.freq, &left, &right );
        offer( q, root );
    }
    print_queue( q );
    free_queue( q );
    return root;
}
