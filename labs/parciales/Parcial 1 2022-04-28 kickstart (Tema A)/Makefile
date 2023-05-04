CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c flight.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) array_helpers.o flight.o main.o -o reader.out

clean:
	@rm -f main.o
	@rm -f array_helpers.o
	@rm -f flight.o
	@rm -f *.out
