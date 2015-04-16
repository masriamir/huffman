#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "node.h"

node new_node( const char c, const int freq, node *left, node *right ) {
    node n;
    n.c = c;
    n.freq = freq;
    n.left = left;
    n.right = right;

    return n;
}

bool is_leaf( const node n ) {
    return n.left == NULL && n.right == NULL;
}

void print_node( const node n ) {
    printf( "node[c = %c, freq = %d, left = %p, right = %p]\n",
            n.c, n.freq, ( void * )n.left, ( void * )n.right );
}
