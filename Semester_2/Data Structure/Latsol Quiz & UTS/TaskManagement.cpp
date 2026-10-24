#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int id = 1;

struct task{
	char desc[100], name[20], due[15], status[20];
	int id;
	task *prev, *next;	
} *head = NULL, *tail = NULL;

task* create(char desc[], char name[], char due[], int id){
	task* node = (task*) malloc (sizeof(task));
	strcpy(node->desc, desc);
	strcpy(node->name, name);
	strcpy(node->due, due);
	strcpy(node->status, "Pending");
	node->id = id;
	node->prev = node->next = NULL;
	return node;
}

void pushHead(char desc[], char name[], char due[], int id){
	task* node = create(desc, name, due, id);
	if(!head) head = tail = node;
	else{
		head->prev = node;
		node->next = head;
		head = node;
	}
}

void pushTail(char desc[], char name[], char due[], int id){
	task* node = create(desc, name, due, id);
	if(!head) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void pushMid(char desc[], char name[], char due[], int id){
	task* node = create(desc, name, due, id);
	if(!head) head = tail = node;
	else if(strcmp(node->due, head->due) < 0) pushHead(desc, name, due, id);
	else if(strcmp(node->due, tail->due) >= 0) pushTail(desc, name, due, id);
	else{
		task* curr = head;
		while(curr && strcmp(curr->due, node->due) <= 0) curr = curr->next;
		node->next = curr;
		node->prev = curr->prev;
		curr->prev->next = node;
		curr->prev = node;
	}
}

void popHead(){
	if(!head) return;
	else if(head == tail){
		strcpy(head->status, "Completed");
		printf("Task details:\n");
		printf("ID: %d\n", head->id);
		printf("Description: %s\n", head->desc);
		printf("Assigned Employee: %s\n", head->name);
		printf("Due Date: %s\n", head->due);
		printf("Status: %s\n", head->status);
		puts("");
		free(head);
		head = tail = NULL;
	}
	else{
		strcpy(head->status, "Completed");
		printf("Task details:\n");
		printf("ID: %d\n", head->id);
		printf("Description: %s\n", head->desc);
		printf("Assigned Employee: %s\n", head->name);
		printf("Due Date: %s\n", head->due);
		printf("Status: %s\n", head->status);
		task* del = head;
		head = head->next;
		head->prev = NULL;
		free(del);
	}
}

void print(){
	printf("%-05s%-40s%-25s%-16s%-08s\n", "ID", "Task Description", "Assigned Employee", "Due Date", "Status");
	task* curr = head;
	while(curr){
		printf("%-05d%-40s%-25s%-16s%-08s\n", curr->id, curr->desc, curr->name, curr->due, curr->status);
		curr = curr->next;
	}
}

int main(){
	
	int n;
	char inputDesc[100], inputName[20], inputDue[15];
	printf("Number of tasks: ");
	scanf("%d", &n); getchar();
	for(int i = 0; i < n; i++){
		puts("");
		printf("Task Description: ");
		scanf("%[^\n]", &inputDesc); getchar();
		printf("Assign Employee: ");
		scanf("%[^\n]", &inputName); getchar();
		printf("Due Date: ");
		scanf("%[^\n]", &inputDue); getchar();
		pushMid(inputDesc, inputName, inputDue, id);
		id++;
	}
	puts("");
	print();
	puts("");
	
	char reachedDue[5];
	int popAmount;
	printf("Is there any task that has reached its due date? ");
	scanf("%s", reachedDue); getchar();
	if(strcmp(reachedDue, "Yes") == 0){
		printf("How many? ");
		scanf("%d", &popAmount); getchar();
		for(int i = 0; i < popAmount; i++){
			puts("");
			popHead();
		}
	}
	puts("");
	puts("The rest tasks:");
	print();
	
	return 0;
}
