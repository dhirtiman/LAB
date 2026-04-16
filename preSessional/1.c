// 1. write a program to find the second largest element in an array.

/*
to run this program in turbo c
include stdio,conio,limits

define arr,n i, lg,sc
take in size of array , input array elements
check if only 1 element exists , fail if fail
traverse the arraay 
 if element is larger than lg , set lg = element , sc = lg
 else if, element is larger than sc and !=lg , set sc = lg

if(sc is still INT_MIN)
  print no found
else:
  print sc

*/

#include <stdio.h>
#include <conio.h>
#include <limits.h>

void main()
{
	int arr[50], n, i;
	int largest, second_largest;

	// clrscr();
	printf("Enter number of elements: ");
	scanf("%d", &n);

	if (n < 2)
	{
		printf("\nSecond largest element does not exist.");
		getch();
		return;
	}

	printf("\nEnter array elements: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	largest = INT_MIN;
	second_largest = INT_MIN;

	for (i = 0; i < n; i++)
	{
		if (arr[i] > largest)
		{
			second_largest = largest;
			largest = arr[i];
		}
		else if (arr[i] > second_largest && arr[i] != largest)
		{
			second_largest = arr[i];
		}
	}
	if (second_largest == INT_MIN)
		printf("Second largest element does not exist.");
	else
		printf("Second largest element is: %d", second_largest);
	getch();
}

/*
Enter number of elements: 10

Enter array elements: 1 2 3 4 5 6 7 8 9 10
Second largest element is: 9
*/
