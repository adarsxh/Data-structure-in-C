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

bool search(bstnode *root, int data){
	if(root==NULL)
		return false;
	else if(root->data == data)
		return true;
	else if(data<=root->data)
		return search(root->left,data);
	else
		return search(root->right, data);
}


int main(){
	bstnode *root = NULL;
	
	root=insert(root, 15);
	root = insert(root,20);
	root = insert(root,23);
	root = insert(root,19);
	root = insert(root,100);
	root = insert(root,9);
	root = insert(root,23);
	
	int n;
	cout<<"Enter the number to be searched\n";
	cin>>n;
	if(search(root, n)==true) cout<<"Found\n";
	else cout<<"Not Found\n";
}
