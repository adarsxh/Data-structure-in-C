#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct stac{
	queue <int>q1,q2;
	int top(){
		if(q1.empty())
			return -1;
		while(q1.size()!=1){
			q2.push(q1.front());
			q1.pop();
		}
		int t=q1.front();
		q1.pop();
		q2.push(t);
		while(q2.empty()==false){
			q1.push(q2.front());
			q2.pop();
		}
		return t;
	}
	int size(){
		return q1.size();
	}
	void push(int x){
		return q1.push(x);
	}
	void cpop(){
		if(q1.empty())
			return;
		int x=q1.size();
		for(int i=0;i<x-1;i++){
			
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		while(q2.empty()==false){
			q1.push(q2.front());
			q2.pop();
		}
	}
	
};

int main(){
	stac a;
	a.push(10);
	a.push(20);
	a.push(30);
	a.push(40);
//	a.cpop();
	while(a.size()!=0){
		cout<<a.top()<<" ";
		a.cpop();
	}
	
}
