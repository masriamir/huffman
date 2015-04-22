#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "map.h"
#include "node.h"

typedef struct code_t {
    char c;
    char *bin;
} code;

typedef struct dictionary_t {
    code **arr;
    size_t size;
    size_t cap;
} dictionary;

code *new_code( const char, char * );
void free_code( code ** );
void print_code( const code * );
dictionary *build_dictionary( const node *, const size_t );
void build( dictionary *, const node *, char * );
dictionary *new_dictionary( const size_t );
void free_dictionary( dictionary ** );
void print_dictionary( const dictionary * );

#endif
