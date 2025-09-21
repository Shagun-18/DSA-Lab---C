//WAP to implement binary search.
#include <stdio.h>
int main() {
    int arr[20], n, i, x, low, high, mid, found=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d sorted elements: ",n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&x);

    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]==x) {
            printf("Element found at position %d\n",mid+1);
            found=1;
            break;
        } else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    if(!found) printf("Element not found.\n");
    return 0;
}
