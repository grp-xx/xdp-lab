all: $(patsubst %.c,%.o,$(wildcard *.c))

%.o: %.c
	clang -O2 -g -Wall -target bpf -c $^ -o $@
#	pahole -J $@

%.o: %.cpp
	clang++ -O2  -Wall -c $^ -o $@

.PHONY: clean
clean:
	rm -f *.o
