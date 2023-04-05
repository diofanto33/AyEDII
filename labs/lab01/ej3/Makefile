CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

all: clean reader.out

%.out: ;
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) main.o array_helpers.o -o reader.out

clean:
	@rm -f *.o
	@rm -f *.out
