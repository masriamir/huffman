#include <stdlib.h>
#include <string.h>

#include "mem_util.h"
#include "tree.h"
#include "node.h"
#include "queue.h"

//TODO refactor?
node *build_tree( const char *str ) {
    int char_freq[ASCII] = { 0 };
    for ( size_t i = 0; str[i] != '\0'; i++ ) {
        // arr index is ascii value of char
        int ascii = ( int ) str[i];
        char_freq[ascii]++;
    }

    queue q = new_queue( DEF_QUEUE_SZ );
    for ( size_t i = 0; i < ASCII; i++ ) {
        if ( char_freq[i] != 0 ) {
            node *n = new_node( i, char_freq[i], NULL, NULL );
            if ( !offer( &q, n ) ) {
                error_exit( EX_ACCESS );
            }
        }
    }

    while ( q.size > 1 ) {
        // pointers are being reassigned, no need to free them here
        node *left = poll( &q );
        node *right = poll( &q );
        node *root = new_node( '\0', left->freq + right->freq, left, right );
        if ( !offer( &q, root ) ) {
            error_exit( EX_ACCESS );
        }
    }

    node *root = poll( &q );
    free_queue( &q );

    char buf[MAX_CODE_LENGTH] = { 0 };
    encode_tree( root, buf );

    return root;
}

void encode_tree( node *root, char *buf ) {
    if ( is_leaf( root ) ) {
        size_t buf_len = strlen( buf ) + 1;
        root->bits = new_mem( buf_len );
        strncpy( root->bits, buf, buf_len );
    } else {
        strncat( buf, "0", 1 );
        encode_tree( root->left, buf );
        buf[ strlen( buf ) - 1 ] = '\0';
        strncat( buf, "1", 1 );
        encode_tree( root->right, buf );
        buf[ strlen( buf ) - 1 ] = '\0';
    }
}

char *encode( const node *root, const char *str ) {
    size_t size = 0;
    size_t cap = DEF_BUF_SZ;
    char *buf = new_mem( cap * sizeof( *buf ) );
    *buf = '\0';

    for ( size_t i = 0; i < strlen( str ); i++ ) {
        node *n = get_node( root, str[i] );
        invalid_mem_exit( n, EX_ACCESS );
        size_t code_len = strlen( n->bits );

        if ( size + code_len >= cap ) {
            cap += DEF_BUF_SZ;
            buf = re_mem( buf, cap );
        }

        strncat( buf, n->bits, code_len );
        size += code_len;
    }

    return buf;
}

node *get_node( const node *root, const char c ) {
    node *n = ( node * ) root;

    if ( is_leaf( n ) && n->c == c ) {
        return n;
    } else {
        if ( !invalid_mem( n->left ) ) {
            node *left = get_node( n->left, c );
            if ( !invalid_mem( left ) ) {
                return left;
            }
        }
        if ( !invalid_mem( n->right ) ) {
            node *right = get_node( n->right, c );
            if ( !invalid_mem( right ) ) {
                return right;
            }
        }
    }

    return NULL;
}

void free_tree( node *n ) {
    // check needed due to recursive frees
    if ( invalid_mem( n ) ) {
        return;
    }

    free_tree( n->left );
    free_tree( n->right );
    free_node( n );
}
