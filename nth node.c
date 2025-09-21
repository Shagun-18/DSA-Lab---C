//Write a function to get Nth node in a Linked List. Use this function in C program.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void insertAtEnd(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x; temp->next=NULL;
    if(head==NULL) head=temp;
    else {
        struct Node* p=head;
        while(p->next!=NULL) p=p->next;
        p->next=temp;
    }
}

struct Node* getNthNode(int n) {
    struct Node* p=head;
    int count=1;
    while(p!=NULL && count<n) { p=p->next; count++; }
    return p;
}

void display() {
    struct Node* p=head;
    if(head==NULL) { printf("List is empty\n"); return; }
    printf("List elements: ");
    while(p!=NULL) { printf("%d ", p->data); p=p->next; }
    printf("\n");
}

int main() {
    int choice, x, n;
    do {
        printf("\n1.Insert\n2.Display\n3.Get Nth Node\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter element: "); scanf("%d",&x); insertAtEnd(x); break;
            case 2: display(); break;
            case 3:
                printf("Enter N: "); scanf("%d",&n);
                struct Node* node = getNthNode(n);
                if(node!=NULL) printf("Nth node = %d\n", node->data);
                else printf("Node not found\n");
                break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice!=4);
    return 0;
}
