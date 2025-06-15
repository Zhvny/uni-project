#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char id[10];
    char name[50];
    int qty;
    struct medicine *left, *right;
};

struct medicine *addMedicine(struct medicine *cur, char id[], char name[], int qty)
{
    if(cur==NULL)
    {
        struct medicine *newMed=(medicine*)malloc(sizeof(medicine));
        strcpy(newMed->id, id);
        strcpy(newMed->name, name);
        newMed->qty=qty;
        newMed->left=NULL;
        newMed->right=NULL;
        cur=newMed;
    }
    else if(strcmp(id, cur->id)<0)
        cur->left=addMedicine(cur->left, id, name, qty);
    else if(strcmp(id, cur->id)>0)
        cur->right=addMedicine(cur->right, id, name, qty);
    else
    {
        //the id is the same as an existing id, so add stock
        cur->qty+=qty;
    }
    return cur;
}

struct medicine *findLeftMostRight(struct medicine *cur)
{
    while(cur->left!=NULL){
    	cur=cur->left;
	}
	return cur;
}

struct medicine *deleteMed(struct medicine *cur, char id[], int qty)
{
    struct medicine *temp;
    if(cur==NULL)
    {
        printf("medicine %s is not found..\n", id);
    }
    else if(strcmp(id, cur->id)<0)
        cur->left=deleteMed(cur->left, id, qty);
    else if(strcmp(id, cur->id)>0)
        cur->right=deleteMed(cur->right, id, qty);
    else
    {
        //id is found
        if(qty>cur->qty){
			printf("Quantity of medicine %s is not enough...\n", id);
		}else if(cur->qty>qty){
			cur->qty-=qty;
		}else{
			//delete data
			if(cur->left==NULL&&cur->right==NULL){
        		cur=NULL;
        		free(cur);
			}else if(cur->left==NULL){
				temp=cur->right;
				cur=temp;
				free(temp);
			}else if(cur->right==NULL){
				temp=cur->left;
				cur=temp;
				free(temp);
			}else{
				temp=findLeftMostRight(cur->right);
				strcpy(cur->id, temp->id);
				strcpy(cur->name, temp->name);
				cur->qty=temp->qty;
				cur->right=deleteMed(cur->right, temp->id, temp->qty);
			}
		}
    }
    return cur;
}

void inOrder(struct medicine *cur)
{
    if(cur!=NULL)
    {
        inOrder(cur->left);
        printf("%s - %-15s : %d\n", cur->id, cur->name, cur->qty);
        inOrder(cur->right);
    }
}

int main()
{
    struct medicine *root=NULL;
    root=addMedicine(root, "MED020", "Amoxicillin", 2);
    root=addMedicine(root, "MED020", "Amoxicillin", 3);
    root=addMedicine(root, "MED011", "Paracetamol", 1);
    root=addMedicine(root, "MED035", "Levothyroxine", 2);
    root=addMedicine(root, "MED017", "Omeprazole", 1);
    root=addMedicine(root, "MED011", "Paracetamol", 1);
    root=addMedicine(root, "MED015", "Atorvastatin", 5);
    root=deleteMed(root, "MED035", 3);
    root=deleteMed(root, "MED015", 3);
    root=deleteMed(root, "MED020", 5);
    inOrder(root);
    return 0;
}
