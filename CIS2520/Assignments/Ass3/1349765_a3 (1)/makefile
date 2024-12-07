# Compiler to use
CC = gcc

# Compiler flags (e.g., to show all warnings and enforce C99 standard)
CFLAGS = -Wall -g -std=c99 -pedantic

# Targets for executables
TARGETS = a3q1 a3q2

# Default rule to build all
all: $(TARGETS)


a3q1: a3q1.o a3q1_functions.o
	$(CC) $(CFLAGS) -o a3q1 a3q1.o a3q1_functions.o -lm

a3q2: a3q2.o a3q2_functions.o
	$(CC) $(CFLAGS) -o a3q2 a3q2.o a3q2_functions.o

a3q1.o: a3q1_main.c a3q1_header.h
	$(CC) $(CFLAGS) -c a3q1_main.c -o a3q1.o

a3q1_functions.o: a3q1_functions.c a3q1_header.h
	$(CC) $(CFLAGS) -c a3q1_functions.c

a3q2.o: a3q2_main.c a3q2_header.h
	$(CC) $(CFLAGS) -c a3q2_main.c -o a3q2.o

a3q2_functions.o: a3q2_functions.c a3q2_header.h
	$(CC) $(CFLAGS) -c a3q2_functions.c

clean:
	rm -f *.o 
	rm -f $(TARGETS)