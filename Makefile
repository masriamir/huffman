src = $(wildcard *.c)
obj = $(src:.c=.o)

CFLAGS+=-W -Wall -pedantic-errors -g -std=c99

out: $(obj)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) out
