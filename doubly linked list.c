//Write a menu driven program to implement doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL) head->prev = temp;
    head = temp;
}

// Insert at end
void insertAtEnd(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; temp->next = NULL;
    if(head == NULL) { temp->prev = NULL; head = temp; return; }
    struct Node* p = head;
    while(p->next != NULL) p = p->next;
    p->next = temp;
    temp->prev = p;
}

// Insert at specific position
void insertAtPosition(int x, int pos) {
    if(pos == 1) { insertAtBeginning(x); return; }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    struct Node* p = head;
    for(int i=1; i<pos-1 && p!=NULL; i++) p = p->next;
    if(p == NULL) { printf("Position out of range\n"); free(temp); return; }
    temp->next = p->next;
    temp->prev = p;
    if(p->next != NULL) p->next->prev = temp;
    p->next = temp;
}

// Delete from beginning
void deleteFromBeginning() {
    if(head == NULL) { printf("List is empty\n"); return; }
    struct Node* temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if(head == NULL) { printf("List is empty\n"); return; }
    struct Node* p = head;
    if(p->next == NULL) { printf("Deleted: %d\n", p->data); free(p); head=NULL; return; }
    while(p->next != NULL) p = p->next;
    printf("Deleted: %d\n", p->data);
    p->prev->next = NULL;
    free(p);
}

// Delete from specific position
void deleteFromPosition(int pos) {
    if(head == NULL) { printf("List is empty\n"); return; }
    if(pos == 1) { deleteFromBeginning(); return; }
    struct Node* p = head;
    for(int i=1; i<pos && p!=NULL; i++) p = p->next;
    if(p == NULL) { printf("Position out of range\n"); return; }
    printf("Deleted: %d\n", p->data);
    if(p->next != NULL) p->next->prev = p->prev;
    if(p->prev != NULL) p->prev->next = p->next;
    free(p);
}

// Display forward
void displayForward() {
    if(head == NULL) { printf("List is empty\n"); return; }
    struct Node* p = head;
    printf("Forward: ");
    while(p != NULL) { printf("%d ", p->data); p = p->next; }
    printf("\n");
}

// Display backward
void displayBackward() {
    if(head == NULL) { printf("List is empty\n"); return; }
    struct Node* p = head;
    while(p->next != NULL) p = p->next;
    printf("Backward: ");
    while(p != NULL) { printf("%d ", p->data); p = p->prev; }
    printf("\n");
}

int main() {
    int choice, x, pos;
    do {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n");
        printf("4.Delete from Beginning\n5.Delete from End\n6.Delete from Position\n");
        printf("7.Display Forward\n8.Display Backward\n9.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter element: "); scanf("%d",&x); insertAtBeginning(x); break;
            case 2: printf("Enter element: "); scanf("%d",&x); insertAtEnd(x); break;
            case 3:
                printf("Enter element: "); scanf("%d",&x);
                printf("Enter position: "); scanf("%d",&pos);
                insertAtPosition(x,pos); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6:
                printf("Enter position: "); scanf("%d",&pos);
                deleteFromPosition(pos); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 9);
    return 0;
}
