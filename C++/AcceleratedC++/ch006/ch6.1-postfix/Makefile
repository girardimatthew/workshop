CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o

all: ch6.1-postfix

ch6.1-postfix: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.1-postfix

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o