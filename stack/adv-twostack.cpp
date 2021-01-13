#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct twostack{
	int *arr,cap,top1,top2;
	twostack(int n){
		cap = n;
		top1=-1;
		top2=cap;
		arr=new int(n);
		}
	void push1(int x){
		if(top1<top2-1){
			top1++;
			arr[top1]=x;
		}
	}
	void push2(int x){
		if(top1<top2-1){
			top2--;
			arr[top2]=x;
		}
	}
	int pop1(){
		if(top1>-1){
		int x=arr[top1];
		top1--;
		return x;
		}
		else
			exit(1);
	}
	int pop2(){
		if(top2<cap){
			int x = arr[top2];
			top2++;
			return x;
		}
		else
			exit(1);
	}
	void print1(){
		while(top1>-1){
			cout<<arr[top1]<<"\t";
			top1--;
		}
	}
	void print2(){
		while(top2<cap){
			cout<<arr[top2]<<"\t";
			top2++;
		}
	}
	
};

int main(){
	twostack a(10);
	a.push1(10);
	a.push1(20);
	a.push2(100);
	a.push2(200);
	a.push1(30);
	a.push2(300);
	a.pop1();
	a.pop2();
	a.print1();
	cout<<endl;
	cout<<endl;
	a.print2();
	
}
