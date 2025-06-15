#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct andy{
	char card[4];
	andy *prev, *next;
}*head = NULL, *tail = NULL;

struct bob{
	char card[4];
	bob *prev, *next;
}*head2 = NULL, *tail2 = NULL;
	
andy* createAndy(char card[]){
	andy* node = (andy*) malloc (sizeof(andy));
	strcpy(node->card, card);
	node->next = node->prev = NULL;
	return node;
}

bob* createBob(char card[]){
	bob* node = (bob*) malloc (sizeof(bob));
	strcpy(node->card, card);
	node->next = node->prev = NULL;
	return node;
}

void pushAndy(char card[]){
	andy* node = createAndy(card);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void pushBob(char card[]){
	bob* node = createBob(card);
	if(!head2) head2 = tail2 = node;
	else{
		tail2->next = node;
		node->prev = tail2;
		tail2 = node;
	}
}

void popAndy(char card[]){
	if(!head) return;
	else if(strcmpi(head->card, card) == 0){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}
		else{
			andy* del = head;
			head = head->next;
			head->prev = NULL;
			free(del);
		}
	}
	else if(strcmpi(tail->card, card) == 0){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}
		else{
			andy* del = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(del);
		}
	}
	else{
		andy* curr = head;
		while(curr->next && strcmpi(curr->next->card, card) != 0) curr = curr->next;
		if(!curr->next){
			puts("Not Found");
			return;
		}
		else{
			andy* del = curr->next;
			curr->next = del->next;
			del->next->prev = curr;
			del = NULL;
			free(del);
		}
	}
}

void popBob(char card[]){
	if(!head2) return;
	else if(strcmpi(head2->card, card) == 0){
		if(head2 == tail2){
			free(head2);
			head = tail = NULL;
		}
		else{
			bob* del = head2;
			head2 = head2->next;
			head2->prev = NULL;
			free(del);
		}
	}
	else if(strcmpi(tail2->card, card) == 0){
		if(head2 == tail2){
			free(head2);
			head2 = tail2 = NULL;
		}
		else{
			bob* del = tail2;
			tail2 = tail2->prev;
			tail2->next = NULL;
			free(del);
		}
	}
	else{
		bob* curr = head2;
		while(curr->next && strcmpi(curr->next->card, card) != 0) curr = curr->next;
		if(!curr->next){
			puts("Not Found");
			return;
		}
		else{
			bob* del = curr->next;
			curr->next = del->next;
			del->next->prev = curr;
			del = NULL;
			free(del);
		}
	}
}

void printAndy(){
	andy* curr = head;
	while(curr){
		printf("%s", curr->card);
		if(curr->next) printf(" <-> ");
		curr = curr->next;
	}
}

void printBob(){
	bob* curr = head2;
	while(curr){
		printf("%s", curr->card);
		if(curr->next) printf(" <-> ");
		curr = curr->next;
	}
}
int main(){
	char Andy[4], Bob[4];
	puts("Andy discard card phase");
	pushAndy("7R");
	pushAndy("4B");
	pushAndy("3R");
	pushAndy("6B");
	pushAndy("8R");
	pushAndy("3B");
	pushAndy("5R");
	printAndy();
	
	for(int i = 0; i < 2; i++){
		puts("");
		if(i == 0) printf("enter 1st card label to delete: ");
		else printf("enter 2nd card label to delete: ");
		scanf("%s", Andy); getchar();
		popAndy(Andy);
		printAndy();
	}
	
	puts("\n");
	puts("Bob discard card phase");
	pushBob("4R");
	pushBob("2B");
	pushBob("1B");
	pushBob("6R");
	pushBob("0R");
	pushBob("2B");
	pushBob("7B");
	printBob();
	
	for(int i = 0; i < 2; i++){
		puts("");
		if(i == 0) printf("enter 1st card label to delete: ");
		else printf("enter 2nd card label to delete: ");
		scanf("%s", Bob); getchar();
		popBob(Bob);
		printBob();
	}
	puts("\n");
	puts("Andy Cards:");
	printAndy();
	puts("");
	puts("Bob Cards:");
	printBob();
	puts("");
	
	andy* curr = head;
	bob* curr2 = head2;
	int bobScore = 0, andyScore = 0;

	while(curr && curr2){
		if(strcmp(curr->card, curr2->card) > 0) andyScore++;
		else if(strcmp(curr2->card, curr->card) > 0) bobScore++;
		curr = curr->next;
		curr2 = curr2->next;
	}
	
	puts("");
	printf("Andy Points: %d\n", andyScore);
	printf("Bob Points: %d\n", bobScore);
	puts("");
	
	if(andyScore > bobScore) puts("Andy Wins!");
	else if(andyScore < bobScore) puts("Bob Wins!");
	else puts("Draw!");
	
	return 0;
}
