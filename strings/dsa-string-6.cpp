//check if two strings are in rotation

#include<bits/stdc++.h>
using namespace std;

bool arerotation(string s1, string s2){
	if(s1.length()!=s2.length())
		return false;
	s1 =s1+s1;
	return(s1.find(s2)!=string::npos);
}
int main(){
	string s1 = "abcd", s2 = "cdak";
	if(arerotation(s1, s2))
		printf("TRUE");
	else
		printf("FALSE");
}
