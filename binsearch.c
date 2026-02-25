// 13 . write a program to implement binary search

#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    int result = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int main()
{
    int n, arr[20], choice, key, index;
    printf("enter the number of elements in the array:");
    scanf("%d", &n);
    printf("enter %d sorted elements\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter element to search using Binary Search:");
    scanf("%d", &key);
    index = binarySearch(arr, n, key);
    if (index != -1)
    {
        printf("first occurance of %d found at index %d\n", key, index);
    }
}

/*

enter the number of elements in the array:10
enter 10 sorted elements
1 2 3 4 5 6 7 7 8 9
enter element to search using Binary Search:7
first occurance of 7 found at index 6

*/