// 24. Write a program to sort a given set of elements using Heap Sort.

#include <stdio.h>
#include <stdlib.h>

// function to heapify a subtree rooted with node i

void heapify(int arr[],int n,int i){
  int largest=i;
  int left = 2*i+1;
  int right = left+1;

  if(left <n && arr[left] > arr[largest])
    largest=left;
  if(right <n && arr[right] > arr[largest])
    largest=right;

  if(largest !=i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr,n,largest);
  }
}

void heapSort(int arr[],int n) {
  for(int i=n/2-1;i>=0;i--)
    heapify(arr,n,i);

  for(int i=n-1;i>=0;i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr,i,0);
  }
}

void printArray(int arr[],int n) {
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}

int main() {
   int arr[] = {5,4,3,2,1,0,9,8,7,6};
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("Array before: ");
   printArray(arr,n);
   heapSort(arr,n);
   printf("Sorted array is:\n");
   printArray(arr,n);
   return 0;
}

/*
Array before: 5 4 3 2 1 0 9 8 7 6
Sorted array is:
0 1 2 3 4 5 6 7 8 9

*/
