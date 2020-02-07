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
    oStack.top = NULL;
    oStack.num_of_nodes = 0u;

    for(i = 1; i <= STACK_SIZE; i++)
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
    inv_push = STACK_SIZE + 1;
    eRet = stack_push(inv_push, &oStack);
    if(eRet == STACK_FULL)
    {
        printf("\n\rSTACK> Pass: Reported full.");
    }
    else
    {
        printf("\n\rSTACK> Fail: Failed to report full.");
    }
	
	eRet = STACK_PASS;
    for(i = 1; i <= STACK_SIZE; i++)
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
        printf("\n\rSTACK> Pass: Reported Empty.");
    }
    else
    {
        printf("\n\rSTACK> Fail: Failed to report empty.");
    }

return(0);
}
