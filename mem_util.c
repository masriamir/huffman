#include <stdlib.h>
#include <stdio.h>

#include "huffman.h"
#include "mem_util.h"

void *new_mem( const size_t size ) {
    void *ptr = malloc( size );
    invalid_mem_exit( ptr, EX_MEM );
    return ptr;
}

void *re_mem( void *ptr, const size_t size ) {
    void *tmp = realloc( ptr, size );
    invalid_mem_exit( tmp, EX_MEM );
    return tmp;
}

void free_mem( void *ptr ) {
    if ( ptr == NULL ) {
        return;
    } else {
        free( ptr );
        ptr = NULL;
    }
}

bool invalid_mem( const void *ptr ) {
    if ( ptr == NULL ) {
        return true;
    }
    return false;
}

bool invalid_mem_err( const void *ptr, const char *str ) {
    if ( invalid_mem( ptr ) ) {
        error( str );
        return true;
    }
    return false;
}

void invalid_mem_exit( const void *ptr, const char *str ) {
    if ( invalid_mem_err( ptr, str ) ) {
        exit( EXIT_FAILURE );
    }
}

void error( const char *str ) {
    fprintf( stderr, "Error: %s\n", str );
}

void error_exit( const char *str ) {
    error( str );
    exit( EXIT_FAILURE );
}
