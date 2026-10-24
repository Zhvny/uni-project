#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Track{
	char category[25], details[25];
	int amount;
	Track* prev, *next;
} *head = NULL, *tail = NULL, *curr = NULL;

int balance = 0, foodbalance = 0, entbalance = 0, housebalance = 0, otherbalance = 0;

Track* newNode(char cat[], char details[], int amount){
	Track* node = (Track*) malloc (sizeof(Track));
	strcpy(node->category, cat);
	strcpy(node->details, details);
	node->amount = amount;
	node->prev = node->next = NULL;
	return node;
}

void pushHead(char cat[], char details[], int amount){
	Track* node = newNode(cat, details, amount);
	if(!head) head = tail = node;
	else{
		head->prev = node;
		node->next = head;
		head = node;
	}
}

void pushTail(char cat[], char details[], int amount){
	Track* node = newNode(cat, details, amount);
	if(!head) head = tail = node;
	else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void popHead(){
	if(head == NULL) return;
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		Track *del = head;
		head = head->next;
		head->prev = NULL;
		free(del);
	}
}

void popTail(){
	if(!head) return;
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		Track *del = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(del);
	}
}
void popMid(char del[]){
	if(!head) return;
	
	else if(strcmp(head->details, del) == 0){
		balance += head->amount;
		if(strcmp(head->category, "food") == 0) foodbalance -= head->amount;
		else if(strcmp(head->category, "house") == 0) housebalance -= head->amount;
		else if(strcmp(head->category, "entertainment") == 0) entbalance -= head->amount;
		else if(strcmp(head->category, "other") == 0) otherbalance -= head->amount;
		popHead();
	}
	else if(strcmp(tail->details, del) == 0){
		balance += tail->amount;
		if(strcmp(tail->category, "food") == 0) foodbalance -= tail->amount;
		else if(strcmp(tail->category, "house") == 0) housebalance -= tail->amount;
		else if(strcmp(tail->category, "entertainment") == 0) entbalance -= tail->amount;
		else if(strcmp(tail->category, "other") == 0) otherbalance -= tail->amount;
		popTail();
	}
	else{
		Track* curr = head;
		while(curr->next && strcmp(curr->next->details, del) != 0) curr = curr->next;
		if(curr->next == NULL) puts("Not Found!");
		else{
			Track* del = curr->next;
			curr->next = del->next;
			del->next->prev = curr;
			balance += del->amount;
			if(strcmp(del->category, "food") == 0) foodbalance -= del->amount;
			else if(strcmp(del->category, "house") == 0) housebalance -= del->amount;
			else if(strcmp(del->category, "entertainment") == 0) entbalance -= del->amount;
			else if(strcmp(del->category, "other") == 0) otherbalance -= del->amount;
			del = NULL;
			free(del);
		}
	}
	
	
}

void print(){
	printf("Account Balance: %d\n", balance);
	printf("food: %d\n", foodbalance);
	printf("house: %d\n", housebalance);
	printf("entertainment: %d\n", entbalance);
	printf("other: %d\n", otherbalance);
	
	Track* curr = head;
	while(curr){
		printf("%s (%s): %d\n", curr->details, curr->category, curr->amount);
		curr = curr->next;
	}
}
int main(){
	
	int n;
	char del[25];
	scanf("%d", &balance); getchar();
	scanf("%d", &n); getchar();
	for(int i = 0; i < n; i++){
		char inputCat[25], inputDet[25];
		int inputAmount;
		scanf("%s %s %d", inputCat, inputDet, &inputAmount); getchar();
		pushTail(inputCat, inputDet, inputAmount);
		balance -= inputAmount;
		if(strcmp(inputCat, "food") == 0) foodbalance += inputAmount;
		else if(strcmp(inputCat, "house") == 0) housebalance += inputAmount;
		else if(strcmp(inputCat, "entertainment") == 0) entbalance += inputAmount;
		else if(strcmp(inputCat, "other") == 0) otherbalance += inputAmount;
	}
	scanf("%s", del); getchar();
	popMid(del);
	print();
	
	
	return 0;
}
