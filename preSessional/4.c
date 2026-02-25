// 4. write a program to find the sum of all elements of a given matrix.

#include <stdio.h>
#include <conio.h>

void main()
{
	int a[101][101], i, j, rows, cols;
	int sum = 0;
	printf("\nEnter the number of rows:");
	scanf("%d", &rows);

	printf("\nEnter the number of cols:");
	scanf("%d", &cols);
	printf("\nEnter matrix elements: ");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	}

	printf("\nSum of all the elements: %d", sum);
}

/*
Enter the number of rows:2

Enter the number of cols:3

Enter matrix elements: 1 1 1 1 1 1 1 1 1

Sum of all the elements: 6
*/