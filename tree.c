#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "node.h"
#include "queue.h"

node *build_tree( const map *m ) {
    queue q = new_queue( m->size );
    for ( size_t i = 0; i < m->size; i++ ) {
        offer( &q, new_node( m->arr[i].c, m->arr[i].freq, NULL, NULL ) );
    }

    while ( q.size > 1 ) {
        // pointers are being reassigned, no need to free them here
        node *left = poll( &q );
        node *right = poll( &q );
        node *root = new_node( '\0', left->freq + right->freq, left, right );
        offer( &q, root );
    }

    node *root = poll( &q );
    free_queue( &q );
    return root;
}

void free_tree( node *n ) {
    if ( !check_mem( n ) ) {
        return;
    }

    free_tree( n->left );
    free_tree( n->right );
    free_node( n );
}

void print_tree( const node *n ) {
    check_mem_exit( n, EX_ACCESS );

    if ( is_leaf( n ) ) {
        print_node( n );
    } else {
        print_node( n );
        print_tree( n->left );
        print_tree( n->right );
    }
}
