#include <stdio.h>
#include <stdlib.h>   // for exit()

#define size 10

void push(int n);
void pop();
void display();

int stack[size], top = -1;

int main()
{
    int n, ch;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &n);
            push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

void push(int n)
{
    if (top == size - 1)
    {
        printf("Stack is FULL!\n");
    }
    else
    {
        top++;
        stack[top] = n;
        printf("%d pushed into stack.\n", n);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is EMPTY!\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is EMPTY!\n");
    }
    else
    {
        int i;
        printf("Stack elements are: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}