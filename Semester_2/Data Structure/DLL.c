#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void pushHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    newNode->next = *head;
    if (*head) (*head)->prev = newNode;
    *head = newNode;
}

void pushMid(Node** head, int data, int after) {
    Node* temp = *head;
    while (temp && temp->data != after) temp = temp->next;
    if (!temp) return;
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void pushTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void popHead(Node** head) {
    if (!*head) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(temp);
}

void popMid(Node** head, int key) {
    Node* temp = *head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == *head) *head = temp->next;
    free(temp);
}

void popTail(Node** head) {
    if (!*head) return;
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else *head = NULL;
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    pushHead(&head, 10);
    pushTail(&head, 20);
    pushTail(&head, 30);
    pushMid(&head, 25, 20);
    printList(head);
    popHead(&head);
    printList(head);
    popMid(&head, 25);
    printList(head);
    popTail(&head);
    printList(head);
    return 0;
}