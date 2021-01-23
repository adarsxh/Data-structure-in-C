#include<iostream>
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

node *floor(node *root,int x){
	node *res = NULL;
	while(root!=NULL){
		if(root->key==x)
			return root;
		else if(root->key>x)
			root=root->left;
		else{
			res = root;
			root=root->right;
		}
	}
	return res;
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

node *ceil(node *root, int x){
	node *res = NULL;
	while(root!=NULL){
		if(root->key==x)
			return root;
		else if(root->key<x)
			root=root->right;
		else{
			if(res==NULL)
				res = root;
			else if(res->key>root->key)
				res = root;
			
			root = root->left;
		}
	}
	return res;
}
node *insert(node *root, int x){
	if(root==NULL)
		return new node(x);
	else if(root->key<x)
		root->right = insert(root->right,x);
	else if(root->key>x)
		root->left = insert(root->left,x);
	return root;
}
int main(){
	node *root=	NULL;
	root = insert(root, 10);
	root = insert(root, 4);
	root = insert(root, 13);
	root = insert(root, 11);
	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 14);
	iterativeprintm2(root);
	cout<<floor(root, 12)->key<<endl;
	cout<<ceil(root, 1)->key<<endl;
	
}
