CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o fgrade.o median.o average.o grade.o Student_info.o extract_fails.o

all: ch6.2-comparing-grading-schemes

ch6.2-comparing-grading-schemes: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.2-comparing-grading-schemes

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o