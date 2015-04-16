#ifndef NODE_H
#define NODE_H

typedef struct node_t node;

struct node_t {
    char c;
    int freq;
    node *left;
    node *right;
};

/* allocation */
node new_node( const char, const int, node *, node * );
//void free_node( node ** );

/* util */
void print_node( node );

#endif
