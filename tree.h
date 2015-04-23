/**
 * @file
 * @brief Huffman tree builder.
 */

#ifndef TREE_H
#define TREE_H

#include "huffman.h"
#include "map.h"

/**
 * Constructs a Huffman tree and returns a pointer to the root node.
 * @param charmap the character frequency map pointer to build the tree from
 * @param size the number of elements in the charmap
 * @return a pointer to the root node of the tree
 */
node *build_tree( const map *, const size_t );

/**
 * Frees the given tree from memory.
 * @param n a pointer to the root node of the tree
 */
void free_tree( node * );

/**
 * Prints the contents of a tree.
 * @param n the root node pointer to the tree
 */
void print_tree( const node * );

#endif
