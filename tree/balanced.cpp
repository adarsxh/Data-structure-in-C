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

int height(node *root){
	if(root==NULL)
		return 0;
	return(1+max(height(root->left),height(root->right)));
}

bool isbalanced(node *root){         //naive method O(n^2)
	if(root==NULL)
		return true;
	int lh = height(root->left);
	int rh=height(root->right);
		return(abs(lh-rh)<=1&& isbalanced(root->left)&&isbalanced(root->right));
}
int isBalanced(node *root){          //this modifies the height function, if a node is balanced it will return the height and if it isnt then -1.
	if(root==NULL)
		return 0;                   //better algo O(n)
	int lh = isBalanced(root->left);
	if(lh==-1)
		return -1;
	int rh=isBalanced(root->right);
	if(rh==-1)
		return -1;
	if(abs(lh-rh)>1)
		return -1;
	else
		return(max(lh,rh)+1);
}

int maxwidht(node *root){
	if(root==NULL)
		return 0;
	queue<node *>q;
	q.push(root);
	int res=0;
	while(q.empty()==false){
		int count=q.size();
		res=max(res,count);
		for(int i=0;i<count;i++){
			node *curr=q.front();
			q.pop();
			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
	}
	return res;
}
int main(){
	node *root = new node(10);
	root->left = new node(20);
	root->right = new node (30);
	root->right->left = new node(40);
	root->right->right = new node(50);
	root->left->right = new node(60);
	root->left->left = new node(70);
	if(isBalanced(root)==-1)
		cout<<"Not balanced"<<endl;
	else
		cout<<"Balanced"<<endl;
	cout<<maxwidht(root)<<endl;
}
