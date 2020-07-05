CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o frame.o hcat.o vcat.o width.o

all: ex5-8

ex5-8: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex5-8

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o