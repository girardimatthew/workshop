# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -Wall

# define the C source files
# SRC = ternaryCondition

# define the executable file 
MAIN = output

all:	$(MAIN)
		@echo	Simple compiler named $(MAIN) has been compiled

$(MAIN): $(SRC).c
	$(CC) $(CFLAGS) -o $(MAIN).o $(SRC).c

clean:
	$(RM) $(MAIN).o
