#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100


struct Product{
	
	char ID[5];
	char name[255];
	int price;
	int stock;
	char category[10];
	char expired[255];
	
	Product *next;
	
	
}*table[SIZE];


int hundreds = 0, tens = 0, ones = 1;

struct Product *createProduct(char ID[], char name[], int price, int stock, char category[], char expired[]){
	
	struct Product *newProduct = (Product*)malloc(sizeof(Product));
	
	strcpy(newProduct->ID, ID);
	strcpy(newProduct->name, name);
	newProduct->price = price;
	newProduct->stock = stock;
	strcpy(newProduct->category, category);
	strcpy(newProduct->expired, expired);
	
	newProduct->next = NULL;
	
	return newProduct;
}

int hashingKey(char ID[]){
	
	int key = (ID[0] * (ID[3] + ID[1] - ID[2])) % SIZE;
	
	return key;
}


void insert(char ID[], char name[], int price, int stock, char category[], char expired[]){
	
	int key = hashingKey(ID);
	struct Product *addNode = createProduct(ID, name, price, stock, category, expired);
	
	if(table[key] == NULL){
		table[key] = addNode;
		return;
	}
	else{
		Product *curr = table[key];
		
		while(curr->next != NULL){
			curr = curr->next;
		}
		
		curr->next = addNode;
	}
	
}

void display(){
	
	int checkKosong = 1;
	for(int i = 0; i < SIZE; i++){
		
		Product *curr = table[i];
		
		if(table[i] != NULL){
			
			checkKosong = 0;
			
			while(curr != NULL){
				printf("Product ID   : %s\n", curr->ID);
				puts("===================");
				printf("Product Name : %s\n", curr->name);
				printf("Product Price: %d\n", curr->price);
				printf("Product Stock: %d\n", curr->stock);
				printf("Expired Date : %s\n", curr->expired);
				puts("");
				
				curr = curr->next;
			}
		}
		
	}
	
	if(checkKosong == 1){
		puts("No Product Data");
	}
}

void addProduct(){
	
	char ID[5];
	char name[255];
	int price;
	int stock;
	char category[10];
	char expired[255];
	
	int day, month, year;
	
	do{
		printf("Insert Product Name [Must be more than 5 characters]: "); getchar();
		scanf("%[^\n]", &name); 
		
	}while(strlen(name) <= 5);
	
	do{
		printf("Insert Product Price [1 - 150000 (inclusive)]: "); getchar();
		scanf("%d", &price); 
		
	}while(price < 1 || price > 150000);
	
	do{
		printf("Insert Product Stock [more than 0]: "); getchar();
		scanf("%d", &stock); 
		
	}while(stock < 1);
	
	do{
		printf("Insert Product Category [Health | Food | Digital]: "); getchar();
		scanf("%s", &category); 
		
	}while(strcmp(category, "Health") != 0 && strcmp(category, "Food") != 0 && strcmp(category, "Digital") != 0);
	
	
	if(strcmp(category, "Digital") != 0){
		
		int minDay = 1, maxDay = 30;
		int minMonth = 1, maxMonth = 12;
		int minYear = 20, maxYear = 25;
		
		day = (rand() % (maxDay - minDay + 1)) + minDay;		
		month = (rand() % (maxMonth - minMonth + 1)) + minMonth;	
		year = (rand() % (maxYear - minYear + 1)) + minYear;
		
		sprintf(expired, "%d/%d/%d", day, month, year);
	}
	else{
		strcpy(expired, "-");
	}
	
	
	sprintf(ID, "%c%d%d%d", category[0], hundreds, tens, ones);
	ones++;
	if(ones == 10){
		ones = 0;
		tens++;
	}
	if(tens == 10){
		tens=0;
		hundreds++;
	}
	
//	printf("%s\n", ID);
//	printf("%s\n", name);
//	printf("%d\n", price);
//	printf("%d\n", stock);
//	printf("%s\n", category);
//	printf("%s\n", expired);

	insert(ID, name, price, stock, category, expired);
	puts("Product successfully added!"); getchar();
	
	
}

void deleteData(char ID[]){
	
	int key = hashingKey(ID);
	char confirmation;
	
	if(table[key] == NULL){
		puts("There is no data");
		return;
	}
	else if(table[key] != NULL && strcmp(table[key]->ID, ID) == 0){
		printf("Sure to delete %s ? [Y/N] (Case Insensitive): ", table[key]->ID); getchar();
		scanf("%c", &confirmation);
		
		if(confirmation == 'Y' || confirmation == 'y'){
			Product *erase = table[key];
			table[key] = table[key]->next;
			free(erase);
			erase = NULL;
			
			puts("Successfully erased data!"); getchar();
		}
	}
	else{
		Product *curr = table[key];
		
		while(curr->next != NULL && strcmp(curr->next->ID, ID) != 0){
			curr = curr->next;
		}
		
		if(curr->next == NULL){
			printf("Product doesnt exist"); getchar();
			return;
		}
		
		printf("Sure to delete %s ? [Y/N] (Case Insensitive): ", table[key]->ID); getchar();
		scanf("%c", &confirmation);
		
		if(confirmation == 'Y' || confirmation == 'y'){
			Product *erase = curr->next;
			curr->next = erase->next;
			free(erase);
			erase = NULL;
			
			puts("Successfully erased data!"); getchar();
		}
		
	}
	
}

int main(){
	
	int choice;
	
	do{
		system("cls");
		display();
		puts("");
		puts("MINI SO");
		puts("=======");
		puts("1. Add New Product");
		puts("2. Delete Product");
		puts("3. Exit");
		printf("Choose [1 - 3] > ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:{
				addProduct();
				break;
			}
			case 2:{
				char ID[5];
				printf("Input Product ID to delete: "); getchar();
				scanf("%s", &ID);
				
				deleteData(ID);
				
				break;
			}
			case 3:{
				break;
			}
			default:{
				puts("Pilih yang bener jancok");
				break;
			}
		}
		
	}while(choice != 3);
	
	
	return 0;
}






