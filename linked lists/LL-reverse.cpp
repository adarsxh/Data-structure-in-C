#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node * next;
	node(int x){
		data = x;
		next =NULL;
	}
};

void printlist(node *head){
	while(head!=NULL){
		cout<<(head->data)<<"\t";
		head=head->next;
	}
}

node* revlist(node *head){
	vector <int > arr;
	for(node *curr=head; curr!=NULL; curr=curr->next){
		arr.push_back(curr->data);
	}
	for(node *curr=head; curr!=NULL; curr=curr->next){
		curr->data=arr.back();
		arr.pop_back();
	}
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
	revlist(head);
	printlist(head);
}
