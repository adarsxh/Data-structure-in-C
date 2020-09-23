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

bool isbstutill(bstnode *root,int minv,int maxv){
	if(root==NULL) return true;
	if(root->data>minv && root->data<maxv
		&& isbstutill(root->left, minv,root->data)
		&& isbstutill(root->right, root->data, maxv))
		return true;
	else
		return true;
}

bool isbst(bstnode *root){
	return(isbstutill(root, INT_MIN, INT_MAX));
}
void inorder(bstnode *root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}


int main(){
	bstnode *root = NULL;
	int n,i,p;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Node value: ");
		scanf("%d",&p);
		root = insert(root, p);
	}
	inorder(root);
	if(isbst(root)==true)
		printf("\nGiven tree is BST");
	else
		printf("\nTree is not BST");
	
}
