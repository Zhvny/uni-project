#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char name[10], priority[20];
	int prio;
	data *next, *prev;
}*head = NULL, *tail = NULL;

int amount = 0;

data* create(char name[], char priority[]){
	data* node = (data*)malloc(sizeof(data));
	strcpy(node->name, name);
	strcpy(node->priority, priority);
	if(strcmp(priority, "HIGH") == 0) node->prio = 1;
	else if(strcmp(priority, "LOW") == 0) node->prio = 2;
	node->next = node->prev = NULL;
	return node;
}

void pushHead(char name[], char priority[]){
	data* node = create(name, priority);
	if(!head) head = tail = node;
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char name[], char priority[]){
	data* node = create(name, priority);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void pushMid(char name[], char priority[]){
	data* node = create(name, priority);
	if(!head) head = tail = node;
	else if(node->prio < head->prio) pushHead(name, priority);
	else if(node->prio >= tail->prio) pushTail(name, priority);
	else{
		data* curr = head;
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
		data* del = head;
		head = head->next;
		head->prev = NULL;
		free(del);
	}
}

void popAll(){
	while(head){
		printf("%s is DONE.\n", head->name);
		popHead();
		amount--;
	}
}

void print(){
	puts("Task lists:");
	data* curr = head;
	int index = 1;
	while(curr){
		printf("%-02d %-06s %-06s\n", index, curr->name, curr->priority);
		index++;
		curr = curr->next;
	}
}



int main(){
	
	char input[20];
	while(true){
		scanf("%s", input); getchar();
		if(strcmp(input, "INSERT") == 0){
			char name[20], priority[20];
			scanf("%s %s", name, priority); getchar();
			if(strlen(name) == 4 && ((strcmp(priority, "HIGH") == 0) || (strcmp(priority, "LOW") == 0))){
				pushMid(name, priority);
				amount++;
			}
		}
		else if(strcmp(input, "VIEW") == 0){
			if(!head) puts("No Data!!");
			else print();
		}
		else if(strcmp(input, "DO") == 0){
			if(head){
				printf("%s is DONE.\n", head->name);
				popHead();
				amount--;
				if(amount > 0) printf("%d tasks remaining...\n", amount);
				else{
					printf("0 tasks remaining");
					break;
				}
			}
		}
		else if(strcmp(input, "DOALL") == 0){
			popAll();
			if(amount > 0) printf("%d tasks remaining...\n", amount);
			else{
				printf("0 tasks remaining");
				break;
			}
		}
		if(strcmp(input, "INSERT") != 0) puts("");
	}
	
	
	return 0;
}
