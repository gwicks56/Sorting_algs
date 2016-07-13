/*
** Header for COMP20007 Assignment 1
** Geordie Wicks 185828
** With thanks to stackoverflow for the wealth of information available
** and Jason Holden, for his general sudo code tips
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "partition.h"

/*
  The function implements Quick Sort algorithm by using an implicit Stack
  push (0, n - 1) to stack
  while stack is not empty do
	(left, right) = pop ()
	choose pivot is the element at left index
	k = patition. k is the index in the array that the left elements are less or equal than it
		and the right elements are greater it
	push (left, k - 1)
	push (k + 1, right)
  end while

 

 */
void myQuicksort(void **A, int n, int(cmp)(void *, void*)) {
	
	int k;
	int left;
	int right;	
	int value;
	//create stack
	Stack *stack = stack_new();	


	//push (right, left) = (n - 1, 0) 
	value = n -1;
	stack_push(stack, (void*)value);

	value = 0;
	stack_push(stack, (void*)value);
 
	while (stack_isEmpty(stack) == 0)
	{
		
		//get (left, right)
		left = (int)stack_pop(stack); 
		right = (int)stack_pop(stack); 

		if (right > left){

			k = partition(A, left, right, A[left], cmp);

			if (k - left > right - k)
			{ 
				//push (k-1, left) 
				value = k - 1;
				stack_push(stack, (void*)value);

				value = left;
				stack_push(stack, (void*)value);

				//push (right, k + 1) 
				value = right;
				stack_push(stack, (void*)value);

				value = k + 1;
				stack_push(stack, (void*)value);
			}
			else
			{ 
				//push (right, k + 1) 
				value = right;
				stack_push(stack, (void*)value);

				value = k + 1;
				stack_push(stack, (void*)value);

				//push (k, left) 
				value = k;
				stack_push(stack, (void*)value);

				value = left;
				stack_push(stack, (void*)value);
			}  
		}
	}	
}