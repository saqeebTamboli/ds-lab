#include <stdio.h>
#define size 3

int queue[size];
int front = -1, rear = -1;

void insert() {
    int item;

    if (rear == size - 1) {
        printf("Queue overflow");
        return;
    }

    printf("Enter the element to insert:");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;

    printf("%d inserted into the queue\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow");
        return;
    }

    printf("Deleted element: %d", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty");
        return;
    }

    printf("Queue elements:");

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program"); return 0;
            default: printf("Invalid Choice");
        }
    }
}