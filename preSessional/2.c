// 2. write a program to find the sum of diagonal elements of a matrix.

#include <stdio.h>
#include <conio.h>
/*
include io and io 

define 2d array of arbritary size , iterators, size variable , sum
take the size as input from user, n
input elemenst into the array using a double loop 
  from i , 0 to n-1
    from j , 0 to n-1
	  store value -> arr[i][j]

 traverse the array diagonally 
  from i , 0  to n-1
    add arr[i][i] to sum

  print sum
*/


void main()
{
	int a[10][10], i, j, n, sum = 0;

	printf("\nEnter order of square matrix: ");
	scanf("%d", &n);

	printf("\nEnter matrix elements: ");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		sum += a[i][i];
	}

	printf("Sum of diagonals = %d", sum);
}

/*

Enter order of square matrix: 4

Enter matrix elements: 1 2 3 4 5 1 7 8 9 10 1 12 13 14 15 1
Sum of diagonals = 4
*/
