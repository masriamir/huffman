CC = gcc
CFLAGS += -Wall -Wextra -Werror -pedantic-errors -g -O2 -std=c99 -fPIC
LDFLAGS = -shared

src = $(wildcard src/*.c)
obj = $(src:.c=.o)

STATIC_LIB = libhuffman.a
DYNAMIC_LIB = libhuffman.so

.PHONY: all
all: $(STATIC_LIB) $(DYNAMIC_LIB)

$(STATIC_LIB): $(obj)
	ar vrcs $@ $^

$(DYNAMIC_LIB): $(obj)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(STATIC_LIB) $(DYNAMIC_LIB) $(obj)
