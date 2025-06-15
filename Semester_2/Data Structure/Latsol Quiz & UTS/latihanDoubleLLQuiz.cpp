#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Mhs{
	char name[25], nim[25];
	int age;
	Mhs *prev, *next;
	
}*head = NULL, *tail = NULL;

Mhs* create(char name[], char nim[], int age){
	Mhs* temp = (Mhs*)malloc(sizeof(Mhs));
	strcpy(temp->name, name);
	strcpy(temp->nim, nim);
	temp->age = age;
	temp->next = temp->prev = NULL;
	return temp;
}

void pushHead(char name[], char nim[], int age){
	Mhs* node = create(name, nim, age);
	if(!head) head = tail = node;
	else{
		head->prev = node;
		node->next = head;
		head = node;
	}
}

void pushTail(char name[], char nim[], int age){
	Mhs* node = create(name, nim, age);
	if(!head) head = tail = node;
	else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void pushMid(char name[], char nim[], int age){
	Mhs* node = create(name, nim, age);
	if(!head) head = tail = node;
	else if(node->age < head->age) pushHead(name, nim, age);
	else if(node->age > tail->age) pushTail(name, nim, age);
	else{
		Mhs* curr = head;
		while(curr && curr->age < node->age) curr = curr->next;
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
		Mhs* del = head;
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
		Mhs* del = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(del);
	}
}

void popMid(int age){
	if(!head) return;
	else if(head->age == age) popHead();
	else if(tail->age == age) popTail();
	else{
		Mhs* curr = head;
		while(curr->next && curr->next->age != age) curr = curr->next;
		if(!curr->next){
			puts("Not Found!");
			return;
		}
		else{
			Mhs* del = curr->next;
			curr->next = del->next;
			del->next->prev = curr;
			del = NULL;
			free(del);
		}
	}
}

void search(char name[]){
	if(!head){
		puts("data empty!!");
		return;
	}
	else{
		int index = 0;
		Mhs* curr = head;
		if(strcmp(curr->name, name) == 0) printf("Found %s at index %d\n", curr->name, index);
		else{
			while(curr->next && strcmp(curr->next->name, name) != 0) {
				curr = curr->next;
				index++;
			}
			if(!curr->next) puts("Data not Found!");
			else{
				printf("Found %s at index %d\n", curr->next->name, index+1);
			}
		}
	}
}
void print(){
	Mhs* curr = head;
	while(curr){
		printf("Nama: %s, NIM: %s, Usia: %d\n", curr->name, curr->nim, curr->age);
		curr = curr->next;
	}
}

int main(){
	
	char a[25];
	pushMid("davin", "192819", 40);
	pushMid("monik", "198939", 35);
	pushMid("dav", "1919", 28);
	pushMid("vin", "19234819", 29);
	pushMid("adada", "14449", 30);
	popHead();
	popTail();
	popMid(29);
	popMid(29);
	popMid(30);
	print();
	scanf("%s", a); getchar();
	search(a);
	
	return 0;
}
