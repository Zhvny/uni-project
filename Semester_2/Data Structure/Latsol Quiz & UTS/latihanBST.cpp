#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	int val;
	data *left, *right, *parent;
}*root = NULL;

data* insert(data* curr, int val, data *parent){
	if(!curr){
		curr = (data*) malloc (sizeof(data));
		curr->parent = parent;
		curr->val = val;
		curr->left = curr->right = NULL;
	}
	else{
		if(val < curr->val) curr->left = insert(curr->left, val, curr);
		else if(val > curr->val) curr->right = insert(curr->right, val, curr);
	}
	return curr;
}

data *search(data *curr, int val){
	if(!curr) return NULL;
	else if(curr->val == val) return curr;
	else if(val < curr->val) return search(curr->left, val);
	else if(val > curr->val) return search(curr->right, val);
}

data *pop(data *curr, int val){
	if(!curr) return NULL;
	else if(val < curr->val) curr->left = pop(curr->left, val);
	else if(val > curr->val) curr->right = pop(curr->right, val);
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
			free(curr);
		}
		else{
			data *temp = curr->left;
			while(temp->right) temp = temp->right;
			curr->val = temp->val;
			curr->left = pop(curr->left, temp->val);
		}
	}
	return curr;
}

data *popAll(data *curr){
	if(!curr) return NULL;
	curr->left = popAll(curr->left);
	curr->right = popAll(curr->right);
	free(curr);
	return NULL;
}

void inOrder(data* curr){
	if(curr->left) inOrder(curr->left);
	printf("%d ", curr->val);
	if(curr->right) inOrder(curr->right);
}

void preOrder(data* curr){
	printf("%d ", curr->val);
	if(curr->left) preOrder(curr->left);
	if(curr->right) preOrder(curr->right);
}

void postOrder(data* curr){
	if(curr->left) postOrder(curr->left);
	if(curr->right) postOrder(curr->right);
	printf("%d ", curr->val);
}

int min(data *curr){
	if(!curr) return -1;
	if(!curr->left) return curr->val;
	else return min(curr->left);
}

int max(data *curr){
	if(!curr) return -1;
	if(!curr->right) return curr->val;
	else return max(curr->right);
}

int height(data *curr){
	if(!curr) return -1;
	else{
		int left = height(curr->left), right = height(curr->right);
		return (left > right ? left : right) + 1;
	}
}

int countNodes(data *curr){
	if(!curr) return 0;
	else return 1 + countNodes(curr->left) + countNodes(curr->right);
}

int main(){
	
	int choice = 0, key = 0;
	data* temp = NULL;
	do{
		puts("");
		puts("");
		printf("Min Nodes: %d\n", min(root));
		printf("Max Nodes: %d\n", max(root));
		printf("Height of BST: %d\n", height(root));
		printf("The Node Amount: %d\n", countNodes(root));
		puts("Menu");
		puts("=================");
		puts("");
		puts("1. Add Data");
		puts("2. View Data");
		puts("3. Search Data");
		puts("4. Delete Data");
		puts("5. Delete All Data");
		puts("6. Exit");
		printf("Choose [1-5]: ");
		scanf("%d", &choice); getchar();
		switch(choice){
			case 1:{ 
				printf("Input key to insert: ");
				scanf("%d", &key); getchar();
				temp = search(root, key);
				if(!temp) root = insert(root, key, NULL);
				else puts("FAILED: Duplicate Data");
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 2:{
				if(root){
					printf("Preorder: "); preOrder(root);
					puts("");
					printf("Inorder: "); inOrder(root);
					puts("");
					printf("Postorder: "); postOrder(root);
					puts("");
				}
				else puts("NO DATA!!");
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 3:{
				printf("Input key to search: ");
				scanf("%d", &key); getchar();
				temp = search(root, key);
				if(!temp) puts("Data Not Found!!");
				else printf("%d found at the BST\n", key);
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 4:{
				printf("Input key to delete: ");
				scanf("%d", &key); getchar();
				temp = search(root, key);
				if(!temp) puts("Data Not Found!!");
				else{
					root = pop(root, key);
					puts("Delete Successful!");
				}
				printf("Press enter to continue..."); getchar();
				break;
			}
			case 5:{
				if(root){
					root = popAll(root);
					puts("Delete All Success!");
				}
				else puts("NO DATA CAN BE DELETED!!");
				printf("Press enter to continue..."); getchar();
				break;
			}
		}
		puts("");
	}while(choice != 6);
	
	return 0;
}
