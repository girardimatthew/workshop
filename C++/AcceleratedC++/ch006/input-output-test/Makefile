CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o 

all: test

test: $(OBJECTS)
	$(CC) $(OBJECTS) -o test

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o