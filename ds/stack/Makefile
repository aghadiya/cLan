CC=gcc
CFLAGS=-I.
DEPS=stack.h
OBJ=test_stack.o stack.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stackmake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o 
	rm stackmake
