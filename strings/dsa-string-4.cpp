//finding lexicographic rank of any string after taking all its permutation and combinations

#include<bits/stdc++.h>
using namespace std;

int fact(int a){
	return (a<=1)?1:a*fact(a-1);
}
int lexicographic(string s){
	int rank = 1;
	int n = s.length();
	int mul = fact(n);
	int count[256] = {0};
	for(int i=0;i<n;i++)
		count[s[i]]++;
	for(int i=1;i<256;i++)
		count[i] = count[i]+count[i-1];
	for(int i=0;i<n;i++){
		mul = mul/(n-i);
		rank = rank + count[s[i]-1]*mul;
		for(int j=s[i];j<256;j++)
			count[j]--;
	}
	return rank;
}

int main(){
	string s = "prime";
	printf("%d",lexicographic(s));
}
