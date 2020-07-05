CC=g++
CFLAGS=-I.
DEPS =
OBJ = main.o split.o frame.o hcat.o vcat.o width.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ex5-7: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o