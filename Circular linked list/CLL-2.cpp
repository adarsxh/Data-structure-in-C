#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x){
		data=x;
		next = NULL;
	}
};
void printlist(node *head){
	if(head==NULL)
		return ;
	cout<<(head->data)<<" ";
	for(node *p=head->next;p!=head;p=p->next){
		cout<<(p->data)<<" ";
	}
}
node *insertbegin(node *head,int x){
	node *temp=new node(x);
	if(head==NULL)
		temp->next=temp;
	else{
		node *curr=head;
		while(curr->next!=head){
			curr=curr->next;
		}
		curr->next=temp;
		temp->next=head;
	}
	return temp;
}
 node *insertbegin2(node *head, int x){
	node *temp=new node(x);
	if(head==NULL){
		temp->next=temp;
		return temp;
	}
	else{
		temp->next=head->next;
		head->next=temp;
		int t=temp->data;
		temp->data=head->data;
		head->data=t;
	}
	return head;
 }

int main(){
	node *head= new node(10);
	head->next = new node(20);
	head->next->next = new node(30);
	head->next->next->next = new node(40);
	head->next->next->next->next=head;
	printlist(head);
	cout<<endl;
	head = insertbegin2(head, 5);
	printlist(head);
}
