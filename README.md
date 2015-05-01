# huffman

## Overview

Huffman encoding/decoding library written in C.

## Compiling

Simply run `make` and both static and dynamic libraries will be generated. Make sure to `#include "huffman.h"` in your project and set your `LD_LIBRARY_PATH` environment variable.

## Example

Huffman-encode a string:
    char *encoded = huffman_encode( "my plain string" );

You must free the pointer when you are done.
    free( encoded );

## Features

* encode strings (output will not include the tree)

## TODO

* decode strings
* encode/decode from files
* read/write tree and encoded data from/to file
* user controlled output buffer size
* small optimizations
* `make install` directive
