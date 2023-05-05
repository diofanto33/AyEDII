CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c bakery_product.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) array_helpers.o bakery_product.o main.o -o reader.out

clean:
	@rm -f main.o
	@rm -f array_helpers.o
	@rm -f bakery_product.o
	@rm -f *.out
