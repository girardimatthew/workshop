CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o 

all: ch6.1.1-split

ch6.1.1-split: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.1.1-split

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o