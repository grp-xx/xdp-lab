all: $(patsubst %.c,%.o,$(wildcard *.c))

%.o: %.c
	clang -O2 -g -Wall -target bpf -c $^ -o $@
#	pahole -J $@

.PHONY: clean
clean:
	rm -f *.o