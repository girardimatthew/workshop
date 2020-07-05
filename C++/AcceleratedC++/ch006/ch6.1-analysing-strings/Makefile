CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o width.o frame.o hcat.o vcat.o

all: ch6.1-analysing-strings

ch6.1-analysing-strings: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.1-analysing-strings

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o