//finding whether the permutation of a small sstring is present in a big string
#include<bits/stdc++.h>

using namespace std;

bool aresame(int a[], int b[],int n, int m){
	if(n!=m)
		return false;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])
			return false;
	}
	return true;
	
}
bool isanagrampresent(string txt, string pat){
	int counttxt[256]={0}, countpat[256]={0};
	for(int i=0;i<pat.length();i++){
		counttxt[txt[i]]++;
		countpat[pat[i]]++;
	}
	for(int i=pat.length();i<txt.length();i++){
		if(aresame(counttxt, countpat,256,256))
			return true;
		counttxt[txt[i]]++;
		counttxt[txt[i-pat.length()]]--;
	}
	return false;
}
int main(){
	string txt = "geeksforgeeks";
	string pat = "egsk";
	if(isanagrampresent(txt,pat))
		printf("True");
	else
		printf("false");
}

