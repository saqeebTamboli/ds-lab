#include <stdio.h>
#include <ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char c) {
    if (top < max - 1) {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char check() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int prcd(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void stuff(char in[], char post[]) {
    int i, j = 0;
    char ch;

    for (i = 0; in[i] != '\0'; i++) {

        ch = in[i];

        if (isalnum(ch)) {
            post[j++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (check() != '(')
                post[j++] = pop();
            pop();   // remove '('
        }

        else {  // operator
            while (top != -1 && prcd(check()) >= prcd(ch))
                post[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        post[j++] = pop();

    post[j] = '\0';
}

int main() {
    char in[max], post[max];

    printf("Enter infix expression: ");
    scanf("%s", in);

    stuff(in, post);

    printf("Postfix expression: %s\n", post);

    return 0;
}