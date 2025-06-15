#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char name[100], job[25];
	int dmg, lvl;
	data *left, *right, *parent;
}*root = NULL;

data* insert(data* curr, char name[], char job[], int dmg, int lvl, data* parent){
	if(!curr){
		curr = (data*) malloc(sizeof(data));
		curr->parent = parent;
		curr->dmg = dmg;
		curr->lvl = lvl;
		strcpy(curr->name, name);
		strcpy(curr->job, job);
		curr->left = curr->right = NULL;
	}
	else{
		if(dmg < curr->dmg) curr->left = insert(curr->left, name, job, dmg, lvl, curr);
		else if(dmg > curr->dmg) curr->right = insert(curr->right, name, job, dmg, lvl, curr);
	}
	return curr;
}

data* search(data* curr, char name[]){
	if(!curr) return NULL;
	else if(strcmp(curr->name, name) == 0) return curr;
	else if(strcmp(name, curr->name) < 0) return search(curr->left, name);
	else if(strcmp(name, curr->name) > 0) return search(curr->right, name);
}

data* pop(data* curr, char name[]){
	if(!curr) return NULL;
	else if(strcmp(name, curr->name) < 0) curr->left = pop(curr->left, name);
	else if(strcmp(name, curr->name) > 0) curr->right = pop(curr->right, name);
	else{
		if(!curr->right || !curr->left){
			data *temp = NULL;
			if(curr->right) temp = curr->right;
			else temp = curr->left;
			
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
			curr->dmg = temp->dmg;
			curr->lvl = temp->lvl;
			strcpy(curr->name, temp->name);
			strcpy(curr->job, temp->job);
			curr->left = pop(curr->left, temp->name);
		}
	}
	return curr;
}

data* popAll(data* curr){
	if(!curr) return NULL;
	curr->left = popAll(curr->left);
	curr->right = popAll(curr->right);
	free(curr);
	return NULL;
}

void preOrder(data* curr){
	printf("%d ", curr->dmg);
	if(curr->left) preOrder(curr->left);
	if(curr->right) preOrder(curr->right);
}

void inOrder(data* curr){
	if(curr->left) inOrder(curr->left);
	printf("%d ", curr->dmg);
	if(curr->right) inOrder(curr->right);
}

void postOrder(data* curr){
	if(curr->left) postOrder(curr->left);
	if(curr->right) postOrder(curr->right);
	printf("%d ", curr->dmg);
}

void view(data* curr){
	printf("* %-25s | %-15s | lvl. %-04d | damage: %-05d\n", curr->name, curr->job, curr->lvl, curr->dmg);
	if(curr->left) view(curr->left);
	if(curr->right) view(curr->right);
}
int main(){
	
	char name[100], job[25];
	int dmg, lvl, choice;
	printf("%d\n", rand() % 50);
	printf("%d\n", rand() % 25);
	printf("%d\n", rand() % 75);
	do{
		puts("1. View All Characters");
		puts("2. Add New Character");
		puts("3. Inorder, Preorder, Postorder Character's Damage");
//		puts("4. Delete Characters");
		puts("4. Exit and Popall");
		puts("");
		printf(">> Input choice : ");
		scanf("%d", &choice); getchar();
		switch(choice){
			case 1:{
				if(!root) puts("--- There is No Character in The Tree ---");
				else{
					puts("Character List :\n");
					view(root);
				}
				break;
			}
			case 2:{
				int check = 1;
				do{
					check = 1;
					printf("Input Character's Name [3..20][non space char]: ");
					scanf("%[^\n]", &name); getchar();
					for(int i = 0; i < strlen(name); i++){
						if(name[i] == ' ') check = 0;
					}
				}while(strlen(name) < 3 || strlen(name) > 20 || check == 0);
				puts("");
				
				do{
					printf("Input Character's Job [fighter/rogue/mage]: ");
					scanf("%s", job); getchar();	
				}while(strcmp(job, "fighter") != 0 && strcmp(job, "rogue") != 0 && strcmp(job, "mage") != 0);
				puts("");
				
				do{
					printf("Input Character's Level [1..105]: ");
					scanf("%d", &lvl); getchar();
				}while(lvl < 1 || lvl > 105);
				
				if(strcmp(job, "fighter") == 0) dmg = lvl + (rand() % 50);
				else if(strcmp(job, "rogue") == 0) dmg = lvl + (rand() % 25);
				else if(strcmp(job, "mage") == 0) dmg = lvl + (rand() % 75);
				puts("");
				puts("");
				root = insert(root, name, job, dmg, lvl, NULL);
				puts("--- Add New Character Success ---");
				break;
			}
			case 3:{
				if(!root) puts("--- There is No Character in The Tree ---");
				else{
					printf("Preorder: "); preOrder(root);
					puts("");
					printf("Inorder: "); inOrder(root);
					puts("");
					printf("Postorder: "); postOrder(root);
					puts("");
				}
				break;
			}
//			case 4:{
//				char del[101];
//				printf("Input the hero name to be deleted: ");
//				scanf("%s", del); getchar();
//				data* temp = NULL;
//				temp = search(root, del);
//				if(!temp) puts("Data Not Found!");
//				else{
//					root = pop(root, name);
//					puts("Delete Success!");
//				}
//				break;
//			}
		}
		puts("");
		puts("");
	}while(choice != 4);
	root = popAll(root);
	if(!root) puts("--- There is No Character in The Tree ---");
	else view(root);
	
	return 0;
}
