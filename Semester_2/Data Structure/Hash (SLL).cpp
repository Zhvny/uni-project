#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct SLL {
    Node *head;
} SLL;

Node *create(int value) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

int hash_function(int value) {
    return value % 10;
}

void push(SLL *sll, int value) {
    int hash_key = hash_function(value);
    Node *newnode = create(value);

    if ((sll + hash_key)->head == NULL) {
        (sll + hash_key)->head = newnode;
        return;
    }

    Node *current = (sll + hash_key)->head;
    while (current->next != NULL)
        current = current->next;
    current->next = newnode;
}

void pop(SLL *sll, int value){
	int hash_key = hash_function(value);
	
if((sll + hash_key)->head == NULL){
	printf("Data not found\n");
		return;
}

	if((sll + hash_key)->head->value == value){
		Node *temp = (sll + hash_key)->head;
		(sll + hash_key)->head = (sll + hash_key)->head-> next;
		free(temp);
	}
	
	Node *current = (sll + hash_key)->head;
	while(current -> next != NULL && current -> value != value)
	current =current -> next;
	
	if(current -> next == NULL){
		printf("Data not found\n");
		return;
	}
	
	Node *temp = current -> next;
	current -> next = temp -> next;
	free(temp);
}

void printAll(SLL *sll) {
    for (int i = 0; i < 10; i++) {
        Node *current = (sll + i)->head;
        printf("Hash IDX %d: ", i);
        while (current != NULL) {
            printf("%d", current->value);
            if (current->next != NULL)
                printf(" -> ");
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    SLL *sll = (SLL*)malloc(sizeof(SLL) * 10);
    for (int i = 0; i < 10; i++)
        (sll + i)->head = NULL;

    push(sll, 10);
    push(sll, 25);
    push(sll, 30);
    push(sll, 64);
    push(sll, 11);
    push(sll, 105);
    push(sll, 75);
    pop(sll, 75);
    pop(sll, 1000);

    printAll(sll);

//	SLL *sll = (*SLL)malloc(sizeof(SLL));
//	SLL -> head = (Node*)malloc(sizeof(Node)*10);
	
	return 0;
}
