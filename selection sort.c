//WAP to sort an array of 10 elements using selection sort.
#include <stdio.h>
int main() {
    int arr[10], i, j, min, temp;

    printf("Enter 10 elements: ");
    for(i=0;i<10;i++) scanf("%d",&arr[i]);

    for(i=0;i<9;i++) {
        min=i;
        for(j=i+1;j<10;j++) {
            if(arr[j]<arr[min]) min=j;
        }
        if(min!=i) {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

    printf("Array after Selection Sort: ");
    for(i=0;i<10;i++) printf("%d ",arr[i]);

    return 0;
}

