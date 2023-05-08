CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c pair.c
	$(CC) $(CFLAGS) pair.o main.o -o reader.output

clean:
	@rm -f main.o
	@rm -f pair.o
	@rm -f *.output
