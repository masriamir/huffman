#ifndef PRINT_H
#define PRINT_H

#include "node.h"
#include "map.h"
#include "queue.h"
#include "dictionary.h"
#include "code.h"
#include "pair.h"

/**
 * Prints the contents of a dictionary code.
 * @param cd the code to print
 */
void print_code( const code );

/**
 * Prints the contents of a huffman dictionary.
 * @param d the dictionary to print
 */
void print_dictionary( const dictionary );

/**
 * Prints the contents of a node.
 * @param n the node pointer to print
 */
void print_node( const node * );

/**
 * Prints the contents of a character-frequency map.
 * @param map the map struct to print
 */
void print_map( const map );

/**
 * Prints the contents of a queue.
 * @param q the queue struct to print
 */
void print_queue( const queue );

/**
 * Prints the contents of a tree.
 * @param n the root node pointer to the tree
 */
void print_tree( const node * );

/**
 * Prints the contents of a pair struct.
 * @param p the pair struct
 */
void print_pair( const pair );

#endif
