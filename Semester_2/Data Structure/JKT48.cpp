#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int val;
	char ch[20];
	struct Node *next, *prev;
} *head = NULL, *tail = NULL;

struct Node* newNode(char ch[], int val) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	strcpy(node->ch, ch);
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void pushHead(char ch[], int val) {
	struct Node* node = newNode(ch, val);
	if (head == NULL) {
		head = tail = node;
	} else {
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char ch[], int val) {
	struct Node* node = newNode(ch, val);
	if (head == NULL) {
		head = tail = node;
	} else {
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void push(char ch[], int val) {
	struct Node* node = newNode(ch, val);
	if (head == NULL) {
		head = tail = node;
	} else if (head->val > val) {
		pushHead(ch, val);
	} else if (tail->val < val) {
		pushTail(ch, val);
	} else {
		struct Node* current = head;
		while (current && current->val < val) {
			current = current->next;
		}
		node->next = current;
		node->prev = current->prev;
		current->prev->next = node;
		current->prev = node;
	}
}

void popHead() {
	if (head == NULL) {
		printf("No Data\n");
	} else if (head == tail) {
		free(head);
		head = tail = NULL;
	} else {
		struct Node* temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}

void popTail() {
	if (head == NULL) {
		printf("No Data\n");
	} else if (head == tail) {
		free(head);
		head = tail = NULL;
	} else {
		struct Node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	}
}

void pop(int val) {
	if (head == NULL) {
		printf("No Data\n");
	} else if (head == tail) {
		free(head);
		head = tail = NULL;
	} else if (val == head->val) {
		popHead();
	} else if (val == tail->val) {
		popTail();
	} else {
		struct Node* current = head;
		while (current && current->val != val) {
			current = current->next;
		}
		if (!current) {
			printf("No Data\n");
		} else {
			current->prev->next = current->next;
			current->next->prev = current->prev;
			free(current);
		}
	}
}

void print() {
	if (head == NULL) {
		printf("No Data\n");
	} else {
		struct Node* current = head;
		while (current) {
			printf("Nama: %s, No: %d\n", current->ch, current->val);
			current = current->next;
		}
	}
}

int main() {
	push("Kevin", 3000);
	push("Adel", 5);
	push("Christy", 6);
	push("Feni", 9);
	push("Muthe", 10);
	push("Gita", 11);
	push("Marsha", 12);
	push("Flora", 8);
	push("Freya", 4);
	push("Gracia", 1);
	push("Michie", 2);
	push("Zee", 7);
	push("Kathrina", 3);

	pop(3000);

	print();

	return 0;
}

