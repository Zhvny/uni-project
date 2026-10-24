#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cust{
	int prio;
	char name[25];
	Cust *prev, *next;
}*head = NULL, *tail = NULL;

Cust* newNode(char prio[], char name[]){
	Cust* node = (Cust*)malloc(sizeof(Cust));
	strcpy(node->name, name);
	if(strcmp(prio, "VVIP") == 0) node->prio = 1;
	else if(strcmp(prio, "VIP") == 0) node->prio = 2;
	else if(strcmp(prio, "Member") == 0) node->prio = 3;
	else if(strcmp(prio, "Guest") == 0) node->prio = 4;
	node->prev = node->next = NULL;
	return node;
}

void push(char prio[], char name[]){
	Cust *node = newNode(prio, name);
	if(!head) head = tail = node;
	else if(node->prio < head->prio){
		node->next = head;
		head->prev = node;
		head = node;
	}
	else if(node->prio >= tail->prio){
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
	else{
		Cust *curr = head;
		while(curr && node->prio >= curr->prio) curr = curr->next;
		node->next = curr;
		node->prev = curr->prev;
		curr->prev->next = node;
		curr->prev = node;
	}
}

void pop(){ // popHead
	if(!head) puts("Empty!");
	else{
		puts("");
		printf("Attention! %s is being served at ", head->name);
		if(head->prio == 1) puts("VVIP table");
		else if(head->prio == 2) puts("VIP table");
		else if(head->prio == 3) puts("Member table");
		else if(head->prio == 4) puts("Guest table");
		
		if(head == tail) head = tail = NULL;
		else{
			Cust* del = head;
			head = head->next;
			head->prev = NULL;
			free(del);
		}
		printf("Press enter to continue..."); getchar();
	}
}

void print(){
	if(!head) puts("Empty");
	else{
		puts("");
		int index = 1;
		Cust* curr = head;
		while(curr){
			printf("%d. %s\n", index, curr->name);
			curr = curr->next;
			index++;
		}
	}
}

void dismiss(){
	if(!head){
		puts("Empty!");
		return;
	}
	else{
		head = tail = NULL;
		puts("End of the day");
		puts("Press enter to continue..."); getchar();
	}
}

void menu(){
	int choice = 0;
	do{
		system("cls");
		puts("===============================");
		puts("SUNIB Restaurant");
		puts("===============================");
		print();
		puts("");
		puts("1. Add");
		puts("2. Serve One");
		puts("3. Serve All");
		puts("4. Dismiss");
		puts("0. Exit");
		printf("Please Input Number [1-4]: ");
		scanf("%d", &choice); getchar();
		switch(choice){
			
			case 1:{
				char inputName[25], inputPrio[25];
				scanf("%s %[^\n]", inputPrio, inputName); getchar();
				push(inputPrio, inputName);
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				while(head) pop();
				break;
			}
			case 4:{
				dismiss();
				break;
			}
		}
	}while(choice != 0);
}

int main(){
	
	menu();
	
	return 0;
}
