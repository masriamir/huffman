#ifndef CODE_H
#define CODE_H

#define MAX_CODE_LEN 64

typedef struct code_t {
    char c;
    char bin[MAX_CODE_LEN];
} code;

code new_code( const char, const char * );

#endif
