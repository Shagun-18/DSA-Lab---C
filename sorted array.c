#include <stdio.h>
int main() {
    int arr[20], n, i, x, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements: ", n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Enter element to insert: ");
    scanf("%d",&x);

    // Find position
    for(pos=0; pos<n && arr[pos]<x; pos++);

    // Shift elements
    for(i=n;i>pos;i--) arr[i]=arr[i-1];

    arr[pos]=x;
    n++;

    printf("Array after insertion: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}
