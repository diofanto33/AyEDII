CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c clone_ptr.c
	$(CC) $(CFLAGS) -c clone.c
	$(CC) $(CFLAGS) clone_ptr.o clone.o -o reader.output

clean:
	@rm -f clone.o
	@rm -f clone_ptr.o
	@rm -f *.output
