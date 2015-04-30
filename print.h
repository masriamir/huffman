#ifndef PRINT_H
#define PRINT_H

#include "node.h"
#include "queue.h"

/**
 * Prints the contents of a node.
 * @param n the node pointer to print
 */
void print_node( const node * );

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

#endif
