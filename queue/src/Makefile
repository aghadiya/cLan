CC=gcc
IDIR=../inc
CFLAGS=-I$(IDIR)
DEPS=queue.h
OBJS=test_queue.o queue.o

%.o: %.c $(DEPS)
	$(CC) -g $@ $< $(CFLAGS)

queue_app: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm queue_app
