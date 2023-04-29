CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c helpers.c
	$(CC) $(CFLAGS) -c sort.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) helpers.o sort.o main.o -o reader.out

clean:
	@rm -f main.o
	@rm -f helpers.o
	@rm -f sort.o
	@rm -f *.out
