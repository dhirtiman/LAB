// / q23Write a program to perform Merge Sort on a given set of elements and display the result in descending order.

#include <stdio.h>
#include <stdlib.h>

// funtion to merge two sorted subarrays into a single sorted array

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;    // size of the left subarray
    const int n2 = right - mid; // size of the right subarray

    // creating temporary arrays

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 0, 9, 8, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    printf("Original Array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, n - 1);
    printf("Sorted Array: \n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*
Original Array:
5 4 3 2 1 0 9 8 7 6
Sorted Array:
9 8 7 6 5 4 3 2 1 0
*/
