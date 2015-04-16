#ifndef WF_H
#define WF_H

#define ASCII_LENGTH 256
#define ELEMENTS( x ) ( sizeof( x ) / sizeof( x[0] ) )

typedef struct wf_item {
    char c;
    int freq;
} wf_item;

/* allocation */
wf_item *word_frequency( const char * );
void free_wf_items( wf_item ** );

/* util */
unsigned int get_num_unique_chars( const int *, const size_t );
int compare_wf_item( const void *, const void * );
void sort_wf_items( wf_item **, const size_t );
void print_wf_item( const wf_item );
void print_wf_items( const wf_item * );

#endif
