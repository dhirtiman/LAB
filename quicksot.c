// program to implement quick sort

#include <stdio.h>

void swap(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

int partition(int arr[],int low,int high) {
   int p = arr[low];
   int i = low;
   int j = high;

   while (i<j) {
	while (arr[i] <= p && i<= high -1 ) {
	   i++;
	}
	while (arr[j] > p && j >= low + 1) {
	   j--;
	}
	if (i<j) {
	   swap(&arr[i],&arr[j]);
	}
	
   }
   swap(&arr[low],&arr[j]);
   return j;
}
void quickSort(int arr[],int low,int high) {
   int pi;  

   if(low<high) {
	pi = partition(arr,low,high);
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);
   }
}

int main() {
   int i,size,arr[100];


   printf("\nEnter the size of the array: ");
   scanf("%d",&size);
   printf("\nEnter %d unsorted elements: ",size);

   for ( i = 0; i < size;i++)
	scanf("%d",&arr[i]);

   quickSort(arr,0,size-1);

   for ( i = 0 ; i<size; i++ ) 
	printf("%d ",arr[i]);	

   return 0;
}


	





