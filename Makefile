CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -g

twecho: twecho.o

twecho.o: twecho.c

.PHONY: clean
clean: 
	rm -f *.o twecho

.PHONY: all
all: clean twecho