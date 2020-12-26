#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map> 
using namespace std;
 
int main(){
	unordered_map <string, int> m;
	m["gfg"] = 20;
	m["ide"] = 30;
	m.insert({"courses", 15});
	for(auto x:m)
		cout<<x.first<<" "<<x.second<<endl;
	
	if(m.find("ide")!=m.end())
		cout<<"Found";
	else
		cout<<"Not found\n";
	for(auto it=m.begin(); it!=m.end(); it++)
		cout<<(it->first)<<" "<<(it->second)<<endl;
	return 0;
}
