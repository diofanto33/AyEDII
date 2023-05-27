CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c queue.c 
	$(CC) $(CFLAGS) -c queue_helpers.c 
	$(CC) $(CFLAGS) -c main.c 
	$(CC) $(CFLAGS) queue.o queue_helpers.o main.o -o reader.output

clean:
	@rm -f main.o
	@rm -f queue_helpers.o
	@rm -f queue.o 
	@rm -f *.output
