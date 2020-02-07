CC=gcc
CFLAGS=-I.
DEPS=stack.h
OBJ=test_stack.o stack.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stackmake: test_stack.o stack.o
	$(CC) -o stackmake test_stack.o stack.o

clean:
	rm *.o 
	rm stackmake
