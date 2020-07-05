CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o

all: ex5-11

ex5-11: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex5-11

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o