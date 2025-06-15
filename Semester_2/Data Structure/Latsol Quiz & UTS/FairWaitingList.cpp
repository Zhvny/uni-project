#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct people{
	int id;
	people *prev, *next;
}*head = NULL, *tail = NULL, *head2 = NULL, *tail2 = NULL, *head3 = NULL, *tail3 = NULL;


people* create(int id){
	people* temp = (people*)malloc(sizeof(people));
	temp->id = id;
	temp->next = temp->prev = NULL;
	return temp;
}

void push(int id){
	people* node = create(id);
	if(!head) head = tail = node;
	else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void push2(int id){
	people* node = create(id);
	if(!head2) head2 = tail2 = node;
	else{
		node->prev = tail2;
		tail2->next = node;
		tail2 = node;
	}
}

void pushNewQueue(int id){
	people* node = create(id);
	if(!head3) head3 = tail3 = node;
	else{
		node->prev = tail3;
		tail3->next = node;
		tail3 = node;
	}
}

void popHead(){
	if(!head3) return;
	else if(head3 == tail3){
		free(head3);
		head3 = tail3 = NULL;
	}
	else{
		people* del = head3;
		head3 = head3->next;
		head3->prev = NULL;
		free(del);
	}
}

void popTail(){
	if(!head3) return;
	else if(head3 == tail3){
		free(head3);
		head3 = tail3 = NULL;
	}
	else{
		people* del = tail3;
		tail3 = tail3->prev;
		tail3->next = NULL;
		free(del);
	}
}

void popQueue(int id){
	if(!head) return;
	else if(head->id == id) popHead();
	else if(tail->id == id) popTail();
	else{
		people* curr = head3;
		while(curr->next && curr->next->id != id) curr = curr->next;
		people* del = curr->next;
		curr->next = del->next;
		del->next->prev = curr;
		del = NULL;
		free(del);
	}
}

int main(){
	
	int online, walkin, onlineID, walkinID, delAmount, delNum;
	scanf("%d %d", &online, &walkin); getchar();
	for(int i = 0; i < online; i++){
		scanf("%d", &onlineID); 
		push(onlineID);
	}
	getchar();
	
	for(int i = 0; i < walkin; i++){
		scanf("%d", &walkinID); 
		push2(walkinID);
	}
	getchar();
	
	people* curr = head;
	people* curr2 = head2;
	while(curr || curr2){
		if(curr){
			pushNewQueue(curr->id);
			curr = curr->next;
		}
		
		if(curr2){
			pushNewQueue(curr2->id);
			curr2 = curr2->next;
		}
	}
	
	scanf("%d", &delAmount); getchar();
	for(int i = 0; i < delAmount; i++){
		scanf("%d", &delNum); getchar();
		popQueue(delNum);
	}
	
	puts("");
	people* curr3 = head3;
	while(curr3){
		printf("%d ", curr3->id);
		curr3 = curr3->next;
	}
	return 0;
}
