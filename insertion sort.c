//WAP to sort an array of 10 elements using insertion sort.
#include <stdio.h>
int main() {
    int arr[10], i, j, key;

    printf("Enter 10 elements: ");
    for(i=0;i<10;i++) scanf("%d",&arr[i]);

    for(i=1;i<10;i++) {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    printf("Array after Insertion Sort: ");
    for(i=0;i<10;i++) printf("%d ",arr[i]);

    return 0;
}
