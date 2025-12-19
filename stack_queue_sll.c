#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int info;
    struct node *next;
};

/* Stack and Queue pointers */
struct node *start_stack = NULL;
struct node *start_queue = NULL;
struct node *rear_queue = NULL;

/* Stack Operations */
void push_stack(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->info = value;
    newnode->next = start_stack;
    start_stack = newnode;
    printf("Pushed %d onto stack\n", value);
}

void pop_stack() {
    if (start_stack == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = start_stack;
    printf("Popped %d from stack\n", temp->info);
    start_stack = start_stack->next;
    free(temp);
}

void display_stack() {
    if (start_stack == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = start_stack;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

/* Queue Operations */
void enqueue(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->info = value;
    newnode->next = NULL;

    if (start_queue == NULL) {
        start_queue = rear_queue = newnode;
    } else {
        rear_queue->next = newnode;
        rear_queue = newnode;
    }
    printf("Enqueued %d into queue\n", value);
}

void dequeue() {
    if (start_queue == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = start_queue;
    printf("Dequeued %d from queue\n", temp->info);
    start_queue = start_queue->next;
    if (start_queue == NULL)
        rear_queue = NULL;
    free(temp);
}

void display_queue() {
    if (start_queue == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = start_queue;
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

/* Main Function */
int main() {
    int choice, subchoice, value;

    while (1) {
        printf("\n--- STACK & QUEUE USING LINKED LIST ---\n");
        printf("1. Stack operations\n");
        printf("2. Queue operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- STACK MENU ---\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display\n");
            printf("4. Back\n");
            printf("Enter your choice: ");
            scanf("%d", &subchoice);

            switch (subchoice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    push_stack(value);
                    break;
                case 2:
                    pop_stack();
                    break;
                case 3:
                    display_stack();
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
            }

        } else if (choice == 2) {
            printf("\n--- QUEUE MENU ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Back\n");
            printf("Enter your choice: ");
            scanf("%d", &subchoice);

            switch (subchoice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    display_queue();
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
            }

        } else if (choice == 3) {
            printf("Exiting program...\n");
            return 0;
        } else {
            printf("Invalid choice\n");
        }
    }
}