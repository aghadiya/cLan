CC = gcc
IDIR=../inc
CFLAGS=-I$(IDIR)
DEPS=linklist.h
OBJS=test_linklist.o linklist.o

%.o: %.c $(DEPS)
	$(CC) -g $@ $< $(CFLAGS)

linklist_app: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm linklist_app
