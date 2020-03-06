#ifndef STACK_H
#define STACK_H

#define STACK_SIZE    (10u)
struct node
{
    /* Data to be stored in stack */
    int data; 
    /* Link to the previous node */                  
    struct node *link;          
};

struct stack
{
    /* Stack pointer (top of stack) */
    struct node *top; 
    /* Number of nodes in stack */          
    unsigned int num_of_nodes;  
	/* Stack size */
	unsigned int size;
};

typedef enum
{
    /* Stack operation successfull. */
    STACK_PASS,
    /* Stack is empty. */                 
    STACK_EMPTY,
    /* Stack is full. */
    STACK_FULL,
    /* Invalid parameter.*/
    STACK_INV_PARAM
}STACK_RET;

STACK_RET stack_init(struct stack *pStack, unsigned int nSize);
STACK_RET stack_push(int data, struct stack *pStack);
STACK_RET stack_pop(int *pData, struct stack *pStack);
#endif /* STACK_H */
