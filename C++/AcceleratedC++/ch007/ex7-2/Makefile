CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o median.o grade.o Student_info.o

file_name = $(shell basename $(CURDIR))

all: $(file_name)

$(file_name): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(file_name)

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf ${file_name}

test:
	@echo $(notdir $(CURDIR))
	@echo $(CURDIR)
	@echo $(shell basename $(CURDIR))