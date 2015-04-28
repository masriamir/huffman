#include <stdlib.h>

#include "mem_util.h"
#include "map.h"
#include "node.h"
#include "queue.h"

node *build_tree( const map *m ) {
    queue q = new_queue( m->size );
    for ( size_t i = 0; i < m->size; i++ ) {
        node *n = new_node( m->arr[i].c, m->arr[i].freq, NULL, NULL );
        if ( !offer( &q, n ) ) {
            error_exit( EX_ACCESS );
        }
    }

    while ( q.size > 1 ) {
        // pointers are being reassigned, no need to free them here
        node *left = poll( &q );
        node *right = poll( &q );
        node *root = new_node( '\0', left->freq + right->freq, left, right );
        if ( !offer( &q, root ) ) {
            error_exit( EX_ACCESS );
        }
    }

    node *root = poll( &q );
    free_queue( &q );
    return root;
}

void free_tree( node *n ) {
    // check needed due to recursive frees
    if ( invalid_mem( n ) ) {
        return;
    }

    free_tree( n->left );
    free_tree( n->right );
    free_node( n );
}
