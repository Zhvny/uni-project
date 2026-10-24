#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char MEMBERSHIP_TYPE[][100] = {" ", "Non-Member", "Bronze", "Silver", "Gold", "Platinum"};
struct Menu{
	int id;
	char name[100];
	int price;
};

struct Customer{
	int id;
	char name[100];
	int membershipType;
};

struct Order{
	int menuId;
	int quantity;
	char notes[200];
};

struct Queue{
	char orderId[9];
	Customer customer;
	Order customerOrders[100];
	int orderCount;
	Queue* next;
	Queue* prev;
};

Queue* HEAD = NULL;
Queue* TAIL = NULL;

Menu menus[100];
int menuCount;
	
Customer customers[105];
int customerCount;

int read_customer_data(){
	//ignoring index 0
	int count = 1;
	
	FILE *f = fopen("customers.txt", "r");
	
	if( f == NULL )
		return -1;
	
	while(!feof(f)){
		fscanf(f, "%d#%[^\#]#%d\n", &customers[count].id, &customers[count].name, &customers[count].membershipType);
		count++;
	}
	fclose(f);
	return count;
}

int read_menu_data(){
	//ignoring index 0
	int count = 1;
	
	FILE *f = fopen("menus.txt", "r");
	
	if( f == NULL )
		return -1;
	
	while(!feof(f)){
		fscanf(f, "%d#%[^\#]#%d\n", &menus[count].id, &menus[count].name, &menus[count].price);
		count++;
	}
	fclose(f);
	return count;
}

char* generate_order_id(Customer customer){
	char orderId[9];
	orderId[0] = '0';
	orderId[1] = customers[customer.id].membershipType + '0';
	orderId[2] = '-';
	orderId[3] = rand()%26 + 'A';
	orderId[4] = rand()%26 + 'A';
	orderId[5] = rand()%10 + '0';
	orderId[6] = rand()%10 + '0';
	orderId[7] = rand()%10 + '0';
	orderId[8] = rand()%10 + '0';
	orderId[9] = '\0';
	return orderId;
}

Queue* create_queue(Customer customer, Order* customerOrders, int orderCount){
	int i = 0;
	
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	strcpy(queue->orderId, generate_order_id(customer));
	queue->customer = customer;
	
	for( int i=0 ;  i<orderCount ; i++ ){
		queue->customerOrders[i] = customerOrders[i];
	}
	
//	queue->customerOrders = customerOrders;
	queue->orderCount = orderCount;
	queue->next = NULL;
	queue->prev = NULL;
	return queue;	
}

void push_head(Queue* node){
	if( !HEAD ){
		HEAD = TAIL = node;
	}
	else{
		node->next = HEAD;
		HEAD->prev = node;
		HEAD = node;
	}
}

void push_tail(Queue* node){
	if( !HEAD ){
		HEAD = TAIL = node;
	}
	else{
		TAIL->next = node;
		node->prev = TAIL;
		TAIL = node;
	}
}

void push(Queue* node){
	if( !HEAD ){
		push_head(node);
	}
	else if( node->customer.membershipType > HEAD->customer.membershipType ){
		push_head(node);
	}
	else if( node->customer.membershipType <= TAIL->customer.membershipType ){
		push_tail(node);
	}
	else{
		Queue* curr = HEAD;
		while( node->customer.membershipType <= curr->customer.membershipType ){
			curr = curr->next;
		}
		curr->prev->next = node;
		node->prev = curr->prev;
		node->next = curr;
		curr->prev = node;
	}
}

void pop(){
	if( !HEAD ){
		printf(" There is no order in the queue!\n");
		return;
	}
	else if( HEAD == TAIL ){
		printf(" Finished preparation for order ID %s (%s).\n", HEAD->orderId, HEAD->customer.name);
		free(HEAD);
		HEAD = TAIL = NULL;
	}
	else{
		printf(" Finished preparation for order ID %s (%s).\n", HEAD->orderId, HEAD->customer.name);
		HEAD = HEAD->next;
		free(HEAD->prev);
		HEAD->prev = NULL;
	}
}

void pop_head(){
	if( !HEAD ){
		return;
	}
	else if( HEAD == TAIL ){
		free(HEAD);
		HEAD = TAIL = NULL;
	}
	else{
		HEAD = HEAD->next;
		free(HEAD->prev);
		HEAD->prev = NULL;
	}
}

void pop_all(){
	while( HEAD ){
		pop_head();
	}
}

Customer find_customer(char* name){
	Customer temp;
	temp.id = -1;
	temp.membershipType = 1;
	strcpy(temp.name, name);
	
	//ignoring index 0
	for(int i=1 ; i<customerCount ; i++){
		if( strcmp(customers[i].name, name) == 0 )
			return customers[i];
	}
	
	return temp;
}

void view_menus(){
	printf(" %2s %-25s %7s\n", "ID", " Name", "   Price");
	for(int i=1 ; i<menuCount ; i++){
		printf(" %2d  %-25s %7d\n", menus[i].id, menus[i].name, menus[i].price);
	}
}

void view_order(Order* orders, int count){
	int total = 0;
	int subtotal = 0;
	for(int i = 0 ; i<count ; i++){
		subtotal = orders[i].quantity * menus[orders[i].menuId].price;
		printf(" %3d x %-25s = %d\n", orders[i].quantity, menus[orders[i].menuId].name, subtotal);
		total += subtotal;
	}
	printf(" Total order is %d.\n", total);
}

void view_queue(){
	
	if( !HEAD ){
		printf(" There is no order in the queue!\n");
		return;	
	}
		
	Queue* curr = HEAD;
	int count = 1;
	while(curr){
		printf(" Queue No.%03d\n", count);
		printf(" Order ID  : %s\n", curr->orderId);
		printf(" Customer  : %s\n", curr->customer.name);
		printf(" Order List:\n");
		view_order(curr->customerOrders, curr->orderCount);
		count++;
		printf("\n\n");
		curr = curr->next;
	}
}


int main(){
	
	srand(time(NULL));
	
//	Read customer data from customers.txt
	customerCount = read_customer_data();	
	if( customerCount == -1 ){
		printf(" Fail to load customer data.\nApplication terminated\n.");
		return -1;
	}
	
//	Read menu data from menus.txt
	menuCount = read_menu_data();	
	if( menuCount == -1 ){
		printf(" Fail to load menu data.\nApplication terminated\n.");
		return -1;
	}

	int menu;
	int menuIdOrdered;
	int quantityOrdered;
	
	Customer customer;
	Order orders[100];
	int orderCount = 0;
	
	
	char customerName[100];
	
	do{
		system("cls");
		printf(" Hov's Fresh Concoction\n");
		printf(" ======================\n");
		printf(" 1. Add New Order\n");
		printf(" 2. View Order Queue\n");
		printf(" 3. Serve Order\n");
		printf(" 4. Exit\n");
		printf(" >> ");
		
		scanf("%d", &menu);
		fflush(stdin);
		
		switch(menu){
			
			case 1:
				system("cls");
				
				printf(" Input customer name: ");
				scanf("%[^\n]", &customerName);
				fflush(stdin);
				customer = find_customer(customerName);
				
//				Check whether customer data exists
				if( customer.id != -1 ){
					printf("\n Membership data found!\n");
					printf(" Customer ID    : %d\n", customer.id);
					printf(" Customer Name  : %s\n", customer.name);
					printf(" Membership Type: %s\n", MEMBERSHIP_TYPE[customer.membershipType]);
				}
				else{
					printf("\n Membership data not found!\n");
				}
				
				printf("\n Press ENTER to order...");
				getchar();
				
				
				orderCount = 0;
				do{
					system("cls");
					view_menus();
					
					printf("\n Input Menu ID to be added [-1 to finish order]: ");
					scanf("%d", &menuIdOrdered);
					fflush(stdin);
										
//						Input -1 to end order						
					if( menuIdOrdered == -1 ){
						system("cls");
						printf(" Please wait to be seated.\n Below is your order details:\n");
						view_order(orders, orderCount);
						
//						Add to queue
						push(create_queue(customer, orders, orderCount));
						break;	
					}
					
					if( menuIdOrdered < 1 || menuIdOrdered >= menuCount ){
						printf(" Invalid Menu ID!\n");
						getchar();
					}
					else{
						orders[orderCount].menuId = menuIdOrdered;
						do{							
							printf(" Input quantity for \"%s\": ", menus[orders[orderCount].menuId].name);
							scanf("%d", &quantityOrdered);
							fflush(stdin);
							
							if( quantityOrdered < 1 ){
								printf(" Invalid quantity (minimum 1)!\n");
								getchar();
							}
							else{
								orders[orderCount].quantity = quantityOrdered;
								
								printf(" \"%s\" x %3d added to the order.", menus[orders[orderCount].menuId].name, orders[orderCount].quantity = quantityOrdered);
								getchar();
								break;
							}
						}while (1);
						orderCount++;
					}					
				}while( 1 );
								
				
				printf("\n Press ENTER to back to Main Menu...");
				getchar();
				break;
				
			case 2:
				system("cls");
				view_queue();
				printf("\n Press ENTER to back to Main Menu...");
				getchar();
				break;
				
			case 3:
				system("cls");
				pop();
				printf("\n Press ENTER to back to Main Menu...");
				getchar();
				break;
			
		}
		
	}while(menu != 4);

	pop_all();

	return 0;
}
