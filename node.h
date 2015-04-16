/**
 * @file
 * @brief huffman node implementation
 */

#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

typedef struct node_t node;

/**
 * Node struct to build a huffman tree.
 */
struct node_t {
    char c; ///< character
    int freq; ///< frequency
    node *left; ///< left child
    node *right; ///< right child
};

/**
 * Allocates and returns a new node pointer.
 * @param c character
 * @param freq frequency
 * @param left left child
 * @param right right child
 * @return the allocated node
 */
node new_node( const char, const int, node *, node * );
//void free_node( node ** );

/**
 * Returns true if the node has no children, false otherwise.
 * @param n the node to check
 * @return true if node is a leaf, false otherwise
 */
bool is_leaf( const node );

/**
 * Prints the contents of a node.
 * @param n the node to print
 */
void print_node( const node );

#endif
