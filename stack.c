/*
** Header for COMP20007 Assignment 1
** Geordie Wicks 185828
** With thanks to stackoverflow for the wealth of information available
** and Jason Holden, for his general sudo code tips
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10000  /* maximum elements in size */

typedef struct {
    void **A;   // the allocated array of void * pointers, [0..size-1]
    int size;   // the size of A
    int top;    // the index of the current top of the stack
} Stack;



Stack *stack_new()                      // create a new, empty stack
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->A = (void **)malloc(sizeof(void *) * MAX_STACK_SIZE);
	s->size = 0;
	s->top = -1;
	return s;
}

void stack_push(Stack *s, void *item) // push item onto stack s
{  
	

	s->top++;
	s->A[s->top] = item;
	s->size++;
}

void  *stack_pop(Stack *s)              // pop item from stack s
{
	void* item = s->A[s->top];
	s->top--;
	s->size--;
	return item;
}

int    stack_isEmpty(Stack *s)          // return 1 if stack s is empty, else 0
{
	if (s->size == 0)
	{
		return 1;
	}
	return 0;
}

void   stack_print(Stack *s, void(printFn)(void *)) // print whole stack
{
	int i;
	for (i = 0; i < s->size; i++)
	{
		printFn(s->A[i]);	
	}
}
