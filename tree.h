/**
 * @file
 * @brief Huffman tree builder.
 */

#ifndef TREE_H
#define TREE_H

#include "node.h"

#define ASCII 256 ///< number of ASCII characters
#define DEF_QUEUE_SZ 64 ///< default queue size to use when building tree

/**
 * Constructs a Huffman tree and returns a pointer to the root node.
 * @param str the string to use when generating the tree
 * @return a pointer to the root node of the tree
 */
node *build_tree( const char * );

/**
 * Generates the huffman codes for each leaf in the given tree.
 * @param root a pointer to the root node of the tree
 * @param buf a character buffer to concatenate generated codes
 */
void encode_tree( node *, char * );

/**
 * Returns a pointer to a node in the given tree that contains the given char.
 * @param root a pointer to the root node of the tree
 * @param c the character to search for
 * @return a pointer to the node if found, NULL otherwise
 */
node *get_node( const node *, const char );

/**
 * Frees the given tree from memory.
 * @param n a pointer to the root node of the tree
 */
void free_tree( node * );

#endif
