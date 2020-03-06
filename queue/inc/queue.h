#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE		(10u)

struct node
{
	int data;
	struct node *link;
};

struct queue
{
	struct node *front;
	struct node *rear;
	unsigned int num_of_nodes;
	unsigned int size;
};

typedef enum
{
	QUEUE_PASS,
	QUEUE_EMPTY,
	QUEUE_FULL,
}QUEUE_RET;

/*Queue api prototypes. */
QUEUE_RET queue_init(struct queue *pQueue, int nSize);
QUEUE_RET enqueue(int data, struct queue *pQueue);
QUEUE_RET dequeue(int *pData, struct queue *pQueue);
#endif /* QUEUE_H */
