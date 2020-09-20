#include<iostream>
using namespace std;

struct bstnode{
	int data;
	bstnode *left;
	bstnode *right;
};

bstnode* getnewnode(bstnode *root, int data){
	bstnode *newnode = new bstnode();
	newnode->data = data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

bstnode* insert (bstnode *root, int data){
	if(root == NULL) {
		root = getnewnode(root, data);
		return root;
	}
	else if(data <= root->data){
		root->left=insert(root->left, data);
	}
	else
		root->right=insert(root->right,data);
	return root;
}

int minit(bstnode *root){
	if(root==NULL){
		cout<<"Empty list\n";
		return -1;
	}
	while(root->left!=NULL)
		root=root->left;
	return root->data;
}
int minre(bstnode *root){
	if(root==NULL){
		cout<<"Empty list\n";
		return -1;
	}
	else if(root->left==NULL)
		return root->data;
	minre(root->left);
}

int height(bstnode *root){
	if(root==NULL)
		return -1;
	return max(height(root->left),height(root->right))+1;
}

int main(){
	bstnode *root = NULL;
	
	root=insert(root, 15);
	root = insert(root,20);
	root = insert(root,10);
	root = insert(root,19);
	root = insert(root,1);
	root = insert(root,11);
	root = insert(root,23);
	
	cout<<"Minimum element is" <<minit(root)<<"(by iterative method)\n";
	cout<<"Minimum element is "<<minre(root)<<"(by recursive method)\n";
	cout<<"Height of BST is "<< height(root);
}
