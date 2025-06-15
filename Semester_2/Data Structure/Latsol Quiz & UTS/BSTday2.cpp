#include <stdio.h>
#include <stdlib.h>

/*
input:
7
1
2
3
2
4
5
4

output:
1
2
3
3
4
5
5
*/

struct data{
	int val;
	data *left, *right, *parent;
}*root = NULL;

data* insert(data* curr, int val, data* parent){
	if(!curr){
		curr = (data*)malloc(sizeof(data));
		curr->parent = parent;
		curr->val = val;
		curr->left = curr->right = NULL;
	}
	else{
		if(val < curr->val) curr->left = insert(curr->left, val, curr);
		else if(val > curr->val) curr->right = insert(curr->right, val, curr);
	}
}

data* search(data *curr, int val){
	if(!curr) return NULL;
	else if(val < curr->val) return search(curr->left, val);
	else if(val > curr->val) return search(curr->right, val);
	else return curr;
}
int countNodes(data* curr){
	if(!curr) return NULL;
	else return 1 + countNodes(curr->left) + countNodes(curr->right);
}


int main(){
	
	int t, input;
	data* temp = NULL;
	scanf("%d", &t); getchar();
	int arr[t+3];
	for(int i = 0; i < t; i++){
		scanf("%d", &input); getchar();
		temp = search(root, input);
		if(!temp) root = insert(root, input, NULL);
		arr[i] = countNodes(root);
	}
	
	puts("");
	for(int i = 0; i < t; i++){
		printf("%d\n", arr[i]);
	}
	
	
	
	return 0;
}
