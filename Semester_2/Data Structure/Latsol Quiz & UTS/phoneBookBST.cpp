#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book{
	char name[255], phone[50];
	book *left, *right, *parent;
}*root = NULL;

book* insert(book* curr, char name[], char phone[], book* parent){
	if(!curr){
		curr = (book*)malloc(sizeof(book));
		strcpy(curr->name, name);
		strcpy(curr->phone, phone);
		curr->parent = parent;
		curr->left = curr->right = NULL;
	}
	else{
		if(strcmp(name, curr->name) < 0) curr->left = insert(curr->left, name, phone, curr);
		else if(strcmp(name, curr->name) > 0) curr->right = insert(curr->right, name, phone, curr);
	}
	return curr;
}

book* search(book* curr, char name[]){
	if(!curr) return NULL;
	else if(strcmp(name, curr->name) < 0) return search(curr->left, name);
	else if(strcmp(name, curr->name) > 0) return search(curr->right, name);
	else return curr;
}

book* pop(book* curr, char name[]){
	if(!curr) return NULL;
	else if(strcmp(name, curr->name) < 0) curr->left = pop(curr->left, name);
	else if(strcmp(name, curr->name) > 0) curr->right = pop(curr->right, name);
	else{
		if(!curr->left || !curr->right){
			book *temp = NULL;
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
			// predecessor
			book* temp = curr->left;
			while(temp->right) temp = temp->right;
			strcpy(curr->name, temp->name);
			strcpy(curr->phone, temp->phone);
			curr->left = pop(curr->left, temp->name);
		}
	}
	return curr;
}

void inOrder(book *curr){
	if(curr->left) inOrder(curr->left);
	printf("Name: %s\n", curr->name);
	printf("Phone: %s\n", curr->phone);
	puts("");
	if(curr->right) inOrder(curr->right);
}
int main(){
	
	int choice = 0;
	book* temp = NULL;
	char phone[50], name[255];
	
	do{
		puts("");
		puts("");
		puts("1. Insert");
		puts("2. Search");
		puts("3. Delete");
		puts("4. View");
		puts("5. Exit");
		printf(">> ");
		scanf("%d", &choice); getchar();
		
		switch(choice){
			case 1:{
				printf("Input Name to Insert: ");
				scanf("%s", name); getchar();
				printf("Input Phone: ");
				scanf("%s", phone); getchar();
				temp = search(root, name);
				if(!temp) root = insert(root, name, phone, NULL);
				else puts("FAILED: Duplicate Data");
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 2:{
				printf("Input Name to Search: ");
				scanf("%s", name); getchar();
				temp = search(root, name);
				if(!temp) puts("FAILED: Data Not Found!");
				else{
					puts("Data Found!");
					printf("Name: %s\n", temp->name);
					printf("Phone: %s\n", temp->phone);
				}
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 3:{
				printf("Input Name to Delete: ");
				scanf("%s", name); getchar();
				temp = search(root, name);
				if(!temp) puts("FAILED: Data Not Found!");
				else{
					root = pop(root, name);
					puts("Delete Success!!");
				}
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 4:{
				if(root) inOrder(root);
				else puts("No Data in the BST!!");
				printf("Press enter to continue..."); getchar();
				break;
			}
		}
	}while(choice != 5);
	
	
	return 0;
}
