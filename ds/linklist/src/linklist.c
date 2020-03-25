#include "linklist.h"

LINKLIST_RET linklist_init(struct linklist *pLinklist, unsigned int size)
{
	pLinklist->first = NULL;
	pLinklist->num_of_nodes = 0;
	pLinklist->size = LINKLIST_SIZE;
return(LINKLIST_PASS);
}

LINKLIST_RET linklist_append(struct linklist *pLinklist, int nData)
{
	LINKLIST_RET eRet = LINKLIST_PASS;
	struct node *temp, *trv;

	if(pLinklist->num_of_nodes >= pLinklist->size)
	{
		eRet = LINKLIST_FULL;
	}
	else
	{
		temp = malloc(sizeof(struct node));
		temp->data = nData;
		temp->link = NULL;
		pLinklist->num_of_nodes++;
	}

	if(LINKLIST_PASS == eRet)
	{
		if(pLinklist->first == NULL)
		{
			pLinklist->first = temp;
		}
		else
		{
			trv = pLinklist->first;
			while(trv->link != NULL)
			{
				trv = trv->link;
			}
			trv->link = temp;	
		}
	}
return(eRet); 
}

LINKLIST_RET linklist_addAtBeg(struct linklist *pLinklist, int nData)
{
	LINKLIST_RET eRet = LINKLIST_PASS;
	struct node *temp;

	if(pLinklist->num_of_nodes >= pLinklist->size)
	{
		eRet = LINKLIST_FULL;
	}
	else
	{
		temp = malloc(sizeof(struct node));
		temp->data = nData;
		temp->link = pLinklist->first;
		pLinklist->first = temp;
		pLinklist->num_of_nodes++;
	}
return(eRet);
}

LINKLIST_RET linklist_addAfter(struct linklist *pLinklist, int nData, int nPos)
{
	LINKLIST_RET eRet = LINKLIST_PASS;
	struct node *temp, *trv;
	int i;
	
	if(pLinklist->num_of_nodes >= pLinklist->size)
	{
		eRet = LINKLIST_FULL;
	}
	else
	{
		temp = malloc(sizeof(struct node));
		temp->data = nData;
		pLinklist->num_of_nodes++;
	}
	if(eRet == LINKLIST_PASS)
	{
		trv = pLinklist->first;
		for(i = 0; i < nPos; i++)
		{
			trv = trv->link;	
		}
		temp->link = trv->link;
		trv->link = temp;
	}
return(eRet);
}

LINKLIST_RET linklist_delete(struct linklist *pLinklist, int nData)
{
	LINKLIST_RET eRet = LINKLIST_PASS;
	struct node *trv, *prev;
	int i;
	if(pLinklist->first == NULL)
	{
		eRet = LINKLIST_EMPTY;
	}
	else
	{
		trv = pLinklist->first;
		pLinklist->num_of_nodes--;
	}
	if(eRet == LINKLIST_PASS)
	{
		for(i = 0; i < pLinklist->num_of_nodes; i++)
		{
			if(trv->data == nData)
			{
				if(pLinklist->first == trv)
				{
					pLinklist->first = trv->link;
				}
				else
				{
					prev->link = trv->link;
				}
				free(trv);
				break;
			}
			else
			{
				prev = trv;
				trv = trv->link;
			}	
		}
	}
return(eRet);
}

LINKLIST_RET linklist_display(struct linklist *pLinklist)
{
	LINKLIST_RET eRet = LINKLIST_PASS;
	struct node *trv;
	int i, nIdx = 0;
	if(pLinklist->num_of_nodes = 0)
	{
		eRet = LINKLIST_EMPTY;
	}
	else
	{
		trv = pLinklist->first;	
	}
	if(eRet == LINKLIST_PASS)
	{
		#if 1
		while(trv != NULL)
		{
			printf("\n\rLINKLIST> Data[%d] = %d",nIdx++,trv->data);
			trv = trv->link;
		}
		#else
		for(i = 0; i < pLinklist->num_of_nodes; i++)
		{
			printf("\n\rLINKLIST> Data[%d] = %d",i,trv->data);
			trv = trv->link;
		}	
		#endif
	}
return(eRet);
}

