// 3. write a program to declare , initialize, and display a two-dimensional
//  array(matrix).

#include <stdio.h>
#include <conio.h>

void main()
{
	int a[101][101], i, j, rows, cols;

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
		}
	}

	printf("\nThe matrix is: \n");

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

/*
Enter the number of rows:2

Enter the number of cols:2

Enter matrix elements: 1 2 3 4

The matrix is:
1       2
3       4
*/
