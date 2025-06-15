#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient{
	char name[40];
	int prio;
	patient *next, *prev;
}*head = NULL, *tail = NULL;

patient* create(char name[], char status[]){
	patient* node = (patient*) malloc (sizeof(patient));
	strcpy(node->name, name);
	if(strcmp(status, "Critical") == 0) node->prio = 1;
	else if(strcmp(status, "Serious") == 0) node->prio = 2;
	else if(strcmp(status, "Fair") == 0) node->prio = 3;
	else if(strcmp(status, "Good") == 0) node->prio = 4;
	node->prev = node->next = NULL;
	return node;
}

void pushHead(char name[], char status[]){
	patient* node = create(name, status);
	if(!head) head = tail = node;
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char name[], char status[]){
	patient* node = create(name, status);
	if(!head) head = tail = node;
	else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void pushMid(char name[], char status[]){
	patient* node = create(name, status);
	if(!head) head = tail = node;
	else if(node->prio < head->prio) pushHead(name, status);
	else if(node->prio >= tail->prio) pushTail(name, status);
	else{
		patient* curr = head;
		while(curr && node->prio >= curr->prio) curr = curr->next;
		node->next = curr;
		node->prev = curr->prev;
		curr->prev->next = node;
		curr->prev = node;
	}
}

void popHead(){
	if(!head) head = tail = NULL;
	else if(head == tail){
		if(head->prio == 1) printf("%s is in the Emergency Room\n", head->name); 
		else if(head->prio == 2) printf("%s is in the Examination Room\n", head->name); 
		else if(head->prio == 3 || head->prio == 4) printf("%s is in the Consultation Room\n", head->name); 
		free(head);
		head = tail = NULL;
	}
	else{
		if(head->prio == 1) printf("%s is in the Emergency Room\n", head->name); 
		else if(head->prio == 2) printf("%s is in the Examination Room\n", head->name); 
		else if(head->prio == 3 || head->prio == 4) printf("%s is in the Consultation Room\n", head->name); 
		patient* del = head;
		head = head->next;
		head->prev = NULL;
		free(del);
	}
}

void print(){
	if(!head){
		printf(" None\n");
		return;
	}
	patient* curr = head;
	while(curr){
		printf(" %s", curr->name);
		if(curr->next) printf(",");
		curr = curr->next;
	}
	puts("");
}

int main(){
	
	int n;
	scanf("%d", &n); getchar();
	for(int i = 0; i < n; i++){
//		if(head) print();
		char events[10], name[40], status[25];
		scanf("%s", events); getchar();
	
		if(strcmp(events, "ADD") == 0){
			scanf("%s %s", name, status); getchar();
			pushMid(name, status);
		}
		else if(strcmp(events, "CALL") == 0) popHead();
	}	
	
	printf("Waiting Room:");
	print();
	
	return 0;
}
