#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char name[15], type[15];
	int prio;
	data *prev, *next;
}*head = NULL, *tail = NULL;

data* create(char name[], char type[]){
	data* node = (data*)malloc(sizeof(data));
	strcpy(node->name, name);
	strcpy(node->type, type);
	if(strcmp(type, "FAST_TRACK") == 0) node->prio = 1;
	else if(strcmp(type, "REGULER") == 0) node->prio = 2;
	node->next = node->prev = NULL;
	return node;
}

void pushHead(char name[], char type[]){
	data *node = create(name, type);
	if(!head) head = tail = node;
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char name[], char type[]){
	data *node = create(name, type);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void pushMid(char name[], char type[]){
	data *node = create(name, type);
	if(!head) head = tail = node;
	else if(node->prio < head->prio) pushHead(name, type);
	else if(node->prio >= tail->prio) pushTail(name, type);
	else{
		data *curr = head;
		while(curr && node->prio >= curr->prio) curr = curr->next;
		node->next = curr;
		node->prev = curr->prev;
		curr->prev->next = node;
		curr->prev = node;
	}
}

void popHead(){
	if(!head) return;
	else if(head == tail){
		free(head);
		head = tail = NULL;	
	}
	else{
		data *del = head;
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
		data *del = tail;
		tail = tail->next;
		tail->next = NULL;
		free(del);
	}
}

void popMid(char name[]){
	if(!head) return;
	else if(strcmp(name, head->name) == 0) popHead();
	else if(strcmp(name, tail->name) == 0) popTail();
	else{
		data *curr = head;
		while(curr->next && strcmp(curr->next->name, name) != 0) curr = curr->next;
		if(!curr->next) return;
		data *del = curr->next;
		curr->next = del->next;
		del->next->prev = curr;
		del = NULL;
		free(del);
	}
	
}

void print(){
	if(!head){
		puts("No Data");
		return;
	}
	data *curr = head;
	int index = 1;
	printf("%-02s %-10s %-08s\n", "No", "Name", "Ticket");
	while(curr){
		printf("%-02d %-10s %-08s\n", index, curr->name, curr->type);
		index++;
		curr = curr->next;
	}
}

int amount = 0;
int main(){
	
	char input[200];
	int regis, remove;
	while(true){
		scanf("%s", input); getchar();
		if(strcmp(input, "REGISTER") == 0){
			char name[20], type[20];
			scanf("%d", &regis); getchar();	
			amount += regis;
			for(int i = 0; i < regis; i++){
				scanf("%s %s", name, type); getchar();
				pushMid(name, type);
			}
			print();
		}
		else if(strcmp(input, "REMOVE") == 0){
			char name[20];
			scanf("%d", &remove); getchar();
			amount -= remove;
			for(int i = 0; i < remove; i++){
				scanf("%s", name); getchar();
				popMid(name);
			}
			print();
		}
		else if(strcmp(input, "CALL") == 0){
			for(int i = 0; i < 4; i++){
				if(head && amount > 0){
					printf("%s ", head->name);
					popHead();
					amount--;
				}
			}
			puts("got into the boat.");
			printf("%d queues remaining.\n", amount);
		}
		if(amount <= 0) break;
		
		puts("");
	}
	
	return 0;
}
