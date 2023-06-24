CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = tape.c
TESTERS = insertl insertr middler middlel copy
OBJECTS = $(SOURCES:.c=.o)

.PHONY: clean

all: insertl

insertl:  insertl.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $< $(LFLAGS) $(LIBS)

insertr:  insertr.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $< $(LFLAGS) $(LIBS)

middlel:  middlel.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $< $(LFLAGS) $(LIBS)

middler:  middler.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $< $(LFLAGS) $(LIBS)

copy:  copy.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $< $(LFLAGS) $(LIBS)

test: test-insertl test-insertr test-middlel test-middler test-copy

test-insertl: test-insertl-1 test-insertl-2 test-insertl-3

test-insertl-1: insertl
	./insertl hola

test-insertl-2: insertl
	./insertl hola 0

test-insertl-3: insertl
	./insertl hola 3

test-insertr: test-insertr-1 test-insertr-2 test-insertr-3

test-insertr-1: insertr
	./insertr hola

test-insertr-2: insertr
	./insertr hola 0

test-insertr-3: insertr
	./insertr hola 3

test-middlel: middlel
	./middlel abcd 2 123

test-middler: middler
	./middler abcd 2 123

test-copy: test-copy-1 test-copy-2

test-copy-1: copy
	./copy hola

test-copy-2: copy
	./copy hola 123

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o  $(TESTERS)

