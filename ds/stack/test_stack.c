#include <stdio.h>
#include "stack.h"

int main (void)
{
    STACK_RET eRet = STACK_PASS;
    int i;
    int inv_push;
    struct stack oStack;
    /* printf("\n\rSTACK> Stack Verification!!!"); */
    oStack.top = NULL;
    oStack.num_of_nodes = 0u;

    for(i = 1; i <= STACK_SIZE; i++)
    {
        eRet |= stack_push(i, &oStack);
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

return(0);
}
