#include <stdlib.h>
#include <stdio.h>

#include "wf.h"
#include "node.h"
#include "queue.h"

node *build_tree( const wf_item *wf_arr, const size_t size ) {
    queue *q = new_queue();
    for ( size_t i = 0; i < size; i++ ) {
        offer( q, new_node( wf_arr[i].c, wf_arr[i].freq, NULL, NULL ) );
    }
    while ( q->size > 1 ) {
        node *left = poll( q );
        node *right = poll( q );
        node *root = new_node( '\0', left->freq + right->freq, left, right );
        offer( q, root );
    }
    node *root = poll( q );
    free_queue( &q );
    return root;
}
