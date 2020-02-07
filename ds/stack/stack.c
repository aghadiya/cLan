#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK_RET stack_push(int data, struct stack *pStack)
{
    STACK_RET eRet = STACK_PASS;
    struct node *temp;
    if(pStack->num_of_nodes >= STACK_SIZE)
    {
        eRet = STACK_FULL;
    }
    else
    {
        temp = malloc (sizeof(struct node));
        temp->data = data;
        temp->link = pStack->top;
        pStack->top = temp;
        pStack->num_of_nodes++;
    }
return(eRet);
}

STACK_RET stack_pop(int *pData, struct stack *pStack)
{
    STACK_RET eRet = STACK_PASS;
    struct node *temp;

    if(pStack->top == NULL)
    {
        eRet = STACK_EMPTY;
    }
    else
    {
        temp = pStack->top;
        *pData = pStack->top->data;
        pStack->top = pStack->top->link;
        pStack->num_of_nodes--;
        free(temp);
    }
return(eRet);
}

