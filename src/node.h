/**
 * @file
 * @brief Huffman node implementation.
 */

#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

#define MAX_CODE_LENGTH 32 ///< maximum length of a single huffman code

/**
 * Node struct used when building a huffman tree.
 */
typedef struct node_t {
    char c; ///< character
    int freq; ///< frequency
    char *bits; ///< encoded bits
    struct node_t *left; ///< left child pointer
    struct node_t *right; ///< right child pointer
} node;

/**
 * Allocates and returns a new node pointer.
 * @param c the character
 * @param freq the character's frequency
 * @param left a node pointer to the left child
 * @param right a node pointer to the right child
 * @return a pointer to the allocated node
 */
node *new_node( const char, const int, node *, node * );

/**
 * Frees the given node from memory.
 * @param n a pointer to the node
 */
void free_node( node * );

/**
 * Compares two nodes by their frequency.
 * @param a a pointer to the first node
 * @param b a pointer to the second node
 * @return an int representing the lesser of the two nodes
 */
int compare_node( const void *, const void * );

/**
 * Returns true if the given node has no children, false otherwise.
 * @param n a pointer to the node
 * @return true if node is a leaf, false otherwise
 */
bool is_leaf( const node * );

#endif
