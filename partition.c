/*
** Header for COMP20007 Assignment 1
** Geordie Wicks 185828
** With thanks to stackoverflow for the wealth of information available
** and Jason Holden, for his general sudo code tips
 */


#include <stdio.h>
 
/*
	partition is used in quicksort algorithm
		
*/
int partition(void **A, int low, int high, void *pivot, int (cmp)(void *, void *))
{	
	void* temp;

	int left = low, right = high;
	
	while (left < right)
	{
		//move the left index to approriate position
		while (left < high && cmp(A[left], pivot) <= 0) left++;

		//move the right index to approriate position
		while (right > low && cmp(pivot, A[right]) < 0) right--; 
		
		//swap two elements
		if (left < right){
			temp = A[left];
			A[left] = A[right];
			A[right] = temp;
		}
	}
	
	A[low] = A[right];
    A[right] = pivot;
	return right;
	
}