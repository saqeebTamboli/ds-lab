#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

void createlist(int n) {
    int val;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);

        struct node *p = (struct node*) malloc(sizeof(struct node));
        p->info = val;
        p->next = NULL;

        if(start == NULL) {
            start = p;
        }
        else {
            struct node *last = start;
            while(last->next != NULL)
                last = last->next;
            last->next = p;
        }
    }
}

void deletefirst() {
    if(start == NULL) return;

    struct node *temp = start;
    start = start->next;
    free(temp);
}

void deletevalue(int val) {
    if(start == NULL) return;

    if(start->info == val) {
        deletefirst();
        return;
    }

    struct node *prev = start;
    struct node *temp = start->next;

    while(temp != NULL && temp->info != val) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void deletelast() {
    if(start == NULL) return;

    if(start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    struct node *temp = start;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void display() {
    struct node *temp = start;

    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, n, val;

    while(1) {
        printf("1. Create list\n");
        printf("2. Delete first\n");
        printf("3. Delete at specific value\n");
        printf("4. Delete last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("How many elements? ");
                scanf("%d", &n);
                printf("Enter values:\n");
                createlist(n);
                break;

            case 2:
                deletefirst();
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deletevalue(val);
                break;

            case 4:
                deletelast();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}