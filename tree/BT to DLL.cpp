#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;

struct node{
	int key;
	node *right;
	node *left;
	node(int x){
		key = x;
		right = NULL;
		left = NULL;
	}
	
};

node *prevv=NULL;
node *btd(node *root){
	if(root==NULL)
		return root;
	node *head=btd(root->left);
	if(prevv==NULL)
		head = root;
	else{
		root->left=prevv;
		prevv->right=root;
	}
	prevv = root;
	btd(root->right);
	return head;
}
node *printll(node *head){
	if(head==NULL)
		return head;
	while(head!=NULL){
		cout<<head->key<<" ";
		head = head->right;
	}
}

int main(){
	node *root = new node(10);
	root->left = new node(20);
	root->right = new node (30);
	root->right->left = new node(40);
	root->right->right = new node(50);
	root->left->right = new node(60);
	root->left->left = new node(70);
	node *head = btd(root);
	printll(head);
	
}
