#include "dlinklist.h"

DLINKLIST_RET dlinklist_init(struct dlinklist *pDLinklist, unsigned int size)
{
	pDLinklist->head = NULL;
	pDLinklist->num_of_nodes = 0;
	pDLinklist->size = size;
return(DLINKLIST_PASS);
}

DLINKLIST_RET dlinklist_append(struct dlinklist *pDLinklist, int nData)
{
	DLINKLIST_RET eRet = DLINKLIST_PASS;
	struct node *temp, *trv;

	if(pDLinklist->num_of_nodes >= pDLinklist->size)
	{	
		eRet = DLINKLIST_FULL;
	}
	else
	{
		pDLinklist->num_of_nodes++;
		temp = malloc(sizeof(struct node));
		temp->data = nData;
		temp->end = NULL;
		
		if(pDLinklist->head == NULL)
		{
			temp->start = NULL;
			pDLinklist->head = temp;
		}
		else
		{
			trv = pDLinklist->head;
			while(trv->end != NULL)
			{
				trv = trv->end;
			}
			temp->start = trv;
			trv->end = temp;
		}
	}
return(eRet);
} 

DLINKLIST_RET dlinklist_addAtBeg(struct dlinklist *pDLinklist, int nData)
{
	DLINKLIST_RET eRet = DLINKLIST_PASS;
	struct node *temp;

	if(pDLinklist->num_of_nodes >= DLINKLIST_SIZE)
	{
		eRet = DLINKLIST_FULL;
	}
	else
	{
		pDLinklist->num_of_nodes++;
		temp = malloc(sizeof(struct node));
		temp->start = NULL;
		temp->data = nData;	
		if(pDLinklist->head == NULL)
		{
			temp->end = NULL;
			pDLinklist->head = temp;
		}
		else
		{	
			pDLinklist->head->start = temp;
			temp->end = pDLinklist->head;
			pDLinklist->head = temp;
		}
	}	
return(eRet);
}

DLINKLIST_RET dlinklist_addAfter(struct dlinklist *pDLinklist, int nData, int nPos)
{
	DLINKLIST_RET eRet = DLINKLIST_PASS;
	struct node *temp, *trv;
	int i;

	if(pDLinklist->num_of_nodes >= DLINKLIST_SIZE)
	{
		eRet = DLINKLIST_FULL;
	}
	else if(nPos >= (pDLinklist->num_of_nodes - 1))
	{
		eRet = DLINKLIST_EMPTY;
	}
	else
	{
		pDLinklist->num_of_nodes++;
		temp = malloc(sizeof(struct node));
		temp->data = nData;
		if(pDLinklist->head == NULL)
		{
			temp->start = NULL;
			temp->end = NULL;
			pDLinklist->head = temp;
		}
		else
		{
			trv = pDLinklist->head;
			for(i = 0; i < nPos ; i++)
			{
				trv = trv->end;
			}
			trv->end->start = temp;
			temp->end = trv->end;
			temp->start = trv;
			trv->end = temp;
		}		
	}
return(eRet);
}

DLINKLIST_RET dlinklist_delete(struct dlinklist *pDLinklist, int nData)
{
	DLINKLIST_RET eRet = DLINKLIST_PASS;
	struct node *trv;
	
	if(pDLinklist->head == NULL)
	{
		eRet = DLINKLIST_EMPTY;
	}	
	else
	{
		trv = pDLinklist->head;
		while(trv != NULL)
		{
			if(trv->data == nData)
			{
				if(trv == pDLinklist->head)
				{
					pDLinklist->head = pDLinklist->head->end;
				}
				else if (trv->end == NULL)
				{
					trv->start->end = NULL;
				}
				else
				{
					trv->start->end = trv->end;
					trv->end->start = trv->start;
				}
				free(trv);
				pDLinklist->num_of_nodes--;
				break;
			}
			else
			{
				trv = trv->end;
			}
		}		
	}
return(eRet);
}

DLINKLIST_RET dlinklist_display(struct dlinklist *pDLinklist)
{
	DLINKLIST_RET eRet = DLINKLIST_PASS;
	struct node *trv;
	int i, nIdx = 0;
	
	if(pDLinklist->head == NULL)
	{
		eRet = DLINKLIST_EMPTY;
	}
	else
	{	
		trv = pDLinklist->head;
		while(trv != NULL)
		{
			printf("\n\rDLINKLIST> Data[%d] = %d", nIdx++, trv->data);
			trv = trv->end;
		}
	}
return(eRet);
}
