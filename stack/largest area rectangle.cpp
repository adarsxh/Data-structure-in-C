#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

int recarea(int arr[], int n){
	int res;
	stack<int> s;
//	int curr = arr[0];
	for(int i=0;i<n;i++){
		while(s.empty()==false&&arr[s.top()]>=arr[i]){
			int tp = s.top();
			s.pop();
			int curr = arr[tp]*(s.empty()?i:(i-s.top()-1));
			res = max(res, curr);
		}
		s.push(i);
	}
	while(s.empty()==false){
		int tp = s.top();
		s.pop();
		int curr = arr[tp] *(s.empty()?n:(n-s.top()-1));
		res = max(res, curr);
	}
	return res;
}

int main(){
	int arr[] = {6, 2, 5, 4, 1, 5, 6};
	int n = 7;
	int r=recarea(arr, n);
	cout<<r<<endl;
}
