#include <stdio.h>
#include <stdlib.h>

/*
6
3 2 7 5 4 1 

outputnya:
2 4
*/

struct data{
	int val;
	data *prev, *next;
}*head = NULL, *tail = NULL;

data* create(int val){
	data *node = (data*)malloc(sizeof(data));
	node->val = val;
	node->next = node->prev = NULL;
	return node;
}

void push(int val){
	data* node = create(val);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
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

void popTail(){
	if(!head) return;
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		data* del = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(del);
	}
}

void popOdd(){
	data* curr = head;
	while(curr){
		if(curr->val % 2 != 0 && curr == head){ // di head
			popHead();
		}
		else if(curr->val % 2 != 0 && curr == tail){ // di tail
			popTail();
		}
		else if(curr->val % 2 != 0){ // di tengah
			data* del = curr;
			curr->prev->next = del->next;
			del->next->prev = curr->prev;
			del = NULL;
			free(del);
		}
		curr = curr->next;
	}
}

void print(){
	data* curr = head;
	while(curr){
		printf("%d ", curr->val);
		curr = curr->next;
	}
}
int main(){
	
	int t, input;
	scanf("%d", &t); getchar();
	for(int i = 0; i < t; i++){
		scanf("%d", &input);
		push(input);
	}
	getchar();
	popOdd();
	print();
	
	
	
	return 0;
}
