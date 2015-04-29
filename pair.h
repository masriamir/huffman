/**
 * @file
 * @brief Pair implementation used to store a character and its frequency.
 */

#ifndef PAIR_H
#define PAIR_H

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

#endif
