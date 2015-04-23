#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "huffman.h"
#include "map.h"
#include "node.h"
#include "code.h"

#define MAX_BUF_LEN 256

typedef struct dictionary_t {
    code *arr;
    size_t size;
    size_t cap;
} dictionary;

dictionary *build_dictionary( const node *, const size_t );
void build( dictionary *, const node *, char * );
dictionary *new_dictionary( const size_t );
void free_dictionary( dictionary * );
char *get_code( const dictionary *, const char );
char get_char( const dictionary *, const char * );
void print_dictionary( const dictionary );

#endif
