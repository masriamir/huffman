#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "mem_util.h"

void *new_mem( const size_t size ) {
    void *ptr = malloc( size );
    check_mem_exit( ptr, "could not allocate memory" );
    return ptr;
}

void free_mem( void *ptr ) {
    if ( ptr == NULL ) {
        return;
    } else {
        free( ptr );
        ptr = NULL;
    }
}

bool check_mem( const void *ptr ) {
    if ( ptr == NULL ) {
        return false;
    }
    return true;
}

bool check_mem_err( const void *ptr, const char *str ) {
    if ( !check_mem( ptr ) ) {
        fprintf( stderr, "Error: %s\n", str );
        return false;
    }
    return true;
}

void check_mem_exit( const void *ptr, const char *str ) {
    if ( !check_mem_err( ptr, str ) ) {
        exit( EXIT_FAILURE );
    }
}
