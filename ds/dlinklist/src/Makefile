CC = gcc
IDIR=../inc
CFLAGS=-I$(IDIR)
DEPS=dlinklist.h
OBJS=test_dlinklist.o dlinklist.o

%.o: %.c $(DEPS)
	$(CC) -g $@ $< $(CFLAGS)

dlinklist_app: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm dlinklist_app
