CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) array_helpers.o main.o -o reader.output

clean:
	@rm -f main.o
	@rm -f array_helpers.o
	@rm -f *.output
