/**
 * @file
 * @brief Array-based map implementation using character-frequency pairs.
 */

#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdbool.h>

#include "pair.h"

/**
 * Array implementation of a map of character-frequency pairs.
 */
typedef struct map_t {
    pair *arr; ///< array of pairs
    size_t size; ///< size of the map
    size_t cap; ///< maximum capacity of the map
} map;

/**
 * Allocates and returns a new map pointer.
 * @param size the fixed size of the map
 * @return the allocated map pointer
 */
map *new_map( const size_t );

/**
 * Frees the given map from memory.
 * @param map the map pointer to free
 */
void free_map( map * );

/**
 * Inserts a new pair into the given map.
 * @param map the map pointer
 * @param pair the pair struct to insert
 * @return true if successful, false otherwise
 */
bool put( map *, const pair );

/**
 * Sorts a character-frequency map by frequency in descending order.
 * @param map a pointer to a map of character-frequency pairs
 */
void sort_map( map * );

#endif
