#include <string.h>

#include "mem_util.h"
#include "dictionary.h"
#include "tree.h"

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
