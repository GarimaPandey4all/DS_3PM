#include <stdio.h>
#include <stdlib.h>
#define size 5

int queue[size], front = -1, rear = -1;

void enqueue()
{
    int value;

    if(rear == size - 1)
    {
        printf("Queue is Full");
    }
    else {
        printf("Enter any value:");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue is Empty");
    }
    else {
        printf("Deleted value is: %d", queue[front]);

        front++;

        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if(rear == -1)
    {
        printf("Queue is Empty");
    }
    else {
        int i;
        printf("Elements in queue are:\n");
        for(i = front; i <= rear; i++)
        {
            printf("%d  ", queue[i]);
        }
    }
}

int main()
{

    int choice;

    while(1)
    {
        printf("\n\n1. Enqueue\n");
        printf("\n\n2. Dequeue\n");
        printf("\n\n3. Display\n");
        printf("\n\n4. Exit\n");
        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}
