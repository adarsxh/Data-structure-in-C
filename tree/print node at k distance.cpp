#include<iostream>
#include<queue>
using namespace std;

struct node{
	int key;
	node *right, *left;
	node(int x){
		key=x;
		right = NULL;
		left =NULL;
	}
};

void printkdist(node *root, int k){
	if(root==NULL)
		return ;
	if(k==0)
		cout<<(root->key)<<" ";
	else{
		printkdist(root->left, k-1);
		printkdist(root->right, k-1);
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
	
	printkdist(root, 2);
	
}
