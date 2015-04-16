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

#endif
