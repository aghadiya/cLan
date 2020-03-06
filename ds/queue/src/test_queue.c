#include <stdio.h>
#include "queue.h"
int main (void)
{
	QUEUE_RET eRet = QUEUE_PASS;
	struct queue oQueue;
	int i, inv_enqueue;
	int dequeued_data;
	printf("\n\rQUEUE> Queue verification start!!!");

	eRet = queue_init(&oQueue, QUEUE_SIZE);
	if(QUEUE_PASS != eRet)
	{
		printf("\n\rQUEUE> Queue initialization failed.");
	}
	else
	{
		printf("\n\rQUEUE> Queue initialization passed.");
	}
	
	for(i = 1; i <= oQueue.size; i++)
	{
		eRet |= enqueue(i, &oQueue);
		if(eRet == QUEUE_PASS)
		{
			printf("\n\rQUEUE> Enqueued %d", i);
		}
	}
	inv_enqueue = oQueue.size + 1;
	eRet = enqueue(inv_enqueue, &oQueue);
	if(eRet == QUEUE_FULL)
	{
		printf("\n\rQUEUE> Pass: Reported overflow.");
	}
	else
	{
		printf("\n\rQUEUE> Fail: Failed to report overflow.");
	}
	
	eRet = QUEUE_PASS;
	for(i = 0; i < oQueue.size; i++)
	{
		eRet |= dequeue(&dequeued_data, &oQueue);
		if(eRet == QUEUE_PASS)
		{
			printf("\n\rQUEUE> Dequeued %d", dequeued_data);
		}
	}

	eRet = dequeue(&dequeued_data, &oQueue);
	if(eRet == QUEUE_EMPTY)
	{
		printf("\n\rQUEUE> Pass: Reported underflow.");
	}
	else
	{
		printf("\n\rQUEUE> Fail: Failed to report underflow.");
	}


return(0);
}

