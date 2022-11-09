CC = gcc
CFLAGS = -Wall
OBJ = build/usage.o build/gt-ls.o build/gt-rm.o build/gt.o
DEPS = src/bin/gt.h src/bin/usage.h

.PHONY: build
build: build/gt

build/%.o: src/bin/%.c $(DEPS)
	@$(CC) $(CFLAGS) -o $@ -c $<

build/gt: $(OBJ)
	@$(CC) -o $@ $^

clean:
	@rm build/*
