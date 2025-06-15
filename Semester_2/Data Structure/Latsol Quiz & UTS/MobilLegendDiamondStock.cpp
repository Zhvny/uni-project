#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char date[20], name[20];
	int stock;
	data* prev, *next;
}*head = NULL, *head2 = NULL, *head3 = NULL, *tail = NULL, *tail2 = NULL, *tail3 = NULL;

int cepe = 0, gope = 0, ceceng = 0;

data* create(char date[], char name[], int stock){
	data* node = (data*)malloc(sizeof(data));
	node->stock = stock;
	strcpy(node->name, name);
	strcpy(node->date, date);
	node->next = node->prev = NULL;
	return node;
}

void push100(char date[], char name[], int stock){
	data* node = create(date, name, stock);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	cepe += stock;
}

void push500(char date[], char name[], int stock){
	data* node = create(date, name, stock);
	if(!head2) head2 = tail2 = node;
	else{
		tail2->next = node;
		node->prev = tail2;
		tail2 = node;
	}
	gope += stock;
}

void push1000(char date[], char name[], int stock){
	data* node = create(date, name, stock);
	if(!head3) head3 = tail3 = node;
	else{
		tail3->next = node;
		node->prev = tail3;
		tail3 = node;
	}
	ceceng += stock;
}

void popHead100(){
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

void popHead500(){
	if(!head2) return;
	else if(head2 == tail2){
		free(head2);
		head2 = tail2 = NULL;
	}
	else{
		data* del = head2;
		head2 = head2->next;
		head2->prev = NULL;
		free(del);
	}
}

void popHead1000(){
	if(!head3) return;
	else if(head3 == tail){
		free(head3);
		head3 = tail3 = NULL;
	}
	else{
		data* del = head3;
		head3 = head3->next;
		head3->prev = NULL;
		free(del);
	}
}


void popCategory(char name[]){
	if(strcmp(name, "100D") == 0){
		while(head){
			cepe -= head->stock;
			popHead100();
		} 
	}
	else if(strcmp(name, "500D") == 0){
		while(head2){
			gope -= head2->stock;
			popHead500();
		}
	}	
	else if(strcmp(name, "1000D") == 0){
		while(head3){
			ceceng -= head3->stock;
			popHead1000();
		}
	}
}

void print(){
	if(!head && !head2 && !head3){
		puts("NO DATA");
		return;
	}
	data* curr = head, *curr2 = head2, *curr3 = head3;
	printf("100D Stock: %d\n", cepe);
	while(curr){
		printf("%s : %02d item (%s)\n", curr->name, curr->stock, curr->date);
		curr = curr->next;
	}
	printf("500D Stock: %d\n", gope);
	while(curr2){
		printf("%s : %02d item (%s)\n", curr2->name, curr2->stock, curr2->date);
		curr2 = curr2->next;
	}
	printf("1000D Stock: %d\n", ceceng);
	while(curr3){
		printf("%s : %02d item (%s)\n", curr3->name, curr3->stock, curr3->date);
		curr3 = curr3->next;
	}
}

int main(){
	
	int t;
	scanf("%d", &t); getchar();
	char date[t+2][200], name[t+2][100], del[100];
	int stock[t+2];
	
	for(int i = 0; i < t; i++){
		scanf("%s %s %d", date[i], name[i], &stock[i]); getchar();
	}
	scanf("%s", del); getchar();
	
	for(int i = 0; i < t; i++){
		if(strcmp(name[i], "100D") == 0) push100(date[i], name[i], stock[i]);
		else if(strcmp(name[i], "500D") == 0) push500(date[i], name[i], stock[i]);
		else if(strcmp(name[i], "1000D") == 0) push1000(date[i], name[i], stock[i]);
	}
	print();
	popCategory(del);
	puts("Remaining Stock:");
	print();
	
	return 0;
}
