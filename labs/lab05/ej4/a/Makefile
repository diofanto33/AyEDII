CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c strfuncs.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) strfuncs.o main.o -o reader.output

clean:
	@rm -f main.o
	@rm -f strfuncs.o
	@rm -f *.output
