#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "code.h"

code new_code( const char c, const char *bin ) {
    code cd;

    cd.c = c;
    size_t len = strlen( bin );
    if ( len > MAX_CODE_LEN ) {
        len = MAX_CODE_LEN;
    }
    strncpy( cd.bin, bin, len );
    cd.bin[len] = '\0';

    return cd;
}

void print_code( const code cd ) {
    printf( "code[c = %c, bin = %s]\n", cd.c, cd.bin );
}