#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node {
    int data;
    struct node* next;
};

/* Function to insert a node at the beginning of a linked list */
void insert(struct node** head_ref, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to print a linked list */
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Function to reverse a linked list */
void reverse(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    struct node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Print the original linked list
    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    reverse(&head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    printList(head);

    return 0;
}

