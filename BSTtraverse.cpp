#include<iostream>
#include<queue>
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

void levelorder(bstnode* root){
	if(root==NULL) return;
	queue<bstnode*> Q;
	Q.push(root);
	while(!Q.empty()){
		bstnode *current = Q.front();
		cout<<current->data<<"->";
		if(current->left!=NULL) Q.push(current->left);
		if(current->right!=NULL) Q.push(current->right);
		Q.pop();
	}
}

void preorder(bstnode *root){
	if(root==NULL) return;
	printf("%d->", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(bstnode *root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}

void postorder(bstnode *root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d->", root->data);
	
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
	
	printf("Level order:\n");
	levelorder(root);
	printf("\nPre order:\n");
	preorder(root);
	printf("\nIn order:\n");
	inorder(root);
	printf("\nPost order:\n");
	postorder(root);
}
