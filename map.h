#ifndef WF_H
#define WF_H

#define ASCII_LENGTH 256
#define ELEMENTS( x ) ( sizeof( x ) / sizeof( x[0] ) )

typedef struct cf_pair_t {
    char c;
    int freq;
} cf_pair;

/* allocation */
cf_pair *word_frequency( const char * );
void free_cf_pairs( cf_pair ** );

/* util */
unsigned int get_num_unique_chars( const int *, const size_t );
int compare_cf_pair( const void *, const void * );
void sort_cf_pairs( cf_pair **, const size_t );
void print_cf_pair( const cf_pair );
void print_cf_pairs( const cf_pair * );

#endif
