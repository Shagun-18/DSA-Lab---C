//WAP to implement stack using array (menu-driven program).
#include <stdio.h>
#define MAX 10

int stack[MAX];
int topIndex = -1;

// Check if stack is empty
int isEmpty() {
    return topIndex == -1;
}

// Check if stack is full
int isFull() {
    return topIndex == MAX - 1;
}

// Push element onto stack
void push(int x) {
    if(isFull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++topIndex] = x;
        printf("%d pushed onto stack\n", x);
    }
}

// Pop element from stack
int pop() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[topIndex--];
    }
}

// Get top element without removing
int top() {
    if(isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[topIndex];
    }
}

// Display stack elements
void display() {
    if(isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for(int i=topIndex; i>=0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    do {
        printf("\n1.Push\n2.Pop\n3.Top\n4.Display\n5.IsEmpty\n6.IsFull\n7.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                x = pop();
                if(x != -1) printf("Popped element: %d\n", x);
                break;
            case 3:
                x = top();
                if(x != -1) printf("Top element: %d\n", x);
                break;
            case 4:
                display();
                break;
            case 5:
                if(isEmpty()) printf("Stack is empty\n");
                else printf("Stack is not empty\n");
                break;
            case 6:
                if(isFull()) printf("Stack is full\n");
                else printf("Stack is not full\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 7);

    return 0;
}
