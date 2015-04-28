/**
 * @file
 * @brief Huffman tree builder.
 */

#ifndef TREE_H
#define TREE_H

#include "map.h"

/**
 * Constructs a Huffman tree and returns a pointer to the root node.
 * @param charmap the character frequency map pointer to build the tree from
 * @param size the number of elements in the charmap
 * @return a pointer to the root node of the tree
 */
node *build_tree( const map * );

/**
 * Frees the given tree from memory.
 * @param n a pointer to the root node of the tree
 */
void free_tree( node * );

#endif
