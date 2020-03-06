#include <stdio.h>
#include "stack.h"

int main (void)
{
    STACK_RET eRet = STACK_PASS;
    int i;
    int inv_push;
	int pop_data = 0;
    struct stack oStack;
    /* printf("\n\rSTACK> Stack Verification!!!"); */
    eRet = stack_init(&oStack, STACK_SIZE);
    if(eRet != STACK_PASS)
    {
        printf("\n\rSTACK> Stack initialization failed.");
    }
    else
    {
        printf("\n\rSTACK> Stack initialization passed.");
    }

    for(i = 1; i <= oStack.size; i++)
    {
        eRet |= stack_push(i, &oStack);
		if(eRet == STACK_PASS)
		{
			printf("\n\rSTACK> Pushed %d",i);
		}
    }
    if(eRet != STACK_PASS)
    {
        printf("\n\rSTACK> Push failed.");
    }
    else
    {
        printf("\n\rSTACK> Push passed.");
    }
    inv_push = oStack.size + 1;
    eRet = stack_push(inv_push, &oStack);
    if(eRet == STACK_FULL)
    {
        printf("\n\rSTACK> Pass: Reported stack overflow.");
    }
    else
    {
        printf("\n\rSTACK> Fail: Failed to report stack overflow.");
    }
	
	eRet = STACK_PASS;
    for(i = 0; i < oStack.size; i++)
    {
        eRet |= stack_pop(&pop_data, &oStack);
		if(eRet == STACK_PASS)
		{
			printf("\n\rSTACK> Popped %d",pop_data);
		}
    }
    if(eRet != STACK_PASS)
    {
        printf("\n\rSTACK> Pop failed.");
    }
    else
    {
        printf("\n\rSTACK> Pop passed.");
    }

    eRet = stack_pop(&pop_data, &oStack);
    if(eRet == STACK_EMPTY)
    {
        printf("\n\rSTACK> Pass: Reported stack underflow.");
    }
    else
    {
        printf("\n\rSTACK> Fail: Failed to report stack underflow.");
    }


return(0);
}
