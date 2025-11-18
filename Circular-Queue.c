#include<stdio.h>

#define size 5

int items[size];
int front = -1, rear = -1;
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == size - 1)) return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}

void enQueue(int element)
{
    if(isFull())
        printf("\n Queue is Full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % size;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

int deQueue()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is Empty !! \n");
        return (-1);
    }
    else
    {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        printf("\n Deleted Element -> %d \n", element);
        return(element);
    }
}

void display()
{
    int i;
    if (isEmpty())
        printf("\n Empty Queue\n");
    else
    {
        printf("\n Front -> %d", front);
        printf("\n Items -> ");
        for(i = front; i != rear; i = (i+1) % size)
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\n Rear -> %d\n",rear);
    }
}

int main()
{
    // Check if the queue is empty
    printf("\nIs the queue empty? %s", isEmpty() ? "Yes" : "No");

    // Enqueue some elements (size is 5)
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();

    // Dequeue an element
    deQueue();
    display();

    // Enqueue more, demonstrating the circular nature
    enQueue(40);
    enQueue(50); // Queue is now full (with one space left to distinguish full/empty)
    display();

    // Attempt to enqueue when full
    enQueue(60);

    // Check if full
    printf("\nIs the queue full? %s", isFull() ? "Yes" : "No");

    return 0;
}
