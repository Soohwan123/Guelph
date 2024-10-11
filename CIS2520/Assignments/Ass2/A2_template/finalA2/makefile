# Compiler to use
CC = gcc

# Compiler flags (e.g., to show all warnings and enforce C99 standard)
CFLAGS = -Wall -g -std=c99 -pedantic


# Targets for executables
TARGETS = a2q1 a2q2

# Default rule to build all
all: $(TARGETS)

# Rule to build the first program (a2q1)
a2q1: q1.o q1_functions.o
	$(CC) $(CFLAGS) -o a2q1 q1.o q1_functions.o

# Rule to build the second program (a2q2)
a2q2: q2.o q2_functions.o
	$(CC) $(CFLAGS) -o a2q2 q2.o q2_functions.o

# Rule to compile q1.c into q1.o
q1.o: q1.c q1.h
	$(CC) $(CFLAGS) -c q1.c

# Rule to compile q1_functions.c into q1_functions.o
q1_functions.o: q1_functions.c q1.h
	$(CC) $(CFLAGS) -c q1_functions.c

# Rule to compile q2.c into q2.o
q2.o: q2.c q2.h
	$(CC) $(CFLAGS) -c q2.c

# Rule to compile q2_functions.c into q2_functions.o
q2_functions.o: q2_functions.c q2.h
	$(CC) $(CFLAGS) -c q2_functions.c

# Rule to clean up (remove object files and executables)
clean:
	rm -f *.o $(TARGETS)