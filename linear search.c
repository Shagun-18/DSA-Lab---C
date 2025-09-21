#include <stdio.h>

int main() {
    int arr[10], i, n, search, found = 0;

    // Input 10 elements
    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &search);

    // Linear Search
    for(i = 0; i < 10; i++) {
        if(arr[i] == search) {
            printf("Element %d found at position %d\n", search, i+1);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Element %d not found in the array.\n", search);
    }

    return 0;
}
