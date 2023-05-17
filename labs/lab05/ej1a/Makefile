CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c test.c
	$(CC) $(CFLAGS) -c stack.c
	$(CC) $(CFLAGS) stack.o test.o -o reader.output

clean:
	@rm -f test.o
	@rm -f stack.o
	@rm -f *.output
