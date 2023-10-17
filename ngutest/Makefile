CC = clang
CFLAGS = -Wall -I../src -g -O0 -fPIC
LDFLAGS = -L../build -Wl,-rpath=../build
LDLIBS = -lngulibc -pthread

all: main

main: main.o
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
		rm -f main.o

main.o: main.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f main

.PHONY: all clean
