#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* head = NULL; Node* curr = NULL;

Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode) return NULL;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void push(int data){
	if(!head){
		head = curr = createNode(data);
		return;
	}
	Node* newNode = createNode(data);
	newNode->next = curr->next;
	newNode->prev = curr;
	if(curr->next) curr->next->prev = newNode;
	curr->next = newNode;
	curr = newNode;
}

void left(int key){
	while (key-- && curr->prev) curr = curr->prev;
}

void right(int key){ 
	while (key-- && curr->next) curr = curr->next;
}


void pop(int data){
	if(!head) return;
	Node* del = curr;
	if (curr == head) head = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    if (curr->prev) curr->prev->next = curr->next;
    curr = curr->next ? curr->next : curr->prev;	// Ni artinya curr->next != NULL dia pilih 1, kalo curr->next = NULL ya pilih 2.
    free(del);
}

void print(){
    if (!head){ 
		printf("NO TAB\n"); return;
	}
    for (Node *temp = head; temp; temp = temp->next) printf(temp == curr ? "[%d] " : "%d ", temp->data);
    printf("\n");
}

int main(){
    int M, data;
    char K;
    scanf("%d", &M);
    while (M--){
        scanf(" %c", &K);
        if (K == 'O'){
			scanf("%d", &data); push(data);
		}
        else if (K == 'L'){ 
			scanf("%d", &data); left(data);
		}
        else if (K == 'R'){
			scanf("%d", &data); right(data);
		}
        else if (K == 'C'){
        	scanf("%d", &data); pop(data);
		}
    }
    print();
}

/*
10
O 10
O 20
O 30
O 40
L 3
C 10
C 20
C 30
R 1
C 40
*/
