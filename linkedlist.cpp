#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *root = NULL;

void append()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	
	if(root == 	NULL) root = temp;
	else{
		struct node *p;
		p = root;
		while(p->link !=NULL) p = p->link;
		
		p->link = temp;
	}
	
}

void display()
{
	struct node *temp;
	temp = root;
	if (temp == NULL) printf("List is empty");
	else{
		while(temp != NULL){
			printf("%d-->", temp->data);
			temp = temp->link;
		}
		
	}
}
int length()
{
	struct node *temp;
	int count = 1;
	temp = root;
	if(temp == NULL) return 0;
	else{
		while(temp->link != NULL){
			count++;
			temp = temp->link;
			
		}
	}
	return count;
}
void del()
{
	struct node *temp;
	int loc;
	temp = root;
	printf("\nEnter the delete loc: ");
	scanf("%d", &loc);
	if(loc>length()) printf("\nInvalid loc");
	else if(loc==1){
		root = temp->link;
		temp->link = NULL;
		free(temp);
		display();
	}
	else{
		struct node *p,*q;
		int i=1;
		p =root;
		while(i<loc-1){
			p = p->link;
			i++;
		}
		q= p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);
		display();
	}
	
}
void insert()
{
	struct node *temp;
	int loc;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	printf("\nEnter the loc: ");
	scanf("%d", &loc);
	if(loc>length() || loc<=0) printf("\ninvalid loc");
	else{
		struct node *p,*q;
		int count = 1;
		p = root;
		while(count< loc){
			p = p->link;
			count++;
		}
		q = p->link;
		
		temp->link = q;
		p->link = temp;
		display();
}
	
void swap()
{
	struct node *p,*q,*r;
	int loc,i=1;
	printf("\nEnter loc: ");
	scanf("%d", &loc);
	if(loc>length()) printf("\ninvalid location");
	else {
		p=root;
		while(i<loc-1){
		p = p->link
		i++;
	}
	q = q->link;
	r = q->link;
	}
	q->link = r->link;
	r->link = q;
	p->link = r;	
}


int main()
{
	int n;
	while(1){
		printf("1.Append\n");
		printf("2.Insert\n");
		printf("3.Delete\n");
		printf("4.Display\n");
		printf("5.Length\n");
		printf("6.Swap\n");
		printf("7.EXIT\n");
		
		printf("\nEnter your choice: ");
		scanf("%d", &n);
		
		switch(n){
			case 1: append();
					break;
			case 2: insert();
					break;
			case 3: del();
					break;
			case 4: display();
					break;
			case 5: printf("\nLength: %d", length());
					break;
			case 6: swap();
					break;
			case 7: exit(1);
			default: printf("\nInvalid input");		
			
		}
	}
}
	


