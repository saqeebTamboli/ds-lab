#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node* createNode(int value) {
    struct node *p = malloc(sizeof *p);
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->info = value;
    p->next = NULL;
    return p;
}

void insertAtFirst(int value) {
    struct node *p = createNode(value);
    p->next = start;
    start = p;
}

void insertAtEnd(int value) {
    struct node *p = createNode(value);
    if (start == NULL) {
        start = p;
        return;
    }
    struct node *last = start;
    while (last->next != NULL)
        last = last->next;
    last->next = p;
}

void insertAtPosition(int pos, int value) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtFirst(value);
        return;
    }
    struct node *last = start;
    for (int i = 1; i < pos - 1 && last != NULL; i++)
        last = last->next;
    if (last == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct node *p = createNode(value);
    p->next = last->next;
    last->next = p;
}

void display() {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *last = start;
    printf("Linked List: ");
    while (last != NULL) {
        printf("%d -> ", last->info);
        last = last->next;
    }
    printf("NULL\n");
}

void createList() {
    int n, value;
    printf("Enter the no. of elements to create list: ");
    if (scanf("%d", &n) != 1) return;
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) return;
        insertAtEnd(value);
    }
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\n1. Create list\n2. Insert at first\n3. Insert at any position\n4. Insert at end\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: createList(); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insertAtFirst(val); break;
            case 3: printf("Enter position: "); scanf("%d", &pos); printf("Enter value: "); scanf("%d", &val); insertAtPosition(pos, val); break;
            case 4: printf("Enter value: "); scanf("%d", &val); insertAtEnd(val); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

