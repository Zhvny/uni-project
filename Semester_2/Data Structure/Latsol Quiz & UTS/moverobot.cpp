#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char command[12], level[12];
	int prio;
	data *next, *prev;
}*head = NULL, *tail = NULL;

data* create(char lev[], char comm[]){
	data* node = (data*)malloc(sizeof(data));
	strcpy(node->command, comm);
	strcpy(node->level, lev);
	if(strcmp(lev, "CRITICAL") == 0) node->prio = 1;
	else if(strcmp(lev, "HIGH") == 0) node->prio = 2;
	else if(strcmp(lev, "NORMAL") == 0) node->prio = 3;
	else if(strcmp(lev, "LOW") == 0) node->prio = 4;
	node->prev = node->next = NULL;
	return node;
}

void pushHead(char lev[], char comm[]){
	data* node = create(lev, comm);
	if(!head) head = tail = node;
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char lev[], char comm[]){
	data* node = create(lev, comm);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void move(char lev[], char comm[]){
	data* node = create(lev, comm);
	if(!head) head = tail = node;
	else if(node->prio < head->prio) pushHead(lev, comm);
	else if(node->prio >= tail->prio) pushTail(lev, comm);
	else{
		data *curr = head;
		while(curr && curr->prio <= node->prio) curr = curr->next;
		node->next = curr;
		node->prev = curr->prev;
		curr->prev->next = node;
		curr->prev = node;
	}
}
int x = 0, y = 0;
void print(){
	data *curr = head;
	while(curr){
		if(strcmp(curr->command, "up") == 0) y++;
		else if(strcmp(curr->command, "down") == 0 && y-1 >= 0) y--;
		else if(strcmp(curr->command, "left") == 0 && x-1 >= 0) x--;
		else if(strcmp(curr->command, "right") == 0) x++;
		printf("%s %s\n", curr->level, curr->command);
		curr = curr->next;
	}
	printf("Result = (%d, %d)\n", x, y);
}

int main(){
	move("HIGH", "up");
	move("LOW", "right");
	move("NORMAL", "up");
	move("CRITICAL", "up");
	move("CRITICAL", "up");
	move("HIGH", "down");
	move("CRITICAL", "up");

	move("NORMAL", "left");
	move("NORMAL", "right");
	move("HIGH", "up");
	move("CRITICAL", "left");
	move("LOW", "right");
	move("LOW", "up");
	move("HIGH", "right");
	move("LOW", "down");
	print();
	
	return 0;
}
