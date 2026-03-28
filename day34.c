#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) { // handle negative numbers
            push(&stack, atoi(token));
        } else { // operator
            int b = pop(&stack);
            int a = pop(&stack);
            int result;
            switch(token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break; // integer division
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack); // final result
}

int main() {
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0; // remove newline
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}