#include "queue.h"

QUEUE_RET queue_init(struct queue *pQueue, unsigned int nSize)
{
	pQueue->front = NULL;
	pQueue->rear = NULL;
	pQueue->num_of_nodes = 0;
	pQueue->size = nSize;
return(QUEUE_PASS);
}

QUEUE_RET enqueue(int data, struct queue *pQueue)
{
	QUEUE_RET eRet = QUEUE_PASS;
	struct node *temp;
	
	if(QUEUE_SIZE <= pQueue->num_of_nodes)
	{
		eRet = QUEUE_FULL;
	}
	else
	{
		temp = malloc (sizeof(struct node));
	}
	
	if(eRet == QUEUE_PASS)
	{
		temp->data = data;
		temp->link = NULL;
		pQueue->num_of_nodes++;
		if(pQueue->front == NULL)
		{
			pQueue->front = temp;
			pQueue->rear = temp;
		}
		else
		{
			pQueue->rear->link = temp;
			pQueue->rear = temp;
		}
	}
return(eRet);
}

QUEUE_RET dequeue(int *pData, struct queue *pQueue)
{
	QUEUE_RET eRet = QUEUE_PASS;
	struct node *temp;

	if(pQueue->num_of_nodes == 0)
	{
		eRet = QUEUE_EMPTY;
	}
	else
	{
		pQueue->num_of_nodes--;
	}
	if(eRet == QUEUE_PASS)
	{
		temp = pQueue->front;
		pQueue->front = pQueue->front->link;
		*pData = temp->data;
		/*free(temp);*/
	}
return(eRet);
}

