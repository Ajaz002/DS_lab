//finding an element and length of a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert at end
void insert(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to find element
void findElement(int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", key);
}

// Function to get length
void getLength() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Length of list: %d\n", count);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Find Element\n");
        printf("4. Get Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter element to find: ");
                scanf("%d", &value);
                findElement(value);
                break;
            case 4:
                getLength();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}