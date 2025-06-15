//  Library for standard input and output
#include<stdio.h>
//  Library for string manipuation
#include<string.h>
//  Library for sleep() function
#include<unistd.h>
//  Library for clearscreen automaticly
#include<stdlib.h>

// Struct to store data based data naming on file.csv
struct data {
	char district[30];
	char city[30];
	int price;
	int rooms;
	int bathrooms;
	int carParks;
	char type[30];
	char furnish[30];
};

// Declare a struct to store struct data perline
struct data apartment[12545481823227];

// Declare index to count how many data in file.csv
long long int index = 0;

// Declare variabels as checker for sorting and searching data
int checker = 0;
int print = 0;
char YorN[4];

// Typing animation
void delayPrint(char *str)
{
    char *p;
    for (p = str; *p; p++) {
        putchar(*p);
        fflush(stdout);
        usleep(2000);
    }
}

// Loading animation
void sleepTime(){
	int i;
	for(i = 0; i < 3; i++){
		sleep(1);
		delayPrint(".");
	}
	sleep(1);
	delayPrint("\n");
}

// Print table
void printTable(){
	printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");
	printf("| %12s%-13s | %7s%-7s | %5s%-5s | %5s%-5s | %5s%-5s | %5s%-5s | %6s%-6s | %6s%-6s |\n", "LOCA","TION", "CI","TY", "PRI","CE", "ROO","MS", "BATH","ROOMS", "CARP", "ARK", "TY", "PE", "FURN", "ISH");
	printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");
}

// Column identification by name
int columnSearch(char column[]){
	if(strcmpi(column, "location") == 0){
		return 1;
	} else if(strcmpi(column, "city") == 0){
		return 2; 
	} else if(strcmpi(column, "price") == 0){
		return 3;
	} else if(strcmpi(column, "rooms") == 0){
		return 4;
	} else if(strcmpi(column, "bathrooms") == 0){
		return 5;
	} else if(strcmpi(column, "carparks") == 0){
		return 6;
	} else if(strcmpi(column, "type") == 0){
		return 7; 
	} else if(strcmpi(column, "furnish") == 0){
		return 8; 
	} else {
        delayPrint("\n.-. .-. .-. .-. .   |  .   \n");
        delayPrint("| | | | |-' `-. |     (    \n"); 
        delayPrint("`-' `-' '   `-' .   |  `   \n");
		delayPrint("Sorry, we couldn't find what you're looking for.\n");
		return 9;
	}
}

// Return interger to sorting
int sortCase(char sorting[]){
	if(strcmp(sorting, "asc") == 0){
		return 1;
	} else if (strcmp(sorting, "desc") == 0){
		return 2;
	}
	return -1;
}

// Return interger to yes or no
int YesOrNo(char YorN[]){
	if(strcmp(YorN, "yes") == 0){
		return 1;
	} else if (strcmp(YorN, "no") == 0){
		return 2;
	}
	return -1;
}

// Merge sort
void sort(int left, int mid, int right, int columnCase, int whichSort){
	int nLeft = mid - left + 1;
	int nRight = right - mid;
	struct data Left[nLeft];
	struct data Right[nRight];
	int a;
	for(a = 0; a < nLeft; a++){
		Left[a] = apartment[left + a];
	}
	for(a = 0; a < nRight; a++){
		Right[a] = apartment[mid + 1 + a];
	}
	int i = 0, j = 0, k = left;
	while(i < nLeft && j < nRight){
		switch(columnCase){
			case 1:
				if(whichSort == 1){
					if(strcmp(Left[i].district, Right[j].district) < 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].district, Right[j].district) > 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 2:
				if(whichSort == 1){
					if(strcmp(Left[i].city, Right[j].city) < 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].city, Right[j].city) > 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 3:
				if(whichSort == 1){
					if(Left[i].price < Right[j].price){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].price > Right[j].price){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 4:
				if(whichSort == 1){
					if(Left[i].rooms < Right[j].rooms){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].rooms > Right[j].rooms){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 5:
				if(whichSort == 1){
					if(Left[i].bathrooms < Right[j].bathrooms){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].bathrooms > Right[j].bathrooms){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 6:
				if(whichSort == 1){
					if(Left[i].carParks < Right[j].carParks){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].carParks > Right[j].carParks){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 7:
				if(whichSort == 1){
					if(strcmp(Left[i].type, Right[j].type) < 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].type, Right[j].type) > 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		case 8:
				if(whichSort == 1){
					if(strcmp(Left[i].furnish, Right[j].furnish) < 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].furnish, Right[j].furnish) > 0){
						apartment[k] = Left[i];
						i++;
					}
					else {
						apartment[k] = Right[j];
						j++;
					}
				}
			break;
		}
	k++;
	}
	while(i < nLeft){
		apartment[k++] = Left[i++];
	}
	while(j < nRight){
		apartment[k++] = Right[j++];
	}
}
void merge(int left, int right, int columnCase, int whichSort){
	int mid = left + (right - left)/2;
	if(left < right){
		merge(left, mid, columnCase, whichSort);
		merge(mid+1, right, columnCase, whichSort);
		sort(left, mid, right, columnCase, whichSort);
	}
}

// Search interger
void intSearch(int columnCase){
	long long int find;
	long long int i = 0;
	checker = 0;
	int forn = 0;	
	int response;
	delayPrint("What are you searching for? ");
	scanf("%lld", &find);
	getchar();
	switch(columnCase){
		case 3:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(apartment[i].price == find){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);	
			}while(checker == 0); 
			break;
		case 4:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(apartment[i].rooms == find){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);				
			}while(checker != 1); 
			break;
		case 5:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(apartment[i].bathrooms == find){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);
			}while(checker != 1); 
			break;
		case 6:	
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(apartment[i].carParks == find){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);				
			}while(checker != 1); 
			break;
	}
}

// Search string
void stringSearch(int columnCase){
	char find[30];
	long long int i = 0;
	checker = 0;
	int forn = 0;	
	int response;
	delayPrint("What are you searching for? ");
	scanf("%s", find);
	getchar();
	switch(columnCase){
		case 1:		
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(strcmpi(apartment[i].district, find)==0){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);				
			}while(checker != 1); 
			break;
		case 2:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(strcmpi(apartment[i].city, find)==0){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);			
			}while(checker != 1); 
			break;
		case 7:		
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(strcmpi(apartment[i].type, find)==0){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						delayPrint("--------------------------\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);		
			}while(checker != 1); 
			break;
		case 8:	
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						delayPrint("  \\,`/ / \n");
						delayPrint(" _)..  `_		  ___                   _ _   __  _ _  \n");
						delayPrint("( __  -\\		 | __|_ _ _ _ ___ _ _  | | | /  \\| | | \n");
						delayPrint("    '`.                  | _|| '_| '_/ _ | '_| |_  _| () |_  _|\n");
						delayPrint("   ( \\>_-_,		 |___|_| |_| \\___|_|     |_| \\__/  |_| \n");
						delayPrint("   _||_ ~-/ \n");
						delayPrint("\n");
						delayPrint("There is no data to show :(\n");
						checker = 1;
						return;
					}
					if(strcmpi(apartment[i].furnish, find)==0){
						if(forn == 0){
							delayPrint("Found it! Let me show you the details");
							sleepTime();
							printTable();	
							forn = 1;		
						}
						printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
						printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");	
						print++;
						if(print == 5){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						delayPrint("\n    |\\__/,|   (`\\\n");
						delayPrint("  _.|o o  |_   ) )\n");
						delayPrint("-(((---(((----------------\n");
						delayPrint("That's all there is to it!\n");
						return;
					}
				}
				do {
				delayPrint("Do you want to see more data [yes / no]? ");
				scanf("%[^\n]", YorN);
				getchar();	
				response = YesOrNo(YorN);
					if (response == 1) {
						system("cls");
						printTable();
					} else if (response == 2) {
						checker = 1;
					} 
				}
				while (response == -1);			
			}while(checker != 1);
			break;
	}
}

// Read data
void readFile(){
	FILE *fp = fopen("file.csv","r");
	if(fp == NULL){
		perror("Error!");
	}else{
		while(!feof(fp)){
		fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", apartment[index].district, apartment[index].city, &apartment[index].price, &apartment[index].rooms, &apartment[index].bathrooms, &apartment[index].carParks, apartment[index].type, apartment[index].furnish);
		index++;
		}
	}
	fclose(fp);
}

// Display data
void displayData(int rows){
	delayPrint("In response to your query\n");
	sleep(1);
	delayPrint("Here you go");
	sleepTime();
	printTable();
	int i;
	for(i = 0; i < rows; i++){
		printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
			apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
		printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");
	}
}

// Export data
void ExportData(char fileName[]){
	delayPrint("File Name : ");
	scanf("%[^\n]", fileName);
	getchar();
	strcat(fileName, ".csv");
	delayPrint("Wait! Exporting data");
	sleepTime();
	FILE *fn = fopen(fileName, "w");
	int i;
	for(i = 0; i < index; i++){
		printf(fn, "%s,%s,%d,%d,%d,%d,%s,%s\n", apartment[i].district,apartment[i].city,apartment[i].price,apartment[i].rooms,apartment[i].bathrooms,apartment[i].carParks,apartment[i].type,apartment[i].furnish);
	}
	fclose(fn);	
}

int main() {
	int userInput, rows, columnCase;
	char column[15];
	char sorting[10];
	char fileName[30];
	int response;
	readFile();
	do{
		do{
			system("cls");			
			delayPrint("========= SELECTION =========\n");
			delayPrint("What do you want to do?\n");
			delayPrint("1. Display data\n");
			delayPrint("2. Search data\n");
			delayPrint("3. Sort data\n");
			delayPrint("4. Export data\n");
			delayPrint("5. Exit\n");
			delayPrint("Your choice: ");
			scanf("%d", &userInput);
			getchar();
			}while(userInput < 1 || userInput > 5);
			switch(userInput){
				case 1: 
					do{
						delayPrint("Number of rows: ");
						scanf("%d", &rows);
						getchar();
					}while(rows < 0);
					if(rows > index){
						rows = index;
					}
					displayData(rows);	
					break;
				case 2:
					do{
						delayPrint("Choose column : ");
						scanf("%[^\n]", column);
						getchar();
						columnCase = columnSearch(column);
						if(columnCase == 1 || columnCase == 2 || columnCase == 7 || columnCase == 8){
							stringSearch(columnCase);
						} else if(columnCase == 3 || columnCase == 4 || columnCase == 5 || columnCase == 6){
							intSearch(columnCase);
						}						
					}while(columnCase == 9);
					break;
				case 3:
					checker = 0;
					int i; 
					rows = 5;
					int whichSort;
					do{
						delayPrint("Choose column : ");
						scanf("%s", column);
						getchar();
						columnCase = columnSearch(column);
					}while(columnCase == 9);
					do{
						whichSort = 0;
						delayPrint("Sort ascending / descending? [asc / desc] ");
						scanf("%[^\n]", sorting);
						getchar();
						whichSort = sortCase(sorting);
					}while(whichSort == -1);
					i = 0;
                    delayPrint("\n  _____  _                      __          __   _ _         \n");
                    delayPrint(" |  __ \\| |                     \\ \\        / /  (_) |        \n");
                    delayPrint(" | |__) | | ___  __ _ ___  ___   \\ \\  /\\  / /_ _ _| |_      \n");
                    delayPrint(" |  ___/| |/ _ \\/ _` / __|/ _ \\   \\ \\/  \\/ / _` | | __|     \n");
                    delayPrint(" | |    | |  __/ (_| \\__ \\  __/    \\  /\\  / (_| | | |_ _ _ _\n");
					delayPrint(" |_|    |_|\\___|\\__,_|___/\\___|     \\/  \\/ \\__,_|_|\\__(_|_|_)\n");
                    delayPrint("We're sorting the data");
					sleepTime();
					merge(0, index - 1, columnCase, whichSort);
					delayPrint("Sorting done!\n");
					sleep(1);
					printTable();
					do{
						for(i; i < rows; i++){
							printf("| %-25s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
								apartment[i].district, apartment[i].city, apartment[i].price, apartment[i].rooms, apartment[i].bathrooms, apartment[i].carParks, apartment[i].type, apartment[i].furnish);
							printf("+---------------------------+----------------+------------+------------+------------+------------+--------------+--------------+\n");
							if(i == index - 1){
								delayPrint("That's all!\n");
								break;
							}
						}
						do {
						delayPrint("Do you want to see more data [yes / no]? ");
						scanf("%[^\n]", YorN);
						getchar();	
						response = YesOrNo(YorN);
							if (response == 1) {
								system("cls");
								printTable(); 
								rows += 5;
								if(rows > index){
									rows = index;
								} 
							} else {
								checker = 1;
							}
						}while (response == -1);	
					}while(checker != 1 && rows <= index);
					break;
				case 4:
					ExportData(fileName);
					printf("Okay! exporting to %s finished!\n", fileName);
					sleep(1);
					break;
				case 5:
					system("cls");
					delayPrint("\n           _____   _  _     ___    _  _    _  __    ___      _   \n");
					delayPrint("    o O O |_   _| | || |   /   \\  | \\| |  | |/ /   / __|    | |  \n");
					delayPrint("   o        | |   | __ |   | - |  | .` |  | ' <    \\__ \\    |_|   \n");
					delayPrint("  TS__[O]  _|_|_  |_||_|   |_|_|  |_|\\_|  |_|\\_\\   |___/   _(_)_  \n");
					delayPrint(" {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_| \"\"\" | \n");
					delayPrint("./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' \n");  
					delayPrint("You are leaving the system");
					sleepTime();
					break;
			}
		delayPrint("Press ENTER to leaving the system\n");	
		getchar();
		fflush(stdout);
	}while(userInput != 5);
	return 0;
}