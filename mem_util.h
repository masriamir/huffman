#ifndef MEM_UTIL_H
#define MEM_UTIL_H

#include <stdlib.h>
#include <stdbool.h>

#define EX_ACCESS "illegal memory access"
#define EX_MEM "could not allocate memory"

void *new_mem( const size_t );
void *re_mem( void *, const size_t );
void free_mem( void * );

bool invalid_mem( const void * );
bool invalid_mem_err( const void *, const char * );
void invalid_mem_exit( const void *, const char * );

void error( const char * );
void error_exit( const char * );

#endif
