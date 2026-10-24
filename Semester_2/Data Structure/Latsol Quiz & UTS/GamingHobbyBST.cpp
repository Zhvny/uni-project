#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char name[100];
	int rating;
	data *left, *right, *parent;
}*root = NULL;

data* insert(data* curr, char name[], int rating, data* parent){
	if(!curr){
		curr = (data*)malloc(sizeof(data));
		curr->parent = parent;
		curr->rating = rating;
		strcpy(curr->name, name);
		curr->right = curr->left = NULL;
	}
	else{
		if(strcmpi(name, curr->name) < 0) curr->right = insert(curr->right, name, rating, curr);
		else curr->left = insert(curr->left, name, rating, curr);
	}
	return curr;
}

data* search(data* curr, char name[]){
	if(!curr) return NULL;
	else if(strcmpi(name, curr->name) < 0) return search(curr->right, name);
	else if(strcmpi(name, curr->name) > 0) return search(curr->left, name);
	else if(strcmpi(name, curr->name) == 0) return curr;
}

data* pop(data* curr, char name[]){
	if(!curr) return NULL;
	else if(strcmpi(name, curr->name) < 0) curr->right = pop(curr->right, name);
	else if(strcmpi(name, curr->name) > 0) curr->left = pop(curr->left, name);
	else{
		if(!curr->right || !curr->left){
			data* temp = NULL;
			if(curr->left) temp = curr->left;
			else temp = curr->right;
			
			if(!temp){
				temp = curr;
				curr = NULL;
			}
			else{
				temp->parent = curr->parent;
				*curr = *temp;
			}
			free(temp);
		}
		else{
			data* temp = curr->left;
			while(temp->right) temp = temp->right;
			curr->rating = temp->rating;
			strcpy(curr->name, temp->name);
			curr->left = pop(curr->left, temp->name);
		}
	}
	return curr;
}
void inOrder(data* curr){
	if(curr->left) inOrder(curr->left);
	printf("Name: %s	Rating: %d\n", curr->name, curr->rating);
	if(curr->right) inOrder(curr->right);
}

int main(){
	
	int choice = 0, rating = 0;
	char name[200];
	data* temp = NULL;
	do{
		puts("");
		if(root) inOrder(root);
		else puts("No Data!");
		puts("");
		puts("1. Insert");
		puts("2. Delete");
		puts("3. Exit");
		printf(">> ");
		scanf("%d", &choice); getchar();
		switch(choice){
			case 1:{
				do{
					printf("Insert Game Name: ");
					scanf("%s", name); getchar();
				}while(strlen(name) < 1 || strlen(name) > 100);
				
				do{
					printf("Insert Rating: ");
					scanf("%d", &rating); getchar();
				}while(rating < 1 || rating > 10);
				
				temp = search(root, name);
				if(!temp){
					root = insert(root, name, rating, NULL);
					puts("Insert Success!");
				}
				else puts("FAILED: Duplicate Data");
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 2:{
				printf("Insert Game Name: ");
				scanf("%s", name); getchar();
				temp = search(root, name);
				if(!temp) puts("Game name does not exist!");
				else{
					root = pop(root, name);
					puts("Delete Success!");
				}
				printf("Press enter to continue..."); getchar();
				break;
			}
		}	
	}while(choice != 3);

	
	return 0;
}
