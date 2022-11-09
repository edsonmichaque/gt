CC = gcc
CFLAGS = -Wall

.PHONY: build
build: build/gt

build/gt.o: src/bin/gt.c
	$(CC) $(CFLAGS) -o $@ -c $^

build/gt: build/gt.o
	$(CC) -o $@ $^

clean:
	rm build/*
