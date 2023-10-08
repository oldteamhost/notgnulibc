CC = clang
CFLAGS = -Wall -I../src -g -O0 -fPIC
LDFLAGS = -L../build -Wl,-rpath=../build
LDLIBS = -lngulibc -pthread

all: main

main: main.o
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f main main.o

.PHONY: all clean
