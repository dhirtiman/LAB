#include <stdio.h>

int main()
{
    int n, key;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1;
    int mid, found = -1;

    // Binary Search
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            found = mid;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == -1)
    {
        printf("Element not found\n");
        return 0;
    }

    // Count occurrences
    int count = 1;

    int i = found - 1;
    while(i >= 0 && arr[i] == key)
    {
        count++;
        i--;
    }

    i = found + 1;
    while(i < n && arr[i] == key)
    {
        count++;
        i++;
    }

    printf("Element found at location: %d\n", found + 1);
    printf("Number of occurrences: %d\n", count);

    return 0;
}