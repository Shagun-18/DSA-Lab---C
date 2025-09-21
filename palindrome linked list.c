//Write a C program to check whether a Singly Linked List is a Palindrome or not.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void insertAtEnd(int x) {
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x; temp->next=NULL;
    if(head==NULL) head=temp;
    else {
        struct Node* p=head;
        while(p->next!=NULL) p=p->next;
        p->next=temp;
    }
}

int isPalindrome() {
    int arr[50], i=0;
    struct Node* p=head;
    while(p!=NULL) { arr[i++]=p->data; p=p->next; }
    for(int j=0;j<i/2;j++) {
        if(arr[j]!=arr[i-1-j]) return 0;
    }
    return 1;
}

void display() {
    struct Node* p=head;
    if(head==NULL) { printf("List is empty\n"); return; }
    printf("List elements: ");
    while(p!=NULL) { printf("%d ", p->data); p=p->next; }
    printf("\n");
}

int main() {
    int choice, x;
    do {
        printf("\n1.Insert\n2.Display\n3.Check Palindrome\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter element: "); scanf("%d",&x); insertAtEnd(x); break;
            case 2: display(); break;
            case 3:
                if(isPalindrome()) printf("Linked List is a Palindrome\n");
                else printf("Linked List is NOT a Palindrome\n");
                break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice!=4);
    return 0;
}
