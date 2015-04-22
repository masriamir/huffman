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
 * Allocates and returns a new pair pointer.
 * @param c the character
 * @param freq the character's frequency
 * @return the allocated pair pointer
 */
pair *new_pair( const char, const int );

/**
 * Frees the given pair from memory.
 * @param p the address of the pair pointer to free
 */
void free_pair( pair ** );

/**
 * Compares two character-frequency pairs by their frequency.
 * @param a the first character-frequency pair
 * @param b the second character-frequency pair
 * @return an int representing the greater of the two pairs
 */
int compare_freq( const void *, const void * );

/**
 * Prints the contents of a pair.
 * @param p the pair pointer to print
 */
void print_pair( const pair * );

#endif
