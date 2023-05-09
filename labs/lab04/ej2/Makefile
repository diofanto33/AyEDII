CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c counter.c
	$(CC) $(CFLAGS) counter.o main.o -o reader.output

clean:
	@rm -f main.o
	@rm -f counter.o
	@rm -f *.output
