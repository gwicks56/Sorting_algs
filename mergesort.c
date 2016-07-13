/*
** Header for COMP20007 Assignment 1
** Geordie Wicks 185828
** With thanks to stackoverflow for the wealth of information available
** and Jason Holden, for his general sudo code tips
 */

#include <stdlib.h>
#include "stack.h"
#include "partition.h"

/*
merge 2 sub arrays [start, m - 1] and [m + 1, stop]
by using in place merge algorithm
*/
void merge(void **A, void **B, int start, int m, int stop, int(cmp)(void *, void*)){ 
	int i = start, j=stop, k = start;

	//copy A to B at appropriate positions
	while (i < stop && j < m) { 
		if (cmp(A[i],A[j]) <= 0) {
			B[k]=A[i]; i++;
		} 
		else 
		{
			B[k]=A[j]; j++;
		}
		k++;
	}

	//copy to B
	while (i < stop) { 
		B[k] = A[i]; 
		i++; 
		k++;
	}
	while (j < m) { 
		B[k] = A[j]; 
		j++; 
		k++;
	}
	//copy back to A
	for (k = start; k < m; k++) { 
		A[k] = B[k]; 

	}
}

/*
The function implements merge sort using non-recursive algorithm

...
*/
void myMergesort(void **A, int n, int(cmp)(void *, void*)) {

	//define a temp array B
	void **B = (void **)malloc(sizeof(void *) * n);

	int k,u, i;

	//create stack
	Stack *stack = stack_new();

	k = 1;
	stack_push(stack, (void*)k);
	while (stack_isEmpty(stack) == 0)
	{
		k = (int)stack_pop(stack); 
		if (k >= n){
			break;
		}
		i = 0;
		while (i + k <= n) {
			u = i + k * 2;
			if (u > n) u = n;
			merge(A, B, i,u, i+k, cmp);
			i = i + k * 2;
		}
		k = k * 2;
		stack_push(stack, (void*)k);
	}
}
