CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c fixstring.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) main.o fixstring.o -o program.output

clean:
	@rm -f *.o
	@rm -f *.output
