/**
 * @file
 * @brief Queue implementation to handle nodes (224 bytes).
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "node.h"

#define DEF_SZ 8

typedef struct queue_t {
    node **arr;
    size_t size;
    size_t cap;
} queue;

/* allocation */
queue *new_queue( void );
void free_queue( queue ** );
size_t resize_queue( queue ** );

/* operations */
bool offer( queue *, node * );
node *poll( queue * );
node *peek( const queue * );

/* util */
void print_queue( const queue * );

#endif
