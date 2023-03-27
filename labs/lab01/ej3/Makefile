CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) main.o array_helpers.o -o reader.output

clean:
	@rm -f *.o
	@rm -f *.output
