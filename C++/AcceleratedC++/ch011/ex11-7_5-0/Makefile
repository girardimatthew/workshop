# Define compiler
CXX = g++
CC = g++
# Compiler flags
CFLAGS = -c -Wall -std=c++17
OBJECTS = main.o width.o hcat.o split.o frame.o vcat.o

file_name = $(shell basename $(CURDIR))

all: $(file_name)

$(file_name): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(file_name).out 

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	@rm -rf *.o *.out *.gch

test:
	@echo $(file_name)
	@echo $(notdir $(CURDIR))
	@echo $(CURDIR)
	@echo $(shell basename $(CURDIR))
	@echo $(CC) $(OBJECTS) -o $(file_name).out 