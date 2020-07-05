CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o fgrade.o median.o average.o grade.o Student_info.o extract_fails.o

all: ex6-5

ex6-5: $(OBJECTS)
	$(CC) $(OBJECTS) -o ex6-5

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o