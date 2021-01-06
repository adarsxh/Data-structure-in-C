#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x){
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

void printmiddle(node *head){
	if(head==NULL)
		return;
	node *slow=head, *fast=head;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	cout<<(slow->data);
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

int main(){
	node *head = new node(10);
	node *temp1 = new node(20);
	node *temp2 = new node(30);
	node *temp3 = new node(40);
	head->next = temp1;
	temp1->next = temp2;
	temp2->next = temp3;
	head = insertend(head, 50);
	head = insertend(head, 60);
	
	printlist(head);
	cout<<endl;
	printmiddle(head);
}
