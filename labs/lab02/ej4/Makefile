CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g -no-pie

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c sort.c
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) main.o sort.o sort_helpers.o array_helpers.o -o reader.output

clean:
	@rm -f main.o
	@rm -f sort.o
	@rm -f *.output
