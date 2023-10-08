CC = clang
CFLAGS = -Wall -I../src
LDFLAGS = -L../build
LDLIBS = -lngulibc

all: main

main: main.o
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f main main.o

.PHONY: all clean

