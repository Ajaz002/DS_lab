#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;  // front (left)
struct Node* tail = NULL;  // rear (right)

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Left (Front)
void insertLeft(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at LEFT.\n", data);
}

// Insert at Right (Rear)
void insertRight(int data) {
    struct Node* newNode = createNode(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("%d inserted at RIGHT.\n", data);
}

// Insert at Specific Position (1-based index)
void insertAtPosition(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = createNode(data);

    // Insert at head
    if (pos == 1) {
        insertLeft(data);
        return;
    }

    struct Node* temp = head;
    int i = 1;

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        // Position is beyond current length, insert at end
        insertRight(data);
    } else {
        // Insert before temp
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = newNode;
        temp->prev = newNode;
        printf("%d inserted at position %d.\n", data, pos);
    }
}

// Delete from Left (Front)
void deleteLeft() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("%d deleted from LEFT.\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    free(temp);
}

// Delete from Right (Rear)
void deleteRight() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = tail;
    printf("%d deleted from RIGHT.\n", temp->data);
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    free(temp);
}

// Display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("DLL contents: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu-driven program
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Left\n");
        printf("2. Insert at Right\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Left\n");
        printf("5. Delete from Right\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertLeft(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRight(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(value, pos);
            break;
        case 4:
            deleteLeft();
            break;
        case 5:
            deleteRight();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}