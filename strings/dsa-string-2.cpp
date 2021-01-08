//finding index of leftmost character that repeats in a given string
#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
	if(a<=b)
		return a;
	else
		return b;
}
int firstrepeat(string s){
	int res=INT_MAX;
	int fi[256];
	for(int i=0;i<256;i++)
		fi[i]=-1;
	for(int i=0;i<s.length();i++){
		if(fi[s[i]]==-1)
			fi[s[i]] = i;
		else
			res = min(res,fi[s[i]]);
	}
	return(res==INT_MAX)?-1:res;
}

int main()
{
	string s = "gekforgkedvjhsdjdbf";
	printf("%d",firstrepeat(s));
}
