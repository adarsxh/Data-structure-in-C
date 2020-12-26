#include<iostream>
#include<list>
using namespace std;
struct myhash{
	int BUCKET;
	list<int> *table;
	myhash(int b){
		BUCKET = b;
		table = new list<int>[BUCKET];
	}
	void insert(int key){
		int i = hash(key);
		table[i].push_back(key);
	}
	void remove(int key){
		int i = hash(key);
		table[i].remove(key);
	}
	void search(int key){
		int i=hash(key);
		for(auto x:table[i]){
			if(x==key)
				return true;
		}
		return false;
	}
	int hash(int key){
		return key%BUCKET;
	}
};

int main(){
	struct myhash a;
	
}
