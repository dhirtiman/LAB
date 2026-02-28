// Implement Binary search
#include<stdio.h>
#include<conio.h>



int binarySearch(int arr[],int n,int key) {
	int low = 0 , high = n-1 , mid,result = -1;
	while (low<=high) {
	   mid = low+(high-low)/2;
	   if(arr[mid]==key) {
		result=mid;
		high = mid-1;
	   }else if (arr[mid] < key ) {
		low = mid+1;
	   }else {
		high = mid -1;
	   }
	}
	return result;
}

void main()
{
    int n,arr[20],choice,key,index;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter %d sorted elements\n",n);
    for(int i=0;i<n;i++) {
	scanf("%d",&arr[i]);
    }
    printf("\nEnter element to search using Binary search: ");
    scanf("%d",&key);
    index = binarySearch(arr,n,key);
    if( index != -1)
	printf("\nFirst occurance of %d found at index %d",key,index);
    
}


/*

Enter the number of elements in the array: 10

Enter 10 sorted elements
1 2 3 4 5 6 7 7 8 9

Enter element to search using Binary search: 7

First occurance of 7 found at index 6
*/