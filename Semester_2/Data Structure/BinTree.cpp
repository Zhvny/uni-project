#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

Node *create(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data){
    if(root == NULL){
        root = create(data);
        return root;
    }
    // Ke Kiri
    if(root->data > data){
        root->left = insert(root->left, data);
    }
    // Ke Kanan
    else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

void printAll(Node *root){
    if(root != NULL){
        printAll(root->left);
        printf("%d -> ", root->data);
        printAll(root->right);
        // Atas = Pre-order (prefix)
        // Tengah = In-order (infix)
        // bawah = Post-order (postfix)
    }
}


//	Predecessor = nilai terbesar di <subtree kiri> = 5
//  Successor = nilai terkecil di <subtree kanan> = 6
Node *getPredecessor(Node *root){
	Node *current = root->left; //	Kalo successor root->right;
	while(current->right != NULL) current = current->right; //	Kalo successor curr->left != NULL, current->left;
	return current;
}

//	Search lalu buang
Node *deleteNode(Node *root, int data){
	//	Search
	if(root == NULL) return root;
	if(root->data > data){
		root->left = deleteNode(root->left, data);
	}
	else if(root->data < data){
		root->right = deleteNode(root->right, data);
	}
	
	//	Udah pasti ketemu
	
	//	Kalo ga punya anak
	if(root->left == NULL && root->right == NULL){
		free(root);
		root = NULL;
		return root;
	}
	//	Kalo punya anak
	//	Anak kiri
	if(root->right == NULL){
		Node *temp = root;
		root = root->left;
		free(temp);
	}
	//	Anak kanan
	else if(root->left == NULL){
		Node *temp = root;
		root = root->right;
		free(temp);
	}
	// Anak kiri & kanan (2 anak) (ini cotoh predecessor)
	else{
		Node *predecessor = getPredecessor(root);
		root->data = predecessor->data;
		root->left = deleteNode(root->left, root->data);
	}
	return root;
}

void freeTree(Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
//  Node *root = (Node*)malloc(sizeof(Node));
	Node *root = NULL;
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 12);
    root = insert(root, 9);
    
    root = deleteNode(root, 3);
    
    printf("In-order traversal: ");
    printAll(root);
    printf("\n");
    freeTree(root);
    return 0;
}
