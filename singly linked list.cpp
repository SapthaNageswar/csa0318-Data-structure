#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a new node at the end of the list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = newNode;
    } else {
        // Traverse the list to find the last node and append the new node
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list implementation
int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Print the list after insertions at the beginning
    printf("Linked List after insertions at the beginning: ");
    printList(head);

    // Insert elements at the end
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Print the list after insertions at the end
    printf("Linked List after insertions at the end: ");
    printList(head);

    return 0;
}

