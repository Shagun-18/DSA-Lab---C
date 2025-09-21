//Write a C program to insert an element in a sorted linked list so that it remains sorted even after insertion.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertSorted(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; temp->next = NULL;

    if(head==NULL || x < head->data) {
        temp->next=head; head=temp; return;
    }

    struct Node* p = head;
    while(p->next!=NULL && p->next->data < x) p=p->next;
    temp->next = p->next;
    p->next = temp;
}

void display() {
    struct Node* p = head;
    if(head==NULL) { printf("List is empty\n"); return; }
    printf("List elements: ");
    while(p!=NULL) { printf("%d ", p->data); p=p->next; }
    printf("\n");
}

int main() {
    int choice, x;
    do {
        printf("\n1.Insert Sorted\n2.Display\n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter element: "); scanf("%d",&x);
                insertSorted(x); break;
            case 2: display(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice!=3);
    return 0;
}
