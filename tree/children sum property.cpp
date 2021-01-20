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

bool issum(node *root){
	if(root==NULL)
		return true;
	if(root->left==NULL&&root->right==NULL)
		return true;
	int sum=0;
	if(root->left!=NULL)
		sum += root->left->key;
	if(root->right!=NULL)
		sum += root->right->key;
	return(root->key==sum&&issum(root->left)&&issum(root->right));
}
int main(){
	node *root = new node(50);
	root->left= new node(20);
	root->right = new node(30);
	root->left->left=new node(20);
/*	root->left->right=new node(50);
	root->right->left=new node(60);
	root->right->right=new node(70);
	root->left->left->left=new node(80);
	root->left->left->right=new node(90);
	root->left->right->right=new node(100);*/
	
	if(issum(root))
		cout<<"Followed";
	else
		cout<<"Not followed";
	
}
