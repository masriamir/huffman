/**
 * @file
 * @brief
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "node.h"

#define DEF_BUF_SZ 1024 * 32 ///< default size of the encoded buffer

/**
 * Encodes a given string using the given huffman tree.
 * @param root a pointer to the root node of the tree
 * @param str the string to encode
 * @return the huffman encoded string
 */
char *encode( const node *, const char * );

#endif
