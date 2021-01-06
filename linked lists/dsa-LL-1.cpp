#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node (int x){
		data = x;
		next = NULL;
	}
};

void printlist(node *head){
	while(head!=NULL){
		cout<<(head->data)<<"\t";
		head=head->next;
	}
}
void printlistrec(node *head){
	if(head==NULL)
		return;
	cout<<(head->data)<<"\t";
	printlistrec(head->next);
}

int search(node *head, int x){
	int pos=1;
	while(head!=NULL){
		if(head->data==x)
			return pos;
		else{
			pos++;
			head=head->next;
		}
	}
	return -1;
}
node* insertbegin(node *head, int x){
	node *temp = new node(x);
	temp->next=head;
	return temp;
}

node* insertend(node *head, int x){
	node *temp=new node(x);
	if(head==NULL)
		return temp;
	node *curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next = temp;
	return head; 
}

node *delhead(node *head){
	if(head==NULL)
		return NULL;
	else{
		node *temp=head->next;
		delete(head);
		return temp;
	}
}
node* dellast(node* head){
	if(head==NULL)
		return NULL;
	if(head->next==NULL){
		delete(head);
		return NULL;
	}
	node *curr=head;
	while(curr->next->next!=NULL)
		curr=curr->next;
	delete(curr->next);
	curr->next=NULL;
	return head;
}

node * insertpos(node* head, int x, int pos){
	node *temp=new node(x);
	if(pos==1){
		return insertbegin(head, x);
	}
	node* curr = head;
	for(int i=0;i<pos-2&&curr!=NULL;i++){
		curr=curr->next;
	}
	if(curr==NULL)
		return NULL;
	temp->next=curr->next;
	curr->next=temp;
	return head;
}
node* insertsorted(node* head, int x){
	node* temp = new node(x);
	if(head==NULL){
		return temp;
	}
	if(x<head->data){
		temp->next=head;
		return temp;
	}
	node* curr=head;
	while(curr->next!=NULL&&curr->next->data<x){
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
}
int main(){
	node *head = new node(10);
	node *temp1 = new node(20);
	node *temp2 = new node(30);
	node *temp3 = new node(40);
	head->next = temp1;
	temp1->next = temp2;
	temp2->next = temp3;
	cout<<"Iteratively: \n";
	printlist(head);
	cout<<"\nRecursively: \n";
	printlistrec(head);
	cout<<"\nSearching 3\n";
	cout<<search(head, 3)<<"\n";
	cout<<"\nInserting at beginning: "<<endl;
	head = insertbegin(head, 5);
	printlist(head);
	cout<<"\nInserting at end: "<<endl;
	head = insertend(head, 60);
	printlist(head);
	head = delhead(head);
	cout<<"\nDeleting head: "<<endl;
	printlist(head);
	head = dellast(head);
	cout<<"\nDeleting last: "<<endl;
	printlist(head);
	cout<<"\nInserting 45 at 4: "<<endl;
	head = insertpos(head, 35, 4);
	head = insertpos(head, 5, 1);
	printlist(head);
	head = insertsorted(head, 25);
	cout<<"\nInserting sorted: "<<endl;
	printlist(head);
	return 0;
}
