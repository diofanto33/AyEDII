CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c weather.c
	$(CC) $(CFLAGS) -c weather_utils.c
	$(CC) $(CFLAGS) array_helpers.o weather.o weather_utils.o main.o -o reader.output

clean:
	@rm -f main.o
	@rm -f array_helpers.o
	@rm -f weather.o
	@rm -f weather_utils.o
	@rm -f *.output
