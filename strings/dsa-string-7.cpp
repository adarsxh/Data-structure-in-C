#include<bits/stdc++.h>
using namespace std;

void patsearch(string txt, string pat){
	int n=txt.length(), m=pat.length(), j=0;
	for(int i=0;i<n-m;i++){
		for(j=0;j<m;j++){
			if(txt[i+j]!=pat[j])
				break;
		}
		if(j==m)
			printf("%d\t",i);
	}
}

int main(){
	string txt = "geeksforgeeks",pat="for";
	patsearch(txt,pat);
}
