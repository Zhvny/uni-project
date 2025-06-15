#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char name[20];
	char prio[15];
	int priority;
	int hour;
	int minute;
	struct data *next;
}*head=NULL, *tail=NULL;

int getPrio(char prio[]){
	if(strcmp(prio,"Premium")==0){
		return 4;
	}else if(strcmp(prio,"VIP")==0){
		return 3;
	}else if(strcmp(prio,"VVIP")==0){
		return 2;
	}else if(strcmp(prio,"Regular")==0){
		return 1;
	}else{
		return -1;
	}
}

void insert(char prio[], char name[], int hour, int minute){
	struct data *newData=(data*)malloc(sizeof(data));
	newData->hour=hour;
	newData->minute=minute;
	strcpy(newData->name, name);
	strcpy(newData->prio,prio);
	int priority=getPrio(prio);
	newData->priority=priority;
	newData->next=NULL;
	
	struct data *ptr;
	
	if(head==NULL){
		head=tail=newData;
	}else if(head->hour>newData->hour){
		newData->next=head;
		head=newData;
	}else if(tail->hour<newData->hour){
		tail->next=newData;
		tail=newData;
	}else{
		ptr=head;
		while(ptr->hour<newData->hour&&ptr->next!=NULL){
			ptr=ptr->next;
		}
		while(ptr->minute<=newData->minute&&ptr->next!=NULL){
			ptr=ptr->next;
		}
		
		if(ptr->hour==newData->hour&&ptr->minute==newData->minute){
			while(ptr->priority>newData->priority&&ptr->next!=NULL){
				ptr=ptr->next;	
			}
		}
		newData->next=ptr->next;
		ptr->next=newData;
	}
}

void print(){
	struct data *ptr=head;
	while(ptr!=NULL){
		printf("[%s] %s - %02d:%02d\n", ptr->prio, ptr->name, ptr->hour, ptr->minute);
		ptr=ptr->next;
	}
}

int main(){
	int n;
	scanf("%d", &n); getchar();
	for(int i=0; i<n; i++){
		char prio[15], name[20];
		int hour, minute;
		scanf("%s %s %d:%d", prio, name, &hour, &minute);
		getchar();
		insert(prio, name, hour, minute);
	}
	print();
}
