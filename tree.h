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
node *build_tree( const map *, const size_t );

/**
 * Frees the tree represented by the address of the given root node pointer
 * from memory.
 * @param n the address of the root node pointer to the tree
 */
void free_tree( node ** );

/**
 * Prints the contents of a tree.
 * @param n the root node pointer to the tree
 */
void print_tree( const node * );

#endif
