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


bstnode* findmin(bstnode *root){
	if(root==NULL) return root;
	bstnode *current = root;
	while(current->left!=NULL)
			current = current->left;
	return current;
}
bstnode* del(bstnode* root, int data){
	if(root==NULL)
		return root;
	else if(data<root->data) root->left=del(root->left, data);
	else if(data>root->data) root->right = del(root->right, data);
	else{
		if(root->left==NULL && root->right==NULL){
			delete root;
			root=NULL;
		}
		else if(root->left==NULL){
			bstnode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right==NULL){
			bstnode * temp = root;
			root=root->left;
			delete(temp);
		}
		else{
			bstnode *temp= findmin(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);
		}
		
				
	}
	return root;
}

void inorder(bstnode *root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}


int main(){
	bstnode *root = NULL;
	int n,i,p, q;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Node value: ");
		scanf("%d",&p);
		root = insert(root, p);
	}
	printf("\n\n");
	inorder(root);
	printf("\nEnter the node to be deleted: \n");
	scanf("%d", &q);
	del(root, q);
	printf("\n\n");
	inorder(root);
	
}
