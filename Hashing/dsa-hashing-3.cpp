#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main(){
	unordered_set <int> s;
	s.insert(20);
	s.insert(23);
	s.insert(30);
	s.insert(89);
	cout<<endl;
	if(s.find(23)==s.end())
		cout<<"Not found";
	else
		cout<<"Found "<<(*s.find(23));
	cout<<endl;
	cout<<s.size()<<" ";
	s.erase(23);
	cout<<s.size()<<"\n ";
	return 0;
}
