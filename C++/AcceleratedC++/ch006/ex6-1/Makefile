CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o width.o frame.o hcat.o vcat.o

all: ex6.1

ex6.1: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex6.1

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o