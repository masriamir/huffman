/**
 * @file
 * @brief Pair implementation used to store a character and its frequency.
 */

#ifndef PAIR_H
#define PAIR_H

#include "huffman.h"

/**
 * Character-frequency pair struct used to build a map.
 */
typedef struct pair_t {
    char c;
    int freq;
} pair;

/**
 * Returns a new pair struct.
 * @param c the character
 * @param freq the character's frequency
 * @return the new pair struct
 */
pair new_pair( const char, const int );

/**
 * Compares two character-frequency pairs by their frequency.
 * @param a the first character-frequency pair
 * @param b the second character-frequency pair
 * @return an int representing the greater of the two pairs
 */
int compare_freq( const void *, const void * );

/**
 * Prints the contents of a pair struct.
 * @param p the pair struct
 */
void print_pair( const pair );

#endif
