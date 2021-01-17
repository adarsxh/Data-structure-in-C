#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#include<stack>
using namespace std;

void printmaxkn(int arr[], int n, int k){   //naive solution O(n^2) time complexity
	for(int i=0;i<n-k+1;i++){
		int mx = arr[i];
		for(int j=i+1;j<i+k;j++)
			mx = max(arr[i],mx);
		cout<<mx<<" ";
	}
}
void printmaxke(int arr[], int n, int k){   //efficient solution O(n) time complexity
	deque<int> dq;
	for(int i=0;i<k;i++){
		while(!dq.empty()&&arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for(int i=k;i<n;i++){
		cout<<arr[dq.front()]<<" ";
		while(!dq.empty()&&dq.front()<=(i-k))
			dq.pop_front();
		while(!dq.empty()&&arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	cout<<arr[dq.front()]<<" ";
	
}

int main(){
	int arr[]={10, 8, 5, 12, 15, 7, 6};
	printmaxke(arr, 7, 3);
}
