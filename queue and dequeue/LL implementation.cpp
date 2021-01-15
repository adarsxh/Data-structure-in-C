#include<iostream>
#include<bits/stdc++.h>
using namespace  std;

struct node{
	int data;
	node *next;
	node (int x){
		data = x;
		next = NULL;
	}
};

struct que{
	node *front, *rear;
	int size;
	que(){
		rear = NULL;
		front =NULL;
		size=0;
	}
	void enque(int x){
		node *temp = new node(x);
		if(front==NULL){
			front = temp;
			rear = temp;
		}
		rear->next=temp;
		rear = temp;
		size++;
	}
	void deque(){
		if(front==NULL)
			return;
		node *temp = front;
		front=front->next;
		delete(temp);
		if(front==NULL)
			rear=NULL;
		size--;
	}
	int getsize(){
		return size;
	}
	int getel(){
		if(front!=NULL)
			return front->data;
	}
	bool empty(){
		return (front==NULL);
	}
};
int main(){
	que a;
	a.enque(10);
	a.enque(20);
	a.enque(30);
	a.enque(40);
	while(a.empty()==false){
		cout<<a.getel()<<"\t";
		a.deque();
	}
}
