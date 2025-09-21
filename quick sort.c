//WAP to sort an array by using quick sort.
#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot=arr[high], i=low-1, j, temp;
    for(j=low;j<high;j++) {
        if(arr[j]<pivot) {
            i++;
            temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
        }
    }
    temp=arr[i+1]; arr[i+1]=arr[high]; arr[high]=temp;
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main() {
    int arr[10], i;
    printf("Enter 10 elements: ");
    for(i=0;i<10;i++) scanf("%d",&arr[i]);

    quickSort(arr,0,9);

    printf("Array after Quick Sort: ");
    for(i=0;i<10;i++) printf("%d ",arr[i]);

    return 0;
}
