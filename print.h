/**
 * @file
 * @brief Print utility functions.
 */

#ifndef PRINT_H
#define PRINT_H

#include "node.h"
#include "queue.h"

/**
 * Prints the contents of a given node.
 * @param n a pointer to the node
 */
void print_node( const node * );

/**
 * Prints the contents of a given queue.
 * @param q the queue to print
 */
void print_queue( const queue );

/**
 * Prints the contents of a given tree.
 * @param n a pointer to the root node of the tree
 */
void print_tree( const node * );

#endif
