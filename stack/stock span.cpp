#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
void span(vector<int> arr){
	stack<int>s;
	int n=arr.size();
	s.push(0);
	for(int i=0;i<n;i++){
		while(!s.empty() && arr[s.top()]<=arr[i])
			s.pop();
		int span = (s.empty()?(i+1):(i-s.top()));
		cout<<span<<" ";
		s.push(i);
	}
}
int main(){
	vector<int> a{15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
	span(a);
	
}
