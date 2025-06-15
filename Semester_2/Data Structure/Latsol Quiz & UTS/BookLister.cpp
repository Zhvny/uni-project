#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book{
	char genre[30], name[255], code[10];
	book *prev, *next;
}*head = NULL, *tail = NULL;

book* newBook(char genre[], char code[], char name[]){
	book* temp = (book*) malloc(sizeof(book));
	strcpy(temp->genre, genre);
	strcpy(temp->code, code);
	strcpy(temp->name, name);
	temp->prev = temp->next = NULL;
	return temp;
}

void pushMid(char genre[], char code[], char name[]){
	book* node = newBook(genre, code, name);
	if(!head) head = tail = node;
	else if(strcmp(node->name, head->name) < 0){
		node->next = head;
		head->prev = node;
		head = node;
	}
	else if(strcmp(node->name, tail->name) > 0){
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	else{
		book* curr = head;
		while(curr && strcmp(curr->name, node->name) < 0) curr = curr->next;
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
		book* del = head;
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
		book* del = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(del);
	}
}

void popMid(char input[], char del[]){
	if(!head) return;
	if(strcmp(input, "Name") == 0){
		if(strcmp(head->name, del) == 0) popHead();
		else if(strcmp(tail->name, del) == 0) popTail();
		else{
			book* curr = head;
			while(curr->next && strcmp(curr->next->name, del) != 0) curr = curr->next;
			if(!curr->next) return;
			else{
				book* del = curr->next;
				curr->next = del->next;
				del->next->prev = curr;
				del = NULL;
				free(del);
			}
		}
	}
	else if(strcmp(input, "Code") == 0){
		if(strcmp(head->code, del) == 0) popHead();
		else if(strcmp(tail->code, del) == 0) popTail();
		else{
			book* curr = head;
			while(curr->next && strcmp(curr->next->code, del) != 0) curr = curr->next;
			if(!curr->next) return;
			else{
				book* del = curr->next;
				curr->next = del->next;
				del->next->prev = curr;
				del = NULL;
				free(del);
			}
		}
	}
	else if(strcmp(input, "Genre") == 0){
		book* curr = head;
		while(curr){
			if(strcmp(curr->genre, del) == 0 && curr == head){
				popHead();
				curr = curr->next;
			}
			else if(strcmp(curr->genre, del) == 0 && curr == tail){
				popTail();
				curr = curr->next;
			}
			else if(strcmp(curr->genre, del) == 0){
				book* del = curr;
				curr = curr->next;
				curr->prev = del->prev;
				del->prev->next = curr;
				free(del);
			}
			else curr = curr->next;
		}
	}
}
void print(){
	book* curr = head;
	while(curr){
		printf("%s %s %s\n", curr->genre, curr->code, curr->name);
		curr = curr->next;
	}
}
int main(){
	
	char input[20], name[255], genre[20], code[20], del[25];
	int n;
	scanf("%d", &n); getchar();
	scanf("%s", input); getchar();
	for(int i = 0; i < n; i++){
		scanf("%s %s %[^\n]", genre, code, &name); getchar();
		pushMid(genre, code, name);
	}
	scanf("%[^\n]", del); getchar();
	puts("");
	print();
	popMid(input, del);
	puts("");
	print();
	
}
