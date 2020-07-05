CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o prettyprint.o

all: ex6-4

ex6-4: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex6-4

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o