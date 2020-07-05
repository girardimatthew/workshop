CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o split.o

all: ch6.1.2-palindromes

ch6.1.2-palindromes: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.1.2-palindromes

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o