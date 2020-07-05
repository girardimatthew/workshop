CC=g++
CFLAGS=-I.
DEPS = Student_info.h extract_fails.h fgrade.h grade.h median.h 
OBJ = main.o fgrade.o Student_info.o extract_fails.o grade.o median.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ex5-6: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)