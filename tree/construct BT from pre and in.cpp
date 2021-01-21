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


int preindex=0;
node *tree(int in[], int pre[], int is, int ie){
	if(ie>is)
		return NULL;
	node *root=new node(pre[preindex++]);
	int inindex;
	for(int i=is;i<=ie;i++){
		if(in[i]==root->key){
			inindex=i;
			break;
		}
	}
	root->left=tree(in, pre, is, inindex-1);
	root->right=tree(in, pre, inindex+1, ie);
	return root;
}
void iterativeprintm2(node *root){
	if(root==NULL)
		return;
	queue<node *>q;
	q.push(root);
	while(q.empty()==false){
		int count =q.size();
		for(int i=0;i<count;i++){
			node *curr=q.front();
			q.pop();
			cout<<(curr->key)<<" ";
			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
		cout<<"\n";
	}
}

int main(){
	int in[]={70, 20, 60, 10, 40, 30, 50};
	int pre[]={10, 20, 70, 60, 30, 40, 50};
	node *head = tree(in, pre, 0, 6);
	iterativeprintm2(head);
	
}
