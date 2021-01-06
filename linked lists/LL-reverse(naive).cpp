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

node* revlistnaive(node *head){
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

node *reversebetter(node *head){
	node *curr=head;
	node *prev =NULL;
	while(curr!=NULL){
		node *next = curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

node *revrec1(node *head){
	if(head==NULL||head->next==NULL)
		return head;
	node *rest_head=revrec1(head->next);
	node *rest_tail=head->next;
	rest_tail->next=head;
	head->next=NULL;
	return rest_head;
}
node *revrec2(node *curr, node *prev){
	if(curr==NULL)
		return prev;
	node *next = curr->next;
	curr->next=prev;
	return revrec2(next, curr);
}
int main(){
	node *head = new node(10);
	node *temp1 = new node(20);
	node *temp2 = new node(30);
	node *temp3 = new node(40);
	head->next = temp1;
	temp1->next = temp2;
	temp2->next = temp3;
//	cout<<"Naive func"<<endl;
//	revlistnaive(head);
//	printlist(head);
//	cout<<"\nbetter func"<<endl;
//	reversebetter(head);
//	printlist(head);
//	cout<<"\nrecursive func1"<<endl;
//	revrec1(head);
	printlist(head);
	cout<<"\nrecursive func2"<<endl;
	revrec2(head, NULL);
	printlist(head);
}
