CC = g++
CFLAGS = -c -Wall -std=c++17
OBJECTS = main.o fgrade.o median.o average.o grade.o Student_info.o extract_fails.o

file_name = $(shell basename $(CURDIR))

all: $(file_name)

$(file_name): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(file_name).out

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	@ls *.o *.out
	@rm -rf *.o *.out

test:
	@echo $(file_name)
	@echo $(notdir $(CURDIR))
	@echo $(CURDIR)
	@echo $(shell basename $(CURDIR))