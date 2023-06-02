CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = main.c set.c set_helpers.c
OBJECTS = $(SOURCES:.c=.o)
TESTFILES = $(shell ls input)
TARGET = setload

.PHONY: clean

all: $(TARGET)

test: $(TARGET) $(TESTFILES)

%.in:
	@echo "\e[1;37mTesting $*...\e[0m\e[0;37m\n"
	valgrind --leak-check=full ./$(TARGET) input/$*.in
	@echo "\n\n"


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
