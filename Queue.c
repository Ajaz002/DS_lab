#include<stdio.h>
#define max 20

int queue[max], front=-1, rear=-1;

void enqueue(int ele) {
    if(front==-1) {
        front=0;
    }
    if(rear==max-1) {
        printf("Queue is full. Can't insert element\n");
        return;   // prevent overflow
    }
    queue[++rear]=ele;
    printf("%d inserted into queue\n", ele);
}

void dequeue() {
    if(front==-1 || front>rear) {
        printf("Queue is empty. Can't delete element\n");
    }
    else {
        printf("%d is removed from queue\n", queue[front]);
        front++;
        if(front>rear) {
            front=rear=-1;
        }
    }
}

void display() {
    if(front==-1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int value, choice;
    while(1) {
        printf("\nSelect choice :\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1 : {
                printf("Enter value : ");
                scanf("%d",&value);
                enqueue(value);
                break;
            }
            case 2 : {
                dequeue();
                break;
            }
            case 3 : {
                display();
                break;
            }
            case 4 : {
                printf("Exiting...\n");
                return 0;
            }
            default : {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    return 0; 
}