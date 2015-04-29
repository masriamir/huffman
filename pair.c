#include "pair.h"

pair new_pair( const char c, const int freq ) {
    pair p;

    p.c = c;
    p.freq = freq;

    return p;
}
