#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i;

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void printPoly(struct Node* head) {
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}