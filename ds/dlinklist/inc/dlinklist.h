#ifndef DLINKLIST_H
#define DLINKLIST_H

#include<stdio.h>
#include<stdlib.h>

#define DLINKLIST_SIZE		(10u)

struct node
{
	struct node *start;
	int data;
	struct node *end;
};

struct dlinklist
{
	struct node *head;
	unsigned int num_of_nodes;
	unsigned int size;
};

typedef enum
{
	DLINKLIST_PASS,
	DLINKLIST_FULL,
	DLINKLIST_EMPTY,
}DLINKLIST_RET;

DLINKLIST_RET dlinklist_init(struct dlinklist *pDLinklist, unsigned int size);

DLINKLIST_RET dlinklist_append(struct dlinklist *pDLinklist, int nData);
DLINKLIST_RET dlinklist_addAtBeg(struct dlinklist *pDLinklist, int nData);
DLINKLIST_RET dlinklist_addAfter(struct dlinklist *pDLinklist, int nData, int nPos);
DLINKLIST_RET dlinklist_delete(struct dlinklist *pDLinklist, int nData);

DLINKLIST_RET dlinklist_display(struct dlinklist *pDLinklist);

#endif /* #ifndef CIR_LINKLIST_H */
