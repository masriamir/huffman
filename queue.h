/**
 * @file
 * @brief Queue implementation to handle nodes (224 bytes).
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "huffman.h"
#include "node.h"

/**
 * Array implementation of a queue of nodes.
 */
typedef struct queue_t {
    node **arr; ///< pointer to an array of nodes
    size_t size; ///< size of the queue
    size_t cap; ///< maximum capacity of the queue
} queue;

/**
 * Returns a new queue struct.
 * @param size the size of the queue
 * @return the new queue struct
 */
queue new_queue( const size_t );

/**
 * Frees the given queue from memory.
 * @param q the queue pointer to free
 */
void free_queue( queue * );

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
 * @param q the queue struct to print
 */
void print_queue( const queue );

#endif
