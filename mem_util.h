#ifndef MEM_UTIL_H
#define MEM_UTIL_H

#include <stdbool.h>

void *new_mem( const size_t );
void free_mem( void * );

bool check_mem( const void * );
bool check_mem_err( const void *, const char * );
void check_mem_exit( const void *, const char * );

#endif
