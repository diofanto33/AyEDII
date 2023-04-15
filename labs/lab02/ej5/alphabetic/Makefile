CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

CFLAGSO = -Wall -Wextra -std=c99

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c sort.c
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c fixstring.c
	$(CC) $(CFLAGS) -c sort_helpers.c
	$(CC) $(CFLAGSO) array_helpers.o fixstring.o main.o sort.o sort_helpers.o -o reader.output

clean:
	@rm -f main.o
	@rm -f sort.o
	@rm -f array_helpers.o
	@rm -f fixstring.o
	@rm -f sort_helpers.o
	@rm -f *.output
