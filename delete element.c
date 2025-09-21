//WAP to delete a given element from an array
#include <stdio.h>
int main() {
    int arr[20], n, i, x, pos=-1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Enter element to delete: ");
    scanf("%d",&x);

    for(i=0;i<n;i++) {
        if(arr[i]==x) {
            pos=i;
            break;
        }
    }

    if(pos==-1) printf("Element not found!\n");
    else {
        for(i=pos;i<n-1;i++) arr[i]=arr[i+1];
        n--;
        printf("Array after deletion: ");
        for(i=0;i<n;i++) printf("%d ",arr[i]);
    }
    return 0;
}

