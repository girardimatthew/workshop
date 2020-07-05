CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o furls.o prettyprint.o

all: ex6-2

ex6-2: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex6-2

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o