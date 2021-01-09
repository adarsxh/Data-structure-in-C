#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *prev;
	node *next;
	node(int x){
		data = x;
		prev=next=NULL;
	}
};

void printlist(node *head){
	if(head==NULL)
		return;
	else{
		while(head!=NULL){
			cout<<(head->data)<<" ";
			head=head->next;
		}
			
	}
}

node *insertbegin(node *head, int x){
	node *temp=new node(x);
	if(head==NULL)
		return temp;
	else{
		temp->next=head;
		head->prev=temp;
		return temp;
	}
}
node *insertend(node *head, int x){
	node *temp=new node(x);
	if(head==NULL)
		return temp;
	else{
		node *curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
		temp->prev=curr;
		return head;
	}
}
node *reverse(node *head){
	if(head==NULL||head->next==NULL)
		return head;
	node *prev=NULL, *curr=head;
	while(curr!=NULL){
		prev=curr->prev;
		curr->prev=curr->next;
		curr->next=prev;
		curr=curr->prev;
	}
	return prev->prev;
}
node *delhead(node *head){
	if(head==NULL||head->next==NULL){
		delete(head);
		return NULL;
	}
	else{
		node *temp=head->next;
		temp->prev=NULL;
		head->next=NULL;
		delete(head);
		return temp;
	}
}
node *dellast(node *head){
	if(head==NULL||head->next==NULL)
		return NULL;
	else{
		node *curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		node *temp=curr->prev;
		temp->next=NULL;
		curr->prev=NULL;
		delete(curr);
		return head;
	}
}
int main(){
	node *head = NULL;
	head = insertend(head, 25);
/*	head = insertbegin(head, 15);
	head = insertbegin(head, 10);
	head = insertend(head, 35);
	head = insertend(head, 45);
	head = insertend(head, 55);*/
	printlist(head);
	cout<<endl;
	head = reverse(head);
	printlist(head);
//	head = delhead(head);
	cout<<endl;
	printlist(head);
	cout<<endl;
	head = dellast(head);
	printlist(head);
}
