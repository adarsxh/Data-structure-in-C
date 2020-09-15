#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node *root=NULL;

void append(){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right =NULL;
	if(root==NULL) root = temp;
	else{
		struct node *p;
		p = root;
		while(p->right!=NULL) 	p = p->right;
		p->right= temp;
		temp->left=p;
	}
}

void addatbegin(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d", &temp->data);
	temp->right=NULL;
	temp->left = NULL;
	if(root ==NULL) root=temp;
	else{
		temp->right = root;
		root->left = temp;
		root = temp;
	}
}

int length(){
	struct node *temp;
	int count=0;
	if(root == NULL) printf("\nempty list");
	else{
		temp = root;
		while(temp!=NULL){
			count++;
			temp=temp->right;
		}
		return count;
	}
}

void display(){
	struct node *temp;
	temp = root;
	while(temp!=NULL){
		printf("%d<-->",temp->data);
		temp = temp->right;
	}
}

void addafter(){
	struct node *temp, *p;
	int loc, len, i;
	printf("\nEnter th  location");
	scanf("%d",&loc);
	len = length();
	if(loc>len) {
		printf("\nInvalid location");
		printf("\nonly %d nodes in the list", len);
	}
	else{
		temp = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter node data: ");
		scanf("%d",&temp->data);
		temp->left=NULL;
		temp->right=NULL;
		
		p = root;
		while(i<loc){
			p = p->right;
			i++;
		}
		temp->right = p->right;
		p->right->left = temp;
		p->right = temp;
		temp->left=p;
	}
}

void reverse(){
	struct node *temp;
	temp = root;
	while(temp->right!=NULL) 
		temp = temp->right;
	printf("\n Reverse: ");
	while(temp!=NULL){
		printf("%d<-->", temp->data);
		temp = temp->left;
	}
	
}
void del(){
	struct node *temp;
	int  loc, len;
	printf("\nEnter location: ");
	scanf("%d", &loc);
	len = length();
	temp = root;
	if(loc>len) printf("\nInvalid location");
	else if(loc ==1){
			root = temp->right;
			temp->right->left = NULL;
			temp->right = NULL;
			free(temp);
			}
		
	else{
		struct node *p, *q;
		int i=1;
		p = root;
		while(loc-1>i){
			p=p->right;
			i++;
		}
		q = p->right;
		printf("\n%d",q->data);
		p->right = q->right;	
		q->right->left=p;
		q->right=NULL;
	
		q->left = NULL;
		free(q);
		
	}
	
}

int main(){
	int n;
	while(1){
		printf("\n1.APPPEND");
		printf("\n2.ADD AT BEGINNING");
		printf("\n3.LENGHT");
		printf("\n4.DISPLAY");
		printf("\n5.ADD AT LOCATION");
		printf("\n6.DELETE");
		printf("\n7.REVERSE");
		printf("\n8.EXIT");
		
		printf("\nEnter your choice: ");
		scanf("%d", &n);
		
		switch(n){
			case 1: append();
					break;
			case 2: addatbegin();
					break;
			case 3: printf("\nLenght: %d",length());
					break;
			case 4: display();
					break;
			case 5: addafter();
					break;
			case 6: del();
					break;
			case 7: reverse();
					break;
			case 8: exit(1);
			default: printf("\nEnter valid input");
		}
	}
	
}


















