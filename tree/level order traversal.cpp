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
void iterativeprint(node *root){
	if(root==NULL)                       //if tree is null return without printing anything
		return ;
	queue<node*>q;
	q.push(root);						//push root to print
	q.push(NULL);
	while(q.size()>1){
		node *curr=q.front();
		q.pop();
		if(curr==NULL){					//when null is encountred, print /n which shows the end of a level
			cout<<"\n";
			q.push(NULL);
			continue;
		}
		cout<<(curr->key)<<" ";
		if(curr->left!=NULL)     		//push the left child of the parent to the queue
			q.push(curr->left);			
		if(curr->right!=NULL)			//push right child of parent 
			q.push(curr->right);
	}
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
	node *root = new node(10);
	root->left= new node(20);
	root->right = new node(30);
	root->left->left=new node(40);
	root->left->right=new node(50);
	root->right->left=new node(60);
	root->right->right=new node(70);
	iterativeprintm2(root);
	
}
