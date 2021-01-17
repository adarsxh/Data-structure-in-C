#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#include<stack>
using namespace std;

int nfpp(int petrol[], int dist[], int n){
	for(int start=0;start<n;start){
		int curr_pet=0;
		int end=start;
		while(true){
			curr_pet += (petrol[end]-dist[end]);
			if(curr_pet<0)
				break;
			end = (end+1)%n;
			if(end==start)
				return (start+1);
		}
	}
	return -1;
}

int efpp(int petrol[], int dist[], int n){
	int start = 0, curr_pet = 0;
	int prev_pet = 0;
	for(int i=0;i<n;i++){
		curr_pet += (petrol[i]-dist[i]);
		if(curr_pet<0){
			start = i+1;
			prev_pet = curr_pet;
			curr_pet = 0;
		}
	}
	return ((curr_pet+prev_pet)>=0)?(start+1):-1;
}
int main(){
	int petrol[]={50, 10, 60, 100};
	int dist[]={30, 20, 100, 10};
	cout<<efpp(petrol, dist, 4)<<" ";
}
