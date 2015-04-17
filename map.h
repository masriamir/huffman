/**
 * @file
 * @brief Array-based map implementation using character-frequency pairs.
 */

#ifndef MAP_H
#define MAP_H

#define ASCII_LENGTH 256 ///< number of ASCII characters
#define ELEMENTS( x ) ( sizeof( x ) / sizeof( x[0] ) ) ///< length of an array

/**
 * Character-frequency pair struct used to build a map.
 */
typedef struct cf_pair_t {
    char c; ///< character
    unsigned int freq; ///< frequency
} cf_pair;

/**
 * Allocates and returns a new map of character-frequency pairs.
 * @param str the character string to generate the array from
 * @return a map of character frequency pairs
 */
cf_pair *build_charmap( const char * );

/**
 * Frees the given map from memory.
 * @param map the address of the map pointer to free
 */
void free_map( cf_pair ** );

/**
 * Returns the number of elements in the preliminary ASCII-indexed array.
 * @param arr an array of integers
 * @param size the total size of the array
 * @return the number of actual elements in the array
 */
unsigned int get_num_unique_chars( const int *, const size_t );

/**
 * Compares two character frequency pairs by their frequency.
 * @param a the first character-frequency pair
 * @param b the second character-frequency pair
 * @return an int representing the greater of the two pairs
 */
int compare_cf_pair( const void *, const void * );

/**
 * Sorts a character-frequency map by frequency in descending order.
 * @param map the map of character-frequency pairs
 * @param size the size of the map
 */
void sort_map( cf_pair **, const size_t );

/**
 * Prints the contents of a single character-frequency pair.
 * @param entry the character-frequency pair
 */
void print_entry( const cf_pair );

/**
 * Prints the contents of a character-frequency map.
 * @param map the map pointer to print
 */
void print_map( const cf_pair * );

#endif
