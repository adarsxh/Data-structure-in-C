#include<bits/stdc++.h>
using namespace std;

bool anagram(string s1, string s2){
	if(s1.length()!=s2.length())
		return false;
	int count[256] = {0};
	for(int i=0;i<s1.length();i++)
		count[s1[i]]++;
	for(int i=0;i<s2.length();i++)
		count[s2[i]]--;
	for(int i=0;i<256;i++)
		if(count[i]!=0)
			return false;
	return true;
}

int main()
{
	string s1 = "geeks";
	string s2 = "skege";
	if(anagram(s1, s2))
		cout<<"S1 and S2 are anagram";
	else
		cout<<"They are not anagram";
}
