CC = g++
CFLAGS = -c -Wall -std=c++17
OBJECTS = main.o 

file_name = $(shell basename $(CURDIR))

all: $(file_name)

$(file_name): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(file_name).out

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	@rm -rf *.o *.out

test:
	@echo $(file_name)
	@echo $(notdir $(CURDIR))
	@echo $(CURDIR)
	@echo $(shell basename $(CURDIR))