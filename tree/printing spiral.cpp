#include<iostream>
#include<queue>
#include<stack>
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

void printspiralm1(node *root){
	if(root==NULL)
		return;
	queue<node*>q;
	stack<int>s;
	bool reverse = false;
	q.push(root);
	while(q.empty()==false){
		int count=q.size();
		for(int i=0;i<count;i++){
			node *curr=q.front();
			q.pop();
			if(reverse)
				s.push(curr->key);
			else{
				cout<<curr->key<<" ";
			}
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
		if(reverse){
			while(s.empty()==false){
				cout<<s.top()<<" ";
				s.pop();
			}
		
		}
		reverse = !reverse;
	}
}

void printspiralm2(node *root){
	if(root==NULL)
		return ;
	stack<node*>s1;
	stack<node*>s2;
	s1.push(root);
	while(s1.empty()==false||s2.empty()==false){
		while(s1.empty()==false){
			node *curr=s1.top();
			s1.pop();
			cout<<curr->key<<" ";
			if(curr->left!=NULL)
				s2.push(curr->left);
			if(curr->right!=NULL)
				s2.push(curr->right);
		}
		while(s2.empty()==false){
			node *curr=s2.top();
			s2.pop();
			cout<<curr->key<<" ";
			if(curr->right!=NULL)
				s1.push(curr->right);
			if(curr->left!=NULL)
				s1.push(curr->left);
		}
	}
}

int main(){
	node *root = new node(1);
	root->left= new node(2);
	root->right = new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	root->left->left->left=new node(8);
	root->left->left->right=new node(9);
	root->left->right->left=new node(10);
	printspiralm1(root);
	
}
