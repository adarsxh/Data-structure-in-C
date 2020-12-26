#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map> 
using namespace std;

void countfreq(int a[], int n){
	unordered_map<int, int> mp;
	for(int i=0;i<n;i++)
		mp[a[i]]++;
	for(auto x:mp)
		cout<<x.first<<" "<<x.second<<endl;
}
int main(){
	int a[] = {2, 3, 2, 2, 3, 4, 56, 67, 56};
	countfreq(a, 9);
	return 0;
	
}
