#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	Node *left;
	Node *right;
};

Node *root = NULL;

Node *createNewNode(int key){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode -> key = key;
	newNode -> right = newNode -> left = NULL;
	
	return newNode;
}

Node *push(Node *curr, int key){
	if (!curr){
		return createNewNode(key);
	}else if(key == curr->key){
		printf("Duplicate key!!\n");
//		return curr;
	}else if(key < curr->key){
		curr->left = push(curr->left, key);
	}else if(key > curr->key){
		curr->right = push(curr->right,key);
	}
	return curr;
}

void preOrder(Node *curr){
	if(curr){
		printf("%d\n",curr->key);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(Node *curr){
	if(curr){
		if(curr->left) inOrder(curr->left);
		printf("%d\n",curr->key);
		if(curr->right) inOrder(curr->right);
	}
}

void postOrder(Node *curr){
	if(curr){
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d\n",curr->key);
	}
}

Node* getPredecessor(Node *node){
	Node *temp = node->left;
	while(temp->right){
		temp = temp->right;
	}
	
	return temp;
}

Node* getSuccessor(Node *node){
	Node *temp = node->right;
	while(temp->left){
		temp = temp->left;
	}
	
	return temp;
}

Node* pop(Node *curr, int key){
	if(!root){
		printf("BST is empty!\n");
	}else if(!curr){
		printf("Key is not found!\n");
		return NULL;
	}else if(key < curr->key){
		curr->left = pop(curr->left,key);
	}else if(key > curr->key){
		curr->right = pop(curr->right,key);
	}else if(key == curr->key){
		if(!curr->left&&!curr->right){
			free(curr);
			curr = NULL;
		}else if(!curr->left){
			Node *replacement = curr->right;
			free(curr);
			curr = replacement;
		}else if(!curr->right){
			Node *replacement = curr->left;
			free(curr);
			curr = replacement;
		}else{
			Node *replacement = getPredecessor(curr);
			curr->key = replacement->key;
			curr->left = pop(curr->left, replacement->key);
		}
	}
	return curr;
}

int main(){
	root = push(root, 5);
	root = push(root, 2);
	root = push(root, 6);
	root = push(root, 1);
	root = push(root, 9);
	inOrder(root);
	
	return 0;
}
