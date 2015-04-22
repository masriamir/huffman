#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "node.h"
#include "queue.h"

node *build_tree( const map *m, const size_t size ) {
    queue *q = new_queue();
    for ( size_t i = 0; i < size; i++ ) {
        offer( q, new_node( ( m->arr[i] )->c, ( m->arr[i] )->freq,
                            NULL, NULL ) );
    }

    while ( q->size > 1 ) {
        // pointers are being reassigned, no need to free them here
        node *left = poll( q );
        printf( "left = [%c: %d]\n", left->c, left->freq );
        node *right = poll( q );
        printf( "right = [%c: %d]\n", right->c, right->freq );
        node *root = new_node( '\0', left->freq + right->freq, left, right );
        offer( q, root );
    }

    node *root = poll( q );
    free_queue( &q );
    return root;
}

void free_tree( node **n ) {
    if ( *n == NULL ) {
        return;
    }

    if ( is_leaf( *n ) ) {
        free_node( n );
    } else {
        free_tree( &( *n )->left );
        free_tree( &( *n )->right );
    }

    free_node( n );
}

void print_tree( const node *n ) {
    if ( n == NULL ) {
        fprintf( stderr, "illegal access\n" );
        exit( 1 );
    }

    if ( is_leaf( n ) ) {
        print_node( n );
    } else {
        print_node( n );
        print_tree( n->left );
        print_tree( n->right );
    }
}
