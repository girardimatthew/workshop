CC = g++
CFLAGS = -c -Wall -std=c++17
OBJECTS = main.o fgrade.o median.o average.o grade.o Student_info.o extract.o

all: ex6-9

ex6-9: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex6-9

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o