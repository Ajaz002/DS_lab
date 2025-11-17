#include <stdio.h>
#define SIZE 10

int q[SIZE];
int front = -1;
int rear = -1;
int len = 0;

int isFull() {
    return (len == SIZE);
}

int isEmpty() {
    return (len == 0);
}

void enqueueFront(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + SIZE) % SIZE;

    q[front] = value;
    len++;
}

void enqueueRear(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    q[rear] = value;
    len++;
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }

    int popped = q[front];
    front = (front + 1) % SIZE;
    len--;

    if (len == 0) front = rear = -1;

    return popped;
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }

    int popped = q[rear];
    rear = (rear - 1 + SIZE) % SIZE;
    len--;

    if (len == 0) front = rear = -1;

    return popped;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque:\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", q[(front + i) % SIZE]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue Front\n2. Enqueue Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                value = deleteFront();
                if (value != -1)
                    printf("Deleted: %d\n", value);
                break;
            case 4:
                value = deleteRear();
                if (value != -1)
                    printf("Deleted: %d\n", value);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}
