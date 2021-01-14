#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

vector<int> nextgreater(int arr[], int n){
	stack<int >s;
	vector<int> v;
	s.push(arr[n-1]);
	v.push_back(-1);
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && s.top()<=arr[i])
			s.pop();
		int nextg = (s.empty()?-1:s.top());
		v.push_back(nextg);
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	return v;
}
int main(){
	int arr[]={5, 15, 10, 8, 6, 12, 9, 18};
	vector<int>a;
	a = nextgreater(arr, 8);
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	
}
