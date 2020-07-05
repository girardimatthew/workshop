CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o furls.o prettyprint.o

all: ch6.1.3-findingURLs

ch6.1.3-findingURLs: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.1.3-findingURLs

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o