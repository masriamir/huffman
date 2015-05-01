/**
 * @file
 * @brief Huffman tree builder.
 */

#ifndef TREE_H
#define TREE_H

#include "node.h"

#define ASCII 256 ///< number of ASCII characters
#define DEF_QUEUE_SZ 64 ///< default queue size to use when building tree
#define DEF_BUF_SZ 1024 * 32 ///< default size of the encoded buffer

/**
 * Constructs a huffman tree based on the given string.
 * @param str the string
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
 * Encodes a given string using the given huffman tree.
 * @param root a pointer to the root node of the tree
 * @param str the string to encode
 * @return the huffman encoded string
 */
char *encode( const node *, const char * );

/**
 * Finds and returns a specific node from a given tree.
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
