CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o

all: ex5-9

ex5-9: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex5-9

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o