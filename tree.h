/**
 * @file
 * @brief Huffman tree builder.
 */

#ifndef TREE_H
#define TREE_H

/**
 * Constructs a Huffman tree and returns the root node.
 * @param charmap the character frequency map to build the tree from
 * @param size the number of elements in the charmap
 * @return the root node of the tree
 */
node *build_tree( const wf_item *, const size_t );

/**
 * Frees the tree represented by the given root node pointer from memory.
 * @param n the address of the root node pointer to the tree
 */
void free_tree( node ** );

/**
 * Print the contents of a tree.
 * @param n the root node pointer to the tree
 */
void print_tree( const node * );

#endif
