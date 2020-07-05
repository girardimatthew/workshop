CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o prettyprint.o

all: ex6-3

ex6-3: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex6-3

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o