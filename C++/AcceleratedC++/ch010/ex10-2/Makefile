CC = g++
CFLAGS = -c -Wall -std=c++17
OBJECTS = main.o median.o

file_name = $(shell basename $(CURDIR))

all: $(file_name)

$(file_name): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(file_name).out

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	@echo "About to delete .o and .out files"
	@rm -rfv *.o *.out
	@echo "Done!"

test:
	@echo $(file_name)
	@echo $(notdir $(CURDIR))
	@echo $(CURDIR)
	@echo $(shell basename $(CURDIR))