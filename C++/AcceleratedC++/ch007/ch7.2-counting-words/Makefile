CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o

file_name = ch7.2-counting-words

all: $(file_name)

$(file_name): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(file_name)

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o