#include <stdio.h>
#define size 3

int queue[size];s
int front = -1, rear = -1;

void insert(int value)
{
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
    {
        printf("Queue overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    int deleted = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    printf("Deleted %d\n", deleted);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;

        i = (i + 1) % size;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice! Try again\n");
        }
    }
