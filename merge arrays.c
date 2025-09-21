//WAP to merge two sorted arrays into a single sorted array
#include <stdio.h>
int main() {
    int a[20], b[20], c[40];
    int n1, n2, i=0, j=0, k=0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements: ", n1);
    for(i=0;i<n1;i++) scanf("%d",&a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements: ", n2);
    for(i=0;i<n2;i++) scanf("%d",&b[i]);

    i=0;j=0;k=0;
    while(i<n1 && j<n2) {
        if(a[i]<b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<n1) c[k++]=a[i++];
    while(j<n2) c[k++]=b[j++];

    printf("Merged sorted array: ");
    for(i=0;i<k;i++) printf("%d ",c[i]);

    return 0;
}

