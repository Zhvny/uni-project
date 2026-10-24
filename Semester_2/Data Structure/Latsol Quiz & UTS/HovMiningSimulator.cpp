#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	int key, depth, gold;
	data *left, *right, *parent;
}*root = NULL;

int count = 1, total = 0;

data* insert(data *curr, int key, int gold, data *parent){
	if(!curr){
		curr = (data*)malloc(sizeof(data));
		curr->key = key;
		curr->gold = gold;
		curr->depth = count;
		count = 1;
		curr->left = curr->right = NULL;
		curr->parent = parent;
	}
	else{
		count++;
		if(key < curr->key) curr->left = insert(curr->left, key, gold, parent);
		else curr->right = insert(curr->right, key, gold, parent);
	}
	return curr;
}

data* search(data* curr, int key){
	if(!curr) return NULL;
	else if(curr->key == key) return curr;
	else if(key < curr->key) return search(curr->left, key);
	else return search(curr->right, key); 
}

void inOrder(data* curr){
	if(curr->left) inOrder(curr->left);
	printf(">> Cave %d	(depth %d  ), total gold production: %d\n", curr->key, curr->depth, curr->gold);
	if(curr->right) inOrder(curr->right);
}

void inOrderGold(data* curr, int depth){
	if(curr->left) inOrderGold(curr->left, depth);
	if(curr->depth == depth) total += curr->gold;
	if(curr->right) inOrderGold(curr->right, depth);
}
int getHeight(data* curr){
	if(!curr) return 0;
	else{
		int left = getHeight(curr->left), right = getHeight(curr->right);
		return (left > right ? left : right) + 1;
	}
}


void totalGold(data* curr, int depth){
	if(!curr) return;
	else{
		if(curr->depth == depth && curr != root) total += curr->gold;
		totalGold(curr->left, depth);
		totalGold(curr->right, depth);
	}
}

data* popAll(data* curr){
	if(!curr) return NULL;
	curr->left = popAll(curr->left);
	curr->right = popAll(curr->right);
	free(curr);
	return NULL;
}
int main(){
	int choice = 0, key = 0, gold = 0;
	data* temp = NULL;
	do{
		puts("");
		puts("");
		puts("Hov Mining Simulator");
		puts("======================");
		puts("[1] Insert Mining Data");
		puts("[2] Display All Cave Data");
		puts("[3] Display Mining Reports");
		puts("[4] Exit");
		printf(">> ");
		scanf("%d", &choice); getchar();
		
		switch(choice){
			case 1:{
				do{
					printf("Input cave index [1-999]: ");
					scanf("%d", &key); getchar();
				}while(key < 1 || key > 999);
				
				do{
					printf("Input gold production [1-100]: ");
					scanf("%d", &gold); getchar();
				}while(gold < 1 || gold > 100);
				puts("");
				
				temp = search(root, key);
				if(!temp){
					puts("New cave index detected.");
					root = insert(root, key, gold, NULL);
					printf("Total gold production for Cave %d is %d.\n", key, gold);
				}
				else{
					puts("Cave index already exists.");
					temp->gold = gold;
					printf("New total gold production for Cave %d is %d.\n", key, gold);	
				}
				puts("");
				printf("Press any key to continue..."); getchar();
				break;
			}
			case 2:{
				if(root) inOrder(root);
				else puts("Cave data is empty, nothing to display.");
				printf("Press any key to continue..."); getchar();
				break;
			}
			case 3:{
				if(!root){
					puts("Cave data is empty, nothing to report.");
				}
				else{
					for(int i = 1; i <= getHeight(root); i++){
//						if(root->depth == i) total += root->gold;
						inOrderGold(root, i);
						printf(">> Total gold production for depth %d  is %d\n", i, total);
						total = 0;
					}
				}
				printf("\nPress any key to continue..."); getchar();
				break;
			}
		}
	}while(choice != 4);
	root = popAll(root);
	puts("All data has been removed from memory.");
	puts("Thank you for playing, see you again...");
	return 0;
}
