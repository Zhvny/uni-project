#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

struct tables{
    char name[20];
}*head[size]={NULL};

int hashFunction(char name[])
{
    int first=0;
	int second=0;
	int sum=0;
	first+=name[0]/10;
	second+=name[strlen(name)-1]%10;
	sum=first*10+second;
	return sum%20+1;
}

void addHash(char name[])
{
    int hashVal=hashFunction(name);
    struct tables *newHash=(struct tables*)malloc(sizeof(struct tables));
    strcpy(newHash->name, name);
    if(head[hashVal]==NULL)
        head[hashVal]=newHash;
    else
    {
       int temp=hashVal+1;
		while(temp!=hashVal){
			if(temp>20){
				temp-=20;
			}
			if(head[temp]==NULL){
				head[temp]=newHash;
				break;
			}
			temp++;
		}
		if(temp==hashVal){
			return;
		}
    }
}

void printHashTable()
{
    for(int i=1; i<=size; i++)
    {
       if(head[i]!=NULL){
			printf("[%02d]%s\n",i, head[i]->name);
		}else{
			printf("[%02d]EMPTY\n",i);
		}
    }
}

int main()
{
    addHash("IRENE");
    addHash("INEKE");
    addHash("AMORA");
    addHash("ANDARAMITA");
    addHash("FADHIL");
    addHash("PRAZ");
    addHash("MICHAEL");
    addHash("BELA");
    printHashTable();
    return 0;
}
