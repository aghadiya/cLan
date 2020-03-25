#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

#define LINKLIST_SIZE	(10)
struct node
{
	int data;
	struct node *link;
};

struct linklist
{
	struct node *first;
	unsigned int num_of_nodes;
	unsigned int size;
};

typedef enum
{
	LINKLIST_PASS,
	LINKLIST_FULL,
	LINKLIST_EMPTY,
}LINKLIST_RET;

LINKLIST_RET linklist_init(struct linklist *pLinklist, unsigned int size);
LINKLIST_RET linklist_append(struct linklist *pLinklist, int nData);
LINKLIST_RET linklist_addAtBeg(struct linklist *pLinklist, int nData);
LINKLIST_RET linklist_addAfter(struct linklist *pLinklist, int nData, int nPos);
LINKLIST_RET linklist_delete(struct linklist *pLinklist, int nData);
LINKLIST_RET linklist_display(struct linklist *pLinklist);

#endif /*LINKLIST_H*/
