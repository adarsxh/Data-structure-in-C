#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map> 
using namespace std;

int countdist(int a[], int n){
	unordered_set <int> s;
	for(int i=0;i<n;i++)
		s.insert(a[i]);
	return s.size();
}

int main(){
	int a[] = {2, 3, 4, 2, 3, 5, 67, 67};
	printf("%d", countdist(a, 8));
	return 0;
}
