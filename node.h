/**
 * @file
 * @brief Huffman node implementation (24 bytes).
 */

#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

/**
 * Node struct to build a huffman tree.
 */
typedef struct node_t {
    char c; ///< character
    int freq; ///< frequency
    struct node_t *left; ///< left child pointer
    struct node_t *right; ///< right child pointer
} node;

/**
 * Allocates and returns a new node pointer.
 * @param c the character
 * @param freq the character's frequency
 * @param left node pointer to the left child
 * @param right node pointer to the right child
 * @return the allocated node pointer
 */
node *new_node( const char, const int, node *, node * );

/**
 * Frees the given node from memory.
 * @param n the address of the node pointer to free
 */
void free_node( node ** );

/**
 * Returns true if the node has no children, false otherwise.
 * @param n the node pointer to check
 * @return true if node is a leaf, false otherwise
 */
bool is_leaf( const node * );

/**
 * Prints the contents of a node.
 * @param n the node pointer to print
 */
void print_node( const node * );

#endif
