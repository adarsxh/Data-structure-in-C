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
		return;
	cout<<(head->data)<<" ";
	for(node *p=head->next;p!=head;p=p->next){
		cout<<(p->data)<<" ";
	}
}

node *delnode(node *head){
	if(head==NULL) return NULL;
	else if(head->next==head){
		delete(head);
		return NULL;
	}
	else{
		node *curr=head;
		while(curr->next!=head)
			curr=curr->next;
		curr->next=head->next;
		delete(head);
		return (curr->next);
	}
}
node *delhead(node *head){
	if(head==NULL||head->next==head){
		delete(head);
		return NULL;
	}
	else{
		head->data=head->next->data;
		node *temp=head->next;
		head->next=temp->next;
		delete(temp);
		return head;
	}
}

node *delknode(node *head, int k){
	if(head==NULL)
		return head;
	if(k==1){
		node *temp=head->next;
		int t=temp->data;
		temp->data=head->data;
		head->data=t;
		head->next=temp->next;
		delete(temp);
		return head;
	}
	else{
		node *prev=head;
		int i=0;
		while(prev->next!=head&&i<(k-2)){
			prev=prev->next;
			i++;
		}
		node *curr=prev->next;
		prev->next=curr->next;
		delete(curr);
		return head;
	}
}

int main(){
	node *head=new node(10);
//	head->next=head;
	head->next = new node(20);
	head->next->next = new node(30);
	head->next->next->next = new node(40);
	head->next->next->next->next=head;
	printlist(head);
	cout<<endl;
	head=delknode(head,2);
	printlist(head);
}
