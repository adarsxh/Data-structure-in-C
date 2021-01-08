//finding the index of leftmost character that does not repeat in a given string
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b){
	if(a<=b)
		return a;
	else
		return b;
}

int firstnonrepeat(string s){
	int res = INT_MAX;
	int fi[256];
	for(int i=0;i<256;i++)
		fi[i]=-1;
	for(int i=0;i<s.length();i++){
		if(fi[s[i]]==-1){
			fi[s[i]]=i;
		}
		else{
			fi[s[i]]=-2;
			
		}
	}
	for(int i=0;i<256;i++){
		if(fi[i]>=0)
			res = min(res,fi[i]);
	}
	return(res==INT_MAX)?-1:res;
}
int main(){
	string s = "geekforgeek";
	printf("%d",firstnonrepeat(s));
}
