CC=gcc
IDIR=../inc
CFLAGS=-I$(IDIR)
DEPS=stack.h
OBJ=test_stack.o stack.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stack_app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o 
	rm stack_app
