/**
 * @file
 * @brief Priority queue implementation to handle nodes.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "node.h"

/**
 * Queue struct using an array to store data.
 */
typedef struct queue_t {
    node **arr; ///< pointer to an array of nodes
    size_t size; ///< size of the queue
    size_t cap; ///< maximum capacity of the queue
} queue;

/**
 * Creates and returns a new queue.
 * @param size the capacity of the queue
 * @return the new queue
 */
queue new_queue( const size_t );

/**
 * Frees the given queue from memory.
 * @param q a pointer to the queue
 */
void free_queue( queue * );

/**
 * Inserts the given node to a queue.
 * @param q a pointer to the queue
 * @param n a pointer to the node
 * @return true if successful, false otherwise
 */
bool offer( queue *, node * );

/**
 * Returns and removes the head of the given queue.
 * @param q a pointer to the queue
 * @return a pointer to the node that was removed
 */
node *poll( queue * );

/**
 * Returns, but does not remove, the head of the given queue.
 * @param q a pointer to the queue
 * @return a pointer to the head of the given queue
 */
node *peek( const queue * );

/**
 * Sorts a given queue by each node's frequency in ascending order.
 * @param q a pointer to the queue
 */
void sort_queue( queue * );

#endif
