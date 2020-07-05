CC = g++
CFLAGS = -c -Wall -std=c++11
OBJECTS = main.o fgrade.o median.o grade.o Student_info.o extract_fails.o

all: ch6.3-classyfing-students

ch6.3-classyfing-students: $(OBJECTS)
	$(CC) $(OBJECTS) -o ch6.3-classyfing-students

%.o: %.cpp
	$(CC) $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf *.o