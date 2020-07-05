CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o

all: ex5-10

ex5-10: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex5-10

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o