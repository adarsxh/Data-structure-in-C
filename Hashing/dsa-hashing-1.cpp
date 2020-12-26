#include<iostream>
using namespace std;
void insert(int a[], int key){
	if(a[key]==0){
		a[key]=1;
		cout<<"true insert"<<endl;
	}
	else
		cout<<"false insert"<<endl;
}
void search(int a[], int key){
	if(a[key]==1)
		cout<<"True search"<<endl;
	else
		cout<<"False search"<<endl;
}
void delet(int a[], int key){
	if(a[key]==1){
		a[key]=0;
		cout<<"True delete "<<endl;
	}
	else
		cout<<"False delete"<<endl;
}
int main(){
	int a[100]={0};
	insert(a, 59);
	insert(a, 39);
	insert(a, 13);
	insert(a, 29);
	search(a, 23);
	search(a, 29);
	delet(a, 29);
	delet(a,29);
	
}
