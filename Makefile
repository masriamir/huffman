src = $(wildcard *.c)
obj = $(src:.c=.o)

CFLAGS+=-W -Wall -pedantic-errors -g -std=c99 -fPIC
LDFLAGS=-shared

out: $(obj)
	$(CC) -o $@ $^ $(CFLAGS)

libhuffman.a: $(obj)
	ar rcs $@ $^

libhuffman.so: $(obj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) out
