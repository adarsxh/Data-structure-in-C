#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct que{					//implementqation on circular array
	int *arr;
	int size, cap, front;
	que(int c){
		cap = c;
		front =0;
		size = 0;
		arr = new int[c];
	}
	bool isfull(){
		return (size==cap);
	}
	bool isempty(){
		return (size==0);
	}
	int getrear(){
		if(isempty())
			return -1;
		else{
			return (front+size-1)%cap;
		}
	}
	int getfront(){
		if(isempty())
			return -1;
		else{
			return front;
		}
	}
	void enque(int x){
		if(isfull())
			return;
		else{
			int rear = getrear();
			rear = (rear+1)%cap;
			arr[rear] = x;
			size++;
		}
	}
	void deque(){
		if(isempty())
			return;
		front = (front+1)%cap;
		size--;
	}
	int top(){
		if(isempty())
			return -1;
		return arr[front];
	}
};

int main(){
	struct que a(10);
	a.enque(20);
	a.enque(30);
	a.enque(40);
	a.enque(50);
	a.enque(60);
//	cout<<a.getfront()<<" "<<a.getrear()<<" ";
	while(!a.isempty()){
		cout<<a.top()<<"\t";
		a.deque();
	}
}
