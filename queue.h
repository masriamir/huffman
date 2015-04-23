/**
 * @file
 * @brief Queue implementation to handle nodes (224 bytes).
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "huffman.h"
#include "node.h"

#define DEF_SZ 8 ///< the default capacity of a queue

/**
 * Array implementation of a queue of nodes.
 */
typedef struct queue_t {
    node **arr; ///< pointer to an array of nodes
    size_t size; ///< size of the queue
    size_t cap; ///< maximum capacity of the queue
} queue;

/**
 * Allocates and returns a new queue pointer.
 * @return the allocated queue pointer
 */
queue *new_queue( void );

/**
 * Frees the given queue from memory.
 * @param q the queue pointer to free
 */
void free_queue( queue * );

/**
 * Resizes the given queue to twice its current capacity.
 * @param q the address of the queue pointer
 * @return the new capacity of the queue
 */
size_t resize_queue( queue ** );

/**
 * Adds the given node to a queue.
 * @param q the queue pointer
 * @param n the node pointer to add
 * @return true if successful, false otherwise
 */
bool offer( queue *, node * );

/**
 * Returns and removes the head of the queue.
 * @param q the queue pointer
 * @return a pointer to the head of the queue
 */
node *poll( queue * );

/**
 * Returns, but does not remove, the head of the queue.
 * @param q the queue pointer
 * @return a pointer to the head of the queue
 */
node *peek( const queue * );

/**
 * Sorts a queue by each node's frequency in descending order.
 * @param q a pointer to a queue of nodes
 */
void sort_queue( queue * );

/**
 * Prints the contents of a queue.
 * @param q the queue pointer to print
 */
void print_queue( const queue * );

#endif
