#include<iostream>
#include<queue>
using namespace std;
int maxlevel = 0;
struct node{
	int key;
	node *right, *left;
	node(int x){
		key=x;
		right = NULL;
		left =NULL;
	}
};

void printleft(node *root, int level){
	if(root==NULL)
		return;
	if(maxlevel<level){
		cout<<(root->key)<<" ";
		maxlevel = level;
	}
	printleft(root->left, level+1);
	printleft(root->right,level+1);
}

void printleftview(node *root){
	printleft(root, 1);
}

void iterativeleft(node*root){
	if(root==NULL)
		return ;
	queue<node *>q;
	q.push(root);
	while(q.empty()==false){
		int count = q.size();
		for(int i=0;i<count;i++){
			node *curr=q.front();
			q.pop();
			if(i==0)
				cout<<(curr->key)<<" ";
			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
	}
}

int main(){
	node *root = new node(10);
	root->left= new node(20);
	root->right = new node(30);
	root->left->left=new node(40);
	root->left->right=new node(50);
	root->right->left=new node(60);
	root->right->right=new node(70);
	root->left->left->left=new node(80);
	root->left->left->right=new node(90);
	root->left->right->right=new node(100);
	iterativeleft(root);
}
