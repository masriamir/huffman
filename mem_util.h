/**
 * @file
 * @brief Memory utility functions.
 */

#ifndef MEM_UTIL_H
#define MEM_UTIL_H

#include <stdlib.h>
#include <stdbool.h>

#define EX_ACCESS "illegal memory access" ///< illegal memory access
#define EX_MEM "could not allocate memory" ///< memory allocation error

/*
 * Allocates a new block of memory.
 * @param size the size of memory to allocate
 * @return a pointer to the allocated memory
 */
void *new_mem( const size_t );

/*
 * Reallocates a given block of memory.
 * @param ptr a pointer to the block of memory to resize
 * @param size the new size of the block
 * @return a pointer to the reallocated memory
 */
void *re_mem( void *, const size_t );

/*
 * Frees a given pointer from memory.
 * @param ptr the pointer
 */
void free_mem( void * );

/*
 * Determines if a given pointer is invalid.
 * @param ptr the pointer
 * @return true if the pointer is NULL, false otherwise
 */
bool invalid_mem( const void * );

/*
 * Determines if a given pointer is invalid and prints the given message.
 * @param ptr the pointer
 * @param str the message to print
 * @return true if the pointer is NULL, false otherwise
 */
bool invalid_mem_err( const void *, const char * );

/*
 * Determines if a given pointer is invalid, prints the given message and exits.
 * @param ptr the pointer
 * @param str the message to print
 */
void invalid_mem_exit( const void *, const char * );

/*
 * Prints a given message to stderr.
 * @param str the message
 */
void error( const char * );

/*
 * Prints a given message to stderr and exits.
 * @param str the message
 */
void error_exit( const char * );

#endif
