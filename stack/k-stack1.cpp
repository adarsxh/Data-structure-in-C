#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct kstack{
	int *arr, *top, *next;
	int k, cap, freetop;
	kstack(int k1, int n){
		k=k1, cap=n;
		arr = new int(cap);
		next = new int(cap);
		top = new int(k);
		for(int i=0;i<k;i++)
			top[i]=-1;
		freetop = 0;
		for(int i=0;i<cap-1;i++)
			next[i]=i+1;
		next[cap-1]=-1;
	}
	void push(int x, int sn){
		int i=freetop;
		freetop = next[i];
		next[i]=top[sn];
		top[sn]=i;
		arr[i]=x;
	}
	int pop(int sn){
		int i=top[sn];
		top[sn]=next[i];
		next[i]=freetop;
		freetop=i;
		return arr[i];
	}
	void print(int sn){
		while(top[sn]!=-1){
			cout<<pop(sn)<<"\t";
		}
	}
	
};

int main(){
	kstack a(3, 6);
	a.push(100,0);
	a.push(200,0);
	a.push(300,0);
	a.push(400,1);
	a.print(0);
	cout<<endl;
	a.print(1);
	cout<<endl;
	a.print(2);
	return(1);
}
	
