/**
 * @file
 * @brief Handles generation of a character-frequency map.
 */

#ifndef WFREQ_H
#define WFREQ_H

#include "map.h"

#define ASCII_LENGTH 256 ///< number of ASCII characters

/**
 * Allocates and returns a new character-frequency map.
 * @param str the character string to generate the map from
 * @return the allocated character-frequency map
 */
map *build_charmap( const char * );

/**
 * Returns the number of elements in the preliminary ASCII-indexed array.
 * @param arr an array of integers
 * @return the number of actual elements in the array
 */
unsigned int get_num_unique_chars( const int * );

#endif
